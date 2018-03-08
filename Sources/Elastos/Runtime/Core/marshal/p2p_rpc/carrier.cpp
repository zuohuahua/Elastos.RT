
#include "carrier.h"
#include "Base64.h"
#include <../../reflection/hashtable.h>

pthread_cond_t gCv = PTHREAD_COND_INITIALIZER;
pthread_mutex_t gMutex = PTHREAD_MUTEX_INITIALIZER;
ElaCarrier* gCarrier = NULL;
ElaConnectionStatus gStatus = ElaConnectionStatus_Disconnected;
ElaConnectionStatus gFriendStatus = ElaConnectionStatus_Disconnected;
pthread_t gCarrierThread = 0;

DataPack* gData = NULL;

HashTable<ElaConnectionStatus, Type_String> gFriendsStatus;

void free_data() 
{
    if (gData != NULL) {
        ArrayOf<Byte>::Free(gData->data);
        delete gData;
        gData = NULL;
    }
}

void FriendRequest(
    ElaCarrier *w,
    const char *userid,
    const ElaUserInfo *info,
    const char *hello,
    void *context)
{
    RPC_LOG("Friend request from user[%s] with HELLO: %s.\n",
           *info->name ? info->name : userid, hello);

    int rc = ela_accept_friend(w, userid);
    if (rc == 0)
        RPC_LOG("Accept friend request success.\n");
    else
        RPC_LOG("Accept friend request failed(0x%x).\n", ela_get_error());
}

void FriendAdded(
    ElaCarrier *w, 
    const ElaFriendInfo *info,
    void *context)
{
    pthread_mutex_lock(&gMutex);

    free_data();
    gData = new DataPack();
    if (!gData) {
        pthread_mutex_unlock(&gMutex);
        return;
    }
    gData->data = ArrayOf<Byte>::Alloc(4);
    if (!gData->data) {
        pthread_mutex_unlock(&gMutex);
        return;
    }

    gData->from = info->user_info.userid;
    Int32 type = ADD_FRIEND_SUCCEEDED;
    memcpy(gData->data->GetPayload(), &type, 4);

    pthread_cond_signal(&gCv);

    pthread_mutex_unlock(&gMutex);
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
    gFriendsStatus.Put((PVoid)friendid, (ElaConnectionStatus*)&status);
    switch (status) {
    case ElaConnectionStatus_Connected:
    {
        pthread_mutex_lock(&gMutex);

        free_data();
        gData = new DataPack();
        if (!gData) {
            pthread_mutex_unlock(&gMutex);
            return;
        }
        gData->data = ArrayOf<Byte>::Alloc(4);
        if (!gData->data) {
            pthread_mutex_unlock(&gMutex);
            return;
        }

        gData->from = friendid;
        Int32 type = FRIEND_ONLINE;
        memcpy(gData->data->GetPayload(), &type, 4);

        pthread_cond_signal(&gCv);

        pthread_mutex_unlock(&gMutex);
        RPC_LOG("Friend[%s] connection changed to be online\n", friendid);
        break;
    }
    case ElaConnectionStatus_Disconnected:
        RPC_LOG("Friend[%s] connection changed to be offline.\n", friendid);
        break;

    default:
        RPC_LOG("Error!!! Got unknown connection status %d.\n", status);
    }
}

void ConnectionStatus(
    ElaCarrier *w,
    ElaConnectionStatus status,
    void *context)
{
    gStatus = status;
    switch (status) {
        case ElaConnectionStatus_Connected:
            pthread_cond_signal(&gCv);
            RPC_LOG("Connected to carrier network.\n");
            break;

        case ElaConnectionStatus_Disconnected:
            RPC_LOG("Disconnect from carrier network.\n");
            break;

        default:
            RPC_LOG("Error!!! Got unknown connection status %d.\n", status);
    }
}

void MessageReceived(
    ElaCarrier *w,
    const char *from,
    const char *msg,
    size_t len,
    void *context)
{
    pthread_mutex_lock(&gMutex);
    RPC_LOG("Receive message: user[%s] msg[%s] len[%d].\n", from, msg, len);

    free_data();
    gData = new DataPack();
    if (!gData) {
        pthread_mutex_unlock(&gMutex);
        return;
    }
    gData->from = from;

    String inData(msg, len);
    ECode ec = Decode(inData.GetBytes(), &gData->data);
    if (FAILED(ec)) {
        return;
    }

    pthread_cond_signal(&gCv);

    pthread_mutex_unlock(&gMutex);
}

void* carrierThread(void* argc)
{
    const char* location = (const char*)argc;

    ElaCallbacks callbacks;
    memset(&callbacks, 0, sizeof(callbacks));
    callbacks.connection_status = ConnectionStatus;
    callbacks.friend_request = FriendRequest;
    callbacks.friend_list = FriendsList;
    callbacks.friend_added = FriendAdded;
    callbacks.friend_message = MessageReceived;
    callbacks.friend_connection = FriendConnectionStatus;

    ElaOptions opts;
    memset(&opts, 0, sizeof(opts));
    opts.udp_enabled = true;
    opts.persistent_location = location;
    opts.bootstraps_size = 1;
    opts.bootstraps = (BootstrapNode *)calloc(1, sizeof(BootstrapNode) * 1);
    if (!opts.bootstraps) {
        assert(0 && "TODO");
    }

    opts.bootstraps[0].ipv4 = "13.58.208.50";
    opts.bootstraps[0].port = "33445";
    opts.bootstraps[0].public_key = "89vny8MrKdDKs7Uta9RdVmspPjnRMdwMmaiEW27pZ7gh";

    gCarrier = ela_new(&opts, &callbacks, NULL);
    if (!gCarrier) {
        RPC_LOG("Error create carrier instance: 0x%x\n", ela_get_error());
        return 0;
    }


    char buf[ELA_MAX_ADDRESS_LEN+1];
    RPC_LOG("Carrier node identities:\n");
    RPC_LOG("   Node ID: %s\n", ela_get_nodeid(gCarrier, buf, sizeof(buf)));
    RPC_LOG("   User ID: %s\n", ela_get_userid(gCarrier, buf, sizeof(buf)));
    RPC_LOG("   Address: %s\n\n", ela_get_address(gCarrier, buf, sizeof(buf)));
    RPC_LOG("\n");

    int rc = ela_run(gCarrier, 10);
    if (rc != 0) {
        RPC_LOG("Error start carrier loop: 0x%x\n", ela_get_error());
        ela_kill(gCarrier);
        return 0;
    }

    return 0;
}

