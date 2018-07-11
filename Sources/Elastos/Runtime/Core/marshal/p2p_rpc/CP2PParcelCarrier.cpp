#include <assert.h>
#include <stdlib.h>

#include "CP2PParcelCarrier.h"
#include "prxstub.h"
#include "rot.h"
#include "elcarrierapi.h"

ECode CParcelCarrier::S_StartService(CObjectStub *pStub, CParcelCarrier **ppParcelCarrier)
{
    ECode ec;

    CP2PParcelCarrier* pP2PParcelCarrier = new CP2PParcelCarrier(pStub);
    pP2PParcelCarrier->mStub = pStub;

    ec = CSessionManager::AcquireInstance(&pP2PParcelCarrier->mSessionManager);
    if (FAILED(ec)) {
        RPC_LOG("CObjectStub Acquire SessionManager failed: 0x%x\n", ec);
        goto ErrorExit;
    }

    pP2PParcelCarrier->mSessionManagerListener = new CP2PParcelCarrier::CSessionManagerListener();
    if (!pP2PParcelCarrier->mSessionManagerListener) {
        ec = E_OUT_OF_MEMORY;
        goto ErrorExit;
    }

    pP2PParcelCarrier->mSessionManager->AddListener(pP2PParcelCarrier->mSessionManagerListener, pP2PParcelCarrier);

    pP2PParcelCarrier->mSessionManager->GetUid(&pStub->m_connName);

    return NOERROR;

ErrorExit:
    delete pStub;
    return ec;
}

ECode CParcelCarrier::S_IsOnline(Elastos::Boolean* pIsOnline)
{
    if (!pIsOnline) {
        return E_INVALID_ARGUMENT;
    }

    ECode ec;
    ICarrier* pCarrier;
    ec = CCarrier::GetInstance(&pCarrier);
    if (FAILED(ec)) {
        return ec;
    }
    Boolean online;
    pCarrier->IsOnline(&online);
    pCarrier->Release();
    *pIsOnline = online;
    return NOERROR;
}

CP2PParcelCarrier::CP2PParcelCarrier(CObjectStub * pStub) :
    CParcelCarrier(pStub),
    mSessionManager(NULL),
    mSessionManagerListener(NULL)
{

}

CP2PParcelCarrier::~CP2PParcelCarrier()
{
    if (mSessionManagerListener) {
        mSessionManager->RemoveListener(mSessionManagerListener, this);
        mSessionManagerListener->Release();
    }

    if (mSessionManager) {
        mSessionManager->Release();
    }
}

Elastos::ECode CP2PParcelCarrierHandleReleaseToZero()
{
    return NOERROR;
}

void CP2PParcelCarrier::CSessionManagerListener::OnSessionRequest(
    /* [in] */ ICarrier* pCarrier,
    /* [in] */ const char *from,
    /* [in] */ const char *sdp,
    /* [in] */ size_t len,
    /* [in] */ void *context)
{
    CP2PParcelCarrier* pP2PParcelCarrier = (CP2PParcelCarrier*)context;
    if (!pP2PParcelCarrier) return;

    CObjectStub* pStub = (CObjectStub*)pP2PParcelCarrier->mStub;

    CSession* pSession;
    ECode ec = pP2PParcelCarrier->mSessionManager->CreateSession(String(from), FALSE,
                        sdp, len, &pSession);
    if (SUCCEEDED(ec)) {
        pSession->Release();
    }
}

void CP2PParcelCarrier::CSessionManagerListener::OnSessionReceived(
    /* [in] */ CSession* pSession,
    /* [in] */ ArrayOf<Byte>* data,
    /* [in] */ void *context)
{
    RPC_LOG("CObjectStub::CSessionManagerListener OnSessionReceived");

    CP2PParcelCarrier* pP2PParcelCarrier = (CP2PParcelCarrier*)context;
    if (!pP2PParcelCarrier) return;

    CObjectStub* pStub = (CObjectStub*)pP2PParcelCarrier->mStub;

    Byte* p = data->GetPayload();
    int _len = data->GetLength();
    size_t _type = *(size_t *)p;
    p += sizeof(size_t);
    _len -= sizeof(size_t);

    RPC_LOG("CObjectStub receive type:%d, len: %d\n", _type, _len);

    CParcelSession *pParcelSession = CParcelSession::S_CreateObject(pSession);
    switch (_type) {
    case METHOD_GET_CLASS_INFO:
        pP2PParcelCarrier->HandleGetClassInfo(pParcelSession, p, _len);
        break;
    case METHOD_INVOKE:
        pP2PParcelCarrier->HandleInvoke(pParcelSession, p, _len);
        break;
    case METHOD_RELEASE:
        pP2PParcelCarrier->HandleRelease(pParcelSession, p, _len);
        break;
    default:
        break;
    }
    delete pParcelSession;
}

ECode CP2PParcelCarrier::HandleReleaseToZero()
{
    return NOERROR;
}
