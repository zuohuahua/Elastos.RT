
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include <elaatomics.h>
#include "prxstub.h"
#include "rot.h"

#ifdef _MSC_VER
# include <winsock2.h>
#else
# include <arpa/inet.h>
#endif


ECode LookupModuleInfo(
    /* [in] */ REMuid rclsid,
    /* [out] */ CIModuleInfo **ppModuleInfo);

ECode LookupClassInfo(
    /* [in] */ REMuid rclsid,
    /* [out] */ CIClassInfo **ppClassInfo);

ECode AcquireClassInfo(
    /* [in] */ const ClassID & classId,
    /* [out] */ CIClassInfo **ppClassInfo);

void FlatModuleInfo(
    /* [in] */ CIModuleInfo *pSrcModInfo,
    /* [out] */ CIModuleInfo *pDestModInfo);

void *GetUnalignedPtr(void *pPtr);

ECode CInterfaceStub::UnmarshalIn(
    /* [in] */ const CIMethodInfo *pMethodInfo,
    /* [in] */ CRemoteParcel *pParcel,
    /* [in, out] */ MarshalHeader *pOutHeader,
    /* [in, out] */ UInt32 *puArgs)
{
    return Stub_ProcessUnmsh_In(
            pMethodInfo,
            (IParcel*)pParcel,
            (UInt32 *)pOutHeader,
            puArgs);
}

ECode CInterfaceStub::MarshalOut(
    /* [in] */ UInt32 *puArgs,
    /* [in] */ MarshalHeader *pInHeader,
    /* [out] */ MarshalHeader *pOutHeader,
    /* [in] */ Boolean bOnlyReleaseIn,
    /* [in, out] */ CRemoteParcel* pParcel)
{
    MarshalHeader *pHeader;
    ECode ec;

    ec = Stub_ProcessMsh_Out(
            &(m_pInfo->mMethods[pInHeader->m_hMethodIndex - 4]),
            puArgs,
            (UInt32 *)pOutHeader,
            bOnlyReleaseIn,
            (IParcel*)pParcel);

    if (pParcel && SUCCEEDED(ec)) {
        pHeader = pParcel->GetMarshalHeader();
        assert(pHeader != NULL);
        pHeader->m_uMagic = pInHeader->m_uMagic;
        pHeader->m_hInterfaceIndex = pInHeader->m_hInterfaceIndex ;
        pHeader->m_hMethodIndex = pInHeader->m_hMethodIndex;
    }

    return ec;
}

CObjectStub::CObjectStub() :
    mSessionManager(NULL),
    mSessionManagerListener(NULL),
    m_pInterfaces(NULL),
    m_bRequestToQuit(FALSE),
    m_cRef(1)
{
}

CObjectStub::~CObjectStub()
{
    if (m_pInterfaces) {
        delete [] m_pInterfaces;
    }

    if (mSessionManagerListener) {
        mSessionManager->RemoveListener(mSessionManagerListener, this);
        mSessionManagerListener->Release();
    }

    if (mSessionManager) {
        mSessionManager->Release();
    }

    UnregisterExportObject(m_connName);

    pthread_exit((void*)0);
}

PInterface CObjectStub::Probe(
    /* [in] */ REIID riid)
{
    Int32 n;

    if (riid == EIID_IInterface) {
        return (IInterface*)(IStub*)this;
    }

    for (n = 0; n < m_cInterfaces; n++) {
        if (riid == m_pInterfaces[n].m_pInfo->mIID) {
            break;
        }
    }
    if (n == m_cInterfaces) {
        MARSHAL_DBGOUT(MSHDBG_WARNING, printf(
                "Stub: Probe failed, iid: "));
        MARSHAL_DBGOUT(MSHDBG_WARNING, DUMP_GUID(riid));

        return NULL;
    }

    return m_pInterfaces[n].m_pObject;
}

UInt32 CObjectStub::AddRef(void)
{
    Int32 lRefs = atomic_inc(&m_cRef);

    MARSHAL_DBGOUT(MSHDBG_CREF, printf(
            "Stub AddRef: %d\n", lRefs));
    return (UInt32)lRefs;
}

