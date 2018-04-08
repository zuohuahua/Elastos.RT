
#ifndef _CARRIER_H_
#define _CARRIER_H_

#include "ela_carrier.h"
#include "ela_session.h"
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

typedef struct _DataPack{
    String from;
    int stream;
    ArrayOf<Byte>* data;
} DataPack;

ELAPI_(int) ECO_PUBLIC carrier_connect(
    const char* location,
    ElaCarrier** carrier);

ELAPI_(int) ECO_PUBLIC carrier_add_friend(
    ElaCarrier* carrier,
    const char* address,
    const char* hello);

ELAPI_(_ELASTOS Boolean) ECO_PUBLIC carrier_is_friend(
    ElaCarrier* carrier,
    const char* uid);

ELAPI_(ElaConnectionStatus) ECO_PUBLIC carrier_get_friend_status(
    const char* uid);

ELAPI_(int) ECO_PUBLIC carrier_send(
    int type,
    void* msg,
    size_t len);

ELAPI_(int) ECO_PUBLIC carrier_wait(
    int time);

ELAPI_(int) ECO_PUBLIC carrier_read(
    DataPack* data,
    Boolean clearData = TRUE);

ELAPI_(void) ECO_PUBLIC carrier_destroy();

ELAPI_(void) ECO_PUBLIC carrier_data_handled();

int carrier_receive(
    const char* from,
    int* type,
    void** buf,
    int* len);

ELAPI_(int) ECO_PUBLIC carrier_session_connect(
    ElaCarrier* carrier,
    const char* uid);

ELAPI_(int) ECO_PUBLIC carrier_session_wait(
    ElaCarrier* carrier);

ELAPI_(void) ECO_PUBLIC carrier_session_destroy();

#endif //_CARRIER_H_
