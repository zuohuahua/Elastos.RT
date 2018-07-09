
#include <assert.h>
#include <stdlib.h>

#include "CSockParcelSession.h"
#include "prxstub.h"
#include "rot.h"

ECode CParcelSession::S_CreateObject(
                /* [in] */ const char * stubConnName,
                /* [out] */ CParcelSession **ppParcelSession)
{
    char ip[32];
    int port;
    ECode ec;

    CSockParcelSession* pParcelSession = new CSockParcelSession();

    sscanf(stubConnName, "%[^:]:%d", ip, &port);

    pParcelSession->m_stubIP = ip;
    pParcelSession->m_stubPort = port;

    if (sock_connect(&pParcelSession->m_tcp, ip, port)) {
        ec = E_FAIL;
        goto ErrorExit;
    }
    *ppParcelSession = pParcelSession;
    return NOERROR;

ErrorExit:
    if (pParcelSession->m_tcp != 0) {
        sock_close(pParcelSession->m_tcp);
    }
}


CSockParcelSession::CSockParcelSession() :
    m_stubPort(0),
    m_tcp(nullptr)
{
}

CSockParcelSession::~CSockParcelSession()
{
    sock_close(m_tcp);
}

ECode CSockParcelSession::SendMessage(
                /* [in] */ RpcMethod type,
                /* [in] */ void* msg,
                /* [in] */ size_t len)
{
    ECode ec = NOERROR;
    if (sock_send_msg(m_tcp, (int)type, msg, len)) {
        ec = E_FAIL; // TODO: sould set an appropriate error code
    }
    return ec;
}

ECode CSockParcelSession::ReceiveMessage(
                /* [out] */ RpcMethod* pType,
                /* [out] */ void** pBuf,
                /* [out] */ int* pLen)
{
    ECode ec = NOERROR;
    if (sock_recv_msg(m_tcp, (int*)pType, pBuf, pLen)) {
        ec = E_FAIL; // TODO: sould set an appropriate error code
    }
    return ec;
}
