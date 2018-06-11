
#ifndef __ELASTOS_WALLET_CWALLETENVIROMENT_H__
#define __ELASTOS_WALLET_CWALLETENVIROMENT_H__

#include "_CWalletEnviroment.h"
#include "elastos/core/Singleton.h"


CarClass(CWalletEnviroment)
    , public Singleton
    , public IWalletEnviroment
{
public:
    CAR_SINGLETON_DECL()

    CAR_INTERFACE_DECL()

    CARAPI InitializeRootPath(
        /* [in] */ const String& rootPath);

    CARAPI GetRootPath(
        /* [out] */ String * pPath);

    CARAPI GetMasterWalletManager(
        /* [out] */ IMasterWalletManager ** ppWalletMgr);

private:
    // TODO: Add your private member variables here.
};


#endif // __ELASTOS_WALLET_CWALLETENVIROMENT_H__
