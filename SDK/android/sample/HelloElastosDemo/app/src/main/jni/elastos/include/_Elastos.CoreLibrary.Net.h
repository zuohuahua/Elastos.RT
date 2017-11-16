#ifndef ___Elastos_CoreLibrary_Net_h__
#define ___Elastos_CoreLibrary_Net_h__

#include <Elastos.CoreLibrary.h>

EXTERN_C ELAPI _Impl_AcquireCallbackHandler(PInterface pServerObj, _ELASTOS REIID iid, PInterface *ppHandler);
EXTERN_C ELAPI _Impl_CheckClsId(PInterface pServerObj, const _ELASTOS ClassID* pClassid, PInterface *ppServerObj);

namespace Elastos {
namespace Net {
CAR_INTERFACE("B02BC252-0292-A11C-636C-7E74F5878392")
IAuthenticator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAuthenticator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAuthenticator*)pObj->Probe(EIID_IAuthenticator);
    }

    static CARAPI_(IAuthenticator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAuthenticator*)pObj->Probe(EIID_IAuthenticator);
    }

    virtual CARAPI GetPasswordAuthentication(
        /* [out] */ Elastos::Net::IPasswordAuthentication ** passwordAuthentication) = 0;

    virtual CARAPI GetRequestingPort(
        /* [out] */ _ELASTOS Int32 * port) = 0;

    virtual CARAPI GetRequestingSite(
        /* [out] */ Elastos::Net::IInetAddress ** address) = 0;

    virtual CARAPI GetRequestingPrompt(
        /* [out] */ _ELASTOS String * prompt) = 0;

    virtual CARAPI GetRequestingProtocol(
        /* [out] */ _ELASTOS String * protocol) = 0;

    virtual CARAPI GetRequestingScheme(
        /* [out] */ _ELASTOS String * scheme) = 0;

    virtual CARAPI GetRequestingHost(
        /* [out] */ _ELASTOS String * hostName) = 0;

    virtual CARAPI GetRequestingURL(
        /* [out] */ Elastos::Net::IURL ** url) = 0;

    virtual CARAPI GetRequestorType(
        /* [out] */ AuthenticatorRequestorType * requestorType) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("55FE825C-0292-A11C-636C-7E7435028A17")
IAuthenticatorHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAuthenticatorHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAuthenticatorHelper*)pObj->Probe(EIID_IAuthenticatorHelper);
    }

    static CARAPI_(IAuthenticatorHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAuthenticatorHelper*)pObj->Probe(EIID_IAuthenticatorHelper);
    }

    virtual CARAPI RequestPasswordAuthentication(
        /* [in] */ Elastos::Net::IInetAddress * rAddr,
        /* [in] */ _ELASTOS Int32 rPort,
        /* [in] */ const _ELASTOS String& rProtocol,
        /* [in] */ const _ELASTOS String& rPrompt,
        /* [in] */ const _ELASTOS String& rScheme,
        /* [out] */ Elastos::Net::IPasswordAuthentication ** passwordAuthentication) = 0;

    virtual CARAPI RequestPasswordAuthentication(
        /* [in] */ const _ELASTOS String& rHost,
        /* [in] */ Elastos::Net::IInetAddress * rAddr,
        /* [in] */ _ELASTOS Int32 rPort,
        /* [in] */ const _ELASTOS String& rProtocol,
        /* [in] */ const _ELASTOS String& rPrompt,
        /* [in] */ const _ELASTOS String& rScheme,
        /* [out] */ Elastos::Net::IPasswordAuthentication ** passwordAuthentication) = 0;

    virtual CARAPI RequestPasswordAuthentication(
        /* [in] */ const _ELASTOS String& rHost,
        /* [in] */ Elastos::Net::IInetAddress * rAddr,
        /* [in] */ _ELASTOS Int32 rPort,
        /* [in] */ const _ELASTOS String& rProtocol,
        /* [in] */ const _ELASTOS String& rPrompt,
        /* [in] */ const _ELASTOS String& rScheme,
        /* [in] */ Elastos::Net::IURL * rURL,
        /* [in] */ AuthenticatorRequestorType reqType,
        /* [out] */ Elastos::Net::IPasswordAuthentication ** passwordAuthentication) = 0;

    virtual CARAPI SetDefault(
        /* [in] */ Elastos::Net::IAuthenticator * a) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("EACC2621-1C12-3FC1-DADB-B821C3C68F0B")
ICacheRequest : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICacheRequest*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICacheRequest*)pObj->Probe(EIID_ICacheRequest);
    }

    static CARAPI_(ICacheRequest*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICacheRequest*)pObj->Probe(EIID_ICacheRequest);
    }

    virtual CARAPI Abort() = 0;

    virtual CARAPI GetBody(
        /* [out] */ Elastos::IO::IOutputStream ** os) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("6CFE2C33-9C12-3FC2-DADB-B821C3C68F0B")
ICacheResponse : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICacheResponse*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICacheResponse*)pObj->Probe(EIID_ICacheResponse);
    }

    static CARAPI_(ICacheResponse*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICacheResponse*)pObj->Probe(EIID_ICacheResponse);
    }

    virtual CARAPI GetBody(
        /* [out] */ Elastos::IO::IInputStream ** is) = 0;

    virtual CARAPI GetHeaders(
        /* [out] */ Elastos::Utility::IMap ** headers) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("2562303E-0312-3119-6EA0-8871E3DC8FF6")
IContentHandler : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IContentHandler*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IContentHandler*)pObj->Probe(EIID_IContentHandler);
    }

    static CARAPI_(IContentHandler*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IContentHandler*)pObj->Probe(EIID_IContentHandler);
    }

    virtual CARAPI GetContent(
        /* [in] */ Elastos::Net::IURLConnection * uConn,
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI GetContent(
        /* [in] */ Elastos::Net::IURLConnection * uConn,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS InterfaceID> * types,
        /* [out] */ IInterface ** obj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("1F963734-0312-3119-6EA0-8871E31CB41F")
IContentHandlerFactory : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IContentHandlerFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IContentHandlerFactory*)pObj->Probe(EIID_IContentHandlerFactory);
    }

    static CARAPI_(IContentHandlerFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IContentHandlerFactory*)pObj->Probe(EIID_IContentHandlerFactory);
    }

    virtual CARAPI CreateContentHandler(
        /* [in] */ const _ELASTOS String& contentType,
        /* [out] */ Elastos::Net::IContentHandler ** handler) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("5853213E-0312-3219-5CB0-4071EE477B1B")
ICookieHandler : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICookieHandler*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICookieHandler*)pObj->Probe(EIID_ICookieHandler);
    }

    static CARAPI_(ICookieHandler*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICookieHandler*)pObj->Probe(EIID_ICookieHandler);
    }

    virtual CARAPI Get(
        /* [in] */ Elastos::Net::IURI * uri,
        /* [in] */ Elastos::Utility::IMap * requestHeaders,
        /* [out] */ Elastos::Utility::IMap ** cookiesMap) = 0;

    virtual CARAPI Put(
        /* [in] */ Elastos::Net::IURI * uri,
        /* [in] */ Elastos::Utility::IMap * requestHeaders) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("576F3522-0312-3219-5CB0-40712E028A17")
ICookieHandlerHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICookieHandlerHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICookieHandlerHelper*)pObj->Probe(EIID_ICookieHandlerHelper);
    }

    static CARAPI_(ICookieHandlerHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICookieHandlerHelper*)pObj->Probe(EIID_ICookieHandlerHelper);
    }

    virtual CARAPI GetDefault(
        /* [out] */ Elastos::Net::ICookieHandler ** handler) = 0;

    virtual CARAPI SetDefault(
        /* [in] */ Elastos::Net::ICookieHandler * handler) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("C5B9A927-7312-28D9-48C0-38F7A3BD8D1B")
IURLStreamHandler : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IURLStreamHandler*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IURLStreamHandler*)pObj->Probe(EIID_IURLStreamHandler);
    }

    static CARAPI_(IURLStreamHandler*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IURLStreamHandler*)pObj->Probe(EIID_IURLStreamHandler);
    }

    virtual CARAPI OpenConnection(
        /* [in] */ Elastos::Net::IURL * u,
        /* [out] */ Elastos::Net::IURLConnection ** urlConnection) = 0;

    virtual CARAPI OpenConnection(
        /* [in] */ Elastos::Net::IURL * u,
        /* [in] */ Elastos::Net::IProxy * proxy,
        /* [out] */ Elastos::Net::IURLConnection ** urlConnection) = 0;

    virtual CARAPI ParseURL(
        /* [in] */ Elastos::Net::IURL * u,
        /* [in] */ const _ELASTOS String& str,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end) = 0;

    virtual CARAPI SetURL(
        /* [in] */ Elastos::Net::IURL * u,
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& file,
        /* [in] */ const _ELASTOS String& ref) = 0;

    virtual CARAPI SetURL(
        /* [in] */ Elastos::Net::IURL * u,
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& authority,
        /* [in] */ const _ELASTOS String& userInfo,
        /* [in] */ const _ELASTOS String& file,
        /* [in] */ const _ELASTOS String& query,
        /* [in] */ const _ELASTOS String& ref) = 0;

    virtual CARAPI ToExternalForm(
        /* [in] */ Elastos::Net::IURL * url,
        /* [out] */ _ELASTOS String * s) = 0;

    virtual CARAPI ToExternalForm(
        /* [in] */ Elastos::Net::IURL * url,
        /* [in] */ _ELASTOS Boolean escapeIllegalCharacters,
        /* [out] */ _ELASTOS String * s) = 0;

    virtual CARAPI Equals(
        /* [in] */ Elastos::Net::IURL * url1,
        /* [in] */ Elastos::Net::IURL * url2,
        /* [out] */ _ELASTOS Boolean * isEquals) = 0;

    virtual CARAPI GetDefaultPort(
        /* [out] */ _ELASTOS Int32 * portNum) = 0;

    virtual CARAPI GetHostAddress(
        /* [in] */ Elastos::Net::IURL * url,
        /* [out] */ Elastos::Net::IInetAddress ** hostAddress) = 0;

    virtual CARAPI GetHashCode(
        /* [in] */ Elastos::Net::IURL * url,
        /* [out] */ _ELASTOS Int32 * code) = 0;

    virtual CARAPI HostsEqual(
        /* [in] */ Elastos::Net::IURL * a,
        /* [in] */ Elastos::Net::IURL * b,
        /* [out] */ _ELASTOS Boolean * isEqual) = 0;

    virtual CARAPI SameFile(
        /* [in] */ Elastos::Net::IURL * url1,
        /* [in] */ Elastos::Net::IURL * url2,
        /* [out] */ _ELASTOS Boolean * isSame) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("65473B2C-7312-28D9-48C0-3807ED477B1B")
IURLStreamHandlerFactory : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IURLStreamHandlerFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IURLStreamHandlerFactory*)pObj->Probe(EIID_IURLStreamHandlerFactory);
    }

    static CARAPI_(IURLStreamHandlerFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IURLStreamHandlerFactory*)pObj->Probe(EIID_IURLStreamHandlerFactory);
    }

    virtual CARAPI CreateURLStreamHandler(
        /* [in] */ const _ELASTOS String& protocol,
        /* [out] */ Elastos::Net::IURLStreamHandler ** handler) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("3A49F10D-B792-BF49-F392-F62DDBFF85DE")
IURI : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IURI*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IURI*)pObj->Probe(EIID_IURI);
    }

    static CARAPI_(IURI*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IURI*)pObj->Probe(EIID_IURI);
    }

    virtual CARAPI GetScheme(
        /* [out] */ _ELASTOS String * scheme) = 0;

    virtual CARAPI GetSchemeSpecificPart(
        /* [out] */ _ELASTOS String * schemeSpecific) = 0;

    virtual CARAPI GetRawSchemeSpecificPart(
        /* [out] */ _ELASTOS String * schemeSpecific) = 0;

    virtual CARAPI GetAuthority(
        /* [out] */ _ELASTOS String * authority) = 0;

    virtual CARAPI GetRawAuthority(
        /* [out] */ _ELASTOS String * authority) = 0;

    virtual CARAPI GetUserInfo(
        /* [out] */ _ELASTOS String * userInfo) = 0;

    virtual CARAPI GetRawUserInfo(
        /* [out] */ _ELASTOS String * userInfo) = 0;

    virtual CARAPI GetHost(
        /* [out] */ _ELASTOS String * host) = 0;

    virtual CARAPI GetPort(
        /* [out] */ _ELASTOS Int32 * port) = 0;

    virtual CARAPI GetEffectivePort(
        /* [out] */ _ELASTOS Int32 * port) = 0;

    virtual CARAPI GetPath(
        /* [out] */ _ELASTOS String * path) = 0;

    virtual CARAPI GetRawPath(
        /* [out] */ _ELASTOS String * path) = 0;

    virtual CARAPI GetQuery(
        /* [out] */ _ELASTOS String * query) = 0;

    virtual CARAPI GetRawQuery(
        /* [out] */ _ELASTOS String * query) = 0;

    virtual CARAPI GetFragment(
        /* [out] */ _ELASTOS String * fragment) = 0;

    virtual CARAPI GetRawFragment(
        /* [out] */ _ELASTOS String * fragment) = 0;

    virtual CARAPI IsAbsolute(
        /* [out] */ _ELASTOS Boolean * isAbsolute) = 0;

    virtual CARAPI IsOpaque(
        /* [out] */ _ELASTOS Boolean * isOpaque) = 0;

    virtual CARAPI Normalize(
        /* [out] */ Elastos::Net::IURI ** uri) = 0;

    virtual CARAPI ParseServerAuthority(
        /* [out] */ Elastos::Net::IURI ** uri) = 0;

    virtual CARAPI Relativize(
        /* [in] */ Elastos::Net::IURI * relative,
        /* [out] */ Elastos::Net::IURI ** uri) = 0;

    virtual CARAPI Resolve(
        /* [in] */ Elastos::Net::IURI * relative,
        /* [out] */ Elastos::Net::IURI ** uri) = 0;

    virtual CARAPI Resolve(
        /* [in] */ const _ELASTOS String& relative,
        /* [out] */ Elastos::Net::IURI ** uri) = 0;

    virtual CARAPI ToASCIIString(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI ToURL(
        /* [out] */ Elastos::Net::IURL ** uri) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("021C2D1B-B792-1149-FACE-68FD3B2F69DF")
IURIHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IURIHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IURIHelper*)pObj->Probe(EIID_IURIHelper);
    }

    static CARAPI_(IURIHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IURIHelper*)pObj->Probe(EIID_IURIHelper);
    }

    virtual CARAPI Create(
        /* [in] */ const _ELASTOS String& uri,
        /* [out] */ Elastos::Net::IURI ** result) = 0;

    virtual CARAPI GetEffectivePort(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ _ELASTOS Int32 specifiedPort,
        /* [out] */ _ELASTOS Int32 * port) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("3299DA15-B792-BF55-F392-F62DDBFF85DE")
IURL : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IURL*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IURL*)pObj->Probe(EIID_IURL);
    }

    static CARAPI_(IURL*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IURL*)pObj->Probe(EIID_IURL);
    }

    virtual CARAPI SameFile(
        /* [in] */ Elastos::Net::IURL * otherURL,
        /* [out] */ _ELASTOS Boolean * isSame) = 0;

    virtual CARAPI GetContent(
        /* [out] */ IInterface ** content) = 0;

    virtual CARAPI OpenStream(
        /* [out] */ Elastos::IO::IInputStream ** is) = 0;

    virtual CARAPI OpenConnection(
        /* [out] */ Elastos::Net::IURLConnection ** connection) = 0;

    virtual CARAPI OpenConnection(
        /* [in] */ Elastos::Net::IProxy * proxy,
        /* [out] */ Elastos::Net::IURLConnection ** connection) = 0;

    virtual CARAPI ToURI(
        /* [out] */ Elastos::Net::IURI ** uri) = 0;

    virtual CARAPI ToURILenient(
        /* [out] */ Elastos::Net::IURI ** uri) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI ToExternalForm(
        /* [out] */ _ELASTOS String * url) = 0;

    virtual CARAPI GetEffectivePort(
        /* [out] */ _ELASTOS Int32 * port) = 0;

    virtual CARAPI GetProtocol(
        /* [out] */ _ELASTOS String * protocol) = 0;

    virtual CARAPI GetAuthority(
        /* [out] */ _ELASTOS String * authority) = 0;

    virtual CARAPI GetUserInfo(
        /* [out] */ _ELASTOS String * info) = 0;

    virtual CARAPI GetHost(
        /* [out] */ _ELASTOS String * hostName) = 0;

    virtual CARAPI GetPort(
        /* [out] */ _ELASTOS Int32 * port) = 0;

    virtual CARAPI GetDefaultPort(
        /* [out] */ _ELASTOS Int32 * port) = 0;

    virtual CARAPI GetFile(
        /* [out] */ _ELASTOS String * file) = 0;

    virtual CARAPI GetPath(
        /* [out] */ _ELASTOS String * path) = 0;

    virtual CARAPI GetQuery(
        /* [out] */ _ELASTOS String * query) = 0;

    virtual CARAPI GetRef(
        /* [out] */ _ELASTOS String * ref) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("2D75310A-B792-1155-FACE-68FD3B2F69DF")
IURLHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IURLHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IURLHelper*)pObj->Probe(EIID_IURLHelper);
    }

    static CARAPI_(IURLHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IURLHelper*)pObj->Probe(EIID_IURLHelper);
    }

    virtual CARAPI SetURLStreamHandlerFactory(
        /* [in] */ Elastos::Net::IURLStreamHandlerFactory * factory) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("F9873830-0312-3219-5CB0-40B1F2477B1B")
ICookieManager : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICookieManager*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICookieManager*)pObj->Probe(EIID_ICookieManager);
    }

    static CARAPI_(ICookieManager*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICookieManager*)pObj->Probe(EIID_ICookieManager);
    }

    virtual CARAPI SetCookiePolicy(
        /* [in] */ Elastos::Net::ICookiePolicy * cookiePolicy) = 0;

    virtual CARAPI GetCookieStore(
        /* [out] */ Elastos::Net::ICookieStore ** cookieStore) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("028F2625-0312-3219-5CB0-40F1F5477B1B")
ICookiePolicy : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICookiePolicy*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICookiePolicy*)pObj->Probe(EIID_ICookiePolicy);
    }

    static CARAPI_(ICookiePolicy*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICookiePolicy*)pObj->Probe(EIID_ICookiePolicy);
    }

    virtual CARAPI ShouldAccept(
        /* [in] */ Elastos::Net::IURI * uri,
        /* [in] */ Elastos::Net::IHttpCookie * cookie,
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("4CB62F12-2312-2ECB-8B66-F2CB9A7C84BE")
ICookiePolicyHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICookiePolicyHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICookiePolicyHelper*)pObj->Probe(EIID_ICookiePolicyHelper);
    }

    static CARAPI_(ICookiePolicyHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICookiePolicyHelper*)pObj->Probe(EIID_ICookiePolicyHelper);
    }

    virtual CARAPI GetCookiePolicy(
        /* [in] */ Elastos::Net::CookiePolicyKind kind,
        /* [out] */ Elastos::Net::ICookiePolicy ** policy) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("95863F44-1152-2E19-0C72-388DE2878392")
