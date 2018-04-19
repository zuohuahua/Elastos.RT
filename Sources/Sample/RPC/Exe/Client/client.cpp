#include "CClient.h"

#include "CChat.h"
#include "Chat.h"

using namespace Elastos;


int main(int argc, char *argv[])
{
    ECode ec;
    IChat* pChat = NULL;
    IInterface* pInterface;

    CLIENT_LOG("=== Client create");
    IClient* client;
    ec = CClient::New(String("/sdcard/Client"), &client);
    if (FAILED(ec)) {
        goto exit;
    }

    CLIENT_LOG("=== Client GetService");
    ec = client->GetService(String("chat"), &pInterface);
    if (FAILED(ec)) {
        goto exit;
    }

    CLIENT_LOG("=== Client Probe IChat");
    pChat = IChat::Probe(pInterface);
    if (!pChat) {
        goto exit;
    }

    CLIENT_LOG("=== Client IChat call send");
    pChat->Send(String("rpctest"));

exit:
    if (pChat) {
        pChat->Release();
    }

    if (client) {
        client->Release();
    }
    CLIENT_LOG("=== Client exit");
    return 0;
}
