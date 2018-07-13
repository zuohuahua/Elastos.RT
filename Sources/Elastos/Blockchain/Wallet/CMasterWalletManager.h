
#ifndef __ELASTOS_WALLET_MASTERWALLETMANAGER_H__
#define __ELASTOS_WALLET_MASTERWALLETMANAGER_H__

#include "_CMasterWalletManager.h"
#include "elastos/core/Object.h"
#include "MasterWalletManager.h"

#include <android/log.h>
#define TAG "Elastos_CAR_MasterWalletManager_Wallet"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__)

struct compare_string
{
    bool operator()(const char *a, const char *b) const
    {
        return std::strcmp(a, b) == 0;
    }
};

CarClass(CMasterWalletManager)
    , public Object
    , public IMasterWalletManager
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    CMasterWalletManager();

    ~CMasterWalletManager();

    CARAPI constructor(
        /* [in] */ const String& rootPath);

    CARAPI CreateMasterWallet(
        /* [in] */ const String& masterWalletId,
        /* [in] */ const String& mnemonic,
        /* [in] */ const String& phrasePassword,
        /* [in] */ const String& payPassword,
        /* [in] */ const String& language,
        /* [out] */ IMasterWallet** masterWallet);

    CARAPI GetAllMasterWallets(
        /* [out, callee] */ ArrayOf<IMasterWallet*>** wallets);

    CARAPI DestroyWallet(
        /* [in] */ const String& masterWalletId);

    CARAPI ImportWalletWithKeystore(
        /* [in] */ const String& masterWalletId,
        /* [in] */ const String& keystoreContent,
        /* [in] */ const String& backupPassword,
        /* [in] */ const String& payPassword,
        /* [in] */ const String& phrasePassword,
        /* [out] */ IMasterWallet** masterWallet);

    CARAPI ImportWalletWithMnemonic(
        /* [in] */ const String& masterWalletId,
        /* [in] */ const String& mnemonic,
        /* [in] */ const String& phrasePassword,
        /* [in] */ const String& payPassword,
        /* [in] */ const String& language,
        /* [out] */ IMasterWallet** masterWallet);

    CARAPI ExportWalletWithKeystore(
        /* [in] */ IMasterWallet* masterWallet,
        /* [in] */ const String& backupPassword,
        /* [in] */ const String& payPassword,
        /* [out] */ String* keystoreContent);

    CARAPI ExportWalletWithMnemonic(
        /* [in] */ IMasterWallet *masterWallet,
        /* [in] */ const String& payPassword,
        /* [out] */ String* mnemonic);

    CARAPI GenerateMnemonic(
        /* [in] */ const String& language,
        /* [out] */ String* mnemonic);

    CARAPI SaveConfigs();

private:
    Elastos::ElaWallet::MasterWalletManager* mSpvMasterWalletMgr;
    std::map<const char*, IMasterWallet*, compare_string> mMasterWalletsMap;
};

#endif // __ELASTOS_WALLET_MASTERWALLETMANAGER_H__
