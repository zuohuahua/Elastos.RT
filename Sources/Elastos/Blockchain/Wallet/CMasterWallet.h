
#ifndef __ELASTOS_WALLET_CMASTERWALLET_H__
#define __ELASTOS_WALLET_CMASTERWALLET_H__

#include "_CMasterWallet.h"
#include "elastos/core/Object.h"


CarClass(CMasterWallet)
    , public Object
    , public IMasterWallet
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    CARAPI CreateSubWallet (
        /* [in] */ const String& chainID,
        /* [in] */ Int32 cointypeIndex,
        /* [in] */ const String& payPassword,
        /* [in] */ Boolean singleAddress,
        /* [out] */ ISubWallet** wallet);

    CARAPI RecoverSubWallet (
        /* [in] */ const String& chainID,
        /* [in] */ Int32 cointypeIndex,
        /* [in] */ const String& payPassword,
        /* [in] */ Boolean singleAddress,
        /* [in] */ Int32 limitGap,
        /* [out] */ ISubWallet** wallet);

    CARAPI DestroyWallet (
        /* [in] */ ISubWallet* wallet);

    CARAPI GetPublicKey (
        /* [out] */ String* publicKey);

    CARAPI constructor();

private:
    // TODO: Add your private member variables here.
};


#endif // __ELASTOS_WALLET_CMASTERWALLET_H__
