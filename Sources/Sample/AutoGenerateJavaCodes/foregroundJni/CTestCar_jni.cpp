
#include <jni.h>

//For Elastos
#include "Elastos.AutoGenerateJavaCodes.h"

//TODO : Need to Modify the java class path.
#define JNIREG_CLASS "elastos/org/xxx/CTestCarUser"

jlong JNICALL nativeInit0(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj)
{
    ICTestCarClassObject* pElaClsObj;
    ECode ec = CTestCar::New(&pElaClsObj);
    if(FAILED(ec)) return 0;

    return pElaClsObj;
}

void JNICALL nativeDestroy(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jlong carobj)
{
    IInterface* pElaClsObj = (IInterface*)carobj;
    pElaClsObj->Release();
}

void JNICALL nativeSetInt(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jlong carobj,
    /* [in] */ jint jvalue)
{
    IInterface* pElaClsObj = (IInterface*)carobj;
    ITestCar::Probe(pElaClsObj)->SetInt(jvalue);
}

jint JNICALL nativeGetInt(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jlong carobj)
{
    IInterface* pElaClsObj = (IInterface*)carobj;
    Int32 _retValue = 0;
    ITestCar::Probe(pElaClsObj)->GetInt(&_retValue);
    return _retValue;
}

void JNICALL nativeSetString(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jlong carobj,
    /* [in] */ jstring jvalue)
{
    IInterface* pElaClsObj = (IInterface*)carobj;
    const char* str1 = env->GetStringUTFChars(jvalue, NULL);
    ITestCar::Probe(pElaClsObj)->SetString(String(str1));
}

jstring JNICALL nativeGetString(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jlong carobj)
{
    IInterface* pElaClsObj = (IInterface*)carobj;
    String _retValue;
    ITestCar::Probe(pElaClsObj)->GetString(&_retValue);
    return env->NewStringUTF(_retValue.string());
}

void JNICALL nativeNormal(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jlong carobj)
{
    IInterface* pElaClsObj = (IInterface*)carobj;
    ITestCar::Probe(pElaClsObj)->Normal();
}

void JNICALL nativeTest1(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jlong carobj,
    /* [in] */ jint jvalue1,
    /* [in] */ jboolean jvalue2,
    /* [in] */ jfloat jvalue3,
    /* [in] */ jdouble jvalue4,
    /* [in] */ jlong jvalue5,
    /* [in] */ jbyte jvalue6,
    /* [in] */ jchar jvalue7,
    /* [in] */ jstring jvalue8)
{
    IInterface* pElaClsObj = (IInterface*)carobj;
    const char* str8 = env->GetStringUTFChars(jvalue8, NULL);
    ITestCar::Probe(pElaClsObj)->Test1(jvalue1, jvalue2, jvalue3, jvalue4, jvalue5, jvalue6, jvalue7, String(str8));
}

jint JNICALL nativeTest2(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jlong carobj,
    /* [in] */ jint jvalue1,
    /* [in] */ jboolean jvalue2,
    /* [in] */ jfloat jvalue3,
    /* [in] */ jdouble jvalue4,
    /* [in] */ jlong jvalue5,
    /* [in] */ jbyte jvalue6,
    /* [in] */ jchar jvalue7,
    /* [in] */ jstring jvalue8,
    /* [in] */ jstring jvalue9,
    /* [in] */ jstring jvalue10)
{
    IInterface* pElaClsObj = (IInterface*)carobj;
    const char* str8 = env->GetStringUTFChars(jvalue8, NULL);
    const char* str9 = env->GetStringUTFChars(jvalue9, NULL);
    const char* str10 = env->GetStringUTFChars(jvalue10, NULL);
    Int32 _retValue = 0;
    ITestCar::Probe(pElaClsObj)->Test2(jvalue1, jvalue2, jvalue3, jvalue4, jvalue5, jvalue6, jvalue7, String(str8), String(str9), String(str10), &_retValue);
    return _retValue;
}

void JNICALL nativeSetInt2(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jlong carobj,
    /* [in] */ jint jvalue)
{
    IInterface* pElaClsObj = (IInterface*)carobj;
    ITestCar2::Probe(pElaClsObj)->SetInt2(jvalue);
}

jstring JNICALL nativeUpdate(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jlong carobj,
    /* [in] */ jstring jvalue1,
    /* [in] */ jstring jvalue2,
    /* [in] */ jstring jvalue3)
{
    IInterface* pElaClsObj = (IInterface*)carobj;
    const char* str1 = env->GetStringUTFChars(jvalue1, NULL);
    const char* str2 = env->GetStringUTFChars(jvalue2, NULL);
    const char* str3 = env->GetStringUTFChars(jvalue3, NULL);
    String _retValue;
    ITestCar2::Probe(pElaClsObj)->Update(String(str1), String(str2), String(str3), &_retValue);
    return env->NewStringUTF(_retValue.string());
}


static const JNINativeMethod gMethods[] = {
    {"nativeInit", "()J", (void*)nativeInit0},
    {"nativeDestroy", "(J)V", (void*)nativeDestroy},
    {"nativeSetInt", "(JI)V", (void*)nativeSetInt},
    {"nativeGetInt", "(J)I", (void*)nativeGetInt},
    {"nativeSetString", "(JLjava/lang/String;)V", (void*)nativeSetString},
    {"nativeGetString", "(J)Ljava/lang/String;", (void*)nativeGetString},
    {"nativeNormal", "(J)V", (void*)nativeNormal},
    {"nativeTest1", "(JIZFDJBCLjava/lang/String;)V", (void*)nativeTest1},
    {"nativeTest2", "(JIZFDJBCLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)I", (void*)nativeTest2},
    {"nativeSetInt2", "(JI)V", (void*)nativeSetInt2},
    {"nativeUpdate", "(JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", (void*)nativeUpdate},
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv * env;
    jclass cls;
    if (vm->GetEnv((void **)&env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    assert(0 && "Please set your own JNIREG_CLASS. If done, delete this line.");

    cls = env->FindClass(JNIREG_CLASS);
    env->RegisterNatives(cls, gMethods, sizeof(gMethods)/sizeof(JNINativeMethod));
    return JNI_VERSION_1_6;
};
