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

#ifndef INTEGER_DST
#if (WORD_WIDE == 8)
typedef Elastos::UInt64 INTEGER_DST;
#else
typedef Elastos::UInt32 INTEGER_DST;
#endif
#endif

/* on 32 bits platform: sizeof(long) = sizeof(void*) = 4
 * on 64 bits platform: sizeof(long) = sizeof(void*) = 8
 */
static long sBase;

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
        p->mKeyValuePairs = (KeyValuePair**)((INTEGER_DST)p->mKeyValuePairs + sBase);

        for (int n = 0; n < p->mKeyValuePairCount; n++) {
            p->mKeyValuePairs[n] = (KeyValuePair*)((INTEGER_DST)p->mKeyValuePairs[n] + sBase);
            MapKeyValuePair(p->mKeyValuePairs[n]);
        }
    }
}

void MapClassDescriptor(
    /* [in] */ ClassDescriptor* p)
{
    if (0 != p->mAnnotationCount) {
        p->mAnnotations = (AnnotationDescriptor**)((INTEGER_DST)p->mAnnotations + sBase);

        for (int n = 0; n < p->mAnnotationCount; n++) {
            p->mAnnotations[n] = (AnnotationDescriptor*)((INTEGER_DST)p->mAnnotations[n] + sBase);
            MapAnnotationDescriptor(p->mAnnotations[n]);
        }
    }

    if (0 != p->mAggregateCount) {
        p->mAggrIndexes = (USHORT *)((INTEGER_DST)p->mAggrIndexes + sBase);
    }
    if (0 != p->mAspectCount) {
        p->mAspectIndexes = (USHORT *)((INTEGER_DST)p->mAspectIndexes + sBase);
    }
    if (0 != p->mClassCount) {
        p->mClassIndexes = (USHORT *)((INTEGER_DST)p->mClassIndexes + sBase);
    }

    if (0 != p->mInterfaceCount) {
        p->mInterfaces = (ClassInterface **)((INTEGER_DST)p->mInterfaces + sBase);

        for (int n = 0; n < p->mInterfaceCount; n++) {
            p->mInterfaces[n] = (ClassInterface *)((INTEGER_DST)p->mInterfaces[n] + sBase);
        }
    }
}

void MapClassDirEntry(
    /* [in] */ ClassDirEntry* p)
{
    p->mName += sBase;
    if (p->mNameSpace) p->mNameSpace += sBase;

    p->mDesc = (ClassDescriptor *)((INTEGER_DST)p->mDesc + sBase);

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
        p->mAnnotations = (AnnotationDescriptor **)((INTEGER_DST)p->mAnnotations + sBase);

        for (int n = 0; n < p->mAnnotationCount; n++) {
            p->mAnnotations[n] = (AnnotationDescriptor *)((INTEGER_DST)p->mAnnotations[n] + sBase);
            MapAnnotationDescriptor(p->mAnnotations[n]);
        }
    }

    if (0 != p->mParamCount) {
        p->mParams = (ParamDescriptor **)((INTEGER_DST)p->mParams + sBase);

        for (int n = 0; n < p->mParamCount; n++) {
            p->mParams[n] = (ParamDescriptor *)((INTEGER_DST)p->mParams[n] + sBase);
            p->mParams[n]->mName += sBase;

            if (p->mParams[n]->mType.mNestedType) {
                p->mParams[n]->mType.mNestedType =
                        (TypeDescriptor *)((INTEGER_DST)p->mParams[n]->mType.mNestedType + sBase);
            }
        }
    }
}

