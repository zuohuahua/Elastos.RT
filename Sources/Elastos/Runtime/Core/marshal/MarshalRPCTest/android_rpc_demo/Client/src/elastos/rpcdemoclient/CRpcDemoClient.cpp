
#include "CRpcDemoClient.h"

static const Int32 ELASTOS_DEFAULT_PORT = 2345;
static const String ELASTOS_RPC_DEMO_SERVICE("Elastos.Droid.Rpc.Demo.Service");

namespace Elastos {
namespace RpcDemoClient {

CAR_OBJECT_IMPL(CRpcDemoClient)
CAR_INTERFACE_IMPL(CRpcDemoClient, Object, IRpcDemoClient);

CRpcDemoClient::CRpcDemoClient()
    : mIamServer(FALSE)
{
    mCarrierProxy = new CarrierProxy();
}

ECode CRpcDemoClient::constructor()
{
    return NOERROR;
}

ECode CRpcDemoClient::Connect(
    /* [in] */ const String& ip,
    /* [in] */ Boolean isServer,
    /* [out] */ Boolean* succeed)
{
    *succeed = FALSE;

    mIamServer = isServer;
    Int32 port = ELASTOS_DEFAULT_PORT;

    //server needs to be registered to itself
    if (mLocalClient == NULL) {
        mLocalClient = new SManC();
    }

    if (mIamServer) {
        //Self server, it will accept the other client to connect it.
        //Connect a local server
        if (mSelfServer == NULL) {
            mSelfServer = new SManS(port);
        }
        assert(mSelfServer != NULL);

        //marshal itself
        if (mLocalClient->Connect(ip, port)) {
            *succeed = TRUE;
            return mLocalClient->AddService(ELASTOS_RPC_DEMO_SERVICE, IRpcDemoClient::Probe(this));
        }

        return NOERROR;
    }

    //Connect the remote server
    *succeed = mLocalClient->Connect(ip, port);

    return NOERROR;
}

ECode CRpcDemoClient::GetAddress(
    /* [in] */ Boolean isSelf,
    /* [out] */ String* address)
{
    assert(mCarrierProxy != NULL);
    if (isSelf || mIamServer) {
        *address = mCarrierProxy->GetAddress();
        return NOERROR;
    }

    AutoPtr<IInterface> obj;
    mLocalClient->GetService(ELASTOS_RPC_DEMO_SERVICE, (IInterface**)&obj);
    return IRpcDemoClient::Probe(obj)->GetAddress(FALSE, address);
}

ECode CRpcDemoClient::AddFriend(
    /* [in] */ const String& address,
    /* [in] */ const String& hello)
{
    mCarrierProxy->AddFriend(address, hello);
    return NOERROR;
}

ECode CRpcDemoClient::SendMsg(
    /* [in] */ const String& msg)
{
    String userid;
    if (mIamServer) {
        userid = CarrierProxy::sAnotherUserID;
    }
    else {
        GetUserId(&userid);
    }
    mCarrierProxy->SendMsg(msg, userid);
    return NOERROR;
}

ECode CRpcDemoClient::SendMsg(
    /* [in] */ const String& userid,
    /* [in] */ const String& msg)
{
    mCarrierProxy->SendMsg(msg, userid);
    return NOERROR;
}

ECode CRpcDemoClient::GetUserId(
    /* [out] */ String* userid)
{
    assert(mCarrierProxy != NULL);
    if (mIamServer) {
        *userid = mCarrierProxy->GetUserId();
        return NOERROR;
    }

    AutoPtr<IInterface> obj;
    mLocalClient->GetService(ELASTOS_RPC_DEMO_SERVICE, (IInterface**)&obj);
    return IRpcDemoClient::Probe(obj)->GetUserId(userid);
}

ECode CRpcDemoClient::SetCarrierNodeListener(
    /* [in] */ ICarrierNodeListener* listener)
{
    assert(mCarrierProxy != NULL);
    return mCarrierProxy->SetCarrierNodeListener(listener);
}

}
}