UInt32 CObjectStub::Release(void)
{
    Int32 lRefs = atomic_dec(&m_cRef);

    if (lRefs == 0) {
        MARSHAL_DBGOUT(MSHDBG_NORMAL, printf(
                "Stub destructed.\n"));
        delete this;

        return 0;
    }

    MARSHAL_DBGOUT(MSHDBG_CREF, printf(
            "Stub Release: %d\n", lRefs));
    return (UInt32)lRefs;
}

ECode CObjectStub::GetInterfaceID(
    /* [in] */ IInterface *pObject,
    /* [out] */ InterfaceID *pIID)
{
    return E_NOT_IMPLEMENTED;
}

#ifdef _arm
ECode CObjectStub::Invoke(
    /* [in] */ CSession* pSession,
    /* [in] */ void *pInData,
    /* [in] */ UInt32 uInSize,
    /* [out] */ CRemoteParcel **ppParcel)
{
    return _Invoke(pSession, pInData, uInSize, ppParcel);
}
#endif //_arm

#ifdef _x86
ECode CObjectStub::Invoke(
    /* [in] */ CSession* pSession,
    /* [in] */ void *pInData,
    /* [in] */ UInt32 uInSize,
    /* [out] */ CRemoteParcel **ppParcel)
#elif defined(_arm)
ECode CObjectStub::_Invoke(
    /* [in] */ CSession* pSession,
    /* [in] */ void *pInData,
    /* [in] */ UInt32 uInSize,
    /* [out] */ CRemoteParcel **ppParcel)
#elif defined(_mips)
ECode CObjectStub::Invoke(
    /* [in] */ CSession* pSession,
    /* [in] */ void *pInData,
    /* [in] */ UInt32 uInSize,
    /* [out] */ CRemoteParcel **ppParcel)
