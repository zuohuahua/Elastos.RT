
#include <jni.h>

//For Elastos
#include "Elastos.AutoGenerateJavaCodes.h"

jlong JNICALL native_CTestCar0(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jdoubleArray jdArray,
    /* [in] */ jobjectArray jsArray)
{
    ITestCar* pElaClsObj;
    int _len1 = env->GetArrayLength(jdArray);
    AutoPtr<ArrayOf<Double> > _array1 = ArrayOf<Double>::Alloc(_len1);
    if(!_array1) return E_OUT_OF_MEMORY;
    jdouble* _items1 = env->GetDoubleArrayElements(jdArray, 0);
    for (Int32 i = 0; i < _len1; i++) {
        (*_array1)[i] = _items1[i];
    }
    env->ReleaseDoubleArrayElements(jdArray, _items1, 0);

    int _len2 = env->GetArrayLength(jsArray);
    AutoPtr<ArrayOf<String> > _array2 = ArrayOf<String>::Alloc(_len2);
    if(!_array2) return E_OUT_OF_MEMORY;
    for (Int32 i = 0; i < _len2; i++) {
        jstring _item = (jstring)env->GetObjectArrayElement(jsArray, i);
        const char* __str = env->GetStringUTFChars(_item, NULL);
        (*_array2)[i] = String(__str);
        env->ReleaseStringUTFChars(_item, __str);
    }

    ECode ec = CTestCar::New(*_array1, *_array2, &pElaClsObj);
    if(FAILED(ec)) return 0;

    JavaVM* jvm;
    env->GetJavaVM(&jvm);
    IJavaInterface::Probe(pElaClsObj)->JavaInit((Handle64)jvm, (Handle64)jobj);
    return (jlong)pElaClsObj;
}

jlong JNICALL native_CTestCar1(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jobject jsm,
    /* [in] */ jobject jcarrier)
{
    ITestCar* pElaClsObj;
    jclass _clazz1 = env->GetObjectClass(jsm);
    jmethodID _methodId1 = env->GetMethodID(_clazz1, "getCarObject", "()J");
    jlong _carobj1 = env->CallLongMethod(jsm, _methodId1);
    IServiceManager* _interface1 = IServiceManager::Probe((IInterface*)_carobj1);

    jclass _clazz2 = env->GetObjectClass(jcarrier);
    jmethodID _methodId2 = env->GetMethodID(_clazz2, "getCarObject", "()J");
    jlong _carobj2 = env->CallLongMethod(jcarrier, _methodId2);
    ICarrier* _interface2 = ICarrier::Probe((IInterface*)_carobj2);

    ECode ec = CTestCar::New(_interface1, _interface2, &pElaClsObj);
    if(FAILED(ec)) return 0;

    JavaVM* jvm;
    env->GetJavaVM(&jvm);
    IJavaInterface::Probe(pElaClsObj)->JavaInit((Handle64)jvm, (Handle64)jobj);
    return (jlong)pElaClsObj;
}

void JNICALL native_CTestCar_Destroy(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jlong carobj)
{
    IInterface* pElaClsObj = (IInterface*)carobj;
    pElaClsObj->Release();
}

void JNICALL native_CTestCar_ITestCar_SetInt(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jlong carobj,
    /* [in] */ jint jvalue)
{
    IInterface* pElaClsObj = (IInterface*)carobj;
    ITestCar::Probe(pElaClsObj)->SetInt(jvalue);
}

jint JNICALL native_CTestCar_ITestCar_GetInt(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jlong carobj)
{
    IInterface* pElaClsObj = (IInterface*)carobj;
    Int32 _retValue = 0;
    ITestCar::Probe(pElaClsObj)->GetInt(&_retValue);
    return _retValue;
}

void JNICALL native_CTestCar_ITestCar_SetString(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jlong carobj,
    /* [in] */ jstring jvalue)
{
    IInterface* pElaClsObj = (IInterface*)carobj;
    const char* str1 = env->GetStringUTFChars(jvalue, NULL);
    ITestCar::Probe(pElaClsObj)->SetString(String(str1));
    env->ReleaseStringUTFChars(jvalue, str1);
}

jstring JNICALL native_CTestCar_ITestCar_GetString(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jlong carobj)
{
    IInterface* pElaClsObj = (IInterface*)carobj;
    String _retValue;
    ITestCar::Probe(pElaClsObj)->GetString(&_retValue);
    return env->NewStringUTF(_retValue.string());
}

void JNICALL native_CTestCar_ITestCar_Normal(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jlong carobj)
{
    IInterface* pElaClsObj = (IInterface*)carobj;
    ITestCar::Probe(pElaClsObj)->Normal();
}

void JNICALL native_CTestCar_ITestCar_Test1(
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
    env->ReleaseStringUTFChars(jvalue8, str8);
}

jint JNICALL native_CTestCar_ITestCar_Test2(
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
    env->ReleaseStringUTFChars(jvalue8, str8);
    env->ReleaseStringUTFChars(jvalue9, str9);
    env->ReleaseStringUTFChars(jvalue10, str10);
    return _retValue;
}

void JNICALL native_CTestCar_ITestCar_Test7(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jlong carobj,
    /* [in] */ jobject janimal)
{
    IInterface* pElaClsObj = (IInterface*)carobj;

    jclass _clazz1 = env->GetObjectClass(janimal);
    jmethodID _methodId1 = env->GetMethodID(_clazz1, "getCarObject", "()J");
    jlong _carobj1 = env->CallLongMethod(janimal, _methodId1);
    IHelloCar* _interface1 = IHelloCar::Probe((IInterface*)_carobj1);

    ITestCar::Probe(pElaClsObj)->Test7(_interface1);
}

