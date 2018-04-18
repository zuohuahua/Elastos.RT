

#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include <elastos.h>

enum {
    MESSAGE_TYPE_DATA = 0,
    MESSAGE_TYPE_EXIT,
};

class RPCMessage
{
public:
    RPCMessage(
        const void* data,
        Int32 len,
        Int32 type);

    ~RPCMessage();

    ArrayOf<Byte>* GetData();

    Int32 GetType();

private:
    ArrayOf<Byte>* mData;
    Int32 mType;
};

#endif //__MESSAGE_H__