ICookieStore : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICookieStore*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICookieStore*)pObj->Probe(EIID_ICookieStore);
    }

    static CARAPI_(ICookieStore*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICookieStore*)pObj->Probe(EIID_ICookieStore);
    }

    virtual CARAPI Add(
        /* [in] */ Elastos::Net::IURI * uri,
        /* [in] */ Elastos::Net::IHttpCookie * cookie) = 0;

    virtual CARAPI Get(
        /* [in] */ Elastos::Net::IURI * uri,
        /* [out] */ Elastos::Utility::IList ** httpCookies) = 0;

    virtual CARAPI GetCookies(
        /* [out] */ Elastos::Utility::IList ** httpCookies) = 0;

    virtual CARAPI GetURIs(
        /* [out] */ Elastos::Utility::IList ** URIs) = 0;

    virtual CARAPI Remove(
        /* [in] */ Elastos::Net::IURI * uri,
        /* [in] */ Elastos::Net::IHttpCookie * cookie,
        /* [out] */ _ELASTOS Boolean * succeeded) = 0;

    virtual CARAPI RemoveAll(
        /* [out] */ _ELASTOS Boolean * succeeded) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("C010B458-0352-F246-6064-20B16ADA0F07")
IDatagramPacket : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDatagramPacket*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatagramPacket*)pObj->Probe(EIID_IDatagramPacket);
    }

    static CARAPI_(IDatagramPacket*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatagramPacket*)pObj->Probe(EIID_IDatagramPacket);
    }

    virtual CARAPI GetAddress(
        /* [out] */ Elastos::Net::IInetAddress ** address) = 0;

    virtual CARAPI GetData(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** data) = 0;

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int32 * length) = 0;

    virtual CARAPI GetOffset(
        /* [out] */ _ELASTOS Int32 * offset) = 0;

    virtual CARAPI GetPort(
        /* [out] */ _ELASTOS Int32 * port) = 0;

    virtual CARAPI SetAddress(
        /* [in] */ Elastos::Net::IInetAddress * addr) = 0;

    virtual CARAPI SetData(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buf) = 0;

    virtual CARAPI SetData(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buf,
        /* [in] */ _ELASTOS Int32 anOffset,
        /* [in] */ _ELASTOS Int32 aLength) = 0;

    virtual CARAPI SetLength(
        /* [in] */ _ELASTOS Int32 len) = 0;

    virtual CARAPI ResetLengthForReceive() = 0;

    virtual CARAPI SetPort(
        /* [in] */ _ELASTOS Int32 aPort) = 0;

    virtual CARAPI SetReceivedLength(
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI GetSocketAddress(
        /* [out] */ Elastos::Net::ISocketAddress ** sockAddr) = 0;

    virtual CARAPI SetSocketAddress(
        /* [in] */ Elastos::Net::ISocketAddress * sockAddr) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("61C7F939-2612-3515-48C0-28FDA3BD8D1B")
IDatagramSocket : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDatagramSocket*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatagramSocket*)pObj->Probe(EIID_IDatagramSocket);
    }

    static CARAPI_(IDatagramSocket*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatagramSocket*)pObj->Probe(EIID_IDatagramSocket);
    }

    virtual CARAPI Close() = 0;

    virtual CARAPI OnClose() = 0;

    virtual CARAPI Connect(
        /* [in] */ Elastos::Net::ISocketAddress * peer) = 0;

    virtual CARAPI Connect(
        /* [in] */ Elastos::Net::IInetAddress * address,
        /* [in] */ _ELASTOS Int32 aPort) = 0;

    virtual CARAPI OnConnect(
        /* [in] */ Elastos::Net::IInetAddress * remoteAddress,
        /* [in] */ _ELASTOS Int32 remotePort) = 0;

    virtual CARAPI Disconnect() = 0;

    virtual CARAPI OnDisconnect() = 0;

    virtual CARAPI GetInetAddress(
        /* [out] */ Elastos::Net::IInetAddress ** address) = 0;

    virtual CARAPI GetLocalAddress(
        /* [out] */ Elastos::Net::IInetAddress ** address) = 0;

    virtual CARAPI GetLocalPort(
        /* [out] */ _ELASTOS Int32 * port) = 0;

    virtual CARAPI GetPort(
        /* [out] */ _ELASTOS Int32 * port) = 0;

    virtual CARAPI GetReceiveBufferSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetSendBufferSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetSoTimeout(
        /* [out] */ _ELASTOS Int32 * timeout) = 0;

    virtual CARAPI Receive(
        /* [in] */ Elastos::Net::IDatagramPacket * pack) = 0;

    virtual CARAPI Send(
        /* [in] */ Elastos::Net::IDatagramPacket * pack) = 0;

    virtual CARAPI SetNetworkInterface(
        /* [in] */ Elastos::Net::INetworkInterface * netInterface) = 0;

    virtual CARAPI SetSendBufferSize(
        /* [in] */ _ELASTOS Int32 size) = 0;

    virtual CARAPI SetReceiveBufferSize(
        /* [in] */ _ELASTOS Int32 size) = 0;

    virtual CARAPI SetSoTimeout(
        /* [in] */ _ELASTOS Int32 timeout) = 0;

    virtual CARAPI Bind(
        /* [in] */ Elastos::Net::ISocketAddress * localAddr) = 0;

    virtual CARAPI OnBind(
        /* [in] */ Elastos::Net::IInetAddress * localAddress,
        /* [in] */ _ELASTOS Int32 localPort) = 0;

    virtual CARAPI IsBound(
        /* [out] */ _ELASTOS Boolean * isBound) = 0;

    virtual CARAPI IsConnected(
        /* [out] */ _ELASTOS Boolean * isConnected) = 0;

    virtual CARAPI GetRemoteSocketAddress(
        /* [out] */ Elastos::Net::ISocketAddress ** address) = 0;

    virtual CARAPI GetLocalSocketAddress(
        /* [out] */ Elastos::Net::ISocketAddress ** address) = 0;

    virtual CARAPI SetReuseAddress(
        /* [in] */ _ELASTOS Boolean reuse) = 0;

    virtual CARAPI GetReuseAddress(
        /* [out] */ _ELASTOS Boolean * reuse) = 0;

    virtual CARAPI SetBroadcast(
        /* [in] */ _ELASTOS Boolean broadcast) = 0;

    virtual CARAPI GetBroadcast(
        /* [out] */ _ELASTOS Boolean * broadcast) = 0;

    virtual CARAPI SetTrafficClass(
        /* [in] */ _ELASTOS Int32 value) = 0;

    virtual CARAPI GetTrafficClass(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI IsClosed(
        /* [out] */ _ELASTOS Boolean * isClosed) = 0;

    virtual CARAPI GetChannel(
        /* [out] */ Elastos::IO::Channels::IDatagramChannel ** channel) = 0;

    virtual CARAPI GetFileDescriptor(
        /* [out] */ Elastos::IO::IFileDescriptor ** fd) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("B6503E32-2612-3515-48C0-281D01C58B19")
IDatagramSocketHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDatagramSocketHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatagramSocketHelper*)pObj->Probe(EIID_IDatagramSocketHelper);
    }

    static CARAPI_(IDatagramSocketHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatagramSocketHelper*)pObj->Probe(EIID_IDatagramSocketHelper);
    }

    virtual CARAPI SetDatagramSocketImplFactory(
        /* [in] */ Elastos::Net::IDatagramSocketImplFactory * fac) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("E1A22D21-6952-36A7-7EB4-B77143868D1F")
ISocketOptions : public IInterface
{
    static const _ELASTOS Int32 _SO_LINGER = 128;
    static const _ELASTOS Int32 _SO_TIMEOUT = 4102;
    static const _ELASTOS Int32 _TCP_NODELAY = 1;
    static const _ELASTOS Int32 _IP_MULTICAST_IF = 16;
    static const _ELASTOS Int32 _SO_BINDADDR = 15;
    static const _ELASTOS Int32 _SO_REUSEADDR = 4;
    static const _ELASTOS Int32 _SO_SNDBUF = 4097;
    static const _ELASTOS Int32 _SO_RCVBUF = 4098;
    static const _ELASTOS Int32 _SO_KEEPALIVE = 8;
    static const _ELASTOS Int32 _IP_TOS = 3;
    static const _ELASTOS Int32 _IP_MULTICAST_LOOP = 18;
    static const _ELASTOS Int32 _SO_BROADCAST = 32;
    static const _ELASTOS Int32 _SO_OOBINLINE = 4099;
    static const _ELASTOS Int32 _IP_MULTICAST_IF2 = 31;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISocketOptions*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketOptions*)pObj->Probe(EIID_ISocketOptions);
    }

    static CARAPI_(ISocketOptions*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketOptions*)pObj->Probe(EIID_ISocketOptions);
    }

    virtual CARAPI GetOption(
        /* [in] */ _ELASTOS Int32 optID,
        /* [out] */ IInterface ** optVal) = 0;

    virtual CARAPI SetOption(
        /* [in] */ _ELASTOS Int32 optID,
        /* [in] */ IInterface * optVal) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("563DB63D-2612-3515-48C0-285DEF477B1B")
IDatagramSocketImpl : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDatagramSocketImpl*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatagramSocketImpl*)pObj->Probe(EIID_IDatagramSocketImpl);
    }

    static CARAPI_(IDatagramSocketImpl*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatagramSocketImpl*)pObj->Probe(EIID_IDatagramSocketImpl);
    }

    virtual CARAPI Bind(
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ Elastos::Net::IInetAddress * addr) = 0;

    virtual CARAPI Close() = 0;

    virtual CARAPI Create() = 0;

    virtual CARAPI GetFileDescriptor(
        /* [out] */ Elastos::IO::IFileDescriptor ** fd) = 0;

    virtual CARAPI GetLocalPort(
        /* [out] */ _ELASTOS Int32 * port) = 0;

    virtual CARAPI GetTTL(
        /* [out] */ _ELASTOS Byte * ttl) = 0;

    virtual CARAPI GetTimeToLive(
        /* [out] */ _ELASTOS Int32 * option) = 0;

    virtual CARAPI Join(
        /* [in] */ Elastos::Net::IInetAddress * addr) = 0;

    virtual CARAPI JoinGroup(
        /* [in] */ Elastos::Net::ISocketAddress * addr,
        /* [in] */ Elastos::Net::INetworkInterface * netInterface) = 0;

    virtual CARAPI Leave(
        /* [in] */ Elastos::Net::IInetAddress * addr) = 0;

    virtual CARAPI LeaveGroup(
        /* [in] */ Elastos::Net::ISocketAddress * addr,
        /* [in] */ Elastos::Net::INetworkInterface * netInterface) = 0;

    virtual CARAPI Peek(
        /* [in] */ Elastos::Net::IInetAddress * sender,
        /* [out] */ _ELASTOS Int32 * addr) = 0;

    virtual CARAPI Receive(
        /* [in] */ Elastos::Net::IDatagramPacket * pack) = 0;

    virtual CARAPI Send(
        /* [in] */ Elastos::Net::IDatagramPacket * pack) = 0;

    virtual CARAPI SetTimeToLive(
        /* [in] */ _ELASTOS Int32 ttl) = 0;

    virtual CARAPI SetTTL(
        /* [in] */ _ELASTOS Byte ttl) = 0;

    virtual CARAPI Connect(
        /* [in] */ Elastos::Net::IInetAddress * inetAddr,
        /* [in] */ _ELASTOS Int32 port) = 0;

    virtual CARAPI Disconnect() = 0;

    virtual CARAPI PeekData(
        /* [in] */ Elastos::Net::IDatagramPacket * pack,
        /* [out] */ _ELASTOS Int32 * port) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("E3C83F37-2612-3515-48C0-285D0FDA8FF6")
IDatagramSocketImplFactory : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDatagramSocketImplFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatagramSocketImplFactory*)pObj->Probe(EIID_IDatagramSocketImplFactory);
    }

    static CARAPI_(IDatagramSocketImplFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatagramSocketImplFactory*)pObj->Probe(EIID_IDatagramSocketImplFactory);
    }

    virtual CARAPI CreateDatagramSocketImpl(
        /* [out] */ Elastos::Net::IDatagramSocketImpl ** impl) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("554B213B-6152-3F38-DADB-B821C3C68F0B")
IResponseCache : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IResponseCache*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IResponseCache*)pObj->Probe(EIID_IResponseCache);
    }

    static CARAPI_(IResponseCache*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IResponseCache*)pObj->Probe(EIID_IResponseCache);
    }

    virtual CARAPI Get(
        /* [in] */ Elastos::Net::IURI * uri,
        /* [in] */ const _ELASTOS String& requestMethod,
        /* [in] */ Elastos::Utility::IMap * requestHeaders,
        /* [out] */ Elastos::Net::ICacheResponse ** cache) = 0;

    virtual CARAPI Put(
        /* [in] */ Elastos::Net::IURI * uri,
        /* [in] */ Elastos::Net::IURLConnection * conn,
        /* [out] */ Elastos::Net::ICacheRequest ** cache) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("5467352E-6152-1138-50BC-9871FF477B1B")
IResponseCacheHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IResponseCacheHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IResponseCacheHelper*)pObj->Probe(EIID_IResponseCacheHelper);
    }

    static CARAPI_(IResponseCacheHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IResponseCacheHelper*)pObj->Probe(EIID_IResponseCacheHelper);
    }

    virtual CARAPI GetDefault(
        /* [out] */ Elastos::Net::IResponseCache ** responseCache) = 0;

    virtual CARAPI SetDefault(
        /* [in] */ Elastos::Net::IResponseCache * responseCache) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("1479FC2B-7312-3F46-DADB-B821C3C68F0B")
IURLConnection : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IURLConnection*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IURLConnection*)pObj->Probe(EIID_IURLConnection);
    }

    static CARAPI_(IURLConnection*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IURLConnection*)pObj->Probe(EIID_IURLConnection);
    }

    virtual CARAPI Connect() = 0;

    virtual CARAPI GetAllowUserInteraction(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetContent(
        /* [out] */ IInterface ** content) = 0;

    virtual CARAPI GetContent(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS InterfaceID> * types,
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI GetContentEncoding(
        /* [out] */ _ELASTOS String * encoding) = 0;

    virtual CARAPI GetContentLength(
        /* [out] */ _ELASTOS Int32 * length) = 0;

    virtual CARAPI GetContentType(
        /* [out] */ _ELASTOS String * type) = 0;

    virtual CARAPI GetDate(
        /* [out] */ _ELASTOS Int64 * date) = 0;

    virtual CARAPI GetDefaultUseCaches(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetDoInput(
        /* [out] */ _ELASTOS Boolean * allowed) = 0;

    virtual CARAPI GetDoOutput(
        /* [out] */ _ELASTOS Boolean * allowed) = 0;

    virtual CARAPI GetExpiration(
        /* [out] */ _ELASTOS Int64 * expiration) = 0;

    virtual CARAPI GetHeaderField(
        /* [in] */ _ELASTOS Int32 pos,
        /* [out] */ _ELASTOS String * value) = 0;

    virtual CARAPI GetHeaderFields(
        /* [out] */ Elastos::Utility::IMap ** headerFields) = 0;

    virtual CARAPI GetRequestProperties(
        /* [out] */ Elastos::Utility::IMap ** properties) = 0;

    virtual CARAPI AddRequestProperty(
        /* [in] */ const _ELASTOS String& field,
        /* [in] */ const _ELASTOS String& newValue) = 0;

    virtual CARAPI GetHeaderField(
        /* [in] */ const _ELASTOS String& key,
        /* [out] */ _ELASTOS String * value) = 0;

    virtual CARAPI GetHeaderFieldDate(
        /* [in] */ const _ELASTOS String& field,
        /* [in] */ _ELASTOS Int64 defaultValue,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI GetHeaderFieldInt32(
        /* [in] */ const _ELASTOS String& field,
        /* [in] */ _ELASTOS Int32 defaultValue,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetHeaderFieldKey(
        /* [in] */ _ELASTOS Int32 posn,
        /* [out] */ _ELASTOS String * key) = 0;

    virtual CARAPI GetIfModifiedSince(
        /* [out] */ _ELASTOS Int64 * time) = 0;

    virtual CARAPI GetInputStream(
        /* [out] */ Elastos::IO::IInputStream ** is) = 0;

    virtual CARAPI GetLastModified(
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI GetOutputStream(
        /* [out] */ Elastos::IO::IOutputStream ** os) = 0;

    virtual CARAPI GetPermission(
        /* [out] */ Elastos::Security::IPermission ** perm) = 0;

    virtual CARAPI GetRequestProperty(
        /* [in] */ const _ELASTOS String& field,
        /* [out] */ _ELASTOS String * property) = 0;

    virtual CARAPI GetURL(
        /* [out] */ Elastos::Net::IURL ** url) = 0;

    virtual CARAPI GetUseCaches(
        /* [out] */ _ELASTOS Boolean * allowed) = 0;

    virtual CARAPI SetAllowUserInteraction(
        /* [in] */ _ELASTOS Boolean newValue) = 0;

    virtual CARAPI SetDefaultUseCaches(
        /* [in] */ _ELASTOS Boolean newValue) = 0;

    virtual CARAPI SetDoInput(
        /* [in] */ _ELASTOS Boolean newValue) = 0;

    virtual CARAPI SetDoOutput(
        /* [in] */ _ELASTOS Boolean newValue) = 0;

    virtual CARAPI SetIfModifiedSince(
        /* [in] */ _ELASTOS Int64 newValue) = 0;

    virtual CARAPI SetRequestProperty(
        /* [in] */ const _ELASTOS String& field,
        /* [in] */ const _ELASTOS String& newValue) = 0;

    virtual CARAPI SetUseCaches(
        /* [in] */ _ELASTOS Boolean newValue) = 0;

    virtual CARAPI SetConnectTimeout(
        /* [in] */ _ELASTOS Int32 timeout) = 0;

    virtual CARAPI GetConnectTimeout(
        /* [out] */ _ELASTOS Int32 * timeout) = 0;

    virtual CARAPI SetReadTimeout(
        /* [in] */ _ELASTOS Int32 timeout) = 0;

    virtual CARAPI GetReadTimeout(
        /* [out] */ _ELASTOS Int32 * timeout) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("7D1FF539-7312-1146-50BC-9871FF477B1B")
IURLConnectionHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IURLConnectionHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IURLConnectionHelper*)pObj->Probe(EIID_IURLConnectionHelper);
    }

    static CARAPI_(IURLConnectionHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IURLConnectionHelper*)pObj->Probe(EIID_IURLConnectionHelper);
    }

    virtual CARAPI GetDefaultAllowUserInteraction(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetDefaultRequestProperty(
        /* [in] */ const _ELASTOS String& field,
        /* [out] */ _ELASTOS String * value) = 0;

    virtual CARAPI GetFileNameMap(
        /* [out] */ Elastos::Net::IFileNameMap ** nameMap) = 0;

    virtual CARAPI GuessContentTypeFromName(
        /* [in] */ const _ELASTOS String& url,
        /* [out] */ _ELASTOS String * type) = 0;

    virtual CARAPI GuessContentTypeFromStream(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ _ELASTOS String * type) = 0;

    virtual CARAPI SetContentHandlerFactory(
        /* [in] */ Elastos::Net::IContentHandlerFactory * contentFactory) = 0;

    virtual CARAPI SetDefaultAllowUserInteraction(
        /* [in] */ _ELASTOS Boolean allows) = 0;

    virtual CARAPI SetDefaultRequestProperty(
        /* [in] */ const _ELASTOS String& field,
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI SetFileNameMap(
        /* [in] */ Elastos::Net::IFileNameMap * map) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("53CEEC35-8452-371B-6630-67F4A3BD8D1B")
IHttpURLConnection : public IInterface
{
    static const _ELASTOS Int32 HTTP_ACCEPTED = 202;
    static const _ELASTOS Int32 HTTP_BAD_GATEWAY = 502;
    static const _ELASTOS Int32 HTTP_BAD_METHOD = 405;
    static const _ELASTOS Int32 HTTP_BAD_REQUEST = 400;
    static const _ELASTOS Int32 HTTP_CLIENT_TIMEOUT = 408;
    static const _ELASTOS Int32 HTTP_CONFLICT = 409;
    static const _ELASTOS Int32 HTTP_CREATED = 201;
    static const _ELASTOS Int32 HTTP_ENTITY_TOO_LARGE = 413;
    static const _ELASTOS Int32 HTTP_FORBIDDEN = 403;
    static const _ELASTOS Int32 HTTP_GATEWAY_TIMEOUT = 504;
    static const _ELASTOS Int32 HTTP_GONE = 410;
    static const _ELASTOS Int32 HTTP_INTERNAL_ERROR = 500;
    static const _ELASTOS Int32 HTTP_LENGTH_REQUIRED = 411;
    static const _ELASTOS Int32 HTTP_MOVED_PERM = 301;
    static const _ELASTOS Int32 HTTP_MOVED_TEMP = 302;
    static const _ELASTOS Int32 HTTP_MULT_CHOICE = 300;
    static const _ELASTOS Int32 HTTP_NO_CONTENT = 204;
    static const _ELASTOS Int32 HTTP_NOT_ACCEPTABLE = 406;
    static const _ELASTOS Int32 HTTP_NOT_AUTHORITATIVE = 203;
    static const _ELASTOS Int32 HTTP_NOT_FOUND = 404;
    static const _ELASTOS Int32 HTTP_NOT_IMPLEMENTED = 501;
    static const _ELASTOS Int32 HTTP_NOT_MODIFIED = 304;
    static const _ELASTOS Int32 HTTP_OK = 200;
    static const _ELASTOS Int32 HTTP_PARTIAL = 206;
    static const _ELASTOS Int32 HTTP_PAYMENT_REQUIRED = 402;
    static const _ELASTOS Int32 HTTP_PRECON_FAILED = 412;
    static const _ELASTOS Int32 HTTP_PROXY_AUTH = 407;
    static const _ELASTOS Int32 HTTP_REQ_TOO_LONG = 414;
    static const _ELASTOS Int32 HTTP_RESET = 205;
    static const _ELASTOS Int32 HTTP_SEE_OTHER = 303;
    static const _ELASTOS Int32 HTTP_SERVER_ERROR = 500;
    static const _ELASTOS Int32 HTTP_USE_PROXY = 305;
    static const _ELASTOS Int32 HTTP_UNAUTHORIZED = 401;
    static const _ELASTOS Int32 HTTP_UNSUPPORTED_TYPE = 415;
    static const _ELASTOS Int32 HTTP_UNAVAILABLE = 503;
    static const _ELASTOS Int32 HTTP_VERSION = 505;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IHttpURLConnection*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHttpURLConnection*)pObj->Probe(EIID_IHttpURLConnection);
    }

    static CARAPI_(IHttpURLConnection*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHttpURLConnection*)pObj->Probe(EIID_IHttpURLConnection);
    }

    virtual CARAPI Disconnect() = 0;

    virtual CARAPI GetErrorStream(
        /* [out] */ Elastos::IO::IInputStream ** stream) = 0;

    virtual CARAPI GetRequestMethod(
        /* [out] */ _ELASTOS String * method) = 0;

    virtual CARAPI GetResponseCode(
        /* [out] */ _ELASTOS Int32 * responseCode) = 0;

    virtual CARAPI GetResponseMessage(
        /* [out] */ _ELASTOS String * message) = 0;

    virtual CARAPI SetRequestMethod(
        /* [in] */ const _ELASTOS String& method) = 0;

    virtual CARAPI UsingProxy(
        /* [out] */ _ELASTOS Boolean * usingProxy) = 0;

    virtual CARAPI GetInstanceFollowRedirects(
        /* [out] */ _ELASTOS Boolean * followRedirects) = 0;

    virtual CARAPI SetInstanceFollowRedirects(
        /* [in] */ _ELASTOS Boolean followRedirects) = 0;

    virtual CARAPI SetFixedLengthStreamingMode(
        /* [in] */ _ELASTOS Int64 contentLength) = 0;

    virtual CARAPI SetFixedLengthStreamingMode(
        /* [in] */ _ELASTOS Int32 contentLength) = 0;

    virtual CARAPI SetChunkedStreamingMode(
        /* [in] */ _ELASTOS Int32 chunkLength) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("018C492C-8452-371B-6630-671401C58B19")
IHttpURLConnectionHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IHttpURLConnectionHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHttpURLConnectionHelper*)pObj->Probe(EIID_IHttpURLConnectionHelper);
    }

    static CARAPI_(IHttpURLConnectionHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHttpURLConnectionHelper*)pObj->Probe(EIID_IHttpURLConnectionHelper);
    }

    virtual CARAPI GetFollowRedirects(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI SetFollowRedirects(
        /* [in] */ _ELASTOS Boolean autoValue) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("F73E2A24-B512-2DA0-7FB4-B77143868D1F")
IFileNameMap : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFileNameMap*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileNameMap*)pObj->Probe(EIID_IFileNameMap);
    }

    static CARAPI_(IFileNameMap*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileNameMap*)pObj->Probe(EIID_IFileNameMap);
    }

    virtual CARAPI GetContentTypeFor(
        /* [in] */ const _ELASTOS String& filename,
        /* [out] */ _ELASTOS String * type) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("982DED4E-0452-33D8-8AC8-7061F0878392")
