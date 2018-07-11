
#include <assert.h>
#include <stdlib.h>

#include "CSockParcelCarrier.h"
#include "prxstub.h"
#include "rot.h"

ECode CParcelCarrier::S_StartService(CObjectStub *pStub, CParcelCarrier **ppParcelCarrier)
{
    CSockParcelCarrier* pSockParcelCarrier = new CSockParcelCarrier(pStub);
    pSockParcelCarrier->mStub = pStub;
    pStub->AddRef();

    if (uv_thread_create(&pSockParcelCarrier->m_serviceThread, &CSockParcelCarrier::S_ServiceRoutine, pSockParcelCarrier)) {
        pStub->Release();
        delete pSockParcelCarrier;
        return E_THREAD_ABORTED;
    }
    sem_wait(&pSockParcelCarrier->m_sem);
    *ppParcelCarrier = pSockParcelCarrier;
    return NOERROR;
}

ECode CParcelCarrier::S_IsOnline(Elastos::Boolean* pIsOnline)
{
    if (!pIsOnline) {
        return E_INVALID_ARGUMENT;
    }

    *pIsOnline = true;
    return NOERROR;
}

CSockParcelCarrier::CSockParcelCarrier(
    /* in */ CObjectStub * pStub)
    : CParcelCarrier(pStub)
{
    if (sem_init(&m_sem, 0, 0) < 0) {
        perror("sem_init()");
    }
}

CSockParcelCarrier::~CSockParcelCarrier()
{
    sem_destroy(&m_sem);
}

void CSockParcelCarrier::S_TCPReadAllocCB(uv_handle_t *handle,
        size_t suggestedSize,
        uv_buf_t *buf)
{
    buf->base = (char *)malloc(suggestedSize);
    if (buf->base == NULL)
        abort();
    buf->len = suggestedSize;
}

struct _BD {
    uv_buf_t buf;
    void *data;
};

void CSockParcelCarrier::S_TCPReadCB(uv_stream_t *stream,
        ssize_t count,
        uv_buf_t const *buf)
{
    ECode ec = NOERROR;
    uv_tcp_t *tcp;
    struct _BD *bd;
    CSockParcelCarrier *pThis;
    uint32_t len;
    size_t _len_;
    size_t _len;
    char *_base, *p;

    tcp = (uv_tcp_t *)stream;
    bd = (struct _BD *)tcp->data;
    pThis = (CSockParcelCarrier *)bd->data;
    if (count < 0) {
        uv_close((uv_handle_t *)tcp, NULL);
        goto out;
    }
    if (count == 0)
        goto out;

    if (bd->buf.base == NULL)
        len = *(uint32_t *)buf->base;
    else
        len = *(uint32_t *)bd->buf.base;

    _len_ = bd->buf.len + count;
    _len = _len_ < len ? _len_ : len;

    _base = (char *)malloc(_len);
    if (_base == NULL)
        abort();

    p = _base;
    if (bd->buf.base != NULL) {
        memcpy(p, bd->buf.base, bd->buf.len);
        p += bd->buf.len;
        free(bd->buf.base);
    }
    memcpy(p, buf->base, _len - bd->buf.len);

    if (_len < len) {
        bd->buf.base = _base;
        bd->buf.len = _len;
    } else {
        int type;
        size_t __len;
        char *__base;

        p = (char *)_base;
        p += sizeof(int32_t);
        _len -= sizeof(int32_t);
        type = *(int32_t *)p;
        p += sizeof(int32_t);
        _len -= sizeof(int32_t);
        CParcelSession *pParcelSession = CParcelSession::S_CreateObject(tcp);
        switch (type) {
        case METHOD_GET_CLASS_INFO:
            ec = pThis->HandleGetClassInfo(pParcelSession, p, _len);
            break;
        case METHOD_INVOKE:
            ec = pThis->HandleInvoke(pParcelSession, p, _len);
            break;
        case METHOD_RELEASE:
            ec = pThis->HandleRelease(pParcelSession, p, _len);
            break;
        default:
            ec = NOERROR;
            break;
        }
        delete pParcelSession;
        if (FAILED(ec))
            abort();

        __len = _len_ - len;
        if (__len == 0) {
            bd->buf.base = NULL;
            bd->buf.len = 0;
            goto out;
        }
        __base = (char *)malloc(__len);
        if (__base == NULL)
            abort();

        memcpy(__base, buf->base + len - bd->buf.len, __len);

        bd->buf.base = __base;
        bd->buf.len = __len;
    }

out:
    free(buf->base);
    if (count < 0)
        free(bd->buf.base);
}

