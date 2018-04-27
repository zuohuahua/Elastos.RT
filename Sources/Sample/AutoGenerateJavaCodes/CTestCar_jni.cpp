
#include <jni.h>

//For Elastos
#include "Elastos.AutoGenerateJavaCodes.Export.h"

//TODO : Need to Modify the java class path.
#define JNIREG_CLASS "elastos/org/xxx/CTestCarUser"

static AutoPtr<ITestCar> sElaClsObj;
static void nativeInit(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj)
{
    CTestCar::New((ITestCar**)&sElaClsObj);
}

static void nativeSetInt(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jint jvalue)
{
    sElaClsObj->SetInt(jvalue);
}

static jint nativeGetInt(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj)
{
    Int32 _retValue = 0;
    sElaClsObj->GetInt(&_retValue);
    return _retValue;
}

static void nativeSetString(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jstring jvalue)
{
    const char* str1 = env->GetStringUTFChars(jvalue, NULL);
    sElaClsObj->SetString(str1);
}

static jstring nativeGetString(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj)
{
    String _retValue;
    sElaClsObj->GetString(&_retValue);
    return env->NewStringUTF(_retValue.string());
}

static void nativeNormal(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj)
{
    sElaClsObj->Normal();
}

static void nativeTest1(
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
    sElaClsObj->Test1(jvalue1, jvalue2, jvalue3, jvalue4, jvalue5, jvalue6, jvalue7, str8);
}

static jint nativeTest2(
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
    sElaClsObj->Test2(jvalue1, jvalue2, jvalue3, jvalue4, jvalue5, jvalue6, jvalue7, str8, str9, str10, &_retValue);
    return _retValue;
}

static void nativeSetInt2(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jint jvalue)
{
    sElaClsObj->SetInt2(jvalue);
}

static jstring nativeUpdate(
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
    sElaClsObj->Update(str1, str2, str3, &_retValue);
    return env->NewStringUTF(_retValue.string());
}


static const JNINativeMethod gMethods[] = {
    {"nativeSetInt", "(I)V", (void*)SetInt},
    {"nativeGetInt", "()I", (void*)GetInt},
    {"nativeSetString", "(Ljava/lang/String;)V", (void*)SetString},
    {"nativeGetString", "()Ljava/lang/String;", (void*)GetString},
    {"nativeNormal", "()V", (void*)Normal},
    {"nativeTest1", "(IZFDJBCLjava/lang/String;)V", (void*)Test1},
    {"nativeTest2", "(IZFDJBCLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)I", (void*)Test2},
    {"nativeSetInt2", "(I)V", (void*)SetInt2},
    {"nativeUpdate", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", (void*)Update},
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved){
    JNIEnv * env;
    jclass cls;
    if(vm->GetEnv((void **)&env,JNI_VERSION_1_6) != JNI_OK){
        return JNI_ERR;
    }
    cls = env->FindClass(JNIREG_CLASS);
    env->RegisterNatives(cls, gMethods, sizeof(gMethods)/sizeof(JNINativeMethod));
    return JNI_VERSION_1_6;
};
