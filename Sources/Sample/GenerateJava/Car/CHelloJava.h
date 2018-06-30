
#ifndef __CHELLOJAVA_H__
#define __CHELLOJAVA_H__

#include "_CHelloJava.h"
#include <jni.h>
#include "elastos/core/Object.h"

using Elastos::Core::IComparable;
using Elastos::Core::EIID_IComparable;


CarClass(CHelloJava)
    , public Object
    , public IHelloJava
    , public IJavaInterface
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    virtual ~CHelloJava()
    {
        GetEnv()->DeleteGlobalRef(mObj);
        Detach();
    }

    CARAPI Hello(
        /* [out] */ String * pHello);

    CARAPI JavaInit(
        /* [in] */ Handle64 jvm,
        /* [in] */ Handle64 jobj);

    CARAPI GetJavaObject(
        /* [out] */ Handle64 * pJobj);

private:
    JNIEnv* GetEnv();
    void Detach();

private:
    // TODO: Add your private member variables here.
    JavaVM* mJvm;
    jobject mObj;
};


#endif // __CHELLOJAVA_H__
