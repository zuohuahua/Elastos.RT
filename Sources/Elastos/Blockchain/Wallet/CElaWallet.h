
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
        /* [out] */ Int64 * pBalance);

    CARAPI GetBalanceWithAddress(
        /* [in] */ const String& address,
        /* [out] */ Int64 * pBalance);

    CARAPI CreateAddress(
        /* [out] */ String * pAddress);

    CARAPI CreateMultiSignAddress(
        /* [in] */ const String& multiPublicKeyJson,
        /* [in] */ Int32 totalSignNum,
        /* [in] */ Int32 requiredSignNum,
        /* [out] */ String * pMultiSignAddress);

    CARAPI GenerateMultiSignTransaction(
        /* [in] */ const String& fromAddress,
        /* [in] */ const String& toAddress,
        /* [in] */ Int64 amount,
        /* [in] */ Int64 fee,
        /* [in] */ const String& payPassword,
        /* [in] */ const String& memo,
        /* [out] */ String * pTransactionMsg);

    CARAPI SendRawTransaction(
        /* [in] */ const String& transactionJson,
        /* [in] */ const String& signJson,
        /* [out] */ String * pTxid);

    CARAPI GetAllAddress(
        /* [in] */ Int32 start,
        /* [in] */ Int32 count,
        /* [out] */ String * pAddressListJson);

    CARAPI AddCallback(
        /* [in] */ ISubWalletCallback * pSubCallback);

    CARAPI RemoveCallback(
        /* [in] */ ISubWalletCallback * pSubCallback);

    CARAPI SendTransaction(
        /* [in] */ const String& fromAddress,
        /* [in] */ const String& toAddress,
        /* [in] */ Int64 amount,
        /* [in] */ Int64 fee,
        /* [in] */ const String& payPassword,
        /* [in] */ const String& memo,
        /* [out] */ String * pTxid);

    CARAPI GetAllTransaction(
        /* [in] */ Int32 start,
        /* [in] */ Int32 count,
        /* [in] */ const String& addressOrTxid,
        /* [out] */ String * pTransactionListJson);

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