void MapInterfaceDescriptor(
    /* [in] */ InterfaceDescriptor* p)
{
    if (0 != p->mAnnotationCount) {
        p->mAnnotations = (AnnotationDescriptor **)((INTEGER_DST)p->mAnnotations + sBase);

        for (int n = 0; n < p->mAnnotationCount; n++) {
            p->mAnnotations[n] = (AnnotationDescriptor *)((INTEGER_DST)p->mAnnotations[n] + sBase);
            MapAnnotationDescriptor(p->mAnnotations[n]);
        }
    }

    if (0 != p->mConstCount) {
        p->mConsts = (InterfaceConstDescriptor **)((INTEGER_DST)p->mConsts + sBase);

        for (int n = 0; n < p->mConstCount; n++) {
            p->mConsts[n] = (InterfaceConstDescriptor *)((INTEGER_DST)p->mConsts[n] + sBase);
            MapInterfaceConstDescriptor(p->mConsts[n]);
        }
    }

    if (0 != p->mMethodCount) {
        p->mMethods = (MethodDescriptor **)((INTEGER_DST)p->mMethods + sBase);

        for (int n = 0; n < p->mMethodCount; n++) {
            p->mMethods[n] = (MethodDescriptor *)((INTEGER_DST)p->mMethods[n] + sBase);
            MapMethodDescriptor(p->mMethods[n]);
        }
    }
}

void MapInterfaceDirEntry(
    /* [in] */ InterfaceDirEntry* p)
{
    p->mName += sBase;
    if (p->mNameSpace) p->mNameSpace += sBase;

    p->mDesc = (InterfaceDescriptor *)((INTEGER_DST)p->mDesc + sBase);

    MapInterfaceDescriptor(p->mDesc);
}

void MapArrayDirEntry(
    /* [in] */ ArrayDirEntry* p)
{
    if (p->mNameSpace) p->mNameSpace += sBase;

    if (p->mType.mNestedType) {
        p->mType.mNestedType = (TypeDescriptor *)((INTEGER_DST)p->mType.mNestedType + sBase);
    }
}

void MapStructDescriptor(
    /* [in] */ StructDescriptor* p)
{
    if (0 != p->mElementCount) {
        p->mElements = (StructElement **)((INTEGER_DST)p->mElements + sBase);

        for (int n = 0; n < p->mElementCount; n++) {
            p->mElements[n] = (StructElement *)((INTEGER_DST)p->mElements[n] + sBase);
            p->mElements[n]->mName += sBase;

            if (p->mElements[n]->mType.mNestedType) {
                p->mElements[n]->mType.mNestedType =
                        (TypeDescriptor *)((INTEGER_DST)p->mElements[n]->mType.mNestedType + sBase);
            }
        }
    }
}

void MapStructDirEntry(
    /* [in] */ StructDirEntry* p)
{
    p->mName += sBase;
    if (p->mNameSpace) p->mNameSpace += sBase;

    p->mDesc = (StructDescriptor *)((INTEGER_DST)p->mDesc + sBase);

    MapStructDescriptor(p->mDesc);
}

void MapEnumDescriptor(
    /* [in] */ EnumDescriptor* p)
{
    if (0 != p->mElementCount) {
        p->mElements = (EnumElement **)((INTEGER_DST)p->mElements + sBase);

        for (int n = 0; n < p->mElementCount; n++) {
            p->mElements[n] = (EnumElement *)((INTEGER_DST)p->mElements[n] + sBase);
            p->mElements[n]->mName += sBase;
        }
    }
}

void MapEnumDirEntry(
    /* [in] */ EnumDirEntry* p)
{
    p->mName += sBase;
    if (p->mNameSpace) p->mNameSpace += sBase;

    p->mDesc = (EnumDescriptor *)((INTEGER_DST)p->mDesc + sBase);

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
        p->mType.mNestedType = (TypeDescriptor *)((INTEGER_DST)p->mType.mNestedType + sBase);
    }
}

