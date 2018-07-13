
#ifndef __CCARRIERLISTENER_H__
#define __CCARRIERLISTENER_H__

#include "_CCarrierListener.h"
#include <jni.h>
#include "elastos/core/Object.h"

using Elastos::Core::IComparable;
using Elastos::Core::EIID_IComparable;


CarClass(CCarrierListener)
    , public Object
    , public ICarrierListener
    , public IJavaInterface
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    virtual ~CCarrierListener()
    {
        GetEnv()->DeleteGlobalRef(mObj);
        Detach();
    }

    CARAPI OnIdle();

    CARAPI OnConnectionChanged(
        /* [in] */ Boolean online);

    CARAPI OnReady();

    CARAPI OnFriendRequest(
        /* [in] */ const String& uid,
        /* [in] */ const String& hello);

    CARAPI OnFriendConnetionChanged(
        /* [in] */ const String& uid,
        /* [in] */ Boolean online);

    CARAPI OnPortForwardingRequest(
        /* [in] */ const String &uid,
        /* [in] */ const String &servicePort,
        /* [out] */ Boolean *accept);

    CARAPI OnPortForwardingResult(
        /* [in] */ const String &uid,
        /* [in] */ const String &localPort,
        /* [in] */ const String &remotePort,
        /* [in] */ ECode code);

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


#endif // __CCARRIERLISTENER_H__
