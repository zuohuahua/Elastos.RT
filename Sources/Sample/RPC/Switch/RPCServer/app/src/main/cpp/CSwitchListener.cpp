
#include "CSwitchListener.h"


CAR_INTERFACE_IMPL(CSwitchListener, Object, ISwitchListener)

_ELASTOS ECode CSwitchListener::OnSwitch1Changed(
        /* [in] */ _ELASTOS Boolean on)
{
    JNIEnv* env = GetEnv();
    jclass clazz = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(clazz, "switch1", "(Z)V");
    env->CallVoidMethod(mObj, method, on);
    Detach();
    return NOERROR;
}

_ELASTOS ECode CSwitchListener::OnSwitch2Changed(
        /* [in] */ _ELASTOS Boolean on)
{
    JNIEnv* env = GetEnv();
    jclass clazz = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(clazz, "switch2", "(Z)V");
    env->CallVoidMethod(mObj, method, on);
    Detach();
    return NOERROR;
}

JNIEnv* CSwitchListener::GetEnv()
{
    JNIEnv* env;
    assert(mVm != NULL);
    mVm->AttachCurrentThread(&env, NULL);
    return env;
}

void CSwitchListener::Detach()
{
    assert(mVm != NULL);
    mVm->DetachCurrentThread();
}