#else
#error unknown architecture
#endif
{
    assert(pInData != NULL);

    MarshalHeader *pInHeader = NULL, *pOutHeader = NULL;
    UInt32 *puArgs, uMethodAddr, uMethodIndex;
    ECode ec, orgec = NOERROR;
    CInterfaceStub *pCurInterface;
    const CIMethodInfo *pMethodInfo;
    CRemoteParcel *pParcel = NULL;

#ifdef _x86
    UInt32 uEAX, uEDX, uECX, uESP;
#elif defined(_arm)

#elif defined(_mips)
    UInt32 uV0, uV1;
    UInt32 uA0, uA1, uA2, uA3;
    UInt32 uT0, uT1, uT2, uT3, uT4, uT5, uT6, uT7, uT8, uT9;
    UInt32 uSp;
#else
#error unknown architecture
#endif
    bool_t bOnlyReleaseIn = FALSE;

    MARSHAL_DBGOUT(MSHDBG_NORMAL,
            printf("Stub: in Invoke: isize(%d)\n", uInSize));

    pInHeader = (MarshalHeader *)pInData;
    if (pInHeader->m_uMagic != MARSHAL_MAGIC) {
        MARSHAL_DBGOUT(MSHDBG_ERROR,
                printf("Stub: invalid magic - %x\n", pInHeader->m_uMagic));
        goto ErrorExit;
    }

#if defined(_DEBUG)
    if (uInSize < sizeof(MarshalHeader)) {
        goto ErrorExit;
    }
    if (uInSize != pInHeader->m_uInSize) {
        MARSHAL_DBGOUT(MSHDBG_ERROR,
                printf("Stub: in size error - %d:%d\n",
                uInSize, pInHeader->m_uInSize + sizeof(MarshalHeader) - 1));
        goto ErrorExit;
    }
    if (pInHeader->m_hInterfaceIndex >= m_cInterfaces) {
        MARSHAL_DBGOUT(MSHDBG_ERROR,
                printf("Stub: interface index error - %d:%d\n",
                pInHeader->m_hInterfaceIndex, m_cInterfaces));
        goto ErrorExit;
    }
    MARSHAL_DBGOUT(MSHDBG_NORMAL,
            printf("Stub: interface idx(%d), method idx(%d)\n",
            pInHeader->m_hInterfaceIndex, pInHeader->m_hMethodIndex));
#endif

    if (pInHeader->m_hMethodIndex >= 4) {
        pCurInterface = &(m_pInterfaces[pInHeader->m_hInterfaceIndex]);

        uMethodIndex = pInHeader->m_hMethodIndex - 4;
        if (uMethodIndex >= pCurInterface->m_pInfo->mMethodNumMinus4) {
            MARSHAL_DBGOUT(MSHDBG_ERROR,
                    printf("Stub: method index out of range - %d:%d\n",
                    uMethodIndex,
                    pCurInterface->m_pInfo->mMethodNumMinus4));
            goto ErrorExit;
        }

        uMethodAddr =
                pCurInterface->m_pInterface->m_vPtr->m_vTable[uMethodIndex + 4];

        if (0 != pInHeader->m_uOutSize) {
            pOutHeader = (MarshalHeader *)alloca(pInHeader->m_uOutSize);
            if (!pOutHeader) {
                MARSHAL_DBGOUT(MSHDBG_ERROR,
                        printf("Stub error: alloca() failed.\n"));
                ec = E_OUT_OF_MEMORY;
                goto ErrorExit;
            }
        }

        pMethodInfo = &((pCurInterface->m_pInfo)->mMethods[uMethodIndex]);
        uInSize = GET_LENGTH(pMethodInfo->mReserved1) * 4 + 4;
        MARSHAL_DBGOUT(MSHDBG_NORMAL,
                printf("Stub: method args stack size (%d)\n", uInSize));
        puArgs = (UInt32 *)alloca(uInSize);
        if (!puArgs) {
            MARSHAL_DBGOUT(MSHDBG_ERROR,
                    printf("Stub error: alloca() failed.\n"));
            ec = E_OUT_OF_MEMORY;
            goto ErrorExit;
        }
#ifdef _x86
        GET_REG(ESP, puArgs);
#endif

        pParcel = new CRemoteParcel(pSession, (UInt32*)pInHeader);
        ec = pCurInterface->UnmarshalIn(pMethodInfo,
                                        pParcel,
                                        pOutHeader,
                                        puArgs + 1);
        if (FAILED(ec)) {
            MARSHAL_DBGOUT(MSHDBG_ERROR,
                    printf("Stub error: UnmarshalIn() failed.\n"));
            goto ErrorExit;
        }

        *puArgs = (UInt32)pCurInterface->m_pObject; // fill this

        MARSHAL_DBGOUT(MSHDBG_NORMAL,
                printf("Stub: invoke method - args(%x), addr(%x) \n",
                puArgs, uMethodAddr));

#ifdef _x86
        GET_REG(EAX, uEAX);
        GET_REG(EDX, uEDX);
        GET_REG(ECX, uECX);
        GET_REG(ESP, uESP);
        assert(uESP == (UInt32)puArgs);
        // NOTE: we should promise STUB_INVOKE_METHOD just occures
        // in use space , if it used in kernel mode , the return
        // args in stack have the possibilty for being modified
        //
        STUB_INVOKE_METHOD(ec, puArgs, uMethodAddr);
        SET_REG(ECX, uECX);
        SET_REG(EDX, uEDX);
        SET_REG(EAX, uEAX);
#elif defined(_arm)

#if defined(_GNUC)
    if (sizeof(UInt32) * 4 >= uInSize) {
        ec = ((ECode (*)(
                UInt32, UInt32, UInt32, UInt32
            ))uMethodAddr)
            (
                *puArgs, *(puArgs + 1), *(puArgs + 2), *(puArgs + 3)
            );
    }
    else if (sizeof(UInt32) * 8 >= uInSize) {
        ec = ((ECode (*)(
                UInt32, UInt32, UInt32, UInt32, UInt32, UInt32, UInt32, UInt32
            ))uMethodAddr)
            (
                *puArgs, *(puArgs + 1), *(puArgs + 2), *(puArgs + 3),
                *(puArgs + 4), *(puArgs + 5), *(puArgs + 6), *(puArgs + 7)
            );
    }
    else if (sizeof(UInt32) * 16 >= uInSize) {
        ec = ((ECode (*)(
                UInt32, UInt32, UInt32, UInt32, UInt32, UInt32, UInt32, UInt32,
                UInt32, UInt32, UInt32, UInt32, UInt32, UInt32, UInt32, UInt32
            ))uMethodAddr)
            (
                *puArgs, *(puArgs + 1), *(puArgs + 2), *(puArgs + 3),
                *(puArgs + 4), *(puArgs + 5), *(puArgs + 6), *(puArgs + 7),
                *(puArgs + 8), *(puArgs + 9), *(puArgs + 10), *(puArgs + 11),
                *(puArgs + 12), *(puArgs + 13), *(puArgs + 14), *(puArgs + 15)
            );
    }
    else if (sizeof(UInt32) * 32 >= uInSize) {
        ec = ((ECode (*)(
                UInt32, UInt32, UInt32, UInt32, UInt32, UInt32, UInt32, UInt32,
                UInt32, UInt32, UInt32, UInt32, UInt32, UInt32, UInt32, UInt32,
                UInt32, UInt32, UInt32, UInt32, UInt32, UInt32, UInt32, UInt32,
                UInt32, UInt32, UInt32, UInt32, UInt32, UInt32, UInt32, UInt32
            ))uMethodAddr)
            (
                *puArgs, *(puArgs + 1), *(puArgs + 2), *(puArgs + 3),
                *(puArgs + 4), *(puArgs + 5), *(puArgs + 6), *(puArgs + 7),
                *(puArgs + 8), *(puArgs + 9), *(puArgs + 10), *(puArgs + 11),
                *(puArgs + 12), *(puArgs + 13), *(puArgs + 14), *(puArgs + 15),
                *(puArgs + 16), *(puArgs + 17), *(puArgs + 18), *(puArgs + 19),
                *(puArgs + 20), *(puArgs + 21), *(puArgs + 22), *(puArgs + 23),
                *(puArgs + 24), *(puArgs + 25), *(puArgs + 26), *(puArgs + 27),
                *(puArgs + 28), *(puArgs + 29), *(puArgs + 30), *(puArgs + 31)
            );
    }
    else {
        MARSHAL_DBGOUT(MSHDBG_ERROR,
                printf("Stub invoke: too many parameters, stack size(%x)\n", uInSize));
        return E_MARSHAL_DATA_TRANSPORT_ERROR;
    }
#else

#error Unknown C++ compiler

#endif // defined(_GNUC)

#elif defined(_mips)
        GET_REG($2, uV0);
        GET_REG($3, uV1);
        GET_REG($4, uA0);
        GET_REG($5, uA1);
        GET_REG($6, uA2);
        GET_REG($7, uA3);
        GET_REG($8, uT0);
        GET_REG($9, uT1);
        GET_REG($10, uT2);
        GET_REG($11, uT3);
        GET_REG($12, uT4);
        GET_REG($13, uT5);
        GET_REG($14, uT6);
        GET_REG($15, uT7);
        GET_REG($24, uT8);
        GET_REG($25, uT9);
        GET_REG($29, uSp);
        STUB_INVOKE_METHOD(ec, puArgs, uMethodAddr);
        SET_REG($29, uSp);
        SET_REG($2, uV0);
        SET_REG($3, uV1);
        SET_REG($4, uA0);
        SET_REG($5, uA1);
        SET_REG($6, uA2);
        SET_REG($7, uA3);
        SET_REG($8, uT0);
        SET_REG($9, uT1);
        SET_REG($10, uT2);
        SET_REG($11, uT3);
        SET_REG($12, uT4);
        SET_REG($13, uT5);
        SET_REG($14, uT6);
        SET_REG($15, uT7);
        SET_REG($24, uT8);
        SET_REG($25, uT9);
#else
#error unknown architecture
#endif

        if (FAILED(ec) && GET_IN_INTERFACE_MARK(pMethodInfo->mReserved1)) {
            bOnlyReleaseIn = TRUE;
        }

        // puArgs + 1 , skip this pointer
        if ((pOutHeader && SUCCEEDED(ec))
            || GET_IN_INTERFACE_MARK(pMethodInfo->mReserved1)) {

            if (pOutHeader && SUCCEEDED(ec)) {
                *ppParcel = new CRemoteParcel(pSession);
                if (*ppParcel == NULL) {
                    ec = E_OUT_OF_MEMORY;
                    goto ErrorExit;
                }
            }

            orgec = pCurInterface->MarshalOut(puArgs + 1,
                                              pInHeader,
                                              pOutHeader,
                                              bOnlyReleaseIn,
                                              *ppParcel);
            if (FAILED(orgec)) {
                MARSHAL_DBGOUT(MSHDBG_ERROR, printf(
                        "Stub: marshal out args fail, hr(%x)\n", ec));
                ec = orgec;
                goto ErrorExit;
            }
        }
    }
    else if (pInHeader->m_hMethodIndex == 0) {
        IInterface *pInterface;
        InterfaceID *pIID = (InterfaceID *)(pInHeader + 1);

        pInterface = m_pInterfaces[0].m_pObject->Probe(*pIID);
        if (pInterface == NULL) {
            ec = E_NO_INTERFACE;
            goto ErrorExit;
        }

        *ppParcel = new CRemoteParcel(pSession);
        if (*ppParcel == NULL) {
            ec = E_OUT_OF_MEMORY;
            goto ErrorExit;
        }

        pOutHeader = (*ppParcel)->GetMarshalHeader();
        memcpy(pOutHeader, pInHeader, sizeof(MarshalHeader));
        ec = (*ppParcel)->WriteInterfacePtr(pInterface);
        if (FAILED(ec)) {
            MARSHAL_DBGOUT(MSHDBG_ERROR,
                    printf(
                        "Stub error(%x): Parcel->WriteInterfacePtr().\n",
                        ec));
            // Here do not need to delete ppParcel for caller will do it.
        }
    }
    else {
        if (pInHeader->m_hMethodIndex == 0) {
            MARSHAL_DBGOUT(MSHDBG_ERROR,
                    printf("Stub error: Remote Probe().\n"));
        }
        else if (pInHeader->m_hMethodIndex == 1) {
            MARSHAL_DBGOUT(MSHDBG_ERROR,
                    printf("Stub error: Remote AddRef().\n"));
        }
        else if (pInHeader->m_hMethodIndex == 2) {
            MARSHAL_DBGOUT(MSHDBG_ERROR,
                    printf("Stub error: Remote Release().\n"));
        }
        else if (pInHeader->m_hMethodIndex == 3) {
            MARSHAL_DBGOUT(MSHDBG_ERROR,
                    printf("Stub error: Remote GetInterfaceID().\n"));
        }
        ec = E_INVALID_OPERATION;    // Do not allow remote Probe().
        goto ErrorExit;
    }

    MARSHAL_DBGOUT(MSHDBG_NORMAL, printf(
            "Stub: invoke server method ok, _SysReply\n"));

ErrorExit:

    if (pParcel != NULL) delete pParcel;

    return ec;
}

