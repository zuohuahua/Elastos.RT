
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Carrier.h"
#include "Base64.h"

int p2p_send_message(
    ElaCarrier *w,
    const char * to,
    int type,
    Byte *msg,
    size_t len)
{
    size_t msgLen = len + 4;
    ArrayOf<Byte>* data = ArrayOf<Byte>::Alloc(msgLen);
    if (data == NULL) {
        return -1;
    }

    void* p = data->GetPayload();
    p = mempcpy(p, &type, 4);
    p = mempcpy(p, msg, len);

    String outData;
    ECode ec = Encode(data, &outData);
    ArrayOf<Byte>::Free(data);
    if (FAILED(ec)) {
        return ec;
    }

    int rc = ela_send_friend_message(w, to, outData.string(), outData.GetLength());
    if (rc == 0)
        printf("Send message success to[%s] msg[%s] len[%d].\n", to, outData.string(), outData.GetLength());
    else
        printf("Send message failed(0x%x).\n", ela_get_error());

    return rc;
}

