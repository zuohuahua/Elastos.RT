
#include <assert.h>
#include <stdlib.h>

#include "CP2PParcelSession.h"
#include "prxstub.h"
#include "rot.h"


CParcelSession *CParcelSession::S_CreateObject(
                /* [in] */ void* pNativeSession)
{
    return new CP2PParcelSession((CSession*)pNativeSession);
}

ECode CP2PParcelSession::StartService(
                /* [in] */ const char * stubConnName)
{
    ECode ec;

    m_serviceStarted = true;

    mListener = new CSessionListener();
    if (!mListener) return E_OUT_OF_MEMORY;
    mListener->AddRef();
    mSession->AddListener(mListener, this);

    pthread_mutexattr_t recursiveAttr;
    pthread_mutexattr_init(&recursiveAttr);
    pthread_mutexattr_settype(&recursiveAttr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mWorkLock, &recursiveAttr);
    pthread_mutexattr_destroy(&recursiveAttr);

    pthread_cond_init(&mCv, NULL);

    m_stubId = stubConnName;

    if (!mSession->IsConnected()) {
        ec = E_FAIL;
        goto ErrorExit;
    }

    return NOERROR;

ErrorExit:
    return ec;
}

ECode CP2PParcelSession::StopService()
{
    if (m_serviceStarted) {
        pthread_cond_destroy(&mCv);
        pthread_mutex_destroy(&mWorkLock);

        if (mData) {
            if (mData->data)
                ArrayOf<Byte>::Free(mData->data);
            delete mData;
            mData = NULL;
        }
        m_serviceStarted = false;
    }
    return NOERROR;
}

CP2PParcelSession::CP2PParcelSession(CSession* pSession) :
    mSession(pSession),
    mListener(NULL),
    mData(NULL),
    m_serviceStarted(false)
{
    if (!mSession) return;
    mSession->AddRef();
}

CP2PParcelSession::~CP2PParcelSession()
{
    if (!mSession) return;

    if (mListener) {
        mSession->RemoveListener(mListener, this);
        mListener->Release();
    }
    mSession->Release();

    if (m_serviceStarted) {
        StopService();
    }
}

ECode CP2PParcelSession::SendMessage(
                /* [in] */ RpcMethod type,
                /* [in] */ void* msg,
                /* [in] */ int len)
{
    return mSession->SendMessage((int)type, msg, len);
}

ECode CP2PParcelSession::ReceiveMessage(
                /* [out] */ RpcMethod* pType,
                /* [out] */ void** buf,
                /* [out] */ int* len)
{
    return mSession->ReceiveMessage((int*)pType, buf, len);
}

ECode CP2PParcelSession::ReceiveFromRemote(
                /* [out] */ RpcMethod* pType,
                /* [out] */ void** buf,
                /* [out] */ int* len)
{
    int *type = (int*)pType;
    pthread_mutex_lock(&mWorkLock);
    if (mData) {
        if (mData->data)
            ArrayOf<Byte>::Free(mData->data);
        delete mData;
        mData = NULL;
    }
    while (mData == NULL) {
        pthread_cond_wait(&mCv, &mWorkLock);
    }

    if (FAILED(mData->ec)) {
        ECode ec = mData->ec;
        if (mData->data)
            ArrayOf<Byte>::Free(mData->data);
        delete mData;
        mData = NULL;
        pthread_mutex_unlock(&mWorkLock);
        return ec;
    }

    Byte* p = mData->data->GetPayload();
    int _len = mData->data->GetLength();
    int _type = *(int *)p;
    p += sizeof(int);
    _len -= sizeof(int);

    RPC_LOG("CP2PParcelSession::ReceiveFromRemote type:%d", _type);
    *type = _type;
    if (buf != NULL) {
        void* _base = malloc(_len);
        if (_base == NULL) {
            if (mData->data)
                ArrayOf<Byte>::Free(mData->data);
            delete mData;
            mData = NULL;
            pthread_mutex_unlock(&mWorkLock);
            return E_FAIL;
        }
        memcpy(_base, p, _len);
        *buf = _base;
        *len = _len;
    }

    if (mData->data)
        ArrayOf<Byte>::Free(mData->data);
    delete mData;
    mData = NULL;
    pthread_mutex_unlock(&mWorkLock);

    return NOERROR;
}

void CP2PParcelSession::CSessionListener::OnSessionConnected(
    /* [in] */ CSession* pSession,
    /* [in] */ Boolean succeeded,
    /* [in] */ void* context)
{
    if (!succeeded) {
        CP2PParcelSession* parcelSession = (CP2PParcelSession*)context;
        if (!parcelSession) return;

        pthread_mutex_lock(&parcelSession->mWorkLock);

        if (parcelSession->mData) {
            if (parcelSession->mData->data)
                ArrayOf<Byte>::Free(parcelSession->mData->data);
            delete parcelSession->mData;
            parcelSession->mData = NULL;
        }

        parcelSession->mData = new DataPack();
        if (!parcelSession->mData) {
            pthread_mutex_unlock(&parcelSession->mWorkLock);
            return;
        }
        parcelSession->mData->data = NULL;
        parcelSession->mData->ec = E_SESSION_FAILED;
        pthread_mutex_unlock(&parcelSession->mWorkLock);
        pthread_cond_signal(&parcelSession->mCv);
    }
    return;
}

void CP2PParcelSession::CSessionListener::OnSessionReceived(
    /* [in] */ CSession* pSession,
    /* [in] */ ArrayOf<Byte>* data,
    /* [in] */ void* context)
{
    RPC_LOG("CP2PParcelSession::CSessionListener::OnSessionReceived data: %p, context: %p", data, context);
    CP2PParcelSession* parcelSession = (CP2PParcelSession*)context;
    if (!parcelSession) return;

    pthread_mutex_lock(&parcelSession->mWorkLock);

    if (parcelSession->mData) {
        if (parcelSession->mData->data)
            ArrayOf<Byte>::Free(parcelSession->mData->data);
        delete parcelSession->mData;
        parcelSession->mData = NULL;
    }

    parcelSession->mData = new DataPack();
    if (!parcelSession->mData) {
        pthread_mutex_unlock(&parcelSession->mWorkLock);
        return;
    }
    parcelSession->mData->data = data->Clone();
    if (!parcelSession->mData->data) {
        pthread_mutex_unlock(&parcelSession->mWorkLock);
        return;
    }
    parcelSession->mData->ec = NOERROR;
    pthread_mutex_unlock(&parcelSession->mWorkLock);
    pthread_cond_signal(&parcelSession->mCv);
}
