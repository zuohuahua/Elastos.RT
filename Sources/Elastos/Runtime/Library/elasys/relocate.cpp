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

#include <elatypes.h>
#include <string.h>
#include <clsinfo.h>

_ELASTOS_NAMESPACE_USING

CAR_INLINE void RelocateUnalignedPtr(
    /* [in] */ void *ptr,
    /* [in] */ uintptr_t offset)
{
#ifdef _x86
    *(uintptr_t *)ptr += offset;
#else
    union
    {
        uintptr_t s;
#ifdef _ELASTOS64
        byte_t    bytes[8];
#else
        byte_t    bytes[4];
#endif
    } u;
    u.bytes[0] = ((byte_t *)ptr)[0];
    u.bytes[1] = ((byte_t *)ptr)[1];
    u.bytes[2] = ((byte_t *)ptr)[2];
    u.bytes[3] = ((byte_t *)ptr)[3];
#ifdef _ELASTOS64
    u.bytes[4] = ((byte_t *)ptr)[4];
    u.bytes[5] = ((byte_t *)ptr)[5];
    u.bytes[6] = ((byte_t *)ptr)[6];
    u.bytes[7] = ((byte_t *)ptr)[7];
#endif

    u.s += offset;

    ((byte_t *)ptr)[0] = u.bytes[0];
    ((byte_t *)ptr)[1] = u.bytes[1];
    ((byte_t *)ptr)[2] = u.bytes[2];
    ((byte_t *)ptr)[3] = u.bytes[3];
#ifdef _ELASTOS64
    ((byte_t *)ptr)[4] = u.bytes[4];
    ((byte_t *)ptr)[5] = u.bytes[5];
    ((byte_t *)ptr)[6] = u.bytes[6];
    ((byte_t *)ptr)[7] = u.bytes[7];
#endif
#endif
}


void RelocateModuleInfo(
    /* [in] */ CIModuleInfo *srcModInfo,
    /* [out] */ CIModuleInfo *destModInfo)
{
    CIClassInfo * classInfo;
    CIInterfaceInfo ** interfaceInfos;
    CIInterfaceInfo * interfaceInfo;
    CIMethodInfo * methodInfo;


    memcpy(destModInfo, srcModInfo, srcModInfo->mTotalSize);

    destModInfo->mInterfaces = (CIInterfaceInfo*)((Byte *)destModInfo +
        (uintptr_t)destModInfo->mInterfaces);
    interfaceInfo = destModInfo->mInterfaces;

    for (Int32 i = 0; i < destModInfo->mInterfaceNum; i++) {
        interfaceInfo[i].mMethods = (CIMethodInfo *) \
              ((Byte *)destModInfo + (uintptr_t)interfaceInfo[i].mMethods);
        methodInfo = interfaceInfo[i].mMethods;
        for (Int32 j = 0; j < interfaceInfo[i].mMethodNumMinus4; j++) {
            methodInfo[j].mParams = (CIBaseType*) \
                 ((Byte *)destModInfo + (uintptr_t)methodInfo[j].mParams);
        }
    }

    destModInfo->mClasses = (CIClassInfo *)((Byte *)destModInfo +
       (uintptr_t)destModInfo->mClasses);
    classInfo = destModInfo->mClasses;
    for (Int32 i = 0; i < destModInfo->mClassNum; i++) {
        classInfo[i].mInterfaces = (CIInterfaceInfo **) \
                ((Byte *)destModInfo + (uintptr_t)(classInfo[i].mInterfaces));
        interfaceInfos = classInfo[i].mInterfaces;
        for (Int32 j = 0; j < classInfo[i].mInterfaceNum; j++) {
            RelocateUnalignedPtr(interfaceInfos + j, (uintptr_t)destModInfo);
        }
        classInfo[i].mUunm =
                (char*)((Byte *)destModInfo + (uintptr_t)classInfo[i].mUunm);
    }
}

