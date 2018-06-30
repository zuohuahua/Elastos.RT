
#include <jni.h>

extern int registerCHelloJavaMethod(JNIEnv * env);
extern int registerCCarrierListenerMethod(JNIEnv * env);

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv * env;
    if (vm->GetEnv((void **)&env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }

    int ret;

    ret = registerCHelloJavaMethod(env);
    if (ret < 0) return ret;
    ret = registerCCarrierListenerMethod(env);
    if (ret < 0) return ret;

    return JNI_VERSION_1_6;
};
