
#include <stdio.h>
#include <new>
#include <eltypes.h>
#include "marshal.h"

ECode Proxy_ProcessMsh_BufferSize(
    /* [in] */ const CIMethodInfo *pMethodInfo,
    /* [in] */ va_list vaArgs,
    /* [out] */ UInt32 *puInSize,
    /* [out] */ UInt32 *puOutSize)
{
    int n, cParams;
    UInt32 uInSize, uOutSize, uSize;
    void *pArg;
    const CIBaseType *pParams;

    uInSize = 0;
    uOutSize = 0;
    cParams = pMethodInfo->mParamNum;
    pParams = pMethodInfo->mParams;

    for (n = 0; n < cParams; n++) {
        if (BT_IS_OUT(pParams[n])) {    // [out]
            uSize = 0;
            uOutSize += sizeof(void*); // for pointer
            pArg = va_arg(vaArgs, void*);

            switch (BT_TYPE(pParams[n])) {
                case BT_TYPE_PUINT8:
                case BT_TYPE_PUINT16:
                case BT_TYPE_PUINT32:
                    uSize = sizeof(UInt32);
                    break;

                case BT_TYPE_PUINT64:
                    uSize = sizeof(UInt64);
                    break;

                case BT_TYPE_PEMUID:
                    uSize = sizeof(EMuid);
                    break;

                case BT_TYPE_PEGUID:
                    uSize = sizeof(EGuid) + 80 * sizeof(char);
                    break;

                case BT_TYPE_PSTRUCT :
                    uSize = sizeof(UInt32) * BT_TYPE_SIZE(pParams[n]);
                    break;

                case BT_TYPE_PSTRING:
                    uSize = sizeof(String);
                    break;

                case BT_TYPE_ARRAYOF:{
                    if (pArg) {
                        uSize = sizeof(CarQuintet) + \
                          MSH_ALIGN_4(((PCARQUINTET)pArg)->mSize);
                    }
                    break;
                }

                case BT_TYPE_PINTERFACE:
                    uSize = sizeof(InterfacePack);
                    break;

                default:
                    MARSHAL_DBGOUT(MSHDBG_ERROR, printf(
                        "MshProc: Invalid [in, out] type(%08x).\n",
                        pParams[n]));
                    assert(0);
                    return E_INVALID_ARGUMENT;
            }

            if (pArg) {
                uOutSize += uSize;
            }
            // else: null pointer do not contain data.
        }

        if (BT_IS_IN(pParams[n])) { // [in]
            switch (BT_TYPE(pParams[n])) {
                case BT_TYPE_UINT8:
                case BT_TYPE_UINT16:
                case BT_TYPE_UINT32:
                    uInSize += sizeof(UInt32);
                    va_arg(vaArgs, UInt32);
                    break;

                case BT_TYPE_PUINT8:
                case BT_TYPE_PUINT16:
                case BT_TYPE_PUINT32:
                    pArg = va_arg(vaArgs, void*);
                    if (pArg) {
                        uInSize += sizeof(void*) + sizeof(UInt32);
                    }
                    else { // null pointer
                        uInSize += sizeof(void*);
                    }
                    break;

                case BT_TYPE_UINT64:
                    va_arg(vaArgs, UInt64);
                    uInSize += sizeof(UInt64);
                    break;

                case BT_TYPE_PUINT64:
                    pArg = va_arg(vaArgs, void*);
                    if (pArg) {
                        uInSize += sizeof(void*) + sizeof(UInt64);
                    }
                    else { // null pointer
                        uInSize += sizeof(void*);
                    }
                    break;

                case BT_TYPE_EGUID:
                    va_arg(vaArgs, EGuid);
                    uInSize += sizeof(EGuid) + 80 * sizeof(char);
                    break;

                case BT_TYPE_EMUID:
                    va_arg(vaArgs, EMuid);
                    uInSize += sizeof(EMuid);
                    break;

                case BT_TYPE_PSTRUCT:
                case BT_TYPE_STRUCT:
                    pArg = va_arg(vaArgs, void*);
                    if (pArg) {
                        uInSize += sizeof(void*) + sizeof(UInt32) * BT_TYPE_SIZE(pParams[n]);
                    }
                    else {  // null pointer
                        uInSize += sizeof(void*);
                    }
                    break;

                case BT_TYPE_PEGUID:
                    pArg = va_arg(vaArgs, void*);
                    if (pArg) {
                        uInSize += sizeof(void*) + sizeof(EGuid)
                                   + 80 * sizeof(char);
                    }
                    else {  // null pointer
                        uInSize += sizeof(void*);
                    }
                    break;

                case BT_TYPE_PEMUID:
                    pArg = va_arg(vaArgs, void*);
                    if (pArg) {
                        uInSize += sizeof(void*) + sizeof(EMuid);
                    }
                    else {  // null pointer
                        uInSize += sizeof(void*);
                    }
                    break;

                case BT_TYPE_STRING:
                    pArg = va_arg(vaArgs, void*);
                    if (pArg) {
                        UInt32 nBufLen = (strlen((char *)(pArg)) + 1)
                            * sizeof(char);
                        uInSize += sizeof(String) + MSH_ALIGN_4(nBufLen);
                    }
                    else {
                        uInSize += sizeof(void*);
                    }
                    break;

                case BT_TYPE_INTERFACE:
                    pArg = va_arg(vaArgs, void*);
                    if (pArg) {
                        uInSize += sizeof(InterfacePack);
                    }
                    else {  // null pointer
                        uInSize += sizeof(void*);
                    }
                    break;

                case BT_TYPE_PINTERFACE:
                    pArg = va_arg(vaArgs, void*);
                    if (pArg) {
                        if (*(void **)pArg) {
                            uInSize += sizeof(InterfacePack);
                        }
                        else {
                            uInSize += sizeof(void*);
                        }
                    }
                    uInSize += sizeof(void*);  // for pointer
                    break;

                case BT_TYPE_STRINGBUF:
                case BT_TYPE_BUFFEROF:
                case BT_TYPE_ARRAYOF:
                    pArg = va_arg(vaArgs, void*);
                    if (pArg) {
                        if (CarQuintetFlag_Type_IObject
                            != (((PCARQUINTET)pArg)->mFlags
                                    & CarQuintetFlag_TypeMask)) {
                            uInSize += MSH_ALIGN_4(sizeof(void*) \
                              + sizeof(CarQuintet) \
                              + ((PCARQUINTET)pArg)->mSize);
                        }
                        else {
                            uInSize += MSH_ALIGN_4(sizeof(void*) \
                              + sizeof(CarQuintet));
                            int used = ((PCARQUINTET)pArg)->mUsed
                                        / sizeof(IInterface *);
                            int *pBuf = (int*)((PCARQUINTET)pArg)->mBuf;
                            uint_t uUsedSize = 0;
                            for (int i = 0; i < used; i++) {
                                if (pBuf[i]) {
                                    uUsedSize += sizeof(InterfacePack);
                                }
                                else {  // null pointer
                                    uUsedSize += sizeof(void*);
                                }
                            }
                            uInSize += MAX((MemorySize)uUsedSize, \
                                MSH_ALIGN_4(((PCARQUINTET)pArg)->mSize));
                        }
                    }
                    else {  // null pointer
                        uInSize += sizeof(void*);
                    }
                    break;

                default:
                    MARSHAL_DBGOUT(MSHDBG_ERROR, printf(
                        "MshProc: Invalid [in, out] type(%08x).\n",
                        pParams[n]));
                    assert(0);
                    return E_INVALID_ARGUMENT;
            }
        }
        else {  // [out]
            pArg = va_arg(vaArgs, void*);
            if (((BT_TYPE(pParams[n]) == BT_TYPE_BUFFEROF) ||
                (BT_TYPE(pParams[n]) == BT_TYPE_ARRAYOF) ||
                (BT_TYPE(pParams[n]) == BT_TYPE_STRINGBUF)) && pArg) {
                uInSize += sizeof(void*); // for size only
            }
            uInSize += sizeof(void*);
        }
    }

    *puInSize = uInSize;
    *puOutSize = uOutSize;
    return NOERROR;
}

