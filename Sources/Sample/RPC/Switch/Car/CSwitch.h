
#ifndef __CSWITCH_H__
#define __CSWITCH_H__

#include "_CSwitch.h"
#include "elastos/core/Object.h"

using Elastos::Core::IComparable;
using Elastos::Core::EIID_IComparable;


CarClass(CSwitch)
    , public Object
    , public ISwitch
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    CSwitch()
        : mListener(NULL)
        , mSwitch1(FALSE)
        , mSwitch2(FALSE)
    {}

    ~CSwitch()
    {
        if (mListener) {
            mListener->Release();
        }
    }

    CARAPI TurnSwitch1(
        /* [in] */ Boolean on);

    CARAPI GetSwitch1(
        /* [out] */ Boolean * pOn);

    CARAPI TurnSwitch2(
        /* [in] */ Boolean on);

    CARAPI GetSwitch2(
        /* [out] */ Boolean * pOn);

    CARAPI SetSwitchListener(
        /* [in] */ ISwitchListener * pListener);

    CARAPI constructor();

private:
    ISwitchListener* mListener;
    Boolean mSwitch1;
    Boolean mSwitch2;
};


#endif // __CSWITCH_H__
