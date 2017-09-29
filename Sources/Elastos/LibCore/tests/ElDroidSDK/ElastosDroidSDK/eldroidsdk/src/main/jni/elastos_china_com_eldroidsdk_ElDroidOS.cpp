
#include "elastos_china_com_eldroidsdk_ElDroidOS.h"
#include "log.h"

//For elastos
#include "elastos/Elastos.CoreLibrary.Core.h"

using Elastos::Core::CString;
using Elastos::Core::ICharSequence;


jstring Java_elastos_china_com_eldroidsdk_ElDroidOS_getElastosString
  (JNIEnv *env, jobject)
{
    LOGD("LOG from JNI");
    AutoPtr<ICharSequence> cs;
    CString::New(String("The string comes form the Elastos Car object: [CString]."), (ICharSequence**)&cs);
    assert(cs != NULL);
    String str;
    cs->ToString(&str);
    return env->NewStringUTF(str.string());
}
