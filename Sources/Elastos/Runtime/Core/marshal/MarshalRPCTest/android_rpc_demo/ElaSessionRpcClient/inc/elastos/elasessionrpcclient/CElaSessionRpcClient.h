
#ifndef __ELASTOS_ELASESSIONRPCCLIENT_CELASESSIONRPCCLIENT_H__
#define __ELASTOS_ELASESSIONRPCCLIENT_CELASESSIONRPCCLIENT_H__

#include "_Elastos_ElaSessionRpcClient_CElaSessionRpcClient.h"
#include <elastos/core/Object.h>
#include "CarrierProxy.h"

namespace Elastos {
namespace ElaSessionRpcClient {

CarClass(CElaSessionRpcClient)
    , public Object
    , public IElaSessionRpcClient
{
public:
    CAR_OBJECT_DECL();

    CAR_INTERFACE_DECL();

    CARAPI constructor();

    CARAPI GetAddress(
        /* [out] */ String* address);

    CARAPI CreateCarrierNodeWithSession();

    CARAPI AddFriend(
        /* [in] */ const String& address,
        /* [in] */ const String& hello,
        /* [out] */ Int32* result);

    CARAPI AcceptRequest(
        /* [in] */ const String& userid);

    CARAPI CreateElaSession(
        /* [in] */ const String& userid);

    CARAPI SessionRequest();

    CARAPI InitElaSession();

    CARAPI SendMessage(
        /* [in] */ const String& userid,
        /* [in] */ const String& msg);

    CARAPI SetCarrierNodeListener(
        /* [in] */ ICarrierNodeListener* listener);

    CARAPI ReplySessionRequest(
        /* [in] */ Boolean agree);

private:
    AutoPtr<CarrierProxy> mCarrierProxy;
};

}
}

#endif // __ELASTOS_ELASESSIONRPCCLIENT_CELASESSIONRPCCLIENT_H__
