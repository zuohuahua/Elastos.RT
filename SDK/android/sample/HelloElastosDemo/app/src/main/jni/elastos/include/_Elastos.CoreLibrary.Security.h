#ifndef ___Elastos_CoreLibrary_Security_h__
#define ___Elastos_CoreLibrary_Security_h__

#include <Elastos.CoreLibrary.h>

EXTERN_C ELAPI _Impl_AcquireCallbackHandler(PInterface pServerObj, _ELASTOS REIID iid, PInterface *ppHandler);
EXTERN_C ELAPI _Impl_CheckClsId(PInterface pServerObj, const _ELASTOS ClassID* pClassid, PInterface *ppServerObj);

namespace Elastos {
namespace Security {
CAR_INTERFACE("9AFD3506-8512-BFF2-F392-F62DDB3F879A")
IKey : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKey*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKey*)pObj->Probe(EIID_IKey);
    }

    static CARAPI_(IKey*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKey*)pObj->Probe(EIID_IKey);
    }

    virtual CARAPI GetAlgorithm(
        /* [out] */ _ELASTOS String * algorithm) = 0;

    virtual CARAPI GetFormat(
        /* [out] */ _ELASTOS String * format) = 0;

    virtual CARAPI GetEncoded(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** encoded) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("C3A11C54-0652-971C-0652-B0F6C3414919")
IPublicKey : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPublicKey*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPublicKey*)pObj->Probe(EIID_IPublicKey);
    }

    static CARAPI_(IPublicKey*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPublicKey*)pObj->Probe(EIID_IPublicKey);
    }

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("80681D52-0652-BDBD-3553-B0F6C3414919")
IPrivateKey : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPrivateKey*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPrivateKey*)pObj->Probe(EIID_IPrivateKey);
    }

    static CARAPI_(IPrivateKey*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPrivateKey*)pObj->Probe(EIID_IPrivateKey);
    }

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("34A53C54-0652-31BD-5481-7DF1C3414919")
IPrincipal : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPrincipal*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPrincipal*)pObj->Probe(EIID_IPrincipal);
    }

    static CARAPI_(IPrincipal*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPrincipal*)pObj->Probe(EIID_IPrincipal);
    }

    virtual CARAPI Equals(
        /* [in] */ IInterface * obj,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
namespace Elastos {
namespace Security {
namespace Acl {
CAR_INTERFACE("C799361A-A612-68C7-FD3B-2F69DFB2FD73")
IOwner : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IOwner*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IOwner*)pObj->Probe(EIID_IOwner);
    }

    static CARAPI_(IOwner*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IOwner*)pObj->Probe(EIID_IOwner);
    }

    virtual CARAPI AddOwner(
        /* [in] */ Elastos::Security::IPrincipal * caller,
        /* [in] */ Elastos::Security::IPrincipal * owner,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI DeleteOwner(
        /* [in] */ Elastos::Security::IPrincipal * caller,
        /* [in] */ Elastos::Security::IPrincipal * owner,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI IsOwner(
        /* [in] */ Elastos::Security::IPrincipal * owner,
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Acl {
CAR_INTERFACE("4C546A04-6292-BFBE-F392-F62DDB3F879A")
IAcl : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAcl*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAcl*)pObj->Probe(EIID_IAcl);
    }

    static CARAPI_(IAcl*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAcl*)pObj->Probe(EIID_IAcl);
    }

    virtual CARAPI SetName(
        /* [in] */ Elastos::Security::IPrincipal * caller,
        /* [in] */ const _ELASTOS String& name) = 0;

    virtual CARAPI GetName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI AddEntry(
        /* [in] */ Elastos::Security::IPrincipal * caller,
        /* [in] */ Elastos::Security::Acl::IAclEntry * entry,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI RemoveEntry(
        /* [in] */ Elastos::Security::IPrincipal * caller,
        /* [in] */ Elastos::Security::Acl::IAclEntry * entry,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetPermissions(
        /* [in] */ Elastos::Security::IPrincipal * user,
        /* [out] */ Elastos::Utility::IEnumeration ** permissions) = 0;

    virtual CARAPI GetEntries(
        /* [out] */ Elastos::Utility::IEnumeration ** entries) = 0;

    virtual CARAPI CheckPermission(
        /* [in] */ Elastos::Security::IPrincipal * principal,
        /* [in] */ Elastos::Security::Acl::IPermission * permission,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Acl {
CAR_INTERFACE("A7809E56-0292-2F13-9CFC-705052868D1F")
IAclEntry : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAclEntry*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAclEntry*)pObj->Probe(EIID_IAclEntry);
    }

    static CARAPI_(IAclEntry*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAclEntry*)pObj->Probe(EIID_IAclEntry);
    }

    virtual CARAPI SetPrincipal(
        /* [in] */ Elastos::Security::IPrincipal * user,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetPrincipal(
        /* [out] */ Elastos::Security::IPrincipal ** principal) = 0;

    virtual CARAPI SetNegativePermissions() = 0;

    virtual CARAPI IsNegative(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI AddPermission(
        /* [in] */ Elastos::Security::Acl::IPermission * permission,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI RemovePermission(
        /* [in] */ Elastos::Security::Acl::IPermission * permission,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI CheckPermission(
        /* [in] */ Elastos::Security::Acl::IPermission * permission,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetPermissions(
        /* [out] */ Elastos::Utility::IEnumeration ** permissions) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI Clone(
        /* [out] */ Elastos::Security::Acl::IAclEntry ** clone) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Acl {
CAR_INTERFACE("3E2F430D-5412-F8CB-FC3B-2F69DFB2FD73")
IGroup : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IGroup*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IGroup*)pObj->Probe(EIID_IGroup);
    }

    static CARAPI_(IGroup*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IGroup*)pObj->Probe(EIID_IGroup);
    }

    virtual CARAPI AddMember(
        /* [in] */ Elastos::Security::IPrincipal * user,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI RemoveMember(
        /* [in] */ Elastos::Security::IPrincipal * user,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI IsMember(
        /* [in] */ Elastos::Security::IPrincipal * member,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetMembers(
        /* [out] */ Elastos::Utility::IEnumeration ** members) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Acl {
CAR_INTERFACE("C2172F4D-8652-3C67-6D2C-FEE1A0A40C1B")
IPermission : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPermission*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPermission*)pObj->Probe(EIID_IPermission);
    }

    static CARAPI_(IPermission*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPermission*)pObj->Probe(EIID_IPermission);
    }

    virtual CARAPI Equals(
        /* [in] */ IInterface * another,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("B1963E45-1452-31CD-16FF-705052868D1F")
IExtension : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IExtension*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IExtension*)pObj->Probe(EIID_IExtension);
    }

    static CARAPI_(IExtension*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IExtension*)pObj->Probe(EIID_IExtension);
    }

    virtual CARAPI GetId(
        /* [out] */ _ELASTOS String * id) = 0;

    virtual CARAPI IsCritical(
        /* [out] */ _ELASTOS Boolean * isCritical) = 0;

    virtual CARAPI GetValue(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** value) = 0;

    virtual CARAPI Encode(
        /* [in] */ Elastos::IO::IOutputStream * outValue) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("34614C4A-8312-9F67-BB75-D2FCC3414919")
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

    virtual CARAPI GetType(
        /* [out] */ _ELASTOS String * type) = 0;

    virtual CARAPI GetEncoded(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** encoded) = 0;

    virtual CARAPI Verify(
        /* [in] */ Elastos::Security::IPublicKey * key) = 0;

    virtual CARAPI Verify(
        /* [in] */ Elastos::Security::IPublicKey * key,
        /* [in] */ const _ELASTOS String& sigProvider) = 0;

    virtual CARAPI GetPublicKey(
        /* [out] */ Elastos::Security::IPublicKey ** key) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("69A0FA17-5852-0900-83D6-379BB22679A3")
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
        /* [out] */ _ELASTOS Int32 * versionNumber) = 0;

    virtual CARAPI GetSerialNumber(
        /* [out] */ Elastos::Math::IBigInteger ** number) = 0;

    virtual CARAPI GetIssuerDN(
        /* [out] */ Elastos::Security::IPrincipal ** issuer) = 0;

    virtual CARAPI GetIssuerX500Principal(
        /* [out] */ Elastosx::Security::Auth::X500::IX500Principal ** issuerName) = 0;

    virtual CARAPI GetSubjectDN(
        /* [out] */ Elastos::Security::IPrincipal ** subject) = 0;

    virtual CARAPI GetSubjectX500Principal(
        /* [out] */ Elastosx::Security::Auth::X500::IX500Principal ** subject) = 0;

    virtual CARAPI GetNotBefore(
        /* [out] */ Elastos::Utility::IDate ** notBefore) = 0;

    virtual CARAPI GetNotAfter(
        /* [out] */ Elastos::Utility::IDate ** notAfter) = 0;

    virtual CARAPI GetTBSCertificate(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** tbsCertificate) = 0;

    virtual CARAPI GetSignature(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** signature) = 0;

    virtual CARAPI GetSigAlgName(
        /* [out] */ _ELASTOS String * sigAlgName) = 0;

    virtual CARAPI GetSigAlgOID(
        /* [out] */ _ELASTOS String * oid) = 0;

    virtual CARAPI GetSigAlgParams(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** sigAlgParams) = 0;

    virtual CARAPI GetIssuerUniqueID(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Boolean> ** issuerUniqueID) = 0;

    virtual CARAPI GetSubjectUniqueID(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Boolean> ** subjectUniqueID) = 0;

    virtual CARAPI GetKeyUsage(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Boolean> ** keyUsage) = 0;

    virtual CARAPI GetExtendedKeyUsage(
        /* [out] */ Elastos::Utility::IList ** keyUsage) = 0;

    virtual CARAPI GetBasicConstraints(
        /* [out] */ _ELASTOS Int32 * constraints) = 0;

    virtual CARAPI GetSubjectAlternativeNames(
        /* [out] */ Elastos::Utility::ICollection ** subjectAlternativeNames) = 0;

    virtual CARAPI GetIssuerAlternativeNames(
        /* [out] */ Elastos::Utility::ICollection ** issuerAlternativeNames) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("906C2B08-B312-BF55-F392-F62DDB3F879A")
ICRL : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICRL*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRL*)pObj->Probe(EIID_ICRL);
    }

    static CARAPI_(ICRL*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRL*)pObj->Probe(EIID_ICRL);
    }

    virtual CARAPI GetType(
        /* [out] */ _ELASTOS String * type) = 0;

    virtual CARAPI IsRevoked(
        /* [in] */ Elastos::Security::Cert::ICertificate * cert,
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("60BD2827-8312-150D-2CE7-FFD1DEC60D19")
ICRLSelector : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICRLSelector*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRLSelector*)pObj->Probe(EIID_ICRLSelector);
    }

    static CARAPI_(ICRLSelector*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRLSelector*)pObj->Probe(EIID_ICRLSelector);
    }

    virtual CARAPI Match(
        /* [in] */ Elastos::Security::Cert::ICRL * crl,
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("C2275623-8312-37FB-B2FE-686FE3860C1B")
ICertPath : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICertPath*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertPath*)pObj->Probe(EIID_ICertPath);
    }

    static CARAPI_(ICertPath*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertPath*)pObj->Probe(EIID_ICertPath);
    }

    virtual CARAPI GetType(
        /* [out] */ _ELASTOS String * type) = 0;

    virtual CARAPI GetCertificates(
        /* [out] */ Elastos::Utility::IList ** certs) = 0;

    virtual CARAPI GetEncoded(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** encoded) = 0;

    virtual CARAPI GetEncoded(
        /* [in] */ const _ELASTOS String& encoding,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** encoded) = 0;

    virtual CARAPI GetEncodings(
        /* [out] */ Elastos::Utility::IIterator ** encodings) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("1EDE2A25-8312-37FB-B25E-B5F1A3BD8D1B")
ICertPathParameters : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICertPathParameters*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertPathParameters*)pObj->Probe(EIID_ICertPathParameters);
    }

    static CARAPI_(ICertPathParameters*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertPathParameters*)pObj->Probe(EIID_ICertPathParameters);
    }

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("C5242F34-8312-37FB-B27A-277123FFE11F")
ICertPathValidatorResult : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICertPathValidatorResult*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertPathValidatorResult*)pObj->Probe(EIID_ICertPathValidatorResult);
    }

    static CARAPI_(ICertPathValidatorResult*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertPathValidatorResult*)pObj->Probe(EIID_ICertPathValidatorResult);
    }

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("206A3821-8312-37FB-B2B2-B97FF8477B1B")
ICertPathBuilderResult : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICertPathBuilderResult*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertPathBuilderResult*)pObj->Probe(EIID_ICertPathBuilderResult);
    }

    static CARAPI_(ICertPathBuilderResult*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertPathBuilderResult*)pObj->Probe(EIID_ICertPathBuilderResult);
    }

    virtual CARAPI GetCertPath(
        /* [out] */ Elastos::Security::Cert::ICertPath ** certPath) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("C0133536-8312-37FB-B2B2-B9CF61068B1F")
ICertPathBuilderSpi : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICertPathBuilderSpi*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertPathBuilderSpi*)pObj->Probe(EIID_ICertPathBuilderSpi);
    }

    static CARAPI_(ICertPathBuilderSpi*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertPathBuilderSpi*)pObj->Probe(EIID_ICertPathBuilderSpi);
    }

    virtual CARAPI EngineBuild(
        /* [in] */ Elastos::Security::Cert::ICertPathParameters * params,
        /* [out] */ Elastos::Security::Cert::ICertPathBuilderResult ** result) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("A479433C-8312-37FB-B2B2-B9FFA3BD8D1B")
ICertPathBuilder : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICertPathBuilder*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertPathBuilder*)pObj->Probe(EIID_ICertPathBuilder);
    }

    static CARAPI_(ICertPathBuilder*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertPathBuilder*)pObj->Probe(EIID_ICertPathBuilder);
    }

    virtual CARAPI GetAlgorithm(
        /* [out] */ _ELASTOS String * algorithm) = 0;

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI Build(
        /* [in] */ Elastos::Security::Cert::ICertPathParameters * params,
        /* [out] */ Elastos::Security::Cert::ICertPathBuilderResult ** result) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("E26D5C3E-8312-37FB-B2B2-B91F01C58B19")
ICertPathBuilderHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICertPathBuilderHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertPathBuilderHelper*)pObj->Probe(EIID_ICertPathBuilderHelper);
    }

    static CARAPI_(ICertPathBuilderHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertPathBuilderHelper*)pObj->Probe(EIID_ICertPathBuilderHelper);
    }

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Security::Cert::ICertPathBuilder ** builder) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& provider,
        /* [out] */ Elastos::Security::Cert::ICertPathBuilder ** builder) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastos::Security::Cert::ICertPathBuilder ** builder) = 0;

    virtual CARAPI GetDefaultType(
        /* [out] */ _ELASTOS String * type) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("CD35483B-8312-37FB-B27A-277123FF8FF6")
ICertPathValidator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICertPathValidator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertPathValidator*)pObj->Probe(EIID_ICertPathValidator);
    }

    static CARAPI_(ICertPathValidator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertPathValidator*)pObj->Probe(EIID_ICertPathValidator);
    }

    virtual CARAPI GetAlgorithm(
        /* [out] */ _ELASTOS String * algorithm) = 0;

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI Validate(
        /* [in] */ Elastos::Security::Cert::ICertPath * certPath,
        /* [in] */ Elastos::Security::Cert::ICertPathParameters * params,
        /* [out] */ Elastos::Security::Cert::ICertPathValidatorResult ** result) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("57195E2F-8312-37FB-B27A-2771237F0414")
ICertPathValidatorHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICertPathValidatorHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertPathValidatorHelper*)pObj->Probe(EIID_ICertPathValidatorHelper);
    }

    static CARAPI_(ICertPathValidatorHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertPathValidatorHelper*)pObj->Probe(EIID_ICertPathValidatorHelper);
    }

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Security::Cert::ICertPathValidator ** validator) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& provider,
        /* [out] */ Elastos::Security::Cert::ICertPathValidator ** validator) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastos::Security::Cert::ICertPathValidator ** validator) = 0;

    virtual CARAPI GetDefaultType(
        /* [out] */ _ELASTOS String * type) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("E8CF3A3F-8312-37FB-B27A-2771233F8719")
ICertPathValidatorSpi : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICertPathValidatorSpi*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertPathValidatorSpi*)pObj->Probe(EIID_ICertPathValidatorSpi);
    }

    static CARAPI_(ICertPathValidatorSpi*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertPathValidatorSpi*)pObj->Probe(EIID_ICertPathValidatorSpi);
    }

    virtual CARAPI EngineValidate(
        /* [in] */ Elastos::Security::Cert::ICertPath * certPath,
        /* [in] */ Elastos::Security::Cert::ICertPathParameters * params,
        /* [out] */ Elastos::Security::Cert::ICertPathValidatorResult ** result) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("3B35293E-8312-37FB-2CE7-FFD1DEC60D19")
ICertSelector : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICertSelector*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertSelector*)pObj->Probe(EIID_ICertSelector);
    }

    static CARAPI_(ICertSelector*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertSelector*)pObj->Probe(EIID_ICertSelector);
    }

    virtual CARAPI Match(
        /* [in] */ Elastos::Security::Cert::ICertificate * cert,
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("1CF95F33-8312-37FB-5EFF-686FE3860C1B")
ICertStore : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICertStore*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertStore*)pObj->Probe(EIID_ICertStore);
    }

    static CARAPI_(ICertStore*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertStore*)pObj->Probe(EIID_ICertStore);
    }

    virtual CARAPI GetType(
        /* [out] */ _ELASTOS String * type) = 0;

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI GetCertStoreParameters(
        /* [out] */ Elastos::Security::Cert::ICertStoreParameters ** parameters) = 0;

    virtual CARAPI GetCertificates(
        /* [in] */ Elastos::Security::Cert::ICertSelector * selector,
        /* [out] */ Elastos::Utility::ICollection ** certs) = 0;

    virtual CARAPI GetCRLs(
        /* [in] */ Elastos::Security::Cert::ICRLSelector * selector,
        /* [out] */ Elastos::Utility::ICollection ** crls) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("0198563B-8312-37FB-5E47-40F162C6FD1F")
ICertStoreHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICertStoreHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertStoreHelper*)pObj->Probe(EIID_ICertStoreHelper);
    }

    static CARAPI_(ICertStoreHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertStoreHelper*)pObj->Probe(EIID_ICertStoreHelper);
    }

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ Elastos::Security::Cert::ICertStoreParameters * params,
        /* [out] */ Elastos::Security::Cert::ICertStore ** certStore) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ Elastos::Security::Cert::ICertStoreParameters * params,
        /* [in] */ const _ELASTOS String& provider,
        /* [out] */ Elastos::Security::Cert::ICertStore ** certStore) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ Elastos::Security::Cert::ICertStoreParameters * params,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastos::Security::Cert::ICertStore ** certStore) = 0;

    virtual CARAPI GetDefaultType(
        /* [out] */ _ELASTOS String * type) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("BDBE2B3C-8312-37FB-5E5F-B5F1A3BD8D1B")
ICertStoreParameters : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICertStoreParameters*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertStoreParameters*)pObj->Probe(EIID_ICertStoreParameters);
    }

    static CARAPI_(ICertStoreParameters*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertStoreParameters*)pObj->Probe(EIID_ICertStoreParameters);
    }

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("D370463F-8312-37FB-5E73-98C1E2477B1B")
ICertStoreSpi : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICertStoreSpi*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertStoreSpi*)pObj->Probe(EIID_ICertStoreSpi);
    }

    static CARAPI_(ICertStoreSpi*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertStoreSpi*)pObj->Probe(EIID_ICertStoreSpi);
    }

    virtual CARAPI EngineGetCertificates(
        /* [in] */ Elastos::Security::Cert::ICertSelector * selector,
        /* [out] */ Elastos::Utility::ICollection ** certs) = 0;

    virtual CARAPI EngineGetCRLs(
        /* [in] */ Elastos::Security::Cert::ICRLSelector * selector,
        /* [out] */ Elastos::Utility::ICollection ** crls) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("1DABBE4E-8312-9F67-BB75-D2FC80C42BAB")
ICertificateFactory : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICertificateFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertificateFactory*)pObj->Probe(EIID_ICertificateFactory);
    }

    static CARAPI_(ICertificateFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertificateFactory*)pObj->Probe(EIID_ICertificateFactory);
    }

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI GetType(
        /* [out] */ _ELASTOS String * type) = 0;

    virtual CARAPI GenerateCertificate(
        /* [in] */ Elastos::IO::IInputStream * inStream,
        /* [out] */ Elastos::Security::Cert::ICertificate ** cert) = 0;

    virtual CARAPI GetCertPathEncodings(
        /* [out] */ Elastos::Utility::IIterator ** it) = 0;

    virtual CARAPI GenerateCertPath(
        /* [in] */ Elastos::IO::IInputStream * inStream,
        /* [out] */ Elastos::Security::Cert::ICertPath ** certPath) = 0;

    virtual CARAPI GenerateCertPath(
        /* [in] */ Elastos::IO::IInputStream * inStream,
        /* [in] */ const _ELASTOS String& encoding,
        /* [out] */ Elastos::Security::Cert::ICertPath ** certPath) = 0;

    virtual CARAPI GenerateCertPath(
        /* [in] */ Elastos::Utility::IList * certificates,
        /* [out] */ Elastos::Security::Cert::ICertPath ** certPath) = 0;

    virtual CARAPI GenerateCertificates(
        /* [in] */ Elastos::IO::IInputStream * inStream,
        /* [out] */ Elastos::Utility::ICollection ** certs) = 0;

    virtual CARAPI GenerateCRL(
        /* [in] */ Elastos::IO::IInputStream * inStream,
        /* [out] */ Elastos::Security::Cert::ICRL ** crl) = 0;

    virtual CARAPI GenerateCRLs(
        /* [in] */ Elastos::IO::IInputStream * inStream,
        /* [out] */ Elastos::Utility::ICollection ** crls) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("59295151-8312-9F67-BB75-D2FC80C42BAB")
ICertificateFactoryHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICertificateFactoryHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertificateFactoryHelper*)pObj->Probe(EIID_ICertificateFactoryHelper);
    }

    static CARAPI_(ICertificateFactoryHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertificateFactoryHelper*)pObj->Probe(EIID_ICertificateFactoryHelper);
    }

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& type,
        /* [out] */ Elastos::Security::Cert::ICertificateFactory ** factory) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ const _ELASTOS String& provider,
        /* [out] */ Elastos::Security::Cert::ICertificateFactory ** factory) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastos::Security::Cert::ICertificateFactory ** factory) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("7A92DF59-8312-9F67-BB75-D2FC80C42BAB")
ICertificateFactorySpi : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICertificateFactorySpi*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertificateFactorySpi*)pObj->Probe(EIID_ICertificateFactorySpi);
    }

    static CARAPI_(ICertificateFactorySpi*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICertificateFactorySpi*)pObj->Probe(EIID_ICertificateFactorySpi);
    }

    virtual CARAPI EngineGenerateCertificate(
        /* [in] */ Elastos::IO::IInputStream * inStream,
        /* [out] */ Elastos::Security::Cert::ICertificate ** cert) = 0;

    virtual CARAPI EngineGenerateCertificates(
        /* [in] */ Elastos::IO::IInputStream * inStream,
        /* [out] */ Elastos::Utility::ICollection ** certs) = 0;

    virtual CARAPI EngineGenerateCRL(
        /* [in] */ Elastos::IO::IInputStream * inStream,
        /* [out] */ Elastos::Security::Cert::ICRL ** crl) = 0;

    virtual CARAPI EngineGenerateCRLs(
        /* [in] */ Elastos::IO::IInputStream * inStream,
        /* [out] */ Elastos::Utility::ICollection ** crls) = 0;

    virtual CARAPI EngineGenerateCertPath(
        /* [in] */ Elastos::IO::IInputStream * inStream,
        /* [out] */ Elastos::Security::Cert::ICertPath ** certPath) = 0;

    virtual CARAPI EngineGenerateCertPath(
        /* [in] */ Elastos::IO::IInputStream * inStream,
        /* [in] */ const _ELASTOS String& encoding,
        /* [out] */ Elastos::Security::Cert::ICertPath ** certPath) = 0;

    virtual CARAPI EngineGenerateCertPath(
        /* [in] */ Elastos::Utility::IList * certificates,
        /* [out] */ Elastos::Security::Cert::ICertPath ** certPath) = 0;

    virtual CARAPI EngineGetCertPathEncodings(
        /* [out] */ Elastos::Utility::IIterator ** encodings) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("211A424A-1152-AF97-2632-787683C36914")
ICollectionCertStoreParameters : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICollectionCertStoreParameters*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollectionCertStoreParameters*)pObj->Probe(EIID_ICollectionCertStoreParameters);
    }

    static CARAPI_(ICollectionCertStoreParameters*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollectionCertStoreParameters*)pObj->Probe(EIID_ICollectionCertStoreParameters);
    }

    virtual CARAPI GetCollection(
        /* [out] */ Elastos::Utility::ICollection ** collection) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("0E674325-8552-0A06-3230-B87FE3F5551B")
ILDAPCertStoreParameters : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILDAPCertStoreParameters*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILDAPCertStoreParameters*)pObj->Probe(EIID_ILDAPCertStoreParameters);
    }

    static CARAPI_(ILDAPCertStoreParameters*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILDAPCertStoreParameters*)pObj->Probe(EIID_ILDAPCertStoreParameters);
    }

    virtual CARAPI GetPort(
        /* [out] */ _ELASTOS Int32 * port) = 0;

    virtual CARAPI GetServerName(
        /* [out] */ _ELASTOS String * name) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("CDADF132-0652-120A-425C-B5F1A3BD8D1B")
IPKIXParameters : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPKIXParameters*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPKIXParameters*)pObj->Probe(EIID_IPKIXParameters);
    }

    static CARAPI_(IPKIXParameters*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPKIXParameters*)pObj->Probe(EIID_IPKIXParameters);
    }

    virtual CARAPI GetTrustAnchors(
        /* [out] */ Elastos::Utility::ISet ** trustAnchors) = 0;

    virtual CARAPI SetTrustAnchors(
        /* [in] */ Elastos::Utility::ISet * trustAnchors) = 0;

    virtual CARAPI IsAnyPolicyInhibited(
        /* [out] */ _ELASTOS Boolean * anyPolicyInhibited) = 0;

    virtual CARAPI SetAnyPolicyInhibited(
        /* [in] */ _ELASTOS Boolean anyPolicyInhibited) = 0;

    virtual CARAPI GetCertPathCheckers(
        /* [out] */ Elastos::Utility::IList ** certPathCheckers) = 0;

    virtual CARAPI SetCertPathCheckers(
        /* [in] */ Elastos::Utility::IList * certPathCheckers) = 0;

    virtual CARAPI AddCertPathChecker(
        /* [in] */ Elastos::Security::Cert::IPKIXCertPathChecker * checker) = 0;

    virtual CARAPI GetCertStores(
        /* [out] */ Elastos::Utility::IList ** certStores) = 0;

    virtual CARAPI SetCertStores(
        /* [in] */ Elastos::Utility::IList * certStores) = 0;

    virtual CARAPI AddCertStore(
        /* [in] */ Elastos::Security::Cert::ICertStore * store) = 0;

    virtual CARAPI GetDate(
        /* [out] */ Elastos::Utility::IDate ** date) = 0;

    virtual CARAPI SetDate(
        /* [in] */ Elastos::Utility::IDate * date) = 0;

    virtual CARAPI IsExplicitPolicyRequired(
        /* [out] */ _ELASTOS Boolean * explicitPolicyRequired) = 0;

    virtual CARAPI SetExplicitPolicyRequired(
        /* [in] */ _ELASTOS Boolean explicitPolicyRequired) = 0;

    virtual CARAPI GetInitialPolicies(
        /* [out] */ Elastos::Utility::ISet ** initialPolicies) = 0;

    virtual CARAPI SetInitialPolicies(
        /* [in] */ Elastos::Utility::ISet * initialPolicies) = 0;

    virtual CARAPI IsPolicyMappingInhibited(
        /* [out] */ _ELASTOS Boolean * policyMappingInhibited) = 0;

    virtual CARAPI SetPolicyMappingInhibited(
        /* [in] */ _ELASTOS Boolean policyMappingInhibited) = 0;

    virtual CARAPI GetPolicyQualifiersRejected(
        /* [out] */ _ELASTOS Boolean * policyQualifiersRejected) = 0;

    virtual CARAPI SetPolicyQualifiersRejected(
        /* [in] */ _ELASTOS Boolean policyQualifiersRejected) = 0;

    virtual CARAPI IsRevocationEnabled(
        /* [out] */ _ELASTOS Boolean * revocationEnabled) = 0;

    virtual CARAPI SetRevocationEnabled(
        /* [in] */ _ELASTOS Boolean revocationEnabled) = 0;

    virtual CARAPI GetSigProvider(
        /* [out] */ _ELASTOS String * sigProvider) = 0;

    virtual CARAPI SetSigProvider(
        /* [in] */ const _ELASTOS String& sigProvider) = 0;

    virtual CARAPI GetTargetCertConstraints(
        /* [out] */ Elastos::Security::Cert::ICertSelector ** targetCertConstraints) = 0;

    virtual CARAPI SetTargetCertConstraints(
        /* [in] */ Elastos::Security::Cert::ICertSelector * targetCertConstraints) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("18794D3B-0652-120A-42B0-B97FD5C68FF6")
IPKIXBuilderParameters : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPKIXBuilderParameters*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPKIXBuilderParameters*)pObj->Probe(EIID_IPKIXBuilderParameters);
    }

    static CARAPI_(IPKIXBuilderParameters*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPKIXBuilderParameters*)pObj->Probe(EIID_IPKIXBuilderParameters);
    }

    virtual CARAPI GetMaxPathLength(
        /* [out] */ _ELASTOS Int32 * length) = 0;

    virtual CARAPI SetMaxPathLength(
        /* [in] */ _ELASTOS Int32 maxPathLength) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("76217C36-D7D2-320B-4EA0-F8D1DEC60D19")
IPolicyNode : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPolicyNode*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPolicyNode*)pObj->Probe(EIID_IPolicyNode);
    }

    static CARAPI_(IPolicyNode*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPolicyNode*)pObj->Probe(EIID_IPolicyNode);
    }

    virtual CARAPI GetChildren(
        /* [out] */ Elastos::Utility::IIterator ** children) = 0;

    virtual CARAPI GetDepth(
        /* [out] */ _ELASTOS Int32 * depth) = 0;

    virtual CARAPI GetExpectedPolicies(
        /* [out] */ Elastos::Utility::ISet ** policies) = 0;

    virtual CARAPI GetParent(
        /* [out] */ Elastos::Security::Cert::IPolicyNode ** parent) = 0;

    virtual CARAPI GetPolicyQualifiers(
        /* [out] */ Elastos::Utility::ISet ** qualifiers) = 0;

    virtual CARAPI GetValidPolicy(
        /* [out] */ _ELASTOS String * policy) = 0;

    virtual CARAPI IsCritical(
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("D9BC6742-1C52-901C-15C4-3055E3878392")
ITrustAnchor : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITrustAnchor*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITrustAnchor*)pObj->Probe(EIID_ITrustAnchor);
    }

    static CARAPI_(ITrustAnchor*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITrustAnchor*)pObj->Probe(EIID_ITrustAnchor);
    }

    virtual CARAPI GetNameConstraints(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** nameConstraints) = 0;

    virtual CARAPI GetTrustedCert(
        /* [out] */ Elastos::Security::Cert::IX509Certificate ** cert) = 0;

    virtual CARAPI GetCA(
        /* [out] */ Elastosx::Security::Auth::X500::IX500Principal ** ca) = 0;

    virtual CARAPI GetCAName(
        /* [out] */ _ELASTOS String * caName) = 0;

    virtual CARAPI GetCAPublicKey(
        /* [out] */ Elastos::Security::IPublicKey ** key) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("41F65A21-0652-120A-4230-B87F23AB7712")
