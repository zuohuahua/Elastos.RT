#ifndef __CP2P_PARCEL_CARRIER_H__
#define __CP2P_PARCEL_CARRIER_H__

#include "CParcelCarrier.h"

#include "carrier.h"
#include "CSessionManager.h"
#include "rpcerror.h"

class CObjectStub;

class CP2PParcelCarrier : public CParcelCarrier
{
public:
    CP2PParcelCarrier(CObjectStub * pStub);
    ~CP2PParcelCarrier();

    Elastos::ECode HandleReleaseToZero();

private:
    friend class CParcelCarrier;

    class CSessionManagerListener
        : public CManagerListener
    {
    public:
        void OnSessionRequest(
            /* [in] */ ICarrier* pCarrier,
            /* [in] */ const char *from,
            /* [in] */ const char *sdp,
            /* [in] */ size_t len,
            /* [in] */ void *context);

        void OnSessionReceived(
            /* [in] */ CSession* pSession,
            /* [in] */ ArrayOf<Byte>* data,
            /* [in] */ void *context);
    };

private:
    CSessionManager             *mSessionManager;
    CSessionManagerListener     *mSessionManagerListener;
};

#endif // __CP2P_PARCEL_CARRIER_H__
