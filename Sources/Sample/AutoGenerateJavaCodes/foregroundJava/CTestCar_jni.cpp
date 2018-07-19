
#include <jni.h>

//For Elastos
#include "Elastos.AutoGenerateJavaCodes.h"

void JNICALL native_CTestCar0(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jdoubleArray jdArray,
    /* [in] */ jobjectArray jsArray)
{
    AutoPtr<IJavaCarManager> pJavaCarManager;
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

    jclass jclazz = env->GetObjectClass(jobj);
    jmethodID jmethodID = env->GetMethodID(jclazz, "getClassId", "()Ljava/lang/String;");
    jstring jclassId = (jstring)env->CallObjectMethod(jobj, jmethodID);
    const char* jclsIdStr = env->GetStringUTFChars(jclassId, nullptr);
    pJavaCarManager->AddCarObject(String(jclsIdStr), (Handle64)env->NewGlobalRef(jobj), pElaClsObj);
    env->ReleaseStringUTFChars(jclassId, jclsIdStr);
}

void JNICALL native_CTestCar1(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jobject jsm,
    /* [in] */ jobject jcarrier)
{
    AutoPtr<IJavaCarManager> pJavaCarManager;
    _CJavaCarManager_AcquireInstance((IJavaCarManager**)&pJavaCarManager);
    ITestCar* pElaClsObj;
    IInterface* _carobj1 = NULL;
    jclass _jclazz1 = env->GetObjectClass(jsm);
    jmethodID _jmethodID1 = env->GetMethodID(_jclazz1, "getClassId", "()Ljava/lang/String;");
    jstring _jclsId1 = (jstring)env->CallObjectMethod(jsm, _jmethodID1);
    const char* _jclsIdStr1 = env->GetStringUTFChars(_jclsId1, nullptr);
    pJavaCarManager->GetCarObject(String(_jclsIdStr1), &_carobj1);
    env->ReleaseStringUTFChars(_jclsId1, _jclsIdStr1);

    if (!_carobj1) return;
    IServiceManager* _interface1 = IServiceManager::Probe(_carobj1);

    IInterface* _carobj2 = NULL;
    jclass _jclazz2 = env->GetObjectClass(jcarrier);
    jmethodID _jmethodID2 = env->GetMethodID(_jclazz2, "getClassId", "()Ljava/lang/String;");
    jstring _jclsId2 = (jstring)env->CallObjectMethod(jcarrier, _jmethodID2);
    const char* _jclsIdStr2 = env->GetStringUTFChars(_jclsId2, nullptr);
    pJavaCarManager->GetCarObject(String(_jclsIdStr2), &_carobj2);
    env->ReleaseStringUTFChars(_jclsId2, _jclsIdStr2);

    if (!_carobj2) return;
    ICarrier* _interface2 = ICarrier::Probe(_carobj2);

    ECode ec = CTestCar::New(_interface1, _interface2, &pElaClsObj);
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

void JNICALL native_CTestCar_Destroy(
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
