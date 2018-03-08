
#include "CService.h"

HashMap<String, InterfacePack*> CService::sServices;

CAR_OBJECT_IMPL(CService)

CAR_INTERFACE_IMPL(CService, Object, IService);


// void MessageReceived(
//     ElaCarrier *w,
//     const char *from,
//     const char *msg,
//     size_t len,
//     void *context)
// {
//     printf("Receive message: user[%s] msg[%s] len[%d].\n", from, msg, len);
//     if (len <= 0) return;

//     String inData(msg, len);
//     ArrayOf<Byte>* outData;
//     ECode ec = Decode(inData.GetBytes(), &outData);
//     if (FAILED(ec)) {
//         return;
//     }

//     void* p = outData->GetPayload();
//     int type = *(size_t *)p;
//     printf("Service receive type: %d\n", type);
//     p += 4;

//     if (type == GET_SERVICE) {
//         String name((char*)p, outData->GetLength() - 4);
//         printf("Service receive name: %s\n", name.string());
//         CService::HandleGetService(from, name);
//     }

//     ArrayOf<Byte>::Free(outData);
//     printf("MessageReceived end\n");
// }

CService::~CService()
{
    if (mElaCarrier != NULL) {
        carrier_destroy();
        mElaCarrier = NULL;
    }

    HashMap<String, InterfacePack*>::Iterator it = sServices.Begin();
    while (it != sServices.End()) {
        if (it->mSecond != NULL) {

            free(it->mSecond);
        }
        it++;
    }
}

ECode CService::HandleMessage(
    /* [in] */ const DataPack& data)
{
    void* p = data.data->GetPayload();
    int type = *(size_t *)p;
    RPC_LOG("Service receive type: %d\n", type);
    p += 4;

    if (type == GET_SERVICE) {
        String name((char*)p, data.data->GetLength() - 4);
        RPC_LOG("Service receive name: %s\n", name.string());
        HandleGetService(data.from, name);
    }

    return NOERROR;
}

ECode CService::HandleGetService(
    /* [in] */ const char *from,
    /* [in] */ const String& name)
{
    InterfacePack ip;
    ECode ec = GetService(name, &ip);

    int size = sizeof(InterfacePack);

    int _len = 4 + 4 + size;

    ArrayOf<Byte>* data = ArrayOf<Byte>::Alloc(_len);

    void *p = data->GetPayload();

    int i32;

    i32 = ec;
    memcpy(p, &i32, 4);
    p += 4;

    if (SUCCEEDED(ec)) {
        i32 = size;
        memcpy(p, &i32, 4);
        p += 4;

        memcpy(p, &ip, size);
    } else
        _len = 4;

    carrier_send(mElaCarrier, from, GET_SERVICE_REPLY, data->GetPayload(), _len);

    ArrayOf<Byte>::Free(data);
}

ECode CService::GetService(
    /* [in] */ const String& name,
    /* [out] */ InterfacePack* pIp)
{
    InterfacePack * ip = sServices[name];
    if (!ip) return E_FAIL;
    memset(pIp, 0, sizeof(InterfacePack));
    pIp->m_clsid = ip->m_clsid;
    pIp->m_uIndex = ip->m_uIndex;

    strcpy(pIp->m_stubConnName, ip->m_stubConnName);
    RPC_LOG("service %s stubConnName is %s\n", name.string(), ip->m_stubConnName);

    return NOERROR;
}

ECode CService::AddService(
    /* [in] */ const String& name,
    /* [in] */ IInterface * pService)
{
    InterfacePack * ip = NULL;
    Int32 size;

    ECode ec = _CObject_MarshalInterface(pService, MarshalType_RPC, (void**)&ip, &size);
    if (FAILED(ec)) return ec;

    sServices[name] = ip;

    return NOERROR;
}

ECode CService::Start()
{
    if (mElaCarrier != NULL) return NOERROR;

    int ret = carrier_connect("/home/zuo/work/Service", &mElaCarrier);
    if (ret != 0) {
        return ret;
    }

    while(true) {
        ret = carrier_wait(-1);
        if (ret != 0) break;

        DataPack data;
        ret = carrier_read(&data);
        if (ret != 0) break;

        HandleMessage(data);
        ArrayOf<Byte>::Free(data.data);
    }

    return NOERROR;
}

ECode CService::constructor()
{
    return NOERROR;
}


