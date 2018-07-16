
#include "CDIDChecker.h"

CAR_OBJECT_IMPL(CDIDChecker)
CAR_INTERFACE_IMPL(CDIDChecker, Object, IDIDChecker);
ECode CDIDChecker::GetValue(
    /* [in] */ const String& did,
    /* [in] */ const String& keyPath,
    /* [out] */ String * pValueJson)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CDIDChecker::GetHistoryValue(
    /* [in] */ const String& did,
    /* [in] */ const String& keyPath,
    /* [out] */ String * pValueListJson)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CDIDChecker::GetAllKeys(
    /* [in] */ const String& did,
    /* [in] */ Int32 start,
    /* [in] */ Int32 count,
    /* [out] */ String * pKeyListJson)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CDIDChecker::GetPublicKey(
    /* [in] */ const String& did,
    /* [out] */ String * pPublicKey)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CDIDChecker::CheckSign(
    /* [in] */ const String& did,
    /* [in] */ const String& publicKey,
    /* [in] */ const String& message,
    /* [in] */ const String& signature,
    /* [out] */ String * pResultJson)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CDIDChecker::CheckDID(
    /* [in] */ const String& did,
    /* [in] */ const String& nonce,
    /* [in] */ const String& appid,
    /* [in] */ const String& declaration,
    /* [in] */ const String& password,
    /* [out] */ String * pResultJson)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}
