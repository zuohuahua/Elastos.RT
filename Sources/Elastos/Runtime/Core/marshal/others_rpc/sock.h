#ifndef __SOCK_H
# define __SOCK_H

# include <uv.h>

#define RPC_LOG

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
