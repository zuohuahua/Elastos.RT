
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include "_Elastos.RpcDemoClient.h"

using Elastos::RpcDemoClient::CRpcDemoClient;
using Elastos::RpcDemoClient::IRpcDemoClient;

int main(int argc, char *argv[])
{
    String ip("192.168.0.104");
    AutoPtr<IRpcDemoClient> rpcDemoClient;
    CRpcDemoClient::New(ip, TRUE, (IRpcDemoClient**)&rpcDemoClient);
    sleep(1000);
    return 0;
}
