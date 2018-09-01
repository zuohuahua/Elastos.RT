//
//  CCarrierListenerCAPI.cpp
//  SwitchServer
//
//  Created by Joel Liang on 2018/8/27.
//

#include <stdio.h>
#include "CCarrierListenerCAPI.h"
#include "CCarrierListener.h"


CCarrierListener *createCarrierListener(const void *pSwiftObj)
{
    return new CCarrierListener(pSwiftObj);
}

void registerCarrierListenerOnIdle(
        CCarrierListener *pObj,
        fnCarrierListenerOnIdle onIdle)
{
    pObj->onIdle = onIdle;
}

void registerCarrierListenerOnConnectionChanged(
        CCarrierListener *pObj,
        fnCarrierListenerOnConnectionChanged onConnectionChanged)
{
    pObj->onConnectionChanged = onConnectionChanged;
}

void registerCarrierListenerOnReady(
        CCarrierListener *pObj,
        fnCarrierListenerOnReady onReady)
{
    pObj->onReady = onReady;
}

void registerCarrierListenerOnFriendRequest(
        CCarrierListener *pObj,
        fnCarrierListenerOnFriendRequest onFriendRequest)
{
    pObj->onFriendRequest = onFriendRequest;
}

void registerCarrierListenerOnFriendConnetionChanged(
        CCarrierListener *pObj,
        fnCarrierListenerOnFriendConnetionChanged onFriendConnetionChanged)
{
    pObj->onFriendConnetionChanged = onFriendConnetionChanged;
}

void registerCarrierListenerOnPortForwardingRequest(
        CCarrierListener *pObj,
        fnCarrierListenerOnPortForwardingRequest onPortForwardingRequest)
{
    pObj->onPortForwardingRequest = onPortForwardingRequest;
}

void registerCarrierListenerOnPortForwardingResult(
        CCarrierListener *pObj,
        fnCarrierListenerOnPortForwardingResult onPortForwardingResult)
{
    pObj->onPortForwardingResult = onPortForwardingResult;
}

void registerCarrierListenerOnMessageReceived(
        CCarrierListener *pObj,
        fnCarrierListenerOnMessageReceived onMessageReceived)
{
    pObj->onMessageReceived = onMessageReceived;
}