IHttpCookie : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IHttpCookie*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHttpCookie*)pObj->Probe(EIID_IHttpCookie);
    }

    static CARAPI_(IHttpCookie*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHttpCookie*)pObj->Probe(EIID_IHttpCookie);
    }

    virtual CARAPI GetComment(
        /* [out] */ _ELASTOS String * comment) = 0;

    virtual CARAPI GetCommentURL(
        /* [out] */ _ELASTOS String * url) = 0;

    virtual CARAPI GetDiscard(
        /* [out] */ _ELASTOS Boolean * discard) = 0;

    virtual CARAPI GetDomainAttr(
        /* [out] */ _ELASTOS String * theDomain) = 0;

    virtual CARAPI GetMaxAge(
        /* [out] */ _ELASTOS Int64 * maxAge) = 0;

    virtual CARAPI GetName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetPath(
        /* [out] */ _ELASTOS String * path) = 0;

    virtual CARAPI GetPortList(
        /* [out] */ _ELASTOS String * portList) = 0;

    virtual CARAPI GetSecure(
        /* [out] */ _ELASTOS Boolean * secure) = 0;

    virtual CARAPI GetValue(
        /* [out] */ _ELASTOS String * value) = 0;

    virtual CARAPI GetVersion(
        /* [out] */ _ELASTOS Int32 * theVersion) = 0;

    virtual CARAPI HasExpired(
        /* [out] */ _ELASTOS Boolean * expired) = 0;

    virtual CARAPI SetComment(
        /* [in] */ const _ELASTOS String& comment) = 0;

    virtual CARAPI SetCommentURL(
        /* [in] */ const _ELASTOS String& commentURL) = 0;

    virtual CARAPI SetDiscard(
        /* [in] */ _ELASTOS Boolean discard) = 0;

    virtual CARAPI SetDomain(
        /* [in] */ const _ELASTOS String& pattern) = 0;

    virtual CARAPI SetMaxAge(
        /* [in] */ _ELASTOS Int64 deltaSeconds) = 0;

    virtual CARAPI SetPath(
        /* [in] */ const _ELASTOS String& path) = 0;

    virtual CARAPI SetPortList(
        /* [in] */ const _ELASTOS String& portList) = 0;

    virtual CARAPI SetSecure(
        /* [in] */ _ELASTOS Boolean secure) = 0;

    virtual CARAPI SetValue(
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI SetVersion(
        /* [in] */ _ELASTOS Int32 v) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("C6213216-7452-33DF-23CB-2E8B46E83BA3")
IHttpCookieHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IHttpCookieHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHttpCookieHelper*)pObj->Probe(EIID_IHttpCookieHelper);
    }

    static CARAPI_(IHttpCookieHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHttpCookieHelper*)pObj->Probe(EIID_IHttpCookieHelper);
    }

    virtual CARAPI IsDomainMatches(
        /* [in] */ const _ELASTOS String& domainPattern,
        /* [in] */ const _ELASTOS String& host,
        /* [out] */ _ELASTOS Boolean * match) = 0;

    virtual CARAPI Parse(
        /* [in] */ const _ELASTOS String& header,
        /* [out] */ Elastos::Utility::IList ** cookies) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("F6D93111-D492-BF5C-F392-F62DDBFF85DE")
IIDN : public IInterface
{
    static const _ELASTOS Int32 ALLOW_UNASSIGNED = 1;
    static const _ELASTOS Int32 USE_STD3_ASCII_RULES = 2;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IIDN*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IIDN*)pObj->Probe(EIID_IIDN);
    }

    static CARAPI_(IIDN*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IIDN*)pObj->Probe(EIID_IIDN);
    }

    virtual CARAPI ToASCII(
        /* [in] */ const _ELASTOS String& input,
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI ToASCII(
        /* [in] */ const _ELASTOS String& input,
        /* [in] */ _ELASTOS Int32 flags,
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI ToUnicode(
        /* [in] */ const _ELASTOS String& input,
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI ToUnicode(
        /* [in] */ const _ELASTOS String& input,
        /* [in] */ _ELASTOS Int32 flags,
        /* [out] */ _ELASTOS String * name) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("8D00F935-41D2-3714-88FC-686FE3860C1B")
IInetAddress : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInetAddress*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInetAddress*)pObj->Probe(EIID_IInetAddress);
    }

    static CARAPI_(IInetAddress*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInetAddress*)pObj->Probe(EIID_IInetAddress);
    }

    virtual CARAPI GetAddress(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** address) = 0;

    virtual CARAPI GetHostAddress(
        /* [out] */ _ELASTOS String * hostAddress) = 0;

    virtual CARAPI GetHostName(
        /* [out] */ _ELASTOS String * hostName) = 0;

    virtual CARAPI GetCanonicalHostName(
        /* [out] */ _ELASTOS String * hostName) = 0;

    virtual CARAPI GetFamily(
        /* [out] */ _ELASTOS Int32 * family) = 0;

    virtual CARAPI IsAnyLocalAddress(
        /* [out] */ _ELASTOS Boolean * isAnyLocalAddress) = 0;

    virtual CARAPI IsLinkLocalAddress(
        /* [out] */ _ELASTOS Boolean * isLinkLocalAddress) = 0;

    virtual CARAPI IsLoopbackAddress(
        /* [out] */ _ELASTOS Boolean * isLoopbackAddress) = 0;

    virtual CARAPI IsMCGlobal(
        /* [out] */ _ELASTOS Boolean * isMCGlobal) = 0;

    virtual CARAPI IsMCLinkLocal(
        /* [out] */ _ELASTOS Boolean * isMCLinkLocal) = 0;

    virtual CARAPI IsMCNodeLocal(
        /* [out] */ _ELASTOS Boolean * isMCNodeLocal) = 0;

    virtual CARAPI IsMCOrgLocal(
        /* [out] */ _ELASTOS Boolean * isMCOrgLocal) = 0;

    virtual CARAPI IsMCSiteLocal(
        /* [out] */ _ELASTOS Boolean * isMCSiteLocal) = 0;

    virtual CARAPI IsMulticastAddress(
        /* [out] */ _ELASTOS Boolean * isMulticastAddress) = 0;

    virtual CARAPI IsSiteLocalAddress(
        /* [out] */ _ELASTOS Boolean * isSiteLocalAddress) = 0;

    virtual CARAPI IsReachable(
        /* [in] */ _ELASTOS Int32 timeout,
        /* [out] */ _ELASTOS Boolean * isReachable) = 0;

    virtual CARAPI IsReachable(
        /* [in] */ Elastos::Net::INetworkInterface * networkInterface,
        /* [in] */ _ELASTOS Int32 ttl,
        /* [in] */ _ELASTOS Int32 timeout,
        /* [out] */ _ELASTOS Boolean * isReachable) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("4B27C035-41D2-3714-8844-40F162C6FD1F")
IInetAddressHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInetAddressHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInetAddressHelper*)pObj->Probe(EIID_IInetAddressHelper);
    }

    static CARAPI_(IInetAddressHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInetAddressHelper*)pObj->Probe(EIID_IInetAddressHelper);
    }

    virtual CARAPI GetUNSPECIFIED(
        /* [out] */ Elastos::Net::IInetAddress ** addr) = 0;

    virtual CARAPI GetAllByName(
        /* [in] */ const _ELASTOS String& host,
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Net::IInetAddress *> ** interAddress) = 0;

    virtual CARAPI GetAllByNameOnNet(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 netId,
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Net::IInetAddress *> ** addresses) = 0;

    virtual CARAPI GetByName(
        /* [in] */ const _ELASTOS String& host,
        /* [out] */ Elastos::Net::IInetAddress ** interAddr) = 0;

    virtual CARAPI GetByNameOnNet(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 netId,
        /* [out] */ Elastos::Net::IInetAddress ** address) = 0;

    virtual CARAPI GetLocalHost(
        /* [out] */ Elastos::Net::IInetAddress ** interAddr) = 0;

    virtual CARAPI ClearDnsCache() = 0;

    virtual CARAPI IsNumeric(
        /* [in] */ const _ELASTOS String& address,
        /* [out] */ _ELASTOS Boolean * isNumeric) = 0;

    virtual CARAPI ParseNumericAddress(
        /* [in] */ const _ELASTOS String& numericAddress,
        /* [out] */ Elastos::Net::IInetAddress ** interAddr) = 0;

    virtual CARAPI GetLoopbackAddress(
        /* [out] */ Elastos::Net::IInetAddress ** interAddr) = 0;

    virtual CARAPI GetByAddress(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * ipAddress,
        /* [out] */ Elastos::Net::IInetAddress ** interAddr) = 0;

    virtual CARAPI GetByAddress(
        /* [in] */ const _ELASTOS String& hostName,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * ipAddress,
        /* [out] */ Elastos::Net::IInetAddress ** interAddr) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("91041A28-41D2-3714-0810-F9D1DEC60D19")
IInet4Address : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInet4Address*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInet4Address*)pObj->Probe(EIID_IInet4Address);
    }

    static CARAPI_(IInet4Address*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInet4Address*)pObj->Probe(EIID_IInet4Address);
    }

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("B20D372C-41D2-3714-0810-8980E2C58CFB")
IInet4AddressHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInet4AddressHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInet4AddressHelper*)pObj->Probe(EIID_IInet4AddressHelper);
    }

    static CARAPI_(IInet4AddressHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInet4AddressHelper*)pObj->Probe(EIID_IInet4AddressHelper);
    }

    virtual CARAPI GetANY(
        /* [out] */ Elastos::Net::IInetAddress ** result) = 0;

    virtual CARAPI GetALL(
        /* [out] */ Elastos::Net::IInetAddress ** result) = 0;

    virtual CARAPI GetLOOPBACK(
        /* [out] */ Elastos::Net::IInetAddress ** result) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("479D4D30-41D2-3714-0C10-F9D1DEC60D19")
IInet6Address : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInet6Address*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInet6Address*)pObj->Probe(EIID_IInet6Address);
    }

    static CARAPI_(IInet6Address*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInet6Address*)pObj->Probe(EIID_IInet6Address);
    }

    virtual CARAPI GetScopeId(
        /* [out] */ _ELASTOS Int32 * scopeId) = 0;

    virtual CARAPI GetScopedInterface(
        /* [out] */ Elastos::Net::INetworkInterface ** scopedInterface) = 0;

    virtual CARAPI IsIPv4CompatibleAddress(
        /* [out] */ _ELASTOS Boolean * IPv4Compatible) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("56174925-41D2-3714-0C10-8980E2C58CFB")
IInet6AddressHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInet6AddressHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInet6AddressHelper*)pObj->Probe(EIID_IInet6AddressHelper);
    }

    static CARAPI_(IInet6AddressHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInet6AddressHelper*)pObj->Probe(EIID_IInet6AddressHelper);
    }

    virtual CARAPI GetByAddress(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * addr,
        /* [in] */ _ELASTOS Int32 scope_id,
        /* [out] */ Elastos::Net::IInet6Address ** address) = 0;

    virtual CARAPI GetByAddress(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * addr,
        /* [in] */ Elastos::Net::INetworkInterface * nif,
        /* [out] */ Elastos::Net::IInet6Address ** address) = 0;

    virtual CARAPI GetANY(
        /* [out] */ Elastos::Net::IInetAddress ** result) = 0;

    virtual CARAPI GetLOOPBACK(
        /* [out] */ Elastos::Net::IInetAddress ** result) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("E50A1B33-6952-3F22-DADB-B821C3C68F0B")
ISocketAddress : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISocketAddress*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketAddress*)pObj->Probe(EIID_ISocketAddress);
    }

    static CARAPI_(ISocketAddress*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketAddress*)pObj->Probe(EIID_ISocketAddress);
    }

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("0F6E6532-41D2-3714-4A13-F9D1DEC60D19")
IInetSocketAddress : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInetSocketAddress*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInetSocketAddress*)pObj->Probe(EIID_IInetSocketAddress);
    }

    static CARAPI_(IInetSocketAddress*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInetSocketAddress*)pObj->Probe(EIID_IInetSocketAddress);
    }

    virtual CARAPI GetPort(
        /* [out] */ _ELASTOS Int32 * port) = 0;

    virtual CARAPI SetPort(
        /* [in] */ _ELASTOS Int32 port) = 0;

    virtual CARAPI GetAddress(
        /* [out] */ Elastos::Net::IInetAddress ** address) = 0;

    virtual CARAPI SetAddress(
        /* [in] */ Elastos::Net::IInetAddress * address) = 0;

    virtual CARAPI GetHostName(
        /* [out] */ _ELASTOS String * hostname) = 0;

    virtual CARAPI GetHostString(
        /* [out] */ _ELASTOS String * hostString) = 0;

    virtual CARAPI IsUnresolved(
        /* [out] */ _ELASTOS Boolean * isUnresolved) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("8EEB3528-41D2-3714-4A13-8980E2C58CFB")
IInetSocketAddressHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInetSocketAddressHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInetSocketAddressHelper*)pObj->Probe(EIID_IInetSocketAddressHelper);
    }

    static CARAPI_(IInetSocketAddressHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInetSocketAddressHelper*)pObj->Probe(EIID_IInetSocketAddressHelper);
    }

    virtual CARAPI CreateUnresolved(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Net::IInetSocketAddress ** inetSocketAddress) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("BE834A3E-4092-3F22-DADB-B821C3C68F0B")
IInterfaceAddress : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInterfaceAddress*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInterfaceAddress*)pObj->Probe(EIID_IInterfaceAddress);
    }

    static CARAPI_(IInterfaceAddress*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInterfaceAddress*)pObj->Probe(EIID_IInterfaceAddress);
    }

    virtual CARAPI GetAddress(
        /* [out] */ Elastos::Net::IInetAddress ** address) = 0;

    virtual CARAPI GetBroadcast(
        /* [out] */ Elastos::Net::IInetAddress ** broadcast) = 0;

    virtual CARAPI GetNetworkPrefixLength(
        /* [out] */ _ELASTOS Int16 * length) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("5C07C943-8592-9BDC-1571-90B16ADA0F07")
