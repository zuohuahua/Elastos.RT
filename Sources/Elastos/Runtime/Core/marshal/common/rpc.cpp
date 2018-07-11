
#include "prxstub.h"

#include <pthread.h>
#include <dlfcn.h>
#include <stdio.h>
//#include <sys/config.h>
#include <elastos.h>
#include "marshal.h"
#include "CParcelSession.h"

_ELASTOS_NAMESPACE_USING

ECode RegisterModuleInfo(
    /* [in] */ CIModuleInfo *pSrcModuleInfo);

ECode LookupModuleInfo(
    /* [in] */ REMuid rclsid,
    /* [out] */ CIModuleInfo **ppModuleInfo);

ECode GetRemoteClassInfo(
    /* [in] */ CParcelSession *pParcelSession,
    /* [in] */ REMuid clsId,
    /* [out] */ CIClassInfo ** ppClassInfo)
{
    ECode ec;
    UInt32 uSize = 0;
    CIModuleInfo *pModInfo;

    if (ppClassInfo == NULL) return E_INVALID_ARGUMENT;

    int type;
    void *buf = NULL;
    int len;

    ec = pParcelSession->SendMessage(RpcMethod::get_class_info, NULL, 0);
    if (FAILED(ec)) {
        goto Exit;
    }

    ec = pParcelSession->ReceiveMessage((RpcMethod*)&type, &buf, &len);
    if (FAILED(ec)) {
        goto Exit;
    }

    if (type != (int)RpcMethod::get_class_info_reply)
        goto Exit;

    pModInfo = (CIModuleInfo *)buf;
    uSize = len;

    ec = RegisterModuleInfo(pModInfo);
    if (FAILED(ec)) {
        MARSHAL_DBGOUT(MSHDBG_ERROR,
                printf("Register module info fail.\n"));
        goto Exit;
    }

    if (FAILED(LookupModuleInfo(clsId, &pModInfo))) {
        MARSHAL_DBGOUT(MSHDBG_ERROR,
                printf("Find module info fail.\n"));
        goto Exit;
    }

    ec = E_DOES_NOT_EXIST;
    for (Int32 m = 0; m < pModInfo->mClassNum; m++) {
        if (pModInfo->mClasses[m].mCLSID == clsId) {
            *ppClassInfo = &(pModInfo->mClasses[m]);

            MARSHAL_DBGOUT(MSHDBG_NORMAL, printf("iid: "));
            MARSHAL_DBGOUT(MSHDBG_NORMAL,
                    DUMP_GUID((*ppClassInfo)->mCLSID));
            MARSHAL_DBGOUT(MSHDBG_NORMAL,
                    printf("UUNM: %s.\n", (*ppClassInfo)->mUunm));
            MARSHAL_DBGOUT(MSHDBG_NORMAL,
                    printf("InterfaceNumber: %d.\n", (*ppClassInfo)->mInterfaceNum));

            ec = NOERROR;
            goto Exit;
        }
    }

Exit:
    free(buf);
    return ec;
}
