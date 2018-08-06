
#include <assert.h>
#include <stdlib.h>

#include "CSockParcelSession.h"
#include "prxstub.h"
#include "rot.h"

CParcelSession* CParcelSession::S_CreateObject(
                /* [in] */ void* pNativeSession)
{
    CSockParcelSession* pParcelSession = new CSockParcelSession();

    pParcelSession->m_serviceStarted = false;
    pParcelSession->m_tcp = (uv_tcp_t*)pNativeSession;

    return pParcelSession;
}

ECode CSockParcelSession::StartService(
                /* [in] */ const char * stubConnName)
{
    char ip[32];
    int port;
    ECode ec;

    sscanf(stubConnName, "%[^:]:%d", ip, &port);

    m_serviceStarted = true;
    m_stubIP = ip;
    m_stubPort = port;

    if (sock_connect(&m_tcp, ip, port)) {
        ec = E_FAIL;
        goto ErrorExit;
    }
    return NOERROR;

ErrorExit:
    if (m_tcp != nullptr) {
        sock_close(m_tcp);
    }
}

ECode CSockParcelSession::StopService()
{
    if (m_serviceStarted) {
        sock_close(m_tcp);
        m_serviceStarted = false;
    }
}

CSockParcelSession::CSockParcelSession() :
    m_stubPort(0),
    m_serviceStarted(false),
    m_tcp(nullptr)
{
}

CSockParcelSession::~CSockParcelSession()
{
    if (m_serviceStarted) {
        StopService();
    }
}

ECode CSockParcelSession::SendMessage(
                /* [in] */ RpcMethod type,
                /* [in] */ void* msg,
                /* [in] */ int len)
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

ECode CSockParcelSession::ReceiveFromRemote(
                /* [out] */ RpcMethod* pType,
                /* [out] */ void** pBuf,
                /* [out] */ int* pLen)
{
    return this->ReceiveMessage(pType, pBuf, pLen);
}
