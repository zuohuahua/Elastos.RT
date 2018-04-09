
#ifndef __CSERVICEMANAGER_H__
#define __CSERVICEMANAGER_H__


#include <elastos.h>
#include <elrefbase.h>
#include <elspinlock.h>
#include "../../reflection/hashtable.h"
#include "marshal.h"
#include "CSessionManager.h"
#include "elcarrierapi.h"

enum
{
    SESSION_CONNECT_FAILED = 1,
    SESSION_CONNECT_SUCCEEDED,
    SESSION_SERVICE_INFO,
};

class CServiceManager
    : public ElLightRefBase
    , public IServiceManager
{
public:
    static ECode AcquireInstance(
        /* [out] */ IServiceManager** manager);

public:
    CServiceManager();

    ~CServiceManager();

    CARAPI_(PInterface) Probe(
        /* [in] */ REIID riid);

    CARAPI_(UInt32) AddRef();

    CARAPI_(UInt32) Release();

    CARAPI GetInterfaceID(
        /* [in] */ IInterface* object,
        /* [out] */ InterfaceID* iid);

    CARAPI AddService(
        /* [in] */ const String& name,
        /* [in] */ IInterface * pService);

    CARAPI GetService(
        /* [in] */ const String& uid,
        /* [in] */ const String& name,
        /* [out] */ IInterface ** ppService);

private:
    class CSessionManagerListener
        : public CManagerListener
    {
    public:
        void OnSessionRequest(
            /* [in] */ ICarrier* pCarrier,
            /* [in] */ const char *from,
            /* [in] */ const char *sdp,
            /* [in] */ size_t len,
            /* [in] */ void *context);

        void OnSessionReceived(
            /* [in] */ CSession* pSession,
            /* [in] */ ArrayOf<Byte>* data,
            /* [in] */ void *context);
    };

    class CGetServiceListener
        : public SessionListener
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
    ECode GetService(
        /* [in] */ const String& name,
        /* [out] */ InterfacePack* pIp);
        
    ECode HandleGetService(
        /* [in] */ CSession* pSession,
        /* [in] */ const String& name);

private:
    static IServiceManager* sInstance;
    static SpinLock sInstanceLock;

    static HashTable<InterfacePack, Type_String> sServices;
    static pthread_mutex_t sServiceLock;

    static pthread_mutex_t sGetServiceMutex;
    static pthread_cond_t sGetServiceCv;

    static Int32 sNotifyType;
    static ArrayOf<Byte>* sData;

private:
    ICarrier* mCarrier;

    CSessionManager* mSessionManager;
    CSessionManagerListener* mListener;
};


#endif // __CSERVICEMANAGER_H__