ECode CObjectStub::GetClassID(
    /* [out] */ EMuid *pClsid)
{
    assert(pClsid != NULL);

    *pClsid = ((CIClassInfo*)m_pInfo)->mCLSID;
    return NOERROR;
}

ECode CObjectStub::GetClassInfo(
    /* [out] */ CIClassInfo **ppClassInfo)
{
    assert(ppClassInfo != NULL);

    *ppClassInfo = m_pInfo;
    return NOERROR;
}

ECode CObjectStub::GetInterfaceIndex(
    /* [in] */ IInterface *pObj,
    /* [out] */ UInt32 *puIndex)
{
    for (UInt32 n = 0; n < (UInt32)m_cInterfaces; n++) {
        if (m_pInterfaces[n].m_pObject == pObj) {
            *puIndex = n;
            return NOERROR;
        }
    }
    MARSHAL_DBGOUT(MSHDBG_WARNING, printf(
        "Stub: InterfaceIndex failed - pObj(%x)\n", pObj));

    return E_NO_INTERFACE;
}

ECode CObjectStub::HandleGetClassInfo(CSession* pSession, void const *base, int len)
{
    EMuid clsid;
    CIModuleInfo *pSrcModInfo;
    CIModuleInfo *pDestModInfo;

    this->GetClassID(&clsid);
    if (FAILED(LookupModuleInfo(clsid, &pSrcModInfo))) {
        MARSHAL_DBGOUT(MSHDBG_ERROR, printf("Lookup module info fail.\n"));
        return NOERROR;
    }

    pDestModInfo = (CIModuleInfo *)calloc(1, pSrcModInfo->mTotalSize);
    FlatModuleInfo(pSrcModInfo, pDestModInfo);

    pSession->SendMessage(METHOD_GET_CLASS_INFO_REPLY, pDestModInfo,
                    pDestModInfo->mTotalSize);

    free(pDestModInfo);

    return NOERROR;
}

