
#define __USE_REMOTE_SOCKET

#if defined(__USE_REMOTE_SOCKET)
#include "prxstub.h"
#endif

#if !defined(__USE_REMOTE_SOCKET)
#include <dbus/dbus.h>
#endif

#include <pthread.h>
#include <dlfcn.h>
#include <stdio.h>
//#include <sys/config.h>
#include <elastos.h>
#include "marshal.h"

_ELASTOS_NAMESPACE_USING

void RelocateUnalignedPtr(void *pPtr, size_t offset);

void RelocateModuleInfo(
    /* [in] */ CIModuleInfo* pSrcModInfo,
    /* [out] */ CIModuleInfo* pDestModInfo);

static CIModuleInfoNode *s_pModuleInfoList = NULL;

static pthread_mutex_t s_moduleInfoLock;

#if defined(_DEBUG) || defined(_MARSHAL_DEBUG)
int _DumpGUID(REIID riid)
{
    return printf("%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X\n",
        riid.mData1, riid.mData2, riid.mData3,
        riid.mData4[0], riid.mData4[1], riid.mData4[2],
        riid.mData4[3], riid.mData4[4], riid.mData4[5],
        riid.mData4[6], riid.mData4[7]);
}

int _DumpCLSID(RClassID rclsid)
{
    _DumpGUID((REIID)rclsid);
    return printf("%s\n", rclsid.mUunm);
}
#endif // _DEBUG || _MARSHAL_DEBUG

ECode InitMIL()
{
    pthread_mutexattr_t recursiveAttr;
    pthread_mutexattr_init(&recursiveAttr);
    pthread_mutexattr_settype(&recursiveAttr, PTHREAD_MUTEX_RECURSIVE);
    if (pthread_mutex_init(&s_moduleInfoLock, &recursiveAttr)) {
        return E_FAIL;
    }
    pthread_mutexattr_destroy(&recursiveAttr);

    return NOERROR;
}

void UninitMIL()
{
    pthread_mutex_destroy(&s_moduleInfoLock);
}

ECode RegisterModuleInfo(
    /* [in] */ CIModuleInfo *pSrcModuleInfo)
{
    CIModuleInfo * pModuleInfo;
    CIModuleInfoNode *pNewNode;
    CIModuleInfoNode *pCurNode;
    CIClassInfo    *pClassInfo;
    CIInterfaceInfo *pInterfaceInfo;

    assert (NULL != pSrcModuleInfo);

    // TODO: compare component uuid, need car support
    // prevent from registering same ClassInfo again
    //
    pthread_mutex_lock(&s_moduleInfoLock);
    if (pSrcModuleInfo->mClassNum != 0) {
        pClassInfo = (CIClassInfo *)((UInt32)pSrcModuleInfo->mClasses \
                + (UInt32)pSrcModuleInfo);
        pCurNode = s_pModuleInfoList;
        while (pCurNode != NULL) {
            if (pCurNode->mModInfo->mClassNum != 0 \
                && pClassInfo[0].mCLSID == \
                pCurNode->mModInfo->mClasses[0].mCLSID) {
                break;
            }
            pCurNode = pCurNode->mNext;
        }
    }
    else if (pSrcModuleInfo->mInterfaceNum != 0) {
        pInterfaceInfo = (CIInterfaceInfo *)((UInt32)pSrcModuleInfo->mInterfaces \
                + (UInt32)pSrcModuleInfo);
        pCurNode = s_pModuleInfoList;
        while (pCurNode != NULL) {
            if (pCurNode->mModInfo->mInterfaceNum != 0 \
                && pInterfaceInfo[0].mIID == \
                pCurNode->mModInfo->mInterfaces[0].mIID) {
                break;
            }
            pCurNode = pCurNode->mNext;
        }
    }
    else {
        pthread_mutex_unlock(&s_moduleInfoLock);
        // No class info need to register
        return NOERROR;
    }

    if (pCurNode != NULL) {
        pthread_mutex_unlock(&s_moduleInfoLock);
        return S_ALREADY_EXISTS;
    }

    pModuleInfo = (CIModuleInfo *)malloc(pSrcModuleInfo->mTotalSize);
    if (NULL == pModuleInfo) {
        pthread_mutex_unlock(&s_moduleInfoLock);
        return E_OUT_OF_MEMORY;
    }
    RelocateModuleInfo(pSrcModuleInfo, pModuleInfo);

    pNewNode = (CIModuleInfoNode *)malloc(sizeof(CIModuleInfoNode));
    if (pNewNode == NULL) {
        free(pModuleInfo);
        pthread_mutex_unlock(&s_moduleInfoLock);
        return E_OUT_OF_MEMORY;
    }
    pNewNode->mModInfo = (CIModuleInfo *)pModuleInfo;
    pNewNode->mNext = NULL;
    if (s_pModuleInfoList == NULL) {
        s_pModuleInfoList = pNewNode;
    }
    else {
        pNewNode->mNext = s_pModuleInfoList->mNext;
        s_pModuleInfoList->mNext = pNewNode;
    }
    pthread_mutex_unlock(&s_moduleInfoLock);

    return NOERROR;
}

