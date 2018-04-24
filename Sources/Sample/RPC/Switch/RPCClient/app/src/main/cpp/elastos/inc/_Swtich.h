#ifndef ___Swtich_h__
#define ___Swtich_h__

#include "Swtich.h"

ELAPI _Impl_AcquireCallbackHandler(PInterface pServerObj, _ELASTOS REIID iid, PInterface *ppHandler);
ELAPI _Impl_CheckClsId(PInterface pServerObj, const _ELASTOS ClassID* pClassid, PInterface *ppServerObj);

CAR_INTERFACE("BFE8303F-0712-2C1D-6E98-5891F1FE0FA6")
ISwitchListener : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISwitchListener*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISwitchListener*)pObj->Probe(EIID_ISwitchListener);
    }

    static CARAPI_(ISwitchListener*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISwitchListener*)pObj->Probe(EIID_ISwitchListener);
    }

    static CARAPI_(ISwitchListener*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI OnSwitch1Changed(
        /* [in] */ _ELASTOS Boolean on) = 0;

    virtual CARAPI OnSwitch2Changed(
        /* [in] */ _ELASTOS Boolean on) = 0;

};

CAR_INTERFACE("15034311-0712-B7B2-B9FE-1D5EC79CCEDE")
ISwitch : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISwitch*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISwitch*)pObj->Probe(EIID_ISwitch);
    }

    static CARAPI_(ISwitch*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISwitch*)pObj->Probe(EIID_ISwitch);
    }

    static CARAPI_(ISwitch*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI TurnSwitch1(
        /* [in] */ _ELASTOS Boolean on) = 0;

    virtual CARAPI GetSwitch1(
        /* [out] */ _ELASTOS Boolean * on) = 0;

    virtual CARAPI TurnSwitch2(
        /* [in] */ _ELASTOS Boolean on) = 0;

    virtual CARAPI GetSwitch2(
        /* [out] */ _ELASTOS Boolean * on) = 0;

    virtual CARAPI SetSwitchListener(
        /* [in] */ ISwitchListener * listener) = 0;

};

CAR_INTERFACE("ADE45423-0312-200E-58DC-30B1428FD11F")
ICSwitchClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSwitchClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSwitchClassObject*)pObj->Probe(EIID_ICSwitchClassObject);
    }

    static CARAPI_(ICSwitchClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSwitchClassObject*)pObj->Probe(EIID_ICSwitchClassObject);
    }

    static CARAPI_(ICSwitchClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};


class CSwitch
{
public:
    static _ELASTOS ECode New(
            /* [out] */ ISwitch** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSwitch, RGM_SAME_DOMAIN, EIID_ISwitch, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
            /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSwitch, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
            /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSwitch, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
            /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSwitch, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};

#endif // ___Swtich_h__
