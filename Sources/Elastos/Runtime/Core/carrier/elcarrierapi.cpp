//=========================================================================
// Copyright (C) 2018 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#include <elcarrierapi.h>

#ifndef VALIDATE_NOT_NULL
#define VALIDATE_NOT_NULL(x) if (!x) { return E_INVALID_ARGUMENT; }
#endif

#ifdef _android
#include <android/log.h>
#define CARRIER_LOG(...) __android_log_print(ANDROID_LOG_DEBUG, "ElCarrier", __VA_ARGS__)
#else
#define CARRIER_LOG printf
#endif

ELAPI _CCarrier_GetInstance(
    /* [out] */ ICarrier** carrier)
{
    return Elastos::CCarrier::GetInstance(carrier);
}

_ELASTOS_NAMESPACE_BEGIN


static void OnConnectionChanged(
    /* [in] */ ElaCarrier *w,
    /* [in] */ ElaConnectionStatus status,
    /* [in] */ void *context)
{
    switch (status) {
    case ElaConnectionStatus_Connected:
        CARRIER_LOG("[OnConnectionChanged] Connected to carrier network.\n");
        break;

    case ElaConnectionStatus_Disconnected:
        CARRIER_LOG("[OnConnectionChanged] Disconnect from carrier network.\n");
        break;

    default:
        CARRIER_LOG("[OnConnectionChanged] Error!!! Got unknown connection status %d.\n", status);
    }
    CCarrier::GetLocalInstance()->DistributeOnConnectionChanged(status == 0);
}

static void OnFriendConnetionChanged(
    /* [in] */ ElaCarrier *w,
    /* [in] */ const char *friendid,
    /* [in] */ ElaConnectionStatus status,
    /* [in] */ void *context)
{
    switch (status) {
    case ElaConnectionStatus_Connected:
        CARRIER_LOG("[OnFriendConnetionChanged] Friend[%s] connection changed to be online\n", friendid);
        break;

    case ElaConnectionStatus_Disconnected:
        CARRIER_LOG("[OnFriendConnetionChanged] Friend[%s] connection changed to be offline.\n", friendid);
        break;

    default:
        CARRIER_LOG("[OnFriendConnetionChanged] Error!!! Got unknown connection status %d.\n", status);
    }
    CCarrier::GetLocalInstance()->DistributeOnFriendConnetionChanged(String(friendid), status == 0);
}

static void OnFriendRequest(
    /* [in] */ ElaCarrier *w,
    /* [in] */ const char *userid,
    /* [in] */ const ElaUserInfo *info,
    /* [in] */ const char *hello,
    /* [in] */ void *context)
{
    CARRIER_LOG("[OnFriendRequest] Friend request from user[%s] with HELLO: %s.\n",
           *info->name ? info->name : userid, hello);
    CARRIER_LOG("[OnFriendRequest] Reply use following commands:\n");
    CARRIER_LOG("[OnFriendRequest]   faccept %s\n", userid);
    CCarrier::GetLocalInstance()->DistributeOnFriendRequest(String(userid), String(hello));
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
    CARRIER_LOG("[display_friend_info]           ID: %s\n", fi->user_info.userid);
    CARRIER_LOG("[display_friend_info]         Name: %s\n", fi->user_info.name);
    CARRIER_LOG("[display_friend_info]  Description: %s\n", fi->user_info.description);
    CARRIER_LOG("[display_friend_info]       Gender: %s\n", fi->user_info.gender);
    CARRIER_LOG("[display_friend_info]        Phone: %s\n", fi->user_info.phone);
    CARRIER_LOG("[display_friend_info]        Email: %s\n", fi->user_info.email);
    CARRIER_LOG("[display_friend_info]       Region: %s\n", fi->user_info.region);
    CARRIER_LOG("[display_friend_info]        Label: %s\n", fi->label);
    CARRIER_LOG("[display_friend_info]     Presence: %s\n", presence_name[fi->presence]);
    CARRIER_LOG("[display_friend_info]   Connection: %s\n", connection_name[fi->status]);
}

static void OnFriendAdded(
    /* [in] */ ElaCarrier *w,
    /* [in] */ const ElaFriendInfo *info,
    /* [in] */ void *context)
{
    CARRIER_LOG("[OnFriendAdded] New friend added. The friend information:\n");
    display_friend_info(info);
}

static void OnFriendMessage(
    /* [in] */ ElaCarrier *w,
    /* [in] */ const char *from,
    /* [in] */ const char *msg,
    /* [in] */ size_t len,
    /* [in] */ void *context)
{
    CARRIER_LOG("[OnFriendMessage] Message from friend[%s]: %.*s\n", from, (int)len, msg);
}

