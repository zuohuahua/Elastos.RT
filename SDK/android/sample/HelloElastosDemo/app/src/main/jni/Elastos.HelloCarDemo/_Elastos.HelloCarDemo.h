#ifndef ___Elastos_HelloCarDemo_h__
#define ___Elastos_HelloCarDemo_h__

#include <Elastos.HelloCarDemo.h>

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

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};

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

#endif // ___Elastos_HelloCarDemo_h__
