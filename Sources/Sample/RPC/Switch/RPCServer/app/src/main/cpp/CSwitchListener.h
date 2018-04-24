//
// Created by 林楠 on 2018/4/11.
//

#ifndef RPCDEMO_CMESSAGELISTENER_H
#define RPCDEMO_CMESSAGELISTENER_H

#include <elastos/core/Object.h>
#include <jni.h>
#include "_ElastosCore.h"
#include "elatypes.h"
#include <_Swtich.h>

class CSwitchListener
    : public Object
    , public ISwitchListener
{
public:
    CAR_INTERFACE_DECL()

    CSwitchListener(
            JNIEnv *env,
            jobject jobj)
    {
        env->GetJavaVM(&mVm);
        mObj = env->NewGlobalRef(jobj);
    }

    virtual ~CSwitchListener()
    {
    }

    CARAPI OnSwitch1Changed(
        /* [in] */ Boolean on);

    CARAPI OnSwitch2Changed(
            /* [in] */ Boolean on);


private:
    JNIEnv* GetEnv();

    void Detach();

private:
    JavaVM* mVm;
    jobject mObj;
};
#endif //RPCDEMO_CMESSAGELISTENER_H
