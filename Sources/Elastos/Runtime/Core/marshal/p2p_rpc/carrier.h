
#ifndef _CARRIER_H_
#define _CARRIER_H_

#include <elastos.h>

#ifdef _android
#include <android/log.h>
#define RPC_LOG(...) __android_log_print(ANDROID_LOG_DEBUG, "P2P RPC", __VA_ARGS__)
#else
#define RPC_LOG printf
#endif

enum {
    ADD_SERVICE = 0,
    GET_SERVICE,
    REMOVE_SERVICE,
    ADD_SERVICE_REPLY,
    GET_SERVICE_REPLY,
    REMOVE_SERVICE_REPLY,
    ADD_FRIEND_SUCCEEDED,
    SELF_ONLINE,
    FRIEND_ONLINE,
    METHOD_GET_CLASS_INFO,
    METHOD_INVOKE,
    METHOD_RELEASE,
    METHOD_GET_CLASS_INFO_REPLY,
    METHOD_INVOKE_REPLY,
    METHOD_RELEASE_REPLY
};

struct DataPack
{
    ArrayOf<Byte>* data;
    ECode ec;
};

#endif //_CARRIER_H_
