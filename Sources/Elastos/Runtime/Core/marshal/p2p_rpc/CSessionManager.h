
#ifndef __C_SESSION_MANAGER_H__
#define __C_SESSION_MANAGER_H__

#include <elastos.h>
#include <elrefbase.h>
#include <elcontainer.h>
#include <elspinlock.h>
#include "session.h"
#include "carrier.h"

class CManagerListener
    : public ElLightRefBase
{
public:
    virtual void OnSessionRequest(
        /* [in] */ ICarrier* pCarrier,
        /* [in] */ const char *from,
        /* [in] */ const char *sdp,
        /* [in] */ size_t len,
        /* [in] */ void *context) = 0;

    virtual void OnSessionReceived(
        /* [in] */ CSession* pSession,
        /* [in] */ ArrayOf<Byte>* data,
        /* [in] */ void *context) = 0;

    CARAPI_(UInt32) AddRef();

    CARAPI_(UInt32) Release();
};

class CSessionManager
    : public ElLightRefBase
{
public:
    static ECode AcquireInstance(
        /* [out] */ CSessionManager** ppManager);

public:
    CSessionManager(
        /* [in] */ ICarrier* pCarrier);

    ~CSessionManager();

    CARAPI_(UInt32) AddRef();

    CARAPI_(UInt32) Release();

    ECode CreateSession(
        /* [in] */ const String& uid,
        /* [in] */ Boolean initiator,
        /* [in] */ const char *sdp,
        /* [in] */ size_t len,
        /* [in] */ CSession** ppSession);

    ECode GetSession(
        /* [in] */ const String& uid,
        /* [out] */ CSession** ppSession);

    // listeners only for stub there
    ECode AddListener(
        /* [in] */ CManagerListener* pListener,
        /* [in] */ void* context);

    ECode RemoveListener(
        /* [in] */ CManagerListener* pListener,
        /* [in] */ void* context);

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
            /* [in] */ CManagerListener* pListener,
            /* [in] */ void* context)
        {
            mListener = pListener;
            mListener->AddRef();
            mContext = context;
        }

        ~ListenerNode()
        {
            if (mListener)
                mListener->Release();
        }

    public:
        CManagerListener* mListener;
        void* mContext;
    };

    class SessionNode
        : public SLinkNode
    {
    public:
        SessionNode()
            : mSession(NULL)
        {}

        SessionNode(
            /* [in] */ CSession* pSession)
        {
            mSession = pSession;
            mSession->AddRef();
        }

        ~SessionNode()
        {
            if (mSession)
                mSession->Release();
        }

    public:
        CSession* mSession;
    };

    class CReceiveListener
        : public CSessionListener
    {
    public:
        void OnSessionConnected(
            /* [in] */ Boolean succeeded,
            /* [in] */ void* context);

        void OnSessionReceived(
            /* [in] */ CSession* pSession,
            /* [in] */ ArrayOf<Byte>* data,
            /* [in] */ void* context);
    };

private:

    ListenerNode* FindListener(
        /* [in] */ CManagerListener* pListener,
        /* [in] */ void* context,
        /* [in] */ Boolean detach = FALSE);

    ECode InitSession();

private:
    static CSessionManager* sInstance;
    static SpinLock sInstanceLock;

    static ICarrier* sCarrier;

    static ListenerNode sListeners;
    static pthread_mutex_t sListenersLock;

private:
    SessionNode mSessions;
    pthread_mutex_t mSessionsLock;

    CReceiveListener* mReceiveListener;

    friend void SessionRequestCallback(
        ElaCarrier *w,
        const char *from,
        const char *sdp,
        size_t len,
        void *context);
};


#endif //__C_SESSION_MANAGER_H__
