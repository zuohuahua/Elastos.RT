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

#include "elastos/io/CPlainFile.h"
#include "elastos/core/StringBuilder.h"
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <sys/types.h>
#include <fcntl.h>
#include <assert.h>

using Elastos::Core::StringBuilder;

#ifdef _android
#include <android/log.h>
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, "PlainFile", __VA_ARGS__)
#else
#define LOGD printf
#endif

namespace Elastos {
namespace IO {

#ifndef VALIDATE_NOT_NULL
#define VALIDATE_NOT_NULL(x) if (!x) { return E_INVALID_ARGUMENT; }
#endif

static char sSeparatorChar = '/';

CAR_OBJECT_IMPL(CPlainFile)
CAR_INTERFACE_IMPL(CPlainFile, Object, IPlainFile)
CPlainFile::CPlainFile()
{}

ECode CPlainFile::constructor(
    /* [in] */ const String& dir)
{
    return constructor(dir, String(NULL));
}

ECode CPlainFile::constructor(
    /* [in] */ const String& dir,
    /* [in] */ const String& name)
{
    if (dir.IsNullOrEmpty()) {
        return E_INVALID_ARGUMENT;
    }

    mDir = dir;
    mName = name;
    return NOERROR;
}

ECode CPlainFile::Exists(
    /* [out] */ Boolean* exists)
{
    VALIDATE_NOT_NULL(exists);
    // The result is directory.
    if (mName.IsNullOrEmpty() && _IsDir(mDir)) {
        *exists = TRUE;
        return NOERROR;
    }

    // Real file.
    String absolute = _GetAbsolutePath(mDir, mName);
    Int32 rc = access(absolute.string(), F_OK);
    //rc = -1: Don't exist or hasn't the permission
    *exists = (rc == 0);
    return NOERROR;
}

ECode CPlainFile::IsDir(
    /* [out] */ Boolean* isDir)
{
    VALIDATE_NOT_NULL(isDir);
    *isDir = _IsDir(mDir.string());

    return NOERROR;
}

ECode CPlainFile::IsFile(
    /* [out] */ Boolean* isFile)
{
    VALIDATE_NOT_NULL(isFile);
    // At least, it's a directory.
    if (mName.IsNullOrEmpty()) {
        *isFile = FALSE;
        return NOERROR;
    }

    String absolute = _GetAbsolutePath(mDir, mName);
    *isFile = _IsFile(absolute.string());

    return NOERROR;
}

ECode CPlainFile::Delete()
{
    if (!mName.IsNullOrEmpty()) {
        String absolute = _GetAbsolutePath(mDir, mName);
        remove(absolute.string());
        return NOERROR;
    }

    return _Delete(mDir.string());
}

ECode CPlainFile::_Delete(
    /* [in] */ const char* path)
{
    if(_IsFile(path)) {
        remove(path);
        return NOERROR;
    }

    DIR *dir = NULL;
    dirent *dir_info = NULL;
    if(_IsDir(path)) {
        if((dir = opendir(path)) == NULL) {
            return NOERROR;
        }

        while((dir_info = readdir(dir)) != NULL) {
            if(_IsSpecialDir(dir_info->d_name)) {
                continue;
            }

            String absolute = _GetAbsolutePath(String(path), String(dir_info->d_name));
            _Delete(absolute.string());
            rmdir(absolute.string());
        }

        // Need closedir?
        // closedir(path);
    }

    return NOERROR;
}

ECode CPlainFile::Mkdir()
{
    if (mkdir(mDir.string(), S_IRWXU) == -1) {
        return E_INVALID_ARGUMENT;
    }
    return NOERROR;
}

ECode CPlainFile::Mkdirs()
{
    if(_Mkdirs(mDir)) {
        return NOERROR;
    }

    return E_INVALID_ARGUMENT;
}

ECode CPlainFile::Write(
    /* [in] */ const String& content)
{
    if (mName.IsNullOrEmpty()) {
        LOGD("[Write] : (This path is a directory which can't write data.), Line=[%d].\n", __LINE__);
        return E_INVALID_ARGUMENT;
    }

    // Mkdir using the mDir.
    _Mkdirs(mDir);
    if (!_IsDir(mDir.string())) {
        LOGD("[Write] : (The file's directory may be invalid), Line=[%d].\n", __LINE__);
        return E_INVALID_ARGUMENT;
    }

    String real = _GetAbsolutePath(mDir, mName);
    FILE *fp = fopen(real.string(), "a+");
    if (NULL == fp) {
        LOGD("[Write] : (Open the file:[%s] failed.), Line=[%d].\n", real.string(), __LINE__);
        return E_INVALID_ARGUMENT;
    }

    if(fwrite(content, strlen(content), 1, fp) != 1) {
        fclose (fp);
        LOGD("[Write] : (Write the file:[%s] failed.), Line=[%d].\n", real.string(), __LINE__);
        return E_INVALID_ARGUMENT;
    }

    fclose (fp);
    return NOERROR;
}

ECode CPlainFile::Read(
    /* [out] */ String* content)
{
    VALIDATE_NOT_NULL(content);
    *content = NULL;

    if (mName.IsNullOrEmpty()) {
        LOGD("[Read] : (This path is a directory which can't read data.), Line=[%d].\n", __LINE__);
        return E_INVALID_ARGUMENT;
    }

    String real = _GetAbsolutePath(mDir, mName);
    FILE *fp = fopen(real.string(), "rt");
    if (NULL == fp) {
        LOGD("[Read] : (Open the file:[%s] failed.), Line=[%d].\n", real.string(), __LINE__);
        return E_INVALID_ARGUMENT;
    }

    //Read data.
    static const Int32 LEN = 512;
    char buffer[LEN] = {0};
    Int32 size = 0;
    StringBuilder sb;
    while ((size = fread(buffer, sizeof(char), LEN, fp)) > 0) {
        sb.Append(buffer);
    }

    fclose (fp);

    return sb.ToString(content);
}

ECode CPlainFile::GetPath(
    /* [out] */ String* path)
{
    VALIDATE_NOT_NULL(path);
    if (mName.IsNullOrEmpty()) {
        *path = mDir;
        return NOERROR;
    }

    *path = _GetAbsolutePath(mDir, mName);
    return NOERROR;
}

Boolean CPlainFile::_IsDir(
    /* [in] */ const char* path)
{
    struct stat statbuf;
    if(lstat(path, &statbuf) == 0) {
        return S_ISDIR(statbuf.st_mode) != 0;
    }
    return FALSE;
}

Boolean CPlainFile::_IsFile(
    /* [in] */ const char* path)
{
    struct stat statbuf;
    if(lstat(path, &statbuf) == 0) {
        // Check whether the file is a regular file.
        return S_ISREG(statbuf.st_mode) != 0;
    }

    return FALSE;
}

Boolean CPlainFile::_IsFileExist(
    /* [in] */ const char* path)
{
    if (path == NULL) {
        return FALSE;
    }

    if ((access(path, F_OK)) != -1) {
        return TRUE;
    }

    return FALSE;
}

Boolean CPlainFile::_IsDirExist(
    /* [in] */ const char* path)
{
    if (path == NULL || opendir(path) == NULL) {
        return FALSE;
    }

    return TRUE;
}

Boolean CPlainFile::_IsSpecialDir(
    /* [in] */ const char* path)
{
    return strcmp(path, ".") == 0 || strcmp(path, "..") == 0;
}

Boolean CPlainFile::_Mkdirs(
    /* [in] */ const String& path)
{
    if (path.IsNullOrEmpty()) {
        LOGD("The path = NULL");
        return FALSE;
    }

    String tmpPath(path);
    if (path.LastIndexOf(sSeparatorChar) > 0) {
        tmpPath.Append(sSeparatorChar);
    }
    Int32 index = tmpPath.IndexOf(sSeparatorChar, 1);
    while (index > 0) {
        String path = tmpPath.Substring(0, index);

        if (!_IsDirExist(path.string()) ) {
            if (mkdir(path.string(), S_IRWXU) == -1) {
                LOGD("mkdir has an error.");
                return FALSE;
            }
        }

        index = tmpPath.IndexOf(sSeparatorChar, index + 1);
    }

    return TRUE;
}

String CPlainFile::_GetAbsolutePath(
    /* [in] */ const String& dir,
    /* [in] */ const String& name)
{
    String absolute(dir);
    if (absolute.LastIndexOf(sSeparatorChar) > 0) {
        absolute.Append(sSeparatorChar);
        absolute.Append(name);
        return absolute;
    }

    absolute.Append(name);
    return absolute;
}

} // namespace IO
} // namespace Elastos
