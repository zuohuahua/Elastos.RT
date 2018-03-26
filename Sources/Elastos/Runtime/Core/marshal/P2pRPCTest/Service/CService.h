
#ifndef __CSERVICE_H__
#define __CSERVICE_H__

#include "_CService.h"
#include "elastos/core/Object.h"
#include "elastos/utility/etl/HashMap.h"

#include <ela_carrier.h>
#include <ela_session.h>
#include "carrier.h"

using Elastos::Core::IComparable;
using Elastos::Core::EIID_IComparable;

using Elastos::Utility::Etl::HashMap;

// come from marshal.h
typedef struct InterfacePack
{
    EMuid               m_clsid;             // clsid of object
    UInt32              m_uIndex;            // interface index in class

    Char8               m_stubConnName[256];// dbus unique connection name of stub
} InterfacePack;


CarClass(CService)
    , public Object
    , public IService
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    CARAPI AddService(
        /* [in] */ const String& name,
        /* [in] */ IInterface * pService);

    CARAPI Start();

    CARAPI constructor(
        /* [in] */ const String& location);

    ~CService();

    ECode HandleGetService(
        /* [in] */ const char *from,
        /* [in] */ const String& name);

    ECode GetService(
        /* [in] */ const String& name,
        /* [out] */ InterfacePack* ip);

private:
    // TODO: Add your private member variables here.
    static HashMap<String, InterfacePack*> sServices;
    ElaCarrier* mElaCarrier;
};


#endif // __CSERVICE_H__
