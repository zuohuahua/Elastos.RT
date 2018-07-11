
#ifndef __CPARCEL_SESSION_H__
#define __CPARCEL_SESSION_H__

#include "elastos.h"

enum class RpcMethod : int {
    get_class_info,
    invoke,
    release,
    get_class_info_reply,
    invoke_reply,
    release_reply
};

class CParcelSession
{
public:
    CParcelSession() {}

    virtual ~CParcelSession() {}

    static CParcelSession* S_CreateObject(
                /* [in] */ void* pNativeSession);

    virtual Elastos::ECode StartService(
                /* [in] */ const char *stubConnName) = 0;

    virtual Elastos::ECode StopService() = 0;

    virtual Elastos::ECode SendMessage(
                /* [in] */ RpcMethod type,
                /* [in] */ void* msg,
                /* [in] */ size_t len) = 0;

    virtual Elastos::ECode ReceiveMessage(
                /* [out] */ RpcMethod* pType,
                /* [out] */ void** pBuf,
                /* [out] */ int* pLen) = 0;

    virtual Elastos::ECode ReceiveFromRemote(
                /* [out] */ RpcMethod* pType,
                /* [out] */ void** pBuf,
                /* [out] */ int* pLen) = 0;
};

#endif //__CPARCEL_SESSION_H__
