#ifndef ___Elastos_CoreLibrary_Extensions_h__
#define ___Elastos_CoreLibrary_Extensions_h__

#include <Elastos.CoreLibrary.h>

EXTERN_C ELAPI _Impl_AcquireCallbackHandler(PInterface pServerObj, _ELASTOS REIID iid, PInterface *ppHandler);
EXTERN_C ELAPI _Impl_CheckClsId(PInterface pServerObj, const _ELASTOS ClassID* pClassid, PInterface *ppServerObj);

namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("E045FD17-C312-2BCE-5AFF-CE4BDAB76CEF")
ICipher : public IInterface
{
    static const _ELASTOS Int32 DECRYPT_MODE = 2;
    static const _ELASTOS Int32 ENCRYPT_MODE = 1;
    static const _ELASTOS Int32 PRIVATE_KEY = 2;
    static const _ELASTOS Int32 PUBLIC_KEY = 1;
    static const _ELASTOS Int32 SECRET_KEY = 3;
    static const _ELASTOS Int32 UNWRAP_MODE = 4;
    static const _ELASTOS Int32 WRAP_MODE = 3;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICipher*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICipher*)pObj->Probe(EIID_ICipher);
    }

    static CARAPI_(ICipher*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICipher*)pObj->Probe(EIID_ICipher);
    }

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI GetAlgorithm(
        /* [out] */ _ELASTOS String * value) = 0;

    virtual CARAPI GetBlockSize(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetOutputSize(
        /* [in] */ _ELASTOS Int32 inputLen,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetIV(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** value) = 0;

    virtual CARAPI GetParameters(
        /* [out] */ Elastos::Security::IAlgorithmParameters ** parameters) = 0;

    virtual CARAPI GetExemptionMechanism(
        /* [out] */ Elastosx::Crypto::IExemptionMechanism ** parameters) = 0;

    virtual CARAPI Init(
        /* [in] */ _ELASTOS Int32 opmode,
        /* [in] */ Elastos::Security::IKey * key) = 0;

    virtual CARAPI Init(
        /* [in] */ _ELASTOS Int32 opmode,
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ Elastos::Security::ISecureRandom * sr) = 0;

    virtual CARAPI Init(
        /* [in] */ _ELASTOS Int32 opmode,
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * sr) = 0;

    virtual CARAPI Init(
        /* [in] */ _ELASTOS Int32 opmode,
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * aps,
        /* [in] */ Elastos::Security::ISecureRandom * sr) = 0;

    virtual CARAPI Init(
        /* [in] */ _ELASTOS Int32 opmode,
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ Elastos::Security::IAlgorithmParameters * ap) = 0;

    virtual CARAPI Init(
        /* [in] */ _ELASTOS Int32 opmode,
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ Elastos::Security::IAlgorithmParameters * ap,
        /* [in] */ Elastos::Security::ISecureRandom * sr) = 0;

    virtual CARAPI Init(
        /* [in] */ _ELASTOS Int32 opmode,
        /* [in] */ Elastos::Security::Cert::ICertificate * certificate) = 0;

    virtual CARAPI Init(
        /* [in] */ _ELASTOS Int32 opmode,
        /* [in] */ Elastos::Security::Cert::ICertificate * certificate,
        /* [in] */ Elastos::Security::ISecureRandom * sr) = 0;

    virtual CARAPI Update(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * input,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** output) = 0;

    virtual CARAPI Update(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * input,
        /* [in] */ _ELASTOS Int32 inputOffset,
        /* [in] */ _ELASTOS Int32 inputLen,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** output) = 0;

    virtual CARAPI Update(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * input,
        /* [in] */ _ELASTOS Int32 inputOffset,
        /* [in] */ _ELASTOS Int32 inputLen,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * output,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Update(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * input,
        /* [in] */ _ELASTOS Int32 inputOffset,
        /* [in] */ _ELASTOS Int32 inputLen,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * output,
        /* [in] */ _ELASTOS Int32 outputOffset,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Update(
        /* [in] */ Elastos::IO::IByteBuffer * input,
        /* [in] */ Elastos::IO::IByteBuffer * output,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI UpdateAAD(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * input) = 0;

    virtual CARAPI UpdateAAD(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * input,
        /* [in] */ _ELASTOS Int32 inputOffset,
        /* [in] */ _ELASTOS Int32 inputLen) = 0;

    virtual CARAPI UpdateAAD(
        /* [in] */ Elastos::IO::IByteBuffer * input) = 0;

    virtual CARAPI DoFinal(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** buf) = 0;

    virtual CARAPI DoFinal(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * output,
        /* [in] */ _ELASTOS Int32 outputOffset,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI DoFinal(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * input,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** output) = 0;

    virtual CARAPI DoFinal(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * input,
        /* [in] */ _ELASTOS Int32 inputOffset,
        /* [in] */ _ELASTOS Int32 inputLen,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** output) = 0;

    virtual CARAPI DoFinal(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * input,
        /* [in] */ _ELASTOS Int32 inputOffset,
        /* [in] */ _ELASTOS Int32 inputLen,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * output,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI DoFinal(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * input,
        /* [in] */ _ELASTOS Int32 inputOffset,
        /* [in] */ _ELASTOS Int32 inputLen,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * output,
        /* [in] */ _ELASTOS Int32 outputOffset,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI DoFinal(
        /* [in] */ Elastos::IO::IByteBuffer * input,
        /* [in] */ Elastos::IO::IByteBuffer * output,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Wrap(
        /* [in] */ Elastos::Security::IKey * key,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** array) = 0;

    virtual CARAPI Unwrap(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * wrappedKey,
        /* [in] */ const _ELASTOS String& wrappedKeyAlgorithm,
        /* [in] */ _ELASTOS Int32 wrappedKeyType,
        /* [out] */ Elastos::Security::IKey ** key) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("A8F56F01-C312-2BCE-5A47-E83BA3F5EFBC")
ICipherHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICipherHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICipherHelper*)pObj->Probe(EIID_ICipherHelper);
    }

    static CARAPI_(ICipherHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICipherHelper*)pObj->Probe(EIID_ICipherHelper);
    }

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& transformation,
        /* [out] */ Elastosx::Crypto::ICipher ** cipher) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& transformation,
        /* [in] */ const _ELASTOS String& provider,
        /* [out] */ Elastosx::Crypto::ICipher ** cipher) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& transformation,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastosx::Crypto::ICipher ** cipher) = 0;

    virtual CARAPI GetMaxAllowedKeyLength(
        /* [in] */ const _ELASTOS String& transformation,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetMaxAllowedParameterSpec(
        /* [in] */ const _ELASTOS String& transformation,
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec ** value) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("333F234C-0312-6416-9F6D-59CB46188C1F")
ICipherInputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICipherInputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICipherInputStream*)pObj->Probe(EIID_ICipherInputStream);
    }

    static CARAPI_(ICipherInputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICipherInputStream*)pObj->Probe(EIID_ICipherInputStream);
    }

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("2EC22422-0312-3316-56DC-972A1B050918")
ICipherOutputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICipherOutputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICipherOutputStream*)pObj->Probe(EIID_ICipherOutputStream);
    }

    static CARAPI_(ICipherOutputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICipherOutputStream*)pObj->Probe(EIID_ICipherOutputStream);
    }

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("ED39F54C-0312-6416-9F71-28FBC3414919")
ICipherSpi : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICipherSpi*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICipherSpi*)pObj->Probe(EIID_ICipherSpi);
    }

    static CARAPI_(ICipherSpi*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICipherSpi*)pObj->Probe(EIID_ICipherSpi);
    }

    virtual CARAPI EngineSetMode(
        /* [in] */ const _ELASTOS String& mode) = 0;

    virtual CARAPI EngineSetPadding(
        /* [in] */ const _ELASTOS String& padding) = 0;

    virtual CARAPI EngineGetBlockSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI EngineGetOutputSize(
        /* [in] */ _ELASTOS Int32 inputLen,
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI EngineGetIV(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** iv) = 0;

    virtual CARAPI EngineGetParameters(
        /* [out] */ Elastos::Security::IAlgorithmParameters ** param) = 0;

    virtual CARAPI EngineInit(
        /* [in] */ _ELASTOS Int32 opmode,
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ Elastos::Security::ISecureRandom * random) = 0;

    virtual CARAPI EngineInit(
        /* [in] */ _ELASTOS Int32 opmode,
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * params,
        /* [in] */ Elastos::Security::ISecureRandom * random) = 0;

    virtual CARAPI EngineInit(
        /* [in] */ _ELASTOS Int32 opmode,
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ Elastos::Security::IAlgorithmParameters * params,
        /* [in] */ Elastos::Security::ISecureRandom * random) = 0;

    virtual CARAPI EngineUpdate(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * input,
        /* [in] */ _ELASTOS Int32 inputOffset,
        /* [in] */ _ELASTOS Int32 inputLen,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** output) = 0;

    virtual CARAPI EngineUpdate(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * input,
        /* [in] */ _ELASTOS Int32 inputOffset,
        /* [in] */ _ELASTOS Int32 inputLen,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * output,
        /* [in] */ _ELASTOS Int32 outputOffset,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI EngineUpdate(
        /* [in] */ Elastos::IO::IByteBuffer * input,
        /* [in] */ Elastos::IO::IByteBuffer * output,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI EngineUpdateAAD(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * input,
        /* [in] */ _ELASTOS Int32 inputOffset,
        /* [in] */ _ELASTOS Int32 inputLen) = 0;

    virtual CARAPI EngineUpdateAAD(
        /* [in] */ Elastos::IO::IByteBuffer * input) = 0;

    virtual CARAPI EngineDoFinal(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * input,
        /* [in] */ _ELASTOS Int32 inputOffset,
        /* [in] */ _ELASTOS Int32 inputLen,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** bytes) = 0;

    virtual CARAPI EngineDoFinal(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * input,
        /* [in] */ _ELASTOS Int32 inputOffset,
        /* [in] */ _ELASTOS Int32 inputLen,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * output,
        /* [in] */ _ELASTOS Int32 outputOffset,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI EngineDoFinal(
        /* [in] */ Elastos::IO::IByteBuffer * input,
        /* [in] */ Elastos::IO::IByteBuffer * output,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI EngineWrap(
        /* [in] */ Elastos::Security::IKey * keyToWrap,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** wrappedKey) = 0;

    virtual CARAPI EngineUnwrap(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * wrappedKey,
        /* [in] */ const _ELASTOS String& wrappedKeyAlgorithm,
        /* [in] */ _ELASTOS Int32 wrappedKeyType,
        /* [out] */ Elastos::Security::IKey ** key) = 0;

    virtual CARAPI EngineGetKeySize(
        /* [in] */ Elastos::Security::IKey * key,
        /* [out] */ _ELASTOS Int32 * size) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("30F81F02-85D2-2FBF-C3CE-2B5A7333FB3B")
INullCipherSpi : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INullCipherSpi*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INullCipherSpi*)pObj->Probe(EIID_INullCipherSpi);
    }

    static CARAPI_(INullCipherSpi*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INullCipherSpi*)pObj->Probe(EIID_INullCipherSpi);
    }

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("DDA0855A-1412-8013-D516-CBA0B7B7660A")
IEncryptedPrivateKeyInfo : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IEncryptedPrivateKeyInfo*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEncryptedPrivateKeyInfo*)pObj->Probe(EIID_IEncryptedPrivateKeyInfo);
    }

    static CARAPI_(IEncryptedPrivateKeyInfo*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEncryptedPrivateKeyInfo*)pObj->Probe(EIID_IEncryptedPrivateKeyInfo);
    }

    virtual CARAPI GetAlgName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetAlgParameters(
        /* [out] */ Elastos::Security::IAlgorithmParameters ** params) = 0;

    virtual CARAPI GetEncryptedData(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** data) = 0;

    virtual CARAPI GetKeySpec(
        /* [in] */ Elastosx::Crypto::ICipher * cipher,
        /* [out] */ Elastos::Security::Spec::IPKCS8EncodedKeySpec ** spec) = 0;

    virtual CARAPI GetKeySpec(
        /* [in] */ Elastos::Security::IKey * decryptKey,
        /* [out] */ Elastos::Security::Spec::IPKCS8EncodedKeySpec ** spec) = 0;

    virtual CARAPI GetKeySpec(
        /* [in] */ Elastos::Security::IKey * decryptKey,
        /* [in] */ const _ELASTOS String& providerName,
        /* [out] */ Elastos::Security::Spec::IPKCS8EncodedKeySpec ** spec) = 0;

    virtual CARAPI GetKeySpec(
        /* [in] */ Elastos::Security::IKey * decryptKey,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastos::Security::Spec::IPKCS8EncodedKeySpec ** spec) = 0;

    virtual CARAPI GetEncoded(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** data) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("60618E4B-1452-3014-D25A-40116AA90D18")
IExemptionMechanism : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IExemptionMechanism*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IExemptionMechanism*)pObj->Probe(EIID_IExemptionMechanism);
    }

    static CARAPI_(IExemptionMechanism*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IExemptionMechanism*)pObj->Probe(EIID_IExemptionMechanism);
    }

    virtual CARAPI GetName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI IsCryptoAllowed(
        /* [in] */ Elastos::Security::IKey * key,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetOutputSize(
        /* [in] */ _ELASTOS Int32 inputLen,
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI Init(
        /* [in] */ Elastos::Security::IKey * key) = 0;

    virtual CARAPI Init(
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ Elastos::Security::IAlgorithmParameters * params) = 0;

    virtual CARAPI Init(
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * params) = 0;

    virtual CARAPI GenExemptionBlob(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** blob) = 0;

    virtual CARAPI GenExemptionBlob(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * output,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI GenExemptionBlob(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * output,
        /* [in] */ _ELASTOS Int32 outputOffset,
        /* [out] */ _ELASTOS Int32 * number) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("46464B4A-1452-3014-D25A-40116AA90D18")
IExemptionMechanismHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IExemptionMechanismHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IExemptionMechanismHelper*)pObj->Probe(EIID_IExemptionMechanismHelper);
    }

    static CARAPI_(IExemptionMechanismHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IExemptionMechanismHelper*)pObj->Probe(EIID_IExemptionMechanismHelper);
    }

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastosx::Crypto::IExemptionMechanism ** em) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& provider,
        /* [out] */ Elastosx::Crypto::IExemptionMechanism ** em) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastosx::Crypto::IExemptionMechanism ** em) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("995F844B-1452-3014-D25A-40116AA90D18")
IExemptionMechanismSpi : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IExemptionMechanismSpi*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IExemptionMechanismSpi*)pObj->Probe(EIID_IExemptionMechanismSpi);
    }

    static CARAPI_(IExemptionMechanismSpi*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IExemptionMechanismSpi*)pObj->Probe(EIID_IExemptionMechanismSpi);
    }

    virtual CARAPI EngineGenExemptionBlob(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** blob) = 0;

    virtual CARAPI EngineGenExemptionBlob(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * output,
        /* [in] */ _ELASTOS Int32 outputOffset,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI EngineGetOutputSize(
        /* [in] */ _ELASTOS Int32 inputLen,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI EngineInit(
        /* [in] */ Elastos::Security::IKey * key) = 0;

    virtual CARAPI EngineInit(
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ Elastos::Security::IAlgorithmParameters * params) = 0;

    virtual CARAPI EngineInit(
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * params) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("E0DC1B16-8712-359A-7A53-28FF3B2F69DF")
ISecretKey : public IInterface
{
    static const _ELASTOS Int64 serialVersionUID;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISecretKey*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISecretKey*)pObj->Probe(EIID_ISecretKey);
    }

    static CARAPI_(ISecretKey*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISecretKey*)pObj->Probe(EIID_ISecretKey);
    }

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("246A7643-0512-0A6B-E6A1-D0F9C3414919")
IKeyAgreement : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyAgreement*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyAgreement*)pObj->Probe(EIID_IKeyAgreement);
    }

    static CARAPI_(IKeyAgreement*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyAgreement*)pObj->Probe(EIID_IKeyAgreement);
    }

    virtual CARAPI GetAlgorithm(
        /* [out] */ _ELASTOS String * al) = 0;

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI Init(
        /* [in] */ Elastos::Security::IKey * key) = 0;

    virtual CARAPI Init(
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ Elastos::Security::ISecureRandom * random) = 0;

    virtual CARAPI Init(
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * random) = 0;

    virtual CARAPI Init(
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * random,
        /* [in] */ Elastos::Security::ISecureRandom * sr) = 0;

    virtual CARAPI DoPhase(
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ _ELASTOS Boolean lastPhase,
        /* [out] */ Elastos::Security::IKey ** result) = 0;

    virtual CARAPI GenerateSecret(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** secret) = 0;

    virtual CARAPI GenerateSecret(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * sharedSecret,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI GenerateSecret(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastosx::Crypto::ISecretKey ** key) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("7BA0455F-0512-0A6B-E6A1-D01901C58BB0")
IKeyAgreementHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyAgreementHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyAgreementHelper*)pObj->Probe(EIID_IKeyAgreementHelper);
    }

    static CARAPI_(IKeyAgreementHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyAgreementHelper*)pObj->Probe(EIID_IKeyAgreementHelper);
    }

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastosx::Crypto::IKeyAgreement ** ka) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& provider,
        /* [out] */ Elastosx::Crypto::IKeyAgreement ** ka) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastosx::Crypto::IKeyAgreement ** ka) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("BFF57E4C-0512-0A6B-E6A1-D0C9A1EC0F07")
IKeyAgreementSpi : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyAgreementSpi*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyAgreementSpi*)pObj->Probe(EIID_IKeyAgreementSpi);
    }

    static CARAPI_(IKeyAgreementSpi*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyAgreementSpi*)pObj->Probe(EIID_IKeyAgreementSpi);
    }

    virtual CARAPI EngineDoPhase(
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ _ELASTOS Boolean lastPhase,
        /* [out] */ Elastos::Security::IKey ** result) = 0;

    virtual CARAPI EngineGenerateSecret(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** result) = 0;

    virtual CARAPI EngineGenerateSecret(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * sharedSecret,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI EngineGenerateSecret(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastosx::Crypto::ISecretKey ** skey) = 0;

    virtual CARAPI EngineInit(
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ Elastos::Security::ISecureRandom * random) = 0;

    virtual CARAPI EngineInit(
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * params,
        /* [in] */ Elastos::Security::ISecureRandom * random) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("22D95455-0512-106B-983D-7B74F5878392")
IKeyGenerator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyGenerator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyGenerator*)pObj->Probe(EIID_IKeyGenerator);
    }

    static CARAPI_(IKeyGenerator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyGenerator*)pObj->Probe(EIID_IKeyGenerator);
    }

    virtual CARAPI GetAlgorithm(
        /* [out] */ _ELASTOS String * al) = 0;

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI GenerateKey(
        /* [out] */ Elastosx::Crypto::ISecretKey ** skey) = 0;

    virtual CARAPI Init(
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * params) = 0;

    virtual CARAPI Init(
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * params,
        /* [in] */ Elastos::Security::ISecureRandom * random) = 0;

    virtual CARAPI Init(
        /* [in] */ _ELASTOS Int32 keysize) = 0;

    virtual CARAPI Init(
        /* [in] */ _ELASTOS Int32 keysize,
        /* [in] */ Elastos::Security::ISecureRandom * random) = 0;

    virtual CARAPI Init(
        /* [in] */ Elastos::Security::ISecureRandom * random) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("88844517-8512-10F2-1AA3-3579CB7584BE")
IKeyGeneratorHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyGeneratorHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyGeneratorHelper*)pObj->Probe(EIID_IKeyGeneratorHelper);
    }

    static CARAPI_(IKeyGeneratorHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyGeneratorHelper*)pObj->Probe(EIID_IKeyGeneratorHelper);
    }

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastosx::Crypto::IKeyGenerator ** ka) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& provider,
        /* [out] */ Elastosx::Crypto::IKeyGenerator ** ka) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastosx::Crypto::IKeyGenerator ** ka) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("F7DB505A-0512-106B-983D-7B749543D91F")
IKeyGeneratorSpi : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyGeneratorSpi*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyGeneratorSpi*)pObj->Probe(EIID_IKeyGeneratorSpi);
    }

    static CARAPI_(IKeyGeneratorSpi*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyGeneratorSpi*)pObj->Probe(EIID_IKeyGeneratorSpi);
    }

    virtual CARAPI EngineGenerateKey(
        /* [out] */ Elastosx::Crypto::ISecretKey ** result) = 0;

    virtual CARAPI EngineInit(
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * params,
        /* [in] */ Elastos::Security::ISecureRandom * random) = 0;

    virtual CARAPI EngineInit(
        /* [in] */ _ELASTOS Int32 keysize,
        /* [in] */ Elastos::Security::ISecureRandom * random) = 0;

    virtual CARAPI EngineInit(
        /* [in] */ Elastos::Security::ISecureRandom * random) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("5A6C721B-4592-BF9A-F392-F62DDBFBCFD4")
IMac : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMac*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMac*)pObj->Probe(EIID_IMac);
    }

    static CARAPI_(IMac*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMac*)pObj->Probe(EIID_IMac);
    }

    virtual CARAPI GetAlgorithm(
        /* [out] */ _ELASTOS String * al) = 0;

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI GetMacLength(
        /* [out] */ _ELASTOS Int32 * len) = 0;

    virtual CARAPI Init(
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * spec) = 0;

    virtual CARAPI Init(
        /* [in] */ Elastos::Security::IKey * key) = 0;

    virtual CARAPI Update(
        /* [in] */ _ELASTOS Byte input) = 0;

    virtual CARAPI Update(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * input,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 len) = 0;

    virtual CARAPI Update(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * input) = 0;

    virtual CARAPI Update(
        /* [in] */ Elastos::IO::IByteBuffer * input) = 0;

    virtual CARAPI DoFinal(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** result) = 0;

    virtual CARAPI DoFinal(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * output,
        /* [in] */ _ELASTOS Int32 outOffset) = 0;

    virtual CARAPI DoFinal(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * output,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** result) = 0;

    virtual CARAPI Reset() = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("2CA33C1F-4592-119A-FACE-68FD3B2F69DF")
IMacHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMacHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMacHelper*)pObj->Probe(EIID_IMacHelper);
    }

    static CARAPI_(IMacHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMacHelper*)pObj->Probe(EIID_IMacHelper);
    }

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastosx::Crypto::IMac ** mac) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& provider,
        /* [out] */ Elastosx::Crypto::IMac ** mac) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastosx::Crypto::IMac ** mac) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("2A386409-4592-DC9A-CCFE-CE4BDAB76CEF")
IMacSpi : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMacSpi*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMacSpi*)pObj->Probe(EIID_IMacSpi);
    }

    static CARAPI_(IMacSpi*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMacSpi*)pObj->Probe(EIID_IMacSpi);
    }

    virtual CARAPI EngineGetMacLength(
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI EngineInit(
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * params) = 0;

    virtual CARAPI EngineUpdate(
        /* [in] */ _ELASTOS Byte input) = 0;

    virtual CARAPI EngineUpdate(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * input,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 len) = 0;

    virtual CARAPI EngineDoFinal(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** input) = 0;

    virtual CARAPI EngineReset() = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("C7955D36-0712-2614-6AA0-B8D110DA8FF6")
ISecretKeyFactory : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISecretKeyFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISecretKeyFactory*)pObj->Probe(EIID_ISecretKeyFactory);
    }

    static CARAPI_(ISecretKeyFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISecretKeyFactory*)pObj->Probe(EIID_ISecretKeyFactory);
    }

    virtual CARAPI GetAlgorithm(
        /* [out] */ _ELASTOS String * al) = 0;

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI GenerateSecret(
        /* [in] */ Elastos::Security::Spec::IKeySpec * keySpec,
        /* [out] */ Elastosx::Crypto::ISecretKey ** key) = 0;

    virtual CARAPI GetKeySpec(
        /* [in] */ Elastosx::Crypto::ISecretKey * key,
        /* [in] */ const _ELASTOS ClassID & keySpec,
        /* [out] */ Elastos::Security::Spec::IKeySpec ** spec) = 0;

    virtual CARAPI TranslateKey(
        /* [in] */ Elastosx::Crypto::ISecretKey * key,
        /* [out] */ Elastosx::Crypto::ISecretKey ** secretKey) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("BFB4493C-0712-2614-6AA0-B8D1105A0414")
ISecretKeyFactoryHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISecretKeyFactoryHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISecretKeyFactoryHelper*)pObj->Probe(EIID_ISecretKeyFactoryHelper);
    }

    static CARAPI_(ISecretKeyFactoryHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISecretKeyFactoryHelper*)pObj->Probe(EIID_ISecretKeyFactoryHelper);
    }

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastosx::Crypto::ISecretKeyFactory ** secretKeyFactory) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& provider,
        /* [out] */ Elastosx::Crypto::ISecretKeyFactory ** secretKeyFactory) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastosx::Crypto::ISecretKeyFactory ** secretKeyFactory) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("580A5B2F-0712-2614-6AA0-B8D1101A8719")
ISecretKeyFactorySpi : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISecretKeyFactorySpi*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISecretKeyFactorySpi*)pObj->Probe(EIID_ISecretKeyFactorySpi);
    }

    static CARAPI_(ISecretKeyFactorySpi*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISecretKeyFactorySpi*)pObj->Probe(EIID_ISecretKeyFactorySpi);
    }

    virtual CARAPI EngineGenerateSecret(
        /* [in] */ Elastos::Security::Spec::IKeySpec * keySpec,
        /* [out] */ Elastosx::Crypto::ISecretKey ** key) = 0;

    virtual CARAPI EngineGetKeySpec(
        /* [in] */ Elastosx::Crypto::ISecretKey * key,
        /* [in] */ const _ELASTOS ClassID & keySpec,
        /* [out] */ Elastos::Security::Spec::IKeySpec ** spec) = 0;

    virtual CARAPI EngineTranslateKey(
        /* [in] */ Elastosx::Crypto::ISecretKey * key,
        /* [out] */ Elastosx::Crypto::ISecretKey ** secretKey) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("9DCD4545-0712-2961-4F7C-F9E1A0A40C1B")
ISealedObject : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISealedObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISealedObject*)pObj->Probe(EIID_ISealedObject);
    }

    static CARAPI_(ISealedObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISealedObject*)pObj->Probe(EIID_ISealedObject);
    }

    virtual CARAPI GetAlgorithm(
        /* [out] */ _ELASTOS String * result) = 0;

    virtual CARAPI GetObject(
        /* [in] */ Elastos::Security::IKey * key,
        /* [out] */ IInterface ** result) = 0;

    virtual CARAPI GetObject(
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ IInterface ** result) = 0;

    virtual CARAPI GetObject(
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ const _ELASTOS String& provider,
        /* [out] */ IInterface ** result) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("D4811C4C-85D2-2FDC-18B0-20FBEC878392")
INullCipher : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INullCipher*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INullCipher*)pObj->Probe(EIID_INullCipher);
    }

    static CARAPI_(INullCipher*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INullCipher*)pObj->Probe(EIID_INullCipher);
    }

};
}
}
namespace Elastosx {
namespace Crypto {
namespace Interfaces {
CAR_INTERFACE("B9222B1E-1352-2851-FF3B-2F69DFB2BDFF")
IDHKey : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDHKey*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDHKey*)pObj->Probe(EIID_IDHKey);
    }

    static CARAPI_(IDHKey*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDHKey*)pObj->Probe(EIID_IDHKey);
    }

    virtual CARAPI GetParams(
        /* [out] */ Elastosx::Crypto::Spec::IDHParameterSpec ** spec) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Interfaces {
CAR_INTERFACE("5AB12D0C-1352-3565-9B93-374AA1FCEFBC")
IDHPrivateKey : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDHPrivateKey*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDHPrivateKey*)pObj->Probe(EIID_IDHPrivateKey);
    }

    static CARAPI_(IDHPrivateKey*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDHPrivateKey*)pObj->Probe(EIID_IDHPrivateKey);
    }

    virtual CARAPI GetX(
        /* [out] */ Elastos::Math::IBigInteger ** bi) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Interfaces {
CAR_INTERFACE("E6A02C07-1352-7865-F9B2-2685F2BFF392")
IDHPublicKey : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDHPublicKey*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDHPublicKey*)pObj->Probe(EIID_IDHPublicKey);
    }

    static CARAPI_(IDHPublicKey*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDHPublicKey*)pObj->Probe(EIID_IDHPublicKey);
    }

    virtual CARAPI GetY(
        /* [out] */ Elastos::Math::IBigInteger ** bi) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Interfaces {
CAR_INTERFACE("60AA4606-B652-1438-CAFF-CE4BDAB76CEF")
IPBEKey : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPBEKey*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPBEKey*)pObj->Probe(EIID_IPBEKey);
    }

    static CARAPI_(IPBEKey*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPBEKey*)pObj->Probe(EIID_IPBEKey);
    }

    virtual CARAPI GetIterationCount(
        /* [out] */ _ELASTOS Int32 * count) = 0;

    virtual CARAPI GetSalt(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** salts) = 0;

    virtual CARAPI GetPassword(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Char32> ** salts) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("8630271D-E352-1470-CA73-336AFECE4BDA")
IDESKeySpec : public IInterface
{
    static const _ELASTOS Int32 DES_KEY_LEN = 8;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDESKeySpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDESKeySpec*)pObj->Probe(EIID_IDESKeySpec);
    }

    static CARAPI_(IDESKeySpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDESKeySpec*)pObj->Probe(EIID_IDESKeySpec);
    }

    virtual CARAPI GetKey(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** key) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("93563D1D-E352-1470-CA73-336A46E83BA3")
IDESKeySpecHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDESKeySpecHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDESKeySpecHelper*)pObj->Probe(EIID_IDESKeySpecHelper);
    }

    static CARAPI_(IDESKeySpecHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDESKeySpecHelper*)pObj->Probe(EIID_IDESKeySpecHelper);
    }

    virtual CARAPI IsParityAdjusted(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI IsWeak(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("4A3D2A1E-E352-E870-8952-28CFCDA8F93B")
IDESedeKeySpec : public IInterface
{
    static const _ELASTOS Int32 DES_EDE_KEY_LEN = 24;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDESedeKeySpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDESedeKeySpec*)pObj->Probe(EIID_IDESedeKeySpec);
    }

    static CARAPI_(IDESedeKeySpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDESedeKeySpec*)pObj->Probe(EIID_IDESedeKeySpec);
    }

    virtual CARAPI GetKey(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** key) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("C23E3A19-E352-E870-8952-28CFCDA819A1")
IDESedeKeySpecHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDESedeKeySpecHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDESedeKeySpecHelper*)pObj->Probe(EIID_IDESedeKeySpecHelper);
    }

    static CARAPI_(IDESedeKeySpecHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDESedeKeySpecHelper*)pObj->Probe(EIID_IDESedeKeySpecHelper);
    }

    virtual CARAPI IsParityAdjusted(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("E00D4434-8352-1008-50C4-B8CA61060A13")
IDHGenParameterSpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDHGenParameterSpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDHGenParameterSpec*)pObj->Probe(EIID_IDHGenParameterSpec);
    }

    static CARAPI_(IDHGenParameterSpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDHGenParameterSpec*)pObj->Probe(EIID_IDHGenParameterSpec);
    }

    virtual CARAPI GetPrimeSize(
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI GetExponentSize(
        /* [out] */ _ELASTOS Int32 * result) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("C5CA3230-8352-5708-39CC-4061E2477B1B")
IDHParameterSpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDHParameterSpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDHParameterSpec*)pObj->Probe(EIID_IDHParameterSpec);
    }

    static CARAPI_(IDHParameterSpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDHParameterSpec*)pObj->Probe(EIID_IDHParameterSpec);
    }

    virtual CARAPI GetP(
        /* [out] */ Elastos::Math::IBigInteger ** bi) = 0;

    virtual CARAPI GetG(
        /* [out] */ Elastos::Math::IBigInteger ** bi) = 0;

    virtual CARAPI GetL(
        /* [out] */ _ELASTOS Int32 * result) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("78A83314-1352-3565-9B93-374AA13C37A3")
IDHPrivateKeySpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDHPrivateKeySpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDHPrivateKeySpec*)pObj->Probe(EIID_IDHPrivateKeySpec);
    }

    static CARAPI_(IDHPrivateKeySpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDHPrivateKeySpec*)pObj->Probe(EIID_IDHPrivateKeySpec);
    }

    virtual CARAPI GetX(
        /* [out] */ Elastos::Math::IBigInteger ** bi) = 0;

    virtual CARAPI GetP(
        /* [out] */ Elastos::Math::IBigInteger ** bi) = 0;

    virtual CARAPI GetG(
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("EEAD321F-1352-7865-F9B2-2685F2DC8C9A")
IDHPublicKeySpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDHPublicKeySpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDHPublicKeySpec*)pObj->Probe(EIID_IDHPublicKeySpec);
    }

    static CARAPI_(IDHPublicKeySpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDHPublicKeySpec*)pObj->Probe(EIID_IDHPublicKeySpec);
    }

    virtual CARAPI GetY(
        /* [out] */ Elastos::Math::IBigInteger ** bi) = 0;

    virtual CARAPI GetP(
        /* [out] */ Elastos::Math::IBigInteger ** bi) = 0;

    virtual CARAPI GetG(
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("7FB63335-0412-1606-AE72-9881C2C48FF6")
IGCMParameterSpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IGCMParameterSpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IGCMParameterSpec*)pObj->Probe(EIID_IGCMParameterSpec);
    }

    static CARAPI_(IGCMParameterSpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IGCMParameterSpec*)pObj->Probe(EIID_IGCMParameterSpec);
    }

    virtual CARAPI GetTLen(
        /* [out] */ _ELASTOS Int32 * bi) = 0;

    virtual CARAPI GetIV(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** bi) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("D0132B3B-8492-571C-39CC-4061E2477B1B")
IIvParameterSpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IIvParameterSpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IIvParameterSpec*)pObj->Probe(EIID_IIvParameterSpec);
    }

    static CARAPI_(IIvParameterSpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IIvParameterSpec*)pObj->Probe(EIID_IIvParameterSpec);
    }

    virtual CARAPI GetIV(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** bi) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("FA756324-0612-0E05-325C-E5300385891F")
IOAEPParameterSpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IOAEPParameterSpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IOAEPParameterSpec*)pObj->Probe(EIID_IOAEPParameterSpec);
    }

    static CARAPI_(IOAEPParameterSpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IOAEPParameterSpec*)pObj->Probe(EIID_IOAEPParameterSpec);
    }

    virtual CARAPI GetDigestAlgorithm(
        /* [out] */ _ELASTOS String * result) = 0;

    virtual CARAPI GetMGFAlgorithm(
        /* [out] */ _ELASTOS String * result) = 0;

    virtual CARAPI GetMGFParameters(
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec ** spec) = 0;

    virtual CARAPI GetPSource(
        /* [out] */ Elastosx::Crypto::Spec::IPSource ** source) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("A80B382D-0612-0E05-325C-E53003858908")
IOAEPParameterSpecHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IOAEPParameterSpecHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IOAEPParameterSpecHelper*)pObj->Probe(EIID_IOAEPParameterSpecHelper);
    }

    static CARAPI_(IOAEPParameterSpecHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IOAEPParameterSpecHelper*)pObj->Probe(EIID_IOAEPParameterSpecHelper);
    }

    virtual CARAPI GetDEFAULT(
        /* [out] */ Elastosx::Crypto::Spec::IOAEPParameterSpec ** spec) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("D6345D0E-B652-1438-CA73-336AFECE4BDA")
IPBEKeySpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPBEKeySpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPBEKeySpec*)pObj->Probe(EIID_IPBEKeySpec);
    }

    static CARAPI_(IPBEKeySpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPBEKeySpec*)pObj->Probe(EIID_IPBEKeySpec);
    }

    virtual CARAPI ClearPassword() = 0;

    virtual CARAPI GetPassword(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Char32> ** pwd) = 0;

    virtual CARAPI GetSalt(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** salt) = 0;

    virtual CARAPI GetIterationCount(
        /* [out] */ _ELASTOS Int32 * count) = 0;

    virtual CARAPI GetKeyLength(
        /* [out] */ _ELASTOS Int32 * length) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("C92D3F22-8652-0E05-AE72-9881C2C48FF6")
IPBEParameterSpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPBEParameterSpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPBEParameterSpec*)pObj->Probe(EIID_IPBEParameterSpec);
    }

    static CARAPI_(IPBEParameterSpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPBEParameterSpec*)pObj->Probe(EIID_IPBEParameterSpec);
    }

    virtual CARAPI GetSalt(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** salt) = 0;

    virtual CARAPI GetIterationCount(
        /* [out] */ _ELASTOS Int32 * count) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("0EF72A32-0652-3FD3-DADB-B821C3C68E1F")
IPSource : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPSource*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPSource*)pObj->Probe(EIID_IPSource);
    }

    static CARAPI_(IPSource*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPSource*)pObj->Probe(EIID_IPSource);
    }

    virtual CARAPI GetAlgorithm(
        /* [out] */ _ELASTOS String * result) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("EEA62956-0652-610E-5575-2BF6C3414919")
IPSpecified : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPSpecified*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPSpecified*)pObj->Probe(EIID_IPSpecified);
    }

    static CARAPI_(IPSpecified*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPSpecified*)pObj->Probe(EIID_IPSpecified);
    }

    virtual CARAPI GetValue(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** value) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("E9413101-C652-A8CD-C9A6-2C7A46E83BA3")
IPSpecifiedHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPSpecifiedHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPSpecifiedHelper*)pObj->Probe(EIID_IPSpecifiedHelper);
    }

    static CARAPI_(IPSpecifiedHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPSpecifiedHelper*)pObj->Probe(EIID_IPSpecifiedHelper);
    }

    virtual CARAPI GetDEFAULT(
        /* [out] */ Elastosx::Crypto::Spec::IPSpecified ** result) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("F2753F2C-06D2-0206-AE72-9881C2C48FF6")
IRC2ParameterSpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRC2ParameterSpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRC2ParameterSpec*)pObj->Probe(EIID_IRC2ParameterSpec);
    }

    static CARAPI_(IRC2ParameterSpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRC2ParameterSpec*)pObj->Probe(EIID_IRC2ParameterSpec);
    }

    virtual CARAPI GetEffectiveKeyBits(
        /* [out] */ _ELASTOS Int32 * bits) = 0;

    virtual CARAPI GetIV(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** iv) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("E7EC4A33-06D2-0506-AE72-9881C2C48FF6")
IRC5ParameterSpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRC5ParameterSpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRC5ParameterSpec*)pObj->Probe(EIID_IRC5ParameterSpec);
    }

    static CARAPI_(IRC5ParameterSpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRC5ParameterSpec*)pObj->Probe(EIID_IRC5ParameterSpec);
    }

    virtual CARAPI GetVersion(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetRounds(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetWordSize(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetIV(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** iv) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("0F39430B-8712-359A-7A53-28CFCDA8F93B")
ISecretKeySpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISecretKeySpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISecretKeySpec*)pObj->Probe(EIID_ISecretKeySpec);
    }

    static CARAPI_(ISecretKeySpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISecretKeySpec*)pObj->Probe(EIID_ISecretKeySpec);
    }

    virtual CARAPI GetAlgorithm(
        /* [out] */ _ELASTOS String * value) = 0;

    virtual CARAPI GetFormat(
        /* [out] */ _ELASTOS String * value) = 0;

    virtual CARAPI GetEncoded(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** value) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("D3E5AC38-0312-2C06-66AC-B8AFC7E88FF6")
ICCipherClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCipherClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCipherClassObject*)pObj->Probe(EIID_ICCipherClassObject);
    }

    static CARAPI_(ICCipherClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCipherClassObject*)pObj->Probe(EIID_ICCipherClassObject);
    }

    virtual CARAPI CreateObjectWithCipherSpiProviderTransformation(
        /* [in] */ Elastosx::Crypto::ICipherSpi * cipherSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& transformation,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithTransformationTransformPartsProvider(
        /* [in] */ const _ELASTOS String& transformation,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * transformParts,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("2DC26A04-C312-F3B0-8AD6-11FACE68CDBC")
ICCipherHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCipherHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCipherHelperClassObject*)pObj->Probe(EIID_ICCipherHelperClassObject);
    }

    static CARAPI_(ICCipherHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCipherHelperClassObject*)pObj->Probe(EIID_ICCipherHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("6CBC7959-0312-2C06-C83E-DBB2968D3018")
ICCipherInputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCipherInputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCipherInputStreamClassObject*)pObj->Probe(EIID_ICCipherInputStreamClassObject);
    }

    static CARAPI_(ICCipherInputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCipherInputStreamClassObject*)pObj->Probe(EIID_ICCipherInputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithIsC(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithIs(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("F1A97A29-0312-2C06-66AC-B82F55360A12")
ICCipherOutputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCipherOutputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCipherOutputStreamClassObject*)pObj->Probe(EIID_ICCipherOutputStreamClassObject);
    }

    static CARAPI_(ICCipherOutputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCipherOutputStreamClassObject*)pObj->Probe(EIID_ICCipherOutputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithOsC(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithOs(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("0C3CCB50-0312-2628-00AB-2D96416F6FCD")
ICEncryptedPrivateKeyInfoClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICEncryptedPrivateKeyInfoClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICEncryptedPrivateKeyInfoClassObject*)pObj->Probe(EIID_ICEncryptedPrivateKeyInfoClassObject);
    }

    static CARAPI_(ICEncryptedPrivateKeyInfoClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICEncryptedPrivateKeyInfoClassObject*)pObj->Probe(EIID_ICEncryptedPrivateKeyInfoClassObject);
    }

    virtual CARAPI CreateObjectWithEncoded(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encoded,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithEncryptionAlgorithmNameEncryptedData(
        /* [in] */ const _ELASTOS String& encryptionAlgorithmName,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encryptedData,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithAlgParamsEncryptedData(
        /* [in] */ Elastos::Security::IAlgorithmParameters * algParams,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encryptedData,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("F05A7F5C-8312-2828-60A4-B58022D4521B")
ICExemptionMechanismClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICExemptionMechanismClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICExemptionMechanismClassObject*)pObj->Probe(EIID_ICExemptionMechanismClassObject);
    }

    static CARAPI_(ICExemptionMechanismClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICExemptionMechanismClassObject*)pObj->Probe(EIID_ICExemptionMechanismClassObject);
    }

    virtual CARAPI CreateObjectWithExmechSpiProviderMechanism(
        /* [in] */ Elastosx::Crypto::IExemptionMechanismSpi * exmechSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& mechanism,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("BF387651-8312-2828-60A4-B58022D4521B")
ICExemptionMechanismHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICExemptionMechanismHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICExemptionMechanismHelperClassObject*)pObj->Probe(EIID_ICExemptionMechanismHelperClassObject);
    }

    static CARAPI_(ICExemptionMechanismHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICExemptionMechanismHelperClassObject*)pObj->Probe(EIID_ICExemptionMechanismHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("FE167B22-8312-0A86-54D4-4081E2BD1EA3")
ICKeyAgreementClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICKeyAgreementClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyAgreementClassObject*)pObj->Probe(EIID_ICKeyAgreementClassObject);
    }

    static CARAPI_(ICKeyAgreementClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyAgreementClassObject*)pObj->Probe(EIID_ICKeyAgreementClassObject);
    }

    virtual CARAPI CreateObjectWithKeyAgreeSpiProviderAlgorithm(
        /* [in] */ Elastosx::Crypto::IKeyAgreementSpi * keyAgreeSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("196E7041-0312-D60A-14CC-43A133028A17")
ICKeyAgreementHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICKeyAgreementHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyAgreementHelperClassObject*)pObj->Probe(EIID_ICKeyAgreementHelperClassObject);
    }

    static CARAPI_(ICKeyAgreementHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyAgreementHelperClassObject*)pObj->Probe(EIID_ICKeyAgreementHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("458B792A-8312-1086-50C4-B84FE2467E3D")
ICKeyGeneratorClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICKeyGeneratorClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyGeneratorClassObject*)pObj->Probe(EIID_ICKeyGeneratorClassObject);
    }

    static CARAPI_(ICKeyGeneratorClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyGeneratorClassObject*)pObj->Probe(EIID_ICKeyGeneratorClassObject);
    }

    virtual CARAPI CreateObjectWithKeyGenSpiProviderAlgorithm(
        /* [in] */ Elastosx::Crypto::IKeyGeneratorSpi * keyGenSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("FD7A7019-4312-3CA1-84C6-684DDE721DA1")
ICKeyGeneratorHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICKeyGeneratorHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyGeneratorHelperClassObject*)pObj->Probe(EIID_ICKeyGeneratorHelperClassObject);
    }

    static CARAPI_(ICKeyGeneratorHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyGeneratorHelperClassObject*)pObj->Probe(EIID_ICKeyGeneratorHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("1C777039-0312-240B-4CE8-31FAA3BD8D1B")
ICMacClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICMacClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMacClassObject*)pObj->Probe(EIID_ICMacClassObject);
    }

    static CARAPI_(ICMacClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMacClassObject*)pObj->Probe(EIID_ICMacClassObject);
    }

    virtual CARAPI CreateObjectWithKeyGenSpiProviderAlgorithm(
        /* [in] */ Elastosx::Crypto::IMacSpi * keyGenSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("0C2F6706-6312-6691-84BE-335A332F69DB")
ICMacHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICMacHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMacHelperClassObject*)pObj->Probe(EIID_ICMacHelperClassObject);
    }

    static CARAPI_(ICMacHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMacHelperClassObject*)pObj->Probe(EIID_ICMacHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("81C67D28-0312-280E-4CD4-4071A321343D")
ICSecretKeyFactoryClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSecretKeyFactoryClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSecretKeyFactoryClassObject*)pObj->Probe(EIID_ICSecretKeyFactoryClassObject);
    }

    static CARAPI_(ICSecretKeyFactoryClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSecretKeyFactoryClassObject*)pObj->Probe(EIID_ICSecretKeyFactoryClassObject);
    }

    virtual CARAPI CreateObjectWithKeyFacSpiProviderAlgorithm(
        /* [in] */ Elastosx::Crypto::ISecretKeyFactorySpi * keyFacSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("2DB27422-0312-280E-4CD4-4071A321B408")
ICSecretKeyFactoryHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSecretKeyFactoryHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSecretKeyFactoryHelperClassObject*)pObj->Probe(EIID_ICSecretKeyFactoryHelperClassObject);
    }

    static CARAPI_(ICSecretKeyFactoryHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSecretKeyFactoryHelperClassObject*)pObj->Probe(EIID_ICSecretKeyFactoryHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("CE557C37-0312-280E-48BC-D06F548FD11F")
ICSealedObjectClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSealedObjectClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSealedObjectClassObject*)pObj->Probe(EIID_ICSealedObjectClassObject);
    }

    static CARAPI_(ICSealedObjectClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSealedObjectClassObject*)pObj->Probe(EIID_ICSealedObjectClassObject);
    }

    virtual CARAPI CreateObjectWithObjectC(
        /* [in] */ Elastos::IO::ISerializable * object,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithObject(
        /* [in] */ Elastosx::Crypto::ISealedObject * object,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
CAR_INTERFACE("94216817-7312-EFE1-CBB0-F38AD6CC4BDA")
ICNullCipherClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICNullCipherClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNullCipherClassObject*)pObj->Probe(EIID_ICNullCipherClassObject);
    }

    static CARAPI_(ICNullCipherClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNullCipherClassObject*)pObj->Probe(EIID_ICNullCipherClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("A4137E29-8312-0E06-3834-E4300385093D")
ICDESKeySpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDESKeySpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDESKeySpecClassObject*)pObj->Probe(EIID_ICDESKeySpecClassObject);
    }

    static CARAPI_(ICDESKeySpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDESKeySpecClassObject*)pObj->Probe(EIID_ICDESKeySpecClassObject);
    }

    virtual CARAPI CreateObjectWithKey(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithKeyOffset(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("9E60730C-D312-1C38-85F2-DC8C9A11FACE")
ICDESKeySpecHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDESKeySpecHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDESKeySpecHelperClassObject*)pObj->Probe(EIID_ICDESKeySpecHelperClassObject);
    }

    static CARAPI_(ICDESKeySpecHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDESKeySpecHelperClassObject*)pObj->Probe(EIID_ICDESKeySpecHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("2D5B8107-D312-1C38-7AA2-14CA73336A32")
ICDESedeKeySpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDESedeKeySpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDESedeKeySpecClassObject*)pObj->Probe(EIID_ICDESedeKeySpecClassObject);
    }

    static CARAPI_(ICDESedeKeySpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDESedeKeySpecClassObject*)pObj->Probe(EIID_ICDESedeKeySpecClassObject);
    }

    virtual CARAPI CreateObjectWithKey(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithKeyOffset(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("7A55760F-D312-1C38-7AA2-14CA73336A46")
ICDESedeKeySpecHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDESedeKeySpecHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDESedeKeySpecHelperClassObject*)pObj->Probe(EIID_ICDESedeKeySpecHelperClassObject);
    }

    static CARAPI_(ICDESedeKeySpecHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDESedeKeySpecHelperClassObject*)pObj->Probe(EIID_ICDESedeKeySpecHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("28C87F3E-8312-1106-20A0-887195C30C14")
ICDHGenParameterSpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDHGenParameterSpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDHGenParameterSpecClassObject*)pObj->Probe(EIID_ICDHGenParameterSpecClassObject);
    }

    static CARAPI_(ICDHGenParameterSpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDHGenParameterSpecClassObject*)pObj->Probe(EIID_ICDHGenParameterSpecClassObject);
    }

    virtual CARAPI CreateObjectWithPrimeSizeExponentSize(
        /* [in] */ _ELASTOS Int32 primeSize,
        /* [in] */ _ELASTOS Int32 exponentSize,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("448B7C3F-8312-1106-AE72-9881C2841EA3")
ICDHParameterSpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDHParameterSpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDHParameterSpecClassObject*)pObj->Probe(EIID_ICDHParameterSpecClassObject);
    }

    static CARAPI_(ICDHParameterSpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDHParameterSpecClassObject*)pObj->Probe(EIID_ICDHParameterSpecClassObject);
    }

    virtual CARAPI CreateObjectWithPG(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPGL(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [in] */ _ELASTOS Int32 l,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("61E36B14-D312-5944-CDE6-E48D5228CFCD")
ICDHPrivateKeySpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDHPrivateKeySpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDHPrivateKeySpecClassObject*)pObj->Probe(EIID_ICDHPrivateKeySpecClassObject);
    }

    static CARAPI_(ICDHPrivateKeySpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDHPrivateKeySpecClassObject*)pObj->Probe(EIID_ICDHPrivateKeySpecClassObject);
    }

    virtual CARAPI CreateObjectWithXPG(
        /* [in] */ Elastos::Math::IBigInteger * x,
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("AD136A10-D312-1944-5EBE-AC49A13C37A3")
ICDHPublicKeySpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDHPublicKeySpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDHPublicKeySpecClassObject*)pObj->Probe(EIID_ICDHPublicKeySpecClassObject);
    }

    static CARAPI_(ICDHPublicKeySpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDHPublicKeySpecClassObject*)pObj->Probe(EIID_ICDHPublicKeySpecClassObject);
    }

    virtual CARAPI CreateObjectWithYPG(
        /* [in] */ Elastos::Math::IBigInteger * y,
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("36C5972B-0312-0C08-2C5C-E5300385093D")
ICGCMParameterSpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICGCMParameterSpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICGCMParameterSpecClassObject*)pObj->Probe(EIID_ICGCMParameterSpecClassObject);
    }

    static CARAPI_(ICGCMParameterSpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICGCMParameterSpecClassObject*)pObj->Probe(EIID_ICGCMParameterSpecClassObject);
    }

    virtual CARAPI CreateObjectWithTagLenIv(
        /* [in] */ _ELASTOS Int32 tagLen,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithTagLenIvOffsetByteCount(
        /* [in] */ _ELASTOS Int32 tagLen,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("ADE08A29-0312-3909-AE72-9881C2841EA3")
ICIvParameterSpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICIvParameterSpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICIvParameterSpecClassObject*)pObj->Probe(EIID_ICIvParameterSpecClassObject);
    }

    static CARAPI_(ICIvParameterSpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICIvParameterSpecClassObject*)pObj->Probe(EIID_ICIvParameterSpecClassObject);
    }

    virtual CARAPI CreateObjectWithIv(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithIvOffsetByteCount(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("7DDF9C25-0312-0A0C-1C64-B8CA61060A13")
ICOAEPParameterSpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICOAEPParameterSpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICOAEPParameterSpecClassObject*)pObj->Probe(EIID_ICOAEPParameterSpecClassObject);
    }

    static CARAPI_(ICOAEPParameterSpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICOAEPParameterSpecClassObject*)pObj->Probe(EIID_ICOAEPParameterSpecClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithMdNameMgfNameMgfSpecPSrc(
        /* [in] */ const _ELASTOS String& mdName,
        /* [in] */ const _ELASTOS String& mgfName,
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * mgfSpec,
        /* [in] */ Elastosx::Crypto::Spec::IPSource * pSrc,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("D06A7A37-0312-0A0C-1C64-B8CA61060A13")
ICOAEPParameterSpecHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICOAEPParameterSpecHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICOAEPParameterSpecHelperClassObject*)pObj->Probe(EIID_ICOAEPParameterSpecHelperClassObject);
    }

    static CARAPI_(ICOAEPParameterSpecHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICOAEPParameterSpecHelperClassObject*)pObj->Probe(EIID_ICOAEPParameterSpecHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("C62EC734-8312-0B0C-1C34-E4300385093D")
ICPBEKeySpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPBEKeySpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPBEKeySpecClassObject*)pObj->Probe(EIID_ICPBEKeySpecClassObject);
    }

    static CARAPI_(ICPBEKeySpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPBEKeySpecClassObject*)pObj->Probe(EIID_ICPBEKeySpecClassObject);
    }

    virtual CARAPI CreateObjectWithPassword(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPasswordSaltIterationCountKeyLength(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * salt,
        /* [in] */ _ELASTOS Int32 iterationCount,
        /* [in] */ _ELASTOS Int32 keyLength,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPasswordSaltIterationCount(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * salt,
        /* [in] */ _ELASTOS Int32 iterationCount,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("5B9E7A25-8312-0B0C-1C5C-E5300385093D")
ICPBEParameterSpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPBEParameterSpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPBEParameterSpecClassObject*)pObj->Probe(EIID_ICPBEParameterSpecClassObject);
    }

    static CARAPI_(ICPBEParameterSpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPBEParameterSpecClassObject*)pObj->Probe(EIID_ICPBEParameterSpecClassObject);
    }

    virtual CARAPI CreateObjectWithSaltIterationCount(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * salt,
        /* [in] */ _ELASTOS Int32 iterationCount,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("30666723-8312-A60C-F518-FDD1DEC60D19")
ICPSourceClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPSourceClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPSourceClassObject*)pObj->Probe(EIID_ICPSourceClassObject);
    }

    static CARAPI_(ICPSourceClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPSourceClassObject*)pObj->Probe(EIID_ICPSourceClassObject);
    }

    virtual CARAPI CreateObjectWithPSrcName(
        /* [in] */ const _ELASTOS String& pSrcName,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("5C1B7E18-9312-3371-6AB2-298B9ECC4BDA")
ICPSpecifiedClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPSpecifiedClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPSpecifiedClassObject*)pObj->Probe(EIID_ICPSpecifiedClassObject);
    }

    static CARAPI_(ICPSpecifiedClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPSpecifiedClassObject*)pObj->Probe(EIID_ICPSpecifiedClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithP(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * p,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("8C267317-9312-3371-6AB2-298B9E11FACE")
ICPSpecifiedHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPSpecifiedHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPSpecifiedHelperClassObject*)pObj->Probe(EIID_ICPSpecifiedHelperClassObject);
    }

    static CARAPI_(ICPSpecifiedHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPSpecifiedHelperClassObject*)pObj->Probe(EIID_ICPSpecifiedHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("36ACC229-8312-0C0D-045C-E5300385093D")
ICRC2ParameterSpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICRC2ParameterSpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRC2ParameterSpecClassObject*)pObj->Probe(EIID_ICRC2ParameterSpecClassObject);
    }

    static CARAPI_(ICRC2ParameterSpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRC2ParameterSpecClassObject*)pObj->Probe(EIID_ICRC2ParameterSpecClassObject);
    }

    virtual CARAPI CreateObjectWithEffectiveKeyBits(
        /* [in] */ _ELASTOS Int32 effectiveKeyBits,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithEffectiveKeyBitsIv(
        /* [in] */ _ELASTOS Int32 effectiveKeyBits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithEffectiveKeyBitsIvOffset(
        /* [in] */ _ELASTOS Int32 effectiveKeyBits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("1411C537-8312-0C0D-0A5C-E5300385093D")
ICRC5ParameterSpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICRC5ParameterSpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRC5ParameterSpecClassObject*)pObj->Probe(EIID_ICRC5ParameterSpecClassObject);
    }

    static CARAPI_(ICRC5ParameterSpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRC5ParameterSpecClassObject*)pObj->Probe(EIID_ICRC5ParameterSpecClassObject);
    }

    virtual CARAPI CreateObjectWithVerRoundsWordSize(
        /* [in] */ _ELASTOS Int32 ver,
        /* [in] */ _ELASTOS Int32 rounds,
        /* [in] */ _ELASTOS Int32 wordSize,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithVerRoundsWordSizeIv(
        /* [in] */ _ELASTOS Int32 ver,
        /* [in] */ _ELASTOS Int32 rounds,
        /* [in] */ _ELASTOS Int32 wordSize,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithVerRoundsWordSizeIvOffset(
        /* [in] */ _ELASTOS Int32 ver,
        /* [in] */ _ELASTOS Int32 rounds,
        /* [in] */ _ELASTOS Int32 wordSize,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
CAR_INTERFACE("AC0A9611-C312-66A1-8DDE-14CA73336A32")
ICSecretKeySpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSecretKeySpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSecretKeySpecClassObject*)pObj->Probe(EIID_ICSecretKeySpecClassObject);
    }

    static CARAPI_(ICSecretKeySpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSecretKeySpecClassObject*)pObj->Probe(EIID_ICSecretKeySpecClassObject);
    }

    virtual CARAPI CreateObjectWithKeyAlgorithm(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithKeyOffsetLenAlgorithm(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 len,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
CAR_INTERFACE("5646583A-6952-3F68-DADB-B821C3C68E1F")
ISocketFactory : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISocketFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketFactory*)pObj->Probe(EIID_ISocketFactory);
    }

    static CARAPI_(ISocketFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketFactory*)pObj->Probe(EIID_ISocketFactory);
    }

    virtual CARAPI CreateSocket(
        /* [out] */ Elastos::Net::ISocket ** sock) = 0;

    virtual CARAPI CreateSocket(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Net::ISocket ** sock) = 0;

    virtual CARAPI CreateSocket(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ Elastos::Net::IInetAddress * localHost,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ Elastos::Net::ISocket ** sock) = 0;

    virtual CARAPI CreateSocket(
        /* [in] */ Elastos::Net::IInetAddress * host,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Net::ISocket ** sock) = 0;

    virtual CARAPI CreateSocket(
        /* [in] */ Elastos::Net::IInetAddress * address,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ Elastos::Net::IInetAddress * localAddress,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ Elastos::Net::ISocket ** sock) = 0;

};
}
}
namespace Elastosx {
namespace Net {
CAR_INTERFACE("BD5C2C31-6952-1168-50BC-9871FF477B1B")
ISocketFactoryHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISocketFactoryHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketFactoryHelper*)pObj->Probe(EIID_ISocketFactoryHelper);
    }

    static CARAPI_(ISocketFactoryHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketFactoryHelper*)pObj->Probe(EIID_ISocketFactoryHelper);
    }

    virtual CARAPI GetDefault(
        /* [out] */ Elastosx::Net::ISocketFactory ** factory) = 0;

};
}
}
namespace Elastosx {
namespace Net {
CAR_INTERFACE("7A846A22-E612-D0D2-7EB4-B77143868D1D")
IServerSocketFactory : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IServerSocketFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IServerSocketFactory*)pObj->Probe(EIID_IServerSocketFactory);
    }

    static CARAPI_(IServerSocketFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IServerSocketFactory*)pObj->Probe(EIID_IServerSocketFactory);
    }

    virtual CARAPI CreateServerSocket(
        /* [out] */ Elastos::Net::IServerSocket ** sock) = 0;

    virtual CARAPI CreateServerSocket(
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Net::IServerSocket ** sock) = 0;

    virtual CARAPI CreateServerSocket(
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Int32 backlog,
        /* [out] */ Elastos::Net::IServerSocket ** sock) = 0;

    virtual CARAPI CreateServerSocket(
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Int32 backlog,
        /* [in] */ Elastos::Net::IInetAddress * iAddress,
        /* [out] */ Elastos::Net::IServerSocket ** sock) = 0;

};
}
}
namespace Elastosx {
namespace Net {
CAR_INTERFACE("920E3232-E612-D0D2-22A0-7831E3FE8FF6")
IServerSocketFactoryHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IServerSocketFactoryHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IServerSocketFactoryHelper*)pObj->Probe(EIID_IServerSocketFactoryHelper);
    }

    static CARAPI_(IServerSocketFactoryHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IServerSocketFactoryHelper*)pObj->Probe(EIID_IServerSocketFactoryHelper);
    }

    virtual CARAPI GetDefault(
        /* [out] */ Elastosx::Net::IServerSocketFactory ** factory) = 0;

};
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("D2263E2B-8312-37FB-B276-A881C3C68D95")
ICertPathTrustManagerParameters : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICertPathTrustManagerParameters*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertPathTrustManagerParameters*)pObj->Probe(EIID_ICertPathTrustManagerParameters);
    }

    static CARAPI_(ICertPathTrustManagerParameters*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertPathTrustManagerParameters*)pObj->Probe(EIID_ICertPathTrustManagerParameters);
    }

    virtual CARAPI GetParameters(
        /* [out] */ Elastos::Security::Cert::ICertPathParameters ** param) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("E8073E24-A8D2-3208-6CDC-884102068AF0")
IDefaultHostnameVerifier : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDefaultHostnameVerifier*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDefaultHostnameVerifier*)pObj->Probe(EIID_IDefaultHostnameVerifier);
    }

    static CARAPI_(IDefaultHostnameVerifier*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDefaultHostnameVerifier*)pObj->Probe(EIID_IDefaultHostnameVerifier);
    }

    virtual CARAPI Verify(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ Elastos::Security::Cert::IX509Certificate * certificate,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI VerifyHostName(
        /* [in] */ const _ELASTOS String& hostName,
        /* [in] */ const _ELASTOS String& cn,
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("0B905158-9212-48CF-6D17-3ED165678644")
IDistinguishedNameParser : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDistinguishedNameParser*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDistinguishedNameParser*)pObj->Probe(EIID_IDistinguishedNameParser);
    }

    static CARAPI_(IDistinguishedNameParser*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDistinguishedNameParser*)pObj->Probe(EIID_IDistinguishedNameParser);
    }

    virtual CARAPI FindMostSpecific(
        /* [in] */ const _ELASTOS String& attributeType,
        /* [out] */ _ELASTOS String * specific) = 0;

    virtual CARAPI GetAllMostSpecificFirst(
        /* [in] */ const _ELASTOS String& attributeType,
        /* [out] */ Elastos::Utility::IList ** frist) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("295DAA50-0452-2741-08BB-4051048659CD")
IHandshakeCompletedEvent : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IHandshakeCompletedEvent*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHandshakeCompletedEvent*)pObj->Probe(EIID_IHandshakeCompletedEvent);
    }

    static CARAPI_(IHandshakeCompletedEvent*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHandshakeCompletedEvent*)pObj->Probe(EIID_IHandshakeCompletedEvent);
    }

    virtual CARAPI GetSession(
        /* [out] */ Elastosx::Net::Ssl::ISSLSession ** session) = 0;

    virtual CARAPI GetCipherSuite(
        /* [out] */ _ELASTOS String * suite) = 0;

    virtual CARAPI GetLocalCertificates(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> ** cert) = 0;

    virtual CARAPI GetPeerCertificates(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> ** cert) = 0;

    virtual CARAPI GetPeerCertificateChain(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastosx::Security::Cert::IX509Certificate *> ** chain) = 0;

    virtual CARAPI GetPeerPrincipal(
        /* [out] */ Elastos::Security::IPrincipal ** principal) = 0;

    virtual CARAPI GetLocalPrincipal(
        /* [out] */ Elastos::Security::IPrincipal ** principal) = 0;

    virtual CARAPI GetSocket(
        /* [out] */ Elastosx::Net::Ssl::ISSLSocket ** socket) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("61493F4A-0452-2741-08BB-4051048659CD")
IHandshakeCompletedListener : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IHandshakeCompletedListener*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHandshakeCompletedListener*)pObj->Probe(EIID_IHandshakeCompletedListener);
    }

    static CARAPI_(IHandshakeCompletedListener*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHandshakeCompletedListener*)pObj->Probe(EIID_IHandshakeCompletedListener);
    }

    virtual CARAPI HandshakeCompleted(
        /* [in] */ Elastosx::Net::Ssl::IHandshakeCompletedEvent * event) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("B29E2947-0452-45AC-777E-78C6A2DBB31F")
IHostnameVerifier : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IHostnameVerifier*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHostnameVerifier*)pObj->Probe(EIID_IHostnameVerifier);
    }

    static CARAPI_(IHostnameVerifier*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHostnameVerifier*)pObj->Probe(EIID_IHostnameVerifier);
    }

    virtual CARAPI Verify(
        /* [in] */ const _ELASTOS String& hostname,
        /* [in] */ Elastosx::Net::Ssl::ISSLSession * session,
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("DE4BC92C-8452-371B-66D8-60CEE8477B1B")
IHttpsURLConnection : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IHttpsURLConnection*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHttpsURLConnection*)pObj->Probe(EIID_IHttpsURLConnection);
    }

    static CARAPI_(IHttpsURLConnection*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHttpsURLConnection*)pObj->Probe(EIID_IHttpsURLConnection);
    }

    virtual CARAPI GetCipherSuite(
        /* [out] */ _ELASTOS String * suite) = 0;

    virtual CARAPI GetLocalCertificates(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> ** certificates) = 0;

    virtual CARAPI GetServerCertificates(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> ** certificates) = 0;

    virtual CARAPI GetPeerPrincipal(
        /* [out] */ Elastos::Security::IPrincipal ** principal) = 0;

    virtual CARAPI GetLocalPrincipal(
        /* [out] */ Elastos::Security::IPrincipal ** principal) = 0;

    virtual CARAPI SetHostnameVerifier(
        /* [in] */ Elastosx::Net::Ssl::IHostnameVerifier * v) = 0;

    virtual CARAPI GetHostnameVerifier(
        /* [out] */ Elastosx::Net::Ssl::IHostnameVerifier ** verifier) = 0;

    virtual CARAPI SetSSLSocketFactory(
        /* [in] */ Elastosx::Net::Ssl::ISSLSocketFactory * sf) = 0;

    virtual CARAPI GetSSLSocketFactory(
        /* [out] */ Elastosx::Net::Ssl::ISSLSocketFactory ** factory) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("DBBD9336-8452-371B-66D8-60CE28028A17")
IHttpsURLConnectionHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IHttpsURLConnectionHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHttpsURLConnectionHelper*)pObj->Probe(EIID_IHttpsURLConnectionHelper);
    }

    static CARAPI_(IHttpsURLConnectionHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHttpsURLConnectionHelper*)pObj->Probe(EIID_IHttpsURLConnectionHelper);
    }

    virtual CARAPI SetDefaultHostnameVerifier(
        /* [in] */ Elastosx::Net::Ssl::IHostnameVerifier * v) = 0;

    virtual CARAPI GetDefaultHostnameVerifier(
        /* [out] */ Elastosx::Net::Ssl::IHostnameVerifier ** verifier) = 0;

    virtual CARAPI SetDefaultSSLSocketFactory(
        /* [in] */ Elastosx::Net::Ssl::ISSLSocketFactory * sf) = 0;

    virtual CARAPI GetDefaultSSLSocketFactory(
        /* [out] */ Elastosx::Net::Ssl::ISSLSocketFactory ** factory) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("6AF71D3C-C352-3F95-DADB-B821C3C68E1F")
IKeyManager : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyManager*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyManager*)pObj->Probe(EIID_IKeyManager);
    }

    static CARAPI_(IKeyManager*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyManager*)pObj->Probe(EIID_IKeyManager);
    }

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("A6FD5133-C352-D095-7EB4-B77143868D1D")
IKeyManagerFactory : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyManagerFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyManagerFactory*)pObj->Probe(EIID_IKeyManagerFactory);
    }

    static CARAPI_(IKeyManagerFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyManagerFactory*)pObj->Probe(EIID_IKeyManagerFactory);
    }

    virtual CARAPI GetAlgorithm(
        /* [out] */ _ELASTOS String * algorithm) = 0;

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI Init(
        /* [in] */ Elastos::Security::IKeyStore * ks,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password) = 0;

    virtual CARAPI Init(
        /* [in] */ Elastosx::Net::Ssl::IManagerFactoryParameters * spec) = 0;

    virtual CARAPI GetKeyManagers(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastosx::Net::Ssl::IKeyManager *> ** managers) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("D1B35E3D-C352-D095-22A0-7831E3FE8FF6")
IKeyManagerFactoryHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyManagerFactoryHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyManagerFactoryHelper*)pObj->Probe(EIID_IKeyManagerFactoryHelper);
    }

    static CARAPI_(IKeyManagerFactoryHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyManagerFactoryHelper*)pObj->Probe(EIID_IKeyManagerFactoryHelper);
    }

    virtual CARAPI GetDefaultAlgorithm(
        /* [out] */ _ELASTOS String * algorithm) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastosx::Net::Ssl::IKeyManagerFactory ** factory) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& provider,
        /* [out] */ Elastosx::Net::Ssl::IKeyManagerFactory ** factory) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastosx::Net::Ssl::IKeyManagerFactory ** factory) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("B5F34F2A-C352-D095-38CC-60F1A3BD8D1B")
IKeyManagerFactorySpi : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyManagerFactorySpi*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyManagerFactorySpi*)pObj->Probe(EIID_IKeyManagerFactorySpi);
    }

    static CARAPI_(IKeyManagerFactorySpi*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyManagerFactorySpi*)pObj->Probe(EIID_IKeyManagerFactorySpi);
    }

    virtual CARAPI EngineInit(
        /* [in] */ Elastos::Security::IKeyStore * ks,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password) = 0;

    virtual CARAPI EngineInit(
        /* [in] */ Elastosx::Net::Ssl::IManagerFactoryParameters * spec) = 0;

    virtual CARAPI EngineGetKeyManagers(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastosx::Net::Ssl::IKeyManager *> ** managers) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("EE07393D-C352-6CD7-EE5F-B5F1A3BD8D1B")
IKeyStoreBuilderParameters : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyStoreBuilderParameters*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStoreBuilderParameters*)pObj->Probe(EIID_IKeyStoreBuilderParameters);
    }

    static CARAPI_(IKeyStoreBuilderParameters*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStoreBuilderParameters*)pObj->Probe(EIID_IKeyStoreBuilderParameters);
    }

    virtual CARAPI GetParameters(
        /* [out] */ Elastos::Utility::IList ** param) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("63362B37-4AD2-5768-6DFC-686FE3860C1B")
IManagerFactoryParameters : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IManagerFactoryParameters*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IManagerFactoryParameters*)pObj->Probe(EIID_IManagerFactoryParameters);
    }

    static CARAPI_(IManagerFactoryParameters*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IManagerFactoryParameters*)pObj->Probe(EIID_IManagerFactoryParameters);
    }

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("A41FD95B-0712-150E-8868-DE71E3878392")
ISSLContext : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISSLContext*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLContext*)pObj->Probe(EIID_ISSLContext);
    }

    static CARAPI_(ISSLContext*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLContext*)pObj->Probe(EIID_ISSLContext);
    }

    virtual CARAPI GetProtocol(
        /* [out] */ _ELASTOS String * protocol) = 0;

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI Init(
        /* [in] */ _ELASTOS ArrayOf<Elastosx::Net::Ssl::IKeyManager *> * km,
        /* [in] */ _ELASTOS ArrayOf<Elastosx::Net::Ssl::ITrustManager *> * tm,
        /* [in] */ Elastos::Security::ISecureRandom * sr) = 0;

    virtual CARAPI GetSocketFactory(
        /* [out] */ Elastosx::Net::Ssl::ISSLSocketFactory ** factory) = 0;

    virtual CARAPI GetServerSocketFactory(
        /* [out] */ Elastosx::Net::Ssl::ISSLServerSocketFactory ** factory) = 0;

    virtual CARAPI CreateSSLEngine(
        /* [out] */ Elastosx::Net::Ssl::ISSLEngine ** engine) = 0;

    virtual CARAPI CreateSSLEngine(
        /* [in] */ const _ELASTOS String& peerHost,
        /* [in] */ _ELASTOS Int32 peerPort,
        /* [out] */ Elastosx::Net::Ssl::ISSLEngine ** engine) = 0;

    virtual CARAPI GetServerSessionContext(
        /* [out] */ Elastosx::Net::Ssl::ISSLSessionContext ** context) = 0;

    virtual CARAPI GetClientSessionContext(
        /* [out] */ Elastosx::Net::Ssl::ISSLSessionContext ** context) = 0;

    virtual CARAPI GetDefaultSSLParameters(
        /* [out] */ Elastosx::Net::Ssl::ISSLParameters ** param) = 0;

    virtual CARAPI GetSupportedSSLParameters(
        /* [out] */ Elastosx::Net::Ssl::ISSLParameters ** param) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("BB675815-C712-8C55-1CDF-E87E47E83BA3")
ISSLContextHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISSLContextHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLContextHelper*)pObj->Probe(EIID_ISSLContextHelper);
    }

    static CARAPI_(ISSLContextHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLContextHelper*)pObj->Probe(EIID_ISSLContextHelper);
    }

    virtual CARAPI GetDefault(
        /* [out] */ Elastosx::Net::Ssl::ISSLContext ** context) = 0;

    virtual CARAPI SetDefault(
        /* [in] */ Elastosx::Net::Ssl::ISSLContext * sslContext) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& protocol,
        /* [out] */ Elastosx::Net::Ssl::ISSLContext ** instance) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& provider,
        /* [out] */ Elastosx::Net::Ssl::ISSLContext ** instance) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastosx::Net::Ssl::ISSLContext ** context) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("DB85FC0D-C712-8C55-1CDF-E87E7333FB3B")
ISSLContextSpi : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISSLContextSpi*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLContextSpi*)pObj->Probe(EIID_ISSLContextSpi);
    }

    static CARAPI_(ISSLContextSpi*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLContextSpi*)pObj->Probe(EIID_ISSLContextSpi);
    }

    virtual CARAPI EngineInit(
        /* [in] */ _ELASTOS ArrayOf<Elastosx::Net::Ssl::IKeyManager *> * km,
        /* [in] */ _ELASTOS ArrayOf<Elastosx::Net::Ssl::ITrustManager *> * tm,
        /* [in] */ Elastos::Security::ISecureRandom * sr) = 0;

    virtual CARAPI EngineGetSocketFactory(
        /* [out] */ Elastosx::Net::Ssl::ISSLSocketFactory ** factory) = 0;

    virtual CARAPI EngineGetServerSocketFactory(
        /* [out] */ Elastosx::Net::Ssl::ISSLServerSocketFactory ** factory) = 0;

    virtual CARAPI EngineCreateSSLEngine(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastosx::Net::Ssl::ISSLEngine ** engine) = 0;

    virtual CARAPI EngineCreateSSLEngine(
        /* [out] */ Elastosx::Net::Ssl::ISSLEngine ** engine) = 0;

    virtual CARAPI EngineGetServerSessionContext(
        /* [out] */ Elastosx::Net::Ssl::ISSLSessionContext ** context) = 0;

    virtual CARAPI EngineGetClientSessionContext(
        /* [out] */ Elastosx::Net::Ssl::ISSLSessionContext ** context) = 0;

    virtual CARAPI EngineGetDefaultSSLParameters(
        /* [out] */ Elastosx::Net::Ssl::ISSLParameters ** param) = 0;

    virtual CARAPI EngineGetSupportedSSLParameters(
        /* [out] */ Elastosx::Net::Ssl::ISSLParameters ** param) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("68D1EF4E-0712-150E-A0C0-3BFAC3414919")
ISSLEngine : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISSLEngine*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLEngine*)pObj->Probe(EIID_ISSLEngine);
    }

    static CARAPI_(ISSLEngine*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLEngine*)pObj->Probe(EIID_ISSLEngine);
    }

    virtual CARAPI GetPeerHost(
        /* [out] */ _ELASTOS String * host) = 0;

    virtual CARAPI GetPeerPort(
        /* [out] */ _ELASTOS Int32 * port) = 0;

    virtual CARAPI BeginHandshake() = 0;

    virtual CARAPI CloseInbound() = 0;

    virtual CARAPI CloseOutbound() = 0;

    virtual CARAPI GetDelegatedTask(
        /* [out] */ Elastos::Core::IRunnable ** task) = 0;

    virtual CARAPI GetEnabledCipherSuites(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** suites) = 0;

    virtual CARAPI GetEnabledProtocols(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** protocols) = 0;

    virtual CARAPI GetEnableSessionCreation(
        /* [out] */ _ELASTOS Boolean * enabled) = 0;

    virtual CARAPI GetHandshakeStatus(
        /* [out] */ Elastosx::Net::Ssl::SSLEngineResult_HandshakeStatus * status) = 0;

    virtual CARAPI GetNeedClientAuth(
        /* [out] */ _ELASTOS Boolean * auth) = 0;

    virtual CARAPI GetSession(
        /* [out] */ Elastosx::Net::Ssl::ISSLSession ** session) = 0;

    virtual CARAPI GetSupportedCipherSuites(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** suites) = 0;

    virtual CARAPI GetSupportedProtocols(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** protocols) = 0;

    virtual CARAPI GetUseClientMode(
        /* [out] */ _ELASTOS Boolean * mode) = 0;

    virtual CARAPI GetWantClientAuth(
        /* [out] */ _ELASTOS Boolean * auth) = 0;

    virtual CARAPI IsInboundDone(
        /* [out] */ _ELASTOS Boolean * done) = 0;

    virtual CARAPI IsOutboundDone(
        /* [out] */ _ELASTOS Boolean * done) = 0;

    virtual CARAPI SetEnabledCipherSuites(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * suites) = 0;

    virtual CARAPI SetEnabledProtocols(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * protocols) = 0;

    virtual CARAPI SetEnableSessionCreation(
        /* [in] */ _ELASTOS Boolean flag) = 0;

    virtual CARAPI SetNeedClientAuth(
        /* [in] */ _ELASTOS Boolean need) = 0;

    virtual CARAPI SetUseClientMode(
        /* [in] */ _ELASTOS Boolean mode) = 0;

    virtual CARAPI SetWantClientAuth(
        /* [in] */ _ELASTOS Boolean want) = 0;

    virtual CARAPI Unwrap(
        /* [in] */ Elastos::IO::IByteBuffer * src,
        /* [in] */ _ELASTOS ArrayOf<Elastos::IO::IByteBuffer *> * dsts,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastosx::Net::Ssl::ISSLEngineResult ** result) = 0;

    virtual CARAPI Wrap(
        /* [in] */ _ELASTOS ArrayOf<Elastos::IO::IByteBuffer *> * srcs,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::IO::IByteBuffer * dst,
        /* [out] */ Elastosx::Net::Ssl::ISSLEngineResult ** result) = 0;

    virtual CARAPI Unwrap(
        /* [in] */ Elastos::IO::IByteBuffer * src,
        /* [in] */ Elastos::IO::IByteBuffer * dst,
        /* [out] */ Elastosx::Net::Ssl::ISSLEngineResult ** result) = 0;

    virtual CARAPI Unwrap(
        /* [in] */ Elastos::IO::IByteBuffer * src,
        /* [in] */ _ELASTOS ArrayOf<Elastos::IO::IByteBuffer *> * dsts,
        /* [out] */ Elastosx::Net::Ssl::ISSLEngineResult ** result) = 0;

    virtual CARAPI Wrap(
        /* [in] */ _ELASTOS ArrayOf<Elastos::IO::IByteBuffer *> * srcs,
        /* [in] */ Elastos::IO::IByteBuffer * dst,
        /* [out] */ Elastosx::Net::Ssl::ISSLEngineResult ** result) = 0;

    virtual CARAPI Wrap(
        /* [in] */ Elastos::IO::IByteBuffer * src,
        /* [in] */ Elastos::IO::IByteBuffer * dst,
        /* [out] */ Elastosx::Net::Ssl::ISSLEngineResult ** result) = 0;

    virtual CARAPI GetSSLParameters(
        /* [out] */ Elastosx::Net::Ssl::ISSLParameters ** parameters) = 0;

    virtual CARAPI SetSSLParameters(
        /* [in] */ Elastosx::Net::Ssl::ISSLParameters * p) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("89505F57-0712-150E-A0C0-3B9A2672CD1F")
ISSLEngineResult : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISSLEngineResult*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLEngineResult*)pObj->Probe(EIID_ISSLEngineResult);
    }

    static CARAPI_(ISSLEngineResult*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLEngineResult*)pObj->Probe(EIID_ISSLEngineResult);
    }

    virtual CARAPI GetStatus(
        /* [out] */ Elastosx::Net::Ssl::SSLEngineResult_Status * status) = 0;

    virtual CARAPI GetHandshakeStatus(
        /* [out] */ Elastosx::Net::Ssl::SSLEngineResult_HandshakeStatus * status) = 0;

    virtual CARAPI BytesConsumed(
        /* [out] */ _ELASTOS Int32 * bytesConsumed) = 0;

    virtual CARAPI BytesProduced(
        /* [out] */ _ELASTOS Int32 * bytesProduced) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("159F9A24-0712-150E-AEDA-F8D1DEC60D19")
ISSLParameters : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISSLParameters*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLParameters*)pObj->Probe(EIID_ISSLParameters);
    }

    static CARAPI_(ISSLParameters*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLParameters*)pObj->Probe(EIID_ISSLParameters);
    }

    virtual CARAPI GetCipherSuites(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** suites) = 0;

    virtual CARAPI SetCipherSuites(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * cipherSuites) = 0;

    virtual CARAPI GetProtocols(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** protocols) = 0;

    virtual CARAPI SetProtocols(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * protocols) = 0;

    virtual CARAPI GetNeedClientAuth(
        /* [out] */ _ELASTOS Boolean * auth) = 0;

    virtual CARAPI SetNeedClientAuth(
        /* [in] */ _ELASTOS Boolean needClientAuth) = 0;

    virtual CARAPI GetWantClientAuth(
        /* [out] */ _ELASTOS Boolean * auth) = 0;

    virtual CARAPI SetWantClientAuth(
        /* [in] */ _ELASTOS Boolean wantClientAuth) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("363CF538-0712-150E-3097-FED1DEC60D19")
ISSLServerSocket : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISSLServerSocket*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLServerSocket*)pObj->Probe(EIID_ISSLServerSocket);
    }

    static CARAPI_(ISSLServerSocket*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLServerSocket*)pObj->Probe(EIID_ISSLServerSocket);
    }

    virtual CARAPI GetEnabledCipherSuites(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** suites) = 0;

    virtual CARAPI SetEnabledCipherSuites(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * suites) = 0;

    virtual CARAPI GetSupportedCipherSuites(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** suites) = 0;

    virtual CARAPI GetSupportedProtocols(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** protocols) = 0;

    virtual CARAPI GetEnabledProtocols(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** protocols) = 0;

    virtual CARAPI SetEnabledProtocols(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * protocols) = 0;

    virtual CARAPI SetNeedClientAuth(
        /* [in] */ _ELASTOS Boolean need) = 0;

    virtual CARAPI GetNeedClientAuth(
        /* [out] */ _ELASTOS Boolean * need) = 0;

    virtual CARAPI SetWantClientAuth(
        /* [in] */ _ELASTOS Boolean want) = 0;

    virtual CARAPI GetWantClientAuth(
        /* [out] */ _ELASTOS Boolean * want) = 0;

    virtual CARAPI SetUseClientMode(
        /* [in] */ _ELASTOS Boolean mode) = 0;

    virtual CARAPI GetUseClientMode(
        /* [out] */ _ELASTOS Boolean * mode) = 0;

    virtual CARAPI SetEnableSessionCreation(
        /* [in] */ _ELASTOS Boolean flag) = 0;

    virtual CARAPI GetEnableSessionCreation(
        /* [out] */ _ELASTOS Boolean * enabled) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("AF5A573E-0712-150E-3097-86F6A3BD8D1B")
ISSLServerSocketFactory : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISSLServerSocketFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLServerSocketFactory*)pObj->Probe(EIID_ISSLServerSocketFactory);
    }

    static CARAPI_(ISSLServerSocketFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLServerSocketFactory*)pObj->Probe(EIID_ISSLServerSocketFactory);
    }

    virtual CARAPI GetDefaultCipherSuites(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** suites) = 0;

    virtual CARAPI GetSupportedCipherSuites(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** suites) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("84C7393F-0712-150E-3097-861601C58B19")
ISSLServerSocketFactoryHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISSLServerSocketFactoryHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLServerSocketFactoryHelper*)pObj->Probe(EIID_ISSLServerSocketFactoryHelper);
    }

    static CARAPI_(ISSLServerSocketFactoryHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLServerSocketFactoryHelper*)pObj->Probe(EIID_ISSLServerSocketFactoryHelper);
    }

    virtual CARAPI GetDefault(
        /* [out] */ Elastosx::Net::IServerSocketFactory ** factory) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("919FFD56-0712-150E-3844-9BF8C3414919")
ISSLSession : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISSLSession*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLSession*)pObj->Probe(EIID_ISSLSession);
    }

    static CARAPI_(ISSLSession*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLSession*)pObj->Probe(EIID_ISSLSession);
    }

    virtual CARAPI GetApplicationBufferSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetCipherSuite(
        /* [out] */ _ELASTOS String * suite) = 0;

    virtual CARAPI GetCreationTime(
        /* [out] */ _ELASTOS Int64 * time) = 0;

    virtual CARAPI GetId(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** id) = 0;

    virtual CARAPI GetLastAccessedTime(
        /* [out] */ _ELASTOS Int64 * time) = 0;

    virtual CARAPI GetLocalCertificates(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> ** certs) = 0;

    virtual CARAPI GetLocalPrincipal(
        /* [out] */ Elastos::Security::IPrincipal ** principal) = 0;

    virtual CARAPI GetPacketBufferSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetPeerCertificateChain(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastosx::Security::Cert::IX509Certificate *> ** chain) = 0;

    virtual CARAPI GetPeerCertificates(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> ** certs) = 0;

    virtual CARAPI GetPeerHost(
        /* [out] */ _ELASTOS String * host) = 0;

    virtual CARAPI GetPeerPort(
        /* [out] */ _ELASTOS Int32 * port) = 0;

    virtual CARAPI GetPeerPrincipal(
        /* [out] */ Elastos::Security::IPrincipal ** principal) = 0;

    virtual CARAPI GetProtocol(
        /* [out] */ _ELASTOS String * protocol) = 0;

    virtual CARAPI GetSessionContext(
        /* [out] */ Elastosx::Net::Ssl::ISSLSessionContext ** context) = 0;

    virtual CARAPI GetValue(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI GetValueNames(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** names) = 0;

    virtual CARAPI Invalidate() = 0;

    virtual CARAPI IsValid(
        /* [out] */ _ELASTOS Boolean * isValid) = 0;

    virtual CARAPI PutValue(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI RemoveValue(
        /* [in] */ const _ELASTOS String& name) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("B2503A2F-0712-150E-38E0-8F6FA63EB31F")
ISSLSessionBindingEvent : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISSLSessionBindingEvent*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLSessionBindingEvent*)pObj->Probe(EIID_ISSLSessionBindingEvent);
    }

    static CARAPI_(ISSLSessionBindingEvent*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLSessionBindingEvent*)pObj->Probe(EIID_ISSLSessionBindingEvent);
    }

    virtual CARAPI GetName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetSession(
        /* [out] */ Elastosx::Net::Ssl::ISSLSession ** session) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("890A423C-0712-150E-38E0-8F6FA67EC6FB")
ISSLSessionBindingListener : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISSLSessionBindingListener*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLSessionBindingListener*)pObj->Probe(EIID_ISSLSessionBindingListener);
    }

    static CARAPI_(ISSLSessionBindingListener*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLSessionBindingListener*)pObj->Probe(EIID_ISSLSessionBindingListener);
    }

    virtual CARAPI ValueBound(
        /* [in] */ Elastosx::Net::Ssl::ISSLSessionBindingEvent * event) = 0;

    virtual CARAPI ValueUnbound(
        /* [in] */ Elastosx::Net::Ssl::ISSLSessionBindingEvent * event) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("DC707C5E-0712-150E-3844-9B4844F38E1B")
ISSLSessionContext : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISSLSessionContext*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLSessionContext*)pObj->Probe(EIID_ISSLSessionContext);
    }

    static CARAPI_(ISSLSessionContext*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLSessionContext*)pObj->Probe(EIID_ISSLSessionContext);
    }

    virtual CARAPI GetIds(
        /* [out] */ Elastos::Utility::IEnumeration ** ids) = 0;

    virtual CARAPI GetSession(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * sessionId,
        /* [out] */ Elastosx::Net::Ssl::ISSLSession ** session) = 0;

    virtual CARAPI GetSessionCacheSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetSessionTimeout(
        /* [out] */ _ELASTOS Int32 * timeout) = 0;

    virtual CARAPI SetSessionCacheSize(
        /* [in] */ _ELASTOS Int32 size) = 0;

    virtual CARAPI SetSessionTimeout(
        /* [in] */ _ELASTOS Int32 seconds) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("F6D4F03A-0712-150E-4AFF-686FE3860C1B")
ISSLSocket : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISSLSocket*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLSocket*)pObj->Probe(EIID_ISSLSocket);
    }

    static CARAPI_(ISSLSocket*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLSocket*)pObj->Probe(EIID_ISSLSocket);
    }

    virtual CARAPI GetSupportedCipherSuites(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** suites) = 0;

    virtual CARAPI GetEnabledCipherSuites(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** suites) = 0;

    virtual CARAPI SetEnabledCipherSuites(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * suites) = 0;

    virtual CARAPI GetSupportedProtocols(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** protocols) = 0;

    virtual CARAPI GetEnabledProtocols(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** protocols) = 0;

    virtual CARAPI SetEnabledProtocols(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * protocols) = 0;

    virtual CARAPI GetSession(
        /* [out] */ Elastosx::Net::Ssl::ISSLSession ** session) = 0;

    virtual CARAPI AddHandshakeCompletedListener(
        /* [in] */ Elastosx::Net::Ssl::IHandshakeCompletedListener * listener) = 0;

    virtual CARAPI RemoveHandshakeCompletedListener(
        /* [in] */ Elastosx::Net::Ssl::IHandshakeCompletedListener * listener) = 0;

    virtual CARAPI StartHandshake() = 0;

    virtual CARAPI SetUseClientMode(
        /* [in] */ _ELASTOS Boolean mode) = 0;

    virtual CARAPI GetUseClientMode(
        /* [out] */ _ELASTOS Boolean * mode) = 0;

    virtual CARAPI SetNeedClientAuth(
        /* [in] */ _ELASTOS Boolean need) = 0;

    virtual CARAPI SetWantClientAuth(
        /* [in] */ _ELASTOS Boolean want) = 0;

    virtual CARAPI GetNeedClientAuth(
        /* [out] */ _ELASTOS Boolean * auth) = 0;

    virtual CARAPI GetWantClientAuth(
        /* [out] */ _ELASTOS Boolean * auth) = 0;

    virtual CARAPI SetEnableSessionCreation(
        /* [in] */ _ELASTOS Boolean flag) = 0;

    virtual CARAPI GetEnableSessionCreation(
        /* [out] */ _ELASTOS Boolean * enabled) = 0;

    virtual CARAPI GetSSLParameters(
        /* [out] */ Elastosx::Net::Ssl::ISSLParameters ** param) = 0;

    virtual CARAPI SetSSLParameters(
        /* [in] */ Elastosx::Net::Ssl::ISSLParameters * p) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("C2FE5D3C-0712-150E-4A43-FBD1DEC60D19")
ISSLSocketFactory : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISSLSocketFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLSocketFactory*)pObj->Probe(EIID_ISSLSocketFactory);
    }

    static CARAPI_(ISSLSocketFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLSocketFactory*)pObj->Probe(EIID_ISSLSocketFactory);
    }

    virtual CARAPI GetDefaultCipherSuites(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** suites) = 0;

    virtual CARAPI GetSupportedCipherSuites(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** suites) = 0;

    virtual CARAPI CreateSocket(
        /* [in] */ Elastos::Net::ISocket * s,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean autoClose,
        /* [out] */ Elastos::Net::ISocket ** sock) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("D2F23329-0712-150E-4A43-8B80E2C58CFB")
ISSLSocketFactoryHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISSLSocketFactoryHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLSocketFactoryHelper*)pObj->Probe(EIID_ISSLSocketFactoryHelper);
    }

    static CARAPI_(ISSLSocketFactoryHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISSLSocketFactoryHelper*)pObj->Probe(EIID_ISSLSocketFactoryHelper);
    }

    virtual CARAPI GetDefault(
        /* [out] */ Elastosx::Net::ISocketFactory ** factory) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("AD03553A-8752-381A-6CDC-5809ED477B1B")
ITrustManagerFactory : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITrustManagerFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITrustManagerFactory*)pObj->Probe(EIID_ITrustManagerFactory);
    }

    static CARAPI_(ITrustManagerFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITrustManagerFactory*)pObj->Probe(EIID_ITrustManagerFactory);
    }

    virtual CARAPI GetAlgorithm(
        /* [out] */ _ELASTOS String * algorithm) = 0;

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI Init(
        /* [in] */ Elastos::Security::IKeyStore * ks) = 0;

    virtual CARAPI Init(
        /* [in] */ Elastosx::Net::Ssl::IManagerFactoryParameters * spec) = 0;

    virtual CARAPI GetTrustManagers(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastosx::Net::Ssl::ITrustManager *> ** managers) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("58336038-8752-381A-6CDC-58092D028A17")
ITrustManagerFactoryHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITrustManagerFactoryHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITrustManagerFactoryHelper*)pObj->Probe(EIID_ITrustManagerFactoryHelper);
    }

    static CARAPI_(ITrustManagerFactoryHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITrustManagerFactoryHelper*)pObj->Probe(EIID_ITrustManagerFactoryHelper);
    }

    virtual CARAPI GetDefaultAlgorithm(
        /* [out] */ _ELASTOS String * algorithm) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastosx::Net::Ssl::ITrustManagerFactory ** factory) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& provider,
        /* [out] */ Elastosx::Net::Ssl::ITrustManagerFactory ** factory) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastosx::Net::Ssl::ITrustManagerFactory ** factory) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("BBF95335-8752-381A-6CDC-58098DC30C16")
ITrustManagerFactorySpi : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITrustManagerFactorySpi*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITrustManagerFactorySpi*)pObj->Probe(EIID_ITrustManagerFactorySpi);
    }

    static CARAPI_(ITrustManagerFactorySpi*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITrustManagerFactorySpi*)pObj->Probe(EIID_ITrustManagerFactorySpi);
    }

    virtual CARAPI EngineInit(
        /* [in] */ Elastos::Security::IKeyStore * ks) = 0;

    virtual CARAPI EngineInit(
        /* [in] */ Elastosx::Net::Ssl::IManagerFactoryParameters * spec) = 0;

    virtual CARAPI EngineGetTrustManagers(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastosx::Net::Ssl::ITrustManager *> ** managers) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("F1761F33-8752-381A-6CDC-58F9A3BD8D1B")
ITrustManager : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITrustManager*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITrustManager*)pObj->Probe(EIID_ITrustManager);
    }

    static CARAPI_(ITrustManager*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITrustManager*)pObj->Probe(EIID_ITrustManager);
    }

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("000D570F-5852-8900-B3DF-687CA22785F2")
IX509ExtendedKeyManager : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IX509ExtendedKeyManager*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX509ExtendedKeyManager*)pObj->Probe(EIID_IX509ExtendedKeyManager);
    }

    static CARAPI_(IX509ExtendedKeyManager*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX509ExtendedKeyManager*)pObj->Probe(EIID_IX509ExtendedKeyManager);
    }

    virtual CARAPI ChooseEngineClientAlias(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * keyType,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::IPrincipal *> * issuers,
        /* [in] */ Elastosx::Net::Ssl::ISSLEngine * engine,
        /* [out] */ _ELASTOS String * alias) = 0;

    virtual CARAPI ChooseEngineServerAlias(
        /* [in] */ const _ELASTOS String& keyType,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::IPrincipal *> * issuers,
        /* [in] */ Elastosx::Net::Ssl::ISSLEngine * engine,
        /* [out] */ _ELASTOS String * alias) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("793B8322-8852-0002-1234-5CF9A3BD8D1B")
IX509KeyManager : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IX509KeyManager*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX509KeyManager*)pObj->Probe(EIID_IX509KeyManager);
    }

    static CARAPI_(IX509KeyManager*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX509KeyManager*)pObj->Probe(EIID_IX509KeyManager);
    }

    virtual CARAPI ChooseClientAlias(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * keyType,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::IPrincipal *> * issuers,
        /* [in] */ Elastos::Net::ISocket * socket,
        /* [out] */ _ELASTOS String * alias) = 0;

    virtual CARAPI ChooseServerAlias(
        /* [in] */ const _ELASTOS String& keyType,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::IPrincipal *> * issuers,
        /* [in] */ Elastos::Net::ISocket * socket,
        /* [out] */ _ELASTOS String * alias) = 0;

    virtual CARAPI GetCertificateChain(
        /* [in] */ const _ELASTOS String& alias,
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::Cert::IX509Certificate *> ** chain) = 0;

    virtual CARAPI GetClientAliases(
        /* [in] */ const _ELASTOS String& keyType,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::IPrincipal *> * issuers,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** alias) = 0;

    virtual CARAPI GetServerAliases(
        /* [in] */ const _ELASTOS String& keyType,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::IPrincipal *> * issuers,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** alias) = 0;

    virtual CARAPI GetPrivateKey(
        /* [in] */ const _ELASTOS String& alias,
        /* [out] */ Elastos::Security::IPrivateKey ** key) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("19B35937-8852-0002-1274-A881C3C68D95")
IX509TrustManager : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IX509TrustManager*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX509TrustManager*)pObj->Probe(EIID_IX509TrustManager);
    }

    static CARAPI_(IX509TrustManager*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX509TrustManager*)pObj->Probe(EIID_IX509TrustManager);
    }

    virtual CARAPI CheckClientTrusted(
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Cert::IX509Certificate *> * chain,
        /* [in] */ const _ELASTOS String& authType) = 0;

    virtual CARAPI CheckServerTrusted(
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> * chain,
        /* [in] */ const _ELASTOS String& authType) = 0;

    virtual CARAPI GetAcceptedIssuers(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::Cert::IX509Certificate *> ** issuers) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
CAR_INTERFACE("275C7531-8312-9851-4B43-D363F4477B1B")
ICDefaultServerSocketFactoryClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDefaultServerSocketFactoryClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDefaultServerSocketFactoryClassObject*)pObj->Probe(EIID_ICDefaultServerSocketFactoryClassObject);
    }

    static CARAPI_(ICDefaultServerSocketFactoryClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDefaultServerSocketFactoryClassObject*)pObj->Probe(EIID_ICDefaultServerSocketFactoryClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Net {
CAR_INTERFACE("52AA6F34-8312-A551-A1E9-31FAA3BD8D1B")
ICDefaultSocketFactoryClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDefaultSocketFactoryClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDefaultSocketFactoryClassObject*)pObj->Probe(EIID_ICDefaultSocketFactoryClassObject);
    }

    static CARAPI_(ICDefaultSocketFactoryClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDefaultSocketFactoryClassObject*)pObj->Probe(EIID_ICDefaultSocketFactoryClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Net {
CAR_INTERFACE("68807431-0312-A5CC-A145-40F162C67D3D")
ICServerSocketFactoryHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICServerSocketFactoryHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICServerSocketFactoryHelperClassObject*)pObj->Probe(EIID_ICServerSocketFactoryHelperClassObject);
    }

    static CARAPI_(ICServerSocketFactoryHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICServerSocketFactoryHelperClassObject*)pObj->Probe(EIID_ICServerSocketFactoryHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Net {
CAR_INTERFACE("B6AB6E39-8312-D0D2-22A0-7831E3BE1EA3")
ICSocketFactoryHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSocketFactoryHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSocketFactoryHelperClassObject*)pObj->Probe(EIID_ICSocketFactoryHelperClassObject);
    }

    static CARAPI_(ICSocketFactoryHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSocketFactoryHelperClassObject*)pObj->Probe(EIID_ICSocketFactoryHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("88527C1B-C312-F5A0-9D91-F7DAD5B87D5B")
ICCertPathTrustManagerParametersClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCertPathTrustManagerParametersClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCertPathTrustManagerParametersClassObject*)pObj->Probe(EIID_ICCertPathTrustManagerParametersClassObject);
    }

    static CARAPI_(ICCertPathTrustManagerParametersClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCertPathTrustManagerParametersClassObject*)pObj->Probe(EIID_ICCertPathTrustManagerParametersClassObject);
    }

    virtual CARAPI CreateObjectWithParameters(
        /* [in] */ Elastos::Security::Cert::ICertPathParameters * parameters,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("66F9765A-8312-D823-72DF-8880B5E8CE0F")
ICDefaultHostnameVerifierClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDefaultHostnameVerifierClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDefaultHostnameVerifierClassObject*)pObj->Probe(EIID_ICDefaultHostnameVerifierClassObject);
    }

    static CARAPI_(ICDefaultHostnameVerifierClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDefaultHostnameVerifierClassObject*)pObj->Probe(EIID_ICDefaultHostnameVerifierClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("8EDB742E-8312-1C51-3854-C05C1A9A1EA3")
ICDefaultSSLServerSocketFactoryClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDefaultSSLServerSocketFactoryClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDefaultSSLServerSocketFactoryClassObject*)pObj->Probe(EIID_ICDefaultSSLServerSocketFactoryClassObject);
    }

    static CARAPI_(ICDefaultSSLServerSocketFactoryClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDefaultSSLServerSocketFactoryClassObject*)pObj->Probe(EIID_ICDefaultSSLServerSocketFactoryClassObject);
    }

    virtual CARAPI CreateObjectWithMes(
        /* [in] */ const _ELASTOS String& mes,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("DD066E3B-8312-1C51-3854-280D4D8FD11F")
ICDefaultSSLSocketFactoryClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDefaultSSLSocketFactoryClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDefaultSSLSocketFactoryClassObject*)pObj->Probe(EIID_ICDefaultSSLSocketFactoryClassObject);
    }

    static CARAPI_(ICDefaultSSLSocketFactoryClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDefaultSSLSocketFactoryClassObject*)pObj->Probe(EIID_ICDefaultSSLSocketFactoryClassObject);
    }

    virtual CARAPI CreateObjectWithMes(
        /* [in] */ const _ELASTOS String& mes,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("82977444-0312-9F24-91DA-2E7CA2CBCE0C")
ICDistinguishedNameParserClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDistinguishedNameParserClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDistinguishedNameParserClassObject*)pObj->Probe(EIID_ICDistinguishedNameParserClassObject);
    }

    static CARAPI_(ICDistinguishedNameParserClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDistinguishedNameParserClassObject*)pObj->Probe(EIID_ICDistinguishedNameParserClassObject);
    }

    virtual CARAPI CreateObjectWithPrincipal(
        /* [in] */ Elastosx::Security::Auth::X500::IX500Principal * principal,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("5D997048-8312-8208-4E10-7681A2080CB3")
ICHandshakeCompletedEventClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICHandshakeCompletedEventClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICHandshakeCompletedEventClassObject*)pObj->Probe(EIID_ICHandshakeCompletedEventClassObject);
    }

    static CARAPI_(ICHandshakeCompletedEventClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICHandshakeCompletedEventClassObject*)pObj->Probe(EIID_ICHandshakeCompletedEventClassObject);
    }

    virtual CARAPI CreateObjectWithSockS(
        /* [in] */ Elastosx::Net::Ssl::ISSLSocket * sock,
        /* [in] */ Elastosx::Net::Ssl::ISSLSession * s,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("F74F8030-8312-2B86-A1E9-31FAA3BD8D1B")
ICKeyManagerFactoryClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICKeyManagerFactoryClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyManagerFactoryClassObject*)pObj->Probe(EIID_ICKeyManagerFactoryClassObject);
    }

    static CARAPI_(ICKeyManagerFactoryClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyManagerFactoryClassObject*)pObj->Probe(EIID_ICKeyManagerFactoryClassObject);
    }

    virtual CARAPI CreateObjectWithFactorySpiProviderAlgorithm(
        /* [in] */ Elastosx::Net::Ssl::IKeyManagerFactorySpi * factorySpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("691B762B-8312-2B86-A145-40F162C67D3D")
ICKeyManagerFactoryHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICKeyManagerFactoryHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyManagerFactoryHelperClassObject*)pObj->Probe(EIID_ICKeyManagerFactoryHelperClassObject);
    }

    static CARAPI_(ICKeyManagerFactoryHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyManagerFactoryHelperClassObject*)pObj->Probe(EIID_ICKeyManagerFactoryHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("8D9C7722-8312-3708-6ECC-B0C19C510414")
ICHttpsURLConnectionHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICHttpsURLConnectionHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICHttpsURLConnectionHelperClassObject*)pObj->Probe(EIID_ICHttpsURLConnectionHelperClassObject);
    }

    static CARAPI_(ICHttpsURLConnectionHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICHttpsURLConnectionHelperClassObject*)pObj->Probe(EIID_ICHttpsURLConnectionHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("B6C07815-C312-1571-23C7-37BADFCC4BDA")
ICSSLContextClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSSLContextClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSSLContextClassObject*)pObj->Probe(EIID_ICSSLContextClassObject);
    }

    static CARAPI_(ICSSLContextClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSSLContextClassObject*)pObj->Probe(EIID_ICSSLContextClassObject);
    }

    virtual CARAPI CreateObjectWithContextSpiProviderProtocol(
        /* [in] */ Elastosx::Net::Ssl::ISSLContextSpi * contextSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& protocol,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("4E1E6F03-C312-1571-23C7-37BADF11FACE")
ICSSLContextHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSSLContextHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSSLContextHelperClassObject*)pObj->Probe(EIID_ICSSLContextHelperClassObject);
    }

    static CARAPI_(ICSSLContextHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSSLContextHelperClassObject*)pObj->Probe(EIID_ICSSLContextHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("9386924A-0312-1C0E-2A40-8177344DE49A")
ICSSLEngineResultClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSSLEngineResultClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSSLEngineResultClassObject*)pObj->Probe(EIID_ICSSLEngineResultClassObject);
    }

    static CARAPI_(ICSSLEngineResultClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSSLEngineResultClassObject*)pObj->Probe(EIID_ICSSLEngineResultClassObject);
    }

    virtual CARAPI CreateObjectWithStatusHandshakeStatusBytesConsumedBytesProduced(
        /* [in] */ Elastosx::Net::Ssl::SSLEngineResult_Status status,
        /* [in] */ Elastosx::Net::Ssl::SSLEngineResult_HandshakeStatus handshakeStatus,
        /* [in] */ _ELASTOS Int32 bytesConsumed,
        /* [in] */ _ELASTOS Int32 bytesProduced,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("F789AD21-0312-1C0E-2A5C-B5A1C7E88FF6")
ICSSLParametersClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSSLParametersClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSSLParametersClassObject*)pObj->Probe(EIID_ICSSLParametersClassObject);
    }

    static CARAPI_(ICSSLParametersClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSSLParametersClassObject*)pObj->Probe(EIID_ICSSLParametersClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCipherSuites(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * cipherSuites,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCipherSuitesProtocols(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * cipherSuites,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * protocols,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("3A8A801B-C312-5571-86D6-306BDBAC1C33")
ICSSLPermissionClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSSLPermissionClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSSLPermissionClassObject*)pObj->Probe(EIID_ICSSLPermissionClassObject);
    }

    static CARAPI_(ICSSLPermissionClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSSLPermissionClassObject*)pObj->Probe(EIID_ICSSLPermissionClassObject);
    }

    virtual CARAPI CreateObjectWithName(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithNameActions(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("FF947B3E-0312-1C0E-2A60-2E0D2D028A17")
ICSSLServerSocketFactoryHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSSLServerSocketFactoryHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSSLServerSocketFactoryHelperClassObject*)pObj->Probe(EIID_ICSSLServerSocketFactoryHelperClassObject);
    }

    static CARAPI_(ICSSLServerSocketFactoryHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSSLServerSocketFactoryHelperClassObject*)pObj->Probe(EIID_ICSSLServerSocketFactoryHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("3DC8753D-0312-1C0E-2A70-C01FDF4C7D66")
ICSSLSessionBindingEventClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSSLSessionBindingEventClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSSLSessionBindingEventClassObject*)pObj->Probe(EIID_ICSSLSessionBindingEventClassObject);
    }

    static CARAPI_(ICSSLSessionBindingEventClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSSLSessionBindingEventClassObject*)pObj->Probe(EIID_ICSSLSessionBindingEventClassObject);
    }

    virtual CARAPI CreateObjectWithSessionName(
        /* [in] */ Elastosx::Net::Ssl::ISSLSession * session,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("2AE37529-0312-1C0E-2A94-861601C58B19")
ICSSLSocketFactoryHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSSLSocketFactoryHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSSLSocketFactoryHelperClassObject*)pObj->Probe(EIID_ICSSLSocketFactoryHelperClassObject);
    }

    static CARAPI_(ICSSLSocketFactoryHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSSLSocketFactoryHelperClassObject*)pObj->Probe(EIID_ICSSLSocketFactoryHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("76D68226-8312-350E-70D8-B8B1129A1EA3")
ICTrustManagerFactoryClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICTrustManagerFactoryClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTrustManagerFactoryClassObject*)pObj->Probe(EIID_ICTrustManagerFactoryClassObject);
    }

    static CARAPI_(ICTrustManagerFactoryClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTrustManagerFactoryClassObject*)pObj->Probe(EIID_ICTrustManagerFactoryClassObject);
    }

    virtual CARAPI CreateObjectWithFactorySpiProviderAlgorithm(
        /* [in] */ Elastosx::Net::Ssl::ITrustManagerFactorySpi * factorySpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
CAR_INTERFACE("E8A17826-8312-350E-70D8-B8B1125A0414")
ICTrustManagerFactoryHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICTrustManagerFactoryHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTrustManagerFactoryHelperClassObject*)pObj->Probe(EIID_ICTrustManagerFactoryHelperClassObject);
    }

    static CARAPI_(ICTrustManagerFactoryHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTrustManagerFactoryHelperClassObject*)pObj->Probe(EIID_ICTrustManagerFactoryHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
namespace Callback {
CAR_INTERFACE("73C36627-0652-3612-6CE8-C87F22CE8FF6")
IPasswordCallback : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPasswordCallback*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPasswordCallback*)pObj->Probe(EIID_IPasswordCallback);
    }

    static CARAPI_(IPasswordCallback*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPasswordCallback*)pObj->Probe(EIID_IPasswordCallback);
    }

    virtual CARAPI GetPrompt(
        /* [out] */ _ELASTOS String * prompt) = 0;

    virtual CARAPI IsEchoOn(
        /* [out] */ _ELASTOS Boolean * echoOn) = 0;

    virtual CARAPI SetPassword(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password) = 0;

    virtual CARAPI GetPassword(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Char32> ** password) = 0;

    virtual CARAPI ClearPassword() = 0;

};
}
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
CAR_INTERFACE("5DFC535A-0652-BDBD-3533-C03B2BC66740")
IPrivateCredentialPermission : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPrivateCredentialPermission*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPrivateCredentialPermission*)pObj->Probe(EIID_IPrivateCredentialPermission);
    }

    static CARAPI_(IPrivateCredentialPermission*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPrivateCredentialPermission*)pObj->Probe(EIID_IPrivateCredentialPermission);
    }

    virtual CARAPI GetPrincipals(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Core::IArrayOf *> ** principals) = 0;

    virtual CARAPI GetCredentialClass(
        /* [out] */ _ELASTOS String * credential) = 0;

};
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
CAR_INTERFACE("5157BA08-8712-2D97-6ADE-BFF392F62DDB")
ISubject : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISubject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISubject*)pObj->Probe(EIID_ISubject);
    }

    static CARAPI_(ISubject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISubject*)pObj->Probe(EIID_ISubject);
    }

    virtual CARAPI Equals(
        /* [in] */ IInterface * obj,
        /* [out] */ _ELASTOS Boolean * isEqual) = 0;

    virtual CARAPI GetPrincipals(
        /* [out] */ Elastos::Utility::ISet ** principals) = 0;

    virtual CARAPI GetPrincipals(
        /* [in] */ IInterface * c,
        /* [out] */ Elastos::Utility::ISet ** principals) = 0;

    virtual CARAPI GetPrivateCredentials(
        /* [out] */ Elastos::Utility::ISet ** credentials) = 0;

    virtual CARAPI GetPrivateCredentials(
        /* [in] */ const _ELASTOS ClassID & id,
        /* [out] */ Elastos::Utility::ISet ** credentials) = 0;

    virtual CARAPI GetPublicCredentials(
        /* [out] */ Elastos::Utility::ISet ** credentials) = 0;

    virtual CARAPI GetPublicCredentials(
        /* [in] */ const _ELASTOS ClassID & id,
        /* [out] */ Elastos::Utility::ISet ** credentials) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI SetReadOnly() = 0;

    virtual CARAPI IsReadOnly(
        /* [out] */ _ELASTOS Boolean * isReadOnly) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
CAR_INTERFACE("07C65415-8712-2D97-6ADE-11FACE68FD3B")
ISubjectHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISubjectHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISubjectHelper*)pObj->Probe(EIID_ISubjectHelper);
    }

    static CARAPI_(ISubjectHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISubjectHelper*)pObj->Probe(EIID_ISubjectHelper);
    }

    virtual CARAPI DoAs(
        /* [in] */ Elastosx::Security::Auth::ISubject * subject,
        /* [in] */ Elastos::Security::IPrivilegedAction * action,
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI DoAsPrivileged(
        /* [in] */ Elastosx::Security::Auth::ISubject * subject,
        /* [in] */ Elastos::Security::IPrivilegedAction * action,
        /* [in] */ Elastos::Security::IAccessControlContext * context,
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI DoAs(
        /* [in] */ Elastosx::Security::Auth::ISubject * subject,
        /* [in] */ Elastos::Security::IPrivilegedExceptionAction * action,
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI DoAsPrivileged(
        /* [in] */ Elastosx::Security::Auth::ISubject * subject,
        /* [in] */ Elastos::Security::IPrivilegedExceptionAction * action,
        /* [in] */ Elastos::Security::IAccessControlContext * context,
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI GetSubject(
        /* [in] */ Elastos::Security::IAccessControlContext * context,
        /* [out] */ Elastosx::Security::Auth::ISubject ** subject) = 0;

};
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
CAR_INTERFACE("2A393843-0712-251C-40BE-629253621118")
ISubjectDomainCombiner : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISubjectDomainCombiner*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISubjectDomainCombiner*)pObj->Probe(EIID_ISubjectDomainCombiner);
    }

    static CARAPI_(ISubjectDomainCombiner*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISubjectDomainCombiner*)pObj->Probe(EIID_ISubjectDomainCombiner);
    }

    virtual CARAPI GetSubject(
        /* [out] */ Elastosx::Security::Auth::ISubject ** subject) = 0;

};
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
namespace X500 {
CAR_INTERFACE("B237430A-5852-4000-56B3-B1C9CEE4FB3B")
IX500Principal : public IInterface
{
    static const _ELASTOS String CANONICAL;
    static const _ELASTOS String RFC1779;
    static const _ELASTOS String RFC2253;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IX500Principal*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX500Principal*)pObj->Probe(EIID_IX500Principal);
    }

    static CARAPI_(IX500Principal*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX500Principal*)pObj->Probe(EIID_IX500Principal);
    }

    virtual CARAPI GetEncoded(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** encodedName) = 0;

    virtual CARAPI GetName(
        /* [in] */ const _ELASTOS String& format,
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetName(
        /* [in] */ const _ELASTOS String& format,
        /* [in] */ Elastos::Utility::IMap * oidMap,
        /* [out] */ _ELASTOS String * name) = 0;

};
}
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
namespace Callback {
CAR_INTERFACE("45232A35-9C52-ED1F-6DDC-906163C70F0E")
ICallback : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICallback*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICallback*)pObj->Probe(EIID_ICallback);
    }

    static CARAPI_(ICallback*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICallback*)pObj->Probe(EIID_ICallback);
    }

};
}
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
namespace Callback {
CAR_INTERFACE("73E5372E-9C52-3F73-DADB-B821C3C68E1F")
ICallbackHandler : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICallbackHandler*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICallbackHandler*)pObj->Probe(EIID_ICallbackHandler);
    }

    static CARAPI_(ICallbackHandler*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICallbackHandler*)pObj->Probe(EIID_ICallbackHandler);
    }

    virtual CARAPI Handle(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastosx::Security::Auth::Callback::ICallback *> ** cbs) = 0;

};
}
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
CAR_INTERFACE("9A393652-1192-DBD6-2DFD-705052868D1D")
IDestroyable : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDestroyable*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDestroyable*)pObj->Probe(EIID_IDestroyable);
    }

    static CARAPI_(IDestroyable*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDestroyable*)pObj->Probe(EIID_IDestroyable);
    }

    virtual CARAPI Destroy() = 0;

    virtual CARAPI IsDestroyed(
        /* [out] */ _ELASTOS Boolean * isDestroyed) = 0;

};
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
CAR_INTERFACE("6B8A274D-0292-A51C-333C-E36963F10F07")
IAuthPermission : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAuthPermission*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAuthPermission*)pObj->Probe(EIID_IAuthPermission);
    }

    static CARAPI_(IAuthPermission*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAuthPermission*)pObj->Probe(EIID_IAuthPermission);
    }

};
}
}
}
namespace Elastosx {
namespace Security {
namespace Cert {
CAR_INTERFACE("7C975F4E-8312-9F67-BB75-D2FCC3414919")
ICertificate : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICertificate*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertificate*)pObj->Probe(EIID_ICertificate);
    }

    static CARAPI_(ICertificate*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertificate*)pObj->Probe(EIID_ICertificate);
    }

    virtual CARAPI Equals(
        /* [in] */ IInterface * obj,
        /* [out] */ _ELASTOS Boolean * isEqual) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI GetEncoded(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** encode) = 0;

    virtual CARAPI Verify(
        /* [in] */ Elastos::Security::IPublicKey * key) = 0;

    virtual CARAPI Verify(
        /* [in] */ Elastos::Security::IPublicKey * key,
        /* [in] */ const _ELASTOS String& sigProvider) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetPublicKey(
        /* [out] */ Elastos::Security::IPublicKey ** pubkey) = 0;

};
}
}
}
namespace Elastosx {
namespace Security {
namespace Cert {
CAR_INTERFACE("088CB10C-5852-0900-83D6-379BB22679A3")
IX509Certificate : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IX509Certificate*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX509Certificate*)pObj->Probe(EIID_IX509Certificate);
    }

    static CARAPI_(IX509Certificate*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX509Certificate*)pObj->Probe(EIID_IX509Certificate);
    }

    virtual CARAPI CheckValidity() = 0;

    virtual CARAPI CheckValidity(
        /* [in] */ Elastos::Utility::IDate * date) = 0;

    virtual CARAPI GetVersion(
        /* [out] */ _ELASTOS Int32 * vs) = 0;

    virtual CARAPI GetSerialNumber(
        /* [out] */ Elastos::Math::IBigInteger ** number) = 0;

    virtual CARAPI GetIssuerDN(
        /* [out] */ Elastos::Security::IPrincipal ** dn) = 0;

    virtual CARAPI GetSubjectDN(
        /* [out] */ Elastos::Security::IPrincipal ** dn) = 0;

    virtual CARAPI GetNotBefore(
        /* [out] */ Elastos::Utility::IDate ** dt) = 0;

    virtual CARAPI GetNotAfter(
        /* [out] */ Elastos::Utility::IDate ** dt) = 0;

    virtual CARAPI GetSigAlgName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetSigAlgOID(
        /* [out] */ _ELASTOS String * oid) = 0;

    virtual CARAPI GetSigAlgParams(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** params) = 0;

};
}
}
}
namespace Elastosx {
namespace Security {
namespace Cert {
CAR_INTERFACE("27204417-5852-0900-83D6-379BB22679A3")
IX509CertificateHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IX509CertificateHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX509CertificateHelper*)pObj->Probe(EIID_IX509CertificateHelper);
    }

    static CARAPI_(IX509CertificateHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX509CertificateHelper*)pObj->Probe(EIID_IX509CertificateHelper);
    }

    virtual CARAPI GetInstance(
        /* [in] */ Elastos::IO::IInputStream * inStream,
        /* [out] */ Elastosx::Security::Cert::IX509Certificate ** cert) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * certData,
        /* [out] */ Elastosx::Security::Cert::IX509Certificate ** cert) = 0;

};
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
namespace Callback {
CAR_INTERFACE("0B057F22-8312-240C-6CD8-D091FF441C3D")
ICPasswordCallbackClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPasswordCallbackClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPasswordCallbackClassObject*)pObj->Probe(EIID_ICPasswordCallbackClassObject);
    }

    static CARAPI_(ICPasswordCallbackClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPasswordCallbackClassObject*)pObj->Probe(EIID_ICPasswordCallbackClassObject);
    }

    virtual CARAPI CreateObjectWithPromptEchoOn(
        /* [in] */ const _ELASTOS String& prompt,
        /* [in] */ _ELASTOS Boolean echoOn,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
namespace X500 {
CAR_INTERFACE("9A96B610-1312-0016-90D5-6C6CB233F932")
ICX500PrincipalClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICX500PrincipalClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICX500PrincipalClassObject*)pObj->Probe(EIID_ICX500PrincipalClassObject);
    }

    static CARAPI_(ICX500PrincipalClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICX500PrincipalClassObject*)pObj->Probe(EIID_ICX500PrincipalClassObject);
    }

    virtual CARAPI CreateObjectWithName1(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * name1,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithIs(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithName2(
        /* [in] */ const _ELASTOS String& name2,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithNameKeywordMap(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ Elastos::Utility::IMap * keywordMap,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
CAR_INTERFACE("B6D98752-0312-3805-4A67-78C6D3C66206")
ICAuthPermissionClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAuthPermissionClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAuthPermissionClassObject*)pObj->Probe(EIID_ICAuthPermissionClassObject);
    }

    static CARAPI_(ICAuthPermissionClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAuthPermissionClassObject*)pObj->Probe(EIID_ICAuthPermissionClassObject);
    }

    virtual CARAPI CreateObjectWithName(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithNameActions(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
CAR_INTERFACE("1F6B7F5A-8312-7A0C-7B6B-668077568CCF")
ICPrivateCredentialPermissionClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPrivateCredentialPermissionClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPrivateCredentialPermissionClassObject*)pObj->Probe(EIID_ICPrivateCredentialPermissionClassObject);
    }

    static CARAPI_(ICPrivateCredentialPermissionClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPrivateCredentialPermissionClassObject*)pObj->Probe(EIID_ICPrivateCredentialPermissionClassObject);
    }

    virtual CARAPI CreateObjectWithNameAction(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& action,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
CAR_INTERFACE("4333AF3E-0312-380E-4AB4-4061E2861EA3")
ICSubjectClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSubjectClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSubjectClassObject*)pObj->Probe(EIID_ICSubjectClassObject);
    }

    static CARAPI_(ICSubjectClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSubjectClassObject*)pObj->Probe(EIID_ICSubjectClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithReadOnlySubjPrincipalsPubCredentialsPrivCredentials(
        /* [in] */ _ELASTOS Boolean readOnly,
        /* [in] */ Elastos::Utility::ISet * subjPrincipals,
        /* [in] */ Elastos::Utility::ISet * pubCredentials,
        /* [in] */ Elastos::Utility::ISet * privCredentials,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
CAR_INTERFACE("FCE37214-C312-65E1-8B9A-7784BE335A33")
ICSubjectHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSubjectHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSubjectHelperClassObject*)pObj->Probe(EIID_ICSubjectHelperClassObject);
    }

    static CARAPI_(ICSubjectHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSubjectHelperClassObject*)pObj->Probe(EIID_ICSubjectHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
CAR_INTERFACE("ECFF7247-0312-380E-4A80-7CC524A7C422")
ICSubjectDomainCombinerClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSubjectDomainCombinerClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSubjectDomainCombinerClassObject*)pObj->Probe(EIID_ICSubjectDomainCombinerClassObject);
    }

    static CARAPI_(ICSubjectDomainCombinerClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSubjectDomainCombinerClassObject*)pObj->Probe(EIID_ICSubjectDomainCombinerClassObject);
    }

    virtual CARAPI CreateObjectWithSub(
        /* [in] */ Elastosx::Security::Auth::ISubject * sub,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Security {
namespace Cert {
CAR_INTERFACE("B99F7A14-1312-4016-C2A0-F5CDA6AC49DE")
ICX509CertificateHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICX509CertificateHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICX509CertificateHelperClassObject*)pObj->Probe(EIID_ICX509CertificateHelperClassObject);
    }

    static CARAPI_(ICX509CertificateHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICX509CertificateHelperClassObject*)pObj->Probe(EIID_ICX509CertificateHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Sql {
CAR_INTERFACE("FC9F5523-20D2-A64C-7FB4-B77143868D1D")
ICommonDataSource : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICommonDataSource*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICommonDataSource*)pObj->Probe(EIID_ICommonDataSource);
    }

    static CARAPI_(ICommonDataSource*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICommonDataSource*)pObj->Probe(EIID_ICommonDataSource);
    }

    virtual CARAPI GetLoginTimeout(
        /* [out] */ _ELASTOS Int32 * loginTimeout) = 0;

    virtual CARAPI GetLogWriter(
        /* [out] */ Elastos::IO::IPrintWriter ** logWriter) = 0;

    virtual CARAPI SetLoginTimeout(
        /* [in] */ _ELASTOS Int32 seconds) = 0;

    virtual CARAPI SetLogWriter(
        /* [in] */ Elastos::IO::IPrintWriter * value) = 0;

};
}
}
namespace Elastosx {
namespace Sql {
CAR_INTERFACE("53722D27-2312-3F66-DADB-B821C3C68E1F")
IConnectionEvent : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IConnectionEvent*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IConnectionEvent*)pObj->Probe(EIID_IConnectionEvent);
    }

    static CARAPI_(IConnectionEvent*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IConnectionEvent*)pObj->Probe(EIID_IConnectionEvent);
    }

    virtual CARAPI GetSQLException(
        /* [out] */ _ELASTOS ECode * sqlException) = 0;

};
}
}
namespace Elastosx {
namespace Sql {
CAR_INTERFACE("82F34D31-2312-1966-EFFF-686FE3860C1B")
IConnectionEventListener : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IConnectionEventListener*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IConnectionEventListener*)pObj->Probe(EIID_IConnectionEventListener);
    }

    static CARAPI_(IConnectionEventListener*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IConnectionEventListener*)pObj->Probe(EIID_IConnectionEventListener);
    }

    virtual CARAPI ConnectionClosed(
        /* [in] */ Elastosx::Sql::IConnectionEvent * theEvent) = 0;

    virtual CARAPI ConnectionErrorOccurred(
        /* [in] */ Elastosx::Sql::IConnectionEvent * theEvent) = 0;

};
}
}
namespace Elastosx {
namespace Sql {
CAR_INTERFACE("C187333B-2612-3FD3-DADB-B821C3C68E1F")
IDataSource : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDataSource*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDataSource*)pObj->Probe(EIID_IDataSource);
    }

    static CARAPI_(IDataSource*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDataSource*)pObj->Probe(EIID_IDataSource);
    }

    virtual CARAPI GetConnection(
        /* [out] */ Elastos::Sql::IConnection ** conn) = 0;

    virtual CARAPI GetConnection(
        /* [in] */ const _ELASTOS String& theUsername,
        /* [in] */ const _ELASTOS String& thePassword,
        /* [out] */ Elastos::Sql::IConnection ** conn) = 0;

};
}
}
namespace Elastosx {
namespace Sql {
CAR_INTERFACE("F2543824-EAD2-CCF7-7EB4-B77143868D1D")
IStatementEvent : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IStatementEvent*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStatementEvent*)pObj->Probe(EIID_IStatementEvent);
    }

    static CARAPI_(IStatementEvent*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStatementEvent*)pObj->Probe(EIID_IStatementEvent);
    }

    virtual CARAPI GetStatement(
        /* [out] */ Elastos::Sql::IPreparedStatement ** pstmt) = 0;

    virtual CARAPI GetSQLException(
        /* [out] */ _ELASTOS Int32 * sqlException) = 0;

};
}
}
namespace Elastosx {
namespace Sql {
CAR_INTERFACE("0F794A3C-EAD2-CCF7-32DE-FFD1DEC60D19")
IStatementEventListener : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IStatementEventListener*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStatementEventListener*)pObj->Probe(EIID_IStatementEventListener);
    }

    static CARAPI_(IStatementEventListener*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStatementEventListener*)pObj->Probe(EIID_IStatementEventListener);
    }

    virtual CARAPI StatementClosed(
        /* [in] */ Elastosx::Sql::IStatementEvent * event) = 0;

    virtual CARAPI StatementErrorOccurred(
        /* [in] */ Elastosx::Sql::IStatementEvent * event) = 0;

};
}
}
namespace Elastosx {
namespace Sql {
CAR_INTERFACE("9F989D28-5852-8CFD-7EB4-B77143868D1D")
IPooledConnection : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPooledConnection*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPooledConnection*)pObj->Probe(EIID_IPooledConnection);
    }

    static CARAPI_(IPooledConnection*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPooledConnection*)pObj->Probe(EIID_IPooledConnection);
    }

    virtual CARAPI AddConnectionEventListener(
        /* [in] */ Elastosx::Sql::IConnectionEventListener * theListener) = 0;

    virtual CARAPI Close() = 0;

    virtual CARAPI GetConnection(
        /* [out] */ Elastos::Sql::IConnection ** connection) = 0;

    virtual CARAPI RemoveConnectionEventListener(
        /* [in] */ Elastosx::Sql::IConnectionEventListener * theListener) = 0;

    virtual CARAPI AddStatementEventListener(
        /* [in] */ Elastosx::Sql::IStatementEventListener * listener1) = 0;

    virtual CARAPI RemoveStatementEventListener(
        /* [in] */ Elastosx::Sql::IStatementEventListener * listener2) = 0;

};
}
}
namespace Elastosx {
namespace Sql {
CAR_INTERFACE("A12D4D2B-A312-98B0-4CFF-686FE3860C1B")
IConnectionPoolDataSource : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IConnectionPoolDataSource*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IConnectionPoolDataSource*)pObj->Probe(EIID_IConnectionPoolDataSource);
    }

    static CARAPI_(IConnectionPoolDataSource*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IConnectionPoolDataSource*)pObj->Probe(EIID_IConnectionPoolDataSource);
    }

    virtual CARAPI GetPooledConnection(
        /* [out] */ Elastosx::Sql::IPooledConnection ** pconn) = 0;

    virtual CARAPI GetPooledConnection(
        /* [in] */ const _ELASTOS String& theUser,
        /* [in] */ const _ELASTOS String& thePassword,
        /* [out] */ Elastosx::Sql::IPooledConnection ** pconn) = 0;

};
}
}
namespace Elastosx {
namespace Sql {
CAR_INTERFACE("53E41A21-06D2-3A19-3433-FBD1DEC60D19")
IRowSetEvent : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRowSetEvent*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRowSetEvent*)pObj->Probe(EIID_IRowSetEvent);
    }

    static CARAPI_(IRowSetEvent*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRowSetEvent*)pObj->Probe(EIID_IRowSetEvent);
    }

};
}
}
namespace Elastosx {
namespace Sql {
CAR_INTERFACE("8AF13F38-06D2-3A19-3467-BCFFA3BD8D1B")
IRowSetListener : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRowSetListener*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRowSetListener*)pObj->Probe(EIID_IRowSetListener);
    }

    static CARAPI_(IRowSetListener*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRowSetListener*)pObj->Probe(EIID_IRowSetListener);
    }

    virtual CARAPI CursorMoved(
        /* [in] */ Elastosx::Sql::IRowSetEvent * theEvent) = 0;

    virtual CARAPI RowChanged(
        /* [in] */ Elastosx::Sql::IRowSetEvent * theEvent) = 0;

    virtual CARAPI RowSetChanged(
        /* [in] */ Elastosx::Sql::IRowSetEvent * theEvent) = 0;

};
}
}
namespace Elastosx {
namespace Sql {
CAR_INTERFACE("B9BEF956-86D2-6AAF-7E38-2829C3C68E1F")
IRowSet : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRowSet*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRowSet*)pObj->Probe(EIID_IRowSet);
    }

    static CARAPI_(IRowSet*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRowSet*)pObj->Probe(EIID_IRowSet);
    }

    virtual CARAPI AddRowSetListener(
        /* [in] */ Elastosx::Sql::IRowSetListener * theListener) = 0;

    virtual CARAPI ClearParameters() = 0;

    virtual CARAPI Execute() = 0;

    virtual CARAPI GetCommand(
        /* [out] */ _ELASTOS String * command) = 0;

    virtual CARAPI GetDataSourceName(
        /* [out] */ _ELASTOS String * dataSourceName) = 0;

    virtual CARAPI GetEscapeProcessing(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetMaxFieldSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetMaxRows(
        /* [out] */ _ELASTOS Int32 * rows) = 0;

    virtual CARAPI GetPassword(
        /* [out] */ _ELASTOS String * password) = 0;

    virtual CARAPI GetQueryTimeout(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetTransactionIsolation(
        /* [out] */ _ELASTOS Int32 * level) = 0;

    virtual CARAPI GetUrl(
        /* [out] */ _ELASTOS String * url) = 0;

    virtual CARAPI GetUsername(
        /* [out] */ _ELASTOS String * username) = 0;

    virtual CARAPI IsReadOnly(
        /* [out] */ _ELASTOS Boolean * isReadOnly) = 0;

    virtual CARAPI RemoveRowSetListener(
        /* [in] */ Elastosx::Sql::IRowSetListener * theListener) = 0;

    virtual CARAPI SetArray(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::IArray * theArray) = 0;

    virtual CARAPI SetAsciiStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IInputStream * theInputStream,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI SetAsciiStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IInputStream * theInputStream) = 0;

    virtual CARAPI SetAsciiStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IInputStream * theInputStream) = 0;

    virtual CARAPI SetAsciiStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IInputStream * theInputStream,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI SetBigDecimal(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Math::IBigDecimal * theBigDecimal) = 0;

    virtual CARAPI SetBigDecimal(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Math::IBigDecimal * theBigDecimal) = 0;

    virtual CARAPI SetBinaryStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IInputStream * theInputStream,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI SetBinaryStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IInputStream * theInputStream) = 0;

    virtual CARAPI SetBinaryStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IInputStream * theInputStream) = 0;

    virtual CARAPI SetBinaryStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IInputStream * theInputStream,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI SetBlob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::IBlob * theBlob) = 0;

    virtual CARAPI SetBlob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IInputStream * theInputStream) = 0;

    virtual CARAPI SetBlob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IInputStream * theInputStream,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI SetBlob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IInputStream * theInputStream) = 0;

    virtual CARAPI SetBlob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IInputStream * theInputStream,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI SetBlob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::IBlob * theBlob) = 0;

    virtual CARAPI SetBoolean(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ _ELASTOS Boolean theBoolean) = 0;

    virtual CARAPI SetBoolean(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Boolean theBoolean) = 0;

    virtual CARAPI SetByte(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ _ELASTOS Byte theByte) = 0;

    virtual CARAPI SetByte(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Byte theByte) = 0;

    virtual CARAPI SetBytes(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * theByteArray) = 0;

    virtual CARAPI SetBytes(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * theByteArray) = 0;

    virtual CARAPI SetCharacterStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * theReader,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI SetCharacterStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * theReader) = 0;

    virtual CARAPI SetCharacterStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * theReader) = 0;

    virtual CARAPI SetCharacterStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * theReader,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI SetClob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::IClob * theClob) = 0;

    virtual CARAPI SetClob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * theReader,
        /* [in] */ Elastos::Sql::IClob * theClob) = 0;

    virtual CARAPI SetClob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * theReader,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI SetClob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::IClob * theClob) = 0;

    virtual CARAPI SetClob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * theReader) = 0;

    virtual CARAPI SetClob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * theReader,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI SetCommand(
        /* [in] */ const _ELASTOS String& cmd) = 0;

    virtual CARAPI SetConcurrency(
        /* [in] */ _ELASTOS Int32 concurrency) = 0;

    virtual CARAPI SetDataSourceName(
        /* [in] */ const _ELASTOS String& name) = 0;

    virtual CARAPI SetDate(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::ISQLDate * theDate) = 0;

    virtual CARAPI SetDate(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::ISQLDate * theDate,
        /* [in] */ Elastos::Utility::ICalendar * theCalendar) = 0;

    virtual CARAPI SetDate(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::ISQLDate * theDate) = 0;

    virtual CARAPI SetDate(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::ISQLDate * theDate,
        /* [in] */ Elastos::Utility::ICalendar * theCalendar) = 0;

    virtual CARAPI SetDouble(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ _ELASTOS Double theDouble) = 0;

    virtual CARAPI SetDouble(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Double theDouble) = 0;

    virtual CARAPI SetEscapeProcessing(
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI SetFloat(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ _ELASTOS Float theFloat) = 0;

    virtual CARAPI SetFloat(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Float theFloat) = 0;

    virtual CARAPI SetInt32(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ _ELASTOS Int32 theInteger) = 0;

    virtual CARAPI SetInt32(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Int32 theInteger) = 0;

    virtual CARAPI SetInt64(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ _ELASTOS Int64 theLong) = 0;

    virtual CARAPI SetInt64(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Int64 theLong) = 0;

    virtual CARAPI SetMaxFieldSize(
        /* [in] */ _ELASTOS Int32 max) = 0;

    virtual CARAPI SetMaxRows(
        /* [in] */ _ELASTOS Int32 max) = 0;

    virtual CARAPI SetNCharacterStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * theReader) = 0;

    virtual CARAPI SetNCharacterStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * theReader,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI SetNCharacterStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * theReader) = 0;

    virtual CARAPI SetNCharacterStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * theReader,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI SetNClob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::INClob * theNClob) = 0;

    virtual CARAPI SetNClob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * theReader) = 0;

    virtual CARAPI SetNClob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * theReader,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI SetNClob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::INClob * theNClob) = 0;

    virtual CARAPI SetNClob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * theReader) = 0;

    virtual CARAPI SetNClob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * theReader,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI SetNString(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ const _ELASTOS String& theNString) = 0;

    virtual CARAPI SetNString(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ const _ELASTOS String& theNString) = 0;

    virtual CARAPI SetNull(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ _ELASTOS Int32 sqlType) = 0;

    virtual CARAPI SetNull(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ _ELASTOS Int32 sqlType,
        /* [in] */ const _ELASTOS String& typeName) = 0;

    virtual CARAPI SetNull(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Int32 sqlType) = 0;

    virtual CARAPI SetNull(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Int32 sqlType,
        /* [in] */ const _ELASTOS String& typeName) = 0;

    virtual CARAPI SetObject(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ IInterface * theObject) = 0;

    virtual CARAPI SetObject(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ IInterface * theObject,
        /* [in] */ _ELASTOS Int32 targetSqlType) = 0;

    virtual CARAPI SetObject(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ IInterface * theObject,
        /* [in] */ _ELASTOS Int32 targetSqlType,
        /* [in] */ _ELASTOS Int32 scale) = 0;

    virtual CARAPI SetObject(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ IInterface * theObject) = 0;

    virtual CARAPI SetObject(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ IInterface * theObject,
        /* [in] */ _ELASTOS Int32 targetSqlType) = 0;

    virtual CARAPI SetObject(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ IInterface * theObject,
        /* [in] */ _ELASTOS Int32 targetSqlType,
        /* [in] */ _ELASTOS Int32 scale) = 0;

    virtual CARAPI SetPassword(
        /* [in] */ const _ELASTOS String& password) = 0;

    virtual CARAPI SetQueryTimeout(
        /* [in] */ _ELASTOS Int32 seconds) = 0;

    virtual CARAPI SetReadOnly(
        /* [in] */ _ELASTOS Boolean readOnly) = 0;

    virtual CARAPI SetRef(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::IRef * theRef) = 0;

    virtual CARAPI SetInt16(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ _ELASTOS Int16 theShort) = 0;

    virtual CARAPI SetInt16(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Int16 theShort) = 0;

    virtual CARAPI SetString(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ const _ELASTOS String& theString) = 0;

    virtual CARAPI SetString(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ const _ELASTOS String& theString) = 0;

    virtual CARAPI SetRowId(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::IRowId * theRowId) = 0;

    virtual CARAPI SetRowId(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::IRowId * theRowId) = 0;

    virtual CARAPI SetSQLXML(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::ISQLXML * theSQLXML) = 0;

    virtual CARAPI SetSQLXML(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::ISQLXML * theSQLXML) = 0;

    virtual CARAPI SetTime(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::ITime * theTime) = 0;

    virtual CARAPI SetTime(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::ITime * theTime,
        /* [in] */ Elastos::Utility::ICalendar * theCalendar) = 0;

    virtual CARAPI SetTime(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::ITime * theTime) = 0;

    virtual CARAPI SetTime(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::ITime * theTime,
        /* [in] */ Elastos::Utility::ICalendar * theCalendar) = 0;

    virtual CARAPI SetTimestamp(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::ITimestamp * theTimestamp) = 0;

    virtual CARAPI SetTimestamp(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::ITimestamp * theTimestamp,
        /* [in] */ Elastos::Utility::ICalendar * theCalendar) = 0;

    virtual CARAPI SetTimestamp(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::ITimestamp * theTimestamp) = 0;

    virtual CARAPI SetTimestamp(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::ITimestamp * theTimestamp,
        /* [in] */ Elastos::Utility::ICalendar * theCalendar) = 0;

    virtual CARAPI SetTransactionIsolation(
        /* [in] */ _ELASTOS Int32 level) = 0;

    virtual CARAPI SetType(
        /* [in] */ _ELASTOS Int32 type) = 0;

    virtual CARAPI SetTypeMap(
        /* [in] */ Elastos::Utility::IMap * theTypeMap) = 0;

    virtual CARAPI SetUrl(
        /* [in] */ const _ELASTOS String& theURL) = 0;

    virtual CARAPI SetURL(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Net::IURL * theURL) = 0;

    virtual CARAPI SetUsername(
        /* [in] */ const _ELASTOS String& theUsername) = 0;

};
}
}
namespace Elastosx {
namespace Sql {
CAR_INTERFACE("BFC1FF59-86D2-6AAF-2C4C-23D180D10F07")
IRowSetMetaData : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRowSetMetaData*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRowSetMetaData*)pObj->Probe(EIID_IRowSetMetaData);
    }

    static CARAPI_(IRowSetMetaData*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRowSetMetaData*)pObj->Probe(EIID_IRowSetMetaData);
    }

    virtual CARAPI SetAutoIncrement(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ _ELASTOS Boolean autoIncrement) = 0;

    virtual CARAPI SetCaseSensitive(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ _ELASTOS Boolean caseSensitive) = 0;

    virtual CARAPI SetCatalogName(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ const _ELASTOS String& catalogName) = 0;

    virtual CARAPI SetColumnCount(
        /* [in] */ _ELASTOS Int32 columnCount) = 0;

    virtual CARAPI SetColumnDisplaySize(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ _ELASTOS Int32 displaySize) = 0;

    virtual CARAPI SetColumnLabel(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ const _ELASTOS String& theLabel) = 0;

    virtual CARAPI SetColumnName(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ const _ELASTOS String& theColumnName) = 0;

    virtual CARAPI SetColumnType(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ _ELASTOS Int32 theSQLType) = 0;

    virtual CARAPI SetColumnTypeName(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ const _ELASTOS String& theTypeName) = 0;

    virtual CARAPI SetCurrency(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ _ELASTOS Boolean isCurrency) = 0;

    virtual CARAPI SetNullable(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ _ELASTOS Int32 nullability) = 0;

    virtual CARAPI SetPrecision(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ _ELASTOS Int32 thePrecision) = 0;

    virtual CARAPI SetScale(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ _ELASTOS Int32 theScale) = 0;

    virtual CARAPI SetSchemaName(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ const _ELASTOS String& theSchemaName) = 0;

    virtual CARAPI SetSearchable(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ _ELASTOS Boolean isSearchable) = 0;

    virtual CARAPI SetSigned(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ _ELASTOS Boolean isSigned) = 0;

    virtual CARAPI SetTableName(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ const _ELASTOS String& theTableName) = 0;

};
}
}
namespace Elastosx {
namespace Sql {
CAR_INTERFACE("B869572D-06D2-3A19-340F-FCD1DEC60D19")
IRowSetInternal : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRowSetInternal*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRowSetInternal*)pObj->Probe(EIID_IRowSetInternal);
    }

    static CARAPI_(IRowSetInternal*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRowSetInternal*)pObj->Probe(EIID_IRowSetInternal);
    }

    virtual CARAPI GetConnection(
        /* [out] */ Elastos::Sql::IConnection ** conn) = 0;

    virtual CARAPI GetOriginal(
        /* [out] */ Elastos::Sql::IResultSet ** original) = 0;

    virtual CARAPI GetOriginalRow(
        /* [out] */ Elastos::Sql::IResultSet ** originalRow) = 0;

    virtual CARAPI GetParams(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** params) = 0;

    virtual CARAPI SetMetaData(
        /* [in] */ Elastosx::Sql::IRowSetMetaData * theMetaData) = 0;

};
}
}
namespace Elastosx {
namespace Sql {
CAR_INTERFACE("33BA2350-86D2-6AAF-CE3C-FBE1A0A40C1B")
IRowSetReader : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRowSetReader*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRowSetReader*)pObj->Probe(EIID_IRowSetReader);
    }

    static CARAPI_(IRowSetReader*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRowSetReader*)pObj->Probe(EIID_IRowSetReader);
    }

    virtual CARAPI ReadData(
        /* [in] */ Elastosx::Sql::IRowSetInternal * theCaller) = 0;

};
}
}
namespace Elastosx {
namespace Sql {
CAR_INTERFACE("0B292449-86D2-6AAF-F0D4-F8E1A0A40C1B")
IRowSetWriter : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRowSetWriter*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRowSetWriter*)pObj->Probe(EIID_IRowSetWriter);
    }

    static CARAPI_(IRowSetWriter*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRowSetWriter*)pObj->Probe(EIID_IRowSetWriter);
    }

    virtual CARAPI WriteData(
        /* [in] */ Elastosx::Sql::IRowSetInternal * theRowSet,
        /* [out] */ _ELASTOS Boolean * value) = 0;

};
}
}
namespace Elastosx {
namespace Sql {
CAR_INTERFACE("DFDC9537-0312-CC46-F418-FDD1DEC60D19")
ICConnectionEventClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICConnectionEventClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICConnectionEventClassObject*)pObj->Probe(EIID_ICConnectionEventClassObject);
    }

    static CARAPI_(ICConnectionEventClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICConnectionEventClassObject*)pObj->Probe(EIID_ICConnectionEventClassObject);
    }

    virtual CARAPI CreateObjectWithTheConnection(
        /* [in] */ Elastosx::Sql::IPooledConnection * theConnection,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithTheConnectionTheException(
        /* [in] */ Elastosx::Sql::IPooledConnection * theConnection,
        /* [in] */ _ELASTOS ECode theException,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Sql {
CAR_INTERFACE("91D16429-8312-320D-7468-66A6C7E88FF6")
ICRowSetEventClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICRowSetEventClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRowSetEventClassObject*)pObj->Probe(EIID_ICRowSetEventClassObject);
    }

    static CARAPI_(ICRowSetEventClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRowSetEventClassObject*)pObj->Probe(EIID_ICRowSetEventClassObject);
    }

    virtual CARAPI CreateObjectWithTheSource(
        /* [in] */ Elastosx::Sql::IRowSet * theSource,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Sql {
CAR_INTERFACE("2FA19232-8312-EFD5-99E9-31FAA3BD8D1B")
ICStatementEventClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICStatementEventClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStatementEventClassObject*)pObj->Probe(EIID_ICStatementEventClassObject);
    }

    static CARAPI_(ICStatementEventClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStatementEventClassObject*)pObj->Probe(EIID_ICStatementEventClassObject);
    }

    virtual CARAPI CreateObjectWithConStatementTheException(
        /* [in] */ Elastosx::Sql::IPooledConnection * con,
        /* [in] */ Elastos::Sql::IPreparedStatement * statement,
        /* [in] */ _ELASTOS ECode theException,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithConStatement(
        /* [in] */ Elastosx::Sql::IPooledConnection * con,
        /* [in] */ Elastos::Sql::IPreparedStatement * statement,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastosx {
namespace Xml {
CAR_INTERFACE("B8361B0E-6852-8C55-1CDB-3719DFF6EFBC")
IXMLConstants : public IInterface
{
    static const _ELASTOS String NULL_NS_URI;
    static const _ELASTOS String DEFAULT_NS_PREFIX;
    static const _ELASTOS String XML_NS_URI;
    static const _ELASTOS String XML_NS_PREFIX;
    static const _ELASTOS String XMLNS_ATTRIBUTE_NS_URI;
    static const _ELASTOS String XMLNS_ATTRIBUTE;
    static const _ELASTOS String W3C_XML_SCHEMA_NS_URI;
    static const _ELASTOS String W3C_XML_SCHEMA_INSTANCE_NS_URI;
    static const _ELASTOS String W3C_XPATH_DATATYPE_NS_URI;
    static const _ELASTOS String XML_DTD_NS_URI;
    static const _ELASTOS String RELAXNG_NS_URI;
    static const _ELASTOS String FEATURE_SECURE_PROCESSING;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IXMLConstants*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXMLConstants*)pObj->Probe(EIID_IXMLConstants);
    }

    static CARAPI_(IXMLConstants*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXMLConstants*)pObj->Probe(EIID_IXMLConstants);
    }

};
}
}
namespace Elastosx {
namespace Xml {
namespace Parsers {
CAR_INTERFACE("4BC6B728-2CD2-F736-7FB4-B77143868D1D")
IDocumentBuilder : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDocumentBuilder*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDocumentBuilder*)pObj->Probe(EIID_IDocumentBuilder);
    }

    static CARAPI_(IDocumentBuilder*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDocumentBuilder*)pObj->Probe(EIID_IDocumentBuilder);
    }

    virtual CARAPI Reset() = 0;

    virtual CARAPI Parse(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ Org::W3c::Dom::IDocument ** doc) = 0;

    virtual CARAPI Parse(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ Org::W3c::Dom::IDocument ** doc) = 0;

    virtual CARAPI Parse(
        /* [in] */ const _ELASTOS String& uri,
        /* [out] */ Org::W3c::Dom::IDocument ** doc) = 0;

    virtual CARAPI Parse(
        /* [in] */ Elastos::IO::IFile * f,
        /* [out] */ Org::W3c::Dom::IDocument ** doc) = 0;

    virtual CARAPI Parse(
        /* [in] */ Org::Xml::Sax::IInputSource * is,
        /* [out] */ Org::W3c::Dom::IDocument ** doc) = 0;

    virtual CARAPI IsNamespaceAware(
        /* [out] */ _ELASTOS Boolean * isAware) = 0;

    virtual CARAPI IsValidating(
        /* [out] */ _ELASTOS Boolean * isValidating) = 0;

    virtual CARAPI SetEntityResolver(
        /* [in] */ Org::Xml::Sax::IEntityResolver * er) = 0;

    virtual CARAPI SetErrorHandler(
        /* [in] */ Org::Xml::Sax::IErrorHandler * eh) = 0;

    virtual CARAPI NewDocument(
        /* [out] */ Org::W3c::Dom::IDocument ** doc) = 0;

    virtual CARAPI GetDOMImplementation(
        /* [out] */ Org::W3c::Dom::IDOMImplementation ** impl) = 0;

    virtual CARAPI GetSchema(
        /* [out] */ Elastosx::Xml::Validation::ISchema ** schema) = 0;

    virtual CARAPI IsXIncludeAware(
        /* [out] */ _ELASTOS Boolean * isAware) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Parsers {
CAR_INTERFACE("A014F727-2CD2-F736-A1FD-686FE3860C1B")
IDocumentBuilderFactory : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDocumentBuilderFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDocumentBuilderFactory*)pObj->Probe(EIID_IDocumentBuilderFactory);
    }

    static CARAPI_(IDocumentBuilderFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDocumentBuilderFactory*)pObj->Probe(EIID_IDocumentBuilderFactory);
    }

    virtual CARAPI NewDocumentBuilder(
        /* [out] */ Elastosx::Xml::Parsers::IDocumentBuilder ** builder) = 0;

    virtual CARAPI SetNamespaceAware(
        /* [in] */ _ELASTOS Boolean awareness) = 0;

    virtual CARAPI SetValidating(
        /* [in] */ _ELASTOS Boolean validating) = 0;

    virtual CARAPI SetIgnoringElementContentWhitespace(
        /* [in] */ _ELASTOS Boolean whitespace) = 0;

    virtual CARAPI SetExpandEntityReferences(
        /* [in] */ _ELASTOS Boolean expandEntityRef) = 0;

    virtual CARAPI SetIgnoringComments(
        /* [in] */ _ELASTOS Boolean ignoreComments) = 0;

    virtual CARAPI SetCoalescing(
        /* [in] */ _ELASTOS Boolean coalescing) = 0;

    virtual CARAPI IsNamespaceAware(
        /* [out] */ _ELASTOS Boolean * isAware) = 0;

    virtual CARAPI IsValidating(
        /* [out] */ _ELASTOS Boolean * isValidating) = 0;

    virtual CARAPI IsIgnoringElementContentWhitespace(
        /* [out] */ _ELASTOS Boolean * isIgnoringElementContentWhiteSpace) = 0;

    virtual CARAPI IsExpandEntityReferences(
        /* [out] */ _ELASTOS Boolean * isExpandEntityReferences) = 0;

    virtual CARAPI IsIgnoringComments(
        /* [out] */ _ELASTOS Boolean * comments) = 0;

    virtual CARAPI IsCoalescing(
        /* [out] */ _ELASTOS Boolean * isCoalescing) = 0;

    virtual CARAPI SetAttribute(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ IObject * value) = 0;

    virtual CARAPI GetAttribute(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** attri) = 0;

    virtual CARAPI SetFeature(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI GetFeature(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Boolean * feature) = 0;

    virtual CARAPI GetSchema(
        /* [out] */ Elastosx::Xml::Validation::ISchema ** schema) = 0;

    virtual CARAPI SetSchema(
        /* [in] */ Elastosx::Xml::Validation::ISchema * schema) = 0;

    virtual CARAPI SetXIncludeAware(
        /* [in] */ _ELASTOS Boolean state) = 0;

    virtual CARAPI IsXIncludeAware(
        /* [out] */ _ELASTOS Boolean * isXIncludeAware) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Parsers {
CAR_INTERFACE("78084929-2CD2-F736-A145-40F162C6FD1F")
IDocumentBuilderFactoryHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDocumentBuilderFactoryHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDocumentBuilderFactoryHelper*)pObj->Probe(EIID_IDocumentBuilderFactoryHelper);
    }

    static CARAPI_(IDocumentBuilderFactoryHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDocumentBuilderFactoryHelper*)pObj->Probe(EIID_IDocumentBuilderFactoryHelper);
    }

    virtual CARAPI NewInstance(
        /* [out] */ Elastosx::Xml::Parsers::IDocumentBuilderFactory ** instance) = 0;

    virtual CARAPI NewInstance(
        /* [in] */ const _ELASTOS String& factoryClassName,
        /* [in] */ Elastos::Core::IClassLoader * classLoader,
        /* [out] */ Elastosx::Xml::Parsers::IDocumentBuilderFactory ** instance) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Parsers {
CAR_INTERFACE("35C8B238-0712-2105-3290-A861E33EB41F")
ISAXParserFactory : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISAXParserFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISAXParserFactory*)pObj->Probe(EIID_ISAXParserFactory);
    }

    static CARAPI_(ISAXParserFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISAXParserFactory*)pObj->Probe(EIID_ISAXParserFactory);
    }

    virtual CARAPI NewSAXParser(
        /* [out] */ Elastosx::Xml::Parsers::ISAXParser ** parser) = 0;

    virtual CARAPI SetNamespaceAware(
        /* [in] */ _ELASTOS Boolean awareness) = 0;

    virtual CARAPI SetValidating(
        /* [in] */ _ELASTOS Boolean validating) = 0;

    virtual CARAPI IsNamespaceAware(
        /* [out] */ _ELASTOS Boolean * isAware) = 0;

    virtual CARAPI IsValidating(
        /* [out] */ _ELASTOS Boolean * isValidating) = 0;

    virtual CARAPI SetFeature(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI GetFeature(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Boolean * feature) = 0;

    virtual CARAPI GetSchema(
        /* [out] */ Elastosx::Xml::Validation::ISchema ** schema) = 0;

    virtual CARAPI SetSchema(
        /* [in] */ Elastosx::Xml::Validation::ISchema * schema) = 0;

    virtual CARAPI SetXIncludeAware(
        /* [in] */ _ELASTOS Boolean state) = 0;

    virtual CARAPI IsXIncludeAware(
        /* [out] */ _ELASTOS Boolean * isAware) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Parsers {
CAR_INTERFACE("8BA44339-0712-2105-3290-A861E33EB408")
ISAXParserFactoryHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISAXParserFactoryHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISAXParserFactoryHelper*)pObj->Probe(EIID_ISAXParserFactoryHelper);
    }

    static CARAPI_(ISAXParserFactoryHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISAXParserFactoryHelper*)pObj->Probe(EIID_ISAXParserFactoryHelper);
    }

    virtual CARAPI NewInstance(
        /* [out] */ Elastosx::Xml::Parsers::ISAXParserFactory ** instance) = 0;

    virtual CARAPI NewInstance(
        /* [in] */ const _ELASTOS String& factoryClassName,
        /* [in] */ Elastos::Core::IClassLoader * classLoader,
        /* [out] */ Elastosx::Xml::Parsers::ISAXParserFactory ** instance) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Parsers {
CAR_INTERFACE("B13EB607-A712-1984-59DB-68FD3B2F69DF")
ISAXParser : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISAXParser*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISAXParser*)pObj->Probe(EIID_ISAXParser);
    }

    static CARAPI_(ISAXParser*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISAXParser*)pObj->Probe(EIID_ISAXParser);
    }

    virtual CARAPI Reset() = 0;

    virtual CARAPI Parse(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Org::Xml::Sax::IDocumentHandler * hb) = 0;

    virtual CARAPI Parse(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Org::Xml::Sax::IDocumentHandler * hb,
        /* [in] */ const _ELASTOS String& systemId) = 0;

    virtual CARAPI Parse(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Org::Xml::Sax::IDTDHandler * dh) = 0;

    virtual CARAPI Parse(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Org::Xml::Sax::IDTDHandler * dh,
        /* [in] */ const _ELASTOS String& systemId) = 0;

    virtual CARAPI Parse(
        /* [in] */ const _ELASTOS String& uri,
        /* [in] */ Org::Xml::Sax::IDocumentHandler * hb) = 0;

    virtual CARAPI Parse(
        /* [in] */ const _ELASTOS String& uri,
        /* [in] */ Org::Xml::Sax::IDTDHandler * dh) = 0;

    virtual CARAPI Parse(
        /* [in] */ Elastos::IO::IFile * f,
        /* [in] */ Org::Xml::Sax::IDocumentHandler * hb) = 0;

    virtual CARAPI Parse(
        /* [in] */ Elastos::IO::IFile * f,
        /* [in] */ Org::Xml::Sax::IDTDHandler * dh) = 0;

    virtual CARAPI Parse(
        /* [in] */ Org::Xml::Sax::IInputSource * is,
        /* [in] */ Org::Xml::Sax::IDocumentHandler * hb) = 0;

    virtual CARAPI Parse(
        /* [in] */ Org::Xml::Sax::IInputSource * is,
        /* [in] */ Org::Xml::Sax::IDTDHandler * dh) = 0;

    virtual CARAPI GetParser(
        /* [out] */ Org::Xml::Sax::IParser ** parser) = 0;

    virtual CARAPI GetXMLReader(
        /* [out] */ Org::Xml::Sax::IXMLReader ** reader) = 0;

    virtual CARAPI IsNamespaceAware(
        /* [out] */ _ELASTOS Boolean * isAware) = 0;

    virtual CARAPI IsValidating(
        /* [out] */ _ELASTOS Boolean * isValidating) = 0;

    virtual CARAPI SetProperty(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI GetProperty(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** property) = 0;

    virtual CARAPI GetSchema(
        /* [out] */ Elastosx::Xml::Validation::ISchema ** schema) = 0;

    virtual CARAPI IsXIncludeAware(
        /* [out] */ _ELASTOS Boolean * isAware) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Validation {
CAR_INTERFACE("75D7684E-1C92-192D-F8FE-9E55E3878392")
ITypeInfoProvider : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITypeInfoProvider*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITypeInfoProvider*)pObj->Probe(EIID_ITypeInfoProvider);
    }

    static CARAPI_(ITypeInfoProvider*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITypeInfoProvider*)pObj->Probe(EIID_ITypeInfoProvider);
    }

    virtual CARAPI GetElementTypeInfo(
        /* [out] */ Org::W3c::Dom::ITypeInfo ** info) = 0;

    virtual CARAPI GetAttributeTypeInfo(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ Org::W3c::Dom::ITypeInfo ** info) = 0;

    virtual CARAPI IsIdAttribute(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Boolean * state) = 0;

    virtual CARAPI IsSpecified(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Boolean * specified) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Validation {
CAR_INTERFACE("A0C4A751-9D92-5747-7F38-2829C3C68E1F")
IValidator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IValidator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IValidator*)pObj->Probe(EIID_IValidator);
    }

    static CARAPI_(IValidator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IValidator*)pObj->Probe(EIID_IValidator);
    }

    virtual CARAPI Reset() = 0;

    virtual CARAPI Validate(
        /* [in] */ Elastosx::Xml::Transform::ISource * source) = 0;

    virtual CARAPI Validate(
        /* [in] */ Elastosx::Xml::Transform::ISource * source,
        /* [in] */ Elastosx::Xml::Transform::IResult * result) = 0;

    virtual CARAPI SetErrorHandler(
        /* [in] */ Org::Xml::Sax::IErrorHandler * errorHandler) = 0;

    virtual CARAPI GetErrorHandler(
        /* [out] */ Org::Xml::Sax::IErrorHandler ** handler) = 0;

    virtual CARAPI SetResourceResolver(
        /* [in] */ Org::W3c::Dom::Ls::ILSResourceResolver * resourceResolver) = 0;

    virtual CARAPI GsetResourceResolver(
        /* [out] */ Org::W3c::Dom::Ls::ILSResourceResolver ** resolver) = 0;

    virtual CARAPI GetFeature(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Boolean * feature) = 0;

    virtual CARAPI SetFeature(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI SetProperty(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI GetProperty(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** property) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Validation {
CAR_INTERFACE("CE7CCD2C-7792-3712-F29F-FBD1DEC60D19")
IValidatorHandler : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IValidatorHandler*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IValidatorHandler*)pObj->Probe(EIID_IValidatorHandler);
    }

    static CARAPI_(IValidatorHandler*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IValidatorHandler*)pObj->Probe(EIID_IValidatorHandler);
    }

    virtual CARAPI SetContentHandler(
        /* [in] */ Org::Xml::Sax::IContentHandler * receiver) = 0;

    virtual CARAPI GetContentHandler(
        /* [out] */ Org::Xml::Sax::IContentHandler ** receiver) = 0;

    virtual CARAPI SetErrorHandler(
        /* [in] */ Org::Xml::Sax::IErrorHandler * errorHandler) = 0;

    virtual CARAPI GetErrorHandler(
        /* [out] */ Org::Xml::Sax::IErrorHandler ** errorHandler) = 0;

    virtual CARAPI SetResourceResolver(
        /* [in] */ Org::W3c::Dom::Ls::ILSResourceResolver * resourceResolver) = 0;

    virtual CARAPI GetResourceResolver(
        /* [out] */ Org::W3c::Dom::Ls::ILSResourceResolver ** resourceResolver) = 0;

    virtual CARAPI GetTypeInfoProvider(
        /* [out] */ Elastosx::Xml::Validation::ITypeInfoProvider ** provider) = 0;

    virtual CARAPI GetFeature(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Boolean * feature) = 0;

    virtual CARAPI SetFeature(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI SetProperty(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI GetProperty(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** property) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Validation {
CAR_INTERFACE("5D493F41-0712-3951-7F38-2829C3C68E1F")
ISchema : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISchema*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISchema*)pObj->Probe(EIID_ISchema);
    }

    static CARAPI_(ISchema*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISchema*)pObj->Probe(EIID_ISchema);
    }

    virtual CARAPI NewValidator(
        /* [out] */ Elastosx::Xml::Validation::IValidator ** validator) = 0;

    virtual CARAPI NewValidatorHandler(
        /* [out] */ Elastosx::Xml::Validation::IValidatorHandler ** handler) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Validation {
CAR_INTERFACE("DB5EDB46-0712-3951-1F90-7865F5878392")
ISchemaFactory : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISchemaFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISchemaFactory*)pObj->Probe(EIID_ISchemaFactory);
    }

    static CARAPI_(ISchemaFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISchemaFactory*)pObj->Probe(EIID_ISchemaFactory);
    }

    virtual CARAPI IsSchemaLanguageSupported(
        /* [in] */ const _ELASTOS String& schemaLanguage,
        /* [out] */ _ELASTOS Boolean * state) = 0;

    virtual CARAPI GetFeature(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Boolean * feature) = 0;

    virtual CARAPI SetFeature(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI SetProperty(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI GetProperty(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** property) = 0;

    virtual CARAPI SetErrorHandler(
        /* [in] */ Org::Xml::Sax::IErrorHandler * errorHandler) = 0;

    virtual CARAPI GetErrorHandler(
        /* [out] */ Org::Xml::Sax::IErrorHandler ** errorHandler) = 0;

    virtual CARAPI SetResourceResolver(
        /* [in] */ Org::W3c::Dom::Ls::ILSResourceResolver * resourceResolver) = 0;

    virtual CARAPI GetResourceResolver(
        /* [out] */ Org::W3c::Dom::Ls::ILSResourceResolver ** resourceResolver) = 0;

    virtual CARAPI NewSchema(
        /* [in] */ Elastosx::Xml::Transform::ISource * schema,
        /* [out] */ Elastosx::Xml::Validation::ISchema ** instance) = 0;

    virtual CARAPI NewSchema(
        /* [in] */ Elastos::IO::IFile * schema,
        /* [out] */ Elastosx::Xml::Validation::ISchema ** instance) = 0;

    virtual CARAPI NewSchema(
        /* [in] */ Elastos::Net::IURL * schema,
        /* [out] */ Elastosx::Xml::Validation::ISchema ** instance) = 0;

    virtual CARAPI NewSchema(
        /* [in] */ _ELASTOS ArrayOf<Elastosx::Xml::Transform::ISource *> * schemas,
        /* [out] */ Elastosx::Xml::Validation::ISchema ** instance) = 0;

    virtual CARAPI NewSchema(
        /* [out] */ Elastosx::Xml::Validation::ISchema ** schema) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Validation {
CAR_INTERFACE("D7354338-0712-2B13-50C0-20012D028A17")
ISchemaFactoryHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISchemaFactoryHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISchemaFactoryHelper*)pObj->Probe(EIID_ISchemaFactoryHelper);
    }

    static CARAPI_(ISchemaFactoryHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISchemaFactoryHelper*)pObj->Probe(EIID_ISchemaFactoryHelper);
    }

    virtual CARAPI NewInstance(
        /* [in] */ const _ELASTOS String& schemaLanguage,
        /* [out] */ Elastosx::Xml::Validation::ISchemaFactory ** factory) = 0;

    virtual CARAPI NewInstance(
        /* [in] */ const _ELASTOS String& schemaLanguage,
        /* [in] */ const _ELASTOS String& factoryClassName,
        /* [in] */ Elastos::Core::IClassLoader * classLoader,
        /* [out] */ Elastosx::Xml::Validation::ISchemaFactory ** factory) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Validation {
CAR_INTERFACE("95B1453C-0712-2B13-50C0-2001CDDAFD1F")
ISchemaFactoryFinder : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISchemaFactoryFinder*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISchemaFactoryFinder*)pObj->Probe(EIID_ISchemaFactoryFinder);
    }

    static CARAPI_(ISchemaFactoryFinder*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISchemaFactoryFinder*)pObj->Probe(EIID_ISchemaFactoryFinder);
    }

    virtual CARAPI NewFactory(
        /* [in] */ const _ELASTOS String& schemaLanguage,
        /* [out] */ Elastosx::Xml::Validation::ISchemaFactory ** factory) = 0;

    virtual CARAPI CreateInstance(
        /* [in] */ const _ELASTOS String& className,
        /* [out] */ Elastosx::Xml::Validation::ISchemaFactory ** factory) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Validation {
CAR_INTERFACE("1ABC3735-0712-2B13-50C0-20018DE3FD1F")
ISchemaFactoryLoader : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISchemaFactoryLoader*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISchemaFactoryLoader*)pObj->Probe(EIID_ISchemaFactoryLoader);
    }

    static CARAPI_(ISchemaFactoryLoader*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISchemaFactoryLoader*)pObj->Probe(EIID_ISchemaFactoryLoader);
    }

    virtual CARAPI NewFactory(
        /* [in] */ const _ELASTOS String& schemaLanguage,
        /* [out] */ Elastosx::Xml::Validation::ISchemaFactory ** factory) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Namespace {
CAR_INTERFACE("BB784219-7692-3091-FA3B-2F69DFB2BDFF")
IQName : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IQName*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IQName*)pObj->Probe(EIID_IQName);
    }

    static CARAPI_(IQName*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IQName*)pObj->Probe(EIID_IQName);
    }

    virtual CARAPI GetNamespaceURI(
        /* [out] */ _ELASTOS String * uri) = 0;

    virtual CARAPI GetLocalPart(
        /* [out] */ _ELASTOS String * part) = 0;

    virtual CARAPI GetPrefix(
        /* [out] */ _ELASTOS String * prefix) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Namespace {
CAR_INTERFACE("F1062B26-8692-11A0-50BC-9871FF477B1B")
IQNameHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IQNameHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IQNameHelper*)pObj->Probe(EIID_IQNameHelper);
    }

    static CARAPI_(IQNameHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IQNameHelper*)pObj->Probe(EIID_IQNameHelper);
    }

    virtual CARAPI ValueOf(
        /* [in] */ const _ELASTOS String& qNameAsString,
        /* [out] */ Elastosx::Xml::Namespace::IQName ** name) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Namespace {
CAR_INTERFACE("02C94C55-9752-369D-C082-22A279C78D1F")
INamespaceContext : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INamespaceContext*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INamespaceContext*)pObj->Probe(EIID_INamespaceContext);
    }

    static CARAPI_(INamespaceContext*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INamespaceContext*)pObj->Probe(EIID_INamespaceContext);
    }

    virtual CARAPI GetNamespaceURI(
        /* [in] */ const _ELASTOS String& prefix,
        /* [out] */ _ELASTOS String * uri) = 0;

    virtual CARAPI GetPrefix(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [out] */ _ELASTOS String * perfix) = 0;

    virtual CARAPI GetPrefixes(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [out] */ Elastos::Utility::IIterator ** iterator) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Datatype {
CAR_INTERFACE("E995334E-0352-B246-C312-812CE8868D07")
IDatatypeConstantsField : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDatatypeConstantsField*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatatypeConstantsField*)pObj->Probe(EIID_IDatatypeConstantsField);
    }

    static CARAPI_(IDatatypeConstantsField*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatatypeConstantsField*)pObj->Probe(EIID_IDatatypeConstantsField);
    }

    virtual CARAPI GetId(
        /* [out] */ _ELASTOS Int32 * id) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Datatype {
CAR_INTERFACE("1760FE45-0352-B246-C312-812CE8868D1F")
IDatatypeConstants : public IInterface
{
    static const _ELASTOS Int32 JANUARY = 1;
    static const _ELASTOS Int32 FEBRUARY = 2;
    static const _ELASTOS Int32 MARCH = 3;
    static const _ELASTOS Int32 APRIL = 4;
    static const _ELASTOS Int32 MAY = 5;
    static const _ELASTOS Int32 JUNE = 6;
    static const _ELASTOS Int32 JULY = 7;
    static const _ELASTOS Int32 AUGUST = 8;
    static const _ELASTOS Int32 SEPTEMBER = 9;
    static const _ELASTOS Int32 OCTOBER = 10;
    static const _ELASTOS Int32 NOVEMBER = 11;
    static const _ELASTOS Int32 DECEMBER = 12;
    static const _ELASTOS Int32 LESSER = -1;
    static const _ELASTOS Int32 EQUAL = 0;
    static const _ELASTOS Int32 GREATER = 1;
    static const _ELASTOS Int32 INDETERMINATE = 2;
    static const _ELASTOS Int32 FIELD_UNDEFINED = 0x80000000;
    static const _ELASTOS Int32 MAX_TIMEZONE_OFFSET = -840;
    static const _ELASTOS Int32 MIN_TIMEZONE_OFFSET = 840;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDatatypeConstants*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatatypeConstants*)pObj->Probe(EIID_IDatatypeConstants);
    }

    static CARAPI_(IDatatypeConstants*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatatypeConstants*)pObj->Probe(EIID_IDatatypeConstants);
    }

    virtual CARAPI GetQNameForDATETIME(
        /* [out] */ Elastosx::Xml::Namespace::IQName ** datetime) = 0;

    virtual CARAPI GetQNameForTIME(
        /* [out] */ Elastosx::Xml::Namespace::IQName ** time) = 0;

    virtual CARAPI GetQNameForDATE(
        /* [out] */ Elastosx::Xml::Namespace::IQName ** date) = 0;

    virtual CARAPI GetQNameForGYEARMONTH(
        /* [out] */ Elastosx::Xml::Namespace::IQName ** gyearmonth) = 0;

    virtual CARAPI GetQNameForGMONTHDAY(
        /* [out] */ Elastosx::Xml::Namespace::IQName ** gmonthday) = 0;

    virtual CARAPI GetQNameForGYEAR(
        /* [out] */ Elastosx::Xml::Namespace::IQName ** gyear) = 0;

    virtual CARAPI GetQNameForGMONTH(
        /* [out] */ Elastosx::Xml::Namespace::IQName ** gmonth) = 0;

    virtual CARAPI GetQNameForGDAY(
        /* [out] */ Elastosx::Xml::Namespace::IQName ** gday) = 0;

    virtual CARAPI GetQNameForDURATION(
        /* [out] */ Elastosx::Xml::Namespace::IQName ** duration) = 0;

    virtual CARAPI GetQNameForDURATION_DAYTIME(
        /* [out] */ Elastosx::Xml::Namespace::IQName ** duration_daytime) = 0;

    virtual CARAPI GetQNameForDURATION_YEARMONTH(
        /* [out] */ Elastosx::Xml::Namespace::IQName ** duration_yearmonth) = 0;

    virtual CARAPI GetFieldForYEARS(
        /* [out] */ Elastosx::Xml::Datatype::IDatatypeConstantsField ** years) = 0;

    virtual CARAPI GetFieldForMONTHS(
        /* [out] */ Elastosx::Xml::Datatype::IDatatypeConstantsField ** months) = 0;

    virtual CARAPI GetFieldForDAYS(
        /* [out] */ Elastosx::Xml::Datatype::IDatatypeConstantsField ** days) = 0;

    virtual CARAPI GetFieldForHOURS(
        /* [out] */ Elastosx::Xml::Datatype::IDatatypeConstantsField ** hours) = 0;

    virtual CARAPI GetFieldForMINUTES(
        /* [out] */ Elastosx::Xml::Datatype::IDatatypeConstantsField ** minutes) = 0;

    virtual CARAPI GetFieldForSECONDS(
        /* [out] */ Elastosx::Xml::Datatype::IDatatypeConstantsField ** seconds) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Datatype {
CAR_INTERFACE("CF09EE5F-0352-8EDE-7E38-2829C3C68E1F")
IDuration : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDuration*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDuration*)pObj->Probe(EIID_IDuration);
    }

    static CARAPI_(IDuration*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDuration*)pObj->Probe(EIID_IDuration);
    }

    virtual CARAPI GetXMLSchemaType(
        /* [out] */ Elastosx::Xml::Namespace::IQName ** type) = 0;

    virtual CARAPI GetSign(
        /* [out] */ _ELASTOS Int32 * sign) = 0;

    virtual CARAPI GetYears(
        /* [out] */ _ELASTOS Int32 * years) = 0;

    virtual CARAPI GetMonths(
        /* [out] */ _ELASTOS Int32 * months) = 0;

    virtual CARAPI GetDays(
        /* [out] */ _ELASTOS Int32 * days) = 0;

    virtual CARAPI GetHours(
        /* [out] */ _ELASTOS Int32 * hours) = 0;

    virtual CARAPI GetMinutes(
        /* [out] */ _ELASTOS Int32 * minutes) = 0;

    virtual CARAPI GetSeconds(
        /* [out] */ _ELASTOS Int32 * seconds) = 0;

    virtual CARAPI GetTimeInMillis(
        /* [in] */ Elastos::Utility::ICalendar * startInstant,
        /* [out] */ _ELASTOS Int64 * time) = 0;

    virtual CARAPI GetTimeInMillis(
        /* [in] */ Elastos::Utility::IDate * startInstant,
        /* [out] */ _ELASTOS Int64 * time) = 0;

    virtual CARAPI GetField(
        /* [in] */ Elastosx::Xml::Datatype::IDatatypeConstantsField * filed,
        /* [out] */ Elastos::Core::INumber ** rst) = 0;

    virtual CARAPI IsSet(
        /* [in] */ Elastosx::Xml::Datatype::IDatatypeConstantsField * field,
        /* [out] */ _ELASTOS Boolean * time) = 0;

    virtual CARAPI Add(
        /* [in] */ Elastosx::Xml::Datatype::IDuration * rhs,
        /* [out] */ Elastosx::Xml::Datatype::IDuration ** duration) = 0;

    virtual CARAPI AddTo(
        /* [in] */ Elastos::Utility::ICalendar * calendar) = 0;

    virtual CARAPI AddTo(
        /* [in] */ Elastos::Utility::IDate * date) = 0;

    virtual CARAPI Subtract(
        /* [in] */ Elastosx::Xml::Datatype::IDuration * rhs,
        /* [out] */ Elastosx::Xml::Datatype::IDuration ** duration) = 0;

    virtual CARAPI Multiply(
        /* [in] */ _ELASTOS Int32 factor,
        /* [out] */ Elastosx::Xml::Datatype::IDuration ** duration) = 0;

    virtual CARAPI Multiply(
        /* [in] */ Elastos::Math::IBigDecimal * factor,
        /* [out] */ Elastosx::Xml::Datatype::IDuration ** duration) = 0;

    virtual CARAPI Negate(
        /* [out] */ Elastosx::Xml::Datatype::IDuration ** duration) = 0;

    virtual CARAPI NormalizeWith(
        /* [in] */ Elastos::Utility::ICalendar * startTimeInstant,
        /* [out] */ Elastosx::Xml::Datatype::IDuration ** duration) = 0;

    virtual CARAPI Compare(
        /* [in] */ Elastosx::Xml::Datatype::IDuration * duration,
        /* [out] */ _ELASTOS Int32 * rst) = 0;

    virtual CARAPI IsLongerThan(
        /* [in] */ Elastosx::Xml::Datatype::IDuration * rhs,
        /* [out] */ _ELASTOS Boolean * rst) = 0;

    virtual CARAPI IsShorterThan(
        /* [in] */ Elastosx::Xml::Datatype::IDuration * rhs,
        /* [out] */ _ELASTOS Boolean * rst) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Datatype {
CAR_INTERFACE("4ECEF846-0852-150B-20E0-8DA75710833F")
IXMLGregorianCalendar : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IXMLGregorianCalendar*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXMLGregorianCalendar*)pObj->Probe(EIID_IXMLGregorianCalendar);
    }

    static CARAPI_(IXMLGregorianCalendar*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXMLGregorianCalendar*)pObj->Probe(EIID_IXMLGregorianCalendar);
    }

    virtual CARAPI Clear() = 0;

    virtual CARAPI Reset() = 0;

    virtual CARAPI SetYear(
        /* [in] */ Elastos::Math::IBigInteger * year) = 0;

    virtual CARAPI SetYear(
        /* [in] */ _ELASTOS Int32 year) = 0;

    virtual CARAPI SetMonth(
        /* [in] */ _ELASTOS Int32 month) = 0;

    virtual CARAPI SetDay(
        /* [in] */ _ELASTOS Int32 day) = 0;

    virtual CARAPI SetTimezone(
        /* [in] */ _ELASTOS Int32 offset) = 0;

    virtual CARAPI SetTime(
        /* [in] */ _ELASTOS Int32 hour,
        /* [in] */ _ELASTOS Int32 minute,
        /* [in] */ _ELASTOS Int32 second) = 0;

    virtual CARAPI SetHour(
        /* [in] */ _ELASTOS Int32 hour) = 0;

    virtual CARAPI SetMinute(
        /* [in] */ _ELASTOS Int32 minute) = 0;

    virtual CARAPI SetSecond(
        /* [in] */ _ELASTOS Int32 second) = 0;

    virtual CARAPI SetMillisecond(
        /* [in] */ _ELASTOS Int32 millisecond) = 0;

    virtual CARAPI SetFractionalSecond(
        /* [in] */ Elastos::Math::IBigDecimal * year) = 0;

    virtual CARAPI SetTime(
        /* [in] */ _ELASTOS Int32 hour,
        /* [in] */ _ELASTOS Int32 minute,
        /* [in] */ _ELASTOS Int32 second,
        /* [in] */ Elastos::Math::IBigDecimal * fractional) = 0;

    virtual CARAPI SetTime(
        /* [in] */ _ELASTOS Int32 hour,
        /* [in] */ _ELASTOS Int32 minute,
        /* [in] */ _ELASTOS Int32 second,
        /* [in] */ _ELASTOS Int32 millisecond) = 0;

    virtual CARAPI GetEon(
        /* [out] */ Elastos::Math::IBigInteger ** eon) = 0;

    virtual CARAPI GetYear(
        /* [out] */ _ELASTOS Int32 * eon) = 0;

    virtual CARAPI GetEonAndYear(
        /* [out] */ Elastos::Math::IBigInteger ** eon) = 0;

    virtual CARAPI GetMonth(
        /* [out] */ _ELASTOS Int32 * month) = 0;

    virtual CARAPI GetDay(
        /* [out] */ _ELASTOS Int32 * day) = 0;

    virtual CARAPI GetTimezone(
        /* [out] */ _ELASTOS Int32 * timezone) = 0;

    virtual CARAPI GetHour(
        /* [out] */ _ELASTOS Int32 * hour) = 0;

    virtual CARAPI GetMinute(
        /* [out] */ _ELASTOS Int32 * minute) = 0;

    virtual CARAPI GetSecond(
        /* [out] */ _ELASTOS Int32 * second) = 0;

    virtual CARAPI GetMillisecond(
        /* [out] */ _ELASTOS Int32 * millisecond) = 0;

    virtual CARAPI GetFractionalSecond(
        /* [out] */ Elastos::Math::IBigDecimal ** second) = 0;

    virtual CARAPI Compare(
        /* [in] */ Elastosx::Xml::Datatype::IXMLGregorianCalendar * xmlGregorianCalendar,
        /* [out] */ _ELASTOS Int32 * minute) = 0;

    virtual CARAPI Normalize(
        /* [out] */ Elastosx::Xml::Datatype::IXMLGregorianCalendar ** xmlGregorianCalendar) = 0;

    virtual CARAPI ToXMLFormat(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetXMLSchemaType(
        /* [out] */ Elastosx::Xml::Namespace::IQName ** qName) = 0;

    virtual CARAPI IsValid(
        /* [out] */ _ELASTOS Boolean * str) = 0;

    virtual CARAPI Add(
        /* [in] */ Elastosx::Xml::Datatype::IDuration * duration) = 0;

    virtual CARAPI ToGregorianCalendar(
        /* [out] */ Elastos::Utility::IGregorianCalendar ** cdr) = 0;

    virtual CARAPI ToGregorianCalendar(
        /* [in] */ Elastos::Utility::ITimeZone * timezone,
        /* [in] */ Elastos::Utility::ILocale * aLocale,
        /* [in] */ Elastosx::Xml::Datatype::IXMLGregorianCalendar * defaults,
        /* [out] */ Elastos::Utility::IGregorianCalendar ** cdr) = 0;

    virtual CARAPI GetTimeZone(
        /* [in] */ _ELASTOS Int32 defaultZoneoffset,
        /* [in] */ Elastos::Utility::ITimeZone * timezone) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Datatype {
CAR_INTERFACE("6714EB25-A612-3C1B-66A0-80F6A3BD8D1B")
IDatatypeFactory : public IInterface
{
    static const _ELASTOS String DATATYPEFACTORY_PROPERTY;
    static const _ELASTOS String DATATYPEFACTORY_IMPLEMENTATION_CLASS;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDatatypeFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatatypeFactory*)pObj->Probe(EIID_IDatatypeFactory);
    }

    static CARAPI_(IDatatypeFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatatypeFactory*)pObj->Probe(EIID_IDatatypeFactory);
    }

    virtual CARAPI NewDuration(
        /* [in] */ const _ELASTOS String& lexicalRepresentation,
        /* [out] */ Elastosx::Xml::Datatype::IDuration ** duration) = 0;

    virtual CARAPI NewDuration(
        /* [in] */ _ELASTOS Int64 durationInMilliSeconds,
        /* [out] */ Elastosx::Xml::Datatype::IDuration ** duration) = 0;

    virtual CARAPI NewDuration(
        /* [in] */ _ELASTOS Boolean isPositive,
        /* [in] */ Elastos::Math::IBigInteger * years,
        /* [in] */ Elastos::Math::IBigInteger * months,
        /* [in] */ Elastos::Math::IBigInteger * days,
        /* [in] */ Elastos::Math::IBigInteger * hours,
        /* [in] */ Elastos::Math::IBigInteger * minutes,
        /* [in] */ Elastos::Math::IBigDecimal * seconds,
        /* [out] */ Elastosx::Xml::Datatype::IDuration ** duration) = 0;

    virtual CARAPI NewDuration(
        /* [in] */ _ELASTOS Boolean isPositive,
        /* [in] */ _ELASTOS Int32 years,
        /* [in] */ _ELASTOS Int32 months,
        /* [in] */ _ELASTOS Int32 days,
        /* [in] */ _ELASTOS Int32 hours,
        /* [in] */ _ELASTOS Int32 minutes,
        /* [in] */ _ELASTOS Int32 seconds,
        /* [out] */ Elastosx::Xml::Datatype::IDuration ** duration) = 0;

    virtual CARAPI NewDurationDayTime(
        /* [in] */ const _ELASTOS String& lexicalRepresentation,
        /* [out] */ Elastosx::Xml::Datatype::IDuration ** duration) = 0;

    virtual CARAPI NewDurationDayTime(
        /* [in] */ _ELASTOS Int64 durationInMilliseconds,
        /* [out] */ Elastosx::Xml::Datatype::IDuration ** duration) = 0;

    virtual CARAPI NewDurationDayTime(
        /* [in] */ _ELASTOS Boolean isPositive,
        /* [in] */ Elastos::Math::IBigInteger * day,
        /* [in] */ Elastos::Math::IBigInteger * hour,
        /* [in] */ Elastos::Math::IBigInteger * minute,
        /* [in] */ Elastos::Math::IBigInteger * second,
        /* [out] */ Elastosx::Xml::Datatype::IDuration ** duration) = 0;

    virtual CARAPI NewDurationDayTime(
        /* [in] */ _ELASTOS Boolean isPositive,
        /* [in] */ _ELASTOS Int32 day,
        /* [in] */ _ELASTOS Int32 hour,
        /* [in] */ _ELASTOS Int32 minute,
        /* [in] */ _ELASTOS Int32 second,
        /* [out] */ Elastosx::Xml::Datatype::IDuration ** duration) = 0;

    virtual CARAPI NewDurationYearMonth(
        /* [in] */ const _ELASTOS String& lexicalRepresentation,
        /* [out] */ Elastosx::Xml::Datatype::IDuration ** duration) = 0;

    virtual CARAPI NewDurationYearMonth(
        /* [in] */ _ELASTOS Int64 durationInMilliseconds,
        /* [out] */ Elastosx::Xml::Datatype::IDuration ** duration) = 0;

    virtual CARAPI NewDurationYearMonth(
        /* [in] */ _ELASTOS Boolean isPositive,
        /* [in] */ Elastos::Math::IBigInteger * year,
        /* [in] */ Elastos::Math::IBigInteger * month,
        /* [out] */ Elastosx::Xml::Datatype::IDuration ** duration) = 0;

    virtual CARAPI NewDurationYearMonth(
        /* [in] */ _ELASTOS Boolean isPositive,
        /* [in] */ _ELASTOS Int32 year,
        /* [in] */ _ELASTOS Int32 month,
        /* [out] */ Elastosx::Xml::Datatype::IDuration ** duration) = 0;

    virtual CARAPI NewXMLGregorianCalendar(
        /* [out] */ Elastosx::Xml::Datatype::IXMLGregorianCalendar ** rst) = 0;

    virtual CARAPI NewXMLGregorianCalendar(
        /* [in] */ const _ELASTOS String& lexicalRepresentation,
        /* [out] */ Elastosx::Xml::Datatype::IXMLGregorianCalendar ** rst) = 0;

    virtual CARAPI NewXMLGregorianCalendar(
        /* [in] */ Elastos::Utility::IGregorianCalendar * cal,
        /* [out] */ Elastosx::Xml::Datatype::IXMLGregorianCalendar ** rst) = 0;

    virtual CARAPI NewXMLGregorianCalendar(
        /* [in] */ Elastos::Math::IBigInteger * year,
        /* [in] */ _ELASTOS Int32 month,
        /* [in] */ _ELASTOS Int32 day,
        /* [in] */ _ELASTOS Int32 hour,
        /* [in] */ _ELASTOS Int32 minute,
        /* [in] */ _ELASTOS Int32 second,
        /* [in] */ Elastos::Math::IBigDecimal * fractionalSecond,
        /* [in] */ _ELASTOS Int32 timezone,
        /* [out] */ Elastosx::Xml::Datatype::IXMLGregorianCalendar ** rst) = 0;

    virtual CARAPI NewXMLGregorianCalendar(
        /* [in] */ _ELASTOS Int32 year,
        /* [in] */ _ELASTOS Int32 month,
        /* [in] */ _ELASTOS Int32 day,
        /* [in] */ _ELASTOS Int32 hour,
        /* [in] */ _ELASTOS Int32 minute,
        /* [in] */ _ELASTOS Int32 second,
        /* [in] */ _ELASTOS Int32 millisecond,
        /* [in] */ _ELASTOS Int32 timezone,
        /* [out] */ Elastosx::Xml::Datatype::IXMLGregorianCalendar ** rst) = 0;

    virtual CARAPI NewXMLGregorianCalendarDate(
        /* [in] */ _ELASTOS Int32 year,
        /* [in] */ _ELASTOS Int32 month,
        /* [in] */ _ELASTOS Int32 day,
        /* [in] */ _ELASTOS Int32 timezone,
        /* [out] */ Elastosx::Xml::Datatype::IXMLGregorianCalendar ** rst) = 0;

    virtual CARAPI NewXMLGregorianCalendarTime(
        /* [in] */ _ELASTOS Int32 hours,
        /* [in] */ _ELASTOS Int32 minutes,
        /* [in] */ _ELASTOS Int32 seconds,
        /* [in] */ _ELASTOS Int32 timezone,
        /* [out] */ Elastosx::Xml::Datatype::IXMLGregorianCalendar ** rst) = 0;

    virtual CARAPI NewXMLGregorianCalendarTime(
        /* [in] */ _ELASTOS Int32 hours,
        /* [in] */ _ELASTOS Int32 minutes,
        /* [in] */ _ELASTOS Int32 seconds,
        /* [in] */ Elastos::Math::IBigDecimal * fractionalSecond,
        /* [in] */ _ELASTOS Int32 timezone,
        /* [out] */ Elastosx::Xml::Datatype::IXMLGregorianCalendar ** rst) = 0;

    virtual CARAPI NewXMLGregorianCalendarTime(
        /* [in] */ _ELASTOS Int32 hours,
        /* [in] */ _ELASTOS Int32 minutes,
        /* [in] */ _ELASTOS Int32 seconds,
        /* [in] */ _ELASTOS Int32 milliseconds,
        /* [in] */ _ELASTOS Int32 timezone,
        /* [out] */ Elastosx::Xml::Datatype::IXMLGregorianCalendar ** rst) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Datatype {
CAR_INTERFACE("C52B432C-A612-3C1B-66A0-801601C58B19")
IDatatypeFactoryHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDatatypeFactoryHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatatypeFactoryHelper*)pObj->Probe(EIID_IDatatypeFactoryHelper);
    }

    static CARAPI_(IDatatypeFactoryHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatatypeFactoryHelper*)pObj->Probe(EIID_IDatatypeFactoryHelper);
    }

    virtual CARAPI NewInstance(
        /* [out] */ Elastosx::Xml::Datatype::IDatatypeFactory ** instance) = 0;

    virtual CARAPI NewInstance(
        /* [in] */ const _ELASTOS String& factoryClassName,
        /* [in] */ Elastos::Core::IClassLoader * classLoader,
        /* [out] */ Elastosx::Xml::Datatype::IDatatypeFactory ** instance) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
CAR_INTERFACE("11712338-D492-3686-7EB4-B77143868D1D")
IOutputKeys : public IInterface
{
    static const _ELASTOS String METHOD;
    static const _ELASTOS String VERSION;
    static const _ELASTOS String ENCODING;
    static const _ELASTOS String OMIT_XML_DECLARATION;
    static const _ELASTOS String STANDALONE;
    static const _ELASTOS String DOCTYPE_PUBLIC;
    static const _ELASTOS String DOCTYPE_SYSTEM;
    static const _ELASTOS String CDATA_SECTION_ELEMENTS;
    static const _ELASTOS String INDENT;
    static const _ELASTOS String MEDIA_TYPE;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IOutputKeys*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IOutputKeys*)pObj->Probe(EIID_IOutputKeys);
    }

    static CARAPI_(IOutputKeys*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IOutputKeys*)pObj->Probe(EIID_IOutputKeys);
    }

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
CAR_INTERFACE("4633352C-E1D2-ED1F-6DDC-906163C78F10")
IResult : public IInterface
{
    static const _ELASTOS String PI_DISABLE_OUTPUT_ESCAPING;
    static const _ELASTOS String PI_ENABLE_OUTPUT_ESCAPING;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IResult*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IResult*)pObj->Probe(EIID_IResult);
    }

    static CARAPI_(IResult*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IResult*)pObj->Probe(EIID_IResult);
    }

    virtual CARAPI SetSystemId(
        /* [in] */ const _ELASTOS String& systemId) = 0;

    virtual CARAPI GetSystemId(
        /* [out] */ _ELASTOS String * systemId) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
CAR_INTERFACE("4C3B352B-E992-ED1F-6DDC-906163C78F10")
ISource : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISource*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISource*)pObj->Probe(EIID_ISource);
    }

    static CARAPI_(ISource*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISource*)pObj->Probe(EIID_ISource);
    }

    virtual CARAPI SetSystemId(
        /* [in] */ const _ELASTOS String& systemId) = 0;

    virtual CARAPI GetSystemId(
        /* [out] */ _ELASTOS String * systemId) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
CAR_INTERFACE("1AB55856-8712-A0AD-2AC8-E874FA878392")
ISourceLocator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISourceLocator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISourceLocator*)pObj->Probe(EIID_ISourceLocator);
    }

    static CARAPI_(ISourceLocator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISourceLocator*)pObj->Probe(EIID_ISourceLocator);
    }

    virtual CARAPI GetPublicId(
        /* [out] */ _ELASTOS String * id) = 0;

    virtual CARAPI GetSystemId(
        /* [out] */ _ELASTOS String * id) = 0;

    virtual CARAPI GetLineNumber(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI GetColumnNumber(
        /* [out] */ _ELASTOS Int32 * number) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
CAR_INTERFACE("B1D82B04-B792-1B49-6ACB-6F8ED6BFF392")
IURIResolver : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IURIResolver*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IURIResolver*)pObj->Probe(EIID_IURIResolver);
    }

    static CARAPI_(IURIResolver*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IURIResolver*)pObj->Probe(EIID_IURIResolver);
    }

    virtual CARAPI Resolve(
        /* [in] */ const _ELASTOS String& href,
        /* [in] */ const _ELASTOS String& base,
        /* [out] */ Elastosx::Xml::Transform::ISource ** source) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
CAR_INTERFACE("5676DD59-1C52-3641-BCD5-D859E3878392")
ITransformer : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITransformer*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITransformer*)pObj->Probe(EIID_ITransformer);
    }

    static CARAPI_(ITransformer*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITransformer*)pObj->Probe(EIID_ITransformer);
    }

    virtual CARAPI Reset() = 0;

    virtual CARAPI Transform(
        /* [in] */ Elastosx::Xml::Transform::ISource * xmlSource,
        /* [in] */ Elastosx::Xml::Transform::IResult * outputTarget) = 0;

    virtual CARAPI SetParameter(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI GetParameter(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI ClearParameters() = 0;

    virtual CARAPI SetURIResolver(
        /* [in] */ Elastosx::Xml::Transform::IURIResolver * resolver) = 0;

    virtual CARAPI GetURIResolver(
        /* [out] */ Elastosx::Xml::Transform::IURIResolver ** resolver) = 0;

    virtual CARAPI SetOutputProperties(
        /* [in] */ Elastos::Utility::IProperties * oformat) = 0;

    virtual CARAPI GetOutputProperties(
        /* [out] */ Elastos::Utility::IProperties ** oformat) = 0;

    virtual CARAPI SetOutputProperty(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI GetOutputProperty(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS String * property) = 0;

    virtual CARAPI SetErrorListener(
        /* [in] */ Elastosx::Xml::Transform::IErrorListener * listener) = 0;

    virtual CARAPI GetErrorListener(
        /* [out] */ Elastosx::Xml::Transform::IErrorListener ** listener) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
CAR_INTERFACE("B99E430D-8752-F3C2-4BDE-A8FD3B2F69DF")
ITemplates : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITemplates*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITemplates*)pObj->Probe(EIID_ITemplates);
    }

    static CARAPI_(ITemplates*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITemplates*)pObj->Probe(EIID_ITemplates);
    }

    virtual CARAPI NewTransformer(
        /* [out] */ Elastosx::Xml::Transform::ITransformer ** transformer) = 0;

    virtual CARAPI GetOutputProperties(
        /* [out] */ Elastos::Utility::IProperties ** properties) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
CAR_INTERFACE("30D5B22E-8752-241A-62D8-48911FC67D68")
ITransformerFactory : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITransformerFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITransformerFactory*)pObj->Probe(EIID_ITransformerFactory);
    }

    static CARAPI_(ITransformerFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITransformerFactory*)pObj->Probe(EIID_ITransformerFactory);
    }

    virtual CARAPI NewTransformer(
        /* [in] */ Elastosx::Xml::Transform::ISource * source,
        /* [out] */ Elastosx::Xml::Transform::ITransformer ** transformer) = 0;

    virtual CARAPI NewTransformer(
        /* [out] */ Elastosx::Xml::Transform::ITransformer ** transformer) = 0;

    virtual CARAPI NewTemplates(
        /* [in] */ Elastosx::Xml::Transform::ISource * source,
        /* [out] */ Elastosx::Xml::Transform::ITemplates ** transformer) = 0;

    virtual CARAPI GetAssociatedStylesheet(
        /* [in] */ Elastosx::Xml::Transform::ISource * source,
        /* [in] */ const _ELASTOS String& media,
        /* [in] */ const _ELASTOS String& title,
        /* [in] */ const _ELASTOS String& charset,
        /* [out] */ Elastosx::Xml::Transform::ISource ** heet) = 0;

    virtual CARAPI SetURIResolver(
        /* [in] */ Elastosx::Xml::Transform::IURIResolver * resolver) = 0;

    virtual CARAPI GetURIResolver(
        /* [out] */ Elastosx::Xml::Transform::IURIResolver ** resolver) = 0;

    virtual CARAPI SetFeature(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI GetFeature(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI SetAttribute(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI GetAttribute(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** attribute) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
CAR_INTERFACE("9B7C472D-8752-241A-62D8-48911FC67D68")
ITransformerFactoryHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITransformerFactoryHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITransformerFactoryHelper*)pObj->Probe(EIID_ITransformerFactoryHelper);
    }

    static CARAPI_(ITransformerFactoryHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITransformerFactoryHelper*)pObj->Probe(EIID_ITransformerFactoryHelper);
    }

    virtual CARAPI NewInstance(
        /* [out] */ Elastosx::Xml::Transform::ITransformerFactory ** factory) = 0;

    virtual CARAPI NewInstance(
        /* [in] */ const _ELASTOS String& factoryClassName,
        /* [in] */ Elastos::Core::IClassLoader * classLoader,
        /* [out] */ Elastosx::Xml::Transform::ITransformerFactory ** factory) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
CAR_INTERFACE("80033C2A-B2D2-F78C-7FB4-B77143868D1D")
IErrorListener : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IErrorListener*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IErrorListener*)pObj->Probe(EIID_IErrorListener);
    }

    static CARAPI_(IErrorListener*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IErrorListener*)pObj->Probe(EIID_IErrorListener);
    }

    virtual CARAPI Warning() = 0;

    virtual CARAPI Error() = 0;

    virtual CARAPI FatalError() = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
namespace Dom {
CAR_INTERFACE("BCC73952-0352-160C-2AC8-E874FA878392")
IDOMLocator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDOMLocator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMLocator*)pObj->Probe(EIID_IDOMLocator);
    }

    static CARAPI_(IDOMLocator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMLocator*)pObj->Probe(EIID_IDOMLocator);
    }

    virtual CARAPI GetOriginatingNode(
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

};
}
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
namespace Dom {
CAR_INTERFACE("C28A2D2F-0352-160C-0EFF-686FE3860C1B")
IDOMResult : public IInterface
{
    static const _ELASTOS String FEATURE;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDOMResult*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMResult*)pObj->Probe(EIID_IDOMResult);
    }

    static CARAPI_(IDOMResult*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMResult*)pObj->Probe(EIID_IDOMResult);
    }

    virtual CARAPI SetNode(
        /* [in] */ Org::W3c::Dom::INode * node) = 0;

};
}
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
namespace Dom {
CAR_INTERFACE("9F133423-0352-160C-4CFF-686FE3860C1B")
IDOMSource : public IInterface
{
    static const _ELASTOS String FEATURE;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDOMSource*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMSource*)pObj->Probe(EIID_IDOMSource);
    }

    static CARAPI_(IDOMSource*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMSource*)pObj->Probe(EIID_IDOMSource);
    }

    virtual CARAPI SetNode(
        /* [in] */ Org::W3c::Dom::INode * node) = 0;

    virtual CARAPI GetNode(
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

};
}
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
namespace Sax {
CAR_INTERFACE("97295C26-0712-2105-0EFF-686FE3860C1B")
ISAXResult : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISAXResult*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISAXResult*)pObj->Probe(EIID_ISAXResult);
    }

    static CARAPI_(ISAXResult*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISAXResult*)pObj->Probe(EIID_ISAXResult);
    }

    virtual CARAPI SetHandler(
        /* [in] */ Org::Xml::Sax::IContentHandler * handler) = 0;

    virtual CARAPI GetHandler(
        /* [out] */ Org::Xml::Sax::IContentHandler ** handler) = 0;

    virtual CARAPI SetLexicalHandler(
        /* [in] */ Org::Xml::Sax::Ext::ILexicalHandler * handler) = 0;

    virtual CARAPI GetLexicalHandler(
        /* [out] */ Org::Xml::Sax::Ext::ILexicalHandler ** handler) = 0;

};
}
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
namespace Sax {
CAR_INTERFACE("F9C75A2B-0712-2105-4CFF-686FE3860C1B")
ISAXSource : public IInterface
{
    static const _ELASTOS String FEATURE;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISAXSource*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISAXSource*)pObj->Probe(EIID_ISAXSource);
    }

    static CARAPI_(ISAXSource*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISAXSource*)pObj->Probe(EIID_ISAXSource);
    }

    virtual CARAPI SetXMLReader(
        /* [in] */ Org::Xml::Sax::IXMLReader * reader) = 0;

    virtual CARAPI GetXMLReader(
        /* [out] */ Org::Xml::Sax::IXMLReader ** reader) = 0;

    virtual CARAPI SetInputSource(
        /* [in] */ Org::Xml::Sax::IInputSource * inputSource) = 0;

    virtual CARAPI GetInputSource(
        /* [out] */ Org::Xml::Sax::IInputSource ** inputSource) = 0;

};
}
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
namespace Sax {
CAR_INTERFACE("13454F3F-0752-3014-66BC-207103FFB91F")
ITemplatesHandler : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITemplatesHandler*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITemplatesHandler*)pObj->Probe(EIID_ITemplatesHandler);
    }

    static CARAPI_(ITemplatesHandler*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITemplatesHandler*)pObj->Probe(EIID_ITemplatesHandler);
    }

    virtual CARAPI GetTemplates(
        /* [out] */ Elastosx::Xml::Transform::ITemplates ** templates) = 0;

    virtual CARAPI SetSystemId(
        /* [in] */ const _ELASTOS String& systemID) = 0;

    virtual CARAPI GetSystemId(
        /* [out] */ _ELASTOS String * systemID) = 0;

};
}
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
namespace Sax {
CAR_INTERFACE("845B5C25-8752-241A-62D8-48911FC6FD73")
ITransformerHandler : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITransformerHandler*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITransformerHandler*)pObj->Probe(EIID_ITransformerHandler);
    }

    static CARAPI_(ITransformerHandler*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITransformerHandler*)pObj->Probe(EIID_ITransformerHandler);
    }

    virtual CARAPI SetResult(
        /* [in] */ Elastosx::Xml::Transform::IResult * result) = 0;

    virtual CARAPI SetSystemId(
        /* [in] */ const _ELASTOS String& systemID) = 0;

    virtual CARAPI GetSystemId(
        /* [out] */ _ELASTOS String * systemID) = 0;

    virtual CARAPI GetTransformer(
        /* [out] */ Elastosx::Xml::Transform::ITransformer ** transformer) = 0;

};
}
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
namespace Sax {
CAR_INTERFACE("982C9C04-A712-5D84-4DC6-762AD7305A3F")
ISAXTransformerFactory : public IInterface
{
    static const _ELASTOS String FEATURE;
    static const _ELASTOS String FEATURE_XMLFILTER;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISAXTransformerFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISAXTransformerFactory*)pObj->Probe(EIID_ISAXTransformerFactory);
    }

    static CARAPI_(ISAXTransformerFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISAXTransformerFactory*)pObj->Probe(EIID_ISAXTransformerFactory);
    }

    virtual CARAPI NewTransformerHandler(
        /* [in] */ Elastosx::Xml::Transform::ISource * src,
        /* [out] */ Elastosx::Xml::Transform::Sax::ITransformerHandler ** handler) = 0;

    virtual CARAPI NewTransformerHandler(
        /* [in] */ Elastosx::Xml::Transform::ITemplates * templates,
        /* [out] */ Elastosx::Xml::Transform::Sax::ITransformerHandler ** handler) = 0;

    virtual CARAPI NewTransformerHandler(
        /* [out] */ Elastosx::Xml::Transform::Sax::ITransformerHandler ** handler) = 0;

    virtual CARAPI NewTemplatesHandler(
        /* [out] */ Elastosx::Xml::Transform::Sax::ITemplatesHandler ** handler) = 0;

    virtual CARAPI NewXMLFilter(
        /* [in] */ Elastosx::Xml::Transform::ISource * src,
        /* [out] */ Org::Xml::Sax::IXMLFilter ** handler) = 0;

    virtual CARAPI NewXMLFilter(
        /* [in] */ Elastosx::Xml::Transform::ITemplates * templates,
        /* [out] */ Org::Xml::Sax::IXMLFilter ** handler) = 0;

};
}
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
namespace Stream {
CAR_INTERFACE("A8563938-B512-C6AC-3D6C-90F0A3BD8D1B")
IFilePathToURI : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFilePathToURI*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFilePathToURI*)pObj->Probe(EIID_IFilePathToURI);
    }

    static CARAPI_(IFilePathToURI*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFilePathToURI*)pObj->Probe(EIID_IFilePathToURI);
    }

    virtual CARAPI Filepath2URI(
        /* [in] */ const _ELASTOS String& path,
        /* [out] */ _ELASTOS String * uri) = 0;

};
}
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
namespace Stream {
CAR_INTERFACE("29437D31-6C92-2414-601C-FED1DEC60D19")
IStreamResult : public IInterface
{
    static const _ELASTOS String FEATURE;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IStreamResult*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStreamResult*)pObj->Probe(EIID_IStreamResult);
    }

    static CARAPI_(IStreamResult*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStreamResult*)pObj->Probe(EIID_IStreamResult);
    }

    virtual CARAPI SetOutputStream(
        /* [in] */ Elastos::IO::IOutputStream * outputStream) = 0;

    virtual CARAPI GetOutputStream(
        /* [out] */ Elastos::IO::IOutputStream ** outputStream) = 0;

    virtual CARAPI SetWriter(
        /* [in] */ Elastos::IO::IWriter * writer) = 0;

    virtual CARAPI GetWriter(
        /* [out] */ Elastos::IO::IWriter ** writer) = 0;

    virtual CARAPI SetSystemId(
        /* [in] */ const _ELASTOS String& systemId) = 0;

    virtual CARAPI SetSystemId(
        /* [in] */ Elastos::IO::IFile * f) = 0;

    virtual CARAPI GetSystemId(
        /* [out] */ _ELASTOS String * id) = 0;

};
}
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
namespace Stream {
CAR_INTERFACE("A2C29127-6C92-2414-6098-FED1DEC60D19")
IStreamSource : public IInterface
{
    static const _ELASTOS String FEATURE;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IStreamSource*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStreamSource*)pObj->Probe(EIID_IStreamSource);
    }

    static CARAPI_(IStreamSource*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStreamSource*)pObj->Probe(EIID_IStreamSource);
    }

    virtual CARAPI SetInputStream(
        /* [in] */ Elastos::IO::IInputStream * inputStream) = 0;

    virtual CARAPI GetInputStream(
        /* [out] */ Elastos::IO::IInputStream ** inputStream) = 0;

    virtual CARAPI SetReader(
        /* [in] */ Elastos::IO::IReader * reader) = 0;

    virtual CARAPI GetReader(
        /* [out] */ Elastos::IO::IReader ** reader) = 0;

    virtual CARAPI SetPublicId(
        /* [in] */ const _ELASTOS String& publicId) = 0;

    virtual CARAPI GetPublicId(
        /* [out] */ _ELASTOS String * publicId) = 0;

    virtual CARAPI SetSystemId(
        /* [in] */ const _ELASTOS String& systemId) = 0;

    virtual CARAPI GetSystemId(
        /* [out] */ _ELASTOS String * systemId) = 0;

    virtual CARAPI SetSystemId(
        /* [in] */ Elastos::IO::IFile * f) = 0;

};
}
}
}
}
namespace Elastosx {
namespace Xml {
namespace XPath {
CAR_INTERFACE("40FA691A-9852-F791-CAC8-B17D93F16DFF")
IXPathConstants : public IInterface
{
    static const _ELASTOS String DOM_OBJECT_MODEL;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IXPathConstants*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXPathConstants*)pObj->Probe(EIID_IXPathConstants);
    }

    static CARAPI_(IXPathConstants*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXPathConstants*)pObj->Probe(EIID_IXPathConstants);
    }

    virtual CARAPI GetQNameNUMBER(
        /* [out] */ Elastosx::Xml::Namespace::IQName ** qName) = 0;

    virtual CARAPI GetQNameSTRING(
        /* [out] */ Elastosx::Xml::Namespace::IQName ** qName) = 0;

    virtual CARAPI GetQNameBOOLEAN(
        /* [out] */ Elastosx::Xml::Namespace::IQName ** qName) = 0;

    virtual CARAPI GetQNameNODESET(
        /* [out] */ Elastosx::Xml::Namespace::IQName ** qName) = 0;

    virtual CARAPI GetQNameNODE(
        /* [out] */ Elastosx::Xml::Namespace::IQName ** qName) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace XPath {
CAR_INTERFACE("B4D34432-8852-CFAC-66D4-C01FFF477B1B")
IXPathExpression : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IXPathExpression*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXPathExpression*)pObj->Probe(EIID_IXPathExpression);
    }

    static CARAPI_(IXPathExpression*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXPathExpression*)pObj->Probe(EIID_IXPathExpression);
    }

    virtual CARAPI Evaluate(
        /* [in] */ IInterface * item,
        /* [in] */ Elastosx::Xml::Namespace::IQName * returnType,
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI Evaluate(
        /* [in] */ IInterface * item,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI Evaluate(
        /* [in] */ Org::Xml::Sax::IInputSource * source,
        /* [in] */ Elastosx::Xml::Namespace::IQName * returnType,
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI Evaluate(
        /* [in] */ Org::Xml::Sax::IInputSource * source,
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace XPath {
CAR_INTERFACE("36EB2A31-8852-E1AC-7EB4-B77143868D1D")
IXPathFunction : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IXPathFunction*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXPathFunction*)pObj->Probe(EIID_IXPathFunction);
    }

    static CARAPI_(IXPathFunction*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXPathFunction*)pObj->Probe(EIID_IXPathFunction);
    }

    virtual CARAPI Evaluate(
        /* [in] */ Elastos::Utility::IList * args,
        /* [out] */ IInterface ** obj) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace XPath {
CAR_INTERFACE("D1093934-8852-E1AC-36E0-97F122C7FD1F")
IXPathFunctionResolver : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IXPathFunctionResolver*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXPathFunctionResolver*)pObj->Probe(EIID_IXPathFunctionResolver);
    }

    static CARAPI_(IXPathFunctionResolver*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXPathFunctionResolver*)pObj->Probe(EIID_IXPathFunctionResolver);
    }

    virtual CARAPI ResolveFunction(
        /* [in] */ Elastosx::Xml::Namespace::IQName * functionName,
        /* [in] */ _ELASTOS Int32 arity,
        /* [out] */ Elastosx::Xml::XPath::IXPathFunction ** func) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace XPath {
CAR_INTERFACE("FA203929-8852-DCAC-37E0-97F122C7FD1F")
IXPathVariableResolver : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IXPathVariableResolver*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXPathVariableResolver*)pObj->Probe(EIID_IXPathVariableResolver);
    }

    static CARAPI_(IXPathVariableResolver*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXPathVariableResolver*)pObj->Probe(EIID_IXPathVariableResolver);
    }

    virtual CARAPI ResolveVariable(
        /* [in] */ Elastosx::Xml::Namespace::IQName * variableName,
        /* [out] */ IInterface ** obj) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace XPath {
CAR_INTERFACE("2317CC08-9852-F791-FA3B-2F69DFB2BDFF")
IXPath : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IXPath*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXPath*)pObj->Probe(EIID_IXPath);
    }

    static CARAPI_(IXPath*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXPath*)pObj->Probe(EIID_IXPath);
    }

    virtual CARAPI Reset() = 0;

    virtual CARAPI SetXPathVariableResolver(
        /* [in] */ Elastosx::Xml::XPath::IXPathVariableResolver * resolver) = 0;

    virtual CARAPI GetXPathVariableResolver(
        /* [out] */ Elastosx::Xml::XPath::IXPathVariableResolver ** resolver) = 0;

    virtual CARAPI SetXPathFunctionResolver(
        /* [in] */ Elastosx::Xml::XPath::IXPathFunctionResolver * resolver) = 0;

    virtual CARAPI GetXPathFunctionResolver(
        /* [out] */ Elastosx::Xml::XPath::IXPathFunctionResolver ** resolver) = 0;

    virtual CARAPI SetNamespaceContext(
        /* [in] */ Elastosx::Xml::Namespace::INamespaceContext * nsContext) = 0;

    virtual CARAPI GetNamespaceContext(
        /* [out] */ Elastosx::Xml::Namespace::INamespaceContext ** nsContext) = 0;

    virtual CARAPI Compile(
        /* [in] */ const _ELASTOS String& expression,
        /* [out] */ Elastosx::Xml::XPath::IXPathExpression ** exprs) = 0;

    virtual CARAPI Evaluate(
        /* [in] */ const _ELASTOS String& expression,
        /* [in] */ IInterface * item,
        /* [in] */ Elastosx::Xml::Namespace::IQName * returnType,
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI Evaluate(
        /* [in] */ const _ELASTOS String& expression,
        /* [in] */ IInterface * item,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI Evaluate(
        /* [in] */ const _ELASTOS String& expression,
        /* [in] */ Org::Xml::Sax::IInputSource * source,
        /* [in] */ Elastosx::Xml::Namespace::IQName * returnType,
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI Evaluate(
        /* [in] */ const _ELASTOS String& expression,
        /* [in] */ Org::Xml::Sax::IInputSource * source,
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace XPath {
CAR_INTERFACE("EFC48329-8852-D0AC-7EB4-B77143868D1D")
IXPathFactory : public IInterface
{
    static const _ELASTOS String DEFAULT_PROPERTY_NAME;
    static const _ELASTOS String DEFAULT_OBJECT_MODEL_URI;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IXPathFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXPathFactory*)pObj->Probe(EIID_IXPathFactory);
    }

    static CARAPI_(IXPathFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXPathFactory*)pObj->Probe(EIID_IXPathFactory);
    }

    virtual CARAPI IsObjectModelSupported(
        /* [in] */ const _ELASTOS String& objectModel,
        /* [out] */ _ELASTOS Boolean * state) = 0;

    virtual CARAPI SetFeature(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI GetFeature(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Boolean * feature) = 0;

    virtual CARAPI SetXPathVariableResolver(
        /* [in] */ Elastosx::Xml::XPath::IXPathVariableResolver * resolver) = 0;

    virtual CARAPI SetXPathFunctionResolver(
        /* [in] */ Elastosx::Xml::XPath::IXPathFunctionResolver * resolver) = 0;

    virtual CARAPI NewXPath(
        /* [out] */ Elastosx::Xml::XPath::IXPath ** path) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace XPath {
CAR_INTERFACE("8C4F3F21-8852-D0AC-ACDD-FFD1DEC60D19")
IXPathFactoryFinder : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IXPathFactoryFinder*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXPathFactoryFinder*)pObj->Probe(EIID_IXPathFactoryFinder);
    }

    static CARAPI_(IXPathFactoryFinder*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXPathFactoryFinder*)pObj->Probe(EIID_IXPathFactoryFinder);
    }

    virtual CARAPI NewFactory(
        /* [in] */ const _ELASTOS String& uri,
        /* [out] */ Elastosx::Xml::XPath::IXPathFactory ** fty) = 0;

    virtual CARAPI CreateInstance(
        /* [in] */ const _ELASTOS String& className,
        /* [out] */ Elastosx::Xml::XPath::IXPathFactory ** fty) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Namespace {
CAR_INTERFACE("88A8B837-0312-410D-F518-FDD1DEC60D19")
ICQNameClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICQNameClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICQNameClassObject*)pObj->Probe(EIID_ICQNameClassObject);
    }

    static CARAPI_(ICQNameClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICQNameClassObject*)pObj->Probe(EIID_ICQNameClassObject);
    }

    virtual CARAPI CreateObjectWithNamespaceURILocalPart(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& localPart,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithNamespaceURILocalPartPrefix(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& localPart,
        /* [in] */ const _ELASTOS String& prefix,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithLocalPart(
        /* [in] */ const _ELASTOS String& localPart,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Namespace {
CAR_INTERFACE("C14A7036-0312-410D-23A0-7831E3BE1EA3")
ICQNameHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICQNameHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICQNameHelperClassObject*)pObj->Probe(EIID_ICQNameHelperClassObject);
    }

    static CARAPI_(ICQNameHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICQNameHelperClassObject*)pObj->Probe(EIID_ICQNameHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Datatype {
CAR_INTERFACE("42517551-8312-8C06-6487-250259D00D1B")
ICDatatypeConstantsClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDatatypeConstantsClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDatatypeConstantsClassObject*)pObj->Probe(EIID_ICDatatypeConstantsClassObject);
    }

    static CARAPI_(ICDatatypeConstantsClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDatatypeConstantsClassObject*)pObj->Probe(EIID_ICDatatypeConstantsClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Datatype {
CAR_INTERFACE("987E792A-0312-374C-78CC-40012D028A17")
ICDatatypeFactoryHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDatatypeFactoryHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDatatypeFactoryHelperClassObject*)pObj->Probe(EIID_ICDatatypeFactoryHelperClassObject);
    }

    static CARAPI_(ICDatatypeFactoryHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDatatypeFactoryHelperClassObject*)pObj->Probe(EIID_ICDatatypeFactoryHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Parsers {
CAR_INTERFACE("B6EF7F22-8312-6C59-EE43-8B80E2C58CFB")
ICDocumentBuilderFactoryHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDocumentBuilderFactoryHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDocumentBuilderFactoryHelperClassObject*)pObj->Probe(EIID_ICDocumentBuilderFactoryHelperClassObject);
    }

    static CARAPI_(ICDocumentBuilderFactoryHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDocumentBuilderFactoryHelperClassObject*)pObj->Probe(EIID_ICDocumentBuilderFactoryHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Parsers {
CAR_INTERFACE("53037924-0312-0A0E-4264-2051C3C67D68")
ICSAXParserFactoryHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSAXParserFactoryHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSAXParserFactoryHelperClassObject*)pObj->Probe(EIID_ICSAXParserFactoryHelperClassObject);
    }

    static CARAPI_(ICSAXParserFactoryHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSAXParserFactoryHelperClassObject*)pObj->Probe(EIID_ICSAXParserFactoryHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Validation {
CAR_INTERFACE("AD857932-0312-260E-56A0-8041025A0414")
ICSchemaFactoryHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSchemaFactoryHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSchemaFactoryHelperClassObject*)pObj->Probe(EIID_ICSchemaFactoryHelperClassObject);
    }

    static CARAPI_(ICSchemaFactoryHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSchemaFactoryHelperClassObject*)pObj->Probe(EIID_ICSchemaFactoryHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
namespace Dom {
CAR_INTERFACE("80699F3D-8312-1806-2C98-D663F4477B1B")
ICDOMSourceClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDOMSourceClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDOMSourceClassObject*)pObj->Probe(EIID_ICDOMSourceClassObject);
    }

    static CARAPI_(ICDOMSourceClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDOMSourceClassObject*)pObj->Probe(EIID_ICDOMSourceClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithN(
        /* [in] */ Org::W3c::Dom::INode * n,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithNodeSystemID(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ const _ELASTOS String& systemID,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
namespace Dom {
CAR_INTERFACE("BB11E82B-8312-1806-2C1C-D663F4477B1B")
ICDOMResultClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDOMResultClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDOMResultClassObject*)pObj->Probe(EIID_ICDOMResultClassObject);
    }

    static CARAPI_(ICDOMResultClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDOMResultClassObject*)pObj->Probe(EIID_ICDOMResultClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithNode(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithNodeSystemId(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithNodeNextSibling(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ Org::W3c::Dom::INode * nextSibling,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithNodeNextSiblingSystemId(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ Org::W3c::Dom::INode * nextSibling,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
namespace Sax {
CAR_INTERFACE("2FBA6E22-0312-0A0E-421C-D663F4477B1B")
ICSAXResultClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSAXResultClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSAXResultClassObject*)pObj->Probe(EIID_ICSAXResultClassObject);
    }

    static CARAPI_(ICSAXResultClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSAXResultClassObject*)pObj->Probe(EIID_ICSAXResultClassObject);
    }

    virtual CARAPI CreateObjectWithHandler(
        /* [in] */ Org::Xml::Sax::IContentHandler * handler,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
namespace Sax {
CAR_INTERFACE("CA40932B-0312-0A0E-4298-D663F4477B1B")
ICSAXSourceClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSAXSourceClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSAXSourceClassObject*)pObj->Probe(EIID_ICSAXSourceClassObject);
    }

    static CARAPI_(ICSAXSourceClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSAXSourceClassObject*)pObj->Probe(EIID_ICSAXSourceClassObject);
    }

    virtual CARAPI CreateObjectWithReaderInputSource(
        /* [in] */ Org::Xml::Sax::IXMLReader * reader,
        /* [in] */ Org::Xml::Sax::IInputSource * inputSource,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithInputSource(
        /* [in] */ Org::Xml::Sax::IInputSource * inputSource,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
namespace Stream {
CAR_INTERFACE("381CD328-0312-28D9-48C0-38ACC7E88FF6")
ICStreamResultClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICStreamResultClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStreamResultClassObject*)pObj->Probe(EIID_ICStreamResultClassObject);
    }

    static CARAPI_(ICStreamResultClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStreamResultClassObject*)pObj->Probe(EIID_ICStreamResultClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithOutputStream(
        /* [in] */ Elastos::IO::IOutputStream * outputStream,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithWriter(
        /* [in] */ Elastos::IO::IWriter * writer,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithSystemId(
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithF(
        /* [in] */ Elastos::IO::IFile * f,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
namespace Stream {
CAR_INTERFACE("A81EFB3B-0312-28D9-48C0-30ADC7E88FF6")
ICStreamSourceClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICStreamSourceClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStreamSourceClassObject*)pObj->Probe(EIID_ICStreamSourceClassObject);
    }

    static CARAPI_(ICStreamSourceClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStreamSourceClassObject*)pObj->Probe(EIID_ICStreamSourceClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithInputStream(
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithInputStreamSystemId(
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithReader(
        /* [in] */ Elastos::IO::IReader * reader,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithReaderSystemId(
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithSystemId(
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithF(
        /* [in] */ Elastos::IO::IFile * f,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastosx {
namespace Xml {
namespace XPath {
CAR_INTERFACE("44006F1A-1312-E466-BD32-726CDF647CDB")
ICXPathConstantsClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICXPathConstantsClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICXPathConstantsClassObject*)pObj->Probe(EIID_ICXPathConstantsClassObject);
    }

    static CARAPI_(ICXPathConstantsClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICXPathConstantsClassObject*)pObj->Probe(EIID_ICXPathConstantsClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace XPath {
CAR_INTERFACE("80016A3C-8312-5910-A159-BBAFC7E88FF6")
ICXPathFactoryFinderClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICXPathFactoryFinderClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICXPathFactoryFinderClassObject*)pObj->Probe(EIID_ICXPathFactoryFinderClassObject);
    }

    static CARAPI_(ICXPathFactoryFinderClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICXPathFactoryFinderClassObject*)pObj->Probe(EIID_ICXPathFactoryFinderClassObject);
    }

    virtual CARAPI CreateObjectWithCl(
        /* [in] */ Elastos::Core::IClassLoader * cl,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastosx {
namespace Crypto {
class CCipher
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastosx::Crypto::ICipherSpi * cipherSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& transformation,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCipherClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCipher, RGM_SAME_DOMAIN,
                EIID_ICCipherClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCipherSpiProviderTransformation(cipherSpi, provider, transformation, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& transformation,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * transformParts,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCipherClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCipher, RGM_SAME_DOMAIN,
                EIID_ICCipherClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTransformationTransformPartsProvider(transformation, transformParts, provider, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::ICipherSpi * cipherSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& transformation,
        /* [out] */ Elastosx::Crypto::ICipher** __ICipher)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cipherSpi, provider, transformation, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICipher = (Elastosx::Crypto::ICipher*)__pNewObj->Probe(Elastosx::Crypto::EIID_ICipher);
        if (*__ICipher) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::ICipherSpi * cipherSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& transformation,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cipherSpi, provider, transformation, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::ICipherSpi * cipherSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& transformation,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cipherSpi, provider, transformation, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::ICipherSpi * cipherSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& transformation,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cipherSpi, provider, transformation, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& transformation,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * transformParts,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastosx::Crypto::ICipher** __ICipher)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(transformation, transformParts, provider, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICipher = (Elastosx::Crypto::ICipher*)__pNewObj->Probe(Elastosx::Crypto::EIID_ICipher);
        if (*__ICipher) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& transformation,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * transformParts,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(transformation, transformParts, provider, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& transformation,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * transformParts,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(transformation, transformParts, provider, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& transformation,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * transformParts,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(transformation, transformParts, provider, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
namespace Elastosx {
namespace Crypto {
class CCipherHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Crypto::ICipherHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCipherHelper, RGM_SAME_DOMAIN, Elastosx::Crypto::EIID_ICipherHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCipherHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCipherHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCipherHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastosx {
namespace Crypto {
class CCipherInputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCipherInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCipherInputStream, RGM_SAME_DOMAIN,
                EIID_ICCipherInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIsC(is, c, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCipherInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCipherInputStream, RGM_SAME_DOMAIN,
                EIID_ICCipherInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIs(is, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ Elastosx::Crypto::ICipherInputStream** __ICipherInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICipherInputStream = (Elastosx::Crypto::ICipherInputStream*)__pNewObj->Probe(Elastosx::Crypto::EIID_ICipherInputStream);
        if (*__ICipherInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ Elastos::IO::IFilterInputStream** __IFilterInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterInputStream = (Elastos::IO::IFilterInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterInputStream);
        if (*__IFilterInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ Elastosx::Crypto::ICipherInputStream** __ICipherInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICipherInputStream = (Elastosx::Crypto::ICipherInputStream*)__pNewObj->Probe(Elastosx::Crypto::EIID_ICipherInputStream);
        if (*__ICipherInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ Elastos::IO::IFilterInputStream** __IFilterInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterInputStream = (Elastos::IO::IFilterInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterInputStream);
        if (*__IFilterInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
namespace Elastosx {
namespace Crypto {
class CCipherOutputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCipherOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCipherOutputStream, RGM_SAME_DOMAIN,
                EIID_ICCipherOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOsC(os, c, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCipherOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCipherOutputStream, RGM_SAME_DOMAIN,
                EIID_ICCipherOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOs(os, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ Elastosx::Crypto::ICipherOutputStream** __ICipherOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICipherOutputStream = (Elastosx::Crypto::ICipherOutputStream*)__pNewObj->Probe(Elastosx::Crypto::EIID_ICipherOutputStream);
        if (*__ICipherOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ Elastos::IO::IFilterOutputStream** __IFilterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterOutputStream = (Elastos::IO::IFilterOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterOutputStream);
        if (*__IFilterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ Elastosx::Crypto::ICipherOutputStream** __ICipherOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICipherOutputStream = (Elastosx::Crypto::ICipherOutputStream*)__pNewObj->Probe(Elastosx::Crypto::EIID_ICipherOutputStream);
        if (*__ICipherOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ Elastos::IO::IFilterOutputStream** __IFilterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterOutputStream = (Elastos::IO::IFilterOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterOutputStream);
        if (*__IFilterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
namespace Elastosx {
namespace Crypto {
class CEncryptedPrivateKeyInfo
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encoded,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICEncryptedPrivateKeyInfoClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CEncryptedPrivateKeyInfo, RGM_SAME_DOMAIN,
                EIID_ICEncryptedPrivateKeyInfoClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithEncoded(encoded, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& encryptionAlgorithmName,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encryptedData,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICEncryptedPrivateKeyInfoClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CEncryptedPrivateKeyInfo, RGM_SAME_DOMAIN,
                EIID_ICEncryptedPrivateKeyInfoClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithEncryptionAlgorithmNameEncryptedData(encryptionAlgorithmName, encryptedData, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Security::IAlgorithmParameters * algParams,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encryptedData,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICEncryptedPrivateKeyInfoClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CEncryptedPrivateKeyInfo, RGM_SAME_DOMAIN,
                EIID_ICEncryptedPrivateKeyInfoClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithAlgParamsEncryptedData(algParams, encryptedData, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encoded,
        /* [out] */ Elastosx::Crypto::IEncryptedPrivateKeyInfo** __IEncryptedPrivateKeyInfo)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(encoded, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IEncryptedPrivateKeyInfo = (Elastosx::Crypto::IEncryptedPrivateKeyInfo*)__pNewObj->Probe(Elastosx::Crypto::EIID_IEncryptedPrivateKeyInfo);
        if (*__IEncryptedPrivateKeyInfo) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encoded,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(encoded, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encoded,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(encoded, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encoded,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(encoded, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& encryptionAlgorithmName,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encryptedData,
        /* [out] */ Elastosx::Crypto::IEncryptedPrivateKeyInfo** __IEncryptedPrivateKeyInfo)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(encryptionAlgorithmName, encryptedData, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IEncryptedPrivateKeyInfo = (Elastosx::Crypto::IEncryptedPrivateKeyInfo*)__pNewObj->Probe(Elastosx::Crypto::EIID_IEncryptedPrivateKeyInfo);
        if (*__IEncryptedPrivateKeyInfo) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& encryptionAlgorithmName,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encryptedData,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(encryptionAlgorithmName, encryptedData, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& encryptionAlgorithmName,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encryptedData,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(encryptionAlgorithmName, encryptedData, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& encryptionAlgorithmName,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encryptedData,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(encryptionAlgorithmName, encryptedData, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IAlgorithmParameters * algParams,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encryptedData,
        /* [out] */ Elastosx::Crypto::IEncryptedPrivateKeyInfo** __IEncryptedPrivateKeyInfo)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(algParams, encryptedData, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IEncryptedPrivateKeyInfo = (Elastosx::Crypto::IEncryptedPrivateKeyInfo*)__pNewObj->Probe(Elastosx::Crypto::EIID_IEncryptedPrivateKeyInfo);
        if (*__IEncryptedPrivateKeyInfo) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IAlgorithmParameters * algParams,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encryptedData,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(algParams, encryptedData, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IAlgorithmParameters * algParams,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encryptedData,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(algParams, encryptedData, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IAlgorithmParameters * algParams,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encryptedData,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(algParams, encryptedData, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
namespace Elastosx {
namespace Crypto {
class CExemptionMechanism
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastosx::Crypto::IExemptionMechanismSpi * exmechSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& mechanism,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICExemptionMechanismClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CExemptionMechanism, RGM_SAME_DOMAIN,
                EIID_ICExemptionMechanismClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithExmechSpiProviderMechanism(exmechSpi, provider, mechanism, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::IExemptionMechanismSpi * exmechSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& mechanism,
        /* [out] */ Elastosx::Crypto::IExemptionMechanism** __IExemptionMechanism)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(exmechSpi, provider, mechanism, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IExemptionMechanism = (Elastosx::Crypto::IExemptionMechanism*)__pNewObj->Probe(Elastosx::Crypto::EIID_IExemptionMechanism);
        if (*__IExemptionMechanism) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::IExemptionMechanismSpi * exmechSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& mechanism,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(exmechSpi, provider, mechanism, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::IExemptionMechanismSpi * exmechSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& mechanism,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(exmechSpi, provider, mechanism, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::IExemptionMechanismSpi * exmechSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& mechanism,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(exmechSpi, provider, mechanism, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
namespace Elastosx {
namespace Crypto {
class CExemptionMechanismHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Crypto::IExemptionMechanismHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CExemptionMechanismHelper, RGM_SAME_DOMAIN, Elastosx::Crypto::EIID_IExemptionMechanismHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CExemptionMechanismHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CExemptionMechanismHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CExemptionMechanismHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastosx {
namespace Crypto {
class CKeyAgreement
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastosx::Crypto::IKeyAgreementSpi * keyAgreeSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICKeyAgreementClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CKeyAgreement, RGM_SAME_DOMAIN,
                EIID_ICKeyAgreementClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithKeyAgreeSpiProviderAlgorithm(keyAgreeSpi, provider, algorithm, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::IKeyAgreementSpi * keyAgreeSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastosx::Crypto::IKeyAgreement** __IKeyAgreement)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyAgreeSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeyAgreement = (Elastosx::Crypto::IKeyAgreement*)__pNewObj->Probe(Elastosx::Crypto::EIID_IKeyAgreement);
        if (*__IKeyAgreement) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::IKeyAgreementSpi * keyAgreeSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyAgreeSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::IKeyAgreementSpi * keyAgreeSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyAgreeSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::IKeyAgreementSpi * keyAgreeSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyAgreeSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
namespace Elastosx {
namespace Crypto {
class CKeyAgreementHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Crypto::IKeyAgreementHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyAgreementHelper, RGM_SAME_DOMAIN, Elastosx::Crypto::EIID_IKeyAgreementHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyAgreementHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyAgreementHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyAgreementHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastosx {
namespace Crypto {
class CKeyGenerator
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastosx::Crypto::IKeyGeneratorSpi * keyGenSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICKeyGeneratorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CKeyGenerator, RGM_SAME_DOMAIN,
                EIID_ICKeyGeneratorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithKeyGenSpiProviderAlgorithm(keyGenSpi, provider, algorithm, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::IKeyGeneratorSpi * keyGenSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastosx::Crypto::IKeyGenerator** __IKeyGenerator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyGenSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeyGenerator = (Elastosx::Crypto::IKeyGenerator*)__pNewObj->Probe(Elastosx::Crypto::EIID_IKeyGenerator);
        if (*__IKeyGenerator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::IKeyGeneratorSpi * keyGenSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyGenSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::IKeyGeneratorSpi * keyGenSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyGenSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::IKeyGeneratorSpi * keyGenSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyGenSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
namespace Elastosx {
namespace Crypto {
class CKeyGeneratorHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Crypto::IKeyGeneratorHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyGeneratorHelper, RGM_SAME_DOMAIN, Elastosx::Crypto::EIID_IKeyGeneratorHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyGeneratorHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyGeneratorHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyGeneratorHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastosx {
namespace Crypto {
class CMac
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastosx::Crypto::IMacSpi * keyGenSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICMacClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CMac, RGM_SAME_DOMAIN,
                EIID_ICMacClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithKeyGenSpiProviderAlgorithm(keyGenSpi, provider, algorithm, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::IMacSpi * keyGenSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastosx::Crypto::IMac** __IMac)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyGenSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMac = (Elastosx::Crypto::IMac*)__pNewObj->Probe(Elastosx::Crypto::EIID_IMac);
        if (*__IMac) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::IMacSpi * keyGenSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyGenSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::IMacSpi * keyGenSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyGenSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::IMacSpi * keyGenSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyGenSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::IMacSpi * keyGenSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyGenSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
namespace Elastosx {
namespace Crypto {
class CMacHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Crypto::IMacHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMacHelper, RGM_SAME_DOMAIN, Elastosx::Crypto::EIID_IMacHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMacHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMacHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMacHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastosx {
namespace Crypto {
class CSecretKeyFactory
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastosx::Crypto::ISecretKeyFactorySpi * keyFacSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSecretKeyFactoryClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSecretKeyFactory, RGM_SAME_DOMAIN,
                EIID_ICSecretKeyFactoryClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithKeyFacSpiProviderAlgorithm(keyFacSpi, provider, algorithm, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::ISecretKeyFactorySpi * keyFacSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastosx::Crypto::ISecretKeyFactory** __ISecretKeyFactory)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyFacSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISecretKeyFactory = (Elastosx::Crypto::ISecretKeyFactory*)__pNewObj->Probe(Elastosx::Crypto::EIID_ISecretKeyFactory);
        if (*__ISecretKeyFactory) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::ISecretKeyFactorySpi * keyFacSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyFacSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::ISecretKeyFactorySpi * keyFacSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyFacSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::ISecretKeyFactorySpi * keyFacSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyFacSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
namespace Elastosx {
namespace Crypto {
class CSecretKeyFactoryHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Crypto::ISecretKeyFactoryHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSecretKeyFactoryHelper, RGM_SAME_DOMAIN, Elastosx::Crypto::EIID_ISecretKeyFactoryHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSecretKeyFactoryHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSecretKeyFactoryHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSecretKeyFactoryHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastosx {
namespace Crypto {
class CSealedObject
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::ISerializable * object,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSealedObjectClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSealedObject, RGM_SAME_DOMAIN,
                EIID_ICSealedObjectClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithObjectC(object, c, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastosx::Crypto::ISealedObject * object,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSealedObjectClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSealedObject, RGM_SAME_DOMAIN,
                EIID_ICSealedObjectClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithObject(object, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::ISerializable * object,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ Elastosx::Crypto::ISecretKeyFactory** __ISecretKeyFactory)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(object, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISecretKeyFactory = (Elastosx::Crypto::ISecretKeyFactory*)__pNewObj->Probe(Elastosx::Crypto::EIID_ISecretKeyFactory);
        if (*__ISecretKeyFactory) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::ISerializable * object,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(object, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::ISerializable * object,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(object, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::ISerializable * object,
        /* [in] */ Elastosx::Crypto::ICipher * c,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(object, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::ISealedObject * object,
        /* [out] */ Elastosx::Crypto::ISecretKeyFactory** __ISecretKeyFactory)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(object, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISecretKeyFactory = (Elastosx::Crypto::ISecretKeyFactory*)__pNewObj->Probe(Elastosx::Crypto::EIID_ISecretKeyFactory);
        if (*__ISecretKeyFactory) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::ISealedObject * object,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(object, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::ISealedObject * object,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(object, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::ISealedObject * object,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(object, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
namespace Elastosx {
namespace Crypto {
class CNullCipher
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastosx::Crypto::INullCipher** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNullCipher, RGM_SAME_DOMAIN, Elastosx::Crypto::EIID_INullCipher, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNullCipher, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNullCipher, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNullCipher, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
class CDESKeySpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDESKeySpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDESKeySpec, RGM_SAME_DOMAIN,
                EIID_ICDESKeySpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithKey(key, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDESKeySpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDESKeySpec, RGM_SAME_DOMAIN,
                EIID_ICDESKeySpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithKeyOffset(key, offset, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [out] */ Elastosx::Crypto::Spec::IDESKeySpec** __IDESKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDESKeySpec = (Elastosx::Crypto::Spec::IDESKeySpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IDESKeySpec);
        if (*__IDESKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [out] */ Elastos::Security::Spec::IKeySpec** __IKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeySpec = (Elastos::Security::Spec::IKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IKeySpec);
        if (*__IKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ Elastosx::Crypto::Spec::IDESKeySpec** __IDESKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, offset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDESKeySpec = (Elastosx::Crypto::Spec::IDESKeySpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IDESKeySpec);
        if (*__IDESKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ Elastos::Security::Spec::IKeySpec** __IKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, offset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeySpec = (Elastos::Security::Spec::IKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IKeySpec);
        if (*__IKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, offset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, offset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, offset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
class CDESKeySpecHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Crypto::Spec::IDESKeySpecHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDESKeySpecHelper, RGM_SAME_DOMAIN, Elastosx::Crypto::Spec::EIID_IDESKeySpecHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDESKeySpecHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDESKeySpecHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDESKeySpecHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
class CDESedeKeySpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDESedeKeySpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDESedeKeySpec, RGM_SAME_DOMAIN,
                EIID_ICDESedeKeySpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithKey(key, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDESedeKeySpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDESedeKeySpec, RGM_SAME_DOMAIN,
                EIID_ICDESedeKeySpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithKeyOffset(key, offset, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [out] */ Elastosx::Crypto::Spec::IDESedeKeySpec** __IDESedeKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDESedeKeySpec = (Elastosx::Crypto::Spec::IDESedeKeySpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IDESedeKeySpec);
        if (*__IDESedeKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [out] */ Elastos::Security::Spec::IKeySpec** __IKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeySpec = (Elastos::Security::Spec::IKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IKeySpec);
        if (*__IKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ Elastosx::Crypto::Spec::IDESedeKeySpec** __IDESedeKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, offset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDESedeKeySpec = (Elastosx::Crypto::Spec::IDESedeKeySpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IDESedeKeySpec);
        if (*__IDESedeKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ Elastos::Security::Spec::IKeySpec** __IKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, offset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeySpec = (Elastos::Security::Spec::IKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IKeySpec);
        if (*__IKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, offset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, offset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, offset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
class CDESedeKeySpecHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Crypto::Spec::IDESedeKeySpecHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDESedeKeySpecHelper, RGM_SAME_DOMAIN, Elastosx::Crypto::Spec::EIID_IDESedeKeySpecHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDESedeKeySpecHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDESedeKeySpecHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDESedeKeySpecHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
class CDHGenParameterSpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 primeSize,
        /* [in] */ _ELASTOS Int32 exponentSize,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDHGenParameterSpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDHGenParameterSpec, RGM_SAME_DOMAIN,
                EIID_ICDHGenParameterSpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPrimeSizeExponentSize(primeSize, exponentSize, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 primeSize,
        /* [in] */ _ELASTOS Int32 exponentSize,
        /* [out] */ Elastosx::Crypto::Spec::IDHGenParameterSpec** __IDHGenParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(primeSize, exponentSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDHGenParameterSpec = (Elastosx::Crypto::Spec::IDHGenParameterSpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IDHGenParameterSpec);
        if (*__IDHGenParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 primeSize,
        /* [in] */ _ELASTOS Int32 exponentSize,
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec** __IAlgorithmParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(primeSize, exponentSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAlgorithmParameterSpec = (Elastos::Security::Spec::IAlgorithmParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IAlgorithmParameterSpec);
        if (*__IAlgorithmParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 primeSize,
        /* [in] */ _ELASTOS Int32 exponentSize,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(primeSize, exponentSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 primeSize,
        /* [in] */ _ELASTOS Int32 exponentSize,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(primeSize, exponentSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 primeSize,
        /* [in] */ _ELASTOS Int32 exponentSize,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(primeSize, exponentSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
class CDHParameterSpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDHParameterSpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDHParameterSpec, RGM_SAME_DOMAIN,
                EIID_ICDHParameterSpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPG(p, g, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [in] */ _ELASTOS Int32 l,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDHParameterSpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDHParameterSpec, RGM_SAME_DOMAIN,
                EIID_ICDHParameterSpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPGL(p, g, l, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ Elastosx::Crypto::Spec::IDHParameterSpec** __IDHParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(p, g, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDHParameterSpec = (Elastosx::Crypto::Spec::IDHParameterSpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IDHParameterSpec);
        if (*__IDHParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec** __IAlgorithmParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(p, g, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAlgorithmParameterSpec = (Elastos::Security::Spec::IAlgorithmParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IAlgorithmParameterSpec);
        if (*__IAlgorithmParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(p, g, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(p, g, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(p, g, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [in] */ _ELASTOS Int32 l,
        /* [out] */ Elastosx::Crypto::Spec::IDHParameterSpec** __IDHParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(p, g, l, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDHParameterSpec = (Elastosx::Crypto::Spec::IDHParameterSpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IDHParameterSpec);
        if (*__IDHParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [in] */ _ELASTOS Int32 l,
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec** __IAlgorithmParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(p, g, l, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAlgorithmParameterSpec = (Elastos::Security::Spec::IAlgorithmParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IAlgorithmParameterSpec);
        if (*__IAlgorithmParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [in] */ _ELASTOS Int32 l,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(p, g, l, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [in] */ _ELASTOS Int32 l,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(p, g, l, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [in] */ _ELASTOS Int32 l,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(p, g, l, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
class CDHPrivateKeySpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Math::IBigInteger * x,
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDHPrivateKeySpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDHPrivateKeySpec, RGM_SAME_DOMAIN,
                EIID_ICDHPrivateKeySpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithXPG(x, p, g, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * x,
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ Elastosx::Crypto::Spec::IDHPrivateKeySpec** __IDHPrivateKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(x, p, g, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDHPrivateKeySpec = (Elastosx::Crypto::Spec::IDHPrivateKeySpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IDHPrivateKeySpec);
        if (*__IDHPrivateKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * x,
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ Elastos::Security::Spec::IKeySpec** __IKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(x, p, g, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeySpec = (Elastos::Security::Spec::IKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IKeySpec);
        if (*__IKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * x,
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(x, p, g, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * x,
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(x, p, g, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * x,
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(x, p, g, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
class CDHPublicKeySpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Math::IBigInteger * y,
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDHPublicKeySpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDHPublicKeySpec, RGM_SAME_DOMAIN,
                EIID_ICDHPublicKeySpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithYPG(y, p, g, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * y,
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ Elastosx::Crypto::Spec::IDHPublicKeySpec** __IDHPublicKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(y, p, g, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDHPublicKeySpec = (Elastosx::Crypto::Spec::IDHPublicKeySpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IDHPublicKeySpec);
        if (*__IDHPublicKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * y,
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ Elastos::Security::Spec::IKeySpec** __IKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(y, p, g, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeySpec = (Elastos::Security::Spec::IKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IKeySpec);
        if (*__IKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * y,
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(y, p, g, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * y,
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(y, p, g, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * y,
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(y, p, g, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
class CGCMParameterSpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 tagLen,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICGCMParameterSpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CGCMParameterSpec, RGM_SAME_DOMAIN,
                EIID_ICGCMParameterSpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTagLenIv(tagLen, iv, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 tagLen,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICGCMParameterSpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CGCMParameterSpec, RGM_SAME_DOMAIN,
                EIID_ICGCMParameterSpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTagLenIvOffsetByteCount(tagLen, iv, offset, byteCount, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 tagLen,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ Elastosx::Crypto::Spec::IGCMParameterSpec** __IGCMParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tagLen, iv, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IGCMParameterSpec = (Elastosx::Crypto::Spec::IGCMParameterSpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IGCMParameterSpec);
        if (*__IGCMParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 tagLen,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec** __IAlgorithmParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tagLen, iv, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAlgorithmParameterSpec = (Elastos::Security::Spec::IAlgorithmParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IAlgorithmParameterSpec);
        if (*__IAlgorithmParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 tagLen,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tagLen, iv, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 tagLen,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tagLen, iv, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 tagLen,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tagLen, iv, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 tagLen,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [out] */ Elastosx::Crypto::Spec::IGCMParameterSpec** __IGCMParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tagLen, iv, offset, byteCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IGCMParameterSpec = (Elastosx::Crypto::Spec::IGCMParameterSpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IGCMParameterSpec);
        if (*__IGCMParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 tagLen,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec** __IAlgorithmParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tagLen, iv, offset, byteCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAlgorithmParameterSpec = (Elastos::Security::Spec::IAlgorithmParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IAlgorithmParameterSpec);
        if (*__IAlgorithmParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 tagLen,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tagLen, iv, offset, byteCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 tagLen,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tagLen, iv, offset, byteCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 tagLen,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tagLen, iv, offset, byteCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
class CIvParameterSpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICIvParameterSpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CIvParameterSpec, RGM_SAME_DOMAIN,
                EIID_ICIvParameterSpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIv(iv, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICIvParameterSpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CIvParameterSpec, RGM_SAME_DOMAIN,
                EIID_ICIvParameterSpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIvOffsetByteCount(iv, offset, byteCount, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ Elastosx::Crypto::Spec::IIvParameterSpec** __IIvParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iv, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIvParameterSpec = (Elastosx::Crypto::Spec::IIvParameterSpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IIvParameterSpec);
        if (*__IIvParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec** __IAlgorithmParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iv, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAlgorithmParameterSpec = (Elastos::Security::Spec::IAlgorithmParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IAlgorithmParameterSpec);
        if (*__IAlgorithmParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iv, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iv, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iv, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [out] */ Elastosx::Crypto::Spec::IIvParameterSpec** __IIvParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iv, offset, byteCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIvParameterSpec = (Elastosx::Crypto::Spec::IIvParameterSpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IIvParameterSpec);
        if (*__IIvParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec** __IAlgorithmParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iv, offset, byteCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAlgorithmParameterSpec = (Elastos::Security::Spec::IAlgorithmParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IAlgorithmParameterSpec);
        if (*__IAlgorithmParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iv, offset, byteCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iv, offset, byteCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iv, offset, byteCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
class COAEPParameterSpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& mdName,
        /* [in] */ const _ELASTOS String& mgfName,
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * mgfSpec,
        /* [in] */ Elastosx::Crypto::Spec::IPSource * pSrc,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICOAEPParameterSpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_COAEPParameterSpec, RGM_SAME_DOMAIN,
                EIID_ICOAEPParameterSpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithMdNameMgfNameMgfSpecPSrc(mdName, mgfName, mgfSpec, pSrc, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastosx::Crypto::Spec::IOAEPParameterSpec** __object)
    {
        return _CObject_CreateInstance(ECLSID_COAEPParameterSpec, RGM_SAME_DOMAIN, Elastosx::Crypto::Spec::EIID_IOAEPParameterSpec, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec** __object)
    {
        return _CObject_CreateInstance(ECLSID_COAEPParameterSpec, RGM_SAME_DOMAIN, Elastos::Security::Spec::EIID_IAlgorithmParameterSpec, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_COAEPParameterSpec, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_COAEPParameterSpec, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_COAEPParameterSpec, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& mdName,
        /* [in] */ const _ELASTOS String& mgfName,
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * mgfSpec,
        /* [in] */ Elastosx::Crypto::Spec::IPSource * pSrc,
        /* [out] */ Elastosx::Crypto::Spec::IOAEPParameterSpec** __IOAEPParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mdName, mgfName, mgfSpec, pSrc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOAEPParameterSpec = (Elastosx::Crypto::Spec::IOAEPParameterSpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IOAEPParameterSpec);
        if (*__IOAEPParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& mdName,
        /* [in] */ const _ELASTOS String& mgfName,
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * mgfSpec,
        /* [in] */ Elastosx::Crypto::Spec::IPSource * pSrc,
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec** __IAlgorithmParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mdName, mgfName, mgfSpec, pSrc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAlgorithmParameterSpec = (Elastos::Security::Spec::IAlgorithmParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IAlgorithmParameterSpec);
        if (*__IAlgorithmParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& mdName,
        /* [in] */ const _ELASTOS String& mgfName,
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * mgfSpec,
        /* [in] */ Elastosx::Crypto::Spec::IPSource * pSrc,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mdName, mgfName, mgfSpec, pSrc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& mdName,
        /* [in] */ const _ELASTOS String& mgfName,
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * mgfSpec,
        /* [in] */ Elastosx::Crypto::Spec::IPSource * pSrc,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mdName, mgfName, mgfSpec, pSrc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& mdName,
        /* [in] */ const _ELASTOS String& mgfName,
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * mgfSpec,
        /* [in] */ Elastosx::Crypto::Spec::IPSource * pSrc,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mdName, mgfName, mgfSpec, pSrc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
class COAEPParameterSpecHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Crypto::Spec::IOAEPParameterSpecHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_COAEPParameterSpecHelper, RGM_SAME_DOMAIN, Elastosx::Crypto::Spec::EIID_IOAEPParameterSpecHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_COAEPParameterSpecHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_COAEPParameterSpecHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_COAEPParameterSpecHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
class CPBEKeySpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPBEKeySpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPBEKeySpec, RGM_SAME_DOMAIN,
                EIID_ICPBEKeySpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPassword(password, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * salt,
        /* [in] */ _ELASTOS Int32 iterationCount,
        /* [in] */ _ELASTOS Int32 keyLength,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPBEKeySpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPBEKeySpec, RGM_SAME_DOMAIN,
                EIID_ICPBEKeySpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPasswordSaltIterationCountKeyLength(password, salt, iterationCount, keyLength, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * salt,
        /* [in] */ _ELASTOS Int32 iterationCount,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPBEKeySpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPBEKeySpec, RGM_SAME_DOMAIN,
                EIID_ICPBEKeySpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPasswordSaltIterationCount(password, salt, iterationCount, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [out] */ Elastosx::Crypto::Spec::IPBEKeySpec** __IPBEKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(password, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPBEKeySpec = (Elastosx::Crypto::Spec::IPBEKeySpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IPBEKeySpec);
        if (*__IPBEKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [out] */ Elastos::Security::Spec::IKeySpec** __IKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(password, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeySpec = (Elastos::Security::Spec::IKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IKeySpec);
        if (*__IKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(password, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(password, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(password, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * salt,
        /* [in] */ _ELASTOS Int32 iterationCount,
        /* [in] */ _ELASTOS Int32 keyLength,
        /* [out] */ Elastosx::Crypto::Spec::IPBEKeySpec** __IPBEKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(password, salt, iterationCount, keyLength, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPBEKeySpec = (Elastosx::Crypto::Spec::IPBEKeySpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IPBEKeySpec);
        if (*__IPBEKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * salt,
        /* [in] */ _ELASTOS Int32 iterationCount,
        /* [in] */ _ELASTOS Int32 keyLength,
        /* [out] */ Elastos::Security::Spec::IKeySpec** __IKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(password, salt, iterationCount, keyLength, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeySpec = (Elastos::Security::Spec::IKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IKeySpec);
        if (*__IKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * salt,
        /* [in] */ _ELASTOS Int32 iterationCount,
        /* [in] */ _ELASTOS Int32 keyLength,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(password, salt, iterationCount, keyLength, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * salt,
        /* [in] */ _ELASTOS Int32 iterationCount,
        /* [in] */ _ELASTOS Int32 keyLength,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(password, salt, iterationCount, keyLength, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * salt,
        /* [in] */ _ELASTOS Int32 iterationCount,
        /* [in] */ _ELASTOS Int32 keyLength,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(password, salt, iterationCount, keyLength, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * salt,
        /* [in] */ _ELASTOS Int32 iterationCount,
        /* [out] */ Elastosx::Crypto::Spec::IPBEKeySpec** __IPBEKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(password, salt, iterationCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPBEKeySpec = (Elastosx::Crypto::Spec::IPBEKeySpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IPBEKeySpec);
        if (*__IPBEKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * salt,
        /* [in] */ _ELASTOS Int32 iterationCount,
        /* [out] */ Elastos::Security::Spec::IKeySpec** __IKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(password, salt, iterationCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeySpec = (Elastos::Security::Spec::IKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IKeySpec);
        if (*__IKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * salt,
        /* [in] */ _ELASTOS Int32 iterationCount,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(password, salt, iterationCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * salt,
        /* [in] */ _ELASTOS Int32 iterationCount,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(password, salt, iterationCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * salt,
        /* [in] */ _ELASTOS Int32 iterationCount,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(password, salt, iterationCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
class CPBEParameterSpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * salt,
        /* [in] */ _ELASTOS Int32 iterationCount,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPBEParameterSpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPBEParameterSpec, RGM_SAME_DOMAIN,
                EIID_ICPBEParameterSpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSaltIterationCount(salt, iterationCount, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * salt,
        /* [in] */ _ELASTOS Int32 iterationCount,
        /* [out] */ Elastosx::Crypto::Spec::IPBEParameterSpec** __IPBEParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(salt, iterationCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPBEParameterSpec = (Elastosx::Crypto::Spec::IPBEParameterSpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IPBEParameterSpec);
        if (*__IPBEParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * salt,
        /* [in] */ _ELASTOS Int32 iterationCount,
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec** __IAlgorithmParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(salt, iterationCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAlgorithmParameterSpec = (Elastos::Security::Spec::IAlgorithmParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IAlgorithmParameterSpec);
        if (*__IAlgorithmParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * salt,
        /* [in] */ _ELASTOS Int32 iterationCount,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(salt, iterationCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * salt,
        /* [in] */ _ELASTOS Int32 iterationCount,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(salt, iterationCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * salt,
        /* [in] */ _ELASTOS Int32 iterationCount,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(salt, iterationCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
class CPSource
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& pSrcName,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPSourceClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPSource, RGM_SAME_DOMAIN,
                EIID_ICPSourceClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPSrcName(pSrcName, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pSrcName,
        /* [out] */ Elastosx::Crypto::Spec::IPSource** __IPSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pSrcName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPSource = (Elastosx::Crypto::Spec::IPSource*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IPSource);
        if (*__IPSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pSrcName,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pSrcName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pSrcName,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pSrcName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pSrcName,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pSrcName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
class CPSpecified
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * p,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPSpecifiedClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPSpecified, RGM_SAME_DOMAIN,
                EIID_ICPSpecifiedClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithP(p, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastosx::Crypto::Spec::IPSpecified** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPSpecified, RGM_SAME_DOMAIN, Elastosx::Crypto::Spec::EIID_IPSpecified, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPSpecified, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPSpecified, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPSpecified, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * p,
        /* [out] */ Elastosx::Crypto::Spec::IPSpecified** __IPSpecified)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(p, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPSpecified = (Elastosx::Crypto::Spec::IPSpecified*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IPSpecified);
        if (*__IPSpecified) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * p,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(p, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * p,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(p, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * p,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(p, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
class CPSpecifiedHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Crypto::Spec::IPSpecifiedHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPSpecifiedHelper, RGM_SAME_DOMAIN, Elastosx::Crypto::Spec::EIID_IPSpecifiedHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPSpecifiedHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPSpecifiedHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPSpecifiedHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
class CRC2ParameterSpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 effectiveKeyBits,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICRC2ParameterSpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CRC2ParameterSpec, RGM_SAME_DOMAIN,
                EIID_ICRC2ParameterSpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithEffectiveKeyBits(effectiveKeyBits, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 effectiveKeyBits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICRC2ParameterSpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CRC2ParameterSpec, RGM_SAME_DOMAIN,
                EIID_ICRC2ParameterSpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithEffectiveKeyBitsIv(effectiveKeyBits, iv, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 effectiveKeyBits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICRC2ParameterSpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CRC2ParameterSpec, RGM_SAME_DOMAIN,
                EIID_ICRC2ParameterSpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithEffectiveKeyBitsIvOffset(effectiveKeyBits, iv, offset, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 effectiveKeyBits,
        /* [out] */ Elastosx::Crypto::Spec::IRC2ParameterSpec** __IRC2ParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(effectiveKeyBits, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRC2ParameterSpec = (Elastosx::Crypto::Spec::IRC2ParameterSpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IRC2ParameterSpec);
        if (*__IRC2ParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 effectiveKeyBits,
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec** __IAlgorithmParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(effectiveKeyBits, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAlgorithmParameterSpec = (Elastos::Security::Spec::IAlgorithmParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IAlgorithmParameterSpec);
        if (*__IAlgorithmParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 effectiveKeyBits,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(effectiveKeyBits, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 effectiveKeyBits,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(effectiveKeyBits, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 effectiveKeyBits,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(effectiveKeyBits, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 effectiveKeyBits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ Elastosx::Crypto::Spec::IRC2ParameterSpec** __IRC2ParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(effectiveKeyBits, iv, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRC2ParameterSpec = (Elastosx::Crypto::Spec::IRC2ParameterSpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IRC2ParameterSpec);
        if (*__IRC2ParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 effectiveKeyBits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec** __IAlgorithmParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(effectiveKeyBits, iv, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAlgorithmParameterSpec = (Elastos::Security::Spec::IAlgorithmParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IAlgorithmParameterSpec);
        if (*__IAlgorithmParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 effectiveKeyBits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(effectiveKeyBits, iv, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 effectiveKeyBits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(effectiveKeyBits, iv, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 effectiveKeyBits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(effectiveKeyBits, iv, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 effectiveKeyBits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ Elastosx::Crypto::Spec::IRC2ParameterSpec** __IRC2ParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(effectiveKeyBits, iv, offset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRC2ParameterSpec = (Elastosx::Crypto::Spec::IRC2ParameterSpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IRC2ParameterSpec);
        if (*__IRC2ParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 effectiveKeyBits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec** __IAlgorithmParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(effectiveKeyBits, iv, offset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAlgorithmParameterSpec = (Elastos::Security::Spec::IAlgorithmParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IAlgorithmParameterSpec);
        if (*__IAlgorithmParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 effectiveKeyBits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(effectiveKeyBits, iv, offset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 effectiveKeyBits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(effectiveKeyBits, iv, offset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 effectiveKeyBits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(effectiveKeyBits, iv, offset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
class CRC5ParameterSpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 ver,
        /* [in] */ _ELASTOS Int32 rounds,
        /* [in] */ _ELASTOS Int32 wordSize,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICRC5ParameterSpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CRC5ParameterSpec, RGM_SAME_DOMAIN,
                EIID_ICRC5ParameterSpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithVerRoundsWordSize(ver, rounds, wordSize, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 ver,
        /* [in] */ _ELASTOS Int32 rounds,
        /* [in] */ _ELASTOS Int32 wordSize,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICRC5ParameterSpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CRC5ParameterSpec, RGM_SAME_DOMAIN,
                EIID_ICRC5ParameterSpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithVerRoundsWordSizeIv(ver, rounds, wordSize, iv, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 ver,
        /* [in] */ _ELASTOS Int32 rounds,
        /* [in] */ _ELASTOS Int32 wordSize,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICRC5ParameterSpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CRC5ParameterSpec, RGM_SAME_DOMAIN,
                EIID_ICRC5ParameterSpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithVerRoundsWordSizeIvOffset(ver, rounds, wordSize, iv, offset, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 ver,
        /* [in] */ _ELASTOS Int32 rounds,
        /* [in] */ _ELASTOS Int32 wordSize,
        /* [out] */ Elastosx::Crypto::Spec::IRC5ParameterSpec** __IRC5ParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ver, rounds, wordSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRC5ParameterSpec = (Elastosx::Crypto::Spec::IRC5ParameterSpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IRC5ParameterSpec);
        if (*__IRC5ParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 ver,
        /* [in] */ _ELASTOS Int32 rounds,
        /* [in] */ _ELASTOS Int32 wordSize,
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec** __IAlgorithmParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ver, rounds, wordSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAlgorithmParameterSpec = (Elastos::Security::Spec::IAlgorithmParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IAlgorithmParameterSpec);
        if (*__IAlgorithmParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 ver,
        /* [in] */ _ELASTOS Int32 rounds,
        /* [in] */ _ELASTOS Int32 wordSize,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ver, rounds, wordSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 ver,
        /* [in] */ _ELASTOS Int32 rounds,
        /* [in] */ _ELASTOS Int32 wordSize,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ver, rounds, wordSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 ver,
        /* [in] */ _ELASTOS Int32 rounds,
        /* [in] */ _ELASTOS Int32 wordSize,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ver, rounds, wordSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 ver,
        /* [in] */ _ELASTOS Int32 rounds,
        /* [in] */ _ELASTOS Int32 wordSize,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ Elastosx::Crypto::Spec::IRC5ParameterSpec** __IRC5ParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ver, rounds, wordSize, iv, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRC5ParameterSpec = (Elastosx::Crypto::Spec::IRC5ParameterSpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IRC5ParameterSpec);
        if (*__IRC5ParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 ver,
        /* [in] */ _ELASTOS Int32 rounds,
        /* [in] */ _ELASTOS Int32 wordSize,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec** __IAlgorithmParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ver, rounds, wordSize, iv, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAlgorithmParameterSpec = (Elastos::Security::Spec::IAlgorithmParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IAlgorithmParameterSpec);
        if (*__IAlgorithmParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 ver,
        /* [in] */ _ELASTOS Int32 rounds,
        /* [in] */ _ELASTOS Int32 wordSize,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ver, rounds, wordSize, iv, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 ver,
        /* [in] */ _ELASTOS Int32 rounds,
        /* [in] */ _ELASTOS Int32 wordSize,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ver, rounds, wordSize, iv, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 ver,
        /* [in] */ _ELASTOS Int32 rounds,
        /* [in] */ _ELASTOS Int32 wordSize,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ver, rounds, wordSize, iv, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 ver,
        /* [in] */ _ELASTOS Int32 rounds,
        /* [in] */ _ELASTOS Int32 wordSize,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ Elastosx::Crypto::Spec::IRC5ParameterSpec** __IRC5ParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ver, rounds, wordSize, iv, offset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRC5ParameterSpec = (Elastosx::Crypto::Spec::IRC5ParameterSpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_IRC5ParameterSpec);
        if (*__IRC5ParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 ver,
        /* [in] */ _ELASTOS Int32 rounds,
        /* [in] */ _ELASTOS Int32 wordSize,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec** __IAlgorithmParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ver, rounds, wordSize, iv, offset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAlgorithmParameterSpec = (Elastos::Security::Spec::IAlgorithmParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IAlgorithmParameterSpec);
        if (*__IAlgorithmParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 ver,
        /* [in] */ _ELASTOS Int32 rounds,
        /* [in] */ _ELASTOS Int32 wordSize,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ver, rounds, wordSize, iv, offset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 ver,
        /* [in] */ _ELASTOS Int32 rounds,
        /* [in] */ _ELASTOS Int32 wordSize,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ver, rounds, wordSize, iv, offset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 ver,
        /* [in] */ _ELASTOS Int32 rounds,
        /* [in] */ _ELASTOS Int32 wordSize,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iv,
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ver, rounds, wordSize, iv, offset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Crypto {
namespace Spec {
class CSecretKeySpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSecretKeySpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSecretKeySpec, RGM_SAME_DOMAIN,
                EIID_ICSecretKeySpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithKeyAlgorithm(key, algorithm, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 len,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSecretKeySpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSecretKeySpec, RGM_SAME_DOMAIN,
                EIID_ICSecretKeySpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithKeyOffsetLenAlgorithm(key, offset, len, algorithm, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastosx::Crypto::Spec::ISecretKeySpec** __ISecretKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISecretKeySpec = (Elastosx::Crypto::Spec::ISecretKeySpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_ISecretKeySpec);
        if (*__ISecretKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastosx::Crypto::ISecretKey** __ISecretKey)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISecretKey = (Elastosx::Crypto::ISecretKey*)__pNewObj->Probe(Elastosx::Crypto::EIID_ISecretKey);
        if (*__ISecretKey) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Security::IKey** __IKey)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKey = (Elastos::Security::IKey*)__pNewObj->Probe(Elastos::Security::EIID_IKey);
        if (*__IKey) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Security::Spec::IKeySpec** __IKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeySpec = (Elastos::Security::Spec::IKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IKeySpec);
        if (*__IKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 len,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastosx::Crypto::Spec::ISecretKeySpec** __ISecretKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, offset, len, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISecretKeySpec = (Elastosx::Crypto::Spec::ISecretKeySpec*)__pNewObj->Probe(Elastosx::Crypto::Spec::EIID_ISecretKeySpec);
        if (*__ISecretKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 len,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastosx::Crypto::ISecretKey** __ISecretKey)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, offset, len, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISecretKey = (Elastosx::Crypto::ISecretKey*)__pNewObj->Probe(Elastosx::Crypto::EIID_ISecretKey);
        if (*__ISecretKey) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 len,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Security::IKey** __IKey)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, offset, len, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKey = (Elastos::Security::IKey*)__pNewObj->Probe(Elastos::Security::EIID_IKey);
        if (*__IKey) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 len,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Security::Spec::IKeySpec** __IKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, offset, len, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeySpec = (Elastos::Security::Spec::IKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IKeySpec);
        if (*__IKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 len,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, offset, len, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 len,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, offset, len, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 len,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, offset, len, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 len,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(key, offset, len, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Net {
class CDefaultServerSocketFactory
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastosx::Net::IServerSocketFactory** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultServerSocketFactory, RGM_SAME_DOMAIN, Elastosx::Net::EIID_IServerSocketFactory, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultServerSocketFactory, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultServerSocketFactory, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultServerSocketFactory, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastosx {
namespace Net {
class CDefaultSocketFactory
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastosx::Net::ISocketFactory** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultSocketFactory, RGM_SAME_DOMAIN, Elastosx::Net::EIID_ISocketFactory, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultSocketFactory, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultSocketFactory, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultSocketFactory, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastosx {
namespace Net {
class CServerSocketFactoryHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Net::IServerSocketFactoryHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CServerSocketFactoryHelper, RGM_SAME_DOMAIN, Elastosx::Net::EIID_IServerSocketFactoryHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CServerSocketFactoryHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CServerSocketFactoryHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CServerSocketFactoryHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastosx {
namespace Net {
class CSocketFactoryHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Net::ISocketFactoryHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSocketFactoryHelper, RGM_SAME_DOMAIN, Elastosx::Net::EIID_ISocketFactoryHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSocketFactoryHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSocketFactoryHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSocketFactoryHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
class CCertPathTrustManagerParameters
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Security::Cert::ICertPathParameters * parameters,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCertPathTrustManagerParametersClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCertPathTrustManagerParameters, RGM_SAME_DOMAIN,
                EIID_ICCertPathTrustManagerParametersClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithParameters(parameters, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ICertPathParameters * parameters,
        /* [out] */ Elastosx::Net::Ssl::ICertPathTrustManagerParameters** __ICertPathTrustManagerParameters)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parameters, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICertPathTrustManagerParameters = (Elastosx::Net::Ssl::ICertPathTrustManagerParameters*)__pNewObj->Probe(Elastosx::Net::Ssl::EIID_ICertPathTrustManagerParameters);
        if (*__ICertPathTrustManagerParameters) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ICertPathParameters * parameters,
        /* [out] */ Elastosx::Net::Ssl::IManagerFactoryParameters** __IManagerFactoryParameters)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parameters, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IManagerFactoryParameters = (Elastosx::Net::Ssl::IManagerFactoryParameters*)__pNewObj->Probe(Elastosx::Net::Ssl::EIID_IManagerFactoryParameters);
        if (*__IManagerFactoryParameters) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ICertPathParameters * parameters,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parameters, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ICertPathParameters * parameters,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parameters, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ICertPathParameters * parameters,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parameters, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
class CDefaultHostnameVerifier
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastosx::Net::Ssl::IDefaultHostnameVerifier** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultHostnameVerifier, RGM_SAME_DOMAIN, Elastosx::Net::Ssl::EIID_IDefaultHostnameVerifier, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastosx::Net::Ssl::IHostnameVerifier** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultHostnameVerifier, RGM_SAME_DOMAIN, Elastosx::Net::Ssl::EIID_IHostnameVerifier, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultHostnameVerifier, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultHostnameVerifier, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultHostnameVerifier, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
class CDefaultSSLServerSocketFactory
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& mes,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDefaultSSLServerSocketFactoryClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDefaultSSLServerSocketFactory, RGM_SAME_DOMAIN,
                EIID_ICDefaultSSLServerSocketFactoryClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithMes(mes, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& mes,
        /* [out] */ Elastosx::Net::Ssl::ISSLServerSocketFactory** __ISSLServerSocketFactory)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mes, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISSLServerSocketFactory = (Elastosx::Net::Ssl::ISSLServerSocketFactory*)__pNewObj->Probe(Elastosx::Net::Ssl::EIID_ISSLServerSocketFactory);
        if (*__ISSLServerSocketFactory) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& mes,
        /* [out] */ Elastosx::Net::IServerSocketFactory** __IServerSocketFactory)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mes, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IServerSocketFactory = (Elastosx::Net::IServerSocketFactory*)__pNewObj->Probe(Elastosx::Net::EIID_IServerSocketFactory);
        if (*__IServerSocketFactory) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& mes,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mes, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& mes,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mes, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& mes,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mes, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
class CDefaultSSLSocketFactory
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& mes,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDefaultSSLSocketFactoryClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDefaultSSLSocketFactory, RGM_SAME_DOMAIN,
                EIID_ICDefaultSSLSocketFactoryClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithMes(mes, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& mes,
        /* [out] */ Elastosx::Net::Ssl::ISSLSocketFactory** __ISSLSocketFactory)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mes, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISSLSocketFactory = (Elastosx::Net::Ssl::ISSLSocketFactory*)__pNewObj->Probe(Elastosx::Net::Ssl::EIID_ISSLSocketFactory);
        if (*__ISSLSocketFactory) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& mes,
        /* [out] */ Elastosx::Net::ISocketFactory** __ISocketFactory)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mes, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISocketFactory = (Elastosx::Net::ISocketFactory*)__pNewObj->Probe(Elastosx::Net::EIID_ISocketFactory);
        if (*__ISocketFactory) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& mes,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mes, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& mes,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mes, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& mes,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mes, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
class CDistinguishedNameParser
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastosx::Security::Auth::X500::IX500Principal * principal,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDistinguishedNameParserClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDistinguishedNameParser, RGM_SAME_DOMAIN,
                EIID_ICDistinguishedNameParserClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPrincipal(principal, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Security::Auth::X500::IX500Principal * principal,
        /* [out] */ Elastosx::Net::Ssl::IDistinguishedNameParser** __IDistinguishedNameParser)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(principal, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDistinguishedNameParser = (Elastosx::Net::Ssl::IDistinguishedNameParser*)__pNewObj->Probe(Elastosx::Net::Ssl::EIID_IDistinguishedNameParser);
        if (*__IDistinguishedNameParser) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Security::Auth::X500::IX500Principal * principal,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(principal, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Security::Auth::X500::IX500Principal * principal,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(principal, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Security::Auth::X500::IX500Principal * principal,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(principal, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
class CHandshakeCompletedEvent
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastosx::Net::Ssl::ISSLSocket * sock,
        /* [in] */ Elastosx::Net::Ssl::ISSLSession * s,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICHandshakeCompletedEventClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CHandshakeCompletedEvent, RGM_SAME_DOMAIN,
                EIID_ICHandshakeCompletedEventClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSockS(sock, s, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::ISSLSocket * sock,
        /* [in] */ Elastosx::Net::Ssl::ISSLSession * s,
        /* [out] */ Elastosx::Net::Ssl::IHandshakeCompletedEvent** __IHandshakeCompletedEvent)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sock, s, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IHandshakeCompletedEvent = (Elastosx::Net::Ssl::IHandshakeCompletedEvent*)__pNewObj->Probe(Elastosx::Net::Ssl::EIID_IHandshakeCompletedEvent);
        if (*__IHandshakeCompletedEvent) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::ISSLSocket * sock,
        /* [in] */ Elastosx::Net::Ssl::ISSLSession * s,
        /* [out] */ Elastos::Utility::IEventObject** __IEventObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sock, s, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IEventObject = (Elastos::Utility::IEventObject*)__pNewObj->Probe(Elastos::Utility::EIID_IEventObject);
        if (*__IEventObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::ISSLSocket * sock,
        /* [in] */ Elastosx::Net::Ssl::ISSLSession * s,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sock, s, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::ISSLSocket * sock,
        /* [in] */ Elastosx::Net::Ssl::ISSLSession * s,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sock, s, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::ISSLSocket * sock,
        /* [in] */ Elastosx::Net::Ssl::ISSLSession * s,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sock, s, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::ISSLSocket * sock,
        /* [in] */ Elastosx::Net::Ssl::ISSLSession * s,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sock, s, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
class CKeyManagerFactory
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastosx::Net::Ssl::IKeyManagerFactorySpi * factorySpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICKeyManagerFactoryClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CKeyManagerFactory, RGM_SAME_DOMAIN,
                EIID_ICKeyManagerFactoryClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFactorySpiProviderAlgorithm(factorySpi, provider, algorithm, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::IKeyManagerFactorySpi * factorySpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastosx::Net::Ssl::IKeyManagerFactory** __IKeyManagerFactory)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(factorySpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeyManagerFactory = (Elastosx::Net::Ssl::IKeyManagerFactory*)__pNewObj->Probe(Elastosx::Net::Ssl::EIID_IKeyManagerFactory);
        if (*__IKeyManagerFactory) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::IKeyManagerFactorySpi * factorySpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(factorySpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::IKeyManagerFactorySpi * factorySpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(factorySpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::IKeyManagerFactorySpi * factorySpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(factorySpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
class CKeyManagerFactoryHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Net::Ssl::IKeyManagerFactoryHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyManagerFactoryHelper, RGM_SAME_DOMAIN, Elastosx::Net::Ssl::EIID_IKeyManagerFactoryHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyManagerFactoryHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyManagerFactoryHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyManagerFactoryHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
class CHttpsURLConnectionHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Net::Ssl::IHttpsURLConnectionHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHttpsURLConnectionHelper, RGM_SAME_DOMAIN, Elastosx::Net::Ssl::EIID_IHttpsURLConnectionHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHttpsURLConnectionHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHttpsURLConnectionHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHttpsURLConnectionHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
class CSSLContext
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastosx::Net::Ssl::ISSLContextSpi * contextSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& protocol,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSSLContextClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSSLContext, RGM_SAME_DOMAIN,
                EIID_ICSSLContextClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithContextSpiProviderProtocol(contextSpi, provider, protocol, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::ISSLContextSpi * contextSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& protocol,
        /* [out] */ Elastosx::Net::Ssl::ISSLContext** __ISSLContext)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(contextSpi, provider, protocol, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISSLContext = (Elastosx::Net::Ssl::ISSLContext*)__pNewObj->Probe(Elastosx::Net::Ssl::EIID_ISSLContext);
        if (*__ISSLContext) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::ISSLContextSpi * contextSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& protocol,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(contextSpi, provider, protocol, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::ISSLContextSpi * contextSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& protocol,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(contextSpi, provider, protocol, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::ISSLContextSpi * contextSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& protocol,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(contextSpi, provider, protocol, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
class CSSLContextHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Net::Ssl::ISSLContextHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSSLContextHelper, RGM_SAME_DOMAIN, Elastosx::Net::Ssl::EIID_ISSLContextHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSSLContextHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSSLContextHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSSLContextHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
class CSSLEngineResult
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastosx::Net::Ssl::SSLEngineResult_Status status,
        /* [in] */ Elastosx::Net::Ssl::SSLEngineResult_HandshakeStatus handshakeStatus,
        /* [in] */ _ELASTOS Int32 bytesConsumed,
        /* [in] */ _ELASTOS Int32 bytesProduced,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSSLEngineResultClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSSLEngineResult, RGM_SAME_DOMAIN,
                EIID_ICSSLEngineResultClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithStatusHandshakeStatusBytesConsumedBytesProduced(status, handshakeStatus, bytesConsumed, bytesProduced, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::SSLEngineResult_Status status,
        /* [in] */ Elastosx::Net::Ssl::SSLEngineResult_HandshakeStatus handshakeStatus,
        /* [in] */ _ELASTOS Int32 bytesConsumed,
        /* [in] */ _ELASTOS Int32 bytesProduced,
        /* [out] */ Elastosx::Net::Ssl::ISSLEngineResult** __ISSLEngineResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(status, handshakeStatus, bytesConsumed, bytesProduced, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISSLEngineResult = (Elastosx::Net::Ssl::ISSLEngineResult*)__pNewObj->Probe(Elastosx::Net::Ssl::EIID_ISSLEngineResult);
        if (*__ISSLEngineResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::SSLEngineResult_Status status,
        /* [in] */ Elastosx::Net::Ssl::SSLEngineResult_HandshakeStatus handshakeStatus,
        /* [in] */ _ELASTOS Int32 bytesConsumed,
        /* [in] */ _ELASTOS Int32 bytesProduced,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(status, handshakeStatus, bytesConsumed, bytesProduced, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::SSLEngineResult_Status status,
        /* [in] */ Elastosx::Net::Ssl::SSLEngineResult_HandshakeStatus handshakeStatus,
        /* [in] */ _ELASTOS Int32 bytesConsumed,
        /* [in] */ _ELASTOS Int32 bytesProduced,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(status, handshakeStatus, bytesConsumed, bytesProduced, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::SSLEngineResult_Status status,
        /* [in] */ Elastosx::Net::Ssl::SSLEngineResult_HandshakeStatus handshakeStatus,
        /* [in] */ _ELASTOS Int32 bytesConsumed,
        /* [in] */ _ELASTOS Int32 bytesProduced,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(status, handshakeStatus, bytesConsumed, bytesProduced, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
class CSSLParameters
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * cipherSuites,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSSLParametersClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSSLParameters, RGM_SAME_DOMAIN,
                EIID_ICSSLParametersClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCipherSuites(cipherSuites, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * cipherSuites,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * protocols,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSSLParametersClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSSLParameters, RGM_SAME_DOMAIN,
                EIID_ICSSLParametersClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCipherSuitesProtocols(cipherSuites, protocols, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastosx::Net::Ssl::ISSLParameters** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSSLParameters, RGM_SAME_DOMAIN, Elastosx::Net::Ssl::EIID_ISSLParameters, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSSLParameters, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSSLParameters, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSSLParameters, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * cipherSuites,
        /* [out] */ Elastosx::Net::Ssl::ISSLParameters** __ISSLParameters)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cipherSuites, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISSLParameters = (Elastosx::Net::Ssl::ISSLParameters*)__pNewObj->Probe(Elastosx::Net::Ssl::EIID_ISSLParameters);
        if (*__ISSLParameters) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * cipherSuites,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cipherSuites, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * cipherSuites,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cipherSuites, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * cipherSuites,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cipherSuites, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * cipherSuites,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * protocols,
        /* [out] */ Elastosx::Net::Ssl::ISSLParameters** __ISSLParameters)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cipherSuites, protocols, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISSLParameters = (Elastosx::Net::Ssl::ISSLParameters*)__pNewObj->Probe(Elastosx::Net::Ssl::EIID_ISSLParameters);
        if (*__ISSLParameters) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * cipherSuites,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * protocols,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cipherSuites, protocols, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * cipherSuites,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * protocols,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cipherSuites, protocols, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * cipherSuites,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * protocols,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cipherSuites, protocols, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
class CSSLPermission
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSSLPermissionClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSSLPermission, RGM_SAME_DOMAIN,
                EIID_ICSSLPermissionClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithName(name, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSSLPermissionClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSSLPermission, RGM_SAME_DOMAIN,
                EIID_ICSSLPermissionClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithNameActions(name, actions, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Security::IPermission** __IPermission)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPermission = (Elastos::Security::IPermission*)__pNewObj->Probe(Elastos::Security::EIID_IPermission);
        if (*__IPermission) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Security::IGuard** __IGuard)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IGuard = (Elastos::Security::IGuard*)__pNewObj->Probe(Elastos::Security::EIID_IGuard);
        if (*__IGuard) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ Elastos::Security::IPermission** __IPermission)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, actions, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPermission = (Elastos::Security::IPermission*)__pNewObj->Probe(Elastos::Security::EIID_IPermission);
        if (*__IPermission) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, actions, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ Elastos::Security::IGuard** __IGuard)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, actions, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IGuard = (Elastos::Security::IGuard*)__pNewObj->Probe(Elastos::Security::EIID_IGuard);
        if (*__IGuard) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, actions, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, actions, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, actions, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
class CSSLServerSocketFactoryHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Net::Ssl::ISSLServerSocketFactoryHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSSLServerSocketFactoryHelper, RGM_SAME_DOMAIN, Elastosx::Net::Ssl::EIID_ISSLServerSocketFactoryHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSSLServerSocketFactoryHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSSLServerSocketFactoryHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSSLServerSocketFactoryHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
class CSSLSessionBindingEvent
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastosx::Net::Ssl::ISSLSession * session,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSSLSessionBindingEventClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSSLSessionBindingEvent, RGM_SAME_DOMAIN,
                EIID_ICSSLSessionBindingEventClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSessionName(session, name, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::ISSLSession * session,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastosx::Net::Ssl::ISSLSessionBindingEvent** __ISSLSessionBindingEvent)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(session, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISSLSessionBindingEvent = (Elastosx::Net::Ssl::ISSLSessionBindingEvent*)__pNewObj->Probe(Elastosx::Net::Ssl::EIID_ISSLSessionBindingEvent);
        if (*__ISSLSessionBindingEvent) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::ISSLSession * session,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Utility::IEventObject** __IEventObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(session, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IEventObject = (Elastos::Utility::IEventObject*)__pNewObj->Probe(Elastos::Utility::EIID_IEventObject);
        if (*__IEventObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::ISSLSession * session,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(session, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::ISSLSession * session,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(session, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::ISSLSession * session,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(session, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::ISSLSession * session,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(session, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
class CSSLSocketFactoryHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Net::Ssl::ISSLSocketFactoryHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSSLSocketFactoryHelper, RGM_SAME_DOMAIN, Elastosx::Net::Ssl::EIID_ISSLSocketFactoryHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSSLSocketFactoryHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSSLSocketFactoryHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSSLSocketFactoryHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
class CTrustManagerFactory
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastosx::Net::Ssl::ITrustManagerFactorySpi * factorySpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICTrustManagerFactoryClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CTrustManagerFactory, RGM_SAME_DOMAIN,
                EIID_ICTrustManagerFactoryClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFactorySpiProviderAlgorithm(factorySpi, provider, algorithm, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::ITrustManagerFactorySpi * factorySpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastosx::Net::Ssl::ITrustManagerFactory** __ITrustManagerFactory)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(factorySpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ITrustManagerFactory = (Elastosx::Net::Ssl::ITrustManagerFactory*)__pNewObj->Probe(Elastosx::Net::Ssl::EIID_ITrustManagerFactory);
        if (*__ITrustManagerFactory) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::ITrustManagerFactorySpi * factorySpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(factorySpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::ITrustManagerFactorySpi * factorySpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(factorySpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Net::Ssl::ITrustManagerFactorySpi * factorySpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(factorySpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Net {
namespace Ssl {
class CTrustManagerFactoryHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Net::Ssl::ITrustManagerFactoryHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTrustManagerFactoryHelper, RGM_SAME_DOMAIN, Elastosx::Net::Ssl::EIID_ITrustManagerFactoryHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTrustManagerFactoryHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTrustManagerFactoryHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTrustManagerFactoryHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
namespace Callback {
class CPasswordCallback
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& prompt,
        /* [in] */ _ELASTOS Boolean echoOn,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPasswordCallbackClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPasswordCallback, RGM_SAME_DOMAIN,
                EIID_ICPasswordCallbackClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPromptEchoOn(prompt, echoOn, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& prompt,
        /* [in] */ _ELASTOS Boolean echoOn,
        /* [out] */ Elastosx::Security::Auth::Callback::ICallback** __ICallback)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(prompt, echoOn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICallback = (Elastosx::Security::Auth::Callback::ICallback*)__pNewObj->Probe(Elastosx::Security::Auth::Callback::EIID_ICallback);
        if (*__ICallback) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& prompt,
        /* [in] */ _ELASTOS Boolean echoOn,
        /* [out] */ Elastosx::Security::Auth::Callback::IPasswordCallback** __IPasswordCallback)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(prompt, echoOn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPasswordCallback = (Elastosx::Security::Auth::Callback::IPasswordCallback*)__pNewObj->Probe(Elastosx::Security::Auth::Callback::EIID_IPasswordCallback);
        if (*__IPasswordCallback) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& prompt,
        /* [in] */ _ELASTOS Boolean echoOn,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(prompt, echoOn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& prompt,
        /* [in] */ _ELASTOS Boolean echoOn,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(prompt, echoOn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& prompt,
        /* [in] */ _ELASTOS Boolean echoOn,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(prompt, echoOn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
namespace X500 {
class CX500Principal
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * name1,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICX500PrincipalClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CX500Principal, RGM_SAME_DOMAIN,
                EIID_ICX500PrincipalClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithName1(name1, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICX500PrincipalClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CX500Principal, RGM_SAME_DOMAIN,
                EIID_ICX500PrincipalClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIs(is, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& name2,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICX500PrincipalClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CX500Principal, RGM_SAME_DOMAIN,
                EIID_ICX500PrincipalClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithName2(name2, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ Elastos::Utility::IMap * keywordMap,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICX500PrincipalClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CX500Principal, RGM_SAME_DOMAIN,
                EIID_ICX500PrincipalClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithNameKeywordMap(name, keywordMap, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * name1,
        /* [out] */ Elastos::Security::IPrincipal** __IPrincipal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name1, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPrincipal = (Elastos::Security::IPrincipal*)__pNewObj->Probe(Elastos::Security::EIID_IPrincipal);
        if (*__IPrincipal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * name1,
        /* [out] */ Elastosx::Security::Auth::X500::IX500Principal** __IX500Principal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name1, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IX500Principal = (Elastosx::Security::Auth::X500::IX500Principal*)__pNewObj->Probe(Elastosx::Security::Auth::X500::EIID_IX500Principal);
        if (*__IX500Principal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * name1,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name1, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * name1,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name1, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * name1,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name1, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ Elastos::Security::IPrincipal** __IPrincipal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPrincipal = (Elastos::Security::IPrincipal*)__pNewObj->Probe(Elastos::Security::EIID_IPrincipal);
        if (*__IPrincipal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ Elastosx::Security::Auth::X500::IX500Principal** __IX500Principal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IX500Principal = (Elastosx::Security::Auth::X500::IX500Principal*)__pNewObj->Probe(Elastosx::Security::Auth::X500::EIID_IX500Principal);
        if (*__IX500Principal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name2,
        /* [out] */ Elastos::Security::IPrincipal** __IPrincipal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name2, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPrincipal = (Elastos::Security::IPrincipal*)__pNewObj->Probe(Elastos::Security::EIID_IPrincipal);
        if (*__IPrincipal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name2,
        /* [out] */ Elastosx::Security::Auth::X500::IX500Principal** __IX500Principal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name2, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IX500Principal = (Elastosx::Security::Auth::X500::IX500Principal*)__pNewObj->Probe(Elastosx::Security::Auth::X500::EIID_IX500Principal);
        if (*__IX500Principal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name2,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name2, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name2,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name2, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name2,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name2, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ Elastos::Utility::IMap * keywordMap,
        /* [out] */ Elastos::Security::IPrincipal** __IPrincipal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, keywordMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPrincipal = (Elastos::Security::IPrincipal*)__pNewObj->Probe(Elastos::Security::EIID_IPrincipal);
        if (*__IPrincipal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ Elastos::Utility::IMap * keywordMap,
        /* [out] */ Elastosx::Security::Auth::X500::IX500Principal** __IX500Principal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, keywordMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IX500Principal = (Elastosx::Security::Auth::X500::IX500Principal*)__pNewObj->Probe(Elastosx::Security::Auth::X500::EIID_IX500Principal);
        if (*__IX500Principal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ Elastos::Utility::IMap * keywordMap,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, keywordMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ Elastos::Utility::IMap * keywordMap,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, keywordMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ Elastos::Utility::IMap * keywordMap,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, keywordMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
class CAuthPermission
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAuthPermissionClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAuthPermission, RGM_SAME_DOMAIN,
                EIID_ICAuthPermissionClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithName(name, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAuthPermissionClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAuthPermission, RGM_SAME_DOMAIN,
                EIID_ICAuthPermissionClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithNameActions(name, actions, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastosx::Security::Auth::IAuthPermission** __IAuthPermission)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAuthPermission = (Elastosx::Security::Auth::IAuthPermission*)__pNewObj->Probe(Elastosx::Security::Auth::EIID_IAuthPermission);
        if (*__IAuthPermission) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Security::IPermission** __IPermission)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPermission = (Elastos::Security::IPermission*)__pNewObj->Probe(Elastos::Security::EIID_IPermission);
        if (*__IPermission) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Security::IGuard** __IGuard)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IGuard = (Elastos::Security::IGuard*)__pNewObj->Probe(Elastos::Security::EIID_IGuard);
        if (*__IGuard) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ Elastosx::Security::Auth::IAuthPermission** __IAuthPermission)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, actions, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAuthPermission = (Elastosx::Security::Auth::IAuthPermission*)__pNewObj->Probe(Elastosx::Security::Auth::EIID_IAuthPermission);
        if (*__IAuthPermission) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ Elastos::Security::IPermission** __IPermission)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, actions, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPermission = (Elastos::Security::IPermission*)__pNewObj->Probe(Elastos::Security::EIID_IPermission);
        if (*__IPermission) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ Elastos::Security::IGuard** __IGuard)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, actions, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IGuard = (Elastos::Security::IGuard*)__pNewObj->Probe(Elastos::Security::EIID_IGuard);
        if (*__IGuard) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, actions, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, actions, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, actions, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
class CPrivateCredentialPermission
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& action,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPrivateCredentialPermissionClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPrivateCredentialPermission, RGM_SAME_DOMAIN,
                EIID_ICPrivateCredentialPermissionClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithNameAction(name, action, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& action,
        /* [out] */ Elastos::Security::IGuard** __IGuard)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, action, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IGuard = (Elastos::Security::IGuard*)__pNewObj->Probe(Elastos::Security::EIID_IGuard);
        if (*__IGuard) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& action,
        /* [out] */ Elastos::Security::IPermission** __IPermission)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, action, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPermission = (Elastos::Security::IPermission*)__pNewObj->Probe(Elastos::Security::EIID_IPermission);
        if (*__IPermission) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& action,
        /* [out] */ Elastosx::Security::Auth::IPrivateCredentialPermission** __IPrivateCredentialPermission)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, action, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPrivateCredentialPermission = (Elastosx::Security::Auth::IPrivateCredentialPermission*)__pNewObj->Probe(Elastosx::Security::Auth::EIID_IPrivateCredentialPermission);
        if (*__IPrivateCredentialPermission) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& action,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, action, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& action,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, action, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& action,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, action, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
class CSubject
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Boolean readOnly,
        /* [in] */ Elastos::Utility::ISet * subjPrincipals,
        /* [in] */ Elastos::Utility::ISet * pubCredentials,
        /* [in] */ Elastos::Utility::ISet * privCredentials,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSubjectClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSubject, RGM_SAME_DOMAIN,
                EIID_ICSubjectClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithReadOnlySubjPrincipalsPubCredentialsPrivCredentials(readOnly, subjPrincipals, pubCredentials, privCredentials, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastosx::Security::Auth::ISubject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSubject, RGM_SAME_DOMAIN, Elastosx::Security::Auth::EIID_ISubject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSubject, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSubject, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSubject, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean readOnly,
        /* [in] */ Elastos::Utility::ISet * subjPrincipals,
        /* [in] */ Elastos::Utility::ISet * pubCredentials,
        /* [in] */ Elastos::Utility::ISet * privCredentials,
        /* [out] */ Elastosx::Security::Auth::ISubject** __ISubject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(readOnly, subjPrincipals, pubCredentials, privCredentials, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISubject = (Elastosx::Security::Auth::ISubject*)__pNewObj->Probe(Elastosx::Security::Auth::EIID_ISubject);
        if (*__ISubject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean readOnly,
        /* [in] */ Elastos::Utility::ISet * subjPrincipals,
        /* [in] */ Elastos::Utility::ISet * pubCredentials,
        /* [in] */ Elastos::Utility::ISet * privCredentials,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(readOnly, subjPrincipals, pubCredentials, privCredentials, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean readOnly,
        /* [in] */ Elastos::Utility::ISet * subjPrincipals,
        /* [in] */ Elastos::Utility::ISet * pubCredentials,
        /* [in] */ Elastos::Utility::ISet * privCredentials,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(readOnly, subjPrincipals, pubCredentials, privCredentials, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean readOnly,
        /* [in] */ Elastos::Utility::ISet * subjPrincipals,
        /* [in] */ Elastos::Utility::ISet * pubCredentials,
        /* [in] */ Elastos::Utility::ISet * privCredentials,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(readOnly, subjPrincipals, pubCredentials, privCredentials, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
class CSubjectHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Security::Auth::ISubjectHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSubjectHelper, RGM_SAME_DOMAIN, Elastosx::Security::Auth::EIID_ISubjectHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSubjectHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSubjectHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSubjectHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastosx {
namespace Security {
namespace Auth {
class CSubjectDomainCombiner
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastosx::Security::Auth::ISubject * sub,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSubjectDomainCombinerClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSubjectDomainCombiner, RGM_SAME_DOMAIN,
                EIID_ICSubjectDomainCombinerClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSub(sub, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Security::Auth::ISubject * sub,
        /* [out] */ Elastos::Security::IDomainCombiner** __IDomainCombiner)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sub, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDomainCombiner = (Elastos::Security::IDomainCombiner*)__pNewObj->Probe(Elastos::Security::EIID_IDomainCombiner);
        if (*__IDomainCombiner) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Security::Auth::ISubject * sub,
        /* [out] */ Elastosx::Security::Auth::ISubjectDomainCombiner** __ISubjectDomainCombiner)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sub, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISubjectDomainCombiner = (Elastosx::Security::Auth::ISubjectDomainCombiner*)__pNewObj->Probe(Elastosx::Security::Auth::EIID_ISubjectDomainCombiner);
        if (*__ISubjectDomainCombiner) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Security::Auth::ISubject * sub,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sub, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Security::Auth::ISubject * sub,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sub, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Security::Auth::ISubject * sub,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sub, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Security {
namespace Cert {
class CX509CertificateHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Security::Cert::IX509CertificateHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CX509CertificateHelper, RGM_SAME_DOMAIN, Elastosx::Security::Cert::EIID_IX509CertificateHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CX509CertificateHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CX509CertificateHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CX509CertificateHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastosx {
namespace Sql {
class CConnectionEvent
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastosx::Sql::IPooledConnection * theConnection,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICConnectionEventClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CConnectionEvent, RGM_SAME_DOMAIN,
                EIID_ICConnectionEventClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTheConnection(theConnection, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastosx::Sql::IPooledConnection * theConnection,
        /* [in] */ _ELASTOS ECode theException,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICConnectionEventClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CConnectionEvent, RGM_SAME_DOMAIN,
                EIID_ICConnectionEventClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTheConnectionTheException(theConnection, theException, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IPooledConnection * theConnection,
        /* [out] */ Elastosx::Sql::IConnectionEvent** __IConnectionEvent)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theConnection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IConnectionEvent = (Elastosx::Sql::IConnectionEvent*)__pNewObj->Probe(Elastosx::Sql::EIID_IConnectionEvent);
        if (*__IConnectionEvent) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IPooledConnection * theConnection,
        /* [out] */ Elastos::Utility::IEventObject** __IEventObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theConnection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IEventObject = (Elastos::Utility::IEventObject*)__pNewObj->Probe(Elastos::Utility::EIID_IEventObject);
        if (*__IEventObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IPooledConnection * theConnection,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theConnection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IPooledConnection * theConnection,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theConnection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IPooledConnection * theConnection,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theConnection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IPooledConnection * theConnection,
        /* [in] */ _ELASTOS ECode theException,
        /* [out] */ Elastosx::Sql::IConnectionEvent** __IConnectionEvent)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theConnection, theException, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IConnectionEvent = (Elastosx::Sql::IConnectionEvent*)__pNewObj->Probe(Elastosx::Sql::EIID_IConnectionEvent);
        if (*__IConnectionEvent) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IPooledConnection * theConnection,
        /* [in] */ _ELASTOS ECode theException,
        /* [out] */ Elastos::Utility::IEventObject** __IEventObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theConnection, theException, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IEventObject = (Elastos::Utility::IEventObject*)__pNewObj->Probe(Elastos::Utility::EIID_IEventObject);
        if (*__IEventObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IPooledConnection * theConnection,
        /* [in] */ _ELASTOS ECode theException,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theConnection, theException, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IPooledConnection * theConnection,
        /* [in] */ _ELASTOS ECode theException,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theConnection, theException, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IPooledConnection * theConnection,
        /* [in] */ _ELASTOS ECode theException,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theConnection, theException, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
namespace Elastosx {
namespace Sql {
class CRowSetEvent
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastosx::Sql::IRowSet * theSource,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICRowSetEventClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CRowSetEvent, RGM_SAME_DOMAIN,
                EIID_ICRowSetEventClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTheSource(theSource, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IRowSet * theSource,
        /* [out] */ Elastosx::Sql::IRowSetEvent** __IRowSetEvent)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theSource, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRowSetEvent = (Elastosx::Sql::IRowSetEvent*)__pNewObj->Probe(Elastosx::Sql::EIID_IRowSetEvent);
        if (*__IRowSetEvent) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IRowSet * theSource,
        /* [out] */ Elastos::Utility::IEventObject** __IEventObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theSource, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IEventObject = (Elastos::Utility::IEventObject*)__pNewObj->Probe(Elastos::Utility::EIID_IEventObject);
        if (*__IEventObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IRowSet * theSource,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theSource, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IRowSet * theSource,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theSource, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IRowSet * theSource,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theSource, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
namespace Elastosx {
namespace Sql {
class CStatementEvent
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastosx::Sql::IPooledConnection * con,
        /* [in] */ Elastos::Sql::IPreparedStatement * statement,
        /* [in] */ _ELASTOS ECode theException,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStatementEventClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStatementEvent, RGM_SAME_DOMAIN,
                EIID_ICStatementEventClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithConStatementTheException(con, statement, theException, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastosx::Sql::IPooledConnection * con,
        /* [in] */ Elastos::Sql::IPreparedStatement * statement,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStatementEventClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStatementEvent, RGM_SAME_DOMAIN,
                EIID_ICStatementEventClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithConStatement(con, statement, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IPooledConnection * con,
        /* [in] */ Elastos::Sql::IPreparedStatement * statement,
        /* [in] */ _ELASTOS ECode theException,
        /* [out] */ Elastosx::Sql::IStatementEvent** __IStatementEvent)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(con, statement, theException, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStatementEvent = (Elastosx::Sql::IStatementEvent*)__pNewObj->Probe(Elastosx::Sql::EIID_IStatementEvent);
        if (*__IStatementEvent) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IPooledConnection * con,
        /* [in] */ Elastos::Sql::IPreparedStatement * statement,
        /* [in] */ _ELASTOS ECode theException,
        /* [out] */ Elastos::Utility::IEventObject** __IEventObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(con, statement, theException, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IEventObject = (Elastos::Utility::IEventObject*)__pNewObj->Probe(Elastos::Utility::EIID_IEventObject);
        if (*__IEventObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IPooledConnection * con,
        /* [in] */ Elastos::Sql::IPreparedStatement * statement,
        /* [in] */ _ELASTOS ECode theException,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(con, statement, theException, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IPooledConnection * con,
        /* [in] */ Elastos::Sql::IPreparedStatement * statement,
        /* [in] */ _ELASTOS ECode theException,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(con, statement, theException, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IPooledConnection * con,
        /* [in] */ Elastos::Sql::IPreparedStatement * statement,
        /* [in] */ _ELASTOS ECode theException,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(con, statement, theException, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IPooledConnection * con,
        /* [in] */ Elastos::Sql::IPreparedStatement * statement,
        /* [out] */ Elastosx::Sql::IStatementEvent** __IStatementEvent)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(con, statement, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStatementEvent = (Elastosx::Sql::IStatementEvent*)__pNewObj->Probe(Elastosx::Sql::EIID_IStatementEvent);
        if (*__IStatementEvent) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IPooledConnection * con,
        /* [in] */ Elastos::Sql::IPreparedStatement * statement,
        /* [out] */ Elastos::Utility::IEventObject** __IEventObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(con, statement, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IEventObject = (Elastos::Utility::IEventObject*)__pNewObj->Probe(Elastos::Utility::EIID_IEventObject);
        if (*__IEventObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IPooledConnection * con,
        /* [in] */ Elastos::Sql::IPreparedStatement * statement,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(con, statement, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IPooledConnection * con,
        /* [in] */ Elastos::Sql::IPreparedStatement * statement,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(con, statement, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Sql::IPooledConnection * con,
        /* [in] */ Elastos::Sql::IPreparedStatement * statement,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(con, statement, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
namespace Elastosx {
namespace Xml {
namespace Namespace {
class CQName
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& localPart,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICQNameClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CQName, RGM_SAME_DOMAIN,
                EIID_ICQNameClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithNamespaceURILocalPart(namespaceURI, localPart, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& localPart,
        /* [in] */ const _ELASTOS String& prefix,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICQNameClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CQName, RGM_SAME_DOMAIN,
                EIID_ICQNameClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithNamespaceURILocalPartPrefix(namespaceURI, localPart, prefix, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& localPart,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICQNameClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CQName, RGM_SAME_DOMAIN,
                EIID_ICQNameClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithLocalPart(localPart, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& localPart,
        /* [out] */ Elastosx::Xml::Namespace::IQName** __IQName)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(namespaceURI, localPart, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IQName = (Elastosx::Xml::Namespace::IQName*)__pNewObj->Probe(Elastosx::Xml::Namespace::EIID_IQName);
        if (*__IQName) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& localPart,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(namespaceURI, localPart, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& localPart,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(namespaceURI, localPart, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& localPart,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(namespaceURI, localPart, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& localPart,
        /* [in] */ const _ELASTOS String& prefix,
        /* [out] */ Elastosx::Xml::Namespace::IQName** __IQName)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(namespaceURI, localPart, prefix, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IQName = (Elastosx::Xml::Namespace::IQName*)__pNewObj->Probe(Elastosx::Xml::Namespace::EIID_IQName);
        if (*__IQName) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& localPart,
        /* [in] */ const _ELASTOS String& prefix,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(namespaceURI, localPart, prefix, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& localPart,
        /* [in] */ const _ELASTOS String& prefix,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(namespaceURI, localPart, prefix, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& localPart,
        /* [in] */ const _ELASTOS String& prefix,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(namespaceURI, localPart, prefix, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& localPart,
        /* [out] */ Elastosx::Xml::Namespace::IQName** __IQName)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(localPart, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IQName = (Elastosx::Xml::Namespace::IQName*)__pNewObj->Probe(Elastosx::Xml::Namespace::EIID_IQName);
        if (*__IQName) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& localPart,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(localPart, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& localPart,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(localPart, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& localPart,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(localPart, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Namespace {
class CQNameHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Xml::Namespace::IQNameHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CQNameHelper, RGM_SAME_DOMAIN, Elastosx::Xml::Namespace::EIID_IQNameHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CQNameHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CQNameHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CQNameHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Datatype {
class CDatatypeConstants
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Xml::Datatype::IDatatypeConstants** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatatypeConstants, RGM_SAME_DOMAIN, Elastosx::Xml::Datatype::EIID_IDatatypeConstants, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatatypeConstants, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatatypeConstants, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatatypeConstants, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Datatype {
class CDatatypeFactoryHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Xml::Datatype::IDatatypeFactoryHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatatypeFactoryHelper, RGM_SAME_DOMAIN, Elastosx::Xml::Datatype::EIID_IDatatypeFactoryHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatatypeFactoryHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatatypeFactoryHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatatypeFactoryHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Parsers {
class CDocumentBuilderFactoryHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Xml::Parsers::IDocumentBuilderFactoryHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDocumentBuilderFactoryHelper, RGM_SAME_DOMAIN, Elastosx::Xml::Parsers::EIID_IDocumentBuilderFactoryHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDocumentBuilderFactoryHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDocumentBuilderFactoryHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDocumentBuilderFactoryHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Parsers {
class CSAXParserFactoryHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Xml::Parsers::ISAXParserFactoryHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSAXParserFactoryHelper, RGM_SAME_DOMAIN, Elastosx::Xml::Parsers::EIID_ISAXParserFactoryHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSAXParserFactoryHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSAXParserFactoryHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSAXParserFactoryHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Validation {
class CSchemaFactoryHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastosx::Xml::Validation::ISchemaFactoryHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSchemaFactoryHelper, RGM_SAME_DOMAIN, Elastosx::Xml::Validation::EIID_ISchemaFactoryHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSchemaFactoryHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSchemaFactoryHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSchemaFactoryHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
namespace Dom {
class CDOMSource
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Org::W3c::Dom::INode * n,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDOMSourceClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDOMSource, RGM_SAME_DOMAIN,
                EIID_ICDOMSourceClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithN(n, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ const _ELASTOS String& systemID,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDOMSourceClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDOMSource, RGM_SAME_DOMAIN,
                EIID_ICDOMSourceClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithNodeSystemID(node, systemID, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastosx::Xml::Transform::Dom::IDOMSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDOMSource, RGM_SAME_DOMAIN, Elastosx::Xml::Transform::Dom::EIID_IDOMSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastosx::Xml::Transform::ISource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDOMSource, RGM_SAME_DOMAIN, Elastosx::Xml::Transform::EIID_ISource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDOMSource, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDOMSource, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDOMSource, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * n,
        /* [out] */ Elastosx::Xml::Transform::Dom::IDOMSource** __IDOMSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(n, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDOMSource = (Elastosx::Xml::Transform::Dom::IDOMSource*)__pNewObj->Probe(Elastosx::Xml::Transform::Dom::EIID_IDOMSource);
        if (*__IDOMSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * n,
        /* [out] */ Elastosx::Xml::Transform::ISource** __ISource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(n, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISource = (Elastosx::Xml::Transform::ISource*)__pNewObj->Probe(Elastosx::Xml::Transform::EIID_ISource);
        if (*__ISource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * n,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(n, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * n,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(n, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * n,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(n, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ const _ELASTOS String& systemID,
        /* [out] */ Elastosx::Xml::Transform::Dom::IDOMSource** __IDOMSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, systemID, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDOMSource = (Elastosx::Xml::Transform::Dom::IDOMSource*)__pNewObj->Probe(Elastosx::Xml::Transform::Dom::EIID_IDOMSource);
        if (*__IDOMSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ const _ELASTOS String& systemID,
        /* [out] */ Elastosx::Xml::Transform::ISource** __ISource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, systemID, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISource = (Elastosx::Xml::Transform::ISource*)__pNewObj->Probe(Elastosx::Xml::Transform::EIID_ISource);
        if (*__ISource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ const _ELASTOS String& systemID,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, systemID, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ const _ELASTOS String& systemID,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, systemID, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ const _ELASTOS String& systemID,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, systemID, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
namespace Dom {
class CDOMResult
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDOMResultClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDOMResult, RGM_SAME_DOMAIN,
                EIID_ICDOMResultClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithNode(node, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDOMResultClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDOMResult, RGM_SAME_DOMAIN,
                EIID_ICDOMResultClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithNodeSystemId(node, systemId, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ Org::W3c::Dom::INode * nextSibling,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDOMResultClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDOMResult, RGM_SAME_DOMAIN,
                EIID_ICDOMResultClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithNodeNextSibling(node, nextSibling, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ Org::W3c::Dom::INode * nextSibling,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDOMResultClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDOMResult, RGM_SAME_DOMAIN,
                EIID_ICDOMResultClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithNodeNextSiblingSystemId(node, nextSibling, systemId, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastosx::Xml::Transform::Dom::IDOMResult** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDOMResult, RGM_SAME_DOMAIN, Elastosx::Xml::Transform::Dom::EIID_IDOMResult, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastosx::Xml::Transform::IResult** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDOMResult, RGM_SAME_DOMAIN, Elastosx::Xml::Transform::EIID_IResult, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDOMResult, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDOMResult, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDOMResult, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [out] */ Elastosx::Xml::Transform::Dom::IDOMResult** __IDOMResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDOMResult = (Elastosx::Xml::Transform::Dom::IDOMResult*)__pNewObj->Probe(Elastosx::Xml::Transform::Dom::EIID_IDOMResult);
        if (*__IDOMResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [out] */ Elastosx::Xml::Transform::IResult** __IResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IResult = (Elastosx::Xml::Transform::IResult*)__pNewObj->Probe(Elastosx::Xml::Transform::EIID_IResult);
        if (*__IResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ Elastosx::Xml::Transform::Dom::IDOMResult** __IDOMResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDOMResult = (Elastosx::Xml::Transform::Dom::IDOMResult*)__pNewObj->Probe(Elastosx::Xml::Transform::Dom::EIID_IDOMResult);
        if (*__IDOMResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ Elastosx::Xml::Transform::IResult** __IResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IResult = (Elastosx::Xml::Transform::IResult*)__pNewObj->Probe(Elastosx::Xml::Transform::EIID_IResult);
        if (*__IResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ Org::W3c::Dom::INode * nextSibling,
        /* [out] */ Elastosx::Xml::Transform::Dom::IDOMResult** __IDOMResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, nextSibling, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDOMResult = (Elastosx::Xml::Transform::Dom::IDOMResult*)__pNewObj->Probe(Elastosx::Xml::Transform::Dom::EIID_IDOMResult);
        if (*__IDOMResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ Org::W3c::Dom::INode * nextSibling,
        /* [out] */ Elastosx::Xml::Transform::IResult** __IResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, nextSibling, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IResult = (Elastosx::Xml::Transform::IResult*)__pNewObj->Probe(Elastosx::Xml::Transform::EIID_IResult);
        if (*__IResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ Org::W3c::Dom::INode * nextSibling,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, nextSibling, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ Org::W3c::Dom::INode * nextSibling,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, nextSibling, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ Org::W3c::Dom::INode * nextSibling,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, nextSibling, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ Org::W3c::Dom::INode * nextSibling,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ Elastosx::Xml::Transform::Dom::IDOMResult** __IDOMResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, nextSibling, systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDOMResult = (Elastosx::Xml::Transform::Dom::IDOMResult*)__pNewObj->Probe(Elastosx::Xml::Transform::Dom::EIID_IDOMResult);
        if (*__IDOMResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ Org::W3c::Dom::INode * nextSibling,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ Elastosx::Xml::Transform::IResult** __IResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, nextSibling, systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IResult = (Elastosx::Xml::Transform::IResult*)__pNewObj->Probe(Elastosx::Xml::Transform::EIID_IResult);
        if (*__IResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ Org::W3c::Dom::INode * nextSibling,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, nextSibling, systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ Org::W3c::Dom::INode * nextSibling,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, nextSibling, systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::W3c::Dom::INode * node,
        /* [in] */ Org::W3c::Dom::INode * nextSibling,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(node, nextSibling, systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
namespace Sax {
class CSAXResult
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Org::Xml::Sax::IContentHandler * handler,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSAXResultClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSAXResult, RGM_SAME_DOMAIN,
                EIID_ICSAXResultClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithHandler(handler, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IContentHandler * handler,
        /* [out] */ Elastosx::Xml::Transform::Sax::ISAXResult** __ISAXResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISAXResult = (Elastosx::Xml::Transform::Sax::ISAXResult*)__pNewObj->Probe(Elastosx::Xml::Transform::Sax::EIID_ISAXResult);
        if (*__ISAXResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IContentHandler * handler,
        /* [out] */ Elastosx::Xml::Transform::IResult** __IResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IResult = (Elastosx::Xml::Transform::IResult*)__pNewObj->Probe(Elastosx::Xml::Transform::EIID_IResult);
        if (*__IResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IContentHandler * handler,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IContentHandler * handler,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IContentHandler * handler,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
namespace Sax {
class CSAXSource
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Org::Xml::Sax::IXMLReader * reader,
        /* [in] */ Org::Xml::Sax::IInputSource * inputSource,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSAXSourceClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSAXSource, RGM_SAME_DOMAIN,
                EIID_ICSAXSourceClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithReaderInputSource(reader, inputSource, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Org::Xml::Sax::IInputSource * inputSource,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSAXSourceClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSAXSource, RGM_SAME_DOMAIN,
                EIID_ICSAXSourceClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithInputSource(inputSource, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IXMLReader * reader,
        /* [in] */ Org::Xml::Sax::IInputSource * inputSource,
        /* [out] */ Elastosx::Xml::Transform::Sax::ISAXSource** __ISAXSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(reader, inputSource, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISAXSource = (Elastosx::Xml::Transform::Sax::ISAXSource*)__pNewObj->Probe(Elastosx::Xml::Transform::Sax::EIID_ISAXSource);
        if (*__ISAXSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IXMLReader * reader,
        /* [in] */ Org::Xml::Sax::IInputSource * inputSource,
        /* [out] */ Elastosx::Xml::Transform::ISource** __ISource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(reader, inputSource, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISource = (Elastosx::Xml::Transform::ISource*)__pNewObj->Probe(Elastosx::Xml::Transform::EIID_ISource);
        if (*__ISource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IXMLReader * reader,
        /* [in] */ Org::Xml::Sax::IInputSource * inputSource,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(reader, inputSource, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IXMLReader * reader,
        /* [in] */ Org::Xml::Sax::IInputSource * inputSource,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(reader, inputSource, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IXMLReader * reader,
        /* [in] */ Org::Xml::Sax::IInputSource * inputSource,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(reader, inputSource, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IInputSource * inputSource,
        /* [out] */ Elastosx::Xml::Transform::Sax::ISAXSource** __ISAXSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(inputSource, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISAXSource = (Elastosx::Xml::Transform::Sax::ISAXSource*)__pNewObj->Probe(Elastosx::Xml::Transform::Sax::EIID_ISAXSource);
        if (*__ISAXSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IInputSource * inputSource,
        /* [out] */ Elastosx::Xml::Transform::ISource** __ISource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(inputSource, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISource = (Elastosx::Xml::Transform::ISource*)__pNewObj->Probe(Elastosx::Xml::Transform::EIID_ISource);
        if (*__ISource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IInputSource * inputSource,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(inputSource, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IInputSource * inputSource,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(inputSource, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IInputSource * inputSource,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(inputSource, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
namespace Stream {
class CStreamResult
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * outputStream,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStreamResultClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStreamResult, RGM_SAME_DOMAIN,
                EIID_ICStreamResultClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOutputStream(outputStream, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IWriter * writer,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStreamResultClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStreamResult, RGM_SAME_DOMAIN,
                EIID_ICStreamResultClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithWriter(writer, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStreamResultClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStreamResult, RGM_SAME_DOMAIN,
                EIID_ICStreamResultClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSystemId(systemId, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFile * f,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStreamResultClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStreamResult, RGM_SAME_DOMAIN,
                EIID_ICStreamResultClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithF(f, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastosx::Xml::Transform::Stream::IStreamResult** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStreamResult, RGM_SAME_DOMAIN, Elastosx::Xml::Transform::Stream::EIID_IStreamResult, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastosx::Xml::Transform::IResult** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStreamResult, RGM_SAME_DOMAIN, Elastosx::Xml::Transform::EIID_IResult, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStreamResult, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStreamResult, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStreamResult, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outputStream,
        /* [out] */ Elastosx::Xml::Transform::Stream::IStreamResult** __IStreamResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outputStream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStreamResult = (Elastosx::Xml::Transform::Stream::IStreamResult*)__pNewObj->Probe(Elastosx::Xml::Transform::Stream::EIID_IStreamResult);
        if (*__IStreamResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outputStream,
        /* [out] */ Elastosx::Xml::Transform::IResult** __IResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outputStream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IResult = (Elastosx::Xml::Transform::IResult*)__pNewObj->Probe(Elastosx::Xml::Transform::EIID_IResult);
        if (*__IResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outputStream,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outputStream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outputStream,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outputStream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outputStream,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outputStream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * writer,
        /* [out] */ Elastosx::Xml::Transform::Stream::IStreamResult** __IStreamResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(writer, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStreamResult = (Elastosx::Xml::Transform::Stream::IStreamResult*)__pNewObj->Probe(Elastosx::Xml::Transform::Stream::EIID_IStreamResult);
        if (*__IStreamResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * writer,
        /* [out] */ Elastosx::Xml::Transform::IResult** __IResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(writer, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IResult = (Elastosx::Xml::Transform::IResult*)__pNewObj->Probe(Elastosx::Xml::Transform::EIID_IResult);
        if (*__IResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * writer,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(writer, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * writer,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(writer, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * writer,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(writer, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ Elastosx::Xml::Transform::Stream::IStreamResult** __IStreamResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStreamResult = (Elastosx::Xml::Transform::Stream::IStreamResult*)__pNewObj->Probe(Elastosx::Xml::Transform::Stream::EIID_IStreamResult);
        if (*__IStreamResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ Elastosx::Xml::Transform::IResult** __IResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IResult = (Elastosx::Xml::Transform::IResult*)__pNewObj->Probe(Elastosx::Xml::Transform::EIID_IResult);
        if (*__IResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * f,
        /* [out] */ Elastosx::Xml::Transform::Stream::IStreamResult** __IStreamResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(f, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStreamResult = (Elastosx::Xml::Transform::Stream::IStreamResult*)__pNewObj->Probe(Elastosx::Xml::Transform::Stream::EIID_IStreamResult);
        if (*__IStreamResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * f,
        /* [out] */ Elastosx::Xml::Transform::IResult** __IResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(f, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IResult = (Elastosx::Xml::Transform::IResult*)__pNewObj->Probe(Elastosx::Xml::Transform::EIID_IResult);
        if (*__IResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * f,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(f, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * f,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(f, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * f,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(f, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
}
namespace Elastosx {
namespace Xml {
namespace Transform {
namespace Stream {
class CStreamSource
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStreamSourceClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStreamSource, RGM_SAME_DOMAIN,
                EIID_ICStreamSourceClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithInputStream(inputStream, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStreamSourceClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStreamSource, RGM_SAME_DOMAIN,
                EIID_ICStreamSourceClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithInputStreamSystemId(inputStream, systemId, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IReader * reader,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStreamSourceClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStreamSource, RGM_SAME_DOMAIN,
                EIID_ICStreamSourceClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithReader(reader, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStreamSourceClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStreamSource, RGM_SAME_DOMAIN,
                EIID_ICStreamSourceClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithReaderSystemId(reader, systemId, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStreamSourceClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStreamSource, RGM_SAME_DOMAIN,
                EIID_ICStreamSourceClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSystemId(systemId, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFile * f,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStreamSourceClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStreamSource, RGM_SAME_DOMAIN,
                EIID_ICStreamSourceClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithF(f, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastosx::Xml::Transform::Stream::IStreamSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStreamSource, RGM_SAME_DOMAIN, Elastosx::Xml::Transform::Stream::EIID_IStreamSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastosx::Xml::Transform::ISource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStreamSource, RGM_SAME_DOMAIN, Elastosx::Xml::Transform::EIID_ISource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStreamSource, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStreamSource, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStreamSource, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [out] */ Elastosx::Xml::Transform::Stream::IStreamSource** __IStreamSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(inputStream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStreamSource = (Elastosx::Xml::Transform::Stream::IStreamSource*)__pNewObj->Probe(Elastosx::Xml::Transform::Stream::EIID_IStreamSource);
        if (*__IStreamSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [out] */ Elastosx::Xml::Transform::ISource** __ISource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(inputStream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISource = (Elastosx::Xml::Transform::ISource*)__pNewObj->Probe(Elastosx::Xml::Transform::EIID_ISource);
        if (*__ISource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(inputStream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(inputStream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(inputStream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ Elastosx::Xml::Transform::Stream::IStreamSource** __IStreamSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(inputStream, systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStreamSource = (Elastosx::Xml::Transform::Stream::IStreamSource*)__pNewObj->Probe(Elastosx::Xml::Transform::Stream::EIID_IStreamSource);
        if (*__IStreamSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ Elastosx::Xml::Transform::ISource** __ISource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(inputStream, systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISource = (Elastosx::Xml::Transform::ISource*)__pNewObj->Probe(Elastosx::Xml::Transform::EIID_ISource);
        if (*__ISource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(inputStream, systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(inputStream, systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(inputStream, systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * reader,
        /* [out] */ Elastosx::Xml::Transform::Stream::IStreamSource** __IStreamSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(reader, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStreamSource = (Elastosx::Xml::Transform::Stream::IStreamSource*)__pNewObj->Probe(Elastosx::Xml::Transform::Stream::EIID_IStreamSource);
        if (*__IStreamSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * reader,
        /* [out] */ Elastosx::Xml::Transform::ISource** __ISource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(reader, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISource = (Elastosx::Xml::Transform::ISource*)__pNewObj->Probe(Elastosx::Xml::Transform::EIID_ISource);
        if (*__ISource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * reader,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(reader, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * reader,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(reader, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * reader,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(reader, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ Elastosx::Xml::Transform::Stream::IStreamSource** __IStreamSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(reader, systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStreamSource = (Elastosx::Xml::Transform::Stream::IStreamSource*)__pNewObj->Probe(Elastosx::Xml::Transform::Stream::EIID_IStreamSource);
        if (*__IStreamSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ Elastosx::Xml::Transform::ISource** __ISource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(reader, systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISource = (Elastosx::Xml::Transform::ISource*)__pNewObj->Probe(Elastosx::Xml::Transform::EIID_ISource);
        if (*__ISource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(reader, systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(reader, systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(reader, systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ Elastosx::Xml::Transform::Stream::IStreamSource** __IStreamSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStreamSource = (Elastosx::Xml::Transform::Stream::IStreamSource*)__pNewObj->Probe(Elastosx::Xml::Transform::Stream::EIID_IStreamSource);
        if (*__IStreamSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ Elastosx::Xml::Transform::ISource** __ISource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISource = (Elastosx::Xml::Transform::ISource*)__pNewObj->Probe(Elastosx::Xml::Transform::EIID_ISource);
        if (*__ISource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(systemId, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * f,
        /* [out] */ Elastosx::Xml::Transform::Stream::IStreamSource** __IStreamSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(f, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStreamSource = (Elastosx::Xml::Transform::Stream::IStreamSource*)__pNewObj->Probe(Elastosx::Xml::Transform::Stream::EIID_IStreamSource);
        if (*__IStreamSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * f,
        /* [out] */ Elastosx::Xml::Transform::ISource** __ISource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(f, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISource = (Elastosx::Xml::Transform::ISource*)__pNewObj->Probe(Elastosx::Xml::Transform::EIID_ISource);
        if (*__ISource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * f,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(f, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * f,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(f, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * f,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(f, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
}
namespace Elastosx {
namespace Xml {
namespace XPath {
class CXPathConstants
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastosx::Xml::XPath::IXPathConstants** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXPathConstants, RGM_SAME_DOMAIN, Elastosx::Xml::XPath::EIID_IXPathConstants, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXPathConstants, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXPathConstants, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXPathConstants, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastosx {
namespace Xml {
namespace XPath {
class CXPathFactoryFinder
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Core::IClassLoader * cl,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICXPathFactoryFinderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CXPathFactoryFinder, RGM_SAME_DOMAIN,
                EIID_ICXPathFactoryFinderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCl(cl, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IClassLoader * cl,
        /* [out] */ Elastosx::Xml::XPath::IXPathFactoryFinder** __IXPathFactoryFinder)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cl, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IXPathFactoryFinder = (Elastosx::Xml::XPath::IXPathFactoryFinder*)__pNewObj->Probe(Elastosx::Xml::XPath::EIID_IXPathFactoryFinder);
        if (*__IXPathFactoryFinder) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IClassLoader * cl,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cl, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IClassLoader * cl,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cl, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IClassLoader * cl,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cl, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}

#endif // __Elastos_CoreLibrary_Extensions_h__
