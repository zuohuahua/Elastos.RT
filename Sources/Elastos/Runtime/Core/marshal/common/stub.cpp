
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include <elaatomics.h>
#include "prxstub.h"
#include "rot.h"
#include "CParcelCarrier.h"

#ifdef _MSC_VER
# include <winsock2.h>
#else
# include <arpa/inet.h>
#endif


ECode LookupClassInfo(
    /* [in] */ REMuid rclsid,
    /* [out] */ CIClassInfo **ppClassInfo);

ECode AcquireClassInfo(
    /* [in] */ const ClassID & classId,
    /* [out] */ CIClassInfo **ppClassInfo);

void *GetUnalignedPtr(void *pPtr);

ECode CInterfaceStub::UnmarshalIn(
    /* [in] */ const CIMethodInfo *pMethodInfo,
    /* [in] */ CRemoteParcel *pParcel,
    /* [in, out] */ MarshalHeader *pOutHeader,
    /* [in, out] */ PVoid *puArgs)
{
    return Stub_ProcessUnmsh_In(
            pMethodInfo,
            (IParcel*)pParcel,
            (UInt32 *)pOutHeader,
            puArgs);
}

ECode CInterfaceStub::MarshalOut(
    /* [in] */ PVoid *puArgs,
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

    UnregisterExportObject(m_connName);

    delete m_pParcelCarrier;

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

ECode CObjectStub::Invoke(
    /* [in] */ CParcelSession* pParcelSession,
    /* [in] */ void *pInData,
    /* [in] */ UInt32 uInSize,
    /* [out] */ CRemoteParcel **ppParcel)
{
    assert(pInData != NULL);

    MarshalHeader *pInHeader = NULL, *pOutHeader = NULL;
    PVoid *puArgs, uMethodAddr;
    UInt32 uArgs, uMethodIndex;
    ECode ec, orgec = NOERROR;
    CInterfaceStub *pCurInterface;
    const CIMethodInfo *pMethodInfo;
    CRemoteParcel *pParcel = NULL;

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
                uInSize, pInHeader->m_uInSize + (UInt32)sizeof(MarshalHeader) - 1));
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
        uInSize = GET_LENGTH(pMethodInfo->mReserved1) * sizeof(PVoid) + sizeof(PVoid);

        MARSHAL_DBGOUT(MSHDBG_NORMAL,
                printf("Stub: method args stack size (%d)\n", uInSize));
        puArgs = (PVoid *)alloca(uInSize);
        if (!puArgs) {
            MARSHAL_DBGOUT(MSHDBG_ERROR,
                    printf("Stub error: alloca() failed.\n"));
            ec = E_OUT_OF_MEMORY;
            goto ErrorExit;
        }

        pParcel = new CRemoteParcel(pParcelSession, (UInt32*)pInHeader);
        ec = pCurInterface->UnmarshalIn(pMethodInfo,
                                        pParcel,
                                        pOutHeader,
                                        puArgs + 1);
        if (FAILED(ec)) {
            MARSHAL_DBGOUT(MSHDBG_ERROR,
                    printf("Stub error: UnmarshalIn() failed.\n"));
            goto ErrorExit;
        }

        *puArgs = (PVoid)pCurInterface->m_pObject; // fill this

        MARSHAL_DBGOUT(MSHDBG_NORMAL,
                printf("Stub: invoke method - args(%p), addr(%p) \n",
                puArgs, uMethodAddr));

        if (sizeof(PVoid) * 4 >= uInSize) {
            ec = ((ECode (*)(...))uMethodAddr)
                (
                    *puArgs, *(puArgs + 1), *(puArgs + 2), *(puArgs + 3)
                );
        }
        else if (sizeof(PVoid) * 8 >= uInSize) {
            ec = ((ECode (*)(...))uMethodAddr)
                (
                    *puArgs, *(puArgs + 1), *(puArgs + 2), *(puArgs + 3),
                    *(puArgs + 4), *(puArgs + 5), *(puArgs + 6), *(puArgs + 7)
                );
        }
        else if (sizeof(PVoid) * 16 >= uInSize) {
            ec = ((ECode (*)(...))uMethodAddr)
                (
                    *puArgs, *(puArgs + 1), *(puArgs + 2), *(puArgs + 3),
                    *(puArgs + 4), *(puArgs + 5), *(puArgs + 6), *(puArgs + 7),
                    *(puArgs + 8), *(puArgs + 9), *(puArgs + 10), *(puArgs + 11),
                    *(puArgs + 12), *(puArgs + 13), *(puArgs + 14), *(puArgs + 15)
                );
        }
        else if (sizeof(PVoid) * 32 >= uInSize) {
            ec = ((ECode (*)(...))uMethodAddr)
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

        if (FAILED(ec) && GET_IN_INTERFACE_MARK(pMethodInfo->mReserved1)) {
            bOnlyReleaseIn = TRUE;
        }

        // puArgs + 1 , skip this pointer
        if ((pOutHeader && SUCCEEDED(ec))
            || GET_IN_INTERFACE_MARK(pMethodInfo->mReserved1)) {

            if (pOutHeader && SUCCEEDED(ec)) {
                *ppParcel = new CRemoteParcel(pParcelSession);
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

        *ppParcel = new CRemoteParcel(pParcelSession);
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
        "Stub: InterfaceIndex failed - pObj(%p)\n", pObj));

    return E_NO_INTERFACE;
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
    //Start stub rpc service
    ec = CParcelCarrier::S_StartService(pStub, &pStub->m_pParcelCarrier);
    if (FAILED(ec)) {
        pObject->Release();
        MARSHAL_DBGOUT(MSHDBG_ERROR, printf("Stub: start rpc server fail.\n"));
        goto ErrorExit;
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
