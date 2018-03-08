
#ifndef __CCLIENT_H__
#define __CCLIENT_H__

#include "_CClient.h"
#include <elastos/core/Object.h>

#include <ela_carrier.h>
#include <ela_session.h>
#include <pthread.h>
#include "carrier.h"

using Elastos::Core::IComparable;
using Elastos::Core::EIID_IComparable;

// come from marshal.h
typedef struct InterfacePack
{
    EMuid               m_clsid;             // clsid of object
    UInt32              m_uIndex;            // interface index in class

    Char8               m_stubConnName[256];// dbus unique connection name of stub
} InterfacePack;


CarClass(CClient)
    , public Object
    , public IClient
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()


    CClient()
        : mCarrier(NULL)
    {}

    ~CClient();

    CARAPI GetService(
        /* [in] */ const String& name,
        /* [out] */ IInterface ** ppService);

    CARAPI constructor();

    ECode AddFriend(
        /* [in] */ const String& address);

    ECode SendMessage(
        /* [in] */ const String& to,
        /* [in] */ Int32 type,
        /* [in] */ const String& msg);

    ECode GetService(
        /* [in] */ const String& name,
        /* [out] */ InterfacePack* ip);

private:
    ElaCarrier* mCarrier;
};


#endif // __CCLIENT_H__
