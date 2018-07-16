
#ifndef __ELASTOS_DID_CDIDMANAGER_H__
#define __ELASTOS_DID_CDIDMANAGER_H__

#include "_CDIDManager.h"
#include "elastos/core/Object.h"
#include <elcontainer.h>
#include "ididManager.h"

struct compare_string
{
    bool operator()(const char *a, const char *b) const
    {
        return std::strcmp(a, b) == 0;
    }
};

CarClass(CDIDManager)
    , public Object
    , public IDIDManager
{
private:
    class DIDManagerCallback
        : public Object
        , public Elastos::DID::IIdManagerCallback
    {
    public:
        DIDManagerCallback(
            /* [in] */ IDIDManagerCallback* callback);

        virtual void OnIdStatusChanged(
                /* [in] */ const std::string &id,
                /* [in] */ const std::string &path,
                /* [in] */ const nlohmann::json &value);

    private:
        AutoPtr<IDIDManagerCallback> mCallback;
    };


public:
    CAR_OBJECT_DECL()
    CAR_INTERFACE_DECL()

    CDIDManager();

    ~CDIDManager();

    CARAPI CreateDID(
        /* [in] */ const String& password,
        /* [out] */ IDID ** ppDid);

    CARAPI GetDID(
        /* [in] */ const String& didName,
        /* [out] */ IDID ** ppDid);

    CARAPI GetDIDList(
        /* [out] */ String * pDidListJson);

    CARAPI DestoryDID(
        /* [in] */ const String& did);

    CARAPI RegisterCallback(
        /* [in] */ const String& did,
        /* [in] */ IDIDManagerCallback * pDidcallback);

    CARAPI UnregisterCallback(
        /* [in] */ const String& did);

    CARAPI constructor(
        /* [in] */ IMasterWallet * pMasterWallet,
        /* [in] */ const String& rootPath);

private:
    Elastos::DID::IDIDManager* mIDIDMgr;
    std::map<const char*, DIDManagerCallback*, compare_string> mIdManagerCallbacksMap;
    std::map<const char*, IDID*, compare_string> mDIDsMap;
};


#endif // __ELASTOS_DID_CDIDMANAGER_H__
