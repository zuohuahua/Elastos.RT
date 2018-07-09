
#ifndef __CPARCEL_SESSION_H__
#define __CPARCEL_SESSION_H__

#include "elastos.h"

class CObjectProxy;

enum class RpcMethod {
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

    static Elastos::ECode S_CreateObject(
                /* [in] */ const char *stubConnName,
                /* [out] */ CParcelSession **ppParcelSession);

    virtual Elastos::ECode SendMessage(
                /* [in] */ RpcMethod type,
                /* [in] */ void* msg,
                /* [in] */ size_t len) = 0;

    virtual Elastos::ECode ReceiveMessage(
                /* [out] */ RpcMethod* pType,
                /* [out] */ void** pBuf,
                /* [out] */ int* pLen) = 0;
};


#endif //__CPARCEL_SESSION_H__
