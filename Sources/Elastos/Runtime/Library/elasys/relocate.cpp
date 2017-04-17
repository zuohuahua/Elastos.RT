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
    /* [in] */ size_t offset)
{
#ifdef _x86
    *(size_t *)ptr += offset;
#else
    union
    {
        size_t  s;
        byte_t  bytes[4];
    } u;
    u.bytes[0] = ((byte_t *)ptr)[0];
    u.bytes[1] = ((byte_t *)ptr)[1];
    u.bytes[2] = ((byte_t *)ptr)[2];
    u.bytes[3] = ((byte_t *)ptr)[3];

    u.s += offset;

    ((byte_t *)ptr)[0] = u.bytes[0];
    ((byte_t *)ptr)[1] = u.bytes[1];
    ((byte_t *)ptr)[2] = u.bytes[2];
    ((byte_t *)ptr)[3] = u.bytes[3];
#endif
}

#ifndef INTEGER_DST
#ifdef _ELASTOS64
typedef UInt64 INTEGER_DST;
#else
typedef UInt32 INTEGER_DST;
#endif
#endif

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
        (INTEGER_DST)destModInfo->mInterfaces);
    interfaceInfo = destModInfo->mInterfaces;
    for (Int32 i = 0; i < destModInfo->mInterfaceNum; i++) {
        interfaceInfo[i].mMethods = (CIMethodInfo *) \
              ((Byte *)destModInfo + (INTEGER_DST)interfaceInfo[i].mMethods);
        methodInfo = interfaceInfo[i].mMethods;
        for (Int32 j = 0; j < interfaceInfo[i].mMethodNumMinus4; j++) {
            methodInfo[j].mParams = (CIBaseType*) \
                 ((Byte *)destModInfo + (INTEGER_DST)methodInfo[j].mParams);
        }
    }

    destModInfo->mClasses = (CIClassInfo *)((Byte *)destModInfo +
       (INTEGER_DST)destModInfo->mClasses);
    classInfo = destModInfo->mClasses;
    for (Int32 i = 0; i < destModInfo->mClassNum; i++) {
        classInfo[i].mInterfaces = (CIInterfaceInfo **) \
                ((Byte *)destModInfo + (INTEGER_DST)(classInfo[i].mInterfaces));
        interfaceInfos = classInfo[i].mInterfaces;
        for (Int32 j = 0; j < classInfo[i].mInterfaceNum; j++) {
            RelocateUnalignedPtr(interfaceInfos + j, (size_t)destModInfo);
        }
        classInfo[i].mUunm =
                (char*)((Byte *)destModInfo + (INTEGER_DST)classInfo[i].mUunm);
    }
}

CAR_INLINE void  FlatUnalignedPtr(
    /* [in] */ void *ptr,
    /* [in] */ size_t offset)
{
#ifdef _x86
    *(size_t *)ptr -= offset;
#elif defined(_arm)
    union
    {
        size_t  s;
        byte_t  bytes[4];
    } u;
    u.bytes[0] = ((byte_t *)ptr)[0];
    u.bytes[1] = ((byte_t *)ptr)[1];
    u.bytes[2] = ((byte_t *)ptr)[2];
    u.bytes[3] = ((byte_t *)ptr)[3];

    u.s -= offset;

    ((byte_t *)ptr)[0] = u.bytes[0];
    ((byte_t *)ptr)[1] = u.bytes[1];
    ((byte_t *)ptr)[2] = u.bytes[2];
    ((byte_t *)ptr)[3] = u.bytes[3];
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
            ((Byte*)destModInfo->mInterfaces - (INTEGER_DST)srcModInfo);
    interfaceInfo = (CIInterfaceInfo*)((Byte*) destModInfo->mInterfaces + \
                      (INTEGER_DST)destModInfo);

    for (i = 0; i < destModInfo->mInterfaceNum; i++) {
        interfaceInfo[i].mMethods = (CIMethodInfo *) \
              ((Byte*)interfaceInfo[i].mMethods - (INTEGER_DST)srcModInfo);

        methodInfo = (CIMethodInfo*)((Byte*)interfaceInfo[i].mMethods + \
                            (INTEGER_DST)destModInfo);
        for (j = 0; j < interfaceInfo[i].mMethodNumMinus4; j++) {
            methodInfo[j].mParams = (CIBaseType*) \
                 ((Byte*)methodInfo[j].mParams - (INTEGER_DST)srcModInfo);
        }
    }

    destModInfo->mClasses = (CIClassInfo*) \
            ((Byte*)destModInfo->mClasses - (INTEGER_DST)srcModInfo);

    classInfo = (CIClassInfo*)((Byte*)destModInfo->mClasses + (INTEGER_DST)destModInfo);
    for (i = 0; i < destModInfo->mClassNum; i++) {
        classInfo[i].mInterfaces = (CIInterfaceInfo**) \
                ((Byte*)classInfo[i].mInterfaces - (INTEGER_DST)srcModInfo);

        interfaceInfos = (CIInterfaceInfo**)((Byte*)classInfo[i].mInterfaces + \
                (INTEGER_DST)destModInfo);
        for (j = 0; j < classInfo[i].mInterfaceNum; j++) {
            FlatUnalignedPtr(interfaceInfos + j, (size_t)srcModInfo);
        }
        classInfo[i].mUunm =  \
            (char*)((Byte*)classInfo[i].mUunm - (INTEGER_DST)srcModInfo);
    }
}
