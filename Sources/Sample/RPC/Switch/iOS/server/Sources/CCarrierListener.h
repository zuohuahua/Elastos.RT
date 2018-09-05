//
//  CCarrierListener.h
//  SwitchServer
//
//  Created by Joel Liang on 2018/8/26.
//

#ifndef CCarrierListener_h
#define CCarrierListener_h

#include <elastos/core/Object.h>
#include "ElastosCore.h"
#include "elatypes.h"
#include "CCarrierListenerCAPI.h"

class CCarrierListener;

class CCarrierListener
: public Object
, public ICarrierListener
{
public:

    CAR_INTERFACE_DECL()

    CCarrierListener(const void *pSwiftObj)
        : mSwiftObj(pSwiftObj),
          onIdle(nullptr),
          onConnectionChanged(nullptr),
          onReady(nullptr),
          onFriendRequest(nullptr),
          onFriendConnectionChanged(nullptr),
          onPortForwardingRequest(nullptr),
          onPortForwardingResult(nullptr),
          onMessageReceived(nullptr)
    {
    }

    ~CCarrierListener()
    {
    }

    CARAPI OnIdle();

    CARAPI OnConnectionChanged(
                /* [in] */ _ELASTOS Boolean online);

    CARAPI OnReady();

    CARAPI OnFriendRequest(
                /* [in] */ const _ELASTOS String& uid,
                /* [in] */ const _ELASTOS String& hello);

    CARAPI OnFriendConnectionChanged(
                /* [in] */ const _ELASTOS String& uid,
                /* [in] */ _ELASTOS Boolean online);

    CARAPI OnPortForwardingRequest(
                /* [in] */ const String &uid,
                /* [in] */ const String &servicePort,
                /* [out] */ Boolean *accept);

    CARAPI OnPortForwardingResult(
                /* [in] */ const String &uid,
                /* [in] */ const String &localPort,
                /* [in] */ const String &remotePort,
                /* [in] */ ECode code);

    CARAPI OnMessageReceived(
                /* [in] */ const String& uid,
                /* [in] */ const ArrayOf<Byte>& message);

private:
    const void * mSwiftObj;
    fnCarrierListenerOnIdle                     onIdle;
    fnCarrierListenerOnConnectionChanged        onConnectionChanged;
    fnCarrierListenerOnReady                    onReady;
    fnCarrierListenerOnFriendRequest            onFriendRequest;
    fnCarrierListenerOnFriendConnectionChanged   onFriendConnectionChanged;
    fnCarrierListenerOnPortForwardingRequest    onPortForwardingRequest;
    fnCarrierListenerOnPortForwardingResult     onPortForwardingResult;
    fnCarrierListenerOnMessageReceived          onMessageReceived;

    friend CCarrierListener *createCarrierListener(void *pSwiftObj);
    friend void registerCarrierListenerOnIdle(
            CCarrierListener *pObj,
            fnCarrierListenerOnIdle OnIdle);
    friend void registerCarrierListenerOnConnectionChanged(
            CCarrierListener *pObj,
            fnCarrierListenerOnConnectionChanged OnConnectionChanged);
    friend void registerCarrierListenerOnReady(
            CCarrierListener *pObj,
            fnCarrierListenerOnReady OnReady);
    friend void registerCarrierListenerOnFriendRequest(
            CCarrierListener *pObj,
            fnCarrierListenerOnFriendRequest OnFriendRequest);
    friend void registerCarrierListenerOnFriendConnectionChanged(
            CCarrierListener *pObj,
            fnCarrierListenerOnFriendConnectionChanged OnFriendConnectionChanged);
    friend void registerCarrierListenerOnPortForwardingRequest(
            CCarrierListener *pObj,
            fnCarrierListenerOnPortForwardingRequest OnPortForwardingRequest);
    friend void registerCarrierListenerOnPortForwardingResult(
            CCarrierListener *pObj,
            fnCarrierListenerOnPortForwardingResult OnPortForwardingResult);
    friend void registerCarrierListenerOnMessageReceived(
            CCarrierListener *pObj,
            fnCarrierListenerOnMessageReceived OnMessageReceived);
};


#endif /* CCarrierListener_h */
