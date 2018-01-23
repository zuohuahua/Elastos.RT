
#ifndef __ELASTOS_PRCDEMOCLIENT_SMANC_H__
#define __ELASTOS_PRCDEMOCLIENT_SMANC_H__

#include <elastos/core/Object.h>

#ifndef __USE_MALLOC
#define __USE_MALLOC
#endif

#include <elastos/utility/etl/HashMap.h>

using namespace Elastos;
using Elastos::Utility::Etl::HashMap;

class SManC: public Object
{
public:
    SManC();

    ~SManC();

    CARAPI_(Boolean) Connect(
        /* [in] */ const String& ip,
        /* [in] */ Int32 port);

    CARAPI AddService(
        /* [in] */ const String& name,
        /* [in] */ IInterface * pService);

    CARAPI AddServiceEx(
        /* [in] */ const String& name,
        /* [in] */ IInterface * pService,
        /* [in] */ Boolean allowIsolated);

    CARAPI GetService(
        /* [in] */ const String& name,
        /* [out] */ IInterface ** ppService);

private:
    Int32                                      m_sockfd;
    HashMap<String, AutoPtr<IInterface> > mServiceCache;
};

#endif // __ELASTOS_PRCDEMOCLIENT_SMANC_H__
