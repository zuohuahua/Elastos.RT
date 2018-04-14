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

#include "elastos/core/StringUtils.h"
#include "elastos/core/StringBuilder.h"
#include "elastos/core/AutoLock.h"
#include "elastos/coredef.h"

using Elastos::Core::AutoLock;
using Elastos::Core::CString;
using Elastos::Core::StringUtils;
using Elastos::IO::CPlainFile;
using Elastos::IO::IPlainFile;

/**
 * =====================Description of the car class CPlainFile=======================
 * An representation of a file system identified by a pathname.
 * The pathname must be absolute (relative to the root directory of the file system)
 *
 * The actual file referenced by a CPlainFile may or may not exist. It may
 * also, despite the name CPlainFile, be a directory or other regular file.
 */

void testPlainFile()
{
    const Int32 LEN = 512;
    char cwd[LEN];
    getcwd(cwd, LEN);
    String path(cwd);

    // Test File
    AutoPtr<IPlainFile> file;
    String path1(path);
    path1.Append("/test1/test11");

    ECode ec = CPlainFile::New(path1, (IPlainFile**)&file);
    printf("Test Path=================[%s], ec=[0x%08x]\n", path1.string(), ec);
    assert(ec == NOERROR && file != NULL);

    ec = file->Write(String("0123456789"));
    if (FAILED(ec)) {
        printf("Write data failed at the path:[%s]\n", path1.string());
    }

    Boolean exists = FALSE;
    file->Exists(&exists);
    if (exists) {
        printf("The path: [%s] is exist.\n", path1.string());
    }
    else {
        printf("The path: [%s] is not exist.\n", path1.string());
    }

    file->Mkdirs();
    file->Exists(&exists);
    if (exists) {
        printf("The path: [%s] is exist.\n", path1.string());
    }
    else {
        printf("The path: [%s] is not exist.\n", path1.string());
    }

    Boolean isDir = FALSE;
    file->IsDir(&isDir);
    if (isDir) {
        printf("The path: [%s] is a directory.\n", path1.string());
    }
    else {
        printf("The path: [%s] is not a directory.\n", path1.string());
    }

    Boolean isFile = FALSE;
    file->IsFile(&isFile);
    if (isFile) {
        printf("The path: [%s] is a file.\n", path1.string());
    }
    else {
        printf("The path: [%s] is not a file.\n", path1.string());
    }

    String absolutePath;
    file->GetPath(&absolutePath);
    printf("The path's absolutePath is [%s].\n", absolutePath.string());

    // ===================================================================
    // Test File2
    String path2(path);
    path2.Append("/test2/test22");
    AutoPtr<IPlainFile> file2;
    ec = CPlainFile::New(path2, String("testFilename"), (IPlainFile**)&file2);
    assert(ec == NOERROR && file2 != NULL);

    ec = file2->Write(String("01234"));
    ASSERT_SUCCEEDED(ec);

    ec = file2->Write(String("文件"));
    ASSERT_SUCCEEDED(ec);

    ec = file2->Write(String("56789"));
    ASSERT_SUCCEEDED(ec);

    String content;
    file2->Read(&content);
    printf("The file's content: [%s].\n", content.string());

    exists = FALSE;
    file2->Exists(&exists);
    if (exists) {
        printf("The path: [%s] is exist.\n", path1.string());
    }
    else {
        printf("The path: [%s] is not exist.\n", path1.string());
    }

    isDir = FALSE;
    file2->IsDir(&isDir);
    if (isDir) {
        printf("The path: [%s] is a directory.\n", path1.string());
    }
    else {
        printf("The path: [%s] is not a directory.\n", path1.string());
    }

    isFile = FALSE;
    file2->IsFile(&isFile);
    if (isFile) {
        printf("The path: [%s] is a file.\n", path1.string());
    }
    else {
        printf("The path: [%s] is not a file.\n", path1.string());
    }

    absolutePath = NULL;
    file2->GetPath(&absolutePath);
    printf("The path's absolutePath is [%s].\n", absolutePath.string());
}

int main(int argc, char *argv[])
{
    printf("======================================================\n");
    printf("=========== Test PlainFile ============\n");
    printf("======================================================\n\n");

    testPlainFile();

    printf("\n=========== Exit Test PlainFile ============\n");
    return 0;
}
