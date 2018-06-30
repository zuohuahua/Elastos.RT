
#include "CCarrierListener.h"

CAR_OBJECT_IMPL(CCarrierListener)
CAR_INTERFACE_IMPL(CCarrierListener, Object, ICarrierListener, IJavaInterface);

ECode CCarrierListener::OnConnectionChanged(
    /* [in] */ Boolean online)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "OnConnectionChanged", "(Z)V");
    env->CallVoidMethod(mObj, method, online);
    Detach();
    return NOERROR;
}

ECode CCarrierListener::OnReady()
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "OnReady", "()V");
    env->CallVoidMethod(mObj, method);
    Detach();
    return NOERROR;
}

ECode CCarrierListener::OnFriendRequest(
    /* [in] */ const String& uid,
    /* [in] */ const String& hello)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "OnFriendRequest", "(Ljava/lang/String;Ljava/lang/String;)V");
    jstring _jstr1 = env->NewStringUTF(uid.string());
    jstring _jstr2 = env->NewStringUTF(hello.string());
    env->CallVoidMethod(mObj, method, _jstr1, _jstr2);
    Detach();
    return NOERROR;
}

ECode CCarrierListener::OnFriendConnetionChanged(
    /* [in] */ const String& uid,
    /* [in] */ Boolean online)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "OnFriendConnetionChanged", "(Ljava/lang/String;Z)V");
    jstring _jstr1 = env->NewStringUTF(uid.string());
    env->CallVoidMethod(mObj, method, _jstr1, online);
    Detach();
    return NOERROR;
}

ECode CCarrierListener::JavaInit(
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

ECode CCarrierListener::GetJavaObject(
    /* [out] */ Handle64* jobj)
{
    if (!jobj) {
        return E_INVALID_ARGUMENT;
    }

    *jobj = (Handle64)mObj;
    return NOERROR;
}

JNIEnv* CCarrierListener::GetEnv()
{
    JNIEnv* env;
    assert(mJvm != NULL);
    mJvm->AttachCurrentThread(&env, NULL);
    return env;
}

void CCarrierListener::Detach()
{
    assert(mJvm != NULL);
    mJvm->DetachCurrentThread();
}

