
#include "CMessage.h"

CMessage::CMessage(
    void* data,
    Int32 len,
    Int32 type)
{
    if (data && len > 0) {
        mData = ArrayOf<Byte>::Alloc(len);
        if (!mData) return;
        memcpy(mData->GetPayload(), data, len);
    }

    mType = type;
}

CMessage::~CMessage()
{
    if (mData) {
        ArrayOf<Byte>::Free(mData);
    }
}

ArrayOf<Byte>* CMessage::GetData()
{
    return mData;
}

Int32 CMessage::GetType()
{
    return mType;
}
