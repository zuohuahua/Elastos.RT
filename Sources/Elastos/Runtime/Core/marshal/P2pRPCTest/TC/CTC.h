
#ifndef __CTC_H__
#define __CTC_H__

#include "_CTC.h"
#include "elastos/core/Object.h"

using Elastos::Core::IComparable;
using Elastos::Core::EIID_IComparable;


CarClass(CTC)
    , public Object
    , public ITC
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    CARAPI Get(
        /* [out] */ Int32 * pI);

    CARAPI Set(
        /* [in] */ Int32 i);

    CARAPI constructor(
        /* [in] */ Int32 i);

private:
    // TODO: Add your private member variables here.
    Int32 m_i;
};


#endif // __CTC_H__
