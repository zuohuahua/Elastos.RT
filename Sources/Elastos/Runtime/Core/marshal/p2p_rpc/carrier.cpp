
#include "carrier.h"
#include "Base64.h"
#include <../../reflection/hashtable.h>
#include <unistd.h>

static struct {
    ElaSession *ws;
    int stream;
    char remote_sdp[2048];
    size_t sdp_len;
} session_ctx;


enum {
    SESSION_REQUEST = 20,
    SESSION_INITIALIZED,
    SESSION_REQUEST_COMPLETED,
    SESSION_TRANSPORT_READY,
    SESSION_CONNECTED,
};

pthread_cond_t gCv = PTHREAD_COND_INITIALIZER;
pthread_mutex_t gMutex = PTHREAD_MUTEX_INITIALIZER;
ElaCarrier* gCarrier = NULL;
ElaConnectionStatus gStatus = ElaConnectionStatus_Disconnected;
ElaConnectionStatus gFriendStatus = ElaConnectionStatus_Disconnected;
pthread_t gCarrierThread = 0;

DataPack* gData = NULL;

HashTable<ElaConnectionStatus, Type_String> gFriendsStatus;

static void free_data() 
{
    if (gData != NULL) {
        ArrayOf<Byte>::Free(gData->data);
        delete gData;
        gData = NULL;
    }
}

static void notify(
    const char* from,
    int type,
    void* msg,
    int len)
{
    pthread_mutex_lock(&gMutex);

    free_data();
    gData = new DataPack();
    if (!gData) {
        pthread_mutex_unlock(&gMutex);
        return;
    }

    int _bufLen = len + 4;
    gData->data = ArrayOf<Byte>::Alloc(_bufLen);
    if (!gData->data) {
        pthread_mutex_unlock(&gMutex);
        return;
    }

    // gData->from = from;
    void* p = gData->data->GetPayload();
    memcpy(p, &type, 4);
    p += 4;
    if (msg != NULL) {
        memcpy(p, msg, len);
    }

    pthread_cond_broadcast(&gCv);

    pthread_mutex_unlock(&gMutex);
}

