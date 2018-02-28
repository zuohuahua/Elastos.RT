
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

#include "_Client.h"
#include "_TC.h"



int main(int argc, char *argv[])
{
    ECode ec;
    IClient *pClient;
    String str;
    ArrayOf<Int32>* array = ArrayOf<Int32>::Alloc(2);
    AutoPtr<ArrayOf<Int32>> ret;
    AutoPtr<ArrayOf<ITC2*>> interfaces;
    // AutoPtr<ArrayOf<String>> strings;


    ec = CClient::New(&pClient);
    if (FAILED(ec))
        goto out1;

    IInterface *ifc;
    ITC *itc;

    ec = pClient->GetService(String("TC"), &ifc);
    if (FAILED(ec))
        goto out2;
    itc = ITC::Probe(ifc);
    if (itc == NULL)
        goto out2;

    // Int32 i;

    // ec = itc->Get(&i);
    // if (FAILED(ec))
    //     goto out2;

    // printf("%d\n", i);

    // itc->Increment();

    // ec = itc->Get(&i);
    // if (FAILED(ec))
    //     goto out2;

    // printf("%d\n", i);

    // ec = itc->GetString(&str);
    // if (FAILED(ec))
    //     goto out2;

    // printf("GetString %s\n", str.string());

    // ec = itc->SetString(String("client test"));
    // if (FAILED(ec))
    //     goto out2;

    // ec = itc->GetString(&str);
    // if (FAILED(ec))
    //     goto out2;

    // printf("GetString %s\n", str.string());


    // ec = itc->SetBoolean(true);
    // if (FAILED(ec))
    //     goto out2;

    // Boolean b;
    // ec = itc->GetBoolean(&b);
    // if (FAILED(ec))
    //     goto out2;

    // printf("GetBoolean %d\n", b);

    // ec = itc->SetInt64(87899090);
    // if (FAILED(ec))
    //     goto out2;

    // Int64 i64;
    // ec = itc->GetInt64(&i64);
    // if (FAILED(ec))
    //     goto out2;

    // printf("GetInt64 %lld\n", i64);

    // ec = itc->SetDouble(1.90598);
    // if (FAILED(ec))
    //     goto out2;

    // Double d;
    // ec = itc->GetDouble(&d);
    // if (FAILED(ec))
    //     goto out2;

    // printf("GetDouble %lf\n", d);


    // array->Set(0, 11);
    // array->Set(1, 22);
    // ec = itc->SetArrayOf(*array);
    // if (FAILED(ec))
    //     goto out2;

    // ec = itc->GetArrayOf((ArrayOf<Int32>**)&ret);
    // if (FAILED(ec))
    //     goto out2;

    // printf("GetArrayOf %d %d\n", (*ret)[0], (*ret)[1]);

    // ec = itc->GetArrayOfInterface((ArrayOf<ITC2*>**)&interfaces);
    // if (FAILED(ec))
    //     goto out2;
    // printf("GetArrayOfInterface interfaces\n");

    // (*interfaces)[0]->GetEx(&i);
    // printf("GetArrayOfInterface ITC2 GetEx %d\n", i);

    // // ec = itc->GetArrayOfString((ArrayOf<String>**)&strings);
    // // if (FAILED(ec))
    // //     goto out2;
    // // printf("GetArrayOfString %s %s\n", (*strings)[0], (*strings)[1]);

    sleep(10);

out2:
    if (pClient != NULL)
        pClient->Release();
    if (array != NULL)
        ArrayOf<Int32>::Free(array);

out1:
    return 0;
}

