
#include "CElaWallet.h"


CAR_OBJECT_IMPL(CElaWallet)
CAR_INTERFACE_IMPL(CElaWallet, Object, ISubWallet);

ECode CElaWallet::GetBalanceInfo(
    /* [out] */ String * pBalanceInfoJson)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CElaWallet::GetBalance(
    /* [out] */ Int64 * pBalance)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CElaWallet::GetBalanceWithAddress(
    /* [in] */ const String& address,
    /* [out] */ Int64 * pBalance)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CElaWallet::CreateAddress(
    /* [out] */ String * pAddress)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CElaWallet::CreateMultiSignAddress(
    /* [in] */ const String& multiPublicKeyJson,
    /* [in] */ Int32 totalSignNum,
    /* [in] */ Int32 requiredSignNum,
    /* [out] */ String * pMultiSignAddress)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CElaWallet::GenerateMultiSignTransaction(
    /* [in] */ const String& fromAddress,
    /* [in] */ const String& toAddress,
    /* [in] */ Int64 amount,
    /* [in] */ Int64 fee,
    /* [in] */ const String& payPassword,
    /* [in] */ const String& memo,
    /* [out] */ String * pTransactionMsg)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CElaWallet::SendRawTransaction(
    /* [in] */ const String& transactionJson,
    /* [in] */ const String& signJson,
    /* [out] */ String * pTxid)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CElaWallet::GetAllAddress(
    /* [in] */ Int32 start,
    /* [in] */ Int32 count,
    /* [out] */ String * pAddressListJson)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CElaWallet::AddCallback(
    /* [in] */ ISubWalletCallback * pSubCallback)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CElaWallet::RemoveCallback(
    /* [in] */ ISubWalletCallback * pSubCallback)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CElaWallet::SendTransaction(
    /* [in] */ const String& fromAddress,
    /* [in] */ const String& toAddress,
    /* [in] */ Int64 amount,
    /* [in] */ Int64 fee,
    /* [in] */ const String& payPassword,
    /* [in] */ const String& memo,
    /* [out] */ String * pTxid)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CElaWallet::GetAllTransaction(
    /* [in] */ Int32 start,
    /* [in] */ Int32 count,
    /* [in] */ const String& addressOrTxid,
    /* [out] */ String * pTransactionListJson)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CElaWallet::Sign(
    /* [in] */ const String& message,
    /* [in] */ const String& payPassword,
    /* [out] */ String * pSignature)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CElaWallet::CheckSign(
    /* [in] */ const String& address,
    /* [in] */ const String& message,
    /* [in] */ const String& signature,
    /* [out] */ String * pResultJson)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CElaWallet::constructor()
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}
