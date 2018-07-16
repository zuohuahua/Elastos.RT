
#ifndef __ELASTOS_DID_ELADID_H__
#define __ELASTOS_DID_ELADID_H__

#include "elastos/core/Object.h"
#include "Elastos.DID.h"
#include "idid.h"

class ElaDID
    : public Object
    , public IDID
{
public:
    CAR_INTERFACE_DECL()

    ElaDID(
        /* [in] */ Elastos::DID::IDID* did);

    CARAPI GetDIDName (
        /* [out] */ String* did);

    CARAPI SetValue (
        /* [in] */ const String& keyPath,
        /* [in] */ const String& valueJson);

    CARAPI GetValue (
        /* [in] */ const String& keyPath,
        /* [out] */ String* valueJson);

    CARAPI GetHistoryValue (
        /* [in] */ const String& keyPath,
        /* [out] */ String* valuesListJson);

    CARAPI GetAllKeys (
        /* [in] */ Int32 start,
        /* [in] */ Int32 count,
        /* [out] */ String* keyListJson);

    CARAPI Sign (
        /* [in] */ const String& message,
        /* [in] */ const String& password,
        /* [out] */ String* signature);

    CARAPI GenerateProgram(
        /* [in] */ const String& message,
        /* [in] */ const String& password,
        /* [out] */ String* resultJson);

    CARAPI CheckSign (
        /* [in] */ const String& message,
        /* [in] */ const String& signature,
        /* [out] */ String* resultJson);

    CARAPI GetPublicKey(
        /* [out] */ String* publicKey);

private:
    Elastos::DID::IDID* mDid;
};

#endif // __ELASTOS_DID_ELADID_H__
