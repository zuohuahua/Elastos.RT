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

#ifndef __AJUSTADD_H__
#define __AJUSTADD_H__

#ifndef INTEGER_DST
#ifdef _ELASTOS64
typedef Elastos::UInt64 INTEGER_DST;
#else
typedef Elastos::UInt32 INTEGER_DST;
#endif
#endif

_ELASTOS_NAMESPACE_USING

inline ClassDirEntry* getClassDirAddr(
    /* [in] */ long base,
    /* [in] */ ClassDirEntry** dir,
    /* [in] */ Int32 index)
{
    dir = (ClassDirEntry**)((INTEGER_DST)dir + base);
    return (ClassDirEntry*)((INTEGER_DST)dir[index] + base);
}

inline InterfaceDirEntry* getInterfaceDirAddr(
    /* [in] */ long base,
    /* [in] */ InterfaceDirEntry** dir,
    /* [in] */ Int32 index)
{
    dir = (InterfaceDirEntry**)((INTEGER_DST)dir + base);
    return (InterfaceDirEntry*)((INTEGER_DST)dir[index] + base);
}

inline StructDirEntry* getStructDirAddr(
    /* [in] */ long base,
    /* [in] */ StructDirEntry** dir,
    /* [in] */ Int32 index)
{
    dir = (StructDirEntry**)((INTEGER_DST)dir + base);
    return (StructDirEntry*)((INTEGER_DST)dir[index] + base);
}

inline EnumDirEntry* getEnumDirAddr(
    /* [in] */ long base,
    /* [in] */ EnumDirEntry** dir,
    /* [in] */ Int32 index)
{
    dir = (EnumDirEntry**)((INTEGER_DST)dir + base);
    return (EnumDirEntry*)((INTEGER_DST)dir[index] + base);
}

inline AliasDirEntry* getAliasDirAddr(
    /* [in] */ long base,
    /* [in] */ AliasDirEntry** dir,
    /* [in] */ Int32 index)
{
    dir = (AliasDirEntry**)((INTEGER_DST)dir + base);
    return (AliasDirEntry*)((INTEGER_DST)dir[index] + base);
}

inline ArrayDirEntry* getArrayDirAddr(
    /* [in] */ long base,
    /* [in] */ ArrayDirEntry** dir,
    /* [in] */ Int32 index)
{
    dir = (ArrayDirEntry**)((INTEGER_DST)dir + base);
    return (ArrayDirEntry*)((INTEGER_DST)dir[index] + base);
}

inline ConstDirEntry* getConstDirAddr(
    /* [in] */ long base,
    /* [in] */ ConstDirEntry** dir,
    /* [in] */ Int32 index)
{
    dir = (ConstDirEntry**)((INTEGER_DST)dir + base);
    return (ConstDirEntry*)((INTEGER_DST)dir[index] + base);
}

inline AnnotationDescriptor* getAnnotationDescAddr(
    /* [in] */ size_t base,
    /* [in] */ AnnotationDescriptor** desc,
    /* [in] */ Int32 index)
{
    desc = (AnnotationDescriptor**)((INTEGER_DST)desc + base);
    return (AnnotationDescriptor*)((INTEGER_DST)desc[index] + base);
}

inline MethodDescriptor* getMethodDescAddr(
    /* [in] */ long base,
    /* [in] */ MethodDescriptor** desc,
    /* [in] */ Int32 index)
{
    desc = (MethodDescriptor**)((INTEGER_DST)desc + base);
    return (MethodDescriptor*)((INTEGER_DST)desc[index] + base);
}

inline ParamDescriptor* getParamDescAddr(
    /* [in] */ long base,
    /* [in] */ ParamDescriptor** desc,
    /* [in] */ Int32 index)
{
    desc = (ParamDescriptor**)((INTEGER_DST)desc + base);
    return (ParamDescriptor*)((INTEGER_DST)desc[index] + base);
}

inline StructElement* getStructElementAddr(
    /* [in] */ long base,
    /* [in] */ StructElement** element,
    /* [in] */ Int32 index)
{
    element = (StructElement**)((INTEGER_DST)element + base);
    return (StructElement*)((INTEGER_DST)element[index] + base);
}

inline EnumElement* getEnumElementAddr(
    /* [in] */ long base,
    /* [in] */ EnumElement** element,
    /* [in] */ Int32 index)
{
    element = (EnumElement**)((INTEGER_DST)element + base);
    return (EnumElement*)((INTEGER_DST)element[index] + base);
}

inline ClassInterface* getCIFAddr(
    /* [in] */ long base,
    /* [in] */ ClassInterface** clsInterface,
    /* [in] */ Int32 index)
{
    clsInterface = (ClassInterface**)((INTEGER_DST)clsInterface + base);
    return (ClassInterface*)((INTEGER_DST)clsInterface[index] + base);
}

inline char* getLibNameAddr(
    /* [in] */ long base,
    /* [in] */ char** libName,
    /* [in] */ Int32 index)
{
    libName = (char**)((INTEGER_DST)libName + base);
    return (char*)((INTEGER_DST)libName[index] + base);
}

inline char* adjustNameAddr(
    /* [in] */ long base,
    /* [in] */ char* name)
{
    return name ? name + base : name;
}

inline USHORT* adjustIndexsAddr(
    /* [in] */ long base,
    /* [in] */ USHORT* indexs)
{
    return indexs ? (USHORT*)((PByte)indexs + base) : indexs;
}

inline ClassDescriptor* adjustClassDescAddr(
    /* [in] */ long base,
    /* [in] */ ClassDescriptor* desc)
{
    return desc ? (ClassDescriptor*)((PByte)desc + base) : desc;
}

inline InterfaceDescriptor* adjustInterfaceDescAddr(
    /* [in] */ long base,
    /* [in] */ InterfaceDescriptor* desc)
{
    return desc ? (InterfaceDescriptor*)((PByte)desc + base) : desc;
}

inline MethodDescriptor* adjustMethodDescAddr(
    /* [in] */ long base,
    /* [in] */ MethodDescriptor* desc)
{
    return desc ? (MethodDescriptor*)((PByte)desc + base) : desc;
}

inline ParamDescriptor* adjustParamDescAddr(
    /* [in] */ long base,
    /* [in] */ ParamDescriptor* desc)
{
    return desc ? (ParamDescriptor*)((PByte)desc + base) : desc;
}

inline StructDescriptor* adjustStructDescAddr(
    /* [in] */ long base,
    /* [in] */ StructDescriptor* desc)
{
    return desc ? (StructDescriptor*)((PByte)desc + base) : desc;
}

inline EnumDescriptor* adjustEnumDescAddr(
    /* [in] */ long base,
    /* [in] */ EnumDescriptor* desc)
{
    return desc ? (EnumDescriptor*)((PByte)desc + base) : desc;
}

inline TypeDescriptor* adjustTypeAddr(
    /* [in] */ long base,
    /* [in] */ TypeDescriptor* desc)
{
    return desc ? (TypeDescriptor*)((PByte)desc + base) : desc;
}

inline TypeDescriptor* adjustNestedTypeAddr(
    /* [in] */ long base,
    /* [in] */ TypeDescriptor* nestedType)
{
    return nestedType ?
            (TypeDescriptor*)((PByte)nestedType + base) : nestedType;
}

#endif // __AJUSTADD_H__
