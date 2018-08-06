
#ifndef _CARRIER_H_
#define _CARRIER_H_

#include <elastos.h>

#ifdef _android
#include <android/log.h>
#define RPC_LOG(...) __android_log_print(ANDROID_LOG_DEBUG, "P2P_RPC", __VA_ARGS__)
#else
#define RPC_LOG printf
#endif

#include "CParcelSession.h"

enum {
    METHOD_GET_CLASS_INFO,
    METHOD_INVOKE,
    METHOD_RELEASE,
    METHOD_GET_CLASS_INFO_REPLY,
    METHOD_INVOKE_REPLY,
    METHOD_RELEASE_REPLY,
    ADD_SERVICE,
    GET_SERVICE,
    REMOVE_SERVICE,
    ADD_SERVICE_REPLY,
    GET_SERVICE_REPLY,
    REMOVE_SERVICE_REPLY,
    ADD_FRIEND_SUCCEEDED,
    SELF_ONLINE,
    FRIEND_ONLINE
};

static_assert(METHOD_GET_CLASS_INFO       == (int)RpcMethod::get_class_info,       "Enum value must equal.");
static_assert(METHOD_INVOKE               == (int)RpcMethod::invoke,               "Enum value must equal.");
static_assert(METHOD_RELEASE              == (int)RpcMethod::release,              "Enum value must equal.");
static_assert(METHOD_GET_CLASS_INFO_REPLY == (int)RpcMethod::get_class_info_reply, "Enum value must equal.");
static_assert(METHOD_INVOKE_REPLY         == (int)RpcMethod::invoke_reply,         "Enum value must equal.");
static_assert(METHOD_RELEASE_REPLY        == (int)RpcMethod::release_reply,        "Enum value must equal.");

struct DataPack
{
    ArrayOf<Byte>* data;
    ECode ec;
};

#endif //_CARRIER_H_
