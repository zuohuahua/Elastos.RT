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

#include <ctype.h>
#ifndef _apple
#ifdef _linux
#include <sys/io.h>
#else
#include <io.h>
#endif
#endif
#include <unistd.h>

#include "clsbase.h"

#ifndef _win32
#define _access access
#define _stricmp strcasecmp
#endif

#define _MAX_PATH 256

void GetNakedFileName(const char *pszSource, char *pszDest)
{
    int n;

    while (isspace(*pszSource)) pszSource++;

    n = strlen(pszSource) - 1;
    while (n >= 0) {
        if (IS_PATH_SEPARATOR(*(pszSource + n)) || *(pszSource + n) == ':') break;
        n--;
    }
    pszSource += n + 1;

    strcpy(pszDest, pszSource);
    n = strlen(pszDest) - 1;
    while (n >= 0) {
        if ('.' == *(pszDest + n)) {
            *(pszDest + n) = '\0';
            return;
        }
        n--;
    }
}

void GetNakedFileType(const char *pszSource, char *pszDest)
{
    int n = strlen(pszSource) - 1;

    while (n >= 0) {
        if ('.' == *(pszSource + n)) {
            strcpy(pszDest, pszSource + n + 1);
            return;
        }
        n--;
    }
    *pszDest = 0;
}

int SearchFileFromPath(
    const char *pszPath, const char *pszFile, char *pszResult)
{
    int n;
    char szFileToSearch[_MAX_PATH] = {0};

    strcpy(szFileToSearch, pszFile);
#if defined(_cmake)
    // With cmake building environment, we only store CAR class metadata in a separate file.
    n = strlen(szFileToSearch);
    if (!_stricmp(szFileToSearch + n - 4, ".eco")) {
        strcpy(szFileToSearch + n - 4, ".cls");
    } else if (!strncmp(pszFile, "lib", 3) && !_stricmp(szFileToSearch + n - 3, ".so")) {
        int filename_len = strlen(pszFile);
        int prefix_len = strlen("lib");
        memmove(szFileToSearch + n - filename_len, szFileToSearch + n - filename_len + prefix_len, filename_len - prefix_len);
        strcpy(szFileToSearch + n - strlen("lib.so"), ".cls");
    }
#endif

    if (0 == _access(szFileToSearch, 0)) {
        strcpy(pszResult, szFileToSearch);
        _ReturnOK (CLS_NoError);
    }

    while (0 != *pszPath) {
        n = 0;
        while (':' != *pszPath && 0 != *pszPath) {
            pszResult[n++] = *pszPath++;
        }
        if (n > 0) {
            if (!IS_PATH_SEPARATOR(pszResult[n - 1])) pszResult[n++] = '/';
            strcpy(pszResult + n, szFileToSearch);

            if (0 == _access(pszResult, 0)) _ReturnOK (CLS_NoError);
        }

        while (':' == *pszPath) pszPath++;
    }
    pszResult[0] = 0;

    ExtraMessage(szFileToSearch);
    _ReturnError (CLSError_NotFound);
}
