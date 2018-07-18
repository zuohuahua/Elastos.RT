
#include "CJavaCarManager.h"

IJavaCarManager* CJavaCarManager::sInstance = NULL;
SpinLock CJavaCarManager::sInstanceLock;

HashTable<IInterface*, Type_UInt64> CJavaCarManager::sCarObjects;
HashTable<Handle64, Type_UInt64> CJavaCarManager::sJavaObjects;
pthread_mutex_t CJavaCarManager::sObjectLock;

IJavaCarManager* gJavaCarManager = NULL;

ELAPI _CJavaCarManager_AcquireInstance(
    /* [out] */ IJavaCarManager** manager)
{
    return CJavaCarManager::AcquireInstance(manager);
}

void InitJavaCarManager()
{
    _CJavaCarManager_AcquireInstance(&gJavaCarManager);
}

void UninitJavaCarManager()
{
    gJavaCarManager->Release();
    gJavaCarManager = NULL;
}

ECode CJavaCarManager::AcquireInstance(
    /* [out] */ IJavaCarManager** manager)
{
    if (!manager) {
        return E_INVALID_ARGUMENT;
    }

    sInstanceLock.Lock();
    if (sInstance == NULL) {
        CJavaCarManager* instance = new CJavaCarManager();
        if (instance == NULL) {
            sInstanceLock.Unlock();
            return E_OUT_OF_MEMORY;
        }

        sInstance = IJavaCarManager::Probe(instance);
    }
    *manager = sInstance;
    (*manager)->AddRef();
    sInstanceLock.Unlock();

    return NOERROR;
}

CJavaCarManager::CJavaCarManager()
{
    pthread_mutexattr_t recursiveAttr;
    pthread_mutexattr_init(&recursiveAttr);
    pthread_mutexattr_settype(&recursiveAttr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&sObjectLock, &recursiveAttr);
    pthread_mutexattr_destroy(&recursiveAttr);
}

CJavaCarManager::~CJavaCarManager()
{
    sInstanceLock.Lock();
    sInstance = NULL;
    sInstanceLock.Unlock();

    pthread_mutex_destroy(&sObjectLock);
}

UInt32 CJavaCarManager::AddRef()
{
    return ElLightRefBase::AddRef();
}

UInt32 CJavaCarManager::Release()
{
    return ElLightRefBase::Release();
}

PInterface CJavaCarManager::Probe(
    /* [in] */ REIID riid)
{
    if (riid == EIID_IInterface) {
        return (PInterface)this;
    }
    else if (riid == EIID_IJavaCarManager) {
        return (IJavaCarManager *)this;
    }
    else {
        return NULL;
    }
}

ECode CJavaCarManager::GetInterfaceID(
    /* [in] */ IInterface* object,
    /* [out] */ InterfaceID* iid)
{
    if (!iid) {
        return E_INVALID_ARGUMENT;
    }

    if (object == (IInterface *)(IJavaCarManager *)this) {
        *iid = EIID_IJavaCarManager;
    }
    else {
        return E_INVALID_ARGUMENT;
    }
    return NOERROR;
}

ECode CJavaCarManager::AddCarObject(
    /* [in] */ Handle64 javaObj,
    /* [in] */ IInterface* carObj)
{
    if (javaObj == 0 || !carObj) {
        return E_INVALID_ARGUMENT;
    }

    pthread_mutex_lock(&sObjectLock);
    sCarObjects.Put((PVoid)javaObj, &carObj);
    sJavaObjects.Put((PVoid)carObj, &javaObj);
    pthread_mutex_unlock(&sObjectLock);
    return NOERROR;
}

ECode CJavaCarManager::RemoveCarObject(
    /* [in] */ Handle64 javaObj,
    /* [in] */ IInterface* carObj)
{
    if (javaObj == 0 || !carObj) {
        return E_INVALID_ARGUMENT;
    }

    pthread_mutex_lock(&sObjectLock);
    sCarObjects.Remove((PVoid)javaObj);
    sJavaObjects.Remove((PVoid)carObj);
    pthread_mutex_unlock(&sObjectLock);
    return NOERROR;
}

ECode CJavaCarManager::GetJavaObject(
    /* [in] */ IInterface* carObj,
    /* [out] */ Handle64* javaObj)
{
    if (!javaObj || !carObj) {
        return E_INVALID_ARGUMENT;
    }

    pthread_mutex_lock(&sObjectLock);
    javaObj = sJavaObjects.Get((PVoid)carObj);
    pthread_mutex_unlock(&sObjectLock);
    return NOERROR;
}

ECode CJavaCarManager::GetCarObject(
    /* [in] */ Handle64 javaObj,
    /* [out] */ IInterface** carObj)
{
    if (javaObj == 0 || !carObj) {
        return E_INVALID_ARGUMENT;
    }

    pthread_mutex_lock(&sObjectLock);
    carObj = sCarObjects.Get((PVoid)javaObj);
    pthread_mutex_unlock(&sObjectLock);
    return NOERROR;
}


