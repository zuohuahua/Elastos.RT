
#include "ElaDID.h"

extern String ToStringFromJson(nlohmann::json jsonValue);
extern nlohmann::json ToJosnFromString(const char* str);

CAR_INTERFACE_IMPL(ElaDID, Object, IDID)
ElaDID::ElaDID(
    /* [in] */ Elastos::DID::IDID* did)
    : mDid(did)
{}

ECode ElaDID::GetDIDName (
    /* [out] */ String* did)
{
    VALIDATE_NOT_NULL(did);
    VALIDATE_NOT_NULL(mDid);
    std::string didName = mDid->GetDIDName();
    *did = String(didName.c_str());
    return NOERROR;
}

ECode ElaDID::SetValue (
    /* [in] */ const String& keyPath,
    /* [in] */ const String& valueJson)
{
    VALIDATE_NOT_NULL(mDid);
    mDid->SetValue(keyPath.string(), ToJosnFromString(valueJson.string()));
    return NOERROR;
}

ECode ElaDID::GetValue (
    /* [in] */ const String& keyPath,
    /* [out] */ String* valueJson)
{
    VALIDATE_NOT_NULL(valueJson);
    VALIDATE_NOT_NULL(mDid);
    nlohmann::json jsonValue = mDid->GetValue(keyPath.string());
    *valueJson = ToStringFromJson(jsonValue);
    return NOERROR;
}

ECode ElaDID::GetHistoryValue (
    /* [in] */ const String& keyPath,
    /* [out] */ String* valuesListJson)
{
    VALIDATE_NOT_NULL(valuesListJson);
    VALIDATE_NOT_NULL(mDid);
    nlohmann::json jsonValue = mDid->GetHistoryValue(keyPath.string());
    *valuesListJson = ToStringFromJson(jsonValue);
    return NOERROR;
}

ECode ElaDID::GetAllKeys (
    /* [in] */ Int32 start,
    /* [in] */ Int32 count,
    /* [out] */ String* keyListJson)
{
    VALIDATE_NOT_NULL(keyListJson);
    VALIDATE_NOT_NULL(mDid);
    nlohmann::json jsonValue = mDid->GetAllKeys(start, count);
    *keyListJson = ToStringFromJson(jsonValue);
    return NOERROR;
}

ECode ElaDID::Sign (
    /* [in] */ const String& message,
    /* [in] */ const String& password,
    /* [out] */ String* signature)
{
    VALIDATE_NOT_NULL(signature);
    VALIDATE_NOT_NULL(mDid);
    std::string value = mDid->Sign(message.string(), password.string());
    *signature = String(value.c_str());
    return NOERROR;
}

ECode ElaDID::GenerateProgram(
    /* [in] */ const String& message,
    /* [in] */ const String& password,
    /* [out] */ String* resultJson)
{
    VALIDATE_NOT_NULL(resultJson);
    VALIDATE_NOT_NULL(mDid);
    nlohmann::json jsonValue = mDid->GenerateProgram(message.string(), password.string());
    *resultJson = ToStringFromJson(jsonValue);
    return NOERROR;
}

ECode ElaDID::CheckSign(
    /* [in] */ const String& message,
    /* [in] */ const String& signature,
    /* [out] */ String* resultJson)
{
    VALIDATE_NOT_NULL(resultJson);
    VALIDATE_NOT_NULL(mDid);
    nlohmann::json jsonValue = mDid->CheckSign(message.string(), signature.string());
    *resultJson = ToStringFromJson(jsonValue);
    return NOERROR;
}

ECode ElaDID::GetPublicKey(
    /* [out] */ String* publicKey)
{
    VALIDATE_NOT_NULL(publicKey);
    VALIDATE_NOT_NULL(mDid);
    std::string value = mDid->GetPublicKey();
    *publicKey = String(value.c_str());
    return NOERROR;
}
