#ifndef ___Elastos_CoreLibrary_Utility_Zip_h__
#define ___Elastos_CoreLibrary_Utility_Zip_h__

#include <Elastos.CoreLibrary.h>

EXTERN_C ELAPI _Impl_AcquireCallbackHandler(PInterface pServerObj, _ELASTOS REIID iid, PInterface *ppHandler);
EXTERN_C ELAPI _Impl_CheckClsId(PInterface pServerObj, const _ELASTOS ClassID* pClassid, PInterface *ppServerObj);

namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("B34A221C-C8D2-8CCE-1CDB-3719DFF6EFBC")
IZipConstants : public IInterface
{
    static const _ELASTOS Int64 LOCSIG;
    static const _ELASTOS Int64 EXTSIG;
    static const _ELASTOS Int64 CENSIG;
    static const _ELASTOS Int64 ENDSIG;
    static const _ELASTOS Int32 LOCHDR = 30;
    static const _ELASTOS Int32 EXTHDR = 16;
    static const _ELASTOS Int32 CENHDR = 46;
    static const _ELASTOS Int32 ENDHDR = 22;
    static const _ELASTOS Int32 LOCVER = 4;
    static const _ELASTOS Int32 LOCFLG = 6;
    static const _ELASTOS Int32 LOCHOW = 8;
    static const _ELASTOS Int32 LOCTIM = 10;
    static const _ELASTOS Int32 LOCCRC = 14;
    static const _ELASTOS Int32 LOCSIZ = 18;
    static const _ELASTOS Int32 LOCLEN = 22;
    static const _ELASTOS Int32 LOCNAM = 26;
    static const _ELASTOS Int32 LOCEXT = 28;
    static const _ELASTOS Int32 EXTCRC = 4;
    static const _ELASTOS Int32 EXTSIZ = 8;
    static const _ELASTOS Int32 EXTLEN = 12;
    static const _ELASTOS Int32 CENVEM = 4;
    static const _ELASTOS Int32 CENVER = 6;
    static const _ELASTOS Int32 CENFLG = 8;
    static const _ELASTOS Int32 CENHOW = 10;
    static const _ELASTOS Int32 CENTIM = 12;
    static const _ELASTOS Int32 CENCRC = 16;
    static const _ELASTOS Int32 CENSIZ = 20;
    static const _ELASTOS Int32 CENLEN = 24;
    static const _ELASTOS Int32 CENNAM = 28;
    static const _ELASTOS Int32 CENEXT = 30;
    static const _ELASTOS Int32 CENCOM = 32;
    static const _ELASTOS Int32 CENDSK = 34;
    static const _ELASTOS Int32 CENATT = 36;
    static const _ELASTOS Int32 CENATX = 38;
    static const _ELASTOS Int32 CENOFF = 42;
    static const _ELASTOS Int32 ENDSUB = 8;
    static const _ELASTOS Int32 ENDTOT = 10;
    static const _ELASTOS Int32 ENDSIZ = 12;
    static const _ELASTOS Int32 ENDOFF = 16;
    static const _ELASTOS Int32 ENDCOM = 20;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IZipConstants*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IZipConstants*)pObj->Probe(EIID_IZipConstants);
    }

    static CARAPI_(IZipConstants*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IZipConstants*)pObj->Probe(EIID_IZipConstants);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("65023D4A-90D2-9161-61FC-705052868D1F")
IChecksum : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IChecksum*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IChecksum*)pObj->Probe(EIID_IChecksum);
    }

    static CARAPI_(IChecksum*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IChecksum*)pObj->Probe(EIID_IChecksum);
    }

    virtual CARAPI GetValue(
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI Reset() = 0;

    virtual CARAPI Update(
        /* [in] */ _ELASTOS Int32 val) = 0;

    virtual CARAPI Update(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer) = 0;

    virtual CARAPI Update(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buf,
        /* [in] */ _ELASTOS Int32 off,
        /* [in] */ _ELASTOS Int32 nbytes) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("841F1D0B-7292-68BE-3D08-BFF392F62DDB")
IAdler32 : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAdler32*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAdler32*)pObj->Probe(EIID_IAdler32);
    }

    static CARAPI_(IAdler32*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAdler32*)pObj->Probe(EIID_IAdler32);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("1D971B0D-B312-8331-F03B-2F69DFB2FD7B")
ICRC32 : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICRC32*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRC32*)pObj->Probe(EIID_ICRC32);
    }

    static CARAPI_(ICRC32*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRC32*)pObj->Probe(EIID_ICRC32);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("0C82D347-96D2-2614-33FF-705052868D1F")
IInflater : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInflater*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInflater*)pObj->Probe(EIID_IInflater);
    }

    static CARAPI_(IInflater*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInflater*)pObj->Probe(EIID_IInflater);
    }

    virtual CARAPI End() = 0;

    virtual CARAPI Finished(
        /* [out] */ _ELASTOS Boolean * finished) = 0;

    virtual CARAPI GetAdler(
        /* [out] */ _ELASTOS Int32 * checksum) = 0;

    virtual CARAPI GetBytesRead(
        /* [out] */ _ELASTOS Int64 * number) = 0;

    virtual CARAPI GetBytesWritten(
        /* [out] */ _ELASTOS Int64 * number) = 0;

    virtual CARAPI GetRemaining(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI GetCurrentOffset(
        /* [out] */ _ELASTOS Int32 * offset) = 0;

    virtual CARAPI GetTotalIn(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI GetTotalOut(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Inflate(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buf,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Inflate(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI NeedsDictionary(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI NeedsInput(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Reset() = 0;

    virtual CARAPI SetDictionary(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buf) = 0;

    virtual CARAPI SetDictionary(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 byteCount) = 0;

    virtual CARAPI SetInput(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buf) = 0;

    virtual CARAPI SetInput(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 byteCount) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("C864C84C-91D2-2614-33FF-705052868D1F")
IDeflater : public IInterface
{
    static const _ELASTOS Int32 BEST_COMPRESSION = 9;
    static const _ELASTOS Int32 BEST_SPEED = 1;
    static const _ELASTOS Int32 DEFAULT_COMPRESSION = -1;
    static const _ELASTOS Int32 DEFAULT_STRATEGY = 0;
    static const _ELASTOS Int32 DEFLATED = 8;
    static const _ELASTOS Int32 FILTERED = 1;
    static const _ELASTOS Int32 HUFFMAN_ONLY = 2;
    static const _ELASTOS Int32 NO_FLUSH = 0;
    static const _ELASTOS Int32 SYNC_FLUSH = 2;
    static const _ELASTOS Int32 FULL_FLUSH = 3;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDeflater*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDeflater*)pObj->Probe(EIID_IDeflater);
    }

    static CARAPI_(IDeflater*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDeflater*)pObj->Probe(EIID_IDeflater);
    }

    virtual CARAPI Deflate(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buf,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Deflate(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Deflate(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [in] */ _ELASTOS Int32 flush,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI End() = 0;

    virtual CARAPI Finish() = 0;

    virtual CARAPI Finished(
        /* [out] */ _ELASTOS Boolean * finished) = 0;

    virtual CARAPI GetAdler(
        /* [out] */ _ELASTOS Int32 * checksum) = 0;

    virtual CARAPI GetTotalIn(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI GetTotalOut(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI NeedsInput(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Reset() = 0;

    virtual CARAPI SetDictionary(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buf) = 0;

    virtual CARAPI SetDictionary(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 byteCount) = 0;

    virtual CARAPI SetInput(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buf) = 0;

    virtual CARAPI SetInput(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 byteCount) = 0;

    virtual CARAPI SetLevel(
        /* [in] */ _ELASTOS Int32 level) = 0;

    virtual CARAPI SetStrategy(
        /* [in] */ _ELASTOS Int32 strategy) = 0;

    virtual CARAPI GetBytesRead(
        /* [out] */ _ELASTOS Int64 * number) = 0;

    virtual CARAPI GetBytesWritten(
        /* [out] */ _ELASTOS Int64 * number) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("BA3CB04E-08D2-3316-9CFC-705052868D1F")
IZipEntry : public IInterface
{
    static const _ELASTOS Int32 DEFLATED = 8;
    static const _ELASTOS Int32 STORED = 0;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IZipEntry*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IZipEntry*)pObj->Probe(EIID_IZipEntry);
    }

    static CARAPI_(IZipEntry*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IZipEntry*)pObj->Probe(EIID_IZipEntry);
    }

    virtual CARAPI GetComment(
        /* [out] */ _ELASTOS String * comment) = 0;

    virtual CARAPI GetCompressedSize(
        /* [out] */ _ELASTOS Int64 * size) = 0;

    virtual CARAPI GetCrc(
        /* [out] */ _ELASTOS Int64 * checksum) = 0;

    virtual CARAPI GetExtra(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** extra) = 0;

    virtual CARAPI GetMethod(
        /* [out] */ _ELASTOS Int32 * method) = 0;

    virtual CARAPI GetName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int64 * size) = 0;

    virtual CARAPI GetTime(
        /* [out] */ _ELASTOS Int64 * time) = 0;

    virtual CARAPI IsDirectory(
        /* [out] */ _ELASTOS Boolean * isDirectory) = 0;

    virtual CARAPI SetComment(
        /* [in] */ const _ELASTOS String& comment) = 0;

    virtual CARAPI SetCompressedSize(
        /* [in] */ _ELASTOS Int64 size) = 0;

    virtual CARAPI SetCrc(
        /* [in] */ _ELASTOS Int64 checksum) = 0;

    virtual CARAPI SetExtra(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data) = 0;

    virtual CARAPI SetMethod(
        /* [in] */ _ELASTOS Int32 method) = 0;

    virtual CARAPI SetSize(
        /* [in] */ _ELASTOS Int64 size) = 0;

    virtual CARAPI SetTime(
        /* [in] */ _ELASTOS Int64 time) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("EA4F2946-96D2-2614-336F-59CB46188C1F")
IInflaterInputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInflaterInputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInflaterInputStream*)pObj->Probe(EIID_IInflaterInputStream);
    }

    static CARAPI_(IInflaterInputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInflaterInputStream*)pObj->Probe(EIID_IInflaterInputStream);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("24313022-C1D2-2F14-48DC-B82F55360A12")
IInflaterOutputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInflaterOutputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInflaterOutputStream*)pObj->Probe(EIID_IInflaterOutputStream);
    }

    static CARAPI_(IInflaterOutputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInflaterOutputStream*)pObj->Probe(EIID_IInflaterOutputStream);
    }

    virtual CARAPI Finish() = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("EF58295B-91D2-2614-336F-59CB46188C1F")
IDeflaterInputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDeflaterInputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDeflaterInputStream*)pObj->Probe(EIID_IDeflaterInputStream);
    }

    static CARAPI_(IDeflaterInputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDeflaterInputStream*)pObj->Probe(EIID_IDeflaterInputStream);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("293A304E-91D2-2614-3363-C071632D1B61")
IDeflaterOutputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDeflaterOutputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDeflaterOutputStream*)pObj->Probe(EIID_IDeflaterOutputStream);
    }

    static CARAPI_(IDeflaterOutputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDeflaterOutputStream*)pObj->Probe(EIID_IDeflaterOutputStream);
    }

    virtual CARAPI Finish() = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("EE6D3A27-08D2-3316-FEC9-464102C68FF6")
IZipInputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IZipInputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IZipInputStream*)pObj->Probe(EIID_IZipInputStream);
    }

    static CARAPI_(IZipInputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IZipInputStream*)pObj->Probe(EIID_IZipInputStream);
    }

    virtual CARAPI CloseEntry() = 0;

    virtual CARAPI GetNextEntry(
        /* [out] */ Elastos::Utility::Zip::IZipEntry ** entry) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("81855639-08D2-3316-A4CA-464102C68FF6")
IZipOutputStream : public IInterface
{
    static const _ELASTOS Int32 DEFLATED = 8;
    static const _ELASTOS Int32 STORED = 0;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IZipOutputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IZipOutputStream*)pObj->Probe(EIID_IZipOutputStream);
    }

    static CARAPI_(IZipOutputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IZipOutputStream*)pObj->Probe(EIID_IZipOutputStream);
    }

    virtual CARAPI CloseEntry() = 0;

    virtual CARAPI PutNextEntry(
        /* [in] */ Elastos::Utility::Zip::IZipEntry * ze) = 0;

    virtual CARAPI SetComment(
        /* [in] */ const _ELASTOS String& comment) = 0;

    virtual CARAPI SetLevel(
        /* [in] */ _ELASTOS Int32 level) = 0;

    virtual CARAPI SetMethod(
        /* [in] */ _ELASTOS Int32 method) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("571A332C-1E52-FFFD-64A3-2001E3477B1B")
ICheckedInputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICheckedInputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICheckedInputStream*)pObj->Probe(EIID_ICheckedInputStream);
    }

    static CARAPI_(ICheckedInputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICheckedInputStream*)pObj->Probe(EIID_ICheckedInputStream);
    }

    virtual CARAPI GetChecksum(
        /* [out] */ Elastos::Utility::Zip::IChecksum ** checksum) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("836C3423-1E52-52FD-65A3-2001E3477B1B")
ICheckedOutputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICheckedOutputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICheckedOutputStream*)pObj->Probe(EIID_ICheckedOutputStream);
    }

    static CARAPI_(ICheckedOutputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICheckedOutputStream*)pObj->Probe(EIID_ICheckedOutputStream);
    }

    virtual CARAPI GetChecksum(
        /* [out] */ Elastos::Utility::Zip::IChecksum ** checksum) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("D0662535-8412-1211-32FC-938D82048C1F")
IGZIPInputStream : public IInterface
{
    static const _ELASTOS Int32 GZIP_MAGIC = 0x00008b1f;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IGZIPInputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IGZIPInputStream*)pObj->Probe(EIID_IGZIPInputStream);
    }

    static CARAPI_(IGZIPInputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IGZIPInputStream*)pObj->Probe(EIID_IGZIPInputStream);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("4570263A-8412-1211-3248-958D82048C1F")
IGZIPOutputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IGZIPOutputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IGZIPOutputStream*)pObj->Probe(EIID_IGZIPOutputStream);
    }

    static CARAPI_(IGZIPOutputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IGZIPOutputStream*)pObj->Probe(EIID_IGZIPOutputStream);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("5F0D2A0F-C8D2-0FCE-FBA2-9BF270778D92")
IZipFileRAFStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IZipFileRAFStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IZipFileRAFStream*)pObj->Probe(EIID_IZipFileRAFStream);
    }

    static CARAPI_(IZipFileRAFStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IZipFileRAFStream*)pObj->Probe(EIID_IZipFileRAFStream);
    }

    virtual CARAPI Fill(
        /* [in] */ Elastos::Utility::Zip::IInflater * inflater,
        /* [in] */ _ELASTOS Int32 nativeEndBufSize,
        /* [out] */ _ELASTOS Int32 * result) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("31E65A06-C8D2-0FCE-FBA2-BFF392F62DDB")
