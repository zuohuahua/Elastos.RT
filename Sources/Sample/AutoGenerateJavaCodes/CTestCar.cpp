
#include "CTestCar.h"

CAR_OBJECT_IMPL(CTestCar)
CAR_INTERFACE_IMPL(CTestCar, Object, ITestCar, ITestCar2);

ECode CTestCar::SetInt(
    /* [in] */ Int32 value)
{
    if (mClassPath.IsNullOrEmpty()) {
        return E_INVALID_ARGUMENT;
    }

    //Call the java codes, Now we are only support static method.
    String outSign;
    String signature("(");
    signature.Append("I");
    if (!outSign.IsNullOrEmpty()) {
        signature.Append(")");
        signature.Append(outSign);
    }
    else {
        signature.Append(")V");
    }

    jclass cls = mEnv->FindClass(mClassPath.string());
    String methodName("SetInt");
    jmethodID staticMethod = mEnv->GetStaticMethodID(cls, methodName.string(), signature.string());
    mEnv->CallStaticVoidMethod(cls, staticMethod);

    return NOERROR;
}

ECode CTestCar::GetInt(
    /* [out] */ Int32 * pValue)
{
    if (mClassPath.IsNullOrEmpty()) {
        return E_INVALID_ARGUMENT;
    }

    //Call the java codes, Now we are only support static method.
    String outSign;
    String signature("(");
    outSign.Append("I");
    if (!outSign.IsNullOrEmpty()) {
        signature.Append(")");
        signature.Append(outSign);
    }
    else {
        signature.Append(")V");
    }

    jclass cls = mEnv->FindClass(mClassPath.string());
    String methodName("GetInt");
    jmethodID staticMethod = mEnv->GetStaticMethodID(cls, methodName.string(), signature.string());
    mEnv->CallStaticVoidMethod(cls, staticMethod);

    return NOERROR;
}

ECode CTestCar::SetString(
    /* [in] */ const String& value)
{
    if (mClassPath.IsNullOrEmpty()) {
        return E_INVALID_ARGUMENT;
    }

    //Call the java codes, Now we are only support static method.
    String outSign;
    String signature("(");
    signature.Append("Ljava/lang/String;");
    if (!outSign.IsNullOrEmpty()) {
        signature.Append(")");
        signature.Append(outSign);
    }
    else {
        signature.Append(")V");
    }

    jclass cls = mEnv->FindClass(mClassPath.string());
    String methodName("SetString");
    jmethodID staticMethod = mEnv->GetStaticMethodID(cls, methodName.string(), signature.string());
    mEnv->CallStaticVoidMethod(cls, staticMethod);

    return NOERROR;
}

ECode CTestCar::GetString(
    /* [out] */ String * pValue)
{
    if (mClassPath.IsNullOrEmpty()) {
        return E_INVALID_ARGUMENT;
    }

    //Call the java codes, Now we are only support static method.
    String outSign;
    String signature("(");
    outSign.Append("Ljava/lang/String;");
    if (!outSign.IsNullOrEmpty()) {
        signature.Append(")");
        signature.Append(outSign);
    }
    else {
        signature.Append(")V");
    }

    jclass cls = mEnv->FindClass(mClassPath.string());
    String methodName("GetString");
    jmethodID staticMethod = mEnv->GetStaticMethodID(cls, methodName.string(), signature.string());
    mEnv->CallStaticVoidMethod(cls, staticMethod);

    return NOERROR;
}

ECode CTestCar::Normal()
{
    if (mClassPath.IsNullOrEmpty()) {
        return E_INVALID_ARGUMENT;
    }

    //Call the java codes, Now we are only support static method.
    String outSign;
    String signature("(");
    if (!outSign.IsNullOrEmpty()) {
        signature.Append(")");
        signature.Append(outSign);
    }
    else {
        signature.Append(")V");
    }

    jclass cls = mEnv->FindClass(mClassPath.string());
    String methodName("Normal");
    jmethodID staticMethod = mEnv->GetStaticMethodID(cls, methodName.string(), signature.string());
    mEnv->CallStaticVoidMethod(cls, staticMethod);

    return NOERROR;
}

