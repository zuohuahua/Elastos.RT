
#ifndef __CTC_H__
#define __CTC_H__

#include "_CTC.h"
#include "elastos/core/Object.h"

using Elastos::Core::IComparable;
using Elastos::Core::EIID_IComparable;


CarClass(CTC)
    , public Object
    , public ITC
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    CARAPI Get(
        /* [out] */ Int32 * pI);

    CARAPI Set(
        /* [in] */ Int32 i);

    CARAPI Increment();

    CARAPI Decrement();

    CARAPI GetString(
        /* [out] */ String* str);

    CARAPI SetString(
        /* [in] */ const String& str);

    CARAPI GetBoolean(
        /* [out] */ Boolean* b);

    CARAPI SetBoolean(
        /* [in] */ Boolean b);

    CARAPI GetInt64(
        /* [out] */ Int64* i);

    CARAPI SetInt64(
        /* [in] */ Int64 i);

    CARAPI GetDouble(
        /* [out] */ Double* d);

    CARAPI SetDouble(
        /* [in] */ Double d);

    CARAPI GetArrayOf(
        /* [out, callee] */ ArrayOf<Int32>** array);

    CARAPI SetArrayOf(
        /* [in] */ const ArrayOf<Int32>& array);

    CARAPI constructor(
        /* [in] */ Int32 i);

private:
    // TODO: Add your private member variables here.
    Int32 m_i;
    String m_str;
    Int64 m_i64;
    Boolean m_b;
    Double m_d;
    ArrayOf<Int32>* mArray;
};


#endif // __CTC_H__