ECode CObjectStub::HandleInvoke(CSession* pSession, void const *base, int len)
{
    void *pOutBuffer;
    Int32 outSize;
    CRemoteParcel *pParcel = NULL;
    ECode ec;

    RPC_LOG("Call Invoke.");
    MARSHAL_DBGOUT(MSHDBG_NORMAL, printf("Call Invoke.\n"));

    ec = this->Invoke(pSession, (void *)base, len, &pParcel);
    RPC_LOG("Call Invoke ec: %x", ec);

    int32_t _ec = ec;
    if (pParcel != NULL) {
        pParcel->GetElementSize(&outSize);
        pParcel->GetElementPayload((Handle32*)&pOutBuffer);

        if (outSize > 0) {
            int out_size = sizeof _ec + outSize;
            // char out_buf[out_size];
            char* out_buf = (char*)alloca(out_size * sizeof(char));
            char *p;

            p = out_buf;
            memcpy(p, &_ec, sizeof _ec);
            p += sizeof _ec;
            memcpy(p, pOutBuffer, outSize);

            pSession->SendMessage(METHOD_INVOKE_REPLY, out_buf, out_size);

        }
    } else {
        pSession->SendMessage(METHOD_INVOKE_REPLY, &_ec, sizeof _ec);
    }

    if (pParcel != NULL)
        delete pParcel;

    return NOERROR;
}