IPKIXCertPathValidatorResult : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPKIXCertPathValidatorResult*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPKIXCertPathValidatorResult*)pObj->Probe(EIID_IPKIXCertPathValidatorResult);
    }

    static CARAPI_(IPKIXCertPathValidatorResult*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPKIXCertPathValidatorResult*)pObj->Probe(EIID_IPKIXCertPathValidatorResult);
    }

    virtual CARAPI GetPolicyTree(
        /* [out] */ Elastos::Security::Cert::IPolicyNode ** policyTree) = 0;

    virtual CARAPI GetPublicKey(
        /* [out] */ Elastos::Security::IPublicKey ** key) = 0;

    virtual CARAPI GetTrustAnchor(
        /* [out] */ Elastos::Security::Cert::ITrustAnchor ** anchor) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("86C63C3C-0652-120A-4230-B87F232B9BFB")
IPKIXCertPathBuilderResult : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPKIXCertPathBuilderResult*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPKIXCertPathBuilderResult*)pObj->Probe(EIID_IPKIXCertPathBuilderResult);
    }

    static CARAPI_(IPKIXCertPathBuilderResult*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPKIXCertPathBuilderResult*)pObj->Probe(EIID_IPKIXCertPathBuilderResult);
    }

    virtual CARAPI GetCertPath(
        /* [out] */ Elastos::Security::Cert::ICertPath ** certPath) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("CE3F6429-0652-120A-4230-B87F236B9EFB")
IPKIXCertPathChecker : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPKIXCertPathChecker*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPKIXCertPathChecker*)pObj->Probe(EIID_IPKIXCertPathChecker);
    }

    static CARAPI_(IPKIXCertPathChecker*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPKIXCertPathChecker*)pObj->Probe(EIID_IPKIXCertPathChecker);
    }

    virtual CARAPI Init(
        /* [in] */ _ELASTOS Boolean forward) = 0;

    virtual CARAPI IsForwardCheckingSupported(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetSupportedExtensions(
        /* [out] */ Elastos::Utility::ISet ** extensions) = 0;

    virtual CARAPI Check(
        /* [in] */ Elastos::Security::Cert::ICertificate * cert,
        /* [in] */ Elastos::Utility::ICollection * unresolvedCritExts) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("27336339-57D2-380D-48BC-609182C5FD7D")
IPolicyQualifierInfo : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPolicyQualifierInfo*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPolicyQualifierInfo*)pObj->Probe(EIID_IPolicyQualifierInfo);
    }

    static CARAPI_(IPolicyQualifierInfo*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPolicyQualifierInfo*)pObj->Probe(EIID_IPolicyQualifierInfo);
    }

    virtual CARAPI GetEncoded(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** encoded) = 0;

    virtual CARAPI GetPolicyQualifierId(
        /* [out] */ _ELASTOS String * id) = 0;

    virtual CARAPI GetPolicyQualifier(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** qualifier) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("C69CF60E-5852-0900-B355-BFF392F62DDB")
IX509CRL : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IX509CRL*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX509CRL*)pObj->Probe(EIID_IX509CRL);
    }

    static CARAPI_(IX509CRL*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX509CRL*)pObj->Probe(EIID_IX509CRL);
    }

    virtual CARAPI Equals(
        /* [in] */ IInterface * other,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI GetEncoded(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** encoded) = 0;

    virtual CARAPI Verify(
        /* [in] */ Elastos::Security::IPublicKey * key) = 0;

    virtual CARAPI VerifyEx(
        /* [in] */ Elastos::Security::IPublicKey * key,
        /* [in] */ const _ELASTOS String& sigProvider) = 0;

    virtual CARAPI GetVersion(
        /* [out] */ _ELASTOS Int32 * vs) = 0;

    virtual CARAPI GetIssuerDN(
        /* [out] */ Elastos::Security::IPrincipal ** issuer) = 0;

    virtual CARAPI GetIssuerX500Principal(
        /* [out] */ Elastosx::Security::Auth::X500::IX500Principal ** issuer) = 0;

    virtual CARAPI GetThisUpdate(
        /* [out] */ Elastos::Utility::IDate ** thisUpdate) = 0;

    virtual CARAPI GetNextUpdate(
        /* [out] */ Elastos::Utility::IDate ** nextUpdate) = 0;

    virtual CARAPI GetRevokedCertificate(
        /* [in] */ Elastos::Math::IBigInteger * serialNumber,
        /* [out] */ Elastos::Security::Cert::IX509CRLEntry ** crlEntry) = 0;

    virtual CARAPI GetRevokedCertificateEx(
        /* [in] */ Elastos::Security::Cert::IX509Certificate * certificate,
        /* [out] */ Elastos::Security::Cert::IX509CRLEntry ** crlEntry) = 0;

    virtual CARAPI GetRevokedCertificates(
        /* [out] */ Elastos::Utility::ISet ** ctrlEntrys) = 0;

    virtual CARAPI GetTBSCertList(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** tbsCertList) = 0;

    virtual CARAPI GetSignature(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** signature) = 0;

    virtual CARAPI GetSigAlgName(
        /* [out] */ _ELASTOS String * sigAlgName) = 0;

    virtual CARAPI GetSigAlgOID(
        /* [out] */ _ELASTOS String * sigAlgOid) = 0;

    virtual CARAPI GetSigAlgParams(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** sigAlgParams) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("4BA88817-5852-8900-B3DF-686CB372FC3B")
IX509Extension : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IX509Extension*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX509Extension*)pObj->Probe(EIID_IX509Extension);
    }

    static CARAPI_(IX509Extension*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX509Extension*)pObj->Probe(EIID_IX509Extension);
    }

    virtual CARAPI GetCriticalExtensionOIDs(
        /* [out] */ Elastos::Utility::ISet ** oids) = 0;

    virtual CARAPI GetExtensionValue(
        /* [in] */ const _ELASTOS String& oid,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** extensionValue) = 0;

    virtual CARAPI GetNonCriticalExtensionOIDs(
        /* [out] */ Elastos::Utility::ISet ** oids) = 0;

    virtual CARAPI HasUnsupportedCriticalExtension(
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("33FD9328-8852-0002-1230-D85081D88FF6")
IX509CRLEntry : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IX509CRLEntry*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX509CRLEntry*)pObj->Probe(EIID_IX509CRLEntry);
    }

    static CARAPI_(IX509CRLEntry*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX509CRLEntry*)pObj->Probe(EIID_IX509CRLEntry);
    }

    virtual CARAPI Equals(
        /* [in] */ IInterface * other,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI GetEncoded(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** encoded) = 0;

    virtual CARAPI GetSerialNumber(
        /* [out] */ Elastos::Math::IBigInteger ** number) = 0;

    virtual CARAPI GetCertificateIssuer(
        /* [out] */ Elastosx::Security::Auth::X500::IX500Principal ** issuer) = 0;

    virtual CARAPI GetRevocationDate(
        /* [out] */ Elastos::Utility::IDate ** revocationDate) = 0;

    virtual CARAPI HasExtensions(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetRevocationReason(
        /* [out] */ Elastos::Security::Cert::CRLReason * reason) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("8C08FC39-8852-0002-1230-D850C172FE1F")
IX509CRLSelector : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IX509CRLSelector*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX509CRLSelector*)pObj->Probe(EIID_IX509CRLSelector);
    }

    static CARAPI_(IX509CRLSelector*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX509CRLSelector*)pObj->Probe(EIID_IX509CRLSelector);
    }

    virtual CARAPI SetIssuers(
        /* [in] */ Elastos::Utility::ICollection * issuers) = 0;

    virtual CARAPI SetIssuerNames(
        /* [in] */ Elastos::Utility::ICollection * names) = 0;

    virtual CARAPI AddIssuer(
        /* [in] */ Elastosx::Security::Auth::X500::IX500Principal * issuer) = 0;

    virtual CARAPI AddIssuerName(
        /* [in] */ const _ELASTOS String& issuerName) = 0;

    virtual CARAPI AddIssuerNameEx(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * iss_name) = 0;

    virtual CARAPI SetMinCRLNumber(
        /* [in] */ Elastos::Math::IBigInteger * minCRL) = 0;

    virtual CARAPI SetMaxCRLNumber(
        /* [in] */ Elastos::Math::IBigInteger * maxCRL) = 0;

    virtual CARAPI SetDateAndTime(
        /* [in] */ Elastos::Utility::IDate * dateAndTime) = 0;

    virtual CARAPI SetCertificateChecking(
        /* [in] */ Elastos::Security::Cert::IX509Certificate * cert) = 0;

    virtual CARAPI GetIssuers(
        /* [out] */ Elastos::Utility::ICollection ** issuers) = 0;

    virtual CARAPI GetIssuerNames(
        /* [out] */ Elastos::Utility::ICollection ** issuer) = 0;

    virtual CARAPI GetMinCRL(
        /* [out] */ Elastos::Math::IBigInteger ** minCrl) = 0;

    virtual CARAPI GetMaxCRL(
        /* [out] */ Elastos::Math::IBigInteger ** maxCrl) = 0;

    virtual CARAPI GetDateAndTime(
        /* [out] */ Elastos::Utility::IDate ** time) = 0;

    virtual CARAPI GetCertificateChecking(
        /* [out] */ Elastos::Security::Cert::IX509Certificate ** checking) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI Match(
        /* [in] */ Elastos::Security::Cert::ICRL * crl,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Clone(
        /* [out] */ IInterface ** obj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("046BF721-8852-0002-1230-B87FC372FE1F")
IX509CertSelector : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IX509CertSelector*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX509CertSelector*)pObj->Probe(EIID_IX509CertSelector);
    }

    static CARAPI_(IX509CertSelector*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX509CertSelector*)pObj->Probe(EIID_IX509CertSelector);
    }

    virtual CARAPI SetCertificate(
        /* [in] */ Elastos::Security::Cert::IX509Certificate * certificate) = 0;

    virtual CARAPI GetCertificate(
        /* [out] */ Elastos::Security::Cert::IX509Certificate ** certificate) = 0;

    virtual CARAPI SetSerialNumber(
        /* [in] */ Elastos::Math::IBigInteger * serialNumber) = 0;

    virtual CARAPI GetSerialNumber(
        /* [out] */ Elastos::Math::IBigInteger ** serialNumber) = 0;

    virtual CARAPI SetIssuer(
        /* [in] */ Elastosx::Security::Auth::X500::IX500Principal * issuer) = 0;

    virtual CARAPI GetIssuer(
        /* [out] */ Elastosx::Security::Auth::X500::IX500Principal ** issuer) = 0;

    virtual CARAPI SetIssuerUsingString(
        /* [in] */ const _ELASTOS String& issuerName) = 0;

    virtual CARAPI GetIssuerAsString(
        /* [out] */ _ELASTOS String * issuer) = 0;

    virtual CARAPI SetIssuerUsingBytes(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * issuerDN) = 0;

    virtual CARAPI GetIssuerAsBytes(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** issuerDN) = 0;

    virtual CARAPI SetSubject(
        /* [in] */ Elastosx::Security::Auth::X500::IX500Principal * subject) = 0;

    virtual CARAPI GetSubject(
        /* [out] */ Elastosx::Security::Auth::X500::IX500Principal ** subject) = 0;

    virtual CARAPI SetSubjectUsingString(
        /* [in] */ const _ELASTOS String& subjectDN) = 0;

    virtual CARAPI GetSubjectAsString(
        /* [out] */ _ELASTOS String * subjectDN) = 0;

    virtual CARAPI SetSubjectUsingBytes(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * subjectDN) = 0;

    virtual CARAPI GetSubjectAsBytes(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** subjectDN) = 0;

    virtual CARAPI SetSubjectKeyIdentifier(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * subjectKeyIdentifier) = 0;

    virtual CARAPI GetSubjectKeyIdentifier(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** subjectKeyIdentifier) = 0;

    virtual CARAPI SetAuthorityKeyIdentifier(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * authorityKeyIdentifier) = 0;

    virtual CARAPI GetAuthorityKeyIdentifier(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** authorityKeyIdentifier) = 0;

    virtual CARAPI SetCertificateValid(
        /* [in] */ Elastos::Utility::IDate * certificateValid) = 0;

    virtual CARAPI GetCertificateValid(
        /* [out] */ Elastos::Utility::IDate ** certificateValid) = 0;

    virtual CARAPI SetPrivateKeyValid(
        /* [in] */ Elastos::Utility::IDate * privateKeyValid) = 0;

    virtual CARAPI GetPrivateKeyValid(
        /* [out] */ Elastos::Utility::IDate ** privateKeyValid) = 0;

    virtual CARAPI SetSubjectPublicKeyAlgID(
        /* [in] */ const _ELASTOS String& oid) = 0;

    virtual CARAPI GetSubjectPublicKeyAlgID(
        /* [out] */ _ELASTOS String * oid) = 0;

    virtual CARAPI SetSubjectPublicKey(
        /* [in] */ Elastos::Security::IPublicKey * key) = 0;

    virtual CARAPI SetSubjectPublicKeyEx(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key) = 0;

    virtual CARAPI GetSubjectPublicKey(
        /* [out] */ Elastos::Security::IPublicKey ** key) = 0;

    virtual CARAPI SetKeyUsage(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Boolean> * keyUsage) = 0;

    virtual CARAPI GetKeyUsage(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Boolean> ** keyUsage) = 0;

    virtual CARAPI SetExtendedKeyUsage(
        /* [in] */ Elastos::Utility::ISet * keyUsage) = 0;

    virtual CARAPI GetExtendedKeyUsage(
        /* [out] */ Elastos::Utility::ISet ** keyUsage) = 0;

    virtual CARAPI SetMatchAllSubjectAltNames(
        /* [in] */ _ELASTOS Boolean matchAllNames) = 0;

    virtual CARAPI GetMatchAllSubjectAltNames(
        /* [out] */ _ELASTOS Boolean * matchAllNames) = 0;

    virtual CARAPI SetSubjectAlternativeNames(
        /* [in] */ Elastos::Utility::ICollection * names) = 0;

    virtual CARAPI AddSubjectAlternativeName(
        /* [in] */ _ELASTOS Int32 tag,
        /* [in] */ const _ELASTOS String& name) = 0;

    virtual CARAPI AddSubjectAlternativeNameEx(
        /* [in] */ _ELASTOS Int32 tag,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * name) = 0;

    virtual CARAPI GetSubjectAlternativeNames(
        /* [out] */ Elastos::Utility::ICollection ** names) = 0;

    virtual CARAPI SetNameConstraints(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * bytes) = 0;

    virtual CARAPI GetNameConstraints(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** bytes) = 0;

    virtual CARAPI SetBasicConstraints(
        /* [in] */ _ELASTOS Int32 pathLen) = 0;

    virtual CARAPI GetBasicConstraints(
        /* [out] */ _ELASTOS Int32 * pathLen) = 0;

    virtual CARAPI SetPolicy(
        /* [in] */ Elastos::Utility::ISet * policies) = 0;

    virtual CARAPI GetPolicy(
        /* [out] */ Elastos::Utility::ISet ** policies) = 0;

    virtual CARAPI AddPathToName(
        /* [in] */ _ELASTOS Int32 type,
        /* [in] */ const _ELASTOS String& name) = 0;

    virtual CARAPI SetPathToNames(
        /* [in] */ Elastos::Utility::ICollection * names) = 0;

    virtual CARAPI AddPathToNameEx(
        /* [in] */ _ELASTOS Int32 type,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * name) = 0;

    virtual CARAPI GetPathToNames(
        /* [out] */ Elastos::Utility::ICollection ** name) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("FC7D4D4E-06D2-0A0E-3084-AE9141EF4E2D")
IRSAOtherPrimeInfo : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRSAOtherPrimeInfo*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRSAOtherPrimeInfo*)pObj->Probe(EIID_IRSAOtherPrimeInfo);
    }

    static CARAPI_(IRSAOtherPrimeInfo*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRSAOtherPrimeInfo*)pObj->Probe(EIID_IRSAOtherPrimeInfo);
    }

    virtual CARAPI GetCrtCoefficient(
        /* [out] */ Elastos::Math::IBigInteger ** crtCoefficient) = 0;

    virtual CARAPI GetPrime(
        /* [out] */ Elastos::Math::IBigInteger ** prime) = 0;

    virtual CARAPI GetExponent(
        /* [out] */ Elastos::Math::IBigInteger ** exponent) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Interfaces {
CAR_INTERFACE("7BB42D1B-C352-1429-CAFF-CE4BDAB76CFF")
IDSAKey : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDSAKey*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDSAKey*)pObj->Probe(EIID_IDSAKey);
    }

    static CARAPI_(IDSAKey*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDSAKey*)pObj->Probe(EIID_IDSAKey);
    }

    virtual CARAPI GetParams(
        /* [out] */ Elastos::Security::Interfaces::IDSAParams ** parameters) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Interfaces {
CAR_INTERFACE("1D784712-C352-1429-CA67-245B43688CD6")
IDSAKeyPairGenerator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDSAKeyPairGenerator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDSAKeyPairGenerator*)pObj->Probe(EIID_IDSAKeyPairGenerator);
    }

    static CARAPI_(IDSAKeyPairGenerator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDSAKeyPairGenerator*)pObj->Probe(EIID_IDSAKeyPairGenerator);
    }

    virtual CARAPI Initialize(
        /* [in] */ Elastos::Security::Interfaces::IDSAParams * params,
        /* [in] */ Elastos::Security::ISecureRandom * random) = 0;

    virtual CARAPI InitializeEx(
        /* [in] */ _ELASTOS Int32 modlen,
        /* [in] */ _ELASTOS Boolean genParams,
        /* [in] */ Elastos::Security::ISecureRandom * random) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Interfaces {
CAR_INTERFACE("54DA3334-0352-0A0E-B0DA-F8D1DEC60D19")
IDSAParams : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDSAParams*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDSAParams*)pObj->Probe(EIID_IDSAParams);
    }

    static CARAPI_(IDSAParams*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDSAParams*)pObj->Probe(EIID_IDSAParams);
    }

    virtual CARAPI GetG(
        /* [out] */ Elastos::Math::IBigInteger ** base) = 0;

    virtual CARAPI GetP(
        /* [out] */ Elastos::Math::IBigInteger ** prime) = 0;

    virtual CARAPI GetQ(
        /* [out] */ Elastos::Math::IBigInteger ** subprime) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Interfaces {
CAR_INTERFACE("D9862F1E-C352-5929-CDE6-E48D5228FF3B")
IDSAPrivateKey : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDSAPrivateKey*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDSAPrivateKey*)pObj->Probe(EIID_IDSAPrivateKey);
    }

    static CARAPI_(IDSAPrivateKey*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDSAPrivateKey*)pObj->Probe(EIID_IDSAPrivateKey);
    }

    virtual CARAPI GetX(
        /* [out] */ Elastos::Math::IBigInteger ** x) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Interfaces {
CAR_INTERFACE("805B2E07-C352-1929-5EBE-AC49A1FCEFBC")
IDSAPublicKey : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDSAPublicKey*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDSAPublicKey*)pObj->Probe(EIID_IDSAPublicKey);
    }

    static CARAPI_(IDSAPublicKey*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDSAPublicKey*)pObj->Probe(EIID_IDSAPublicKey);
    }

    virtual CARAPI GetY(
        /* [out] */ Elastos::Math::IBigInteger ** y) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Interfaces {
CAR_INTERFACE("98E72C1B-C392-2850-FF3B-2F69DFB2FD73")
IECKey : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IECKey*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IECKey*)pObj->Probe(EIID_IECKey);
    }

    static CARAPI_(IECKey*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IECKey*)pObj->Probe(EIID_IECKey);
    }

    virtual CARAPI GetParams(
        /* [out] */ Elastos::Security::Spec::IECParameterSpec ** params) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Interfaces {
CAR_INTERFACE("8B2A2E15-C392-3564-9B93-374AA1FCEFBC")
IECPrivateKey : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IECPrivateKey*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IECPrivateKey*)pObj->Probe(EIID_IECPrivateKey);
    }

    static CARAPI_(IECPrivateKey*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IECPrivateKey*)pObj->Probe(EIID_IECPrivateKey);
    }

    virtual CARAPI GetS(
        /* [out] */ Elastos::Math::IBigInteger ** s) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Interfaces {
CAR_INTERFACE("5BD22D1B-C392-7864-F9B2-2685F2BFF392")
IECPublicKey : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IECPublicKey*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IECPublicKey*)pObj->Probe(EIID_IECPublicKey);
    }

    static CARAPI_(IECPublicKey*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IECPublicKey*)pObj->Probe(EIID_IECPublicKey);
    }

    virtual CARAPI GetW(
        /* [out] */ Elastos::Security::Spec::IECPoint ** s) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Interfaces {
CAR_INTERFACE("7F1D2E10-C6D2-1429-CAFF-CE4BDAB76CFF")
IRSAKey : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRSAKey*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRSAKey*)pObj->Probe(EIID_IRSAKey);
    }

    static CARAPI_(IRSAKey*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRSAKey*)pObj->Probe(EIID_IRSAKey);
    }

    virtual CARAPI GetModulus(
        /* [out] */ Elastos::Math::IBigInteger ** modulus) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Interfaces {
CAR_INTERFACE("BFB83D0A-C6D2-5929-CDE6-E48D5228FF3B")
IRSAPrivateKey : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRSAPrivateKey*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRSAPrivateKey*)pObj->Probe(EIID_IRSAPrivateKey);
    }

    static CARAPI_(IRSAPrivateKey*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRSAPrivateKey*)pObj->Probe(EIID_IRSAPrivateKey);
    }

    virtual CARAPI GetPrivateExponent(
        /* [out] */ Elastos::Math::IBigInteger ** privateExponent) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Interfaces {
CAR_INTERFACE("D21F9F12-C6D2-1629-FEDE-6C56B3309AD5")
IRSAMultiPrimePrivateCrtKey : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRSAMultiPrimePrivateCrtKey*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRSAMultiPrimePrivateCrtKey*)pObj->Probe(EIID_IRSAMultiPrimePrivateCrtKey);
    }

    static CARAPI_(IRSAMultiPrimePrivateCrtKey*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRSAMultiPrimePrivateCrtKey*)pObj->Probe(EIID_IRSAMultiPrimePrivateCrtKey);
    }

    virtual CARAPI GetCrtCoefficient(
        /* [out] */ Elastos::Math::IBigInteger ** crtCoefficient) = 0;

    virtual CARAPI GetOtherPrimeInfo(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::Spec::IRSAOtherPrimeInfo *> ** otherPrimeInfo) = 0;

    virtual CARAPI GetPrimeP(
        /* [out] */ Elastos::Math::IBigInteger ** primeP) = 0;

    virtual CARAPI GetPrimeQ(
        /* [out] */ Elastos::Math::IBigInteger ** primeQ) = 0;

    virtual CARAPI GetPrimeExponentP(
        /* [out] */ Elastos::Math::IBigInteger ** primeExponentP) = 0;

    virtual CARAPI GetPrimeExponentQ(
        /* [out] */ Elastos::Math::IBigInteger ** primeExponentQ) = 0;

    virtual CARAPI GetPublicExponent(
        /* [out] */ Elastos::Math::IBigInteger ** publicExponent) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Interfaces {
CAR_INTERFACE("357A8417-C6D2-5929-CDE6-E48D32F54DA1")
IRSAPrivateCrtKey : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRSAPrivateCrtKey*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRSAPrivateCrtKey*)pObj->Probe(EIID_IRSAPrivateCrtKey);
    }

    static CARAPI_(IRSAPrivateCrtKey*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRSAPrivateCrtKey*)pObj->Probe(EIID_IRSAPrivateCrtKey);
    }

    virtual CARAPI GetCrtCoefficient(
        /* [out] */ Elastos::Math::IBigInteger ** crtCoefficient) = 0;

    virtual CARAPI GetPrimeP(
        /* [out] */ Elastos::Math::IBigInteger ** primeP) = 0;

    virtual CARAPI GetPrimeQ(
        /* [out] */ Elastos::Math::IBigInteger ** primeQ) = 0;

    virtual CARAPI GetPrimeExponentP(
        /* [out] */ Elastos::Math::IBigInteger ** primeExponentP) = 0;

    virtual CARAPI GetPrimeExponentQ(
        /* [out] */ Elastos::Math::IBigInteger ** primeExponentQ) = 0;

    virtual CARAPI GetPublicExponent(
        /* [out] */ Elastos::Math::IBigInteger ** publicExponent) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Interfaces {
CAR_INTERFACE("A8C83B09-C6D2-1929-5EBE-AC49A1FCEFBC")
IRSAPublicKey : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRSAPublicKey*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRSAPublicKey*)pObj->Probe(EIID_IRSAPublicKey);
    }

    static CARAPI_(IRSAPublicKey*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRSAPublicKey*)pObj->Probe(EIID_IRSAPublicKey);
    }

    virtual CARAPI GetPublicExponent(
        /* [out] */ Elastos::Math::IBigInteger ** publicExponent) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("69F02E29-8292-2A17-F2B3-B8B102C6550E")
IAlgorithmParameterSpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAlgorithmParameterSpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAlgorithmParameterSpec*)pObj->Probe(EIID_IAlgorithmParameterSpec);
    }

    static CARAPI_(IAlgorithmParameterSpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAlgorithmParameterSpec*)pObj->Probe(EIID_IAlgorithmParameterSpec);
    }

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("E14A2832-0352-0A0E-AE72-9881C2C48FF6")
IDSAParameterSpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDSAParameterSpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDSAParameterSpec*)pObj->Probe(EIID_IDSAParameterSpec);
    }

    static CARAPI_(IDSAParameterSpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDSAParameterSpec*)pObj->Probe(EIID_IDSAParameterSpec);
    }

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("0A751F06-8512-DCF2-8C9A-BFF392F62DDB")
IKeySpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeySpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeySpec*)pObj->Probe(EIID_IKeySpec);
    }

    static CARAPI_(IKeySpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeySpec*)pObj->Probe(EIID_IKeySpec);
    }

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("0FF33918-C352-5929-CDE6-E48D5228CFCD")
IDSAPrivateKeySpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDSAPrivateKeySpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDSAPrivateKeySpec*)pObj->Probe(EIID_IDSAPrivateKeySpec);
    }

    static CARAPI_(IDSAPrivateKeySpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDSAPrivateKeySpec*)pObj->Probe(EIID_IDSAPrivateKeySpec);
    }

    virtual CARAPI GetG(
        /* [out] */ Elastos::Math::IBigInteger ** g) = 0;

    virtual CARAPI GetP(
        /* [out] */ Elastos::Math::IBigInteger ** p) = 0;

    virtual CARAPI GetQ(
        /* [out] */ Elastos::Math::IBigInteger ** q) = 0;

    virtual CARAPI GetX(
        /* [out] */ Elastos::Math::IBigInteger ** x) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("EC913812-C352-1929-5EBE-AC49A13C37A3")
IDSAPublicKeySpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDSAPublicKeySpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDSAPublicKeySpec*)pObj->Probe(EIID_IDSAPublicKeySpec);
    }

    static CARAPI_(IDSAPublicKeySpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDSAPublicKeySpec*)pObj->Probe(EIID_IDSAPublicKeySpec);
    }

    virtual CARAPI GetG(
        /* [out] */ Elastos::Math::IBigInteger ** g) = 0;

    virtual CARAPI GetP(
        /* [out] */ Elastos::Math::IBigInteger ** p) = 0;

    virtual CARAPI GetQ(
        /* [out] */ Elastos::Math::IBigInteger ** q) = 0;

    virtual CARAPI GetY(
        /* [out] */ Elastos::Math::IBigInteger ** y) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("B86B2B1B-C392-2C3C-FA9E-BFF392F62DDB")
IECField : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IECField*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IECField*)pObj->Probe(EIID_IECField);
    }

    static CARAPI_(IECField*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IECField*)pObj->Probe(EIID_IECField);
    }

    virtual CARAPI GetFieldSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("050C6D1D-C392-2C3C-FA9E-8F00FFCE4BDA")
IECFieldF2m : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IECFieldF2m*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IECFieldF2m*)pObj->Probe(EIID_IECFieldF2m);
    }

    static CARAPI_(IECFieldF2m*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IECFieldF2m*)pObj->Probe(EIID_IECFieldF2m);
    }

    virtual CARAPI GetM(
        /* [out] */ _ELASTOS Int32 * m) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * obj,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI GetMidTermsOfReductionPolynomial(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Int32> ** terms) = 0;

    virtual CARAPI GetReductionPolynomial(
        /* [out] */ Elastos::Math::IBigInteger ** rp) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("CF3F3602-C392-2C3C-FA9E-CFFC3B2F69DF")
IECFieldFp : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IECFieldFp*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IECFieldFp*)pObj->Probe(EIID_IECFieldFp);
    }

    static CARAPI_(IECFieldFp*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IECFieldFp*)pObj->Probe(EIID_IECFieldFp);
    }

    virtual CARAPI GetP(
        /* [out] */ Elastos::Math::IBigInteger ** p) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * obj,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("E5D73124-0392-1006-50C4-B8CA61060A13")
IECGenParameterSpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IECGenParameterSpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IECGenParameterSpec*)pObj->Probe(EIID_IECGenParameterSpec);
    }

    static CARAPI_(IECGenParameterSpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IECGenParameterSpec*)pObj->Probe(EIID_IECGenParameterSpec);
    }

    virtual CARAPI GetName(
        /* [out] */ _ELASTOS String * name) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("1F936630-0392-5706-39CC-4061E2477B1B")
IECParameterSpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IECParameterSpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IECParameterSpec*)pObj->Probe(EIID_IECParameterSpec);
    }

    static CARAPI_(IECParameterSpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IECParameterSpec*)pObj->Probe(EIID_IECParameterSpec);
    }

    virtual CARAPI GetCofactor(
        /* [out] */ _ELASTOS Int32 * cofactor) = 0;

    virtual CARAPI GetCurve(
        /* [out] */ Elastos::Security::Spec::IEllipticCurve ** curve) = 0;

    virtual CARAPI GetGenerator(
        /* [out] */ Elastos::Security::Spec::IECPoint ** generator) = 0;

    virtual CARAPI GetOrder(
        /* [out] */ Elastos::Math::IBigInteger ** order) = 0;

    virtual CARAPI SetCurveName(
        /* [in] */ const _ELASTOS String& curveName) = 0;

    virtual CARAPI GetCurveName(
        /* [out] */ _ELASTOS String * result) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("23F3333A-0392-5E06-7FB4-B77143868D1F")
