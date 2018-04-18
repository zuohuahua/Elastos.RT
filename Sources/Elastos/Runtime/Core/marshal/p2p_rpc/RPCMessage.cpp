
#include "RPCMessage.h"

RPCMessage::RPCMessage(
    const void* data,
    Int32 len,
    Int32 type)
    : mData(NULL)
{
    if (data && len > 0) {
        mData = ArrayOf<Byte>::Alloc(len);
        if (!mData) return;
        memcpy(mData->GetPayload(), data, len);
    }

    mType = type;
}

RPCMessage::~RPCMessage()
{
    if (mData) {
        ArrayOf<Byte>::Free(mData);
    }
}

ArrayOf<Byte>* RPCMessage::GetData()
{
    return mData;
}

Int32 RPCMessage::GetType()
{
    return mType;
}
