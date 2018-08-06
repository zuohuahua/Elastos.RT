
#include "CSessionManager.h"
#include "elcarrierapi.h"
#include "android/log.h"


CSessionManager* CSessionManager::sInstance = NULL;
SpinLock CSessionManager::sInstanceLock;

ICarrier* CSessionManager::sCarrier = NULL;

CSessionManager::ListenerNode CSessionManager::sListeners;
pthread_mutex_t CSessionManager::sListenersLock;


UInt32 CManagerListener::AddRef()
{
    return ElLightRefBase::AddRef();
}

UInt32 CManagerListener::Release()
{
    return ElLightRefBase::Release();
}

ECode CSessionManager::AcquireInstance(
    CSessionManager** ppManager)
{
    if (!ppManager) {
        return E_INVALID_ARGUMENT;
    }

    sInstanceLock.Lock();
    if (sInstance == NULL) {
        ICarrier* carrier;
        ECode ec = CCarrier::GetInstance(&carrier);
        if (FAILED(ec)) {
            RPC_LOG("CSessionManager get Carrier failed: 0x%x\n", ec);
            return ec;
        }

        sInstance = new CSessionManager(carrier);
        carrier->Release();
        if (sInstance == NULL) {
            sInstanceLock.Unlock();
            RPC_LOG("CSessionManager new instance failed\n");
            return E_OUT_OF_MEMORY;
        }

    }
    *ppManager = sInstance;
    (*ppManager)->AddRef();
    sInstanceLock.Unlock();

    return NOERROR;
}

CSessionManager::CSessionManager(
    /* [in] */ ICarrier* pCarrier)
{
    if (sCarrier) {
        sCarrier->Release();
    }
    sCarrier = pCarrier;
    if (sCarrier) {
        sCarrier->AddRef();
    }

    mReceiveListener = new CReceiveListener();
    if (mReceiveListener) {
        mReceiveListener->AddRef();
    }

    pthread_mutexattr_t recursiveAttr;
    pthread_mutexattr_init(&recursiveAttr);
    pthread_mutexattr_settype(&recursiveAttr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&sListenersLock, &recursiveAttr);
    pthread_mutex_init(&mSessionsLock, &recursiveAttr);
    pthread_mutexattr_destroy(&recursiveAttr);

    sListeners.Initialize();
    mSessions.Initialize();

    InitSession();
}

CSessionManager::~CSessionManager()
{
    sInstanceLock.Lock();
    sInstance = NULL;
    sInstanceLock.Unlock();

    if (sCarrier) {
        sCarrier->Release();
        sCarrier = NULL;
    }

    pthread_mutex_lock(&sListenersLock);
    if (!sListeners.IsEmpty()) {
        ListenerNode* head = &sListeners;
        ListenerNode* next = (ListenerNode*)sListeners.Next();
        while(next != head) {
            next->Detach(head);
            delete next;
            next = (ListenerNode*)sListeners.Next();
        }
    }
    sListeners.Initialize();
    pthread_mutex_unlock(&sListenersLock);
    pthread_mutex_destroy(&sListenersLock);

    pthread_mutex_lock(&mSessionsLock);
    if (!mSessions.IsEmpty()) {
        SessionNode* head = &mSessions;
        SessionNode* next = (SessionNode*)mSessions.Next();
        while(next != head) {
            next->Detach(head);
            delete next;
            next = (SessionNode*)mSessions.Next();
        }
    }
    pthread_mutex_unlock(&mSessionsLock);
    pthread_mutex_destroy(&mSessionsLock);

    if (mReceiveListener) {
        mReceiveListener->Release();
    }
}

UInt32 CSessionManager::AddRef()
{
    return ElLightRefBase::AddRef();
}

UInt32 CSessionManager::Release()
{
    return ElLightRefBase::Release();
}