CAR_INLINE void  FlatUnalignedPtr(
    /* [in] */ void *ptr,
    /* [in] */ uintptr_t offset)
{
#ifdef _x86
    *(uintptr_t *)ptr -= offset;
#elif defined(_arm)
    union
    {
        uintptr_t s;
#ifdef _ELASTOS64
        byte_t    bytes[8];
#else
        byte_t    bytes[4];
#endif
    } u;
    u.bytes[0] = ((byte_t *)ptr)[0];
    u.bytes[1] = ((byte_t *)ptr)[1];
    u.bytes[2] = ((byte_t *)ptr)[2];
    u.bytes[3] = ((byte_t *)ptr)[3];
#ifdef _ELASTOS64
    u.bytes[4] = ((byte_t *)ptr)[4];
    u.bytes[5] = ((byte_t *)ptr)[5];
    u.bytes[6] = ((byte_t *)ptr)[6];
    u.bytes[7] = ((byte_t *)ptr)[7];
#endif

    u.s -= offset;

    ((byte_t *)ptr)[0] = u.bytes[0];
    ((byte_t *)ptr)[1] = u.bytes[1];
    ((byte_t *)ptr)[2] = u.bytes[2];
    ((byte_t *)ptr)[3] = u.bytes[3];
#ifdef _ELASTOS64
    ((byte_t *)ptr)[4] = u.bytes[4];
    ((byte_t *)ptr)[5] = u.bytes[5];
    ((byte_t *)ptr)[6] = u.bytes[6];
    ((byte_t *)ptr)[7] = u.bytes[7];
#endif
#else
#error unsupported architecure.
#endif
}

void FlatModuleInfo(
    /* [in] */ CIModuleInfo *srcModInfo,
    /* [out] */ CIModuleInfo *destModInfo)
{
    Int32 i, j;
    CIClassInfo * classInfo;
    CIInterfaceInfo ** interfaceInfos;
    CIInterfaceInfo * interfaceInfo;
    CIMethodInfo * methodInfo;

    memcpy(destModInfo, srcModInfo, srcModInfo->mTotalSize);
    destModInfo->mInterfaces = (CIInterfaceInfo*) \
            ((Byte*)destModInfo->mInterfaces - (uintptr_t)srcModInfo);
    interfaceInfo = (CIInterfaceInfo*)((Byte*) destModInfo->mInterfaces + \
                      (uintptr_t)destModInfo);

    for (i = 0; i < destModInfo->mInterfaceNum; i++) {
        interfaceInfo[i].mMethods = (CIMethodInfo *) \
              ((Byte*)interfaceInfo[i].mMethods - (uintptr_t)srcModInfo);

        methodInfo = (CIMethodInfo*)((Byte*)interfaceInfo[i].mMethods + \
                            (uintptr_t)destModInfo);
        for (j = 0; j < interfaceInfo[i].mMethodNumMinus4; j++) {
            methodInfo[j].mParams = (CIBaseType*) \
                 ((Byte*)methodInfo[j].mParams - (uintptr_t)srcModInfo);
        }
    }

    destModInfo->mClasses = (CIClassInfo*) \
            ((Byte*)destModInfo->mClasses - (uintptr_t)srcModInfo);

    classInfo = (CIClassInfo*)((Byte*)destModInfo->mClasses + (uintptr_t)destModInfo);
    for (i = 0; i < destModInfo->mClassNum; i++) {
        classInfo[i].mInterfaces = (CIInterfaceInfo**) \
                ((Byte*)classInfo[i].mInterfaces - (uintptr_t)srcModInfo);

        interfaceInfos = (CIInterfaceInfo**)((Byte*)classInfo[i].mInterfaces + \
                (uintptr_t)destModInfo);
        for (j = 0; j < classInfo[i].mInterfaceNum; j++) {
            FlatUnalignedPtr(interfaceInfos + j, (uintptr_t)srcModInfo);
        }
        classInfo[i].mUunm =  \
            (char*)((Byte*)classInfo[i].mUunm - (uintptr_t)srcModInfo);
    }
}
