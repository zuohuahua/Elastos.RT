
#include "CTestCar.h"



CAR_OBJECT_IMPL(CTestCar)

CAR_INTERFACE_IMPL(CTestCar, Object, ITestCar, IJavaInterface);

ECode CTestCar::SetInt(
    /* [in] */ Int32 value)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CTestCar::GetInt(
    /* [out] */ Int32 * pValue)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CTestCar::SetString(
    /* [in] */ const String& value)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CTestCar::GetString(
    /* [out] */ String * pValue)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CTestCar::Normal()
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CTestCar::Test1(
    /* [in] */ Int32 value1,
    /* [in] */ Boolean value2,
    /* [in] */ Float value3,
    /* [in] */ Double value4,
    /* [in] */ Int64 value5,
    /* [in] */ Byte value6,
    /* [in] */ Char32 value7,
    /* [in] */ const String& value8)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CTestCar::Test2(
    /* [in] */ Int32 value1,
    /* [in] */ Boolean value2,
    /* [in] */ Float value3,
    /* [in] */ Double value4,
    /* [in] */ Int64 value5,
    /* [in] */ Byte value6,
    /* [in] */ Char32 value7,
    /* [in] */ const String& value8,
    /* [in] */ const String& value9,
    /* [in] */ const String& value10,
    /* [out] */ Int32 * pResult)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CTestCar::Test7(
    /* [in] */ IHelloCar * pAnimal)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CTestCar::Test8(
    /* [out] */ IHelloCar ** ppAnimal)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CTestCar::Test9(
    /* [in] */ const ArrayOf<ICarrier *> & carriers)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CTestCar::Test10(
    /* [out, callee] */ ArrayOf<ICarrier *> ** ppCarriers)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CTestCar::JavaInit(
    /* [in] */ Handle64 jvm)
{
    mJvm = (JavaVM*)jvm;
    assert(mJvm != NULL);

    return NOERROR;
}

ECode CTestCar::constructor(
    /* [in] */ const ArrayOf<Double> & dArray,
    /* [in] */ const ArrayOf<String> & sArray)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CTestCar::constructor(
    /* [in] */ IServiceManager * pSm,
    /* [in] */ ICarrier * pCarrier)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

JNIEnv* CTestCar::GetEnv()
{
    JNIEnv* env;
    assert(mJvm != NULL);
    mJvm->AttachCurrentThread(&env, NULL);
    return env;
}

void CTestCar::Detach()
{
    assert(mJvm != NULL);
    mJvm->DetachCurrentThread();
}

