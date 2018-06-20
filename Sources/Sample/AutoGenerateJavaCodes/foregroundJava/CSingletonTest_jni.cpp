
#include <jni.h>

//For Elastos
jlong JNICALL native_CSingletonTest0(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj)
{
    ITestCar2* pElaClsObj;
    ECode ec = CSingletonTest::AcquireSingleton(&pElaClsObj);
    if(FAILED(ec)) return 0;

    JavaVM* jvm;
    env->GetJavaVM(&jvm);
    IJavaInterface::Probe(pElaClsObj)->JavaInit((Handle64)jvm, (Handle64)&jobj);
    return (jlong)pElaClsObj;
}

void JNICALL native_CSingletonTest_Destroy(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jlong carobj)
{
    IInterface* pElaClsObj = (IInterface*)carobj;
    pElaClsObj->Release();
}


static const JNINativeMethod gMethods[] = {
    {"native_CSingletonTest", "()J", (void*)native_CSingletonTest0},
    {"native_CSingletonTest_Destroy", "(J)V", (void*)native_CSingletonTest_Destroy},
};

int registerCSingletonTestMethod(JNIEnv * env) {
    jclass clazz = env->FindClass("org/elastos/Elastos.AutoGenerateJavaCodes/CSingletonTest");
    if (clazz == NULL) return JNI_FALSE;

    int ret = env->RegisterNatives(clazz, gMethods, sizeof(gMethods)/sizeof(JNINativeMethod));
    if (ret < 0) return ret;

    return JNI_TRUE;
};
