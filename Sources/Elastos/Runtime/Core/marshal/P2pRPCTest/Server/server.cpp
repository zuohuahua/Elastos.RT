
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

#include "_Service.h"

#include "_TC.h"



int main(int argc, char *argv[])
{
    ECode ec;
    IService *pService;

    ec = CService::New(&pService);
    if (FAILED(ec))
        goto out1;

    ITC *itc;

    ec = CTC::New(10, &itc);
    if (FAILED(ec))
        goto out2;

    if (pService->AddService(String("TC"), itc))
        goto out3;

    pService->Start();

    sleep(1000);

out3:
    if (itc != NULL)
        itc->Release();

out2:
    if (pService != NULL)
        pService->Release();

out1:
    return 0;
}

