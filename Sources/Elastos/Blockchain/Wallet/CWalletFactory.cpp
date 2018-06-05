
#include "CWalletFactory.h"


CAR_OBJECT_IMPL(CWalletFactory)
CAR_INTERFACE_IMPL(CWalletFactory, Object, IWalletFactory);

ECode CWalletFactory::CreateMasterWallet(
    /* [in] */ const String& phrasePassword,
    /* [in] */ const String& payPassword,
    /* [in] */ const String& language,
    /* [out] */ IMasterWallet ** ppMasterWallet)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CWalletFactory::DestroyWallet(
    /* [in] */ IMasterWallet * pMasterWallet)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CWalletFactory::ImportWalletWithKeystore(
    /* [in] */ const String& keystorePath,
    /* [in] */ const String& backupPassword,
    /* [in] */ const String& payPassword,
    /* [out] */ IMasterWallet ** ppMasterWallet)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CWalletFactory::ExportWalletWithKeystore(
    /* [in] */ IMasterWallet * pMasterWallet,
    /* [in] */ const String& backupPassword,
    /* [in] */ const String& keystorePath)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CWalletFactory::ImportWalletWithMnemonic(
    /* [in] */ const String& mnemonic,
    /* [in] */ const String& phrasePassword,
    /* [in] */ const String& payPassword,
    /* [in] */ const String& language,
    /* [out] */ IMasterWallet ** ppMasterWallet)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CWalletFactory::ExportWalletWithMnemonic(
    /* [in] */ IMasterWallet * pMasterWallet,
    /* [in] */ const String& payPassword,
    /* [out] */ String * pMnemonic)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CWalletFactory::constructor()
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}
