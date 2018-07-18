
#include <jni.h>

//For Elastos
#include "GenerateJava.h"

void JNICALL native_CHelloJava0(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj)
{
    AutoPtr<IJavaCarManager*> pJavaCarManager;
    _CJavaCarManager_AcquireInstance((IJavaCarManager**)&pJavaCarManager);
    IHelloJava* pElaClsObj;
    ECode ec = CHelloJava::New(&pElaClsObj);
    if(FAILED(ec)) return;

    JavaVM* jvm;
    env->GetJavaVM(&jvm);
    IJavaInterface::Probe(pElaClsObj)->JavaInit((Handle64)jvm);
    pJavaCarManager->AddCarObject((Handle64)jobj, pElaClsObj);
}

void JNICALL native_CHelloJava_Destroy(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj)
{
    AutoPtr<IJavaCarManager*> pJavaCarManager;
    _CJavaCarManager_AcquireInstance((IJavaCarManager**)&pJavaCarManager);
    IInterface* pElaClsObj = NULL;
    pJavaCarManager->GetCarObject((Handle64)jobj, &pElaClsObj);
    if (pElaClsObj) {
        pJavaCarManager->RemoveCarObject((Handle64)jobj, pElaClsObj);
        pElaClsObj->Release();
    }
}



static const JNINativeMethod gMethods[] = {
    {"native_CHelloJava", "()V", (void*)native_CHelloJava0},
    {"native_CHelloJava_Destroy", "()V", (void*)native_CHelloJava_Destroy},
};

int registerCHelloJavaMethod(JNIEnv * env) {
    jclass clazz = env->FindClass("org/elastos/GenerateJava/CHelloJava");
    if (clazz == NULL) return JNI_FALSE;

    int ret = env->RegisterNatives(clazz, gMethods, sizeof(gMethods)/sizeof(JNINativeMethod));
    if (ret < 0) return ret;

    return JNI_TRUE;
};
