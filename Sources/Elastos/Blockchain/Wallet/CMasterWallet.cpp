
#include "CMasterWallet.h"


CAR_OBJECT_IMPL(CMasterWallet)
CAR_INTERFACE_IMPL(CMasterWallet, Object, IMasterWallet);

ECode CMasterWallet::CreateSubWallet (
    /* [in] */ const String& chainID,
    /* [in] */ Int32 cointypeIndex,
    /* [in] */ const String& payPassword,
    /* [in] */ Boolean singleAddress,
    /* [out] */ ISubWallet** wallet)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CMasterWallet::RecoverSubWallet (
    /* [in] */ const String& chainID,
    /* [in] */ Int32 cointypeIndex,
    /* [in] */ const String& payPassword,
    /* [in] */ Boolean singleAddress,
    /* [in] */ Int32 limitGap,
    /* [out] */ ISubWallet** wallet)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CMasterWallet::DestroyWallet (
    /* [in] */ ISubWallet* wallet)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CMasterWallet::GetPublicKey (
    /* [out] */ String* publicKey)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CMasterWallet::constructor()
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}
