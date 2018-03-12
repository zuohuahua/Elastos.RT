
#include "CarrierProxy.h"
#include "log.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

static void connection_callback(
    /* [in] */ ElaCarrier *w,
    /* [in] */ ElaConnectionStatus status,
    /* [in] */ void *context)
{
    assert(CarrierProxy::mCarrierNodeListener != NULL);
    switch (status) {
    case ElaConnectionStatus_Connected:
        LOGD("[connection_callback] Connected to carrier network.\n");
        break;

    case ElaConnectionStatus_Disconnected:
        LOGD("[connection_callback] Disconnect from carrier network.\n");
        break;

    default:
        LOGD("[connection_callback] Error!!! Got unknown connection status %d.\n", status);
    }
    CarrierProxy::mCarrierNodeListener->OnConnection(status);
}

static void friend_connection_callback(
    /* [in] */ ElaCarrier *w,
    /* [in] */ const char *friendid,
    /* [in] */ ElaConnectionStatus status,
    /* [in] */ void *context)
{
    switch (status) {
    case ElaConnectionStatus_Connected:
        LOGD("[friend_connection_callback] Friend[%s] connection changed to be online\n", friendid);
        CarrierProxy::sIsOnline = TRUE;
        break;

    case ElaConnectionStatus_Disconnected:
        LOGD("[friend_connection_callback] Friend[%s] connection changed to be offline.\n", friendid);
        break;

    default:
        LOGD("[friend_connection_callback] Error!!! Got unknown connection status %d.\n", status);
    }

    CarrierProxy::mCarrierNodeListener->OnFriendConnection(String(friendid), status);
}

static void friend_request_callback(
    /* [in] */ ElaCarrier *w,
    /* [in] */ const char *userid,
    /* [in] */ const ElaUserInfo *info,
    /* [in] */ const char *hello,
    /* [in] */ void *context)
{
    LOGD("[friend_request_callback] Friend request from user[%s] with HELLO: %s.\n",
           *info->name ? info->name : userid, hello);
    LOGD("[friend_request_callback] Reply use following commands:\n");
    LOGD("[friend_request_callback]   faccept %s\n", userid);
    // assert(0 && "TODO");
    // if (strcmp(hello, "123") == 0) {
    // ela_accept_friend(w, userid);
    // }
    CarrierProxy::mCarrierNodeListener->OnFriendRequest(String(userid), String(hello));
}

const char *presence_name[] = {
    "none",    // None;
    "away",    // Away;
    "busy",    // Busy;
};

static const char *connection_name[] = {
    "online",
    "offline"
};

static void display_friend_info(
    /* [in] */ const ElaFriendInfo *fi)
{
    LOGD("[display_friend_info]           ID: %s\n", fi->user_info.userid);
    LOGD("[display_friend_info]         Name: %s\n", fi->user_info.name);
    LOGD("[display_friend_info]  Description: %s\n", fi->user_info.description);
    LOGD("[display_friend_info]       Gender: %s\n", fi->user_info.gender);
    LOGD("[display_friend_info]        Phone: %s\n", fi->user_info.phone);
    LOGD("[display_friend_info]        Email: %s\n", fi->user_info.email);
    LOGD("[display_friend_info]       Region: %s\n", fi->user_info.region);
    LOGD("[display_friend_info]        Label: %s\n", fi->label);
    LOGD("[display_friend_info]     Presence: %s\n", presence_name[fi->presence]);
    LOGD("[display_friend_info]   Connection: %s\n", connection_name[fi->status]);
}

static void friend_added_callback(
    /* [in] */ ElaCarrier *w,
    /* [in] */ const ElaFriendInfo *info,
    /* [in] */ void *context)
{
    LOGD("[friend_added_callback] New friend added. The friend information:\n");
    display_friend_info(info);
    CarrierProxy::mCarrierNodeListener->OnFreindAdded(String(info->user_info.userid));
}

static void message_callback(
    /* [in] */ ElaCarrier *w,
    /* [in] */ const char *from,
    /* [in] */ const char *msg,
    /* [in] */ size_t len,
    /* [in] */ void *context)
{
    LOGD("[message_callback] Message from friend[%s]: %.*s\n", from, (int)len, msg);
    CarrierProxy::mCarrierNodeListener->OnFriendMessage(String(from), String(msg));
}

static void ready(
    /* [in] */ ElaCarrier *carrier,
    /* [in] */ void *context)
{
    assert(CarrierProxy::mCarrierNodeListener != NULL);
    CarrierProxy::mCarrierNodeListener->OnReady();
}