ECode UnregisterModuleInfo(
    /* [in] */ CIModuleInfo *pModuleInfo)
{
    CIModuleInfoNode *pCurNode, *pPreNode;

    assert(pModuleInfo != NULL);

    pthread_mutex_lock(&s_moduleInfoLock);
    pPreNode = NULL;
    pCurNode = s_pModuleInfoList;
    while (pCurNode != NULL) {
        if ((*pCurNode).mModInfo == pModuleInfo) {
            break;
        }
        pPreNode = pCurNode;
        pCurNode = pCurNode->mNext;
    }

    if (pCurNode != NULL) {
        if (pPreNode == NULL) {
            s_pModuleInfoList = pCurNode->mNext;
        }
        else {
            pPreNode->mNext = pCurNode->mNext;
        }
        pthread_mutex_unlock(&s_moduleInfoLock);
        free(pCurNode);

        return NOERROR;
    }

    pthread_mutex_unlock(&s_moduleInfoLock);
    return E_DOES_NOT_EXIST;
}

ELAPI ECO_PUBLIC LookupInterfaceInfo(
    /* [in] */ REMuid ritfid,
    /* [out] */ CIInterfaceInfo** interfaceInfo)
{
    assert(interfaceInfo != NULL);

    pthread_mutex_lock(&s_moduleInfoLock);
    CIModuleInfoNode* curNode = s_pModuleInfoList;
    while (curNode != NULL) {
        CIModuleInfo* modInfo = curNode->mModInfo;
        for (Int32 m = 0; m < modInfo->mInterfaceNum; m++) {
            if (modInfo->mInterfaces[m].mIID == ritfid) {
                *interfaceInfo = &(modInfo->mInterfaces[m]);
                pthread_mutex_unlock(&s_moduleInfoLock);
                return NOERROR;
            }
        }
        curNode = curNode->mNext;
    }
    pthread_mutex_unlock(&s_moduleInfoLock);

    return E_DOES_NOT_EXIST;
}

ECode LookupClassInfo(
    /* [in] */ REMuid rclsid,
    /* [out] */ CIClassInfo **ppClassInfo)
{
    CIModuleInfoNode *pCurNode;
    CIModuleInfo *pModInfo;
    int m;

    assert(ppClassInfo != NULL);

    pthread_mutex_lock(&s_moduleInfoLock);
    pCurNode = s_pModuleInfoList;
    while (pCurNode != NULL) {
        pModInfo = pCurNode->mModInfo;
        for (m = 0; m < pModInfo->mClassNum; m++) {
            if (pModInfo->mClasses[m].mCLSID == rclsid) {
                *ppClassInfo = &(pModInfo->mClasses[m]);
                pthread_mutex_unlock(&s_moduleInfoLock);
                return NOERROR;
            }
        }
        pCurNode = pCurNode->mNext;
    }
    pthread_mutex_unlock(&s_moduleInfoLock);

    return E_DOES_NOT_EXIST;
}

