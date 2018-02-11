
#ifndef __ELASTOS_PRCDEMOCLIENT_CRPCDEMOCLIENT_H__
#define __ELASTOS_PRCDEMOCLIENT_CRPCDEMOCLIENT_H__

#include "_Elastos_RpcDemoClient_CRpcDemoClient.h"
#include <elastos/core/Object.h>
#include "CarrierProxy.h"
#include "SManC.h"
#include "SManS.h"

namespace Elastos {
namespace RpcDemoClient {

CarClass(CRpcDemoClient)
    , public Object
    , public IRpcDemoClient
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    CRpcDemoClient();

    CARAPI constructor();

    CARAPI Connect(
        /* [in] */ const String& ip,
        /* [in] */ Boolean isServer,
        /* [out] */ Boolean* succeed);

    CARAPI GetAddress(
        /* [in] */ Boolean isSelf,
        /* [out] */ String* address);

    CARAPI AddFriend(
        /* [in] */ const String& address,
        /* [in] */ const String& hello);

    CARAPI SendMsg(
        /* [in] */ const String& msg);

    CARAPI SendMsg(
        /* [in] */ const String& userid,
        /* [in] */ const String& msg);

    CARAPI GetUserId(
        /* [out] */ String* userid);

    CARAPI SetCarrierNodeListener(
        /* [in] */ ICarrierNodeListener* listener);

private:
    AutoPtr<SManS> mSelfServer;
    AutoPtr<SManC> mLocalClient;
    Boolean mIamServer;
    AutoPtr<CarrierProxy> mCarrierProxy;
};

}
}

#endif // __ELASTOS_PRCDEMOCLIENT_CRPCDEMOCLIENT_H__
