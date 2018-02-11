#ifndef __CAR_ELASTOS_RPCDEMOCLIENT_H__
#define __CAR_ELASTOS_RPCDEMOCLIENT_H__

#ifndef _NO_INCLIST
#include <elastos.h>
using namespace Elastos;
#include <Elastos.CoreLibrary.h>

#endif // !_NO_INCLIST


namespace Elastos {
namespace RpcDemoClient {
interface ICarrierNodeListener;
EXTERN const _ELASTOS InterfaceID EIID_ICarrierNodeListener;
interface IRpcDemoClient;
EXTERN const _ELASTOS InterfaceID EIID_IRpcDemoClient;
interface ICRpcDemoClientClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICRpcDemoClientClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CRpcDemoClient;
EXTERN const _ELASTOS ClassID ECLSID_CRpcDemoClientClassObject;
}
}





#ifndef __ENUM_Elastos_RpcDemoClient_ElaConnectionStatus__
#define __ENUM_Elastos_RpcDemoClient_ElaConnectionStatus__
namespace Elastos {
namespace RpcDemoClient {
enum {
    ElaConnectionStatus_Connected = 0,
    ElaConnectionStatus_Disconnected = 1,
};
typedef _ELASTOS Int32 ElaConnectionStatus;
}
}

#endif //__ENUM_Elastos_RpcDemoClient_ElaConnectionStatus__


#ifdef __ELASTOS_RPCDEMOCLIENT_USER_TYPE_H__
#include "Elastos.RpcDemoClient_user_type.h"
#endif

#endif // __CAR_ELASTOS_RPCDEMOCLIENT_H__
