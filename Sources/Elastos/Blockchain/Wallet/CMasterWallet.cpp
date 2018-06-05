
#include "CMasterWallet.h"


CAR_OBJECT_IMPL(CMasterWallet)
CAR_INTERFACE_IMPL(CMasterWallet, Object, IMasterWallet);

ECode CMasterWallet::CreateSubWallet(
    /* [in] */ SubWalletType type,
    /* [in] */ const String& chainID,
    /* [in] */ Int32 coinTypeIndex,
    /* [in] */ const String& payPassword,
    /* [in] */ Boolean singleAddress,
    /* [in] */ Int64 feePerKb,
    /* [out] */ ISubWallet ** ppWallet)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CMasterWallet::RecoverSubWallet(
    /* [in] */ SubWalletType type,
    /* [in] */ const String& chainID,
    /* [in] */ Int32 coinTypeIndex,
    /* [in] */ const String& payPassword,
    /* [in] */ Boolean singleAddress,
    /* [in] */ Int32 limitGap,
    /* [in] */ Int64 feePerKb,
    /* [out] */ ISubWallet ** ppWallet)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CMasterWallet::DestroyWallet(
    /* [in] */ ISubWallet * pWallet)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CMasterWallet::GetPublicKey(
    /* [out] */ String * pPublicKey)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CMasterWallet::Sign(
    /* [in] */ const String& message,
    /* [in] */ const String& payPassword,
    /* [out] */ String * pSignature)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CMasterWallet::CheckSign(
    /* [in] */ const String& address,
    /* [in] */ const String& message,
    /* [in] */ const String& signature,
    /* [out] */ String * pResultJson)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CMasterWallet::DeriveIdAndKeyForPurpose(
    /* [in] */ Int32 purpose,
    /* [in] */ Int32 index,
    /* [in] */ const String& payPassword,
    /* [out] */ String* id,
    /* [out] */ String* key)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CMasterWallet::constructor()
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}