IMulticastSocket : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMulticastSocket*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMulticastSocket*)pObj->Probe(EIID_IMulticastSocket);
    }

    static CARAPI_(IMulticastSocket*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMulticastSocket*)pObj->Probe(EIID_IMulticastSocket);
    }

    virtual CARAPI GetInterface(
        /* [out] */ Elastos::Net::IInetAddress ** address) = 0;

    virtual CARAPI GetNetworkInterface(
        /* [out] */ Elastos::Net::INetworkInterface ** networkInterface) = 0;

    virtual CARAPI GetTimeToLive(
        /* [out] */ _ELASTOS Int32 * ttl) = 0;

    virtual CARAPI GetTTL(
        /* [out] */ _ELASTOS Byte * ttl) = 0;

    virtual CARAPI JoinGroup(
        /* [in] */ Elastos::Net::IInetAddress * groupAddr) = 0;

    virtual CARAPI JoinGroup(
        /* [in] */ Elastos::Net::ISocketAddress * groupAddress,
        /* [in] */ Elastos::Net::INetworkInterface * netInterface) = 0;

    virtual CARAPI LeaveGroup(
        /* [in] */ Elastos::Net::IInetAddress * groupAddr) = 0;

    virtual CARAPI LeaveGroup(
        /* [in] */ Elastos::Net::ISocketAddress * groupAddress,
        /* [in] */ Elastos::Net::INetworkInterface * netInterface) = 0;

    virtual CARAPI Send(
        /* [in] */ Elastos::Net::IDatagramPacket * pack,
        /* [in] */ _ELASTOS Byte ttl) = 0;

    virtual CARAPI SetInterface(
        /* [in] */ Elastos::Net::IInetAddress * addr) = 0;

    virtual CARAPI SetNetworkInterface(
        /* [in] */ Elastos::Net::INetworkInterface * ni) = 0;

    virtual CARAPI SetTimeToLive(
        /* [in] */ _ELASTOS Int32 ttl) = 0;

    virtual CARAPI SetTTL(
        /* [in] */ _ELASTOS Byte ttl) = 0;

    virtual CARAPI GetLoopbackMode(
        /* [out] */ _ELASTOS Boolean * isDisabled) = 0;

    virtual CARAPI SetLoopbackMode(
        /* [in] */ _ELASTOS Boolean isDisabled) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("9889D536-05D2-3714-74E4-7721F0477B1B")
INetworkInterface : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INetworkInterface*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INetworkInterface*)pObj->Probe(EIID_INetworkInterface);
    }

    static CARAPI_(INetworkInterface*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INetworkInterface*)pObj->Probe(EIID_INetworkInterface);
    }

    virtual CARAPI GetIndex(
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetInetAddresses(
        /* [out] */ Elastos::Utility::IEnumeration ** addresses) = 0;

    virtual CARAPI GetDisplayName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * obj,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetInterfaceAddresses(
        /* [out] */ Elastos::Utility::IList ** addresses) = 0;

    virtual CARAPI GetSubInterfaces(
        /* [out] */ Elastos::Utility::IEnumeration ** subInterfaces) = 0;

    virtual CARAPI GetParent(
        /* [out] */ Elastos::Net::INetworkInterface ** parent) = 0;

    virtual CARAPI IsUp(
        /* [out] */ _ELASTOS Boolean * isUp) = 0;

    virtual CARAPI IsLoopback(
        /* [out] */ _ELASTOS Boolean * isLoopback) = 0;

    virtual CARAPI IsPointToPoint(
        /* [out] */ _ELASTOS Boolean * isPointToPoint) = 0;

    virtual CARAPI SupportsMulticast(
        /* [out] */ _ELASTOS Boolean * multicast) = 0;

    virtual CARAPI GetHardwareAddress(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** address) = 0;

    virtual CARAPI GetMTU(
        /* [out] */ _ELASTOS Int32 * mtu) = 0;

    virtual CARAPI IsVirtual(
        /* [out] */ _ELASTOS Boolean * isVirtual) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("25975B35-05D2-3714-74E4-772130028A17")
INetworkInterfaceHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INetworkInterfaceHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INetworkInterfaceHelper*)pObj->Probe(EIID_INetworkInterfaceHelper);
    }

    static CARAPI_(INetworkInterfaceHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INetworkInterfaceHelper*)pObj->Probe(EIID_INetworkInterfaceHelper);
    }

    virtual CARAPI GetByName(
        /* [in] */ const _ELASTOS String& interfaceName,
        /* [out] */ Elastos::Net::INetworkInterface ** networkInterface) = 0;

    virtual CARAPI GetByInetAddress(
        /* [in] */ Elastos::Net::IInetAddress * address,
        /* [out] */ Elastos::Net::INetworkInterface ** networkInterface) = 0;

    virtual CARAPI GetByIndex(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ Elastos::Net::INetworkInterface ** networkInterface) = 0;

    virtual CARAPI GetNetworkInterfaces(
        /* [out] */ Elastos::Utility::IEnumeration ** networkInterfaceList) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("BE8D3A1D-4652-B6DA-2ED7-A782DF2B1ADF")
IPasswordAuthentication : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPasswordAuthentication*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPasswordAuthentication*)pObj->Probe(EIID_IPasswordAuthentication);
    }

    static CARAPI_(IPasswordAuthentication*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPasswordAuthentication*)pObj->Probe(EIID_IPasswordAuthentication);
    }

    virtual CARAPI GetPassword(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Char32> ** password) = 0;

    virtual CARAPI GetUserName(
        /* [out] */ _ELASTOS String * userName) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("9476254A-0652-1293-1B30-920783838C55")
IPlainDatagramSocketImpl : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPlainDatagramSocketImpl*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPlainDatagramSocketImpl*)pObj->Probe(EIID_IPlainDatagramSocketImpl);
    }

    static CARAPI_(IPlainDatagramSocketImpl*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPlainDatagramSocketImpl*)pObj->Probe(EIID_IPlainDatagramSocketImpl);
    }

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("E5DDF42B-E952-3F7A-DADB-B821C3C68F0B")
ISocketImpl : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISocketImpl*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketImpl*)pObj->Probe(EIID_ISocketImpl);
    }

    static CARAPI_(ISocketImpl*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketImpl*)pObj->Probe(EIID_ISocketImpl);
    }

    virtual CARAPI Accept(
        /* [in] */ Elastos::Net::ISocketImpl * newSocket) = 0;

    virtual CARAPI Available(
        /* [out] */ _ELASTOS Int32 * num) = 0;

    virtual CARAPI Bind(
        /* [in] */ Elastos::Net::IInetAddress * address,
        /* [in] */ _ELASTOS Int32 port) = 0;

    virtual CARAPI Close() = 0;

    virtual CARAPI Connect(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port) = 0;

    virtual CARAPI Connect(
        /* [in] */ Elastos::Net::IInetAddress * address,
        /* [in] */ _ELASTOS Int32 port) = 0;

    virtual CARAPI Create(
        /* [in] */ _ELASTOS Boolean isStreaming) = 0;

    virtual CARAPI GetFileDescriptor(
        /* [out] */ Elastos::IO::IFileDescriptor ** fileDescriptor) = 0;

    virtual CARAPI GetInetAddress(
        /* [out] */ Elastos::Net::IInetAddress ** netAddress) = 0;

    virtual CARAPI GetInputStream(
        /* [out] */ Elastos::IO::IInputStream ** inputStream) = 0;

    virtual CARAPI GetLocalPort(
        /* [out] */ _ELASTOS Int32 * num) = 0;

    virtual CARAPI GetOutputStream(
        /* [out] */ Elastos::IO::IOutputStream ** outputStream) = 0;

    virtual CARAPI GetPort(
        /* [out] */ _ELASTOS Int32 * port) = 0;

    virtual CARAPI Listen(
        /* [in] */ _ELASTOS Int32 backlog) = 0;

    virtual CARAPI ShutdownInput() = 0;

    virtual CARAPI ShutdownOutput() = 0;

    virtual CARAPI Connect(
        /* [in] */ Elastos::Net::ISocketAddress * remoteAddr,
        /* [in] */ _ELASTOS Int32 timeout) = 0;

    virtual CARAPI SupportsUrgentData(
        /* [out] */ _ELASTOS Boolean * isSupports) = 0;

    virtual CARAPI SendUrgentData(
        /* [in] */ _ELASTOS Int32 value) = 0;

    virtual CARAPI SetPerformancePreferences(
        /* [in] */ _ELASTOS Int32 connectionTime,
        /* [in] */ _ELASTOS Int32 latency,
        /* [in] */ _ELASTOS Int32 bandwidth) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("FED82829-8652-2417-58C4-285DEF477B1B")
IPlainSocketImpl : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPlainSocketImpl*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPlainSocketImpl*)pObj->Probe(EIID_IPlainSocketImpl);
    }

    static CARAPI_(IPlainSocketImpl*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPlainSocketImpl*)pObj->Probe(EIID_IPlainSocketImpl);
    }

    virtual CARAPI SocksAccept() = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("E8CC2327-8652-2417-58C4-C05CBADE8FF6")
IPlainServerSocketImpl : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPlainServerSocketImpl*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPlainServerSocketImpl*)pObj->Probe(EIID_IPlainServerSocketImpl);
    }

    static CARAPI_(IPlainServerSocketImpl*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPlainServerSocketImpl*)pObj->Probe(EIID_IPlainServerSocketImpl);
    }

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("F7592410-5652-3BCB-FF3B-2F69DFB2FD5F")
IProxy : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IProxy*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IProxy*)pObj->Probe(EIID_IProxy);
    }

    static CARAPI_(IProxy*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IProxy*)pObj->Probe(EIID_IProxy);
    }

    virtual CARAPI GetType(
        /* [out] */ Elastos::Net::ProxyType * type) = 0;

    virtual CARAPI GetAddress(
        /* [out] */ Elastos::Net::ISocketAddress ** address) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("29B2240C-5652-3BCB-1FA1-EF8CD6BFF392")
IProxyHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IProxyHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IProxyHelper*)pObj->Probe(EIID_IProxyHelper);
    }

    static CARAPI_(IProxyHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IProxyHelper*)pObj->Probe(EIID_IProxyHelper);
    }

    virtual CARAPI GetNO_PROXY(
        /* [out] */ Elastos::Net::IProxy ** proxy) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("E3612E21-8652-321A-76F0-B09CFF477B1B")
IProxySelector : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IProxySelector*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IProxySelector*)pObj->Probe(EIID_IProxySelector);
    }

    static CARAPI_(IProxySelector*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IProxySelector*)pObj->Probe(EIID_IProxySelector);
    }

    virtual CARAPI Select(
        /* [in] */ Elastos::Net::IURI * uri,
        /* [out] */ Elastos::Utility::IList ** container) = 0;

    virtual CARAPI ConnectFailed(
        /* [in] */ Elastos::Net::IURI * uri,
        /* [in] */ Elastos::Net::ISocketAddress * address,
        /* [in] */ _ELASTOS ECode failure) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("1E5D3523-8652-321A-76F0-B09C3F028A17")
IProxySelectorHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IProxySelectorHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IProxySelectorHelper*)pObj->Probe(EIID_IProxySelectorHelper);
    }

    static CARAPI_(IProxySelectorHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IProxySelectorHelper*)pObj->Probe(EIID_IProxySelectorHelper);
    }

    virtual CARAPI GetDefault(
        /* [out] */ Elastos::Net::IProxySelector ** selector) = 0;

    virtual CARAPI SetDefault(
        /* [in] */ Elastos::Net::IProxySelector * selector) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("5569812E-0712-2614-E8C3-29FCA3BD8D1B")
ISecureCacheResponse : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISecureCacheResponse*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISecureCacheResponse*)pObj->Probe(EIID_ISecureCacheResponse);
    }

    static CARAPI_(ISecureCacheResponse*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISecureCacheResponse*)pObj->Probe(EIID_ISecureCacheResponse);
    }

    virtual CARAPI GetCipherSuite(
        /* [out] */ _ELASTOS String * clipherSuite) = 0;

    virtual CARAPI GetLocalCertificateChain(
        /* [out] */ Elastos::Utility::IList ** certificateChain) = 0;

    virtual CARAPI GetServerCertificateChain(
        /* [out] */ Elastos::Utility::IList ** certificateChain) = 0;

    virtual CARAPI GetPeerPrincipal(
        /* [out] */ Elastos::Security::IPrincipal ** principal) = 0;

    virtual CARAPI GetLocalPrincipal(
        /* [out] */ Elastos::Security::IPrincipal ** principal) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("5456F339-E612-3FD2-DADB-B821C3C68F0B")
IServerSocket : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IServerSocket*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IServerSocket*)pObj->Probe(EIID_IServerSocket);
    }

    static CARAPI_(IServerSocket*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IServerSocket*)pObj->Probe(EIID_IServerSocket);
    }

    virtual CARAPI GetImpl(
        /* [out] */ Elastos::Net::ISocketImpl ** impl) = 0;

    virtual CARAPI Accept(
        /* [out] */ Elastos::Net::ISocket ** socket) = 0;

    virtual CARAPI Close() = 0;

    virtual CARAPI GetInetAddress(
        /* [out] */ Elastos::Net::IInetAddress ** address) = 0;

    virtual CARAPI GetLocalPort(
        /* [out] */ _ELASTOS Int32 * port) = 0;

    virtual CARAPI GetSoTimeout(
        /* [out] */ _ELASTOS Int32 * timeout) = 0;

    virtual CARAPI SetSoTimeout(
        /* [in] */ _ELASTOS Int32 timeout) = 0;

    virtual CARAPI Bind(
        /* [in] */ Elastos::Net::ISocketAddress * localAddr) = 0;

    virtual CARAPI Bind(
        /* [in] */ Elastos::Net::ISocketAddress * localAddr,
        /* [in] */ _ELASTOS Int32 backlog) = 0;

    virtual CARAPI GetLocalSocketAddress(
        /* [out] */ Elastos::Net::ISocketAddress ** address) = 0;

    virtual CARAPI IsBound(
        /* [out] */ _ELASTOS Boolean * isBound) = 0;

    virtual CARAPI IsClosed(
        /* [out] */ _ELASTOS Boolean * isClosed) = 0;

    virtual CARAPI SetReuseAddress(
        /* [in] */ _ELASTOS Boolean reuse) = 0;

    virtual CARAPI GetReuseAddress(
        /* [out] */ _ELASTOS Boolean * reuse) = 0;

    virtual CARAPI SetReceiveBufferSize(
        /* [in] */ _ELASTOS Int32 size) = 0;

    virtual CARAPI GetReceiveBufferSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetChannel(
        /* [out] */ Elastos::IO::Channels::IServerSocketChannel ** channel) = 0;

    virtual CARAPI SetPerformancePreferences(
        /* [in] */ _ELASTOS Int32 connectionTime,
        /* [in] */ _ELASTOS Int32 latency,
        /* [in] */ _ELASTOS Int32 bandwidth) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("48213031-E612-11D2-50BC-9871FF477B1B")
IServerSocketHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IServerSocketHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IServerSocketHelper*)pObj->Probe(EIID_IServerSocketHelper);
    }

    static CARAPI_(IServerSocketHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IServerSocketHelper*)pObj->Probe(EIID_IServerSocketHelper);
    }

    virtual CARAPI SetSocketFactory(
        /* [in] */ Elastos::Net::ISocketImplFactory * aFactory) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("1D95FE28-E952-ED1F-6DDC-9061E3C70514")
ISocket : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISocket*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocket*)pObj->Probe(EIID_ISocket);
    }

    static CARAPI_(ISocket*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocket*)pObj->Probe(EIID_ISocket);
    }

    virtual CARAPI Close() = 0;

    virtual CARAPI OnClose() = 0;

    virtual CARAPI GetInetAddress(
        /* [out] */ Elastos::Net::IInetAddress ** address) = 0;

    virtual CARAPI GetInputStream(
        /* [out] */ Elastos::IO::IInputStream ** is) = 0;

    virtual CARAPI GetKeepAlive(
        /* [out] */ _ELASTOS Boolean * keepAlive) = 0;

    virtual CARAPI GetLocalAddress(
        /* [out] */ Elastos::Net::IInetAddress ** address) = 0;

    virtual CARAPI GetLocalPort(
        /* [out] */ _ELASTOS Int32 * localPort) = 0;

    virtual CARAPI GetOutputStream(
        /* [out] */ Elastos::IO::IOutputStream ** os) = 0;

    virtual CARAPI GetPort(
        /* [out] */ _ELASTOS Int32 * port) = 0;

    virtual CARAPI GetSoLinger(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetReceiveBufferSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetSendBufferSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetSoTimeout(
        /* [out] */ _ELASTOS Int32 * timeout) = 0;

    virtual CARAPI GetTcpNoDelay(
        /* [out] */ _ELASTOS Boolean * noDelay) = 0;

    virtual CARAPI SetKeepAlive(
        /* [in] */ _ELASTOS Boolean keepAlive) = 0;

    virtual CARAPI SetSendBufferSize(
        /* [in] */ _ELASTOS Int32 size) = 0;

    virtual CARAPI SetReceiveBufferSize(
        /* [in] */ _ELASTOS Int32 size) = 0;

    virtual CARAPI SetSoLinger(
        /* [in] */ _ELASTOS Boolean on,
        /* [in] */ _ELASTOS Int32 timeout) = 0;

    virtual CARAPI SetSoTimeout(
        /* [in] */ _ELASTOS Int32 timeout) = 0;

    virtual CARAPI SetTcpNoDelay(
        /* [in] */ _ELASTOS Boolean on) = 0;

    virtual CARAPI ShutdownInput() = 0;

    virtual CARAPI ShutdownOutput() = 0;

    virtual CARAPI GetLocalSocketAddress(
        /* [out] */ Elastos::Net::ISocketAddress ** address) = 0;

    virtual CARAPI GetRemoteSocketAddress(
        /* [out] */ Elastos::Net::ISocketAddress ** address) = 0;

    virtual CARAPI IsBound(
        /* [out] */ _ELASTOS Boolean * isBound) = 0;

    virtual CARAPI IsConnected(
        /* [out] */ _ELASTOS Boolean * isConnected) = 0;

    virtual CARAPI IsClosed(
        /* [out] */ _ELASTOS Boolean * isClosed) = 0;

    virtual CARAPI Bind(
        /* [in] */ Elastos::Net::ISocketAddress * localAddr) = 0;

    virtual CARAPI OnBind(
        /* [in] */ Elastos::Net::IInetAddress * localAddr,
        /* [in] */ _ELASTOS Int32 localPort) = 0;

    virtual CARAPI Connect(
        /* [in] */ Elastos::Net::ISocketAddress * remoteAddr) = 0;

    virtual CARAPI Connect(
        /* [in] */ Elastos::Net::ISocketAddress * remoteAddr,
        /* [in] */ _ELASTOS Int32 timeout) = 0;

    virtual CARAPI OnConnect(
        /* [in] */ Elastos::Net::ISocketAddress * remoteAddr,
        /* [in] */ _ELASTOS Int32 timeout) = 0;

    virtual CARAPI IsInputShutdown(
        /* [out] */ _ELASTOS Boolean * isInputShutdown) = 0;

    virtual CARAPI IsOutputShutdown(
        /* [out] */ _ELASTOS Boolean * isOutputShutdown) = 0;

    virtual CARAPI SetReuseAddress(
        /* [in] */ _ELASTOS Boolean reuse) = 0;

    virtual CARAPI GetReuseAddress(
        /* [out] */ _ELASTOS Boolean * reuse) = 0;

    virtual CARAPI SetOOBInline(
        /* [in] */ _ELASTOS Boolean oobinline) = 0;

    virtual CARAPI GetOOBInline(
        /* [out] */ _ELASTOS Boolean * oobinline) = 0;

    virtual CARAPI SetTrafficClass(
        /* [in] */ _ELASTOS Int32 value) = 0;

    virtual CARAPI GetTrafficClass(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI SendUrgentData(
        /* [in] */ _ELASTOS Int32 value) = 0;

    virtual CARAPI GetChannel(
        /* [out] */ Elastos::IO::Channels::ISocketChannel ** channel) = 0;

    virtual CARAPI GetFileDescriptor(
        /* [out] */ Elastos::IO::IFileDescriptor ** fd) = 0;

    virtual CARAPI SetPerformancePreferences(
        /* [in] */ _ELASTOS Int32 connectionTime,
        /* [in] */ _ELASTOS Int32 latency,
        /* [in] */ _ELASTOS Int32 bandwidth) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("B9952E24-E952-2808-5ECC-B8FFA3BD8D1B")
ISocketHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISocketHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketHelper*)pObj->Probe(EIID_ISocketHelper);
    }

    static CARAPI_(ISocketHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketHelper*)pObj->Probe(EIID_ISocketHelper);
    }

    virtual CARAPI SetSocketImplFactory(
        /* [in] */ Elastos::Net::ISocketImplFactory * fac) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("E70D2F37-E952-D07A-7EB4-B77143868D1F")
