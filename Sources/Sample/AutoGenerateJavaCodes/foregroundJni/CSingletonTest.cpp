
#include "CSingletonTest.h"



CAR_SINGLETON_IMPL(CSingletonTest)

CAR_INTERFACE_IMPL(CSingletonTest, Singleton, ITestCar2, IJavaInterface);

ECode CSingletonTest::SetInt2(
    /* [in] */ Int32 value)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CSingletonTest::Update(
    /* [in] */ const String& value1,
    /* [in] */ const String& value2,
    /* [in] */ const String& value3,
    /* [out] */ String * pValue)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CSingletonTest::Test1(
    /* [in] */ const String& name,
    /* [in] */ const ArrayOf<Int32> & array)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CSingletonTest::Test2(
    /* [in] */ const ArrayOf<String> & strArray,
    /* [in] */ const ArrayOf<Int32> & intArray)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CSingletonTest::Test3(
    /* [in] */ Int32 i,
    /* [out, callee] */ ArrayOf<String> ** ppStrArray)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CSingletonTest::Test4()
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CSingletonTest::Test5(
    /* [out] */ String * pStr)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CSingletonTest::Test6(
    /* [in] */ Int32 i,
    /* [in] */ const String& str,
    /* [out, callee] */ ArrayOf<Float> ** ppFloatArray)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CSingletonTest::JavaInit(
    /* [in] */ Handle64 jvm)
{
    mJvm = (JavaVM*)jvm;
    assert(mJvm != NULL);

    return NOERROR;
}

ECode CSingletonTest::constructor()
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

JNIEnv* CSingletonTest::GetEnv()
{
    JNIEnv* env;
    assert(mJvm != NULL);
    mJvm->AttachCurrentThread(&env, NULL);
    return env;
}

void CSingletonTest::Detach()
{
    assert(mJvm != NULL);
    mJvm->DetachCurrentThread();
}

