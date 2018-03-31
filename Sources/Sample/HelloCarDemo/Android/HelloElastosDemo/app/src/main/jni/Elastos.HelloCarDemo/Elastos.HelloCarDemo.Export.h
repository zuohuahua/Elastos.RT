
#include "Elastos.CoreLibrary.Core.h"
#include "_Elastos.HelloCarDemo.h"


using namespace Elastos;


#ifndef __UUNM_Elastos_HelloCarDemo_DEFINED__
#define __UUNM_Elastos_HelloCarDemo_DEFINED__
#define c_pElastos_HelloCarDemoUunm "libElastos.HelloCarDemo.so"
#endif // __UUNM_Elastos_HelloCarDemo_DEFINED__

#ifndef __ECLSID_CHelloCar_DEFINED__
#define __ECLSID_CHelloCar_DEFINED__
static const _ELASTOS ClassID ECLSID_CHelloCar = {
    {0x716F1E4C,0x044C,0x2F14,{0x19,0x24,0xFA,0xE1,0xA0,0xA4,0x0C,0x1B}},
    (char *)c_pElastos_HelloCarDemoUunm,
    0xdc3a8dbb };
#endif // __CLSID_CHelloCar_DEFINED__

#ifndef __ECLSID_CHelloCarClassObject_DEFINED__
#define __ECLSID_CHelloCarClassObject_DEFINED__
static const _ELASTOS ClassID ECLSID_CHelloCarClassObject = {
    {0xF19D2933,0x044C,0x2F14,{0x5E,0xC8,0x60,0x40,0xA2,0x86,0x1E,0xA3}},
    (char *)c_pElastos_HelloCarDemoUunm,
    0xdc3a8dbb };
#endif // __CLSID_CHelloCarClassObject_DEFINED__

#ifndef __EIID_IHelloCar_DEFINED__
#define __EIID_IHelloCar_DEFINED__
static const _ELASTOS InterfaceID EIID_IHelloCar = \
    {0x0A7A0F11,0x8452,0xAFBE,{0xCC,0x90,0xF5,0x1F,0xA1,0xEF,0x2B,0x4B}};
#endif // __IID_IHelloCar_DEFINED__

#ifndef __EIID_ICHelloCarClassObject_DEFINED__
#define __EIID_ICHelloCarClassObject_DEFINED__
static const _ELASTOS InterfaceID EIID_ICHelloCarClassObject = \
    {0x5A7F5610,0x1312,0xEFA1,{0x2B,0x33,0x64,0xCD,0xBC,0xA4,0x6D,0x63}};
#endif // __IID_ICHelloCarClassObject_DEFINED__
