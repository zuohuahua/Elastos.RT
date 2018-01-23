
#ifndef __ELASTOS_PRCDEMOCLIENT_SMANS_H__
#define __ELASTOS_PRCDEMOCLIENT_SMANS_H__

#include <elastos/core/Object.h>

#ifndef __USE_MALLOC
#define __USE_MALLOC
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <clsinfo.h>
#include <elastos/utility/etl/HashMap.h>
#include <elautoptr.h>

#define MAX_SERVICE_NUMBER 32


using namespace Elastos;
using Elastos::Utility::Etl::HashMap;

// come from marshal.h
typedef struct InterfacePack
{
    EMuid               m_clsid;             // clsid of object
    UInt32              m_uIndex;            // interface index in class

    Char8               m_stubConnName[256];// dbus unique connection name of stub
} InterfacePack;

class SManS: public Object
{
public:
    SManS(
        /* [in] */ Int32 port);

    virtual ~SManS();

    enum {
        ADD_SERVICE = 0,
        GET_SERVICE,
        REMOVE_SERVICE,
        ADD_SERVICE_REPLY,
        GET_SERVICE_REPLY,
        REMOVE_SERVICE_REPLY
    };

    CARAPI test(void);

private:
    typedef int (SManS::*handle_event_t)(int fd,
            int events,
            void *user_data);

    struct epoll_event_data {
        int fd;
        handle_event_t handle;
        void *user_data;
    };

    int m_epfd;

    int m_port;

    pthread_t m_threadID;

    int HandleAddService(int sfd, void const *buf, int len);

    int HandleGetService(int sfd, void const *buf, int len);

    int HandleRemoveService(int sfd, void const *buf, int len);

    int HandleReceiveEvent(int sfd, int events, void *user_data);

    int HandleConnectionEvent(int sfd, int events, void *user_data);

    static void *S_ServiceRoutine(void *arg);

    ECode AddService(
        /* [in] */ const String& name,
        /* [in] */ InterfacePack * ip);

    ECode GetService(
        /* [in] */ const String& name,
        /* [out] */ InterfacePack * pIp);

    ECode RemoveService(
        /* [in] */ const String& name);

private:
    HashMap<String, InterfacePack*> mServices;
};


#endif // __ELASTOS_PRCDEMOCLIENT_SMANS_H__
