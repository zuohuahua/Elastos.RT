
#include "CService.h"
#include "Carrier.h"
#include "Base64.h"

HashMap<String, InterfacePack*> CService::sServices;
ElaCarrier* CService::sElaCarrier = NULL;

CAR_OBJECT_IMPL(CService)

CAR_INTERFACE_IMPL(CService, Object, IService);

void FriendAdded(
    ElaCarrier *w, 
    const ElaFriendInfo *info,
    void *context)
{
    printf("Friend added: user[%s].\n", info->user_info.name);
}

void ConnectionStatus(
    ElaCarrier *w,
    ElaConnectionStatus status,
    void *context)
{
    switch (status) {
        case ElaConnectionStatus_Connected:
            printf("Connected to carrier network.\n");
            break;

        case ElaConnectionStatus_Disconnected:
            printf("Disconnect from carrier network.\n");
            break;

        default:
            printf("Error!!! Got unknown connection status %d.\n", status);
    }
}

void MessageReceived(
    ElaCarrier *w,
    const char *from,
    const char *msg,
    size_t len,
    void *context)
{
    printf("Receive message: user[%s] msg[%s] len[%d].\n", from, msg, len);
    if (len <= 0) return;

    String inData(msg, len);
    ArrayOf<Byte>* outData;
    ECode ec = Decode(inData.GetBytes(), &outData);
    if (FAILED(ec)) {
        return;
    }

    void* p = outData->GetPayload();
    int type = *(size_t *)p;
    printf("Service receive type: %d\n", type);
    p += 4;

    if (type == GET_SERVICE) {
        String name((char*)p, outData->GetLength() - 4);
        printf("Service receive name: %s\n", name.string());
        CService::HandleGetService(from, name);
    }

    ArrayOf<Byte>::Free(outData);
    printf("MessageReceived end\n");
}

void FriendRequest(
    ElaCarrier *w,
    const char *userid,
    const ElaUserInfo *info,
    const char *hello,
    void *context)
{
    printf("Friend request from user[%s] with HELLO: %s.\n",
           *info->name ? info->name : userid, hello);

    int rc = ela_accept_friend(w, userid);
    if (rc == 0)
        printf("Accept friend request success.\n");
    else
        printf("Accept friend request failed(0x%x).\n", ela_get_error());
}


CService::~CService()
{
    if (sElaCarrier != NULL) {
        ela_kill(sElaCarrier);
        sElaCarrier = NULL;
    }

    HashMap<String, InterfacePack*>::Iterator it = sServices.Begin();
    while (it != sServices.End()) {
        if (it->mSecond != NULL) {

            free(it->mSecond);
        }
        it++;
    }
}

ECode CService::HandleGetService(
    /* [in] */ const char *from,
    /* [in] */ const String& name)
{
    InterfacePack ip;
    ECode ec = GetService(name, &ip);

    int size = sizeof(InterfacePack);

    int _len = 4 + 4 + size;

    ArrayOf<Byte>* data = ArrayOf<Byte>::Alloc(_len);

    void *p = data->GetPayload();

    int i32;

    i32 = ec;
    p = mempcpy(p, &i32, 4);

    if (SUCCEEDED(ec)) {
        i32 = size;
        p = mempcpy(p, &i32, 4);

        memcpy(p, &ip, size);
    } else
        _len = 4;

    p2p_send_message(sElaCarrier, from, GET_SERVICE_REPLY, data->GetPayload(), _len);

    printf("HandleGetService end1\n");
    ArrayOf<Byte>::Free(data);
    printf("HandleGetService end\n");
}

ECode CService::GetService(
    /* [in] */ const String& name,
    /* [out] */ InterfacePack* pIp)
{
    InterfacePack * ip = sServices[name];
    if (!ip) return E_FAIL;
    memset(pIp, 0, sizeof(InterfacePack));
    pIp->m_clsid = ip->m_clsid;
    pIp->m_uIndex = ip->m_uIndex;

    strcpy(pIp->m_stubConnName, ip->m_stubConnName);
    printf("service %s stubConnName is %s\n", name.string(), ip->m_stubConnName);

    return NOERROR;
}

ECode CService::AddService(
    /* [in] */ const String& name,
    /* [in] */ IInterface * pService)
{
    InterfacePack * ip = NULL;
    Int32 size;

    ECode ec = _CObject_MarshalInterface(pService, MarshalType_RPC, (void**)&ip, &size);
    if (FAILED(ec)) return ec;

    sServices[name] = ip;

    return NOERROR;
}

ECode CService::Start()
{
    if (sElaCarrier != NULL) return NOERROR;

    ElaCallbacks callbacks;
    memset(&callbacks, 0, sizeof(callbacks));
    callbacks.connection_status = ConnectionStatus;
    callbacks.friend_request = FriendRequest;
    callbacks.friend_added = FriendAdded;
    callbacks.friend_message = MessageReceived;

    ElaOptions opts;
    memset(&opts, 0, sizeof(opts));
    opts.udp_enabled = true;
    opts.persistent_location = "/home/zuo/work/Service";
    opts.bootstraps_size = 1;
    opts.bootstraps = (BootstrapNode *)calloc(1, sizeof(BootstrapNode) * 1);
    if (!opts.bootstraps) {
        assert(0 && "TODO");
    }

    opts.bootstraps[0].ipv4 = "13.58.208.50";
    opts.bootstraps[0].port = "33445";
    opts.bootstraps[0].public_key = "89vny8MrKdDKs7Uta9RdVmspPjnRMdwMmaiEW27pZ7gh";

    sElaCarrier = ela_new(&opts, &callbacks, NULL);
    if (!sElaCarrier) {
        printf("Error create carrier instance: 0x%x\n", ela_get_error());
        return E_FAIL;
    }

    char buf[ELA_MAX_ADDRESS_LEN+1];
    printf("Carrier node identities:\n");
    printf("   Node ID: %s\n", ela_get_nodeid(sElaCarrier, buf, sizeof(buf)));
    printf("   User ID: %s\n", ela_get_userid(sElaCarrier, buf, sizeof(buf)));
    printf("   Address: %s\n\n", ela_get_address(sElaCarrier, buf, sizeof(buf)));
    printf("\n");

    int rc = ela_run(sElaCarrier, 10);
    if (rc != 0) {
        printf("Error start carrier loop: 0x%x\n", ela_get_error());
        ela_kill(sElaCarrier);
        sElaCarrier = NULL;
        return E_FAIL;
    }

    return NOERROR;
}

ECode CService::constructor()
{
    return NOERROR;
}


