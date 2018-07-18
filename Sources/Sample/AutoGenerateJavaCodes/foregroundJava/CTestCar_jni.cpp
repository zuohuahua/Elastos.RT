
#include <jni.h>

//For Elastos
#include "Elastos.AutoGenerateJavaCodes.h"

void JNICALL native_CTestCar0(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jdoubleArray jdArray,
    /* [in] */ jobjectArray jsArray)
{
    AutoPtr<IJavaCarManager*> pJavaCarManager;
    _CJavaCarManager_AcquireInstance((IJavaCarManager**)&pJavaCarManager);
    ITestCar* pElaClsObj;
    int _len1 = env->GetArrayLength(jdArray);
    AutoPtr<ArrayOf<Double> > _array1 = ArrayOf<Double>::Alloc(_len1);
    if(!_array1) return;
    jdouble* _items1 = env->GetDoubleArrayElements(jdArray, 0);
    for (Int32 i = 0; i < _len1; i++) {
        (*_array1)[i] = _items1[i];
    }
    env->ReleaseDoubleArrayElements(jdArray, _items1, 0);

    int _len2 = env->GetArrayLength(jsArray);
    AutoPtr<ArrayOf<String> > _array2 = ArrayOf<String>::Alloc(_len2);
    if(!_array2) return;
    for (Int32 i = 0; i < _len2; i++) {
        jstring _item = (jstring)env->GetObjectArrayElement(jsArray, i);
        const char* __str = env->GetStringUTFChars(_item, NULL);
        (*_array2)[i] = String(__str);
        env->ReleaseStringUTFChars(_item, __str);
    }

    ECode ec = CTestCar::New(*_array1, *_array2, &pElaClsObj);
    if(FAILED(ec)) return;

    JavaVM* jvm;
    env->GetJavaVM(&jvm);
    IJavaInterface::Probe(pElaClsObj)->JavaInit((Handle64)jvm);
    pJavaCarManager->AddCarObject((Handle64)jobj, pElaClsObj);
}

void JNICALL native_CTestCar1(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jobject jsm,
    /* [in] */ jobject jcarrier)
{
    AutoPtr<IJavaCarManager*> pJavaCarManager;
    _CJavaCarManager_AcquireInstance((IJavaCarManager**)&pJavaCarManager);
    ITestCar* pElaClsObj;
    IInterface* _carobj1 = NULL;
    pJavaCarManager->GetCarObject((Handle64)jsm, &_carobj1);
    if (!_carobj1) return;
    IServiceManager* _interface1 = IServiceManager::Probe(_carobj1);

    IInterface* _carobj2 = NULL;
    pJavaCarManager->GetCarObject((Handle64)jcarrier, &_carobj2);
    if (!_carobj2) return;
    ICarrier* _interface2 = ICarrier::Probe(_carobj2);

    ECode ec = CTestCar::New(_interface1, _interface2, &pElaClsObj);
    if(FAILED(ec)) return;

    JavaVM* jvm;
    env->GetJavaVM(&jvm);
    IJavaInterface::Probe(pElaClsObj)->JavaInit((Handle64)jvm);
    pJavaCarManager->AddCarObject((Handle64)jobj, pElaClsObj);
}

void JNICALL native_CTestCar_Destroy(
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
    {"native_CTestCar", "([D[Ljava/lang/String;)V", (void*)native_CTestCar0},
    {"native_CTestCar", "(Lorg/elastos/xxx/IServiceManager;Lorg/elastos/xxx/ICarrier;)V", (void*)native_CTestCar1},
    {"native_CTestCar_Destroy", "()V", (void*)native_CTestCar_Destroy},
};

int registerCTestCarMethod(JNIEnv * env) {
    jclass clazz = env->FindClass("org/elastos/Elastos.AutoGenerateJavaCodes/CTestCar");
    if (clazz == NULL) return JNI_FALSE;

    int ret = env->RegisterNatives(clazz, gMethods, sizeof(gMethods)/sizeof(JNINativeMethod));
    if (ret < 0) return ret;

    return JNI_TRUE;
};
