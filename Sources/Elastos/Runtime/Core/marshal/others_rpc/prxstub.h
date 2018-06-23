
#ifndef __PRXSTUB_H__
#define __PRXSTUB_H__

# include <uv.h>

#include <semaphore.h>

#include "eltypes.h"
#include "car.h"
#include "marshal.h"
#include "CRemoteParcel.h"

_ELASTOS_NAMESPACE_USING

#define GET_LENGTH(a) ((a) & 0x3f)
#define GET_IN_INTERFACE_MARK(a) ((a) & 0x80)

enum {
    METHOD_GET_CLASS_INFO,
    METHOD_INVOKE,
    METHOD_RELEASE,
    METHOD_GET_CLASS_INFO_REPLY,
    METHOD_INVOKE_REPLY,
    METHOD_RELEASE_REPLY
};

class CObjectProxy;

class CInterfaceProxy
{
public:
    static CARAPI_(PInterface) S_Probe(
            /* [in] */ CInterfaceProxy *pThis,
            /* [in] */ REIID riid);

    static CARAPI_(UInt32) S_AddRef(
            /* [in] */ CInterfaceProxy *pThis);

    static CARAPI_(UInt32) S_Release(
            /* [in] */ CInterfaceProxy *pThis);

    static CARAPI S_GetInterfaceID(
            /* [in] */ CInterfaceProxy *pThis,
            /* [in] */ IInterface *pObject,
            /* [out] */ InterfaceID *pIID);

    CARAPI BufferSize(
            /* [in] */ UInt32 uMethodIndex,
            /* [in] */ va_list vaArgs,
            /* [out] */ UInt32 *puInSize,
            /* [out] */ UInt32 *puOutSize);

    CARAPI MarshalIn(
            /* [in] */ UInt32 uMethodIndex,
            /* [in] */ va_list vaArgs,
            /* [in, out] */ CRemoteParcel *pParcel);

    CARAPI UnmarshalOut(
            /* [in] */ UInt32 uMethodIndex,
            /* [out] */ CRemoteParcel *pParcel,
            /* [in] */ va_list vaArgs);

    inline CARAPI_(UInt32) CountMethodArgs(
            /* [in] */ UInt32 uMethodIndex);

    CARAPI_(Boolean) MethodHasOutArgs(
            /* [in] */ UInt32 uMethodIndex);

    static CARAPI ProxyEntry(
            /* [in] */ CInterfaceProxy *pThis,
            /* [in] */ UInt32 uMethodIndex,
            /* [in] */ va_list vaArgs);

public:
    PVoid                   m_pvVptr;       // must be first member

    UInt32                  m_uIndex;       // interface index in object
    CObjectProxy            *m_pOwner;
    const CIInterfaceInfo   *m_pInfo;
};

class CObjectProxy : public IProxy
{
public:
    CObjectProxy();
    virtual ~CObjectProxy();

    CARAPI_(PInterface) Probe(
            /* [in] */ REIID riid);

    CARAPI_(UInt32) AddRef(void);

    CARAPI_(UInt32) Release(void);

    CARAPI GetInterfaceCount(
        /* [out] */ Int32* count);

    CARAPI GetAllInterfaceInfos(
        /* [out] */ ArrayOf<IInterfaceInfo*>* interfaceInfos);

    CARAPI GetInterfaceID(
            /* [in] */ IInterface *pObject,
            /* [out] */ InterfaceID *pIID);

    CARAPI GetInterface(
            /* [in] */ UInt32 uIndex,
            /* [out] */ IInterface **ppObj);

    CARAPI GetInterfaceIndex(
             /* [in] */ IInterface *pObj,
             /* [out] */UInt32* pIndex);

    CARAPI GetClassID(
            /* [out] */ EMuid *pClsid);

    CARAPI GetClassInfo(
            /* [out] */ CIClassInfo **ppInfo);

    CARAPI LinkToDeath(
            /* [in] */ IProxyDeathRecipient* recipient,
            /* [in] */ Int32 flags);

    CARAPI UnlinkToDeath(
            /* [in] */ IProxyDeathRecipient* recipient,
            /* [in] */ Int32 flags,
            /* [out] */ Boolean* result);

    CARAPI IsStubAlive(
        /* [out] */ Boolean* result);

