
#include <jni.h>

//For Elastos
#include "Elastos.AutoGenerateJavaCodes.h"

//TODO : Need to Modify the java class path.
#define JNIREG_CLASS "org/elastos/Elastos.AutoGenerateJavaCodes/CTestCar"

jlong JNICALL nativeInit0(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj)
{
    ITestCar* pElaClsObj;
    ECode ec = CTestCar::New(&pElaClsObj);
    if(FAILED(ec)) return 0;

    JavaVM* jvm;
    env->GetJavaVM(&jvm);
    IJavaInterface::Probe(pElaClsObj)->JavaInit((Handle64)jvm, (Handle64)&jobj);
    return (jlong)pElaClsObj;
}

void JNICALL nativeDestroy(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jlong carobj)
{
    IInterface* pElaClsObj = (IInterface*)carobj;
    pElaClsObj->Release();
}


static const JNINativeMethod gMethods[] = {
    {"nativeInit", "()J", (void*)nativeInit0},
    {"nativeDestroy", "(J)V", (void*)nativeDestroy},
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv * env;
    jclass cls;
    if (vm->GetEnv((void **)&env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    cls = env->FindClass(JNIREG_CLASS);
    env->RegisterNatives(cls, gMethods, sizeof(gMethods)/sizeof(JNINativeMethod));
    return JNI_VERSION_1_6;
};
