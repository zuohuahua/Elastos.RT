
#include <jni.h>
#include<android/log.h>

//For Elastos
#include "Elastos.RpcDemoClient.Export.h"

#define TAG "Elastos_RPC_Log" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型

using Elastos::RpcDemoClient::CRpcDemoClient;
using Elastos::RpcDemoClient::IRpcDemoClient;

#define JNIREG_CLASS "elastos/rpc/demo/TestUtils"

static AutoPtr<IRpcDemoClient> sRpcDemoClient;

static jstring JNICALL nativeGetTag(JNIEnv *env, jobject jobj)
{
    if (sRpcDemoClient == NULL) {
        return env->NewStringUTF("nativeGetTag NULL");
    }

    String value;
    sRpcDemoClient->GetTag(&value);
    LOGD("nativeGetTag===================value=[%s]", value.string());
    return env->NewStringUTF(value.string());
}

static jboolean JNICALL nativeSetTag(JNIEnv *env, jobject jobj, jstring jtag)
{
    if (sRpcDemoClient == NULL) {
        return false;
    }

    const char* tag;
    tag = env->GetStringUTFChars(jtag, NULL);
    sRpcDemoClient->SetTag(String(tag));
    LOGD("nativeSetTag===================value=[%s]", tag);
    return true;
}

static jboolean JNICALL nativeConnect(JNIEnv *env, jobject jobj, jstring jip, jboolean isServer)
{
    const char* ip;
    ip = env->GetStringUTFChars(jip, NULL);
    LOGD("nativeConnect===================ip=[%s]", ip);
    CRpcDemoClient::New(String(ip), isServer ? TRUE : FALSE, (IRpcDemoClient**)&sRpcDemoClient);
    assert(sRpcDemoClient != NULL);

    Boolean succeed = FALSE;
    sRpcDemoClient->Connect(&succeed);
    return (jboolean)succeed;
}

static jstring JNICALL nativeGetHelloCarString(JNIEnv *env, jobject jobj)
{
    // AutoPtr<IHelloCar> helloCarObj;
    // ECode ec = CHelloCar::New((IHelloCar**)&helloCarObj);
    // if (ec != NOERROR || helloCarObj == NULL) {
    //     return 0;
    // }
    // String helloString;

    // String newString("[native] Hello, ");
    // newString += helloString + "!";

    // return env->NewStringUTF(newString.string());
    return env->NewStringUTF(NULL);
}

static const JNINativeMethod gMethods[] = {
    {"nativeConnect", "(Ljava/lang/String;Z)Z", (void*)nativeConnect},
    {"nativeGetTag", "()Ljava/lang/String;", (void*)nativeGetTag},
    {"nativeSetTag", "(Ljava/lang/String;)Z", (void*)nativeSetTag},
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved){
    JNIEnv * env;
    jclass cls;
    jint result = -1;
    if(vm->GetEnv((void **)&env,JNI_VERSION_1_6) != JNI_OK){
        return JNI_ERR;
    }

    cls = env->FindClass(JNIREG_CLASS);
    env->RegisterNatives(cls, gMethods, sizeof(gMethods)/sizeof(JNINativeMethod));
    return JNI_VERSION_1_6;
}
