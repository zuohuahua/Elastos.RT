
#ifndef __CSINGLETONTEST_H__
#define __CSINGLETONTEST_H__

#include "_CSingletonTest.h"
#include <jni.h>
#include "elastos/core/Singleton.h"


CarClass(CSingletonTest)
    , public Singleton
    , public ITestCar2
    , public IJavaInterface
{
public:
    CAR_SINGLETON_DECL()

    CAR_INTERFACE_DECL()

    virtual ~CSingletonTest()
    {
        GetEnv()->DeleteGlobalRef(mObj);
        Detach();
    }

    CARAPI SetInt2(
        /* [in] */ Int32 value);

    CARAPI Update(
        /* [in] */ const String& value1,
        /* [in] */ const String& value2,
        /* [in] */ const String& value3,
        /* [out] */ String * pValue);

    CARAPI Test1(
        /* [in] */ const String& name,
        /* [in] */ const ArrayOf<Int32> & array);

    CARAPI Test2(
        /* [in] */ const ArrayOf<String> & strArray,
        /* [in] */ const ArrayOf<Int32> & intArray);

    CARAPI Test3(
        /* [in] */ Int32 i,
        /* [out, callee] */ ArrayOf<String> ** ppStrArray);

    CARAPI Test4();

    CARAPI Test5(
        /* [out] */ String * pStr);

    CARAPI Test6(
        /* [in] */ Int32 i,
        /* [in] */ const String& str,
        /* [out, callee] */ ArrayOf<Float> ** ppFloatArray);

    CARAPI JavaInit(
        /* [in] */ Handle64 jvm,
        /* [in] */ Handle64 jobj);

    CARAPI GetJavaObject(
        /* [out] */ Handle64 * pJobj);

    CARAPI constructor();

private:
    JNIEnv* GetEnv();
    void Detach();

private:
    // TODO: Add your private member variables here.
    JavaVM* mJvm;
    jobject mObj;
};


#endif // __CSINGLETONTEST_H__
