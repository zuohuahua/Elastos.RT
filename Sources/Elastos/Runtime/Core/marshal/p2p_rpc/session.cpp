
#include "session.h"
#include "carrier.h"
#include "elcarrierapi.h"
#include "rpcerror.h"
#include "eladef.h"

using Elastos::CCarrier;

void* workThread(void* argc)
{
    CSession* pThis = (CSession*)argc;
    if (!pThis) return 0;

    RPC_LOG("Session[%d] work thread %d start...\n", pThis->mStream, gettid());

    Boolean exit = FALSE;
    while(!exit) {

        pthread_mutex_lock(&pThis->mWorkLock);
        while(pThis->mMessageQueue.IsEmpty()) {
            pthread_cond_wait(&pThis->mCv, &pThis->mWorkLock);
        }

        if (pThis->mMessageQueue.IsEmpty()) {
            pthread_mutex_unlock(&pThis->mWorkLock);
            continue;
        }

        CSession::MessageNode* node = (CSession::MessageNode*)pThis->mMessageQueue.Next();
        node->Detach();
        pthread_mutex_unlock(&pThis->mWorkLock);

        Int32 type = node->mMessage->GetType();
        RPC_LOG("workThread thread wait handle message type: %d", type);
        switch(type) {
        case MESSAGE_TYPE_DATA: {
            // save sender uid in tls
            void* buf = pthread_getspecific(TL_CARRIER_ID_SLOT);
            if (buf) {
                free(buf);
            }
            void* p = malloc(pThis->mUid.GetLength());
            if (p) {
                memcpy(p, pThis->mUid.string(), pThis->mUid.GetLength());
                int ret = pthread_setspecific(TL_CARRIER_ID_SLOT, p);
            }

            pThis->NotifySessionReceived(node->mMessage);
            break;
        }
        case MESSAGE_TYPE_EXIT:
            RPC_LOG("Session[%d] work thread end...\n", pThis->mStream);
            exit = TRUE;
            break;
        default:
            RPC_LOG("Session[%d] work thread message type not recognaized: %d\n", pThis->mStream, type);
            break;
        }

        delete node;
    }


    void* buf = pthread_getspecific(TL_CARRIER_ID_SLOT);
    return buf;
}

UInt32 SessionListener::AddRef()
{
    return ElLightRefBase::AddRef();
}

UInt32 SessionListener::Release()
{
    return ElLightRefBase::Release();
}

CSession::CSession(
    /* [in] */ ICarrier* pCarrier,
    /* [in] */ const char* uid,
    /* [in] */ const char *sdp,
    /* [in] */ size_t len)
    : mCarrier(pCarrier)
    , mElaSession(NULL)
    , mStream(0)
    , mInitiator(TRUE)
    , mWorkThread(0)
    , mData(NULL)
    , mWaitingForData(FALSE)
{
    if (mCarrier) {
        mCarrier->AddRef();
    }

    if (pCarrier) {
        // Handle64 carrier;
        ECode ec = ((CCarrier*)pCarrier)->GetCarrierHandle(&mElaCarrier);
        // if (SUCCEEDED(ec)) {
        // }
    }

    mUid = uid;

    if (len > 0 && sdp) {
        strncpy(mRemoteSdp, sdp, len);
        mSdpLen = len;
        mRemoteSdp[len] = '\0';
    }

    pthread_mutexattr_t recursiveAttr;
    pthread_mutexattr_init(&recursiveAttr);
    pthread_mutexattr_settype(&recursiveAttr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mListenersLock, &recursiveAttr);
    pthread_mutex_init(&mWorkLock, &recursiveAttr);
    pthread_mutex_init(&mDataLock, &recursiveAttr);
    pthread_mutexattr_destroy(&recursiveAttr);

    pthread_cond_init(&mCv, NULL);
    pthread_cond_init(&mDataCv, NULL);

    mListeners.Initialize();
    mMessageQueue.Initialize();
}

