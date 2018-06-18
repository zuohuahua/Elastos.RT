
#include "CTestCar.h"

CAR_OBJECT_IMPL(CTestCar)
CAR_INTERFACE_IMPL(CTestCar, Object, ITestCar, ITestCar2, IJavaInterface);

ECode CTestCar::SetInt(
    /* [in] */ Int32 value)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "SetInt", "(I)V");
    env->CallVoidMethod(cls, method, value);
    Detach();
    return NOERROR;
}

ECode CTestCar::GetInt(
    /* [out] */ Int32 * value)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "GetInt", "()I");
    *value = (int)env->CallIntMethod(cls, method);
    Detach();
    return NOERROR;
}

ECode CTestCar::SetString(
    /* [in] */ const String& value)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "SetString", "(Ljava/lang/String;)V");
    jstring _jstr1 = env->NewStringUTF(value.string());
    env->CallVoidMethod(cls, method, _jstr1);
    Detach();
    return NOERROR;
}

ECode CTestCar::GetString(
    /* [out] */ String * value)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "GetString", "()Ljava/lang/String;");
    jstring _jstr = (jstring)env->CallObjectMethod(cls, method);
    const char* __str = env->GetStringUTFChars(_jstr, NULL);
    *value = String(__str);
    env->ReleaseStringUTFChars(_jstr, __str);
    Detach();
    return NOERROR;
}

ECode CTestCar::Normal()
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "Normal", "()V");
    env->CallVoidMethod(cls, method);
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
    jmethodID method = env->GetMethodID(cls, "Test1", "(IZFDJBCLjava/lang/String;)V");
    jstring _jstr8 = env->NewStringUTF(value8.string());
    env->CallVoidMethod(cls, method, value1, value2, value3, value4, value5, value6, value7, _jstr8);
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
    /* [out] */ Int32 * result)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "Test2", "(IZFDJBCLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)I");
    jstring _jstr8 = env->NewStringUTF(value8.string());
    jstring _jstr9 = env->NewStringUTF(value9.string());
    jstring _jstr10 = env->NewStringUTF(value10.string());
    *result = (int)env->CallIntMethod(cls, method, value1, value2, value3, value4, value5, value6, value7, _jstr8, _jstr9, _jstr10);
    Detach();
    return NOERROR;
}

ECode CTestCar::SetInt2(
    /* [in] */ Int32 value)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "SetInt2", "(I)V");
    env->CallVoidMethod(cls, method, value);
    Detach();
    return NOERROR;
}

ECode CTestCar::Update(
    /* [in] */ const String& value1,
    /* [in] */ const String& value2,
    /* [in] */ const String& value3,
    /* [out] */ String * value)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "Update", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
    jstring _jstr1 = env->NewStringUTF(value1.string());
    jstring _jstr2 = env->NewStringUTF(value2.string());
    jstring _jstr3 = env->NewStringUTF(value3.string());
    jstring _jstr = (jstring)env->CallObjectMethod(cls, method, _jstr1, _jstr2, _jstr3);
    const char* __str = env->GetStringUTFChars(_jstr, NULL);
    *value = String(__str);
    env->ReleaseStringUTFChars(_jstr, __str);
    Detach();
    return NOERROR;
}

ECode CTestCar::JavaInit(
    /* [in] */ Handle64 jvm,
    /* [in] */ Handle64 jobj)
{
    mJvm = (JavaVM*)jvm;
    assert(mJvm != NULL);

    jobject jclsobj = *((jobject*)jobj);
    mObj = GetEnv()->NewGlobalRef(jclsobj);
    if (mObj == NULL) {
        return E_INVALID_ARGUMENT;
    }

    return NOERROR;
}

ECode CTestCar::GetJavaObject(
    /* [out] */ Handle64* jobj)
{
    if (!jobj) {
        return E_INVALID_ARGUMENT;
    }

    *jobj = (Handle64)&mObj;
    return NOERROR;
}

ECode CTestCar::constructor()
{
    // TODO: Add your code here for constructor
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