ECode CSessionManager::CreateSession(
    /* [in] */ const String& uid,
    /* [in] */ Boolean initiator,
    /* [in] */ const char *sdp,
    /* [in] */ int len,
    /* [out] */ CSession** ppSession)
{
    if (uid.IsNullOrEmpty() || !ppSession) {
        return E_INVALID_ARGUMENT;
    }

    ECode ec = GetSession(uid, ppSession);
    if (SUCCEEDED(ec)) {
        RPC_LOG("CSessionManager::CreateSession uid: %s exist", uid.string());
        return S_ALREADY_EXISTS;
    }

    CSession* session = new CSession(sCarrier, uid, sdp, len);
    if (!session) {
        return E_OUT_OF_MEMORY;
    }

    ec = session->Connect(initiator);
    if (FAILED(ec)) {
        delete session;
        return ec;
    }

    session->AddListener(mReceiveListener, this);

    pthread_mutex_lock(&mSessionsLock);
    SessionNode* node = new SessionNode(session);
    if (!node) {
        delete session;
        return E_OUT_OF_MEMORY;
    }
    mSessions.InsertFirst(node);
    pthread_mutex_unlock(&mSessionsLock);

    *ppSession = session;
    (*ppSession)->AddRef();

    return NOERROR;
}

ECode CSessionManager::GetSession(
    /* [in] */ const String& uid,
    /* [out] */  CSession** ppSession)
{
    if (uid.IsNullOrEmpty() || !ppSession) {
        return E_INVALID_ARGUMENT;
    }

    pthread_mutex_lock(&mSessionsLock);
    SessionNode* head = &mSessions;
    SessionNode* next = (SessionNode*)mSessions.Next();
    while(next != head) {
        String remoteUid;
        next->mSession->GetUid(&remoteUid);
        if (remoteUid.Equals(uid)) {
            *ppSession = next->mSession;
            (*ppSession)->AddRef();
            pthread_mutex_unlock(&mSessionsLock);
            return NOERROR;
        }
        next = (SessionNode*)next->Next();
    }
    pthread_mutex_unlock(&mSessionsLock);

    return E_DOES_NOT_EXIST;
}

ECode CSessionManager::AddListener(
    /* [in] */ CManagerListener* pListener,
    /* [in] */ void* context)
{
    if (!pListener) {
        return E_INVALID_ARGUMENT;
    }

    if (FindListener(pListener, context)) {
        return NOERROR;
    }

    pthread_mutex_lock(&sListenersLock);

    ListenerNode* node = new ListenerNode(pListener, context);
    if (!node) {
        pthread_mutex_unlock(&sListenersLock);
        return E_OUT_OF_MEMORY;
    }
    sListeners.InsertFirst(node);

    pthread_mutex_unlock(&sListenersLock);
    return NOERROR;
}

ECode CSessionManager::RemoveListener(
    /* [in] */ CManagerListener* pListener,
    /* [in] */ void* context)
{
    if (!pListener) {
        return E_INVALID_ARGUMENT;
    }

    ListenerNode* node = FindListener(pListener, context, TRUE);
    if (node) {
        delete node;
    }

    return NOERROR;
}

ECode CSessionManager::GetUid(
    /* [out] */ String* pUid)
{
    return sCarrier->GetUserid(pUid);
}

CSessionManager::ListenerNode* CSessionManager::FindListener(
    /* [in] */ CManagerListener* pListener,
    /* [in] */ void* context,
    /* [in] */ Boolean detach)
{
    pthread_mutex_lock(&sListenersLock);
    if (sListeners.IsEmpty()) {
        pthread_mutex_unlock(&sListenersLock);
        return NULL;
    }

    ListenerNode* head = &sListeners;
    ListenerNode* next = (ListenerNode*)sListeners.Next();
    ListenerNode* prev = head;
    while(next != head) {
        if (next->mListener == pListener && next->mContext == context) {
            if (detach) {
                next->Detach(prev);
            }
            pthread_mutex_unlock(&sListenersLock);
            return next;
        }
        prev = next;
        next = (ListenerNode*)next->Next();
    }

    pthread_mutex_unlock(&sListenersLock);
    return NULL;
}

