
#include "SubWallet.h"
#include "MainchainSubWallet.h"
#include "IdChainSubWallet.h"
#include "SidechainSubWallet.h"
#include <sstream>

const char* ToStringFromJson(nlohmann::json jsonValue);
nlohmann::json ToJosnFromString(const char* str);

SubWallet::SubWallet(
    /* [in] */ Elastos::ElaWallet::ISubWallet* spvSubWallet)
    : mSpvSubWallet(spvSubWallet)
{}

SubWallet::~SubWallet()
{}

PInterface SubWallet::Probe(
    /* [in] */ REIID riid)
{
    if (riid == EIID_ISubWallet) {
        return (ISubWallet*)this;
    }
    else if (riid == EIID_IMainchainSubWallet) {
        return (IMainchainSubWallet*)(MainchainSubWallet*)this;
    }
    else if (riid == EIID_ISidechainSubWallet) {
        return (ISidechainSubWallet*)(SidechainSubWallet*)this;
    }
    else if (riid == EIID_IIdChainSubWallet) {
        return (IIdChainSubWallet*)(IdChainSubWallet*)this;
    }

    return NULL;
}

UInt32 SubWallet::AddRef()
{
    return ElRefBase::AddRef();
}

UInt32 SubWallet::Release()
{
    return ElRefBase::Release();
}

ECode SubWallet::GetInterfaceID(
    /* [in] */ IInterface* object,
    /* [out] */ InterfaceID* iid)
{
    VALIDATE_NOT_NULL(iid);
    if (object == (IInterface *)(ISubWallet *)this) {
        *iid = EIID_ISubWallet;
    }
    if (object == (IInterface *)(IMainchainSubWallet *)this) {
        *iid = EIID_IMainchainSubWallet;
    }
    if (object == (IInterface *)(ISidechainSubWallet *)this) {
        *iid = EIID_ISidechainSubWallet;
    }
    if (object == (IInterface *)(IIdChainSubWallet *)this) {
        *iid = EIID_IIdChainSubWallet;
    }
    else {
        return E_INVALID_ARGUMENT;
    }
    return NOERROR;
}

ECode SubWallet::GetChainId(
    /* [out] */ String* id)
{
    VALIDATE_NOT_NULL(id);
    std::string result = mSpvSubWallet->GetChainId();
    *id = String(result.c_str());
    return NOERROR;
}

ECode SubWallet::GetBalanceInfo (
    /* [out] */ String* balanceInfoJson)
{
    VALIDATE_NOT_NULL(balanceInfoJson);
    nlohmann::json result = mSpvSubWallet->GetBalanceInfo();
    *balanceInfoJson = String(ToStringFromJson(result));
    return NOERROR;
}

ECode SubWallet::GetBalance (
    /* [out] */ Int64* balance)
{
    VALIDATE_NOT_NULL(balance);
    *balance = mSpvSubWallet->GetBalance();
    return NOERROR;
}

ECode SubWallet::CreateAddress (
    /* [out] */ String* address)
{
    VALIDATE_NOT_NULL(address);
    std::string result = mSpvSubWallet->CreateAddress();
    *address = String(result.c_str());
    return NOERROR;
}

ECode SubWallet::GetAllAddress (
    /* [in] */ Int32 start,
    /* [in] */ Int32 count,
    /* [out] */ String* addressesJson)
{
    VALIDATE_NOT_NULL(addressesJson);
    nlohmann::json addresses = mSpvSubWallet->GetAllAddress(start, count);
    *addressesJson = String(ToStringFromJson(addresses));
    return NOERROR;
}

ECode SubWallet::GetBalanceWithAddress (
    /* [in] */ const String& address,
    /* [out] */ Int64* balance)
{
    VALIDATE_NOT_NULL(balance);
    *balance = mSpvSubWallet->GetBalanceWithAddress(address.string());
    return NOERROR;
}

ECode SubWallet::AddCallback (
    /* [in] */ ISubWalletListener* listener)
{
    VALIDATE_NOT_NULL(listener);
    AutoPtr<SubWalletCallback> callback = new SubWalletCallback(listener);
    if (callback == NULL) return E_OUT_OF_MEMORY;

    mSpvSubWallet->AddCallback(callback);
    ECode ec = AddSubWalletCallbackNode(callback);
    if (FAILED(ec)) {
        mSpvSubWallet->RemoveCallback(callback);
    }

    return ec;
}

ECode SubWallet::RemoveCallback (
    /* [in] */ ISubWalletListener* listener)
{
    VALIDATE_NOT_NULL(listener);
    AutoPtr<SubWalletCallback> callback = new SubWalletCallback(listener);
    if (callback == NULL) return E_OUT_OF_MEMORY;

    mSpvSubWallet->RemoveCallback(callback);
    RemoveSubWalletCallbackNode(callback);
    return NOERROR;
}

ECode SubWallet::CreateTransaction (
    /* [in] */ const String& fromAddress,
    /* [in] */ const String& toAddress,
    /* [in] */ Int64 amount,
    /* [in] */ Int64 fee,
    /* [in] */ const String& memo,
    /* [in] */ const String& remark,
    /* [out] */ String* txidJson)
{
    VALIDATE_NOT_NULL(txidJson);
    nlohmann::json result = mSpvSubWallet->CreateTransaction(fromAddress.string(), toAddress.string(), amount
            , fee, memo.string(), remark.string());
    *txidJson = String(ToStringFromJson(result));
    return NOERROR;
}