static void OnReady(
    /* [in] */ ElaCarrier *carrier,
    /* [in] */ void *context)
{
    CCarrier::GetLocalInstance()->DistributeOnReady();
}

static bool OnFriendsList(
    ElaCarrier *w,
    const ElaFriendInfo *friend_info,
    void *context)
{
    return true;
}


AutoPtr<ICarrier> CCarrier::sGlobalCarrier;
Boolean CCarrier::sInitialized = FALSE;

CCarrier* CCarrier::sLocalInstance = NULL;
CCarrier::CCarrier()
    : mElaCarrier(NULL)
    , mListenersLock(PTHREAD_MUTEX_INITIALIZER)
    , mFriendsTableLock(PTHREAD_MUTEX_INITIALIZER)
    , m_carrierThreadId(0)
    , mIsOnline(FALSE)
{}

CCarrier::~CCarrier()
{
    if (mElaCarrier != NULL) {
        ela_kill(mElaCarrier);
        mElaCarrier = NULL;
    }
}

ECode CCarrier::GetInstance(
    /* [out] */ ICarrier** carrier)
{
    VALIDATE_NOT_NULL(carrier);

    if (sGlobalCarrier == NULL) {
        sGlobalCarrier = new CCarrier();
    }
    *carrier = sGlobalCarrier;
    return NOERROR;
}

ECode CCarrier::GetCarrierHandle(
    /* [out] */ Handle64* handle)
{
    VALIDATE_NOT_NULL(handle);
    *handle = (Handle64)mElaCarrier;
    return NOERROR;
}

ECode CCarrier::Start(
    /* [in] */ const String& carrierDataPath)
{
    mDataPath = carrierDataPath;
    if (pthread_create(&m_carrierThreadId, NULL, CarrierThread, (void *)this)) {
        CARRIER_LOG("Create thread failed.\n");
        return E_FAIL;
    }
    sLocalInstance = this;
    return NOERROR;
}

void *CCarrier::CarrierThread(void *arg)
{
    CCarrier* proxy = (CCarrier *)arg;
    ElaCallbacks callbacks;
    memset(&callbacks, 0, sizeof(callbacks));
    callbacks.connection_status = OnConnectionChanged;
    callbacks.ready = OnReady;
    callbacks.friend_request = OnFriendRequest;
    callbacks.friend_connection = OnFriendConnetionChanged;
    callbacks.friend_list = OnFriendsList;
    callbacks.friend_message = OnFriendMessage;
    callbacks.friend_added = OnFriendAdded;

    ElaOptions opts;
    memset(&opts, 0, sizeof(opts));
    opts.udp_enabled = true;
    opts.persistent_location = proxy->mDataPath.string();
    opts.bootstraps_size = 1;
    opts.bootstraps = (BootstrapNode *)calloc(1, sizeof(BootstrapNode) * 1);
    if (!opts.bootstraps) {
        CARRIER_LOG("out of memory.\n");
        return NULL;
    }

    opts.bootstraps[0].ipv4 = "13.58.208.50";
    opts.bootstraps[0].port = "33445";
    opts.bootstraps[0].public_key = "89vny8MrKdDKs7Uta9RdVmspPjnRMdwMmaiEW27pZ7gh";

    proxy->mElaCarrier = ela_new(&opts, &callbacks, NULL);
    if (proxy->mElaCarrier == NULL) {
        CARRIER_LOG("Error start carrier loop: 0x%x\n", ela_get_error());
        return NULL;
    }

    char buf[ELA_MAX_ADDRESS_LEN + 1];
    CARRIER_LOG("Carrier node identities:\n");
    CARRIER_LOG("   Node ID: %s\n", ela_get_nodeid(proxy->mElaCarrier, buf, sizeof(buf)));
    CARRIER_LOG("   User ID: %s\n", ela_get_userid(proxy->mElaCarrier, buf, sizeof(buf)));
    CARRIER_LOG("   Address: %s\n\n", ela_get_address(proxy->mElaCarrier, buf, sizeof(buf)));

    int rc = ela_run(proxy->mElaCarrier, 10);
    if (rc != 0) {
        CARRIER_LOG("Error start carrier loop: 0x%x\n", ela_get_error());
        ela_kill(proxy->mElaCarrier);
        proxy->mElaCarrier = NULL;
    }

    return NULL;
}

ECode CCarrier::Stop()
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CCarrier::RegenerateAddress()
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CCarrier::GetAddress(
    /* [out] */ String* myAddress)
{
    VALIDATE_NOT_NULL(myAddress);
    char buf[ELA_MAX_ADDRESS_LEN + 1];
    ela_get_address(mElaCarrier, buf, sizeof(buf));
    *myAddress = String(buf);
    return NOERROR;
}

