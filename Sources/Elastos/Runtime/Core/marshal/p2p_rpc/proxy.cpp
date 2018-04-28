
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <elaatomics.h>
#include <sys/mman.h>
#include "prxstub.h"
#include "rot.h"

EXTERN_C const InterfaceID EIID_IProxy;

ECode LookupClassInfo(
    /* [in] */ REMuid rclsid,
    /* [out] */ CIClassInfo **ppClassInfo);

ECode GetRemoteClassInfo(
    /* [in] */ CSession* pSession,
    /* [in] */ REMuid clsId,
    /* [out] */ CIClassInfo ** ppClassInfo);

void *GetUnalignedPtr(void *pPtr);

Address s_proxyEntryAddress = 0;

#define SYS_PROXY_RET_OFFSET    9

#ifndef PAGE_SIZE
#define PAGE_SIZE (1u << 12)
#endif
#ifndef PAGE_MASK
#define PAGE_MASK (~(PAGE_SIZE - 1))
#endif
#ifndef PAGE_ALIGN
#define PAGE_ALIGN(va) (((va)+PAGE_SIZE-1)&PAGE_MASK)
#endif

UInt32 g_marshalVtbl[MSH_MAX_METHODS];

EXTERN_C void ProxyEntryFunc(void);

#ifdef _GNUC
#    if defined(_arm)
#       define DECL_SYS_PROXY_ENTRY()              \
            __asm__(                               \
            ".text;"                               \
            ".align 4;"                            \
            ".arm;"                                \
            ".globl ProxyEntryFunc;"               \
            "ProxyEntryFunc:"                      \
            "push {r0 - r3};"                      \
            "push {lr};"                           \
            "mov  r1, #0xff;"                      \
            "ldr  pc, [r0, #4];"                   \
        )
        DECL_SYS_PROXY_ENTRY();
#    elif defined(_x86)

#  if 0
#       define DECL_SYS_PROXY_ENTRY()             \
            __asm__(                               \
                ".text;"                           \
                ".align 4;"                        \
                ".globl ProxyEntryFunc;"          \
                "ProxyEntryFunc:"                 \
                ".intel_syntax;"                   \
                "ret    0x4;"                      \
                ".att_syntax;"                     \
            )
        DECL_SYS_PROXY_ENTRY();
#  else


/*
 * ^  o == offset
 * |  o == args
 * |  o == this
 * |  o == &ret
 * |  o == &up_o
 * |  o == eip
 */

#   define DECL_SYS_PROXY_ENTRY()                  \
	__asm__(                                   \
		".text;"                           \
		".align 4;"                        \
		".globl ProxyEntryFunc;"           \
		"ProxyEntryFunc:"                  \
		".intel_syntax noprefix;"          \
		"push esp;"                        \
		"mov eax, dword ptr [esp + 8];"    \
		"call dword ptr [eax + 4];"        \
		"add esp, 0x4;"                    \
		"ret;"                             \
		".att_syntax;"                     \
	       )
            DECL_SYS_PROXY_ENTRY();
#  endif

#    else
#        error "Unknown archibute"
#   endif
#else
#   if defined(_x86)
#       define DECL_SYS_PROXY_ENTRY() \
            __declspec( naked ) void ProxyEntryFunc()                   \
            {                                       \
                __asm push esp                      \
                __asm mov eax, dword ptr [esp + 8]  \
                __asm call dword ptr [eax +4]       \
                __asm ret  0x4                      \
            }
        DECL_SYS_PROXY_ENTRY();
#   endif
#endif

#ifdef _arm

EXTERN_C void __ProxyEntry(void);

EXTERN_C ECode GlobalProxyEntry(UInt32 *puArgs)
{
    return CInterfaceProxy::ProxyEntry(puArgs);
}

#ifdef _GNUC
#define DECL_PROXY_ENTRY()              \
    __asm__(                            \
        ".text;"                        \
        ".align 4;"                     \
        ".arm;"                         \
        ".globl __ProxyEntry;"          \
        "__ProxyEntry:"                 \
        "push   {r1};"                  \
        "add    r0, sp, #4;"            \
        "bl     GlobalProxyEntry;"      \
        "add    sp, sp, #4;"            \
        "pop    {lr};"                  \
        "pop    {r1};"                  \
        "pop    {r1 - r3};"             \
        "push   {lr};"                  \
        "pop    {pc};"                  \
    )

DECL_PROXY_ENTRY();
#endif