ECode CTestCar::Test1(
    /* [in] */ Int32 value1,
    /* [in] */ Boolean value2,
    /* [in] */ Float value3,
    /* [in] */ Double value4,
    /* [in] */ Int64 value5,
    /* [in] */ Byte value6,
    /* [in] */ Char32 value7,
    /* [in] */ const String& value8)
{
    if (mClassPath.IsNullOrEmpty()) {
        return E_INVALID_ARGUMENT;
    }

    //Call the java codes, Now we are only support static method.
    String outSign;
    String signature("(");
    signature.Append("I");
    signature.Append("Z");
    signature.Append("F");
    signature.Append("D");
    signature.Append("J");
    signature.Append("B");
    signature.Append("C");
    signature.Append("Ljava/lang/String;");
    if (!outSign.IsNullOrEmpty()) {
        signature.Append(")");
        signature.Append(outSign);
    }
    else {
        signature.Append(")V");
    }

    jclass cls = mEnv->FindClass(mClassPath.string());
    String methodName("Test1");
    jmethodID staticMethod = mEnv->GetStaticMethodID(cls, methodName.string(), signature.string());
    mEnv->CallStaticVoidMethod(cls, staticMethod);

    return NOERROR;
}

ECode CTestCar::Test2(
    /* [in] */ Int32 value1,
    /* [in] */ Boolean value2,
    /* [in] */ Float value3,
    /* [in] */ Double value4,
    /* [in] */ Int64 value5,
    /* [in] */ Byte value6,
    /* [in] */ Char32 value7,
    /* [in] */ const String& value8,
    /* [in] */ const String& value9,
    /* [in] */ const String& value10,
    /* [out] */ Int32 * pResult)
{
    if (mClassPath.IsNullOrEmpty()) {
        return E_INVALID_ARGUMENT;
    }

    //Call the java codes, Now we are only support static method.
    String outSign;
    String signature("(");
    signature.Append("I");
    signature.Append("Z");
    signature.Append("F");
    signature.Append("D");
    signature.Append("J");
    signature.Append("B");
    signature.Append("C");
    signature.Append("Ljava/lang/String;");
    signature.Append("Ljava/lang/String;");
    signature.Append("Ljava/lang/String;");
    outSign.Append("I");
    if (!outSign.IsNullOrEmpty()) {
        signature.Append(")");
        signature.Append(outSign);
    }
    else {
        signature.Append(")V");
    }

    jclass cls = mEnv->FindClass(mClassPath.string());
    String methodName("Test2");
    jmethodID staticMethod = mEnv->GetStaticMethodID(cls, methodName.string(), signature.string());
    mEnv->CallStaticVoidMethod(cls, staticMethod);

    return NOERROR;
}

ECode CTestCar::SetInt2(
    /* [in] */ Int32 value)
{
    if (mClassPath.IsNullOrEmpty()) {
        return E_INVALID_ARGUMENT;
    }

    //Call the java codes, Now we are only support static method.
    String outSign;
    String signature("(");
    signature.Append("I");
    if (!outSign.IsNullOrEmpty()) {
        signature.Append(")");
        signature.Append(outSign);
    }
    else {
        signature.Append(")V");
    }

    jclass cls = mEnv->FindClass(mClassPath.string());
    String methodName("SetInt2");
    jmethodID staticMethod = mEnv->GetStaticMethodID(cls, methodName.string(), signature.string());
    mEnv->CallStaticVoidMethod(cls, staticMethod);

    return NOERROR;
}

ECode CTestCar::Update(
    /* [in] */ const String& value1,
    /* [in] */ const String& value2,
    /* [in] */ const String& value3,
    /* [out] */ String * pValue)
{
    if (mClassPath.IsNullOrEmpty()) {
        return E_INVALID_ARGUMENT;
    }

    //Call the java codes, Now we are only support static method.
    String outSign;
    String signature("(");
    signature.Append("Ljava/lang/String;");
    signature.Append("Ljava/lang/String;");
    signature.Append("Ljava/lang/String;");
    outSign.Append("Ljava/lang/String;");
    if (!outSign.IsNullOrEmpty()) {
        signature.Append(")");
        signature.Append(outSign);
    }
    else {
        signature.Append(")V");
    }

    jclass cls = mEnv->FindClass(mClassPath.string());
    String methodName("Update");
    jmethodID staticMethod = mEnv->GetStaticMethodID(cls, methodName.string(), signature.string());
    mEnv->CallStaticVoidMethod(cls, staticMethod);

    return NOERROR;
}

ECode CTestCar::constructor(
    /* [in] */ Handle64 jvm,
    /* [in] */ const String& classPath)
{
    // TODO: Add your code here for constructor
    JavaVM* vm = (JavaVM*)jvm;
    assert(vm != NULL);
    mClassPath = classPath;

    vm->AttachCurrentThread(&mEnv, NULL);
    jclass cls = mEnv->FindClass(mClassPath.string());
    if (cls == NULL) {
        return E_INVALID_ARGUMENT;
    }

    return NOERROR;
}