ECode Proxy_ProcessMsh_In(
    /* [in] */ const CIMethodInfo *pMethodInfo,
    /* [in] */ va_list vaArgs,
    /* [in, out] */ IParcel *pParcel)
{
    int n, cParams;
    const CIBaseType *pParams;
    ECode ec;

    cParams = pMethodInfo->mParamNum;
    pParams = pMethodInfo->mParams;

    for (n = 0; n < cParams; n++) {
        if (BT_IS_IN(pParams[n])) { // [in] or [in, out]
            switch (BT_TYPE(pParams[n])) {
                case BT_TYPE_UINT8:
                case BT_TYPE_UINT16:
                case BT_TYPE_UINT32:
                    pParcel->WriteInt32(va_arg(vaArgs, Int32));
                    break;

                case BT_TYPE_UINT64:
                    pParcel->WriteInt64(va_arg(vaArgs, Int64));
                    break;

                case BT_TYPE_STRUCT:
                case BT_TYPE_PSTRUCT:
                    pParcel->WriteStruct(va_arg(vaArgs, Handle32), BT_TYPE_SIZE(pParams[n]) * 4);
                    break;

                case BT_TYPE_EMUID:
                    pParcel->WriteEMuid(va_arg(vaArgs, EMuid));
                    break;

                case BT_TYPE_EGUID:
                    pParcel->WriteEGuid(va_arg(vaArgs, EGuid));
                    break;

                case BT_TYPE_ARRAYOF:
                    pParcel->WriteArrayOf(va_arg(vaArgs, Handle32));
                    break;

                case BT_TYPE_STRING:
                    pParcel->WriteString(*va_arg(vaArgs, String*));
                    break;

                case BT_TYPE_INTERFACE:
                    ec = pParcel->WriteInterfacePtr(va_arg(vaArgs, IInterface*));
                    if (FAILED(ec)) {
                        MARSHAL_DBGOUT(MSHDBG_ERROR, printf(
                                "MshProc: marshal interface, ec = %x\n", ec));
                        return ec;
                    }
                    break;

                default:
                    MARSHAL_DBGOUT(MSHDBG_ERROR, printf(
                        "MshProc: Invalid [in, out] type(%08x).\n",
                        pParams[n]));
                    assert(0);
                    return E_INVALID_ARGUMENT;
            }
        }
        else {  // [out]
            void *pArg = va_arg(vaArgs, void*);
            if (pArg) pParcel->WriteInt32(MSH_NOT_NULL);
            else pParcel->WriteInt32(MSH_NULL);

            if (((BT_TYPE(pParams[n]) == BT_TYPE_BUFFEROF) ||
                (BT_TYPE(pParams[n]) == BT_TYPE_ARRAYOF) ||
                (BT_TYPE(pParams[n]) == BT_TYPE_STRINGBUF)) && pArg) {
                pParcel->WriteInt32(((PCARQUINTET)pArg)->mSize);
            }
        }
    }

    return NOERROR;
}

