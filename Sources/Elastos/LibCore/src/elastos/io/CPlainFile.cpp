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

static char separatorChar = '/';

CAR_OBJECT_IMPL(CPlainFile)
CAR_INTERFACE_IMPL(CPlainFile, Object, IPlainFile)
CPlainFile::CPlainFile()
{}

ECode CPlainFile::constructor(
    /* [in] */ const String& path)
{
    mPath = path;
    return NOERROR;
}

ECode CPlainFile::Exists(
    /* [out] */ Boolean* exists)
{
    VALIDATE_NOT_NULL(exists);

    Int32 rc = access(mPath.string(), F_OK);
    //rc = -1: Don't exist or hasn't the permission
    *exists = (rc == 0);
    return NOERROR;
}

ECode CPlainFile::IsDir(
    /* [out] */ Boolean* isDir)
{
    VALIDATE_NOT_NULL(isDir);
    *isDir = _IsDir(mPath.string());

    return NOERROR;
}

ECode CPlainFile::IsFile(
    /* [out] */ Boolean* isFile)
{
    VALIDATE_NOT_NULL(isFile);
    *isFile = _IsFile(mPath.string());

    return NOERROR;
}

ECode CPlainFile::Delete()
{
    return _Delete(mPath.string());
}

ECode CPlainFile::_Delete(
    /* [in] */ const char* path)
{
    DIR *dir;
    dirent *dir_info;
    char file_path[PATH_MAX];
    if(_IsFile(path)) {
        remove(path);
        return NOERROR;
    }

    if(_IsDir(path)) {
        if((dir = opendir(path)) == NULL) {
            return NOERROR;
        }

        while((dir_info = readdir(dir)) != NULL) {
            if(_IsSpecialDir(dir_info->d_name)) {
                continue;
            }

            _GetFilePath(path, dir_info->d_name, file_path);
            _Delete(file_path);
            rmdir(file_path);
        }

        // Need closedir?
        // closedir(path);
    }

    return NOERROR;
}

ECode CPlainFile::Mkdir()
{
    if (mkdir(mPath.string(), S_IRWXU) == -1) {
        return E_INVALID_ARGUMENT;
    }
    return NOERROR;
}

ECode CPlainFile::Mkdirs()
{
    if(_Mkdirs(mPath)) {
        return NOERROR;
    }

    return E_INVALID_ARGUMENT;
}

ECode CPlainFile::Write(
    /* [in] */ const String& content)
{
    FILE *fp = fopen(mPath.string(), "a+");
    if (NULL == fp) {
        return E_INVALID_ARGUMENT;
    }
    if(fwrite(content, strlen(content), 1, fp) != 1) {
        fclose (fp);
        return E_INVALID_ARGUMENT;
    }

    fclose (fp);
    return NOERROR;
}

ECode CPlainFile::Read(
    /* [out] */ String* content)
{
    VALIDATE_NOT_NULL(content);

    return NOERROR;
}

ECode CPlainFile::GetPath(
    /* [out] */ String* path)
{
    VALIDATE_NOT_NULL(path);
    *path = mPath;
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

void CPlainFile::_GetFilePath(
    /* [in] */ const char* path,
    /* [in] */ const char* file_name,
    /* [in] */ char *file_path)
{
    strcpy(file_path, path);
    if(file_path[strlen(path) - 1] != separatorChar) {
        strcat(file_path, "/");
    }
    strcat(file_path, file_name);
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
        LOGD("The mPath = NULL");
        return FALSE;
    }

    String tmpPath(path);
    if (path.LastIndexOf(separatorChar) > 0) {
        tmpPath.Append(separatorChar);
    }
    Int32 index = tmpPath.IndexOf(separatorChar, 1);
    while (index > 0) {
        String path = tmpPath.Substring(0, index);
        LOGD("[%s], Line=[%d], path=[%s]", __FUNCTION__, __LINE__, path.string());

        if (!_IsDirExist(path.string()) ) {
            if (mkdir(path.string(), S_IRWXU) == -1) {
                LOGD("mkdir has an error.");
                return FALSE;
            }
        }

        index = tmpPath.IndexOf(separatorChar, index);
    }

    return TRUE;
}

Boolean CPlainFile::_CreateFile(
    /* [in] */ const char* path,
    /* [in] */ const char* fileName)
{
    if(_IsDirExist(path)){
        if (_IsFileExist(fileName)) {
            return TRUE;
        }
    }
    else{
        if (_Mkdirs(String(path))) {
            if(open(fileName,O_RDWR | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH, 0600) != -1) {
                return TRUE;
            }
        }

    }

    return  FALSE;
}

} // namespace IO
} // namespace Elastos