IECPoint : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IECPoint*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IECPoint*)pObj->Probe(EIID_IECPoint);
    }

    static CARAPI_(IECPoint*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IECPoint*)pObj->Probe(EIID_IECPoint);
    }

    virtual CARAPI GetAffineX(
        /* [out] */ Elastos::Math::IBigInteger ** affineX) = 0;

    virtual CARAPI GetAffineY(
        /* [out] */ Elastos::Math::IBigInteger ** affineY) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("24F83517-C392-3564-9B93-374AA13C37A3")
IECPrivateKeySpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IECPrivateKeySpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IECPrivateKeySpec*)pObj->Probe(EIID_IECPrivateKeySpec);
    }

    static CARAPI_(IECPrivateKeySpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IECPrivateKeySpec*)pObj->Probe(EIID_IECPrivateKeySpec);
    }

    virtual CARAPI GetParams(
        /* [out] */ Elastos::Security::Spec::IECParameterSpec ** params) = 0;

    virtual CARAPI GetS(
        /* [out] */ Elastos::Math::IBigInteger ** s) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("296C3404-C392-7864-F9B2-2685F2DC8C9A")
IECPublicKeySpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IECPublicKeySpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IECPublicKeySpec*)pObj->Probe(EIID_IECPublicKeySpec);
    }

    static CARAPI_(IECPublicKeySpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IECPublicKeySpec*)pObj->Probe(EIID_IECPublicKeySpec);
    }

    virtual CARAPI GetParams(
        /* [out] */ Elastos::Security::Spec::IECParameterSpec ** params) = 0;

    virtual CARAPI GetW(
        /* [out] */ Elastos::Security::Spec::IECPoint ** w) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("28CC4D16-F392-ECBE-7CB3-2683D739FA3B")
IEllipticCurve : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IEllipticCurve*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEllipticCurve*)pObj->Probe(EIID_IEllipticCurve);
    }

    static CARAPI_(IEllipticCurve*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEllipticCurve*)pObj->Probe(EIID_IEllipticCurve);
    }

    virtual CARAPI GetA(
        /* [out] */ Elastos::Math::IBigInteger ** a) = 0;

    virtual CARAPI GetB(
        /* [out] */ Elastos::Math::IBigInteger ** b) = 0;

    virtual CARAPI GetField(
        /* [out] */ Elastos::Security::Spec::IECField ** field) = 0;

    virtual CARAPI GetSeed(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** seed) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * other,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("53153928-B012-0D13-39CC-4061E2477B1B")
IEncodedKeySpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IEncodedKeySpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEncodedKeySpec*)pObj->Probe(EIID_IEncodedKeySpec);
    }

    static CARAPI_(IEncodedKeySpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEncodedKeySpec*)pObj->Probe(EIID_IEncodedKeySpec);
    }

    virtual CARAPI GetEncoded(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** encoded) = 0;

    virtual CARAPI GetFormat(
        /* [out] */ _ELASTOS String * format) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("3A903B27-0592-0F08-025C-E5300385891F")
IMGF1ParameterSpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMGF1ParameterSpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMGF1ParameterSpec*)pObj->Probe(EIID_IMGF1ParameterSpec);
    }

    static CARAPI_(IMGF1ParameterSpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMGF1ParameterSpec*)pObj->Probe(EIID_IMGF1ParameterSpec);
    }

    virtual CARAPI GetDigestAlgorithm(
        /* [out] */ _ELASTOS String * algorithm) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("FB642B21-0652-0C0A-3820-0076A2218719")
IPKCS8EncodedKeySpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPKCS8EncodedKeySpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPKCS8EncodedKeySpec*)pObj->Probe(EIID_IPKCS8EncodedKeySpec);
    }

    static CARAPI_(IPKCS8EncodedKeySpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPKCS8EncodedKeySpec*)pObj->Probe(EIID_IPKCS8EncodedKeySpec);
    }

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("94987538-0652-1C0E-AE72-9881C2C48FF6")
IPSSParameterSpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPSSParameterSpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPSSParameterSpec*)pObj->Probe(EIID_IPSSParameterSpec);
    }

    static CARAPI_(IPSSParameterSpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPSSParameterSpec*)pObj->Probe(EIID_IPSSParameterSpec);
    }

    virtual CARAPI GetSaltLength(
        /* [out] */ _ELASTOS Int32 * saltLength) = 0;

    virtual CARAPI GetDigestAlgorithm(
        /* [out] */ _ELASTOS String * digestAlgo) = 0;

    virtual CARAPI GetMGFAlgorithm(
        /* [out] */ _ELASTOS String * mgfaAlgo) = 0;

    virtual CARAPI GetMGFParameters(
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec ** mgfParams) = 0;

    virtual CARAPI GetTrailerField(
        /* [out] */ _ELASTOS Int32 * trailerField) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("C1E82148-0652-971C-0652-B0F6C3414919")
IPublicKey : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPublicKey*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPublicKey*)pObj->Probe(EIID_IPublicKey);
    }

    static CARAPI_(IPublicKey*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPublicKey*)pObj->Probe(EIID_IPublicKey);
    }

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("36C34928-06D2-0A0E-1A42-4011E32A8719")
IRSAKeyGenParameterSpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRSAKeyGenParameterSpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRSAKeyGenParameterSpec*)pObj->Probe(EIID_IRSAKeyGenParameterSpec);
    }

    static CARAPI_(IRSAKeyGenParameterSpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRSAKeyGenParameterSpec*)pObj->Probe(EIID_IRSAKeyGenParameterSpec);
    }

    virtual CARAPI GetKeysize(
        /* [out] */ _ELASTOS Int32 * keySize) = 0;

    virtual CARAPI GetPublicExponent(
        /* [out] */ Elastos::Math::IBigInteger ** pubExponent) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("1347450F-C6D2-5929-CDE6-E48D5228CFCD")
IRSAPrivateKeySpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRSAPrivateKeySpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRSAPrivateKeySpec*)pObj->Probe(EIID_IRSAPrivateKeySpec);
    }

    static CARAPI_(IRSAPrivateKeySpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRSAPrivateKeySpec*)pObj->Probe(EIID_IRSAPrivateKeySpec);
    }

    virtual CARAPI GetModulus(
        /* [out] */ Elastos::Math::IBigInteger ** modulus) = 0;

    virtual CARAPI GetPrivateExponent(
        /* [out] */ Elastos::Math::IBigInteger ** exponent) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("57899D09-C6D2-1629-FEDE-6C56B3309AD5")
IRSAMultiPrimePrivateCrtKeySpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRSAMultiPrimePrivateCrtKeySpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRSAMultiPrimePrivateCrtKeySpec*)pObj->Probe(EIID_IRSAMultiPrimePrivateCrtKeySpec);
    }

    static CARAPI_(IRSAMultiPrimePrivateCrtKeySpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRSAMultiPrimePrivateCrtKeySpec*)pObj->Probe(EIID_IRSAMultiPrimePrivateCrtKeySpec);
    }

    virtual CARAPI GetCrtCoefficient(
        /* [out] */ Elastos::Math::IBigInteger ** crtCoefficient) = 0;

    virtual CARAPI GetOtherPrimeInfo(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::Spec::IRSAOtherPrimeInfo *> ** primeInfo) = 0;

    virtual CARAPI GetPrimeExponentP(
        /* [out] */ Elastos::Math::IBigInteger ** p) = 0;

    virtual CARAPI GetPrimeExponentQ(
        /* [out] */ Elastos::Math::IBigInteger ** q) = 0;

    virtual CARAPI GetPrimeP(
        /* [out] */ Elastos::Math::IBigInteger ** p) = 0;

    virtual CARAPI GetPrimeQ(
        /* [out] */ Elastos::Math::IBigInteger ** q) = 0;

    virtual CARAPI GetPublicExponent(
        /* [out] */ Elastos::Math::IBigInteger ** pubExponent) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("BAE3820D-C6D2-5929-CDE6-E48D32F54DA1")
IRSAPrivateCrtKeySpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRSAPrivateCrtKeySpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRSAPrivateCrtKeySpec*)pObj->Probe(EIID_IRSAPrivateCrtKeySpec);
    }

    static CARAPI_(IRSAPrivateCrtKeySpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRSAPrivateCrtKeySpec*)pObj->Probe(EIID_IRSAPrivateCrtKeySpec);
    }

    virtual CARAPI GetCrtCoefficient(
        /* [out] */ Elastos::Math::IBigInteger ** coefficient) = 0;

    virtual CARAPI GetPrimeExponentP(
        /* [out] */ Elastos::Math::IBigInteger ** p) = 0;

    virtual CARAPI GetPrimeExponentQ(
        /* [out] */ Elastos::Math::IBigInteger ** q) = 0;

    virtual CARAPI GetPrimeP(
        /* [out] */ Elastos::Math::IBigInteger ** p) = 0;

    virtual CARAPI GetPrimeQ(
        /* [out] */ Elastos::Math::IBigInteger ** q) = 0;

    virtual CARAPI GetPublicExponent(
        /* [out] */ Elastos::Math::IBigInteger ** pubExponent) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("371C4304-C6D2-1929-5EBE-AC49A13C37A3")
IRSAPublicKeySpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRSAPublicKeySpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRSAPublicKeySpec*)pObj->Probe(EIID_IRSAPublicKeySpec);
    }

    static CARAPI_(IRSAPublicKeySpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRSAPublicKeySpec*)pObj->Probe(EIID_IRSAPublicKeySpec);
    }

    virtual CARAPI GetModulus(
        /* [out] */ Elastos::Math::IBigInteger ** modulus) = 0;

    virtual CARAPI GetPublicExponent(
        /* [out] */ Elastos::Math::IBigInteger ** exponent) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("953E2A30-8852-0002-1200-3BD190C30C14")
IX509EncodedKeySpec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IX509EncodedKeySpec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX509EncodedKeySpec*)pObj->Probe(EIID_IX509EncodedKeySpec);
    }

    static CARAPI_(IX509EncodedKeySpec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IX509EncodedKeySpec*)pObj->Probe(EIID_IX509EncodedKeySpec);
    }

};
}
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("EC29473E-90D2-0C48-64C4-B88162C78D1F")
IAccessControlContext : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAccessControlContext*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAccessControlContext*)pObj->Probe(EIID_IAccessControlContext);
    }

    static CARAPI_(IAccessControlContext*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAccessControlContext*)pObj->Probe(EIID_IAccessControlContext);
    }

    virtual CARAPI CheckPermission(
        /* [in] */ Elastos::Security::IPermission * perm) = 0;

    virtual CARAPI GetDomainCombiner(
        /* [out] */ Elastos::Security::IDomainCombiner ** domCombiner) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("5C6D313E-8292-2A17-F2B3-B8B102C65508")
IAlgorithmParameterGeneratorSpi : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAlgorithmParameterGeneratorSpi*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAlgorithmParameterGeneratorSpi*)pObj->Probe(EIID_IAlgorithmParameterGeneratorSpi);
    }

    static CARAPI_(IAlgorithmParameterGeneratorSpi*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAlgorithmParameterGeneratorSpi*)pObj->Probe(EIID_IAlgorithmParameterGeneratorSpi);
    }

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("9D909C3D-90D2-2F48-EEFF-686FE3860C1B")
IAccessController : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAccessController*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAccessController*)pObj->Probe(EIID_IAccessController);
    }

    static CARAPI_(IAccessController*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAccessController*)pObj->Probe(EIID_IAccessController);
    }

    virtual CARAPI DoPrivileged(
        /* [in] */ Elastos::Security::IPrivilegedAction * action,
        /* [out] */ IInterface ** result) = 0;

    virtual CARAPI DoPrivileged(
        /* [in] */ Elastos::Security::IPrivilegedAction * action,
        /* [in] */ Elastos::Security::IAccessControlContext * context,
        /* [out] */ IInterface ** result) = 0;

    virtual CARAPI DoPrivileged(
        /* [in] */ Elastos::Security::IPrivilegedExceptionAction * action,
        /* [out] */ IInterface ** result) = 0;

    virtual CARAPI DoPrivileged(
        /* [in] */ Elastos::Security::IPrivilegedExceptionAction * action,
        /* [in] */ Elastos::Security::IAccessControlContext * context,
        /* [out] */ IInterface ** result) = 0;

    virtual CARAPI DoPrivilegedWithCombiner(
        /* [in] */ Elastos::Security::IPrivilegedAction * action,
        /* [out] */ IInterface ** result) = 0;

    virtual CARAPI DoPrivilegedWithCombiner(
        /* [in] */ Elastos::Security::IPrivilegedExceptionAction * action,
        /* [out] */ IInterface ** result) = 0;

    virtual CARAPI CheckPermission(
        /* [in] */ Elastos::Security::IPermission * permission) = 0;

    virtual CARAPI GetContext(
        /* [out] */ Elastos::Security::IAccessControlContext ** context) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("C25C672A-8292-2A17-F2B3-B8B102C65508")
IAlgorithmParameterGenerator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAlgorithmParameterGenerator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAlgorithmParameterGenerator*)pObj->Probe(EIID_IAlgorithmParameterGenerator);
    }

    static CARAPI_(IAlgorithmParameterGenerator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAlgorithmParameterGenerator*)pObj->Probe(EIID_IAlgorithmParameterGenerator);
    }

    virtual CARAPI GetAlgorithm(
        /* [out] */ _ELASTOS String * algorithm) = 0;

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI Init(
        /* [in] */ _ELASTOS Int32 size) = 0;

    virtual CARAPI Init(
        /* [in] */ _ELASTOS Int32 size,
        /* [in] */ Elastos::Security::ISecureRandom * random) = 0;

    virtual CARAPI Init(
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * genParamSpec) = 0;

    virtual CARAPI Init(
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * genParamSpec,
        /* [in] */ Elastos::Security::ISecureRandom * random) = 0;

    virtual CARAPI GenerateParameters(
        /* [out] */ Elastos::Security::IAlgorithmParameters ** parameters) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("1D6B552B-8292-2A17-F2B3-B8B102C65508")
IAlgorithmParameterGeneratorHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAlgorithmParameterGeneratorHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAlgorithmParameterGeneratorHelper*)pObj->Probe(EIID_IAlgorithmParameterGeneratorHelper);
    }

    static CARAPI_(IAlgorithmParameterGeneratorHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAlgorithmParameterGeneratorHelper*)pObj->Probe(EIID_IAlgorithmParameterGeneratorHelper);
    }

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Security::IAlgorithmParameterGenerator ** instance) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& provider,
        /* [out] */ Elastos::Security::IAlgorithmParameterGenerator ** instance) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastos::Security::IAlgorithmParameterGenerator ** instance) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("CC676D22-8292-2A17-F2B3-B8B102C6551B")
IAlgorithmParameters : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAlgorithmParameters*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAlgorithmParameters*)pObj->Probe(EIID_IAlgorithmParameters);
    }

    static CARAPI_(IAlgorithmParameters*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAlgorithmParameters*)pObj->Probe(EIID_IAlgorithmParameters);
    }

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI GetAlgorithm(
        /* [out] */ _ELASTOS String * algorithm) = 0;

    virtual CARAPI Init(
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * paramSpec) = 0;

    virtual CARAPI Init(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * params) = 0;

    virtual CARAPI Init(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * params,
        /* [in] */ const _ELASTOS String& format) = 0;

    virtual CARAPI GetParameterSpec(
        /* [in] */ const _ELASTOS ClassID & type,
        /* [out] */ IInterface ** paramSpec) = 0;

    virtual CARAPI GetEncoded(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** encoded) = 0;

    virtual CARAPI GetEncoded(
        /* [in] */ const _ELASTOS String& format,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** encoded) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("B9064D36-8292-2A17-F2B3-B8B102C6551B")
IAlgorithmParametersHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAlgorithmParametersHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAlgorithmParametersHelper*)pObj->Probe(EIID_IAlgorithmParametersHelper);
    }

    static CARAPI_(IAlgorithmParametersHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAlgorithmParametersHelper*)pObj->Probe(EIID_IAlgorithmParametersHelper);
    }

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Security::IAlgorithmParameters ** instance) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& provider,
        /* [out] */ Elastos::Security::IAlgorithmParameters ** instance) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastos::Security::IAlgorithmParameters ** instance) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("28F4AB3B-8652-321A-72B0-38713FF38FF6")
IProviderService : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IProviderService*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IProviderService*)pObj->Probe(EIID_IProviderService);
    }

    static CARAPI_(IProviderService*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IProviderService*)pObj->Probe(EIID_IProviderService);
    }

    virtual CARAPI AddAlias(
        /* [in] */ const _ELASTOS String& alias) = 0;

    virtual CARAPI PutAttribute(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI GetType(
        /* [out] */ _ELASTOS String * type) = 0;

    virtual CARAPI GetAlgorithm(
        /* [out] */ _ELASTOS String * algorithm) = 0;

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI GetClassName(
        /* [out] */ _ELASTOS String * className) = 0;

    virtual CARAPI SetClassName(
        /* [in] */ const _ELASTOS String& className) = 0;

    virtual CARAPI GetAttribute(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS String * attrib) = 0;

    virtual CARAPI GetAliases(
        /* [out] */ Elastos::Utility::IList ** aliases) = 0;

    virtual CARAPI NewInstance(
        /* [in] */ IInterface * constructorParameter,
        /* [out] */ IInterface ** instance) = 0;

    virtual CARAPI SupportsParameter(
        /* [in] */ IInterface * parameter,
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI GetAttributes(
        /* [out] */ Elastos::Utility::IMap ** attributes) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("8B6F815D-0652-BFBE-67D5-F8E1A0A40C1B")
IProvider : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IProvider*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IProvider*)pObj->Probe(EIID_IProvider);
    }

    static CARAPI_(IProvider*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IProvider*)pObj->Probe(EIID_IProvider);
    }

    virtual CARAPI GetName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetVersion(
        /* [out] */ _ELASTOS Double * versionNumber) = 0;

    virtual CARAPI GetInfo(
        /* [out] */ _ELASTOS String * info) = 0;

    virtual CARAPI ImplementsAlg(
        /* [in] */ const _ELASTOS String& serv,
        /* [in] */ const _ELASTOS String& alg,
        /* [in] */ const _ELASTOS String& attribute,
        /* [in] */ const _ELASTOS String& val,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI SetProviderNumber(
        /* [in] */ _ELASTOS Int32 n) = 0;

    virtual CARAPI GetProviderNumber(
        /* [out] */ _ELASTOS Int32 * n) = 0;

    virtual CARAPI GetService(
        /* [in] */ const _ELASTOS String& type,
        /* [out] */ Elastos::Security::IProviderService ** service) = 0;

    virtual CARAPI GetService(
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Security::IProviderService ** service) = 0;

    virtual CARAPI GetServices(
        /* [out] */ Elastos::Utility::ISet ** services) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("6B2E3C16-8292-6BDF-56CB-397BA2F5EFBC")
IAuthProvider : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAuthProvider*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAuthProvider*)pObj->Probe(EIID_IAuthProvider);
    }

    static CARAPI_(IAuthProvider*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAuthProvider*)pObj->Probe(EIID_IAuthProvider);
    }

    virtual CARAPI Login(
        /* [in] */ Elastosx::Security::Auth::ISubject * subject,
        /* [in] */ Elastosx::Security::Auth::Callback::ICallbackHandler * handler) = 0;

    virtual CARAPI Logout() = 0;

    virtual CARAPI SetCallbackHandler(
        /* [in] */ Elastosx::Security::Auth::Callback::ICallbackHandler * handler) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("19C45F41-8312-9F67-BB75-D2FCC3414919")
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

    virtual CARAPI Decode(
        /* [in] */ Elastos::IO::IInputStream * stream) = 0;

    virtual CARAPI Encode(
        /* [in] */ Elastos::IO::IOutputStream * stream) = 0;

    virtual CARAPI GetFormat(
        /* [out] */ _ELASTOS String * format) = 0;

    virtual CARAPI GetGuarantor(
        /* [out] */ Elastos::Security::IPrincipal ** guarantor) = 0;

    virtual CARAPI GetPrincipal(
        /* [out] */ Elastos::Security::IPrincipal ** principal) = 0;

    virtual CARAPI GetPublicKey(
        /* [out] */ Elastos::Security::IPublicKey ** pubKey) = 0;

    virtual CARAPI ToString(
        /* [in] */ _ELASTOS Boolean detailed,
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("DC0C5224-F112-241B-60CC-F8D1DEC60D19")
ITimestamp : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITimestamp*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITimestamp*)pObj->Probe(EIID_ITimestamp);
    }

    static CARAPI_(ITimestamp*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITimestamp*)pObj->Probe(EIID_ITimestamp);
    }

    virtual CARAPI Equals(
        /* [in] */ PInterface obj,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetSignerCertPath(
        /* [out] */ Elastos::Security::Cert::ICertPath ** path) = 0;

    virtual CARAPI GetTimestamp(
        /* [out] */ Elastos::Utility::IDate ** dt) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * strVal) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("B7CF3A3F-2012-2C0E-54C4-B8FFA3BD8D1B")
ICodeSigner : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICodeSigner*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICodeSigner*)pObj->Probe(EIID_ICodeSigner);
    }

    static CARAPI_(ICodeSigner*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICodeSigner*)pObj->Probe(EIID_ICodeSigner);
    }

    virtual CARAPI GetSignerCertPath(
        /* [out] */ Elastos::Security::Cert::ICertPath ** certPath) = 0;

    virtual CARAPI GetTimestamp(
        /* [out] */ Elastos::Security::ITimestamp ** timestamp) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("4A0C4C3E-2012-3FD3-DADB-B821C3C60F0E")
ICodeSource : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICodeSource*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICodeSource*)pObj->Probe(EIID_ICodeSource);
    }

    static CARAPI_(ICodeSource*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICodeSource*)pObj->Probe(EIID_ICodeSource);
    }

    virtual CARAPI GetCertificates(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::ICertificate *> ** certs) = 0;

    virtual CARAPI GetCodeSigners(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::ICodeSigner *> ** codeSigners) = 0;

    virtual CARAPI GetLocation(
        /* [out] */ Elastos::Net::IURL ** location) = 0;

    virtual CARAPI Implies(
        /* [in] */ Elastos::Security::ICodeSource * cs,
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("416C465C-1292-9074-B7AC-65230CC60F07")
IDigestInputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDigestInputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDigestInputStream*)pObj->Probe(EIID_IDigestInputStream);
    }

    static CARAPI_(IDigestInputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDigestInputStream*)pObj->Probe(EIID_IDigestInputStream);
    }

    virtual CARAPI GetMessageDigest(
        /* [out] */ Elastos::Security::IMessageDigest ** msgDigest) = 0;

    virtual CARAPI SetMessageDigest(
        /* [in] */ Elastos::Security::IMessageDigest * digest) = 0;

    virtual CARAPI On(
        /* [in] */ _ELASTOS Boolean on) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("1616473A-0352-2A16-F0DF-902A1B050918")
IDigestOutputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDigestOutputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDigestOutputStream*)pObj->Probe(EIID_IDigestOutputStream);
    }

    static CARAPI_(IDigestOutputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDigestOutputStream*)pObj->Probe(EIID_IDigestOutputStream);
    }

    virtual CARAPI GetMessageDigest(
        /* [out] */ Elastos::Security::IMessageDigest ** msgDigest) = 0;

    virtual CARAPI SetMessageDigest(
        /* [in] */ Elastos::Security::IMessageDigest * digest) = 0;

    virtual CARAPI On(
        /* [in] */ _ELASTOS Boolean on) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("7B29282F-2D52-3206-6094-6011E3FE8FF6")
IDomainCombiner : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDomainCombiner*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDomainCombiner*)pObj->Probe(EIID_IDomainCombiner);
    }

    static CARAPI_(IDomainCombiner*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDomainCombiner*)pObj->Probe(EIID_IDomainCombiner);
    }

    virtual CARAPI Combine(
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::IProtectionDomain *> * current,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::IProtectionDomain *> * assigned,
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::IProtectionDomain *> ** result) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("BE68220D-8412-F593-F93B-2F69DFB2FD73")
IGuard : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IGuard*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IGuard*)pObj->Probe(EIID_IGuard);
    }

    static CARAPI_(IGuard*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IGuard*)pObj->Probe(EIID_IGuard);
    }

    virtual CARAPI CheckGuard(
        /* [in] */ IInterface * object) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("005E2947-0412-891C-669D-F8F2C3414919")
IGuardedObject : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IGuardedObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IGuardedObject*)pObj->Probe(EIID_IGuardedObject);
    }

    static CARAPI_(IGuardedObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IGuardedObject*)pObj->Probe(EIID_IGuardedObject);
    }

    virtual CARAPI GetObject(
        /* [out] */ IInterface ** object) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("B1A47C4B-9592-1865-7F38-2829C3C60F0E")
IIdentity : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IIdentity*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IIdentity*)pObj->Probe(EIID_IIdentity);
    }

    static CARAPI_(IIdentity*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IIdentity*)pObj->Probe(EIID_IIdentity);
    }

    virtual CARAPI AddCertificate(
        /* [in] */ Elastos::Security::ICertificate * certificate) = 0;

    virtual CARAPI RemoveCertificate(
        /* [in] */ Elastos::Security::ICertificate * certificate) = 0;

    virtual CARAPI Certificates(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::ICertificate *> ** certs) = 0;

    virtual CARAPI ToString(
        /* [in] */ _ELASTOS Boolean detailed,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetScope(
        /* [out] */ Elastos::Security::IIdentityScope ** scope) = 0;

    virtual CARAPI SetPublicKey(
        /* [in] */ Elastos::Security::IPublicKey * key) = 0;

    virtual CARAPI GetPublicKey(
        /* [out] */ Elastos::Security::IPublicKey ** pubKey) = 0;

    virtual CARAPI SetInfo(
        /* [in] */ const _ELASTOS String& info) = 0;

    virtual CARAPI GetInfo(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("97DB6B5D-9592-1865-39B8-0AFBC3414919")
IIdentityScope : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IIdentityScope*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IIdentityScope*)pObj->Probe(EIID_IIdentityScope);
    }

    static CARAPI_(IIdentityScope*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IIdentityScope*)pObj->Probe(EIID_IIdentityScope);
    }

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetIdentity(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Security::IIdentity ** identity) = 0;

    virtual CARAPI GetIdentity(
        /* [in] */ Elastos::Security::IPrincipal * principal,
        /* [out] */ Elastos::Security::IIdentity ** identity) = 0;

    virtual CARAPI GetIdentity(
        /* [in] */ Elastos::Security::IPublicKey * key,
        /* [out] */ Elastos::Security::IIdentity ** identity) = 0;

    virtual CARAPI AddIdentity(
        /* [in] */ Elastos::Security::IIdentity * identity) = 0;

    virtual CARAPI RemoveIdentity(
        /* [in] */ Elastos::Security::IIdentity * identity) = 0;

    virtual CARAPI Identities(
        /* [out] */ Elastos::Utility::IEnumeration ** ids) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("E2BD3442-9592-1865-39B8-0A1B01C58BB0")
IIdentityScopeHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IIdentityScopeHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IIdentityScopeHelper*)pObj->Probe(EIID_IIdentityScopeHelper);
    }

    static CARAPI_(IIdentityScopeHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IIdentityScopeHelper*)pObj->Probe(EIID_IIdentityScopeHelper);
    }

    virtual CARAPI GetSystemScope(
        /* [out] */ Elastos::Security::IIdentityScope ** scope) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("3D246729-4352-3F68-DADB-B821C3C60F0E")
IKeyFactory : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyFactory*)pObj->Probe(EIID_IKeyFactory);
    }

    static CARAPI_(IKeyFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyFactory*)pObj->Probe(EIID_IKeyFactory);
    }

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI GetAlgorithm(
        /* [out] */ _ELASTOS String * algorithm) = 0;

    virtual CARAPI GeneratePublic(
        /* [in] */ Elastos::Security::Spec::IKeySpec * keySpec,
        /* [out] */ Elastos::Security::IPublicKey ** pubKey) = 0;

    virtual CARAPI GeneratePrivate(
        /* [in] */ Elastos::Security::Spec::IKeySpec * keySpec,
        /* [out] */ Elastos::Security::IPrivateKey ** prvKey) = 0;

    virtual CARAPI GetKeySpec(
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ const _ELASTOS ClassID & type,
        /* [out] */ Elastos::Security::Spec::IKeySpec ** keySpec) = 0;

    virtual CARAPI TranslateKey(
        /* [in] */ Elastos::Security::IKey * key,
        /* [out] */ Elastos::Security::IKey ** translatedKey) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("A2DA442C-4352-1168-50BC-9871FF477B1B")
IKeyFactoryHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyFactoryHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyFactoryHelper*)pObj->Probe(EIID_IKeyFactoryHelper);
    }

    static CARAPI_(IKeyFactoryHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyFactoryHelper*)pObj->Probe(EIID_IKeyFactoryHelper);
    }

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Security::IKeyFactory ** instance) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& provider,
        /* [out] */ Elastos::Security::IKeyFactory ** instance) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastos::Security::IKeyFactory ** instance) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("BC516B2D-4352-1C68-66B0-F8D1DEC60D19")
IKeyFactorySpi : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyFactorySpi*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyFactorySpi*)pObj->Probe(EIID_IKeyFactorySpi);
    }

    static CARAPI_(IKeyFactorySpi*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyFactorySpi*)pObj->Probe(EIID_IKeyFactorySpi);
    }

    virtual CARAPI EngineGeneratePublic(
        /* [in] */ Elastos::Security::Spec::IKeySpec * keySpec,
        /* [out] */ Elastos::Security::IPublicKey ** pubKey) = 0;

    virtual CARAPI EngineGeneratePrivate(
        /* [in] */ Elastos::Security::Spec::IKeySpec * keySpec,
        /* [out] */ Elastos::Security::IPrivateKey ** priKey) = 0;

    virtual CARAPI EngineGetKeySpec(
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ const _ELASTOS ClassID & keySpec,
        /* [out] */ Elastos::Security::Spec::IKeySpec ** retkeySpec) = 0;

    virtual CARAPI EngineTranslateKey(
        /* [in] */ Elastos::Security::IKey * key,
        /* [out] */ Elastos::Security::IKey ** translatedKey) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("41762D0A-8512-19F2-C9D6-BFF392F62DDB")
IKeyPair : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyPair*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyPair*)pObj->Probe(EIID_IKeyPair);
    }

    static CARAPI_(IKeyPair*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyPair*)pObj->Probe(EIID_IKeyPair);
    }

    virtual CARAPI GetPrivate(
        /* [out] */ Elastos::Security::IPrivateKey ** prvKey) = 0;

    virtual CARAPI GetPublic(
        /* [out] */ Elastos::Security::IPublicKey ** pubKey) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("3D057B50-0512-196B-FCD4-80C0ECD9A3AB")