ECode CObjectStub::HandleRelease(CSession* pSession, void const *base, int len)
{
    MARSHAL_DBGOUT(MSHDBG_NORMAL, printf("Stub Release.\n"));

    //bugbug: if there are more than one processes invoke
    //        the stub, then one proxy in a process call "Release"
    //        should not make the stub quit. We should use
    //        reference count to control when to make the stub quit.
    //this->m_bRequestToQuit = TRUE;

    this->Release();
    return NOERROR;
}

ECode CObjectStub::S_CreateObject(
    /* [in] */ IInterface *pObject,
    /* [out] */ IStub **ppIStub)
{
    CObjectStub *pStub;
    CInterfaceStub *pInterfaces;
    IInterface *pObj;
    IObject *pObj1;
    ClassID clsid;
    InterfaceID iid;
    ECode ec = NOERROR;
    CIClassInfo ** ppClassInfo = NULL;
    Int32 n;

    if (!pObject || !ppIStub) {
        return E_INVALID_ARGUMENT;
    }

    *ppIStub = NULL;

    pStub = new CObjectStub();
    if (!pStub) {
        return E_OUT_OF_MEMORY;
    }

    ec = CSessionManager::AcquireInstance(&pStub->mSessionManager);
    if (FAILED(ec)) {
        RPC_LOG("CObjectStub Acquire SessionManager failed: 0x%x\n", ec);
        goto ErrorExit;
    }

    pStub->mSessionManagerListener = new CSessionManagerListener();
    if (!pStub->mSessionManagerListener) {
        ec = E_OUT_OF_MEMORY;
        goto ErrorExit;
    }

    pStub->mSessionManager->AddListener(pStub->mSessionManagerListener, pStub);

    pStub->mSessionManager->GetUid(&pStub->m_connName);

    pObj1 = (IObject *)pObject->Probe(EIID_IAspect);
    if (!pObj1) {
        pObj1 = (IObject*)pObject->Probe(EIID_IObject);
    }
    if (!pObj1) {
        MARSHAL_DBGOUT(MSHDBG_ERROR, printf(
                "Create stub: interface do not support EIID_IObject QI.\n"));
        goto ErrorExit;
    }

    ec = pObj1->GetClassID(&clsid);
    if (FAILED(ec)) {
        MARSHAL_DBGOUT(MSHDBG_ERROR, printf(
                "Create stub: fail to get object's ClassID.\n"));
        goto ErrorExit;
    }

    MARSHAL_DBGOUT(MSHDBG_NORMAL, printf(
            "QI class info ok. EMuid is:\n"));
    MARSHAL_DBGOUT(MSHDBG_NORMAL, DUMP_CLSID(clsid));

    ec = pObject->GetInterfaceID(pObject, &iid);
    if (FAILED(ec)) {
        MARSHAL_DBGOUT(MSHDBG_ERROR, printf(
                "Create stub: interface does not have InterfaceID.\n"));
        goto ErrorExit;
    }
    MARSHAL_DBGOUT(MSHDBG_NORMAL, printf(
            "QI EIID info ok. EIID is:\n"));
    MARSHAL_DBGOUT(MSHDBG_NORMAL, DUMP_GUID(iid));

    ec = LookupClassInfo(clsid.mClsid, &(pStub->m_pInfo));
    if (FAILED(ec)) {
        ec = AcquireClassInfo(clsid, &(pStub->m_pInfo));
        if (FAILED(ec)) {
            MARSHAL_DBGOUT(MSHDBG_ERROR,
                    printf("Create Stub: get class info fail, the ec = 0x%08x\n", ec));
            goto ErrorExit;
        }
    }

    ppClassInfo = &(pStub->m_pInfo);

    MARSHAL_DBGOUT(MSHDBG_NORMAL, printf(
            "Create stub: Get class info ok.\n"));

    pInterfaces = new CInterfaceStub[(*ppClassInfo)->mInterfaceNum];
    if (!pInterfaces) {
        MARSHAL_DBGOUT(MSHDBG_ERROR, printf("Create stub: out of memory.\n"));
        ec = E_OUT_OF_MEMORY;
        goto ErrorExit;
    }
    pStub->m_cInterfaces = (*ppClassInfo)->mInterfaceNum;
    pStub->m_pInterfaces = pInterfaces;

    pObject->AddRef();
    for (n = 0; n < (*ppClassInfo)->mInterfaceNum; n++) {
        CIInterfaceInfo *pInterfaceInfo =
                (CIInterfaceInfo *)GetUnalignedPtr(
                        (*ppClassInfo)->mInterfaces + n);
        pObj = pObject->Probe(pInterfaceInfo->mIID);
        if (!pObj) {
            MARSHAL_DBGOUT(MSHDBG_ERROR,
                    printf("Create stub: no such interface.\n"));
            ec = E_NO_INTERFACE;
            pObject->Release();
            goto ErrorExit;
        }
        pInterfaces[n].m_pInfo = pInterfaceInfo;
        pInterfaces[n].m_pObject = pObj;
    }

    ec = RegisterExportObject(pStub->m_connName, pObject, pStub);
    if (FAILED(ec)) {
        pObject->Release();
        MARSHAL_DBGOUT(MSHDBG_ERROR, printf(
                "Create stub: register export object failed, ec(%x)\n", ec));
        goto ErrorExit;
    }

    *ppIStub = (IStub *)pStub;

    return NOERROR;

ErrorExit:
    delete pStub;
    return ec;
}