ECode LookupModuleInfo(
    /* [in] */ REMuid rclsid,
    /* [out] */ CIModuleInfo **ppModuleInfo)
{
    CIModuleInfoNode *pCurNode;
    CIModuleInfo *pModInfo;
    int m;

    assert(ppModuleInfo != NULL);

    pthread_mutex_lock(&s_moduleInfoLock);
    pCurNode = s_pModuleInfoList;
    while (pCurNode != NULL) {
        pModInfo = pCurNode->mModInfo;
        for (m = 0; m < pModInfo->mClassNum; m++) {
            if (pModInfo->mClasses[m].mCLSID == rclsid) {
                *ppModuleInfo = pModInfo;
                pthread_mutex_unlock(&s_moduleInfoLock);
                return NOERROR;
            }
        }
        pCurNode = pCurNode->mNext;
    }
    pthread_mutex_unlock(&s_moduleInfoLock);

    return E_DOES_NOT_EXIST;
}

// TODO:
void *GetUnalignedPtr(void *pPtr)
{
#ifdef _x86
    return *(void **)pPtr;
#else
    union
    {
        void    *p;
        byte_t  bytes[4];
    } u;
    u.bytes[0] = ((byte_t *)pPtr)[0];
    u.bytes[1] = ((byte_t *)pPtr)[1];
    u.bytes[2] = ((byte_t *)pPtr)[2];
    u.bytes[3] = ((byte_t *)pPtr)[3];

    return u.p;
#endif
}

ELAPI ECO_PUBLIC RegisterModuleInfo(
    /* [in] */ const String& moduleName)
{
    typedef ECode (STDCALL *CarDllGetClassObject_t)(
            REMuid clsid, REIID riid, IInterface** clsObj);

    char path[260];
    strcpy(path, moduleName.string());
#ifdef _DEBUG
    void* module = dlopen(path, RTLD_NOW);
#else
    void* module = dlopen(path, RTLD_LAZY);
#endif

    strcpy(path, "DllGetClassObject");
    CarDllGetClassObject_t func = (CarDllGetClassObject_t)dlsym(module, path);

    CIModuleInfo* modInfo;
    func(ECLSID_ClassInfo, EIID_IInterface, (IInterface**)&modInfo);

    ECode ec = RegisterModuleInfo(modInfo);
    if (FAILED(ec)) {
#if defined(_DEBUG) || defined(_MARSHAL_DEBUG)
        //ALOGD("Failed to RegisterModuleInfo in %s", moduleName.string());
#endif
    }
    return ec;
}

ECode AcquireClassInfo(
    /* [in] */ const ClassID & classId,
    /* [in] */ CIClassInfo **ppClsInfo)
{
    ECode ec;
    CIModuleInfo *pModInfo;
    void *pModule;

    typedef ECode (STDCALL *CarDllGetClassObject_t)(
            REMuid clsid, REIID riid, IInterface **ppObj);

    if (ppClsInfo == NULL) return E_INVALID_ARGUMENT;

    pModule = dlopen(classId.mUunm, RTLD_NOW);

    CarDllGetClassObject_t func = (CarDllGetClassObject_t)
            dlsym(pModule, "DllGetClassObject");

    func(ECLSID_ClassInfo, EIID_IInterface, (IInterface**)&pModInfo);

    ec = RegisterModuleInfo(pModInfo);
    if (FAILED(ec)) return ec;

    ec = LookupModuleInfo(classId.mClsid, &pModInfo);
    if (FAILED(ec)) return ec;

    for (Int32 m = 0; m < pModInfo->mClassNum; m++) {
        if (pModInfo->mClasses[m].mCLSID == classId.mClsid) {
            *ppClsInfo = &(pModInfo->mClasses[m]);
            return NOERROR;
        }
    }

    return E_DOES_NOT_EXIST;
}

