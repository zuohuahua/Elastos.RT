
#include "CServiceManager.h"
#include "carrier.h"

IServiceManager* CServiceManager::sInstance = NULL;
SpinLock CServiceManager::sInstanceLock;

HashTable<InterfacePack, Type_String> CServiceManager::sServices;
pthread_mutex_t CServiceManager::sServiceLock;

pthread_mutex_t CServiceManager::sGetServiceMutex;
pthread_cond_t CServiceManager::sGetServiceCv;
Int32 CServiceManager::sNotifyType = 0;
ArrayOf<Byte>* CServiceManager::sData = NULL;


ELAPI _CServiceManager_AcquireInstance(
    /* [out] */ IServiceManager** manager)
{
    return CServiceManager::AcquireInstance(manager);
}

CServiceManager::CServiceManager()
    : mCarrier(NULL)
    , mSessionManager(NULL)
    , mListener(NULL)
{
    ECode ec = CCarrier::GetInstance(&mCarrier);
    if (FAILED(ec)) {
        RPC_LOG("ServiceManager get Carrier failed: 0x%x\n", ec);
        return;
    }

    ec = CSessionManager::AcquireInstance(&mSessionManager);
    if (FAILED(ec)) {
        RPC_LOG("ServiceManager Acquire SessionManager failed: 0x%x\n", ec);
        return;
    }
    mListener = new CSessionManagerListener();
    if (!mListener) {
        RPC_LOG("ServiceManager new listener failed\n");
        return;
    }
    mListener->AddRef();
    mSessionManager->AddListener(mListener, this);

    pthread_mutexattr_t recursiveAttr;
    pthread_mutexattr_init(&recursiveAttr);
    pthread_mutexattr_settype(&recursiveAttr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&sServiceLock, &recursiveAttr);
    pthread_mutex_init(&sGetServiceMutex, &recursiveAttr);
    pthread_mutexattr_destroy(&recursiveAttr);

    pthread_cond_init(&sGetServiceCv, NULL);
}

CServiceManager::~CServiceManager()
{
    if (mListener) {
        mSessionManager->RemoveListener(mListener, this);
        mListener->Release();
    }

    if (mSessionManager) {
        mSessionManager->Release();
    }

    sInstanceLock.Lock();
    sInstance = NULL;
    sInstanceLock.Unlock();

    pthread_mutex_destroy(&sServiceLock);
    pthread_mutex_destroy(&sGetServiceMutex);
    pthread_cond_destroy(&sGetServiceCv);

    if (mCarrier) {
        mCarrier->Release();
    }
}

ECode CServiceManager::AcquireInstance(
    /* [out] */ IServiceManager** ppManager)
{
    if (!ppManager) {
        return E_INVALID_ARGUMENT;
    }

    sInstanceLock.Lock();
    if (sInstance == NULL) {
        CServiceManager* instance = new CServiceManager();
        if (instance == NULL) {
            sInstanceLock.Unlock();
            RPC_LOG("CServiceManager new instance failed\n");
            return E_OUT_OF_MEMORY;
        }

        sInstance = IServiceManager::Probe(instance);
    }
    *ppManager = sInstance;
    (*ppManager)->AddRef();
    sInstanceLock.Unlock();

    return NOERROR;
}

UInt32 CServiceManager::AddRef()
{
    return ElLightRefBase::AddRef();
}

UInt32 CServiceManager::Release()
{
    return ElLightRefBase::Release();
}

PInterface CServiceManager::Probe(
    /* [in] */ REIID riid)
{
    if (riid == EIID_IInterface) {
        return (PInterface)this;
    }
    else if (riid == EIID_IServiceManager) {
        return (IServiceManager *)this;
    }
    else {
        return NULL;
    }
}

ECode CServiceManager::GetInterfaceID(
    /* [in] */ IInterface* object,
    /* [out] */ InterfaceID* iid)
{
    if (!iid) {
        return E_INVALID_ARGUMENT;
    }

    if (object == (IInterface *)(IServiceManager *)this) {
        *iid = EIID_IServiceManager;
    }
    else {
        return E_INVALID_ARGUMENT;
    }
    return NOERROR;
}