ISocketImplFactory : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISocketImplFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketImplFactory*)pObj->Probe(EIID_ISocketImplFactory);
    }

    static CARAPI_(ISocketImplFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketImplFactory*)pObj->Probe(EIID_ISocketImplFactory);
    }

    virtual CARAPI CreateSocketImpl(
        /* [out] */ Elastos::Net::ISocketImpl ** createdInstance) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("98D38833-0712-2619-5CD8-2030F3477B1B")
ISocks4Message : public IInterface
{
    static const _ELASTOS Int32 COMMAND_CONNECT = 1;
    static const _ELASTOS Int32 COMMAND_BIND = 2;
    static const _ELASTOS Int32 RETURN_SUCCESS = 90;
    static const _ELASTOS Int32 RETURN_FAILURE = 91;
    static const _ELASTOS Int32 RETURN_CANNOT_CONNECT_TO_IDENTD = 92;
    static const _ELASTOS Int32 RETURN_DIFFERENT_USER_IDS = 93;
    static const _ELASTOS Int32 REPLY_LENGTH = 8;
    static const _ELASTOS Int32 INDEX_VERSION = 0;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISocks4Message*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocks4Message*)pObj->Probe(EIID_ISocks4Message);
    }

    static CARAPI_(ISocks4Message*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocks4Message*)pObj->Probe(EIID_ISocks4Message);
    }

    virtual CARAPI GetCommandOrResult(
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI SetCommandOrResult(
        /* [in] */ _ELASTOS Int32 command) = 0;

    virtual CARAPI GetPort(
        /* [out] */ _ELASTOS Int32 * port) = 0;

    virtual CARAPI SetPort(
        /* [in] */ _ELASTOS Int32 port) = 0;

    virtual CARAPI GetIP(
        /* [out] */ _ELASTOS Int32 * ip) = 0;

    virtual CARAPI SetIP(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * ip) = 0;

    virtual CARAPI GetUserId(
        /* [out] */ _ELASTOS String * id) = 0;

    virtual CARAPI SetUserId(
        /* [in] */ const _ELASTOS String& id) = 0;

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int32 * length) = 0;

    virtual CARAPI GetErrorString(
        /* [in] */ _ELASTOS Int32 error,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetBytes(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** bytes) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("53792421-7312-3560-7EB4-B77143868D1F")
IURLEncoder : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IURLEncoder*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IURLEncoder*)pObj->Probe(EIID_IURLEncoder);
    }

    static CARAPI_(IURLEncoder*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IURLEncoder*)pObj->Probe(EIID_IURLEncoder);
    }

    virtual CARAPI Encode(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ _ELASTOS String * result) = 0;

    virtual CARAPI Encode(
        /* [in] */ const _ELASTOS String& s,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ _ELASTOS String * result) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("6E7C2434-F312-354F-7EB4-B77143868D1F")
IURLDecoder : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IURLDecoder*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IURLDecoder*)pObj->Probe(EIID_IURLDecoder);
    }

    static CARAPI_(IURLDecoder*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IURLDecoder*)pObj->Probe(EIID_IURLDecoder);
    }

    virtual CARAPI Decode(
        /* [in] */ const _ELASTOS String& s,
        /* [out] */ _ELASTOS String * result) = 0;

    virtual CARAPI Decode(
        /* [in] */ const _ELASTOS String& s,
        /* [in] */ const _ELASTOS String& encoding,
        /* [out] */ _ELASTOS String * result) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("5AAC842A-04D2-3512-9833-FAD1DEC60D19")
