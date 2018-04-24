#ifndef __CAR_SWTICH_H__
#define __CAR_SWTICH_H__

#ifndef _NO_INCLIST
#include "elastos.h"
using namespace Elastos;
#include "Elastos.CoreLibrary.h"


#endif // !_NO_INCLIST


interface ISwitchListener;
EXTERN const _ELASTOS InterfaceID EIID_ISwitchListener;
interface ISwitch;
EXTERN const _ELASTOS InterfaceID EIID_ISwitch;
interface ICSwitchClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICSwitchClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CSwitch;
EXTERN const _ELASTOS ClassID ECLSID_CSwitchClassObject;





#ifdef __SWTICH_USER_TYPE_H__
#include "Swtich_user_type.h"
#endif

#endif // __CAR_SWTICH_H__
