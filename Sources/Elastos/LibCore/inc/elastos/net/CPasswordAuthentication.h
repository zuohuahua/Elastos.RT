//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#ifndef __ELASTOS_NET_CPASSWORDAUTHENTICATION_H__
#define __ELASTOS_NET_CPASSWORDAUTHENTICATION_H__

#include "_Elastos_Net_CPasswordAuthentication.h"
#include "elastos/core/Object.h"

using Elastos::Core::Object;

namespace Elastos {
namespace Net {

CarClass(CPasswordAuthentication)
    , public Object
    , public IPasswordAuthentication
{
public:
    CAR_INTERFACE_DECL()

    CAR_OBJECT_DECL()

    ~CPasswordAuthentication();

    CARAPI constructor(
        /* [in] */ const String& userName,
        /* [in] */ ArrayOf<Char32> * password);

    CARAPI GetPassword(
        /* [out, callee] */ ArrayOf<Char32>** password);

    CARAPI GetUserName(
        /* [out] */ String* userName);

private:
    String mUserName;

    AutoPtr<ArrayOf<Char32> > mPassword;
};

} // namespace Net
} // namespace Elastos

#endif //__ELASTOS_NET_CPASSWORDAUTHENTICATION_H__
