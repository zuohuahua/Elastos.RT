
#include "CClient.h"
#include "Carrier.h"
#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>
#include "Base64.h"

#define SERVER_ADDRESS "6in5GLjxmfmsMWZB1ttFCAGXwmJi3orTVWPogmv44ZvXsyuQwRR6"
#define SERVER_UID "3bx3rqkQ6RpNjqi51GaD1DqsVXU5jGxtv27c3CsH7chN"

pthread_cond_t CClient::sCv = PTHREAD_COND_INITIALIZER;
pthread_mutex_t CClient::sMutex = PTHREAD_MUTEX_INITIALIZER;
ElaConnectionStatus CClient::sStatus = ElaConnectionStatus_Disconnected;
ElaConnectionStatus CClient::sFriendStatus = ElaConnectionStatus_Disconnected;

DataPack* data = NULL;

enum {
    ADD_SERVICE = 0,
    GET_SERVICE,
    REMOVE_SERVICE,
    ADD_SERVICE_REPLY,
    GET_SERVICE_REPLY,
    REMOVE_SERVICE_REPLY
};

CAR_OBJECT_IMPL(CClient)

CAR_INTERFACE_IMPL(CClient, Object, IClient);

void FriendAdded(
    ElaCarrier *w, 
    const ElaFriendInfo *info,
    void *context)
{
    pthread_mutex_lock(&CClient::sMutex);

    String result("FriendAdded");
    data = new DataPack();
    data->m_len = result.GetLength();
    data->m_len += 1;
    data->m_data = malloc(data->m_len);
    if (!data->m_data) return;
    memcpy(data->m_data, result.string(), data->m_len);

    pthread_cond_signal(&CClient::sCv);

    pthread_mutex_unlock(&CClient::sMutex);
}

bool FriendsList(
    ElaCarrier *w,
    const ElaFriendInfo *friend_info,
    void *context)
{
    return true;
}

void FriendConnectionStatus(
    ElaCarrier *w,
    const char *friendid,
    ElaConnectionStatus status,
    void *context)
{
    CClient::sFriendStatus = status;
    switch (status) {
    case ElaConnectionStatus_Connected:
        pthread_cond_signal(&CClient::sCv);
        printf("Friend[%s] connection changed to be online\n", friendid);
        break;

    case ElaConnectionStatus_Disconnected:
        printf("Friend[%s] connection changed to be offline.\n", friendid);
        break;

    default:
        printf("Error!!! Got unknown connection status %d.\n", status);
    }
}

