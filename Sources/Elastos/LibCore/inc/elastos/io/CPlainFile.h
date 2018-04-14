//=========================================================================
// Copyright (C) 2018 The Elastos Open Source Project
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

#ifndef __ELASTOS_IO_CPLAINFILE_H__
#define __ELASTOS_IO_CPLAINFILE_H__

#include "_Elastos_IO_CPlainFile.h"
#include "elastos/core/Object.h"

namespace Elastos {
namespace IO {

/**
 * An representation of a file system identified by a pathname.
 * The pathname must be absolute (relative to the root directory of the file system)
 *
 * The actual file referenced by a CPlainFile may or may not exist. It may
 * also, despite the name CPlainFile, be a directory or other regular file.
 */
CarClass(CPlainFile)
    , public Object
    , public IPlainFile
{
public:
    CPlainFile();

    CAR_OBJECT_DECL();

    CAR_INTERFACE_DECL();

    CARAPI constructor(
        /* [in] */ const String& dir);

    CARAPI constructor(
        /* [in] */ const String& dir,
        /* [in] */ const String& name);

    CARAPI Exists(
        /* [out] */ Boolean* exists);

    CARAPI IsDir(
        /* [out] */ Boolean* isDir);

    CARAPI IsFile(
        /* [out] */ Boolean* isFile);

    CARAPI Delete();

    CARAPI Mkdir();

    CARAPI Mkdirs();

    CARAPI Write(
        /* [in] */ const String& content);

    CARAPI Read(
        /* [out] */ String* content);

    CARAPI GetPath(
        /* [out] */ String* path);

private:
    CARAPI_(Boolean) _IsFile(
        /* [in] */ const char* path);

    CARAPI_(Boolean) _IsDir(
        /* [in] */ const char* path);

    CARAPI _Delete(
        /* [in] */ const char* path);

    CARAPI_(Boolean) _IsSpecialDir(
        /* [in] */ const char* path);

    CARAPI_(Boolean) _IsFileExist(
        /* [in] */ const char* path);

    CARAPI_(Boolean) _IsDirExist(
        /* [in] */ const char* path);

    CARAPI_(Boolean) _Mkdirs(
        /* [in] */ const String& path);

    CARAPI_(String) _GetAbsolutePath(
        /* [in] */ const String& dir,
        /* [in] */ const String& name);

private:
    String mDir;
    String mName;
};

} // namespace IO
} // namespace Elastos

#endif // __ELASTOS_IO_CPLAINFILE_H__
