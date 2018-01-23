#ifndef ___Elastos_RpcDemoClient_h__
#define ___Elastos_RpcDemoClient_h__

#include <Elastos.RpcDemoClient.h>

ELAPI _Impl_AcquireCallbackHandler(PInterface pServerObj, _ELASTOS REIID iid, PInterface *ppHandler);
ELAPI _Impl_CheckClsId(PInterface pServerObj, const _ELASTOS ClassID* pClassid, PInterface *ppServerObj);

namespace Elastos {
namespace RpcDemoClient {
CAR_INTERFACE("26333C30-86D2-2619-1AA0-8021A3CF8FF6")
IRpcDemoClient : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRpcDemoClient*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRpcDemoClient*)pObj->Probe(EIID_IRpcDemoClient);
    }

    static CARAPI_(IRpcDemoClient*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRpcDemoClient*)pObj->Probe(EIID_IRpcDemoClient);
    }

    virtual CARAPI Connect(
        /* [out] */ _ELASTOS Boolean * succeed) = 0;

    virtual CARAPI Chat(
        /* [in] */ const _ELASTOS String& text) = 0;

    virtual CARAPI SetTag(
        /* [in] */ const _ELASTOS String& text) = 0;

    virtual CARAPI GetTag(
        /* [out] */ _ELASTOS String * text) = 0;

};
}
}

namespace Elastos {
namespace RpcDemoClient {
CAR_INTERFACE("FF1D8E38-8312-330D-4C34-400143461F3D")
ICRpcDemoClientClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICRpcDemoClientClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRpcDemoClientClassObject*)pObj->Probe(EIID_ICRpcDemoClientClassObject);
    }

    static CARAPI_(ICRpcDemoClientClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRpcDemoClientClassObject*)pObj->Probe(EIID_ICRpcDemoClientClassObject);
    }

    virtual CARAPI CreateObjectWithIpIsServer(
        /* [in] */ const _ELASTOS String& ip,
        /* [in] */ _ELASTOS Boolean isServer,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithIpPortIsServer(
        /* [in] */ const _ELASTOS String& ip,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean isServer,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace RpcDemoClient {
class CRpcDemoClient
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& ip,
        /* [in] */ _ELASTOS Boolean isServer,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICRpcDemoClientClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CRpcDemoClient, RGM_SAME_DOMAIN,
                EIID_ICRpcDemoClientClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIpIsServer(ip, isServer, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& ip,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean isServer,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICRpcDemoClientClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CRpcDemoClient, RGM_SAME_DOMAIN,
                EIID_ICRpcDemoClientClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIpPortIsServer(ip, port, isServer, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& ip,
        /* [in] */ _ELASTOS Boolean isServer,
        /* [out] */ Elastos::RpcDemoClient::IRpcDemoClient** __IRpcDemoClient)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ip, isServer, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRpcDemoClient = (Elastos::RpcDemoClient::IRpcDemoClient*)__pNewObj->Probe(Elastos::RpcDemoClient::EIID_IRpcDemoClient);
        if (*__IRpcDemoClient) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& ip,
        /* [in] */ _ELASTOS Boolean isServer,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ip, isServer, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& ip,
        /* [in] */ _ELASTOS Boolean isServer,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ip, isServer, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& ip,
        /* [in] */ _ELASTOS Boolean isServer,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ip, isServer, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& ip,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean isServer,
        /* [out] */ Elastos::RpcDemoClient::IRpcDemoClient** __IRpcDemoClient)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ip, port, isServer, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRpcDemoClient = (Elastos::RpcDemoClient::IRpcDemoClient*)__pNewObj->Probe(Elastos::RpcDemoClient::EIID_IRpcDemoClient);
        if (*__IRpcDemoClient) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& ip,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean isServer,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ip, port, isServer, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& ip,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean isServer,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ip, port, isServer, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& ip,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean isServer,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ip, port, isServer, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}

#endif // ___Elastos_RpcDemoClient_h__
