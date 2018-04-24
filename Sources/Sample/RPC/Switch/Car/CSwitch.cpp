
#include "CSwitch.h"



CAR_OBJECT_IMPL(CSwitch)

CAR_INTERFACE_IMPL(CSwitch, Object, ISwitch);

ECode CSwitch::TurnSwitch1(
    /* [in] */ Boolean on)
{
    if (on != mSwitch1) {
        mSwitch1 = on;
        if (mListener) {
            mListener->OnSwitch1Changed(on);
        }
    }
    return NOERROR;
}

ECode CSwitch::GetSwitch1(
    /* [out] */ Boolean * pOn)
{
    if (!pOn) {
        return E_INVALID_ARGUMENT;
    }
    *pOn = mSwitch1;
    return NOERROR;
}

ECode CSwitch::TurnSwitch2(
    /* [in] */ Boolean on)
{
    if (on != mSwitch2) {
        mSwitch2 = on;
        if (mListener) {
            mListener->OnSwitch2Changed(on);
        }
    }

    return NOERROR;
}

ECode CSwitch::GetSwitch2(
    /* [out] */ Boolean * pOn)
{
    if (!pOn) {
        return E_INVALID_ARGUMENT;
    }
    *pOn = mSwitch2;
    return NOERROR;
}

ECode CSwitch::SetSwitchListener(
    /* [in] */ ISwitchListener * pListener)
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

ECode CSwitch::constructor()
{
    return NOERROR;
}


