
#ifndef __CCHAT_H__
#define __CCHAT_H__

#include "_CChat.h"
#include "elastos/core/Object.h"

using Elastos::Core::IComparable;
using Elastos::Core::EIID_IComparable;


CarClass(CChat)
    , public Object
    , public IChat
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    CChat()
    	: mListener(NULL)
    {}

    ~CChat()
    {
    	if (mListener) {
    		mListener->Release();
    	}
    }

    CARAPI Send(
        /* [in] */ const String& msg);

    CARAPI SetMessageListener(
        /* [in] */ IMessageListener * pListener);

    CARAPI constructor();

private:
    IMessageListener* mListener;
};


#endif // __CCHAT_H__