ECode CCarrier::AccpetFriendRequest(
    /* [in] */ const String& uid)
{
    Int32 rc = ela_accept_friend(mElaCarrier, uid);
    if (rc == 0) {
        CARRIER_LOG("Accept friend request success.\n");
    }
    else {
        CARRIER_LOG("Accept friend request failed(0x%x).\n", ela_get_error());
    }
    return NOERROR;
}

ECode CCarrier::AddFriend(
    /* [in] */ const String& friendAddress,
    /* [in] */ const String& hello)
{
    Int32 rc = ela_add_friend(mElaCarrier, friendAddress.string(), hello.string());
    if (rc == 0) {
        CARRIER_LOG("Request to add a new friend succeess.\n");
    }
    else {
        CARRIER_LOG("Request to add a new friend failed(0x%x).\n", ela_get_error());
    }
    return NOERROR;
}

ECode CCarrier::RemoveFriend(
    /* [in] */ IFriend* _friend)
{
    VALIDATE_NOT_NULL(_friend);

    String uid;
    _friend->GetUid(&uid);
    Int32 rc = ela_remove_friend(mElaCarrier, uid.string());
    if (rc == 0) {
        CARRIER_LOG("Remove friend %s success.\n", uid.string());
    }
    else {
        CARRIER_LOG("Remove friend %s failed (0x%x).\n", uid.string(), ela_get_error());
    }
    return NOERROR;
}

ECode CCarrier::IsOnline(
    /* [out] */ Boolean* online)
{
    VALIDATE_NOT_NULL(online);
    *online = mIsOnline;
    return NOERROR;
}

ECode CCarrier::GetFriend(
    /* [in] */ const String& uid,
    /* [out] */ IFriend** _friend)
{
    VALIDATE_NOT_NULL(_friend);
    CFriend** f = mFriendsTable.Get(const_cast<char*>(uid.string()));
    *_friend = (IFriend*)(*f)->Probe(EIID_IFriend);

    //The caller need to use AutoPtr<IFriend> xxx to get the interface.
    (*f)->AddRef();
    return NOERROR;
}

ECode CCarrier::GetFriends(
    /* [out, callee] */ ArrayOf<IFriend*>** friends)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CCarrier::AddCarrierNodeListener(
    /* [in] */ ICarrierListener* listener)
{
    pthread_mutex_lock(&mListenersLock);
    Boolean contains = FALSE;
    ListenerNode* it = &mListeners;
    for (; NULL != it; it = (ListenerNode*)(it->Next())) {
        if (it->mCarrierListener.Get() == listener) {
            contains = TRUE;
            break;
        }
    }

    if (!contains) {
        ListenerNode* listenerNode = new ListenerNode;
        listenerNode->mCarrierListener = listener;
        mListeners.InsertFirst(listenerNode);
    }
    pthread_mutex_unlock(&mListenersLock);

    return NOERROR;
}

ECode CCarrier::RemoveCarrierNodeListener(
    /* [in] */ ICarrierListener* listener)
{
    pthread_mutex_lock(&mListenersLock);
    ListenerNode* prev = NULL;
    ListenerNode* it = &mListeners;
    for (; NULL != it; it = (ListenerNode*)(it->Next())) {
        if (it->mCarrierListener.Get() == listener) {
            it->mCarrierListener = NULL;

            ListenerNode* head = &mListeners;
            if (it != head) {
                it->Detach(prev);
                delete it;
            }

            pthread_mutex_unlock(&mListenersLock);
            return NOERROR;
        }
        prev = it;
    }

    CARRIER_LOG("Remove a non-existent Listener.\n");
    pthread_mutex_unlock(&mListenersLock);
    return NOERROR;
}

ECode CCarrier::Import(
    /* [in] */ const String& dataPath)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CCarrier::Export(
    /* [out] */ String* dataPath)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CCarrier::DistributeOnConnectionChanged(
    /* [in] */ Boolean online)
{
    //Set the carrier's status
    mIsOnline = online;

    //Distribute the callback: OnConnectionChanged
    pthread_mutex_lock(&mListenersLock);
    ListenerNode* it = &mListeners;
    for (; NULL != it; it = (ListenerNode*)(it->Next())) {
        it->mCarrierListener->OnConnectionChanged(online);
    }
    pthread_mutex_unlock(&mListenersLock);

    return NOERROR;
}

ECode CCarrier::DistributeOnReady()
{
    //Distribute the callback: OnReady.
    pthread_mutex_lock(&mListenersLock);
    ListenerNode* it = &mListeners;
    for (; NULL != it; it = (ListenerNode*)(it->Next())) {
        it->mCarrierListener->OnReady();
    }
    pthread_mutex_unlock(&mListenersLock);

    return NOERROR;
}

