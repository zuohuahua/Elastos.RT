#ifndef __CP2P_PARCEL_SESSION_H__
#define __CP2P_PARCEL_SESSION_H__

#include "CParcelSession.h"

#include "carrier.h"
#include "CSessionManager.h"
#include "rpcerror.h"

class CP2PParcelSession : public CParcelSession
{
public:
    CP2PParcelSession(CSession* pSession);
    ~CP2PParcelSession();

    Elastos::ECode StartService(
                /* [in] */ const char *stubConnName);

    Elastos::ECode StopService();

    Elastos::ECode SendMessage(
                /* [in] */ RpcMethod type,
                /* [in] */ void* msg,
                /* [in] */ size_t len);

    Elastos::ECode ReceiveMessage(
                /* [out] */ RpcMethod* pType,
                /* [out] */ void** pBuf,
                /* [out] */ int* pLen);

    Elastos::ECode ReceiveFromRemote(
                /* [out] */ RpcMethod* pType,
                /* [out] */ void** pBuf,
                /* [out] */ int* pLen);

private:
    class CSessionListener
        : public SessionListener
    {
    public:
        void OnSessionConnected(
            /* [in] */ CSession* pSession,
            /* [in] */ Boolean succeeded,
            /* [in] */ void* context);

        void OnSessionReceived(
            /* [in] */ CSession* pSession,
            /* [in] */ ArrayOf<Byte>* data,
            /* [in] */ void* context);
    };

    String                  m_stubId;
    CSession                *mSession;
    CSessionListener        *mListener;
    pthread_cond_t          mCv;
    pthread_mutex_t         mWorkLock;
    DataPack*               mData;
    bool                    m_serviceStarted;
};

#endif // __CP2P_PARCEL_SESSION_H__
