
#include "CChat.h"



CAR_OBJECT_IMPL(CChat)

CAR_INTERFACE_IMPL(CChat, Object, IChat);

ECode CChat::Send(
    /* [in] */ const String& msg)
{
    if (mListener) {
    	mListener->MessageRecived(msg);
    }
    return NOERROR;
}

ECode CChat::SetMessageListener(
    /* [in] */ IMessageListener * pListener)
{
    if (mListener) {
        mListener->Release();
    }
    mListener = pListener;
    if (mListener) {
        mListener->AddRef();
    }
    return NOERROR;
}

ECode CChat::constructor()
{
    // TODO: Add your code here
    return NOERROR;
}