void CObjectStub::CSessionManagerListener::OnSessionRequest(
    /* [in] */ ICarrier* pCarrier,
    /* [in] */ const char *from,
    /* [in] */ const char *sdp,
    /* [in] */ size_t len,
    /* [in] */ void *context)
{
    CObjectStub* pStub = (CObjectStub*)context;
    if (!pStub) return;

    CSession* pSession;
    ECode ec = pStub->mSessionManager->CreateSession(String(from), FALSE,
                        sdp, len, &pSession);
    if (SUCCEEDED(ec)) {
        pSession->Release();
    }
}

void CObjectStub::CSessionManagerListener::OnSessionReceived(
    /* [in] */ CSession* pSession,
    /* [in] */ ArrayOf<Byte>* data,
    /* [in] */ void *context)
{
    RPC_LOG("CObjectStub::CSessionManagerListener OnSessionReceived");

    CObjectStub* pStub = (CObjectStub*)context;
    if (!pStub) return;

    Byte* p = data->GetPayload();
    int _len = data->GetLength();
    size_t _type = *(size_t *)p;
    p += sizeof(size_t);
    _len -= sizeof(size_t);

    RPC_LOG("CObjectStub receive type:%d, len: %d\n", _type, _len);

    switch (_type) {
    case METHOD_GET_CLASS_INFO:
        pStub->HandleGetClassInfo(pSession, p, _len);
        break;
    case METHOD_INVOKE:
        pStub->HandleInvoke(pSession, p, _len);
        break;
    case METHOD_RELEASE:
        pStub->HandleRelease(pSession, p, _len);
        break;
    default:
        break;
    }
}
