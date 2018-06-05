
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
        /* [in] */ const String& phrasePassword,
        /* [in] */ const String& payPassword,
        /* [in] */ const String& language,
        /* [out] */ IMasterWallet ** ppMasterWallet);

    CARAPI DestroyWallet(
        /* [in] */ IMasterWallet * pMasterWallet);

    CARAPI ImportWalletWithKeystore(
        /* [in] */ const String& keystorePath,
        /* [in] */ const String& backupPassword,
        /* [in] */ const String& payPassword,
        /* [out] */ IMasterWallet ** ppMasterWallet);

    CARAPI ExportWalletWithKeystore(
        /* [in] */ IMasterWallet * pMasterWallet,
        /* [in] */ const String& backupPassword,
        /* [in] */ const String& keystorePath);

    CARAPI ImportWalletWithMnemonic(
        /* [in] */ const String& mnemonic,
        /* [in] */ const String& phrasePassword,
        /* [in] */ const String& payPassword,
        /* [in] */ const String& language,
        /* [out] */ IMasterWallet ** ppMasterWallet);

    CARAPI ExportWalletWithMnemonic(
        /* [in] */ IMasterWallet * pMasterWallet,
        /* [in] */ const String& payPassword,
        /* [out] */ String * pMnemonic);

    CARAPI constructor();

private:
    // TODO: Add your private member variables here.
};


#endif // __ELASTOS_WALLET_CWALLETFACTORY_H__
