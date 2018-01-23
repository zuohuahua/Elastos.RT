
#ifndef __ELASTOS_PRCDEMOCLIENT_CRPCDEMOCLIENT_H__
#define __ELASTOS_PRCDEMOCLIENT_CRPCDEMOCLIENT_H__

#include "_Elastos_RpcDemoClient_CRpcDemoClient.h"
#include <elastos/core/Object.h>
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

    CARAPI constructor(
        /* [in] */ const String& ip,
        /* [in] */ Boolean isServer);

    CARAPI constructor(
        /* [in] */ const String& ip,
        /* [in] */ Int32 port,
        /* [in] */ Boolean isServer);

    CARAPI Connect(
        /* [out] */ Boolean* succeed);

    CARAPI Chat(
        /* [in] */ const String& text);

    CARAPI SetTag(
        /* [in] */ const String& tag);

    CARAPI GetTag(
        /* [out] */ String* tag);

private:
    AutoPtr<SManS> mSelfServer;
    AutoPtr<SManC> mLocalClient;
    Boolean mIamServer;
    String mIP;
    Int32 mPort;
    String mTag;
};

}
}

#endif // __ELASTOS_PRCDEMOCLIENT_CRPCDEMOCLIENT_H__
