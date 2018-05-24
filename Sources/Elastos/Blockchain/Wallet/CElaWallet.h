
#ifndef __ELASTOS_WALLET_CELAWALLET_H__
#define __ELASTOS_WALLET_CELAWALLET_H__

#include "_CElaWallet.h"
#include "elastos/core/Object.h"


CarClass(CElaWallet)
    , public Object
    , public ISubWallet
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    CARAPI GetBalanceInfo(
        /* [out] */ String * pBalanceInfoJson);

    CARAPI GetBalance(
        /* [out] */ Double * pBalance);

    CARAPI GetBalanceWithAddress(
        /* [in] */ const String& address,
        /* [out] */ Double * pBalance);

    CARAPI CreateAddress(
        /* [out] */ String * pAddress);

    CARAPI CreateMultiSignAddress(
        /* [in] */ const String& multiPublicKeyJson,
        /* [in] */ Int32 totalSignNum,
        /* [in] */ Int32 requiredSignNum,
        /* [out] */ String * pMultiSignAddress);

    CARAPI GenerateMultiSignTransation(
        /* [in] */ const String& fromAddress,
        /* [in] */ const String& toAddress,
        /* [in] */ Double amount,
        /* [in] */ Double fee,
        /* [in] */ const String& payPassword,
        /* [in] */ const String& memo,
        /* [out] */ String * pTransationMsg);

    CARAPI SendRawTransation(
        /* [in] */ const String& transationJson,
        /* [in] */ const String& sign,
        /* [out] */ String * pTxid);

    CARAPI GetAddressesCount(
        /* [out] */ Int32 * pCount);

    CARAPI GetAllAddress(
        /* [in] */ Int32 start,
        /* [in] */ Int32 count,
        /* [out] */ String * pAddressListJson);

    CARAPI AddCallback(
        /* [in] */ ISubWalletCallback * pSubCallback);

    CARAPI RemoveCallback(
        /* [in] */ ISubWalletCallback * pSubCallback);

    CARAPI SendTransation(
        /* [in] */ const String& fromAddress,
        /* [in] */ const String& toAddress,
        /* [in] */ Double amount,
        /* [in] */ Double fee,
        /* [in] */ const String& payPassword,
        /* [in] */ const String& memo,
        /* [out] */ String * pTxid);

    CARAPI GetTransationsCount(
        /* [out] */ Int32 * pCount);

    CARAPI GetAllTransation(
        /* [in] */ Int32 start,
        /* [in] */ Int32 count,
        /* [in] */ const String& addressOrTxid,
        /* [out] */ String * pTransationListJson);

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


#endif // __ELASTOS_WALLET_CELAWALLET_H__
