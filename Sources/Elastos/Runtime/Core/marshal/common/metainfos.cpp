//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#include <pthread.h>
#include <dlfcn.h>
#include <stdio.h>
#include "elastos.h"
#include "clsinfo.h"
#include "marshal.h"
//#include <cutils/log.h>

_ELASTOS_NAMESPACE_USING

void RelocateModuleInfo(
    /* [in] */ CIModuleInfo* pSrcModInfo,
    /* [out] */ CIModuleInfo* pDestModInfo);

static CIModuleInfoNode* s_pModuleInfoList = NULL;

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
    /* [in] */ CIModuleInfo* pSrcModuleInfo)
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
        pClassInfo = (CIClassInfo *)((uintptr_t)pSrcModuleInfo->mClasses \
                + (uintptr_t)pSrcModuleInfo);
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
        pInterfaceInfo = (CIInterfaceInfo *)((uintptr_t)pSrcModuleInfo->mInterfaces \
                + (uintptr_t)pSrcModuleInfo);
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
void *GetUnalignedPtr(void* pPtr)
{
#ifdef _x86
    return *(void **)pPtr;
#else
    union
    {
        void    *p;
#ifdef _ELASTOS64
        byte_t  bytes[8];
#else
        byte_t  bytes[4];
#endif
    } u;
    u.bytes[0] = ((byte_t *)pPtr)[0];
    u.bytes[1] = ((byte_t *)pPtr)[1];
    u.bytes[2] = ((byte_t *)pPtr)[2];
    u.bytes[3] = ((byte_t *)pPtr)[3];
#ifdef _ELASTOS64
    u.bytes[4] = ((byte_t *)pPtr)[4];
    u.bytes[5] = ((byte_t *)pPtr)[5];
    u.bytes[6] = ((byte_t *)pPtr)[6];
    u.bytes[7] = ((byte_t *)pPtr)[7];
#endif

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
    /* [in] */ const ClassID& classId,
    /* [out] */ CIClassInfo** ppClsInfo)
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

