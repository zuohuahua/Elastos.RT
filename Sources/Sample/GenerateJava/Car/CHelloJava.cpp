
#include "CHelloJava.h"

CAR_OBJECT_IMPL(CHelloJava)
CAR_INTERFACE_IMPL(CHelloJava, Object, IHelloJava, IJavaInterface);

ECode CHelloJava::Hello(
    /* [out] */ String * hello)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "Hello", "()Ljava/lang/String;");
    jstring _jstr = (jstring)env->CallObjectMethod(mObj, method);
    const char* __str = env->GetStringUTFChars(_jstr, NULL);
    *hello = String(__str);
    env->ReleaseStringUTFChars(_jstr, __str);
    Detach();
    return NOERROR;
}

ECode CHelloJava::JavaInit(
    /* [in] */ Handle64 jvm,
    /* [in] */ Handle64 jobj)
{
    mJvm = (JavaVM*)jvm;
    assert(mJvm != NULL);

    jobject jclsobj = (jobject)jobj;
    mObj = GetEnv()->NewGlobalRef(jclsobj);
    if (mObj == NULL) {
        return E_INVALID_ARGUMENT;
    }

    return NOERROR;
}

ECode CHelloJava::GetJavaObject(
    /* [out] */ Handle64* jobj)
{
    if (!jobj) {
        return E_INVALID_ARGUMENT;
    }

    *jobj = (Handle64)mObj;
    return NOERROR;
}

JNIEnv* CHelloJava::GetEnv()
{
    JNIEnv* env;
    assert(mJvm != NULL);
    mJvm->AttachCurrentThread(&env, NULL);
    return env;
}

void CHelloJava::Detach()
{
    assert(mJvm != NULL);
    mJvm->DetachCurrentThread();
}

