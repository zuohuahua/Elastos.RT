
#include "SManC.h"
#include "log.h"
#include <sys/types.h>
#include <unistd.h>
#include <elapi.h>

#include "sock.h"

#define ELASTOS_SMANS_IP "192.168.0.103" // It's your SMan IP.
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

SManC::SManC()
    : m_sockfd(-1)
    , mServiceCache(11)
{}

Boolean SManC::Connect(
    /* [in] */ const String& ip,
    /* [in] */ Int32 port)
{
    int sockfd;
    do {
        static Int32 count = 1;
        sockfd = sock_connect(ip.string(), port);
        if (sockfd == -1) {
            count ++;
            usleep(1000);
        }
        if (count >= 20) {
            return FALSE;
        }
    } while (sockfd == -1);

    m_sockfd = sockfd;
    return TRUE;
}

SManC::~SManC()
{
    mServiceCache.Clear();
}

ECode SManC::AddService(
    /* [in] */ const String& name,
    /* [in] */ IInterface * pService)
{
    return AddServiceEx(name, pService, FALSE);
}

ECode SManC::AddServiceEx(
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
    if (FAILED(ec)) {
        return ec;
    }

    int _len;

    _len = strlen((char const *)name);
    _len++;
    _len += sizeof(int32_t);
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
    // p = (char *)mempcpy(p, &i32, 4);
    // p = (char *)mempcpy(p, buf, size);
    p = (char *)memcpy(p, &i32, sizeof(int32_t)) + sizeof(int32_t);
    p = (char *)memcpy(p, buf, size) + size;
    c = allowIsolated ? 1 : 0;
    *p = c;

    if (sock_send_msg(m_sockfd, ADD_SERVICE, _buf, _len)) {
        return E_FAIL;
    }

    void *_rbuf;
    int _rlen;
    int type;
    if (sock_recv_msg(m_sockfd, &type, &_rbuf, &_rlen)) {
        return E_FAIL;
    }

    if (type != ADD_SERVICE_REPLY) {
        return E_FAIL;
    }

    if (_rlen < 4) {
        return E_FAIL;
    }

    i32 = *(Int32 *)_rbuf;

    return (ECode)i32;
}

ECode SManC::GetService(
    /* [in] */ const String& name,
    /* [out] */ IInterface ** ppService)
{
    //VALIDATE_NOT_NULL(ppService);
    if (ppService == NULL) {
        return NOERROR;
    }
    *ppService = NULL;

    if (name.IsNullOrEmpty()) {
        return NOERROR;
    }

    HashMap<String, AutoPtr<IInterface> >::Iterator it =
            mServiceCache.Find(name);
    if (it != mServiceCache.End()) {
        *ppService = it->mSecond;
        if (*ppService != 0) {
            (*ppService)->AddRef();
        }
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

    if (sock_send_msg(m_sockfd, GET_SERVICE, _buf, _len)) {
        return E_FAIL;
    }

    void *_rbuf = NULL;
    int _rlen = 0;
    int type = 0;
    if (sock_recv_msg(m_sockfd, &type, &_rbuf, &_rlen)) {
        return E_FAIL;
    }

    if (type != GET_SERVICE_REPLY) {
        return E_FAIL;
    }

    char *p;
    p = (char *)_rbuf;

    Int32 i32;

    i32 = *(Int32 *)p;
    p += 4;

    ec = i32;
    if (FAILED(ec)) {
        return ec;
    }

    i32 = *(Int32 *)p;
    p += 4;

    size = i32;

    buf = p;
    ec = _CObject_UnmarshalInterface(buf, MarshalType_RPC,
        UnmarshalFlag_Noncoexisting, ppService, &size);
    free(_rbuf);
    if (SUCCEEDED(ec)) {
        // TODO: release old key.
        if (*ppService) (*ppService)->AddRef();
        mServiceCache[name] = *ppService;
    }
    return ec;
}
