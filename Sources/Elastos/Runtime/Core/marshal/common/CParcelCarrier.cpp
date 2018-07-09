#include <stdlib.h>
#include "CParcelCarrier.h"
#include "prxstub.h"

#ifdef SOCK_RPC
#include <uv.h>

#include "sock.h"
#endif

ECode LookupModuleInfo(
    /* [in] */ REMuid rclsid,
    /* [out] */ CIModuleInfo **ppModuleInfo);

void FlatModuleInfo(
    /* [in] */ CIModuleInfo *pSrcModInfo,
    /* [out] */ CIModuleInfo *pDestModInfo);

ECode CParcelCarrier::HandleGetClassInfo(
                        CParcelSession* pParcelSession,
                        void const *base, int len)
{
#ifdef P2P_RPC
    CSession* pSession = (CSession *)pParcelSession;
#endif
#ifdef SOCK_RPC
    uv_tcp_t *tcp = (uv_tcp_t *)pParcelSession;
#endif
    EMuid clsid;
    CIModuleInfo *pSrcModInfo;
    CIModuleInfo *pDestModInfo;

    mStub->GetClassID(&clsid);
    if (FAILED(LookupModuleInfo(clsid, &pSrcModInfo))) {
        MARSHAL_DBGOUT(MSHDBG_ERROR, printf("Lookup module info fail.\n"));
        return NOERROR;
    }

    pDestModInfo = (CIModuleInfo *)calloc(1, pSrcModInfo->mTotalSize);
    FlatModuleInfo(pSrcModInfo, pDestModInfo);

#ifdef P2P_RPC
    pSession->SendMessage(METHOD_GET_CLASS_INFO_REPLY, pDestModInfo,
                    pDestModInfo->mTotalSize);
#endif
#ifdef SOCK_RPC
    if (sock_send_msg(tcp,
                METHOD_GET_CLASS_INFO_REPLY,
                pDestModInfo,
                pDestModInfo->mTotalSize))
        MARSHAL_DBGOUT(MSHDBG_ERROR, printf("Socket-sending failed.\n"));
#endif

    free(pDestModInfo);

    return NOERROR;
}

ECode CParcelCarrier::HandleInvoke(
                        CParcelSession* pParcelSession,
                        void const *base, int len)
{
#ifdef P2P_RPC
    CSession* pSession = (CSession *)pParcelSession;
#endif
#ifdef SOCK_RPC
    uv_tcp_t *tcp = (uv_tcp_t *)pParcelSession;
#endif
    void *pOutBuffer;
    Int32 outSize;
    CRemoteParcel *pParcel = NULL;
    ECode ec;

    RPC_LOG("Call Invoke.");
    MARSHAL_DBGOUT(MSHDBG_NORMAL, printf("Call Invoke.\n"));

    ec = mStub->Invoke(
#ifdef P2P_RPC
                           pSession,
#endif
                           (void *)base, len, &pParcel);
    RPC_LOG("Call Invoke ec: %x", ec);

    int32_t _ec = ec;
    if (pParcel != NULL) {
        pParcel->GetElementSize(&outSize);
        pParcel->GetElementPayload((Handle32*)&pOutBuffer);

        if (outSize > 0) {
            int out_size = sizeof _ec + outSize;
            // char out_buf[out_size];
            char* out_buf = (char*)alloca(out_size * sizeof(char));
            char *p;

            p = out_buf;
            memcpy(p, &_ec, sizeof _ec);
            p += sizeof _ec;
            memcpy(p, pOutBuffer, outSize);


#ifdef SOCK_RPC
            if (sock_send_msg(tcp, METHOD_INVOKE_REPLY, out_buf, out_size))
                MARSHAL_DBGOUT(MSHDBG_ERROR,
                        printf("Socket-sending failed.\n"));
#endif
#ifdef P2P_RPC
            pSession->SendMessage(METHOD_INVOKE_REPLY, out_buf, out_size);
#endif

        }
    } else {
#ifdef SOCK_RPC
	    if (sock_send_msg(tcp, METHOD_INVOKE_REPLY, &_ec, sizeof _ec))
		    MARSHAL_DBGOUT(MSHDBG_ERROR,
				    printf("Socket-sending failed.\n"));
#endif
#ifdef P2P_RPC
        pSession->SendMessage(METHOD_INVOKE_REPLY, &_ec, sizeof _ec);
#endif
    }

    if (pParcel != NULL)
        delete pParcel;

    return NOERROR;
}

ECode CParcelCarrier::HandleRelease(
                        CParcelSession* pParcelSession,
                        void const *base, int len)
{
#ifdef P2P_RPC
    CSession* pSession = (CSession *)pParcelSession;
#endif
#ifdef SOCK_RPC
    uv_tcp_t *tcp = (uv_tcp_t *)pParcelSession;
#endif
    MARSHAL_DBGOUT(MSHDBG_NORMAL, printf("Stub Release.\n"));

    //bugbug: if there are more than one processes invoke
    //        the stub, then one proxy in a process call "Release"
    //        should not make the stub quit. We should use
    //        reference count to control when to make the stub quit.
    //mStub->m_bRequestToQuit = TRUE;

    if (mStub->Release() == 0) {
        this->HandleReleaseToZero();
    }

    return NOERROR;
}
