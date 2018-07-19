
#include <jni.h>

//For Elastos
#include "Elastos.AutoGenerateJavaCodes.h"

void JNICALL native_CSingletonTest0(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj)
{
    AutoPtr<IJavaCarManager> pJavaCarManager;
    _CJavaCarManager_AcquireInstance((IJavaCarManager**)&pJavaCarManager);
    ITestCar2* pElaClsObj;
    ECode ec = CSingletonTest::AcquireSingleton(&pElaClsObj);
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

void JNICALL native_CSingletonTest_Destroy(
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


void JNICALL native_CSingletonTest_ITestCar2_SetInt2(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jint jvalue)
{
    AutoPtr<IJavaCarManager> pJavaCarManager;
    _CJavaCarManager_AcquireInstance((IJavaCarManager**)&pJavaCarManager);

    IInterface* pElaClsObj = NULL;
    jclass jclazz = env->GetObjectClass(jobj);
    jmethodID jmethodID = env->GetMethodID(jclazz, "getClassId", "()Ljava/lang/String;");
    jstring jclassId = (jstring)env->CallObjectMethod(jobj, jmethodID);
    const char* jclsIdStr = env->GetStringUTFChars(jclassId, nullptr);
    pJavaCarManager->GetCarObject(String(jclsIdStr), &pElaClsObj);
    env->ReleaseStringUTFChars(jclassId, jclsIdStr);

    ITestCar2::Probe(pElaClsObj)->SetInt2(jvalue);
}

jstring JNICALL native_CSingletonTest_ITestCar2_Update(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jstring jvalue1,
    /* [in] */ jstring jvalue2,
    /* [in] */ jstring jvalue3)
{
    AutoPtr<IJavaCarManager> pJavaCarManager;
    _CJavaCarManager_AcquireInstance((IJavaCarManager**)&pJavaCarManager);

    IInterface* pElaClsObj = NULL;
    jclass jclazz = env->GetObjectClass(jobj);
    jmethodID jmethodID = env->GetMethodID(jclazz, "getClassId", "()Ljava/lang/String;");
    jstring jclassId = (jstring)env->CallObjectMethod(jobj, jmethodID);
    const char* jclsIdStr = env->GetStringUTFChars(jclassId, nullptr);
    pJavaCarManager->GetCarObject(String(jclsIdStr), &pElaClsObj);
    env->ReleaseStringUTFChars(jclassId, jclsIdStr);

    const char* str1 = env->GetStringUTFChars(jvalue1, NULL);
    const char* str2 = env->GetStringUTFChars(jvalue2, NULL);
    const char* str3 = env->GetStringUTFChars(jvalue3, NULL);
    String _retValue;
    ITestCar2::Probe(pElaClsObj)->Update(String(str1), String(str2), String(str3), &_retValue);
    env->ReleaseStringUTFChars(jvalue1, str1);
    env->ReleaseStringUTFChars(jvalue2, str2);
    env->ReleaseStringUTFChars(jvalue3, str3);
    return env->NewStringUTF(_retValue.string());
}

void JNICALL native_CSingletonTest_ITestCar2_Test1(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jstring jname,
    /* [in] */ jintArray jarray)
{
    AutoPtr<IJavaCarManager> pJavaCarManager;
    _CJavaCarManager_AcquireInstance((IJavaCarManager**)&pJavaCarManager);

    IInterface* pElaClsObj = NULL;
    jclass jclazz = env->GetObjectClass(jobj);
    jmethodID jmethodID = env->GetMethodID(jclazz, "getClassId", "()Ljava/lang/String;");
    jstring jclassId = (jstring)env->CallObjectMethod(jobj, jmethodID);
    const char* jclsIdStr = env->GetStringUTFChars(jclassId, nullptr);
    pJavaCarManager->GetCarObject(String(jclsIdStr), &pElaClsObj);
    env->ReleaseStringUTFChars(jclassId, jclsIdStr);

    const char* str1 = env->GetStringUTFChars(jname, NULL);
    int _len2 = env->GetArrayLength(jarray);
    AutoPtr<ArrayOf<Int32> > _array2 = ArrayOf<Int32>::Alloc(_len2);
    if(!_array2) return;
    jint* _items2 = env->GetIntArrayElements(jarray, 0);
    for (Int32 i = 0; i < _len2; i++) {
        (*_array2)[i] = _items2[i];
    }
    env->ReleaseIntArrayElements(jarray, _items2, 0);

    ITestCar2::Probe(pElaClsObj)->Test1(String(str1), *_array2);
    env->ReleaseStringUTFChars(jname, str1);
}

void JNICALL native_CSingletonTest_ITestCar2_Test2(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jobjectArray jstrArray,
    /* [in] */ jintArray jintArray)
{
    AutoPtr<IJavaCarManager> pJavaCarManager;
    _CJavaCarManager_AcquireInstance((IJavaCarManager**)&pJavaCarManager);

    IInterface* pElaClsObj = NULL;
    jclass jclazz = env->GetObjectClass(jobj);
    jmethodID jmethodID = env->GetMethodID(jclazz, "getClassId", "()Ljava/lang/String;");
    jstring jclassId = (jstring)env->CallObjectMethod(jobj, jmethodID);
    const char* jclsIdStr = env->GetStringUTFChars(jclassId, nullptr);
    pJavaCarManager->GetCarObject(String(jclsIdStr), &pElaClsObj);
    env->ReleaseStringUTFChars(jclassId, jclsIdStr);

    int _len1 = env->GetArrayLength(jstrArray);
    AutoPtr<ArrayOf<String> > _array1 = ArrayOf<String>::Alloc(_len1);
    if(!_array1) return;
    for (Int32 i = 0; i < _len1; i++) {
        jstring _item = (jstring)env->GetObjectArrayElement(jstrArray, i);
        const char* __str = env->GetStringUTFChars(_item, NULL);
        (*_array1)[i] = String(__str);
        env->ReleaseStringUTFChars(_item, __str);
    }

    int _len2 = env->GetArrayLength(jintArray);
    AutoPtr<ArrayOf<Int32> > _array2 = ArrayOf<Int32>::Alloc(_len2);
    if(!_array2) return;
    jint* _items2 = env->GetIntArrayElements(jintArray, 0);
    for (Int32 i = 0; i < _len2; i++) {
        (*_array2)[i] = _items2[i];
    }
    env->ReleaseIntArrayElements(jintArray, _items2, 0);

    ITestCar2::Probe(pElaClsObj)->Test2(*_array1, *_array2);
}

jobjectArray JNICALL native_CSingletonTest_ITestCar2_Test3(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jint ji)
{
    AutoPtr<IJavaCarManager> pJavaCarManager;
    _CJavaCarManager_AcquireInstance((IJavaCarManager**)&pJavaCarManager);

    IInterface* pElaClsObj = NULL;
    jclass jclazz = env->GetObjectClass(jobj);
    jmethodID jmethodID = env->GetMethodID(jclazz, "getClassId", "()Ljava/lang/String;");
    jstring jclassId = (jstring)env->CallObjectMethod(jobj, jmethodID);
    const char* jclsIdStr = env->GetStringUTFChars(jclassId, nullptr);
    pJavaCarManager->GetCarObject(String(jclsIdStr), &pElaClsObj);
    env->ReleaseStringUTFChars(jclassId, jclsIdStr);

    AutoPtr<ArrayOf<String> > _retValue;
    ITestCar2::Probe(pElaClsObj)->Test3(ji, (ArrayOf<String>**)&_retValue);
    jclass _retClazz = env->FindClass("java/lang/String");
    jobjectArray retArray = env->NewObjectArray(_retValue->GetLength(), _retClazz, NULL);
    if (retArray == NULL) return NULL;
    for (Int32 i = 0; i < _retValue->GetLength(); i++) {
        jstring _str = env->NewStringUTF((*_retValue)[i].string());
        env->SetObjectArrayElement(retArray, i, _str);
    }

    return retArray;
}

void JNICALL native_CSingletonTest_ITestCar2_Test4(
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
    env->ReleaseStringUTFChars(jclassId, jclsIdStr);

    ITestCar2::Probe(pElaClsObj)->Test4();
}

jstring JNICALL native_CSingletonTest_ITestCar2_Test5(
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
    env->ReleaseStringUTFChars(jclassId, jclsIdStr);

    String _retValue;
    ITestCar2::Probe(pElaClsObj)->Test5(&_retValue);
    return env->NewStringUTF(_retValue.string());
}

jfloatArray JNICALL native_CSingletonTest_ITestCar2_Test6(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj,
    /* [in] */ jint ji,
    /* [in] */ jstring jstr)
{
    AutoPtr<IJavaCarManager> pJavaCarManager;
    _CJavaCarManager_AcquireInstance((IJavaCarManager**)&pJavaCarManager);

    IInterface* pElaClsObj = NULL;
    jclass jclazz = env->GetObjectClass(jobj);
    jmethodID jmethodID = env->GetMethodID(jclazz, "getClassId", "()Ljava/lang/String;");
    jstring jclassId = (jstring)env->CallObjectMethod(jobj, jmethodID);
    const char* jclsIdStr = env->GetStringUTFChars(jclassId, nullptr);
    pJavaCarManager->GetCarObject(String(jclsIdStr), &pElaClsObj);
    env->ReleaseStringUTFChars(jclassId, jclsIdStr);

    const char* str2 = env->GetStringUTFChars(jstr, NULL);
    AutoPtr<ArrayOf<Float> > _retValue;
    ITestCar2::Probe(pElaClsObj)->Test6(ji, String(str2), (ArrayOf<Float>**)&_retValue);
    jfloatArray retArray = env->NewFloatArray(_retValue->GetLength());
    if (retArray == NULL) return NULL;
    jfloat _fill[_retValue->GetLength()];
    for (Int32 i = 0; i < _retValue->GetLength(); i++) {
        _fill[i] = (*_retValue)[i];
    }
    env->SetFloatArrayRegion(retArray, 0, _retValue->GetLength(), _fill);

    return retArray;
}


static const JNINativeMethod gMethods[] = {
    {"native_CSingletonTest", "()V", (void*)native_CSingletonTest0},
    {"native_CSingletonTest_Destroy", "()V", (void*)native_CSingletonTest_Destroy},
    {"native_CSingletonTest_ITestCar2_SetInt2", "(I)V", (void*)native_CSingletonTest_ITestCar2_SetInt2},
    {"native_CSingletonTest_ITestCar2_Update", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", (void*)native_CSingletonTest_ITestCar2_Update},
    {"native_CSingletonTest_ITestCar2_Test1", "(Ljava/lang/String;[I)V", (void*)native_CSingletonTest_ITestCar2_Test1},
    {"native_CSingletonTest_ITestCar2_Test2", "([Ljava/lang/String;[I)V", (void*)native_CSingletonTest_ITestCar2_Test2},
    {"native_CSingletonTest_ITestCar2_Test3", "(I)[Ljava/lang/String;", (void*)native_CSingletonTest_ITestCar2_Test3},
    {"native_CSingletonTest_ITestCar2_Test4", "()V", (void*)native_CSingletonTest_ITestCar2_Test4},
    {"native_CSingletonTest_ITestCar2_Test5", "()Ljava/lang/String;", (void*)native_CSingletonTest_ITestCar2_Test5},
    {"native_CSingletonTest_ITestCar2_Test6", "(ILjava/lang/String;)[F", (void*)native_CSingletonTest_ITestCar2_Test6},
};

int registerCSingletonTestMethod(JNIEnv * env) {
    jclass clazz = env->FindClass("org/elastos/Elastos.AutoGenerateJavaCodes/CSingletonTest");
    if (clazz == NULL) return JNI_FALSE;

    int ret = env->RegisterNatives(clazz, gMethods, sizeof(gMethods)/sizeof(JNINativeMethod));
    if (ret < 0) return ret;

    return JNI_TRUE;
};