void DoRelocCLS(
    /* [in] */ CLSModule* p)
{
    sBase = (long)p;

    p->mName += sBase;
    if (p->mUunm) p->mUunm += sBase;
    if (p->mServiceName) p->mServiceName += sBase;
    if (p->mDefinedInterfaceCount > 0) {
        p->mDefinedInterfaceIndexes = (int *)((INTEGER_DST)(p->mDefinedInterfaceIndexes) + sBase);
    }

    if (0 != p->mFileCount) {
        p->mFileDirs = (FileDirEntry **)((INTEGER_DST)p->mFileDirs + sBase);

        for (int n = 0; n < p->mFileCount; n++) {
            p->mFileDirs[n] = (FileDirEntry *)((INTEGER_DST)p->mFileDirs[n] + sBase);
            MapFileDirEntry(p->mFileDirs[n]);
        }
    }
    else {
        p->mFileDirs = NULL;
    }

    if (0 != p->mClassCount) {
        p->mClassDirs = (ClassDirEntry **)((INTEGER_DST)p->mClassDirs + sBase);

        for (int n = 0; n < p->mClassCount; n++) {
            p->mClassDirs[n] = (ClassDirEntry *)((INTEGER_DST)p->mClassDirs[n] + sBase);
            MapClassDirEntry(p->mClassDirs[n]);
        }
    }
    else {
        p->mClassDirs = NULL;
    }

    if (0 != p->mInterfaceCount) {
        p->mInterfaceDirs = (InterfaceDirEntry **)((INTEGER_DST)p->mInterfaceDirs + sBase);

        for (int n = 0; n < p->mInterfaceCount; n++) {
            p->mInterfaceDirs[n] = (InterfaceDirEntry *)((INTEGER_DST)p->mInterfaceDirs[n] + sBase);
            MapInterfaceDirEntry(p->mInterfaceDirs[n]);
        }
    }
    else {
        p->mInterfaceDirs = NULL;
    }

    if (0 != p->mArrayCount) {
        p->mArrayDirs = (ArrayDirEntry **)((INTEGER_DST)p->mArrayDirs + sBase);

        for (int n = 0; n < p->mArrayCount; n++) {
            p->mArrayDirs[n] = (ArrayDirEntry *)((INTEGER_DST)p->mArrayDirs[n] + sBase);
            MapArrayDirEntry(p->mArrayDirs[n]);
        }
    }
    else {
        p->mArrayDirs = NULL;
    }

    if (0 != p->mStructCount) {
        p->mStructDirs = (StructDirEntry **)((INTEGER_DST)p->mStructDirs + sBase);

        for (int n = 0; n < p->mStructCount; n++) {
            p->mStructDirs[n] = (StructDirEntry *)((INTEGER_DST)p->mStructDirs[n] + sBase);
            MapStructDirEntry(p->mStructDirs[n]);
        }
    }
    else {
        p->mStructDirs = NULL;
    }

    if (0 != p->mEnumCount) {
        p->mEnumDirs = (EnumDirEntry **)((INTEGER_DST)p->mEnumDirs + sBase);

        for (int n = 0; n < p->mEnumCount; n++) {
            p->mEnumDirs[n] = (EnumDirEntry *)((INTEGER_DST)p->mEnumDirs[n] + sBase);
            MapEnumDirEntry(p->mEnumDirs[n]);
        }
    }
    else {
        p->mEnumDirs = NULL;
    }

    if (0 != p->mConstCount) {
        p->mConstDirs = (ConstDirEntry **)((INTEGER_DST)p->mConstDirs + sBase);

        for (int n = 0; n < p->mConstCount; n++) {
            p->mConstDirs[n] = (ConstDirEntry *)((INTEGER_DST)p->mConstDirs[n] + sBase);
            MapConstDirEntry(p->mConstDirs[n]);
        }
    }
    else {
        p->mConstDirs = NULL;
    }

    if (0 != p->mAliasCount) {
        p->mAliasDirs = (AliasDirEntry **)((INTEGER_DST)p->mAliasDirs + sBase);

        for (int n = 0; n < p->mAliasCount; n++) {
            p->mAliasDirs[n] = (AliasDirEntry *)((INTEGER_DST)p->mAliasDirs[n] + sBase);
            MapAliasDirEntry(p->mAliasDirs[n]);
        }
    }
    else {
        p->mAliasDirs = NULL;
    }

    if (0 != p->mLibraryCount) {
        p->mLibraryNames = (char **)((INTEGER_DST)p->mLibraryNames + sBase);
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
    /* [in] */ int size,
    /* [out] */ CLSModule** outDest)
{
    CLSModule* srcModule = (CLSModule *)src;

    CLSModule* destModule = (CLSModule *)new char[srcModule->mSize];
    if (!destModule) _ReturnError(CLSError_OutOfMemory);

    if (srcModule->mAttribs & CARAttrib_compress) {
        int n = UncompressCLS(src, size, destModule);
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