IKeyPairGenerator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyPairGenerator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyPairGenerator*)pObj->Probe(EIID_IKeyPairGenerator);
    }

    static CARAPI_(IKeyPairGenerator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyPairGenerator*)pObj->Probe(EIID_IKeyPairGenerator);
    }

    virtual CARAPI GetAlgorithm(
        /* [out] */ _ELASTOS String * algorithm) = 0;

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI Initialize(
        /* [in] */ _ELASTOS Int32 keysize) = 0;

    virtual CARAPI Initialize(
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * param) = 0;

    virtual CARAPI GenKeyPair(
        /* [out] */ Elastos::Security::IKeyPair ** keyPair) = 0;

    virtual CARAPI GenerateKeyPair(
        /* [out] */ Elastos::Security::IKeyPair ** keyPair) = 0;

    virtual CARAPI Initialize(
        /* [in] */ _ELASTOS Int32 keysize,
        /* [in] */ Elastos::Security::ISecureRandom * random) = 0;

    virtual CARAPI Initialize(
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * param,
        /* [in] */ Elastos::Security::ISecureRandom * random) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("7BA44A42-0512-196B-FCD4-80C0ECD9A3AB")
IKeyPairGeneratorHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyPairGeneratorHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyPairGeneratorHelper*)pObj->Probe(EIID_IKeyPairGeneratorHelper);
    }

    static CARAPI_(IKeyPairGeneratorHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyPairGeneratorHelper*)pObj->Probe(EIID_IKeyPairGeneratorHelper);
    }

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Security::IKeyPairGenerator ** instance) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& provider,
        /* [out] */ Elastos::Security::IKeyPairGenerator ** instance) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastos::Security::IKeyPairGenerator ** instance) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("97B74949-0512-196B-FCD4-80C0ECD9A3AB")
IKeyPairGeneratorSpi : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyPairGeneratorSpi*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyPairGeneratorSpi*)pObj->Probe(EIID_IKeyPairGeneratorSpi);
    }

    static CARAPI_(IKeyPairGeneratorSpi*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyPairGeneratorSpi*)pObj->Probe(EIID_IKeyPairGeneratorSpi);
    }

    virtual CARAPI GenerateKeyPair(
        /* [out] */ Elastos::Security::IKeyPair ** keyPair) = 0;

    virtual CARAPI Initialize(
        /* [in] */ _ELASTOS Int32 keysize,
        /* [in] */ Elastos::Security::ISecureRandom * random) = 0;

    virtual CARAPI Initialize(
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * params,
        /* [in] */ Elastos::Security::ISecureRandom * random) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("881A432D-C352-6CD7-EEFF-686FE3860C1B")
IKeyStoreBuilder : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyStoreBuilder*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStoreBuilder*)pObj->Probe(EIID_IKeyStoreBuilder);
    }

    static CARAPI_(IKeyStoreBuilder*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStoreBuilder*)pObj->Probe(EIID_IKeyStoreBuilder);
    }

    virtual CARAPI GetKeyStore(
        /* [out] */ Elastos::Security::IKeyStore ** keyStore) = 0;

    virtual CARAPI GetProtectionParameter(
        /* [in] */ const _ELASTOS String& alias,
        /* [out] */ Elastos::Security::IKeyStoreProtectionParameter ** protectionParameter) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("7EE24921-C352-6CD7-EE47-40F162C6FD1F")
IKeyStoreBuilderHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyStoreBuilderHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStoreBuilderHelper*)pObj->Probe(EIID_IKeyStoreBuilderHelper);
    }

    static CARAPI_(IKeyStoreBuilderHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStoreBuilderHelper*)pObj->Probe(EIID_IKeyStoreBuilderHelper);
    }

    virtual CARAPI NewInstance(
        /* [in] */ Elastos::Security::IKeyStore * keyStore,
        /* [in] */ Elastos::Security::IKeyStoreProtectionParameter * protectionParameter,
        /* [out] */ Elastos::Security::IKeyStoreBuilder ** instance) = 0;

    virtual CARAPI NewInstance(
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ Elastos::Security::IKeyStoreProtectionParameter * protectionParameter,
        /* [out] */ Elastos::Security::IKeyStoreBuilder ** instance) = 0;

    virtual CARAPI NewInstance(
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ Elastos::Security::IKeyStoreProtectionParameter * protectionParameter,
        /* [out] */ Elastos::Security::IKeyStoreBuilder ** instance) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("C5DD2029-C352-C4D7-7EB4-B77143868D1F")
IKeyStoreEntry : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyStoreEntry*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStoreEntry*)pObj->Probe(EIID_IKeyStoreEntry);
    }

    static CARAPI_(IKeyStoreEntry*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStoreEntry*)pObj->Probe(EIID_IKeyStoreEntry);
    }

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("43FB603E-C352-19D7-6AB0-C841E2068A86")
IKeyStorePrivateKeyEntry : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyStorePrivateKeyEntry*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStorePrivateKeyEntry*)pObj->Probe(EIID_IKeyStorePrivateKeyEntry);
    }

    static CARAPI_(IKeyStorePrivateKeyEntry*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStorePrivateKeyEntry*)pObj->Probe(EIID_IKeyStorePrivateKeyEntry);
    }

    virtual CARAPI GetPrivateKey(
        /* [out] */ Elastos::Security::IPrivateKey ** privateKey) = 0;

    virtual CARAPI GetCertificateChain(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> ** cc) = 0;

    virtual CARAPI GetCertificate(
        /* [out] */ Elastos::Security::Cert::ICertificate ** cert) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("CB543D3B-C352-1CD7-5098-A881E2464362")
IKeyStoreSecretKeyEntry : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyStoreSecretKeyEntry*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStoreSecretKeyEntry*)pObj->Probe(EIID_IKeyStoreSecretKeyEntry);
    }

    static CARAPI_(IKeyStoreSecretKeyEntry*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStoreSecretKeyEntry*)pObj->Probe(EIID_IKeyStoreSecretKeyEntry);
    }

    virtual CARAPI GetSecretKey(
        /* [out] */ Elastosx::Crypto::ISecretKey ** key) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("FB9E4F2A-C352-1DD7-6AE0-B071433F83FB")
IKeyStoreTrustedCertificateEntry : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyStoreTrustedCertificateEntry*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStoreTrustedCertificateEntry*)pObj->Probe(EIID_IKeyStoreTrustedCertificateEntry);
    }

    static CARAPI_(IKeyStoreTrustedCertificateEntry*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStoreTrustedCertificateEntry*)pObj->Probe(EIID_IKeyStoreTrustedCertificateEntry);
    }

    virtual CARAPI GetTrustedCertificate(
        /* [out] */ Elastos::Security::Cert::ICertificate ** cert) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("A8E84338-C352-1CD7-5F5F-FDD1DEC60D19")
IKeyStoreLoadStoreParameter : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyStoreLoadStoreParameter*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStoreLoadStoreParameter*)pObj->Probe(EIID_IKeyStoreLoadStoreParameter);
    }

    static CARAPI_(IKeyStoreLoadStoreParameter*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStoreLoadStoreParameter*)pObj->Probe(EIID_IKeyStoreLoadStoreParameter);
    }

    virtual CARAPI GetProtectionParameter(
        /* [out] */ Elastos::Security::IKeyStoreProtectionParameter ** protectionParameter) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("D90E2E21-C352-6AD7-E55F-FDD1DEC60D19")
IKeyStoreProtectionParameter : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyStoreProtectionParameter*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStoreProtectionParameter*)pObj->Probe(EIID_IKeyStoreProtectionParameter);
    }

    static CARAPI_(IKeyStoreProtectionParameter*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStoreProtectionParameter*)pObj->Probe(EIID_IKeyStoreProtectionParameter);
    }

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("5B6E4626-C352-71D7-CEA9-95FFA3BD8D1B")
IKeyStoreCallbackHandlerProtection : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyStoreCallbackHandlerProtection*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStoreCallbackHandlerProtection*)pObj->Probe(EIID_IKeyStoreCallbackHandlerProtection);
    }

    static CARAPI_(IKeyStoreCallbackHandlerProtection*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStoreCallbackHandlerProtection*)pObj->Probe(EIID_IKeyStoreCallbackHandlerProtection);
    }

    virtual CARAPI GetCallbackHandler(
        /* [out] */ Elastosx::Security::Auth::Callback::ICallbackHandler ** handler) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("CEEF3839-C352-19D7-48D8-B0A123FF09B5")
IKeyStorePasswordProtection : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyStorePasswordProtection*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStorePasswordProtection*)pObj->Probe(EIID_IKeyStorePasswordProtection);
    }

    static CARAPI_(IKeyStorePasswordProtection*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStorePasswordProtection*)pObj->Probe(EIID_IKeyStorePasswordProtection);
    }

    virtual CARAPI GetPassword(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Char32> ** pwd) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("A32AF93E-C352-3FD7-DADB-B821C3C60F0E")
IKeyStore : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyStore*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStore*)pObj->Probe(EIID_IKeyStore);
    }

    static CARAPI_(IKeyStore*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStore*)pObj->Probe(EIID_IKeyStore);
    }

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI GetType(
        /* [out] */ _ELASTOS String * type) = 0;

    virtual CARAPI GetKey(
        /* [in] */ const _ELASTOS String& alias,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [out] */ Elastos::Security::IKey ** key) = 0;

    virtual CARAPI GetCertificateChain(
        /* [in] */ const _ELASTOS String& alias,
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> ** certChain) = 0;

    virtual CARAPI GetCertificate(
        /* [in] */ const _ELASTOS String& alias,
        /* [out] */ Elastos::Security::Cert::ICertificate ** cert) = 0;

    virtual CARAPI GetCreationDate(
        /* [in] */ const _ELASTOS String& alias,
        /* [out] */ Elastos::Utility::IDate ** creationDate) = 0;

    virtual CARAPI SetKeyEntry(
        /* [in] */ const _ELASTOS String& alias,
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> * chain) = 0;

    virtual CARAPI SetKeyEntryEx(
        /* [in] */ const _ELASTOS String& alias,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> * chain) = 0;

    virtual CARAPI SetCertificateEntry(
        /* [in] */ const _ELASTOS String& alias,
        /* [in] */ Elastos::Security::Cert::ICertificate * cert) = 0;

    virtual CARAPI DeleteEntry(
        /* [in] */ const _ELASTOS String& alias) = 0;

    virtual CARAPI Aliases(
        /* [out] */ Elastos::Utility::IEnumeration ** enumeration) = 0;

    virtual CARAPI ContainsAlias(
        /* [in] */ const _ELASTOS String& alias,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI IsKeyEntry(
        /* [in] */ const _ELASTOS String& alias,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI IsCertificateEntry(
        /* [in] */ const _ELASTOS String& alias,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetCertificateAlias(
        /* [in] */ Elastos::Security::Cert::ICertificate * cert,
        /* [out] */ _ELASTOS String * alias) = 0;

    virtual CARAPI Store(
        /* [in] */ Elastos::IO::IOutputStream * stream,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password) = 0;

    virtual CARAPI StoreEx(
        /* [in] */ Elastos::Security::IKeyStoreLoadStoreParameter * param) = 0;

    virtual CARAPI Load(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password) = 0;

    virtual CARAPI LoadEx(
        /* [in] */ Elastos::Security::IKeyStoreLoadStoreParameter * param) = 0;

    virtual CARAPI GetEntry(
        /* [in] */ const _ELASTOS String& alias,
        /* [in] */ Elastos::Security::IKeyStoreProtectionParameter * param,
        /* [out] */ Elastos::Security::IKeyStoreEntry ** entry) = 0;

    virtual CARAPI SetEntry(
        /* [in] */ const _ELASTOS String& alias,
        /* [in] */ Elastos::Security::IKeyStoreEntry * entry,
        /* [in] */ Elastos::Security::IKeyStoreProtectionParameter * param) = 0;

    virtual CARAPI EntryInstanceOf(
        /* [in] */ const _ELASTOS String& alias,
        /* [in] */ const _ELASTOS ClassID & entryClass,
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("2B91503C-C352-11D7-50BC-9871FF477B1B")
IKeyStoreHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyStoreHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStoreHelper*)pObj->Probe(EIID_IKeyStoreHelper);
    }

    static CARAPI_(IKeyStoreHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStoreHelper*)pObj->Probe(EIID_IKeyStoreHelper);
    }

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& type,
        /* [out] */ Elastos::Security::IKeyStore ** instance) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ const _ELASTOS String& provider,
        /* [out] */ Elastos::Security::IKeyStore ** instance) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastos::Security::IKeyStore ** instance) = 0;

    virtual CARAPI GetDefaultType(
        /* [out] */ _ELASTOS String * defaultType) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("4E8AF225-C352-1CD7-66B0-F8D1DEC60D19")
IKeyStoreSpi : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKeyStoreSpi*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStoreSpi*)pObj->Probe(EIID_IKeyStoreSpi);
    }

    static CARAPI_(IKeyStoreSpi*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKeyStoreSpi*)pObj->Probe(EIID_IKeyStoreSpi);
    }

    virtual CARAPI EngineGetKey(
        /* [in] */ const _ELASTOS String& alias,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [out] */ Elastos::Security::IKey ** key) = 0;

    virtual CARAPI EngineGetCertificateChain(
        /* [in] */ const _ELASTOS String& alias,
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> ** certChain) = 0;

    virtual CARAPI EngineGetCertificate(
        /* [in] */ const _ELASTOS String& alias,
        /* [out] */ Elastos::Security::Cert::ICertificate ** cert) = 0;

    virtual CARAPI EngineGetCreationDate(
        /* [in] */ const _ELASTOS String& alias,
        /* [out] */ Elastos::Utility::IDate ** creationDate) = 0;

    virtual CARAPI EngineSetKeyEntry(
        /* [in] */ const _ELASTOS String& alias,
        /* [in] */ Elastos::Security::IKey * key,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> * chain) = 0;

    virtual CARAPI EngineSetKeyEntry(
        /* [in] */ const _ELASTOS String& alias,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * key,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> * chain) = 0;

    virtual CARAPI EngineSetCertificateEntry(
        /* [in] */ const _ELASTOS String& alias,
        /* [in] */ Elastos::Security::Cert::ICertificate * cert) = 0;

    virtual CARAPI EngineDeleteEntry(
        /* [in] */ const _ELASTOS String& alias) = 0;

    virtual CARAPI EngineAliases(
        /* [out] */ Elastos::Utility::IEnumeration ** aliases) = 0;

    virtual CARAPI EngineContainsAlias(
        /* [in] */ const _ELASTOS String& alias,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI EngineSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI EngineIsKeyEntry(
        /* [in] */ const _ELASTOS String& alias,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI EngineIsCertificateEntry(
        /* [in] */ const _ELASTOS String& alias,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI EngineGetCertificateAlias(
        /* [in] */ Elastos::Security::Cert::ICertificate * cert,
        /* [out] */ _ELASTOS String * alias) = 0;

    virtual CARAPI EngineStore(
        /* [in] */ Elastos::IO::IOutputStream * stream,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password) = 0;

    virtual CARAPI EngineStore(
        /* [in] */ Elastos::Security::IKeyStoreLoadStoreParameter * param) = 0;

    virtual CARAPI EngineLoad(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password) = 0;

    virtual CARAPI EngineLoad(
        /* [in] */ Elastos::Security::IKeyStoreLoadStoreParameter * param) = 0;

    virtual CARAPI EngineGetEntry(
        /* [in] */ const _ELASTOS String& alias,
        /* [in] */ Elastos::Security::IKeyStoreProtectionParameter * protParam,
        /* [out] */ Elastos::Security::IKeyStoreEntry ** entry) = 0;

    virtual CARAPI EngineSetEntry(
        /* [in] */ const _ELASTOS String& alias,
        /* [in] */ Elastos::Security::IKeyStoreEntry * entry,
        /* [in] */ Elastos::Security::IKeyStoreProtectionParameter * protParam) = 0;

    virtual CARAPI EngineEntryInstanceOf(
        /* [in] */ const _ELASTOS String& alias,
        /* [in] */ const _ELASTOS ClassID & entryClass,
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("ED63944B-8592-7C68-94A0-83FCC3414919")
IMessageDigest : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMessageDigest*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMessageDigest*)pObj->Probe(EIID_IMessageDigest);
    }

    static CARAPI_(IMessageDigest*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMessageDigest*)pObj->Probe(EIID_IMessageDigest);
    }

    virtual CARAPI Reset() = 0;

    virtual CARAPI Update(
        /* [in] */ _ELASTOS Byte arg0) = 0;

    virtual CARAPI Update(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * input,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 len) = 0;

    virtual CARAPI Update(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * input) = 0;

    virtual CARAPI Digest(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** hashValue) = 0;

    virtual CARAPI Digest(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 len,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Digest(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * input,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** hashValue) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetAlgorithm(
        /* [out] */ _ELASTOS String * algorithm) = 0;

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI GetDigestLength(
        /* [out] */ _ELASTOS Int32 * length) = 0;

    virtual CARAPI Update(
        /* [in] */ Elastos::IO::IByteBuffer * input) = 0;

    virtual CARAPI SetProvider(
        /* [in] */ Elastos::Security::IProvider * provider) = 0;

    virtual CARAPI SetAlgorithm(
        /* [in] */ const _ELASTOS String& algorithm) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("E0C04E43-8592-7C68-94A0-831C01C58BB0")
IMessageDigestHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMessageDigestHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMessageDigestHelper*)pObj->Probe(EIID_IMessageDigestHelper);
    }

    static CARAPI_(IMessageDigestHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMessageDigestHelper*)pObj->Probe(EIID_IMessageDigestHelper);
    }

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Security::IMessageDigest ** instance) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& provider,
        /* [out] */ Elastos::Security::IMessageDigest ** instance) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastos::Security::IMessageDigest ** instance) = 0;

    virtual CARAPI IsEqual(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * digesta,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * digestb,
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("321B7F41-8592-7C68-94A0-83CCA1EC0F07")
IMessageDigestSpi : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMessageDigestSpi*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMessageDigestSpi*)pObj->Probe(EIID_IMessageDigestSpi);
    }

    static CARAPI_(IMessageDigestSpi*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMessageDigestSpi*)pObj->Probe(EIID_IMessageDigestSpi);
    }

    virtual CARAPI EngineGetDigestLength(
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI EngineUpdate(
        /* [in] */ _ELASTOS Byte input) = 0;

    virtual CARAPI EngineUpdate(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * input,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 len) = 0;

    virtual CARAPI EngineUpdate(
        /* [in] */ Elastos::IO::IByteBuffer * input) = 0;

    virtual CARAPI EngineDigest(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** result) = 0;

    virtual CARAPI EngineDigest(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 len,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI EngineReset() = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("08E44C52-8652-3C67-6D2C-FEE1A0A40C1B")
IPermission : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPermission*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPermission*)pObj->Probe(EIID_IPermission);
    }

    static CARAPI_(IPermission*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPermission*)pObj->Probe(EIID_IPermission);
    }

    virtual CARAPI GetName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI NewPermissionCollection(
        /* [out] */ Elastos::Security::IPermissionCollection ** permissions) = 0;

    virtual CARAPI GetActions(
        /* [out] */ _ELASTOS String * actions) = 0;

    virtual CARAPI Implies(
        /* [in] */ Elastos::Security::IPermission * permission,
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("F4515144-8652-3C67-6D2C-2EE2F2D5C41F")
IPermissionCollection : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPermissionCollection*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPermissionCollection*)pObj->Probe(EIID_IPermissionCollection);
    }

    static CARAPI_(IPermissionCollection*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPermissionCollection*)pObj->Probe(EIID_IPermissionCollection);
    }

    virtual CARAPI Add(
        /* [in] */ Elastos::Security::IPermission * permission) = 0;

    virtual CARAPI GetElements(
        /* [out] */ Elastos::Utility::IEnumeration ** permissions) = 0;

    virtual CARAPI Implies(
        /* [in] */ Elastos::Security::IPermission * permission,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI IsReadOnly(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI SetReadOnly() = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("2F372323-D7D2-36AB-7EB4-B77143868D1F")
IPolicyParameters : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPolicyParameters*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPolicyParameters*)pObj->Probe(EIID_IPolicyParameters);
    }

    static CARAPI_(IPolicyParameters*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPolicyParameters*)pObj->Probe(EIID_IPolicyParameters);
    }

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("40E76425-D7D2-ED1F-6DDC-9061E3070714")
IPolicy : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPolicy*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPolicy*)pObj->Probe(EIID_IPolicy);
    }

    static CARAPI_(IPolicy*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPolicy*)pObj->Probe(EIID_IPolicy);
    }

    virtual CARAPI GetParameters(
        /* [out] */ Elastos::Security::IPolicyParameters ** parameters) = 0;

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI GetType(
        /* [out] */ _ELASTOS String * type) = 0;

    virtual CARAPI GetPermissions(
        /* [in] */ Elastos::Security::ICodeSource * cs,
        /* [out] */ Elastos::Security::IPermissionCollection ** permissions) = 0;

    virtual CARAPI Refresh() = 0;

    virtual CARAPI GetPermissionsEx(
        /* [in] */ Elastos::Security::IProtectionDomain * dom,
        /* [out] */ Elastos::Security::IPermissionCollection ** permissions) = 0;

    virtual CARAPI Implies(
        /* [in] */ Elastos::Security::IProtectionDomain * dom,
        /* [in] */ Elastos::Security::IPermission * permission,
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("C569572A-D7D2-2808-5ECC-B8FFA3BD8D1B")
IPolicyHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPolicyHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPolicyHelper*)pObj->Probe(EIID_IPolicyHelper);
    }

    static CARAPI_(IPolicyHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPolicyHelper*)pObj->Probe(EIID_IPolicyHelper);
    }

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ Elastos::Security::IPolicyParameters * params,
        /* [out] */ Elastos::Security::IPolicy ** instance) = 0;

    virtual CARAPI GetInstanceEx(
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ Elastos::Security::IPolicyParameters * params,
        /* [in] */ const _ELASTOS String& provider,
        /* [out] */ Elastos::Security::IPolicy ** instance) = 0;

    virtual CARAPI GetInstanceEx2(
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ Elastos::Security::IPolicyParameters * params,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastos::Security::IPolicy ** instance) = 0;

    virtual CARAPI GetPolicy(
        /* [out] */ Elastos::Security::IPolicy ** policy) = 0;

    virtual CARAPI SetPolicy(
        /* [in] */ Elastos::Security::IPolicy * policy) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("C1892656-0652-BFBD-53A2-3BA1E0D5C41F")
IPrivilegedAction : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPrivilegedAction*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPrivilegedAction*)pObj->Probe(EIID_IPrivilegedAction);
    }

    static CARAPI_(IPrivilegedAction*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPrivilegedAction*)pObj->Probe(EIID_IPrivilegedAction);
    }

    virtual CARAPI Run(
        /* [out] */ IInterface ** result) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("A6F12F59-0652-BFBD-53A2-3B1105545A05")
IPrivilegedExceptionAction : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPrivilegedExceptionAction*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPrivilegedExceptionAction*)pObj->Probe(EIID_IPrivilegedExceptionAction);
    }

    static CARAPI_(IPrivilegedExceptionAction*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPrivilegedExceptionAction*)pObj->Probe(EIID_IPrivilegedExceptionAction);
    }

    virtual CARAPI Run(
        /* [out] */ IInterface ** result) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("0D09602D-5A92-B5F9-7EB4-B77143868D1F")
IProtectionDomain : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IProtectionDomain*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IProtectionDomain*)pObj->Probe(EIID_IProtectionDomain);
    }

    static CARAPI_(IProtectionDomain*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IProtectionDomain*)pObj->Probe(EIID_IProtectionDomain);
    }

    virtual CARAPI GetClassLoader(
        /* [out] */ Elastos::Core::IClassLoader ** loader) = 0;

    virtual CARAPI GetCodeSource(
        /* [out] */ Elastos::Security::ICodeSource ** codeSource) = 0;

    virtual CARAPI GetPermissions(
        /* [out] */ Elastos::Security::IPermissionCollection ** permissions) = 0;

    virtual CARAPI GetPrincipals(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::IPrincipal *> ** principals) = 0;

    virtual CARAPI Implies(
        /* [in] */ Elastos::Security::IPermission * permission,
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("87014918-8712-789A-8D6E-647CCAF0EFBC")
ISecureRandom : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISecureRandom*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISecureRandom*)pObj->Probe(EIID_ISecureRandom);
    }

    static CARAPI_(ISecureRandom*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISecureRandom*)pObj->Probe(EIID_ISecureRandom);
    }

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI GetAlgorithm(
        /* [out] */ _ELASTOS String * algorithm) = 0;

    virtual CARAPI SetSeed(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * seed) = 0;

    virtual CARAPI GenerateSeed(
        /* [in] */ _ELASTOS Int32 numBytes,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** seed) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("D43D4D1B-8712-789A-8D6E-647CCA7084BE")
ISecureRandomHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISecureRandomHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISecureRandomHelper*)pObj->Probe(EIID_ISecureRandomHelper);
    }

    static CARAPI_(ISecureRandomHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISecureRandomHelper*)pObj->Probe(EIID_ISecureRandomHelper);
    }

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Security::ISecureRandom ** instance) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& provider,
        /* [out] */ Elastos::Security::ISecureRandom ** instance) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastos::Security::ISecureRandom ** instance) = 0;

    virtual CARAPI GetSeed(
        /* [in] */ _ELASTOS Int32 numBytes,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** seed) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("8E555013-8712-789A-8D6E-647CCA3037B3")
ISecureRandomSpi : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISecureRandomSpi*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISecureRandomSpi*)pObj->Probe(EIID_ISecureRandomSpi);
    }

    static CARAPI_(ISecureRandomSpi*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISecureRandomSpi*)pObj->Probe(EIID_ISecureRandomSpi);
    }

    virtual CARAPI EngineSetSeed(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * seed) = 0;

    virtual CARAPI EngineNextBytes(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * bytes) = 0;

    virtual CARAPI EngineGenerateSeed(
        /* [in] */ _ELASTOS Int32 numBytes,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** seed) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("DD7AAA4C-0712-B014-F4CA-FEE1A0A40C1B")
ISecurity : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISecurity*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISecurity*)pObj->Probe(EIID_ISecurity);
    }

    static CARAPI_(ISecurity*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISecurity*)pObj->Probe(EIID_ISecurity);
    }

    virtual CARAPI GetAlgorithmProperty(
        /* [in] */ const _ELASTOS String& algName,
        /* [in] */ const _ELASTOS String& propName,
        /* [out] */ _ELASTOS String * algProp) = 0;

    virtual CARAPI InsertProviderAt(
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ _ELASTOS Int32 position,
        /* [out] */ _ELASTOS Int32 * pos) = 0;

    virtual CARAPI AddProvider(
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ _ELASTOS Int32 * pos) = 0;

    virtual CARAPI RemoveProvider(
        /* [in] */ const _ELASTOS String& name) = 0;

    virtual CARAPI GetProviders(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::IProvider *> ** providers) = 0;

    virtual CARAPI GetProvider(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI GetProviders(
        /* [in] */ const _ELASTOS String& filter,
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::IProvider *> ** providers) = 0;

    virtual CARAPI GetProviders(
        /* [in] */ Elastos::Utility::IMap * filter,
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::IProvider *> ** providers) = 0;

    virtual CARAPI GetProperty(
        /* [in] */ const _ELASTOS String& key,
        /* [out] */ _ELASTOS String * prop) = 0;

    virtual CARAPI SetProperty(
        /* [in] */ const _ELASTOS String& key,
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI GetAlgorithms(
        /* [in] */ const _ELASTOS String& serviceName,
        /* [out] */ Elastos::Utility::ISet ** algs) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("FF0E1F0A-C712-31AA-79E3-35CACDECEFBC")
ISignatureSpi : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISignatureSpi*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISignatureSpi*)pObj->Probe(EIID_ISignatureSpi);
    }

    static CARAPI_(ISignatureSpi*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISignatureSpi*)pObj->Probe(EIID_ISignatureSpi);
    }

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("3F0AB45B-0712-2A16-8AC6-C6FBC3414919")
ISignature : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISignature*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISignature*)pObj->Probe(EIID_ISignature);
    }

    static CARAPI_(ISignature*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISignature*)pObj->Probe(EIID_ISignature);
    }

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::Security::IProvider ** provider) = 0;

    virtual CARAPI GetAlgorithm(
        /* [out] */ _ELASTOS String * algo) = 0;

    virtual CARAPI InitVerify(
        /* [in] */ Elastos::Security::IPublicKey * publicKey) = 0;

    virtual CARAPI InitVerify(
        /* [in] */ Elastos::Security::Cert::ICertificate * certificate) = 0;

    virtual CARAPI InitSign(
        /* [in] */ Elastos::Security::IPrivateKey * privateKey) = 0;

    virtual CARAPI InitSign(
        /* [in] */ Elastos::Security::IPrivateKey * privateKey,
        /* [in] */ Elastos::Security::ISecureRandom * random) = 0;

    virtual CARAPI Sign(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** sign) = 0;

    virtual CARAPI Sign(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * outbuf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 len,
        /* [out] */ _ELASTOS Int32 * num) = 0;

    virtual CARAPI Verify(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * signature,
        /* [out] */ _ELASTOS Boolean * isVerified) = 0;

    virtual CARAPI Verify(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * signature,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ _ELASTOS Boolean * isVerified) = 0;

    virtual CARAPI Update(
        /* [in] */ _ELASTOS Byte b) = 0;

    virtual CARAPI Update(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data) = 0;

    virtual CARAPI Update(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 off,
        /* [in] */ _ELASTOS Int32 len) = 0;

    virtual CARAPI Update(
        /* [in] */ Elastos::IO::IByteBuffer * data) = 0;

    virtual CARAPI SetParameter(
        /* [in] */ const _ELASTOS String& param,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI SetParameter(
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * params) = 0;

    virtual CARAPI GetParameters(
        /* [out] */ Elastos::Security::IAlgorithmParameters ** param) = 0;

    virtual CARAPI GetParameter(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** param) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("C00C430F-C712-31AA-79E3-351AA1EF8CD6")
ISignatureHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISignatureHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISignatureHelper*)pObj->Probe(EIID_ISignatureHelper);
    }

    static CARAPI_(ISignatureHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISignatureHelper*)pObj->Probe(EIID_ISignatureHelper);
    }

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Security::ISignature ** sign) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& provider,
        /* [out] */ Elastos::Security::ISignature ** sign) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastos::Security::ISignature ** sign) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("594D465E-0712-2A16-8E9E-F8F2C3414919")
ISignedObject : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISignedObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISignedObject*)pObj->Probe(EIID_ISignedObject);
    }

    static CARAPI_(ISignedObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISignedObject*)pObj->Probe(EIID_ISignedObject);
    }

    virtual CARAPI GetObject(
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI GetSignature(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** sign) = 0;

    virtual CARAPI GetAlgorithm(
        /* [out] */ _ELASTOS String * algo) = 0;

    virtual CARAPI Verify(
        /* [in] */ Elastos::Security::IPublicKey * verificationKey,
        /* [in] */ Elastos::Security::ISignature * verificationEngine,
        /* [out] */ _ELASTOS Boolean * isVerified) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("E5553814-C712-31AA-5AFF-CE4BDAB76CFF")
ISigner : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISigner*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISigner*)pObj->Probe(EIID_ISigner);
    }

    static CARAPI_(ISigner*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISigner*)pObj->Probe(EIID_ISigner);
    }

    virtual CARAPI GetPrivateKey(
        /* [out] */ Elastos::Security::IPrivateKey ** priKey) = 0;

    virtual CARAPI SetKeyPair(
        /* [in] */ Elastos::Security::IKeyPair * pair) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("6FFA6F4A-1D12-8FBC-5FF8-3E91E1194F1B")