ECode GetRemoteClassInfo(
    /* [in] */ const char* connectionName,
    /* [in] */ REMuid clsId,
    /* [out] */ CIClassInfo ** ppClassInfo)
{
    ECode ec;

#if !defined(__USE_REMOTE_SOCKET)

    DBusError err;
    DBusConnection *pconn = NULL;
    DBusMessage *pmsg = NULL;
    DBusMessage *pReply = NULL;
    DBusMessageIter args;
    DBusMessageIter subargs;

#endif

    UInt32 uSize = 0;
    CIModuleInfo *pModInfo;

    if (ppClassInfo == NULL) return E_INVALID_ARGUMENT;

#if !defined(__USE_REMOTE_SOCKET)

    // initialiset the errors
    dbus_error_init(&err);

    // connect to the session bus and check for errors
#ifdef _MSC_VER
	pconn = dbus_bus_get_private(DBUS_BUS_SESSION, &err);
#else
    pconn = dbus_bus_get_private(DBUS_BUS_SYSTEM, &err);
#endif
    if (dbus_error_is_set(&err)) {
        MARSHAL_DBGOUT(MSHDBG_ERROR,
                printf("Connection Error (%s).\n", err.message));
        dbus_error_free(&err);
        ec = E_FAIL;
        goto Exit;
    }

    // create a new method call and check for errors
    pmsg = dbus_message_new_method_call(connectionName, // target for the method call
                                        STUB_OBJECT_DBUS_OBJECT_PATH, // object to call on
                                        STUB_OBJECT_DBUS_INTERFACE, // interface to call on
                                        "GetClassInfo");  // method name
    if (pmsg == NULL) {
        MARSHAL_DBGOUT(MSHDBG_ERROR,
                printf("Message Null.\n"));
        ec = E_FAIL;
        goto Exit;
    }

    // send message and wait for reply
    MARSHAL_DBGOUT(MSHDBG_NORMAL, printf("Request Sent.\n"));

    pReply = dbus_connection_send_with_reply_and_block(pconn, pmsg, INT_MAX, &err);
    if (dbus_error_is_set(&err)) {
        MARSHAL_DBGOUT(MSHDBG_ERROR,
                printf("Reply Error (%s)\n", err.message));

        dbus_error_free(&err);
        ec = E_FAIL;
        goto Exit;
    }

    // read the parameters
    if (!dbus_message_iter_init(pReply, &args)) {
        MARSHAL_DBGOUT(MSHDBG_ERROR,
                printf("Message has no arguments.\n"));
        ec = E_FAIL;
        goto Exit;
    }
    if (DBUS_TYPE_ARRAY != dbus_message_iter_get_arg_type(&args)) {
        MARSHAL_DBGOUT(MSHDBG_ERROR,
                printf("Argument is not array.\n"));
        ec = E_FAIL;
        goto Exit;
    }

    dbus_message_iter_recurse(&args, &subargs);
    dbus_message_iter_get_fixed_array(&subargs, (void**)&pModInfo, (int*)&uSize);

#else

    int type;
    void *buf = NULL;
    int len;

    if (carrier_send(METHOD_GET_CLASS_INFO, NULL, 0))
        goto Exit;

    if (carrier_receive(connectionName, &type, &buf, &len))
        goto Exit;

    if (type != METHOD_GET_CLASS_INFO_REPLY)
        goto Exit;

    pModInfo = (CIModuleInfo *)buf;
    uSize = len;

#endif

    ec = RegisterModuleInfo(pModInfo);
    if (FAILED(ec)) {
        MARSHAL_DBGOUT(MSHDBG_ERROR,
                printf("Register module info fail.\n"));
        goto Exit;
    }

    if (FAILED(LookupModuleInfo(clsId, &pModInfo))) {
        MARSHAL_DBGOUT(MSHDBG_ERROR,
                printf("Find module info fail.\n"));
        goto Exit;
    }

    ec = E_DOES_NOT_EXIST;
    for (Int32 m = 0; m < pModInfo->mClassNum; m++) {
        if (pModInfo->mClasses[m].mCLSID == clsId) {
            *ppClassInfo = &(pModInfo->mClasses[m]);

            MARSHAL_DBGOUT(MSHDBG_NORMAL, printf("iid: "));
            MARSHAL_DBGOUT(MSHDBG_NORMAL,
                    DUMP_GUID((*ppClassInfo)->mCLSID));
            MARSHAL_DBGOUT(MSHDBG_NORMAL,
                    printf("UUNM: %s.\n", (*ppClassInfo)->mUunm));
            MARSHAL_DBGOUT(MSHDBG_NORMAL,
                    printf("InterfaceNumber: %d.\n", (*ppClassInfo)->mInterfaceNum));

            ec = NOERROR;
            goto Exit;
        }
    }

Exit:

#if !defined(__USE_REMOTE_SOCKET)

    if (pmsg != NULL) dbus_message_unref(pmsg);
    if (pReply != NULL) dbus_message_unref(pReply);

    // free connection
    dbus_connection_close(pconn);
    dbus_connection_unref(pconn);

#else

    free(buf);

#endif

    return ec;
}
