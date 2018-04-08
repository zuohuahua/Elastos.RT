
#ifndef __SESSION_H__
#define __SESSION_H__

#include "ela_carrier.h"
#include "ela_session.h"
#include <elcontainer.h>
#include <elrefbase.h>
#include "CMessage.h"

class CSession;

class CSessionListener
    : public ElLightRefBase
{
public:
    virtual void OnSessionConnected(
        /* [in] */ Boolean succeeded,
        /* [in] */ void* context) = 0;

    virtual void OnSessionReceived(
        /* [in] */ CSession* pSession,
        /* [in] */ ArrayOf<Byte>* data,
        /* [in] */ void* context) = 0;

    CARAPI_(UInt32) AddRef();

    CARAPI_(UInt32) Release();
};

class CSession
    : public ElLightRefBase
{
public:
    CSession(
        /* [in] */ ICarrier* pCarrier,
        /* [in] */ const char* uid,
        /* [in] */ const char *sdp,
        /* [in] */ size_t len);

    ~CSession();

    CARAPI_(UInt32) AddRef();

    CARAPI_(UInt32) Release();

    ECode Connect(
        /* [in] */ Boolean initiator);

    Boolean IsConnected();

    ECode SendMessage(
        /* [in] */ int type,
        /* [in] */ void* msg,
        /* [in] */ size_t len);

    ECode ReceiveMessage(
        /* [out] */ Int32* pType,
        /* [out] */ void** pBuf,
        /* [out] */ Int32* pLen);

    ECode AddListener(
        /* [in] */ CSessionListener* pListener,
        /* [in] */ void* context);

    ECode RemoveListener(
        /* [in] */ CSessionListener* pListener,
        /* [in] */ void* context);

    ECode RemoveAllListener();

    ECode GetUid(
        /* [out] */ String* pUid);

private:
    class ListenerNode
        : public SLinkNode
    {
    public:
        ListenerNode()
            : mListener(NULL)
            , mContext(NULL)
        {}

        ListenerNode(
            /* [in] */ CSessionListener* pListener,
            /* [in] */ void* context)
        {
            mListener = pListener;
            mListener->AddRef();
        }

        ~ListenerNode()
        {
            if (mListener)
                mListener->Release();
        }

    public:
        CSessionListener* mListener;
        void* mContext;
    };

    class MessageNode
        : public DLinkNode
    {
    public:
        MessageNode()
            : mMessage(NULL)
        {}

        MessageNode(
            /* [in] */ CMessage* msg)
        {
            mMessage = msg;
        }

        ~MessageNode()
        {
            if (mMessage)
                delete mMessage;
        }

    public:
        CMessage* mMessage;
    };

private:
    ListenerNode* FindListener(
        /* [in] */ CSessionListener* pListener,
        /* [in] */ void* context,
        /* [in] */ Boolean detach = FALSE);

    ECode SessionRequest();

    ECode SessionStart();

    ECode SessionComplete(
        const char *reason,
        const char *sdp,
        size_t len);

    ECode SessionDestroy();

    ECode NotifySessionConnected(
        /* [in] */ Boolean succeeded);

    ECode NotifySessionReceived(
        /* [in] */ CMessage* msg);

    ECode CreateMessageNode(
        /* [in] */ const void* data,
        /* [in] */ Int32 len,
        /* [in] */ Int32 type,
        /* [out] */ MessageNode** ppNode);

    ECode ClearMessageQuere();


private:
    ICarrier* mCarrier;
    ElaCarrier* mElaCarrier;
    String mUid;

    // session info
    ElaSession* mElaSession;
    int mStream;
    char mRemoteSdp[2048];
    size_t mSdpLen;

    Boolean mInitiator;

    ListenerNode mListeners;
    pthread_mutex_t mListenersLock;

    // work thread
    pthread_t mWorkThread;
    pthread_cond_t mCv;
    pthread_mutex_t mWorkLock;
    MessageNode mMessageQueue;

    // for receive data once
    pthread_cond_t mDataCv;
    pthread_mutex_t mDataLock;
    ArrayOf<Byte>* mData;
    Boolean mWaitingForData;

    friend void* workThread(void* argc);

    friend void StreamStateChanged(
        ElaSession *ws,
        int stream,
        ElaStreamState state,
        void *context);

    friend void SessionRequestComplete(
        ElaSession *ws,
        int status,
        const char *reason,
        const char *sdp,
        size_t len,
        void *context);

    friend void StreamReceiveData(
        ElaSession *ws,
        int stream,
        const void *data,
        size_t len,
        void *context);
};

#endif //__SESSION_H__
