
#include "CSingletonTest.h"

CAR_SINGLETON_IMPL(CSingletonTest)
CAR_INTERFACE_IMPL(CSingletonTest, Singleton, ITestCar2, IJavaInterface);

ECode CSingletonTest::SetInt2(
    /* [in] */ Int32 value)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "SetInt2", "(I)V");
    env->CallVoidMethod(cls, method, value);
    Detach();
    return NOERROR;
}

ECode CSingletonTest::Update(
    /* [in] */ const String& value1,
    /* [in] */ const String& value2,
    /* [in] */ const String& value3,
    /* [out] */ String * value)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "Update", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
    jstring _jstr1 = env->NewStringUTF(value1.string());
    jstring _jstr2 = env->NewStringUTF(value2.string());
    jstring _jstr3 = env->NewStringUTF(value3.string());
    jstring _jstr = (jstring)env->CallObjectMethod(cls, method, _jstr1, _jstr2, _jstr3);
    const char* __str = env->GetStringUTFChars(_jstr, NULL);
    *value = String(__str);
    env->ReleaseStringUTFChars(_jstr, __str);
    Detach();
    return NOERROR;
}

ECode CSingletonTest::Test1(
    /* [in] */ const String& name,
    /* [in] */ const ArrayOf<Int32> & array)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "Test1", "(Ljava/lang/String;[I)V");
    jstring _jstr1 = env->NewStringUTF(name.string());
    jintArray _jarray2 = env->NewIntArray(array.GetLength());
    if (_jarray2 == NULL) {
        Detach();
        return E_OUT_OF_MEMORY;
    }

    jint _fill2[array.GetLength()];
    for (Int32 i = 0; i < array.GetLength(); i++) {
        _fill2[i] = array[i];
    }
    env->SetIntArrayRegion(_jarray2, 0, array.GetLength(), _fill2);

    env->CallVoidMethod(cls, method, _jstr1, _jarray2);
    Detach();
    return NOERROR;
}

ECode CSingletonTest::Test2(
    /* [in] */ const ArrayOf<String> & strArray,
    /* [in] */ const ArrayOf<Int32> & intArray)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "Test2", "([Ljava/lang/String;[I)V");
    jclass _clazz1 = env->FindClass("java/lang/String");
    jobjectArray _jarray1 = env->NewObjectArray(strArray.GetLength(), _clazz1, NULL);
    if (_jarray1 == NULL) {
        Detach();
        return E_OUT_OF_MEMORY;
    }

    for (Int32 i = 0; i < strArray.GetLength(); i++) {
        jstring _str = env->NewStringUTF(strArray[i].string());
        env->SetObjectArrayElement(_jarray1, i, _str);
    }

    jintArray _jarray2 = env->NewIntArray(intArray.GetLength());
    if (_jarray2 == NULL) {
        Detach();
        return E_OUT_OF_MEMORY;
    }

    jint _fill2[intArray.GetLength()];
    for (Int32 i = 0; i < intArray.GetLength(); i++) {
        _fill2[i] = intArray[i];
    }
    env->SetIntArrayRegion(_jarray2, 0, intArray.GetLength(), _fill2);

    env->CallVoidMethod(cls, method, _jarray1, _jarray2);
    Detach();
    return NOERROR;
}

ECode CSingletonTest::Test3(
    /* [in] */ Int32 i,
    /* [out, callee] */ ArrayOf<String> ** strArray)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "Test3", "(I)[Ljava/lang/String;");
    jobjectArray _jarray = (jobjectArray)env->CallObjectMethod(cls, method, i);
    int _len = env->GetArrayLength(_jarray);
    AutoPtr<ArrayOf<String> > _array = ArrayOf<String>::Alloc(_len);
    if (!_array) {
        Detach();
        return E_OUT_OF_MEMORY;
    }

    for (Int32 i = 0; i < _len; i++) {
        jstring _item = (jstring)env->GetObjectArrayElement(_jarray, i);
        const char* __str = env->GetStringUTFChars(_item, NULL);
        (*_array)[i] = String(__str);
        env->ReleaseStringUTFChars(_item, __str);
    }
    *strArray = _array;
    (*strArray)->AddRef();
    Detach();
    return NOERROR;
}

ECode CSingletonTest::Test4()
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "Test4", "()V");
    env->CallVoidMethod(cls, method);
    Detach();
    return NOERROR;
}

ECode CSingletonTest::Test5(
    /* [out] */ String * str)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "Test5", "()Ljava/lang/String;");
    jstring _jstr = (jstring)env->CallObjectMethod(cls, method);
    const char* __str = env->GetStringUTFChars(_jstr, NULL);
    *str = String(__str);
    env->ReleaseStringUTFChars(_jstr, __str);
    Detach();
    return NOERROR;
}

ECode CSingletonTest::Test6(
    /* [in] */ Int32 i,
    /* [in] */ const String& str,
    /* [out, callee] */ ArrayOf<Float> ** floatArray)
{
    JNIEnv* env = GetEnv();
    jclass cls = env->GetObjectClass(mObj);
    jmethodID method = env->GetMethodID(cls, "Test6", "(ILjava/lang/String;)[F");
    jstring _jstr2 = env->NewStringUTF(str.string());
    jfloatArray _jarray = (jfloatArray)env->CallObjectMethod(cls, method, i, _jstr2);
    int _len = env->GetArrayLength(_jarray);
    AutoPtr<ArrayOf<Float> > _array = ArrayOf<Float>::Alloc(_len);
    if (!_array) {
        Detach();
        return E_OUT_OF_MEMORY;
    }

    jfloat* _items = env->GetFloatArrayElements(_jarray, 0);
    for (Int32 i = 0; i < _len; i++) {
        (*_array)[i] = _items[i];
    }
    env->ReleaseFloatArrayElements(_jarray, _items, 0);
    *floatArray = _array;
    (*floatArray)->AddRef();
    Detach();
    return NOERROR;
}

ECode CSingletonTest::JavaInit(
    /* [in] */ Handle64 jvm,
    /* [in] */ Handle64 jobj)
{
    mJvm = (JavaVM*)jvm;
    assert(mJvm != NULL);

    jobject jclsobj = *((jobject*)jobj);
    mObj = GetEnv()->NewGlobalRef(jclsobj);
    if (mObj == NULL) {
        return E_INVALID_ARGUMENT;
    }

    return NOERROR;
}

ECode CSingletonTest::GetJavaObject(
    /* [out] */ Handle64* jobj)
{
    if (!jobj) {
        return E_INVALID_ARGUMENT;
    }

    *jobj = (Handle64)&mObj;
    return NOERROR;
}

ECode CSingletonTest::constructor()
{
    // TODO: Add your code here for constructor
    return NOERROR;
}

JNIEnv* CSingletonTest::GetEnv()
{
    JNIEnv* env;
    assert(mJvm != NULL);
    mJvm->AttachCurrentThread(&env, NULL);
    return env;
}

void CSingletonTest::Detach()
{
    assert(mJvm != NULL);
    mJvm->DetachCurrentThread();
}