IUnresolvedPermission : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IUnresolvedPermission*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IUnresolvedPermission*)pObj->Probe(EIID_IUnresolvedPermission);
    }

    static CARAPI_(IUnresolvedPermission*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IUnresolvedPermission*)pObj->Probe(EIID_IUnresolvedPermission);
    }

    virtual CARAPI GetUnresolvedName(
        /* [out] */ _ELASTOS String * unresolvedName) = 0;

    virtual CARAPI GetUnresolvedActions(
        /* [out] */ _ELASTOS String * unresolvedActions) = 0;

    virtual CARAPI GetUnresolvedType(
        /* [out] */ _ELASTOS String * unresolvedType) = 0;

    virtual CARAPI GetUnresolvedCerts(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> ** certs) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("ED9A922A-8312-350C-64E4-6071E27E663D")
ICProviderServiceClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICProviderServiceClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICProviderServiceClassObject*)pObj->Probe(EIID_ICProviderServiceClassObject);
    }

    static CARAPI_(ICProviderServiceClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICProviderServiceClassObject*)pObj->Probe(EIID_ICProviderServiceClassObject);
    }

    virtual CARAPI CreateObjectWithProviderTypeAlgorithmClassNameAliasesAttributes(
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& className,
        /* [in] */ Elastos::Utility::IList * aliases,
        /* [in] */ Elastos::Utility::IMap * attributes,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("C62E670E-C312-26A1-5EB3-37CFBCA46D63")
ICSecurityClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSecurityClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSecurityClassObject*)pObj->Probe(EIID_ICSecurityClassObject);
    }

    static CARAPI_(ICSecurityClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSecurityClassObject*)pObj->Probe(EIID_ICSecurityClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("85B26E06-C312-6AB1-4CDE-788D46E83BA3")
ICSignatureHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSignatureHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSignatureHelperClassObject*)pObj->Probe(EIID_ICSignatureHelperClassObject);
    }

    static CARAPI_(ICSignatureHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSignatureHelperClassObject*)pObj->Probe(EIID_ICSignatureHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("E4DE7233-8312-0D99-58A8-C07F23028A17")
ICMessageDigestHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICMessageDigestHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMessageDigestHelperClassObject*)pObj->Probe(EIID_ICMessageDigestHelperClassObject);
    }

    static CARAPI_(ICMessageDigestHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMessageDigestHelperClassObject*)pObj->Probe(EIID_ICMessageDigestHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("B8698A2C-8312-9121-18C8-887103C58E1B")
ICAccessControlContextClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAccessControlContextClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAccessControlContextClassObject*)pObj->Probe(EIID_ICAccessControlContextClassObject);
    }

    static CARAPI_(ICAccessControlContextClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAccessControlContextClassObject*)pObj->Probe(EIID_ICAccessControlContextClassObject);
    }

    virtual CARAPI CreateObjectWithAccCombiner(
        /* [in] */ Elastos::Security::IAccessControlContext * acc,
        /* [in] */ Elastos::Security::IDomainCombiner * combiner,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithContext(
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::IProtectionDomain *> * context,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("15BE6F38-8312-9121-5EDC-D763F4477B1B")
ICAccessControllerClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAccessControllerClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAccessControllerClassObject*)pObj->Probe(EIID_ICAccessControllerClassObject);
    }

    static CARAPI_(ICAccessControllerClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAccessControllerClassObject*)pObj->Probe(EIID_ICAccessControllerClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("7FAB7828-0312-2F05-54E4-677163058CAB")
ICAlgorithmParametersHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAlgorithmParametersHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAlgorithmParametersHelperClassObject*)pObj->Probe(EIID_ICAlgorithmParametersHelperClassObject);
    }

    static CARAPI_(ICAlgorithmParametersHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAlgorithmParametersHelperClassObject*)pObj->Probe(EIID_ICAlgorithmParametersHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("A0E28B2C-0312-2F05-54E4-677163058CAB")
ICAlgorithmParameterGeneratorClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAlgorithmParameterGeneratorClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAlgorithmParameterGeneratorClassObject*)pObj->Probe(EIID_ICAlgorithmParameterGeneratorClassObject);
    }

    static CARAPI_(ICAlgorithmParameterGeneratorClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAlgorithmParameterGeneratorClassObject*)pObj->Probe(EIID_ICAlgorithmParameterGeneratorClassObject);
    }

    virtual CARAPI CreateObjectWithParamGenSpiProviderAlgorithm(
        /* [in] */ Elastos::Security::IAlgorithmParameterGeneratorSpi * paramGenSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("5E7FD613-C312-26A1-5EA3-1B199F32CCBC")
ICSecureRandomClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSecureRandomClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSecureRandomClassObject*)pObj->Probe(EIID_ICSecureRandomClassObject);
    }

    static CARAPI_(ICSecureRandomClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSecureRandomClassObject*)pObj->Probe(EIID_ICSecureRandomClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithSeed(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * seed,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithSecureRandomSpiProviderAlgorithm(
        /* [in] */ Elastos::Security::ISecureRandomSpi * secureRandomSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithSecureRandomSpiProvider(
        /* [in] */ Elastos::Security::ISecureRandomSpi * secureRandomSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("C858711B-C312-26A1-5EA3-1B199F321CA1")
ICSecureRandomHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSecureRandomHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSecureRandomHelperClassObject*)pObj->Probe(EIID_ICSecureRandomHelperClassObject);
    }

    static CARAPI_(ICSecureRandomHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSecureRandomHelperClassObject*)pObj->Probe(EIID_ICSecureRandomHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("B9AB873B-8312-1925-EEC3-606123BE1EA3")
ICAllPermissionClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAllPermissionClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAllPermissionClassObject*)pObj->Probe(EIID_ICAllPermissionClassObject);
    }

    static CARAPI_(ICAllPermissionClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAllPermissionClassObject*)pObj->Probe(EIID_ICAllPermissionClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithNameActions(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("4E8D902F-0312-1C40-58A8-88715F8FD11F")
ICCodeSignerClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCodeSignerClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCodeSignerClassObject*)pObj->Probe(EIID_ICCodeSignerClassObject);
    }

    static CARAPI_(ICCodeSignerClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCodeSignerClassObject*)pObj->Probe(EIID_ICCodeSignerClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithSignerCertPathTimestamp(
        /* [in] */ Elastos::Security::Cert::ICertPath * signerCertPath,
        /* [in] */ Elastos::Security::ITimestamp * timestamp,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("BB5F8A3F-0312-A640-F518-FDD1DEC60D19")
ICCodeSourceClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCodeSourceClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCodeSourceClassObject*)pObj->Probe(EIID_ICCodeSourceClassObject);
    }

    static CARAPI_(ICCodeSourceClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCodeSourceClassObject*)pObj->Probe(EIID_ICCodeSourceClassObject);
    }

    virtual CARAPI CreateObjectWithLocationCerts(
        /* [in] */ Elastos::Net::IURL * location,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::ICertificate *> * certs,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithLocationSigners(
        /* [in] */ Elastos::Net::IURL * location,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::ICodeSigner *> * signers,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("9D60715E-0312-E825-206F-59CB46180C06")
ICDigestInputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDigestInputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDigestInputStreamClassObject*)pObj->Probe(EIID_ICDigestInputStreamClassObject);
    }

    static CARAPI_(ICDigestInputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDigestInputStreamClassObject*)pObj->Probe(EIID_ICDigestInputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithStreamDigest(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [in] */ Elastos::Security::IMessageDigest * digest,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("9F4C7135-8312-2C06-54E0-BF2155360A12")
ICDigestOutputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDigestOutputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDigestOutputStreamClassObject*)pObj->Probe(EIID_ICDigestOutputStreamClassObject);
    }

    static CARAPI_(ICDigestOutputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDigestOutputStreamClassObject*)pObj->Probe(EIID_ICDigestOutputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("B6946C23-0312-3808-48D4-38A1DFA81EA3")
ICGuardedObjectClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICGuardedObjectClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICGuardedObjectClassObject*)pObj->Probe(EIID_ICGuardedObjectClassObject);
    }

    static CARAPI_(ICGuardedObjectClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICGuardedObjectClassObject*)pObj->Probe(EIID_ICGuardedObjectClassObject);
    }

    virtual CARAPI CreateObjectWithObjectGuard(
        /* [in] */ IInterface * object,
        /* [in] */ Elastos::Security::IGuard * guard,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("85CB7826-8312-D086-F418-FDD1DEC60D19")
ICKeyFactoryClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICKeyFactoryClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyFactoryClassObject*)pObj->Probe(EIID_ICKeyFactoryClassObject);
    }

    static CARAPI_(ICKeyFactoryClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyFactoryClassObject*)pObj->Probe(EIID_ICKeyFactoryClassObject);
    }

    virtual CARAPI CreateObjectWithKeyFacSpiProviderAlgorithm(
        /* [in] */ Elastos::Security::IKeyFactorySpi * keyFacSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("43A56F34-8312-D086-22A0-7831E3BE1EA3")
ICKeyFactoryHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICKeyFactoryHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyFactoryHelperClassObject*)pObj->Probe(EIID_ICKeyFactoryHelperClassObject);
    }

    static CARAPI_(ICKeyFactoryHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyFactoryHelperClassObject*)pObj->Probe(EIID_ICKeyFactoryHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("94D16E33-8312-1986-48B0-A8A1C7E88FF6")
ICKeyPairClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICKeyPairClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyPairClassObject*)pObj->Probe(EIID_ICKeyPairClassObject);
    }

    static CARAPI_(ICKeyPairClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyPairClassObject*)pObj->Probe(EIID_ICKeyPairClassObject);
    }

    virtual CARAPI CreateObjectWithPublicKeyPrivateKey(
        /* [in] */ Elastos::Security::IPublicKey * publicKey,
        /* [in] */ Elastos::Security::IPrivateKey * privateKey,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("0D7E7516-4312-7CA1-46B2-3584C6684DDE")
ICKeyPairGeneratorHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICKeyPairGeneratorHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyPairGeneratorHelperClassObject*)pObj->Probe(EIID_ICKeyPairGeneratorHelperClassObject);
    }

    static CARAPI_(ICKeyPairGeneratorHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyPairGeneratorHelperClassObject*)pObj->Probe(EIID_ICKeyPairGeneratorHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("4FA1743C-8312-1B86-50CC-D063F4477B1B")
ICKeyRepClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICKeyRepClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyRepClassObject*)pObj->Probe(EIID_ICKeyRepClassObject);
    }

    static CARAPI_(ICKeyRepClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyRepClassObject*)pObj->Probe(EIID_ICKeyRepClassObject);
    }

    virtual CARAPI CreateObjectWithTypeAlgorithmFormatEncoded(
        /* [in] */ Elastos::Security::KeyRepType type,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& format,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encoded,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("AE066D22-8312-AF86-23A0-7831E3BE1EA3")
ICKeyStoreHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICKeyStoreHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyStoreHelperClassObject*)pObj->Probe(EIID_ICKeyStoreHelperClassObject);
    }

    static CARAPI_(ICKeyStoreHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyStoreHelperClassObject*)pObj->Probe(EIID_ICKeyStoreHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("C0AE7A3B-8312-AF86-33D4-609183C40D14")
ICKeyStorePrivateKeyEntryClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICKeyStorePrivateKeyEntryClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyStorePrivateKeyEntryClassObject*)pObj->Probe(EIID_ICKeyStorePrivateKeyEntryClassObject);
    }

    static CARAPI_(ICKeyStorePrivateKeyEntryClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyStorePrivateKeyEntryClassObject*)pObj->Probe(EIID_ICKeyStorePrivateKeyEntryClassObject);
    }

    virtual CARAPI CreateObjectWithPrivateKeyChain(
        /* [in] */ Elastos::Security::IPrivateKey * privateKey,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> * chain,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("AB93733B-8312-AF86-39A0-305103C58D86")
ICKeyStoreSecretKeyEntryClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICKeyStoreSecretKeyEntryClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyStoreSecretKeyEntryClassObject*)pObj->Probe(EIID_ICKeyStoreSecretKeyEntryClassObject);
    }

    static CARAPI_(ICKeyStoreSecretKeyEntryClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyStoreSecretKeyEntryClassObject*)pObj->Probe(EIID_ICKeyStoreSecretKeyEntryClassObject);
    }

    virtual CARAPI CreateObjectWithSecretKey(
        /* [in] */ Elastosx::Crypto::ISecretKey * secretKey,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("374C8336-8312-AF86-3BD4-C061E3867E06")
ICKeyStoreTrustedCertificateEntryClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICKeyStoreTrustedCertificateEntryClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyStoreTrustedCertificateEntryClassObject*)pObj->Probe(EIID_ICKeyStoreTrustedCertificateEntryClassObject);
    }

    static CARAPI_(ICKeyStoreTrustedCertificateEntryClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKeyStoreTrustedCertificateEntryClassObject*)pObj->Probe(EIID_ICKeyStoreTrustedCertificateEntryClassObject);
    }

    virtual CARAPI CreateObjectWithTrustCertificate(
        /* [in] */ Elastos::Security::Cert::ICertificate * trustCertificate,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("406F6A36-8312-F70C-61B0-B011DF861EA3")
ICPermissionsClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPermissionsClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPermissionsClassObject*)pObj->Probe(EIID_ICPermissionsClassObject);
    }

    static CARAPI_(ICPermissionsClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPermissionsClassObject*)pObj->Probe(EIID_ICPermissionsClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("84A56E35-8312-F70C-61B0-B011DF063A3D")
ICPermissionsHashClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPermissionsHashClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPermissionsHashClassObject*)pObj->Probe(EIID_ICPermissionsHashClassObject);
    }

    static CARAPI_(ICPermissionsHashClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPermissionsHashClassObject*)pObj->Probe(EIID_ICPermissionsHashClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("9EBD7C51-0312-783A-1FBF-F07D22C3339E")
ICUnresolvedPermissionClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICUnresolvedPermissionClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICUnresolvedPermissionClassObject*)pObj->Probe(EIID_ICUnresolvedPermissionClassObject);
    }

    static CARAPI_(ICUnresolvedPermissionClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICUnresolvedPermissionClassObject*)pObj->Probe(EIID_ICUnresolvedPermissionClassObject);
    }

    virtual CARAPI CreateObjectWithTypeNameActionsCerts(
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> * certs,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("48717435-0312-37E2-48C0-98A1C7E88FF6")
ICTimestampClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICTimestampClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTimestampClassObject*)pObj->Probe(EIID_ICTimestampClassObject);
    }

    static CARAPI_(ICTimestampClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTimestampClassObject*)pObj->Probe(EIID_ICTimestampClassObject);
    }

    virtual CARAPI CreateObjectWithTimestampSignerCertPath(
        /* [in] */ Elastos::Utility::IDate * timestamp,
        /* [in] */ Elastos::Security::Cert::ICertPath * signerCertPath,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
CAR_INTERFACE("AFCC7D31-0312-2C0E-54C4-D06F548FD11F")
ICSignedObjectClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSignedObjectClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSignedObjectClassObject*)pObj->Probe(EIID_ICSignedObjectClassObject);
    }

    static CARAPI_(ICSignedObjectClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSignedObjectClassObject*)pObj->Probe(EIID_ICSignedObjectClassObject);
    }

    virtual CARAPI CreateObjectWithObjectSigningKeySigningEngine(
        /* [in] */ Elastos::IO::ISerializable * object,
        /* [in] */ Elastos::Security::IPrivateKey * signingKey,
        /* [in] */ Elastos::Security::ISignature * signingEngine,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("CF1E7C5B-0312-CF06-3E77-EBA4F9018957")
ICCertificateFactoryHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCertificateFactoryHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCertificateFactoryHelperClassObject*)pObj->Probe(EIID_ICCertificateFactoryHelperClassObject);
    }

    static CARAPI_(ICCertificateFactoryHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCertificateFactoryHelperClassObject*)pObj->Probe(EIID_ICCertificateFactoryHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("16589B54-8312-2E22-5F4D-64F0EC0687D3")
ICCollectionCertStoreParametersClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCollectionCertStoreParametersClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCollectionCertStoreParametersClassObject*)pObj->Probe(EIID_ICCollectionCertStoreParametersClassObject);
    }

    static CARAPI_(ICCollectionCertStoreParametersClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCollectionCertStoreParametersClassObject*)pObj->Probe(EIID_ICCollectionCertStoreParametersClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCollection(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("EA95B337-8312-0D0A-1464-6070FFC6EBAB")
ICLDAPCertStoreParametersClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICLDAPCertStoreParametersClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLDAPCertStoreParametersClassObject*)pObj->Probe(EIID_ICLDAPCertStoreParametersClassObject);
    }

    static CARAPI_(ICLDAPCertStoreParametersClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLDAPCertStoreParametersClassObject*)pObj->Probe(EIID_ICLDAPCertStoreParametersClassObject);
    }

    virtual CARAPI CreateObjectWithServerNamePort(
        /* [in] */ const _ELASTOS String& serverName,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithServerName(
        /* [in] */ const _ELASTOS String& serverName,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("DD96A63F-8312-140C-2484-B86A438FD11F")
ICPKIXParametersClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPKIXParametersClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPKIXParametersClassObject*)pObj->Probe(EIID_ICPKIXParametersClassObject);
    }

    static CARAPI_(ICPKIXParametersClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPKIXParametersClassObject*)pObj->Probe(EIID_ICPKIXParametersClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithTrustAnchors(
        /* [in] */ Elastos::Utility::ISet * trustAnchors,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithKeyStore(
        /* [in] */ Elastos::Security::IKeyStore * keyStore,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("F4A9CF3C-8312-140C-2484-6073FFAA0D3D")
ICPKIXBuilderParametersClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPKIXBuilderParametersClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPKIXBuilderParametersClassObject*)pObj->Probe(EIID_ICPKIXBuilderParametersClassObject);
    }

    static CARAPI_(ICPKIXBuilderParametersClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPKIXBuilderParametersClassObject*)pObj->Probe(EIID_ICPKIXBuilderParametersClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithTrustAnchorsTargetConstraints(
        /* [in] */ Elastos::Utility::ISet * trustAnchors,
        /* [in] */ Elastos::Security::Cert::ICertSelector * targetConstraints,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithKeyStoreTargetConstraints(
        /* [in] */ Elastos::Security::IKeyStore * keyStore,
        /* [in] */ Elastos::Security::Cert::ICertSelector * targetConstraints,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("D555E305-D312-B8D5-7D2B-B1B9CA35F392")
ICTrustAnchorClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICTrustAnchorClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTrustAnchorClassObject*)pObj->Probe(EIID_ICTrustAnchorClassObject);
    }

    static CARAPI_(ICTrustAnchorClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTrustAnchorClassObject*)pObj->Probe(EIID_ICTrustAnchorClassObject);
    }

    virtual CARAPI CreateObjectWithTrustedCertNameConstraints(
        /* [in] */ Elastos::Security::Cert::IX509Certificate * trustedCert,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * nameConstraints,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCaNameCaPublicKeyNameConstraints(
        /* [in] */ const _ELASTOS String& caName,
        /* [in] */ Elastos::Security::IPublicKey * caPublicKey,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * nameConstraints,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCaPrincipalCaPublicKeyNameConstraints(
        /* [in] */ Elastosx::Security::Auth::X500::IX500Principal * caPrincipal,
        /* [in] */ Elastos::Security::IPublicKey * caPublicKey,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * nameConstraints,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("CD7D9F2B-8312-140C-2484-6070FF465636")
ICPKIXCertPathBuilderResultClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPKIXCertPathBuilderResultClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPKIXCertPathBuilderResultClassObject*)pObj->Probe(EIID_ICPKIXCertPathBuilderResultClassObject);
    }

    static CARAPI_(ICPKIXCertPathBuilderResultClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPKIXCertPathBuilderResultClassObject*)pObj->Probe(EIID_ICPKIXCertPathBuilderResultClassObject);
    }

    virtual CARAPI CreateObjectWithCertPathTrustAnchorPolicyTreeSubjectPublicKey(
        /* [in] */ Elastos::Security::Cert::ICertPath * certPath,
        /* [in] */ Elastos::Security::Cert::ITrustAnchor * trustAnchor,
        /* [in] */ Elastos::Security::Cert::IPolicyNode * policyTree,
        /* [in] */ Elastos::Security::IPublicKey * subjectPublicKey,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("F395992D-8312-140C-2484-6070FF4656EF")
ICPKIXCertPathValidatorResultClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPKIXCertPathValidatorResultClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPKIXCertPathValidatorResultClassObject*)pObj->Probe(EIID_ICPKIXCertPathValidatorResultClassObject);
    }

    static CARAPI_(ICPKIXCertPathValidatorResultClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPKIXCertPathValidatorResultClassObject*)pObj->Probe(EIID_ICPKIXCertPathValidatorResultClassObject);
    }

    virtual CARAPI CreateObjectWithTrustAnchorPolicyTreeSubjectPublicKey(
        /* [in] */ Elastos::Security::Cert::ITrustAnchor * trustAnchor,
        /* [in] */ Elastos::Security::Cert::IPolicyNode * policyTree,
        /* [in] */ Elastos::Security::IPublicKey * subjectPublicKey,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("BCDC732D-8312-1AAF-7090-78C122058BFB")
ICPolicyQualifierInfoClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPolicyQualifierInfoClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPolicyQualifierInfoClassObject*)pObj->Probe(EIID_ICPolicyQualifierInfoClassObject);
    }

    static CARAPI_(ICPolicyQualifierInfoClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPolicyQualifierInfoClassObject*)pObj->Probe(EIID_ICPolicyQualifierInfoClassObject);
    }

    virtual CARAPI CreateObjectWithEncoded(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encoded,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("0F66733E-8312-0510-0024-60B0A182E5FC")
ICX509CRLSelectorClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICX509CRLSelectorClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICX509CRLSelectorClassObject*)pObj->Probe(EIID_ICX509CRLSelectorClassObject);
    }

    static CARAPI_(ICX509CRLSelectorClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICX509CRLSelectorClassObject*)pObj->Probe(EIID_ICX509CRLSelectorClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
CAR_INTERFACE("C7FF7427-8312-0510-0024-6070FF86E5FC")
ICX509CertSelectorClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICX509CertSelectorClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICX509CertSelectorClassObject*)pObj->Probe(EIID_ICX509CertSelectorClassObject);
    }

    static CARAPI_(ICX509CertSelectorClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICX509CertSelectorClassObject*)pObj->Probe(EIID_ICX509CertSelectorClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("15EE6C29-8312-1C06-145C-E5300385093D")
ICDSAParameterSpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDSAParameterSpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDSAParameterSpecClassObject*)pObj->Probe(EIID_ICDSAParameterSpecClassObject);
    }

    static CARAPI_(ICDSAParameterSpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDSAParameterSpecClassObject*)pObj->Probe(EIID_ICDSAParameterSpecClassObject);
    }

    virtual CARAPI CreateObjectWithPQG(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * q,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("17316E0B-D312-4A70-56B3-3979A314CA73")
ICDSAPrivateKeySpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDSAPrivateKeySpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDSAPrivateKeySpecClassObject*)pObj->Probe(EIID_ICDSAPrivateKeySpecClassObject);
    }

    static CARAPI_(ICDSAPrivateKeySpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDSAPrivateKeySpecClassObject*)pObj->Probe(EIID_ICDSAPrivateKeySpecClassObject);
    }

    virtual CARAPI CreateObjectWithXPQG(
        /* [in] */ Elastos::Math::IBigInteger * x,
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * q,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("368D6D1D-D312-4A70-8697-2F6B5228CFCD")
ICDSAPublicKeySpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDSAPublicKeySpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDSAPublicKeySpecClassObject*)pObj->Probe(EIID_ICDSAPublicKeySpecClassObject);
    }

    static CARAPI_(ICDSAPublicKeySpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDSAPublicKeySpecClassObject*)pObj->Probe(EIID_ICDSAPublicKeySpecClassObject);
    }

    virtual CARAPI CreateObjectWithYPQG(
        /* [in] */ Elastos::Math::IBigInteger * y,
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * q,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("821C8A1D-E312-0F30-8BBE-E723C0CC4BDA")
ICECFieldF2mClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICECFieldF2mClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICECFieldF2mClassObject*)pObj->Probe(EIID_ICECFieldF2mClassObject);
    }

    static CARAPI_(ICECFieldF2mClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICECFieldF2mClassObject*)pObj->Probe(EIID_ICECFieldF2mClassObject);
    }

    virtual CARAPI CreateObjectWithM(
        /* [in] */ _ELASTOS Int32 m,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithMRp(
        /* [in] */ _ELASTOS Int32 m,
        /* [in] */ Elastos::Math::IBigInteger * rp,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithMKs(
        /* [in] */ _ELASTOS Int32 m,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * ks,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("344D631F-E312-0F30-8BBE-E733332F69DB")
ICECFieldFpClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICECFieldFpClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICECFieldFpClassObject*)pObj->Probe(EIID_ICECFieldFpClassObject);
    }

    static CARAPI_(ICECFieldFpClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICECFieldFpClassObject*)pObj->Probe(EIID_ICECFieldFpClassObject);
    }

    virtual CARAPI CreateObjectWithP(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("7C236F2B-0312-0C07-20A0-887195C30C14")
ICECGenParameterSpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICECGenParameterSpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICECGenParameterSpecClassObject*)pObj->Probe(EIID_ICECGenParameterSpecClassObject);
    }

    static CARAPI_(ICECGenParameterSpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICECGenParameterSpecClassObject*)pObj->Probe(EIID_ICECGenParameterSpecClassObject);
    }

    virtual CARAPI CreateObjectWithName(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("C5938332-0312-0C07-AE72-9881C2841EA3")
ICECParameterSpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICECParameterSpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICECParameterSpecClassObject*)pObj->Probe(EIID_ICECParameterSpecClassObject);
    }

    static CARAPI_(ICECParameterSpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICECParameterSpecClassObject*)pObj->Probe(EIID_ICECParameterSpecClassObject);
    }

    virtual CARAPI CreateObjectWithCurveGeneratorOrderCofactor(
        /* [in] */ Elastos::Security::Spec::IEllipticCurve * curve,
        /* [in] */ Elastos::Security::Spec::IECPoint * generator,
        /* [in] */ Elastos::Math::IBigInteger * order,
        /* [in] */ _ELASTOS Int32 cofactor,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("5C0F8933-0312-0C07-BCEA-31FAA3BD8D1B")
ICECPointClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICECPointClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICECPointClassObject*)pObj->Probe(EIID_ICECPointClassObject);
    }

    static CARAPI_(ICECPointClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICECPointClassObject*)pObj->Probe(EIID_ICECPointClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithAffineXAffineY(
        /* [in] */ Elastos::Math::IBigInteger * affineX,
        /* [in] */ Elastos::Math::IBigInteger * affineY,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("3BE47003-E312-5930-CDE6-E48D5228CFCD")
ICECPrivateKeySpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICECPrivateKeySpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICECPrivateKeySpecClassObject*)pObj->Probe(EIID_ICECPrivateKeySpecClassObject);
    }

    static CARAPI_(ICECPrivateKeySpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICECPrivateKeySpecClassObject*)pObj->Probe(EIID_ICECPrivateKeySpecClassObject);
    }

    virtual CARAPI CreateObjectWithSParams(
        /* [in] */ Elastos::Math::IBigInteger * s,
        /* [in] */ Elastos::Security::Spec::IECParameterSpec * params,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("AFE86F1F-E312-1930-5EBE-AC49A13C37A3")
ICECPublicKeySpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICECPublicKeySpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICECPublicKeySpecClassObject*)pObj->Probe(EIID_ICECPublicKeySpecClassObject);
    }

    static CARAPI_(ICECPublicKeySpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICECPublicKeySpecClassObject*)pObj->Probe(EIID_ICECPublicKeySpecClassObject);
    }

    virtual CARAPI CreateObjectWithWParams(
        /* [in] */ Elastos::Security::Spec::IECPoint * w,
        /* [in] */ Elastos::Security::Spec::IECParameterSpec * params,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("9F748808-E312-2FBC-3BDF-ACC9E0758E32")
ICEllipticCurveClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICEllipticCurveClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICEllipticCurveClassObject*)pObj->Probe(EIID_ICEllipticCurveClassObject);
    }

    static CARAPI_(ICEllipticCurveClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICEllipticCurveClassObject*)pObj->Probe(EIID_ICEllipticCurveClassObject);
    }

    virtual CARAPI CreateObjectWithFieldABSeed(
        /* [in] */ Elastos::Security::Spec::IECField * field,
        /* [in] */ Elastos::Math::IBigInteger * a,
        /* [in] */ Elastos::Math::IBigInteger * b,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * seed,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFieldAB(
        /* [in] */ Elastos::Security::Spec::IECField * field,
        /* [in] */ Elastos::Math::IBigInteger * a,
        /* [in] */ Elastos::Math::IBigInteger * b,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("EA9A7030-0312-100B-1E04-B8CA61060A13")
ICMGF1ParameterSpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICMGF1ParameterSpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMGF1ParameterSpecClassObject*)pObj->Probe(EIID_ICMGF1ParameterSpecClassObject);
    }

    static CARAPI_(ICMGF1ParameterSpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMGF1ParameterSpecClassObject*)pObj->Probe(EIID_ICMGF1ParameterSpecClassObject);
    }

    virtual CARAPI CreateObjectWithMdName(
        /* [in] */ const _ELASTOS String& mdName,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("AD947632-8312-140C-1870-4000EC44430E")
ICPKCS8EncodedKeySpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPKCS8EncodedKeySpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPKCS8EncodedKeySpecClassObject*)pObj->Probe(EIID_ICPKCS8EncodedKeySpecClassObject);
    }

    static CARAPI_(ICPKCS8EncodedKeySpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPKCS8EncodedKeySpecClassObject*)pObj->Probe(EIID_ICPKCS8EncodedKeySpecClassObject);
    }

    virtual CARAPI CreateObjectWithEncodedKey(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encodedKey,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("E6F9A73E-8312-1C0C-385C-E5300385093D")
ICPSSParameterSpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPSSParameterSpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPSSParameterSpecClassObject*)pObj->Probe(EIID_ICPSSParameterSpecClassObject);
    }

    static CARAPI_(ICPSSParameterSpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPSSParameterSpecClassObject*)pObj->Probe(EIID_ICPSSParameterSpecClassObject);
    }

    virtual CARAPI CreateObjectWithSaltLen(
        /* [in] */ _ELASTOS Int32 saltLen,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithMdNameMgfNameMgfSpecSaltLenTrailerField(
        /* [in] */ const _ELASTOS String& mdName,
        /* [in] */ const _ELASTOS String& mgfName,
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * mgfSpec,
        /* [in] */ _ELASTOS Int32 saltLen,
        /* [in] */ _ELASTOS Int32 trailerField,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("3AC28421-8312-1C0D-1434-848022C6550E")
ICRSAKeyGenParameterSpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICRSAKeyGenParameterSpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRSAKeyGenParameterSpecClassObject*)pObj->Probe(EIID_ICRSAKeyGenParameterSpecClassObject);
    }

    static CARAPI_(ICRSAKeyGenParameterSpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRSAKeyGenParameterSpecClassObject*)pObj->Probe(EIID_ICRSAKeyGenParameterSpecClassObject);
    }

    virtual CARAPI CreateObjectWithKeysizePublicExponent(
        /* [in] */ _ELASTOS Int32 keysize,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("2B40DF0F-B312-8A71-85BF-379BD52C8C66")
ICRSAMultiPrimePrivateCrtKeySpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICRSAMultiPrimePrivateCrtKeySpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRSAMultiPrimePrivateCrtKeySpecClassObject*)pObj->Probe(EIID_ICRSAMultiPrimePrivateCrtKeySpecClassObject);
    }

    static CARAPI_(ICRSAMultiPrimePrivateCrtKeySpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRSAMultiPrimePrivateCrtKeySpecClassObject*)pObj->Probe(EIID_ICRSAMultiPrimePrivateCrtKeySpecClassObject);
    }

    virtual CARAPI CreateObjectWithModulusPublicExponentPrivateExponentPrimePPrimeQPrimeExponentPPrimeExponentQCrtCoefficientOtherPrimeInfo(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [in] */ Elastos::Math::IBigInteger * privateExponent,
        /* [in] */ Elastos::Math::IBigInteger * primeP,
        /* [in] */ Elastos::Math::IBigInteger * primeQ,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentP,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentQ,
        /* [in] */ Elastos::Math::IBigInteger * crtCoefficient,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Spec::IRSAOtherPrimeInfo *> * otherPrimeInfo,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("455A8A16-B312-0A71-76AF-689DD52C8C4A")
ICRSAOtherPrimeInfoClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICRSAOtherPrimeInfoClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRSAOtherPrimeInfoClassObject*)pObj->Probe(EIID_ICRSAOtherPrimeInfoClassObject);
    }

    static CARAPI_(ICRSAOtherPrimeInfoClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRSAOtherPrimeInfoClassObject*)pObj->Probe(EIID_ICRSAOtherPrimeInfoClassObject);
    }

    virtual CARAPI CreateObjectWithPrimePrimeExponentCrtCoefficient(
        /* [in] */ Elastos::Math::IBigInteger * prime,
        /* [in] */ Elastos::Math::IBigInteger * primeExponent,
        /* [in] */ Elastos::Math::IBigInteger * crtCoefficient,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("0503C71F-B312-4A71-56B3-3979A34C7D53")
ICRSAPrivateCrtKeySpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICRSAPrivateCrtKeySpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRSAPrivateCrtKeySpecClassObject*)pObj->Probe(EIID_ICRSAPrivateCrtKeySpecClassObject);
    }

    static CARAPI_(ICRSAPrivateCrtKeySpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRSAPrivateCrtKeySpecClassObject*)pObj->Probe(EIID_ICRSAPrivateCrtKeySpecClassObject);
    }

    virtual CARAPI CreateObjectWithModulusPublicExponentPrivateExponentPrimePPrimeQPrimeExponentPPrimeExponentQCrtCoefficient(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [in] */ Elastos::Math::IBigInteger * privateExponent,
        /* [in] */ Elastos::Math::IBigInteger * primeP,
        /* [in] */ Elastos::Math::IBigInteger * primeQ,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentP,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentQ,
        /* [in] */ Elastos::Math::IBigInteger * crtCoefficient,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("3F1E8005-B312-4A71-56B3-3979A314CA73")
ICRSAPrivateKeySpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICRSAPrivateKeySpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRSAPrivateKeySpecClassObject*)pObj->Probe(EIID_ICRSAPrivateKeySpecClassObject);
    }

    static CARAPI_(ICRSAPrivateKeySpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRSAPrivateKeySpecClassObject*)pObj->Probe(EIID_ICRSAPrivateKeySpecClassObject);
    }

    virtual CARAPI CreateObjectWithModulusPrivateExponent(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * privateExponent,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("93C27E0F-B312-4A71-8697-2F6B5228CFCD")
ICRSAPublicKeySpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICRSAPublicKeySpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRSAPublicKeySpecClassObject*)pObj->Probe(EIID_ICRSAPublicKeySpecClassObject);
    }

    static CARAPI_(ICRSAPublicKeySpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRSAPublicKeySpecClassObject*)pObj->Probe(EIID_ICRSAPublicKeySpecClassObject);
    }

    virtual CARAPI CreateObjectWithModulusPublicExponent(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
CAR_INTERFACE("84317523-8312-0510-0024-0076A2218719")
ICX509EncodedKeySpecClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICX509EncodedKeySpecClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICX509EncodedKeySpecClassObject*)pObj->Probe(EIID_ICX509EncodedKeySpecClassObject);
    }

    static CARAPI_(ICX509EncodedKeySpecClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICX509EncodedKeySpecClassObject*)pObj->Probe(EIID_ICX509EncodedKeySpecClassObject);
    }

    virtual CARAPI CreateObjectWithEncodedKey(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encodedKey,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Security {
class CProviderService
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& className,
        /* [in] */ Elastos::Utility::IList * aliases,
        /* [in] */ Elastos::Utility::IMap * attributes,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICProviderServiceClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CProviderService, RGM_SAME_DOMAIN,
                EIID_ICProviderServiceClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithProviderTypeAlgorithmClassNameAliasesAttributes(provider, type, algorithm, className, aliases, attributes, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& className,
        /* [in] */ Elastos::Utility::IList * aliases,
        /* [in] */ Elastos::Utility::IMap * attributes,
        /* [out] */ Elastos::Security::IProviderService** __IProviderService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(provider, type, algorithm, className, aliases, attributes, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IProviderService = (Elastos::Security::IProviderService*)__pNewObj->Probe(Elastos::Security::EIID_IProviderService);
        if (*__IProviderService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& className,
        /* [in] */ Elastos::Utility::IList * aliases,
        /* [in] */ Elastos::Utility::IMap * attributes,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(provider, type, algorithm, className, aliases, attributes, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& className,
        /* [in] */ Elastos::Utility::IList * aliases,
        /* [in] */ Elastos::Utility::IMap * attributes,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(provider, type, algorithm, className, aliases, attributes, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& className,
        /* [in] */ Elastos::Utility::IList * aliases,
        /* [in] */ Elastos::Utility::IMap * attributes,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(provider, type, algorithm, className, aliases, attributes, &__pNewObj);
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
namespace Elastos {
namespace Security {
class CSecurity
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Security::ISecurity** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSecurity, RGM_SAME_DOMAIN, Elastos::Security::EIID_ISecurity, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSecurity, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSecurity, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSecurity, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Security {
class CSignatureHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Security::ISignatureHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSignatureHelper, RGM_SAME_DOMAIN, Elastos::Security::EIID_ISignatureHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSignatureHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSignatureHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSignatureHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Security {
class CMessageDigestHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Security::IMessageDigestHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMessageDigestHelper, RGM_SAME_DOMAIN, Elastos::Security::EIID_IMessageDigestHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMessageDigestHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMessageDigestHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMessageDigestHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Security {
class CAccessControlContext
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Security::IAccessControlContext * acc,
        /* [in] */ Elastos::Security::IDomainCombiner * combiner,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAccessControlContextClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAccessControlContext, RGM_SAME_DOMAIN,
                EIID_ICAccessControlContextClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithAccCombiner(acc, combiner, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::IProtectionDomain *> * context,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAccessControlContextClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAccessControlContext, RGM_SAME_DOMAIN,
                EIID_ICAccessControlContextClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithContext(context, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IAccessControlContext * acc,
        /* [in] */ Elastos::Security::IDomainCombiner * combiner,
        /* [out] */ Elastos::Security::IAccessControlContext** __IAccessControlContext)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(acc, combiner, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAccessControlContext = (Elastos::Security::IAccessControlContext*)__pNewObj->Probe(Elastos::Security::EIID_IAccessControlContext);
        if (*__IAccessControlContext) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IAccessControlContext * acc,
        /* [in] */ Elastos::Security::IDomainCombiner * combiner,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(acc, combiner, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IAccessControlContext * acc,
        /* [in] */ Elastos::Security::IDomainCombiner * combiner,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(acc, combiner, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IAccessControlContext * acc,
        /* [in] */ Elastos::Security::IDomainCombiner * combiner,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(acc, combiner, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::IProtectionDomain *> * context,
        /* [out] */ Elastos::Security::IAccessControlContext** __IAccessControlContext)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(context, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAccessControlContext = (Elastos::Security::IAccessControlContext*)__pNewObj->Probe(Elastos::Security::EIID_IAccessControlContext);
        if (*__IAccessControlContext) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::IProtectionDomain *> * context,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(context, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::IProtectionDomain *> * context,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(context, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::IProtectionDomain *> * context,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(context, &__pNewObj);
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
namespace Elastos {
namespace Security {
class CAccessController
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Security::IAccessController** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAccessController, RGM_SAME_DOMAIN, Elastos::Security::EIID_IAccessController, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAccessController, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAccessController, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAccessController, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Security {
class CAlgorithmParametersHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Security::IAlgorithmParametersHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAlgorithmParametersHelper, RGM_SAME_DOMAIN, Elastos::Security::EIID_IAlgorithmParametersHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAlgorithmParametersHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAlgorithmParametersHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAlgorithmParametersHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Security {
class CAlgorithmParameterGenerator
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Security::IAlgorithmParameterGeneratorSpi * paramGenSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAlgorithmParameterGeneratorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAlgorithmParameterGenerator, RGM_SAME_DOMAIN,
                EIID_ICAlgorithmParameterGeneratorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithParamGenSpiProviderAlgorithm(paramGenSpi, provider, algorithm, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IAlgorithmParameterGeneratorSpi * paramGenSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Security::IAlgorithmParameterGenerator** __IAlgorithmParameterGenerator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(paramGenSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAlgorithmParameterGenerator = (Elastos::Security::IAlgorithmParameterGenerator*)__pNewObj->Probe(Elastos::Security::EIID_IAlgorithmParameterGenerator);
        if (*__IAlgorithmParameterGenerator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IAlgorithmParameterGeneratorSpi * paramGenSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(paramGenSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IAlgorithmParameterGeneratorSpi * paramGenSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(paramGenSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IAlgorithmParameterGeneratorSpi * paramGenSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(paramGenSpi, provider, algorithm, &__pNewObj);
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
namespace Elastos {
namespace Security {
class CSecureRandom
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * seed,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSecureRandomClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSecureRandom, RGM_SAME_DOMAIN,
                EIID_ICSecureRandomClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSeed(seed, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Security::ISecureRandomSpi * secureRandomSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSecureRandomClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSecureRandom, RGM_SAME_DOMAIN,
                EIID_ICSecureRandomClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSecureRandomSpiProviderAlgorithm(secureRandomSpi, provider, algorithm, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Security::ISecureRandomSpi * secureRandomSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSecureRandomClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSecureRandom, RGM_SAME_DOMAIN,
                EIID_ICSecureRandomClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSecureRandomSpiProvider(secureRandomSpi, provider, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IRandom** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSecureRandom, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IRandom, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Security::ISecureRandom** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSecureRandom, RGM_SAME_DOMAIN, Elastos::Security::EIID_ISecureRandom, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSecureRandom, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSecureRandom, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSecureRandom, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * seed,
        /* [out] */ Elastos::Utility::IRandom** __IRandom)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(seed, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRandom = (Elastos::Utility::IRandom*)__pNewObj->Probe(Elastos::Utility::EIID_IRandom);
        if (*__IRandom) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * seed,
        /* [out] */ Elastos::Security::ISecureRandom** __ISecureRandom)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(seed, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISecureRandom = (Elastos::Security::ISecureRandom*)__pNewObj->Probe(Elastos::Security::EIID_ISecureRandom);
        if (*__ISecureRandom) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * seed,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(seed, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * seed,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(seed, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * seed,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(seed, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::ISecureRandomSpi * secureRandomSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Utility::IRandom** __IRandom)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(secureRandomSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRandom = (Elastos::Utility::IRandom*)__pNewObj->Probe(Elastos::Utility::EIID_IRandom);
        if (*__IRandom) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::ISecureRandomSpi * secureRandomSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Security::ISecureRandom** __ISecureRandom)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(secureRandomSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISecureRandom = (Elastos::Security::ISecureRandom*)__pNewObj->Probe(Elastos::Security::EIID_ISecureRandom);
        if (*__ISecureRandom) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::ISecureRandomSpi * secureRandomSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(secureRandomSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::ISecureRandomSpi * secureRandomSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(secureRandomSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::ISecureRandomSpi * secureRandomSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(secureRandomSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::ISecureRandomSpi * secureRandomSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastos::Utility::IRandom** __IRandom)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(secureRandomSpi, provider, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRandom = (Elastos::Utility::IRandom*)__pNewObj->Probe(Elastos::Utility::EIID_IRandom);
        if (*__IRandom) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::ISecureRandomSpi * secureRandomSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastos::Security::ISecureRandom** __ISecureRandom)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(secureRandomSpi, provider, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISecureRandom = (Elastos::Security::ISecureRandom*)__pNewObj->Probe(Elastos::Security::EIID_ISecureRandom);
        if (*__ISecureRandom) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::ISecureRandomSpi * secureRandomSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(secureRandomSpi, provider, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::ISecureRandomSpi * secureRandomSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(secureRandomSpi, provider, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::ISecureRandomSpi * secureRandomSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(secureRandomSpi, provider, &__pNewObj);
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
namespace Elastos {
namespace Security {
class CSecureRandomHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Security::ISecureRandomHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSecureRandomHelper, RGM_SAME_DOMAIN, Elastos::Security::EIID_ISecureRandomHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSecureRandomHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSecureRandomHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSecureRandomHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Security {
class CAllPermission
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAllPermissionClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAllPermission, RGM_SAME_DOMAIN,
                EIID_ICAllPermissionClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithNameActions(name, actions, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Security::IPermission** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAllPermission, RGM_SAME_DOMAIN, Elastos::Security::EIID_IPermission, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAllPermission, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAllPermission, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAllPermission, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
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
namespace Elastos {
namespace Security {
class CCodeSigner
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Security::Cert::ICertPath * signerCertPath,
        /* [in] */ Elastos::Security::ITimestamp * timestamp,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCodeSignerClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCodeSigner, RGM_SAME_DOMAIN,
                EIID_ICCodeSignerClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSignerCertPathTimestamp(signerCertPath, timestamp, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Security::ICodeSigner** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCodeSigner, RGM_SAME_DOMAIN, Elastos::Security::EIID_ICodeSigner, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCodeSigner, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCodeSigner, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCodeSigner, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCodeSigner, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ICertPath * signerCertPath,
        /* [in] */ Elastos::Security::ITimestamp * timestamp,
        /* [out] */ Elastos::Security::ICodeSigner** __ICodeSigner)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(signerCertPath, timestamp, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICodeSigner = (Elastos::Security::ICodeSigner*)__pNewObj->Probe(Elastos::Security::EIID_ICodeSigner);
        if (*__ICodeSigner) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ICertPath * signerCertPath,
        /* [in] */ Elastos::Security::ITimestamp * timestamp,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(signerCertPath, timestamp, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ICertPath * signerCertPath,
        /* [in] */ Elastos::Security::ITimestamp * timestamp,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(signerCertPath, timestamp, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ICertPath * signerCertPath,
        /* [in] */ Elastos::Security::ITimestamp * timestamp,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(signerCertPath, timestamp, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ICertPath * signerCertPath,
        /* [in] */ Elastos::Security::ITimestamp * timestamp,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(signerCertPath, timestamp, &__pNewObj);
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
namespace Elastos {
namespace Security {
class CCodeSource
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Net::IURL * location,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::ICertificate *> * certs,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCodeSourceClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCodeSource, RGM_SAME_DOMAIN,
                EIID_ICCodeSourceClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithLocationCerts(location, certs, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Net::IURL * location,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::ICodeSigner *> * signers,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCodeSourceClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCodeSource, RGM_SAME_DOMAIN,
                EIID_ICCodeSourceClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithLocationSigners(location, signers, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * location,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::ICertificate *> * certs,
        /* [out] */ Elastos::Security::ICodeSource** __ICodeSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(location, certs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICodeSource = (Elastos::Security::ICodeSource*)__pNewObj->Probe(Elastos::Security::EIID_ICodeSource);
        if (*__ICodeSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * location,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::ICertificate *> * certs,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(location, certs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * location,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::ICertificate *> * certs,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(location, certs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * location,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::ICertificate *> * certs,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(location, certs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * location,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::ICertificate *> * certs,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(location, certs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * location,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::ICodeSigner *> * signers,
        /* [out] */ Elastos::Security::ICodeSource** __ICodeSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(location, signers, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICodeSource = (Elastos::Security::ICodeSource*)__pNewObj->Probe(Elastos::Security::EIID_ICodeSource);
        if (*__ICodeSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * location,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::ICodeSigner *> * signers,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(location, signers, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * location,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::ICodeSigner *> * signers,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(location, signers, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * location,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::ICodeSigner *> * signers,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(location, signers, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * location,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::ICodeSigner *> * signers,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(location, signers, &__pNewObj);
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
namespace Elastos {
namespace Security {
class CDigestInputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [in] */ Elastos::Security::IMessageDigest * digest,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDigestInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDigestInputStream, RGM_SAME_DOMAIN,
                EIID_ICDigestInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithStreamDigest(stream, digest, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [in] */ Elastos::Security::IMessageDigest * digest,
        /* [out] */ Elastos::Security::IDigestInputStream** __IDigestInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, digest, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDigestInputStream = (Elastos::Security::IDigestInputStream*)__pNewObj->Probe(Elastos::Security::EIID_IDigestInputStream);
        if (*__IDigestInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [in] */ Elastos::Security::IMessageDigest * digest,
        /* [out] */ Elastos::IO::IFilterInputStream** __IFilterInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, digest, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterInputStream = (Elastos::IO::IFilterInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterInputStream);
        if (*__IFilterInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [in] */ Elastos::Security::IMessageDigest * digest,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, digest, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [in] */ Elastos::Security::IMessageDigest * digest,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, digest, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [in] */ Elastos::Security::IMessageDigest * digest,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, digest, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [in] */ Elastos::Security::IMessageDigest * digest,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, digest, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [in] */ Elastos::Security::IMessageDigest * digest,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, digest, &__pNewObj);
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
namespace Elastos {
namespace Security {
class CDigestOutputStream
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::Security::IDigestOutputStream** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDigestOutputStream, RGM_SAME_DOMAIN, Elastos::Security::EIID_IDigestOutputStream, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IFilterOutputStream** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDigestOutputStream, RGM_SAME_DOMAIN, Elastos::IO::EIID_IFilterOutputStream, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ICloseable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDigestOutputStream, RGM_SAME_DOMAIN, Elastos::IO::EIID_ICloseable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IFlushable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDigestOutputStream, RGM_SAME_DOMAIN, Elastos::IO::EIID_IFlushable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IOutputStream** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDigestOutputStream, RGM_SAME_DOMAIN, Elastos::IO::EIID_IOutputStream, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDigestOutputStream, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDigestOutputStream, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDigestOutputStream, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Security {
class CGuardedObject
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ IInterface * object,
        /* [in] */ Elastos::Security::IGuard * guard,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICGuardedObjectClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CGuardedObject, RGM_SAME_DOMAIN,
                EIID_ICGuardedObjectClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithObjectGuard(object, guard, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * object,
        /* [in] */ Elastos::Security::IGuard * guard,
        /* [out] */ Elastos::Security::IGuardedObject** __IGuardedObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(object, guard, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IGuardedObject = (Elastos::Security::IGuardedObject*)__pNewObj->Probe(Elastos::Security::EIID_IGuardedObject);
        if (*__IGuardedObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * object,
        /* [in] */ Elastos::Security::IGuard * guard,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(object, guard, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * object,
        /* [in] */ Elastos::Security::IGuard * guard,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(object, guard, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * object,
        /* [in] */ Elastos::Security::IGuard * guard,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(object, guard, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * object,
        /* [in] */ Elastos::Security::IGuard * guard,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(object, guard, &__pNewObj);
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
namespace Elastos {
namespace Security {
class CKeyFactory
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Security::IKeyFactorySpi * keyFacSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICKeyFactoryClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CKeyFactory, RGM_SAME_DOMAIN,
                EIID_ICKeyFactoryClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithKeyFacSpiProviderAlgorithm(keyFacSpi, provider, algorithm, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IKeyFactorySpi * keyFacSpi,
        /* [in] */ Elastos::Security::IProvider * provider,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [out] */ Elastos::Security::IKeyFactory** __IKeyFactory)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyFacSpi, provider, algorithm, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeyFactory = (Elastos::Security::IKeyFactory*)__pNewObj->Probe(Elastos::Security::EIID_IKeyFactory);
        if (*__IKeyFactory) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IKeyFactorySpi * keyFacSpi,
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
        /* [in] */ Elastos::Security::IKeyFactorySpi * keyFacSpi,
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
        /* [in] */ Elastos::Security::IKeyFactorySpi * keyFacSpi,
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
namespace Elastos {
namespace Security {
class CKeyFactoryHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Security::IKeyFactoryHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyFactoryHelper, RGM_SAME_DOMAIN, Elastos::Security::EIID_IKeyFactoryHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyFactoryHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyFactoryHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyFactoryHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Security {
class CKeyPair
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Security::IPublicKey * publicKey,
        /* [in] */ Elastos::Security::IPrivateKey * privateKey,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICKeyPairClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CKeyPair, RGM_SAME_DOMAIN,
                EIID_ICKeyPairClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPublicKeyPrivateKey(publicKey, privateKey, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IPublicKey * publicKey,
        /* [in] */ Elastos::Security::IPrivateKey * privateKey,
        /* [out] */ Elastos::Security::IKeyPair** __IKeyPair)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(publicKey, privateKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeyPair = (Elastos::Security::IKeyPair*)__pNewObj->Probe(Elastos::Security::EIID_IKeyPair);
        if (*__IKeyPair) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IPublicKey * publicKey,
        /* [in] */ Elastos::Security::IPrivateKey * privateKey,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(publicKey, privateKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IPublicKey * publicKey,
        /* [in] */ Elastos::Security::IPrivateKey * privateKey,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(publicKey, privateKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IPublicKey * publicKey,
        /* [in] */ Elastos::Security::IPrivateKey * privateKey,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(publicKey, privateKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IPublicKey * publicKey,
        /* [in] */ Elastos::Security::IPrivateKey * privateKey,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(publicKey, privateKey, &__pNewObj);
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
namespace Elastos {
namespace Security {
class CKeyPairGeneratorHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Security::IKeyPairGeneratorHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyPairGeneratorHelper, RGM_SAME_DOMAIN, Elastos::Security::EIID_IKeyPairGeneratorHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyPairGeneratorHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyPairGeneratorHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyPairGeneratorHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Security {
class CKeyRep
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Security::KeyRepType type,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& format,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encoded,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICKeyRepClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CKeyRep, RGM_SAME_DOMAIN,
                EIID_ICKeyRepClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTypeAlgorithmFormatEncoded(type, algorithm, format, encoded, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::KeyRepType type,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& format,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encoded,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(type, algorithm, format, encoded, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::KeyRepType type,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& format,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encoded,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(type, algorithm, format, encoded, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::KeyRepType type,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& format,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encoded,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(type, algorithm, format, encoded, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::KeyRepType type,
        /* [in] */ const _ELASTOS String& algorithm,
        /* [in] */ const _ELASTOS String& format,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encoded,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(type, algorithm, format, encoded, &__pNewObj);
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
namespace Elastos {
namespace Security {
class CKeyStoreHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Security::IKeyStoreHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyStoreHelper, RGM_SAME_DOMAIN, Elastos::Security::EIID_IKeyStoreHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyStoreHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyStoreHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKeyStoreHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Security {
class CKeyStorePrivateKeyEntry
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Security::IPrivateKey * privateKey,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> * chain,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICKeyStorePrivateKeyEntryClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CKeyStorePrivateKeyEntry, RGM_SAME_DOMAIN,
                EIID_ICKeyStorePrivateKeyEntryClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPrivateKeyChain(privateKey, chain, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IPrivateKey * privateKey,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> * chain,
        /* [out] */ Elastos::Security::IKeyStorePrivateKeyEntry** __IKeyStorePrivateKeyEntry)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(privateKey, chain, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeyStorePrivateKeyEntry = (Elastos::Security::IKeyStorePrivateKeyEntry*)__pNewObj->Probe(Elastos::Security::EIID_IKeyStorePrivateKeyEntry);
        if (*__IKeyStorePrivateKeyEntry) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IPrivateKey * privateKey,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> * chain,
        /* [out] */ Elastos::Security::IKeyStoreEntry** __IKeyStoreEntry)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(privateKey, chain, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeyStoreEntry = (Elastos::Security::IKeyStoreEntry*)__pNewObj->Probe(Elastos::Security::EIID_IKeyStoreEntry);
        if (*__IKeyStoreEntry) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IPrivateKey * privateKey,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> * chain,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(privateKey, chain, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IPrivateKey * privateKey,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> * chain,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(privateKey, chain, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IPrivateKey * privateKey,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> * chain,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(privateKey, chain, &__pNewObj);
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
namespace Elastos {
namespace Security {
class CKeyStoreSecretKeyEntry
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastosx::Crypto::ISecretKey * secretKey,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICKeyStoreSecretKeyEntryClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CKeyStoreSecretKeyEntry, RGM_SAME_DOMAIN,
                EIID_ICKeyStoreSecretKeyEntryClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSecretKey(secretKey, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::ISecretKey * secretKey,
        /* [out] */ Elastos::Security::IKeyStoreSecretKeyEntry** __IKeyStoreSecretKeyEntry)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(secretKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeyStoreSecretKeyEntry = (Elastos::Security::IKeyStoreSecretKeyEntry*)__pNewObj->Probe(Elastos::Security::EIID_IKeyStoreSecretKeyEntry);
        if (*__IKeyStoreSecretKeyEntry) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::ISecretKey * secretKey,
        /* [out] */ Elastos::Security::IKeyStoreEntry** __IKeyStoreEntry)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(secretKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeyStoreEntry = (Elastos::Security::IKeyStoreEntry*)__pNewObj->Probe(Elastos::Security::EIID_IKeyStoreEntry);
        if (*__IKeyStoreEntry) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::ISecretKey * secretKey,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(secretKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::ISecretKey * secretKey,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(secretKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Crypto::ISecretKey * secretKey,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(secretKey, &__pNewObj);
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
namespace Elastos {
namespace Security {
class CKeyStoreTrustedCertificateEntry
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Security::Cert::ICertificate * trustCertificate,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICKeyStoreTrustedCertificateEntryClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CKeyStoreTrustedCertificateEntry, RGM_SAME_DOMAIN,
                EIID_ICKeyStoreTrustedCertificateEntryClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTrustCertificate(trustCertificate, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ICertificate * trustCertificate,
        /* [out] */ Elastos::Security::IKeyStoreTrustedCertificateEntry** __IKeyStoreTrustedCertificateEntry)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustCertificate, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeyStoreTrustedCertificateEntry = (Elastos::Security::IKeyStoreTrustedCertificateEntry*)__pNewObj->Probe(Elastos::Security::EIID_IKeyStoreTrustedCertificateEntry);
        if (*__IKeyStoreTrustedCertificateEntry) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ICertificate * trustCertificate,
        /* [out] */ Elastos::Security::IKeyStoreEntry** __IKeyStoreEntry)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustCertificate, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeyStoreEntry = (Elastos::Security::IKeyStoreEntry*)__pNewObj->Probe(Elastos::Security::EIID_IKeyStoreEntry);
        if (*__IKeyStoreEntry) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ICertificate * trustCertificate,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustCertificate, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ICertificate * trustCertificate,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustCertificate, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ICertificate * trustCertificate,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustCertificate, &__pNewObj);
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
namespace Elastos {
namespace Security {
class CPermissions
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::Security::IPermissionCollection** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPermissions, RGM_SAME_DOMAIN, Elastos::Security::EIID_IPermissionCollection, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPermissions, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPermissions, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPermissions, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPermissions, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Security {
class CPermissionsHash
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::Security::IPermissionCollection** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPermissionsHash, RGM_SAME_DOMAIN, Elastos::Security::EIID_IPermissionCollection, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPermissionsHash, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPermissionsHash, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPermissionsHash, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPermissionsHash, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Security {
class CUnresolvedPermission
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> * certs,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICUnresolvedPermissionClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CUnresolvedPermission, RGM_SAME_DOMAIN,
                EIID_ICUnresolvedPermissionClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTypeNameActionsCerts(type, name, actions, certs, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> * certs,
        /* [out] */ Elastos::Security::IUnresolvedPermission** __IUnresolvedPermission)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(type, name, actions, certs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IUnresolvedPermission = (Elastos::Security::IUnresolvedPermission*)__pNewObj->Probe(Elastos::Security::EIID_IUnresolvedPermission);
        if (*__IUnresolvedPermission) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> * certs,
        /* [out] */ Elastos::Security::IPermission** __IPermission)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(type, name, actions, certs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPermission = (Elastos::Security::IPermission*)__pNewObj->Probe(Elastos::Security::EIID_IPermission);
        if (*__IPermission) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> * certs,
        /* [out] */ Elastos::Security::IGuard** __IGuard)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(type, name, actions, certs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IGuard = (Elastos::Security::IGuard*)__pNewObj->Probe(Elastos::Security::EIID_IGuard);
        if (*__IGuard) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> * certs,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(type, name, actions, certs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> * certs,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(type, name, actions, certs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> * certs,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(type, name, actions, certs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& actions,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> * certs,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(type, name, actions, certs, &__pNewObj);
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
namespace Elastos {
namespace Security {
class CTimestamp
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::IDate * timestamp,
        /* [in] */ Elastos::Security::Cert::ICertPath * signerCertPath,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICTimestampClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CTimestamp, RGM_SAME_DOMAIN,
                EIID_ICTimestampClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTimestampSignerCertPath(timestamp, signerCertPath, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IDate * timestamp,
        /* [in] */ Elastos::Security::Cert::ICertPath * signerCertPath,
        /* [out] */ Elastos::Security::ITimestamp** __ITimestamp)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(timestamp, signerCertPath, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ITimestamp = (Elastos::Security::ITimestamp*)__pNewObj->Probe(Elastos::Security::EIID_ITimestamp);
        if (*__ITimestamp) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IDate * timestamp,
        /* [in] */ Elastos::Security::Cert::ICertPath * signerCertPath,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(timestamp, signerCertPath, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IDate * timestamp,
        /* [in] */ Elastos::Security::Cert::ICertPath * signerCertPath,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(timestamp, signerCertPath, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IDate * timestamp,
        /* [in] */ Elastos::Security::Cert::ICertPath * signerCertPath,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(timestamp, signerCertPath, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IDate * timestamp,
        /* [in] */ Elastos::Security::Cert::ICertPath * signerCertPath,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(timestamp, signerCertPath, &__pNewObj);
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
namespace Elastos {
namespace Security {
class CSignedObject
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::ISerializable * object,
        /* [in] */ Elastos::Security::IPrivateKey * signingKey,
        /* [in] */ Elastos::Security::ISignature * signingEngine,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSignedObjectClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSignedObject, RGM_SAME_DOMAIN,
                EIID_ICSignedObjectClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithObjectSigningKeySigningEngine(object, signingKey, signingEngine, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::ISerializable * object,
        /* [in] */ Elastos::Security::IPrivateKey * signingKey,
        /* [in] */ Elastos::Security::ISignature * signingEngine,
        /* [out] */ Elastos::Security::ISignedObject** __ISignedObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(object, signingKey, signingEngine, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISignedObject = (Elastos::Security::ISignedObject*)__pNewObj->Probe(Elastos::Security::EIID_ISignedObject);
        if (*__ISignedObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::ISerializable * object,
        /* [in] */ Elastos::Security::IPrivateKey * signingKey,
        /* [in] */ Elastos::Security::ISignature * signingEngine,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(object, signingKey, signingEngine, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::ISerializable * object,
        /* [in] */ Elastos::Security::IPrivateKey * signingKey,
        /* [in] */ Elastos::Security::ISignature * signingEngine,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(object, signingKey, signingEngine, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::ISerializable * object,
        /* [in] */ Elastos::Security::IPrivateKey * signingKey,
        /* [in] */ Elastos::Security::ISignature * signingEngine,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(object, signingKey, signingEngine, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::ISerializable * object,
        /* [in] */ Elastos::Security::IPrivateKey * signingKey,
        /* [in] */ Elastos::Security::ISignature * signingEngine,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(object, signingKey, signingEngine, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Cert {
class CCertificateFactoryHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Security::Cert::ICertificateFactoryHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCertificateFactoryHelper, RGM_SAME_DOMAIN, Elastos::Security::Cert::EIID_ICertificateFactoryHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCertificateFactoryHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCertificateFactoryHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCertificateFactoryHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
class CCollectionCertStoreParameters
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCollectionCertStoreParametersClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCollectionCertStoreParameters, RGM_SAME_DOMAIN,
                EIID_ICCollectionCertStoreParametersClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCollection(collection, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Security::Cert::ICollectionCertStoreParameters** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollectionCertStoreParameters, RGM_SAME_DOMAIN, Elastos::Security::Cert::EIID_ICollectionCertStoreParameters, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Security::Cert::ICertStoreParameters** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollectionCertStoreParameters, RGM_SAME_DOMAIN, Elastos::Security::Cert::EIID_ICertStoreParameters, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollectionCertStoreParameters, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollectionCertStoreParameters, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollectionCertStoreParameters, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollectionCertStoreParameters, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Security::Cert::ICollectionCertStoreParameters** __ICollectionCertStoreParameters)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollectionCertStoreParameters = (Elastos::Security::Cert::ICollectionCertStoreParameters*)__pNewObj->Probe(Elastos::Security::Cert::EIID_ICollectionCertStoreParameters);
        if (*__ICollectionCertStoreParameters) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Security::Cert::ICertStoreParameters** __ICertStoreParameters)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICertStoreParameters = (Elastos::Security::Cert::ICertStoreParameters*)__pNewObj->Probe(Elastos::Security::Cert::EIID_ICertStoreParameters);
        if (*__ICertStoreParameters) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Cert {
class CLDAPCertStoreParameters
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& serverName,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICLDAPCertStoreParametersClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CLDAPCertStoreParameters, RGM_SAME_DOMAIN,
                EIID_ICLDAPCertStoreParametersClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithServerNamePort(serverName, port, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& serverName,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICLDAPCertStoreParametersClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CLDAPCertStoreParameters, RGM_SAME_DOMAIN,
                EIID_ICLDAPCertStoreParametersClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithServerName(serverName, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Security::Cert::ILDAPCertStoreParameters** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLDAPCertStoreParameters, RGM_SAME_DOMAIN, Elastos::Security::Cert::EIID_ILDAPCertStoreParameters, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Security::Cert::ICertStoreParameters** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLDAPCertStoreParameters, RGM_SAME_DOMAIN, Elastos::Security::Cert::EIID_ICertStoreParameters, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLDAPCertStoreParameters, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLDAPCertStoreParameters, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLDAPCertStoreParameters, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLDAPCertStoreParameters, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& serverName,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Security::Cert::ILDAPCertStoreParameters** __ILDAPCertStoreParameters)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(serverName, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ILDAPCertStoreParameters = (Elastos::Security::Cert::ILDAPCertStoreParameters*)__pNewObj->Probe(Elastos::Security::Cert::EIID_ILDAPCertStoreParameters);
        if (*__ILDAPCertStoreParameters) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& serverName,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Security::Cert::ICertStoreParameters** __ICertStoreParameters)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(serverName, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICertStoreParameters = (Elastos::Security::Cert::ICertStoreParameters*)__pNewObj->Probe(Elastos::Security::Cert::EIID_ICertStoreParameters);
        if (*__ICertStoreParameters) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& serverName,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(serverName, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& serverName,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(serverName, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& serverName,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(serverName, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& serverName,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(serverName, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& serverName,
        /* [out] */ Elastos::Security::Cert::ILDAPCertStoreParameters** __ILDAPCertStoreParameters)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(serverName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ILDAPCertStoreParameters = (Elastos::Security::Cert::ILDAPCertStoreParameters*)__pNewObj->Probe(Elastos::Security::Cert::EIID_ILDAPCertStoreParameters);
        if (*__ILDAPCertStoreParameters) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& serverName,
        /* [out] */ Elastos::Security::Cert::ICertStoreParameters** __ICertStoreParameters)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(serverName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICertStoreParameters = (Elastos::Security::Cert::ICertStoreParameters*)__pNewObj->Probe(Elastos::Security::Cert::EIID_ICertStoreParameters);
        if (*__ICertStoreParameters) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& serverName,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(serverName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& serverName,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(serverName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& serverName,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(serverName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& serverName,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(serverName, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Cert {
class CPKIXParameters
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ISet * trustAnchors,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPKIXParametersClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPKIXParameters, RGM_SAME_DOMAIN,
                EIID_ICPKIXParametersClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTrustAnchors(trustAnchors, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Security::IKeyStore * keyStore,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPKIXParametersClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPKIXParameters, RGM_SAME_DOMAIN,
                EIID_ICPKIXParametersClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithKeyStore(keyStore, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Security::Cert::IPKIXParameters** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPKIXParameters, RGM_SAME_DOMAIN, Elastos::Security::Cert::EIID_IPKIXParameters, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Security::Cert::ICertPathParameters** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPKIXParameters, RGM_SAME_DOMAIN, Elastos::Security::Cert::EIID_ICertPathParameters, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPKIXParameters, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPKIXParameters, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPKIXParameters, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPKIXParameters, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISet * trustAnchors,
        /* [out] */ Elastos::Security::Cert::IPKIXParameters** __IPKIXParameters)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustAnchors, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPKIXParameters = (Elastos::Security::Cert::IPKIXParameters*)__pNewObj->Probe(Elastos::Security::Cert::EIID_IPKIXParameters);
        if (*__IPKIXParameters) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISet * trustAnchors,
        /* [out] */ Elastos::Security::Cert::ICertPathParameters** __ICertPathParameters)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustAnchors, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICertPathParameters = (Elastos::Security::Cert::ICertPathParameters*)__pNewObj->Probe(Elastos::Security::Cert::EIID_ICertPathParameters);
        if (*__ICertPathParameters) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISet * trustAnchors,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustAnchors, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISet * trustAnchors,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustAnchors, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISet * trustAnchors,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustAnchors, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISet * trustAnchors,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustAnchors, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IKeyStore * keyStore,
        /* [out] */ Elastos::Security::Cert::IPKIXParameters** __IPKIXParameters)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyStore, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPKIXParameters = (Elastos::Security::Cert::IPKIXParameters*)__pNewObj->Probe(Elastos::Security::Cert::EIID_IPKIXParameters);
        if (*__IPKIXParameters) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IKeyStore * keyStore,
        /* [out] */ Elastos::Security::Cert::ICertPathParameters** __ICertPathParameters)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyStore, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICertPathParameters = (Elastos::Security::Cert::ICertPathParameters*)__pNewObj->Probe(Elastos::Security::Cert::EIID_ICertPathParameters);
        if (*__ICertPathParameters) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IKeyStore * keyStore,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyStore, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IKeyStore * keyStore,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyStore, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IKeyStore * keyStore,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyStore, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IKeyStore * keyStore,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyStore, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Cert {
class CPKIXBuilderParameters
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ISet * trustAnchors,
        /* [in] */ Elastos::Security::Cert::ICertSelector * targetConstraints,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPKIXBuilderParametersClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPKIXBuilderParameters, RGM_SAME_DOMAIN,
                EIID_ICPKIXBuilderParametersClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTrustAnchorsTargetConstraints(trustAnchors, targetConstraints, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Security::IKeyStore * keyStore,
        /* [in] */ Elastos::Security::Cert::ICertSelector * targetConstraints,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPKIXBuilderParametersClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPKIXBuilderParameters, RGM_SAME_DOMAIN,
                EIID_ICPKIXBuilderParametersClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithKeyStoreTargetConstraints(keyStore, targetConstraints, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Security::Cert::IPKIXBuilderParameters** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPKIXBuilderParameters, RGM_SAME_DOMAIN, Elastos::Security::Cert::EIID_IPKIXBuilderParameters, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Security::Cert::IPKIXParameters** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPKIXBuilderParameters, RGM_SAME_DOMAIN, Elastos::Security::Cert::EIID_IPKIXParameters, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Security::Cert::ICertPathParameters** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPKIXBuilderParameters, RGM_SAME_DOMAIN, Elastos::Security::Cert::EIID_ICertPathParameters, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPKIXBuilderParameters, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPKIXBuilderParameters, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPKIXBuilderParameters, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPKIXBuilderParameters, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISet * trustAnchors,
        /* [in] */ Elastos::Security::Cert::ICertSelector * targetConstraints,
        /* [out] */ Elastos::Security::Cert::IPKIXBuilderParameters** __IPKIXBuilderParameters)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustAnchors, targetConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPKIXBuilderParameters = (Elastos::Security::Cert::IPKIXBuilderParameters*)__pNewObj->Probe(Elastos::Security::Cert::EIID_IPKIXBuilderParameters);
        if (*__IPKIXBuilderParameters) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISet * trustAnchors,
        /* [in] */ Elastos::Security::Cert::ICertSelector * targetConstraints,
        /* [out] */ Elastos::Security::Cert::IPKIXParameters** __IPKIXParameters)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustAnchors, targetConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPKIXParameters = (Elastos::Security::Cert::IPKIXParameters*)__pNewObj->Probe(Elastos::Security::Cert::EIID_IPKIXParameters);
        if (*__IPKIXParameters) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISet * trustAnchors,
        /* [in] */ Elastos::Security::Cert::ICertSelector * targetConstraints,
        /* [out] */ Elastos::Security::Cert::ICertPathParameters** __ICertPathParameters)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustAnchors, targetConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICertPathParameters = (Elastos::Security::Cert::ICertPathParameters*)__pNewObj->Probe(Elastos::Security::Cert::EIID_ICertPathParameters);
        if (*__ICertPathParameters) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISet * trustAnchors,
        /* [in] */ Elastos::Security::Cert::ICertSelector * targetConstraints,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustAnchors, targetConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISet * trustAnchors,
        /* [in] */ Elastos::Security::Cert::ICertSelector * targetConstraints,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustAnchors, targetConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISet * trustAnchors,
        /* [in] */ Elastos::Security::Cert::ICertSelector * targetConstraints,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustAnchors, targetConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISet * trustAnchors,
        /* [in] */ Elastos::Security::Cert::ICertSelector * targetConstraints,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustAnchors, targetConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IKeyStore * keyStore,
        /* [in] */ Elastos::Security::Cert::ICertSelector * targetConstraints,
        /* [out] */ Elastos::Security::Cert::IPKIXBuilderParameters** __IPKIXBuilderParameters)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyStore, targetConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPKIXBuilderParameters = (Elastos::Security::Cert::IPKIXBuilderParameters*)__pNewObj->Probe(Elastos::Security::Cert::EIID_IPKIXBuilderParameters);
        if (*__IPKIXBuilderParameters) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IKeyStore * keyStore,
        /* [in] */ Elastos::Security::Cert::ICertSelector * targetConstraints,
        /* [out] */ Elastos::Security::Cert::IPKIXParameters** __IPKIXParameters)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyStore, targetConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPKIXParameters = (Elastos::Security::Cert::IPKIXParameters*)__pNewObj->Probe(Elastos::Security::Cert::EIID_IPKIXParameters);
        if (*__IPKIXParameters) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IKeyStore * keyStore,
        /* [in] */ Elastos::Security::Cert::ICertSelector * targetConstraints,
        /* [out] */ Elastos::Security::Cert::ICertPathParameters** __ICertPathParameters)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyStore, targetConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICertPathParameters = (Elastos::Security::Cert::ICertPathParameters*)__pNewObj->Probe(Elastos::Security::Cert::EIID_ICertPathParameters);
        if (*__ICertPathParameters) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IKeyStore * keyStore,
        /* [in] */ Elastos::Security::Cert::ICertSelector * targetConstraints,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyStore, targetConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IKeyStore * keyStore,
        /* [in] */ Elastos::Security::Cert::ICertSelector * targetConstraints,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyStore, targetConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IKeyStore * keyStore,
        /* [in] */ Elastos::Security::Cert::ICertSelector * targetConstraints,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyStore, targetConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::IKeyStore * keyStore,
        /* [in] */ Elastos::Security::Cert::ICertSelector * targetConstraints,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyStore, targetConstraints, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Cert {
class CTrustAnchor
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Security::Cert::IX509Certificate * trustedCert,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * nameConstraints,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICTrustAnchorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CTrustAnchor, RGM_SAME_DOMAIN,
                EIID_ICTrustAnchorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTrustedCertNameConstraints(trustedCert, nameConstraints, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& caName,
        /* [in] */ Elastos::Security::IPublicKey * caPublicKey,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * nameConstraints,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICTrustAnchorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CTrustAnchor, RGM_SAME_DOMAIN,
                EIID_ICTrustAnchorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCaNameCaPublicKeyNameConstraints(caName, caPublicKey, nameConstraints, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastosx::Security::Auth::X500::IX500Principal * caPrincipal,
        /* [in] */ Elastos::Security::IPublicKey * caPublicKey,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * nameConstraints,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICTrustAnchorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CTrustAnchor, RGM_SAME_DOMAIN,
                EIID_ICTrustAnchorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCaPrincipalCaPublicKeyNameConstraints(caPrincipal, caPublicKey, nameConstraints, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::IX509Certificate * trustedCert,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * nameConstraints,
        /* [out] */ Elastos::Security::Cert::ITrustAnchor** __ITrustAnchor)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustedCert, nameConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ITrustAnchor = (Elastos::Security::Cert::ITrustAnchor*)__pNewObj->Probe(Elastos::Security::Cert::EIID_ITrustAnchor);
        if (*__ITrustAnchor) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::IX509Certificate * trustedCert,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * nameConstraints,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustedCert, nameConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::IX509Certificate * trustedCert,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * nameConstraints,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustedCert, nameConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::IX509Certificate * trustedCert,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * nameConstraints,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustedCert, nameConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& caName,
        /* [in] */ Elastos::Security::IPublicKey * caPublicKey,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * nameConstraints,
        /* [out] */ Elastos::Security::Cert::ITrustAnchor** __ITrustAnchor)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(caName, caPublicKey, nameConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ITrustAnchor = (Elastos::Security::Cert::ITrustAnchor*)__pNewObj->Probe(Elastos::Security::Cert::EIID_ITrustAnchor);
        if (*__ITrustAnchor) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& caName,
        /* [in] */ Elastos::Security::IPublicKey * caPublicKey,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * nameConstraints,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(caName, caPublicKey, nameConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& caName,
        /* [in] */ Elastos::Security::IPublicKey * caPublicKey,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * nameConstraints,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(caName, caPublicKey, nameConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& caName,
        /* [in] */ Elastos::Security::IPublicKey * caPublicKey,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * nameConstraints,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(caName, caPublicKey, nameConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Security::Auth::X500::IX500Principal * caPrincipal,
        /* [in] */ Elastos::Security::IPublicKey * caPublicKey,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * nameConstraints,
        /* [out] */ Elastos::Security::Cert::ITrustAnchor** __ITrustAnchor)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(caPrincipal, caPublicKey, nameConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ITrustAnchor = (Elastos::Security::Cert::ITrustAnchor*)__pNewObj->Probe(Elastos::Security::Cert::EIID_ITrustAnchor);
        if (*__ITrustAnchor) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Security::Auth::X500::IX500Principal * caPrincipal,
        /* [in] */ Elastos::Security::IPublicKey * caPublicKey,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * nameConstraints,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(caPrincipal, caPublicKey, nameConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Security::Auth::X500::IX500Principal * caPrincipal,
        /* [in] */ Elastos::Security::IPublicKey * caPublicKey,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * nameConstraints,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(caPrincipal, caPublicKey, nameConstraints, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastosx::Security::Auth::X500::IX500Principal * caPrincipal,
        /* [in] */ Elastos::Security::IPublicKey * caPublicKey,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * nameConstraints,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(caPrincipal, caPublicKey, nameConstraints, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Cert {
class CPKIXCertPathBuilderResult
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Security::Cert::ICertPath * certPath,
        /* [in] */ Elastos::Security::Cert::ITrustAnchor * trustAnchor,
        /* [in] */ Elastos::Security::Cert::IPolicyNode * policyTree,
        /* [in] */ Elastos::Security::IPublicKey * subjectPublicKey,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPKIXCertPathBuilderResultClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPKIXCertPathBuilderResult, RGM_SAME_DOMAIN,
                EIID_ICPKIXCertPathBuilderResultClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCertPathTrustAnchorPolicyTreeSubjectPublicKey(certPath, trustAnchor, policyTree, subjectPublicKey, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ICertPath * certPath,
        /* [in] */ Elastos::Security::Cert::ITrustAnchor * trustAnchor,
        /* [in] */ Elastos::Security::Cert::IPolicyNode * policyTree,
        /* [in] */ Elastos::Security::IPublicKey * subjectPublicKey,
        /* [out] */ Elastos::Security::Cert::IPKIXCertPathBuilderResult** __IPKIXCertPathBuilderResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(certPath, trustAnchor, policyTree, subjectPublicKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPKIXCertPathBuilderResult = (Elastos::Security::Cert::IPKIXCertPathBuilderResult*)__pNewObj->Probe(Elastos::Security::Cert::EIID_IPKIXCertPathBuilderResult);
        if (*__IPKIXCertPathBuilderResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ICertPath * certPath,
        /* [in] */ Elastos::Security::Cert::ITrustAnchor * trustAnchor,
        /* [in] */ Elastos::Security::Cert::IPolicyNode * policyTree,
        /* [in] */ Elastos::Security::IPublicKey * subjectPublicKey,
        /* [out] */ Elastos::Security::Cert::IPKIXCertPathValidatorResult** __IPKIXCertPathValidatorResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(certPath, trustAnchor, policyTree, subjectPublicKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPKIXCertPathValidatorResult = (Elastos::Security::Cert::IPKIXCertPathValidatorResult*)__pNewObj->Probe(Elastos::Security::Cert::EIID_IPKIXCertPathValidatorResult);
        if (*__IPKIXCertPathValidatorResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ICertPath * certPath,
        /* [in] */ Elastos::Security::Cert::ITrustAnchor * trustAnchor,
        /* [in] */ Elastos::Security::Cert::IPolicyNode * policyTree,
        /* [in] */ Elastos::Security::IPublicKey * subjectPublicKey,
        /* [out] */ Elastos::Security::Cert::ICertPathValidatorResult** __ICertPathValidatorResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(certPath, trustAnchor, policyTree, subjectPublicKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICertPathValidatorResult = (Elastos::Security::Cert::ICertPathValidatorResult*)__pNewObj->Probe(Elastos::Security::Cert::EIID_ICertPathValidatorResult);
        if (*__ICertPathValidatorResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ICertPath * certPath,
        /* [in] */ Elastos::Security::Cert::ITrustAnchor * trustAnchor,
        /* [in] */ Elastos::Security::Cert::IPolicyNode * policyTree,
        /* [in] */ Elastos::Security::IPublicKey * subjectPublicKey,
        /* [out] */ Elastos::Security::Cert::ICertPathBuilderResult** __ICertPathBuilderResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(certPath, trustAnchor, policyTree, subjectPublicKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICertPathBuilderResult = (Elastos::Security::Cert::ICertPathBuilderResult*)__pNewObj->Probe(Elastos::Security::Cert::EIID_ICertPathBuilderResult);
        if (*__ICertPathBuilderResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ICertPath * certPath,
        /* [in] */ Elastos::Security::Cert::ITrustAnchor * trustAnchor,
        /* [in] */ Elastos::Security::Cert::IPolicyNode * policyTree,
        /* [in] */ Elastos::Security::IPublicKey * subjectPublicKey,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(certPath, trustAnchor, policyTree, subjectPublicKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ICertPath * certPath,
        /* [in] */ Elastos::Security::Cert::ITrustAnchor * trustAnchor,
        /* [in] */ Elastos::Security::Cert::IPolicyNode * policyTree,
        /* [in] */ Elastos::Security::IPublicKey * subjectPublicKey,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(certPath, trustAnchor, policyTree, subjectPublicKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ICertPath * certPath,
        /* [in] */ Elastos::Security::Cert::ITrustAnchor * trustAnchor,
        /* [in] */ Elastos::Security::Cert::IPolicyNode * policyTree,
        /* [in] */ Elastos::Security::IPublicKey * subjectPublicKey,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(certPath, trustAnchor, policyTree, subjectPublicKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ICertPath * certPath,
        /* [in] */ Elastos::Security::Cert::ITrustAnchor * trustAnchor,
        /* [in] */ Elastos::Security::Cert::IPolicyNode * policyTree,
        /* [in] */ Elastos::Security::IPublicKey * subjectPublicKey,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(certPath, trustAnchor, policyTree, subjectPublicKey, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Cert {
class CPKIXCertPathValidatorResult
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Security::Cert::ITrustAnchor * trustAnchor,
        /* [in] */ Elastos::Security::Cert::IPolicyNode * policyTree,
        /* [in] */ Elastos::Security::IPublicKey * subjectPublicKey,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPKIXCertPathValidatorResultClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPKIXCertPathValidatorResult, RGM_SAME_DOMAIN,
                EIID_ICPKIXCertPathValidatorResultClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTrustAnchorPolicyTreeSubjectPublicKey(trustAnchor, policyTree, subjectPublicKey, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ITrustAnchor * trustAnchor,
        /* [in] */ Elastos::Security::Cert::IPolicyNode * policyTree,
        /* [in] */ Elastos::Security::IPublicKey * subjectPublicKey,
        /* [out] */ Elastos::Security::Cert::IPKIXCertPathValidatorResult** __IPKIXCertPathValidatorResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustAnchor, policyTree, subjectPublicKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPKIXCertPathValidatorResult = (Elastos::Security::Cert::IPKIXCertPathValidatorResult*)__pNewObj->Probe(Elastos::Security::Cert::EIID_IPKIXCertPathValidatorResult);
        if (*__IPKIXCertPathValidatorResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ITrustAnchor * trustAnchor,
        /* [in] */ Elastos::Security::Cert::IPolicyNode * policyTree,
        /* [in] */ Elastos::Security::IPublicKey * subjectPublicKey,
        /* [out] */ Elastos::Security::Cert::ICertPathValidatorResult** __ICertPathValidatorResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustAnchor, policyTree, subjectPublicKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICertPathValidatorResult = (Elastos::Security::Cert::ICertPathValidatorResult*)__pNewObj->Probe(Elastos::Security::Cert::EIID_ICertPathValidatorResult);
        if (*__ICertPathValidatorResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ITrustAnchor * trustAnchor,
        /* [in] */ Elastos::Security::Cert::IPolicyNode * policyTree,
        /* [in] */ Elastos::Security::IPublicKey * subjectPublicKey,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustAnchor, policyTree, subjectPublicKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ITrustAnchor * trustAnchor,
        /* [in] */ Elastos::Security::Cert::IPolicyNode * policyTree,
        /* [in] */ Elastos::Security::IPublicKey * subjectPublicKey,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustAnchor, policyTree, subjectPublicKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ITrustAnchor * trustAnchor,
        /* [in] */ Elastos::Security::Cert::IPolicyNode * policyTree,
        /* [in] */ Elastos::Security::IPublicKey * subjectPublicKey,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustAnchor, policyTree, subjectPublicKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Cert::ITrustAnchor * trustAnchor,
        /* [in] */ Elastos::Security::Cert::IPolicyNode * policyTree,
        /* [in] */ Elastos::Security::IPublicKey * subjectPublicKey,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(trustAnchor, policyTree, subjectPublicKey, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Cert {
class CPolicyQualifierInfo
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encoded,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPolicyQualifierInfoClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPolicyQualifierInfo, RGM_SAME_DOMAIN,
                EIID_ICPolicyQualifierInfoClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithEncoded(encoded, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encoded,
        /* [out] */ Elastos::Security::Cert::IPolicyQualifierInfo** __IPolicyQualifierInfo)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(encoded, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPolicyQualifierInfo = (Elastos::Security::Cert::IPolicyQualifierInfo*)__pNewObj->Probe(Elastos::Security::Cert::EIID_IPolicyQualifierInfo);
        if (*__IPolicyQualifierInfo) __pNewObj->AddRef();
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

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
class CX509CRLSelector
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::Security::Cert::IX509CRLSelector** __object)
    {
        return _CObject_CreateInstance(ECLSID_CX509CRLSelector, RGM_SAME_DOMAIN, Elastos::Security::Cert::EIID_IX509CRLSelector, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Security::Cert::ICRLSelector** __object)
    {
        return _CObject_CreateInstance(ECLSID_CX509CRLSelector, RGM_SAME_DOMAIN, Elastos::Security::Cert::EIID_ICRLSelector, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CX509CRLSelector, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CX509CRLSelector, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CX509CRLSelector, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CX509CRLSelector, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace Security {
namespace Cert {
class CX509CertSelector
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::Security::Cert::IX509CertSelector** __object)
    {
        return _CObject_CreateInstance(ECLSID_CX509CertSelector, RGM_SAME_DOMAIN, Elastos::Security::Cert::EIID_IX509CertSelector, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Security::Cert::ICertSelector** __object)
    {
        return _CObject_CreateInstance(ECLSID_CX509CertSelector, RGM_SAME_DOMAIN, Elastos::Security::Cert::EIID_ICertSelector, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CX509CertSelector, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CX509CertSelector, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CX509CertSelector, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CX509CertSelector, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
class CDSAParameterSpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * q,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDSAParameterSpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDSAParameterSpec, RGM_SAME_DOMAIN,
                EIID_ICDSAParameterSpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPQG(p, q, g, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * q,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ Elastos::Security::Spec::IDSAParameterSpec** __IDSAParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(p, q, g, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDSAParameterSpec = (Elastos::Security::Spec::IDSAParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IDSAParameterSpec);
        if (*__IDSAParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * q,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec** __IAlgorithmParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(p, q, g, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAlgorithmParameterSpec = (Elastos::Security::Spec::IAlgorithmParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IAlgorithmParameterSpec);
        if (*__IAlgorithmParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * q,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ Elastos::Security::Interfaces::IDSAParams** __IDSAParams)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(p, q, g, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDSAParams = (Elastos::Security::Interfaces::IDSAParams*)__pNewObj->Probe(Elastos::Security::Interfaces::EIID_IDSAParams);
        if (*__IDSAParams) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * q,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(p, q, g, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * q,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(p, q, g, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * q,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(p, q, g, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Spec {
class CDSAPrivateKeySpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Math::IBigInteger * x,
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * q,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDSAPrivateKeySpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDSAPrivateKeySpec, RGM_SAME_DOMAIN,
                EIID_ICDSAPrivateKeySpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithXPQG(x, p, q, g, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * x,
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * q,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ Elastos::Security::Spec::IDSAPrivateKeySpec** __IDSAPrivateKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(x, p, q, g, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDSAPrivateKeySpec = (Elastos::Security::Spec::IDSAPrivateKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IDSAPrivateKeySpec);
        if (*__IDSAPrivateKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * x,
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * q,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ Elastos::Security::Spec::IKeySpec** __IKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(x, p, q, g, &__pNewObj);
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
        /* [in] */ Elastos::Math::IBigInteger * q,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(x, p, q, g, &__pNewObj);
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
        /* [in] */ Elastos::Math::IBigInteger * q,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(x, p, q, g, &__pNewObj);
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
        /* [in] */ Elastos::Math::IBigInteger * q,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(x, p, q, g, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Spec {
class CDSAPublicKeySpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Math::IBigInteger * y,
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * q,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDSAPublicKeySpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDSAPublicKeySpec, RGM_SAME_DOMAIN,
                EIID_ICDSAPublicKeySpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithYPQG(y, p, q, g, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * y,
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * q,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ Elastos::Security::Spec::IDSAPublicKeySpec** __IDSAPublicKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(y, p, q, g, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDSAPublicKeySpec = (Elastos::Security::Spec::IDSAPublicKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IDSAPublicKeySpec);
        if (*__IDSAPublicKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * y,
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [in] */ Elastos::Math::IBigInteger * q,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ Elastos::Security::Spec::IKeySpec** __IKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(y, p, q, g, &__pNewObj);
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
        /* [in] */ Elastos::Math::IBigInteger * q,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(y, p, q, g, &__pNewObj);
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
        /* [in] */ Elastos::Math::IBigInteger * q,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(y, p, q, g, &__pNewObj);
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
        /* [in] */ Elastos::Math::IBigInteger * q,
        /* [in] */ Elastos::Math::IBigInteger * g,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(y, p, q, g, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Spec {
class CECFieldF2m
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 m,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICECFieldF2mClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CECFieldF2m, RGM_SAME_DOMAIN,
                EIID_ICECFieldF2mClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithM(m, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 m,
        /* [in] */ Elastos::Math::IBigInteger * rp,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICECFieldF2mClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CECFieldF2m, RGM_SAME_DOMAIN,
                EIID_ICECFieldF2mClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithMRp(m, rp, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 m,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * ks,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICECFieldF2mClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CECFieldF2m, RGM_SAME_DOMAIN,
                EIID_ICECFieldF2mClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithMKs(m, ks, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 m,
        /* [out] */ Elastos::Security::Spec::IECFieldF2m** __IECFieldF2m)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(m, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IECFieldF2m = (Elastos::Security::Spec::IECFieldF2m*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IECFieldF2m);
        if (*__IECFieldF2m) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 m,
        /* [out] */ Elastos::Security::Spec::IECField** __IECField)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(m, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IECField = (Elastos::Security::Spec::IECField*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IECField);
        if (*__IECField) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 m,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(m, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 m,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(m, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 m,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(m, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 m,
        /* [in] */ Elastos::Math::IBigInteger * rp,
        /* [out] */ Elastos::Security::Spec::IECFieldF2m** __IECFieldF2m)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(m, rp, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IECFieldF2m = (Elastos::Security::Spec::IECFieldF2m*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IECFieldF2m);
        if (*__IECFieldF2m) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 m,
        /* [in] */ Elastos::Math::IBigInteger * rp,
        /* [out] */ Elastos::Security::Spec::IECField** __IECField)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(m, rp, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IECField = (Elastos::Security::Spec::IECField*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IECField);
        if (*__IECField) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 m,
        /* [in] */ Elastos::Math::IBigInteger * rp,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(m, rp, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 m,
        /* [in] */ Elastos::Math::IBigInteger * rp,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(m, rp, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 m,
        /* [in] */ Elastos::Math::IBigInteger * rp,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(m, rp, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 m,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * ks,
        /* [out] */ Elastos::Security::Spec::IECFieldF2m** __IECFieldF2m)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(m, ks, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IECFieldF2m = (Elastos::Security::Spec::IECFieldF2m*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IECFieldF2m);
        if (*__IECFieldF2m) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 m,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * ks,
        /* [out] */ Elastos::Security::Spec::IECField** __IECField)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(m, ks, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IECField = (Elastos::Security::Spec::IECField*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IECField);
        if (*__IECField) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 m,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * ks,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(m, ks, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 m,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * ks,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(m, ks, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 m,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * ks,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(m, ks, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Spec {
class CECFieldFp
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICECFieldFpClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CECFieldFp, RGM_SAME_DOMAIN,
                EIID_ICECFieldFpClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithP(p, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [out] */ Elastos::Security::Spec::IECFieldFp** __IECFieldFp)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(p, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IECFieldFp = (Elastos::Security::Spec::IECFieldFp*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IECFieldFp);
        if (*__IECFieldFp) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * p,
        /* [out] */ Elastos::Security::Spec::IECField** __IECField)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(p, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IECField = (Elastos::Security::Spec::IECField*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IECField);
        if (*__IECField) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * p,
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
        /* [in] */ Elastos::Math::IBigInteger * p,
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
        /* [in] */ Elastos::Math::IBigInteger * p,
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
namespace Elastos {
namespace Security {
namespace Spec {
class CECGenParameterSpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICECGenParameterSpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CECGenParameterSpec, RGM_SAME_DOMAIN,
                EIID_ICECGenParameterSpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithName(name, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Security::Spec::IECGenParameterSpec** __IECGenParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IECGenParameterSpec = (Elastos::Security::Spec::IECGenParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IECGenParameterSpec);
        if (*__IECGenParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec** __IAlgorithmParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAlgorithmParameterSpec = (Elastos::Security::Spec::IAlgorithmParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IAlgorithmParameterSpec);
        if (*__IAlgorithmParameterSpec) __pNewObj->AddRef();
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

};
}
}
}
namespace Elastos {
namespace Security {
namespace Spec {
class CECParameterSpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Security::Spec::IEllipticCurve * curve,
        /* [in] */ Elastos::Security::Spec::IECPoint * generator,
        /* [in] */ Elastos::Math::IBigInteger * order,
        /* [in] */ _ELASTOS Int32 cofactor,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICECParameterSpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CECParameterSpec, RGM_SAME_DOMAIN,
                EIID_ICECParameterSpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCurveGeneratorOrderCofactor(curve, generator, order, cofactor, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Spec::IEllipticCurve * curve,
        /* [in] */ Elastos::Security::Spec::IECPoint * generator,
        /* [in] */ Elastos::Math::IBigInteger * order,
        /* [in] */ _ELASTOS Int32 cofactor,
        /* [out] */ Elastos::Security::Spec::IECParameterSpec** __IECParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(curve, generator, order, cofactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IECParameterSpec = (Elastos::Security::Spec::IECParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IECParameterSpec);
        if (*__IECParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Spec::IEllipticCurve * curve,
        /* [in] */ Elastos::Security::Spec::IECPoint * generator,
        /* [in] */ Elastos::Math::IBigInteger * order,
        /* [in] */ _ELASTOS Int32 cofactor,
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec** __IAlgorithmParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(curve, generator, order, cofactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAlgorithmParameterSpec = (Elastos::Security::Spec::IAlgorithmParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IAlgorithmParameterSpec);
        if (*__IAlgorithmParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Spec::IEllipticCurve * curve,
        /* [in] */ Elastos::Security::Spec::IECPoint * generator,
        /* [in] */ Elastos::Math::IBigInteger * order,
        /* [in] */ _ELASTOS Int32 cofactor,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(curve, generator, order, cofactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Spec::IEllipticCurve * curve,
        /* [in] */ Elastos::Security::Spec::IECPoint * generator,
        /* [in] */ Elastos::Math::IBigInteger * order,
        /* [in] */ _ELASTOS Int32 cofactor,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(curve, generator, order, cofactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Spec::IEllipticCurve * curve,
        /* [in] */ Elastos::Security::Spec::IECPoint * generator,
        /* [in] */ Elastos::Math::IBigInteger * order,
        /* [in] */ _ELASTOS Int32 cofactor,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(curve, generator, order, cofactor, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Spec {
class CECPoint
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Math::IBigInteger * affineX,
        /* [in] */ Elastos::Math::IBigInteger * affineY,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICECPointClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CECPoint, RGM_SAME_DOMAIN,
                EIID_ICECPointClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithAffineXAffineY(affineX, affineY, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Security::Spec::IECPoint** __object)
    {
        return _CObject_CreateInstance(ECLSID_CECPoint, RGM_SAME_DOMAIN, Elastos::Security::Spec::EIID_IECPoint, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CECPoint, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CECPoint, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CECPoint, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * affineX,
        /* [in] */ Elastos::Math::IBigInteger * affineY,
        /* [out] */ Elastos::Security::Spec::IECPoint** __IECPoint)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(affineX, affineY, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IECPoint = (Elastos::Security::Spec::IECPoint*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IECPoint);
        if (*__IECPoint) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * affineX,
        /* [in] */ Elastos::Math::IBigInteger * affineY,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(affineX, affineY, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * affineX,
        /* [in] */ Elastos::Math::IBigInteger * affineY,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(affineX, affineY, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * affineX,
        /* [in] */ Elastos::Math::IBigInteger * affineY,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(affineX, affineY, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Spec {
class CECPrivateKeySpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Math::IBigInteger * s,
        /* [in] */ Elastos::Security::Spec::IECParameterSpec * params,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICECPrivateKeySpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CECPrivateKeySpec, RGM_SAME_DOMAIN,
                EIID_ICECPrivateKeySpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSParams(s, params, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * s,
        /* [in] */ Elastos::Security::Spec::IECParameterSpec * params,
        /* [out] */ Elastos::Security::Spec::IECPrivateKeySpec** __IECPrivateKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s, params, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IECPrivateKeySpec = (Elastos::Security::Spec::IECPrivateKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IECPrivateKeySpec);
        if (*__IECPrivateKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * s,
        /* [in] */ Elastos::Security::Spec::IECParameterSpec * params,
        /* [out] */ Elastos::Security::Spec::IKeySpec** __IKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s, params, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeySpec = (Elastos::Security::Spec::IKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IKeySpec);
        if (*__IKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * s,
        /* [in] */ Elastos::Security::Spec::IECParameterSpec * params,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s, params, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * s,
        /* [in] */ Elastos::Security::Spec::IECParameterSpec * params,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s, params, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * s,
        /* [in] */ Elastos::Security::Spec::IECParameterSpec * params,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s, params, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Spec {
class CECPublicKeySpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Security::Spec::IECPoint * w,
        /* [in] */ Elastos::Security::Spec::IECParameterSpec * params,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICECPublicKeySpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CECPublicKeySpec, RGM_SAME_DOMAIN,
                EIID_ICECPublicKeySpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithWParams(w, params, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Spec::IECPoint * w,
        /* [in] */ Elastos::Security::Spec::IECParameterSpec * params,
        /* [out] */ Elastos::Security::Spec::IECPublicKeySpec** __IECPublicKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(w, params, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IECPublicKeySpec = (Elastos::Security::Spec::IECPublicKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IECPublicKeySpec);
        if (*__IECPublicKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Spec::IECPoint * w,
        /* [in] */ Elastos::Security::Spec::IECParameterSpec * params,
        /* [out] */ Elastos::Security::Spec::IKeySpec** __IKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(w, params, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeySpec = (Elastos::Security::Spec::IKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IKeySpec);
        if (*__IKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Spec::IECPoint * w,
        /* [in] */ Elastos::Security::Spec::IECParameterSpec * params,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(w, params, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Spec::IECPoint * w,
        /* [in] */ Elastos::Security::Spec::IECParameterSpec * params,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(w, params, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Spec::IECPoint * w,
        /* [in] */ Elastos::Security::Spec::IECParameterSpec * params,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(w, params, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Spec {
class CEllipticCurve
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Security::Spec::IECField * field,
        /* [in] */ Elastos::Math::IBigInteger * a,
        /* [in] */ Elastos::Math::IBigInteger * b,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * seed,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICEllipticCurveClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CEllipticCurve, RGM_SAME_DOMAIN,
                EIID_ICEllipticCurveClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFieldABSeed(field, a, b, seed, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Security::Spec::IECField * field,
        /* [in] */ Elastos::Math::IBigInteger * a,
        /* [in] */ Elastos::Math::IBigInteger * b,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICEllipticCurveClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CEllipticCurve, RGM_SAME_DOMAIN,
                EIID_ICEllipticCurveClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFieldAB(field, a, b, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Spec::IECField * field,
        /* [in] */ Elastos::Math::IBigInteger * a,
        /* [in] */ Elastos::Math::IBigInteger * b,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * seed,
        /* [out] */ Elastos::Security::Spec::IEllipticCurve** __IEllipticCurve)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(field, a, b, seed, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IEllipticCurve = (Elastos::Security::Spec::IEllipticCurve*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IEllipticCurve);
        if (*__IEllipticCurve) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Spec::IECField * field,
        /* [in] */ Elastos::Math::IBigInteger * a,
        /* [in] */ Elastos::Math::IBigInteger * b,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * seed,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(field, a, b, seed, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Spec::IECField * field,
        /* [in] */ Elastos::Math::IBigInteger * a,
        /* [in] */ Elastos::Math::IBigInteger * b,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * seed,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(field, a, b, seed, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Spec::IECField * field,
        /* [in] */ Elastos::Math::IBigInteger * a,
        /* [in] */ Elastos::Math::IBigInteger * b,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * seed,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(field, a, b, seed, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Spec::IECField * field,
        /* [in] */ Elastos::Math::IBigInteger * a,
        /* [in] */ Elastos::Math::IBigInteger * b,
        /* [out] */ Elastos::Security::Spec::IEllipticCurve** __IEllipticCurve)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(field, a, b, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IEllipticCurve = (Elastos::Security::Spec::IEllipticCurve*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IEllipticCurve);
        if (*__IEllipticCurve) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Spec::IECField * field,
        /* [in] */ Elastos::Math::IBigInteger * a,
        /* [in] */ Elastos::Math::IBigInteger * b,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(field, a, b, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Spec::IECField * field,
        /* [in] */ Elastos::Math::IBigInteger * a,
        /* [in] */ Elastos::Math::IBigInteger * b,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(field, a, b, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Security::Spec::IECField * field,
        /* [in] */ Elastos::Math::IBigInteger * a,
        /* [in] */ Elastos::Math::IBigInteger * b,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(field, a, b, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Spec {
class CMGF1ParameterSpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& mdName,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICMGF1ParameterSpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CMGF1ParameterSpec, RGM_SAME_DOMAIN,
                EIID_ICMGF1ParameterSpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithMdName(mdName, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& mdName,
        /* [out] */ Elastos::Security::Spec::IMGF1ParameterSpec** __IMGF1ParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mdName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMGF1ParameterSpec = (Elastos::Security::Spec::IMGF1ParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IMGF1ParameterSpec);
        if (*__IMGF1ParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& mdName,
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec** __IAlgorithmParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mdName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAlgorithmParameterSpec = (Elastos::Security::Spec::IAlgorithmParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IAlgorithmParameterSpec);
        if (*__IAlgorithmParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& mdName,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mdName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& mdName,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mdName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& mdName,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mdName, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Spec {
class CPKCS8EncodedKeySpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encodedKey,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPKCS8EncodedKeySpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPKCS8EncodedKeySpec, RGM_SAME_DOMAIN,
                EIID_ICPKCS8EncodedKeySpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithEncodedKey(encodedKey, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encodedKey,
        /* [out] */ Elastos::Security::Spec::IPKCS8EncodedKeySpec** __IPKCS8EncodedKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(encodedKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPKCS8EncodedKeySpec = (Elastos::Security::Spec::IPKCS8EncodedKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IPKCS8EncodedKeySpec);
        if (*__IPKCS8EncodedKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encodedKey,
        /* [out] */ Elastos::Security::Spec::IEncodedKeySpec** __IEncodedKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(encodedKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IEncodedKeySpec = (Elastos::Security::Spec::IEncodedKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IEncodedKeySpec);
        if (*__IEncodedKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encodedKey,
        /* [out] */ Elastos::Security::Spec::IKeySpec** __IKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(encodedKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeySpec = (Elastos::Security::Spec::IKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IKeySpec);
        if (*__IKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encodedKey,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(encodedKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encodedKey,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(encodedKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encodedKey,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(encodedKey, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Spec {
class CPSSParameterSpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 saltLen,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPSSParameterSpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPSSParameterSpec, RGM_SAME_DOMAIN,
                EIID_ICPSSParameterSpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSaltLen(saltLen, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& mdName,
        /* [in] */ const _ELASTOS String& mgfName,
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * mgfSpec,
        /* [in] */ _ELASTOS Int32 saltLen,
        /* [in] */ _ELASTOS Int32 trailerField,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPSSParameterSpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPSSParameterSpec, RGM_SAME_DOMAIN,
                EIID_ICPSSParameterSpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithMdNameMgfNameMgfSpecSaltLenTrailerField(mdName, mgfName, mgfSpec, saltLen, trailerField, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 saltLen,
        /* [out] */ Elastos::Security::Spec::IPSSParameterSpec** __IPSSParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(saltLen, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPSSParameterSpec = (Elastos::Security::Spec::IPSSParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IPSSParameterSpec);
        if (*__IPSSParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 saltLen,
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec** __IAlgorithmParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(saltLen, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAlgorithmParameterSpec = (Elastos::Security::Spec::IAlgorithmParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IAlgorithmParameterSpec);
        if (*__IAlgorithmParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 saltLen,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(saltLen, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 saltLen,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(saltLen, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 saltLen,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(saltLen, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& mdName,
        /* [in] */ const _ELASTOS String& mgfName,
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * mgfSpec,
        /* [in] */ _ELASTOS Int32 saltLen,
        /* [in] */ _ELASTOS Int32 trailerField,
        /* [out] */ Elastos::Security::Spec::IPSSParameterSpec** __IPSSParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mdName, mgfName, mgfSpec, saltLen, trailerField, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPSSParameterSpec = (Elastos::Security::Spec::IPSSParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IPSSParameterSpec);
        if (*__IPSSParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& mdName,
        /* [in] */ const _ELASTOS String& mgfName,
        /* [in] */ Elastos::Security::Spec::IAlgorithmParameterSpec * mgfSpec,
        /* [in] */ _ELASTOS Int32 saltLen,
        /* [in] */ _ELASTOS Int32 trailerField,
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec** __IAlgorithmParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mdName, mgfName, mgfSpec, saltLen, trailerField, &__pNewObj);
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
        /* [in] */ _ELASTOS Int32 saltLen,
        /* [in] */ _ELASTOS Int32 trailerField,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mdName, mgfName, mgfSpec, saltLen, trailerField, &__pNewObj);
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
        /* [in] */ _ELASTOS Int32 saltLen,
        /* [in] */ _ELASTOS Int32 trailerField,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mdName, mgfName, mgfSpec, saltLen, trailerField, &__pNewObj);
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
        /* [in] */ _ELASTOS Int32 saltLen,
        /* [in] */ _ELASTOS Int32 trailerField,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mdName, mgfName, mgfSpec, saltLen, trailerField, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Spec {
class CRSAKeyGenParameterSpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 keysize,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICRSAKeyGenParameterSpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CRSAKeyGenParameterSpec, RGM_SAME_DOMAIN,
                EIID_ICRSAKeyGenParameterSpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithKeysizePublicExponent(keysize, publicExponent, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 keysize,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [out] */ Elastos::Security::Spec::IRSAKeyGenParameterSpec** __IRSAKeyGenParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keysize, publicExponent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRSAKeyGenParameterSpec = (Elastos::Security::Spec::IRSAKeyGenParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IRSAKeyGenParameterSpec);
        if (*__IRSAKeyGenParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 keysize,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [out] */ Elastos::Security::Spec::IAlgorithmParameterSpec** __IAlgorithmParameterSpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keysize, publicExponent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAlgorithmParameterSpec = (Elastos::Security::Spec::IAlgorithmParameterSpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IAlgorithmParameterSpec);
        if (*__IAlgorithmParameterSpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 keysize,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keysize, publicExponent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 keysize,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keysize, publicExponent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 keysize,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keysize, publicExponent, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Spec {
class CRSAMultiPrimePrivateCrtKeySpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [in] */ Elastos::Math::IBigInteger * privateExponent,
        /* [in] */ Elastos::Math::IBigInteger * primeP,
        /* [in] */ Elastos::Math::IBigInteger * primeQ,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentP,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentQ,
        /* [in] */ Elastos::Math::IBigInteger * crtCoefficient,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Spec::IRSAOtherPrimeInfo *> * otherPrimeInfo,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICRSAMultiPrimePrivateCrtKeySpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CRSAMultiPrimePrivateCrtKeySpec, RGM_SAME_DOMAIN,
                EIID_ICRSAMultiPrimePrivateCrtKeySpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithModulusPublicExponentPrivateExponentPrimePPrimeQPrimeExponentPPrimeExponentQCrtCoefficientOtherPrimeInfo(modulus, publicExponent, privateExponent, primeP, primeQ, primeExponentP, primeExponentQ, crtCoefficient, otherPrimeInfo, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [in] */ Elastos::Math::IBigInteger * privateExponent,
        /* [in] */ Elastos::Math::IBigInteger * primeP,
        /* [in] */ Elastos::Math::IBigInteger * primeQ,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentP,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentQ,
        /* [in] */ Elastos::Math::IBigInteger * crtCoefficient,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Spec::IRSAOtherPrimeInfo *> * otherPrimeInfo,
        /* [out] */ Elastos::Security::Spec::IRSAMultiPrimePrivateCrtKeySpec** __IRSAMultiPrimePrivateCrtKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(modulus, publicExponent, privateExponent, primeP, primeQ, primeExponentP, primeExponentQ, crtCoefficient, otherPrimeInfo, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRSAMultiPrimePrivateCrtKeySpec = (Elastos::Security::Spec::IRSAMultiPrimePrivateCrtKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IRSAMultiPrimePrivateCrtKeySpec);
        if (*__IRSAMultiPrimePrivateCrtKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [in] */ Elastos::Math::IBigInteger * privateExponent,
        /* [in] */ Elastos::Math::IBigInteger * primeP,
        /* [in] */ Elastos::Math::IBigInteger * primeQ,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentP,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentQ,
        /* [in] */ Elastos::Math::IBigInteger * crtCoefficient,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Spec::IRSAOtherPrimeInfo *> * otherPrimeInfo,
        /* [out] */ Elastos::Security::Spec::IRSAPrivateKeySpec** __IRSAPrivateKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(modulus, publicExponent, privateExponent, primeP, primeQ, primeExponentP, primeExponentQ, crtCoefficient, otherPrimeInfo, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRSAPrivateKeySpec = (Elastos::Security::Spec::IRSAPrivateKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IRSAPrivateKeySpec);
        if (*__IRSAPrivateKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [in] */ Elastos::Math::IBigInteger * privateExponent,
        /* [in] */ Elastos::Math::IBigInteger * primeP,
        /* [in] */ Elastos::Math::IBigInteger * primeQ,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentP,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentQ,
        /* [in] */ Elastos::Math::IBigInteger * crtCoefficient,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Spec::IRSAOtherPrimeInfo *> * otherPrimeInfo,
        /* [out] */ Elastos::Security::Spec::IKeySpec** __IKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(modulus, publicExponent, privateExponent, primeP, primeQ, primeExponentP, primeExponentQ, crtCoefficient, otherPrimeInfo, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeySpec = (Elastos::Security::Spec::IKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IKeySpec);
        if (*__IKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [in] */ Elastos::Math::IBigInteger * privateExponent,
        /* [in] */ Elastos::Math::IBigInteger * primeP,
        /* [in] */ Elastos::Math::IBigInteger * primeQ,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentP,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentQ,
        /* [in] */ Elastos::Math::IBigInteger * crtCoefficient,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Spec::IRSAOtherPrimeInfo *> * otherPrimeInfo,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(modulus, publicExponent, privateExponent, primeP, primeQ, primeExponentP, primeExponentQ, crtCoefficient, otherPrimeInfo, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [in] */ Elastos::Math::IBigInteger * privateExponent,
        /* [in] */ Elastos::Math::IBigInteger * primeP,
        /* [in] */ Elastos::Math::IBigInteger * primeQ,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentP,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentQ,
        /* [in] */ Elastos::Math::IBigInteger * crtCoefficient,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Spec::IRSAOtherPrimeInfo *> * otherPrimeInfo,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(modulus, publicExponent, privateExponent, primeP, primeQ, primeExponentP, primeExponentQ, crtCoefficient, otherPrimeInfo, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [in] */ Elastos::Math::IBigInteger * privateExponent,
        /* [in] */ Elastos::Math::IBigInteger * primeP,
        /* [in] */ Elastos::Math::IBigInteger * primeQ,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentP,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentQ,
        /* [in] */ Elastos::Math::IBigInteger * crtCoefficient,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Security::Spec::IRSAOtherPrimeInfo *> * otherPrimeInfo,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(modulus, publicExponent, privateExponent, primeP, primeQ, primeExponentP, primeExponentQ, crtCoefficient, otherPrimeInfo, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Spec {
class CRSAOtherPrimeInfo
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Math::IBigInteger * prime,
        /* [in] */ Elastos::Math::IBigInteger * primeExponent,
        /* [in] */ Elastos::Math::IBigInteger * crtCoefficient,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICRSAOtherPrimeInfoClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CRSAOtherPrimeInfo, RGM_SAME_DOMAIN,
                EIID_ICRSAOtherPrimeInfoClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPrimePrimeExponentCrtCoefficient(prime, primeExponent, crtCoefficient, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * prime,
        /* [in] */ Elastos::Math::IBigInteger * primeExponent,
        /* [in] */ Elastos::Math::IBigInteger * crtCoefficient,
        /* [out] */ Elastos::Security::Spec::IRSAOtherPrimeInfo** __IRSAOtherPrimeInfo)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(prime, primeExponent, crtCoefficient, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRSAOtherPrimeInfo = (Elastos::Security::Spec::IRSAOtherPrimeInfo*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IRSAOtherPrimeInfo);
        if (*__IRSAOtherPrimeInfo) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * prime,
        /* [in] */ Elastos::Math::IBigInteger * primeExponent,
        /* [in] */ Elastos::Math::IBigInteger * crtCoefficient,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(prime, primeExponent, crtCoefficient, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * prime,
        /* [in] */ Elastos::Math::IBigInteger * primeExponent,
        /* [in] */ Elastos::Math::IBigInteger * crtCoefficient,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(prime, primeExponent, crtCoefficient, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * prime,
        /* [in] */ Elastos::Math::IBigInteger * primeExponent,
        /* [in] */ Elastos::Math::IBigInteger * crtCoefficient,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(prime, primeExponent, crtCoefficient, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Spec {
class CRSAPrivateCrtKeySpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [in] */ Elastos::Math::IBigInteger * privateExponent,
        /* [in] */ Elastos::Math::IBigInteger * primeP,
        /* [in] */ Elastos::Math::IBigInteger * primeQ,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentP,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentQ,
        /* [in] */ Elastos::Math::IBigInteger * crtCoefficient,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICRSAPrivateCrtKeySpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CRSAPrivateCrtKeySpec, RGM_SAME_DOMAIN,
                EIID_ICRSAPrivateCrtKeySpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithModulusPublicExponentPrivateExponentPrimePPrimeQPrimeExponentPPrimeExponentQCrtCoefficient(modulus, publicExponent, privateExponent, primeP, primeQ, primeExponentP, primeExponentQ, crtCoefficient, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [in] */ Elastos::Math::IBigInteger * privateExponent,
        /* [in] */ Elastos::Math::IBigInteger * primeP,
        /* [in] */ Elastos::Math::IBigInteger * primeQ,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentP,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentQ,
        /* [in] */ Elastos::Math::IBigInteger * crtCoefficient,
        /* [out] */ Elastos::Security::Spec::IRSAPrivateCrtKeySpec** __IRSAPrivateCrtKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(modulus, publicExponent, privateExponent, primeP, primeQ, primeExponentP, primeExponentQ, crtCoefficient, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRSAPrivateCrtKeySpec = (Elastos::Security::Spec::IRSAPrivateCrtKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IRSAPrivateCrtKeySpec);
        if (*__IRSAPrivateCrtKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [in] */ Elastos::Math::IBigInteger * privateExponent,
        /* [in] */ Elastos::Math::IBigInteger * primeP,
        /* [in] */ Elastos::Math::IBigInteger * primeQ,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentP,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentQ,
        /* [in] */ Elastos::Math::IBigInteger * crtCoefficient,
        /* [out] */ Elastos::Security::Spec::IRSAPrivateKeySpec** __IRSAPrivateKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(modulus, publicExponent, privateExponent, primeP, primeQ, primeExponentP, primeExponentQ, crtCoefficient, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRSAPrivateKeySpec = (Elastos::Security::Spec::IRSAPrivateKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IRSAPrivateKeySpec);
        if (*__IRSAPrivateKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [in] */ Elastos::Math::IBigInteger * privateExponent,
        /* [in] */ Elastos::Math::IBigInteger * primeP,
        /* [in] */ Elastos::Math::IBigInteger * primeQ,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentP,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentQ,
        /* [in] */ Elastos::Math::IBigInteger * crtCoefficient,
        /* [out] */ Elastos::Security::Spec::IKeySpec** __IKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(modulus, publicExponent, privateExponent, primeP, primeQ, primeExponentP, primeExponentQ, crtCoefficient, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeySpec = (Elastos::Security::Spec::IKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IKeySpec);
        if (*__IKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [in] */ Elastos::Math::IBigInteger * privateExponent,
        /* [in] */ Elastos::Math::IBigInteger * primeP,
        /* [in] */ Elastos::Math::IBigInteger * primeQ,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentP,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentQ,
        /* [in] */ Elastos::Math::IBigInteger * crtCoefficient,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(modulus, publicExponent, privateExponent, primeP, primeQ, primeExponentP, primeExponentQ, crtCoefficient, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [in] */ Elastos::Math::IBigInteger * privateExponent,
        /* [in] */ Elastos::Math::IBigInteger * primeP,
        /* [in] */ Elastos::Math::IBigInteger * primeQ,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentP,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentQ,
        /* [in] */ Elastos::Math::IBigInteger * crtCoefficient,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(modulus, publicExponent, privateExponent, primeP, primeQ, primeExponentP, primeExponentQ, crtCoefficient, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [in] */ Elastos::Math::IBigInteger * privateExponent,
        /* [in] */ Elastos::Math::IBigInteger * primeP,
        /* [in] */ Elastos::Math::IBigInteger * primeQ,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentP,
        /* [in] */ Elastos::Math::IBigInteger * primeExponentQ,
        /* [in] */ Elastos::Math::IBigInteger * crtCoefficient,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(modulus, publicExponent, privateExponent, primeP, primeQ, primeExponentP, primeExponentQ, crtCoefficient, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Spec {
class CRSAPrivateKeySpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * privateExponent,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICRSAPrivateKeySpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CRSAPrivateKeySpec, RGM_SAME_DOMAIN,
                EIID_ICRSAPrivateKeySpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithModulusPrivateExponent(modulus, privateExponent, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * privateExponent,
        /* [out] */ Elastos::Security::Spec::IRSAPrivateKeySpec** __IRSAPrivateKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(modulus, privateExponent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRSAPrivateKeySpec = (Elastos::Security::Spec::IRSAPrivateKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IRSAPrivateKeySpec);
        if (*__IRSAPrivateKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * privateExponent,
        /* [out] */ Elastos::Security::Spec::IKeySpec** __IKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(modulus, privateExponent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeySpec = (Elastos::Security::Spec::IKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IKeySpec);
        if (*__IKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * privateExponent,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(modulus, privateExponent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * privateExponent,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(modulus, privateExponent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * privateExponent,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(modulus, privateExponent, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Spec {
class CRSAPublicKeySpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICRSAPublicKeySpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CRSAPublicKeySpec, RGM_SAME_DOMAIN,
                EIID_ICRSAPublicKeySpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithModulusPublicExponent(modulus, publicExponent, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [out] */ Elastos::Security::Spec::IRSAPublicKeySpec** __IRSAPublicKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(modulus, publicExponent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRSAPublicKeySpec = (Elastos::Security::Spec::IRSAPublicKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IRSAPublicKeySpec);
        if (*__IRSAPublicKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [out] */ Elastos::Security::Spec::IKeySpec** __IKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(modulus, publicExponent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeySpec = (Elastos::Security::Spec::IKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IKeySpec);
        if (*__IKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(modulus, publicExponent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(modulus, publicExponent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * modulus,
        /* [in] */ Elastos::Math::IBigInteger * publicExponent,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(modulus, publicExponent, &__pNewObj);
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
namespace Elastos {
namespace Security {
namespace Spec {
class CX509EncodedKeySpec
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encodedKey,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICX509EncodedKeySpecClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CX509EncodedKeySpec, RGM_SAME_DOMAIN,
                EIID_ICX509EncodedKeySpecClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithEncodedKey(encodedKey, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encodedKey,
        /* [out] */ Elastos::Security::Spec::IX509EncodedKeySpec** __IX509EncodedKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(encodedKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IX509EncodedKeySpec = (Elastos::Security::Spec::IX509EncodedKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IX509EncodedKeySpec);
        if (*__IX509EncodedKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encodedKey,
        /* [out] */ Elastos::Security::Spec::IEncodedKeySpec** __IEncodedKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(encodedKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IEncodedKeySpec = (Elastos::Security::Spec::IEncodedKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IEncodedKeySpec);
        if (*__IEncodedKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encodedKey,
        /* [out] */ Elastos::Security::Spec::IKeySpec** __IKeySpec)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(encodedKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IKeySpec = (Elastos::Security::Spec::IKeySpec*)__pNewObj->Probe(Elastos::Security::Spec::EIID_IKeySpec);
        if (*__IKeySpec) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encodedKey,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(encodedKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encodedKey,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(encodedKey, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * encodedKey,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(encodedKey, &__pNewObj);
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

#endif // __Elastos_CoreLibrary_Security_h__
