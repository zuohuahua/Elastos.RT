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
    #define _ELASTOS
    typedef int ECode;
    typedef unsigned char Boolean;
    typedef struct ICarrier ICarrier;
    typedef struct CCarrierListener CCarrierListener;
#endif
    ICarrier *startCarrier(const char*path, CCarrierListener* listener);
    _ELASTOS ECode carrierIsOnline(ICarrier *carrier, _ELASTOS Boolean* online);
    _ELASTOS ECode carrierGetAddress(ICarrier *carrier, const char** myAddress);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CarrierCAPI_h */