static struct {
    ElaSession *ws;
    int unchanged_streams;
    char remote_sdp[2048];
    size_t sdp_len;
    int bulk_mode;
    size_t packets;
    size_t bytes;
    struct timeval first_stamp;
    struct timeval last_stamp;
} session_ctx;

static void session_request_callback(
    /* [in] */ ElaCarrier *w,
    /* [in] */ const char *from,
    /* [in] */ const char *sdp,
    /* [in] */ size_t len,
    /* [in] */ void *context)
{
    strncpy(session_ctx.remote_sdp, sdp, len);
    session_ctx.remote_sdp[len] = 0;
    session_ctx.sdp_len = len;

    LOGD("Session request from[%s] with SDP:\n%s.\n", from, session_ctx.remote_sdp);
    LOGD("Reply use following commands:\n");
    LOGD("  sreply refuse [reason]\n");
    LOGD("OR:\n");
    LOGD("  1. snew %s\n", from);
    LOGD("  2. sadd [plain] [reliable] [multiplexing] [portforwarding]\n");
    LOGD("  3. sreply ok\n");
    CarrierProxy::mCarrierNodeListener->OnSessionRequest(String(from));
}

static void stream_on_state_changed(
    /* [in] */ ElaSession *ws,
    /* [in] */ int stream,
    /* [in] */ ElaStreamState state,
    /* [in] */ void *context)
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

    LOGD("Stream [%d] state changed to: %s\n", stream, state_name[state]);
    if (state == 1 /*initialized*/) {
        CarrierProxy::sStreamIsInitialized = TRUE;
        CarrierProxy::mCarrierNodeListener->OnStreamStateChanged(stream, state);
    }
    if (state == ElaStreamState_transport_ready)
        --session_ctx.unchanged_streams;
}

static void stream_on_data(
    /* [in] */ ElaSession *ws,
    /* [in] */ int stream,
    /* [in] */ const void *data,
    /* [in] */ size_t len,
    /* [in] */ void *context)
{
    if (session_ctx.bulk_mode) {
        if (session_ctx.packets % 1000 == 0)
            LOGD(".");

        if (session_ctx.packets)
            gettimeofday(&session_ctx.last_stamp, NULL);
        else
            gettimeofday(&session_ctx.first_stamp, NULL);

        session_ctx.bytes += len;
        session_ctx.packets++;
    } else {
        AutoPtr<ArrayOf<Byte> > temp = ArrayOf<Byte>::Alloc(len);
        void* p = temp->GetPayload();
        p = memcpy(p, data, len);
        String str(*temp);
        LOGD("Stream [%d] received data [%.*s]\n", stream, (int)len, str.string());
        CarrierProxy::mCarrierNodeListener->OnFriendMessage(String("From session: "), str);
    }
}

static void session_request_complete_callback(
    /* [in] */ ElaSession *ws,
    /* [in] */ int status,
    /* [in] */ const char *reason,
    /* [in] */ const char *sdp,
    /* [in] */ size_t len,
    /* [in] */ void *context)
{
    int rc;

    LOGD("Session complete, status: %d, reason: %s\n", status,
           reason ? reason : "null");

    if (status != 0)
        return;

    strncpy(session_ctx.remote_sdp, sdp, len);
    session_ctx.remote_sdp[len] = 0;
    session_ctx.sdp_len = len;

    rc = ela_session_start(session_ctx.ws, session_ctx.remote_sdp,
                               session_ctx.sdp_len);

    LOGD("Session start %s.\n", rc == 0 ? "success" : "failed");
    CarrierProxy::mCarrierNodeListener->OnSessionReady();
}


AutoPtr<ICarrierNodeListener> CarrierProxy::mCarrierNodeListener;
AutoPtr<CarrierProxy> CarrierProxy::sCarrierProxyInsttance;
Boolean CarrierProxy::sIsOnline = FALSE;
Boolean CarrierProxy::sStreamIsInitialized = FALSE;
CarrierProxy::~CarrierProxy()
{
    if (mElaCarrierNode != NULL) {
        ela_kill(mElaCarrierNode);
        mElaCarrierNode = NULL;
    }
    assert(0 && "TODO");
}

Boolean CarrierProxy::sSessionIsReady()
{
    return sIsOnline && sStreamIsInitialized;
}

void CarrierProxy::TrySessionRequest()
{
    if (sSessionIsReady()) {
        GetInstance()->SessionRequest();
    }
}