CSession::~CSession()
{
    if (mCarrier) {
        mCarrier->Release();
    }

    if (mWorkThread != 0) {
        //send exit message;
        MessageNode* node;
        ECode ec = CreateMessageNode(NULL, 0, MESSAGE_TYPE_EXIT, &node);
        if (SUCCEEDED(ec)) {
            pthread_mutex_lock(&mWorkLock);
            mMessageQueue.InsertNext(node);
            pthread_mutex_unlock(&mWorkLock);
            pthread_cond_signal(&mCv);
            pthread_join(mWorkThread, NULL);
        }
    }
    ClearMessageQuere();

    pthread_mutex_lock(&mDataLock);
    if (mData) {
        if (mData->data)
            ArrayOf<Byte>::Free(mData->data);
        delete mData;
        mData = NULL;
    }
    pthread_mutex_unlock(&mDataLock);

    RemoveAllListener();
    pthread_mutex_destroy(&mWorkLock);
    pthread_mutex_destroy(&mListenersLock);
    pthread_mutex_destroy(&mDataLock);
    pthread_cond_destroy(&mCv);
    pthread_cond_destroy(&mDataCv);
}

UInt32 CSession::AddRef()
{
    return ElLightRefBase::AddRef();
}

UInt32 CSession::Release()
{
    return ElLightRefBase::Release();
}

void StreamStateChanged(
    ElaSession *ws,
    int stream,
    ElaStreamState state,
    void *context)
{
    const char *state_name[] = {
        "raw",
        "initialized",
        "transport_ready",
        "connecting",
        "connected",
        "deactivated",
        "closed",
        "failed"
    };

    RPC_LOG("Stream [%d] state changed to: %s\n", stream, state_name[state]);

    CSession* pThis = (CSession*)context;
    if (!pThis) return;

    if (state == ElaStreamState_initialized) {
        pThis->SessionRequest();
    }
    else if (state == ElaStreamState_connected) {
        pThis->NotifySessionConnected(TRUE);
    }
    else if (state == ElaStreamState_transport_ready) {
        if (!pThis->mInitiator) {
            pThis->SessionStart();
        }
    }
    else if (state == ElaStreamState_deactivated
        || state == ElaStreamState_closed
        || state == ElaStreamState_failed) {
        pThis->NotifySessionConnected(FALSE);

        if (pThis->mWaitingForData) {
            if (pThis->mData) {
                if (pThis->mData->data)
                    ArrayOf<Byte>::Free(pThis->mData->data);
                delete pThis->mData;
                pThis->mData = NULL;
            }

            pThis->mData = new DataPack();
            if (!pThis->mData) {
                pthread_mutex_unlock(&pThis->mDataLock);
                return;
            }

            pThis->mData->data = NULL;
            pThis->mData->ec = E_SESSION_FAILED;
            pthread_mutex_unlock(&pThis->mDataLock);
            pthread_cond_signal(&pThis->mDataCv);
        }
    }
}

void SessionRequestComplete(
    ElaSession *ws,
    int status,
    const char *reason,
    const char *sdp,
    size_t len,
    void *context)
{
    RPC_LOG("Session complete, status: %d, reason: %s, tid: %d\n", status,
           reason ? reason : "null", gettid());

    if (status != 0)
        return;

    CSession* pThis = (CSession*)context;
    if (!pThis) return;

    pThis->SessionComplete(reason, sdp, len);
}

