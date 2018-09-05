//
//  FriendCAPI.h
//  SwitchServer
//
//  Created by Joel Liang on 2018/9/1.
//

#ifndef FriendCAPI_h
#define FriendCAPI_h

#ifdef __cplusplus
    #include "elatypes.h"
extern "C" {
#else
    typedef struct IFriend IFriend;
#endif
    _ELASTOS ECode friendGetUid(IFriend *iFriend, const char** pUid);
    _ELASTOS ECode friendIsOnline(IFriend *iFriend, Boolean* online);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* FriendCAPI_h */
