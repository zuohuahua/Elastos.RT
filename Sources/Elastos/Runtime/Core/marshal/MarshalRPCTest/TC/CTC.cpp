
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

ECode CTC::GetString(
    /* [out] */ String* str)
{
    if (str == NULL)
        return NOERROR;
    *str = m_str;
    return NOERROR;
}

ECode CTC::SetString(
    /* [in] */ const String& str)
{
    m_str = str;
    return NOERROR;
}

ECode CTC::GetBoolean(
    /* [out] */ Boolean* b)
{
    if (b == NULL)
        return NOERROR;
    *b = m_b;
    return NOERROR;
}

ECode CTC::SetBoolean(
    /* [in] */ Boolean b)
{
    m_b = b;
    return NOERROR;
}

ECode CTC::GetInt64(
    /* [out] */ Int64* i)
{
    if (i == NULL)
        return NOERROR;
    *i = m_i64;
    return NOERROR;
}

ECode CTC::SetInt64(
    /* [in] */ Int64 i)
{
    m_i64 = i;
    return NOERROR;
}

ECode CTC::GetDouble(
    /* [out] */ Double* d)
{
    if (d == NULL)
        return NOERROR;
    *d = m_d;
    return NOERROR;
}

ECode CTC::SetDouble(
    /* [in] */ Double d)
{
    m_d = d;
    return NOERROR;
}

ECode CTC::GetArrayOf(
    /* [out, callee] */ ArrayOf<Int32>** array)
{
    if (array == NULL || mArray == NULL)
        return NOERROR;
printf("GetArrayOf");
    *array = mArray->Clone();
    (*array)->AddRef();
printf("GetArrayOf 2");
    return NOERROR;
}

ECode CTC::SetArrayOf(
    /* [in] */ const ArrayOf<Int32>& array)
{
    if (mArray != NULL) {
        mArray->Release();
        mArray = NULL;
    }
printf("SetArrayOf");
    mArray = array.Clone();
    mArray->AddRef();
printf("SetArrayOf 2");

    return NOERROR;
}

ECode CTC::constructor(
    /* [in] */ Int32 i)
{
    m_i = i;
    m_str = "TC";
    m_i64 = 65527;
    m_b = false;
    m_d = 1.90388;
    mArray = NULL;
    return NOERROR;
}