void StreamReceiveData(
    ElaSession *ws,
    int stream,
    const void *data,
    size_t len,
    void *context)
{
    RPC_LOG("Stream %d received data len: %d\n", stream, len);

    CSession* pThis = (CSession*)context;
    if (!pThis) return;

    pthread_mutex_lock(&pThis->mDataLock);
    if (!pThis->mWaitingForData) {
        pthread_mutex_unlock(&pThis->mDataLock);

        CSession::MessageNode* node;
        ECode ec = pThis->CreateMessageNode(data, len, MESSAGE_TYPE_DATA, &node);
        if (FAILED(ec)) {
            return;
        }

        pthread_mutex_lock(&pThis->mWorkLock);
        pThis->mMessageQueue.InsertPrev(node);
        pthread_mutex_unlock(&pThis->mWorkLock);
        pthread_cond_signal(&pThis->mCv);

        return;
    }

    if (pThis->mData) {
        if (pThis->mData->data)
            ArrayOf<Byte>::Free(pThis->mData->data);
        delete pThis->mData;
        pThis->mData = NULL;
    }

    pThis->mData = new DataPack();
    if (!pThis->mData) {
        pthread_mutex_unlock(&pThis->mDataLock);
        return;
    }

    pThis->mData->data = ArrayOf<Byte>::Alloc(len);
    if (!pThis->mData->data) {
        pthread_mutex_unlock(&pThis->mDataLock);
        return;
    }
    memcpy(pThis->mData->data->GetPayload(), data, len);
    pThis->mData->ec = NOERROR;
    pthread_mutex_unlock(&pThis->mDataLock);
    pthread_cond_signal(&pThis->mDataCv);
}

ECode CSession::Connect(
    /* [in] */ Boolean initiator)
{
    if (mElaSession != NULL) {
        return NOERROR;
    }

    mInitiator = initiator;


    IFriend* pFriend;
    ECode ec = mCarrier->GetFriend(mUid, &pFriend);
    if (FAILED(ec)) return ec;

    Boolean online;
    ec = pFriend->IsOnline(&online);
    pFriend->Release();
    if (FAILED(ec)) return ec;

    if (!online) {
        RPC_LOG("session connect friend: %s is not online\n", mUid.string());
        return E_FAIL;
    }

    mElaSession = ela_session_new(mElaCarrier, mUid);
    if (!mElaSession) {
        RPC_LOG("Create session failed.\n");
        return E_FAIL;
    } else {
        RPC_LOG("Create session successfully.\n");
    }

    ElaStreamCallbacks callbacks;

    memset(&callbacks, 0, sizeof(callbacks));
    callbacks.state_changed = StreamStateChanged;
    callbacks.stream_data = StreamReceiveData;

    mStream = ela_session_add_stream(mElaSession, ElaStreamType_text,
                ELA_STREAM_RELIABLE, &callbacks, this);
    if (mStream < 0) {
        ela_session_close(mElaSession);
        mElaSession = NULL;
        RPC_LOG("Add stream failed.\n");
        return E_FAIL;
    }
    else {
        RPC_LOG("Add stream successfully and stream id %d.\n", mStream);
    }

    return NOERROR;
}

Boolean CSession::IsConnected()
{
    ElaStreamState state;
    ela_stream_get_state(mElaSession, mStream, &state);
    return state == ElaStreamState_connected;
}

ECode CSession::SendMessage(
    int type,
    void* msg,
    size_t len)
{
    RPC_LOG("CSession::SendMessage type: %d", type);
    if (mElaCarrier == NULL) {
        return E_FAIL;
    }

    size_t msgLen = len + sizeof(int);
    ArrayOf<Byte>* data = ArrayOf<Byte>::Alloc(msgLen);
    if (data == NULL) {
        return E_OUT_OF_MEMORY;
    }

    Byte* p = data->GetPayload();
    memcpy(p, &type, sizeof(int));
    p += sizeof(int);
    if (msg != NULL) {
        memcpy(p, msg, len);
        p += len;
    }


    int rc = ela_stream_write(mElaSession, mStream,
                                data->GetPayload(), msgLen);
    ArrayOf<Byte>::Free(data);
    if (rc > 0) {
        RPC_LOG("Send message success stream[%d] len[%d].",
                                mStream, msgLen);
        return NOERROR;
    }
    else {
        RPC_LOG("Send message failed(0x%x).", ela_get_error());
        return rc;
    }
}

