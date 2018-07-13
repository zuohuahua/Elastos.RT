
#include "CService.h"

CAR_INTERFACE_IMPL(CCarrierListener, Object, ICarrierListener)

ECode CCarrierListener::OnIdle()
{
    return NOERROR;
}

ECode CCarrierListener::OnConnectionChanged(
    /* [in] */ Boolean online)
{
    SERVICE_LOG("=== Service connection change to: %s\n", online ? "online" : "offline");
    return NOERROR;
}

ECode CCarrierListener::OnReady()
{
    SERVICE_LOG("=== Service OnReady \n");
    return NOERROR;
}

ECode CCarrierListener::OnFriendRequest(
    /* [in] */ const String& uid,
    /* [in] */ const String& hello)
{
    SERVICE_LOG("=== friend %s request \n", uid.string());
    mService->mCarrier->AccpetFriendRequest(uid);
    return NOERROR;
}

ECode CCarrierListener::OnFriendConnetionChanged(
    /* [in] */ const String& uid,
    /* [in] */ Boolean online)
{
    SERVICE_LOG("=== friend %s connection change to: %s\n", uid.string(), online ? "online" : "offline");
    if (!online) {
        pthread_mutex_lock(&mService->mLock);
        mService->mExit = TRUE;
        pthread_mutex_unlock(&mService->mLock);
        pthread_cond_signal(&mService->mCv);
    }
    return NOERROR;
}

ECode CCarrierListener::OnPortForwardingRequest(
    /* [in] */ const String& uid,
    /* [in] */ const String& servicePort,
    /* [out] */ Boolean* accept)
{
    return NOERROR;
}

ECode CCarrierListener::OnPortForwardingResult(
    /* [in] */ const String &uid,
    /* [in] */ const String &localPort,
    /* [in] */ const String &remotePort,
    /* [in] */ ECode code)
{
    return NOERROR;
}

CAR_OBJECT_IMPL(CService)

CAR_INTERFACE_IMPL(CService, Object, IService);

CService::~CService()
{
    if (mListener) {
        mCarrier->RemoveCarrierNodeListener(mListener);
        mListener->Release();
    }

    if (mCarrier) {
        mCarrier->Stop();
        mCarrier->Release();
    }

    if (mServiceManager) {
        mServiceManager->Release();
    }

    pthread_mutex_destroy(&mLock);
    pthread_cond_destroy(&mCv);
}

ECode CService::AddService(
    /* [in] */ const String& name,
    /* [in] */ IInterface * pIntreface)
{
    return mServiceManager->AddService(name, pIntreface);
}

ECode CService::Start()
{
    pthread_mutex_lock(&mLock);
    while(!mExit) {
        pthread_cond_wait(&mCv, &mLock);
    }
    pthread_mutex_unlock(&mLock);

    return NOERROR;
}

ECode CService::constructor(
    /* [in] */ const String& path)
{
    pthread_mutexattr_t recursiveAttr;
    pthread_mutexattr_init(&recursiveAttr);
    pthread_mutexattr_settype(&recursiveAttr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mLock, &recursiveAttr);
    pthread_mutexattr_destroy(&recursiveAttr);

    pthread_cond_init(&mCv, NULL);

    ECode ec = _CCarrier_GetInstance(&mCarrier);
    if (FAILED(ec)) return ec;

    mListener = new CCarrierListener(this);
    if (!mListener) {
        return E_OUT_OF_MEMORY;
    }

    mListener->AddRef();
    mCarrier->AddCarrierNodeListener(mListener);

    ec = mCarrier->Start(path);
    if (FAILED(ec)) return ec;

    ec = _CServiceManager_AcquireInstance(&mServiceManager);
    return ec;
}


