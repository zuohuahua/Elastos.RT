
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

#include "_SManC.h"
#include "_TC.h"



int main(int argc, char *argv[])
{
    ECode ec;
    ISManC *ismc;


    ec = CSManC::New(&ismc);
    if (FAILED(ec))
        goto out1;

    IInterface *ifc;
    ITC *itc;

    ec = ismc->GetService(String("TC"), &ifc);
    if (FAILED(ec))
        goto out2;
    itc = ITC::Probe(ifc);
    if (itc == NULL)
        goto out2;

    Int32 i;

    ec = itc->Get(&i);
    if (FAILED(ec))
        goto out2;

    printf("%d\n", i);

    itc->Increment();

    ec = itc->Get(&i);
    if (FAILED(ec))
        goto out2;

    printf("%d\n", i);

    sleep(10);

out2:
    if (ismc != NULL)
        ismc->Release();

out1:
    return 0;
}

