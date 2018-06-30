
#include <jni.h>

//For Elastos
#include "GenerateJava.h"

jlong JNICALL native_CHelloJava0(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj)
{
    IHelloJava* pElaClsObj;
    ECode ec = CHelloJava::New(&pElaClsObj);
    if(FAILED(ec)) return 0;

    JavaVM* jvm;
    env->GetJavaVM(&jvm);
    IJavaInterface::Probe(pElaClsObj)->JavaInit((Handle64)jvm, (Handle64)jobj);
    return (jlong)pElaClsObj;
}

void JNICALL native_CHelloJava_Destroy(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jlong carobj)
{
    IInterface* pElaClsObj = (IInterface*)carobj;
    pElaClsObj->Release();
}


static const JNINativeMethod gMethods[] = {
    {"native_CHelloJava", "()J", (void*)native_CHelloJava0},
    {"native_CHelloJava_Destroy", "(J)V", (void*)native_CHelloJava_Destroy},
};

int registerCHelloJavaMethod(JNIEnv * env) {
    jclass clazz = env->FindClass("org/elastos/GenerateJava/CHelloJava");
    if (clazz == NULL) return JNI_FALSE;

    int ret = env->RegisterNatives(clazz, gMethods, sizeof(gMethods)/sizeof(JNINativeMethod));
    if (ret < 0) return ret;

    return JNI_TRUE;
};
