#ifndef __CSOCK_PARCEL_CARRIER_H__
#define __CSOCK_PARCEL_CARRIER_H__

#include "CParcelCarrier.h"

#include <uv.h>
#include "sock.h"

class CObjectStub;

class CSockParcelCarrier : public CParcelCarrier
{
public:
    CSockParcelCarrier(CObjectStub * pStub);
    ~CSockParcelCarrier();

    Elastos::ECode HandleReleaseToZero();
private:
    static void S_ServiceRoutine(
            /* [in] */ void *arg);

    static void S_TCPReadAllocCB(uv_handle_t *handle,
            size_t suggestedSize,
            uv_buf_t *buf);

    static void S_TCPReadCB(uv_stream_t *stream,
            ssize_t count,
            uv_buf_t const *buf);

    static void S_ListenCB(uv_stream_t *server, int status);

    friend class CParcelCarrier;

    int                 m_port;
    uv_loop_t          *m_loop;
    uv_thread_t         m_serviceThread;
    sem_t               m_sem;
};

#endif // __CSOCK_PARCEL_CARRIER_H__