    static CARAPI S_CreateObject(
            /* [in] */ REMuid rclsid,
            /* [in] */ const char* stubConnName,
            /* [out] */ IProxy **ppIProxy);

public:
    String              m_stubIP;
    int                 m_stubPort;

    uv_tcp_t           *m_tcp;

    String              m_stubConnName;
    CIClassInfo         *m_pInfo;
    Int32               m_cInterfaces;
    CInterfaceProxy     *m_pInterfaces; // sizeis(m_cInterfaces)
    ICallbackConnector  *m_pICallbackConnector;

    Int32               m_cRef;

private:
    IInterface *RemoteProbe(REIID iid);
};

typedef struct InterfaceStruct {
    struct {
        UInt32 m_vTable[1];
    } *m_vPtr;
}   InterfaceStruct;

class CInterfaceStub
{
public:
    CARAPI UnmarshalIn(
            /* [in] */ const CIMethodInfo *pMethodInfo,
            /* [in] */ CRemoteParcel *pParcel,
            /* [in, out] */ MarshalHeader *pOutHeader,
            /* [in, out] */ UInt32 *puArgs);

    CARAPI MarshalOut(
            /* [in] */ UInt32 *puArgs,
            /* [in] */ MarshalHeader *pInHeader,
            /* [out] */ MarshalHeader *pOutHeader,
            /* [in] */ Boolean bOnlyReleaseIn,
            /* [in, out] */ CRemoteParcel *pParcel);

public:
    union
    {
        IInterface          *m_pObject;
        InterfaceStruct     *m_pInterface;
    };

    const CIInterfaceInfo   *m_pInfo;
};

interface IStub : public IInterface
{
    virtual CARAPI Invoke(
            /* [in] */ void *pInData,
            /* [in] */ UInt32 uInSize,
            /* [out] */ CRemoteParcel **ppParcel) = 0;

    virtual CARAPI GetClassID(
            /* [out] */ EMuid *pClsid) = 0;

    virtual CARAPI GetInterfaceIndex(
            /* [in] */ IInterface *pObj,
            /* [out] */ UInt32 *puIndex) = 0;

    virtual CARAPI GetClassInfo(
            /* [out] */ CIClassInfo **ppClassInfo) = 0;
};

class CObjectStub : public IStub
{
public:
    CObjectStub();
    virtual ~CObjectStub();

    CARAPI_(PInterface) Probe(
            /* [in] */ REIID riid);

    CARAPI_(UInt32) AddRef(void);

    CARAPI_(UInt32) Release(void);

    CARAPI GetInterfaceID(
            /* [in] */ IInterface *pObject,
            /* [out] */ InterfaceID *pIID);

    CARAPI Invoke(
            /* [in] */ void *pInData,
            /* [in] */ UInt32 uInSize,
            /* [out] */ CRemoteParcel **ppParcel);

    CARAPI GetClassID(
            /* [out] */ EMuid *pClsid);

    CARAPI GetInterfaceIndex(
            /* [in] */ IInterface *pObj,
            /* [out] */ UInt32 *puIndex);

    CARAPI GetClassInfo(
            /* [out] */ CIClassInfo **ppClassInfo);

    static CARAPI S_CreateObject(
            /* [in] */ IInterface *pObject,
            /* [out] */ IStub **ppIStub);

private:
    static void S_ServiceRoutine(
            /* [in] */ void *arg);


    ECode HandleGetClassInfo(uv_tcp_t *tcp, void const *base, int len);

    ECode HandleInvoke(uv_tcp_t *tcp, void const *base, int len);

    ECode HandleRelease(uv_tcp_t *tcp, void const *base, int len);

    static void S_TCPReadAllocCB(uv_handle_t *handle,
            size_t suggestedSize,
            uv_buf_t *buf);

    static void S_TCPReadCB(uv_stream_t *stream,
            ssize_t count,
            uv_buf_t const *buf);

    static void S_ListenCB(uv_stream_t *server, int status);


    CARAPI StartIPCService();

    int                 m_port;

    uv_loop_t          *m_loop;


public:
    String              m_connName;
    CIClassInfo         *m_pInfo;
    Int32               m_cInterfaces;
    CInterfaceStub      *m_pInterfaces; // size_is(m_cInterfaces)
    uv_thread_t         m_serviceThread;
    sem_t               m_sem;
    Boolean             m_bRequestToQuit;

    Int32               m_cRef;
};

#define PROXY_ENTRY_NUM     0x80

#endif //__PRXSTUB_H__
