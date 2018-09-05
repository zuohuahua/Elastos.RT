//
//  CCarrierListenerCAPI.h
//  SwitchServer
//
//  Created by Joel Liang on 2018/8/26.
//

#ifndef CCarrierListenerCAPI_h
#define CCarrierListenerCAPI_h

#ifdef __cplusplus
#include "elatypes.h"
class CCarrierListener;
extern "C" {
#else
    typedef struct CCarrierListener CCarrierListener;
#endif
    typedef _ELASTOS ECode (*fnCarrierListenerOnIdle)(
                                /* [in] */ const void *pSwiftObj);

    typedef _ELASTOS ECode (*fnCarrierListenerOnConnectionChanged)(
                                /* [in] */ const void *pSwiftObj,
                                /* [in] */ _ELASTOS Boolean online);

    typedef _ELASTOS ECode (*fnCarrierListenerOnReady)(
                                /* [in] */ const void *pSwiftObj);

    typedef _ELASTOS ECode (*fnCarrierListenerOnFriendRequest)(
                                /* [in] */ const void *pSwiftObj,
                                /* [in] */ const char* uid,
                                /* [in] */ const char* hello);

    typedef _ELASTOS ECode (*fnCarrierListenerOnFriendConnectionChanged)(
                                /* [in] */ const void *pSwiftObj,
                                /* [in] */ const char* uid,
                                /* [in] */ _ELASTOS Boolean online);

    typedef _ELASTOS ECode (*fnCarrierListenerOnPortForwardingRequest)(
                                /* [in] */ const void *pSwiftObj,
                                /* [in] */ const char* uid,
                                /* [in] */ const char* servicePort,
                                /* [out] */ _ELASTOS Boolean *accept);

    typedef _ELASTOS ECode (*fnCarrierListenerOnPortForwardingResult)(
                                /* [in] */ const void *pSwiftObj,
                                /* [in] */ const char* uid,
                                /* [in] */ const char* localPort,
                                /* [in] */ const char* remotePort,
                                /* [in] */ _ELASTOS ECode code);

    typedef _ELASTOS ECode (*fnCarrierListenerOnMessageReceived)(
                                /* [in] */ const void *pSwiftObj,
                                /* [in] */ const char* uid,
                                /* [in] */ const unsigned char* message,
                                /* [in] */ const unsigned int msgSize);


    CCarrierListener *createCarrierListener(const void *pSwiftObj);
    void registerCarrierListenerOnIdle(
            CCarrierListener *pObj,
            fnCarrierListenerOnIdle OnIdle);
    void registerCarrierListenerOnConnectionChanged(
            CCarrierListener *pObj,
            fnCarrierListenerOnConnectionChanged OnConnectionChanged);
    void registerCarrierListenerOnReady(
            CCarrierListener *pObj,
            fnCarrierListenerOnReady OnReady);
    void registerCarrierListenerOnFriendRequest(
            CCarrierListener *pObj,
            fnCarrierListenerOnFriendRequest OnFriendRequest);
    void registerCarrierListenerOnFriendConnectionChanged(
            CCarrierListener *pObj,
            fnCarrierListenerOnFriendConnectionChanged OnFriendConnectionChanged);
    void registerCarrierListenerOnPortForwardingRequest(
            CCarrierListener *pObj,
            fnCarrierListenerOnPortForwardingRequest OnPortForwardingRequest);
    void registerCarrierListenerOnPortForwardingResult(
            CCarrierListener *pObj,
            fnCarrierListenerOnPortForwardingResult OnPortForwardingResult);
    void registerCarrierListenerOnMessageReceived(
            CCarrierListener *pObj,
            fnCarrierListenerOnMessageReceived OnMessageReceived);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CCarrierListenerCAPI_h */
