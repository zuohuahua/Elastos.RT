#include <stdio.h>

#include "elastos.h"

using namespace Elastos;


int main(int argc, char *argv[])
{
    const char* libname = "Elastos.HelloCarDemo.eco";
    const char* classname = "CHelloCar";

    printf("Start reflction\n");

    AutoPtr<IModuleInfo> pMdlInfo;
    ECode ec = CReflector::AcquireModuleInfo(String(libname), (IModuleInfo**)&pMdlInfo);
    if (FAILED(ec)) {
        printf("AcquireModuleInfo failed\n");
        return ec;
    }

    AutoPtr<IClassInfo> pClsInfo;
    ec = pMdlInfo->GetClassInfo(Elastos::String(classname), (IClassInfo**)&pClsInfo);
    if (FAILED(ec)) {
        printf("GetClassInfo failed\n");
        return ec;
    }

    AutoPtr<IInterface> pObject;
    ec = pClsInfo->CreateObject((IInterface**)&pObject);
    if (FAILED(ec)) {
        printf("CreateObject failed\n");
        return ec;
    }

    Int32 nMtdCnt;
    ec = pClsInfo->GetMethodCount(&nMtdCnt);
    if (FAILED(ec)) {
        printf("GetMethodCount failed\n");
        return ec;
    }

    ArrayOf<IMethodInfo*>* pMtdInfoArray = ArrayOf<IMethodInfo*>::Alloc(nMtdCnt);
    ec = pClsInfo->GetAllMethodInfos(pMtdInfoArray);
    if (FAILED(ec)) {
        printf("GetAllMethodInfo failed\n");
        return ec;
    }

    IMethodInfo *pMtdInfo = (*pMtdInfoArray)[0]; //Hello()
    String szMtdName;
    ec = pMtdInfo->GetName(&szMtdName);
    if (FAILED(ec)) {
        printf("pMtdInfo->GetName failed\n");
        return ec;
    }

    AutoPtr<IArgumentList> pArgList;
    ec = pMtdInfo->CreateArgumentList((IArgumentList**)&pArgList);
    if (FAILED(ec)) {
        printf("CreateArgumentList failed\n");
        return ec;
    }

    String output;
    ec = pArgList->SetOutputArgumentOfStringPtr(0, &output);
    if (FAILED(ec)) {
        printf("SetOutputArgumentOfStringPtr failed\n");
        return ec;
    }

    ec = pMtdInfo->Invoke(pObject.Get(), pArgList);
    if (FAILED(ec)) {
        printf("Invoke failed\n");
        return ec;
    } else {
        printf("Hello %s\n", output.string());
    }
    printf("Done\n");
}

