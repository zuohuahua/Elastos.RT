
#include "CHelloJava.h"

CAR_OBJECT_IMPL(CHelloJava)
CAR_INTERFACE_IMPL(CHelloJava, Object, IHelloJava, IJavaInterface);

ECode CHelloJava::Hello(
    /* [out] */ String * hello)
{
    JNIEnv* env = GetEnv();
    Handle64 javaObj;
    mJavaCarManager->GetJavaObject(IHelloJava::Probe(this), &javaObj);
    jobject jobj = (jobject)javaObj;
    jclass cls = env->GetObjectClass(jobj);
    jmethodID method = env->GetMethodID(cls, "Hello", "()Ljava/lang/String;");
    jstring _jstr = (jstring)env->CallObjectMethod(jobj, method);
    const char* __str = env->GetStringUTFChars(_jstr, NULL);
    *hello = String(__str);
    env->ReleaseStringUTFChars(_jstr, __str);
    Detach();
    return NOERROR;
}

ECode CHelloJava::JavaInit(
    /* [in] */ Handle64 jvm)
{
    mJvm = (JavaVM*)jvm;
    assert(mJvm != NULL);

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

