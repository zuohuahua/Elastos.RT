
#include <jni.h>
#include <ela_session.h>

extern int registerCCarrierListenerMethod(JNIEnv * env);

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    ela_session_jni_onload(vm, reserved);

    JNIEnv * env;
    if (vm->GetEnv((void **)&env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }

    int ret;

    ret = registerCCarrierListenerMethod(env);
    if (ret < 0) return ret;

    return JNI_VERSION_1_6;
};
