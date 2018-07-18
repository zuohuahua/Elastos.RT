
#ifndef __CTESTCAR_H__
#define __CTESTCAR_H__

#include "_CTestCar.h"
#include <jni.h>
#include "elastos/core/Object.h"

using Elastos::Core::IComparable;
using Elastos::Core::EIID_IComparable;


CarClass(CTestCar)
    , public Object
    , public ITestCar
    , public IJavaInterface
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    CTestCar()
    {
        _CJavaCarManager_AcquireInstance(&mJavaCarManager);
    }

    virtual ~CTestCar()
    {
        mJavaCarManager->Release();
    }

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
        /* [in] */ const String& value9,
        /* [in] */ const String& value10,
        /* [out] */ Int32 * pResult);

    CARAPI Test7(
        /* [in] */ IHelloCar * pAnimal);

    CARAPI Test8(
        /* [out] */ IHelloCar ** ppAnimal);

    CARAPI Test9(
        /* [in] */ const ArrayOf<ICarrier *> & carriers);

    CARAPI Test10(
        /* [out, callee] */ ArrayOf<ICarrier *> ** ppCarriers);

    CARAPI JavaInit(
        /* [in] */ Handle64 jvm);

    CARAPI constructor(
        /* [in] */ const ArrayOf<Double> & dArray,
        /* [in] */ const ArrayOf<String> & sArray);

    CARAPI constructor(
        /* [in] */ IServiceManager * pSm,
        /* [in] */ ICarrier * pCarrier);

private:
    JNIEnv* GetEnv();
    void Detach();

private:
    // TODO: Add your private member variables here.
    JavaVM* mJvm;
    IJavaCarManager* mJavaCarManager;
};


#endif // __CTESTCAR_H__
