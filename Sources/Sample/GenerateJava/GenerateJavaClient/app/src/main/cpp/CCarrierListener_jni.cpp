
#include <jni.h>

//For Elastos
#include "GenerateJava.h"

jlong JNICALL native_CCarrierListener0(
        /* [in] */ JNIEnv* env,
        /* [in] */ jobject jobj)
{
    ICarrierListener* pElaClsObj;
    ECode ec = CCarrierListener::New(&pElaClsObj);
    if(FAILED(ec)) return 0;

    JavaVM* jvm;
    env->GetJavaVM(&jvm);
    IJavaInterface::Probe(pElaClsObj)->JavaInit((Handle64)jvm, (Handle64)jobj);
    return (jlong)pElaClsObj;
}

void JNICALL native_CCarrierListener_Destroy(
        /* [in] */ JNIEnv* env,
        /* [in] */ jobject jobj,
        /* [in] */ jlong carobj)
{
    IInterface* pElaClsObj = (IInterface*)carobj;
    pElaClsObj->Release();
}


static const JNINativeMethod gMethods[] = {
        {"native_CCarrierListener", "()J", (void*)native_CCarrierListener0},
        {"native_CCarrierListener_Destroy", "(J)V", (void*)native_CCarrierListener_Destroy},
};

int registerCCarrierListenerMethod(JNIEnv * env) {
    jclass clazz = env->FindClass("org/elastos/GenerateJava/CCarrierListener");
    if (clazz == NULL) return JNI_FALSE;

    int ret = env->RegisterNatives(clazz, gMethods, sizeof(gMethods)/sizeof(JNINativeMethod));
    if (ret < 0) return ret;

    return JNI_TRUE;
};
