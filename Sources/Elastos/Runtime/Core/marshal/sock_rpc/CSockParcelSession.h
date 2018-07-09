#ifndef __CSOCK_PARCEL_SESSION_H__
#define __CSOCK_PARCEL_SESSION_H__

#include "CParcelSession.h"

#include <uv.h>
#include "sock.h"

class CSockParcelSession : public CParcelSession
{
public:
    CSockParcelSession();
    ~CSockParcelSession();

    Elastos::ECode SendMessage(
                /* [in] */ RpcMethod type,
                /* [in] */ void* msg,
                /* [in] */ size_t len);

    Elastos::ECode ReceiveMessage(
                /* [out] */ RpcMethod* pType,
                /* [out] */ void** pBuf,
                /* [out] */ int* pLen);

    friend class CParcelSession;
public:
    String              m_stubIP;
    int                 m_stubPort;

    uv_tcp_t           *m_tcp;
};

#endif // __CSOCK_PARCEL_SESSION_H__