ECode Proxy_ProcessUnmsh_Out(
    /* [in] */ const CIMethodInfo *pMethodInfo,
    /* [in] */ IParcel *pParcel,
    /* [in] */ UInt32 uDataSize,
    /* [in, out] */ va_list vaArgs)
{
    Int32 n, cParams, pointValue;
    const CIBaseType *pParams;
    cParams = pMethodInfo->mParamNum;
    pParams = pMethodInfo->mParams;
    void *pArg;

    for (n = 0; n < cParams; n++) {
        if (BT_IS_OUT(pParams[n])) {   // [out] or [in, out]
            pArg = va_arg(vaArgs, void*);
            if (pArg) {
                pParcel->ReadInt32(&pointValue);
                if (pointValue != (Int32)MSH_NOT_NULL) {
                    MARSHAL_DBGOUT(MSHDBG_ERROR, printf(
                        "MshProc: arg conflict in proxy's unmarshal.\n"));
                    return E_INVALID_ARGUMENT;
                }

                switch (BT_TYPE(pParams[n])) {
                    case BT_TYPE_PUINT8:
                        pParcel->ReadByte((Byte*)pArg);
                        break;

                    case BT_TYPE_PUINT16:
                        pParcel->ReadInt16((Int16*)pArg);
                        break;

                    case BT_TYPE_PUINT32:
                        pParcel->ReadInt32((Int32*)pArg);
                        break;

                    case BT_TYPE_PUINT64:
                        pParcel->ReadInt64((Int64*)pArg);
                        break;

                    case BT_TYPE_PSTRUCT:
                        pParcel->ReadStruct((Handle32*)pArg);
                        break;

                    case BT_TYPE_PEMUID:
                        pParcel->ReadEMuid((EMuid*)pArg);
                        break;

                    case BT_TYPE_PEGUID:
                        pParcel->ReadEGuid((EGuid*)pArg);
                        break;

                    case BT_TYPE_PSTRING:
                        pParcel->ReadString((String*)pArg);
                        break;

                    case BT_TYPE_ARRAYOF:
                        if (!BT_IS_CALLEE(pParams[n])) {
                            PCARQUINTET p;
                            pParcel->ReadArrayOf((Handle32*)&p);
                            PCARQUINTET qArg = (PCARQUINTET)pArg;
                            qArg->mUsed = p->mUsed;
                            memcpy(qArg->mBuf, p->mBuf, p->mSize);
                            _CarQuintet_Release(p);
                        }
                        else {
                            pParcel->ReadArrayOf((Handle32*)pArg);
                        }
                        break;

                    case BT_TYPE_PINTERFACE:
                        pParcel->ReadInterfacePtr((Handle32*)pArg);
                        break;

                    default:
                        MARSHAL_DBGOUT(MSHDBG_ERROR, printf(
                                "MshProc: Invalid arg type(%08x)\n", pParams[n]));
                        assert(0);
                        return E_INVALID_ARGUMENT;
                }
            }
            else {
                pParcel->ReadInt32(&pointValue);
                if (pointValue != MSH_NULL) {
                    MARSHAL_DBGOUT(MSHDBG_ERROR, printf(
                            "MshProc: arg conflict in proxy's unmarshal.\n"));
                    return E_INVALID_ARGUMENT;
                }
            }
        }
        else {      // [in]
            switch (BT_TYPE(pParams[n])) {
                case BT_TYPE_UINT64:
                    va_arg(vaArgs, UInt64);
                    break;

                case BT_TYPE_EMUID:
                    va_arg(vaArgs, EMuid);
                    break;

                case BT_TYPE_EGUID:
                    va_arg(vaArgs, EGuid);
                    break;

                default:
                    va_arg(vaArgs, UInt32);
                    break;
            }
        }
    }

    return NOERROR;
}