CarrierProxy* CarrierProxy::GetInstance()
{
    if (sCarrierProxyInsttance == NULL) {
        sCarrierProxyInsttance = new CarrierProxy();
    }
    return sCarrierProxyInsttance;
}

CarrierProxy::CarrierProxy()
    : mStreamId(0)
    , mElaCarrierNode(NULL)
{
}

ECode CarrierProxy::CreateCarrierNodeWithSession()
{
    if (pthread_create(&m_threadID, NULL, S_ServiceRoutine, (void *)this)) {
        assert(0 && "TODO: CarrierProxy");
    }

    return NOERROR;
}

ECode CarrierProxy::InitElaSession()
{
    //Init Session
    int rc = ela_session_init(mElaCarrierNode, session_request_callback, NULL);
    if (rc < 0) {
        LOGD("Session initialized failed.\n");
    }
    else {
        LOGD("Session initialized successfully.\n");
    }
    return NOERROR;
}

ECode CarrierProxy::CreateElaSession(
    /* [in] */ const String& userid)
{
    session_ctx.ws = ela_session_new(mElaCarrierNode, userid.string());
    if (!session_ctx.ws) {
        LOGD("Create session failed.\n");
    } else {
        LOGD("Create session successfully.\n");
    }

    session_ctx.unchanged_streams = 0;

    AddSessionStream();

    return NOERROR;
}

void CarrierProxy::AddSessionStream()
{
    int rc;
    int options = 0;

    ElaStreamCallbacks callbacks;

    memset(&callbacks, 0, sizeof(callbacks));
    callbacks.state_changed = stream_on_state_changed;
    callbacks.stream_data = stream_on_data;

    Int32 argc = 2;
    const char* argv[2] = {"reliable", "plain"};
    if (argc < 1) {
        LOGD("Invalid command syntax.\n");
        return;
    } else if (argc > 1) {
        int i;

        for (i = 1; i < argc; i++) {
            if (strcmp(argv[i], "reliable") == 0) {
                options |= ELA_STREAM_RELIABLE;
            } else if (strcmp(argv[i], "plain") == 0) {
                options |= ELA_STREAM_PLAIN;
            } else if (strcmp(argv[i], "multiplexing") == 0) {
                options |= ELA_STREAM_MULTIPLEXING;
            } else if (strcmp(argv[i], "portforwarding") == 0) {
                options |= ELA_STREAM_PORT_FORWARDING;
            } else {
                LOGD("Invalid command syntax.\n");
                return;
            }
        }
    }

    if ((options & ELA_STREAM_MULTIPLEXING) || (options & ELA_STREAM_PORT_FORWARDING)) {
        assert(0 && "TODO");
        // callbacks.channel_open = on_channel_open;
        // callbacks.channel_opened = on_channel_opened;
        // callbacks.channel_data = on_channel_data;
        // callbacks.channel_pending = on_channel_pending;
        // callbacks.channel_resume = on_channel_resume;
        // callbacks.channel_close = on_channel_close;
    }

    rc = ela_session_add_stream(session_ctx.ws, ElaStreamType_text,
                                options, &callbacks, NULL);
    if (rc < 0) {
        LOGD("Add stream failed.\n");
    }
    else {
        session_ctx.unchanged_streams++;
        mStreamId = rc;
        LOGD("Add stream successfully and stream id %d.\n", rc);
    }
}

void *CarrierProxy::S_ServiceRoutine(void *arg)
{
    CarrierProxy* pThis = (CarrierProxy *)arg;
    ElaCallbacks callbacks;
    memset(&callbacks, 0, sizeof(callbacks));
    callbacks.connection_status = connection_callback;
    callbacks.friend_connection = friend_connection_callback;
    callbacks.friend_request = friend_request_callback;
    callbacks.friend_added = friend_added_callback;
    callbacks.friend_message = message_callback;
    callbacks.ready = ready;

    ElaOptions opts;
    memset(&opts, 0, sizeof(opts));
    opts.udp_enabled = true;
    opts.persistent_location = "/data/data/com.elastos.carrier.elastoscarriersession/";
    opts.bootstraps_size = 1;
    opts.bootstraps = (BootstrapNode *)calloc(1, sizeof(BootstrapNode) * 1);
    if (!opts.bootstraps) {
        assert(0 && "TODO");
    }

    opts.bootstraps[0].ipv4 = "13.58.208.50";
    opts.bootstraps[0].port = "33445";
    opts.bootstraps[0].public_key = "89vny8MrKdDKs7Uta9RdVmspPjnRMdwMmaiEW27pZ7gh";

    pThis->mElaCarrierNode = ela_new(&opts, &callbacks, NULL);
    if (pThis->mElaCarrierNode == NULL) {
        LOGD("Error start carrier loop: 0x%x\n", ela_get_error());
        assert(0 && "TODO");
    }

    char buf[ELA_MAX_ADDRESS_LEN+1];
    LOGD("Carrier node identities:\n");
    LOGD("   Node ID: %s\n", ela_get_nodeid(pThis->mElaCarrierNode, buf, sizeof(buf)));
    LOGD("   User ID: %s\n", ela_get_userid(pThis->mElaCarrierNode, buf, sizeof(buf)));
    LOGD("   Address: %s\n\n", ela_get_address(pThis->mElaCarrierNode, buf, sizeof(buf)));

    int rc = ela_run(pThis->mElaCarrierNode, 10);
    if (rc != 0) {
        LOGD("Error start carrier loop: 0x%x\n", ela_get_error());
        ela_kill(pThis->mElaCarrierNode);
        pThis->mElaCarrierNode = NULL;
    }

    return NULL;
}