ECode CServiceManager::AddService(
    /* [in] */ const String& name,
    /* [in] */ IInterface * pService)
{
    if (!pService || name.IsNullOrEmpty()) {
        return E_INVALID_ARGUMENT;
    }

    RPC_LOG("CServiceManager::AddService: %s", name.string());
    InterfacePack ip;
    ECode ec = StdMarshalInterface(pService, &ip);
    if (FAILED(ec)) return ec;

    pthread_mutex_lock(&sServiceLock);
    sServices.Put((PVoid)(char*)name.string(), &ip);
    pthread_mutex_unlock(&sServiceLock);

    return NOERROR;
}

ECode CServiceManager::GetService(
    /* [in] */ const String& uid,
    /* [in] */ const String& name,
    /* [out] */ IInterface ** ppService)
{
    if (!ppService || uid.IsNullOrEmpty() || name.IsNullOrEmpty()) {
        return E_INVALID_ARGUMENT;
    }

    Boolean waitSesseionConnect = TRUE;
    CSession* session;
    ECode ec = mSessionManager->CreateSession(uid, TRUE, NULL, 0, &session);
    if (FAILED(ec)) {
        return ec;
    }
    if (ec == S_ALREADY_EXISTS) {
        waitSesseionConnect = FALSE;
    }

    CGetServiceListener* listener = new CGetServiceListener();
    listener->AddRef();
    ec = session->AddListener(listener, NULL);
    if (FAILED(ec)) {
        session->Release();
        listener->Release();
        return ec;
    }

    if (waitSesseionConnect) {
        pthread_mutex_lock(&sGetServiceMutex);
        sNotifyType = 0;
        while (sNotifyType == 0) {
            pthread_cond_wait(&sGetServiceCv, &sGetServiceMutex);
        }
        pthread_mutex_unlock(&sGetServiceMutex);

        if (sNotifyType == SESSION_CONNECT_FAILED) {
            RPC_LOG("CServiceManager GetService session connect failed\n");
            session->RemoveListener(listener, NULL);
            session->Release();
            listener->Release();
            return E_FAIL;
        }
    }

    ec = session->SendMessage(GET_SERVICE, name.GetBytes()->GetPayload(), name.GetLength());
    if (FAILED(ec)) {
        session->RemoveListener(listener, NULL);
        session->Release();
        listener->Release();
        return ec;
    }

    pthread_mutex_lock(&sGetServiceMutex);
    sNotifyType = 0;
    if (sData != NULL) {
        ArrayOf<Byte>::Free(sData);
        sData = NULL;
    }
    while (sData == NULL) {
        pthread_cond_wait(&sGetServiceCv, &sGetServiceMutex);
    }

    Byte* p = sData->GetPayload();
    ec = *(ECode *)p;
    RPC_LOG("GetService receive ec:%x\n", ec);
    if (FAILED(ec)) {
        pthread_mutex_unlock(&sGetServiceMutex);
        session->RemoveListener(listener, NULL);
        session->Release();
        listener->Release();
        return ec;
    }
    InterfacePack ip;
    p += sizeof(int);
    int size = *(int *)p;
    p += sizeof(int);
    memcpy(&ip, p, sizeof(InterfacePack));

    ArrayOf<Byte>::Free(sData);
    sData = NULL;

    pthread_mutex_unlock(&sGetServiceMutex);

    session->RemoveListener(listener, NULL);
    listener->Release();

    ec = StdUnmarshalInterface(UnmarshalFlag_Noncoexisting, session, &ip, ppService);
    session->Release();
    return ec;
}

ECode CServiceManager::GetService(
    /* [in] */ const String& name,
    /* [out] */ InterfacePack* pIp)
{
    InterfacePack * ip = sServices.Get((char*)name.string());
    if (!ip) return E_FAIL;

    memset(pIp, 0, sizeof(InterfacePack));
    pIp->m_clsid = ip->m_clsid;
    pIp->m_uIndex = ip->m_uIndex;

    strcpy(pIp->m_stubConnName, ip->m_stubConnName);
    RPC_LOG("service %s stubConnName is %s\n", name.string(), ip->m_stubConnName);

    return NOERROR;
}