void SessionRequestCallback(
    ElaCarrier *w,
    const char *from,
    const char *sdp,
    size_t len,
    void *context)
{
    // strncpy(session_ctx.remote_sdp, sdp, len);
    // session_ctx.remote_sdp[len] = 0;
    // session_ctx.sdp_len = len;

    RPC_LOG("Session request from[%s] with SDP:\n%s.\n", from, sdp);
    RPC_LOG("Reply use following commands:\n");
    RPC_LOG("  sreply refuse [reason]\n");
    RPC_LOG("OR:\n");
    RPC_LOG("  1. snew %s\n", from);
    RPC_LOG("  2. sadd [plain] [reliable] [multiplexing] [portforwarding]\n");
    RPC_LOG("  3. sreply ok\n");

    pthread_mutex_lock(&CSessionManager::sListenersLock);
    if (CSessionManager::sListeners.IsEmpty()) {
        pthread_mutex_unlock(&CSessionManager::sListenersLock);
        return;
    }

    CSessionManager::ListenerNode* head = &CSessionManager::sListeners;
    CSessionManager::ListenerNode* next = (CSessionManager::ListenerNode*)CSessionManager::sListeners.Next();
    while(next != head) {
        pthread_mutex_unlock(&CSessionManager::sListenersLock);
        next->mListener->OnSessionRequest(CSessionManager::sCarrier, from, sdp, len, next->mContext);
        pthread_mutex_lock(&CSessionManager::sListenersLock);
        next = (CSessionManager::ListenerNode*)next->Next();
    }
    pthread_mutex_unlock(&CSessionManager::sListenersLock);
}


ECode CSessionManager::InitSession()
{
    ElaCarrier* carrier;
    ECode ec = ((CCarrier*)sCarrier)->GetCarrierHandle(&carrier);
    if (FAILED(ec)) return ec;

    int ret = ela_session_init(carrier, SessionRequestCallback, NULL);
    if (ret != 0) {
        RPC_LOG("Error init session: 0x%x\n", ela_get_error());
    }

    return NOERROR;
}

void CSessionManager::CReceiveListener::OnSessionConnected(
    /* [in] */ CSession* pSession,
    /* [in] */ Boolean succeeded,
    /* [in] */ void* context)
{
    // if session connect failed, delete the session
    if (!succeeded) {
        CSessionManager* pThis = (CSessionManager*)context;

        pthread_mutex_lock(&pThis->mSessionsLock);
        if (!pThis->mSessions.IsEmpty()) {
            SessionNode* head = &pThis->mSessions;
            SessionNode* next = (SessionNode*)pThis->mSessions.Next();
            SessionNode* prev = head;
            while(next != head) {
                if (next->mSession == pSession) {
                    next->Detach(head);
                    delete next;
                    break;
                }
                prev = next;
                next = (SessionNode*)next->Next();
            }
        }
        pthread_mutex_unlock(&pThis->mSessionsLock);
    }
    return;
}

void CSessionManager::CReceiveListener::OnSessionReceived(
    /* [in] */ CSession* pSession,
    /* [in] */ ArrayOf<Byte>* data,
    /* [in] */ void* context)
{
    RPC_LOG("CSessionManager::CReceiveListener OnSessionReceived: %p, data: %p", pSession, data);
    pthread_mutex_lock(&sListenersLock);
    if (sListeners.IsEmpty()) {
        pthread_mutex_unlock(&sListenersLock);
        return;
    }

    ListenerNode* head = &sListeners;
    ListenerNode* next = (ListenerNode*)sListeners.Next();
    while(next != head) {
        pthread_mutex_unlock(&sListenersLock);
        next->mListener->OnSessionReceived(pSession, data, next->mContext);
        pthread_mutex_lock(&sListenersLock);
        next = (ListenerNode*)next->Next();
    }
    pthread_mutex_unlock(&sListenersLock);
}
