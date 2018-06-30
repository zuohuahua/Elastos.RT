
#ifndef __ELASTOS_WALLET_MASTERWALLET_H__
#define __ELASTOS_WALLET_MASTERWALLET_H__

#include "elastos/core/Object.h"
#include "Elastos.Wallet.h"
#include "IMasterWallet.h"

class MasterWallet
    : public Object
    , public IMasterWallet
{
public:
    CAR_INTERFACE_DECL()

    MasterWallet(
        /* [in] */ Elastos::ElaWallet::IMasterWallet* spvMasterWallet);

    CARAPI GetId(
        /* [out] */ String* id);

    CARAPI GetAllSubWallets(
        /* [out, callee] */ ArrayOf<ISubWallet*>** subWallets);

    CARAPI CreateSubWallet(
        /* [in] */ const String& chainID,
        /* [in] */ const String& payPassword,
        /* [in] */ Boolean singleAddress,
        /* [in] */ Int64 feePerKb,
        /* [out] */ ISubWallet** subWallet);

    CARAPI RecoverSubWallet(
        /* [in] */ const String& chainID,
        /* [in] */ const String& payPassword,
        /* [in] */ Boolean singleAddress,
        /* [in] */ Int32 limitGap,
        /* [in] */ Int64 feePerKb,
        /* [out] */ ISubWallet** subWallet);

    CARAPI DestroyWallet(
        /* [in] */ ISubWallet *wallet);

    CARAPI GetPublicKey(
        /* [out] */ String* publicKey);

    CARAPI Sign(
        /* [in] */ const String& message,
        /* [in] */ const String& payPassword,
        /* [out] */ String* result);

    CARAPI CheckSign(
        /* [in] */ const String& publicKey,
        /* [in] */ const String& message,
        /* [in] */ const String& signature,
        /* [out] */ String* resultJson);

    CARAPI IsAddressValid(
        /* [in] */ const String& address,
        /* [out] */ Boolean* valid);

    CARAPI GetSupportedChains(
        /* [out, callee] */ ArrayOf<String>** supportedChains);

    CARAPI ChangePassword(
        /* [in] */ const String& oldPassword,
        /* [in] */ const String& newPassword);

    CARAPI ResetAddressCache(
        /* [in] */ const String& payPassword);

    Elastos::ElaWallet::IMasterWallet* GetSpvMasterWallet();

private:
    Elastos::ElaWallet::IMasterWallet* mSpvMasterWallet;
};

#endif // __ELASTOS_WALLET_MASTERWALLET_H__