Int32 CarrierProxy::AddFriend(
    /* [in] */ const String& address,
    /* [in] */ const String& hello)
{
    Int32 result = ela_add_friend(mElaCarrierNode, address.string(), hello.string());
    if (result != 0) {
    }
    return result;
}

ECode CarrierProxy::AcceptRequest(
    /* [in] */ const String& userid)
{
    ela_accept_friend(mElaCarrierNode, userid.string());
    return NOERROR;
}

ECode CarrierProxy::SetCarrierNodeListener(
    /* [in] */ ICarrierNodeListener* listener)
{
    assert(listener != NULL);
    mCarrierNodeListener = listener;
    return NOERROR;
}

ECode CarrierProxy::ReplySessionRequest(
    /* [in] */ Boolean agree)
{
    int rc = 0;
    if (!sSessionIsReady()) {
        return NOERROR;
    }

    if (agree) {
        rc = ela_session_reply_request(session_ctx.ws, 0, NULL);
        if (rc < 0) {
            LOGD("response reply_request failed, errorcode=[0x%08x].\n", ela_get_error());
        }
        else {
            LOGD("response invite successuflly.\n");

            while (session_ctx.unchanged_streams > 0)
                usleep(200);

            rc = ela_session_start(session_ctx.ws, session_ctx.remote_sdp,
                                       session_ctx.sdp_len);

            LOGD("Session start %s.\n", rc == 0 ? "success" : "failed");
            mCarrierNodeListener->OnSessionReady();
        }
    }
    else {
        rc = ela_session_reply_request(session_ctx.ws, 1, "refuse reason");
        if (rc < 0) {
            LOGD("response invite failed.\n");
        }
        else {
            LOGD("response invite successuflly.\n");
        }
    }

    return NOERROR;
}

ECode CarrierProxy::SessionRequest()
{
    int rc = ela_session_request(session_ctx.ws,
                             session_request_complete_callback, NULL);
    if (rc < 0) {
        LOGD("session request failed.\n");
    }
    else {
        LOGD("session request successfully.\n");
    }
    return NOERROR;
}

ECode CarrierProxy::GetAddress(
    /* [out] */ String* address)
{
    char buf[ELA_MAX_ADDRESS_LEN + 1];
    ela_get_address(mElaCarrierNode, buf, sizeof(buf));
    *address = String(buf);
    return NOERROR;
}

ECode CarrierProxy::SendMessage(
    /* [in] */ const String& userid,
    /* [in] */ const String& msg)
{
    if (ela_is_friend(mElaCarrierNode, userid)) {
        // int rc = ela_send_friend_message(mElaCarrierNode, userid.string(), msg.string(), msg.GetLength());
        // if (rc == 0) {
        //     LOGD("[CarrierProxy] [%s]====[Send message success.]=======line=[%d]\n", __FUNCTION__, __LINE__);
        // }
        // else {
        //     LOGD("[CarrierProxy] [%s]====Send message failed error=[0x%x]=======line=[%d]\n", __FUNCTION__, __LINE__, ela_get_error());
        // }

        int rc = ela_stream_write(session_ctx.ws, mStreamId,
                (void*)msg.GetBytes()->GetPayload(), msg.GetByteLength());
        if (rc < 0) {
            LOGD("write data failed,  errorcode=[0x%08x]\n", ela_get_error());
        }
        else {
            LOGD("write data successfully.\n");
        }
    }
    return NOERROR;
}