void ConnectionStatus(
    ElaCarrier *w,
    ElaConnectionStatus status,
    void *context)
{
    CClient::sStatus = status;
    switch (status) {
        case ElaConnectionStatus_Connected:
            pthread_cond_signal(&CClient::sCv);
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
    pthread_mutex_lock(&CClient::sMutex);
    printf("Receive message: user[%s] msg[%s] len[%d].\n", from, msg, len);

    String inData(msg, len);
    ArrayOf<Byte>* outData;
    ECode ec = Decode(inData.GetBytes(), &outData);
    if (FAILED(ec)) {
        return;
    }

    data = new DataPack();
    data->m_len = outData->GetLength();
    data->m_data = malloc(data->m_len);
    if (!data->m_data) return;
    memcpy(data->m_data, outData->GetPayload(), data->m_len);

    ArrayOf<Byte>::Free(outData);

    pthread_cond_signal(&CClient::sCv);

    pthread_mutex_unlock(&CClient::sMutex);
}

void* carrierThread(void* argc)
{
    CClient* pThis = (CClient*)argc;

    ElaCallbacks callbacks;
    memset(&callbacks, 0, sizeof(callbacks));
    callbacks.connection_status = ConnectionStatus;
    callbacks.friend_list = FriendsList;
    callbacks.friend_added = FriendAdded;
    callbacks.friend_message = MessageReceived;
    callbacks.friend_connection = FriendConnectionStatus;

    ElaOptions opts;
    memset(&opts, 0, sizeof(opts));
    opts.udp_enabled = true;
    opts.persistent_location = "/home/zuo/work/Client";
    opts.bootstraps_size = 1;
    opts.bootstraps = (BootstrapNode *)calloc(1, sizeof(BootstrapNode) * 1);
    if (!opts.bootstraps) {
        assert(0 && "TODO");
    }

    opts.bootstraps[0].ipv4 = "13.58.208.50";
    opts.bootstraps[0].port = "33445";
    opts.bootstraps[0].public_key = "89vny8MrKdDKs7Uta9RdVmspPjnRMdwMmaiEW27pZ7gh";

    pThis->mCarrier = ela_new(&opts, &callbacks, NULL);
    if (!pThis->mCarrier) {
        printf("Error create carrier instance: 0x%x\n", ela_get_error());
        return 0;
    }


    char buf[ELA_MAX_ADDRESS_LEN+1];
    printf("Carrier node identities:\n");
    printf("   Node ID: %s\n", ela_get_nodeid(pThis->mCarrier, buf, sizeof(buf)));
    printf("   User ID: %s\n", ela_get_userid(pThis->mCarrier, buf, sizeof(buf)));
    printf("   Address: %s\n\n", ela_get_address(pThis->mCarrier, buf, sizeof(buf)));
    printf("\n");

    int rc = ela_run(pThis->mCarrier, 10);
    if (rc != 0) {
        printf("Error start carrier loop: 0x%x\n", ela_get_error());
        ela_kill(pThis->mCarrier);
        return 0;
    }

    return 0;
}

CClient::~CClient()
{
    if (mCarrier != NULL) {
        ela_kill(mCarrier);
        mCarrier = NULL;
    }

    if (mCarrierThread != 0) {
        pthread_join(mCarrierThread, NULL);
        mCarrierThread = 0;
    }
}

ECode CClient::IsFriend(
    /* [in] */ const String& uid,
    /* [out] */ Boolean* isFriend)
{
    if (!isFriend) {
        return E_INVALID_ARGUMENT;
    }

    *isFriend =  ela_is_friend(mCarrier, uid.string());
    return NOERROR;
}

ECode CClient::AddFriend(
    /* [in] */ const String& address)
{
    int ret = ela_add_friend(mCarrier, address.string(), "hello");
    if (ret != 0) {
        printf("Add friend failed 0x%x\n", ela_get_error());
        return E_FAIL;
    }

    pthread_mutex_lock(&sMutex);

    timeval now;
    timespec waitTime;
    gettimeofday(&now, NULL);
    waitTime.tv_sec = now.tv_sec + 10;
    waitTime.tv_nsec = now.tv_usec * 1000;
    while(data == NULL) {
        ret = pthread_cond_timedwait(&sCv, &sMutex, &waitTime);
        if (ret != 0) break;
    }
    if (data == NULL) {
        pthread_mutex_unlock(&sMutex);
        return E_FAIL;
    }

    ECode ec = NOERROR;
    String result((char*)data->m_data);
    if (!result.Equals("FriendAdded")) {
        ec = E_FAIL;
    }

    free(data->m_data);
    delete data;
    data = NULL;
    pthread_mutex_unlock(&sMutex);

    return ec;
}

ECode CClient::SendMessage(
    /* [in] */ const String& to,
    /* [in] */ Int32 type,
    /* [in] */ const String& msg)
{
    printf("Send message to %s content: %s\n", to.string(), msg.string());
    int ret = p2p_send_message(mCarrier, to.string(), type, msg.GetBytes()->GetPayload(), msg.GetByteLength());
    if (ret != 0) {
        printf("Send message failed 0x%x\n", ela_get_error());
        return E_FAIL;
    }


    return NOERROR;
}

ECode CClient::GetService(
    /* [in] */ const String& name,
    /* [out] */ InterfacePack* ip)
{
    ECode ec = SendMessage(String(SERVER_UID), GET_SERVICE, name);
    if (FAILED(ec)) return ec;

    pthread_mutex_lock(&sMutex);

    timeval now;
    timespec waitTime;
    gettimeofday(&now, NULL);
    waitTime.tv_sec = now.tv_sec + 30;
    waitTime.tv_nsec = now.tv_usec * 1000;
    while(data == NULL) {
        int ret = pthread_cond_timedwait(&sCv, &sMutex, &waitTime);
        if (ret != 0) break;
    }
    if (data == NULL) {
        pthread_mutex_unlock(&sMutex);
        printf("GetService failed\n");
        return E_FAIL;
    }

    void* p = data->m_data;
    int type = *(size_t *)p;
    printf("GetService receive type:%d\n", type);
    if (type != GET_SERVICE_REPLY) {
        ec = E_FAIL;
        goto exit;
    }
    p += 4;
    ec = *(ECode *)p;
    printf("GetService receive ec:%x\n", ec);
    if (SUCCEEDED(ec)) {
        p += 4;
        int size = *(int *)p;
        p += 4;
        memcpy(ip, p, sizeof(InterfacePack));
    }

exit:
    free(data->m_data);
    delete data;
    data = NULL;
    pthread_mutex_unlock(&sMutex);

    return ec;
}

ECode CClient::GetService(
    /* [in] */ const String& name,
    /* [out] */ IInterface ** ppService)
{
    if (!ppService) {
        return E_INVALID_ARGUMENT;
    }

    if (sStatus != ElaConnectionStatus_Connected) {
        pthread_mutex_lock(&sMutex);
        timeval now;
        timespec waitTime;
        gettimeofday(&now, NULL);
        waitTime.tv_sec = now.tv_sec + 20;
        waitTime.tv_nsec = now.tv_usec * 1000;
        while(sStatus != ElaConnectionStatus_Connected) {
            int ret = pthread_cond_timedwait(&sCv, &sMutex, &waitTime);
            if (ret != 0) break;
        }
        pthread_mutex_unlock(&sMutex);

        if (sStatus != ElaConnectionStatus_Connected) return E_FAIL;
    }

    Boolean isFriend;
    ECode ec = IsFriend(String(SERVER_UID), &isFriend);
    if (FAILED(ec)) return ec;

    if (!isFriend) {
        ec = AddFriend(String(SERVER_ADDRESS));
        if (FAILED(ec)) return ec;
    }


    if (sFriendStatus != ElaConnectionStatus_Connected) {
        pthread_mutex_lock(&sMutex);
        timeval now;
        timespec waitTime;
        gettimeofday(&now, NULL);
        waitTime.tv_sec = now.tv_sec + 30;
        waitTime.tv_nsec = now.tv_usec * 1000;
        while(sFriendStatus != ElaConnectionStatus_Connected) {
            int ret = pthread_cond_timedwait(&sCv, &sMutex, &waitTime);
            if (ret != 0) break;
        }
        pthread_mutex_unlock(&sMutex);

        if (sFriendStatus != ElaConnectionStatus_Connected) return E_FAIL;
    }


    InterfacePack ip;
    ec = GetService(name, &ip);
    if (FAILED(ec)) return ec;

    printf("service %s stubConnName is %s\n", name.string(), ip.m_stubConnName);
    Int32 size;
    ec = _CObject_UnmarshalInterface((void*)&ip, MarshalType_RPC,
        UnmarshalFlag_Noncoexisting, ppService, &size);
    return ec;
}

ECode CClient::constructor()
{
    int ret = pthread_create(&mCarrierThread, NULL, carrierThread, (void*)this);
    if (ret != 0) {
        printf("Create thread failed\n");
        return E_FAIL;
    }

    return NOERROR;
}


