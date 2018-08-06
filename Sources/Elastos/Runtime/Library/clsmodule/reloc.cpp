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

#include <clsbase.h>

/* on 32 bits platform: sizeof(long) = sizeof(void*) = 4
 * on 64 bits platform: sizeof(long) = sizeof(void*) = 8
 */
static size_t sBase;

void MapFileDirEntry(
    /* [in] */ FileDirEntry* p)
{
    if (p->mPath) p->mPath += sBase;
}

void MapKeyValuePair(KeyValuePair* p)
{
    p->mKey += sBase;
    p->mValue += sBase;
}

void MapAnnotationDescriptor(
    /* [in] */ AnnotationDescriptor* p)
{
    p->mName += sBase;
    if (p->mNameSpace) p->mNameSpace += sBase;

    if (0 != p->mKeyValuePairCount) {
        p->mKeyValuePairs = (KeyValuePair**)((uintptr_t)p->mKeyValuePairs + sBase);

        for (int n = 0; n < p->mKeyValuePairCount; n++) {
            p->mKeyValuePairs[n] = (KeyValuePair*)((uintptr_t)p->mKeyValuePairs[n] + sBase);
            MapKeyValuePair(p->mKeyValuePairs[n]);
        }
    }
}

void MapClassDescriptor(
    /* [in] */ ClassDescriptor* p)
{
    if (0 != p->mAnnotationCount) {
        p->mAnnotations = (AnnotationDescriptor**)((uintptr_t)p->mAnnotations + sBase);

        for (int n = 0; n < p->mAnnotationCount; n++) {
            p->mAnnotations[n] = (AnnotationDescriptor*)((uintptr_t)p->mAnnotations[n] + sBase);
            MapAnnotationDescriptor(p->mAnnotations[n]);
        }
    }

    if (0 != p->mAggregateCount) {
        p->mAggrIndexes = (USHORT *)((uintptr_t)p->mAggrIndexes + sBase);
    }
    if (0 != p->mAspectCount) {
        p->mAspectIndexes = (USHORT *)((uintptr_t)p->mAspectIndexes + sBase);
    }
    if (0 != p->mClassCount) {
        p->mClassIndexes = (USHORT *)((uintptr_t)p->mClassIndexes + sBase);
    }

    if (0 != p->mInterfaceCount) {
        p->mInterfaces = (ClassInterface **)((uintptr_t)p->mInterfaces + sBase);

        for (int n = 0; n < p->mInterfaceCount; n++) {
            p->mInterfaces[n] = (ClassInterface *)((uintptr_t)p->mInterfaces[n] + sBase);
        }
    }
}

void MapClassDirEntry(
    /* [in] */ ClassDirEntry* p)
{
    p->mName += sBase;
    if (p->mNameSpace) p->mNameSpace += sBase;

    p->mDesc = (ClassDescriptor *)((uintptr_t)p->mDesc + sBase);

    MapClassDescriptor(p->mDesc);
}

void MapInterfaceConstDescriptor(
    /* [in] */ InterfaceConstDescriptor* p)
{
    p->mName += sBase;
    if (p->mType == TYPE_STRING && p->mV.mStrValue != NULL) p->mV.mStrValue += sBase;
}

void MapMethodDescriptor(
    /* [in] */ MethodDescriptor* p)
{
    p->mName += sBase;
    p->mSignature += sBase;

    if (0 != p->mAnnotationCount) {
        p->mAnnotations = (AnnotationDescriptor **)((uintptr_t)p->mAnnotations + sBase);

        for (int n = 0; n < p->mAnnotationCount; n++) {
            p->mAnnotations[n] = (AnnotationDescriptor *)((uintptr_t)p->mAnnotations[n] + sBase);
            MapAnnotationDescriptor(p->mAnnotations[n]);
        }
    }

    if (0 != p->mParamCount) {
        p->mParams = (ParamDescriptor **)((uintptr_t)p->mParams + sBase);

        for (int n = 0; n < p->mParamCount; n++) {
            p->mParams[n] = (ParamDescriptor *)((uintptr_t)p->mParams[n] + sBase);
            p->mParams[n]->mName += sBase;

            if (p->mParams[n]->mType.mNestedType) {
                p->mParams[n]->mType.mNestedType =
                        (TypeDescriptor *)((uintptr_t)p->mParams[n]->mType.mNestedType + sBase);
            }
        }
    }
}

