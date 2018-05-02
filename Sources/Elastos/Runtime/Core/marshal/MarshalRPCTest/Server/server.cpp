
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

#include "SManC.h"
#include "TC.h"

int main(int argc, char *argv[])
{
    ECode ec;
    ISManC *ismc;

    ec = CSManC::New(&ismc);
    if (FAILED(ec))
        goto out1;

    ITC *itc;

    ec = CTC::New(10, &itc);
    if (FAILED(ec))
        goto out2;

    if (ismc->AddService(String("TC"), itc))
        goto out3;

    sleep(1000);

out3:
    if (itc != NULL)
        itc->Release();

out2:
    if (ismc != NULL)
        ismc->Release();

out1:
    return 0;
}

