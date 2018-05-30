
#include "CTestCar.h"

CAR_OBJECT_IMPL(CTestCar)
CAR_INTERFACE_IMPL(CTestCar, Object, ITestCar, ITestCar2);

ECode CTestCar::SetInt(
    /* [in] */ Int32 value)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = mEnv->GetMethodID(cls, "SetInt", "(I)V");
    mEnv->CallVoidMethod(cls, method);
    Detach();
    return NOERROR;
}

ECode CTestCar::GetInt(
    /* [out] */ Int32* value)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = mEnv->GetMethodID(cls, "GetInt", "()I");
    *value = (int)mEnv->CallIntMethod(cls, method);
    Detach();
    return NOERROR;
}

ECode CTestCar::SetString(
    /* [in] */ const String& value)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = mEnv->GetMethodID(cls, "SetString", "(Ljava/lang/String;)V");
    mEnv->CallVoidMethod(cls, method);
    Detach();
    return NOERROR;
}

ECode CTestCar::GetString(
    /* [out] */ String* value)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = mEnv->GetMethodID(cls, "GetString", "()Ljava/lang/String;");
    jstring _jstr = (jstring)mEnv->CallObjectMethod(cls, method);
    const char* __str = mEnv->GetStringUTFChars(_jstr, NULL);
    *value = String(__str);
    mEnv->ReleaseStringUTFChars(_jstr, __str);
    Detach();
    return NOERROR;
}

ECode CTestCar::Normal()
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = mEnv->GetMethodID(cls, "Normal", "()V");
    mEnv->CallVoidMethod(cls, method);
    Detach();
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
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = mEnv->GetMethodID(cls, "Test1", "(IZFDJBCLjava/lang/String;)V");
    mEnv->CallVoidMethod(cls, method);
    Detach();
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
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = mEnv->GetMethodID(cls, "Test2", "(IZFDJBCLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)I");
    *result = (int)mEnv->CallIntMethod(cls, method);
    Detach();
    return NOERROR;
}

ECode CTestCar::SetInt2(
    /* [in] */ Int32 value)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = mEnv->GetMethodID(cls, "SetInt2", "(I)V");
    mEnv->CallVoidMethod(cls, method);
    Detach();
    return NOERROR;
}

ECode CTestCar::Update(
    /* [in] */ const String& value1,
    /* [in] */ const String& value2,
    /* [in] */ const String& value3,
    /* [out] */ String* value)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = mEnv->GetMethodID(cls, "Update", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
    jstring _jstr = (jstring)mEnv->CallObjectMethod(cls, method);
    const char* __str = mEnv->GetStringUTFChars(_jstr, NULL);
    *value = String(__str);
    mEnv->ReleaseStringUTFChars(_jstr, __str);
    Detach();
    return NOERROR;
}

ECode CTestCar::constructor(
    /* [in] */ Handle64 jvm,
    /* [in] */ Handle64 jobj)
{
    // TODO: Add your code here for constructor
    mJvm = (JavaVM*)jvm;
    assert(vm != NULL);

    mObj = env->NewGlobalRef(jobj);
    if (mObj == NULL) {
        return E_INVALID_ARGUMENT;
    }

    return NOERROR;
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