ECode CCarrier::DistributeOnFriendRequest(
    /* [in] */ const String& uid,
    /* [in] */ const String& hello)
{
    //Distribute the callback: OnFriendRequest
    pthread_mutex_lock(&mListenersLock);
    ListenerNode* it = &mListeners;
    for (; NULL != it; it = (ListenerNode*)(it->Next())) {
        it->mCarrierListener->OnFriendRequest(uid, hello);
    }
    pthread_mutex_unlock(&mListenersLock);

    return NOERROR;
}

ECode CCarrier::DistributeOnFriendConnetionChanged(
    /* [in] */ const String& uid,
    /* [in] */ Boolean online)
{
    //Update the friends table.
    pthread_mutex_lock(&mFriendsTableLock);
    if (!mFriendsTable.Contains(const_cast<char*>(uid.string()))) {
        //Add the new friend to the table.
        CFriend* f = new CFriend(uid);
        if (!mFriendsTable.Put(const_cast<char*>(uid.string()), (CFriend**)&f)) {
            delete f;

            pthread_mutex_unlock(&mFriendsTableLock);
            return E_OUT_OF_MEMORY;
        }
    }
    else {
        CFriend** _friend = mFriendsTable.Get(const_cast<char*>(uid.string()));
        (*_friend)->UpdateStatus(online);
    }
    pthread_mutex_unlock(&mFriendsTableLock);

    //Distribute the callback: OnFriendConnetionChanged
    pthread_mutex_lock(&mListenersLock);
    ListenerNode* it = &mListeners;
    for (; NULL != it; it = (ListenerNode*)(it->Next())) {
        it->mCarrierListener->OnFriendConnetionChanged(uid, online);
    }
    pthread_mutex_unlock(&mListenersLock);

    return NOERROR;
}

CCarrier* CCarrier::GetLocalInstance()
{
    assert(sLocalInstance != NULL);
    return sLocalInstance;
}

PInterface CCarrier::Probe(
    /* [in] */ REIID riid)
{
    if (riid == EIID_IInterface) {
        return (PInterface)this;
    }
    else if (riid == EIID_ICarrier) {
        return (ICarrier*)this;
    }

    return NULL;
}

UInt32 CCarrier::AddRef()
{
    return ElRefBase::AddRef();
}

UInt32 CCarrier::Release()
{
    return ElRefBase::Release();
}

ECode CCarrier::GetInterfaceID(
    /* [in] */ IInterface* object,
    /* [out] */ InterfaceID* iid)
{
    VALIDATE_NOT_NULL(iid);
    if (object == (IInterface *)(ICarrier *)this) {
        *iid = EIID_ICarrier;
    }
    else {
        return E_INVALID_ARGUMENT;
    }
    return NOERROR;
}


CCarrier::CFriend::CFriend(
    /* [in] */ const String& uid)
    : mUid(uid)
    , mIsOnline(FALSE)
{}

ECode CCarrier::CFriend::GetUid(
    /* [out] */ String* uid)
{
    VALIDATE_NOT_NULL(uid);
    *uid = mUid;
    return NOERROR;
}

ECode CCarrier::CFriend::GetName(
    /* [out] */ String* name)
{
    VALIDATE_NOT_NULL(name);
    *name = mName;
    return NOERROR;
}

ECode CCarrier::CFriend::SetLabel(
    /* [in] */ const String& label)
{
    mLabel = label;
    return NOERROR;
}

ECode CCarrier::CFriend::GetLabel(
    /* [out] */ String* label)
{
    VALIDATE_NOT_NULL(label);
    *label = mLabel;
    return NOERROR;
}

ECode CCarrier::CFriend::IsOnline(
    /* [out] */ Boolean* online)
{
    VALIDATE_NOT_NULL(online);
    *online = mIsOnline;
    return NOERROR;
}

ECode CCarrier::CFriend::UpdateStatus(
    /* [in] */ Boolean online)
{
    mIsOnline = online;
    return NOERROR;
}

UInt32 CCarrier::CFriend::AddRef()
{
    return ElRefBase::AddRef();
}

UInt32 CCarrier::CFriend::Release()
{
    return ElRefBase::Release();
}

PInterface CCarrier::CFriend::Probe(
    /* [in] */ REIID riid)
{
    if (riid == EIID_IInterface) {
        return (PInterface)this;
    }
    else if (riid == EIID_IFriend) {
        return (IFriend*)this;
    }

    return NULL;
}

ECode CCarrier::CFriend::GetInterfaceID(
    /* [in] */ IInterface* object,
    /* [out] */ InterfaceID* iid)
{
    VALIDATE_NOT_NULL(iid);
    if (object == (IInterface *)(IFriend *)this) {
        *iid = EIID_IFriend;
    }
    else {
        return E_INVALID_ARGUMENT;
    }
    return NOERROR;
}

_ELASTOS_NAMESPACE_END
