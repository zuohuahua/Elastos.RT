#ifndef __CAR_ELASTOS_HELLOCARDEMO_H__
#define __CAR_ELASTOS_HELLOCARDEMO_H__

#ifndef _NO_INCLIST
#include "elastos.h"
using namespace Elastos;
#include "Elastos.CoreLibrary.h"

#endif // !_NO_INCLIST

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

interface IHelloCar;
interface ICHelloCarClassObject;





#ifdef __ELASTOS_HELLOCARDEMO_USER_TYPE_H__
#include "Elastos.HelloCarDemo_user_type.h"
#endif
ELAPI _Impl_AcquireCallbackHandler(PInterface pServerObj, _ELASTOS REIID iid, PInterface *ppHandler);
ELAPI _Impl_CheckClsId(PInterface pServerObj, const _ELASTOS ClassID* pClassid, PInterface *ppServerObj);

CAR_INTERFACE("0A7A0F11-8452-AFBE-CC90-F51FA1EF2B4B")
IHelloCar : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IHelloCar*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHelloCar*)pObj->Probe(EIID_IHelloCar);
    }

    static CARAPI_(IHelloCar*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHelloCar*)pObj->Probe(EIID_IHelloCar);
    }

    static CARAPI_(IHelloCar*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Hello(
        /* [out] */ _ELASTOS String * name) = 0;

};
CAR_INTERFACE("5A7F5610-1312-EFA1-2B33-64CDBCA46D63")
ICHelloCarClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICHelloCarClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICHelloCarClassObject*)pObj->Probe(EIID_ICHelloCarClassObject);
    }

    static CARAPI_(ICHelloCarClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICHelloCarClassObject*)pObj->Probe(EIID_ICHelloCarClassObject);
    }

    static CARAPI_(ICHelloCarClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
#ifndef _INSIDE_ELASTOS_HELLOCARDEMO_
class CHelloCar
{
public:
    static _ELASTOS ECode New(
        /* [out] */ IHelloCar** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHelloCar, RGM_SAME_DOMAIN, EIID_IHelloCar, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHelloCar, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHelloCar, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHelloCar, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
#endif // _INSIDE_ELASTOS_HELLOCARDEMO_


#endif // __CAR_ELASTOS_HELLOCARDEMO_H__