ECode SubWallet::CreateMultiSignAddress (
    /* [in] */ const String& multiPublicKeyJson,
    /* [in] */ Int32 totalSignNum,
    /* [in] */ Int32 requiredSignNum,
    /* [out] */ String* multiSignAddress)
{
    VALIDATE_NOT_NULL(multiSignAddress);
    std::string result = mSpvSubWallet->CreateMultiSignAddress(ToJosnFromString(multiPublicKeyJson.string()), totalSignNum, requiredSignNum);
    *multiSignAddress = String(result.c_str());
    return NOERROR;
}

ECode SubWallet::CreateMultiSignTransaction (
    /* [in] */ const String& fromAddress,
    /* [in] */ const String& toAddress,
    /* [in] */ Int64 amount,
    /* [in] */ Int64 fee,
    /* [in] */ const String& memo,
    /* [out] */ String* transactionJson)
{
    VALIDATE_NOT_NULL(transactionJson);
    nlohmann::json result = mSpvSubWallet->CreateMultiSignTransaction(fromAddress.string(), toAddress.string()
                , amount, fee, memo.string());
    *transactionJson = String(ToStringFromJson(result));
    return NOERROR;
}

ECode SubWallet::SendRawTransaction (
    /* [in] */ const String& transactionJson,
    /* [in] */ Int64 fee,
    /* [in] */ const String& payPassword,
    /* [out] */ String* txidJson)
{
    VALIDATE_NOT_NULL(txidJson);
    nlohmann::json result = mSpvSubWallet->SendRawTransaction(ToJosnFromString(transactionJson.string()), fee, payPassword.string());
    *txidJson = String(ToStringFromJson(result));
    return NOERROR;
}

ECode SubWallet::GetAllTransaction (
    /* [in] */ Int32 start,
    /* [in] */ Int32 count,
    /* [in] */ const String& addressOrTxid,
    /* [out] */ String* transactionListJson)
{
    VALIDATE_NOT_NULL(transactionListJson);
    nlohmann::json result = mSpvSubWallet->GetAllTransaction(start, count, addressOrTxid.string());
    *transactionListJson = String(ToStringFromJson(result));
    return NOERROR;
}

ECode SubWallet::Sign (
    /* [in] */ const String& message,
    /* [in] */ const String& payPassword,
    /* [out] */ String* signature)
{
    VALIDATE_NOT_NULL(signature);
    std::string result = mSpvSubWallet->Sign(message.string(), payPassword.string());
    *signature = String(result.c_str());
    return NOERROR;
}

ECode SubWallet::CheckSign (
    /* [in] */ const String& address,
    /* [in] */ const String& message,
    /* [in] */ const String& signature,
    /* [out] */ String* resultJson)
{
    VALIDATE_NOT_NULL(resultJson);
    nlohmann::json result = mSpvSubWallet->CheckSign(address.string(), message.string(), signature.string());
    *resultJson = String(ToStringFromJson(result));
    return NOERROR;
}

ECode SubWallet::CalculateTransactionFee(
    /* [in] */ const String& rawTransaction,
    /* [in] */ Int64 feePerKb,
    /* [out] */ Int64* fee)
{
    VALIDATE_NOT_NULL(fee);
    *fee = mSpvSubWallet->CalculateTransactionFee(ToJosnFromString(rawTransaction.string()), feePerKb);
    return NOERROR;
}

const char* ToStringFromJson(nlohmann::json jsonValue)
{
    const char* value = jsonValue.dump().c_str();
    if (!strcmp(value, "null")) {
        return NULL;
    }

    return value;
}

nlohmann::json ToJosnFromString(const char* str)
{
    nlohmann::json jsonValue;
    std::stringstream ss;
    ss << str;
    jsonValue << ss;
    return jsonValue;
}

SubWallet::SubWalletCallback::SubWalletCallback(
    /* [in] */ ISubWalletListener* callback)
    : mCallback(callback)
{}

void SubWallet::SubWalletCallback::OnTransactionStatusChanged(
    /* [in] */ const std::string &txid,
    /* [in] */ const std::string &status,
    /* [in] */ const nlohmann::json &desc,
    /* [in] */ uint32_t confirms)
{
    if (mCallback == NULL) return;
    mCallback->OnTransactionStatusChanged(String(txid.c_str()), String(status.c_str()), String(ToStringFromJson(desc)), confirms);
}

ECode SubWallet::AddSubWalletCallbackNode(
    /* [in] */ SubWalletCallback* callback)
{
    pthread_mutex_lock(&mCallbacksLock);
    SubWalletCallbackNode* it = &mCallbacks;
    it = (SubWalletCallbackNode*)(it->Next());
    for (; NULL != it; it = (SubWalletCallbackNode*)(it->Next())) {
        if (it->mListener.Get() == callback) {
            pthread_mutex_unlock(&mCallbacksLock);
            return NOERROR;
        }
    }

    SubWalletCallbackNode* listenerNode = new SubWalletCallbackNode;
    if (listenerNode == NULL) return E_OUT_OF_MEMORY;
    listenerNode->mListener = callback;
    mCallbacks.InsertFirst(listenerNode);
    pthread_mutex_unlock(&mCallbacksLock);
    return NOERROR;
}

void SubWallet::RemoveSubWalletCallbackNode(
    /* [in] */ SubWalletCallback* callback)
{
    pthread_mutex_lock(&mCallbacksLock);
    SubWalletCallbackNode* prev = &mCallbacks;
    SubWalletCallbackNode* head = &mCallbacks;
    SubWalletCallbackNode* it = (SubWalletCallbackNode*)(head->Next());
    for (; NULL != it; it = (SubWalletCallbackNode*)(it->Next())) {
        if (it->mListener.Get() == callback) {
            it->mListener = NULL;

            if (it != head) {
                it->Detach(prev);
                delete it;
            }

            pthread_mutex_unlock(&mCallbacksLock);
            return;
        }
        prev = it;
    }

    pthread_mutex_unlock(&mCallbacksLock);
}
