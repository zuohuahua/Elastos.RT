
#ifndef __ELASTOS_ELASESSIONRPCCLIENT__CORRIERPROXY_H__
#define __ELASTOS_ELASESSIONRPCCLIENT__CORRIERPROXY_H__

#include "_Elastos.ElaSessionRpcClient.h"
#include <elastos/core/Object.h>
#include <unistd.h>
#include <ela_carrier.h>
#include <ela_session.h>

using Elastos::ElaSessionRpcClient::ICarrierNodeListener;

class CarrierProxy : public Object
{
public:
    static CARAPI_(CarrierProxy*) GetInstance();

    ~CarrierProxy();

    CARAPI GetAddress(
        /* [out] */ String* address);

    CARAPI CreateCarrierNodeWithSession();

    CARAPI CreateElaSession(
        /* [in] */ const String& userid);

    CARAPI_(Int32) AddFriend(
        /* [in] */ const String& address,
        /* [in] */ const String& hello);

    CARAPI AcceptRequest(
        /* [in] */ const String& userid);

    CARAPI SetCarrierNodeListener(
        /* [in] */ ICarrierNodeListener* listener);

    CARAPI_(void) AddSessionStream();

    CARAPI ReplySessionRequest(
        /* [in] */ Boolean agree);

    CARAPI InitElaSession();

    CARAPI SessionRequest();

    CARAPI SendMessage(
        /* [in] */ const String& userid,
        /* [in] */ const String& msg);

    static CARAPI_(void) TrySessionRequest();

private:
    CarrierProxy();

    static void *S_ServiceRoutine(void *arg);

    static Boolean sSessionIsReady();

public:
    Int32 mStreamId;
    static AutoPtr<ICarrierNodeListener> mCarrierNodeListener;
    static Boolean sIsOnline;
    static Boolean sStreamIsInitialized;

private:
    ElaCarrier* mElaCarrierNode;
    pthread_t m_threadID;
    static AutoPtr<CarrierProxy> sCarrierProxyInsttance;
};

#endif // __ELASTOS_ELASESSIONRPCCLIENT__CORRIERPROXY_H__
