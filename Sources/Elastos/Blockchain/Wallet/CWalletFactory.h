
#ifndef __ELASTOS_WALLET_CWALLETFACTORY_H__
#define __ELASTOS_WALLET_CWALLETFACTORY_H__

#include "_CWalletFactory.h"
#include "elastos/core/Object.h"


CarClass(CWalletFactory)
    , public Object
    , public IWalletFactory
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    CARAPI CreateMasterWallet(
        /* [in] */ const String& backupPassword,
        /* [in] */ const String& payPassword,
        /* [out] */ IMasterWallet ** ppMasterWallet);

    CARAPI DestroyWallet(
        /* [in] */ IMasterWallet * pMasterWallet);

    CARAPI ImportWalletWithKeystore(
        /* [in] */ const String& keystorePath,
        /* [in] */ const String& backupPassword,
        /* [in] */ const String& payPassword,
        /* [out] */ IMasterWallet ** ppMasterWallet);

    CARAPI ImportWalletWithMnemonic(
        /* [in] */ const String& mnemonic,
        /* [in] */ const String& backupPassword,
        /* [in] */ const String& payPassword,
        /* [out] */ IMasterWallet ** ppMasterWallet);

    CARAPI ExportWalletKeystore(
        /* [in] */ IMasterWallet * pMasterWallet,
        /* [in] */ const String& backupPassword,
        /* [in] */ const String& keystorePath);

    CARAPI ExportWalletMnemonic(
        /* [in] */ IMasterWallet * pMasterWallet,
        /* [in] */ const String& backupPassword,
        /* [out] */ String * pMnemonic);

    CARAPI constructor();

private:
    // TODO: Add your private member variables here.
};


#endif // __ELASTOS_WALLET_CWALLETFACTORY_H__
