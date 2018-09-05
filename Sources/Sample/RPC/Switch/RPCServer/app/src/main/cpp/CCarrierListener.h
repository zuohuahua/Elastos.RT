//
// Created by zuo on 18-4-11.
//

#ifndef RPCDEMO_CCARRIERLISTENER_H
#define RPCDEMO_CCARRIERLISTENER_H

#include <elastos/core/Object.h>
#include <jni.h>
#include "ElastosCore.h"
#include "elatypes.h"


class CCarrierListener
        : public Object
        , public ICarrierListener
{
public:

    CAR_INTERFACE_DECL()

    CCarrierListener(
            JNIEnv *env,
            jobject jobj)
    {
        env->GetJavaVM(&mVm);
        mObj = env->NewGlobalRef(jobj);
    }

    virtual ~CCarrierListener()
    {
        GetEnv()->DeleteGlobalRef(mObj);
    }

    CARAPI OnIdle();

    CARAPI OnConnectionChanged(
            /* [in] */ _ELASTOS Boolean online);

    CARAPI OnReady();

    CARAPI OnFriendRequest(
            /* [in] */ const _ELASTOS String& uid,
            /* [in] */ const _ELASTOS String& hello);

    CARAPI OnFriendConnectionChanged(
            /* [in] */ const _ELASTOS String& uid,
            /* [in] */ _ELASTOS Boolean online);

    CARAPI OnPortForwardingRequest(
            /* [in] */ const String &uid,
            /* [in] */ const String &servicePort,
            /* [out] */ Boolean *accept);

    CARAPI OnPortForwardingResult(
            /* [in] */ const String &uid,
            /* [in] */ const String &localPort,
            /* [in] */ const String &remotePort,
            /* [in] */ ECode code);

    CARAPI OnMessageReceived(
            /* [in] */ const String& uid,
            /* [in] */ const ArrayOf<Byte>& message);

private:
    JNIEnv* GetEnv();

    void Detach();

private:
    JavaVM* mVm;
    jobject mObj;
};

#endif //RPCDEMO_CCARRIERLISTENER_H
