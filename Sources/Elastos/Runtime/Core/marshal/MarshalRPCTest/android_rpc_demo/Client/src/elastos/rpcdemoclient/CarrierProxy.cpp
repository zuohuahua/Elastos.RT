
#include "CarrierProxy.h"
#include "log.h"
#include <assert.h>
#include <stdlib.h>

static void connection_callback(ElaCarrier *w, ElaConnectionStatus status,
                                void *context)
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
    CarrierProxy::mCarrierNodeListener->OnConnectionStatus(status);
}

static void friend_connection_callback(ElaCarrier *w, const char *friendid,
                                       ElaConnectionStatus status, void *context)
{
    switch (status) {
    case ElaConnectionStatus_Connected:
        LOGD("[friend_connection_callback] Friend[%s] connection changed to be online\n", friendid);
        break;

    case ElaConnectionStatus_Disconnected:
        LOGD("[friend_connection_callback] Friend[%s] connection changed to be offline.\n", friendid);
        break;

    default:
        LOGD("[friend_connection_callback] Error!!! Got unknown connection status %d.\n", status);
    }
    CarrierProxy::sAnotherUserID = String(friendid);
    CarrierProxy::mCarrierNodeListener->OnFriendConnection(String(friendid), status);
}

static void friend_request_callback(ElaCarrier *w, const char *userid,
                                    const ElaUserInfo *info, const char *hello,
                                    void *context)
{
    LOGD("[friend_request_callback] Friend request from user[%s] with HELLO: %s.\n",
           *info->name ? info->name : userid, hello);
    LOGD("[friend_request_callback] Reply use following commands:\n");
    LOGD("[friend_request_callback]   faccept %s\n", userid);
    // assert(0 && "TODO");
    // if (strcmp(hello, "123") == 0) {
    ela_accept_friend(w, userid);
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

static void display_friend_info(const ElaFriendInfo *fi)
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

static void friend_added_callback(ElaCarrier *w, const ElaFriendInfo *info,
                                  void *context)
{
    LOGD("[friend_added_callback] New friend added. The friend information:\n");
    display_friend_info(info);
    CarrierProxy::sAnotherUserID = String(info->user_info.userid);
    CarrierProxy::mCarrierNodeListener->OnFreindAdded(String(info->user_info.userid));
}

static void message_callback(ElaCarrier *w, const char *from,
                             const char *msg, size_t len, void *context)
{
    LOGD("[message_callback] Message from friend[%s]: %.*s\n", from, (int)len, msg);
    CarrierProxy::mCarrierNodeListener->OnFriendMessage(String(from), String(msg));
}

static void ready(ElaCarrier *carrier, void *context)
{
    CarrierProxy::sIsReady = TRUE;
    assert(CarrierProxy::mCarrierNodeListener != NULL);
    CarrierProxy::mCarrierNodeListener->OnReady();
}

AutoPtr<ICarrierNodeListener> CarrierProxy::mCarrierNodeListener;
Boolean CarrierProxy::sIsReady = FALSE;
String CarrierProxy::sAnotherUserID;
CarrierProxy::~CarrierProxy()
{
    if (mElaCarrierNode != NULL) {
        ela_kill(mElaCarrierNode);
        mElaCarrierNode = NULL;
    }
}

CarrierProxy::CarrierProxy()
    : mElaCarrierNode(NULL)
{
    if (pthread_create(&m_threadID,
                       NULL,
                       S_ServiceRoutine,
                       (void *)this))
    {
        assert(0 && "TODO: CarrierProxy");
    }
}

void *CarrierProxy::S_ServiceRoutine(void *arg)
{
    CarrierProxy* pThis = (CarrierProxy *)arg;
    ElaCallbacks callbacks;
    memset(&callbacks, 0, sizeof(callbacks));
    // callbacks.idle = idle_callback;
    callbacks.connection_status = connection_callback;
    // callbacks.friend_list = friends_list_callback;
    callbacks.friend_connection = friend_connection_callback;
    // callbacks.friend_info = friend_info_callback;
    // callbacks.friend_presence = friend_presence_callback;
    callbacks.friend_request = friend_request_callback;
    callbacks.friend_added = friend_added_callback;
    // callbacks.friend_removed = friend_removed_callback;
    callbacks.friend_message = message_callback;
    // callbacks.friend_invite = invite_request_callback;
    callbacks.ready = ready;

    ElaOptions opts;
    memset(&opts, 0, sizeof(opts));
    opts.udp_enabled = true;
    // opts.persistent_location = ".data";
    opts.persistent_location = "/data/data/elastos.rpc.demo/";
    opts.bootstraps_size = 1;
    opts.bootstraps = (BootstrapNode *)calloc(1, sizeof(BootstrapNode) * 1);
    if (!opts.bootstraps) {
        // fprintf(stderr, "out of memory.");
        // deref(cfg);
        // return -1;
        assert(0 && "TODO");
    }

    opts.bootstraps[0].ipv4 = "13.58.208.50";
    // opts.bootstraps[0].ipv6 = NULL;
    opts.bootstraps[0].port = "33445";
    opts.bootstraps[0].public_key = "89vny8MrKdDKs7Uta9RdVmspPjnRMdwMmaiEW27pZ7gh";

    pThis->mElaCarrierNode = ela_new(&opts, &callbacks, NULL);
    // assert(w != NULL);
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

void CarrierProxy::AddFriend(
    /* [in] */ const String& address,
    /* [in] */ const String& hello)
{
    ela_add_friend(mElaCarrierNode, address.string(), hello.string());
}

ECode CarrierProxy::SendMsg(
    /* [in] */ const String& msg,
    /* [in] */ const String& userid)
{
    if (ela_is_friend(mElaCarrierNode, userid)) {
        int rc = ela_send_friend_message(mElaCarrierNode, userid.string(), msg.string(), msg.GetLength());
        if (rc == 0) {
            LOGD("[CarrierProxy] [%s]====[Send message success.]=======line=[%d]\n", __FUNCTION__, __LINE__);
        }
        else {
            LOGD("[CarrierProxy] [%s]====Send message failed error=[0x%x]=======line=[%d]\n", __FUNCTION__, __LINE__, ela_get_error());
        }
    }

    return NOERROR;
}

String CarrierProxy::GetUserId()
{
    char buf[ELA_MAX_ADDRESS_LEN + 1];
    ela_get_userid(mElaCarrierNode, buf, sizeof(buf));
    return String(buf);
}

String CarrierProxy::GetAddress()
{
    char buf[ELA_MAX_ADDRESS_LEN + 1];
    ela_get_address(mElaCarrierNode, buf, sizeof(buf));
    return String(buf);
}

ECode CarrierProxy::SetCarrierNodeListener(
    /* [in] */ ICarrierNodeListener* listener)
{
    assert(listener != NULL);
    mCarrierNodeListener = listener;
    return NOERROR;
}