ECode Stub_ProcessUnmsh_In(
    /* [in] */ const CIMethodInfo *pMethodInfo,
    /* [in] */ IParcel *pParcel,
    /* [in, out] */ UInt32 *puOutBuffer,
    /* [in, out] */ UInt32 *puArgs)
{
    int n, cParams;
    const CIBaseType *pParams;
    Int32 pointValue, size;
    ECode ec;
    String str;

    if (puOutBuffer) {
        puOutBuffer = (UInt32 *)((MarshalHeader *)puOutBuffer + 1);
    }
    cParams = pMethodInfo->mParamNum;
    pParams = pMethodInfo->mParams;

    for (n = 0; n < cParams; n++) {
        if (BT_IS_OUT(pParams[n])) {    // [out] or [in, out]
            assert(puOutBuffer);
            pParcel->ReadInt32(&pointValue);
            if (pointValue == (Int32)MSH_NOT_NULL) {
                *puOutBuffer = MSH_NOT_NULL;
                puOutBuffer++;

                switch (BT_TYPE(pParams[n])) { // [out]
                    case BT_TYPE_PUINT8:
                    case BT_TYPE_PUINT16:
                    case BT_TYPE_PUINT32:
                        *puArgs = (UInt32)puOutBuffer;
                        puOutBuffer++;
                        break;

                    case BT_TYPE_PUINT64:
                        *puArgs = (UInt32)puOutBuffer;
                        puOutBuffer += 2;
                        break;

                    case BT_TYPE_PEGUID:
                        *puArgs = (UInt32)puOutBuffer;
                        puOutBuffer += sizeof(EMuid) / 4;
                        *puOutBuffer = (UInt32)(puOutBuffer + 1);
                        puOutBuffer += sizeof(char*) / 4
                                    + 80 * sizeof(char) / 4;
                        break;

                    case BT_TYPE_PEMUID:
                        *puArgs = (UInt32)puOutBuffer;
                        puOutBuffer += sizeof(EMuid) / 4;
                        break;

                    case BT_TYPE_PSTRUCT:
                        *puArgs = (UInt32)puOutBuffer;
                        puOutBuffer += BT_TYPE_SIZE(pParams[n]);
                        break;

                    case BT_TYPE_PSTRING:
                        *puArgs = (UInt32)puOutBuffer;
                        new((void*)puOutBuffer) String();
                        puOutBuffer++;
                        break;

                    case BT_TYPE_ARRAYOF:
                        if (!BT_IS_CALLEE(pParams[n])) {
                            Int32 size;
                            pParcel->ReadInt32(&size);
                            *puOutBuffer = (UInt32)malloc(sizeof(CarQuintet));
                            *(PCARQUINTET*)puArgs = (PCARQUINTET)*puOutBuffer;
                            ((PCARQUINTET)*puArgs)->mSize = size;
                            ((PCARQUINTET)*puArgs)->mBuf = malloc(size);
                        }
                        else {
                            *puOutBuffer = 0;
                            *puArgs = (UInt32)puOutBuffer;
                        }
                        puOutBuffer++;

                        break;

                    case BT_TYPE_PINTERFACE:
                        *puOutBuffer = 0;
                        *puArgs = (UInt32)puOutBuffer;
                        puOutBuffer += sizeof(InterfacePack) / 4;
                        break;

                    default:
                        MARSHAL_DBGOUT(MSHDBG_ERROR, printf(
                            "MshProc: Invalid arg type(%08x) in UnMsh_in.\n",
                            pParams[n]));
                        return E_INVALID_ARGUMENT;
                }
            }
            else if (pointValue == MSH_NULL) {
                *puOutBuffer = MSH_NULL;
                puOutBuffer++;
                *puArgs = 0;
            }
            else {
                MARSHAL_DBGOUT(MSHDBG_ERROR, printf(
                    "MshProc: Invalid pointer value in unmarshal in.\n"));
                return E_INVALID_ARGUMENT;
            }
            puArgs++;
        }
        else if (BT_IS_IN(pParams[n])) {    // [in]
            switch (BT_TYPE(pParams[n])) {
                case BT_TYPE_UINT8:
                case BT_TYPE_UINT16:
                case BT_TYPE_UINT32:
                    pParcel->ReadInt32((Int32*)puArgs);
                    puArgs++;
                    break;

                case BT_TYPE_UINT64:
#ifdef _mips
                    // Adjust for 64bits align on mips
                    if (!(n % 2)) {
                        puArgs += 1;
                    }
#endif
                    pParcel->ReadInt64((Int64*)puArgs);
                    puArgs += 2;
                    break;

                case BT_TYPE_EMUID:
                    pParcel->ReadEMuid((EMuid*)puArgs);
                    puArgs += sizeof(EMuid) / 4;
                    break;

                case BT_TYPE_EGUID:
                    pParcel->ReadEGuid((EGuid*)puArgs);
                    puArgs += (sizeof(EGuid) +
                               MSH_ALIGN_4(strlen(((EGuid*)puArgs)->mUunm) + 1)) / 4;
                    break;

                case BT_TYPE_ARRAYOF:
                    pParcel->ReadArrayOf((Handle32*)puArgs);
                    puArgs++;
                    break;

                case BT_TYPE_STRING:
                    pParcel->ReadString(&str);
                    *(String**)puArgs = new String(str);
                    puArgs++;
                    break;

                case BT_TYPE_INTERFACE:
                    ec = pParcel->ReadInterfacePtr((Handle32*)puArgs);
                    if (FAILED(ec)) {
                        MARSHAL_DBGOUT(MSHDBG_ERROR, printf(
                                "MshProc: unmsh interface, ec = %x\n", ec));
                        return ec;
                    }
                    puArgs++;
                    break;

                default:
                    MARSHAL_DBGOUT(MSHDBG_ERROR, printf(
                        "MshProc: Invalid arg type(%08x)\n", pParams[n]));
                    return E_INVALID_ARGUMENT;
            }
        }
        else {
            MARSHAL_DBGOUT(MSHDBG_ERROR, printf(
                "MshProc: Invalid arg type(%08x)\n", pParams[n]));
            return E_INVALID_ARGUMENT;
        }
    }

    return NOERROR;
}

