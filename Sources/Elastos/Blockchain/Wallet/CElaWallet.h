
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
        /* [in] */ Double amount,
        /* [in] */ Double fee,
        /* [in] */ const String& payPassword,
        /* [in] */ const String& memo,
        /* [out] */ String * pTransactionMsg);

    CARAPI SendRawTransaction(
        /* [in] */ const String& transactionJson,
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

    CARAPI SendTransaction(
        /* [in] */ const String& fromAddress,
        /* [in] */ const String& toAddress,
        /* [in] */ Double amount,
        /* [in] */ Double fee,
        /* [in] */ const String& payPassword,
        /* [in] */ const String& memo,
        /* [out] */ String * pTxid);

    CARAPI GetTransactionsCount(
        /* [out] */ Int32 * pCount);

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
        /* [in] */ const String& publicKey,
        /* [in] */ const String& message,
        /* [in] */ const String& signature,
        /* [out] */ String * pResultJson);

    CARAPI constructor();

private:
    // TODO: Add your private member variables here.
};


#endif // __ELASTOS_WALLET_CELAWALLET_H__