#endif

#ifdef _mips

EXTERN_C ECode GlobalProxyEntry(UInt32 *puArgs)
{
    return CInterfaceProxy::ProxyEntry(puArgs);
}

#ifdef _GNUC
void __ProxyContinue()
{
DECL_ASMENTRY(ProxyContinue)
#elif defined(_EVC)
DECL_NAKED void ProxyContinue()
{
#else
#error unknown compiler
#endif
    ASM(
        "sw     $4, 0x0($29);"
        "sw     $5, 0x4($29);"
        "sw     $6, 0x8($29);"
        "sw     $7, 0xc($29);"
        "addiu  $29, $29, -0x1c;"
        "sw     $12, 0x10($29);"
        "add    $4, $29, 0x18;"
        "sw     $4, 0x14($29);"
        "la     $9, GlobalProxyEntry;"
        "jalr   $9;"
        "addiu  $29, $29, 0x1c;"
        "lw     $31, -4($29);"
        "jr     $31;");
}
#endif

void InitProxyEntry()
{
    s_proxyEntryAddress =
            (Address)mmap((void*)0,
                          PAGE_ALIGN(PROXY_ENTRY_NUM * PROXY_ENTRY_SIZE),
                          PROT_READ | PROT_WRITE | PROT_EXEC,
                          MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (s_proxyEntryAddress == 0) {
        printf("out of memory.\n");
        return;
    }

#if defined(_x86)
    char *p = (char *)s_proxyEntryAddress;
    for (UInt32 n = 0; n < PROXY_ENTRY_NUM; n++) {
        memcpy(p, (void*)&ProxyEntryFunc, PROXY_ENTRY_SIZE);
	//*(Int16*)&(p[SYS_PROXY_RET_OFFSET]) = ( (n + 1) << 2);
        p+= PROXY_ENTRY_SIZE;
    }
#elif defined(_arm)
    char * p = (char *)s_proxyEntryAddress;
    for (Int32 n = 0; n < PROXY_ENTRY_NUM; n++) {
        memcpy(p, (void *)&ProxyEntryFunc, PROXY_ENTRY_SIZE);
        p[8] = n;
        p += PROXY_ENTRY_SIZE;
    }
#else
#error "unsupported architecture yet."
#endif

    g_marshalVtbl[0] = (UInt32)&CInterfaceProxy::S_Probe;
    g_marshalVtbl[1] = (UInt32)&CInterfaceProxy::S_AddRef;
    g_marshalVtbl[2] = (UInt32)&CInterfaceProxy::S_Release;
    g_marshalVtbl[3] = (UInt32)&CInterfaceProxy::S_GetInterfaceID;
    for (int m = 4; m < MSH_MAX_METHODS; m++) {
        g_marshalVtbl[m] = PROXY_ENTRY_BASE + ((m - 4) << PROXY_ENTRY_SHIFT);
    }
}

void UninitProxyEntry()
{
     if (0 != s_proxyEntryAddress) {
        munmap((void*)s_proxyEntryAddress,
               PAGE_ALIGN(PROXY_ENTRY_NUM * PROXY_ENTRY_SIZE));
        s_proxyEntryAddress = (Address)NULL;
    }
}

PInterface CInterfaceProxy::S_Probe(
    /* [in] */ CInterfaceProxy *pThis,
    /* [in] */ REIID riid)
{
    return pThis->m_pOwner->Probe(riid);
}

UInt32 CInterfaceProxy::S_AddRef(
    /* [in] */ CInterfaceProxy *pThis)
{
    return pThis->m_pOwner->AddRef();
}

UInt32 CInterfaceProxy::S_Release(
    /* [in] */ CInterfaceProxy *pThis)
{
    return pThis->m_pOwner->Release();
}

ECode CInterfaceProxy::S_GetInterfaceID(
    /* [in] */ CInterfaceProxy *pThis,
    /* [in] */ IInterface *pObject,
    /* [out] */ InterfaceID *pIID)
{
    //todo: not correct.
    return pThis->m_pOwner->GetInterfaceID(pObject, pIID);
}

ECode CInterfaceProxy::BufferSize(
    /* [in] */ UInt32 uMethodIndex,
    /* [in] */ UInt32 *puArgs,
    /* [out] */ UInt32 *puInSize,
    /* [out] */ UInt32 *puOutSize)
{
    ECode ec;
    const CIMethodInfo *pMethodInfo;
    pMethodInfo = &(m_pInfo->mMethods[uMethodIndex]);

    ec = Proxy_ProcessMsh_BufferSize(
            pMethodInfo,
            puArgs,
            puInSize,
            puOutSize);
    if (0 != *puOutSize){
        *puOutSize += sizeof(MarshalHeader);
    }

    if (SUCCEEDED(ec)) {
        *puInSize += sizeof(MarshalHeader);
    }
    return ec;
}

ECode CInterfaceProxy::MarshalIn(
    /* [in] */ UInt32 uMethodIndex,
    /* [in] */ UInt32 *puArgs,
    /* [in, out] */ CRemoteParcel *pParcel)
{
    ECode ec;
    const CIMethodInfo *pMethodInfo;
    MarshalHeader *pHeader;

    pMethodInfo = &(m_pInfo->mMethods[uMethodIndex]);

    ec = Proxy_ProcessMsh_In(
            pMethodInfo,
            puArgs,
            (IParcel*)pParcel);

    if (SUCCEEDED(ec)) {
        pHeader = pParcel->GetMarshalHeader();
        assert(pHeader != NULL);
        pHeader->m_uMagic = MARSHAL_MAGIC;
        pHeader->m_hInterfaceIndex = m_uIndex;
        pHeader->m_hMethodIndex = uMethodIndex + 4;
    }

    return ec;
}

ECode CInterfaceProxy::UnmarshalOut(
    /* [in] */ UInt32 uMethodIndex,
    /* [out] */ CRemoteParcel *pParcel,
    /* [in] */ UInt32 *puArgs)
{
    MarshalHeader *pHeader = pParcel->GetMarshalHeader();

    if (pHeader->m_uMagic != MARSHAL_MAGIC) {
        MARSHAL_DBGOUT(MSHDBG_ERROR,
                printf("Proxy unmsh: invalid magic(%x)\n", pHeader->m_uMagic));
        return E_MARSHAL_DATA_TRANSPORT_ERROR;
    }

#if defined(_DEBUG)
    if (pHeader->m_hInterfaceIndex != (Int16)m_uIndex) {
        MARSHAL_DBGOUT(MSHDBG_ERROR,
                printf("Proxy unmsh: invalid iidx(%x)\n",
                pHeader->m_hInterfaceIndex));
        return E_MARSHAL_DATA_TRANSPORT_ERROR;
    }
    if (pHeader->m_hMethodIndex != (Int16)(uMethodIndex + 4)) {
        MARSHAL_DBGOUT(MSHDBG_ERROR, printf(
                "Proxy unmsh: invalid method(%x)\n", pHeader->m_hMethodIndex));
    }
#endif

    return Proxy_ProcessUnmsh_Out(
            &(m_pInfo->mMethods[uMethodIndex]),
            (IParcel*)pParcel,
            pHeader->m_uOutSize - sizeof(MarshalHeader),
            puArgs);
}

UInt32 CInterfaceProxy::CountMethodArgs(
    /* [in] */ UInt32 uMethodIndex)
{
    return GET_LENGTH((m_pInfo->mMethods[uMethodIndex]).mReserved1);
}

Boolean CInterfaceProxy::MethodHasOutArgs(
    /* [in] */ UInt32 uMethodIndex)
{
    int n, cParams;
    const CIMethodInfo *pMethodInfo;
    const CIBaseType *pParams;

    pMethodInfo = &(m_pInfo->mMethods[uMethodIndex]);
    cParams = pMethodInfo->mParamNum;
    pParams = pMethodInfo->mParams;

    for (n = 0; n < cParams; n++) {
        if (BT_IS_OUT(pParams[n])) return TRUE;
    }

    return FALSE;
}

ECode CInterfaceProxy::ProxyEntry(UInt32 *puArgs)
{
    CInterfaceProxy *pThis;
    UInt32 uMethodIndex, uInSize, uOutSize;
    Int32 size = 0;
    void *pInBuffer = NULL, *pOutBuffer = NULL;
    MarshalHeader *pInHeader = NULL;
    CRemoteParcel *pInParcel = NULL, *pOutParcel = NULL;
    ECode ec;
    UInt32 cArgs;

#ifdef _x86
    //  puArgs = esp,set by ProxyEntryFunc
    //        +---------+
    //        | param   |
    //        +---------+
    //        | pObj    |
    //        +---------+
    //        | retAddr |
    //puArs-->+---------+
    //        | esp     |
    //        +---------+
    //        | retAddr |<--pRet,the return address of ProxyEntryFunc
    //        +---------+
    //        | ...     |
    //        +---------+
    UInt32 pRet = *(puArgs - 2); // get return address
#endif

    puArgs++; // skip ret address

    pThis = (CInterfaceProxy *)*puArgs;
    puArgs++; // skip this

    MARSHAL_DBGOUT(MSHDBG_NORMAL,
            printf("*puArgs = %x, puArgs = %x", *puArgs, puArgs));
    MARSHAL_DBGOUT(MSHDBG_NORMAL, printf("iid: "));
    MARSHAL_DBGOUT(MSHDBG_NORMAL, DUMP_GUID(pThis->m_pInfo->mIID));

#ifdef _x86
    uMethodIndex = CalcMethodIndex(pRet);
#elif defined(_arm)
    uMethodIndex = puArgs[-3];
#else
#error unknown architecture
#endif

    // Get the stack length, not contain "this"
    cArgs = pThis->CountMethodArgs(uMethodIndex);
    MARSHAL_DBGOUT(MSHDBG_NORMAL, printf(
            "Method index(%d), args size(%d)\n", uMethodIndex + 4, cArgs * 4));

    // Calculate the package size
    //
    // NOTE:
    //  1. Alloc pOutHeader on the stack with MAX-out-size
    //  2. Assign pInHeader->m_uOutSize with MAX-out-size
    //  3. Pass the MIN-out-size to SysInvoke's last parameter
    //  4. Call Thread::ReallocBuffer in SysReply if necessary to pass back the
    //      marshaled-out data with error info
    //
    ec = pThis->BufferSize(uMethodIndex, puArgs, &uInSize, &uOutSize);
    if (FAILED(ec)) {
        MARSHAL_DBGOUT(MSHDBG_ERROR,
                printf("Proxy BufferSize() failed, ec = %x\n", ec));
        goto ProxyExit;
    }

    MARSHAL_DBGOUT(MSHDBG_NORMAL, printf(
            "Buffer size: isize(%d), osize(%d)\n", uInSize, uOutSize));
    assert(uInSize >= sizeof(MarshalHeader));

    pInParcel = new CRemoteParcel(pThis->m_pOwner->mSession);
    ec = pThis->MarshalIn(uMethodIndex, puArgs, pInParcel);
    if (SUCCEEDED(ec)) {
        pInParcel->GetElementSize(&size);
        pInParcel->GetElementPayload((Handle32*)&pInBuffer);
        pInHeader = pInParcel->GetMarshalHeader();
        pInHeader->m_uInSize = size;
        pInHeader->m_uOutSize = uOutSize;
        MARSHAL_DBGOUT(MSHDBG_NORMAL, printf(
                "Before RemoteInvoke: ParcelSize(%d)\n", size));

        int type, len;
        char *p = NULL;

        ec = pThis->m_pOwner->mSession->SendMessage(METHOD_INVOKE, pInBuffer, size);
        if (FAILED(ec)) {
            goto UseSocketExit;
        }

        ec = pThis->m_pOwner->ReceiveFromRemote(&type, (void **)&p, &len);
        if (FAILED(ec)) {
            goto UseSocketExit;
        }

        if (type != METHOD_INVOKE_REPLY) {
            ec = E_FAIL; // TODO: sould set an appropriate error code
            goto UseSocketExit;
        }

        ec = *(int32_t *)p;
        if (SUCCEEDED(ec)) {
            if (pThis->MethodHasOutArgs(uMethodIndex)) {
                pOutParcel = new CRemoteParcel(pThis->m_pOwner->mSession, (UInt32*)(p + sizeof(int32_t)));
                ec = pThis->UnmarshalOut(uMethodIndex, pOutParcel, puArgs);
            }
        }

UseSocketExit:
        if (p) free(p);
        goto ProxyExit;
    }
    else {
        MARSHAL_DBGOUT(MSHDBG_ERROR,
                printf("proxy MarshalIn() failed. ec = %x\n", ec));
    }

ProxyExit:
    MARSHAL_DBGOUT(MSHDBG_NORMAL, printf("Exit proxy: ec(%x)\n", ec));

	if (pInParcel != NULL) delete pInParcel;
	if (pOutParcel != NULL) delete pOutParcel;

    SYS_PROXY_EXIT(ec, &puArgs - 1, cArgs);
}

CObjectProxy::CObjectProxy(
    /* [in] */ CSession* pSession) :
    mSession(pSession),
    mListener(NULL),
    mData(NULL),
    m_pInterfaces(NULL),
    m_pICallbackConnector(NULL),
    m_cRef(1)
{
    if (!mSession) return;

    mSession->AddRef();
    mListener = new CProxyListener();
    if (!mListener) return;
    mListener->AddRef();
    mSession->AddListener(mListener, this);

    pthread_mutexattr_t recursiveAttr;
    pthread_mutexattr_init(&recursiveAttr);
    pthread_mutexattr_settype(&recursiveAttr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mWorkLock, &recursiveAttr);
    pthread_mutexattr_destroy(&recursiveAttr);

    pthread_cond_init(&mCv, NULL);
}

CObjectProxy::~CObjectProxy()
{
    if (m_pInterfaces) {
        for (Int32 n = 0; n < m_cInterfaces; n++) {
            if (m_pInterfaces[n].m_pvVptr) {
		    /* Who did this?! */
                //delete [] (UInt32 *)(m_pInterfaces[n].m_pvVptr);
            }
        }
        delete [] m_pInterfaces;
    }

    if (!mSession) return;

    if (mListener) {
        mSession->RemoveListener(mListener, this);
        mListener->Release();
    }
    mSession->Release();

    pthread_cond_destroy(&mCv);
    pthread_mutex_destroy(&mWorkLock);

    if (mData) {
        if (mData->data)
            ArrayOf<Byte>::Free(mData->data);
        delete mData;
        mData = NULL;
    }
}

static const EMuid ECLSID_XOR_CallbackSink = \
/* e724df56-e16a-4599-8edd-a97ab245d583 */
{0xe724df56,0xe16a,0x4599,{0x8e,0xdd,0xa9,0x7a,0xb2,0x45,0xd5,0x83}};

PInterface CObjectProxy::Probe(REIID riid)
{
    int n;

    if (riid == EIID_IInterface) {
        return (IInterface*)(IProxy*)this;
    }
    else if (riid == EIID_IProxy) {
        return (IProxy*)this;
    }

    if (riid == EIID_CALLBACK_CONNECTOR) {
        if (NULL == m_pICallbackConnector) {
            ClassID ezclsid;
            IInterface *pTemp = (IInterface *)&(m_pInterfaces[0].m_pvVptr);
            this->GetClassID(&ezclsid.mClsid);

            ezclsid.mClsid.mData1    ^= ECLSID_XOR_CallbackSink.mData1;
            ezclsid.mClsid.mData2    ^= ECLSID_XOR_CallbackSink.mData2;
            ezclsid.mClsid.mData3    ^= ECLSID_XOR_CallbackSink.mData3;
            ezclsid.mClsid.mData4[0] ^= ECLSID_XOR_CallbackSink.mData4[0];
            ezclsid.mClsid.mData4[1] ^= ECLSID_XOR_CallbackSink.mData4[1];
            ezclsid.mClsid.mData4[2] ^= ECLSID_XOR_CallbackSink.mData4[2];
            ezclsid.mClsid.mData4[3] ^= ECLSID_XOR_CallbackSink.mData4[3];
            ezclsid.mClsid.mData4[4] ^= ECLSID_XOR_CallbackSink.mData4[4];
            ezclsid.mClsid.mData4[5] ^= ECLSID_XOR_CallbackSink.mData4[5];
            ezclsid.mClsid.mData4[6] ^= ECLSID_XOR_CallbackSink.mData4[6];
            ezclsid.mClsid.mData4[7] ^= ECLSID_XOR_CallbackSink.mData4[7];
            ezclsid.mUunm = (char*)alloca(sizeof(char) \
                    * (strlen(((CIClassInfo*)m_pInfo)->mUunm) + 1));
            strcpy(ezclsid.mUunm, ((CIClassInfo*)m_pInfo)->mUunm);
            _CObject_AcquireClassFactory(ezclsid, RGM_SAME_DOMAIN, EIID_CALLBACK_CONNECTOR, &pTemp);
            m_pICallbackConnector = (ICallbackConnector*)pTemp;
        }
        return (IInterface*)m_pICallbackConnector;
    }

    for (n = 0; n < m_cInterfaces; n++) {
        if (riid == m_pInterfaces[n].m_pInfo->mIID) {
            break;
        }
    }
    if (n == m_cInterfaces) {
        // Execute a remote probe to support AOP.
        return RemoteProbe(riid);
    }

    return (IInterface *)&(m_pInterfaces[n].m_pvVptr);
}

typedef struct ProbeRequestData {
    MarshalHeader header;
    InterfaceID iid;
} ProbeRequestData;

typedef struct ProbeReplyData {
    ECode ec;
    MarshalHeader header;
    UInt32 notNull;
    InterfacePack interfacePack;
} ProbeReplyData;

PInterface CObjectProxy::RemoteProbe(REIID riid)
{
    int type, len;
    ECode ec;
    IInterface *pObj;

    struct ProbeRequestData requestData = {
        {
            MARSHAL_MAGIC,
            0,
            0,
            sizeof(ProbeRequestData),
            sizeof(ProbeReplyData) - sizeof(ECode)
        },
        riid
    };
    struct ProbeReplyData *pReplyData;

    ec = mSession->SendMessage(METHOD_INVOKE, &requestData,
                        sizeof(struct ProbeRequestData));
    if (FAILED(ec)) {
        return NULL;
    }

    ec = ReceiveFromRemote(&type, (void **)&pReplyData, &len);
    if (FAILED(ec)) {
        return NULL;
    }

    RPC_LOG(" RemoteProbe receive len: %d", len);

    if (len < sizeof(ProbeReplyData) ||
            type != METHOD_INVOKE_REPLY ||
            !SUCCEEDED(pReplyData->ec)) {
        MARSHAL_DBGOUT(MSHDBG_WARNING,
                printf("proxy RemoteProbe() ec = %x\n", pReplyData->ec));
        free(pReplyData);
    RPC_LOG(" RemoteProbe receive return null");
        return NULL;
    }
    assert(pReplyData->notNull == MSH_NOT_NULL);

    ec = StdUnmarshalInterface(UnmarshalFlag_Noncoexisting,
                               mSession,
                               &(pReplyData->interfacePack),
                               &pObj);
    free(pReplyData);

    return SUCCEEDED(ec) ? pObj : NULL;
}

UInt32 CObjectProxy::AddRef(void)
{
    Int32 lRefs = atomic_inc(&m_cRef);

    MARSHAL_DBGOUT(MSHDBG_CREF, printf(
            "Proxy AddRef: %d\n", lRefs));
    return (UInt32)lRefs;
}

UInt32 CObjectProxy::Release(void)
{
    ECode ec;

    Int32 lRefs = atomic_dec(&m_cRef);

    if (lRefs == 0) {
        MARSHAL_DBGOUT(MSHDBG_NORMAL, printf(
                "Proxy destructed.\n"));

        ec = UnregisterImportObject(m_stubConnName);
        if (ec == S_FALSE) {
            return 1;// other thread hold the proxy
        }

        if (m_pICallbackConnector) {
            m_pICallbackConnector->DisconnectCallbackSink();
            delete m_pICallbackConnector;
        }

        ec = mSession->SendMessage(METHOD_RELEASE, NULL, 0);
        if (FAILED(ec)) {
             goto Exit;
        }

Exit:
        delete this;

        return 0;
    }

    MARSHAL_DBGOUT(MSHDBG_CREF, printf(
            "ProxyRelease: %d\n", lRefs));

    return (UInt32)lRefs;
}

ECode CObjectProxy::GetInterfaceCount(
    /* [out] */ Int32* count) {
    assert(0);
    return NOERROR;
}

ECode CObjectProxy::GetAllInterfaceInfos(
    /* [out] */ ArrayOf<IInterfaceInfo*>* interfaceInfos) {
    assert(0);
    return NOERROR;
}

ECode CObjectProxy::GetInterfaceID(
    /* [in] */ IInterface *pObject,
    /* [out] */ InterfaceID *pIID)
{
    if (NULL == pIID) return E_INVALID_ARGUMENT;

    if (pObject == (IInterface *)(IProxy *)this) {
        *pIID = EIID_IProxy;
    }
    else {
        return E_INVALID_ARGUMENT;
    }
    return NOERROR;
}

ECode CObjectProxy::GetInterface(
    /* [in] */ UInt32 uIndex,
    /* [out] */ IInterface **ppObj)
{
    assert(ppObj != NULL);

    RPC_LOG(" CObjectProxy::GetInterface uIndex: %d, m_cInterfaces: %d", uIndex, m_cInterfaces);
    if (uIndex < (UInt32)m_cInterfaces) {
        *ppObj = (IInterface *)&(m_pInterfaces[uIndex].m_pvVptr);
        this->AddRef();
        return NOERROR;
    }
    MARSHAL_DBGOUT(MSHDBG_WARNING, printf(
            "Proxy: IndexQI failed - idx(%d), cInterfaces(%d)\n",
            uIndex, m_cInterfaces));

    return E_NO_INTERFACE;
}

ECode CObjectProxy::GetInterfaceIndex(
     /* [in] */ IInterface *pObj,
     /* [out] */ UInt32* pIndex)
{
    assert(pIndex != NULL);

    Int32 Index = 0;
    while (Index < m_cInterfaces) {
        if ((void*)pObj == &(m_pInterfaces[Index].m_pvVptr)) {
            *pIndex = Index;
            return NOERROR;
        }
        Index++;
    }
    return E_NO_INTERFACE;
}

ECode CObjectProxy::GetClassID(
    /* [out] */ EMuid *pClsid)
{
    assert(pClsid != NULL);

    *pClsid = ((CIClassInfo*)m_pInfo)->mCLSID;
    return NOERROR;
}

ECode CObjectProxy::GetClassInfo(
    /* [out] */ CIClassInfo **ppClassInfo)
{
    assert(ppClassInfo != NULL);

    *ppClassInfo = m_pInfo;
    return NOERROR;
}

ECode CObjectProxy::LinkToDeath(
    /* [in] */ IProxyDeathRecipient* recipient,
    /* [in] */ Int32 flags)
{
    assert(0);

    return NOERROR;
}

ECode CObjectProxy::UnlinkToDeath(
    /* [in] */ IProxyDeathRecipient* recipient,
    /* [in] */ Int32 flags,
    /* [out] */ Boolean* result)
{
    assert(0);

    return NOERROR;
}

ECode CObjectProxy::IsStubAlive(
    /* [out] */ Boolean* result) {
    assert(0);

    return NOERROR;
}

ECode CObjectProxy::S_CreateObject(
    /* [in] */ CSession* pSession,
    /* [in] */ REMuid rclsid,
    /* [in] */ const char* stubConnName,
    /* [out] */ IProxy **ppIProxy)
{
    if (!pSession) {
        return E_INVALID_ARGUMENT;
    }

    CObjectProxy *pProxy;
    CInterfaceProxy *pInterfaces;
    Int32 n;
    ECode ec;

    if (ppIProxy == NULL) return E_INVALID_ARGUMENT;

    pProxy = new CObjectProxy(pSession);
    if (!pProxy) {
        MARSHAL_DBGOUT(MSHDBG_ERROR,
                printf("Create proxy object: out of memory.\n"));
        return E_OUT_OF_MEMORY;
    }

    pProxy->m_stubConnName = stubConnName;

    pProxy->m_stubId = stubConnName;

    if (!pSession->IsConnected()) {
        ec = E_FAIL;
        goto ErrorExit;
    }

    ec = LookupClassInfo(rclsid, &(pProxy->m_pInfo));
    if (FAILED(ec)) {
        ec = GetRemoteClassInfo(pSession,
                                 rclsid,
                                 &pProxy->m_pInfo);
        if (FAILED(ec)) goto ErrorExit;
    }

    pProxy->m_cInterfaces = ((CIClassInfo*)(pProxy->m_pInfo))->mInterfaceNum;
    pInterfaces = new CInterfaceProxy[pProxy->m_cInterfaces];
    if (!pInterfaces) {
        MARSHAL_DBGOUT(MSHDBG_ERROR,
                printf("Create proxy interfaces: out of memory.\n"));
        ec = E_OUT_OF_MEMORY;
        goto ErrorExit;
    }
    pProxy->m_pInterfaces = pInterfaces;
    memset(pInterfaces, 0, sizeof(CInterfaceProxy) * pProxy->m_cInterfaces);
    for (n = 0; n < pProxy->m_cInterfaces; n++) {
        pInterfaces[n].m_uIndex = n;
        pInterfaces[n].m_pOwner = pProxy;
        CIInterfaceInfo *pInterfaceInfo =
            (CIInterfaceInfo *)GetUnalignedPtr(
                    pProxy->m_pInfo->mInterfaces + n);
        pInterfaces[n].m_pInfo = pInterfaceInfo;
        pInterfaces[n].m_pvVptr = g_marshalVtbl;

#ifdef _x86
	pInterfaces[n].m_pvProxyEntry = (PVoid)&CInterfaceProxy::ProxyEntry;
#elif defined(_arm)
	pInterfaces[n].m_pvProxyEntry = (PVoid)&__ProxyEntry;
#else
#error unknown architecture
#endif
    }

    ec = RegisterImportObject(pProxy->m_stubConnName, (IProxy*)pProxy);
    if (FAILED(ec)) {
        MARSHAL_DBGOUT(MSHDBG_ERROR, printf(
                "Create proxy: register import object failed, ec(%x)\n",
                ec));
        goto ErrorExit;
    }

    *ppIProxy = (IProxy*)pProxy;

    return NOERROR;

ErrorExit:

    delete pProxy;
    return ec;
}

ECode CObjectProxy::ReceiveFromRemote(
    /* [out] */ int* type,
    /* [out] */ void** buf,
    /* [out] */ int* len)
{
    pthread_mutex_lock(&mWorkLock);
    if (mData) {
        if (mData->data)
            ArrayOf<Byte>::Free(mData->data);
        delete mData;
        mData = NULL;
    }
    while (mData == NULL) {
        pthread_cond_wait(&mCv, &mWorkLock);
    }

    if (FAILED(mData->ec)) {
        ECode ec = mData->ec;
        if (mData->data)
            ArrayOf<Byte>::Free(mData->data);
        delete mData;
        mData = NULL;
        pthread_mutex_unlock(&mWorkLock);
        return ec;
    }

    Byte* p = mData->data->GetPayload();
    int _len = mData->data->GetLength();
    int _type = *(size_t *)p;
    p += sizeof(size_t);
    _len -= sizeof(size_t);

    RPC_LOG("CObjectProxy::ReceiveFromRemote type:%d", _type);
    *type = _type;
    if (buf != NULL) {
        void* _base = malloc(_len);
        if (_base == NULL) {
            if (mData->data)
                ArrayOf<Byte>::Free(mData->data);
            delete mData;
            mData = NULL;
            pthread_mutex_unlock(&mWorkLock);
            return E_FAIL;
        }
        memcpy(_base, p, _len);
        *buf = _base;
        *len = _len;
    }

    if (mData->data)
        ArrayOf<Byte>::Free(mData->data);
    delete mData;
    mData = NULL;
    pthread_mutex_unlock(&mWorkLock);

    return NOERROR;
}

void CObjectProxy::CProxyListener::OnSessionConnected(
    /* [in] */ CSession* pSession,
    /* [in] */ Boolean succeeded,
    /* [in] */ void* context)
{
    if (!succeeded) {
        CObjectProxy* proxy = (CObjectProxy*)context;
        if (!proxy) return;

        pthread_mutex_lock(&proxy->mWorkLock);

        if (proxy->mData) {
            if (proxy->mData->data)
                ArrayOf<Byte>::Free(proxy->mData->data);
            delete proxy->mData;
            proxy->mData = NULL;
        }

        proxy->mData = new DataPack();
        if (!proxy->mData) {
            pthread_mutex_unlock(&proxy->mWorkLock);
            return;
        }
        proxy->mData->data = NULL;
        proxy->mData->ec = E_SESSION_FAILED;
        pthread_mutex_unlock(&proxy->mWorkLock);
        pthread_cond_signal(&proxy->mCv);
    }
    return;
}

void CObjectProxy::CProxyListener::OnSessionReceived(
    /* [in] */ CSession* pSession,
    /* [in] */ ArrayOf<Byte>* data,
    /* [in] */ void* context)
{
    RPC_LOG("CObjectProxy::CProxyListener::OnSessionReceived data: %p, context: %p", data, context);
    CObjectProxy* proxy = (CObjectProxy*)context;
    if (!proxy) return;

    pthread_mutex_lock(&proxy->mWorkLock);

    if (proxy->mData) {
        if (proxy->mData->data)
            ArrayOf<Byte>::Free(proxy->mData->data);
        delete proxy->mData;
        proxy->mData = NULL;
    }

    proxy->mData = new DataPack();
    if (!proxy->mData) {
        pthread_mutex_unlock(&proxy->mWorkLock);
        return;
    }
    proxy->mData->data = data->Clone();
    if (!proxy->mData->data) {
        pthread_mutex_unlock(&proxy->mWorkLock);
        return;
    }
    proxy->mData->ec = NOERROR;
    pthread_mutex_unlock(&proxy->mWorkLock);
    pthread_cond_signal(&proxy->mCv);
}