ECode Stub_ProcessMsh_Out(
        /* [in] */ const CIMethodInfo *pMethodInfo,
        /* [in] */ UInt32 *puArgs,
        /* [in] */ UInt32 *puOutBuffer,
        /* [in] */ Boolean bOnlyReleaseIn,
        /* [in, out] */ IParcel* pParcel)
{
    int n, cParams;
    const CIBaseType *pParams;
    MarshalHeader * pOutHeader = NULL;
    ECode ec;

    cParams = pMethodInfo->mParamNum;
    pParams = pMethodInfo->mParams;

    // skip the Out Marshal Header;
    if (puOutBuffer) {
        pOutHeader = (MarshalHeader *)(Void *)puOutBuffer;
        puOutBuffer = (UInt32 *)((MarshalHeader *)puOutBuffer + 1);
    }

    for (n = 0; n < cParams; n++) {
        if (BT_IS_OUT(pParams[n])) {    // [out] or [in, out]
            puArgs++;
            if (*puOutBuffer != MSH_NULL) {
                assert(*puOutBuffer == MSH_NOT_NULL);
                pParcel->WriteInt32(MSH_NOT_NULL);
                puOutBuffer++;

                switch (BT_TYPE(pParams[n])) {
                    case BT_TYPE_PUINT64:
                        pParcel->WriteInt64(*(Int64*)puOutBuffer);
                        puOutBuffer += 2;
                        break;

                    case BT_TYPE_PSTRING:
                        if (*puOutBuffer) {
                            String* p = (String*)puOutBuffer;
                            pParcel->WriteString(*p);
                            p->~String();
                        }
                        else {
                            pParcel->WriteInt32(MSH_NULL);
                        }
                        puOutBuffer++;
                        break;

                    case BT_TYPE_ARRAYOF:
                        {
                            pParcel->WriteArrayOf((Handle32)*puOutBuffer);
                            PCARQUINTET p = (PCARQUINTET)*puOutBuffer;
                            if (p != NULL) {
                                if (!BT_IS_CALLEE(pParams[n])) {
                                    if (CarQuintetFlag_Type_IObject == (p->mFlags
                                            & CarQuintetFlag_TypeMask)) {
                                        int used = ((PCARQUINTET)*puArgs)->mUsed
                                                    / sizeof(IInterface *);
                                        int *buf = (int*)((PCARQUINTET)*puArgs)->mBuf;
                                        for (int i = 0; i < used; i++) {
                                            if (buf[i]) {
                                                ((IInterface *)buf[i])->Release();
                                                buf[i] = 0;
                                            }
                                        }
                                    }
                                    else if (CarQuintetFlag_Type_String == (p->mFlags
                                            & CarQuintetFlag_TypeMask)) {
                                        int size = ((PCARQUINTET)*puArgs)->mSize
                                                    / sizeof(String);
                                        String *buf = (String*)((PCARQUINTET)*puArgs)->mBuf;
                                        for (int i = 0; i < size; i++) {
                                            if (!buf[i].IsNull()) {
                                                buf[i] = NULL;
                                            }
                                        }
                                    }
                                    free(p->mBuf);
                                    free(p);
                                }
                                else {
                                    if (CarQuintetFlag_Type_IObject == (p->mFlags
                                            & CarQuintetFlag_TypeMask)) {
                                        ((ArrayOf<IInterface*>*)p)->Release();
                                    }
                                    else if (CarQuintetFlag_Type_String == (p->mFlags
                                                & CarQuintetFlag_TypeMask)) {
                                        ((ArrayOf<String>*)p)->Release();
                                    }
                                }
                            }
                            puOutBuffer++;
                        }
                        break;

                    case BT_TYPE_PEMUID:
                        pParcel->WriteEMuid(*(EMuid*)puOutBuffer);
                        puOutBuffer += sizeof(EMuid) / 4;
                        break;

                    case BT_TYPE_PSTRUCT:
                        pParcel->WriteStruct((Handle32)puOutBuffer, BT_TYPE_SIZE(pParams[n]) * 4);
                        puOutBuffer += BT_TYPE_SIZE(pParams[n]);
                        break;

                    case BT_TYPE_PEGUID:
                        pParcel->WriteEGuid(*(EGuid*)puOutBuffer);
                        puOutBuffer += sizeof(EMuid) / 4 + sizeof(char*) / 4 \
                                       + 80 * sizeof(char) / 4;
                        break;

                    case BT_TYPE_PINTERFACE:
                        if (!bOnlyReleaseIn) {
                            IInterface *pObj;

                            pObj = (IInterface *)*puOutBuffer;
                            ec = pParcel->WriteInterfacePtr(pObj);
                            if (FAILED(ec)) {
                                MARSHAL_DBGOUT(MSHDBG_ERROR, printf(
                                        "MshProc: marshal interface, ec = %x\n", ec));
                                return ec;
                            }

                            if (NULL != pObj) pObj->Release();

                            puOutBuffer += sizeof(InterfacePack) / 4;
                        }
                        break;

                    default:
                        pParcel->WriteInt32(*(Int32*)puOutBuffer);
                        puOutBuffer++;
                        break;
                }
            }
            else {
                assert(*puOutBuffer == MSH_NULL);
                pParcel->WriteInt32(MSH_NULL);
                puOutBuffer++;
            }
        }
        else {  // BT_IS_IN
            switch (BT_TYPE(pParams[n])) {
                case BT_TYPE_UINT64:
#ifdef _mips
                    // Adjust for 64bits align on mips
                    if (!(n % 2)) puArgs += 1;
#endif
                    puArgs += 2;
                    break;

                case BT_TYPE_EMUID:
                    puArgs += sizeof(EMuid) / 4;
                    break;

                case BT_TYPE_EGUID:
                    puArgs += sizeof(EMuid) / 4 + sizeof(char*) / 4;
                    break;

                case BT_TYPE_PINTERFACE:
                    if (*puArgs && *(UInt32 *)(*puArgs)) {
                        ((IInterface *)*(UInt32 *)*puArgs)->Release();
                    }
                    puArgs++;
                    break;

                case BT_TYPE_INTERFACE:
                    if (*puArgs) {
                        ((IInterface *)*puArgs)->Release();
                    }
                    puArgs++;
                    break;

                case BT_TYPE_STRINGBUF:
                case BT_TYPE_BUFFEROF:
                case BT_TYPE_ARRAYOF:
                    if (*puArgs) {
                        if (CarQuintetFlag_Type_IObject
                            == (((PCARQUINTET)*puArgs)->mFlags
                                    & CarQuintetFlag_TypeMask)) {
                            int used = ((PCARQUINTET)*puArgs)->mUsed
                                        / sizeof(IInterface *);
                            int *pBuf = (int*)((PCARQUINTET)*puArgs)->mBuf;
                            for (int i = 0; i < used; i++) {
                                if (pBuf[i]) {
                                    ((IInterface *)pBuf[i])->Release();
                                    pBuf[i] = 0;
                                }
                            }
                        }
                        else if (CarQuintetFlag_Type_String
                            == (((PCARQUINTET)*puArgs)->mFlags
                                    & CarQuintetFlag_TypeMask)) {
                            int size = ((PCARQUINTET)*puArgs)->mSize
                                        / sizeof(String);
                            String *pBuf = (String*)((PCARQUINTET)*puArgs)->mBuf;
                            for (int i = 0; i < size; i++) {
                                if (!pBuf[i].IsNull()) {
                                    pBuf[i] = NULL;
                                }
                            }
                        }
                        _CarQuintet_Release((PCARQUINTET)*puArgs);
                    }
                    puArgs++;
                    break;

                default:
                    puArgs++;
                    break;
            }
        }
    }

    return NOERROR;
}
