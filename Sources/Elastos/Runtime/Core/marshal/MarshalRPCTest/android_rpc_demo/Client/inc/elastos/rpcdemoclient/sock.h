#ifndef __SOCK_H
# define __SOCK_H

#include <sys/types.h>
#include <elatypes.h>

// extern "C" {

// 	ECO_PUBLIC ssize_t sock_send_all(int sfd, void const *buf, size_t len);

// 	ECO_PUBLIC ssize_t sock_recv_all(int sfd, void *buf, size_t len);

// 	ECO_PUBLIC int sock_make_pack(int type,
//         void const *buf, int len,
//         void const **rbuf, int *rlen);

// 	ECO_PUBLIC int sock_send_msg(int sfd,
//         int type,
//         void const *buf,
//         int len);

// 	ECO_PUBLIC int sock_recv_msg(int sfd,
//         int *type,
//         void **buf,
//         int *len);

// 	ECO_PUBLIC int sock_connect(char const *ip, int port);

// 	ECO_PUBLIC int sock_close(int sid);

// 	ECO_PUBLIC int sock_get_inet_addr(char *buf, int len);

// }

ECO_PUBLIC extern ssize_t sock_send_all(int sfd, void const *buf, size_t len);

ECO_PUBLIC extern ssize_t sock_recv_all(int sfd, void *buf, size_t len);

ECO_PUBLIC extern int sock_make_pack(int type,
        void const *buf, int len,
        void const **rbuf, int *rlen);

ECO_PUBLIC extern int sock_send_msg(int sfd,
        int type,
        void const *buf,
        int len);

ECO_PUBLIC extern int sock_recv_msg(int sfd,
        int *type,
        void **buf,
        int *len);

ECO_PUBLIC extern int sock_connect(char const *ip, int port);

ECO_PUBLIC extern int sock_close(int sid);

ECO_PUBLIC extern int sock_get_inet_addr(char *buf, int len);

#endif
