
#include <jni.h>

//For Elastos
#include "Elastos.AutoGenerateJavaCodes.h"

void JNICALL native_CSingletonTest0(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj)
{
    AutoPtr<IJavaCarManager*> pJavaCarManager;
    _CJavaCarManager_AcquireInstance((IJavaCarManager**)&pJavaCarManager);
    ITestCar2* pElaClsObj;
    ECode ec = CSingletonTest::AcquireSingleton(&pElaClsObj);
    if(FAILED(ec)) return;

    JavaVM* jvm;
    env->GetJavaVM(&jvm);
    IJavaInterface::Probe(pElaClsObj)->JavaInit((Handle64)jvm);
    pJavaCarManager->AddCarObject((Handle64)jobj, pElaClsObj);
}

void JNICALL native_CSingletonTest_Destroy(
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
    {"native_CSingletonTest", "()V", (void*)native_CSingletonTest0},
    {"native_CSingletonTest_Destroy", "()V", (void*)native_CSingletonTest_Destroy},
};

int registerCSingletonTestMethod(JNIEnv * env) {
    jclass clazz = env->FindClass("org/elastos/Elastos.AutoGenerateJavaCodes/CSingletonTest");
    if (clazz == NULL) return JNI_FALSE;

    int ret = env->RegisterNatives(clazz, gMethods, sizeof(gMethods)/sizeof(JNINativeMethod));
    if (ret < 0) return ret;

    return JNI_TRUE;
};
