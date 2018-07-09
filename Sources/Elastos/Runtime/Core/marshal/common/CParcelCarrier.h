
#ifndef __CPARCEL_CARRIER_H__
#define __CPARCEL_CARRIER_H__

#include "elastos.h"

class CObjectStub;
class CParcelSession;

class CParcelCarrier
{
public:
    CParcelCarrier(CObjectStub* pStub) : mStub(pStub) {}

    virtual ~CParcelCarrier() {}

    virtual Elastos::ECode HandleReleaseToZero() = 0;

    static Elastos::ECode S_StartService(CObjectStub *pStub, CParcelCarrier **ppParcelCarrier);

    Elastos::ECode HandleGetClassInfo(CParcelSession* pSession, void const *base, int len);

    Elastos::ECode HandleInvoke(CParcelSession* pSession, void const *base, int len);

    Elastos::ECode HandleRelease(CParcelSession* pSession, void const *base, int len);
protected:
    CObjectStub *mStub;
};


#endif //__CPARCEL_CARRIER_H__