IZipFile : public IInterface
{
    static const _ELASTOS Int32 OPEN_READ = 1;
    static const _ELASTOS Int32 OPEN_DELETE = 4;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IZipFile*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IZipFile*)pObj->Probe(EIID_IZipFile);
    }

    static CARAPI_(IZipFile*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IZipFile*)pObj->Probe(EIID_IZipFile);
    }

    virtual CARAPI Close() = 0;

    virtual CARAPI GetEntries(
        /* [out] */ Elastos::Utility::IEnumeration ** entries) = 0;

    virtual CARAPI GetEntry(
        /* [in] */ const _ELASTOS String& entryName,
        /* [out] */ Elastos::Utility::Zip::IZipEntry ** entry) = 0;

    virtual CARAPI GetInputStream(
        /* [in] */ Elastos::Utility::Zip::IZipEntry * entry,
        /* [out] */ Elastos::IO::IInputStream ** is) = 0;

    virtual CARAPI GetName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetComment(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("9F636929-0312-2705-5EDC-1F20408FD11F")
ICAdler32ClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAdler32ClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAdler32ClassObject*)pObj->Probe(EIID_ICAdler32ClassObject);
    }

    static CARAPI_(ICAdler32ClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAdler32ClassObject*)pObj->Probe(EIID_ICAdler32ClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("16FD6731-0312-1B06-180C-10A0C7E88FF6")
ICCRC32ClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCRC32ClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCRC32ClassObject*)pObj->Probe(EIID_ICCRC32ClassObject);
    }

    static CARAPI_(ICCRC32ClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCRC32ClassObject*)pObj->Probe(EIID_ICCRC32ClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("22A18226-8312-2983-5E90-B8715F8FD11F")
ICInflaterClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICInflaterClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInflaterClassObject*)pObj->Probe(EIID_ICInflaterClassObject);
    }

    static CARAPI_(ICInflaterClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInflaterClassObject*)pObj->Probe(EIID_ICInflaterClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithNoHeader(
        /* [in] */ _ELASTOS Boolean noHeader,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("EAA59C32-8312-2806-52BC-2071E3BE1EA3")
ICDeflaterClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDeflaterClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDeflaterClassObject*)pObj->Probe(EIID_ICDeflaterClassObject);
    }

    static CARAPI_(ICDeflaterClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDeflaterClassObject*)pObj->Probe(EIID_ICDeflaterClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithLevel(
        /* [in] */ _ELASTOS Int32 level,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithLevelNoHeader(
        /* [in] */ _ELASTOS Int32 level,
        /* [in] */ _ELASTOS Boolean noHeader,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("6357A551-8312-292D-4C66-DEB2968D3018")
ICInflaterInputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICInflaterInputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInflaterInputStreamClassObject*)pObj->Probe(EIID_ICInflaterInputStreamClassObject);
    }

    static CARAPI_(ICInflaterInputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInflaterInputStreamClassObject*)pObj->Probe(EIID_ICInflaterInputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithIs(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithIsInflater(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IInflater * inflater,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithIsInflaterBsize(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IInflater * inflater,
        /* [in] */ _ELASTOS Int32 bsize,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("533C8C2B-8312-2983-5E90-B8715FAA6C14")
ICInflaterOutputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICInflaterOutputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInflaterOutputStreamClassObject*)pObj->Probe(EIID_ICInflaterOutputStreamClassObject);
    }

    static CARAPI_(ICInflaterOutputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInflaterOutputStreamClassObject*)pObj->Probe(EIID_ICInflaterOutputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithOs(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithOsInfBufferSize(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IInflater * inf,
        /* [in] */ _ELASTOS Int32 bufferSize,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("7A70AA58-8312-2923-4C66-DEB2968D3018")
ICDeflaterInputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDeflaterInputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDeflaterInputStreamClassObject*)pObj->Probe(EIID_ICDeflaterInputStreamClassObject);
    }

    static CARAPI_(ICDeflaterInputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDeflaterInputStreamClassObject*)pObj->Probe(EIID_ICDeflaterInputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithIs(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithIsDeflater(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IDeflater * deflater,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithIsDeflaterBufferSize(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IDeflater * deflater,
        /* [in] */ _ELASTOS Int32 bufferSize,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("53329C28-8312-2806-52BC-2071E3BE54D9")
ICDeflaterOutputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDeflaterOutputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDeflaterOutputStreamClassObject*)pObj->Probe(EIID_ICDeflaterOutputStreamClassObject);
    }

    static CARAPI_(ICDeflaterOutputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDeflaterOutputStreamClassObject*)pObj->Probe(EIID_ICDeflaterOutputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithOs(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithOsDef(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IDeflater * def,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithOsDefBsize(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IDeflater * def,
        /* [in] */ _ELASTOS Int32 bsize,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("64CE6F34-8312-FA3C-FFC9-464102861EA3")
ICCheckedInputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCheckedInputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCheckedInputStreamClassObject*)pObj->Probe(EIID_ICCheckedInputStreamClassObject);
    }

    static CARAPI_(ICCheckedInputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCheckedInputStreamClassObject*)pObj->Probe(EIID_ICCheckedInputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithIsCsum(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IChecksum * csum,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("C1CC6E2B-8312-FA3C-A5CA-464102861EA3")
ICCheckedOutputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCheckedOutputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCheckedOutputStreamClassObject*)pObj->Probe(EIID_ICCheckedOutputStreamClassObject);
    }

    static CARAPI_(ICCheckedOutputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCheckedOutputStreamClassObject*)pObj->Probe(EIID_ICCheckedOutputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithOsCs(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IChecksum * cs,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("C9CA7E22-0312-2308-2464-F8271B050918")
ICGZIPInputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICGZIPInputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICGZIPInputStreamClassObject*)pObj->Probe(EIID_ICGZIPInputStreamClassObject);
    }

    static CARAPI_(ICGZIPInputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICGZIPInputStreamClassObject*)pObj->Probe(EIID_ICGZIPInputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithIs(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithIsSize(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("FC08B929-0312-2308-2464-902A1B050918")
ICGZIPOutputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICGZIPOutputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICGZIPOutputStreamClassObject*)pObj->Probe(EIID_ICGZIPOutputStreamClassObject);
    }

    static CARAPI_(ICGZIPOutputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICGZIPOutputStreamClassObject*)pObj->Probe(EIID_ICGZIPOutputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithOs(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithOsSyncFlush(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Boolean syncFlush,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithOsSize(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithOsSizeSyncFlush(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Int32 size,
        /* [in] */ _ELASTOS Boolean syncFlush,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("39576B27-8312-2C11-66FC-938D82040C3D")
ICZipInputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICZipInputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICZipInputStreamClassObject*)pObj->Probe(EIID_ICZipInputStreamClassObject);
    }

    static CARAPI_(ICZipInputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICZipInputStreamClassObject*)pObj->Probe(EIID_ICZipInputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithStream(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("CCED6825-8312-2C11-6648-958D82040C3D")
ICZipOutputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICZipOutputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICZipOutputStreamClassObject*)pObj->Probe(EIID_ICZipOutputStreamClassObject);
    }

    static CARAPI_(ICZipOutputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICZipOutputStreamClassObject*)pObj->Probe(EIID_ICZipOutputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithOs(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("C8379B2B-8312-2C11-6610-D363F4477B1B")
ICZipEntryClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICZipEntryClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICZipEntryClassObject*)pObj->Probe(EIID_ICZipEntryClassObject);
    }

    static CARAPI_(ICZipEntryClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICZipEntryClassObject*)pObj->Probe(EIID_ICZipEntryClassObject);
    }

    virtual CARAPI CreateObjectWithName(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithZe(
        /* [in] */ Elastos::Utility::Zip::IZipEntry * ze,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithHdrBufIsDefaultCharset(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * hdrBuf,
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharset * defaultCharset,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
CAR_INTERFACE("EA6C8E3D-8312-2C11-6650-D363F4477B1B")
ICZipFileClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICZipFileClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICZipFileClassObject*)pObj->Probe(EIID_ICZipFileClassObject);
    }

    static CARAPI_(ICZipFileClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICZipFileClassObject*)pObj->Probe(EIID_ICZipFileClassObject);
    }

    virtual CARAPI CreateObjectWithFile(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFileMode(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Int32 mode,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithName(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Jar {
CAR_INTERFACE("2BE93A55-9752-3F9D-1C94-9461E38787CF")
IName : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IName*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IName*)pObj->Probe(EIID_IName);
    }

    static CARAPI_(IName*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IName*)pObj->Probe(EIID_IName);
    }

    virtual CARAPI GetName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * name) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Jar {
CAR_INTERFACE("EE3C4025-1712-3F1B-DADB-B821C3C60F0F")
IAttributes : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAttributes*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttributes*)pObj->Probe(EIID_IAttributes);
    }

    static CARAPI_(IAttributes*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttributes*)pObj->Probe(EIID_IAttributes);
    }

    virtual CARAPI GetValue(
        /* [in] */ Elastos::Utility::Jar::IName * name,
        /* [out] */ _ELASTOS String * value) = 0;

    virtual CARAPI GetValue(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS String * value) = 0;

    virtual CARAPI PutValue(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& val,
        /* [out] */ _ELASTOS String * oldVal) = 0;

    virtual CARAPI PutValue(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& val) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Jar {
CAR_INTERFACE("59B94848-84D2-4E44-7E38-2829C3C60F0F")
IJarEntry : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IJarEntry*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJarEntry*)pObj->Probe(EIID_IJarEntry);
    }

    static CARAPI_(IJarEntry*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJarEntry*)pObj->Probe(EIID_IJarEntry);
    }

    virtual CARAPI GetAttributes(
        /* [out] */ Elastos::Utility::Jar::IAttributes ** attrib) = 0;

    virtual CARAPI GetCertificates(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> ** certificates) = 0;

    virtual CARAPI GetCodeSigners(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::ICodeSigner *> ** codeSigner) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Jar {
CAR_INTERFACE("89246554-0592-2C41-B241-FEE1A0A40C1B")
IManifest : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IManifest*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IManifest*)pObj->Probe(EIID_IManifest);
    }

    static CARAPI_(IManifest*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IManifest*)pObj->Probe(EIID_IManifest);
    }

    virtual CARAPI Clear() = 0;

    virtual CARAPI GetAttributes(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Utility::Jar::IAttributes ** attrib) = 0;

    virtual CARAPI GetEntries(
        /* [out] */ Elastos::Utility::IMap ** entries) = 0;

    virtual CARAPI GetMainAttributes(
        /* [out] */ Elastos::Utility::Jar::IAttributes ** attrib) = 0;

    virtual CARAPI Write(
        /* [in] */ Elastos::IO::IOutputStream * os) = 0;

    virtual CARAPI Read(
        /* [in] */ Elastos::IO::IInputStream * is) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashcode) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * o,
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Jar {
CAR_INTERFACE("C8F1331D-44D2-0FD6-FBA2-BFF392F62DDB")
IJarFile : public IInterface
{
    static const _ELASTOS String MANIFEST_NAME;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IJarFile*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJarFile*)pObj->Probe(EIID_IJarFile);
    }

    static CARAPI_(IJarFile*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJarFile*)pObj->Probe(EIID_IJarFile);
    }

    virtual CARAPI GetJarEntry(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Utility::Jar::IJarEntry ** jarEntry) = 0;

    virtual CARAPI GetManifest(
        /* [out] */ Elastos::Utility::Jar::IManifest ** manifest) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Jar {
CAR_INTERFACE("51C93E58-84D2-5B44-D6B2-1106E3878392")
IJarInputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IJarInputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJarInputStream*)pObj->Probe(EIID_IJarInputStream);
    }

    static CARAPI_(IJarInputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJarInputStream*)pObj->Probe(EIID_IJarInputStream);
    }

    virtual CARAPI GetManifest(
        /* [out] */ Elastos::Utility::Jar::IManifest ** manifest) = 0;

    virtual CARAPI GetNextJarEntry(
        /* [out] */ Elastos::Utility::Jar::IJarEntry ** jarEntry) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Jar {
CAR_INTERFACE("8662252B-04D2-3512-A4CA-464102C68FF6")
IJarOutputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IJarOutputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJarOutputStream*)pObj->Probe(EIID_IJarOutputStream);
    }

    static CARAPI_(IJarOutputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJarOutputStream*)pObj->Probe(EIID_IJarOutputStream);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Jar {
CAR_INTERFACE("5A242E1E-4652-2E9A-5AFF-CE4BDAB76CFF")
IPacker : public IInterface
{
    static const _ELASTOS String CLASS_ATTRIBUTE_PFX;
    static const _ELASTOS String CODE_ATTRIBUTE_PFX;
    static const _ELASTOS String DEFLATE_HINT;
    static const _ELASTOS String EFFORT;
    static const _ELASTOS String ERROR;
    static const _ELASTOS String SFALSE;
    static const _ELASTOS String FIELD_ATTRIBUTE_PFX;
    static const _ELASTOS String KEEP;
    static const _ELASTOS String KEEP_FILE_ORDER;
    static const _ELASTOS String LATEST;
    static const _ELASTOS String METHOD_ATTRIBUTE_PFX;
    static const _ELASTOS String MODIFICATION_TIME;
    static const _ELASTOS String PASS;
    static const _ELASTOS String PASS_FILE_PFX;
    static const _ELASTOS String PROGRESS;
    static const _ELASTOS String SEGMENT_LIMIT;
    static const _ELASTOS String STRIP;
    static const _ELASTOS String STRUE;
    static const _ELASTOS String UNKNOWN_ATTRIBUTE;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPacker*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPacker*)pObj->Probe(EIID_IPacker);
    }

    static CARAPI_(IPacker*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPacker*)pObj->Probe(EIID_IPacker);
    }

    virtual CARAPI Properties(
        /* [out] */ Elastos::Utility::IMap ** prop) = 0;

    virtual CARAPI Pack(
        /* [in] */ Elastos::Utility::Jar::IJarFile * jarFile,
        /* [in] */ Elastos::IO::IOutputStream * outputStream) = 0;

    virtual CARAPI Pack(
        /* [in] */ Elastos::Utility::Jar::IJarInputStream * jarInputStream,
        /* [in] */ Elastos::IO::IOutputStream * outputStream) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Jar {
CAR_INTERFACE("07CB3441-1D12-ABB0-9EFD-705052868D1F")
IUnpacker : public IInterface
{
    static const _ELASTOS String DEFLATE_HINT;
    static const _ELASTOS String SFALSE;
    static const _ELASTOS String KEEP;
    static const _ELASTOS String PROGRESS;
    static const _ELASTOS String STRUE;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IUnpacker*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IUnpacker*)pObj->Probe(EIID_IUnpacker);
    }

    static CARAPI_(IUnpacker*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IUnpacker*)pObj->Probe(EIID_IUnpacker);
    }

    virtual CARAPI Properties(
        /* [out] */ Elastos::Utility::IMap ** prop) = 0;

    virtual CARAPI Unpack(
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [in] */ Elastos::Utility::Jar::IJarOutputStream * outputStream) = 0;

    virtual CARAPI Unpack(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ Elastos::Utility::Jar::IJarOutputStream * jarOutputStream) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Jar {
CAR_INTERFACE("92783107-4652-AE9A-0000-BFF392F62DDB")
IPack200 : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPack200*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPack200*)pObj->Probe(EIID_IPack200);
    }

    static CARAPI_(IPack200*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPack200*)pObj->Probe(EIID_IPack200);
    }

    virtual CARAPI NewPacker(
        /* [out] */ Elastos::Utility::Jar::IPacker ** packer) = 0;

    virtual CARAPI NewUnpacker(
        /* [out] */ Elastos::Utility::Jar::IUnpacker ** unpacker) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Jar {
CAR_INTERFACE("A373782A-6C92-2616-6E4C-205183DA8FF6")
IStrictJarFile : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IStrictJarFile*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStrictJarFile*)pObj->Probe(EIID_IStrictJarFile);
    }

    static CARAPI_(IStrictJarFile*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStrictJarFile*)pObj->Probe(EIID_IStrictJarFile);
    }

    virtual CARAPI GetManifest(
        /* [out] */ Elastos::Utility::Jar::IManifest ** manifest) = 0;

    virtual CARAPI GetIterator(
        /* [out] */ Elastos::Utility::IIterator ** it) = 0;

    virtual CARAPI FindEntry(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Utility::Zip::IZipEntry ** ze) = 0;

    virtual CARAPI GetCertificateChains(
        /* [in] */ Elastos::Utility::Zip::IZipEntry * ze,
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Core::IArrayOf *> ** certificate) = 0;

    virtual CARAPI GetCertificates(
        /* [in] */ Elastos::Utility::Zip::IZipEntry * ze,
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Security::Cert::ICertificate *> ** certificate) = 0;

    virtual CARAPI GetInputStream(
        /* [in] */ Elastos::Utility::Zip::IZipEntry * ze,
        /* [out] */ Elastos::IO::IInputStream ** is) = 0;

    virtual CARAPI Close() = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Jar {
CAR_INTERFACE("73D17F32-8312-7AA0-8CFE-686FE3860C1B")
ICNameClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICNameClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNameClassObject*)pObj->Probe(EIID_ICNameClassObject);
    }

    static CARAPI_(ICNameClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNameClassObject*)pObj->Probe(EIID_ICNameClassObject);
    }

    virtual CARAPI CreateObjectWithName(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithNameValidateName(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Boolean validateName,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Jar {
CAR_INTERFACE("4A909A3F-0312-362E-F418-FDD1DEC60D19")
ICAttributesClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAttributesClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAttributesClassObject*)pObj->Probe(EIID_ICAttributesClassObject);
    }

    static CARAPI_(ICAttributesClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAttributesClassObject*)pObj->Probe(EIID_ICAttributesClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithAttributes(
        /* [in] */ Elastos::Utility::Jar::IAttributes * attributes,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithSize(
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Jar {
CAR_INTERFACE("4CB3933C-8312-2409-6A10-D363F4477B1B")
ICJarEntryClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICJarEntryClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJarEntryClassObject*)pObj->Probe(EIID_ICJarEntryClassObject);
    }

    static CARAPI_(ICJarEntryClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJarEntryClassObject*)pObj->Probe(EIID_ICJarEntryClassObject);
    }

    virtual CARAPI CreateObjectWithName(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithZipEntry(
        /* [in] */ Elastos::Utility::Zip::IZipEntry * zipEntry,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithJarEntry(
        /* [in] */ Elastos::Utility::Jar::IJarEntry * jarEntry,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Jar {
CAR_INTERFACE("51E9D038-8312-2409-6A50-D363F4477B1B")
ICJarFileClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICJarFileClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJarFileClassObject*)pObj->Probe(EIID_ICJarFileClassObject);
    }

    static CARAPI_(ICJarFileClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJarFileClassObject*)pObj->Probe(EIID_ICJarFileClassObject);
    }

    virtual CARAPI CreateObjectWithFile(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFileVerify(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFileVerifyMode(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean verify,
        /* [in] */ _ELASTOS Int32 mode,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFilename(
        /* [in] */ const _ELASTOS String& filename,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFilenameVerify(
        /* [in] */ const _ELASTOS String& filename,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Jar {
CAR_INTERFACE("7316872F-8312-2409-6AFC-938D82040C3D")
ICJarInputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICJarInputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJarInputStreamClassObject*)pObj->Probe(EIID_ICJarInputStreamClassObject);
    }

    static CARAPI_(ICJarInputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJarInputStreamClassObject*)pObj->Probe(EIID_ICJarInputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithStreamVerify(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithStream(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Jar {
CAR_INTERFACE("F7A48222-8312-2409-6A48-958D82040C3D")
ICJarOutputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICJarOutputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJarOutputStreamClassObject*)pObj->Probe(EIID_ICJarOutputStreamClassObject);
    }

    static CARAPI_(ICJarOutputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJarOutputStreamClassObject*)pObj->Probe(EIID_ICJarOutputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithOsManifest(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Jar::IManifest * manifest,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithOs(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Jar {
CAR_INTERFACE("99B69026-0312-240B-62B0-4881FF861EA3")
ICManifestClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICManifestClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICManifestClassObject*)pObj->Probe(EIID_ICManifestClassObject);
    }

    static CARAPI_(ICManifestClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICManifestClassObject*)pObj->Probe(EIID_ICManifestClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithIs(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithMani(
        /* [in] */ Elastos::Utility::Jar::IManifest * mani,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Jar {
CAR_INTERFACE("ADA76928-8312-240C-4CB8-100000801EA3")
ICPack200ClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPack200ClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPack200ClassObject*)pObj->Probe(EIID_ICPack200ClassObject);
    }

    static CARAPI_(ICPack200ClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPack200ClassObject*)pObj->Probe(EIID_ICPack200ClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
class CAdler32
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Zip::IAdler32** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAdler32, RGM_SAME_DOMAIN, Elastos::Utility::Zip::EIID_IAdler32, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Zip::IChecksum** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAdler32, RGM_SAME_DOMAIN, Elastos::Utility::Zip::EIID_IChecksum, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAdler32, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAdler32, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAdler32, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
class CCRC32
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Zip::ICRC32** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCRC32, RGM_SAME_DOMAIN, Elastos::Utility::Zip::EIID_ICRC32, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Zip::IChecksum** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCRC32, RGM_SAME_DOMAIN, Elastos::Utility::Zip::EIID_IChecksum, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCRC32, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCRC32, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCRC32, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Zip {
class CInflater
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Boolean noHeader,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInflaterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInflater, RGM_SAME_DOMAIN,
                EIID_ICInflaterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithNoHeader(noHeader, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Zip::IInflater** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInflater, RGM_SAME_DOMAIN, Elastos::Utility::Zip::EIID_IInflater, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInflater, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInflater, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInflater, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean noHeader,
        /* [out] */ Elastos::Utility::Zip::IInflater** __IInflater)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(noHeader, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInflater = (Elastos::Utility::Zip::IInflater*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IInflater);
        if (*__IInflater) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean noHeader,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(noHeader, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean noHeader,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(noHeader, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean noHeader,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(noHeader, &__pNewObj);
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
namespace Utility {
namespace Zip {
class CDeflater
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 level,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDeflaterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDeflater, RGM_SAME_DOMAIN,
                EIID_ICDeflaterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithLevel(level, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 level,
        /* [in] */ _ELASTOS Boolean noHeader,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDeflaterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDeflater, RGM_SAME_DOMAIN,
                EIID_ICDeflaterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithLevelNoHeader(level, noHeader, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Zip::IDeflater** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDeflater, RGM_SAME_DOMAIN, Elastos::Utility::Zip::EIID_IDeflater, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDeflater, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDeflater, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDeflater, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 level,
        /* [out] */ Elastos::Utility::Zip::IDeflater** __IDeflater)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(level, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDeflater = (Elastos::Utility::Zip::IDeflater*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IDeflater);
        if (*__IDeflater) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 level,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(level, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 level,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(level, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 level,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(level, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 level,
        /* [in] */ _ELASTOS Boolean noHeader,
        /* [out] */ Elastos::Utility::Zip::IDeflater** __IDeflater)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(level, noHeader, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDeflater = (Elastos::Utility::Zip::IDeflater*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IDeflater);
        if (*__IDeflater) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 level,
        /* [in] */ _ELASTOS Boolean noHeader,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(level, noHeader, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 level,
        /* [in] */ _ELASTOS Boolean noHeader,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(level, noHeader, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 level,
        /* [in] */ _ELASTOS Boolean noHeader,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(level, noHeader, &__pNewObj);
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
namespace Utility {
namespace Zip {
class CInflaterInputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInflaterInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInflaterInputStream, RGM_SAME_DOMAIN,
                EIID_ICInflaterInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIs(is, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IInflater * inflater,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInflaterInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInflaterInputStream, RGM_SAME_DOMAIN,
                EIID_ICInflaterInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIsInflater(is, inflater, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IInflater * inflater,
        /* [in] */ _ELASTOS Int32 bsize,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInflaterInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInflaterInputStream, RGM_SAME_DOMAIN,
                EIID_ICInflaterInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIsInflaterBsize(is, inflater, bsize, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ Elastos::Utility::Zip::IInflaterInputStream** __IInflaterInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInflaterInputStream = (Elastos::Utility::Zip::IInflaterInputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IInflaterInputStream);
        if (*__IInflaterInputStream) __pNewObj->AddRef();
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

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IInflater * inflater,
        /* [out] */ Elastos::Utility::Zip::IInflaterInputStream** __IInflaterInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, inflater, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInflaterInputStream = (Elastos::Utility::Zip::IInflaterInputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IInflaterInputStream);
        if (*__IInflaterInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IInflater * inflater,
        /* [out] */ Elastos::IO::IFilterInputStream** __IFilterInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, inflater, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterInputStream = (Elastos::IO::IFilterInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterInputStream);
        if (*__IFilterInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IInflater * inflater,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, inflater, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IInflater * inflater,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, inflater, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IInflater * inflater,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, inflater, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IInflater * inflater,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, inflater, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IInflater * inflater,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, inflater, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IInflater * inflater,
        /* [in] */ _ELASTOS Int32 bsize,
        /* [out] */ Elastos::Utility::Zip::IInflaterInputStream** __IInflaterInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, inflater, bsize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInflaterInputStream = (Elastos::Utility::Zip::IInflaterInputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IInflaterInputStream);
        if (*__IInflaterInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IInflater * inflater,
        /* [in] */ _ELASTOS Int32 bsize,
        /* [out] */ Elastos::IO::IFilterInputStream** __IFilterInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, inflater, bsize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterInputStream = (Elastos::IO::IFilterInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterInputStream);
        if (*__IFilterInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IInflater * inflater,
        /* [in] */ _ELASTOS Int32 bsize,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, inflater, bsize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IInflater * inflater,
        /* [in] */ _ELASTOS Int32 bsize,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, inflater, bsize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IInflater * inflater,
        /* [in] */ _ELASTOS Int32 bsize,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, inflater, bsize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IInflater * inflater,
        /* [in] */ _ELASTOS Int32 bsize,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, inflater, bsize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IInflater * inflater,
        /* [in] */ _ELASTOS Int32 bsize,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, inflater, bsize, &__pNewObj);
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
namespace Utility {
namespace Zip {
class CInflaterOutputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInflaterOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInflaterOutputStream, RGM_SAME_DOMAIN,
                EIID_ICInflaterOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOs(os, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IInflater * inf,
        /* [in] */ _ELASTOS Int32 bufferSize,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInflaterOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInflaterOutputStream, RGM_SAME_DOMAIN,
                EIID_ICInflaterOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOsInfBufferSize(os, inf, bufferSize, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ Elastos::Utility::Zip::IInflaterOutputStream** __IInflaterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInflaterOutputStream = (Elastos::Utility::Zip::IInflaterOutputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IInflaterOutputStream);
        if (*__IInflaterOutputStream) __pNewObj->AddRef();
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

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IInflater * inf,
        /* [in] */ _ELASTOS Int32 bufferSize,
        /* [out] */ Elastos::Utility::Zip::IInflaterOutputStream** __IInflaterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, inf, bufferSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInflaterOutputStream = (Elastos::Utility::Zip::IInflaterOutputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IInflaterOutputStream);
        if (*__IInflaterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IInflater * inf,
        /* [in] */ _ELASTOS Int32 bufferSize,
        /* [out] */ Elastos::IO::IFilterOutputStream** __IFilterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, inf, bufferSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterOutputStream = (Elastos::IO::IFilterOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterOutputStream);
        if (*__IFilterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IInflater * inf,
        /* [in] */ _ELASTOS Int32 bufferSize,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, inf, bufferSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IInflater * inf,
        /* [in] */ _ELASTOS Int32 bufferSize,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, inf, bufferSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IInflater * inf,
        /* [in] */ _ELASTOS Int32 bufferSize,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, inf, bufferSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IInflater * inf,
        /* [in] */ _ELASTOS Int32 bufferSize,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, inf, bufferSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IInflater * inf,
        /* [in] */ _ELASTOS Int32 bufferSize,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, inf, bufferSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IInflater * inf,
        /* [in] */ _ELASTOS Int32 bufferSize,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, inf, bufferSize, &__pNewObj);
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
namespace Utility {
namespace Zip {
class CDeflaterInputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDeflaterInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDeflaterInputStream, RGM_SAME_DOMAIN,
                EIID_ICDeflaterInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIs(is, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IDeflater * deflater,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDeflaterInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDeflaterInputStream, RGM_SAME_DOMAIN,
                EIID_ICDeflaterInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIsDeflater(is, deflater, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IDeflater * deflater,
        /* [in] */ _ELASTOS Int32 bufferSize,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDeflaterInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDeflaterInputStream, RGM_SAME_DOMAIN,
                EIID_ICDeflaterInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIsDeflaterBufferSize(is, deflater, bufferSize, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ Elastos::Utility::Zip::IDeflaterInputStream** __IDeflaterInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDeflaterInputStream = (Elastos::Utility::Zip::IDeflaterInputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IDeflaterInputStream);
        if (*__IDeflaterInputStream) __pNewObj->AddRef();
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

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IDeflater * deflater,
        /* [out] */ Elastos::Utility::Zip::IDeflaterInputStream** __IDeflaterInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, deflater, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDeflaterInputStream = (Elastos::Utility::Zip::IDeflaterInputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IDeflaterInputStream);
        if (*__IDeflaterInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IDeflater * deflater,
        /* [out] */ Elastos::IO::IFilterInputStream** __IFilterInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, deflater, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterInputStream = (Elastos::IO::IFilterInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterInputStream);
        if (*__IFilterInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IDeflater * deflater,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, deflater, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IDeflater * deflater,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, deflater, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IDeflater * deflater,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, deflater, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IDeflater * deflater,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, deflater, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IDeflater * deflater,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, deflater, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IDeflater * deflater,
        /* [in] */ _ELASTOS Int32 bufferSize,
        /* [out] */ Elastos::Utility::Zip::IDeflaterInputStream** __IDeflaterInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, deflater, bufferSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDeflaterInputStream = (Elastos::Utility::Zip::IDeflaterInputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IDeflaterInputStream);
        if (*__IDeflaterInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IDeflater * deflater,
        /* [in] */ _ELASTOS Int32 bufferSize,
        /* [out] */ Elastos::IO::IFilterInputStream** __IFilterInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, deflater, bufferSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterInputStream = (Elastos::IO::IFilterInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterInputStream);
        if (*__IFilterInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IDeflater * deflater,
        /* [in] */ _ELASTOS Int32 bufferSize,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, deflater, bufferSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IDeflater * deflater,
        /* [in] */ _ELASTOS Int32 bufferSize,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, deflater, bufferSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IDeflater * deflater,
        /* [in] */ _ELASTOS Int32 bufferSize,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, deflater, bufferSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IDeflater * deflater,
        /* [in] */ _ELASTOS Int32 bufferSize,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, deflater, bufferSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IDeflater * deflater,
        /* [in] */ _ELASTOS Int32 bufferSize,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, deflater, bufferSize, &__pNewObj);
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
namespace Utility {
namespace Zip {
class CDeflaterOutputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDeflaterOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDeflaterOutputStream, RGM_SAME_DOMAIN,
                EIID_ICDeflaterOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOs(os, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IDeflater * def,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDeflaterOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDeflaterOutputStream, RGM_SAME_DOMAIN,
                EIID_ICDeflaterOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOsDef(os, def, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IDeflater * def,
        /* [in] */ _ELASTOS Int32 bsize,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDeflaterOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDeflaterOutputStream, RGM_SAME_DOMAIN,
                EIID_ICDeflaterOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOsDefBsize(os, def, bsize, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ Elastos::Utility::Zip::IDeflaterOutputStream** __IDeflaterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDeflaterOutputStream = (Elastos::Utility::Zip::IDeflaterOutputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IDeflaterOutputStream);
        if (*__IDeflaterOutputStream) __pNewObj->AddRef();
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

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IDeflater * def,
        /* [out] */ Elastos::Utility::Zip::IDeflaterOutputStream** __IDeflaterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, def, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDeflaterOutputStream = (Elastos::Utility::Zip::IDeflaterOutputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IDeflaterOutputStream);
        if (*__IDeflaterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IDeflater * def,
        /* [out] */ Elastos::IO::IFilterOutputStream** __IFilterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, def, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterOutputStream = (Elastos::IO::IFilterOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterOutputStream);
        if (*__IFilterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IDeflater * def,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, def, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IDeflater * def,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, def, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IDeflater * def,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, def, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IDeflater * def,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, def, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IDeflater * def,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, def, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IDeflater * def,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, def, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IDeflater * def,
        /* [in] */ _ELASTOS Int32 bsize,
        /* [out] */ Elastos::Utility::Zip::IDeflaterOutputStream** __IDeflaterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, def, bsize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDeflaterOutputStream = (Elastos::Utility::Zip::IDeflaterOutputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IDeflaterOutputStream);
        if (*__IDeflaterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IDeflater * def,
        /* [in] */ _ELASTOS Int32 bsize,
        /* [out] */ Elastos::IO::IFilterOutputStream** __IFilterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, def, bsize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterOutputStream = (Elastos::IO::IFilterOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterOutputStream);
        if (*__IFilterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IDeflater * def,
        /* [in] */ _ELASTOS Int32 bsize,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, def, bsize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IDeflater * def,
        /* [in] */ _ELASTOS Int32 bsize,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, def, bsize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IDeflater * def,
        /* [in] */ _ELASTOS Int32 bsize,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, def, bsize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IDeflater * def,
        /* [in] */ _ELASTOS Int32 bsize,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, def, bsize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IDeflater * def,
        /* [in] */ _ELASTOS Int32 bsize,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, def, bsize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IDeflater * def,
        /* [in] */ _ELASTOS Int32 bsize,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, def, bsize, &__pNewObj);
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
namespace Utility {
namespace Zip {
class CCheckedInputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IChecksum * csum,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCheckedInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCheckedInputStream, RGM_SAME_DOMAIN,
                EIID_ICCheckedInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIsCsum(is, csum, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IChecksum * csum,
        /* [out] */ Elastos::Utility::Zip::ICheckedInputStream** __ICheckedInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, csum, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICheckedInputStream = (Elastos::Utility::Zip::ICheckedInputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_ICheckedInputStream);
        if (*__ICheckedInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IChecksum * csum,
        /* [out] */ Elastos::IO::IFilterInputStream** __IFilterInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, csum, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterInputStream = (Elastos::IO::IFilterInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterInputStream);
        if (*__IFilterInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IChecksum * csum,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, csum, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IChecksum * csum,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, csum, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IChecksum * csum,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, csum, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IChecksum * csum,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, csum, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Utility::Zip::IChecksum * csum,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, csum, &__pNewObj);
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
namespace Utility {
namespace Zip {
class CCheckedOutputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IChecksum * cs,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCheckedOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCheckedOutputStream, RGM_SAME_DOMAIN,
                EIID_ICCheckedOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOsCs(os, cs, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IChecksum * cs,
        /* [out] */ Elastos::Utility::Zip::ICheckedOutputStream** __ICheckedOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, cs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICheckedOutputStream = (Elastos::Utility::Zip::ICheckedOutputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_ICheckedOutputStream);
        if (*__ICheckedOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IChecksum * cs,
        /* [out] */ Elastos::IO::IFilterOutputStream** __IFilterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, cs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterOutputStream = (Elastos::IO::IFilterOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterOutputStream);
        if (*__IFilterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IChecksum * cs,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, cs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IChecksum * cs,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, cs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IChecksum * cs,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, cs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IChecksum * cs,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, cs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IChecksum * cs,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, cs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Zip::IChecksum * cs,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, cs, &__pNewObj);
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
namespace Utility {
namespace Zip {
class CGZIPInputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICGZIPInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CGZIPInputStream, RGM_SAME_DOMAIN,
                EIID_ICGZIPInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIs(is, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICGZIPInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CGZIPInputStream, RGM_SAME_DOMAIN,
                EIID_ICGZIPInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIsSize(is, size, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ Elastos::Utility::Zip::IGZIPInputStream** __IGZIPInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IGZIPInputStream = (Elastos::Utility::Zip::IGZIPInputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IGZIPInputStream);
        if (*__IGZIPInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ Elastos::Utility::Zip::IInflaterInputStream** __IInflaterInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInflaterInputStream = (Elastos::Utility::Zip::IInflaterInputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IInflaterInputStream);
        if (*__IInflaterInputStream) __pNewObj->AddRef();
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

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::Utility::Zip::IGZIPInputStream** __IGZIPInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IGZIPInputStream = (Elastos::Utility::Zip::IGZIPInputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IGZIPInputStream);
        if (*__IGZIPInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::Utility::Zip::IInflaterInputStream** __IInflaterInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInflaterInputStream = (Elastos::Utility::Zip::IInflaterInputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IInflaterInputStream);
        if (*__IInflaterInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IFilterInputStream** __IFilterInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterInputStream = (Elastos::IO::IFilterInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterInputStream);
        if (*__IFilterInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, size, &__pNewObj);
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
namespace Utility {
namespace Zip {
class CGZIPOutputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICGZIPOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CGZIPOutputStream, RGM_SAME_DOMAIN,
                EIID_ICGZIPOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOs(os, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Boolean syncFlush,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICGZIPOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CGZIPOutputStream, RGM_SAME_DOMAIN,
                EIID_ICGZIPOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOsSyncFlush(os, syncFlush, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICGZIPOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CGZIPOutputStream, RGM_SAME_DOMAIN,
                EIID_ICGZIPOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOsSize(os, size, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Int32 size,
        /* [in] */ _ELASTOS Boolean syncFlush,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICGZIPOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CGZIPOutputStream, RGM_SAME_DOMAIN,
                EIID_ICGZIPOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOsSizeSyncFlush(os, size, syncFlush, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ Elastos::Utility::Zip::IGZIPOutputStream** __IGZIPOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IGZIPOutputStream = (Elastos::Utility::Zip::IGZIPOutputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IGZIPOutputStream);
        if (*__IGZIPOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ Elastos::Utility::Zip::IDeflaterOutputStream** __IDeflaterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDeflaterOutputStream = (Elastos::Utility::Zip::IDeflaterOutputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IDeflaterOutputStream);
        if (*__IDeflaterOutputStream) __pNewObj->AddRef();
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

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Boolean syncFlush,
        /* [out] */ Elastos::Utility::Zip::IGZIPOutputStream** __IGZIPOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, syncFlush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IGZIPOutputStream = (Elastos::Utility::Zip::IGZIPOutputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IGZIPOutputStream);
        if (*__IGZIPOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Boolean syncFlush,
        /* [out] */ Elastos::Utility::Zip::IDeflaterOutputStream** __IDeflaterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, syncFlush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDeflaterOutputStream = (Elastos::Utility::Zip::IDeflaterOutputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IDeflaterOutputStream);
        if (*__IDeflaterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Boolean syncFlush,
        /* [out] */ Elastos::IO::IFilterOutputStream** __IFilterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, syncFlush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterOutputStream = (Elastos::IO::IFilterOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterOutputStream);
        if (*__IFilterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Boolean syncFlush,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, syncFlush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Boolean syncFlush,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, syncFlush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Boolean syncFlush,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, syncFlush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Boolean syncFlush,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, syncFlush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Boolean syncFlush,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, syncFlush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Boolean syncFlush,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, syncFlush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::Utility::Zip::IGZIPOutputStream** __IGZIPOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IGZIPOutputStream = (Elastos::Utility::Zip::IGZIPOutputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IGZIPOutputStream);
        if (*__IGZIPOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::Utility::Zip::IDeflaterOutputStream** __IDeflaterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDeflaterOutputStream = (Elastos::Utility::Zip::IDeflaterOutputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IDeflaterOutputStream);
        if (*__IDeflaterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IFilterOutputStream** __IFilterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterOutputStream = (Elastos::IO::IFilterOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterOutputStream);
        if (*__IFilterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Int32 size,
        /* [in] */ _ELASTOS Boolean syncFlush,
        /* [out] */ Elastos::Utility::Zip::IGZIPOutputStream** __IGZIPOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, size, syncFlush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IGZIPOutputStream = (Elastos::Utility::Zip::IGZIPOutputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IGZIPOutputStream);
        if (*__IGZIPOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Int32 size,
        /* [in] */ _ELASTOS Boolean syncFlush,
        /* [out] */ Elastos::Utility::Zip::IDeflaterOutputStream** __IDeflaterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, size, syncFlush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDeflaterOutputStream = (Elastos::Utility::Zip::IDeflaterOutputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IDeflaterOutputStream);
        if (*__IDeflaterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Int32 size,
        /* [in] */ _ELASTOS Boolean syncFlush,
        /* [out] */ Elastos::IO::IFilterOutputStream** __IFilterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, size, syncFlush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterOutputStream = (Elastos::IO::IFilterOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterOutputStream);
        if (*__IFilterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Int32 size,
        /* [in] */ _ELASTOS Boolean syncFlush,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, size, syncFlush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Int32 size,
        /* [in] */ _ELASTOS Boolean syncFlush,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, size, syncFlush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Int32 size,
        /* [in] */ _ELASTOS Boolean syncFlush,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, size, syncFlush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Int32 size,
        /* [in] */ _ELASTOS Boolean syncFlush,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, size, syncFlush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Int32 size,
        /* [in] */ _ELASTOS Boolean syncFlush,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, size, syncFlush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ _ELASTOS Int32 size,
        /* [in] */ _ELASTOS Boolean syncFlush,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, size, syncFlush, &__pNewObj);
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
namespace Utility {
namespace Zip {
class CZipInputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICZipInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CZipInputStream, RGM_SAME_DOMAIN,
                EIID_ICZipInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithStream(stream, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [out] */ Elastos::Utility::Zip::IZipInputStream** __IZipInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IZipInputStream = (Elastos::Utility::Zip::IZipInputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IZipInputStream);
        if (*__IZipInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [out] */ Elastos::Utility::Zip::IInflaterInputStream** __IInflaterInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInflaterInputStream = (Elastos::Utility::Zip::IInflaterInputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IInflaterInputStream);
        if (*__IInflaterInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [out] */ Elastos::IO::IFilterInputStream** __IFilterInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterInputStream = (Elastos::IO::IFilterInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterInputStream);
        if (*__IFilterInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, &__pNewObj);
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
namespace Utility {
namespace Zip {
class CZipOutputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICZipOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CZipOutputStream, RGM_SAME_DOMAIN,
                EIID_ICZipOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOs(os, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ Elastos::Utility::Zip::IZipOutputStream** __IZipOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IZipOutputStream = (Elastos::Utility::Zip::IZipOutputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IZipOutputStream);
        if (*__IZipOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ Elastos::Utility::Zip::IDeflaterOutputStream** __IDeflaterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDeflaterOutputStream = (Elastos::Utility::Zip::IDeflaterOutputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IDeflaterOutputStream);
        if (*__IDeflaterOutputStream) __pNewObj->AddRef();
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
}
namespace Elastos {
namespace Utility {
namespace Zip {
class CZipEntry
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICZipEntryClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CZipEntry, RGM_SAME_DOMAIN,
                EIID_ICZipEntryClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithName(name, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::Zip::IZipEntry * ze,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICZipEntryClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CZipEntry, RGM_SAME_DOMAIN,
                EIID_ICZipEntryClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithZe(ze, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * hdrBuf,
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharset * defaultCharset,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICZipEntryClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CZipEntry, RGM_SAME_DOMAIN,
                EIID_ICZipEntryClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithHdrBufIsDefaultCharset(hdrBuf, is, defaultCharset, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Utility::Zip::IZipEntry** __IZipEntry)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IZipEntry = (Elastos::Utility::Zip::IZipEntry*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IZipEntry);
        if (*__IZipEntry) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
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
        /* [in] */ Elastos::Utility::Zip::IZipEntry * ze,
        /* [out] */ Elastos::Utility::Zip::IZipEntry** __IZipEntry)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ze, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IZipEntry = (Elastos::Utility::Zip::IZipEntry*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IZipEntry);
        if (*__IZipEntry) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Zip::IZipEntry * ze,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ze, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Zip::IZipEntry * ze,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ze, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Zip::IZipEntry * ze,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ze, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Zip::IZipEntry * ze,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ze, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * hdrBuf,
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharset * defaultCharset,
        /* [out] */ Elastos::Utility::Zip::IZipEntry** __IZipEntry)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(hdrBuf, is, defaultCharset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IZipEntry = (Elastos::Utility::Zip::IZipEntry*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IZipEntry);
        if (*__IZipEntry) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * hdrBuf,
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharset * defaultCharset,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(hdrBuf, is, defaultCharset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * hdrBuf,
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharset * defaultCharset,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(hdrBuf, is, defaultCharset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * hdrBuf,
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharset * defaultCharset,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(hdrBuf, is, defaultCharset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * hdrBuf,
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharset * defaultCharset,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(hdrBuf, is, defaultCharset, &__pNewObj);
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
namespace Utility {
namespace Zip {
class CZipFile
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICZipFileClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CZipFile, RGM_SAME_DOMAIN,
                EIID_ICZipFileClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFile(file, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Int32 mode,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICZipFileClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CZipFile, RGM_SAME_DOMAIN,
                EIID_ICZipFileClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFileMode(file, mode, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICZipFileClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CZipFile, RGM_SAME_DOMAIN,
                EIID_ICZipFileClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithName(name, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::Utility::Zip::IZipFile** __IZipFile)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IZipFile = (Elastos::Utility::Zip::IZipFile*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IZipFile);
        if (*__IZipFile) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::Utility::Zip::IZipConstants** __IZipConstants)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IZipConstants = (Elastos::Utility::Zip::IZipConstants*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IZipConstants);
        if (*__IZipConstants) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Int32 mode,
        /* [out] */ Elastos::Utility::Zip::IZipFile** __IZipFile)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, mode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IZipFile = (Elastos::Utility::Zip::IZipFile*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IZipFile);
        if (*__IZipFile) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Int32 mode,
        /* [out] */ Elastos::Utility::Zip::IZipConstants** __IZipConstants)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, mode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IZipConstants = (Elastos::Utility::Zip::IZipConstants*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IZipConstants);
        if (*__IZipConstants) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Int32 mode,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, mode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Int32 mode,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, mode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Int32 mode,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, mode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Utility::Zip::IZipFile** __IZipFile)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IZipFile = (Elastos::Utility::Zip::IZipFile*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IZipFile);
        if (*__IZipFile) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Utility::Zip::IZipConstants** __IZipConstants)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IZipConstants = (Elastos::Utility::Zip::IZipConstants*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IZipConstants);
        if (*__IZipConstants) __pNewObj->AddRef();
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
namespace Utility {
namespace Jar {
class CName
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICNameClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CName, RGM_SAME_DOMAIN,
                EIID_ICNameClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithName(name, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Boolean validateName,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICNameClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CName, RGM_SAME_DOMAIN,
                EIID_ICNameClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithNameValidateName(name, validateName, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Utility::Jar::IName** __IName)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IName = (Elastos::Utility::Jar::IName*)__pNewObj->Probe(Elastos::Utility::Jar::EIID_IName);
        if (*__IName) __pNewObj->AddRef();
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
        /* [in] */ _ELASTOS Boolean validateName,
        /* [out] */ Elastos::Utility::Jar::IName** __IName)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, validateName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IName = (Elastos::Utility::Jar::IName*)__pNewObj->Probe(Elastos::Utility::Jar::EIID_IName);
        if (*__IName) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Boolean validateName,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, validateName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Boolean validateName,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, validateName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Boolean validateName,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, validateName, &__pNewObj);
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
namespace Utility {
namespace Jar {
class CAttributes
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::Jar::IAttributes * attributes,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAttributesClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAttributes, RGM_SAME_DOMAIN,
                EIID_ICAttributesClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithAttributes(attributes, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAttributesClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAttributes, RGM_SAME_DOMAIN,
                EIID_ICAttributesClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSize(size, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Jar::IAttributes** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAttributes, RGM_SAME_DOMAIN, Elastos::Utility::Jar::EIID_IAttributes, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAttributes, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IMap** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAttributes, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IMap, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAttributes, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAttributes, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAttributes, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Jar::IAttributes * attributes,
        /* [out] */ Elastos::Utility::Jar::IAttributes** __IAttributes)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(attributes, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAttributes = (Elastos::Utility::Jar::IAttributes*)__pNewObj->Probe(Elastos::Utility::Jar::EIID_IAttributes);
        if (*__IAttributes) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Jar::IAttributes * attributes,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(attributes, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Jar::IAttributes * attributes,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(attributes, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Jar::IAttributes * attributes,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(attributes, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Jar::IAttributes * attributes,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(attributes, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Jar::IAttributes * attributes,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(attributes, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::Utility::Jar::IAttributes** __IAttributes)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAttributes = (Elastos::Utility::Jar::IAttributes*)__pNewObj->Probe(Elastos::Utility::Jar::EIID_IAttributes);
        if (*__IAttributes) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(size, &__pNewObj);
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
namespace Utility {
namespace Jar {
class CJarEntry
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJarEntryClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJarEntry, RGM_SAME_DOMAIN,
                EIID_ICJarEntryClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithName(name, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::Zip::IZipEntry * zipEntry,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJarEntryClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJarEntry, RGM_SAME_DOMAIN,
                EIID_ICJarEntryClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithZipEntry(zipEntry, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::Jar::IJarEntry * jarEntry,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJarEntryClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJarEntry, RGM_SAME_DOMAIN,
                EIID_ICJarEntryClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithJarEntry(jarEntry, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Utility::Jar::IJarEntry** __IJarEntry)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJarEntry = (Elastos::Utility::Jar::IJarEntry*)__pNewObj->Probe(Elastos::Utility::Jar::EIID_IJarEntry);
        if (*__IJarEntry) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Utility::Zip::IZipEntry** __IZipEntry)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IZipEntry = (Elastos::Utility::Zip::IZipEntry*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IZipEntry);
        if (*__IZipEntry) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
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
        /* [in] */ Elastos::Utility::Zip::IZipEntry * zipEntry,
        /* [out] */ Elastos::Utility::Jar::IJarEntry** __IJarEntry)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(zipEntry, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJarEntry = (Elastos::Utility::Jar::IJarEntry*)__pNewObj->Probe(Elastos::Utility::Jar::EIID_IJarEntry);
        if (*__IJarEntry) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Zip::IZipEntry * zipEntry,
        /* [out] */ Elastos::Utility::Zip::IZipEntry** __IZipEntry)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(zipEntry, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IZipEntry = (Elastos::Utility::Zip::IZipEntry*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IZipEntry);
        if (*__IZipEntry) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Zip::IZipEntry * zipEntry,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(zipEntry, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Zip::IZipEntry * zipEntry,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(zipEntry, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Zip::IZipEntry * zipEntry,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(zipEntry, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Zip::IZipEntry * zipEntry,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(zipEntry, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Jar::IJarEntry * jarEntry,
        /* [out] */ Elastos::Utility::Jar::IJarEntry** __IJarEntry)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(jarEntry, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJarEntry = (Elastos::Utility::Jar::IJarEntry*)__pNewObj->Probe(Elastos::Utility::Jar::EIID_IJarEntry);
        if (*__IJarEntry) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Jar::IJarEntry * jarEntry,
        /* [out] */ Elastos::Utility::Zip::IZipEntry** __IZipEntry)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(jarEntry, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IZipEntry = (Elastos::Utility::Zip::IZipEntry*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IZipEntry);
        if (*__IZipEntry) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Jar::IJarEntry * jarEntry,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(jarEntry, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Jar::IJarEntry * jarEntry,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(jarEntry, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Jar::IJarEntry * jarEntry,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(jarEntry, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Jar::IJarEntry * jarEntry,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(jarEntry, &__pNewObj);
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
namespace Utility {
namespace Jar {
class CJarFile
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJarFileClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJarFile, RGM_SAME_DOMAIN,
                EIID_ICJarFileClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFile(file, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJarFileClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJarFile, RGM_SAME_DOMAIN,
                EIID_ICJarFileClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFileVerify(file, verify, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean verify,
        /* [in] */ _ELASTOS Int32 mode,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJarFileClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJarFile, RGM_SAME_DOMAIN,
                EIID_ICJarFileClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFileVerifyMode(file, verify, mode, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& filename,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJarFileClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJarFile, RGM_SAME_DOMAIN,
                EIID_ICJarFileClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFilename(filename, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& filename,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJarFileClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJarFile, RGM_SAME_DOMAIN,
                EIID_ICJarFileClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFilenameVerify(filename, verify, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::Utility::Jar::IJarFile** __IJarFile)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJarFile = (Elastos::Utility::Jar::IJarFile*)__pNewObj->Probe(Elastos::Utility::Jar::EIID_IJarFile);
        if (*__IJarFile) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::Utility::Zip::IZipFile** __IZipFile)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IZipFile = (Elastos::Utility::Zip::IZipFile*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IZipFile);
        if (*__IZipFile) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ Elastos::Utility::Jar::IJarFile** __IJarFile)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, verify, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJarFile = (Elastos::Utility::Jar::IJarFile*)__pNewObj->Probe(Elastos::Utility::Jar::EIID_IJarFile);
        if (*__IJarFile) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ Elastos::Utility::Zip::IZipFile** __IZipFile)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, verify, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IZipFile = (Elastos::Utility::Zip::IZipFile*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IZipFile);
        if (*__IZipFile) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, verify, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, verify, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, verify, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, verify, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean verify,
        /* [in] */ _ELASTOS Int32 mode,
        /* [out] */ Elastos::Utility::Jar::IJarFile** __IJarFile)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, verify, mode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJarFile = (Elastos::Utility::Jar::IJarFile*)__pNewObj->Probe(Elastos::Utility::Jar::EIID_IJarFile);
        if (*__IJarFile) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean verify,
        /* [in] */ _ELASTOS Int32 mode,
        /* [out] */ Elastos::Utility::Zip::IZipFile** __IZipFile)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, verify, mode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IZipFile = (Elastos::Utility::Zip::IZipFile*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IZipFile);
        if (*__IZipFile) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean verify,
        /* [in] */ _ELASTOS Int32 mode,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, verify, mode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean verify,
        /* [in] */ _ELASTOS Int32 mode,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, verify, mode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean verify,
        /* [in] */ _ELASTOS Int32 mode,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, verify, mode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean verify,
        /* [in] */ _ELASTOS Int32 mode,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, verify, mode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [out] */ Elastos::Utility::Jar::IJarFile** __IJarFile)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJarFile = (Elastos::Utility::Jar::IJarFile*)__pNewObj->Probe(Elastos::Utility::Jar::EIID_IJarFile);
        if (*__IJarFile) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [out] */ Elastos::Utility::Zip::IZipFile** __IZipFile)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IZipFile = (Elastos::Utility::Zip::IZipFile*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IZipFile);
        if (*__IZipFile) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ Elastos::Utility::Jar::IJarFile** __IJarFile)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, verify, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJarFile = (Elastos::Utility::Jar::IJarFile*)__pNewObj->Probe(Elastos::Utility::Jar::EIID_IJarFile);
        if (*__IJarFile) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ Elastos::Utility::Zip::IZipFile** __IZipFile)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, verify, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IZipFile = (Elastos::Utility::Zip::IZipFile*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IZipFile);
        if (*__IZipFile) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, verify, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, verify, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, verify, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, verify, &__pNewObj);
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
namespace Utility {
namespace Jar {
class CJarInputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJarInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJarInputStream, RGM_SAME_DOMAIN,
                EIID_ICJarInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithStreamVerify(stream, verify, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJarInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJarInputStream, RGM_SAME_DOMAIN,
                EIID_ICJarInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithStream(stream, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ Elastos::Utility::Jar::IJarInputStream** __IJarInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, verify, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJarInputStream = (Elastos::Utility::Jar::IJarInputStream*)__pNewObj->Probe(Elastos::Utility::Jar::EIID_IJarInputStream);
        if (*__IJarInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ Elastos::Utility::Zip::IZipInputStream** __IZipInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, verify, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IZipInputStream = (Elastos::Utility::Zip::IZipInputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IZipInputStream);
        if (*__IZipInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ Elastos::Utility::Zip::IInflaterInputStream** __IInflaterInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, verify, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInflaterInputStream = (Elastos::Utility::Zip::IInflaterInputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IInflaterInputStream);
        if (*__IInflaterInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ Elastos::IO::IFilterInputStream** __IFilterInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, verify, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterInputStream = (Elastos::IO::IFilterInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterInputStream);
        if (*__IFilterInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, verify, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, verify, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, verify, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, verify, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [in] */ _ELASTOS Boolean verify,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, verify, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [out] */ Elastos::Utility::Jar::IJarInputStream** __IJarInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJarInputStream = (Elastos::Utility::Jar::IJarInputStream*)__pNewObj->Probe(Elastos::Utility::Jar::EIID_IJarInputStream);
        if (*__IJarInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [out] */ Elastos::Utility::Zip::IZipInputStream** __IZipInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IZipInputStream = (Elastos::Utility::Zip::IZipInputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IZipInputStream);
        if (*__IZipInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [out] */ Elastos::Utility::Zip::IInflaterInputStream** __IInflaterInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInflaterInputStream = (Elastos::Utility::Zip::IInflaterInputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IInflaterInputStream);
        if (*__IInflaterInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [out] */ Elastos::IO::IFilterInputStream** __IFilterInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterInputStream = (Elastos::IO::IFilterInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterInputStream);
        if (*__IFilterInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * stream,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(stream, &__pNewObj);
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
namespace Utility {
namespace Jar {
class CJarOutputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Jar::IManifest * manifest,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJarOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJarOutputStream, RGM_SAME_DOMAIN,
                EIID_ICJarOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOsManifest(os, manifest, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJarOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJarOutputStream, RGM_SAME_DOMAIN,
                EIID_ICJarOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOs(os, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Jar::IManifest * manifest,
        /* [out] */ Elastos::Utility::Jar::IJarOutputStream** __IJarOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, manifest, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJarOutputStream = (Elastos::Utility::Jar::IJarOutputStream*)__pNewObj->Probe(Elastos::Utility::Jar::EIID_IJarOutputStream);
        if (*__IJarOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Jar::IManifest * manifest,
        /* [out] */ Elastos::Utility::Zip::IZipOutputStream** __IZipOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, manifest, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IZipOutputStream = (Elastos::Utility::Zip::IZipOutputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IZipOutputStream);
        if (*__IZipOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Jar::IManifest * manifest,
        /* [out] */ Elastos::Utility::Zip::IDeflaterOutputStream** __IDeflaterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, manifest, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDeflaterOutputStream = (Elastos::Utility::Zip::IDeflaterOutputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IDeflaterOutputStream);
        if (*__IDeflaterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Jar::IManifest * manifest,
        /* [out] */ Elastos::IO::IFilterOutputStream** __IFilterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, manifest, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterOutputStream = (Elastos::IO::IFilterOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterOutputStream);
        if (*__IFilterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Jar::IManifest * manifest,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, manifest, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Jar::IManifest * manifest,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, manifest, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Jar::IManifest * manifest,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, manifest, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Jar::IManifest * manifest,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, manifest, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Jar::IManifest * manifest,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, manifest, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::Utility::Jar::IManifest * manifest,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, manifest, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ Elastos::Utility::Jar::IJarOutputStream** __IJarOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJarOutputStream = (Elastos::Utility::Jar::IJarOutputStream*)__pNewObj->Probe(Elastos::Utility::Jar::EIID_IJarOutputStream);
        if (*__IJarOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ Elastos::Utility::Zip::IZipOutputStream** __IZipOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IZipOutputStream = (Elastos::Utility::Zip::IZipOutputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IZipOutputStream);
        if (*__IZipOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ Elastos::Utility::Zip::IDeflaterOutputStream** __IDeflaterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDeflaterOutputStream = (Elastos::Utility::Zip::IDeflaterOutputStream*)__pNewObj->Probe(Elastos::Utility::Zip::EIID_IDeflaterOutputStream);
        if (*__IDeflaterOutputStream) __pNewObj->AddRef();
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
}
namespace Elastos {
namespace Utility {
namespace Jar {
class CManifest
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICManifestClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CManifest, RGM_SAME_DOMAIN,
                EIID_ICManifestClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIs(is, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::Jar::IManifest * mani,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICManifestClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CManifest, RGM_SAME_DOMAIN,
                EIID_ICManifestClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithMani(mani, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Jar::IManifest** __object)
    {
        return _CObject_CreateInstance(ECLSID_CManifest, RGM_SAME_DOMAIN, Elastos::Utility::Jar::EIID_IManifest, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CManifest, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CManifest, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CManifest, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CManifest, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ Elastos::Utility::Jar::IManifest** __IManifest)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IManifest = (Elastos::Utility::Jar::IManifest*)__pNewObj->Probe(Elastos::Utility::Jar::EIID_IManifest);
        if (*__IManifest) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
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
        /* [in] */ Elastos::Utility::Jar::IManifest * mani,
        /* [out] */ Elastos::Utility::Jar::IManifest** __IManifest)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mani, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IManifest = (Elastos::Utility::Jar::IManifest*)__pNewObj->Probe(Elastos::Utility::Jar::EIID_IManifest);
        if (*__IManifest) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Jar::IManifest * mani,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mani, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Jar::IManifest * mani,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mani, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Jar::IManifest * mani,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mani, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Jar::IManifest * mani,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(mani, &__pNewObj);
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
namespace Utility {
namespace Jar {
class CPack200
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Utility::Jar::IPack200** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPack200, RGM_SAME_DOMAIN, Elastos::Utility::Jar::EIID_IPack200, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPack200, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPack200, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPack200, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}

#endif // __Elastos_CoreLibrary_Utility_Zip_h__
