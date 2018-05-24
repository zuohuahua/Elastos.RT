
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

    CARAPI CreateSubWallet(
        /* [in] */ const String& chainID,
        /* [in] */ Int32 cointypeIndex,
        /* [in] */ const String& payPassword,
        /* [in] */ Boolean singleAddress,
        /* [in] */ Int64 feePerKb,
        /* [out] */ ISubWallet ** ppWallet);

    CARAPI RecoverSubWallet(
        /* [in] */ const String& chainID,
        /* [in] */ Int32 cointypeIndex,
        /* [in] */ const String& payPassword,
        /* [in] */ Boolean singleAddress,
        /* [in] */ Int32 limitGap,
        /* [in] */ Int64 feePerKb,
        /* [out] */ ISubWallet ** ppWallet);

    CARAPI DestroyWallet(
        /* [in] */ ISubWallet * pWallet);

    CARAPI GetPublicKey(
        /* [out] */ String * pPublicKey);

    CARAPI Sign(
        /* [in] */ const String& message,
        /* [in] */ const String& payPassword,
        /* [out] */ String * pSignature);

    CARAPI CheckSign(
        /* [in] */ const String& address,
        /* [in] */ const String& message,
        /* [in] */ const String& signature,
        /* [out] */ String * pResultJson);

    CARAPI constructor();

private:
    // TODO: Add your private member variables here.
};


#endif // __ELASTOS_WALLET_CMASTERWALLET_H__