void MapInterfaceDescriptor(
    /* [in] */ InterfaceDescriptor* p)
{
    if (0 != p->mAnnotationCount) {
        p->mAnnotations = (AnnotationDescriptor **)((uintptr_t)p->mAnnotations + sBase);

        for (int n = 0; n < p->mAnnotationCount; n++) {
            p->mAnnotations[n] = (AnnotationDescriptor *)((uintptr_t)p->mAnnotations[n] + sBase);
            MapAnnotationDescriptor(p->mAnnotations[n]);
        }
    }

    if (0 != p->mConstCount) {
        p->mConsts = (InterfaceConstDescriptor **)((uintptr_t)p->mConsts + sBase);

        for (int n = 0; n < p->mConstCount; n++) {
            p->mConsts[n] = (InterfaceConstDescriptor *)((uintptr_t)p->mConsts[n] + sBase);
            MapInterfaceConstDescriptor(p->mConsts[n]);
        }
    }

    if (0 != p->mMethodCount) {
        p->mMethods = (MethodDescriptor **)((uintptr_t)p->mMethods + sBase);

        for (int n = 0; n < p->mMethodCount; n++) {
            p->mMethods[n] = (MethodDescriptor *)((uintptr_t)p->mMethods[n] + sBase);
            MapMethodDescriptor(p->mMethods[n]);
        }
    }
}

void MapInterfaceDirEntry(
    /* [in] */ InterfaceDirEntry* p)
{
    p->mName += sBase;
    if (p->mNameSpace) p->mNameSpace += sBase;

    p->mDesc = (InterfaceDescriptor *)((uintptr_t)p->mDesc + sBase);

    MapInterfaceDescriptor(p->mDesc);
}

void MapArrayDirEntry(
    /* [in] */ ArrayDirEntry* p)
{
    if (p->mNameSpace) p->mNameSpace += sBase;

    if (p->mType.mNestedType) {
        p->mType.mNestedType = (TypeDescriptor *)((uintptr_t)p->mType.mNestedType + sBase);
    }
}

void MapStructDescriptor(
    /* [in] */ StructDescriptor* p)
{
    if (0 != p->mElementCount) {
        p->mElements = (StructElement **)((uintptr_t)p->mElements + sBase);

        for (int n = 0; n < p->mElementCount; n++) {
            p->mElements[n] = (StructElement *)((uintptr_t)p->mElements[n] + sBase);
            p->mElements[n]->mName += sBase;

            if (p->mElements[n]->mType.mNestedType) {
                p->mElements[n]->mType.mNestedType =
                        (TypeDescriptor *)((uintptr_t)p->mElements[n]->mType.mNestedType + sBase);
            }
        }
    }
}

void MapStructDirEntry(
    /* [in] */ StructDirEntry* p)
{
    p->mName += sBase;
    if (p->mNameSpace) p->mNameSpace += sBase;

    p->mDesc = (StructDescriptor *)((uintptr_t)p->mDesc + sBase);

    MapStructDescriptor(p->mDesc);
}

void MapEnumDescriptor(
    /* [in] */ EnumDescriptor* p)
{
    if (0 != p->mElementCount) {
        p->mElements = (EnumElement **)((uintptr_t)p->mElements + sBase);

        for (int n = 0; n < p->mElementCount; n++) {
            p->mElements[n] = (EnumElement *)((uintptr_t)p->mElements[n] + sBase);
            p->mElements[n]->mName += sBase;
        }
    }
}

void MapEnumDirEntry(
    /* [in] */ EnumDirEntry* p)
{
    p->mName += sBase;
    if (p->mNameSpace) p->mNameSpace += sBase;

    p->mDesc = (EnumDescriptor *)((uintptr_t)p->mDesc + sBase);

    MapEnumDescriptor(p->mDesc);
}

void MapConstDirEntry(
    /* [in] */ ConstDirEntry* p)
{
    p->mName += sBase;
    if (p->mNameSpace) p->mNameSpace += sBase;
    if (p->mType == TYPE_STRING && p->mV.mStrValue.mValue != NULL) p->mV.mStrValue.mValue += sBase;
}

void MapAliasDirEntry(
    /* [in] */ AliasDirEntry* p)
{
    p->mName += sBase;
    if (p->mNameSpace) p->mNameSpace += sBase;

    if (p->mType.mNestedType) {
        p->mType.mNestedType = (TypeDescriptor *)((uintptr_t)p->mType.mNestedType + sBase);
    }
}

