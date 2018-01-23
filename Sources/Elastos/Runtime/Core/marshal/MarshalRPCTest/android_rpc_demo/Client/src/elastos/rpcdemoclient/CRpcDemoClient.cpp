
#include "CRpcDemoClient.h"
#include "log.h"

static const Int32 ELASTOS_DEFAULT_PORT = 2345;
static const String ELASTOS_RPC_DEMO_SERVICE("Elastos.Droid.Rpc.Demo.Service");

namespace Elastos {
namespace RpcDemoClient {

CAR_OBJECT_IMPL(CRpcDemoClient)
CAR_INTERFACE_IMPL(CRpcDemoClient, Object, IRpcDemoClient);

CRpcDemoClient::CRpcDemoClient()
    : mIamServer(FALSE)
    , mPort(0)
{}

ECode CRpcDemoClient::constructor(
    /* [in] */ const String& ip,
    /* [in] */ Boolean isServer)
{
    return constructor(ip, ELASTOS_DEFAULT_PORT, isServer);
}

ECode CRpcDemoClient::constructor(
    /* [in] */ const String& ip,
    /* [in] */ Int32 port,
    /* [in] */ Boolean isServer)
{
    mIP = ip;
    mPort = port;
    mIamServer = isServer;
    if (port <= 0) {
        mPort = ELASTOS_DEFAULT_PORT;
    }

    return NOERROR;
}

ECode CRpcDemoClient::Connect(
    /* [out] */ Boolean* succeed)
{
    *succeed = FALSE;

    //server needs to be registered to itself
    mLocalClient = new SManC();
    if (mIamServer) {
        //Self server, it will accept the other client to connect it.
        //Connect a local server
        mSelfServer = new SManS(mPort);
        assert(mSelfServer != NULL);

        //marshal itself
        if (mLocalClient->Connect(mIP, mPort)) {
            *succeed = TRUE;
            return mLocalClient->AddService(ELASTOS_RPC_DEMO_SERVICE, IRpcDemoClient::Probe(this));
        }

        return NOERROR;
    }


    //Connect the remote server
    *succeed = mLocalClient->Connect(mIP, mPort);

    return NOERROR;
}

ECode CRpcDemoClient::Chat(
    /* [in] */ const String& text)
{
    return NOERROR;
}

ECode CRpcDemoClient::SetTag(
    /* [in] */ const String& tag)
{
    LOGD("[%s]===================line=[%d], tag=[%s]\n", __FUNCTION__, __LINE__, tag.string());
    if (mIamServer) {
        mTag = tag;
        return NOERROR;
    }
    AutoPtr<IInterface> obj;
    mLocalClient->GetService(ELASTOS_RPC_DEMO_SERVICE, (IInterface**)&obj);
    return IRpcDemoClient::Probe(obj)->SetTag(tag);
}

ECode CRpcDemoClient::GetTag(
    /* [out] */ String* tag)
{
    if (mIamServer) {
        *tag = mTag;
        return NOERROR;
    }

    AutoPtr<IInterface> obj;
    mLocalClient->GetService(ELASTOS_RPC_DEMO_SERVICE, (IInterface**)&obj);
    return IRpcDemoClient::Probe(obj)->GetTag(tag);
}

}
}
