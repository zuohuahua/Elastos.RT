
#include "CCarrierListener.h"

CAR_OBJECT_IMPL(CCarrierListener)
CAR_INTERFACE_IMPL(CCarrierListener, Object, ICarrierListener, IJavaInterface);

ECode CCarrierListener::OnIdle()
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "OnIdle", "()V");
    env->CallVoidMethod(mObj, method);
    Detach();
    return NOERROR;
}

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

ECode CCarrierListener::OnPortForwardingRequest(
    /* [in] */ const String& uid,
    /* [in] */ const String& servicePort,
    /* [out] */ Boolean * accept)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "OnPortForwardingRequest", "(Ljava/lang/String;Ljava/lang/String;)Z");
    jstring _jstr1 = env->NewStringUTF(uid.string());
    jstring _jstr2 = env->NewStringUTF(servicePort.string());
    *accept = (Boolean)env->CallBooleanMethod(mObj, method, _jstr1, _jstr2);
    Detach();
    return NOERROR;
}

ECode CCarrierListener::OnPortForwardingResult(
    /* [in] */ const String& uid,
    /* [in] */ const String& localPort,
    /* [in] */ const String& remotePort,
    /* [in] */ ECode code)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "OnPortForwardingResult", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V");
    jstring _jstr1 = env->NewStringUTF(uid.string());
    jstring _jstr2 = env->NewStringUTF(localPort.string());
    jstring _jstr3 = env->NewStringUTF(remotePort.string());
    env->CallVoidMethod(mObj, method, _jstr1, _jstr2, _jstr3, code);
    Detach();
    return NOERROR;
}

ECode CCarrierListener::OnMessageReceived(
    /* [in] */ const String& uid,
    /* [in] */ const ArrayOf<Byte> & message)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "OnMessageReceived", "(Ljava/lang/String;[B)V");
    jstring _jstr1 = env->NewStringUTF(uid.string());
    jbyteArray _jarray2 = env->NewByteArray(message.GetLength());
    if (_jarray2 == NULL) {
        Detach();
        return E_OUT_OF_MEMORY;
    }

    jbyte _fill2[message.GetLength()];
    for (Int32 i = 0; i < message.GetLength(); i++) {
        _fill2[i] = message[i];
    }
    env->SetByteArrayRegion(_jarray2, 0, message.GetLength(), _fill2);

    env->CallVoidMethod(mObj, method, _jstr1, _jarray2);
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

