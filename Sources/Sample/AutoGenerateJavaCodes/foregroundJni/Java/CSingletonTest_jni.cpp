
#include <jni.h>

//For Elastos
#include "Elastos.AutoGenerateJavaCodes.h"

void JNICALL native_CSingletonTest0(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj)
{
    AutoPtr<IJavaCarManager> pJavaCarManager;
    _CJavaCarManager_AcquireInstance((IJavaCarManager**)&pJavaCarManager);
    ITestCar2* pElaClsObj;
    ECode ec = CSingletonTest::AcquireSingleton(&pElaClsObj);
    if(FAILED(ec)) return;

    JavaVM* jvm;
    env->GetJavaVM(&jvm);
    IJavaInterface::Probe(pElaClsObj)->JavaInit((Handle64)jvm);

    jclass jclazz = env->GetObjectClass(jobj);
    jmethodID jmethodID = env->GetMethodID(jclazz, "getClassId", "()Ljava/lang/String;");
    jstring jclassId = (jstring)env->CallObjectMethod(jobj, jmethodID);
    const char* jclsIdStr = env->GetStringUTFChars(jclassId, nullptr);
    pJavaCarManager->AddCarObject(String(jclsIdStr), (Handle64)env->NewGlobalRef(jobj), pElaClsObj);
    env->ReleaseStringUTFChars(jclassId, jclsIdStr);
}

void JNICALL native_CSingletonTest_Destroy(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj)
{
    AutoPtr<IJavaCarManager> pJavaCarManager;
    _CJavaCarManager_AcquireInstance((IJavaCarManager**)&pJavaCarManager);

    IInterface* pElaClsObj = NULL;
    jclass jclazz = env->GetObjectClass(jobj);
    jmethodID jmethodID = env->GetMethodID(jclazz, "getClassId", "()Ljava/lang/String;");
    jstring jclassId = (jstring)env->CallObjectMethod(jobj, jmethodID);
    const char* jclsIdStr = env->GetStringUTFChars(jclassId, nullptr);

    pJavaCarManager->GetCarObject(String(jclsIdStr), &pElaClsObj);
    if (pElaClsObj) {
        Handle64 javaObj;
        pJavaCarManager->GetJavaObject(pElaClsObj, &javaObj);
        env->DeleteGlobalRef((jobject)javaObj);
        pJavaCarManager->RemoveCarObject(String(jclsIdStr), pElaClsObj);
        pElaClsObj->Release();
    }
    env->ReleaseStringUTFChars(jclassId, jclsIdStr);
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
