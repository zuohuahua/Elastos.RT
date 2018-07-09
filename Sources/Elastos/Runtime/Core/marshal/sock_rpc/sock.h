#ifndef __SOCK_H
# define __SOCK_H

# include <uv.h>
#include "CParcelSession.h"

#define RPC_LOG

enum {
    METHOD_GET_CLASS_INFO,
    METHOD_INVOKE,
    METHOD_RELEASE,
    METHOD_GET_CLASS_INFO_REPLY,
    METHOD_INVOKE_REPLY,
    METHOD_RELEASE_REPLY
};

static_assert(METHOD_GET_CLASS_INFO       == (int)RpcMethod::get_class_info,       "Enum value must equal.");
static_assert(METHOD_INVOKE               == (int)RpcMethod::invoke,               "Enum value must equal.");
static_assert(METHOD_RELEASE              == (int)RpcMethod::release,              "Enum value must equal.");
static_assert(METHOD_GET_CLASS_INFO_REPLY == (int)RpcMethod::get_class_info_reply, "Enum value must equal.");
static_assert(METHOD_INVOKE_REPLY         == (int)RpcMethod::invoke_reply,         "Enum value must equal.");
static_assert(METHOD_RELEASE_REPLY        == (int)RpcMethod::release_reply,        "Enum value must equal.");

// #ifdef _android
// #include <android/log.h>
// #define RPC_LOG(...) __android_log_print(ANDROID_LOG_DEBUG, "SOCK RPC", __VA_ARGS__)
// #else
// #define RPC_LOG printf
// #endif

extern int sock_send_msg(uv_tcp_t *tcp,
        int type,
        void const *base,
        int len);

extern int sock_recv_msg(uv_tcp_t *tcp,
        int *type,
        void **base,
        int *len);

extern int sock_connect(uv_tcp_t **tcp, char const *ip, int port);

extern int sock_close(uv_tcp_t *tcp);

extern int sock_get_inet_addr(char *buf, int len);

#endif
