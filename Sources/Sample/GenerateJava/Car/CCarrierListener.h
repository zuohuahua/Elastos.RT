
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

    CCarrierListener()
    {
        _CJavaCarManager_AcquireInstance(&mJavaCarManager);
    }

    virtual ~CCarrierListener()
    {
        mJavaCarManager->Release();
    }

    CARAPI OnIdle();

    CARAPI OnConnectionChanged(
        /* [in] */ Boolean online);

    CARAPI OnReady();

    CARAPI OnFriendRequest(
        /* [in] */ const String& uid,
        /* [in] */ const String& hello);

    CARAPI OnFriendConnectionChanged(
        /* [in] */ const String& uid,
        /* [in] */ Boolean online);

    CARAPI OnPortForwardingRequest(
        /* [in] */ const String& uid,
        /* [in] */ const String& servicePort,
        /* [out] */ Boolean * pAccept);

    CARAPI OnPortForwardingResult(
        /* [in] */ const String& uid,
        /* [in] */ const String& localPort,
        /* [in] */ const String& remotePort,
        /* [in] */ ECode code);

    CARAPI OnMessageReceived(
        /* [in] */ const String& uid,
        /* [in] */ const ArrayOf<Byte> & message);

    CARAPI JavaInit(
        /* [in] */ Handle64 jvm);

private:
    JNIEnv* GetEnv();
    void Detach();

private:
    // TODO: Add your private member variables here.
    JavaVM* mJvm;
    IJavaCarManager* mJavaCarManager;
};


#endif // __CCARRIERLISTENER_H__
