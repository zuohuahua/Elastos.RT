
#include <sys/types.h>
#include <ela_carrier.h>
#include <ela_session.h>
#include <elastos.h>

int p2p_send_message(
    ElaCarrier *w,
    const char * to,
    int type,
    Byte *msg,
    size_t len);

