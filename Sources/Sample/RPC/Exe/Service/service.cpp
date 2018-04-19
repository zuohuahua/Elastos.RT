
#include "CService.h"
#include "CChat.h"
#include "Chat.h"

using namespace Elastos;


int main(int argc, char *argv[])
{
    ECode ec;
    IChat* pChat = NULL;

    SERVICE_LOG("=== Service create");
    IService* service;
    ec = CService::New(String("/sdcard/Service"), &service);
    if (FAILED(ec)) {
        goto exit;
    }

    ec = CChat::New(&pChat);
    if (FAILED(ec)) {
        goto exit;
    }

    SERVICE_LOG("=== Service AddService");
    ec = service->AddService(String("chat"), pChat);
    if (FAILED(ec)) {
        goto exit;
    }


    SERVICE_LOG("=== Service start");
    service->Start();

exit:
    if (pChat) {
        pChat->Release();
    }

    if (service) {
        service->Release();
    }
    SERVICE_LOG("=== Service exit");
    return 0;
}
