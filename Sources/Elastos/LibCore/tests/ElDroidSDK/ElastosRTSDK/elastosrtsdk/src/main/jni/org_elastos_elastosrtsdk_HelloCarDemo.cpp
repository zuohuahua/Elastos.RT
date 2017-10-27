
#include "org_elastos_elastosrtsdk_HelloCarDemo.h"

//For elastos
#include "elastos/Elastos.CoreLibrary.Core.h"
#include "elastos/Elastos.HelloCarDemo.h"
#include "elastos/_Elastos.HelloCarDemo.h"

using Elastos::HelloCarDemo::CHelloCar;
using Elastos::HelloCarDemo::IHelloCar;

jlong Java_org_elastos_elastosrtsdk_HelloCarDemo_nativeCreateElastosHelloCar
        (JNIEnv *, jobject)
{
    AutoPtr<IHelloCar> helloCarObj;
    ECode ec = CHelloCar::New((IHelloCar**)&helloCarObj);
    if (ec != NOERROR || helloCarObj == NULL) {
        return 0;
    }
    return (jlong)helloCarObj.Get();
}

void Java_org_elastos_elastosrtsdk_HelloCarDemo_nativeFinalize
        (JNIEnv *, jobject, jlong jproxy)
{
    IHelloCar* obj = (IHelloCar*)jproxy;
    if (obj != NULL) {
        obj->Release();
    }
}

jstring Java_org_elastos_elastosrtsdk_HelloCarDemo_nativeHelloCar
   (JNIEnv *env, jobject, jlong jproxy)
{
    IHelloCar* helloCarObj = (IHelloCar*)jproxy;
    if ( helloCarObj == NULL) {
        return NULL;
    }

    String helloString;

    helloCarObj->Hello(&helloString);

    String newString("Hello, ");
    newString += helloString + "!";

    return env->NewStringUTF(newString.string());
}