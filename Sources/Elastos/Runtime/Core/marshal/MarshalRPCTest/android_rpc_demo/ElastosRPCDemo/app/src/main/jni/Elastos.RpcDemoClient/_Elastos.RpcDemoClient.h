#ifndef ___Elastos_RpcDemoClient_h__
#define ___Elastos_RpcDemoClient_h__

#include <Elastos.RpcDemoClient.h>

ELAPI _Impl_AcquireCallbackHandler(PInterface pServerObj, _ELASTOS REIID iid, PInterface *ppHandler);
ELAPI _Impl_CheckClsId(PInterface pServerObj, const _ELASTOS ClassID* pClassid, PInterface *ppServerObj);

namespace Elastos {
namespace RpcDemoClient {
CAR_INTERFACE("0B8E8158-8312-7A44-9F79-9955C122B367")
ICarrierNodeListener : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICarrierNodeListener*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICarrierNodeListener*)pObj->Probe(EIID_ICarrierNodeListener);
    }

    static CARAPI_(ICarrierNodeListener*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICarrierNodeListener*)pObj->Probe(EIID_ICarrierNodeListener);
    }

    virtual CARAPI OnConnectionStatus(
        /* [in] */ Elastos::RpcDemoClient::ElaConnectionStatus status) = 0;

    virtual CARAPI OnReady() = 0;

    virtual CARAPI OnFriendConnection(
        /* [in] */ const _ELASTOS String& friendid,
        /* [in] */ Elastos::RpcDemoClient::ElaConnectionStatus status) = 0;

    virtual CARAPI OnFriendRequest(
        /* [in] */ const _ELASTOS String& userid,
        /* [in] */ const _ELASTOS String& hello) = 0;

    virtual CARAPI OnFreindAdded(
        /* [in] */ const _ELASTOS String& userid) = 0;

    virtual CARAPI OnFriendMessage(
        /* [in] */ const _ELASTOS String& from,
        /* [in] */ const _ELASTOS String& msg) = 0;

};
}
}

namespace Elastos {
namespace RpcDemoClient {
CAR_INTERFACE("9ADA6C25-86D2-2619-1AA0-8021A3CF8FF6")
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
        /* [in] */ const _ELASTOS String& ip,
        /* [in] */ _ELASTOS Boolean isServer,
        /* [out] */ _ELASTOS Boolean * succeed) = 0;

    virtual CARAPI GetAddress(
        /* [in] */ _ELASTOS Boolean isSelf,
        /* [out] */ _ELASTOS String * address) = 0;

    virtual CARAPI AddFriend(
        /* [in] */ const _ELASTOS String& address,
        /* [in] */ const _ELASTOS String& hello) = 0;

    virtual CARAPI SendMsg(
        /* [in] */ const _ELASTOS String& msg) = 0;

    virtual CARAPI SendMsg(
        /* [in] */ const _ELASTOS String& userid,
        /* [in] */ const _ELASTOS String& msg) = 0;

    virtual CARAPI GetUserId(
        /* [out] */ _ELASTOS String * userid) = 0;

    virtual CARAPI SetCarrierNodeListener(
        /* [in] */ Elastos::RpcDemoClient::ICarrierNodeListener * listener) = 0;

};
}
}

namespace Elastos {
namespace RpcDemoClient {
CAR_INTERFACE("FA947125-8312-330D-4C34-400143461F3D")
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

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace RpcDemoClient {
class CRpcDemoClient
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::RpcDemoClient::IRpcDemoClient** __object)
    {
        return _CObject_CreateInstance(ECLSID_CRpcDemoClient, RGM_SAME_DOMAIN, Elastos::RpcDemoClient::EIID_IRpcDemoClient, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CRpcDemoClient, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CRpcDemoClient, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CRpcDemoClient, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}

#endif // ___Elastos_RpcDemoClient_h__
