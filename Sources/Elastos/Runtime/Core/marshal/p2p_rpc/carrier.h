
#include "ela_carrier.h"
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
    ElaCarrier* carrier,
    const char* to,
    int type,
    Byte* msg,
    size_t len);

ELAPI_(int) ECO_PUBLIC carrier_wait(
    int time);

ELAPI_(int) ECO_PUBLIC carrier_read(
    DataPack* data);

ELAPI_(void) ECO_PUBLIC carrier_destroy();