ELAPI_(int) ECO_PUBLIC carrier_connect(
    const char* location,
    ElaCarrier** carrier)
{
    if (carrier == NULL) {
        return -1;
    }

    if (gCarrier != NULL) {
        *carrier = gCarrier;
        return 0;
    }

    int ret = pthread_create(&gCarrierThread, NULL, carrierThread, (void*)location);
    if (ret != 0) {
        RPC_LOG("Create thread failed\n");
        return -1;
    }

    if (gStatus != ElaConnectionStatus_Connected) {
        pthread_mutex_lock(&gMutex);
        timeval now;
        timespec waitTime;
        gettimeofday(&now, NULL);
        waitTime.tv_sec = now.tv_sec + 30;
        waitTime.tv_nsec = now.tv_usec * 1000;
        while(gStatus != ElaConnectionStatus_Connected) {
            int ret = pthread_cond_timedwait(&gCv, &gMutex, &waitTime);
            if (ret != 0) {
                break;
            }
        }
        pthread_mutex_unlock(&gMutex);

    }

    if (gStatus == ElaConnectionStatus_Connected) {
        *carrier = gCarrier;
        return 0;
    }
    else {
        return -1;
    }
}

ELAPI_(int) ECO_PUBLIC carrier_add_friend(
    ElaCarrier* carrier,
    const char* address,
    const char* hello)
{
    return ela_add_friend(carrier, address, hello);
}

ELAPI_(_ELASTOS Boolean) ECO_PUBLIC carrier_is_friend(
    ElaCarrier* carrier,
    const char* uid)
{
    return ela_is_friend(carrier, uid);
}

ELAPI_(ElaConnectionStatus) ECO_PUBLIC carrier_get_friend_status(
    const char* uid)
{
    ElaConnectionStatus* status = gFriendsStatus.Get((char*)uid);
    if (status == NULL) {
        return ElaConnectionStatus_Disconnected;
    } 
    else {
        return *status;
    }
}

ELAPI_(int) ECO_PUBLIC carrier_send(
    ElaCarrier* carrier,
    const char* to,
    int type,
    Byte* msg,
    size_t len)
{
    size_t msgLen = len + 4;
    ArrayOf<Byte>* data = ArrayOf<Byte>::Alloc(msgLen);
    if (data == NULL) {
        return -1;
    }

    void* p = data->GetPayload();
    memcpy(p, &type, 4);
    p += 4;
    memcpy(p, msg, len);
    p += len;

    String outData;
    ECode ec = Encode(data, &outData);
    ArrayOf<Byte>::Free(data);
    if (FAILED(ec)) {
        return ec;
    }

    int rc = ela_send_friend_message(carrier, to, outData.string(), outData.GetLength());
    if (rc == 0)
        RPC_LOG("Send message success to[%s] msg[%s] len[%d].\n", to, outData.string(), outData.GetLength());
    else
        RPC_LOG("Send message failed(0x%x).\n", ela_get_error());

    return rc;
}

ELAPI_(int) ECO_PUBLIC carrier_wait(
    int time) 
{
    int ret = 0;
    pthread_mutex_lock(&gMutex);
    timeval now;
    timespec waitTime;
    gettimeofday(&now, NULL);
    waitTime.tv_sec = now.tv_sec + time;
    waitTime.tv_nsec = now.tv_usec * 1000;
    while(gData == NULL) {
        if (time > 0) {
            ret = pthread_cond_timedwait(&gCv, &gMutex, &waitTime);
        }
        else {
            ret = pthread_cond_wait(&gCv, &gMutex);
        }
        
        if (ret != 0) {
            break;
        }
    }
    pthread_mutex_unlock(&gMutex);

    return ret;
}

ELAPI_(int) ECO_PUBLIC carrier_read(
    DataPack* outData)
{
    if (outData == NULL) {
        return -1;
    }

    pthread_mutex_lock(&gMutex);
    if (gData == NULL) {
        pthread_mutex_unlock(&gMutex);
        return -1;
    }

    outData->from = gData->from;
    ArrayOf<Byte>* data = gData->data->Clone();
    outData->data = data;

    free_data();
    pthread_mutex_unlock(&gMutex);
    return 0;
}

ELAPI_(void) ECO_PUBLIC carrier_destroy()
{
    if (gCarrier != NULL) {
        ela_kill(gCarrier);
        gCarrier = NULL;
    }

    if (gCarrierThread != 0) {
        pthread_join(gCarrierThread, NULL);
        gCarrierThread = 0;
    }

    free_data();
}
