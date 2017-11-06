
#include "elastos_china_com_elastossample_JniUtils.h"

//For elastos
//#include "elastos/Elastos.CoreLibrary.Core.h"

//using Elastos::Core::CString;
//using Elastos::Core::ICharSequence;

jstring Java_elastos_china_com_elastossample_JniUtils_getCLanguageString
  (JNIEnv *env, jobject)
{
    return env->NewStringUTF("This just a test for Elastos developer!");
}

jstring Java_elastos_china_com_elastossample_JniUtils_getElastosString
  (JNIEnv *env, jobject)
{
    //AutoPtr<ICharSequence> cs;
    //CString::New(String("The string come form the car object [CString]."), (ICharSequence**)&cs);
    //assert(cs != NULL);
    //String str;
    //cs->ToString(&str);
    //return env->NewStringUTF(str.string());
    return env->NewStringUTF("x=x=x=x=xx=x=x=x=x=x=");
}
