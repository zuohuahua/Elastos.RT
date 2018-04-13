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
 * An immutable arbitrary-precision signed decimal.
 *
 * <p>A value is represented by an arbitrary-precision "unscaled value" and a signed 32-bit "scale",
 * combined thus: {@code unscaled * 10<sup>-scale</sup>}. See {@link #unscaledValue} and {@link #scale}.
 *
 * <p>Most operations allow you to supply a {@link MathContext} to specify a desired rounding mode.
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
        /* [in] */ const String& path);

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

    CARAPI_(void) _GetFilePath(
        /* [in] */ const char* path,
        /* [in] */ const char* file_name,
        /* [in] */ char *file_path);

    CARAPI_(Boolean) _IsSpecialDir(
        /* [in] */ const char* path);

    CARAPI_(Boolean) _IsFileExist(
        /* [in] */ const char* path);

    CARAPI_(Boolean) _IsDirExist(
        /* [in] */ const char* path);

    CARAPI_(Boolean) _Mkdirs(
        /* [in] */ const String& path);

    CARAPI_(Boolean) _CreateFile(
        /* [in] */ const char* path,
        /* [in] */ const char* fileName);

    //以追加的方式写入文件
    bool write_file(const char *fileName,const char *content) {
        FILE *fp;
        fp = fopen(fileName, "a+");
        if (NULL == fp) {
            return FALSE;
        }
        if( fwrite(content, strlen(content), 1, fp)!=1)
             return FALSE;
        fclose (fp);
        return true;
    }

private:
    String mPath;
};

} // namespace IO
} // namespace Elastos

#endif // __ELASTOS_IO_CPLAINFILE_H__