ECode CSession::ReceiveMessage(
    /* [out] */ Int32* pType,
    /* [out] */ void** pBuf,
    /* [out] */ Int32* pLen)
{
    if (!pType) {
        return E_INVALID_ARGUMENT;
    }

    pthread_mutex_lock(&mDataLock);
    mWaitingForData = TRUE;
    if (mData) {
        if (mData->data)
            ArrayOf<Byte>::Free(mData->data);
        delete mData;
        mData = NULL;
    }

    while(mData == NULL) {
        pthread_cond_wait(&mDataCv, &mDataLock);
    }
    
    mWaitingForData = FALSE;
    if (mData == NULL) {
        pthread_mutex_unlock(&mDataLock);
        return E_FAIL;
    }

    if (FAILED(mData->ec)) {
        ECode ec = mData->ec;
        if (mData->data)
            ArrayOf<Byte>::Free(mData->data);
        delete mData;
        mData = NULL;
        pthread_mutex_unlock(&mDataLock);
        return ec;
    }

    Byte* p = mData->data->GetPayload();
    int _len = mData->data->GetLength();
    int _type = *(size_t *)p;
    p += sizeof(size_t);
    _len -= sizeof(size_t);

    RPC_LOG("CSession::ReceiveMessage type: %d", _type);
    *pType = _type;
    if (pBuf != NULL) {
        void* _base = malloc(_len);
        if (_base == NULL) {
            ArrayOf<Byte>::Free(mData->data);
            delete mData;
            mData = NULL;
            pthread_mutex_unlock(&mDataLock);
            return E_FAIL;
        }
        memcpy(_base, p, _len);
        *pBuf = _base;
        *pLen = _len;
    }

    pthread_mutex_unlock(&mDataLock);

    return NOERROR;
}

ECode CSession::AddListener(
    /* [in] */ SessionListener* pListener,
    /* [in] */ void* context)
{
    if (!pListener) {
        return E_INVALID_ARGUMENT;
    }

    if (FindListener(pListener, context)) {
        return NOERROR;
    }

    pthread_mutex_lock(&mListenersLock);
    ListenerNode* node = new ListenerNode(pListener, context);
    if (!node) {
        pthread_mutex_unlock(&mListenersLock);
        return E_OUT_OF_MEMORY;
    }
    mListeners.InsertFirst(node);
    pthread_mutex_unlock(&mListenersLock);

    return NOERROR;
}

ECode CSession::RemoveListener(
    /* [in] */ SessionListener* pListener,
    /* [in] */ void* context)
{
    if (!pListener) {
        return E_INVALID_ARGUMENT;
    }

    ListenerNode* node = FindListener(pListener, context, TRUE);
    if (!node) return NOERROR;

    delete node;
    return NOERROR;
}

ECode CSession::RemoveAllListener()
{
    pthread_mutex_lock(&mListenersLock);
    if (!mListeners.IsEmpty()) {
        ListenerNode* head = &mListeners;
        ListenerNode* next = (ListenerNode*)mListeners.Next();
        while(next != head) {
            next->Detach(head);
            delete next;
            next = (ListenerNode*)mListeners.Next();
        }
    }
    pthread_mutex_unlock(&mListenersLock);
    pthread_mutex_destroy(&mListenersLock);

    return NOERROR;
}

ECode CSession::GetUid(
    /* [out] */ String* pUid)
{
    if (!pUid) {
        return E_INVALID_ARGUMENT;
    }

    *pUid = mUid;
    return NOERROR;
}

CSession::ListenerNode* CSession::FindListener(
    /* [in] */ SessionListener* pListener,
    /* [in] */ void* context,
    /* [in] */ Boolean detach)
{
    pthread_mutex_lock(&mListenersLock);
    if (mListeners.IsEmpty()) {
        pthread_mutex_unlock(&mListenersLock);
        return NULL;
    }

    ListenerNode* head = &mListeners;
    ListenerNode* next = (ListenerNode*)mListeners.Next();
    ListenerNode* prev = &mListeners;
    while(next != head) {
        if (next->mListener == pListener && next->mContext == context) {
            if (detach) next->Detach(prev);
            pthread_mutex_unlock(&mListenersLock);
            return next;
        }

        prev = next;
        next = (ListenerNode*)next->Next();
    }
    pthread_mutex_unlock(&mListenersLock);

    return NULL;
}

