//
//  CarrierCAPI.cpp
//  SwitchServer
//
//  Created by Joel Liang on 2018/8/26.
//

#include <stdio.h>

#include <elastos/core/Object.h>
#include "ElastosCore.h"
#include "elatypes.h"

#include "CarrierCAPI.h"
#include "CCarrierListener.h"


ICarrier *startCarrier(const char*path, CCarrierListener* listener)
{
    ICarrier *carrier;
    ECode ec = (ECode) _CCarrier_GetInstance(&carrier);
    if (FAILED(ec)) return nullptr;

    carrier->AddCarrierNodeListener(ICarrierListener::Probe(listener));

    carrier->Start(String(path));
    return carrier;
}

ECode carrierIsOnline(ICarrier *carrier, Boolean* online)
{
    return carrier->IsOnline(online);
}

ECode carrierGetAddress(ICarrier *carrier, const char** myAddress)
{
    String address;
    ECode ec = carrier->GetAddress(&address);
    if (SUCCEEDED(ec)) {
        *myAddress = strdup(address.string());
    }
    return ec;
}

ECode carrierGetFriends(ICarrier *carrier, IFriend ***friends, int *length)
{
    ArrayOf<IFriend*>* friendsArray = NULL;
    ECode ec = carrier->GetFriends(&friendsArray);
    if (SUCCEEDED(ec) && friendsArray) {
        *friends = friendsArray->GetPayload();
        *length = friendsArray->GetLength();
    } else {
        *friends = NULL;
        *length = 0;
    }
    return ec;
}


ECode carrierAccpetFriendRequest(ICarrier *carrier, const char* uid)
{
    return carrier->AccpetFriendRequest(String(uid));
}
