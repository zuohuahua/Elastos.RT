
#include "MainchainSubWallet.h"

extern const char* ToStringFromJson(nlohmann::json jsonValue);
extern nlohmann::json ToJosnFromString(const char* str);

CAR_INTERFACE_IMPL(MainchainSubWallet, SubWallet, IMainchainSubWallet)
MainchainSubWallet::MainchainSubWallet(
    /* [in] */ Elastos::ElaWallet::ISubWallet* subWallet)
    : SubWallet(subWallet)
{}

ECode MainchainSubWallet::CreateDepositTransaction(
    /* [in] */ const String& fromAddress,
    /* [in] */ const String& toAddress,
    /* [in] */ Int64 amount,
    /* [in] */ const String& sidechainAccountsJson,
    /* [in] */ const String& sidechainAmountsJson,
    /* [in] */ const String& sidechainIndexsJson,
    /* [in] */ Int64 fee,
    /* [in] */ const String& memo,
    /* [in] */ const String& remark,
    /* [out] */ String* txidJson)
{
    VALIDATE_NOT_NULL(txidJson);
    Elastos::ElaWallet::IMainchainSubWallet* mainchainSubWallet = (Elastos::ElaWallet::IMainchainSubWallet*)(void*)mSpvSubWallet;
    assert(mainchainSubWallet != NULL);

    nlohmann::json json = mainchainSubWallet->CreateDepositTransaction(fromAddress.string(), toAddress.string(), amount
            , ToJosnFromString(sidechainAccountsJson.string()), ToJosnFromString(sidechainAmountsJson.string()),
            ToJosnFromString(sidechainIndexsJson.string()), fee, memo.string(), remark.string());
    *txidJson = String(ToStringFromJson(json));
    return NOERROR;
}
