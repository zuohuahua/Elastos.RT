
#include <elastos.h>

ECode Decode(
    /* [in] */ ArrayOf<Byte>* inData,
    /* [out, callee] */ ArrayOf<Byte>** outData);

ECode Encode(
    /* [in] */ ArrayOf<Byte>* inData,
    /* [out] */ String* outData);
