//
//  CCarrierListener.cpp
//  SwitchServer
//
//  Created by Joel Liang on 2018/8/26.
//

#include <stdio.h>

#include "CCarrierListener.h"
#include "CCarrierListenerCAPI.h"
#include <Elastos.CoreLibrary.h>


CAR_INTERFACE_IMPL(CCarrierListener, Object, ICarrierListener)

_ELASTOS ECode CCarrierListener::OnIdle()
{
    return onIdle ? onIdle(mSwiftObj) : NOERROR;
}

_ELASTOS ECode CCarrierListener::OnConnectionChanged(
                 /* [in] */ _ELASTOS Boolean online)
{
    printf("Func: %s\n", __FUNCTION__);
    printf("online: %d\n", online);
    return onConnectionChanged ? onConnectionChanged(mSwiftObj, online) : NOERROR;
}

_ELASTOS ECode CCarrierListener::OnReady()
{
    printf("Func: %s\n", __FUNCTION__);
    return onReady ? onReady(mSwiftObj) : NOERROR;
}

_ELASTOS ECode CCarrierListener::OnFriendRequest(
                    /* [in] */ const _ELASTOS String& uid,
                    /* [in] */ const _ELASTOS String& hello)
{
    printf("Func: %s\n", __FUNCTION__);
    printf("uid: %s\n", uid.string());
    printf("hello: %s\n", hello.string());
    return onFriendRequest
                ? onFriendRequest(mSwiftObj, uid.string(), hello.string())
                : NOERROR;
}

_ELASTOS ECode CCarrierListener::OnFriendConnectionChanged(
                    /* [in] */ const _ELASTOS String& uid,
                    /* [in] */ _ELASTOS Boolean online)
{
    printf("Func: %s\n", __FUNCTION__);
    printf("uid: %s\n", uid.string());
    printf("online: %d\n", online);
    return onFriendConnectionChanged
                ? onFriendConnectionChanged(mSwiftObj, uid.string(), online)
                : NOERROR;
}

_ELASTOS ECode CCarrierListener::OnPortForwardingRequest(
                    /* [in] */ const String& uid,
                    /* [in] */ const String& servicePort,
                    /* [out] */ Boolean* accept)
{
    printf("Func: %s\n", __FUNCTION__);
    printf("uid: %s\n", uid.string());
    printf("servicePort: %s\n", servicePort.string());
    return onPortForwardingRequest
                ? onPortForwardingRequest(mSwiftObj, uid.string(),
                                        servicePort.string(),
                                        accept)
                : NOERROR;
}

_ELASTOS ECode CCarrierListener::OnPortForwardingResult(
                    /* [in] */ const String &uid,
                    /* [in] */ const String &localPort,
                    /* [in] */ const String &remotePort,
                    /* [in] */ ECode code)
{
    printf("Func: %s\n", __FUNCTION__);
    printf("uid: %s\n", uid.string());
    printf("localPort: %s\n", localPort.string());
    printf("remotePort: %s\n", remotePort.string());
    return onPortForwardingResult
                ? onPortForwardingResult(mSwiftObj, uid.string(),
                                         localPort.string(),
                                         remotePort.string(),
                                         code)
                : NOERROR;
}

_ELASTOS ECode CCarrierListener::OnMessageReceived(
                    /* [in] */ const String& uid,
                    /* [in] */ const ArrayOf<Byte>& message)
{
    printf("Func: %s\n", __FUNCTION__);
    printf("uid: %s\n", uid.string());
    printf("message lenth: %d\n", message.GetLength());
    return onMessageReceived
                ? onMessageReceived(mSwiftObj, uid.string(),
                                    message.GetPayload(),
                                    message.GetLength())
                : NOERROR;
}
