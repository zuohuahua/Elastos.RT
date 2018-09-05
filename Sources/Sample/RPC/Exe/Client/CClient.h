
#ifndef __CCLIENT_H__
#define __CCLIENT_H__

#include "_CClient.h"
#include "elastos/core/Object.h"

using Elastos::Core::IComparable;
using Elastos::Core::EIID_IComparable;

#ifdef _android
#include <android/log.h>
#define CLIENT_LOG(...) __android_log_print(ANDROID_LOG_DEBUG, "RPCClient", __VA_ARGS__)
#else
#define CLIENT_LOG printf
#endif

class CCarrierListener
        : public Object
        , public ICarrierListener
{
public:

    CAR_INTERFACE_DECL()

    CCarrierListener(
        CClient* client)
    {
        mClient = client;
    }

    virtual ~CCarrierListener()
    {}

    CARAPI OnIdle();

    CARAPI OnConnectionChanged(
        /* [in] */ Boolean online);

    CARAPI OnReady();

    CARAPI OnFriendRequest(
        /* [in] */ const String& uid,
        /* [in] */ const String& hello);

    CARAPI OnFriendConnectionChanged(
        /* [in] */ const String& uid,
        /* [in] */ Boolean online);

    CARAPI OnPortForwardingRequest(
        /* [in] */ const String &uid,
        /* [in] */ const String &servicePort,
        /* [out] */ Boolean *accept);

    CARAPI OnPortForwardingResult(
        /* [in] */ const String &uid,
        /* [in] */ const String &localPort,
        /* [in] */ const String &remotePort,
        /* [in] */ ECode code);

    CARAPI OnMessageReceived(
            /* [in] */ const String& uid,
            /* [in] */ const ArrayOf<Byte>& message);
private:
    CClient* mClient;
};

CarClass(CClient)
    , public Object
    , public IClient
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    CClient()
        : mCarrier(NULL)
        , mServiceManager(NULL)
        , mListener(NULL)
        , mFriendOnline(FALSE)
        , mOnline(FALSE)
    {}

    ~CClient();

    CARAPI GetService(
        /* [in] */ const String& name,
        /* [out] */ IInterface ** ppService);

    CARAPI constructor(
        /* [in] */ const String& path);

private:
    ICarrier* mCarrier;
    IServiceManager* mServiceManager;
    ICarrierListener* mListener;

    pthread_cond_t mCv;
    pthread_mutex_t mLock;
    Boolean mFriendOnline;
    Boolean mOnline;

friend class CCarrierListener;
};


#endif // __CCLIENT_H__