ECode CServiceManager::HandleGetService(
    /* [in] */ CSession* pSession,
    /* [in] */ const String& name)
{
    InterfacePack ip;
    ECode ec = GetService(name, &ip);

    int size = sizeof(InterfacePack);

    int _len = sizeof(int) + sizeof(int) + size;

    ArrayOf<Byte>* data = ArrayOf<Byte>::Alloc(_len);
    if (!data) {
        return E_OUT_OF_MEMORY;
    }

    Byte *p = data->GetPayload();

    int i32;

    i32 = ec;
    memcpy(p, &i32, sizeof(int));
    p += sizeof(int);

    if (SUCCEEDED(ec)) {
        i32 = size;
        memcpy(p, &i32, sizeof(int));
        p += sizeof(int);

        memcpy(p, &ip, size);
    } else
        _len = sizeof(int);

    pSession->SendMessage(GET_SERVICE_REPLY, data->GetPayload(), _len);

    ArrayOf<Byte>::Free(data);
    return NOERROR;
}


void CServiceManager::CSessionManagerListener::OnSessionRequest(
    /* [in] */ ICarrier* pCarrier,
    /* [in] */ const char *from,
    /* [in] */ const char *sdp,
    /* [in] */ size_t len,
    /* [in] */ void *context)
{
    RPC_LOG("CServiceManager::CSessionManagerListener::OnSessionRequest");
    return;
}

void CServiceManager::CSessionManagerListener::OnSessionReceived(
    /* [in] */ CSession* pSession,
    /* [in] */ ArrayOf<Byte>* data,
    /* [in] */ void *context)
{
    CServiceManager* manager = (CServiceManager*)context;
    if (!manager) return;

    Byte* p = data->GetPayload();
    int type = *(size_t *)p;
    RPC_LOG("CServiceManager::CSessionManagerListener receive type: %d\n", type);
    p += sizeof(size_t);

    if (type == GET_SERVICE) {
        String name((char*)p, data->GetLength() - 4);
        manager->HandleGetService(pSession, name);
    }
}

void CServiceManager::CGetServiceListener::OnSessionConnected(
    /* [in] */ CSession* pSession,
    /* [in] */ Boolean succeeded,
    /* [in] */ void* context)
{
    pthread_mutex_lock(&sGetServiceMutex);
    if (succeeded) {
        sNotifyType = SESSION_CONNECT_SUCCEEDED;
    }
    else {
        sNotifyType = SESSION_CONNECT_FAILED;
    }
    pthread_mutex_unlock(&sGetServiceMutex);
    pthread_cond_signal(&sGetServiceCv);
}

void CServiceManager::CGetServiceListener::OnSessionReceived(
    /* [in] */ CSession* pSession,
    /* [in] */ ArrayOf<Byte>* data,
    /* [in] */ void* context)
{
    Byte* p = data->GetPayload();
    size_t type = *(size_t *)p;
    RPC_LOG("CServiceManager::CGetServiceListener receive type:%d\n", type);
    if (type != GET_SERVICE_REPLY) {
        return;
    }

    sNotifyType = SESSION_SERVICE_INFO;

    p += sizeof(size_t);

    pthread_mutex_lock(&sGetServiceMutex);
    int len = data->GetLength() - sizeof(size_t);
    if (sData != NULL) {
        ArrayOf<Byte>::Free(sData);
        sData = NULL;
    }
    sData = ArrayOf<Byte>::Alloc(len);
    if (!sData) {
        RPC_LOG("CGetServiceListener receive out of memory\n");
        return;
    }
    memcpy(sData->GetPayload(), p, len);
    pthread_mutex_unlock(&sGetServiceMutex);
    pthread_cond_signal(&sGetServiceCv);
}