void DoRelocCLS(
    /* [in] */ CLSModule* p)
{
    sBase = (size_t)p;

    p->mName += sBase;
    if (p->mUunm) p->mUunm += sBase;
    if (p->mServiceName) p->mServiceName += sBase;
    if (p->mDefinedInterfaceCount > 0) {
        p->mDefinedInterfaceIndexes = (long *)((uintptr_t)(p->mDefinedInterfaceIndexes) + sBase);
    }

    if (0 != p->mFileCount) {
        p->mFileDirs = (FileDirEntry **)((uintptr_t)p->mFileDirs + sBase);

        for (int n = 0; n < p->mFileCount; n++) {
            p->mFileDirs[n] = (FileDirEntry *)((uintptr_t)p->mFileDirs[n] + sBase);
            MapFileDirEntry(p->mFileDirs[n]);
        }
    }
    else {
        p->mFileDirs = NULL;
    }

    if (0 != p->mClassCount) {
        p->mClassDirs = (ClassDirEntry **)((uintptr_t)p->mClassDirs + sBase);

        for (int n = 0; n < p->mClassCount; n++) {
            p->mClassDirs[n] = (ClassDirEntry *)((uintptr_t)p->mClassDirs[n] + sBase);
            MapClassDirEntry(p->mClassDirs[n]);
        }
    }
    else {
        p->mClassDirs = NULL;
    }

    if (0 != p->mInterfaceCount) {
        p->mInterfaceDirs = (InterfaceDirEntry **)((uintptr_t)p->mInterfaceDirs + sBase);

        for (int n = 0; n < p->mInterfaceCount; n++) {
            p->mInterfaceDirs[n] = (InterfaceDirEntry *)((uintptr_t)p->mInterfaceDirs[n] + sBase);
            MapInterfaceDirEntry(p->mInterfaceDirs[n]);
        }
    }
    else {
        p->mInterfaceDirs = NULL;
    }

    if (0 != p->mArrayCount) {
        p->mArrayDirs = (ArrayDirEntry **)((uintptr_t)p->mArrayDirs + sBase);

        for (int n = 0; n < p->mArrayCount; n++) {
            p->mArrayDirs[n] = (ArrayDirEntry *)((uintptr_t)p->mArrayDirs[n] + sBase);
            MapArrayDirEntry(p->mArrayDirs[n]);
        }
    }
    else {
        p->mArrayDirs = NULL;
    }

    if (0 != p->mStructCount) {
        p->mStructDirs = (StructDirEntry **)((uintptr_t)p->mStructDirs + sBase);

        for (int n = 0; n < p->mStructCount; n++) {
            p->mStructDirs[n] = (StructDirEntry *)((uintptr_t)p->mStructDirs[n] + sBase);
            MapStructDirEntry(p->mStructDirs[n]);
        }
    }
    else {
        p->mStructDirs = NULL;
    }

    if (0 != p->mEnumCount) {
        p->mEnumDirs = (EnumDirEntry **)((uintptr_t)p->mEnumDirs + sBase);

        for (int n = 0; n < p->mEnumCount; n++) {
            p->mEnumDirs[n] = (EnumDirEntry *)((uintptr_t)p->mEnumDirs[n] + sBase);
            MapEnumDirEntry(p->mEnumDirs[n]);
        }
    }
    else {
        p->mEnumDirs = NULL;
    }

    if (0 != p->mConstCount) {
        p->mConstDirs = (ConstDirEntry **)((uintptr_t)p->mConstDirs + sBase);

        for (int n = 0; n < p->mConstCount; n++) {
            p->mConstDirs[n] = (ConstDirEntry *)((uintptr_t)p->mConstDirs[n] + sBase);
            MapConstDirEntry(p->mConstDirs[n]);
        }
    }
    else {
        p->mConstDirs = NULL;
    }

    if (0 != p->mAliasCount) {
        p->mAliasDirs = (AliasDirEntry **)((uintptr_t)p->mAliasDirs + sBase);

        for (int n = 0; n < p->mAliasCount; n++) {
            p->mAliasDirs[n] = (AliasDirEntry *)((uintptr_t)p->mAliasDirs[n] + sBase);
            MapAliasDirEntry(p->mAliasDirs[n]);
        }
    }
    else {
        p->mAliasDirs = NULL;
    }

    if (0 != p->mLibraryCount) {
        p->mLibraryNames = (char **)((uintptr_t)p->mLibraryNames + sBase);
        for (int n = 0; n < p->mLibraryCount; n++) {
            p->mLibraryNames[n] += sBase;
        }
    }
    else {
        p->mLibraryNames = NULL;
    }
}

int RelocFlattedCLS(
    /* [in] */ const void* src,
    /* [in] */ long size,
    /* [out] */ CLSModule** outDest)
{
    CLSModule* srcModule = (CLSModule *)src;

    CLSModule* destModule = (CLSModule *)new char[srcModule->mSize];
    if (!destModule) _ReturnError(CLSError_OutOfMemory);

    if (srcModule->mAttribs & CARAttrib_compress) {
        long n = UncompressCLS(src, size, destModule);
        if (n != srcModule->mSize) {
            delete [] (char *)destModule;
            _ReturnError(CLSError_FormatSize);
        }
    }
    else {
        memcpy(destModule, srcModule, size);
    }

    DoRelocCLS(destModule);
    destModule->mAttribs |= CARAttrib_inheap;

    *outDest = destModule;
    _ReturnOK(CLS_NoError);
}

int DisposeFlattedCLS(
    /* [in] */ void* dest)
{
    if (((CLSModule *)dest)->mAttribs & CARAttrib_inheap) {
        delete [] (char *)dest;
    }
    _ReturnOK(CLS_NoError);
}
