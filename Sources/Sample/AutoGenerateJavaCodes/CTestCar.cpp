
#include "CTestCar.h"

CAR_OBJECT_IMPL(CTestCar)
CAR_INTERFACE_IMPL(CTestCar, Object, ITestCar, ITestCar2);

ECode CTestCar::SetInt(
    /* [in] */ Int32 value)
{
    jclass cls = mEnv->FindClass(mClassPath.string());
    jmethodID staticMethod = mEnv->GetStaticMethodID(cls, "SetInt", "(I)V");
    mEnv->CallStaticVoidMethod(cls, staticMethod);
    return NOERROR;
}

ECode CTestCar::GetInt(
    /* [out] */ Int32* value)
{
    jclass cls = mEnv->FindClass(mClassPath.string());
    jmethodID staticMethod = mEnv->GetStaticMethodID(cls, "GetInt", "()I");
    *value = (int)mEnv->CallStaticIntMethod(cls, staticMethod);
    return NOERROR;
}

ECode CTestCar::SetString(
    /* [in] */ const String& value)
{
    jclass cls = mEnv->FindClass(mClassPath.string());
    jmethodID staticMethod = mEnv->GetStaticMethodID(cls, "SetString", "(Ljava/lang/String;)V");
    mEnv->CallStaticVoidMethod(cls, staticMethod);
    return NOERROR;
}

ECode CTestCar::GetString(
    /* [out] */ String* value)
{
    jclass cls = mEnv->FindClass(mClassPath.string());
    jmethodID staticMethod = mEnv->GetStaticMethodID(cls, "GetString", "()Ljava/lang/String;");
    jstring _jstr = (jstring)mEnv->CallStaticObjectMethod(cls, staticMethod);
    const char* __str = mEnv->GetStringUTFChars(_jstr, NULL);
    *value = String(__str);
    mEnv->ReleaseStringUTFChars(_jstr, __str);
    return NOERROR;
}

ECode CTestCar::Normal()
{
    jclass cls = mEnv->FindClass(mClassPath.string());
    jmethodID staticMethod = mEnv->GetStaticMethodID(cls, "Normal", "()V");
    mEnv->CallStaticVoidMethod(cls, staticMethod);
    return NOERROR;
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
    jclass cls = mEnv->FindClass(mClassPath.string());
    jmethodID staticMethod = mEnv->GetStaticMethodID(cls, "Test1", "(IZFDJBCLjava/lang/String;)V");
    mEnv->CallStaticVoidMethod(cls, staticMethod);
    return NOERROR;
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
    /* [out] */ Int32* result)
{
    jclass cls = mEnv->FindClass(mClassPath.string());
    jmethodID staticMethod = mEnv->GetStaticMethodID(cls, "Test2", "(IZFDJBCLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)I");
    *result = (int)mEnv->CallStaticIntMethod(cls, staticMethod);
    return NOERROR;
}

ECode CTestCar::SetInt2(
    /* [in] */ Int32 value)
{
    jclass cls = mEnv->FindClass(mClassPath.string());
    jmethodID staticMethod = mEnv->GetStaticMethodID(cls, "SetInt2", "(I)V");
    mEnv->CallStaticVoidMethod(cls, staticMethod);
    return NOERROR;
}

ECode CTestCar::Update(
    /* [in] */ const String& value1,
    /* [in] */ const String& value2,
    /* [in] */ const String& value3,
    /* [out] */ String* value)
{
    jclass cls = mEnv->FindClass(mClassPath.string());
    jmethodID staticMethod = mEnv->GetStaticMethodID(cls, "Update", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
    jstring _jstr = (jstring)mEnv->CallStaticObjectMethod(cls, staticMethod);
    const char* __str = mEnv->GetStringUTFChars(_jstr, NULL);
    *value = String(__str);
    mEnv->ReleaseStringUTFChars(_jstr, __str);
    return NOERROR;
}

ECode CTestCar::constructor(
    /* [in] */ Handle64 jvm,
    /* [in] */ const String& classPath)
{
    // TODO: Add your code here for constructor
    JavaVM* vm = (JavaVM*)jvm;
    assert(vm != NULL);
    mClassPath = classPath;

    vm->AttachCurrentThread(&mEnv, NULL);
    jclass cls = mEnv->FindClass(mClassPath.string());
    if (cls == NULL) {
        return E_INVALID_ARGUMENT;
    }

    return NOERROR;
}

