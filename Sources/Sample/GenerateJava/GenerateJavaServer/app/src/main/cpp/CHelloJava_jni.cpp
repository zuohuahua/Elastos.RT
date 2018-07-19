
#include <jni.h>

//For Elastos
#include "GenerateJava.h"

void JNICALL native_CHelloJava0(
        /* [in] */ JNIEnv* env,
        /* [in] */ jobject jobj)
{
    AutoPtr<IJavaCarManager> pJavaCarManager;
    _CJavaCarManager_AcquireInstance((IJavaCarManager**)&pJavaCarManager);
    IHelloJava* pElaClsObj;
    ECode ec = CHelloJava::New(&pElaClsObj);
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

void JNICALL native_CHelloJava_Destroy(
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
