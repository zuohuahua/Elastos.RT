
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
    IJavaInterface::Probe(pElaClsObj)->JavaInit((Handle64)jvm, (Handle64)&jobj);
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
    IJavaInterface::Probe(pElaClsObj)->JavaInit((Handle64)jvm, (Handle64)&jobj);
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


static const JNINativeMethod gMethods[] = {
    {"native_CTestCar", "([D[Ljava/lang/String;)J", (void*)native_CTestCar0},
    {"native_CTestCar", "(Lorg/elastos/xxx/IServiceManager;Lorg/elastos/xxx/ICarrier;)J", (void*)native_CTestCar1},
    {"native_CTestCar_Destroy", "(J)V", (void*)native_CTestCar_Destroy},
};

int registerCTestCarMethod(JNIEnv * env) {
    jclass clazz = env->FindClass("org/elastos/Elastos.AutoGenerateJavaCodes/CTestCar");
    if (clazz == NULL) return JNI_FALSE;

    int ret = env->RegisterNatives(clazz, gMethods, sizeof(gMethods)/sizeof(JNINativeMethod));
    if (ret < 0) return ret;

    return JNI_TRUE;
};