ECode CSession::SessionRequest()
{
    int ret;
    if (mInitiator) {
        ret = ela_session_request(mElaSession,
                             SessionRequestComplete, this);
        if (ret < 0) {
            RPC_LOG("session request failed.\n");
        }
        else {
            RPC_LOG("session request successfully.\n");
        }
    }
    else {
        ret = ela_session_reply_request(mElaSession, 0, NULL);
        if (ret < 0) {
            RPC_LOG("Session response invite failed:%x.\n", ela_get_error());
        }
        else {
            RPC_LOG("Session response invite successuflly.\n");
        }
    }

    if (ret < 0) {
        SessionDestroy();
        NotifySessionConnected(FALSE);
    }

    return ret;
}

ECode CSession::SessionStart()
{
    int ret = ela_session_start(mElaSession, mRemoteSdp, mSdpLen);
    RPC_LOG("Session start %s.\n", ret == 0 ? "success" : "failed");
    if (ret != 0) {
        SessionDestroy();
        NotifySessionConnected(FALSE);
    }

    ret = pthread_create(&mWorkThread, NULL, workThread, (void*)this);
    if (ret != 0) {
        RPC_LOG("Create thread failed\n");
    }

    return NOERROR;
}

ECode CSession::SessionComplete(
    const char *reason,
    const char *sdp,
    size_t len)
{
    strncpy(mRemoteSdp, sdp, len);
    mRemoteSdp[len] = 0;
    mSdpLen = len;

    return SessionStart();
}

ECode CSession::SessionDestroy()
{
    if (mElaSession != NULL) {
        ela_session_close(mElaSession);
        mElaSession = NULL;
    }

    return NOERROR;
}

ECode CSession::NotifySessionConnected(
    /* [in] */ Boolean succeeded)
{
    pthread_mutex_lock(&mListenersLock);
    if (mListeners.IsEmpty()) {
        pthread_mutex_unlock(&mListenersLock);
        return NOERROR;
    }

    ListenerNode* head = &mListeners;
    ListenerNode* next = (ListenerNode*)mListeners.Next();
    while(next != head) {
        next->mListener->OnSessionConnected(this, succeeded, next->mContext);
        next = (ListenerNode*)next->Next();
    }
    pthread_mutex_unlock(&mListenersLock);

    return NOERROR;
}

ECode CSession::NotifySessionReceived(
    /* [in] */ RPCMessage* msg)
{
    pthread_mutex_lock(&mListenersLock);
    if (mListeners.IsEmpty()) {
        pthread_mutex_unlock(&mListenersLock);
        return NOERROR;
    }

    ListenerNode* head = &mListeners;
    ListenerNode* next = (ListenerNode*)mListeners.Next();
    while(next != head) {
        next->mListener->OnSessionReceived(this, msg->GetData(), next->mContext);
        next = (ListenerNode*)next->Next();
    }
    pthread_mutex_unlock(&mListenersLock);
    return NOERROR;
}

ECode CSession::CreateMessageNode(
    /* [in] */ const void* data,
    /* [in] */ Int32 len,
    /* [in] */ Int32 type,
    /* [out] */ MessageNode** ppNode)
{
    if (!ppNode) return E_INVALID_ARGUMENT;

    RPCMessage* msg = new RPCMessage(data, len, type);
    if (!msg) return E_OUT_OF_MEMORY;

    MessageNode* node = new MessageNode(msg);
    if (!node) {
        delete msg;
        return E_OUT_OF_MEMORY;
    }

    *ppNode = node;
    return NOERROR;
}

ECode CSession::ClearMessageQuere()
{
    if (mMessageQueue.IsEmpty()) {
        return NOERROR;
    }

    pthread_mutex_lock(&mWorkLock);
    MessageNode* next = (MessageNode*)mMessageQueue.Next();
    while(next != &mMessageQueue) {
        next->Detach();
        delete next;
        next = (MessageNode*)mMessageQueue.Next();
    }
    pthread_mutex_unlock(&mWorkLock);

    return NOERROR;
}