jobject JNICALL native_CTestCar_ITestCar_Test8(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jlong carobj)
{
    IInterface* pElaClsObj = (IInterface*)carobj;
    AutoPtr<IHelloCar*> _retValue;
    ITestCar::Probe(pElaClsObj)->Test8((IHelloCar**)&_retValue);
    Handle64 _jobj;
    IJavaInterface::Probe(_retValue)->GetJavaObject(&_jobj);
    return (jobject)_jobj;
}

void JNICALL native_CTestCar_ITestCar_Test9(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jlong carobj,
    /* [in] */ jobjectArray jcarriers)
{
    IInterface* pElaClsObj = (IInterface*)carobj;
    int _len1 = env->GetArrayLength(jcarriers);
    AutoPtr<ArrayOf<ICarrier *> > _array1 = ArrayOf<ICarrier *>::Alloc(_len1);
    if(!_array1) return;
    for (Int32 i = 0; i < _len1; i++) {
        jobject _item = env->GetObjectArrayElement(jcarriers, i);
        jclass _clazz = env->GetObjectClass(_item);
        jmethodID _methodId = env->GetMethodID(_clazz, "getCarObject", "()J");
        jlong _carobj = env->CallLongMethod(_item, _methodId);
        (*_array1)[i] = ICarrier::Probe((IInterface*)_carobj);
    }

    ITestCar::Probe(pElaClsObj)->Test9(*_array1);
}

jobjectArray JNICALL native_CTestCar_ITestCar_Test10(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jlong carobj)
{
    IInterface* pElaClsObj = (IInterface*)carobj;
    AutoPtr<ArrayOf<ICarrier *> > _retValue;
    ITestCar::Probe(pElaClsObj)->Test10((ArrayOf<ICarrier *>**)&_retValue);

    //TOOD: please fix the package name of the interface.
    assert(0);
    jclass _retClazz = env->FindClass("org/elastos/xxx/ICarrier");
    jobjectArray retArray = env->NewObjectArray(_retValue->GetLength(), _retClazz, NULL);
    if (retArray == NULL) return NULL;
    for (Int32 i = 0; i < _retValue->GetLength(); i++) {
        Handle64 _jobj;
        IJavaInterface::Probe((*_retValue)[i])->GetJavaObject(&_jobj);
        env->SetObjectArrayElement(retArray, i, (jobject)_jobj);
    }

    return retArray;
}


static const JNINativeMethod gMethods[] = {
    {"native_CTestCar", "([D[Ljava/lang/String;)J", (void*)native_CTestCar0},
    {"native_CTestCar", "(Lorg/elastos/xxx/IServiceManager;Lorg/elastos/xxx/ICarrier;)J", (void*)native_CTestCar1},
    {"native_CTestCar_Destroy", "(J)V", (void*)native_CTestCar_Destroy},
    {"native_CTestCar_ITestCar_SetInt", "(JI)V", (void*)native_CTestCar_ITestCar_SetInt},
    {"native_CTestCar_ITestCar_GetInt", "(J)I", (void*)native_CTestCar_ITestCar_GetInt},
    {"native_CTestCar_ITestCar_SetString", "(JLjava/lang/String;)V", (void*)native_CTestCar_ITestCar_SetString},
    {"native_CTestCar_ITestCar_GetString", "(J)Ljava/lang/String;", (void*)native_CTestCar_ITestCar_GetString},
    {"native_CTestCar_ITestCar_Normal", "(J)V", (void*)native_CTestCar_ITestCar_Normal},
    {"native_CTestCar_ITestCar_Test1", "(JIZFDJBCLjava/lang/String;)V", (void*)native_CTestCar_ITestCar_Test1},
    {"native_CTestCar_ITestCar_Test2", "(JIZFDJBCLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)I", (void*)native_CTestCar_ITestCar_Test2},
    //TODO: please fix the package name of the interface.
    {"native_CTestCar_ITestCar_Test7", "(JLorg/elastos/xxx/IHelloCar;)V", (void*)native_CTestCar_ITestCar_Test7},
    //TODO: please fix the package name of the interface.
    {"native_CTestCar_ITestCar_Test8", "(J)Lorg/elastos/xxx/IHelloCar;", (void*)native_CTestCar_ITestCar_Test8},
    //TODO: please fix the package name of the interface.
    {"native_CTestCar_ITestCar_Test9", "(J[Lorg/elastos/xxx/ICarrier;)V", (void*)native_CTestCar_ITestCar_Test9},
    //TODO: please fix the package name of the interface.
    {"native_CTestCar_ITestCar_Test10", "(J)[Lorg/elastos/xxx/ICarrier;", (void*)native_CTestCar_ITestCar_Test10},
};

int registerCTestCarMethod(JNIEnv * env) {
    jclass clazz = env->FindClass("org/elastos/Elastos.AutoGenerateJavaCodes/CTestCar");
    if (clazz == NULL) return JNI_FALSE;

    int ret = env->RegisterNatives(clazz, gMethods, sizeof(gMethods)/sizeof(JNINativeMethod));
    if (ret < 0) return ret;

    return JNI_TRUE;
};
