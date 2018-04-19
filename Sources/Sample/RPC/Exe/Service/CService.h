
#ifndef __CSERVICE_H__
#define __CSERVICE_H__

#include "_CService.h"
#include "elastos/core/Object.h"

using Elastos::Core::IComparable;
using Elastos::Core::EIID_IComparable;

#ifdef _android
#include <android/log.h>
#define SERVICE_LOG(...) __android_log_print(ANDROID_LOG_DEBUG, "RPCService", __VA_ARGS__)
#else
#define SERVICE_LOG printf
#endif

class CService;

class CCarrierListener
        : public Object
        , public ICarrierListener
{
public:

    CAR_INTERFACE_DECL()

    CCarrierListener(
        CService* service)
    {
        mService = service;
    }

    virtual ~CCarrierListener()
    {}

    CARAPI OnConnectionChanged(
        /* [in] */ Boolean online);

    CARAPI OnReady();

    CARAPI OnFriendRequest(
        /* [in] */ const String& uid,
        /* [in] */ const String& hello);

    CARAPI OnFriendConnetionChanged(
        /* [in] */ const String& uid,
        /* [in] */ Boolean online);

private:
    CService* mService;
};

CarClass(CService)
    , public Object
    , public IService
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    CService()
        : mCarrier(NULL)
        , mServiceManager(NULL)
        , mListener(NULL)
        , mExit(FALSE)
    {}

    ~CService();

    CARAPI AddService(
        /* [in] */ const String& name,
        /* [in] */ IInterface * pIntreface);

    CARAPI Start();

    CARAPI constructor(
        /* [in] */ const String& path);

private:
    ICarrier* mCarrier;
    IServiceManager* mServiceManager;
    ICarrierListener* mListener;

    pthread_cond_t mCv;
    pthread_mutex_t mLock;
    Boolean mExit;

friend class CCarrierListener;
};


#endif // __CSERVICE_H__
