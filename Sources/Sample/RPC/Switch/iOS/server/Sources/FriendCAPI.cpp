//
//  FriendCAPI.cpp
//  SwitchServer
//
//  Created by Joel Liang on 2018/9/1.
//

#include <stdio.h>

#include <elastos/core/Object.h>
#include "ElastosCore.h"
#include "elatypes.h"

#include "FriendCAPI.h"

ECode friendGetUid(IFriend *iFriend, const char** pUid)
{
    String uid;
    ECode ec = iFriend->GetUid(&uid);
    if (SUCCEEDED(ec)) {
        *pUid = strdup(uid.string());
    }
    return ec;
}

ECode friendIsOnline(IFriend *iFriend, Boolean* online)
{
    return iFriend->IsOnline(online);
}
