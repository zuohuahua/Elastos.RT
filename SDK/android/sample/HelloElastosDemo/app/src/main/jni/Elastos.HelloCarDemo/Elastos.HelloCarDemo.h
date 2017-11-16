#ifndef __CAR_ELASTOS_HELLOCARDEMO_H__
#define __CAR_ELASTOS_HELLOCARDEMO_H__

#ifndef _NO_INCLIST
#include <elastos.h>
using namespace Elastos;
#include <Elastos.CoreLibrary.h>

#endif // !_NO_INCLIST


namespace Elastos {
namespace HelloCarDemo {
interface IHelloCar;
EXTERN const _ELASTOS InterfaceID EIID_IHelloCar;
interface ICHelloCarClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICHelloCarClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CHelloCar;
EXTERN const _ELASTOS ClassID ECLSID_CHelloCarClassObject;
}
}





#ifdef __ELASTOS_HELLOCARDEMO_USER_TYPE_H__
#include "Elastos.HelloCarDemo_user_type.h"
#endif

#endif // __CAR_ELASTOS_HELLOCARDEMO_H__
