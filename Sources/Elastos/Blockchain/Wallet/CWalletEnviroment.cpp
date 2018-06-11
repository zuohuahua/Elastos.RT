
#include "CWalletEnviroment.h"


CAR_SINGLETON_IMPL(CWalletEnviroment)
CAR_INTERFACE_IMPL(CWalletEnviroment, Singleton, IWalletEnviroment);

ECode CWalletEnviroment::InitializeRootPath(
    /* [in] */ const String& rootPath)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CWalletEnviroment::GetRootPath(
    /* [out] */ String * pPath)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CWalletEnviroment::GetMasterWalletManager(
    /* [out] */ IMasterWalletManager ** ppWalletMgr)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}
