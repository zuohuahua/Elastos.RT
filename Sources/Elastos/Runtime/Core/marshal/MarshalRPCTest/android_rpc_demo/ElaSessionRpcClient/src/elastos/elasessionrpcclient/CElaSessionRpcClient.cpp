
#include "CElaSessionRpcClient.h"

namespace Elastos {
namespace ElaSessionRpcClient {


CAR_OBJECT_IMPL(CElaSessionRpcClient)
CAR_INTERFACE_IMPL(CElaSessionRpcClient, Object, IElaSessionRpcClient);

ECode CElaSessionRpcClient::AddFriend(
    /* [in] */ const String& address,
    /* [in] */ const String& hello,
    /* [out] */ Int32* result)
{
    *result = mCarrierProxy->AddFriend(address, hello);
    return NOERROR;
}

ECode CElaSessionRpcClient::AcceptRequest(
    /* [in] */ const String& userid)
{
    return mCarrierProxy->AcceptRequest(userid);
}

ECode CElaSessionRpcClient::CreateElaSession(
    /* [in] */ const String& userid)
{
    return mCarrierProxy->CreateElaSession(userid);
}

ECode CElaSessionRpcClient::constructor()
{
    mCarrierProxy = CarrierProxy::GetInstance();
    return NOERROR;
}

ECode CElaSessionRpcClient::CreateCarrierNodeWithSession()
{
    return mCarrierProxy->CreateCarrierNodeWithSession();
}

ECode CElaSessionRpcClient::InitElaSession()
{
    return mCarrierProxy->InitElaSession();
}

ECode CElaSessionRpcClient::ReplySessionRequest(
    /* [in] */ Boolean agree)
{
    return mCarrierProxy->ReplySessionRequest(agree);
}

ECode CElaSessionRpcClient::SessionRequest()
{
    return mCarrierProxy->SessionRequest();
}

ECode CElaSessionRpcClient::SetCarrierNodeListener(
    /* [in] */ ICarrierNodeListener* listener)
{
    assert(mCarrierProxy != NULL);
    return mCarrierProxy->SetCarrierNodeListener(listener);
}

ECode CElaSessionRpcClient::SendMessage(
    /* [in] */ const String& userid,
    /* [in] */ const String& msg)
{
    return mCarrierProxy->SendMessage(userid, msg);
}

ECode CElaSessionRpcClient::GetAddress(
    /* [out] */ String* address)
{
    return mCarrierProxy->GetAddress(address);
}

}
}
