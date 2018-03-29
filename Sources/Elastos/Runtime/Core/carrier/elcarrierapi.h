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

#ifndef __ELCARRIERAPI_H__
#define __ELCARRIERAPI_H__

#include <unistd.h>
#include <elcontainer.h>
#include <elrefbase.h>
#include "ela_carrier.h"
#include "hashtable.h"

_ELASTOS_NAMESPACE_BEGIN

/** @} */
/** @addtogroup CARRef
  *   @{
  */
class CCarrier
    : public ElRefBase
    , public ICarrier
{
public:
    STATIC CARAPI GetInstance(
        /* [out] */ ICarrier** carrier);

    CARAPI Start(
        /* [in] */ const String& carrierDataPath);

    CARAPI Stop();

    CARAPI RegenerateAddress();

    CARAPI GetAddress(
        /* [out] */ String* myAddress);

    CARAPI AccpetFriendRequest(
        /* [in] */ const String& uid);

    CARAPI AddFriend(
        /* [in] */ const String& friendAddress,
        /* [in] */ const String& hello);

    CARAPI RemoveFriend(
        /* [in] */ IFriend* _friend);

    CARAPI IsOnline(
        /* [out] */ Boolean* online);

    CARAPI GetFriend(
        /* [in] */ const String& uid,
        /* [out] */ IFriend** _friend);

    CARAPI GetFriends(
        /* [out, callee] */ ArrayOf<IFriend*>** friends);

    CARAPI AddCarrierNodeListener(
        /* [in] */ ICarrierListener* listener);

    CARAPI RemoveCarrierNodeListener(
        /* [in] */ ICarrierListener* listener);

    CARAPI Import(
        /* [in] */ const String& dataPath);

    CARAPI Export(
        /* [out] */ String* dataPath);

    CARAPI_(UInt32) AddRef();

    CARAPI_(UInt32) Release();

    CARAPI_(PInterface) Probe(
        /* [in] */ REIID riid);

    CARAPI GetInterfaceID(
        /* [in] */ IInterface* object,
        /* [out] */ InterfaceID* iid);

    CARAPI GetCarrierHandle(
        /* [out] */ Handle64* handle);

    //Local functions for distribute the callback.
    CARAPI DistributeOnConnectionChanged(
        /* [in] */ Boolean online);

    CARAPI DistributeOnReady();

    CARAPI DistributeOnFriendRequest(
        /* [in] */ const String& uid,
        /* [in] */ const String& hello);

    CARAPI DistributeOnFriendConnetionChanged(
        /* [in] */ const String& uid,
        /* [in] */ Boolean online);

    static CARAPI_(CCarrier*) GetLocalInstance();

    ~CCarrier();

private:
    //CFriend: include the friend's information.
    class CFriend
        : public ElRefBase
        , public IFriend
    {
    public:
        CFriend(
            /* [in] */ const String& uid,
            /* [in] */ Boolean online);

        CARAPI GetUid(
            /* [out] */ String* uid);

        CARAPI GetName(
            /* [out] */ String* name);

        CARAPI SetLabel(
            /* [in] */ const String& label);

        CARAPI GetLabel(
            /* [out] */ String* label);

        CARAPI IsOnline(
            /* [out] */ Boolean* online);

        CARAPI UpdateStatus(
            /* [in] */ Boolean online);

        CARAPI_(UInt32) AddRef();

        CARAPI_(UInt32) Release();

        CARAPI_(PInterface) Probe(
            /* [in] */ REIID riid);

        CARAPI GetInterfaceID(
            /* [in] */ IInterface* object,
            /* [out] */ InterfaceID* iid);

    private:
        String mUid;
        String mLabel;
        String mName;
        Boolean mIsOnline;
    };

    class ListenerNode : public SLinkNode
    {
    public:
        ListenerNode(){};

    public:
        AutoPtr<ICarrierListener> mCarrierListener;
    };

    class FriendNode : public SLinkNode
    {
    public:
        FriendNode(){}

        CARAPI Get(
            /* [out] */ IFriend** _friend);

    public:
        String mUid;
        AutoPtr<CFriend> mFriend;
    };

private:
    CCarrier();
    CCarrier(CCarrier const&);
    CCarrier& operator=(CCarrier const&);
    static void *CarrierThread(void *arg);
    CARAPI_(void) Cleanup();

    //Local method about friend list.
    CARAPI_(void) AddFriend2List(
        /* [in] */ const String& uid,
        /* [in] */ Boolean online);

    CARAPI_(void) RemoveFriendFromList(
        /* [in] */ IFriend* _friend);

private:
    //This instance: distributing the callbacks.
    static AutoPtr<CCarrier> sGlobalCarrier;

    ElaCarrier* mElaCarrier;
    ListenerNode mListeners;
    pthread_mutex_t mListenersLock;

    FriendNode mFriendList;
    pthread_mutex_t mFriendListLock;

    //Carrier thread id
    pthread_t m_carrierThreadId;

    //Carrier's data path
    String mDataPath;
    //Carrier's status
    Boolean mIsOnline;

    //Carrier is ready
    Boolean mIsReady;
};

_ELASTOS_NAMESPACE_END

#endif // __ELCARRIERAPI_H__
/** @} */
