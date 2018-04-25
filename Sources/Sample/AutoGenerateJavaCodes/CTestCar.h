
#ifndef __CTESTCAR_H__
#define __CTESTCAR_H__

#include "_CTestCar.h"
#include "elastos/core/Object.h"
#include <jni.h>


CarClass(CTestCar)
    , public Object
    , public ITestCar
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    CARAPI SetInt(
        /* [in] */ Int32 value);

    CARAPI GetInt(
        /* [out] */ Int32 * pValue);

    CARAPI SetString(
        /* [in] */ const String& value);

    CARAPI GetString(
        /* [out] */ String * pValue);

    CARAPI Normal();

    CARAPI Test1(
        /* [in] */ Int32 value1,
        /* [in] */ Boolean value2,
        /* [in] */ Float value3,
        /* [in] */ Double value4,
        /* [in] */ Int64 value5,
        /* [in] */ Byte value6,
        /* [in] */ Char32 value7,
        /* [in] */ const String& value8);

    CARAPI Test2(
        /* [in] */ Int32 value1,
        /* [in] */ Boolean value2,
        /* [in] */ Float value3,
        /* [in] */ Double value4,
        /* [in] */ Int64 value5,
        /* [in] */ Byte value6,
        /* [in] */ Char32 value7,
        /* [in] */ const String& value8,
        /* [out] */ Int32 * pResult);

    CARAPI constructor(
        /* [in] */ Handle64 jvm,
        /* [in] */ const String& classPath);

private:
    // TODO: Add your private member variables here.
    JNIEnv* mEnv;
    String mClassPath;
};


#endif // __CTESTCAR_H__
