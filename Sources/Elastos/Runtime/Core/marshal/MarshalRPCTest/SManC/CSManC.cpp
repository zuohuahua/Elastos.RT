
#include "CSManC.h"

#include <sys/types.h>
#include <unistd.h>
#include <elapi.h>

#include "SManC.h"

#include "../sock/sock.h"

CAR_OBJECT_IMPL(CSManC)

CAR_INTERFACE_IMPL(CSManC, Object, ISManC);


#define ELASTOS_SMANS_IP "127.0.0.1" // It's your SMan IP.
#define ELASTOS_SMANS_PORT 2345



enum {
    ADD_SERVICE = 0,
    GET_SERVICE,
    REMOVE_SERVICE,
    ADD_SERVICE_REPLY,
    GET_SERVICE_REPLY,
    REMOVE_SERVICE_REPLY
};

typedef struct InterfacePack {
    EMuid               m_clsid;             // clsid of object
    UInt32              m_uIndex;            // interface index in class

    Char8               m_stubConnName[256];// dbus unique connection name of stub
} InterfacePack;

CSManC::CSManC() :
    mServiceCache(11)
{
    char const *ip;
    int port;
    int sockfd;

    ip = ELASTOS_SMANS_IP;
    port = ELASTOS_SMANS_PORT;
    do {
        sockfd = sock_connect(ip, port);
        if (sockfd == -1)
            usleep(1000);
    } while (sockfd == -1);

    m_sockfd = sockfd;
}

CSManC::~CSManC()
{
    mServiceCache.Clear();
}

ECode CSManC::constructor(void)
{
    return NOERROR;
}

ECode CSManC::AddService(
    /* [in] */ const String& name,
    /* [in] */ IInterface * pService)
{
    return AddServiceEx(name, pService, FALSE);
}

ECode CSManC::AddServiceEx(
    /* [in] */ const String& name,
    /* [in] */ IInterface * pService,
    /* [in] */ Boolean allowIsolated)
{
    if (name.IsNullOrEmpty() || !pService) {
        return NOERROR;
    }

    ECode ec = NOERROR;

    void * buf = NULL;
    Int32 size;

    // TODO: release buf.
    ec = _CObject_MarshalInterface(pService, MarshalType_RPC, &buf, &size);
    if (FAILED(ec)) return ec;

    int _len;

    _len = strlen((char const *)name);
    _len++;
    _len += 4;
    _len += size;
    _len++;

    char _buf[_len];
    char *p;
    Int32 i32;
    char c;

    p = _buf;
    p = stpcpy(p, name);
    ++p;
    i32 = size;
    p = (char *)mempcpy(p, &i32, 4);
    p = (char *)mempcpy(p, buf, size);
    c = allowIsolated ? 1 : 0;
    *p = c;

    if (sock_send_msg(m_sockfd, ADD_SERVICE, _buf, _len))
        return E_FAIL;

    void *_rbuf;
    int _rlen;
    int type;
    if (sock_recv_msg(m_sockfd, &type, &_rbuf, &_rlen))
        return E_FAIL;

    if (type != ADD_SERVICE_REPLY)
        return E_FAIL;

    if (_rlen < 4)
        return E_FAIL;

    i32 = *(Int32 *)_rbuf;

    return (ECode)i32;
}

ECode CSManC::GetService(
    /* [in] */ const String& name,
    /* [out] */ IInterface ** ppService)
{
    //VALIDATE_NOT_NULL(ppService);
    if (ppService == NULL)
        return NOERROR;

    if (name.IsNullOrEmpty()) {
        return NOERROR;
    }

    HashMap<String, AutoPtr<IInterface> >::Iterator it =
            mServiceCache.Find(name);
    if (it != mServiceCache.End()) {
        *ppService = it->mSecond;
        if (*ppService != 0)
            (*ppService)->AddRef();
        return NOERROR;
    }

    ECode ec = NOERROR;

    void *buf = NULL;
    Int32 size;

    char const *_buf;
    int _len;

    _buf = (char const *)name;
    _len = strlen(_buf);
    _len++;

    if (sock_send_msg(m_sockfd, GET_SERVICE, _buf, _len))
        return E_FAIL;

    void *_rbuf;
    int _rlen;
    int type;
    if (sock_recv_msg(m_sockfd, &type, &_rbuf, &_rlen))
        return E_FAIL;

    if (type != GET_SERVICE_REPLY)
        return E_FAIL;

    char *p;

    p = (char *)_rbuf;

    Int32 i32;

    i32 = *(Int32 *)p;
    p += 4;

    ec = i32;
    if (FAILED(ec))
        return ec;

    i32 = *(Int32 *)p;
    p += 4;

    size = i32;

    buf = p;

    ec = _CObject_UnmarshalInterface(buf, MarshalType_RPC,
        UnmarshalFlag_Noncoexisting, ppService, &size);
    free(_rbuf);
    if (SUCCEEDED(ec)) {
        // TODO: release old key.
        mServiceCache[name] = *ppService;
    }
    return ec;
}

/**
 * This is only intended to be called when the process is first being brought
 * up and bound by the activity manager. There is only one thread in the process
 * at that time, so no locking is done.
 *
 * @param cache the cache of service references
 * @hide
 */
#if 0
ECode SManC::InitServiceCache(
    /* [in] */ IObjectStringMap* services)
{
    if (mServiceCache.GetSize() != 0 /*&& Process.supportsProcesses()*/) {
//        throw new IllegalStateException("setServiceCache may only be called once");
        return E_ILLEGAL_STATE_EXCEPTION;
    }
//    sCache.putAll(cache);
    assert(0);
    return NOERROR;
}
#endif

