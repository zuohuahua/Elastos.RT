
#include "CTC.h"



CAR_OBJECT_IMPL(CTC)

CAR_INTERFACE_IMPL(CTC, Object, ITC);

ECode CTC::Get(
    /* [out] */ Int32 * pI)
{
    if (pI == NULL)
        return NOERROR;
    *pI = m_i;
    return NOERROR;
}

ECode CTC::Set(
    /* [in] */ Int32 i)
{
    m_i = i;
    return NOERROR;
}

ECode CTC::Increment()
{
    ++m_i;
    return NOERROR;
}

ECode CTC::Decrement()
{
    --m_i;
    return NOERROR;
}

ECode CTC::constructor(
    /* [in] */ Int32 i)
{
    m_i = i;
    return NOERROR;
}


