
#include "CDIDManager.h"
#include "MasterWallet.h"
#include "ElaDID.h"
#include "IdManagerFactory.h"

String ToStringFromJson(nlohmann::json jsonValue);

CAR_OBJECT_IMPL(CDIDManager)
CAR_INTERFACE_IMPL(CDIDManager, Object, IDIDManager);
CDIDManager::CDIDManager()
    : mIDIDMgr(NULL)
{}

CDIDManager::~CDIDManager()
{
    if (mIDIDMgr) {
        delete mIDIDMgr;
    }

    std::map<const char*, DIDManagerCallback*, compare_string>::iterator it = mIdManagerCallbacksMap.begin();
    for (; it != mIdManagerCallbacksMap.end(); ++it) {
        DIDManagerCallback* callback = it->second;
        if (callback) callback->Release();
    }

    std::map<const char*, IDID*, compare_string>::iterator iter = mDIDsMap.begin();
    for (; iter != mDIDsMap.end(); ++iter) {
        IDID* did = iter->second;
        if (did) did->Release();
    }
}

ECode CDIDManager::CreateDID(
    /* [in] */ const String& password,
    /* [out] */ IDID ** ppDid)
{
    VALIDATE_NOT_NULL(ppDid);
    VALIDATE_NOT_NULL(mIDIDMgr);
    Elastos::DID::IDID* did = mIDIDMgr->CreateDID(password.string());
    VALIDATE_NOT_NULL(did);
    *ppDid = new ElaDID(did);
    if ((*ppDid) == NULL) {
        return E_OUT_OF_MEMORY;
    }

    std::string didName = did->GetDIDName();
    mDIDsMap[didName.c_str()] = *ppDid;
    (*ppDid)->AddRef();
    return NOERROR;
}

ECode CDIDManager::GetDID(
    /* [in] */ const String& didName,
    /* [out] */ IDID ** ppDid)
{
    VALIDATE_NOT_NULL(ppDid);
    VALIDATE_NOT_NULL(mIDIDMgr);
    *ppDid = NULL;

    std::map<const char*, IDID*, compare_string>::iterator iter = mDIDsMap.find(didName.string());
    if (iter != mDIDsMap.end()) {
        *ppDid = iter->second;
        return NOERROR;
    }

    Elastos::DID::IDID* did = mIDIDMgr->GetDID(didName.string());
    VALIDATE_NOT_NULL(did);
    *ppDid = new ElaDID(did);
    if ((*ppDid) == NULL) {
        return E_OUT_OF_MEMORY;
    }

    mDIDsMap[didName.string()] = *ppDid;
    (*ppDid)->AddRef();
    return NOERROR;
}

ECode CDIDManager::GetDIDList(
    /* [out] */ String * pDidListJson)
{
    VALIDATE_NOT_NULL(pDidListJson);
    VALIDATE_NOT_NULL(mIDIDMgr);
    nlohmann::json jsonValue = mIDIDMgr->GetDIDList();
    *pDidListJson = ToStringFromJson(jsonValue);
    return NOERROR;
}

ECode CDIDManager::DestoryDID(
    /* [in] */ const String& did)
{
    VALIDATE_NOT_NULL(mIDIDMgr);
    mIDIDMgr->DestoryDID(did.string());
    return NOERROR;
}

ECode CDIDManager::RegisterCallback(
    /* [in] */ const String& did,
    /* [in] */ IDIDManagerCallback * pDidcallback)
{
    VALIDATE_NOT_NULL(pDidcallback);
    VALIDATE_NOT_NULL(mIDIDMgr);

    std::map<const char*, DIDManagerCallback*, compare_string>::iterator iter = mIdManagerCallbacksMap.find(did.string());
    if (iter == mIdManagerCallbacksMap.end()) {
        AutoPtr<DIDManagerCallback> callback = new DIDManagerCallback(pDidcallback);
        if (callback == NULL) return E_OUT_OF_MEMORY;
        mIDIDMgr->RegisterCallback(did.string(), callback);
        mIdManagerCallbacksMap[did.string()] = callback.Get();
        callback->AddRef();
    }

    return NOERROR;
}

ECode CDIDManager::UnregisterCallback(
    /* [in] */ const String& did)
{
    VALIDATE_NOT_NULL(mIDIDMgr);

    std::map<const char*, DIDManagerCallback*, compare_string>::iterator iter = mIdManagerCallbacksMap.find(did.string());
    if (iter != mIdManagerCallbacksMap.end()) {
        mIDIDMgr->UnregisterCallback(did.string());
        iter->second->Release();
        mIdManagerCallbacksMap.erase(iter);
    }

    return NOERROR;
}

ECode CDIDManager::constructor(
    /* [in] */ IMasterWallet * pMasterWallet,
    /* [in] */ const String& rootPath)
{
    VALIDATE_NOT_NULL(pMasterWallet);
    if (rootPath.IsNullOrEmpty()) {
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }

    Elastos::ElaWallet::IMasterWallet* masterWallet = ((MasterWallet*)pMasterWallet)->GetSpvMasterWallet();
    VALIDATE_NOT_NULL(masterWallet);

    Elastos::DID::IdManagerFactory idFactory;
    mIDIDMgr = idFactory.CreateIdManager(masterWallet, rootPath.string());
    VALIDATE_NOT_NULL(mIDIDMgr);

    return NOERROR;
}

CDIDManager::DIDManagerCallback::DIDManagerCallback(
    /* [in] */ IDIDManagerCallback* callback)
    : mCallback(callback)
{}

void CDIDManager::DIDManagerCallback::OnIdStatusChanged(
        /* [in] */ const std::string &id,
        /* [in] */ const std::string &path,
        /* [in] */ const nlohmann::json &value)
{
    assert(mCallback != NULL);
    mCallback->OnIdStatusChanged(String(id.c_str()), String(path.c_str()), ToStringFromJson(value));
}

String ToStringFromJson(nlohmann::json jsonValue)
{
    const char* value = jsonValue.dump().c_str();
    if (!strcmp(value, "null")) {
        return String(NULL);
    }

    return String(value);
}

nlohmann::json ToJosnFromString(const char* str)
{
    nlohmann::json jsonValue;
    std::stringstream ss;
    ss << str;
    jsonValue << ss;
    return jsonValue;
}
