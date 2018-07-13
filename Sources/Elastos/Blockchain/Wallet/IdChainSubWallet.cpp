
#include "IdChainSubWallet.h"

extern const char* ToStringFromJson(nlohmann::json jsonValue);
extern nlohmann::json ToJosnFromString(const char* str);

CAR_INTERFACE_IMPL(IdChainSubWallet, SidechainSubWallet, IIdChainSubWallet)
IdChainSubWallet::IdChainSubWallet(
    /* [in] */ Elastos::ElaWallet::ISubWallet* subWallet)
    : SidechainSubWallet(subWallet)
{}

ECode IdChainSubWallet::CreateIdTransaction(
    /* [in] */ const String& fromAddress,
    /* [in] */ const String& toAddress,
    /* [in] */ Int64 amount,
    /* [in] */ const String& payloadJson,
    /* [in] */ const String& programJson,
    /* [in] */ Int64 fee,
    /* [in] */ const String& memo,
    /* [in] */ const String& remark,
    /* [out] */ String* result)
{
    VALIDATE_NOT_NULL(result);
    Elastos::ElaWallet::IIdChainSubWallet* idchainSubWallet = (Elastos::ElaWallet::IIdChainSubWallet*)(void*)mSpvSubWallet;
    assert(idchainSubWallet != NULL);

    nlohmann::json json = idchainSubWallet->CreateIdTransaction(fromAddress.string(), toAddress.string(), amount,
        ToJosnFromString(payloadJson.string()) , ToJosnFromString(programJson.string()), fee, memo.string(), remark.string());
    *result = String(ToStringFromJson(json));
    return NOERROR;
}
