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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#ifdef _linux
#include <sys/io.h>
#else
#include <io.h>
#endif
#include <stdio.h>
#include <elf.h>

#include "clsbase.h"

#ifdef _ELASTOS64
    #define Elf32_64_Ehdr   Elf64_Ehdr
    #define Elf32_64_Shdr   Elf64_Shdr
#else
    #define Elf32_64_Ehdr   Elf32_Ehdr
    #define Elf32_64_Shdr   Elf32_Shdr
#endif

typedef struct ModuleRscStruct {
    unsigned int    uSize;
	const char      uClsinfo[0];
} ModuleRscStruct;


int CheckFileFormat(FILE *pFile)
{
    int         cnt  = 0;
    Elf32_64_Ehdr  ehdr;

    if(fseek(pFile, 0, SEEK_SET) < 0) {
        ExtraMessage("fseek() failed");
        _ReturnError (CLSError_OpenFile);
    }

    if ((cnt = fread((char *)&ehdr, 1,sizeof(Elf32_64_Ehdr), pFile)) < 0) {
        ExtraMessage("fread() failed");
        _ReturnError (CLSError_OpenFile);
    }

    if ((ehdr.e_ident[EI_MAG0] != ELFMAG0) || (ehdr.e_ident[EI_MAG1] != ELFMAG1) ||
        (ehdr.e_ident[EI_MAG2] != ELFMAG2) || (ehdr.e_ident[EI_MAG3] != ELFMAG3)) {
        ExtraMessage("elf format mismatch!!\n");
        _ReturnError (CLSError_OpenFile);
    }

    _ReturnOK (CLS_NoError);;
}

int LoadResourceFromELF(const char *pszName, CLSModule **ppDest)
{
    Elf32_64_Ehdr   ehdr;
    Elf32_64_Shdr   *shdr         = NULL;
    Elf32_64_Shdr   *pTemShdr     = NULL;
    ModuleRscStruct *pRsc         = NULL;
    FILE            *pFile        = NULL;
    char            *pStringTable = NULL;
    char            *pSecName     = NULL;
    char            *pGetSec      = NULL;
    char            *secHeader    = NULL;
    int             cnt           = 0;
    int             rRet          = 0;
    int             nRet          = CLS_NoError;

    if (pszName == NULL) {
        char path[256];
        strcpy(path, getenv("XDK_TOOLS"));
        strcat(path, "/carc");
        pFile = fopen(path, "rb");
    }
    else {
        pFile = fopen(pszName, "rb");
    }

    if (!pFile) {
        ExtraMessage("fopen() failed!");
        _ReturnError (CLSError_OpenFile);
    }

    if (fseek(pFile, 0, SEEK_SET) < 0) {
        ExtraMessage("fseek() failed!");
        _ReturnError (CLSError_OpenFile);
    }

    if ((cnt = fread((char *)&ehdr, 1, sizeof(Elf32_64_Ehdr), pFile)) < 0) {
        ExtraMessage("fread() failed!");
        _ReturnError (CLSError_OpenFile);
    }

    if (fseek(pFile, ehdr.e_shoff, SEEK_SET) < 0) {
        ExtraMessage("fopen() failed!");
        _ReturnError (CLSError_OpenFile);
    }

    secHeader = (char *)malloc(sizeof(Elf32_64_Shdr) * ehdr.e_shnum);

    if(NULL == secHeader){
        ExtraMessage("malloc() failed!");
        nRet = CLSError_OpenFile;
        goto reterr;
    }

    if ((cnt = fread(secHeader, 1, ehdr.e_shnum * sizeof(Elf32_64_Shdr), pFile)) < 0) {
        ExtraMessage("fread() failed!");
        nRet = CLSError_OpenFile;
        goto reterr;
    }

    shdr         = (Elf32_64_Shdr *)secHeader;
    pTemShdr     = shdr + ehdr.e_shstrndx;
    pStringTable = (char *)malloc(pTemShdr->sh_size);

    if (fseek(pFile, pTemShdr->sh_offset, SEEK_SET) < 0) {
        ExtraMessage("fseek() failed!");
        nRet = CLSError_OpenFile;
        goto reterr;
    }

    if ((cnt = fread(pStringTable, 1, pTemShdr->sh_size, pFile)) < 0) {
        ExtraMessage("fread() failed!");
        nRet = CLSError_OpenFile;
        goto reterr;
    }

    pTemShdr = shdr;

    for (cnt=0; cnt<ehdr.e_shnum; cnt++){
        pSecName = pStringTable + pTemShdr->sh_name;

        if (!strncmp(pSecName, ".clsresource", 12)) {
            break;
        }

        pTemShdr ++;
    }

    if (cnt == ehdr.e_shnum) {
        ExtraMessage("resource section does not exist!");
        nRet = CLSError_OpenFile;
        goto reterr;
    }

    pGetSec = (char *)malloc(pTemShdr->sh_size);

    if(NULL == pGetSec){
        ExtraMessage("malloc() failed!");
        nRet = CLSError_OpenFile;
        goto reterr;
    }

    if (fseek(pFile, pTemShdr->sh_offset, SEEK_SET) < 0) {
        ExtraMessage("fseek() failed!");
        nRet = CLSError_OpenFile;
        goto reterr;
    }

    if ((cnt = fread(pGetSec, 1, pTemShdr->sh_size, pFile)) < 0) {
        ExtraMessage("fread() failed!");
        nRet = CLSError_OpenFile;
        goto reterr;
    }

    fclose(pFile);
    pRsc = (ModuleRscStruct *)pGetSec;
    rRet    = IsValidCLS((CLSModule *)&(pRsc->uClsinfo[0]), pRsc->uSize, pszName);
    nRet = (rRet < 0) ? rRet : RelocFlattedCLS((CLSModule *)&(pRsc->uClsinfo[0]), pRsc->uSize, ppDest);

reterr:
    if (secHeader)
        free((void *)secHeader);
    if (pGetSec)
        free(pGetSec);
    if(pStringTable)
        free(pStringTable);
    _ReturnError(nRet);
}