static void FriendRequest(
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

static void FriendAdded(
    ElaCarrier *w, 
    const ElaFriendInfo *info,
    void *context)
{
    notify(info->user_info.userid, ADD_FRIEND_SUCCEEDED, NULL, 0);
}

static bool FriendsList(
    ElaCarrier *w,
    const ElaFriendInfo *friend_info,
    void *context)
{
    return true;
}

static void FriendConnectionStatus(
    ElaCarrier *w,
    const char *friendid,
    ElaConnectionStatus status,
    void *context)
{
    gFriendsStatus.Put((PVoid)friendid, (ElaConnectionStatus*)&status);
    switch (status) {
    case ElaConnectionStatus_Connected:
        RPC_LOG("Friend[%s] connection changed to be online\n", friendid);
        notify(friendid, FRIEND_ONLINE, NULL, 0);
        break;
    case ElaConnectionStatus_Disconnected:
        RPC_LOG("Friend[%s] connection changed to be offline.\n", friendid);
        break;

    default:
        RPC_LOG("Error!!! Got unknown connection status %d.\n", status);
    }
}

static void ConnectionStatus(
    ElaCarrier *w,
    ElaConnectionStatus status,
    void *context)
{
    gStatus = status;
    switch (status) {
        case ElaConnectionStatus_Connected:
            RPC_LOG("Connected to carrier network.\n");
            notify("", SELF_ONLINE, NULL, 0);
            break;

        case ElaConnectionStatus_Disconnected:
            RPC_LOG("Disconnect from carrier network.\n");
            break;

        default:
            RPC_LOG("Error!!! Got unknown connection status %d.\n", status);
    }
}

static void MessageReceived(
    ElaCarrier *w,
    const char *from,
    const char *msg,
    size_t len,
    void *context)
{
    RPC_LOG("Receive message: user[%s] msg[%s] len[%d].\n", from, msg, len);
}

static void SessionRequestCallback(
    ElaCarrier *w,
    const char *from,
    const char *sdp,
    size_t len,
    void *context)
{
    strncpy(session_ctx.remote_sdp, sdp, len);
    session_ctx.remote_sdp[len] = 0;
    session_ctx.sdp_len = len;

    RPC_LOG("Session request from[%s] with SDP:\n%s.\n", from, session_ctx.remote_sdp);
    RPC_LOG("Reply use following commands:\n");
    RPC_LOG("  sreply refuse [reason]\n");
    RPC_LOG("OR:\n");
    RPC_LOG("  1. snew %s\n", from);
    RPC_LOG("  2. sadd [plain] [reliable] [multiplexing] [portforwarding]\n");
    RPC_LOG("  3. sreply ok\n");

    notify("", SESSION_REQUEST, (void*)from, strlen(from));
}

static void StreamStateChanged(
    ElaSession *ws,
    int stream,
    ElaStreamState state,
    void *context)
{
    const char *state_name[] = {
        "raw",
        "initialized",
        "transport_ready",
        "connecting",
        "connected",
        "deactivated",
        "closed",
        "failed"
    };

    RPC_LOG("Stream [%d] state changed to: %s\n", stream, state_name[state]);

    if (state == ElaStreamState_initialized) {
        notify("", SESSION_INITIALIZED, NULL, 0);
    }
    else if (state == ElaStreamState_connected) {
        notify("", SESSION_CONNECTED, NULL, 0);
    }
    else if (state == ElaStreamState_transport_ready) {
        notify("", SESSION_TRANSPORT_READY, NULL, 0);
    }
}

static void StreamReceiveData(
    ElaSession *ws,
    int stream,
    const void *data,
    size_t len,
    void *context)
{
    RPC_LOG("Stream %d received data len: %d\n", stream, len);

    pthread_mutex_lock(&gMutex);

    free_data();
    gData = new DataPack();
    if (!gData) {
        RPC_LOG("Receive message new DataPack failed.\n");
        pthread_mutex_unlock(&gMutex);
        return;
    }
    // gData->from = from;
    gData->stream = stream;

    ArrayOf<Byte>* buf = ArrayOf<Byte>::Alloc(len);
    if (!data) {
        pthread_mutex_unlock(&gMutex);
        return;
    }

    memcpy(buf->GetPayload(), data, len);
    gData->data = buf;

    pthread_cond_broadcast(&gCv);

    pthread_mutex_unlock(&gMutex);

    return;
}

static void SessionRequestComplete(
    ElaSession *ws,
    int status,
    const char *reason,
    const char *sdp,
    size_t len,
    void *context)
{
    RPC_LOG("Session complete, status: %d, reason: %s\n", status,
           reason ? reason : "null");

    if (status != 0)
        return;

    strncpy(session_ctx.remote_sdp, sdp, len);
    session_ctx.remote_sdp[len] = 0;
    session_ctx.sdp_len = len;

    notify("", SESSION_REQUEST_COMPLETED, NULL, 0);
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


    int ret = ela_session_init(gCarrier, SessionRequestCallback, NULL);
    if (ret != 0) {
        RPC_LOG("Error init session: 0x%x\n", ela_get_error());
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
        gCarrier = NULL;
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

    if (strlen(location) == 0) {
        return -1;
    }

    int ret = pthread_create(&gCarrierThread, NULL, carrierThread, (void*)location);
    if (ret != 0) {
        RPC_LOG("Create thread failed\n");
        return -1;
    }

    RPC_LOG("carrier_connect waitting for online\n");
    int type;
    void* buf;
    int len;
    ret = carrier_receive(NULL, &type, &buf, &len);
    if (ret != 0) {
        RPC_LOG("carrier_connect waitting for online failed: %d\n", ret);
        return -1;
    }

    if (type == SELF_ONLINE) {
        RPC_LOG("carrier_connect is online\n");
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
    int type,
    void* msg,
    size_t len)
{
    if (gCarrier == NULL) {
        return -1;
    }

    size_t msgLen = len + 4;
    ArrayOf<Byte>* data = ArrayOf<Byte>::Alloc(msgLen);
    if (data == NULL) {
        return -1;
    }

    void* p = data->GetPayload();
    memcpy(p, &type, 4);
    p += 4;
    if (msg != NULL) {
        memcpy(p, msg, len);
        p += len;
    }


    int rc =  ela_stream_write(session_ctx.ws, session_ctx.stream, 
                                data->GetPayload(), msgLen);
    ArrayOf<Byte>::Free(data);
    if (rc > 0) {
        RPC_LOG("Send message success stream[%d] len[%d].\n",
                                session_ctx.stream, msgLen);
        return 0;
    }
    else {
        RPC_LOG("Send message failed(0x%x).\n", ela_get_error());
        return rc;
    }
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
            RPC_LOG("carrier_wait error: %d\n", ret);
            break;
        }
    }
    pthread_mutex_unlock(&gMutex);

    return ret;
}

ELAPI_(int) ECO_PUBLIC carrier_read(
    DataPack* outData,
    Boolean clearData)
{
    if (outData == NULL) {
        RPC_LOG("carrier_read invalid parameter\n");
        return -1;
    }

    pthread_mutex_lock(&gMutex);
    if (gData == NULL) {
        pthread_mutex_unlock(&gMutex);
        RPC_LOG("carrier_read data is null\n");
        return -1;
    }

    // outData->from = gData->from;
    ArrayOf<Byte>* data = gData->data->Clone();
    outData->data = data;

    if (clearData) {
        free_data();
    }

    pthread_mutex_unlock(&gMutex);
    return 0;
}

ELAPI_(void) ECO_PUBLIC carrier_destroy()
{
    if (gCarrier != NULL) {
        ela_session_cleanup(gCarrier);
        ela_kill(gCarrier);
        gCarrier = NULL;
    }

    if (gCarrierThread != 0) {
        pthread_join(gCarrierThread, NULL);
        gCarrierThread = 0;
    }

    free_data();
}

ELAPI_(void) ECO_PUBLIC carrier_data_handled()
{
    free_data();
}

int carrier_receive(
    const char* from,
    int* type,
    void** buf,
    int* len)
{
    int ret = carrier_wait(-1);
    if (ret != 0) {
        return ret;
    }

    DataPack data;
    ret = carrier_read(&data);
    if (ret != 0) {
        return ret;
    }

    if (from != NULL && data.from != NULL && strcmp(from, data.from)) {
        RPC_LOG("carrier_receive receive msg not from target\n");
        return -1;
    }

    void* p = data.data->GetPayload();
    int _len = data.data->GetLength();
    int _type = *(size_t *)p;
    p += 4;
    _len -= 4;

    void* _base = malloc(_len);
    if (_base == NULL) {
        ArrayOf<Byte>::Free(data.data);
        return -1;
    }
    memcpy(_base, p, _len);
    *type = _type;
    if (buf != NULL) {
        *buf = _base;
        *len = _len;
    }
    
    ArrayOf<Byte>::Free(data.data);

    return 0;
}

int carrier_wait_message(
    int type,
    const char* from,
    void** buf,
    int* len)
{
    int _type;
    int ret;
    while(true) {
        ret = carrier_receive(NULL, &_type, buf, len);
        if (ret != 0) {
            return ret;
        }

        if (type == _type) {
            break;
        }
    }

    return 0;
}

int session_new(
    ElaCarrier* carrier,
    const char* uid)
{
    RPC_LOG("Session new \n");
    session_ctx.ws = ela_session_new(carrier, uid);
    if (!session_ctx.ws) {
        RPC_LOG("Create session failed.\n");
        return -1;
    } else {
        RPC_LOG("Create session successfully.\n");
    }

    ElaStreamCallbacks callbacks;

    memset(&callbacks, 0, sizeof(callbacks));
    callbacks.state_changed = StreamStateChanged;
    callbacks.stream_data = StreamReceiveData;

    session_ctx.stream = ela_session_add_stream(session_ctx.ws, ElaStreamType_text,
                ELA_STREAM_RELIABLE | ELA_STREAM_MULTIPLEXING, &callbacks, NULL);
    if (session_ctx.stream < 0) {
        ela_session_close(session_ctx.ws);
        session_ctx.ws = NULL;
        RPC_LOG("Add stream failed.\n");
        return -1;
    }
    else {
        RPC_LOG("Add stream successfully and stream id %d.\n", session_ctx.stream);
    }

    int ret = carrier_wait_message(SESSION_INITIALIZED, NULL, NULL, NULL);
    if (ret != 0) {
        RPC_LOG("Carrier session connect wait stream init failed\n");
    }

    return ret;
}

// for receiver
int session_connect(
    ElaCarrier* carrier,
    const char* uid)
{
    if (session_ctx.ws != NULL) {
        return 0;
    }

    int ret = session_new(carrier, uid);
    if (ret != 0) {
        return ret;
    }

    ret = ela_session_reply_request(session_ctx.ws, 0, NULL);
    if (ret < 0) {
        RPC_LOG("Session response invite failed:%x.\n", ela_get_error());
        goto exit;
    }
    else {
        RPC_LOG("Session response invite successuflly.\n");
    }


    ret = carrier_wait_message(SESSION_TRANSPORT_READY, NULL, NULL, NULL);
    if (ret != 0) {
        RPC_LOG("Carrier session connect wait session connected failed\n");
        goto exit;
    }

    ret = ela_session_start(session_ctx.ws, session_ctx.remote_sdp, session_ctx.sdp_len);
    RPC_LOG("Session start %s 0x%x.\n", ret == 0 ? "success" : "failed", ela_get_error());
    if (ret != 0) {
        goto exit;
    }

    ret = carrier_wait_message(SESSION_CONNECTED, NULL, NULL, NULL);
    if (ret != 0) {
        RPC_LOG("Carrier session connect wait session connected failed\n");
        goto exit;
    }

exit:
    if (ret != 0) {
        carrier_session_destroy();
    }
    return ret;
}

//for sender
ELAPI_(int) ECO_PUBLIC carrier_session_connect(
    ElaCarrier* carrier,
    const char* uid)
{
    if (session_ctx.ws != NULL) {
        return 0;
    }

    int ret = session_new(carrier, uid);
    if (ret != 0) {
        return ret;
    }

    if (carrier_get_friend_status(uid) != ElaConnectionStatus_Connected) {
        ret = carrier_wait_message(FRIEND_ONLINE, uid, NULL, NULL);
        if (ret != 0) {
            RPC_LOG("Carrier session connect wait friend online failed\n");
            goto exit;
        }
    }

    ret = ela_session_request(session_ctx.ws,
                             SessionRequestComplete, NULL);
    if (ret < 0) {
        RPC_LOG("session request failed.\n");
    }
    else {
        RPC_LOG("session request successfully.\n");
    }

    ret = carrier_wait_message(SESSION_REQUEST_COMPLETED, NULL, NULL, NULL);
    if (ret != 0) {
        RPC_LOG("Carrier session connect wait request compeleted failed\n");
        goto exit;
    }

    ret = ela_session_start(session_ctx.ws, session_ctx.remote_sdp, session_ctx.sdp_len);
    RPC_LOG("Session start %s.\n", ret == 0 ? "success" : "failed");
    if (ret != 0) {
        goto exit;
    }

    ret = carrier_wait_message(SESSION_CONNECTED, NULL, NULL, NULL);
    if (ret != 0) {
        RPC_LOG("Carrier session connect wait session connected failed\n");
        goto exit;
    }

    sleep(1);

exit:
    if (ret != 0) {
        carrier_session_destroy();
    }
    return ret;
}


ELAPI_(int) ECO_PUBLIC carrier_session_wait(
    ElaCarrier* carrier)
{
    void* buf;
    int len;

    int ret = carrier_wait_message(SESSION_REQUEST, NULL, &buf, &len);
    if (ret != 0) {
        RPC_LOG("Carrier wait session request failed\n");
        return ret;
    }

    char uid[len + 1];
    memcpy(uid, buf, len);
    free(buf);
    uid[len] = '\0';
    ret = session_connect(carrier, uid);
    if (ret != 0) {
        RPC_LOG("Carrier session connect failed.\n");
        return ret;
    }

    return 0;
}

ELAPI_(void) ECO_PUBLIC carrier_session_destroy()
{
    if (session_ctx.ws != NULL) {
        ela_session_close(session_ctx.ws);
        session_ctx.ws = NULL;
    }
}