void CSockParcelCarrier::S_ListenCB(uv_stream_t *server, int status)
{
    uv_tcp_t *tcp;
    CSockParcelCarrier *pThis;
    uv_tcp_t *_tcp;
    struct _BD *bd;

    tcp = (uv_tcp_t *)server;
    pThis = (CSockParcelCarrier *)tcp->data;
    if (status != 0)
        return;
    _tcp = (uv_tcp_t *)malloc(sizeof(uv_tcp_t));
    if (_tcp == NULL)
        abort();
    if (uv_tcp_init(tcp->loop, _tcp))
        goto out1;

    bd = (struct _BD *)malloc(sizeof(struct _BD));
    if (bd == NULL)
        goto out2;
    bd->buf.base = NULL;
    bd->buf.len = 0;
    _tcp->data = bd;

    if (uv_accept(server, (uv_stream_t *)_tcp))
        goto out3;
    pThis->mStub->AddRef();
    bd->data = pThis;
    if (uv_read_start((uv_stream_t *)_tcp, &S_TCPReadAllocCB, &S_TCPReadCB)) {
        pThis->mStub->Release();
out3:
        free(bd);
out2:
        uv_close((uv_handle_t *)_tcp, NULL);
        uv_run(tcp->loop, UV_RUN_NOWAIT);
out1:
        free(_tcp);
    }
}


void CSockParcelCarrier::S_ServiceRoutine(void *arg)
{
    CSockParcelCarrier *pThis = (CSockParcelCarrier *)arg;
    uv_loop_t *loop;
    int err;
    uv_tcp_t tcp;
    struct sockaddr_in addr;
    char ip[16];
    int port;
    struct sockaddr addr2;
    int addr2len = sizeof(struct sockaddr_in);
    char connName[32];
    ECode ec;

    loop = (uv_loop_t *)malloc(sizeof(uv_loop_t));
    if (loop == NULL)
        abort();
    if (uv_loop_init(loop))
        goto out1;
    if ((err = uv_tcp_init(loop, &tcp)))
        goto out2;
    if ((err = uv_tcp_nodelay(&tcp, 1)))
        goto out3;
    if ((err = uv_tcp_keepalive(&tcp, 1, 1)))
        goto out3;
    if ((err = uv_tcp_simultaneous_accepts(&tcp, 1)))
        goto out3;
    if ((err = uv_ip4_addr("0.0.0.0", 0, &addr)))
        goto out3;
    if ((err = uv_tcp_bind(&tcp, (struct sockaddr *)&addr, 0)))
        goto out3;
    pThis->mStub->AddRef();
    tcp.data = pThis;
    if ((err = uv_listen((uv_stream_t *)&tcp, 128, &S_ListenCB))) {
        pThis->mStub->Release();
        goto out3;
    }
    if (sock_get_inet_addr(ip, sizeof(ip)))
        goto out3;
    pThis->m_loop = loop;
    memset(&addr2, -1, sizeof addr2);
    addr2len = sizeof addr2;
    if (uv_tcp_getsockname(&tcp, &addr2, &addr2len))
	goto out3;
    port = ntohs(((struct sockaddr_in *)&addr2)->sin_port);
    pThis->m_port = port;
    sprintf(connName, "%s:%d", ip, port);
    pThis->mStub->m_connName = connName;
    sem_post(&pThis->m_sem);
    uv_run(loop, UV_RUN_DEFAULT);
    pThis->m_loop = NULL;
    ec = UnregisterExportObject(pThis->mStub->m_connName);
    if (FAILED(ec))
        MARSHAL_DBGOUT(MSHDBG_ERROR, printf(
                    "Release stub: "
                    "unregister export object failed, ec(%x)\n", ec));
out3:
    uv_close((uv_handle_t *)&tcp, NULL);
    uv_run(loop, UV_RUN_NOWAIT);
out2:
    err = uv_loop_close(loop);
out1:
    free(loop);
    pThis->mStub->Release();
    if (err)
        abort();
}

ECode CSockParcelCarrier::HandleReleaseToZero()
{
    if (m_loop != NULL) {
        uv_stop(m_loop);
    }
    return NOERROR;
}
