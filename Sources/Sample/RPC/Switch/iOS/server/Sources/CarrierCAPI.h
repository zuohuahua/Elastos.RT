//
//  CarrierCAPI.h
//  SwitchServer
//
//  Created by Joel Liang on 2018/8/26.
//

#ifndef CarrierCAPI_h
#define CarrierCAPI_h

#ifdef __cplusplus
    class CCarrierListener;
    #include "elatypes.h"
extern "C" {
#else
    typedef struct IFriend IFriend;
    typedef struct ICarrier ICarrier;
    typedef struct CCarrierListener CCarrierListener;
#endif
    ICarrier *startCarrier(const char*path, CCarrierListener* listener);
    _ELASTOS ECode carrierIsOnline(ICarrier *carrier, _ELASTOS Boolean* online);
    _ELASTOS ECode carrierGetAddress(ICarrier *carrier, const char** myAddress);
    _ELASTOS ECode carrierAccpetFriendRequest(ICarrier *carrier, const char* uid);
    _ELASTOS ECode carrierGetFriends(ICarrier *carrier, IFriend ***friends, int *length);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CarrierCAPI_h */
