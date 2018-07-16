
#ifndef __ELASTOS_DID_CDIDCHECKER_H__
#define __ELASTOS_DID_CDIDCHECKER_H__

#include "_CDIDChecker.h"
#include "elastos/core/Object.h"

CarClass(CDIDChecker)
    , public Object
    , public IDIDChecker
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    CARAPI GetValue(
        /* [in] */ const String& did,
        /* [in] */ const String& keyPath,
        /* [out] */ String * pValueJson);

    CARAPI GetHistoryValue(
        /* [in] */ const String& did,
        /* [in] */ const String& keyPath,
        /* [out] */ String * pValueListJson);

    CARAPI GetAllKeys(
        /* [in] */ const String& did,
        /* [in] */ Int32 start,
        /* [in] */ Int32 count,
        /* [out] */ String * pKeyListJson);

    CARAPI GetPublicKey(
        /* [in] */ const String& did,
        /* [out] */ String * pPublicKey);

    CARAPI CheckSign(
        /* [in] */ const String& did,
        /* [in] */ const String& publicKey,
        /* [in] */ const String& message,
        /* [in] */ const String& signature,
        /* [out] */ String * pResultJson);

    CARAPI CheckDID(
        /* [in] */ const String& did,
        /* [in] */ const String& nonce,
        /* [in] */ const String& appid,
        /* [in] */ const String& declaration,
        /* [in] */ const String& password,
        /* [out] */ String * pResultJson);

private:
    // TODO: Add your private member variables here.
};


#endif // __ELASTOS_DID_CDIDCHECKER_H__
