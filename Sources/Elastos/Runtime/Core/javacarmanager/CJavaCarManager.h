
#ifndef __CJAVACARMANAGER_H__
#define __CJAVACARMANAGER_H__

#include <elastos.h>
#include <elrefbase.h>
#include <elspinlock.h>
#include "../reflection/hashtable.h"

class CJavaCarManager
    : public ElLightRefBase
    , public IJavaCarManager
{
public:
    static ECode AcquireInstance(
        /* [out] */ IJavaCarManager** manager);

public:
    CJavaCarManager();

    ~CJavaCarManager();

    CARAPI_(PInterface) Probe(
        /* [in] */ REIID riid);

    CARAPI_(UInt32) AddRef();

    CARAPI_(UInt32) Release();

    CARAPI GetInterfaceID(
        /* [in] */ IInterface* object,
        /* [out] */ InterfaceID* iid);

    CARAPI AddCarObject(
        /* [in] */ Handle64 javaObj,
        /* [in] */ IInterface* carObj);

    CARAPI RemoveCarObject(
        /* [in] */ Handle64 javaObj,
        /* [in] */ IInterface* carObj);

    CARAPI GetJavaObject(
        /* [in] */ IInterface* carObj,
        /* [out] */ Handle64* javaObj);

    CARAPI GetCarObject(
        /* [in] */ Handle64 javaObj,
        /* [out] */ IInterface** carObj);

private:
    static IJavaCarManager* sInstance;
    static SpinLock sInstanceLock;

    static HashTable<IInterface*, Type_UInt64> sCarObjects;
    static HashTable<Handle64, Type_UInt64> sJavaObjects;
    static pthread_mutex_t sObjectLock;

};

#endif //__CJAVACARMANAGER_H__
