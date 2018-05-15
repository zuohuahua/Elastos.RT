
#include <jni.h>

//For Elastos
#include "Elastos.AutoGenerateJavaCodes.h"

//TODO : Need to Modify the java class path.
#define JNIREG_CLASS "elastos/org/xxx/CTestCarUser"

static AutoPtr<ITestCar> sElaClsObj;
static void JNICALL nativeInit(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jstring implClass)
{
    JavaVM* vm;
    env->GetJavaVM(&vm);
    //TODO : the implClass is like "elastos/org/xxx/CTestCarImpl"
    const char* str = env->GetStringUTFChars(implClass, NULL);
    CTestCar::New((Handle64)vm, String(str), (ITestCar**)&sElaClsObj);
    env->ReleaseStringUTFChars(implClass, str);
}

static void JNICALL nativeSetInt(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jint jvalue)
{
    ITestCar::Probe(sElaClsObj)->SetInt(jvalue);
}

static jint JNICALL nativeGetInt(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj)
{
    Int32 _retValue = 0;
    ITestCar::Probe(sElaClsObj)->GetInt(&_retValue);
    return _retValue;
}

static void JNICALL nativeSetString(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jstring jvalue)
{
    const char* str1 = env->GetStringUTFChars(jvalue, NULL);
    ITestCar::Probe(sElaClsObj)->SetString(String(str1));
}

static jstring JNICALL nativeGetString(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj)
{
    String _retValue;
    ITestCar::Probe(sElaClsObj)->GetString(&_retValue);
    return env->NewStringUTF(_retValue.string());
}

static void JNICALL nativeNormal(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj)
{
    ITestCar::Probe(sElaClsObj)->Normal();
}

static void JNICALL nativeTest1(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jint jvalue1,
    /* [in] */ jboolean jvalue2,
    /* [in] */ jfloat jvalue3,
    /* [in] */ jdouble jvalue4,
    /* [in] */ jlong jvalue5,
    /* [in] */ jbyte jvalue6,
    /* [in] */ jchar jvalue7,
    /* [in] */ jstring jvalue8)
{
    const char* str8 = env->GetStringUTFChars(jvalue8, NULL);
    ITestCar::Probe(sElaClsObj)->Test1(jvalue1, jvalue2, jvalue3, jvalue4, jvalue5, jvalue6, jvalue7, String(str8));
}

static jint JNICALL nativeTest2(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
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
    const char* str8 = env->GetStringUTFChars(jvalue8, NULL);
    const char* str9 = env->GetStringUTFChars(jvalue9, NULL);
    const char* str10 = env->GetStringUTFChars(jvalue10, NULL);
    Int32 _retValue = 0;
    ITestCar::Probe(sElaClsObj)->Test2(jvalue1, jvalue2, jvalue3, jvalue4, jvalue5, jvalue6, jvalue7, String(str8), String(str9), String(str10), &_retValue);
    return _retValue;
}

static void JNICALL nativeSetInt2(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jint jvalue)
{
    ITestCar2::Probe(sElaClsObj)->SetInt2(jvalue);
}

static jstring JNICALL nativeUpdate(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jstring jvalue1,
    /* [in] */ jstring jvalue2,
    /* [in] */ jstring jvalue3)
{
    const char* str1 = env->GetStringUTFChars(jvalue1, NULL);
    const char* str2 = env->GetStringUTFChars(jvalue2, NULL);
    const char* str3 = env->GetStringUTFChars(jvalue3, NULL);
    String _retValue;
    ITestCar2::Probe(sElaClsObj)->Update(String(str1), String(str2), String(str3), &_retValue);
    return env->NewStringUTF(_retValue.string());
}


static const JNINativeMethod gMethods[] = {
    {"nativeInit", "(Ljava/lang/String;)V", (void*)nativeInit},
    {"nativeSetInt", "(I)V", (void*)nativeSetInt},
    {"nativeGetInt", "()I", (void*)nativeGetInt},
    {"nativeSetString", "(Ljava/lang/String;)V", (void*)nativeSetString},
    {"nativeGetString", "()Ljava/lang/String;", (void*)nativeGetString},
    {"nativeNormal", "()V", (void*)nativeNormal},
    {"nativeTest1", "(IZFDJBCLjava/lang/String;)V", (void*)nativeTest1},
    {"nativeTest2", "(IZFDJBCLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)I", (void*)nativeTest2},
    {"nativeSetInt2", "(I)V", (void*)nativeSetInt2},
    {"nativeUpdate", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", (void*)nativeUpdate},
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved){
    JNIEnv * env;
    jclass cls;
    if(vm->GetEnv((void **)&env,JNI_VERSION_1_6) != JNI_OK){
        return JNI_ERR;
    }
    assert(0 && "Please set your own JNIREG_CLASS. If done, delete this line.");

    cls = env->FindClass(JNIREG_CLASS);
    env->RegisterNatives(cls, gMethods, sizeof(gMethods)/sizeof(JNINativeMethod));
    return JNI_VERSION_1_6;
};
