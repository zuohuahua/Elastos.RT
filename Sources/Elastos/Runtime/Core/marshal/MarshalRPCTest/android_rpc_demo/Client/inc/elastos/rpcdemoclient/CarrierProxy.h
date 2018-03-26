
#ifndef __ELASTOS_PRCDEMOCLIENT_CORRIERPROXY_H__
#define __ELASTOS_PRCDEMOCLIENT_CORRIERPROXY_H__

#include "elastos/core/Object.h"
#include "_Elastos.RpcDemoClient.h"
#include <unistd.h>
#include <ela_carrier.h>
#include <ela_session.h>

using Elastos::RpcDemoClient::ICarrierNodeListener;

class CarrierProxy : public Object
{
public:
    CarrierProxy();

    ~CarrierProxy();

    CARAPI_(String) GetAddress();

    CARAPI_(void) AddFriend(
        /* [in] */ const String& address,
        /* [in] */ const String& hello);

    CARAPI SendMsg(
        /* [in] */ const String& msg,
        /* [in] */ const String& userid);

    CARAPI_(String) GetUserId();

    CARAPI SetCarrierNodeListener(
        /* [in] */ ICarrierNodeListener* listener);

private:
    static void *S_ServiceRoutine(void *arg);

public:
    static AutoPtr<ICarrierNodeListener> mCarrierNodeListener;
    static Boolean sIsReady;
    static String sAnotherUserID;

private:
    ElaCarrier* mElaCarrierNode;
    pthread_t m_threadID;
};

#endif // __ELASTOS_PRCDEMOCLIENT_CORRIERPROXY_H__