IJarURLConnection : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IJarURLConnection*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJarURLConnection*)pObj->Probe(EIID_IJarURLConnection);
    }

    static CARAPI_(IJarURLConnection*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJarURLConnection*)pObj->Probe(EIID_IJarURLConnection);
    }

    virtual CARAPI GetAttributes(
        /* [out] */ Elastos::Utility::Jar::IAttributes ** attr) = 0;

    virtual CARAPI GetCertificates(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> ** certs) = 0;

    virtual CARAPI GetEntryName(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetJarEntry(
        /* [out] */ Elastos::Utility::Jar::IJarEntry ** entry) = 0;

    virtual CARAPI GetManifest(
        /* [out] */ Elastos::Utility::Jar::IManifest ** manifest) = 0;

    virtual CARAPI GetJarFile(
        /* [out] */ Elastos::Utility::Jar::IJarFile ** file) = 0;

    virtual CARAPI GetJarFileURL(
        /* [out] */ Elastos::Net::IURL ** url) = 0;

    virtual CARAPI GetMainAttributes(
        /* [out] */ Elastos::Utility::Jar::IAttributes ** attr) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("9F2F1B43-85D2-1969-9EF1-B4B1F8878392")
INetPermission : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INetPermission*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INetPermission*)pObj->Probe(EIID_INetPermission);
    }

    static CARAPI_(INetPermission*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INetPermission*)pObj->Probe(EIID_INetPermission);
    }

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("92F81E27-E952-F70C-61B0-B011FF477B1B")
ISocketPermission : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISocketPermission*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketPermission*)pObj->Probe(EIID_ISocketPermission);
    }

    static CARAPI_(ISocketPermission*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketPermission*)pObj->Probe(EIID_ISocketPermission);
    }

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("41FC8832-0312-3206-64B8-608162A51EA3")
ICCookieManagerClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCookieManagerClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCookieManagerClassObject*)pObj->Probe(EIID_ICCookieManagerClassObject);
    }

    static CARAPI_(ICCookieManagerClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCookieManagerClassObject*)pObj->Probe(EIID_ICCookieManagerClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithStoreCookiePolicy(
        /* [in] */ Elastos::Net::ICookieStore * store,
        /* [in] */ Elastos::Net::ICookiePolicy * cookiePolicy,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("0AD1F743-8312-8C06-E4C1-C84062D53406")
ICDatagramPacketClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDatagramPacketClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDatagramPacketClassObject*)pObj->Probe(EIID_ICDatagramPacketClassObject);
    }

    static CARAPI_(ICDatagramPacketClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDatagramPacketClassObject*)pObj->Probe(EIID_ICDatagramPacketClassObject);
    }

    virtual CARAPI CreateObjectWithDataLength(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithDataOffsetLength(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithDataOffsetLengthHostAPort(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::IInetAddress * host,
        /* [in] */ _ELASTOS Int32 aPort,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithDataLengthHostPort(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::IInetAddress * host,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithDataLengthSockAddr(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::ISocketAddress * sockAddr,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithDataOffsetLengthSockAddr(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::ISocketAddress * sockAddr,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("1B1BAF2F-0312-2A4C-6A90-80515A8FD11F")
ICDatagramSocketClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDatagramSocketClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDatagramSocketClassObject*)pObj->Probe(EIID_ICDatagramSocketClassObject);
    }

    static CARAPI_(ICDatagramSocketClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDatagramSocketClassObject*)pObj->Probe(EIID_ICDatagramSocketClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithAPort(
        /* [in] */ _ELASTOS Int32 aPort,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithAportAddr(
        /* [in] */ _ELASTOS Int32 aport,
        /* [in] */ Elastos::Net::IInetAddress * addr,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithLocalAddr(
        /* [in] */ Elastos::Net::ISocketAddress * localAddr,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("F3716205-1312-F7DD-CCC8-B2CBA2CC4BDA")
ICHttpCookieClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICHttpCookieClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICHttpCookieClassObject*)pObj->Probe(EIID_ICHttpCookieClassObject);
    }

    static CARAPI_(ICHttpCookieClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICHttpCookieClassObject*)pObj->Probe(EIID_ICHttpCookieClassObject);
    }

    virtual CARAPI CreateObjectWithNameValue(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("62C06A06-1312-F7DD-CCC8-B2CBA211FACE")
ICHttpCookieHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICHttpCookieHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICHttpCookieHelperClassObject*)pObj->Probe(EIID_ICHttpCookieHelperClassObject);
    }

    static CARAPI_(ICHttpCookieHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICHttpCookieHelperClassObject*)pObj->Probe(EIID_ICHttpCookieHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("92D86A36-8312-2883-6E10-20A2C7E88FF6")
ICInet4AddressClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICInet4AddressClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInet4AddressClassObject*)pObj->Probe(EIID_ICInet4AddressClassObject);
    }

    static CARAPI_(ICInet4AddressClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInet4AddressClassObject*)pObj->Probe(EIID_ICInet4AddressClassObject);
    }

    virtual CARAPI CreateObjectWithAddressHostName(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * address,
        /* [in] */ const _ELASTOS String& hostName,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("266C6C3B-8312-2883-6E10-201201C58B19")
ICInet4AddressHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICInet4AddressHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInet4AddressHelperClassObject*)pObj->Probe(EIID_ICInet4AddressHelperClassObject);
    }

    static CARAPI_(ICInet4AddressHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInet4AddressHelperClassObject*)pObj->Probe(EIID_ICInet4AddressHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("013F722A-8312-2883-6E18-20A2C7E88FF6")
ICInet6AddressClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICInet6AddressClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInet6AddressClassObject*)pObj->Probe(EIID_ICInet6AddressClassObject);
    }

    static CARAPI_(ICInet6AddressClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInet6AddressClassObject*)pObj->Probe(EIID_ICInet6AddressClassObject);
    }

    virtual CARAPI CreateObjectWithAddressHostNameScope_id(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * address,
        /* [in] */ const _ELASTOS String& hostName,
        /* [in] */ _ELASTOS Int32 scope_id,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("266A6C24-8312-2883-6E18-201201C58B19")
ICInet6AddressHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICInet6AddressHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInet6AddressHelperClassObject*)pObj->Probe(EIID_ICInet6AddressHelperClassObject);
    }

    static CARAPI_(ICInet6AddressHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInet6AddressHelperClassObject*)pObj->Probe(EIID_ICInet6AddressHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("EE827B36-8312-2883-6E78-88C16207113D")
ICInetUnixAddressClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICInetUnixAddressClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInetUnixAddressClassObject*)pObj->Probe(EIID_ICInetUnixAddressClassObject);
    }

    static CARAPI_(ICInetUnixAddressClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInetUnixAddressClassObject*)pObj->Probe(EIID_ICInetUnixAddressClassObject);
    }

    virtual CARAPI CreateObjectWithPath(
        /* [in] */ const _ELASTOS String& path,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithBytesPath(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * bytesPath,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("E895DA39-8312-2883-6E94-26A2C7E88FF6")
ICInetSocketAddressClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICInetSocketAddressClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInetSocketAddressClassObject*)pObj->Probe(EIID_ICInetSocketAddressClassObject);
    }

    static CARAPI_(ICInetSocketAddressClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInetSocketAddressClassObject*)pObj->Probe(EIID_ICInetSocketAddressClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPort(
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithAddressPort(
        /* [in] */ Elastos::Net::IInetAddress * address,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithHostPort(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithHostnamePortNeedResolved(
        /* [in] */ const _ELASTOS String& hostname,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean needResolved,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("AFAB7127-8312-2883-6E94-261201C58B19")
ICInetSocketAddressHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICInetSocketAddressHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInetSocketAddressHelperClassObject*)pObj->Probe(EIID_ICInetSocketAddressHelperClassObject);
    }

    static CARAPI_(ICInetSocketAddressHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInetSocketAddressHelperClassObject*)pObj->Probe(EIID_ICInetSocketAddressHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("660C975D-0312-B90B-372B-E22063D53406")
ICMulticastSocketClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICMulticastSocketClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMulticastSocketClassObject*)pObj->Probe(EIID_ICMulticastSocketClassObject);
    }

    static CARAPI_(ICMulticastSocketClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMulticastSocketClassObject*)pObj->Probe(EIID_ICMulticastSocketClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithAPort(
        /* [in] */ _ELASTOS Int32 aPort,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithLocalAddr(
        /* [in] */ Elastos::Net::ISocketAddress * localAddr,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("36337B42-8312-D30B-323C-E36963310393")
ICNetPermissionClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICNetPermissionClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNetPermissionClassObject*)pObj->Probe(EIID_ICNetPermissionClassObject);
    }

    static CARAPI_(ICNetPermissionClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNetPermissionClassObject*)pObj->Probe(EIID_ICNetPermissionClassObject);
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
namespace Elastos {
namespace Net {
CAR_INTERFACE("FA547513-9312-B691-ADCB-F5A9E0F78AC6")
ICPasswordAuthenticationClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPasswordAuthenticationClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPasswordAuthenticationClassObject*)pObj->Probe(EIID_ICPasswordAuthenticationClassObject);
    }

    static CARAPI_(ICPasswordAuthenticationClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPasswordAuthenticationClassObject*)pObj->Probe(EIID_ICPasswordAuthenticationClassObject);
    }

    virtual CARAPI CreateObjectWithUserNamePassword(
        /* [in] */ const _ELASTOS String& userName,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("EEEF8C4E-8312-260C-2536-60240F060719")
ICPlainDatagramSocketImplClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPlainDatagramSocketImplClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPlainDatagramSocketImplClassObject*)pObj->Probe(EIID_ICPlainDatagramSocketImplClassObject);
    }

    static CARAPI_(ICPlainDatagramSocketImplClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPlainDatagramSocketImplClassObject*)pObj->Probe(EIID_ICPlainDatagramSocketImplClassObject);
    }

    virtual CARAPI CreateObjectWithFdLocalPort(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("B01C8221-8312-2F0C-48B0-8881B9743D3D")
ICPlainServerSocketImplClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPlainServerSocketImplClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPlainServerSocketImplClassObject*)pObj->Probe(EIID_ICPlainServerSocketImplClassObject);
    }

    static CARAPI_(ICPlainServerSocketImplClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPlainServerSocketImplClassObject*)pObj->Probe(EIID_ICPlainServerSocketImplClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPFd(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("51C3B73D-8312-2F0C-48B0-8851BA9E1EA3")
ICPlainSocketImplClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPlainSocketImplClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPlainSocketImplClassObject*)pObj->Probe(EIID_ICPlainSocketImplClassObject);
    }

    static CARAPI_(ICPlainSocketImplClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPlainSocketImplClassObject*)pObj->Probe(EIID_ICPlainSocketImplClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPFd(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPProxy(
        /* [in] */ Elastos::Net::IProxy * pProxy,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPFdLocalportPAddrPort(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [in] */ _ELASTOS Int32 localport,
        /* [in] */ Elastos::Net::IInetAddress * pAddr,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("56AD6F3F-8312-2F0C-48B0-8851FA9F6C14")
ICPlainSocketInputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPlainSocketInputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPlainSocketInputStreamClassObject*)pObj->Probe(EIID_ICPlainSocketInputStreamClassObject);
    }

    static CARAPI_(ICPlainSocketInputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPlainSocketInputStreamClassObject*)pObj->Probe(EIID_ICPlainSocketInputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithSocketImpl(
        /* [in] */ Elastos::Net::ISocketImpl * socketImpl,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("671B703E-8312-2F0C-48B0-88515AAA6C14")
ICPlainSocketOutputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPlainSocketOutputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPlainSocketOutputStreamClassObject*)pObj->Probe(EIID_ICPlainSocketOutputStreamClassObject);
    }

    static CARAPI_(ICPlainSocketOutputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPlainSocketOutputStreamClassObject*)pObj->Probe(EIID_ICPlainSocketOutputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithSocketImpl(
        /* [in] */ Elastos::Net::ISocketImpl * socketImpl,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("3C7D753B-8312-350C-64EC-E0A1C7E88FF6")
ICProxyClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICProxyClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICProxyClassObject*)pObj->Probe(EIID_ICProxyClassObject);
    }

    static CARAPI_(ICProxyClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICProxyClassObject*)pObj->Probe(EIID_ICProxyClassObject);
    }

    virtual CARAPI CreateObjectWithTypeSa(
        /* [in] */ Elastos::Net::ProxyType type,
        /* [in] */ Elastos::Net::ISocketAddress * sa,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("40BC6519-9312-F2D5-CE47-E83BA335F392")
ICProxyHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICProxyHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICProxyHelperClassObject*)pObj->Probe(EIID_ICProxyHelperClassObject);
    }

    static CARAPI_(ICProxyHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICProxyHelperClassObject*)pObj->Probe(EIID_ICProxyHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("B8406D33-8312-70C2-22A0-7831E3BE1EA3")
ICResponseCacheHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICResponseCacheHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICResponseCacheHelperClassObject*)pObj->Probe(EIID_ICResponseCacheHelperClassObject);
    }

    static CARAPI_(ICResponseCacheHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICResponseCacheHelperClassObject*)pObj->Probe(EIID_ICResponseCacheHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("5948BC2D-0312-A5CC-F518-FDD1DEC60D19")
ICServerSocketClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICServerSocketClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICServerSocketClassObject*)pObj->Probe(EIID_ICServerSocketClassObject);
    }

    static CARAPI_(ICServerSocketClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICServerSocketClassObject*)pObj->Probe(EIID_ICServerSocketClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPort(
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPortBacklog(
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Int32 backlog,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPortBacklogLocalAddress(
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Int32 backlog,
        /* [in] */ Elastos::Net::IInetAddress * localAddress,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("EA516C27-0312-A5CC-23A0-7831E3BE1EA3")
ICServerSocketHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICServerSocketHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICServerSocketHelperClassObject*)pObj->Probe(EIID_ICServerSocketHelperClassObject);
    }

    static CARAPI_(ICServerSocketHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICServerSocketHelperClassObject*)pObj->Probe(EIID_ICServerSocketHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("9DA6E722-8312-7AD2-8CFE-686FE3860C1B")
ICSocketClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSocketClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSocketClassObject*)pObj->Probe(EIID_ICSocketClassObject);
    }

    static CARAPI_(ICSocketClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSocketClassObject*)pObj->Probe(EIID_ICSocketClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithProxy(
        /* [in] */ Elastos::Net::IProxy * proxy,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithDstNameDstPort(
        /* [in] */ const _ELASTOS String& dstName,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithDstNameDstPortLocalAddressLocalPort(
        /* [in] */ const _ELASTOS String& dstName,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [in] */ Elastos::Net::IInetAddress * localAddress,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithHostNamePortStreaming(
        /* [in] */ const _ELASTOS String& hostName,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean streaming,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithDstAddressDstPort(
        /* [in] */ Elastos::Net::IInetAddress * dstAddress,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithDstAddressDstPortLocalAddressLocalPort(
        /* [in] */ Elastos::Net::IInetAddress * dstAddress,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [in] */ Elastos::Net::IInetAddress * localAddress,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithAddrPortStreaming(
        /* [in] */ Elastos::Net::IInetAddress * addr,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean streaming,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("387D6630-8312-11D2-50BC-98715F8FD11F")
ICSocketHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSocketHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSocketHelperClassObject*)pObj->Probe(EIID_ICSocketHelperClassObject);
    }

    static CARAPI_(ICSocketHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSocketHelperClassObject*)pObj->Probe(EIID_ICSocketHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("5AF16927-8312-19D2-EEC3-606123BE1EA3")
ICSocketPermissionClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSocketPermissionClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSocketPermissionClassObject*)pObj->Probe(EIID_ICSocketPermissionClassObject);
    }

    static CARAPI_(ICSocketPermissionClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSocketPermissionClassObject*)pObj->Probe(EIID_ICSocketPermissionClassObject);
    }

    virtual CARAPI CreateObjectWithHostAction(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& action,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("F68B673F-0312-320E-4CB8-B04160A61EA3")
ICSocks4MessageClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSocks4MessageClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSocks4MessageClassObject*)pObj->Probe(EIID_ICSocks4MessageClassObject);
    }

    static CARAPI_(ICSocks4MessageClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSocks4MessageClassObject*)pObj->Probe(EIID_ICSocks4MessageClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("819ED935-0312-1B0F-24E8-31FAA3BD8D1B")
ICURIClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICURIClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICURIClassObject*)pObj->Probe(EIID_ICURIClassObject);
    }

    static CARAPI_(ICURIClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICURIClassObject*)pObj->Probe(EIID_ICURIClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithSpec(
        /* [in] */ const _ELASTOS String& spec,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithSchemeSchemeSpecificPartFragment(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& schemeSpecificPart,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithSchemeUserInfoHostPortPathQueryFragment(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& userInfo,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& query,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithSchemeHostPathFragment(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithSchemeAuthorityPathQueryFragment(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& authority,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& query,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("D956630E-E312-526D-84BE-335A332F69DB")
ICURIHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICURIHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICURIHelperClassObject*)pObj->Probe(EIID_ICURIHelperClassObject);
    }

    static CARAPI_(ICURIHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICURIHelperClassObject*)pObj->Probe(EIID_ICURIHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("C0E9F624-0312-7AE6-8CFE-686FE3860C1B")
ICURLClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICURLClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICURLClassObject*)pObj->Probe(EIID_ICURLClassObject);
    }

    static CARAPI_(ICURLClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICURLClassObject*)pObj->Probe(EIID_ICURLClassObject);
    }

    virtual CARAPI CreateObjectWithSpec(
        /* [in] */ const _ELASTOS String& spec,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithContextSpec(
        /* [in] */ Elastos::Net::IURL * context,
        /* [in] */ const _ELASTOS String& spec,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithContextSpecHandler(
        /* [in] */ Elastos::Net::IURL * context,
        /* [in] */ const _ELASTOS String& spec,
        /* [in] */ Elastos::Net::IURLStreamHandler * handler,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithProtocolHostFile(
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& file,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithProtocolHostPortFile(
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& file,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithProtocolHostPortFileHandler(
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& file,
        /* [in] */ Elastos::Net::IURLStreamHandler * handler,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("C0436D21-0312-3206-64B8-6081E25C0414")
ICCookieHandlerHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCookieHandlerHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCookieHandlerHelperClassObject*)pObj->Probe(EIID_ICCookieHandlerHelperClassObject);
    }

    static CARAPI_(ICCookieHandlerHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCookieHandlerHelperClassObject*)pObj->Probe(EIID_ICCookieHandlerHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("F55C6C19-C312-B2C8-CBA2-99FCB2261FA1")
ICCookiePolicyHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCookiePolicyHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCookiePolicyHelperClassObject*)pObj->Probe(EIID_ICCookiePolicyHelperClassObject);
    }

    static CARAPI_(ICCookiePolicyHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCookiePolicyHelperClassObject*)pObj->Probe(EIID_ICCookiePolicyHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("01A65D25-0312-0D09-2EE8-31FAA3BD8D1B")
ICIDNClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICIDNClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICIDNClassObject*)pObj->Probe(EIID_ICIDNClassObject);
    }

    static CARAPI_(ICIDNClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICIDNClassObject*)pObj->Probe(EIID_ICIDNClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("FEC76B27-8312-2883-6E10-8980E2C58CFB")
ICInetAddressHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICInetAddressHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInetAddressHelperClassObject*)pObj->Probe(EIID_ICInetAddressHelperClassObject);
    }

    static CARAPI_(ICInetAddressHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInetAddressHelperClassObject*)pObj->Probe(EIID_ICInetAddressHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("415E7033-8312-280B-6EE8-C8EF42600414")
ICNetworkInterfaceHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICNetworkInterfaceHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNetworkInterfaceHelperClassObject*)pObj->Probe(EIID_ICNetworkInterfaceHelperClassObject);
    }

    static CARAPI_(ICNetworkInterfaceHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNetworkInterfaceHelperClassObject*)pObj->Probe(EIID_ICNetworkInterfaceHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("FDCE6427-0312-C0E6-6AE8-31FAA3BD8D1B")
ICURLEncoderClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICURLEncoderClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICURLEncoderClassObject*)pObj->Probe(EIID_ICURLEncoderClassObject);
    }

    static CARAPI_(ICURLEncoderClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICURLEncoderClassObject*)pObj->Probe(EIID_ICURLEncoderClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
CAR_INTERFACE("FED7643D-0312-9FE6-6AE8-31FAA3BD8D1B")
ICURLDecoderClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICURLDecoderClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICURLDecoderClassObject*)pObj->Probe(EIID_ICURLDecoderClassObject);
    }

    static CARAPI_(ICURLDecoderClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICURLDecoderClassObject*)pObj->Probe(EIID_ICURLDecoderClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Net {
class CCookieManager
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Net::ICookieStore * store,
        /* [in] */ Elastos::Net::ICookiePolicy * cookiePolicy,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCookieManagerClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCookieManager, RGM_SAME_DOMAIN,
                EIID_ICCookieManagerClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithStoreCookiePolicy(store, cookiePolicy, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::ICookieManager** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCookieManager, RGM_SAME_DOMAIN, Elastos::Net::EIID_ICookieManager, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::ICookieHandler** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCookieManager, RGM_SAME_DOMAIN, Elastos::Net::EIID_ICookieHandler, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCookieManager, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCookieManager, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCookieManager, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ICookieStore * store,
        /* [in] */ Elastos::Net::ICookiePolicy * cookiePolicy,
        /* [out] */ Elastos::Net::ICookieManager** __ICookieManager)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(store, cookiePolicy, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICookieManager = (Elastos::Net::ICookieManager*)__pNewObj->Probe(Elastos::Net::EIID_ICookieManager);
        if (*__ICookieManager) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ICookieStore * store,
        /* [in] */ Elastos::Net::ICookiePolicy * cookiePolicy,
        /* [out] */ Elastos::Net::ICookieHandler** __ICookieHandler)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(store, cookiePolicy, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICookieHandler = (Elastos::Net::ICookieHandler*)__pNewObj->Probe(Elastos::Net::EIID_ICookieHandler);
        if (*__ICookieHandler) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ICookieStore * store,
        /* [in] */ Elastos::Net::ICookiePolicy * cookiePolicy,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(store, cookiePolicy, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ICookieStore * store,
        /* [in] */ Elastos::Net::ICookiePolicy * cookiePolicy,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(store, cookiePolicy, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ICookieStore * store,
        /* [in] */ Elastos::Net::ICookiePolicy * cookiePolicy,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(store, cookiePolicy, &__pNewObj);
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
namespace Net {
class CDatagramPacket
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDatagramPacketClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDatagramPacket, RGM_SAME_DOMAIN,
                EIID_ICDatagramPacketClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithDataLength(data, length, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDatagramPacketClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDatagramPacket, RGM_SAME_DOMAIN,
                EIID_ICDatagramPacketClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithDataOffsetLength(data, offset, length, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::IInetAddress * host,
        /* [in] */ _ELASTOS Int32 aPort,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDatagramPacketClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDatagramPacket, RGM_SAME_DOMAIN,
                EIID_ICDatagramPacketClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithDataOffsetLengthHostAPort(data, offset, length, host, aPort, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::IInetAddress * host,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDatagramPacketClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDatagramPacket, RGM_SAME_DOMAIN,
                EIID_ICDatagramPacketClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithDataLengthHostPort(data, length, host, port, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::ISocketAddress * sockAddr,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDatagramPacketClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDatagramPacket, RGM_SAME_DOMAIN,
                EIID_ICDatagramPacketClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithDataLengthSockAddr(data, length, sockAddr, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::ISocketAddress * sockAddr,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDatagramPacketClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDatagramPacket, RGM_SAME_DOMAIN,
                EIID_ICDatagramPacketClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithDataOffsetLengthSockAddr(data, offset, length, sockAddr, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::Net::IDatagramPacket** __IDatagramPacket)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDatagramPacket = (Elastos::Net::IDatagramPacket*)__pNewObj->Probe(Elastos::Net::EIID_IDatagramPacket);
        if (*__IDatagramPacket) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::Net::IDatagramPacket** __IDatagramPacket)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDatagramPacket = (Elastos::Net::IDatagramPacket*)__pNewObj->Probe(Elastos::Net::EIID_IDatagramPacket);
        if (*__IDatagramPacket) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::IInetAddress * host,
        /* [in] */ _ELASTOS Int32 aPort,
        /* [out] */ Elastos::Net::IDatagramPacket** __IDatagramPacket)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, offset, length, host, aPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDatagramPacket = (Elastos::Net::IDatagramPacket*)__pNewObj->Probe(Elastos::Net::EIID_IDatagramPacket);
        if (*__IDatagramPacket) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::IInetAddress * host,
        /* [in] */ _ELASTOS Int32 aPort,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, offset, length, host, aPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::IInetAddress * host,
        /* [in] */ _ELASTOS Int32 aPort,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, offset, length, host, aPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::IInetAddress * host,
        /* [in] */ _ELASTOS Int32 aPort,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, offset, length, host, aPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::IInetAddress * host,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Net::IDatagramPacket** __IDatagramPacket)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, length, host, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDatagramPacket = (Elastos::Net::IDatagramPacket*)__pNewObj->Probe(Elastos::Net::EIID_IDatagramPacket);
        if (*__IDatagramPacket) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::IInetAddress * host,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, length, host, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::IInetAddress * host,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, length, host, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::IInetAddress * host,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, length, host, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::ISocketAddress * sockAddr,
        /* [out] */ Elastos::Net::IDatagramPacket** __IDatagramPacket)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, length, sockAddr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDatagramPacket = (Elastos::Net::IDatagramPacket*)__pNewObj->Probe(Elastos::Net::EIID_IDatagramPacket);
        if (*__IDatagramPacket) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::ISocketAddress * sockAddr,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, length, sockAddr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::ISocketAddress * sockAddr,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, length, sockAddr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::ISocketAddress * sockAddr,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, length, sockAddr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::ISocketAddress * sockAddr,
        /* [out] */ Elastos::Net::IDatagramPacket** __IDatagramPacket)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, offset, length, sockAddr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDatagramPacket = (Elastos::Net::IDatagramPacket*)__pNewObj->Probe(Elastos::Net::EIID_IDatagramPacket);
        if (*__IDatagramPacket) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::ISocketAddress * sockAddr,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, offset, length, sockAddr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::ISocketAddress * sockAddr,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, offset, length, sockAddr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Net::ISocketAddress * sockAddr,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(data, offset, length, sockAddr, &__pNewObj);
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
namespace Net {
class CDatagramSocket
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 aPort,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDatagramSocketClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDatagramSocket, RGM_SAME_DOMAIN,
                EIID_ICDatagramSocketClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithAPort(aPort, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 aport,
        /* [in] */ Elastos::Net::IInetAddress * addr,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDatagramSocketClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDatagramSocket, RGM_SAME_DOMAIN,
                EIID_ICDatagramSocketClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithAportAddr(aport, addr, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Net::ISocketAddress * localAddr,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDatagramSocketClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDatagramSocket, RGM_SAME_DOMAIN,
                EIID_ICDatagramSocketClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithLocalAddr(localAddr, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::IDatagramSocket** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatagramSocket, RGM_SAME_DOMAIN, Elastos::Net::EIID_IDatagramSocket, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ICloseable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatagramSocket, RGM_SAME_DOMAIN, Elastos::IO::EIID_ICloseable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatagramSocket, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatagramSocket, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatagramSocket, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 aPort,
        /* [out] */ Elastos::Net::IDatagramSocket** __IDatagramSocket)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(aPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDatagramSocket = (Elastos::Net::IDatagramSocket*)__pNewObj->Probe(Elastos::Net::EIID_IDatagramSocket);
        if (*__IDatagramSocket) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 aPort,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(aPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 aPort,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(aPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 aPort,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(aPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 aPort,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(aPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 aport,
        /* [in] */ Elastos::Net::IInetAddress * addr,
        /* [out] */ Elastos::Net::IDatagramSocket** __IDatagramSocket)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(aport, addr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDatagramSocket = (Elastos::Net::IDatagramSocket*)__pNewObj->Probe(Elastos::Net::EIID_IDatagramSocket);
        if (*__IDatagramSocket) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 aport,
        /* [in] */ Elastos::Net::IInetAddress * addr,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(aport, addr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 aport,
        /* [in] */ Elastos::Net::IInetAddress * addr,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(aport, addr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 aport,
        /* [in] */ Elastos::Net::IInetAddress * addr,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(aport, addr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 aport,
        /* [in] */ Elastos::Net::IInetAddress * addr,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(aport, addr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ISocketAddress * localAddr,
        /* [out] */ Elastos::Net::IDatagramSocket** __IDatagramSocket)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(localAddr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDatagramSocket = (Elastos::Net::IDatagramSocket*)__pNewObj->Probe(Elastos::Net::EIID_IDatagramSocket);
        if (*__IDatagramSocket) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ISocketAddress * localAddr,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(localAddr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ISocketAddress * localAddr,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(localAddr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ISocketAddress * localAddr,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(localAddr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ISocketAddress * localAddr,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(localAddr, &__pNewObj);
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
namespace Net {
class CHttpCookie
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICHttpCookieClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CHttpCookie, RGM_SAME_DOMAIN,
                EIID_ICHttpCookieClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithNameValue(name, value, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ Elastos::Net::IHttpCookie** __IHttpCookie)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IHttpCookie = (Elastos::Net::IHttpCookie*)__pNewObj->Probe(Elastos::Net::EIID_IHttpCookie);
        if (*__IHttpCookie) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, value, &__pNewObj);
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
namespace Net {
class CHttpCookieHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Net::IHttpCookieHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHttpCookieHelper, RGM_SAME_DOMAIN, Elastos::Net::EIID_IHttpCookieHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHttpCookieHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHttpCookieHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHttpCookieHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Net {
class CInet4Address
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * address,
        /* [in] */ const _ELASTOS String& hostName,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInet4AddressClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInet4Address, RGM_SAME_DOMAIN,
                EIID_ICInet4AddressClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithAddressHostName(address, hostName, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * address,
        /* [in] */ const _ELASTOS String& hostName,
        /* [out] */ Elastos::Net::IInet4Address** __IInet4Address)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, hostName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInet4Address = (Elastos::Net::IInet4Address*)__pNewObj->Probe(Elastos::Net::EIID_IInet4Address);
        if (*__IInet4Address) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * address,
        /* [in] */ const _ELASTOS String& hostName,
        /* [out] */ Elastos::Net::IInetAddress** __IInetAddress)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, hostName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInetAddress = (Elastos::Net::IInetAddress*)__pNewObj->Probe(Elastos::Net::EIID_IInetAddress);
        if (*__IInetAddress) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * address,
        /* [in] */ const _ELASTOS String& hostName,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, hostName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * address,
        /* [in] */ const _ELASTOS String& hostName,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, hostName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * address,
        /* [in] */ const _ELASTOS String& hostName,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, hostName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * address,
        /* [in] */ const _ELASTOS String& hostName,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, hostName, &__pNewObj);
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
namespace Net {
class CInet4AddressHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Net::IInet4AddressHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInet4AddressHelper, RGM_SAME_DOMAIN, Elastos::Net::EIID_IInet4AddressHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInet4AddressHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInet4AddressHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInet4AddressHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Net {
class CInet6Address
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * address,
        /* [in] */ const _ELASTOS String& hostName,
        /* [in] */ _ELASTOS Int32 scope_id,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInet6AddressClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInet6Address, RGM_SAME_DOMAIN,
                EIID_ICInet6AddressClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithAddressHostNameScope_id(address, hostName, scope_id, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * address,
        /* [in] */ const _ELASTOS String& hostName,
        /* [in] */ _ELASTOS Int32 scope_id,
        /* [out] */ Elastos::Net::IInet6Address** __IInet6Address)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, hostName, scope_id, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInet6Address = (Elastos::Net::IInet6Address*)__pNewObj->Probe(Elastos::Net::EIID_IInet6Address);
        if (*__IInet6Address) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * address,
        /* [in] */ const _ELASTOS String& hostName,
        /* [in] */ _ELASTOS Int32 scope_id,
        /* [out] */ Elastos::Net::IInetAddress** __IInetAddress)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, hostName, scope_id, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInetAddress = (Elastos::Net::IInetAddress*)__pNewObj->Probe(Elastos::Net::EIID_IInetAddress);
        if (*__IInetAddress) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * address,
        /* [in] */ const _ELASTOS String& hostName,
        /* [in] */ _ELASTOS Int32 scope_id,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, hostName, scope_id, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * address,
        /* [in] */ const _ELASTOS String& hostName,
        /* [in] */ _ELASTOS Int32 scope_id,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, hostName, scope_id, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * address,
        /* [in] */ const _ELASTOS String& hostName,
        /* [in] */ _ELASTOS Int32 scope_id,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, hostName, scope_id, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * address,
        /* [in] */ const _ELASTOS String& hostName,
        /* [in] */ _ELASTOS Int32 scope_id,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, hostName, scope_id, &__pNewObj);
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
namespace Net {
class CInet6AddressHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Net::IInet6AddressHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInet6AddressHelper, RGM_SAME_DOMAIN, Elastos::Net::EIID_IInet6AddressHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInet6AddressHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInet6AddressHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInet6AddressHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Net {
class CInetUnixAddress
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& path,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInetUnixAddressClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInetUnixAddress, RGM_SAME_DOMAIN,
                EIID_ICInetUnixAddressClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPath(path, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * bytesPath,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInetUnixAddressClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInetUnixAddress, RGM_SAME_DOMAIN,
                EIID_ICInetUnixAddressClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithBytesPath(bytesPath, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& path,
        /* [out] */ Elastos::Net::IInetAddress** __IInetAddress)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(path, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInetAddress = (Elastos::Net::IInetAddress*)__pNewObj->Probe(Elastos::Net::EIID_IInetAddress);
        if (*__IInetAddress) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& path,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(path, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& path,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(path, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& path,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(path, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& path,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(path, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * bytesPath,
        /* [out] */ Elastos::Net::IInetAddress** __IInetAddress)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(bytesPath, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInetAddress = (Elastos::Net::IInetAddress*)__pNewObj->Probe(Elastos::Net::EIID_IInetAddress);
        if (*__IInetAddress) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * bytesPath,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(bytesPath, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * bytesPath,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(bytesPath, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * bytesPath,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(bytesPath, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * bytesPath,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(bytesPath, &__pNewObj);
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
namespace Net {
class CInetSocketAddress
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInetSocketAddressClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInetSocketAddress, RGM_SAME_DOMAIN,
                EIID_ICInetSocketAddressClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPort(port, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Net::IInetAddress * address,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInetSocketAddressClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInetSocketAddress, RGM_SAME_DOMAIN,
                EIID_ICInetSocketAddressClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithAddressPort(address, port, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInetSocketAddressClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInetSocketAddress, RGM_SAME_DOMAIN,
                EIID_ICInetSocketAddressClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithHostPort(host, port, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& hostname,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean needResolved,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInetSocketAddressClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInetSocketAddress, RGM_SAME_DOMAIN,
                EIID_ICInetSocketAddressClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithHostnamePortNeedResolved(hostname, port, needResolved, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::IInetSocketAddress** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInetSocketAddress, RGM_SAME_DOMAIN, Elastos::Net::EIID_IInetSocketAddress, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::ISocketAddress** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInetSocketAddress, RGM_SAME_DOMAIN, Elastos::Net::EIID_ISocketAddress, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInetSocketAddress, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInetSocketAddress, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInetSocketAddress, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInetSocketAddress, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Net::IInetSocketAddress** __IInetSocketAddress)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInetSocketAddress = (Elastos::Net::IInetSocketAddress*)__pNewObj->Probe(Elastos::Net::EIID_IInetSocketAddress);
        if (*__IInetSocketAddress) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Net::ISocketAddress** __ISocketAddress)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISocketAddress = (Elastos::Net::ISocketAddress*)__pNewObj->Probe(Elastos::Net::EIID_ISocketAddress);
        if (*__ISocketAddress) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IInetAddress * address,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Net::IInetSocketAddress** __IInetSocketAddress)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInetSocketAddress = (Elastos::Net::IInetSocketAddress*)__pNewObj->Probe(Elastos::Net::EIID_IInetSocketAddress);
        if (*__IInetSocketAddress) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IInetAddress * address,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Net::ISocketAddress** __ISocketAddress)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISocketAddress = (Elastos::Net::ISocketAddress*)__pNewObj->Probe(Elastos::Net::EIID_ISocketAddress);
        if (*__ISocketAddress) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IInetAddress * address,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IInetAddress * address,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IInetAddress * address,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IInetAddress * address,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Net::IInetSocketAddress** __IInetSocketAddress)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(host, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInetSocketAddress = (Elastos::Net::IInetSocketAddress*)__pNewObj->Probe(Elastos::Net::EIID_IInetSocketAddress);
        if (*__IInetSocketAddress) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Net::ISocketAddress** __ISocketAddress)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(host, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISocketAddress = (Elastos::Net::ISocketAddress*)__pNewObj->Probe(Elastos::Net::EIID_ISocketAddress);
        if (*__ISocketAddress) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(host, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(host, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(host, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(host, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& hostname,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean needResolved,
        /* [out] */ Elastos::Net::IInetSocketAddress** __IInetSocketAddress)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(hostname, port, needResolved, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInetSocketAddress = (Elastos::Net::IInetSocketAddress*)__pNewObj->Probe(Elastos::Net::EIID_IInetSocketAddress);
        if (*__IInetSocketAddress) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& hostname,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean needResolved,
        /* [out] */ Elastos::Net::ISocketAddress** __ISocketAddress)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(hostname, port, needResolved, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISocketAddress = (Elastos::Net::ISocketAddress*)__pNewObj->Probe(Elastos::Net::EIID_ISocketAddress);
        if (*__ISocketAddress) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& hostname,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean needResolved,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(hostname, port, needResolved, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& hostname,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean needResolved,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(hostname, port, needResolved, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& hostname,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean needResolved,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(hostname, port, needResolved, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& hostname,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean needResolved,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(hostname, port, needResolved, &__pNewObj);
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
namespace Net {
class CInetSocketAddressHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Net::IInetSocketAddressHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInetSocketAddressHelper, RGM_SAME_DOMAIN, Elastos::Net::EIID_IInetSocketAddressHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInetSocketAddressHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInetSocketAddressHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInetSocketAddressHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Net {
class CMulticastSocket
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 aPort,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICMulticastSocketClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CMulticastSocket, RGM_SAME_DOMAIN,
                EIID_ICMulticastSocketClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithAPort(aPort, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Net::ISocketAddress * localAddr,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICMulticastSocketClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CMulticastSocket, RGM_SAME_DOMAIN,
                EIID_ICMulticastSocketClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithLocalAddr(localAddr, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::IMulticastSocket** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMulticastSocket, RGM_SAME_DOMAIN, Elastos::Net::EIID_IMulticastSocket, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::IDatagramSocket** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMulticastSocket, RGM_SAME_DOMAIN, Elastos::Net::EIID_IDatagramSocket, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ICloseable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMulticastSocket, RGM_SAME_DOMAIN, Elastos::IO::EIID_ICloseable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMulticastSocket, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMulticastSocket, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMulticastSocket, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 aPort,
        /* [out] */ Elastos::Net::IMulticastSocket** __IMulticastSocket)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(aPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMulticastSocket = (Elastos::Net::IMulticastSocket*)__pNewObj->Probe(Elastos::Net::EIID_IMulticastSocket);
        if (*__IMulticastSocket) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 aPort,
        /* [out] */ Elastos::Net::IDatagramSocket** __IDatagramSocket)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(aPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDatagramSocket = (Elastos::Net::IDatagramSocket*)__pNewObj->Probe(Elastos::Net::EIID_IDatagramSocket);
        if (*__IDatagramSocket) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 aPort,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(aPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 aPort,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(aPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 aPort,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(aPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 aPort,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(aPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ISocketAddress * localAddr,
        /* [out] */ Elastos::Net::IMulticastSocket** __IMulticastSocket)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(localAddr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMulticastSocket = (Elastos::Net::IMulticastSocket*)__pNewObj->Probe(Elastos::Net::EIID_IMulticastSocket);
        if (*__IMulticastSocket) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ISocketAddress * localAddr,
        /* [out] */ Elastos::Net::IDatagramSocket** __IDatagramSocket)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(localAddr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDatagramSocket = (Elastos::Net::IDatagramSocket*)__pNewObj->Probe(Elastos::Net::EIID_IDatagramSocket);
        if (*__IDatagramSocket) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ISocketAddress * localAddr,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(localAddr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ISocketAddress * localAddr,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(localAddr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ISocketAddress * localAddr,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(localAddr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ISocketAddress * localAddr,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(localAddr, &__pNewObj);
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
namespace Net {
class CNetPermission
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICNetPermissionClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CNetPermission, RGM_SAME_DOMAIN,
                EIID_ICNetPermissionClassObject, (IInterface**)&pClassObject);
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
        ICNetPermissionClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CNetPermission, RGM_SAME_DOMAIN,
                EIID_ICNetPermissionClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithNameActions(name, actions, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Net::INetPermission** __INetPermission)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INetPermission = (Elastos::Net::INetPermission*)__pNewObj->Probe(Elastos::Net::EIID_INetPermission);
        if (*__INetPermission) __pNewObj->AddRef();
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
        /* [out] */ Elastos::Net::INetPermission** __INetPermission)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, actions, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INetPermission = (Elastos::Net::INetPermission*)__pNewObj->Probe(Elastos::Net::EIID_INetPermission);
        if (*__INetPermission) __pNewObj->AddRef();
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
namespace Net {
class CPasswordAuthentication
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& userName,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPasswordAuthenticationClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPasswordAuthentication, RGM_SAME_DOMAIN,
                EIID_ICPasswordAuthenticationClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithUserNamePassword(userName, password, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& userName,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [out] */ Elastos::Net::IPasswordAuthentication** __IPasswordAuthentication)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(userName, password, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPasswordAuthentication = (Elastos::Net::IPasswordAuthentication*)__pNewObj->Probe(Elastos::Net::EIID_IPasswordAuthentication);
        if (*__IPasswordAuthentication) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& userName,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(userName, password, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& userName,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(userName, password, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& userName,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * password,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(userName, password, &__pNewObj);
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
namespace Net {
class CPlainDatagramSocketImpl
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPlainDatagramSocketImplClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPlainDatagramSocketImpl, RGM_SAME_DOMAIN,
                EIID_ICPlainDatagramSocketImplClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFdLocalPort(fd, localPort, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::IPlainDatagramSocketImpl** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPlainDatagramSocketImpl, RGM_SAME_DOMAIN, Elastos::Net::EIID_IPlainDatagramSocketImpl, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::IDatagramSocketImpl** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPlainDatagramSocketImpl, RGM_SAME_DOMAIN, Elastos::Net::EIID_IDatagramSocketImpl, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::ISocketOptions** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPlainDatagramSocketImpl, RGM_SAME_DOMAIN, Elastos::Net::EIID_ISocketOptions, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPlainDatagramSocketImpl, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPlainDatagramSocketImpl, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPlainDatagramSocketImpl, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ Elastos::Net::IPlainDatagramSocketImpl** __IPlainDatagramSocketImpl)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, localPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPlainDatagramSocketImpl = (Elastos::Net::IPlainDatagramSocketImpl*)__pNewObj->Probe(Elastos::Net::EIID_IPlainDatagramSocketImpl);
        if (*__IPlainDatagramSocketImpl) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ Elastos::Net::IDatagramSocketImpl** __IDatagramSocketImpl)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, localPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDatagramSocketImpl = (Elastos::Net::IDatagramSocketImpl*)__pNewObj->Probe(Elastos::Net::EIID_IDatagramSocketImpl);
        if (*__IDatagramSocketImpl) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ Elastos::Net::ISocketOptions** __ISocketOptions)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, localPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISocketOptions = (Elastos::Net::ISocketOptions*)__pNewObj->Probe(Elastos::Net::EIID_ISocketOptions);
        if (*__ISocketOptions) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, localPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, localPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, localPort, &__pNewObj);
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
namespace Net {
class CPlainServerSocketImpl
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPlainServerSocketImplClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPlainServerSocketImpl, RGM_SAME_DOMAIN,
                EIID_ICPlainServerSocketImplClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPFd(pFd, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::ISocketOptions** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPlainServerSocketImpl, RGM_SAME_DOMAIN, Elastos::Net::EIID_ISocketOptions, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::ISocketImpl** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPlainServerSocketImpl, RGM_SAME_DOMAIN, Elastos::Net::EIID_ISocketImpl, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::IPlainSocketImpl** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPlainServerSocketImpl, RGM_SAME_DOMAIN, Elastos::Net::EIID_IPlainSocketImpl, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::IPlainServerSocketImpl** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPlainServerSocketImpl, RGM_SAME_DOMAIN, Elastos::Net::EIID_IPlainServerSocketImpl, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPlainServerSocketImpl, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPlainServerSocketImpl, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPlainServerSocketImpl, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [out] */ Elastos::Net::ISocketOptions** __ISocketOptions)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pFd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISocketOptions = (Elastos::Net::ISocketOptions*)__pNewObj->Probe(Elastos::Net::EIID_ISocketOptions);
        if (*__ISocketOptions) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [out] */ Elastos::Net::ISocketImpl** __ISocketImpl)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pFd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISocketImpl = (Elastos::Net::ISocketImpl*)__pNewObj->Probe(Elastos::Net::EIID_ISocketImpl);
        if (*__ISocketImpl) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [out] */ Elastos::Net::IPlainSocketImpl** __IPlainSocketImpl)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pFd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPlainSocketImpl = (Elastos::Net::IPlainSocketImpl*)__pNewObj->Probe(Elastos::Net::EIID_IPlainSocketImpl);
        if (*__IPlainSocketImpl) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [out] */ Elastos::Net::IPlainServerSocketImpl** __IPlainServerSocketImpl)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pFd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPlainServerSocketImpl = (Elastos::Net::IPlainServerSocketImpl*)__pNewObj->Probe(Elastos::Net::EIID_IPlainServerSocketImpl);
        if (*__IPlainServerSocketImpl) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pFd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pFd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pFd, &__pNewObj);
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
namespace Net {
class CPlainSocketImpl
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPlainSocketImplClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPlainSocketImpl, RGM_SAME_DOMAIN,
                EIID_ICPlainSocketImplClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPFd(pFd, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Net::IProxy * pProxy,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPlainSocketImplClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPlainSocketImpl, RGM_SAME_DOMAIN,
                EIID_ICPlainSocketImplClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPProxy(pProxy, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [in] */ _ELASTOS Int32 localport,
        /* [in] */ Elastos::Net::IInetAddress * pAddr,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPlainSocketImplClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPlainSocketImpl, RGM_SAME_DOMAIN,
                EIID_ICPlainSocketImplClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPFdLocalportPAddrPort(pFd, localport, pAddr, port, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::ISocketOptions** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPlainSocketImpl, RGM_SAME_DOMAIN, Elastos::Net::EIID_ISocketOptions, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::ISocketImpl** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPlainSocketImpl, RGM_SAME_DOMAIN, Elastos::Net::EIID_ISocketImpl, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::IPlainSocketImpl** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPlainSocketImpl, RGM_SAME_DOMAIN, Elastos::Net::EIID_IPlainSocketImpl, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPlainSocketImpl, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPlainSocketImpl, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPlainSocketImpl, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [out] */ Elastos::Net::ISocketOptions** __ISocketOptions)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pFd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISocketOptions = (Elastos::Net::ISocketOptions*)__pNewObj->Probe(Elastos::Net::EIID_ISocketOptions);
        if (*__ISocketOptions) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [out] */ Elastos::Net::ISocketImpl** __ISocketImpl)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pFd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISocketImpl = (Elastos::Net::ISocketImpl*)__pNewObj->Probe(Elastos::Net::EIID_ISocketImpl);
        if (*__ISocketImpl) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [out] */ Elastos::Net::IPlainSocketImpl** __IPlainSocketImpl)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pFd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPlainSocketImpl = (Elastos::Net::IPlainSocketImpl*)__pNewObj->Probe(Elastos::Net::EIID_IPlainSocketImpl);
        if (*__IPlainSocketImpl) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pFd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pFd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pFd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IProxy * pProxy,
        /* [out] */ Elastos::Net::ISocketOptions** __ISocketOptions)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pProxy, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISocketOptions = (Elastos::Net::ISocketOptions*)__pNewObj->Probe(Elastos::Net::EIID_ISocketOptions);
        if (*__ISocketOptions) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IProxy * pProxy,
        /* [out] */ Elastos::Net::ISocketImpl** __ISocketImpl)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pProxy, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISocketImpl = (Elastos::Net::ISocketImpl*)__pNewObj->Probe(Elastos::Net::EIID_ISocketImpl);
        if (*__ISocketImpl) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IProxy * pProxy,
        /* [out] */ Elastos::Net::IPlainSocketImpl** __IPlainSocketImpl)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pProxy, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPlainSocketImpl = (Elastos::Net::IPlainSocketImpl*)__pNewObj->Probe(Elastos::Net::EIID_IPlainSocketImpl);
        if (*__IPlainSocketImpl) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IProxy * pProxy,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pProxy, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IProxy * pProxy,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pProxy, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IProxy * pProxy,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pProxy, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [in] */ _ELASTOS Int32 localport,
        /* [in] */ Elastos::Net::IInetAddress * pAddr,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Net::ISocketOptions** __ISocketOptions)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pFd, localport, pAddr, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISocketOptions = (Elastos::Net::ISocketOptions*)__pNewObj->Probe(Elastos::Net::EIID_ISocketOptions);
        if (*__ISocketOptions) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [in] */ _ELASTOS Int32 localport,
        /* [in] */ Elastos::Net::IInetAddress * pAddr,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Net::ISocketImpl** __ISocketImpl)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pFd, localport, pAddr, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISocketImpl = (Elastos::Net::ISocketImpl*)__pNewObj->Probe(Elastos::Net::EIID_ISocketImpl);
        if (*__ISocketImpl) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [in] */ _ELASTOS Int32 localport,
        /* [in] */ Elastos::Net::IInetAddress * pAddr,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Net::IPlainSocketImpl** __IPlainSocketImpl)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pFd, localport, pAddr, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPlainSocketImpl = (Elastos::Net::IPlainSocketImpl*)__pNewObj->Probe(Elastos::Net::EIID_IPlainSocketImpl);
        if (*__IPlainSocketImpl) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [in] */ _ELASTOS Int32 localport,
        /* [in] */ Elastos::Net::IInetAddress * pAddr,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pFd, localport, pAddr, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [in] */ _ELASTOS Int32 localport,
        /* [in] */ Elastos::Net::IInetAddress * pAddr,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pFd, localport, pAddr, port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * pFd,
        /* [in] */ _ELASTOS Int32 localport,
        /* [in] */ Elastos::Net::IInetAddress * pAddr,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pFd, localport, pAddr, port, &__pNewObj);
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
namespace Net {
class CPlainSocketInputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Net::ISocketImpl * socketImpl,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPlainSocketInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPlainSocketInputStream, RGM_SAME_DOMAIN,
                EIID_ICPlainSocketInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSocketImpl(socketImpl, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ISocketImpl * socketImpl,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(socketImpl, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ISocketImpl * socketImpl,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(socketImpl, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ISocketImpl * socketImpl,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(socketImpl, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ISocketImpl * socketImpl,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(socketImpl, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ISocketImpl * socketImpl,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(socketImpl, &__pNewObj);
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
namespace Net {
class CPlainSocketOutputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Net::ISocketImpl * socketImpl,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPlainSocketOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPlainSocketOutputStream, RGM_SAME_DOMAIN,
                EIID_ICPlainSocketOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSocketImpl(socketImpl, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ISocketImpl * socketImpl,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(socketImpl, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ISocketImpl * socketImpl,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(socketImpl, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ISocketImpl * socketImpl,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(socketImpl, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ISocketImpl * socketImpl,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(socketImpl, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ISocketImpl * socketImpl,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(socketImpl, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ISocketImpl * socketImpl,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(socketImpl, &__pNewObj);
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
namespace Net {
class CProxy
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Net::ProxyType type,
        /* [in] */ Elastos::Net::ISocketAddress * sa,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICProxyClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CProxy, RGM_SAME_DOMAIN,
                EIID_ICProxyClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTypeSa(type, sa, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::IProxy** __object)
    {
        return _CObject_CreateInstance(ECLSID_CProxy, RGM_SAME_DOMAIN, Elastos::Net::EIID_IProxy, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CProxy, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CProxy, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CProxy, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ProxyType type,
        /* [in] */ Elastos::Net::ISocketAddress * sa,
        /* [out] */ Elastos::Net::IProxy** __IProxy)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(type, sa, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IProxy = (Elastos::Net::IProxy*)__pNewObj->Probe(Elastos::Net::EIID_IProxy);
        if (*__IProxy) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ProxyType type,
        /* [in] */ Elastos::Net::ISocketAddress * sa,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(type, sa, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ProxyType type,
        /* [in] */ Elastos::Net::ISocketAddress * sa,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(type, sa, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::ProxyType type,
        /* [in] */ Elastos::Net::ISocketAddress * sa,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(type, sa, &__pNewObj);
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
namespace Net {
class CProxyHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Net::IProxyHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CProxyHelper, RGM_SAME_DOMAIN, Elastos::Net::EIID_IProxyHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CProxyHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CProxyHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CProxyHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Net {
class CResponseCacheHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Net::IResponseCacheHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CResponseCacheHelper, RGM_SAME_DOMAIN, Elastos::Net::EIID_IResponseCacheHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CResponseCacheHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CResponseCacheHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CResponseCacheHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Net {
class CServerSocket
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICServerSocketClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CServerSocket, RGM_SAME_DOMAIN,
                EIID_ICServerSocketClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPort(port, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Int32 backlog,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICServerSocketClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CServerSocket, RGM_SAME_DOMAIN,
                EIID_ICServerSocketClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPortBacklog(port, backlog, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Int32 backlog,
        /* [in] */ Elastos::Net::IInetAddress * localAddress,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICServerSocketClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CServerSocket, RGM_SAME_DOMAIN,
                EIID_ICServerSocketClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPortBacklogLocalAddress(port, backlog, localAddress, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::IServerSocket** __object)
    {
        return _CObject_CreateInstance(ECLSID_CServerSocket, RGM_SAME_DOMAIN, Elastos::Net::EIID_IServerSocket, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ICloseable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CServerSocket, RGM_SAME_DOMAIN, Elastos::IO::EIID_ICloseable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CServerSocket, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CServerSocket, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CServerSocket, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Net::IServerSocket** __IServerSocket)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IServerSocket = (Elastos::Net::IServerSocket*)__pNewObj->Probe(Elastos::Net::EIID_IServerSocket);
        if (*__IServerSocket) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(port, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Int32 backlog,
        /* [out] */ Elastos::Net::IServerSocket** __IServerSocket)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(port, backlog, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IServerSocket = (Elastos::Net::IServerSocket*)__pNewObj->Probe(Elastos::Net::EIID_IServerSocket);
        if (*__IServerSocket) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Int32 backlog,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(port, backlog, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Int32 backlog,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(port, backlog, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Int32 backlog,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(port, backlog, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Int32 backlog,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(port, backlog, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Int32 backlog,
        /* [in] */ Elastos::Net::IInetAddress * localAddress,
        /* [out] */ Elastos::Net::IServerSocket** __IServerSocket)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(port, backlog, localAddress, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IServerSocket = (Elastos::Net::IServerSocket*)__pNewObj->Probe(Elastos::Net::EIID_IServerSocket);
        if (*__IServerSocket) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Int32 backlog,
        /* [in] */ Elastos::Net::IInetAddress * localAddress,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(port, backlog, localAddress, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Int32 backlog,
        /* [in] */ Elastos::Net::IInetAddress * localAddress,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(port, backlog, localAddress, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Int32 backlog,
        /* [in] */ Elastos::Net::IInetAddress * localAddress,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(port, backlog, localAddress, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Int32 backlog,
        /* [in] */ Elastos::Net::IInetAddress * localAddress,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(port, backlog, localAddress, &__pNewObj);
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
namespace Net {
class CServerSocketHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Net::IServerSocketHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CServerSocketHelper, RGM_SAME_DOMAIN, Elastos::Net::EIID_IServerSocketHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CServerSocketHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CServerSocketHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CServerSocketHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Net {
class CSocket
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Net::IProxy * proxy,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSocketClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSocket, RGM_SAME_DOMAIN,
                EIID_ICSocketClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithProxy(proxy, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& dstName,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSocketClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSocket, RGM_SAME_DOMAIN,
                EIID_ICSocketClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithDstNameDstPort(dstName, dstPort, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& dstName,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [in] */ Elastos::Net::IInetAddress * localAddress,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSocketClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSocket, RGM_SAME_DOMAIN,
                EIID_ICSocketClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithDstNameDstPortLocalAddressLocalPort(dstName, dstPort, localAddress, localPort, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& hostName,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean streaming,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSocketClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSocket, RGM_SAME_DOMAIN,
                EIID_ICSocketClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithHostNamePortStreaming(hostName, port, streaming, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Net::IInetAddress * dstAddress,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSocketClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSocket, RGM_SAME_DOMAIN,
                EIID_ICSocketClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithDstAddressDstPort(dstAddress, dstPort, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Net::IInetAddress * dstAddress,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [in] */ Elastos::Net::IInetAddress * localAddress,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSocketClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSocket, RGM_SAME_DOMAIN,
                EIID_ICSocketClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithDstAddressDstPortLocalAddressLocalPort(dstAddress, dstPort, localAddress, localPort, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Net::IInetAddress * addr,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean streaming,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSocketClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSocket, RGM_SAME_DOMAIN,
                EIID_ICSocketClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithAddrPortStreaming(addr, port, streaming, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::ISocket** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSocket, RGM_SAME_DOMAIN, Elastos::Net::EIID_ISocket, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ICloseable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSocket, RGM_SAME_DOMAIN, Elastos::IO::EIID_ICloseable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSocket, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSocket, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSocket, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IProxy * proxy,
        /* [out] */ Elastos::Net::ISocket** __ISocket)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(proxy, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISocket = (Elastos::Net::ISocket*)__pNewObj->Probe(Elastos::Net::EIID_ISocket);
        if (*__ISocket) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IProxy * proxy,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(proxy, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IProxy * proxy,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(proxy, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IProxy * proxy,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(proxy, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IProxy * proxy,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(proxy, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& dstName,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [out] */ Elastos::Net::ISocket** __ISocket)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dstName, dstPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISocket = (Elastos::Net::ISocket*)__pNewObj->Probe(Elastos::Net::EIID_ISocket);
        if (*__ISocket) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& dstName,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dstName, dstPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& dstName,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dstName, dstPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& dstName,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dstName, dstPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& dstName,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dstName, dstPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& dstName,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [in] */ Elastos::Net::IInetAddress * localAddress,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ Elastos::Net::ISocket** __ISocket)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dstName, dstPort, localAddress, localPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISocket = (Elastos::Net::ISocket*)__pNewObj->Probe(Elastos::Net::EIID_ISocket);
        if (*__ISocket) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& dstName,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [in] */ Elastos::Net::IInetAddress * localAddress,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dstName, dstPort, localAddress, localPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& dstName,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [in] */ Elastos::Net::IInetAddress * localAddress,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dstName, dstPort, localAddress, localPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& dstName,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [in] */ Elastos::Net::IInetAddress * localAddress,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dstName, dstPort, localAddress, localPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& dstName,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [in] */ Elastos::Net::IInetAddress * localAddress,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dstName, dstPort, localAddress, localPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& hostName,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean streaming,
        /* [out] */ Elastos::Net::ISocket** __ISocket)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(hostName, port, streaming, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISocket = (Elastos::Net::ISocket*)__pNewObj->Probe(Elastos::Net::EIID_ISocket);
        if (*__ISocket) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& hostName,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean streaming,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(hostName, port, streaming, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& hostName,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean streaming,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(hostName, port, streaming, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& hostName,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean streaming,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(hostName, port, streaming, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& hostName,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean streaming,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(hostName, port, streaming, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IInetAddress * dstAddress,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [out] */ Elastos::Net::ISocket** __ISocket)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dstAddress, dstPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISocket = (Elastos::Net::ISocket*)__pNewObj->Probe(Elastos::Net::EIID_ISocket);
        if (*__ISocket) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IInetAddress * dstAddress,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dstAddress, dstPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IInetAddress * dstAddress,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dstAddress, dstPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IInetAddress * dstAddress,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dstAddress, dstPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IInetAddress * dstAddress,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dstAddress, dstPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IInetAddress * dstAddress,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [in] */ Elastos::Net::IInetAddress * localAddress,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ Elastos::Net::ISocket** __ISocket)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dstAddress, dstPort, localAddress, localPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISocket = (Elastos::Net::ISocket*)__pNewObj->Probe(Elastos::Net::EIID_ISocket);
        if (*__ISocket) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IInetAddress * dstAddress,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [in] */ Elastos::Net::IInetAddress * localAddress,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dstAddress, dstPort, localAddress, localPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IInetAddress * dstAddress,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [in] */ Elastos::Net::IInetAddress * localAddress,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dstAddress, dstPort, localAddress, localPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IInetAddress * dstAddress,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [in] */ Elastos::Net::IInetAddress * localAddress,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dstAddress, dstPort, localAddress, localPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IInetAddress * dstAddress,
        /* [in] */ _ELASTOS Int32 dstPort,
        /* [in] */ Elastos::Net::IInetAddress * localAddress,
        /* [in] */ _ELASTOS Int32 localPort,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dstAddress, dstPort, localAddress, localPort, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IInetAddress * addr,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean streaming,
        /* [out] */ Elastos::Net::ISocket** __ISocket)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(addr, port, streaming, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISocket = (Elastos::Net::ISocket*)__pNewObj->Probe(Elastos::Net::EIID_ISocket);
        if (*__ISocket) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IInetAddress * addr,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean streaming,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(addr, port, streaming, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IInetAddress * addr,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean streaming,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(addr, port, streaming, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IInetAddress * addr,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean streaming,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(addr, port, streaming, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IInetAddress * addr,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Boolean streaming,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(addr, port, streaming, &__pNewObj);
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
namespace Net {
class CSocketHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Net::ISocketHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSocketHelper, RGM_SAME_DOMAIN, Elastos::Net::EIID_ISocketHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSocketHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSocketHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSocketHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Net {
class CSocketPermission
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& action,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSocketPermissionClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSocketPermission, RGM_SAME_DOMAIN,
                EIID_ICSocketPermissionClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithHostAction(host, action, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& action,
        /* [out] */ Elastos::Net::ISocketPermission** __ISocketPermission)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(host, action, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISocketPermission = (Elastos::Net::ISocketPermission*)__pNewObj->Probe(Elastos::Net::EIID_ISocketPermission);
        if (*__ISocketPermission) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& action,
        /* [out] */ Elastos::Security::IPermission** __IPermission)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(host, action, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPermission = (Elastos::Security::IPermission*)__pNewObj->Probe(Elastos::Security::EIID_IPermission);
        if (*__IPermission) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& action,
        /* [out] */ Elastos::Security::IGuard** __IGuard)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(host, action, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IGuard = (Elastos::Security::IGuard*)__pNewObj->Probe(Elastos::Security::EIID_IGuard);
        if (*__IGuard) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& action,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(host, action, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& action,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(host, action, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& action,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(host, action, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& action,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(host, action, &__pNewObj);
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
namespace Net {
class CSocks4Message
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::ISocks4Message** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSocks4Message, RGM_SAME_DOMAIN, Elastos::Net::EIID_ISocks4Message, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSocks4Message, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSocks4Message, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSocks4Message, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Net {
class CURI
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& spec,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICURIClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CURI, RGM_SAME_DOMAIN,
                EIID_ICURIClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSpec(spec, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& schemeSpecificPart,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICURIClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CURI, RGM_SAME_DOMAIN,
                EIID_ICURIClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSchemeSchemeSpecificPartFragment(scheme, schemeSpecificPart, fragment, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& userInfo,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& query,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICURIClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CURI, RGM_SAME_DOMAIN,
                EIID_ICURIClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSchemeUserInfoHostPortPathQueryFragment(scheme, userInfo, host, port, path, query, fragment, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICURIClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CURI, RGM_SAME_DOMAIN,
                EIID_ICURIClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSchemeHostPathFragment(scheme, host, path, fragment, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& authority,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& query,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICURIClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CURI, RGM_SAME_DOMAIN,
                EIID_ICURIClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSchemeAuthorityPathQueryFragment(scheme, authority, path, query, fragment, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::IURI** __object)
    {
        return _CObject_CreateInstance(ECLSID_CURI, RGM_SAME_DOMAIN, Elastos::Net::EIID_IURI, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::IComparable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CURI, RGM_SAME_DOMAIN, Elastos::Core::EIID_IComparable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CURI, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CURI, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CURI, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CURI, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& spec,
        /* [out] */ Elastos::Net::IURI** __IURI)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(spec, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IURI = (Elastos::Net::IURI*)__pNewObj->Probe(Elastos::Net::EIID_IURI);
        if (*__IURI) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& spec,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(spec, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& spec,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(spec, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& spec,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(spec, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& spec,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(spec, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& spec,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(spec, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& schemeSpecificPart,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ Elastos::Net::IURI** __IURI)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, schemeSpecificPart, fragment, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IURI = (Elastos::Net::IURI*)__pNewObj->Probe(Elastos::Net::EIID_IURI);
        if (*__IURI) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& schemeSpecificPart,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, schemeSpecificPart, fragment, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& schemeSpecificPart,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, schemeSpecificPart, fragment, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& schemeSpecificPart,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, schemeSpecificPart, fragment, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& schemeSpecificPart,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, schemeSpecificPart, fragment, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& schemeSpecificPart,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, schemeSpecificPart, fragment, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& userInfo,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& query,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ Elastos::Net::IURI** __IURI)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, userInfo, host, port, path, query, fragment, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IURI = (Elastos::Net::IURI*)__pNewObj->Probe(Elastos::Net::EIID_IURI);
        if (*__IURI) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& userInfo,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& query,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, userInfo, host, port, path, query, fragment, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& userInfo,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& query,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, userInfo, host, port, path, query, fragment, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& userInfo,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& query,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, userInfo, host, port, path, query, fragment, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& userInfo,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& query,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, userInfo, host, port, path, query, fragment, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& userInfo,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& query,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, userInfo, host, port, path, query, fragment, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ Elastos::Net::IURI** __IURI)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, host, path, fragment, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IURI = (Elastos::Net::IURI*)__pNewObj->Probe(Elastos::Net::EIID_IURI);
        if (*__IURI) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, host, path, fragment, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, host, path, fragment, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, host, path, fragment, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, host, path, fragment, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, host, path, fragment, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& authority,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& query,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ Elastos::Net::IURI** __IURI)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, authority, path, query, fragment, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IURI = (Elastos::Net::IURI*)__pNewObj->Probe(Elastos::Net::EIID_IURI);
        if (*__IURI) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& authority,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& query,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, authority, path, query, fragment, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& authority,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& query,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, authority, path, query, fragment, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& authority,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& query,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, authority, path, query, fragment, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& authority,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& query,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, authority, path, query, fragment, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& scheme,
        /* [in] */ const _ELASTOS String& authority,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& query,
        /* [in] */ const _ELASTOS String& fragment,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(scheme, authority, path, query, fragment, &__pNewObj);
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
namespace Net {
class CURIHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Net::IURIHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CURIHelper, RGM_SAME_DOMAIN, Elastos::Net::EIID_IURIHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CURIHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CURIHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CURIHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Net {
class CURL
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& spec,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICURLClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CURL, RGM_SAME_DOMAIN,
                EIID_ICURLClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSpec(spec, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Net::IURL * context,
        /* [in] */ const _ELASTOS String& spec,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICURLClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CURL, RGM_SAME_DOMAIN,
                EIID_ICURLClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithContextSpec(context, spec, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Net::IURL * context,
        /* [in] */ const _ELASTOS String& spec,
        /* [in] */ Elastos::Net::IURLStreamHandler * handler,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICURLClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CURL, RGM_SAME_DOMAIN,
                EIID_ICURLClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithContextSpecHandler(context, spec, handler, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& file,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICURLClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CURL, RGM_SAME_DOMAIN,
                EIID_ICURLClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithProtocolHostFile(protocol, host, file, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& file,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICURLClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CURL, RGM_SAME_DOMAIN,
                EIID_ICURLClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithProtocolHostPortFile(protocol, host, port, file, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& file,
        /* [in] */ Elastos::Net::IURLStreamHandler * handler,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICURLClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CURL, RGM_SAME_DOMAIN,
                EIID_ICURLClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithProtocolHostPortFileHandler(protocol, host, port, file, handler, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& spec,
        /* [out] */ Elastos::Net::IURL** __IURL)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(spec, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IURL = (Elastos::Net::IURL*)__pNewObj->Probe(Elastos::Net::EIID_IURL);
        if (*__IURL) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& spec,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(spec, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& spec,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(spec, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& spec,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(spec, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& spec,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(spec, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * context,
        /* [in] */ const _ELASTOS String& spec,
        /* [out] */ Elastos::Net::IURL** __IURL)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(context, spec, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IURL = (Elastos::Net::IURL*)__pNewObj->Probe(Elastos::Net::EIID_IURL);
        if (*__IURL) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * context,
        /* [in] */ const _ELASTOS String& spec,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(context, spec, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * context,
        /* [in] */ const _ELASTOS String& spec,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(context, spec, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * context,
        /* [in] */ const _ELASTOS String& spec,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(context, spec, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * context,
        /* [in] */ const _ELASTOS String& spec,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(context, spec, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * context,
        /* [in] */ const _ELASTOS String& spec,
        /* [in] */ Elastos::Net::IURLStreamHandler * handler,
        /* [out] */ Elastos::Net::IURL** __IURL)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(context, spec, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IURL = (Elastos::Net::IURL*)__pNewObj->Probe(Elastos::Net::EIID_IURL);
        if (*__IURL) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * context,
        /* [in] */ const _ELASTOS String& spec,
        /* [in] */ Elastos::Net::IURLStreamHandler * handler,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(context, spec, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * context,
        /* [in] */ const _ELASTOS String& spec,
        /* [in] */ Elastos::Net::IURLStreamHandler * handler,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(context, spec, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * context,
        /* [in] */ const _ELASTOS String& spec,
        /* [in] */ Elastos::Net::IURLStreamHandler * handler,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(context, spec, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * context,
        /* [in] */ const _ELASTOS String& spec,
        /* [in] */ Elastos::Net::IURLStreamHandler * handler,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(context, spec, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& file,
        /* [out] */ Elastos::Net::IURL** __IURL)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(protocol, host, file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IURL = (Elastos::Net::IURL*)__pNewObj->Probe(Elastos::Net::EIID_IURL);
        if (*__IURL) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& file,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(protocol, host, file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& file,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(protocol, host, file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& file,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(protocol, host, file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ const _ELASTOS String& file,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(protocol, host, file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& file,
        /* [out] */ Elastos::Net::IURL** __IURL)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(protocol, host, port, file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IURL = (Elastos::Net::IURL*)__pNewObj->Probe(Elastos::Net::EIID_IURL);
        if (*__IURL) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& file,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(protocol, host, port, file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& file,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(protocol, host, port, file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& file,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(protocol, host, port, file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& file,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(protocol, host, port, file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& file,
        /* [in] */ Elastos::Net::IURLStreamHandler * handler,
        /* [out] */ Elastos::Net::IURL** __IURL)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(protocol, host, port, file, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IURL = (Elastos::Net::IURL*)__pNewObj->Probe(Elastos::Net::EIID_IURL);
        if (*__IURL) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& file,
        /* [in] */ Elastos::Net::IURLStreamHandler * handler,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(protocol, host, port, file, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& file,
        /* [in] */ Elastos::Net::IURLStreamHandler * handler,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(protocol, host, port, file, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& file,
        /* [in] */ Elastos::Net::IURLStreamHandler * handler,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(protocol, host, port, file, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& protocol,
        /* [in] */ const _ELASTOS String& host,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ const _ELASTOS String& file,
        /* [in] */ Elastos::Net::IURLStreamHandler * handler,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(protocol, host, port, file, handler, &__pNewObj);
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
namespace Net {
class CCookieHandlerHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Net::ICookieHandlerHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCookieHandlerHelper, RGM_SAME_DOMAIN, Elastos::Net::EIID_ICookieHandlerHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCookieHandlerHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCookieHandlerHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCookieHandlerHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Net {
class CCookiePolicyHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Net::ICookiePolicyHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCookiePolicyHelper, RGM_SAME_DOMAIN, Elastos::Net::EIID_ICookiePolicyHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCookiePolicyHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCookiePolicyHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCookiePolicyHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Net {
class CIDN
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Net::IIDN** __object)
    {
        return _CObject_CreateInstance(ECLSID_CIDN, RGM_SAME_DOMAIN, Elastos::Net::EIID_IIDN, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CIDN, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CIDN, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CIDN, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Net {
class CInetAddressHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Net::IInetAddressHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInetAddressHelper, RGM_SAME_DOMAIN, Elastos::Net::EIID_IInetAddressHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInetAddressHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInetAddressHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInetAddressHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Net {
class CNetworkInterfaceHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Net::INetworkInterfaceHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNetworkInterfaceHelper, RGM_SAME_DOMAIN, Elastos::Net::EIID_INetworkInterfaceHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNetworkInterfaceHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNetworkInterfaceHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNetworkInterfaceHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Net {
class CURLEncoder
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Net::IURLEncoder** __object)
    {
        return _CObject_CreateInstance(ECLSID_CURLEncoder, RGM_SAME_DOMAIN, Elastos::Net::EIID_IURLEncoder, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CURLEncoder, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CURLEncoder, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CURLEncoder, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Net {
class CURLDecoder
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Net::IURLDecoder** __object)
    {
        return _CObject_CreateInstance(ECLSID_CURLDecoder, RGM_SAME_DOMAIN, Elastos::Net::EIID_IURLDecoder, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CURLDecoder, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CURLDecoder, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CURLDecoder, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}

#endif // __Elastos_CoreLibrary_Net_h__
