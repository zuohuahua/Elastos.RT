
#include <jni.h>
#include <ela_session.h>

extern int registerCTestCarMethod(JNIEnv * env);
extern int registerCSingletonTestMethod(JNIEnv * env);

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    ela_session_jni_onload(vm, reserved);

    JNIEnv * env;
    if (vm->GetEnv((void **)&env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }

    int ret;

    ret = registerCTestCarMethod(env);
    if (ret < 0) return ret;
    ret = registerCSingletonTestMethod(env);
    if (ret < 0) return ret;

    return JNI_VERSION_1_6;
};
