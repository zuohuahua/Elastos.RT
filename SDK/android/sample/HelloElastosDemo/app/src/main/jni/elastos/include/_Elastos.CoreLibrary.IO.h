#ifndef ___Elastos_CoreLibrary_IO_h__
#define ___Elastos_CoreLibrary_IO_h__

#include <Elastos.CoreLibrary.h>

EXTERN_C ELAPI _Impl_AcquireCallbackHandler(PInterface pServerObj, _ELASTOS REIID iid, PInterface *ppHandler);
EXTERN_C ELAPI _Impl_CheckClsId(PInterface pServerObj, const _ELASTOS ClassID* pClassid, PInterface *ppServerObj);

namespace Elastos {
namespace IO {
CAR_INTERFACE("C5501B52-03D2-849B-2DFD-705052868D1F")
IFlushable : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFlushable*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFlushable*)pObj->Probe(EIID_IFlushable);
    }

    static CARAPI_(IFlushable*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFlushable*)pObj->Probe(EIID_IFlushable);
    }

    virtual CARAPI Flush() = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("D4591B41-0312-839A-F5FC-705052868D1F")
ICloseable : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICloseable*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICloseable*)pObj->Probe(EIID_ICloseable);
    }

    static CARAPI_(ICloseable*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICloseable*)pObj->Probe(EIID_ICloseable);
    }

    virtual CARAPI Close() = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("1E751F30-97D2-243F-4ABC-40F1A3BD8D1B")
IAutoCloseable : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAutoCloseable*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAutoCloseable*)pObj->Probe(EIID_IAutoCloseable);
    }

    static CARAPI_(IAutoCloseable*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAutoCloseable*)pObj->Probe(EIID_IAutoCloseable);
    }

    virtual CARAPI Close() = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("03FD4E5A-96D2-6CB5-84C1-F8E1A0A40C1B")
IInputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInputStream*)pObj->Probe(EIID_IInputStream);
    }

    static CARAPI_(IInputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInputStream*)pObj->Probe(EIID_IInputStream);
    }

    virtual CARAPI Available(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Mark(
        /* [in] */ _ELASTOS Int32 readLimit) = 0;

    virtual CARAPI IsMarkSupported(
        /* [out] */ _ELASTOS Boolean * supported) = 0;

    virtual CARAPI Read(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Read(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Read(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Reset() = 0;

    virtual CARAPI Skip(
        /* [in] */ _ELASTOS Int64 byteCount,
        /* [out] */ _ELASTOS Int64 * number) = 0;

    virtual CARAPI Close() = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("3571373A-5492-28D9-48C0-F8D1DEC60D19")
IOutputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IOutputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IOutputStream*)pObj->Probe(EIID_IOutputStream);
    }

    static CARAPI_(IOutputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IOutputStream*)pObj->Probe(EIID_IOutputStream);
    }

    virtual CARAPI Write(
        /* [in] */ _ELASTOS Int32 oneByte) = 0;

    virtual CARAPI Write(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer) = 0;

    virtual CARAPI Write(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 count) = 0;

    virtual CARAPI CheckError(
        /* [out] */ _ELASTOS Boolean * hasError) = 0;

    virtual CARAPI Close() = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("6B5F1E4F-03D2-3516-9F6D-59CB46188C1F")
IFilterInputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFilterInputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFilterInputStream*)pObj->Probe(EIID_IFilterInputStream);
    }

    static CARAPI_(IFilterInputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFilterInputStream*)pObj->Probe(EIID_IFilterInputStream);
    }

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("5BED1F23-03D2-2F16-6EDC-972A1B050918")
IFilterOutputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFilterOutputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFilterOutputStream*)pObj->Probe(EIID_IFilterOutputStream);
    }

    static CARAPI_(IFilterOutputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFilterOutputStream*)pObj->Probe(EIID_IFilterOutputStream);
    }

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("0FFD202C-1A92-FFFD-64A3-2001E3477B1B")
IBufferedInputStream : public IInterface
{
    static const _ELASTOS Int32 DEFAULT_BUFFER_SIZE = 8192;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBufferedInputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBufferedInputStream*)pObj->Probe(EIID_IBufferedInputStream);
    }

    static CARAPI_(IBufferedInputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBufferedInputStream*)pObj->Probe(EIID_IBufferedInputStream);
    }

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("008B2132-1A92-52FD-65A3-2001E3477B1B")
IBufferedOutputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBufferedOutputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBufferedOutputStream*)pObj->Probe(EIID_IBufferedOutputStream);
    }

    static CARAPI_(IBufferedOutputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBufferedOutputStream*)pObj->Probe(EIID_IBufferedOutputStream);
    }

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("6AB81948-19D2-3F3D-1C94-9461E387040C")
IReadable : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IReadable*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IReadable*)pObj->Probe(EIID_IReadable);
    }

    static CARAPI_(IReadable*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IReadable*)pObj->Probe(EIID_IReadable);
    }

    virtual CARAPI Read(
        /* [in] */ Elastos::IO::ICharBuffer * cb,
        /* [out] */ _ELASTOS Int32 * number) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("9BDB4638-DC52-ED1F-6DDC-9061E387BB1F")
IReader : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IReader*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IReader*)pObj->Probe(EIID_IReader);
    }

    static CARAPI_(IReader*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IReader*)pObj->Probe(EIID_IReader);
    }

    virtual CARAPI Mark(
        /* [in] */ _ELASTOS Int32 readLimit) = 0;

    virtual CARAPI IsMarkSupported(
        /* [out] */ _ELASTOS Boolean * supported) = 0;

    virtual CARAPI Read(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Read(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buffer,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Read(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buffer,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 count,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI IsReady(
        /* [out] */ _ELASTOS Boolean * ready) = 0;

    virtual CARAPI Reset() = 0;

    virtual CARAPI Skip(
        /* [in] */ _ELASTOS Int64 charCount,
        /* [out] */ _ELASTOS Int64 * number) = 0;

    virtual CARAPI Read(
        /* [in] */ Elastos::IO::ICharBuffer * target,
        /* [out] */ _ELASTOS Int32 * number) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("A38D232F-1A92-71FD-7FB4-B77143868D1F")
IBufferedReader : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBufferedReader*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBufferedReader*)pObj->Probe(EIID_IBufferedReader);
    }

    static CARAPI_(IBufferedReader*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBufferedReader*)pObj->Probe(EIID_IBufferedReader);
    }

    virtual CARAPI ReadLine(
        /* [out] */ _ELASTOS String * contents) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("A75F362D-F992-ED1F-6DDC-9061E387BB1F")
IWriter : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IWriter*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IWriter*)pObj->Probe(EIID_IWriter);
    }

    static CARAPI_(IWriter*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IWriter*)pObj->Probe(EIID_IWriter);
    }

    virtual CARAPI Write(
        /* [in] */ _ELASTOS Int32 oneChar32) = 0;

    virtual CARAPI Write(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buffer) = 0;

    virtual CARAPI Write(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buffer,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 count) = 0;

    virtual CARAPI Write(
        /* [in] */ const _ELASTOS String& str) = 0;

    virtual CARAPI Write(
        /* [in] */ const _ELASTOS String& str,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 count) = 0;

    virtual CARAPI CheckError(
        /* [out] */ _ELASTOS Boolean * hasError) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("D5832236-1A92-E6FD-7FB4-B77143868D1F")
IBufferedWriter : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBufferedWriter*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBufferedWriter*)pObj->Probe(EIID_IBufferedWriter);
    }

    static CARAPI_(IBufferedWriter*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBufferedWriter*)pObj->Probe(EIID_IBufferedWriter);
    }

    virtual CARAPI NewLine() = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("E5B6212E-9B52-281B-B0FC-938D82048C1F")
IByteArrayInputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IByteArrayInputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IByteArrayInputStream*)pObj->Probe(EIID_IByteArrayInputStream);
    }

    static CARAPI_(IByteArrayInputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IByteArrayInputStream*)pObj->Probe(EIID_IByteArrayInputStream);
    }

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("CCA8582C-9B52-281B-B048-958D82048C1F")
IByteArrayOutputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IByteArrayOutputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IByteArrayOutputStream*)pObj->Probe(EIID_IByteArrayOutputStream);
    }

    static CARAPI_(IByteArrayOutputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IByteArrayOutputStream*)pObj->Probe(EIID_IByteArrayOutputStream);
    }

    virtual CARAPI Reset() = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI ToByteArray(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** bytes) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI ToString(
        /* [in] */ _ELASTOS Int32 hibyte,
        /* [out] */ _ELASTOS String * rev) = 0;

    virtual CARAPI ToString(
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI WriteTo(
        /* [in] */ Elastos::IO::IOutputStream * os) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("EAF21C2B-8312-2415-6A60-89FBA3BD8D1B")
ICharArrayReader : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICharArrayReader*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharArrayReader*)pObj->Probe(EIID_ICharArrayReader);
    }

    static CARAPI_(ICharArrayReader*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharArrayReader*)pObj->Probe(EIID_ICharArrayReader);
    }

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("C5163A3C-8312-2415-6A60-31FFA3BD8D1B")
ICharArrayWriter : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICharArrayWriter*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharArrayWriter*)pObj->Probe(EIID_ICharArrayWriter);
    }

    static CARAPI_(ICharArrayWriter*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharArrayWriter*)pObj->Probe(EIID_ICharArrayWriter);
    }

    virtual CARAPI Reset() = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI ToCharArray(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Char32> ** buffer) = 0;

    virtual CARAPI WriteTo(
        /* [in] */ Elastos::IO::IWriter * ot) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("D8A6AA3C-A612-3F7F-DADB-B821C3C60F77")
IDataInput : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDataInput*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDataInput*)pObj->Probe(EIID_IDataInput);
    }

    static CARAPI_(IDataInput*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDataInput*)pObj->Probe(EIID_IDataInput);
    }

    virtual CARAPI ReadBoolean(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI ReadByte(
        /* [out] */ _ELASTOS Byte * value) = 0;

    virtual CARAPI ReadChar(
        /* [out] */ _ELASTOS Char32 * value) = 0;

    virtual CARAPI ReadDouble(
        /* [out] */ _ELASTOS Double * value) = 0;

    virtual CARAPI ReadFloat(
        /* [out] */ _ELASTOS Float * value) = 0;

    virtual CARAPI ReadFully(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer) = 0;

    virtual CARAPI ReadFully(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 byteCount) = 0;

    virtual CARAPI ReadInt32(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI ReadLine(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI ReadInt64(
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI ReadInt16(
        /* [out] */ _ELASTOS Int16 * value) = 0;

    virtual CARAPI ReadUnsignedByte(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI ReadUnsignedInt16(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI ReadUTF(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI SkipBytes(
        /* [in] */ _ELASTOS Int32 count,
        /* [out] */ _ELASTOS Int32 * value) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("CAEC1C2D-A612-B27F-5190-80F1A3BD8D1B")
IDataInputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDataInputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDataInputStream*)pObj->Probe(EIID_IDataInputStream);
    }

    static CARAPI_(IDataInputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDataInputStream*)pObj->Probe(EIID_IDataInputStream);
    }

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("1EC9292B-A612-B27F-5190-801101C58B19")
IDataInputStreamHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDataInputStreamHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDataInputStreamHelper*)pObj->Probe(EIID_IDataInputStreamHelper);
    }

    static CARAPI_(IDataInputStreamHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDataInputStreamHelper*)pObj->Probe(EIID_IDataInputStreamHelper);
    }

    virtual CARAPI ReadUTF(
        /* [in] */ Elastos::IO::IDataInput * dataInput,
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("B563932A-2612-3FA9-DADB-B821C3C60F77")
IDataOutput : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDataOutput*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDataOutput*)pObj->Probe(EIID_IDataOutput);
    }

    static CARAPI_(IDataOutput*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDataOutput*)pObj->Probe(EIID_IDataOutput);
    }

    virtual CARAPI Write(
        /* [in] */ _ELASTOS Int32 oneByte) = 0;

    virtual CARAPI Write(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer) = 0;

    virtual CARAPI Write(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 count) = 0;

    virtual CARAPI WriteBoolean(
        /* [in] */ _ELASTOS Boolean val) = 0;

    virtual CARAPI WriteByte(
        /* [in] */ _ELASTOS Int32 val) = 0;

    virtual CARAPI WriteBytes(
        /* [in] */ const _ELASTOS String& str) = 0;

    virtual CARAPI WriteChar(
        /* [in] */ _ELASTOS Int32 val) = 0;

    virtual CARAPI WriteChars(
        /* [in] */ const _ELASTOS String& str) = 0;

    virtual CARAPI WriteDouble(
        /* [in] */ _ELASTOS Double val) = 0;

    virtual CARAPI WriteFloat(
        /* [in] */ _ELASTOS Float val) = 0;

    virtual CARAPI WriteInt32(
        /* [in] */ _ELASTOS Int32 val) = 0;

    virtual CARAPI WriteInt64(
        /* [in] */ _ELASTOS Int64 val) = 0;

    virtual CARAPI WriteInt16(
        /* [in] */ _ELASTOS Int32 val) = 0;

    virtual CARAPI WriteUTF(
        /* [in] */ const _ELASTOS String& str) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("31CC9B39-2612-B2A9-5190-80F1A3BD8D1B")
IDataOutputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDataOutputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDataOutputStream*)pObj->Probe(EIID_IDataOutputStream);
    }

    static CARAPI_(IDataOutputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDataOutputStream*)pObj->Probe(EIID_IDataOutputStream);
    }

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI WriteBoolean(
        /* [in] */ _ELASTOS Boolean val) = 0;

    virtual CARAPI WriteByte(
        /* [in] */ _ELASTOS Int32 val) = 0;

    virtual CARAPI WriteBytes(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer) = 0;

    virtual CARAPI WriteBytes(
        /* [in] */ const _ELASTOS String& str) = 0;

    virtual CARAPI WriteChar(
        /* [in] */ _ELASTOS Int32 val) = 0;

    virtual CARAPI WriteChars(
        /* [in] */ const _ELASTOS String& str) = 0;

    virtual CARAPI WriteDouble(
        /* [in] */ _ELASTOS Double val) = 0;

    virtual CARAPI WriteFloat(
        /* [in] */ _ELASTOS Float val) = 0;

    virtual CARAPI WriteInt32(
        /* [in] */ _ELASTOS Int32 val) = 0;

    virtual CARAPI WriteInt64(
        /* [in] */ _ELASTOS Int64 val) = 0;

    virtual CARAPI WriteInt16(
        /* [in] */ _ELASTOS Int32 val) = 0;

    virtual CARAPI WriteUTF(
        /* [in] */ const _ELASTOS String& str) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("35F1251E-0392-2FE3-79A3-E7C3A2EF693F")
IEmulatedFieldsForDumping : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IEmulatedFieldsForDumping*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEmulatedFieldsForDumping*)pObj->Probe(EIID_IEmulatedFieldsForDumping);
    }

    static CARAPI_(IEmulatedFieldsForDumping*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEmulatedFieldsForDumping*)pObj->Probe(EIID_IEmulatedFieldsForDumping);
    }

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("CD7B3644-8712-0167-3D3A-8A20E8444A0B")
ISerializationHandleMap : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISerializationHandleMap*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISerializationHandleMap*)pObj->Probe(EIID_ISerializationHandleMap);
    }

    static CARAPI_(ISerializationHandleMap*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISerializationHandleMap*)pObj->Probe(EIID_ISerializationHandleMap);
    }

    virtual CARAPI Get(
        /* [in] */ IInterface * key,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ _ELASTOS Int32 value,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * empty) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("5D78F62C-B512-ED1F-6DDC-9061E387BB1F")
IFile : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFile*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFile*)pObj->Probe(EIID_IFile);
    }

    static CARAPI_(IFile*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFile*)pObj->Probe(EIID_IFile);
    }

    virtual CARAPI CanExecute(
        /* [out] */ _ELASTOS Boolean * canExecute) = 0;

    virtual CARAPI CanRead(
        /* [out] */ _ELASTOS Boolean * canRead) = 0;

    virtual CARAPI CanWrite(
        /* [out] */ _ELASTOS Boolean * canWrite) = 0;

    virtual CARAPI CompareTo(
        /* [in] */ Elastos::IO::IFile * another,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI Delete(
        /* [out] */ _ELASTOS Boolean * isDeleted) = 0;

    virtual CARAPI Delete() = 0;

    virtual CARAPI DeleteOnExit() = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * obj,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * pCode) = 0;

    virtual CARAPI Exists(
        /* [out] */ _ELASTOS Boolean * isExist) = 0;

    virtual CARAPI GetAbsolutePath(
        /* [out] */ _ELASTOS String * path) = 0;

    virtual CARAPI GetAbsoluteFile(
        /* [out] */ Elastos::IO::IFile ** file) = 0;

    virtual CARAPI GetCanonicalPath(
        /* [out] */ _ELASTOS String * path) = 0;

    virtual CARAPI GetCanonicalFile(
        /* [out] */ Elastos::IO::IFile ** file) = 0;

    virtual CARAPI GetName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetParent(
        /* [out] */ _ELASTOS String * parent) = 0;

    virtual CARAPI GetParentFile(
        /* [out] */ Elastos::IO::IFile ** file) = 0;

    virtual CARAPI GetPath(
        /* [out] */ _ELASTOS String * path) = 0;

    virtual CARAPI IsAbsolute(
        /* [out] */ _ELASTOS Boolean * isAbsolute) = 0;

    virtual CARAPI IsDirectory(
        /* [out] */ _ELASTOS Boolean * isDirectory) = 0;

    virtual CARAPI IsFile(
        /* [out] */ _ELASTOS Boolean * isFile) = 0;

    virtual CARAPI IsHidden(
        /* [out] */ _ELASTOS Boolean * isHidden) = 0;

    virtual CARAPI GetLastModified(
        /* [out] */ _ELASTOS Int64 * time) = 0;

    virtual CARAPI SetLastModified(
        /* [in] */ _ELASTOS Int64 time,
        /* [out] */ _ELASTOS Boolean * succeeded) = 0;

    virtual CARAPI SetReadOnly(
        /* [out] */ _ELASTOS Boolean * succeeded) = 0;

    virtual CARAPI SetExecutable(
        /* [in] */ _ELASTOS Boolean executable,
        /* [in] */ _ELASTOS Boolean ownerOnly,
        /* [out] */ _ELASTOS Boolean * succeeded) = 0;

    virtual CARAPI SetExecutable(
        /* [in] */ _ELASTOS Boolean executable,
        /* [out] */ _ELASTOS Boolean * succeeded) = 0;

    virtual CARAPI SetReadable(
        /* [in] */ _ELASTOS Boolean readable,
        /* [in] */ _ELASTOS Boolean ownerOnly,
        /* [out] */ _ELASTOS Boolean * succeeded) = 0;

    virtual CARAPI SetReadable(
        /* [in] */ _ELASTOS Boolean readable,
        /* [out] */ _ELASTOS Boolean * succeeded) = 0;

    virtual CARAPI SetWritable(
        /* [in] */ _ELASTOS Boolean writable,
        /* [in] */ _ELASTOS Boolean ownerOnly,
        /* [out] */ _ELASTOS Boolean * succeeded) = 0;

    virtual CARAPI SetWritable(
        /* [in] */ _ELASTOS Boolean writable,
        /* [out] */ _ELASTOS Boolean * succeeded) = 0;

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int64 * len) = 0;

    virtual CARAPI List(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** files) = 0;

    virtual CARAPI List(
        /* [in] */ Elastos::IO::IFilenameFilter * filter,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** files) = 0;

    virtual CARAPI ListFiles(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::IO::IFile *> ** files) = 0;

    virtual CARAPI ListFiles(
        /* [in] */ Elastos::IO::IFilenameFilter * filter,
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::IO::IFile *> ** files) = 0;

    virtual CARAPI ListFiles(
        /* [in] */ Elastos::IO::IFileFilter * filter,
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::IO::IFile *> ** files) = 0;

    virtual CARAPI Mkdir(
        /* [out] */ _ELASTOS Boolean * succeeded) = 0;

    virtual CARAPI Mkdirs(
        /* [out] */ _ELASTOS Boolean * succeeded) = 0;

    virtual CARAPI CreateNewFile(
        /* [out] */ _ELASTOS Boolean * succeeded) = 0;

    virtual CARAPI RenameTo(
        /* [in] */ Elastos::IO::IFile * newPath,
        /* [out] */ _ELASTOS Boolean * succeeded) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI ToURI(
        /* [out] */ Elastos::Net::IURI ** uri) = 0;

    virtual CARAPI ToURL(
        /* [out] */ Elastos::Net::IURL ** uri) = 0;

    virtual CARAPI GetTotalSpace(
        /* [out] */ _ELASTOS Int64 * space) = 0;

    virtual CARAPI GetUsableSpace(
        /* [out] */ _ELASTOS Int64 * space) = 0;

    virtual CARAPI GetFreeSpace(
        /* [out] */ _ELASTOS Int64 * space) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("F2D37C3E-B512-2808-5ECC-B8FFA3BD8D1B")
IFileHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFileHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileHelper*)pObj->Probe(EIID_IFileHelper);
    }

    static CARAPI_(IFileHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileHelper*)pObj->Probe(EIID_IFileHelper);
    }

    virtual CARAPI CreateTempFile(
        /* [in] */ const _ELASTOS String& prefix,
        /* [in] */ const _ELASTOS String& suffix,
        /* [out] */ Elastos::IO::IFile ** file) = 0;

    virtual CARAPI CreateTempFile(
        /* [in] */ const _ELASTOS String& prefix,
        /* [in] */ const _ELASTOS String& suffix,
        /* [in] */ Elastos::IO::IFile * directory,
        /* [out] */ Elastos::IO::IFile ** file) = 0;

    virtual CARAPI GetSeparatorChar(
        /* [out] */ _ELASTOS Char32 * separatorChar) = 0;

    virtual CARAPI GetSeparator(
        /* [out] */ _ELASTOS String * separator) = 0;

    virtual CARAPI GetPathSeparatorChar(
        /* [out] */ _ELASTOS Char32 * pathSeparatorChar) = 0;

    virtual CARAPI GetPathSeparator(
        /* [out] */ _ELASTOS String * pathSeparator) = 0;

    virtual CARAPI ListRoots(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::IO::IFile *> ** files) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("284C4C49-03D2-2916-8D98-D0ABF6EA0F07")
IFileDescriptor : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFileDescriptor*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileDescriptor*)pObj->Probe(EIID_IFileDescriptor);
    }

    static CARAPI_(IFileDescriptor*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileDescriptor*)pObj->Probe(EIID_IFileDescriptor);
    }

    virtual CARAPI Sync() = 0;

    virtual CARAPI Valid(
        /* [out] */ _ELASTOS Boolean * isValid) = 0;

    virtual CARAPI GetInt(
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI GetDescriptor(
        /* [out] */ _ELASTOS Int32 * fd) = 0;

    virtual CARAPI SetDescriptor(
        /* [in] */ _ELASTOS Int32 fd) = 0;

    virtual CARAPI IsSocket(
        /* [out] */ _ELASTOS Boolean * isSocket) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("50593E56-03D2-2916-8D98-D0ABF66A0414")
IFileDescriptorHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFileDescriptorHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileDescriptorHelper*)pObj->Probe(EIID_IFileDescriptorHelper);
    }

    static CARAPI_(IFileDescriptorHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileDescriptorHelper*)pObj->Probe(EIID_IFileDescriptorHelper);
    }

    virtual CARAPI GetInFile(
        /* [out] */ Elastos::IO::IFileDescriptor ** inFile) = 0;

    virtual CARAPI GetOutFile(
        /* [out] */ Elastos::IO::IFileDescriptor ** outFile) = 0;

    virtual CARAPI GetErrFile(
        /* [out] */ Elastos::IO::IFileDescriptor ** errFile) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("AFC71D3C-B512-2C07-5EDC-B8FFA3BD8D1B")
IFileFilter : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFileFilter*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileFilter*)pObj->Probe(EIID_IFileFilter);
    }

    static CARAPI_(IFileFilter*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileFilter*)pObj->Probe(EIID_IFileFilter);
    }

    virtual CARAPI Accept(
        /* [in] */ Elastos::IO::IFile * pathname,
        /* [out] */ _ELASTOS Boolean * succeeded) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("E1242133-B512-B27F-5190-80F1A3BD8D1B")
IFileInputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFileInputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileInputStream*)pObj->Probe(EIID_IFileInputStream);
    }

    static CARAPI_(IFileInputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileInputStream*)pObj->Probe(EIID_IFileInputStream);
    }

    virtual CARAPI GetFD(
        /* [out] */ Elastos::IO::IFileDescriptor ** fd) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("F8AE2C27-3512-B2A9-5190-80F1A3BD8D1B")
IFileOutputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFileOutputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileOutputStream*)pObj->Probe(EIID_IFileOutputStream);
    }

    static CARAPI_(IFileOutputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileOutputStream*)pObj->Probe(EIID_IFileOutputStream);
    }

    virtual CARAPI GetChannel(
        /* [out] */ Elastos::IO::Channels::IFileChannel ** channel) = 0;

    virtual CARAPI GetFD(
        /* [out] */ Elastos::IO::IFileDescriptor ** fd) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("77384652-8652-3C67-6D2C-FEE1A0A40C1B")
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
        /* [out] */ Elastos::IO::IPermissionCollection ** object) = 0;

    virtual CARAPI GetActions(
        /* [out] */ _ELASTOS String * actions) = 0;

    virtual CARAPI Implies(
        /* [in] */ Elastos::IO::IPermission * p,
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("CCA92148-8652-3C67-6D2C-2EE2F2D5C41F")
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

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("12F21B26-B512-F70C-61B0-B011FF477B1B")
IFilePermission : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFilePermission*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFilePermission*)pObj->Probe(EIID_IFilePermission);
    }

    static CARAPI_(IFilePermission*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFilePermission*)pObj->Probe(EIID_IFilePermission);
    }

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("FF92293D-3FD2-28D9-48C0-88FBA3BD8D1B")
IInputStreamReader : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInputStreamReader*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInputStreamReader*)pObj->Probe(EIID_IInputStreamReader);
    }

    static CARAPI_(IInputStreamReader*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInputStreamReader*)pObj->Probe(EIID_IInputStreamReader);
    }

    virtual CARAPI GetEncoding(
        /* [out] */ _ELASTOS String * encoding) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("08D41729-B512-3FB8-DADB-B821C3C60F77")
IFileReader : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFileReader*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileReader*)pObj->Probe(EIID_IFileReader);
    }

    static CARAPI_(IFileReader*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileReader*)pObj->Probe(EIID_IFileReader);
    }

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("12D42A3D-5492-28D9-48C0-30FFA3BD8D1B")
IOutputStreamWriter : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IOutputStreamWriter*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IOutputStreamWriter*)pObj->Probe(EIID_IOutputStreamWriter);
    }

    static CARAPI_(IOutputStreamWriter*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IOutputStreamWriter*)pObj->Probe(EIID_IOutputStreamWriter);
    }

    virtual CARAPI GetEncoding(
        /* [out] */ _ELASTOS String * encoding) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("FBB61723-3512-3FF3-DADB-B821C3C60F77")
IFileWriter : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFileWriter*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileWriter*)pObj->Probe(EIID_IFileWriter);
    }

    static CARAPI_(IFileWriter*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileWriter*)pObj->Probe(EIID_IFileWriter);
    }

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("D4002110-C3D2-68BE-4CC2-E8C3BE375AFF")
IFilenameFilter : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFilenameFilter*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFilenameFilter*)pObj->Probe(EIID_IFilenameFilter);
    }

    static CARAPI_(IFilenameFilter*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFilenameFilter*)pObj->Probe(EIID_IFilenameFilter);
    }

    virtual CARAPI Accept(
        /* [in] */ Elastos::IO::IFile * dir,
        /* [in] */ const _ELASTOS String& filename,
        /* [out] */ _ELASTOS Boolean * succeeded) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("A3521948-03D2-3516-9F9D-79F6C3414919")
IFilterReader : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFilterReader*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFilterReader*)pObj->Probe(EIID_IFilterReader);
    }

    static CARAPI_(IFilterReader*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFilterReader*)pObj->Probe(EIID_IFilterReader);
    }

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("96351957-03D2-3516-9FE1-A9F1C3414919")
IFilterWriter : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFilterWriter*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFilterWriter*)pObj->Probe(EIID_IFilterWriter);
    }

    static CARAPI_(IFilterWriter*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFilterWriter*)pObj->Probe(EIID_IFilterWriter);
    }

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("85803C4F-8552-1787-70C0-A05463CB5A36")
ILineNumberInputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILineNumberInputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILineNumberInputStream*)pObj->Probe(EIID_ILineNumberInputStream);
    }

    static CARAPI_(ILineNumberInputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILineNumberInputStream*)pObj->Probe(EIID_ILineNumberInputStream);
    }

    virtual CARAPI GetLineNumber(
        /* [out] */ _ELASTOS Int32 * lineNumber) = 0;

    virtual CARAPI SetLineNumber(
        /* [in] */ _ELASTOS Int32 lineNumber) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("86AA3756-8552-1787-70C0-A054E3CCB31F")
ILineNumberReader : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILineNumberReader*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILineNumberReader*)pObj->Probe(EIID_ILineNumberReader);
    }

    static CARAPI_(ILineNumberReader*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILineNumberReader*)pObj->Probe(EIID_ILineNumberReader);
    }

    virtual CARAPI GetLineNumber(
        /* [out] */ _ELASTOS Int32 * lineNumber) = 0;

    virtual CARAPI SetLineNumber(
        /* [in] */ _ELASTOS Int32 lineNumber) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("A93A4029-D192-3F7F-DADB-B821C3C60F77")
IObjectInput : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IObjectInput*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObjectInput*)pObj->Probe(EIID_IObjectInput);
    }

    static CARAPI_(IObjectInput*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObjectInput*)pObj->Probe(EIID_IObjectInput);
    }

    virtual CARAPI Available(
        /* [out] */ _ELASTOS Int32 * num) = 0;

    virtual CARAPI Close() = 0;

    virtual CARAPI Read(
        /* [out] */ _ELASTOS Int32 * num) = 0;

    virtual CARAPI Read(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [out] */ _ELASTOS Int32 * num) = 0;

    virtual CARAPI Read(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [in] */ _ELASTOS Int32 byteOffset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [out] */ _ELASTOS Int32 * num) = 0;

    virtual CARAPI ReadObject(
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI Skip(
        /* [in] */ _ELASTOS Int64 byteCount,
        /* [out] */ _ELASTOS Int64 * num) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("4F03574A-97D2-6B2D-D908-83F1C3414919")
IObjectInputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IObjectInputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObjectInputStream*)pObj->Probe(EIID_IObjectInputStream);
    }

    static CARAPI_(IObjectInputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObjectInputStream*)pObj->Probe(EIID_IObjectInputStream);
    }

    virtual CARAPI DefaultReadObject() = 0;

    virtual CARAPI ReadFields(
        /* [out] */ Elastos::IO::IObjectInputStreamGetField ** fields) = 0;

    virtual CARAPI ReadUnshared(
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI RegisterValidation(
        /* [in] */ Elastos::IO::IObjectInputValidation * object,
        /* [in] */ _ELASTOS Int32 priority) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("5F056854-97D2-6B2D-D908-8351E581C193")
IObjectInputStreamGetField : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IObjectInputStreamGetField*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObjectInputStreamGetField*)pObj->Probe(EIID_IObjectInputStreamGetField);
    }

    static CARAPI_(IObjectInputStreamGetField*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObjectInputStreamGetField*)pObj->Probe(EIID_IObjectInputStreamGetField);
    }

    virtual CARAPI GetObjectStreamClass(
        /* [out] */ Elastos::IO::IObjectStreamClass ** osClass) = 0;

    virtual CARAPI IsDefaulted(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Boolean * isDefaulted) = 0;

    virtual CARAPI Get(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Boolean defaultValue,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetChar(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Char32 defaultValue,
        /* [out] */ _ELASTOS Char32 * value) = 0;

    virtual CARAPI GetByte(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Byte defaultValue,
        /* [out] */ _ELASTOS Byte * value) = 0;

    virtual CARAPI Get(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Int16 defaultValue,
        /* [out] */ _ELASTOS Int16 * value) = 0;

    virtual CARAPI Get(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Int32 defaultValue,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Get(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Int64 defaultValue,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI Get(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Float defaultValue,
        /* [out] */ _ELASTOS Float * value) = 0;

    virtual CARAPI Get(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Double defaultValue,
        /* [out] */ _ELASTOS Double * value) = 0;

    virtual CARAPI Get(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ IInterface * defaultValue,
        /* [out] */ IInterface ** value) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("DBD63059-97D2-6B2D-ED38-FAE1A0A40C1B")
IObjectInputValidation : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IObjectInputValidation*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObjectInputValidation*)pObj->Probe(EIID_IObjectInputValidation);
    }

    static CARAPI_(IObjectInputValidation*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObjectInputValidation*)pObj->Probe(EIID_IObjectInputValidation);
    }

    virtual CARAPI ValidateObject() = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("53112E30-5192-3FA9-DADB-B821C3C60F77")
IObjectOutput : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IObjectOutput*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObjectOutput*)pObj->Probe(EIID_IObjectOutput);
    }

    static CARAPI_(IObjectOutput*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObjectOutput*)pObj->Probe(EIID_IObjectOutput);
    }

    virtual CARAPI Close() = 0;

    virtual CARAPI Flush() = 0;

    virtual CARAPI WriteObject(
        /* [in] */ IInterface * obj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("11636924-5192-B2A9-5190-80F1A3BD8D1B")
IObjectOutputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IObjectOutputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObjectOutputStream*)pObj->Probe(EIID_IObjectOutputStream);
    }

    static CARAPI_(IObjectOutputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObjectOutputStream*)pObj->Probe(EIID_IObjectOutputStream);
    }

    virtual CARAPI DefaultWriteObject() = 0;

    virtual CARAPI PutFields(
        /* [out] */ Elastos::IO::IObjectOutputStreamPutField ** fields) = 0;

    virtual CARAPI Reset() = 0;

    virtual CARAPI UseProtocolVersion(
        /* [in] */ _ELASTOS Int32 ver) = 0;

    virtual CARAPI WriteFields() = 0;

    virtual CARAPI WriteUnshared(
        /* [in] */ IInterface * object) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("6E9B4F31-5192-B2A9-5190-80D1F6010B14")
IObjectOutputStreamPutField : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IObjectOutputStreamPutField*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObjectOutputStreamPutField*)pObj->Probe(EIID_IObjectOutputStreamPutField);
    }

    static CARAPI_(IObjectOutputStreamPutField*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObjectOutputStreamPutField*)pObj->Probe(EIID_IObjectOutputStreamPutField);
    }

    virtual CARAPI Put(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI PutChar(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Char32 value) = 0;

    virtual CARAPI PutByte(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Byte value) = 0;

    virtual CARAPI Put(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Int16 value) = 0;

    virtual CARAPI Put(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Int32 value) = 0;

    virtual CARAPI Put(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Int64 value) = 0;

    virtual CARAPI Put(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Float value) = 0;

    virtual CARAPI Put(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Double value) = 0;

    virtual CARAPI Put(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI Write(
        /* [in] */ Elastos::IO::IObjectOutput * os) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("4D439229-5192-28D9-48C0-D0F3A3BD8D1B")
IObjectStreamClass : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IObjectStreamClass*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObjectStreamClass*)pObj->Probe(EIID_IObjectStreamClass);
    }

    static CARAPI_(IObjectStreamClass*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObjectStreamClass*)pObj->Probe(EIID_IObjectStreamClass);
    }

    virtual CARAPI GetField(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::IO::IObjectStreamField ** field) = 0;

    virtual CARAPI GetFields(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::IO::IObjectStreamField *> ** fields) = 0;

    virtual CARAPI GetName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetSerialVersionUID(
        /* [out] */ _ELASTOS Int64 * uid) = 0;

    virtual CARAPI ForClass(
        /* [out] */ _ELASTOS ClassID * id) = 0;

    virtual CARAPI IsSerializable(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI IsExternalizable(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI IsProxy(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI IsEnum(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Fields(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::IO::IObjectStreamField *> ** fields) = 0;

    virtual CARAPI SetFlags(
        /* [in] */ _ELASTOS Byte b) = 0;

    virtual CARAPI GetFlags(
        /* [out] */ _ELASTOS Byte * b) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("D6983338-5192-28D9-48C0-D01301C58B19")
IObjectStreamClassHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IObjectStreamClassHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObjectStreamClassHelper*)pObj->Probe(EIID_IObjectStreamClassHelper);
    }

    static CARAPI_(IObjectStreamClassHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObjectStreamClassHelper*)pObj->Probe(EIID_IObjectStreamClassHelper);
    }

    virtual CARAPI Lookup(
        /* [in] */ const _ELASTOS InterfaceID & cl,
        /* [out] */ Elastos::IO::IObjectStreamClass ** osClass) = 0;

    virtual CARAPI LookupAny(
        /* [in] */ const _ELASTOS InterfaceID & cl,
        /* [out] */ Elastos::IO::IObjectStreamClass ** osClass) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("335F6B45-17D2-C236-603C-3078F2878392")
IObjectStreamField : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IObjectStreamField*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObjectStreamField*)pObj->Probe(EIID_IObjectStreamField);
    }

    static CARAPI_(IObjectStreamField*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObjectStreamField*)pObj->Probe(EIID_IObjectStreamField);
    }

    virtual CARAPI CompareTo(
        /* [in] */ Elastos::IO::IObjectStreamField * o,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI GetName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetOffset(
        /* [out] */ _ELASTOS Int32 * offset) = 0;

    virtual CARAPI GetType(
        /* [out] */ _ELASTOS InterfaceID * type) = 0;

    virtual CARAPI GetTypeCode(
        /* [out] */ _ELASTOS Char32 * code) = 0;

    virtual CARAPI GetTypeString(
        /* [out] */ _ELASTOS String * type) = 0;

    virtual CARAPI IsPrimitive(
        /* [out] */ _ELASTOS Boolean * isPrimitive) = 0;

    virtual CARAPI IsUnshared(
        /* [out] */ _ELASTOS Boolean * isUnshared) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("8DDB5C3D-0652-3316-F4FF-938D82048C1F")
IPipedInputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPipedInputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPipedInputStream*)pObj->Probe(EIID_IPipedInputStream);
    }

    static CARAPI_(IPipedInputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPipedInputStream*)pObj->Probe(EIID_IPipedInputStream);
    }

    virtual CARAPI Available(
        /* [out] */ _ELASTOS Int32 * rev) = 0;

    virtual CARAPI Close() = 0;

    virtual CARAPI Connect(
        /* [in] */ IPipedOutputStream * src) = 0;

    virtual CARAPI EstablishConnection() = 0;

    virtual CARAPI Read(
        /* [out] */ _ELASTOS Int32 * rev) = 0;

    virtual CARAPI Read(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * bytes,
        /* [in] */ _ELASTOS Int32 byteOffset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [out] */ _ELASTOS Int32 * rev) = 0;

    virtual CARAPI Done() = 0;

    virtual CARAPI IsConnected(
        /* [out] */ _ELASTOS Boolean * rev) = 0;

};
}
}
CAR_INTERFACE("704B293E-0652-3316-F44B-958D82048C1F")
IPipedOutputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPipedOutputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPipedOutputStream*)pObj->Probe(EIID_IPipedOutputStream);
    }

    static CARAPI_(IPipedOutputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPipedOutputStream*)pObj->Probe(EIID_IPipedOutputStream);
    }

    virtual CARAPI Close() = 0;

    virtual CARAPI Connect(
        /* [in] */ Elastos::IO::IPipedInputStream * stream) = 0;

    virtual CARAPI Flush() = 0;

    virtual CARAPI Write(
        /* [in] */ _ELASTOS Int32 oneByte) = 0;

};
namespace Elastos {
namespace IO {
CAR_INTERFACE("8149AB29-59D2-28D9-48C0-F8D1DEC60D19")
IPrintStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPrintStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPrintStream*)pObj->Probe(EIID_IPrintStream);
    }

    static CARAPI_(IPrintStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPrintStream*)pObj->Probe(EIID_IPrintStream);
    }

    virtual CARAPI Format(
        /* [in] */ const _ELASTOS String& format,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * args,
        /* [out] */ Elastos::IO::IPrintStream ** ps) = 0;

    virtual CARAPI Format(
        /* [in] */ Elastos::Utility::ILocale * l,
        /* [in] */ const _ELASTOS String& format,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * args,
        /* [out] */ Elastos::IO::IPrintStream ** ps) = 0;

    virtual CARAPI Printf(
        /* [in] */ const _ELASTOS String& format,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * args,
        /* [out] */ Elastos::IO::IPrintStream ** ps) = 0;

    virtual CARAPI Printf(
        /* [in] */ Elastos::Utility::ILocale * l,
        /* [in] */ const _ELASTOS String& format,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * args,
        /* [out] */ Elastos::IO::IPrintStream ** ps) = 0;

    virtual CARAPI Print(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * chars) = 0;

    virtual CARAPI PrintChar(
        /* [in] */ _ELASTOS Char32 c) = 0;

    virtual CARAPI Print(
        /* [in] */ _ELASTOS Double d) = 0;

    virtual CARAPI Print(
        /* [in] */ _ELASTOS Float f) = 0;

    virtual CARAPI Print(
        /* [in] */ _ELASTOS Int32 i) = 0;

    virtual CARAPI Print(
        /* [in] */ _ELASTOS Int64 l) = 0;

    virtual CARAPI Print(
        /* [in] */ IInterface * o) = 0;

    virtual CARAPI Print(
        /* [in] */ const _ELASTOS String& str) = 0;

    virtual CARAPI Print(
        /* [in] */ _ELASTOS Boolean b) = 0;

    virtual CARAPI Println() = 0;

    virtual CARAPI Println(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * chars) = 0;

    virtual CARAPI PrintCharln(
        /* [in] */ _ELASTOS Char32 c) = 0;

    virtual CARAPI Println(
        /* [in] */ _ELASTOS Double d) = 0;

    virtual CARAPI Println(
        /* [in] */ _ELASTOS Float f) = 0;

    virtual CARAPI Println(
        /* [in] */ _ELASTOS Int32 i) = 0;

    virtual CARAPI Println(
        /* [in] */ _ELASTOS Int64 l) = 0;

    virtual CARAPI Println(
        /* [in] */ IInterface * o) = 0;

    virtual CARAPI Println(
        /* [in] */ const _ELASTOS String& str) = 0;

    virtual CARAPI Println(
        /* [in] */ _ELASTOS Boolean b) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("6F4AAB3F-59D2-3FF3-DADB-B821C3C60F77")
IPrintWriter : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPrintWriter*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPrintWriter*)pObj->Probe(EIID_IPrintWriter);
    }

    static CARAPI_(IPrintWriter*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPrintWriter*)pObj->Probe(EIID_IPrintWriter);
    }

    virtual CARAPI Format(
        /* [in] */ const _ELASTOS String& format,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * args) = 0;

    virtual CARAPI Format(
        /* [in] */ Elastos::Utility::ILocale * l,
        /* [in] */ const _ELASTOS String& format,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * args) = 0;

    virtual CARAPI Printf(
        /* [in] */ const _ELASTOS String& format,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * args) = 0;

    virtual CARAPI Printf(
        /* [in] */ Elastos::Utility::ILocale * l,
        /* [in] */ const _ELASTOS String& format,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * args) = 0;

    virtual CARAPI Print(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * charArray) = 0;

    virtual CARAPI PrintChar(
        /* [in] */ _ELASTOS Char32 ch) = 0;

    virtual CARAPI Print(
        /* [in] */ _ELASTOS Double dnum) = 0;

    virtual CARAPI Print(
        /* [in] */ _ELASTOS Float fnum) = 0;

    virtual CARAPI Print(
        /* [in] */ _ELASTOS Int32 inum) = 0;

    virtual CARAPI Print(
        /* [in] */ _ELASTOS Int64 lnum) = 0;

    virtual CARAPI Print(
        /* [in] */ IInterface * obj) = 0;

    virtual CARAPI Print(
        /* [in] */ const _ELASTOS String& str) = 0;

    virtual CARAPI Print(
        /* [in] */ _ELASTOS Boolean result) = 0;

    virtual CARAPI Println() = 0;

    virtual CARAPI Println(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * chars) = 0;

    virtual CARAPI PrintCharln(
        /* [in] */ _ELASTOS Char32 c) = 0;

    virtual CARAPI Println(
        /* [in] */ _ELASTOS Double d) = 0;

    virtual CARAPI Println(
        /* [in] */ _ELASTOS Float f) = 0;

    virtual CARAPI Println(
        /* [in] */ _ELASTOS Int32 i) = 0;

    virtual CARAPI Println(
        /* [in] */ _ELASTOS Int64 l) = 0;

    virtual CARAPI Println(
        /* [in] */ IInterface * obj) = 0;

    virtual CARAPI Println(
        /* [in] */ const _ELASTOS String& str) = 0;

    virtual CARAPI Println(
        /* [in] */ _ELASTOS Boolean b) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("51893250-0652-8A1C-25AD-DAB2968D3018")
IPushbackInputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPushbackInputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPushbackInputStream*)pObj->Probe(EIID_IPushbackInputStream);
    }

    static CARAPI_(IPushbackInputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPushbackInputStream*)pObj->Probe(EIID_IPushbackInputStream);
    }

    virtual CARAPI Unread(
        /* [in] */ _ELASTOS Int32 oneByte) = 0;

    virtual CARAPI Unread(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer) = 0;

    virtual CARAPI Unread(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("81842D57-0652-8A1C-25AD-3AF3EC878392")
IPushbackReader : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPushbackReader*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPushbackReader*)pObj->Probe(EIID_IPushbackReader);
    }

    static CARAPI_(IPushbackReader*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPushbackReader*)pObj->Probe(EIID_IPushbackReader);
    }

    virtual CARAPI Unread(
        /* [in] */ _ELASTOS Int32 oneChar) = 0;

    virtual CARAPI Unread(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buffer) = 0;

    virtual CARAPI Unread(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buffer,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("99916B22-06D2-3112-4EC8-803184DA8FF6")
IRandomAccessFile : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRandomAccessFile*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRandomAccessFile*)pObj->Probe(EIID_IRandomAccessFile);
    }

    static CARAPI_(IRandomAccessFile*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRandomAccessFile*)pObj->Probe(EIID_IRandomAccessFile);
    }

    virtual CARAPI GetChannel(
        /* [out] */ Elastos::IO::Channels::IFileChannel ** channel) = 0;

    virtual CARAPI GetFD(
        /* [out] */ Elastos::IO::IFileDescriptor ** fd) = 0;

    virtual CARAPI GetFilePointer(
        /* [out] */ _ELASTOS Int64 * offset) = 0;

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int64 * length) = 0;

    virtual CARAPI Read(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Read(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Read(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Seek(
        /* [in] */ _ELASTOS Int64 offset) = 0;

    virtual CARAPI SetLength(
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI Write(
        /* [in] */ _ELASTOS Int32 oneByte) = 0;

    virtual CARAPI Write(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer) = 0;

    virtual CARAPI Write(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 count) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("F600205B-0712-7314-6380-DAB2968D3018")
ISequenceInputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISequenceInputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISequenceInputStream*)pObj->Probe(EIID_ISequenceInputStream);
    }

    static CARAPI_(ISequenceInputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISequenceInputStream*)pObj->Probe(EIID_ISequenceInputStream);
    }

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("62D8FA4D-1B12-3061-DEB8-60D6B1C60F07")
IStreamTokenizer : public IInterface
{
    static const _ELASTOS Int32 TT_EOF = -1;
    static const _ELASTOS Int32 TT_EOL = 10;
    static const _ELASTOS Int32 TT_NUMBER = -2;
    static const _ELASTOS Int32 TT_WORD = -3;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IStreamTokenizer*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStreamTokenizer*)pObj->Probe(EIID_IStreamTokenizer);
    }

    static CARAPI_(IStreamTokenizer*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStreamTokenizer*)pObj->Probe(EIID_IStreamTokenizer);
    }

    virtual CARAPI GetLineno(
        /* [out] */ _ELASTOS Int32 * num) = 0;

    virtual CARAPI GetNextToken(
        /* [out] */ _ELASTOS Int32 * ttype) = 0;

    virtual CARAPI ParseNumbers() = 0;

    virtual CARAPI PushBack() = 0;

    virtual CARAPI ResetSyntax() = 0;

    virtual CARAPI SetCommentChar(
        /* [in] */ _ELASTOS Int32 ch) = 0;

    virtual CARAPI SetEolIsSignificant(
        /* [in] */ _ELASTOS Boolean flag) = 0;

    virtual CARAPI SetLowerCaseMode(
        /* [in] */ _ELASTOS Boolean flag) = 0;

    virtual CARAPI SetOrdinaryChar(
        /* [in] */ _ELASTOS Int32 ch) = 0;

    virtual CARAPI SetOrdinaryChars(
        /* [in] */ _ELASTOS Int32 low,
        /* [in] */ _ELASTOS Int32 hi) = 0;

    virtual CARAPI SetQuoteChar(
        /* [in] */ _ELASTOS Int32 ch) = 0;

    virtual CARAPI SetSlashSlashComments(
        /* [in] */ _ELASTOS Boolean flag) = 0;

    virtual CARAPI SetSlashStarComments(
        /* [in] */ _ELASTOS Boolean flag) = 0;

    virtual CARAPI SetWhitespaceChars(
        /* [in] */ _ELASTOS Int32 low,
        /* [in] */ _ELASTOS Int32 hi) = 0;

    virtual CARAPI SetWordChars(
        /* [in] */ _ELASTOS Int32 low,
        /* [in] */ _ELASTOS Int32 hi) = 0;

    virtual CARAPI GetNval(
        /* [out] */ _ELASTOS Double * nval) = 0;

    virtual CARAPI SetNval(
        /* [in] */ _ELASTOS Double nval) = 0;

    virtual CARAPI GetSval(
        /* [out] */ _ELASTOS String * sval) = 0;

    virtual CARAPI SetSval(
        /* [in] */ const _ELASTOS String& sval) = 0;

    virtual CARAPI GetTtype(
        /* [out] */ _ELASTOS Int32 * ttype) = 0;

    virtual CARAPI SetTtype(
        /* [in] */ _ELASTOS Int32 ttype) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("411C2434-6C12-FF35-64A3-2001E3477B1B")
IStringBufferInputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IStringBufferInputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStringBufferInputStream*)pObj->Probe(EIID_IStringBufferInputStream);
    }

    static CARAPI_(IStringBufferInputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStringBufferInputStream*)pObj->Probe(EIID_IStringBufferInputStream);
    }

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("875D1922-EC12-3FB8-DADB-B821C3C60F77")
IStringReader : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IStringReader*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStringReader*)pObj->Probe(EIID_IStringReader);
    }

    static CARAPI_(IStringReader*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStringReader*)pObj->Probe(EIID_IStringReader);
    }

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("EB142A3F-6C12-3FF3-DADB-B821C3C60F77")
IStringWriter : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IStringWriter*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStringWriter*)pObj->Probe(EIID_IStringWriter);
    }

    static CARAPI_(IStringWriter*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStringWriter*)pObj->Probe(EIID_IStringWriter);
    }

    virtual CARAPI GetBuffer(
        /* [out] */ Elastos::Core::IStringBuffer ** buf) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("4F97322D-0652-3316-F4C7-FDD1DEC60D19")
IPipedReader : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPipedReader*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPipedReader*)pObj->Probe(EIID_IPipedReader);
    }

    static CARAPI_(IPipedReader*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPipedReader*)pObj->Probe(EIID_IPipedReader);
    }

    virtual CARAPI Connect(
        /* [in] */ Elastos::IO::IPipedWriter * src) = 0;

    virtual CARAPI EstablishConnection() = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("C5AD1F2F-0652-3316-F49B-FFD1DEC60D19")
IPipedWriter : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPipedWriter*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPipedWriter*)pObj->Probe(EIID_IPipedWriter);
    }

    static CARAPI_(IPipedWriter*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPipedWriter*)pObj->Probe(EIID_IPipedWriter);
    }

    virtual CARAPI Connect(
        /* [in] */ Elastos::IO::IPipedReader * reader) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("AD3D3504-C2D2-28DF-569F-681DA1EF8CD6")
IByteOrderHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IByteOrderHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IByteOrderHelper*)pObj->Probe(EIID_IByteOrderHelper);
    }

    static CARAPI_(IByteOrderHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IByteOrderHelper*)pObj->Probe(EIID_IByteOrderHelper);
    }

    virtual CARAPI GetNativeOrder(
        /* [out] */ Elastos::IO::ByteOrder * byteOrder) = 0;

    virtual CARAPI IsNeedsSwap(
        /* [in] */ Elastos::IO::ByteOrder order,
        /* [out] */ _ELASTOS Boolean * isNeedsSwap) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("FEC1E13C-9A92-ED1F-6DDC-9061E387BB1F")
IBuffer : public IInterface
{
    static const _ELASTOS Int32 UNSET_MARK = -1;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBuffer*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBuffer*)pObj->Probe(EIID_IBuffer);
    }

    static CARAPI_(IBuffer*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBuffer*)pObj->Probe(EIID_IBuffer);
    }

    virtual CARAPI GetPrimitiveArray(
        /* [out] */ _ELASTOS Handle64 * offset) = 0;

    virtual CARAPI GetArray(
        /* [out] */ Elastos::Core::IArrayOf ** array) = 0;

    virtual CARAPI GetArrayOffset(
        /* [out] */ _ELASTOS Int32 * offset) = 0;

    virtual CARAPI GetCapacity(
        /* [out] */ _ELASTOS Int32 * cap) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Flip() = 0;

    virtual CARAPI HasArray(
        /* [out] */ _ELASTOS Boolean * hasArray) = 0;

    virtual CARAPI HasRemaining(
        /* [out] */ _ELASTOS Boolean * hasRemaining) = 0;

    virtual CARAPI IsDirect(
        /* [out] */ _ELASTOS Boolean * isDirect) = 0;

    virtual CARAPI IsReadOnly(
        /* [out] */ _ELASTOS Boolean * isReadOnly) = 0;

    virtual CARAPI GetLimit(
        /* [out] */ _ELASTOS Int32 * limit) = 0;

    virtual CARAPI SetLimit(
        /* [in] */ _ELASTOS Int32 newLimit) = 0;

    virtual CARAPI Mark() = 0;

    virtual CARAPI GetPosition(
        /* [out] */ _ELASTOS Int32 * pos) = 0;

    virtual CARAPI SetPosition(
        /* [in] */ _ELASTOS Int32 newPosition) = 0;

    virtual CARAPI GetRemaining(
        /* [out] */ _ELASTOS Int32 * remaining) = 0;

    virtual CARAPI Reset() = 0;

    virtual CARAPI Rewind() = 0;

    virtual CARAPI GetElementSizeShift(
        /* [out] */ _ELASTOS Int32 * elementSizeShift) = 0;

    virtual CARAPI GetEffectiveDirectAddress(
        /* [out] */ _ELASTOS Handle64 * effectiveDirectAddress) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("BF42FA26-9B52-281B-D4FC-686FE3860C1B")
IByteBuffer : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IByteBuffer*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IByteBuffer*)pObj->Probe(EIID_IByteBuffer);
    }

    static CARAPI_(IByteBuffer*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IByteBuffer*)pObj->Probe(EIID_IByteBuffer);
    }

    virtual CARAPI GetArray(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** array) = 0;

    virtual CARAPI AsCharBuffer(
        /* [out] */ Elastos::IO::ICharBuffer ** buffer) = 0;

    virtual CARAPI AsDoubleBuffer(
        /* [out] */ Elastos::IO::IDoubleBuffer ** buffer) = 0;

    virtual CARAPI AsFloatBuffer(
        /* [out] */ Elastos::IO::IFloatBuffer ** buffer) = 0;

    virtual CARAPI AsInt16Buffer(
        /* [out] */ Elastos::IO::IInt16Buffer ** buffer) = 0;

    virtual CARAPI AsInt32Buffer(
        /* [out] */ Elastos::IO::IInt32Buffer ** buffer) = 0;

    virtual CARAPI AsInt64Buffer(
        /* [out] */ Elastos::IO::IInt64Buffer ** buffer) = 0;

    virtual CARAPI AsReadOnlyBuffer(
        /* [out] */ Elastos::IO::IByteBuffer ** buffer) = 0;

    virtual CARAPI Compact() = 0;

    virtual CARAPI CompareTo(
        /* [in] */ Elastos::IO::IByteBuffer * other,
        /* [out] */ _ELASTOS Int32 * rst) = 0;

    virtual CARAPI Duplicate(
        /* [out] */ Elastos::IO::IByteBuffer ** buffer) = 0;

    virtual CARAPI Get(
        /* [out] */ _ELASTOS Byte * value) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Byte * value) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * dst) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * dst,
        /* [in] */ _ELASTOS Int32 dstOffset,
        /* [in] */ _ELASTOS Int32 byteCount) = 0;

    virtual CARAPI GetChar(
        /* [out] */ _ELASTOS Char32 * value) = 0;

    virtual CARAPI GetChar(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Char32 * value) = 0;

    virtual CARAPI GetDouble(
        /* [out] */ _ELASTOS Double * value) = 0;

    virtual CARAPI GetDouble(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Double * value) = 0;

    virtual CARAPI GetFloat(
        /* [out] */ _ELASTOS Float * value) = 0;

    virtual CARAPI GetFloat(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Float * value) = 0;

    virtual CARAPI GetInt32(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetInt32(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetInt64(
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI GetInt64(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI GetInt16(
        /* [out] */ _ELASTOS Int16 * value) = 0;

    virtual CARAPI GetInt16(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Int16 * value) = 0;

    virtual CARAPI GetOrder(
        /* [out] */ Elastos::IO::ByteOrder * byteOrder) = 0;

    virtual CARAPI SetOrder(
        /* [in] */ Elastos::IO::ByteOrder byteOrder) = 0;

    virtual CARAPI IsAccessible(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI SetAccessible(
        /* [in] */ _ELASTOS Boolean accessible) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS Byte b) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Byte b) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * src) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * src,
        /* [in] */ _ELASTOS Int32 srcOffset,
        /* [in] */ _ELASTOS Int32 byteCount) = 0;

    virtual CARAPI Put(
        /* [in] */ Elastos::IO::IByteBuffer * src) = 0;

    virtual CARAPI PutChar(
        /* [in] */ _ELASTOS Char32 value) = 0;

    virtual CARAPI PutChar(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Char32 value) = 0;

    virtual CARAPI PutDouble(
        /* [in] */ _ELASTOS Double value) = 0;

    virtual CARAPI PutDouble(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Double value) = 0;

    virtual CARAPI PutFloat(
        /* [in] */ _ELASTOS Float value) = 0;

    virtual CARAPI PutFloat(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Float value) = 0;

    virtual CARAPI PutInt16(
        /* [in] */ _ELASTOS Int16 value) = 0;

    virtual CARAPI PutInt16(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Int16 value) = 0;

    virtual CARAPI PutInt32(
        /* [in] */ _ELASTOS Int32 value) = 0;

    virtual CARAPI PutInt32(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Int32 value) = 0;

    virtual CARAPI PutInt64(
        /* [in] */ _ELASTOS Int64 value) = 0;

    virtual CARAPI PutInt64(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Int64 value) = 0;

    virtual CARAPI Slice(
        /* [out] */ Elastos::IO::IByteBuffer ** buffer) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("1D5D3B36-9B52-281B-D444-40F162C6FD1F")
IByteBufferHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IByteBufferHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IByteBufferHelper*)pObj->Probe(EIID_IByteBufferHelper);
    }

    static CARAPI_(IByteBufferHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IByteBufferHelper*)pObj->Probe(EIID_IByteBufferHelper);
    }

    virtual CARAPI Allocate(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::IO::IByteBuffer ** byteBuf) = 0;

    virtual CARAPI AllocateDirect(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::IO::IByteBuffer ** byteBuf) = 0;

    virtual CARAPI Wrap(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * array,
        /* [out] */ Elastos::IO::IByteBuffer ** byteBuf) = 0;

    virtual CARAPI Wrap(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * array,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [out] */ Elastos::IO::IByteBuffer ** byteBuf) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("C6F91C3B-9B52-281B-B0A8-F9D1DEC60D19")
IByteArrayBuffer : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IByteArrayBuffer*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IByteArrayBuffer*)pObj->Probe(EIID_IByteArrayBuffer);
    }

    static CARAPI_(IByteArrayBuffer*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IByteArrayBuffer*)pObj->Probe(EIID_IByteArrayBuffer);
    }

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("6A34A428-8312-2415-6AA8-F9D1DEC60D19")
ICharBuffer : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICharBuffer*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharBuffer*)pObj->Probe(EIID_ICharBuffer);
    }

    static CARAPI_(ICharBuffer*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharBuffer*)pObj->Probe(EIID_ICharBuffer);
    }

    virtual CARAPI GetArray(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Char32> ** array) = 0;

    virtual CARAPI AsReadOnlyBuffer(
        /* [out] */ Elastos::IO::ICharBuffer ** buffer) = 0;

    virtual CARAPI GetCharAt(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Char32 * value) = 0;

    virtual CARAPI Compact() = 0;

    virtual CARAPI Duplicate(
        /* [out] */ Elastos::IO::ICharBuffer ** buffer) = 0;

    virtual CARAPI Get(
        /* [out] */ _ELASTOS Char32 * value) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Char32 * value) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * dst) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * dst,
        /* [in] */ _ELASTOS Int32 dstOffset,
        /* [in] */ _ELASTOS Int32 charCount) = 0;

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI GetOrder(
        /* [out] */ Elastos::IO::ByteOrder * byteOrder) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS Char32 c) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Char32 c) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * src) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * src,
        /* [in] */ _ELASTOS Int32 srcOffset,
        /* [in] */ _ELASTOS Int32 charCount) = 0;

    virtual CARAPI Put(
        /* [in] */ Elastos::IO::ICharBuffer * src) = 0;

    virtual CARAPI Put(
        /* [in] */ const _ELASTOS String& str) = 0;

    virtual CARAPI Put(
        /* [in] */ const _ELASTOS String& str,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end) = 0;

    virtual CARAPI Slice(
        /* [out] */ Elastos::IO::ICharBuffer ** buffer) = 0;

    virtual CARAPI SubSequence(
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ Elastos::Core::ICharSequence ** csq) = 0;

    virtual CARAPI AppendChar(
        /* [in] */ _ELASTOS Char32 c) = 0;

    virtual CARAPI Append(
        /* [in] */ Elastos::Core::ICharSequence * csq) = 0;

    virtual CARAPI Append(
        /* [in] */ Elastos::Core::ICharSequence * csq,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end) = 0;

    virtual CARAPI Read(
        /* [in] */ Elastos::IO::ICharBuffer * target,
        /* [out] */ _ELASTOS Int32 * number) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("5D81353B-8312-2415-6AA8-8980E2C58CFB")
ICharBufferHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICharBufferHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharBufferHelper*)pObj->Probe(EIID_ICharBufferHelper);
    }

    static CARAPI_(ICharBufferHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharBufferHelper*)pObj->Probe(EIID_ICharBufferHelper);
    }

    virtual CARAPI Allocate(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::IO::ICharBuffer ** charBuf) = 0;

    virtual CARAPI Wrap(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * array,
        /* [out] */ Elastos::IO::ICharBuffer ** charBuf) = 0;

    virtual CARAPI Wrap(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * array,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 charCount,
        /* [out] */ Elastos::IO::ICharBuffer ** charBuf) = 0;

    virtual CARAPI Wrap(
        /* [in] */ Elastos::Core::ICharSequence * charSequence,
        /* [out] */ Elastos::IO::ICharBuffer ** charBuf) = 0;

    virtual CARAPI Wrap(
        /* [in] */ Elastos::Core::ICharSequence * cs,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ Elastos::IO::ICharBuffer ** charBuf) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("FC876928-2ED2-251C-5EA0-50F3A3BD8D1B")
IDoubleBuffer : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDoubleBuffer*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDoubleBuffer*)pObj->Probe(EIID_IDoubleBuffer);
    }

    static CARAPI_(IDoubleBuffer*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDoubleBuffer*)pObj->Probe(EIID_IDoubleBuffer);
    }

    virtual CARAPI GetArray(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Double> ** array) = 0;

    virtual CARAPI AsReadOnlyBuffer(
        /* [out] */ Elastos::IO::IDoubleBuffer ** buffer) = 0;

    virtual CARAPI Compact() = 0;

    virtual CARAPI Duplicate(
        /* [out] */ Elastos::IO::IDoubleBuffer ** buffer) = 0;

    virtual CARAPI Get(
        /* [out] */ _ELASTOS Double * value) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Double * value) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Double> * dst) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Double> * dst,
        /* [in] */ _ELASTOS Int32 dstOffset,
        /* [in] */ _ELASTOS Int32 doubleCount) = 0;

    virtual CARAPI GetOrder(
        /* [out] */ Elastos::IO::ByteOrder * byteOrder) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS Double d) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Double d) = 0;

    virtual CARAPI Put(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Double> & src) = 0;

    virtual CARAPI Put(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Double> & src,
        /* [in] */ _ELASTOS Int32 srcOffset,
        /* [in] */ _ELASTOS Int32 doubleCount) = 0;

    virtual CARAPI Put(
        /* [in] */ Elastos::IO::IDoubleBuffer * src) = 0;

    virtual CARAPI Slice(
        /* [out] */ Elastos::IO::IDoubleBuffer ** buffer) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("4DEA2F21-2ED2-251C-5EA0-501301C58B19")
IDoubleBufferHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDoubleBufferHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDoubleBufferHelper*)pObj->Probe(EIID_IDoubleBufferHelper);
    }

    static CARAPI_(IDoubleBufferHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDoubleBufferHelper*)pObj->Probe(EIID_IDoubleBufferHelper);
    }

    virtual CARAPI Allocate(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::IO::IDoubleBuffer ** doubleBuf) = 0;

    virtual CARAPI Wrap(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Double> * array,
        /* [out] */ Elastos::IO::IDoubleBuffer ** doubleBuf) = 0;

    virtual CARAPI Wrap(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Double> * array,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 doubleCount,
        /* [out] */ Elastos::IO::IDoubleBuffer ** doubleBuf) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("7970682A-83D2-3217-48DC-50F3A3BD8D1B")
IFloatBuffer : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFloatBuffer*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFloatBuffer*)pObj->Probe(EIID_IFloatBuffer);
    }

    static CARAPI_(IFloatBuffer*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFloatBuffer*)pObj->Probe(EIID_IFloatBuffer);
    }

    virtual CARAPI GetArray(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Float> ** array) = 0;

    virtual CARAPI AsReadOnlyBuffer(
        /* [out] */ Elastos::IO::IFloatBuffer ** buffer) = 0;

    virtual CARAPI Compact() = 0;

    virtual CARAPI Duplicate(
        /* [out] */ Elastos::IO::IFloatBuffer ** buffer) = 0;

    virtual CARAPI Get(
        /* [out] */ _ELASTOS Float * value) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Float * value) = 0;

    virtual CARAPI Get(
        /* [out] */ _ELASTOS ArrayOf<_ELASTOS Float> * dst) = 0;

    virtual CARAPI Get(
        /* [out] */ _ELASTOS ArrayOf<_ELASTOS Float> * dst,
        /* [in] */ _ELASTOS Int32 dstOffset,
        /* [in] */ _ELASTOS Int32 floatCount) = 0;

    virtual CARAPI GetOrder(
        /* [out] */ Elastos::IO::ByteOrder * byteOrder) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS Float f) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Float f) = 0;

    virtual CARAPI Put(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Float> & src) = 0;

    virtual CARAPI Put(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Float> & src,
        /* [in] */ _ELASTOS Int32 srcOffset,
        /* [in] */ _ELASTOS Int32 floatCount) = 0;

    virtual CARAPI Put(
        /* [in] */ Elastos::IO::IFloatBuffer * src) = 0;

    virtual CARAPI Slice(
        /* [out] */ Elastos::IO::IFloatBuffer ** buffer) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("F9A1380A-F3D2-E4CA-BDE0-698AD611FACE")
IFloatBufferHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFloatBufferHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFloatBufferHelper*)pObj->Probe(EIID_IFloatBufferHelper);
    }

    static CARAPI_(IFloatBufferHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFloatBufferHelper*)pObj->Probe(EIID_IFloatBufferHelper);
    }

    virtual CARAPI Allocate(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::IO::IFloatBuffer ** floatBuffer) = 0;

    virtual CARAPI WrapArray(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Float> * array,
        /* [out] */ Elastos::IO::IFloatBuffer ** floatBuffer) = 0;

    virtual CARAPI WrapArray(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Float> * array,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 floatCount,
        /* [out] */ Elastos::IO::IFloatBuffer ** floatBuffer) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("AF9E6831-C152-0600-D4FC-686FE3860C1B")
IInt16Buffer : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInt16Buffer*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInt16Buffer*)pObj->Probe(EIID_IInt16Buffer);
    }

    static CARAPI_(IInt16Buffer*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInt16Buffer*)pObj->Probe(EIID_IInt16Buffer);
    }

    virtual CARAPI GetArray(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Int16> ** array) = 0;

    virtual CARAPI AsReadOnlyBuffer(
        /* [out] */ Elastos::IO::IInt16Buffer ** buffer) = 0;

    virtual CARAPI Compact() = 0;

    virtual CARAPI Duplicate(
        /* [out] */ Elastos::IO::IInt16Buffer ** buffer) = 0;

    virtual CARAPI Get(
        /* [out] */ _ELASTOS Int16 * value) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Int16 * value) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int16> * dst) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int16> * dst,
        /* [in] */ _ELASTOS Int32 dstOffset,
        /* [in] */ _ELASTOS Int32 int16Count) = 0;

    virtual CARAPI GetOrder(
        /* [out] */ Elastos::IO::ByteOrder * byteOrder) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS Int16 s) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Int16 s) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int16> * src) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int16> * src,
        /* [in] */ _ELASTOS Int32 srcOffset,
        /* [in] */ _ELASTOS Int32 int16Count) = 0;

    virtual CARAPI Put(
        /* [in] */ Elastos::IO::IInt16Buffer * src) = 0;

    virtual CARAPI Slice(
        /* [out] */ Elastos::IO::IInt16Buffer ** buffer) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("06FB2E3D-C152-0600-D444-40F162C6FD1F")
IInt16BufferHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInt16BufferHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInt16BufferHelper*)pObj->Probe(EIID_IInt16BufferHelper);
    }

    static CARAPI_(IInt16BufferHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInt16BufferHelper*)pObj->Probe(EIID_IInt16BufferHelper);
    }

    virtual CARAPI Allocate(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::IO::IInt16Buffer ** int16Buffer) = 0;

    virtual CARAPI Wrap(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int16> * array,
        /* [out] */ Elastos::IO::IInt16Buffer ** int16Buffer) = 0;

    virtual CARAPI Wrap(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int16> * array,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 int16Count,
        /* [out] */ Elastos::IO::IInt16Buffer ** int16Buffer) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("B39C6839-C152-0201-D4FC-686FE3860C1B")
IInt32Buffer : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInt32Buffer*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInt32Buffer*)pObj->Probe(EIID_IInt32Buffer);
    }

    static CARAPI_(IInt32Buffer*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInt32Buffer*)pObj->Probe(EIID_IInt32Buffer);
    }

    virtual CARAPI GetArray(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Int32> ** array) = 0;

    virtual CARAPI AsReadOnlyBuffer(
        /* [out] */ Elastos::IO::IInt32Buffer ** buffer) = 0;

    virtual CARAPI Compact() = 0;

    virtual CARAPI Duplicate(
        /* [out] */ Elastos::IO::IInt32Buffer ** buffer) = 0;

    virtual CARAPI Get(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * dst) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * dst,
        /* [in] */ _ELASTOS Int32 dstOffset,
        /* [in] */ _ELASTOS Int32 int32Count) = 0;

    virtual CARAPI GetOrder(
        /* [out] */ Elastos::IO::ByteOrder * byteOrder) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS Int32 i) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Int32 i) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * src) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * src,
        /* [in] */ _ELASTOS Int32 srcOffset,
        /* [in] */ _ELASTOS Int32 int32Count) = 0;

    virtual CARAPI Put(
        /* [in] */ Elastos::IO::IInt32Buffer * src) = 0;

    virtual CARAPI Slice(
        /* [out] */ Elastos::IO::IInt32Buffer ** buffer) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("0AF92E26-C152-0201-D444-40F162C6FD1F")
IInt32BufferHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInt32BufferHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInt32BufferHelper*)pObj->Probe(EIID_IInt32BufferHelper);
    }

    static CARAPI_(IInt32BufferHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInt32BufferHelper*)pObj->Probe(EIID_IInt32BufferHelper);
    }

    virtual CARAPI Allocate(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::IO::IInt32Buffer ** int32Buffer) = 0;

    virtual CARAPI Wrap(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * array,
        /* [out] */ Elastos::IO::IInt32Buffer ** int32Buffer) = 0;

    virtual CARAPI Wrap(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * array,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 int32Count,
        /* [out] */ Elastos::IO::IInt32Buffer ** int32Buffer) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("B1996826-4152-0403-D4FC-686FE3860C1B")
IInt64Buffer : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInt64Buffer*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInt64Buffer*)pObj->Probe(EIID_IInt64Buffer);
    }

    static CARAPI_(IInt64Buffer*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInt64Buffer*)pObj->Probe(EIID_IInt64Buffer);
    }

    virtual CARAPI GetArray(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Int64> ** array) = 0;

    virtual CARAPI AsReadOnlyBuffer(
        /* [out] */ Elastos::IO::IInt64Buffer ** buffer) = 0;

    virtual CARAPI Compact() = 0;

    virtual CARAPI Duplicate(
        /* [out] */ Elastos::IO::IInt64Buffer ** buffer) = 0;

    virtual CARAPI Get(
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI Get(
        /* [out] */ _ELASTOS ArrayOf<_ELASTOS Int64> * dst) = 0;

    virtual CARAPI Get(
        /* [out] */ _ELASTOS ArrayOf<_ELASTOS Int64> * dst,
        /* [in] */ _ELASTOS Int32 dstOffset,
        /* [in] */ _ELASTOS Int32 int64Count) = 0;

    virtual CARAPI GetOrder(
        /* [out] */ Elastos::IO::ByteOrder * byteOrder) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS Int64 l) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Int64 l) = 0;

    virtual CARAPI Put(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int64> & src) = 0;

    virtual CARAPI Put(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int64> & src,
        /* [in] */ _ELASTOS Int32 srcOffset,
        /* [in] */ _ELASTOS Int32 int64Count) = 0;

    virtual CARAPI Put(
        /* [in] */ Elastos::IO::IInt64Buffer * src) = 0;

    virtual CARAPI Slice(
        /* [out] */ Elastos::IO::IInt64Buffer ** buffer) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("08F62E32-4152-0403-D444-40F162C6FD1F")
IInt64BufferHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInt64BufferHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInt64BufferHelper*)pObj->Probe(EIID_IInt64BufferHelper);
    }

    static CARAPI_(IInt64BufferHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInt64BufferHelper*)pObj->Probe(EIID_IInt64BufferHelper);
    }

    virtual CARAPI Allocate(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::IO::IInt64Buffer ** int64Buffer) = 0;

    virtual CARAPI Wrap(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int64> * array,
        /* [out] */ Elastos::IO::IInt64Buffer ** int64Buffer) = 0;

    virtual CARAPI Wrap(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int64> * array,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 int64Count,
        /* [out] */ Elastos::IO::IInt64Buffer ** int64Buffer) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("F2FA2E2E-CB52-FA19-DBDC-40A1E6477B1B")
IMappedByteBuffer : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMappedByteBuffer*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMappedByteBuffer*)pObj->Probe(EIID_IMappedByteBuffer);
    }

    static CARAPI_(IMappedByteBuffer*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMappedByteBuffer*)pObj->Probe(EIID_IMappedByteBuffer);
    }

    virtual CARAPI IsLoaded(
        /* [out] */ _ELASTOS Boolean * isLoaded) = 0;

    virtual CARAPI Load() = 0;

    virtual CARAPI Force() = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("13CD213E-2C92-2614-6EB4-B98142CD8FF6")
IDirectByteBuffer : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDirectByteBuffer*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDirectByteBuffer*)pObj->Probe(EIID_IDirectByteBuffer);
    }

    static CARAPI_(IDirectByteBuffer*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDirectByteBuffer*)pObj->Probe(EIID_IDirectByteBuffer);
    }

    virtual CARAPI Free() = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("027B312D-2C92-2614-6EB4-B981424D0414")
IDirectByteBufferHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDirectByteBufferHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDirectByteBufferHelper*)pObj->Probe(EIID_IDirectByteBufferHelper);
    }

    static CARAPI_(IDirectByteBufferHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDirectByteBufferHelper*)pObj->Probe(EIID_IDirectByteBufferHelper);
    }

    virtual CARAPI GetNewInstance(
        /* [in] */ _ELASTOS Int64 address,
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::IO::IDirectByteBuffer ** instance) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("F790533D-05D2-4377-7EB4-B77143868D1F")
INIOAccess : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INIOAccess*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INIOAccess*)pObj->Probe(EIID_INIOAccess);
    }

    static CARAPI_(INIOAccess*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INIOAccess*)pObj->Probe(EIID_INIOAccess);
    }

    virtual CARAPI GetBasePointer(
        /* [in] */ Elastos::IO::IBuffer * b,
        /* [out] */ _ELASTOS Int64 * result) = 0;

    virtual CARAPI GetBaseArray(
        /* [in] */ Elastos::IO::IBuffer * b,
        /* [out] */ IInterface ** result) = 0;

    virtual CARAPI GetRemainingBytes(
        /* [in] */ Elastos::IO::IBuffer * b,
        /* [out] */ _ELASTOS Int32 * remaining) = 0;

    virtual CARAPI GetBaseArrayOffset(
        /* [in] */ Elastos::IO::IBuffer * b,
        /* [out] */ _ELASTOS Int32 * result) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("CCDA274B-03D2-2916-8D98-D0ABF6EA1041")
IFileDescriptorChannel : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFileDescriptorChannel*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileDescriptorChannel*)pObj->Probe(EIID_IFileDescriptorChannel);
    }

    static CARAPI_(IFileDescriptorChannel*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileDescriptorChannel*)pObj->Probe(EIID_IFileDescriptorChannel);
    }

    virtual CARAPI GetFD(
        /* [out] */ Elastos::IO::IFileDescriptor ** desc) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("FEE92C33-3512-2B06-48C4-8881E245BD1F")
IFileChannelImpl : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFileChannelImpl*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileChannelImpl*)pObj->Probe(EIID_IFileChannelImpl);
    }

    static CARAPI_(IFileChannelImpl*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileChannelImpl*)pObj->Probe(EIID_IFileChannelImpl);
    }

    virtual CARAPI ReleaseLock(
        /* [in] */ Elastos::IO::Channels::IFileLock * lock) = 0;

    virtual CARAPI GetFD(
        /* [out] */ Elastos::IO::IFileDescriptor ** descriptor) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("278A5A1C-C5D2-DECA-CDBE-F6EFBCA47DCB")
INioUtils : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INioUtils*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INioUtils*)pObj->Probe(EIID_INioUtils);
    }

    static CARAPI_(INioUtils*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INioUtils*)pObj->Probe(EIID_INioUtils);
    }

    virtual CARAPI FreeDirectBuffer(
        /* [in] */ Elastos::IO::IByteBuffer * buffer) = 0;

    virtual CARAPI GetFD(
        /* [in] */ Elastos::IO::Channels::IFileChannel * fc,
        /* [out] */ Elastos::IO::IFileDescriptor ** outfd) = 0;

    virtual CARAPI NewFileChannel(
        /* [in] */ Elastos::IO::ICloseable * ioObject,
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 mode,
        /* [out] */ Elastos::IO::Channels::IFileChannel ** outchannel) = 0;

    virtual CARAPI GetUnsafeArray(
        /* [in] */ Elastos::IO::IByteBuffer * b,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** outbyte) = 0;

    virtual CARAPI GetUnsafeArrayOffset(
        /* [in] */ Elastos::IO::IByteBuffer * b,
        /* [out] */ _ELASTOS Int32 * value) = 0;

};
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("5EEB2351-10D2-4741-5FFC-705052868D1F")
IChannel : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IChannel*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IChannel*)pObj->Probe(EIID_IChannel);
    }

    static CARAPI_(IChannel*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IChannel*)pObj->Probe(EIID_IChannel);
    }

    virtual CARAPI IsOpen(
        /* [out] */ _ELASTOS Boolean * rst) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("7AF92D52-19D2-423D-340F-1174F4C50F07")
IReadableByteChannel : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IReadableByteChannel*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IReadableByteChannel*)pObj->Probe(EIID_IReadableByteChannel);
    }

    static CARAPI_(IReadableByteChannel*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IReadableByteChannel*)pObj->Probe(EIID_IReadableByteChannel);
    }

    virtual CARAPI Read(
        /* [in] */ Elastos::IO::IByteBuffer * buffer,
        /* [out] */ _ELASTOS Int32 * number) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("5F5B2E49-9E52-7A8C-8468-1E22E8E88B1F")
IWritableByteChannel : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IWritableByteChannel*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IWritableByteChannel*)pObj->Probe(EIID_IWritableByteChannel);
    }

    static CARAPI_(IWritableByteChannel*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IWritableByteChannel*)pObj->Probe(EIID_IWritableByteChannel);
    }

    virtual CARAPI Write(
        /* [in] */ Elastos::IO::IByteBuffer * buffer,
        /* [out] */ _ELASTOS Int32 * number) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("93967359-10D2-4741-5FD8-F8E1A0A40C1B")
IChannels : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IChannels*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IChannels*)pObj->Probe(EIID_IChannels);
    }

    static CARAPI_(IChannels*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IChannels*)pObj->Probe(EIID_IChannels);
    }

    virtual CARAPI NewInputStream(
        /* [in] */ Elastos::IO::Channels::IReadableByteChannel * channel,
        /* [out] */ Elastos::IO::IInputStream ** inputStream) = 0;

    virtual CARAPI NewOutputStream(
        /* [in] */ Elastos::IO::Channels::IWritableByteChannel * channel,
        /* [out] */ Elastos::IO::IOutputStream ** outputStream) = 0;

    virtual CARAPI NewChannel(
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [out] */ Elastos::IO::Channels::IReadableByteChannel ** inputChannel) = 0;

    virtual CARAPI NewChannel(
        /* [in] */ Elastos::IO::IOutputStream * outputStream,
        /* [out] */ Elastos::IO::Channels::IWritableByteChannel ** outputChannel) = 0;

    virtual CARAPI NewReader(
        /* [in] */ Elastos::IO::Channels::IReadableByteChannel * channel,
        /* [in] */ Elastos::IO::Charset::ICharsetDecoder * decoder,
        /* [in] */ _ELASTOS Int32 minBufferCapacity,
        /* [out] */ Elastos::IO::IReader ** reader) = 0;

    virtual CARAPI NewReader(
        /* [in] */ Elastos::IO::Channels::IReadableByteChannel * channel,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::IO::IReader ** reader) = 0;

    virtual CARAPI NewWriter(
        /* [in] */ Elastos::IO::Channels::IWritableByteChannel * channel,
        /* [in] */ Elastos::IO::Charset::ICharsetEncoder * encoder,
        /* [in] */ _ELASTOS Int32 minBufferCapacity,
        /* [out] */ Elastos::IO::IWriter ** writer) = 0;

    virtual CARAPI NewWriter(
        /* [in] */ Elastos::IO::Channels::IWritableByteChannel * channel,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::IO::IWriter ** writer) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("3EB3335F-8712-B04E-9F41-14A27988A0A3")
IScatteringByteChannel : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IScatteringByteChannel*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IScatteringByteChannel*)pObj->Probe(EIID_IScatteringByteChannel);
    }

    static CARAPI_(IScatteringByteChannel*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IScatteringByteChannel*)pObj->Probe(EIID_IScatteringByteChannel);
    }

    virtual CARAPI Read(
        /* [in] */ _ELASTOS ArrayOf<Elastos::IO::IByteBuffer *> * buffers,
        /* [out] */ _ELASTOS Int64 * ret) = 0;

    virtual CARAPI Read(
        /* [in] */ _ELASTOS ArrayOf<Elastos::IO::IByteBuffer *> * buffers,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ _ELASTOS Int64 * ret) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("3B133454-8412-FB47-F422-15A27988A0A3")
IGatheringByteChannel : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IGatheringByteChannel*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IGatheringByteChannel*)pObj->Probe(EIID_IGatheringByteChannel);
    }

    static CARAPI_(IGatheringByteChannel*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IGatheringByteChannel*)pObj->Probe(EIID_IGatheringByteChannel);
    }

    virtual CARAPI Write(
        /* [in] */ _ELASTOS ArrayOf<Elastos::IO::IByteBuffer *> * buffers,
        /* [out] */ _ELASTOS Int64 * ret) = 0;

    virtual CARAPI Write(
        /* [in] */ _ELASTOS ArrayOf<Elastos::IO::IByteBuffer *> * buffers,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ _ELASTOS Int64 * ret) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("36F52A45-96D2-7FCC-D5B2-B03444D0D117")
IInterruptibleChannel : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInterruptibleChannel*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInterruptibleChannel*)pObj->Probe(EIID_IInterruptibleChannel);
    }

    static CARAPI_(IInterruptibleChannel*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInterruptibleChannel*)pObj->Probe(EIID_IInterruptibleChannel);
    }

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("EBA69848-03D2-2916-8708-3AFAE2878392")
IFileChannel : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFileChannel*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileChannel*)pObj->Probe(EIID_IFileChannel);
    }

    static CARAPI_(IFileChannel*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileChannel*)pObj->Probe(EIID_IFileChannel);
    }

    virtual CARAPI Force(
        /* [in] */ _ELASTOS Boolean metadata) = 0;

    virtual CARAPI Lock(
        /* [out] */ Elastos::IO::Channels::IFileLock ** lock) = 0;

    virtual CARAPI Lock(
        /* [in] */ _ELASTOS Int64 position,
        /* [in] */ _ELASTOS Int64 size,
        /* [in] */ _ELASTOS Boolean shared,
        /* [out] */ Elastos::IO::Channels::IFileLock ** lock) = 0;

    virtual CARAPI Map(
        /* [in] */ Elastos::IO::Channels::FileChannelMapMode mode,
        /* [in] */ _ELASTOS Int64 position,
        /* [in] */ _ELASTOS Int64 size,
        /* [out] */ Elastos::IO::IMappedByteBuffer ** buffer) = 0;

    virtual CARAPI Position(
        /* [out] */ _ELASTOS Int64 * position) = 0;

    virtual CARAPI Position(
        /* [in] */ _ELASTOS Int64 newPosition) = 0;

    virtual CARAPI Read(
        /* [in] */ Elastos::IO::IByteBuffer * buffer,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Read(
        /* [in] */ Elastos::IO::IByteBuffer * buffer,
        /* [in] */ _ELASTOS Int64 position,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Read(
        /* [in] */ _ELASTOS ArrayOf<Elastos::IO::IByteBuffer *> * buffers,
        /* [out] */ _ELASTOS Int64 * number) = 0;

    virtual CARAPI Read(
        /* [in] */ _ELASTOS ArrayOf<Elastos::IO::IByteBuffer *> * buffers,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ _ELASTOS Int64 * number) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int64 * size) = 0;

    virtual CARAPI TransferFrom(
        /* [in] */ Elastos::IO::Channels::IReadableByteChannel * src,
        /* [in] */ _ELASTOS Int64 position,
        /* [in] */ _ELASTOS Int64 count,
        /* [out] */ _ELASTOS Int64 * number) = 0;

    virtual CARAPI TransferTo(
        /* [in] */ _ELASTOS Int64 position,
        /* [in] */ _ELASTOS Int64 count,
        /* [in] */ Elastos::IO::Channels::IWritableByteChannel * target,
        /* [out] */ _ELASTOS Int64 * number) = 0;

    virtual CARAPI Truncate(
        /* [in] */ _ELASTOS Int64 size,
        /* [out] */ Elastos::IO::Channels::IFileChannel ** channel) = 0;

    virtual CARAPI TryLock(
        /* [out] */ Elastos::IO::Channels::IFileLock ** lock) = 0;

    virtual CARAPI TryLock(
        /* [in] */ _ELASTOS Int64 position,
        /* [in] */ _ELASTOS Int64 size,
        /* [in] */ _ELASTOS Boolean shared,
        /* [out] */ Elastos::IO::Channels::IFileLock ** lock) = 0;

    virtual CARAPI Write(
        /* [in] */ Elastos::IO::IByteBuffer * buffer,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Write(
        /* [in] */ Elastos::IO::IByteBuffer * buffer,
        /* [in] */ _ELASTOS Int64 position,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Write(
        /* [in] */ _ELASTOS ArrayOf<Elastos::IO::IByteBuffer *> * buffers,
        /* [out] */ _ELASTOS Int64 * number) = 0;

    virtual CARAPI Write(
        /* [in] */ _ELASTOS ArrayOf<Elastos::IO::IByteBuffer *> * buffers,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ _ELASTOS Int64 * number) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("14738C43-0712-2914-5FE9-1922E8E88B1F")
ISelectableChannel : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISelectableChannel*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISelectableChannel*)pObj->Probe(EIID_ISelectableChannel);
    }

    static CARAPI_(ISelectableChannel*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISelectableChannel*)pObj->Probe(EIID_ISelectableChannel);
    }

    virtual CARAPI GetBlockingLock(
        /* [out] */ IObject ** obj) = 0;

    virtual CARAPI ConfigureBlocking(
        /* [in] */ _ELASTOS Boolean block,
        /* [out] */ Elastos::IO::Channels::ISelectableChannel ** selectableChannel) = 0;

    virtual CARAPI IsBlocking(
        /* [out] */ _ELASTOS Boolean * isBlocking) = 0;

    virtual CARAPI IsRegistered(
        /* [out] */ _ELASTOS Boolean * isRegistered) = 0;

    virtual CARAPI GetKeyFor(
        /* [in] */ Elastos::IO::Channels::ISelector * sel,
        /* [out] */ Elastos::IO::Channels::ISelectionKey ** key) = 0;

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::IO::Channels::Spi::ISelectorProvider ** provider) = 0;

    virtual CARAPI Register(
        /* [in] */ Elastos::IO::Channels::ISelector * sel,
        /* [in] */ _ELASTOS Int32 ops,
        /* [out] */ Elastos::IO::Channels::ISelectionKey ** key) = 0;

    virtual CARAPI Register(
        /* [in] */ Elastos::IO::Channels::ISelector * sel,
        /* [in] */ _ELASTOS Int32 ops,
        /* [in] */ IObject * obj,
        /* [out] */ Elastos::IO::Channels::ISelectionKey ** key) = 0;

    virtual CARAPI GetValidOps(
        /* [out] */ _ELASTOS Int32 * intValue) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("2898A825-6592-0DF9-7FB4-B77143868D1F")
ISelectionKey : public IInterface
{
    static const _ELASTOS Int32 OP_ACCEPT = 16;
    static const _ELASTOS Int32 OP_CONNECT = 8;
    static const _ELASTOS Int32 OP_READ = 1;
    static const _ELASTOS Int32 OP_WRITE = 4;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISelectionKey*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISelectionKey*)pObj->Probe(EIID_ISelectionKey);
    }

    static CARAPI_(ISelectionKey*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISelectionKey*)pObj->Probe(EIID_ISelectionKey);
    }

    virtual CARAPI Attach(
        /* [in] */ IObject * newObj,
        /* [out] */ IObject ** oldObj) = 0;

    virtual CARAPI Attachment(
        /* [out] */ IObject ** obj) = 0;

    virtual CARAPI Cancel() = 0;

    virtual CARAPI GetChannel(
        /* [out] */ Elastos::IO::Channels::ISelectableChannel ** channel) = 0;

    virtual CARAPI GetInterestOps(
        /* [out] */ _ELASTOS Int32 * ops) = 0;

    virtual CARAPI GetInterestOps(
        /* [in] */ _ELASTOS Int32 ops,
        /* [out] */ Elastos::IO::Channels::ISelectionKey ** key) = 0;

    virtual CARAPI IsAcceptable(
        /* [out] */ _ELASTOS Boolean * acceptable) = 0;

    virtual CARAPI IsConnectable(
        /* [out] */ _ELASTOS Boolean * connectable) = 0;

    virtual CARAPI IsReadable(
        /* [out] */ _ELASTOS Boolean * readable) = 0;

    virtual CARAPI IsValid(
        /* [out] */ _ELASTOS Boolean * valid) = 0;

    virtual CARAPI IsWritable(
        /* [out] */ _ELASTOS Boolean * writable) = 0;

    virtual CARAPI GetReadyOps(
        /* [out] */ _ELASTOS Int32 * ops) = 0;

    virtual CARAPI GetSelector(
        /* [out] */ Elastos::IO::Channels::ISelector ** selector) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("A75E6222-E592-3FFC-DADB-B821C3C60F77")
ISelector : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISelector*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISelector*)pObj->Probe(EIID_ISelector);
    }

    static CARAPI_(ISelector*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISelector*)pObj->Probe(EIID_ISelector);
    }

    virtual CARAPI Close() = 0;

    virtual CARAPI IsOpen(
        /* [out] */ _ELASTOS Boolean * isOpen) = 0;

    virtual CARAPI GetKeys(
        /* [out] */ Elastos::Utility::ISet ** keySet) = 0;

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::IO::Channels::Spi::ISelectorProvider ** provider) = 0;

    virtual CARAPI Select(
        /* [out] */ _ELASTOS Int32 * ret) = 0;

    virtual CARAPI Select(
        /* [in] */ _ELASTOS Int64 timeout,
        /* [out] */ _ELASTOS Int32 * ret) = 0;

    virtual CARAPI SelectedKeys(
        /* [out] */ Elastos::Utility::ISet ** keySet) = 0;

    virtual CARAPI SelectNow(
        /* [out] */ _ELASTOS Int32 * ret) = 0;

    virtual CARAPI Wakeup() = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("0B0F7929-6952-2B06-48C4-8881E2C58FF6")
ISocketChannel : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISocketChannel*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketChannel*)pObj->Probe(EIID_ISocketChannel);
    }

    static CARAPI_(ISocketChannel*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketChannel*)pObj->Probe(EIID_ISocketChannel);
    }

    virtual CARAPI GetSocket(
        /* [out] */ Elastos::Net::ISocket ** serverSocket) = 0;

    virtual CARAPI IsConnected(
        /* [out] */ _ELASTOS Boolean * isConnected) = 0;

    virtual CARAPI IsConnectionPending(
        /* [out] */ _ELASTOS Boolean * isConnectionPending) = 0;

    virtual CARAPI Connect(
        /* [in] */ Elastos::Net::ISocketAddress * address,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI FinishConnect(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Read(
        /* [in] */ Elastos::IO::IByteBuffer * target,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Read(
        /* [in] */ _ELASTOS ArrayOf<Elastos::IO::IByteBuffer *> * targets,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ _ELASTOS Int64 * number) = 0;

    virtual CARAPI Read(
        /* [in] */ _ELASTOS ArrayOf<Elastos::IO::IByteBuffer *> * targets,
        /* [out] */ _ELASTOS Int64 * number) = 0;

    virtual CARAPI Write(
        /* [in] */ Elastos::IO::IByteBuffer * buffer,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Write(
        /* [in] */ _ELASTOS ArrayOf<Elastos::IO::IByteBuffer *> * sources,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ _ELASTOS Int64 * number) = 0;

    virtual CARAPI Write(
        /* [in] */ _ELASTOS ArrayOf<Elastos::IO::IByteBuffer *> * buffers,
        /* [out] */ _ELASTOS Int64 * number) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("8F16310E-2712-2E9B-7A33-2B19C7E81BA1")
ISocketChannelHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISocketChannelHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketChannelHelper*)pObj->Probe(EIID_ISocketChannelHelper);
    }

    static CARAPI_(ISocketChannelHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketChannelHelper*)pObj->Probe(EIID_ISocketChannelHelper);
    }

    virtual CARAPI Open(
        /* [out] */ Elastos::IO::Channels::ISocketChannel ** socketChannel) = 0;

    virtual CARAPI Open(
        /* [in] */ Elastos::Net::ISocketAddress * address,
        /* [out] */ Elastos::IO::Channels::ISocketChannel ** socketChannel) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("3B9B3829-E612-0CD2-5690-881103C58B1F")
IServerSocketChannel : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IServerSocketChannel*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IServerSocketChannel*)pObj->Probe(EIID_IServerSocketChannel);
    }

    static CARAPI_(IServerSocketChannel*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IServerSocketChannel*)pObj->Probe(EIID_IServerSocketChannel);
    }

    virtual CARAPI GetSocket(
        /* [out] */ Elastos::Net::IServerSocket ** serverSocket) = 0;

    virtual CARAPI Accept(
        /* [out] */ Elastos::IO::Channels::ISocketChannel ** channel) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("18A7332D-E612-0CD2-5690-881103C58B08")
IServerSocketChannelHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IServerSocketChannelHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IServerSocketChannelHelper*)pObj->Probe(EIID_IServerSocketChannelHelper);
    }

    static CARAPI_(IServerSocketChannelHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IServerSocketChannelHelper*)pObj->Probe(EIID_IServerSocketChannelHelper);
    }

    virtual CARAPI Open(
        /* [out] */ Elastos::IO::Channels::IServerSocketChannel ** socketChannel) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("1D4D5544-0352-F246-600C-1174F4C50F07")
IDatagramChannel : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDatagramChannel*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatagramChannel*)pObj->Probe(EIID_IDatagramChannel);
    }

    static CARAPI_(IDatagramChannel*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatagramChannel*)pObj->Probe(EIID_IDatagramChannel);
    }

    virtual CARAPI GetSocket(
        /* [out] */ Elastos::Net::IDatagramSocket ** socket) = 0;

    virtual CARAPI IsConnected(
        /* [out] */ _ELASTOS Boolean * isConnected) = 0;

    virtual CARAPI Connect(
        /* [in] */ Elastos::Net::ISocketAddress * address,
        /* [out] */ Elastos::IO::Channels::IDatagramChannel ** channel) = 0;

    virtual CARAPI Disconnect() = 0;

    virtual CARAPI Receive(
        /* [in] */ Elastos::IO::IByteBuffer * target,
        /* [out] */ Elastos::Net::ISocketAddress ** address) = 0;

    virtual CARAPI Send(
        /* [in] */ Elastos::IO::IByteBuffer * source,
        /* [in] */ Elastos::Net::ISocketAddress * address,
        /* [out] */ _ELASTOS Int32 * number) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("DEA12F42-0352-F246-600C-1174F4450414")
IDatagramChannelHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDatagramChannelHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatagramChannelHelper*)pObj->Probe(EIID_IDatagramChannelHelper);
    }

    static CARAPI_(IDatagramChannelHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatagramChannelHelper*)pObj->Probe(EIID_IDatagramChannelHelper);
    }

    virtual CARAPI Open(
        /* [out] */ Elastos::IO::Channels::IDatagramChannel ** channel) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("DA29214E-8712-4388-041D-7DF1C3414919")
ISinkChannel : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISinkChannel*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISinkChannel*)pObj->Probe(EIID_ISinkChannel);
    }

    static CARAPI_(ISinkChannel*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISinkChannel*)pObj->Probe(EIID_ISinkChannel);
    }

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("6FB7234C-8712-A0AD-8608-3AFAE2878392")
ISourceChannel : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISourceChannel*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISourceChannel*)pObj->Probe(EIID_ISourceChannel);
    }

    static CARAPI_(ISourceChannel*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISourceChannel*)pObj->Probe(EIID_ISourceChannel);
    }

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("78442419-C652-E8CE-EFBC-A47DCBF62F61")
IPipe : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPipe*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPipe*)pObj->Probe(EIID_IPipe);
    }

    static CARAPI_(IPipe*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPipe*)pObj->Probe(EIID_IPipe);
    }

    virtual CARAPI Sink(
        /* [out] */ Elastos::IO::Channels::ISinkChannel ** channel) = 0;

    virtual CARAPI Source(
        /* [out] */ Elastos::IO::Channels::ISourceChannel ** channel) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("9B35241D-C652-68CE-84BE-335AFFCE4BDA")
IPipeHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPipeHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPipeHelper*)pObj->Probe(EIID_IPipeHelper);
    }

    static CARAPI_(IPipeHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPipeHelper*)pObj->Probe(EIID_IPipeHelper);
    }

    virtual CARAPI Open(
        /* [out] */ Elastos::IO::Channels::IPipe ** pipe) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("D2E4613A-B512-3F8F-DADB-B821C3C60F77")
IFileLock : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFileLock*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileLock*)pObj->Probe(EIID_IFileLock);
    }

    static CARAPI_(IFileLock*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileLock*)pObj->Probe(EIID_IFileLock);
    }

    virtual CARAPI Channel(
        /* [out] */ Elastos::IO::Channels::IFileChannel ** channel) = 0;

    virtual CARAPI GetPosition(
        /* [out] */ _ELASTOS Int64 * position) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int64 * size) = 0;

    virtual CARAPI IsShared(
        /* [out] */ _ELASTOS Boolean * shared) = 0;

    virtual CARAPI Overlaps(
        /* [in] */ _ELASTOS Int64 start,
        /* [in] */ _ELASTOS Int64 length,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI IsValid(
        /* [out] */ _ELASTOS Boolean * valid) = 0;

    virtual CARAPI ReleaseLock() = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * string) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("E51F2156-1092-43CD-041D-7DF1C3414919")
IByteChannel : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IByteChannel*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IByteChannel*)pObj->Probe(EIID_IByteChannel);
    }

    static CARAPI_(IByteChannel*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IByteChannel*)pObj->Probe(EIID_IByteChannel);
    }

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
namespace Spi {
CAR_INTERFACE("8F20892C-E592-19FC-6AC8-C8C1E2C4FD1F")
ISelectorProvider : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISelectorProvider*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISelectorProvider*)pObj->Probe(EIID_ISelectorProvider);
    }

    static CARAPI_(ISelectorProvider*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISelectorProvider*)pObj->Probe(EIID_ISelectorProvider);
    }

    virtual CARAPI OpenDatagramChannel(
        /* [out] */ Elastos::IO::Channels::IDatagramChannel ** channel) = 0;

    virtual CARAPI OpenPipe(
        /* [out] */ Elastos::IO::Channels::IPipe ** pipe) = 0;

    virtual CARAPI OpenSelector(
        /* [out] */ Elastos::IO::Channels::Spi::IAbstractSelector ** selector) = 0;

    virtual CARAPI OpenServerSocketChannel(
        /* [out] */ Elastos::IO::Channels::IServerSocketChannel ** channel) = 0;

    virtual CARAPI OpenSocketChannel(
        /* [out] */ Elastos::IO::Channels::ISocketChannel ** socketChannel) = 0;

    virtual CARAPI InheritedChannel(
        /* [out] */ Elastos::IO::Channels::IChannel ** chanel) = 0;

};
}
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
namespace Spi {
CAR_INTERFACE("14823B31-E592-19FC-6AC8-C8C1E2C4FD08")
ISelectorProviderHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISelectorProviderHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISelectorProviderHelper*)pObj->Probe(EIID_ISelectorProviderHelper);
    }

    static CARAPI_(ISelectorProviderHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISelectorProviderHelper*)pObj->Probe(EIID_ISelectorProviderHelper);
    }

    virtual CARAPI GetProvider(
        /* [out] */ Elastos::IO::Channels::Spi::ISelectorProvider ** provider) = 0;

};
}
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
namespace Spi {
CAR_INTERFACE("67CF3027-8292-3612-6ED4-2061E286E5FC")
IAbstractSelector : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAbstractSelector*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAbstractSelector*)pObj->Probe(EIID_IAbstractSelector);
    }

    static CARAPI_(IAbstractSelector*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAbstractSelector*)pObj->Probe(EIID_IAbstractSelector);
    }

    virtual CARAPI Cancel(
        /* [in] */ Elastos::IO::Channels::ISelectionKey * key) = 0;

};
}
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
namespace Spi {
CAR_INTERFACE("CB242E3E-8292-3612-6ED4-2061E28665F9")
IAbstractSelectionKey : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAbstractSelectionKey*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAbstractSelectionKey*)pObj->Probe(EIID_IAbstractSelectionKey);
    }

    static CARAPI_(IAbstractSelectionKey*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAbstractSelectionKey*)pObj->Probe(EIID_IAbstractSelectionKey);
    }

};
}
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
namespace Spi {
CAR_INTERFACE("0D8C363E-8292-3612-6ED4-2061E2064116")
IAbstractInterruptibleChannel : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAbstractInterruptibleChannel*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAbstractInterruptibleChannel*)pObj->Probe(EIID_IAbstractInterruptibleChannel);
    }

    static CARAPI_(IAbstractInterruptibleChannel*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAbstractInterruptibleChannel*)pObj->Probe(EIID_IAbstractInterruptibleChannel);
    }

};
}
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
namespace Spi {
CAR_INTERFACE("63AC334F-8292-9012-EFBE-E28022E52B3D")
IAbstractSelectableChannel : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAbstractSelectableChannel*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAbstractSelectableChannel*)pObj->Probe(EIID_IAbstractSelectableChannel);
    }

    static CARAPI_(IAbstractSelectableChannel*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAbstractSelectableChannel*)pObj->Probe(EIID_IAbstractSelectableChannel);
    }

};
}
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
CAR_INTERFACE("DEC0834E-90D2-8344-6FFC-705052868D1F")
ICharset : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICharset*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharset*)pObj->Probe(EIID_ICharset);
    }

    static CARAPI_(ICharset*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharset*)pObj->Probe(EIID_ICharset);
    }

    virtual CARAPI Contains(
        /* [in] */ Elastos::IO::Charset::ICharset * charset,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI NewEncoder(
        /* [out] */ Elastos::IO::Charset::ICharsetEncoder ** charsetEncoder) = 0;

    virtual CARAPI NewDecoder(
        /* [out] */ Elastos::IO::Charset::ICharsetDecoder ** charsetDecoder) = 0;

    virtual CARAPI GetName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI Aliases(
        /* [out] */ Elastos::Utility::ISet ** aliasesSet) = 0;

    virtual CARAPI DisplayName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI DisplayName(
        /* [in] */ Elastos::Utility::ILocale * l,
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI IsRegistered(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI CanEncode(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Encode(
        /* [in] */ Elastos::IO::ICharBuffer * buffer,
        /* [out] */ Elastos::IO::IByteBuffer ** byteBuffer) = 0;

    virtual CARAPI Encode(
        /* [in] */ const _ELASTOS String& s,
        /* [out] */ Elastos::IO::IByteBuffer ** byteBuffer) = 0;

    virtual CARAPI Decode(
        /* [in] */ Elastos::IO::IByteBuffer * buffer,
        /* [out] */ Elastos::IO::ICharBuffer ** charBuffer) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
CAR_INTERFACE("827C5309-B312-B592-8DDE-11FACE68FD3B")
ICharsetHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICharsetHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharsetHelper*)pObj->Probe(EIID_ICharsetHelper);
    }

    static CARAPI_(ICharsetHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharsetHelper*)pObj->Probe(EIID_ICharsetHelper);
    }

    virtual CARAPI AvailableCharsets(
        /* [out] */ Elastos::Utility::ISortedMap ** outsm) = 0;

    virtual CARAPI ForName(
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::IO::Charset::ICharset ** charset) = 0;

    virtual CARAPI IsSupported(
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI DefaultCharset(
        /* [out] */ Elastos::IO::Charset::ICharset ** charset) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
CAR_INTERFACE("A4E46A28-A012-871A-7FB4-B77143868D1F")
ICoderResult : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICoderResult*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICoderResult*)pObj->Probe(EIID_ICoderResult);
    }

    static CARAPI_(ICoderResult*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICoderResult*)pObj->Probe(EIID_ICoderResult);
    }

    virtual CARAPI IsUnderflow(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI IsError(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI IsMalformed(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI IsOverflow(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI IsUnmappable(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int32 * length) = 0;

    virtual CARAPI ThrowException() = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
CAR_INTERFACE("CBEB6221-A012-871A-23A0-7831E3FE8FF6")
ICoderResultHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICoderResultHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICoderResultHelper*)pObj->Probe(EIID_ICoderResultHelper);
    }

    static CARAPI_(ICoderResultHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICoderResultHelper*)pObj->Probe(EIID_ICoderResultHelper);
    }

    virtual CARAPI GetUNDERFLOW(
        /* [out] */ Elastos::IO::Charset::ICoderResult ** result) = 0;

    virtual CARAPI GetOVERFLOW(
        /* [out] */ Elastos::IO::Charset::ICoderResult ** result) = 0;

    virtual CARAPI MalformedForLength(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::IO::Charset::ICoderResult ** result) = 0;

    virtual CARAPI UnmappableForLength(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::IO::Charset::ICoderResult ** result) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
CAR_INTERFACE("E578F950-90D2-8344-6F1C-7135ABC60F07")
ICharsetDecoder : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICharsetDecoder*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharsetDecoder*)pObj->Probe(EIID_ICharsetDecoder);
    }

    static CARAPI_(ICharsetDecoder*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharsetDecoder*)pObj->Probe(EIID_ICharsetDecoder);
    }

    virtual CARAPI AverageCharsPerByte(
        /* [out] */ _ELASTOS Float * average) = 0;

    virtual CARAPI Charset(
        /* [out] */ Elastos::IO::Charset::ICharset ** charset) = 0;

    virtual CARAPI Decode(
        /* [in] */ Elastos::IO::IByteBuffer * byteBuffer,
        /* [out] */ Elastos::IO::ICharBuffer ** charBuffer) = 0;

    virtual CARAPI Decode(
        /* [in] */ Elastos::IO::IByteBuffer * byteBuffer,
        /* [in] */ Elastos::IO::ICharBuffer * charBuffer,
        /* [in] */ _ELASTOS Boolean endOfInput,
        /* [out] */ Elastos::IO::Charset::ICoderResult ** result) = 0;

    virtual CARAPI DetectedCharset(
        /* [out] */ Elastos::IO::Charset::ICharset ** charset) = 0;

    virtual CARAPI Flush(
        /* [in] */ Elastos::IO::ICharBuffer * charBuffer,
        /* [out] */ Elastos::IO::Charset::ICoderResult ** result) = 0;

    virtual CARAPI IsAutoDetecting(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI IsCharsetDetected(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI MalformedInputAction(
        /* [out] */ Elastos::IO::Charset::ICodingErrorAction ** codingErrorAction) = 0;

    virtual CARAPI MaxCharsPerByte(
        /* [out] */ _ELASTOS Float * maxNumber) = 0;

    virtual CARAPI OnMalformedInput(
        /* [in] */ Elastos::IO::Charset::ICodingErrorAction * newAction) = 0;

    virtual CARAPI OnUnmappableCharacter(
        /* [in] */ Elastos::IO::Charset::ICodingErrorAction * newAction) = 0;

    virtual CARAPI Replacement(
        /* [out] */ _ELASTOS String * replacement) = 0;

    virtual CARAPI ReplaceWith(
        /* [in] */ const _ELASTOS String& newReplacement) = 0;

    virtual CARAPI Reset() = 0;

    virtual CARAPI UnmappableCharacterAction(
        /* [out] */ Elastos::IO::Charset::ICodingErrorAction ** codingErrorAction) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
CAR_INTERFACE("3C41EB4D-90D2-8344-6F40-7135ABC60F07")
ICharsetEncoder : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICharsetEncoder*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharsetEncoder*)pObj->Probe(EIID_ICharsetEncoder);
    }

    static CARAPI_(ICharsetEncoder*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharsetEncoder*)pObj->Probe(EIID_ICharsetEncoder);
    }

    virtual CARAPI AverageBytesPerChar(
        /* [out] */ _ELASTOS Float * averageNumber) = 0;

    virtual CARAPI CanEncode(
        /* [in] */ _ELASTOS Char32 c,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI CanEncode(
        /* [in] */ Elastos::Core::ICharSequence * sequence,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetCharset(
        /* [out] */ Elastos::IO::Charset::ICharset ** charset) = 0;

    virtual CARAPI Encode(
        /* [in] */ Elastos::IO::ICharBuffer * charBuffer,
        /* [out] */ Elastos::IO::IByteBuffer ** byteBuffer) = 0;

    virtual CARAPI Encode(
        /* [in] */ Elastos::IO::ICharBuffer * charBuffer,
        /* [in] */ Elastos::IO::IByteBuffer * byteBuffer,
        /* [in] */ _ELASTOS Boolean endOfInput,
        /* [out] */ Elastos::IO::Charset::ICoderResult ** result) = 0;

    virtual CARAPI EncodeLoop(
        /* [in] */ Elastos::IO::ICharBuffer * charBuffer,
        /* [in] */ Elastos::IO::IByteBuffer * byteBuffer,
        /* [out] */ Elastos::IO::Charset::ICoderResult ** result) = 0;

    virtual CARAPI Flush(
        /* [in] */ Elastos::IO::IByteBuffer * byteBuffer,
        /* [out] */ Elastos::IO::Charset::ICoderResult ** result) = 0;

    virtual CARAPI IsLegalReplacement(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * replacement,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetMalformedInputAction(
        /* [out] */ Elastos::IO::Charset::ICodingErrorAction ** errorAction) = 0;

    virtual CARAPI GetMaxBytesPerChar(
        /* [out] */ _ELASTOS Float * maxNumber) = 0;

    virtual CARAPI OnMalformedInput(
        /* [in] */ Elastos::IO::Charset::ICodingErrorAction * newAction) = 0;

    virtual CARAPI OnUnmappableCharacter(
        /* [in] */ Elastos::IO::Charset::ICodingErrorAction * newAction) = 0;

    virtual CARAPI GetReplacement(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** replace) = 0;

    virtual CARAPI ReplaceWith(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * replacement) = 0;

    virtual CARAPI Reset() = 0;

    virtual CARAPI GetUnmappableCharacterAction(
        /* [out] */ Elastos::IO::Charset::ICodingErrorAction ** errorAction) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
CAR_INTERFACE("0EE7263B-0312-2719-EA2F-536002FE8FF6")
ICodingErrorAction : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICodingErrorAction*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICodingErrorAction*)pObj->Probe(EIID_ICodingErrorAction);
    }

    static CARAPI_(ICodingErrorAction*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICodingErrorAction*)pObj->Probe(EIID_ICodingErrorAction);
    }

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
CAR_INTERFACE("424C482B-0312-2719-EA2F-5360027E0414")
ICodingErrorActionHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICodingErrorActionHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICodingErrorActionHelper*)pObj->Probe(EIID_ICodingErrorActionHelper);
    }

    static CARAPI_(ICodingErrorActionHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICodingErrorActionHelper*)pObj->Probe(EIID_ICodingErrorActionHelper);
    }

    virtual CARAPI GetIGNORE(
        /* [out] */ Elastos::IO::Charset::ICodingErrorAction ** ignore) = 0;

    virtual CARAPI GetREPLACE(
        /* [out] */ Elastos::IO::Charset::ICodingErrorAction ** replace) = 0;

    virtual CARAPI GetREPORT(
        /* [out] */ Elastos::IO::Charset::ICodingErrorAction ** report) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
CAR_INTERFACE("B80C9F5A-90D2-8344-6FD8-F8E1A0A40C1B")
ICharsets : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICharsets*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharsets*)pObj->Probe(EIID_ICharsets);
    }

    static CARAPI_(ICharsets*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharsets*)pObj->Probe(EIID_ICharsets);
    }

    virtual CARAPI GetISO_8859_1(
        /* [out] */ Elastos::IO::Charset::ICharset ** charset) = 0;

    virtual CARAPI GetUS_ASCII(
        /* [out] */ Elastos::IO::Charset::ICharset ** charset) = 0;

    virtual CARAPI GetUTF_8(
        /* [out] */ Elastos::IO::Charset::ICharset ** charset) = 0;

    virtual CARAPI ToAsciiBytes(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & chars,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** bytes) = 0;

    virtual CARAPI ToIsoLatin1Bytes(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & chars,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** bytes) = 0;

    virtual CARAPI ToUtf8Bytes(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & chars,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** bytes) = 0;

    virtual CARAPI ToBigEndianUtf16Bytes(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & chars,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** bytes) = 0;

    virtual CARAPI AsciiBytesToChars(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & bytes,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Char32> ** chars) = 0;

    virtual CARAPI IsoLatin1BytesToChars(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & bytes,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Char32> ** chars) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
CAR_INTERFACE("A68A3D1A-2592-6C9F-CAA2-A777A7C8EFBC")
IModifiedUtf8 : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IModifiedUtf8*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IModifiedUtf8*)pObj->Probe(EIID_IModifiedUtf8);
    }

    static CARAPI_(IModifiedUtf8*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IModifiedUtf8*)pObj->Probe(EIID_IModifiedUtf8);
    }

    virtual CARAPI Decode(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * inBytes,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * outChars,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 utfSize,
        /* [out] */ _ELASTOS String * string) = 0;

    virtual CARAPI CountBytes(
        /* [in] */ const _ELASTOS String& s,
        /* [in] */ _ELASTOS Boolean shortLength,
        /* [out] */ _ELASTOS Int64 * num) = 0;

    virtual CARAPI Encode(
        /* [in] */ const _ELASTOS String& s,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** bytes) = 0;

    virtual CARAPI Encode(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * dst,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ const _ELASTOS String& s) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
CAR_INTERFACE("2368641E-7712-F193-49D6-27B392B58DDE")
IStandardCharsets : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IStandardCharsets*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStandardCharsets*)pObj->Probe(EIID_IStandardCharsets);
    }

    static CARAPI_(IStandardCharsets*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStandardCharsets*)pObj->Probe(EIID_IStandardCharsets);
    }

    virtual CARAPI GetISO_8859_1(
        /* [out] */ Elastos::IO::Charset::ICharset ** outcharset) = 0;

    virtual CARAPI GetUS_ASCII(
        /* [out] */ Elastos::IO::Charset::ICharset ** outcharset) = 0;

    virtual CARAPI GetUTF_8(
        /* [out] */ Elastos::IO::Charset::ICharset ** outcharset) = 0;

    virtual CARAPI GetUTF_16(
        /* [out] */ Elastos::IO::Charset::ICharset ** outcharset) = 0;

    virtual CARAPI GetUTF_16BE(
        /* [out] */ Elastos::IO::Charset::ICharset ** outcharset) = 0;

    virtual CARAPI GetUTF_16LE(
        /* [out] */ Elastos::IO::Charset::ICharset ** outcharset) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
namespace Spi {
CAR_INTERFACE("2C5E3E45-90D2-8344-6F64-E0FB7B568D1F")
ICharsetProvider : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICharsetProvider*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharsetProvider*)pObj->Probe(EIID_ICharsetProvider);
    }

    static CARAPI_(ICharsetProvider*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharsetProvider*)pObj->Probe(EIID_ICharsetProvider);
    }

    virtual CARAPI Charsets(
        /* [out] */ Elastos::Utility::IIterator ** charsetsIterator) = 0;

    virtual CARAPI CharsetForName(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::IO::Charset::ICharset ** charset) = 0;

};
}
}
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("105A793B-0312-FA35-FFC9-464102861EA3")
ICBufferedInputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICBufferedInputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBufferedInputStreamClassObject*)pObj->Probe(EIID_ICBufferedInputStreamClassObject);
    }

    static CARAPI_(ICBufferedInputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBufferedInputStreamClassObject*)pObj->Probe(EIID_ICBufferedInputStreamClassObject);
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
namespace Elastos {
namespace IO {
CAR_INTERFACE("A7456D24-0312-F9CB-33D4-909183C589FB")
ICSelectorProviderImplClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSelectorProviderImplClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSelectorProviderImplClassObject*)pObj->Probe(EIID_ICSelectorProviderImplClassObject);
    }

    static CARAPI_(ICSelectorProviderImplClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSelectorProviderImplClassObject*)pObj->Probe(EIID_ICSelectorProviderImplClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("CBC48221-8312-3736-5060-912A1B050918")
ICByteArrayOutputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICByteArrayOutputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICByteArrayOutputStreamClassObject*)pObj->Probe(EIID_ICByteArrayOutputStreamClassObject);
    }

    static CARAPI_(ICByteArrayOutputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICByteArrayOutputStreamClassObject*)pObj->Probe(EIID_ICByteArrayOutputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithSize(
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("C9998034-0312-E6D8-F518-FDD1DEC60D19")
ICStringWriterClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICStringWriterClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStringWriterClassObject*)pObj->Probe(EIID_ICStringWriterClassObject);
    }

    static CARAPI_(ICStringWriterClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStringWriterClassObject*)pObj->Probe(EIID_ICStringWriterClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithInitialSize(
        /* [in] */ _ELASTOS Int32 initialSize,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("FBD26145-8312-2C07-6A3E-DBB2968D3018")
ICFilterInputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICFilterInputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFilterInputStreamClassObject*)pObj->Probe(EIID_ICFilterInputStreamClassObject);
    }

    static CARAPI_(ICFilterInputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFilterInputStreamClassObject*)pObj->Probe(EIID_ICFilterInputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithIs(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("8C7C7E24-0312-FA35-A5CA-464102861EA3")
ICBufferedOutputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICBufferedOutputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBufferedOutputStreamClassObject*)pObj->Probe(EIID_ICBufferedOutputStreamClassObject);
    }

    static CARAPI_(ICBufferedOutputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBufferedOutputStreamClassObject*)pObj->Probe(EIID_ICBufferedOutputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithOutsSize(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithOuts(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("86D6643E-8312-2C07-5EDC-B82F55360A12")
ICFilterOutputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICFilterOutputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFilterOutputStreamClassObject*)pObj->Probe(EIID_ICFilterOutputStreamClassObject);
    }

    static CARAPI_(ICFilterOutputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFilterOutputStreamClassObject*)pObj->Probe(EIID_ICFilterOutputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithOuts(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("0EAC7634-0312-FA35-E3EA-31FAA3BD8D1B")
ICBufferedReaderClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICBufferedReaderClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBufferedReaderClassObject*)pObj->Probe(EIID_ICBufferedReaderClassObject);
    }

    static CARAPI_(ICBufferedReaderClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBufferedReaderClassObject*)pObj->Probe(EIID_ICBufferedReaderClassObject);
    }

    virtual CARAPI CreateObjectWithRin(
        /* [in] */ Elastos::IO::IReader * rin,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithRinSize(
        /* [in] */ Elastos::IO::IReader * rin,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("C2C07828-0312-FA35-CDEB-31FAA3BD8D1B")
ICBufferedWriterClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICBufferedWriterClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBufferedWriterClassObject*)pObj->Probe(EIID_ICBufferedWriterClassObject);
    }

    static CARAPI_(ICBufferedWriterClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBufferedWriterClassObject*)pObj->Probe(EIID_ICBufferedWriterClassObject);
    }

    virtual CARAPI CreateObjectWithWout(
        /* [in] */ Elastos::IO::IWriter * wout,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithWoutSize(
        /* [in] */ Elastos::IO::IWriter * wout,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("A6E28A2F-8312-3736-5060-F9271B050918")
ICByteArrayInputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICByteArrayInputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICByteArrayInputStreamClassObject*)pObj->Probe(EIID_ICByteArrayInputStreamClassObject);
    }

    static CARAPI_(ICByteArrayInputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICByteArrayInputStreamClassObject*)pObj->Probe(EIID_ICByteArrayInputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithBuffer(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithBufferOffsetLength(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("5AEC7F3F-0312-2B06-48D4-C012578FD11F")
ICCharArrayReaderClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCharArrayReaderClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCharArrayReaderClassObject*)pObj->Probe(EIID_ICCharArrayReaderClassObject);
    }

    static CARAPI_(ICCharArrayReaderClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCharArrayReaderClassObject*)pObj->Probe(EIID_ICCharArrayReaderClassObject);
    }

    virtual CARAPI CreateObjectWithBuf(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buf,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithBufOffsetLength(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("B1AA8336-0312-2B06-48D4-C0625E8FD11F")
ICCharArrayWriterClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCharArrayWriterClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCharArrayWriterClassObject*)pObj->Probe(EIID_ICCharArrayWriterClassObject);
    }

    static CARAPI_(ICCharArrayWriterClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCharArrayWriterClassObject*)pObj->Probe(EIID_ICCharArrayWriterClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithInitialSize(
        /* [in] */ _ELASTOS Int32 initialSize,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("81536914-C312-64AC-BDE0-698AD611FACE")
ICCharBufferHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCharBufferHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCharBufferHelperClassObject*)pObj->Probe(EIID_ICCharBufferHelperClassObject);
    }

    static CARAPI_(ICCharBufferHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCharBufferHelperClassObject*)pObj->Probe(EIID_ICCharBufferHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("89325F3D-0312-FF4C-64A3-2001438FD11F")
ICDataInputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDataInputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDataInputStreamClassObject*)pObj->Probe(EIID_ICDataInputStreamClassObject);
    }

    static CARAPI_(ICDataInputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDataInputStreamClassObject*)pObj->Probe(EIID_ICDataInputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithIs(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("1844795C-8312-380C-144B-5AB5652D1B61")
ICPushbackInputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPushbackInputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPushbackInputStreamClassObject*)pObj->Probe(EIID_ICPushbackInputStreamClassObject);
    }

    static CARAPI_(ICPushbackInputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPushbackInputStreamClassObject*)pObj->Probe(EIID_ICPushbackInputStreamClassObject);
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
namespace Elastos {
namespace IO {
CAR_INTERFACE("88AB6021-0312-524C-65A3-2001438FD11F")
ICDataOutputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDataOutputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDataOutputStreamClassObject*)pObj->Probe(EIID_ICDataOutputStreamClassObject);
    }

    static CARAPI_(ICDataOutputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDataOutputStreamClassObject*)pObj->Probe(EIID_ICDataOutputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithOs(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("7D416927-8312-3736-50A8-8980E2C58CFB")
ICByteBufferHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICByteBufferHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICByteBufferHelperClassObject*)pObj->Probe(EIID_ICByteBufferHelperClassObject);
    }

    static CARAPI_(ICByteBufferHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICByteBufferHelperClassObject*)pObj->Probe(EIID_ICByteBufferHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("E23A681A-B312-37F0-8AD5-275A47E83BA3")
ICByteOrderHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICByteOrderHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICByteOrderHelperClassObject*)pObj->Probe(EIID_ICByteOrderHelperClassObject);
    }

    static CARAPI_(ICByteOrderHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICByteOrderHelperClassObject*)pObj->Probe(EIID_ICByteOrderHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("AEAC8529-0312-F9CB-EBE9-31FAA3BD8D1B")
ICSelectorImplClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSelectorImplClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSelectorImplClassObject*)pObj->Probe(EIID_ICSelectorImplClassObject);
    }

    static CARAPI_(ICSelectorImplClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSelectorImplClassObject*)pObj->Probe(EIID_ICSelectorImplClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithSelectorProvider(
        /* [in] */ Elastos::IO::Channels::Spi::ISelectorProvider * selectorProvider,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("0A646743-8312-2C07-521A-31A157ED5506")
ICFileDescriptorClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICFileDescriptorClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFileDescriptorClassObject*)pObj->Probe(EIID_ICFileDescriptorClassObject);
    }

    static CARAPI_(ICFileDescriptorClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFileDescriptorClassObject*)pObj->Probe(EIID_ICFileDescriptorClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("1A5D9B30-0312-7A6A-8CFE-686FE3860C1B")
ICFileClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICFileClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFileClassObject*)pObj->Probe(EIID_ICFileClassObject);
    }

    static CARAPI_(ICFileClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFileClassObject*)pObj->Probe(EIID_ICFileClassObject);
    }

    virtual CARAPI CreateObjectWithDirName(
        /* [in] */ Elastos::IO::IFile * dir,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPath(
        /* [in] */ const _ELASTOS String& path,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithDirPathName(
        /* [in] */ const _ELASTOS String& dirPath,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithUri(
        /* [in] */ Elastos::Net::IURI * uri,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("DB536325-0312-116A-50BC-98715F8FD11F")
ICFileHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICFileHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFileHelperClassObject*)pObj->Probe(EIID_ICFileHelperClassObject);
    }

    static CARAPI_(ICFileHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFileHelperClassObject*)pObj->Probe(EIID_ICFileHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("5941AC2C-8312-B27F-5190-8011578FD11F")
ICInputStreamReaderClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICInputStreamReaderClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInputStreamReaderClassObject*)pObj->Probe(EIID_ICInputStreamReaderClassObject);
    }

    static CARAPI_(ICInputStreamReaderClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInputStreamReaderClassObject*)pObj->Probe(EIID_ICInputStreamReaderClassObject);
    }

    virtual CARAPI CreateObjectWithIs(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithIsCharsetName(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithIsDec(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharsetDecoder * dec,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithIsCharset(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharset * charset,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("3A276F2D-0312-2859-4CDC-687303859A08")
ICDirectByteBufferHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDirectByteBufferHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDirectByteBufferHelperClassObject*)pObj->Probe(EIID_ICDirectByteBufferHelperClassObject);
    }

    static CARAPI_(ICDirectByteBufferHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDirectByteBufferHelperClassObject*)pObj->Probe(EIID_ICDirectByteBufferHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("43A9F92B-8312-E6B3-F518-FDD1DEC60D19")
ICPrintWriterClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPrintWriterClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPrintWriterClassObject*)pObj->Probe(EIID_ICPrintWriterClassObject);
    }

    static CARAPI_(ICPrintWriterClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPrintWriterClassObject*)pObj->Probe(EIID_ICPrintWriterClassObject);
    }

    virtual CARAPI CreateObjectWithOuts(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithOutsAutoflush(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithWr(
        /* [in] */ Elastos::IO::IWriter * wr,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithWrAutoflush(
        /* [in] */ Elastos::IO::IWriter * wr,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFile(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFileCsn(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& csn,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFileName(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFileNameCsn(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& csn,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("330F654F-8312-0F0A-2FE0-8041A9C696B5")
ICLineNumberInputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICLineNumberInputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLineNumberInputStreamClassObject*)pObj->Probe(EIID_ICLineNumberInputStreamClassObject);
    }

    static CARAPI_(ICLineNumberInputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLineNumberInputStreamClassObject*)pObj->Probe(EIID_ICLineNumberInputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithIs(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("80487643-8312-0F0A-2FE0-8041A9C69967")
ICLineNumberReaderClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICLineNumberReaderClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLineNumberReaderClassObject*)pObj->Probe(EIID_ICLineNumberReaderClassObject);
    }

    static CARAPI_(ICLineNumberReaderClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLineNumberReaderClassObject*)pObj->Probe(EIID_ICLineNumberReaderClassObject);
    }

    virtual CARAPI CreateObjectWithIr(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithIrSize(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("AABE9724-0312-B2A9-5190-80615E8FD11F")
ICOutputStreamWriterClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICOutputStreamWriterClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICOutputStreamWriterClassObject*)pObj->Probe(EIID_ICOutputStreamWriterClassObject);
    }

    static CARAPI_(ICOutputStreamWriterClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICOutputStreamWriterClassObject*)pObj->Probe(EIID_ICOutputStreamWriterClassObject);
    }

    virtual CARAPI CreateObjectWithOs(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithOsEnc(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ const _ELASTOS String& enc,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithOsCharsetEncoder(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::IO::Charset::ICharsetEncoder * charsetEncoder,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("84B9F82B-8312-B2B3-5190-80A1C7E88FF6")
ICPrintStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPrintStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPrintStreamClassObject*)pObj->Probe(EIID_ICPrintStreamClassObject);
    }

    static CARAPI_(ICPrintStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPrintStreamClassObject*)pObj->Probe(EIID_ICPrintStreamClassObject);
    }

    virtual CARAPI CreateObjectWithOuts(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithOutsAutoflush(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithOutsAutoflushCharsetName(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFile(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFileCharsetName(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFileName(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFileNameCharsetName(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("EE9A7456-8312-380C-144B-5A75E6190393")
ICPushbackReaderClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPushbackReaderClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPushbackReaderClassObject*)pObj->Probe(EIID_ICPushbackReaderClassObject);
    }

    static CARAPI_(ICPushbackReaderClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPushbackReaderClassObject*)pObj->Probe(EIID_ICPushbackReaderClassObject);
    }

    virtual CARAPI CreateObjectWithIr(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithIrSize(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("72E88227-8312-240D-629C-90016308353D")
ICRandomAccessFileClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICRandomAccessFileClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRandomAccessFileClassObject*)pObj->Probe(EIID_ICRandomAccessFileClassObject);
    }

    static CARAPI_(ICRandomAccessFileClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRandomAccessFileClassObject*)pObj->Probe(EIID_ICRandomAccessFileClassObject);
    }

    virtual CARAPI CreateObjectWithFileMode(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& mode,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFileNameMode(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& mode,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("34E67650-0312-280E-E6C6-00B5652D1B61")
ICSequenceInputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSequenceInputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSequenceInputStreamClassObject*)pObj->Probe(EIID_ICSequenceInputStreamClassObject);
    }

    static CARAPI_(ICSequenceInputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSequenceInputStreamClassObject*)pObj->Probe(EIID_ICSequenceInputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithS1S2(
        /* [in] */ Elastos::IO::IInputStream * s1,
        /* [in] */ Elastos::IO::IInputStream * s2,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithE(
        /* [in] */ Elastos::Utility::IEnumeration * e,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("865D6836-0312-6AD8-FEC9-464102861EA3")
ICStringBufferInputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICStringBufferInputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStringBufferInputStreamClassObject*)pObj->Probe(EIID_ICStringBufferInputStreamClassObject);
    }

    static CARAPI_(ICStringBufferInputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStringBufferInputStreamClassObject*)pObj->Probe(EIID_ICStringBufferInputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithStr(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("26455D2F-0312-71D8-F518-FDD1DEC60D19")
ICStringReaderClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICStringReaderClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStringReaderClassObject*)pObj->Probe(EIID_ICStringReaderClassObject);
    }

    static CARAPI_(ICStringReaderClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStringReaderClassObject*)pObj->Probe(EIID_ICStringReaderClassObject);
    }

    virtual CARAPI CreateObjectWithStr(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("9A0D8B38-0312-FF6A-64A3-2001438FD11F")
ICFileInputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICFileInputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFileInputStreamClassObject*)pObj->Probe(EIID_ICFileInputStreamClassObject);
    }

    static CARAPI_(ICFileInputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFileInputStreamClassObject*)pObj->Probe(EIID_ICFileInputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithFile(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFd(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFileName(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("E967C42F-0312-526A-65A3-2001438FD11F")
ICFileOutputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICFileOutputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFileOutputStreamClassObject*)pObj->Probe(EIID_ICFileOutputStreamClassObject);
    }

    static CARAPI_(ICFileOutputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFileOutputStreamClassObject*)pObj->Probe(EIID_ICFileOutputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithFile(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFileAppend(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFd(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFileName(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFileNameAppend(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("23406734-0312-196A-EEC3-606123BE1EA3")
ICFilePermissionClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICFilePermissionClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFilePermissionClassObject*)pObj->Probe(EIID_ICFilePermissionClassObject);
    }

    static CARAPI_(ICFilePermissionClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFilePermissionClassObject*)pObj->Probe(EIID_ICFilePermissionClassObject);
    }

    virtual CARAPI CreateObjectWithPathActions(
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("9D158622-0312-716A-F518-FDD1DEC60D19")
ICFileReaderClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICFileReaderClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFileReaderClassObject*)pObj->Probe(EIID_ICFileReaderClassObject);
    }

    static CARAPI_(ICFileReaderClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFileReaderClassObject*)pObj->Probe(EIID_ICFileReaderClassObject);
    }

    virtual CARAPI CreateObjectWithFile(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFd(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFilename(
        /* [in] */ const _ELASTOS String& filename,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("F1A1BE35-0312-E66A-F518-FDD1DEC60D19")
ICFileWriterClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICFileWriterClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFileWriterClassObject*)pObj->Probe(EIID_ICFileWriterClassObject);
    }

    static CARAPI_(ICFileWriterClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFileWriterClassObject*)pObj->Probe(EIID_ICFileWriterClassObject);
    }

    virtual CARAPI CreateObjectWithFile(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFileAppend(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFd(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFilename(
        /* [in] */ const _ELASTOS String& filename,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFilenameAppend(
        /* [in] */ const _ELASTOS String& filename,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("56826105-7312-B2B1-77B3-AFCDBCA46D63")
ICNioUtilsClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICNioUtilsClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNioUtilsClassObject*)pObj->Probe(EIID_ICNioUtilsClassObject);
    }

    static CARAPI_(ICNioUtilsClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNioUtilsClassObject*)pObj->Probe(EIID_ICNioUtilsClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("D64EB12E-8312-2C0C-66E8-FF271B050918")
ICPipedInputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPipedInputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPipedInputStreamClassObject*)pObj->Probe(EIID_ICPipedInputStreamClassObject);
    }

    static CARAPI_(ICPipedInputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPipedInputStreamClassObject*)pObj->Probe(EIID_ICPipedInputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithIpos(
        /* [in] */ IPipedOutputStream * ipos,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPipeSize(
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithIposPipeSize(
        /* [in] */ IPipedOutputStream * ipos,
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("51158037-8312-2C0C-66E8-972A1B050918")
ICPipedOutputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPipedOutputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPipedOutputStreamClassObject*)pObj->Probe(EIID_ICPipedOutputStreamClassObject);
    }

    static CARAPI_(ICPipedOutputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPipedOutputStreamClassObject*)pObj->Probe(EIID_ICPipedOutputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithTarget(
        /* [in] */ Elastos::IO::IPipedInputStream * target,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("D94DAA3D-8312-2C0C-66E8-8FABC7E88FF6")
ICPipedReaderClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPipedReaderClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPipedReaderClassObject*)pObj->Probe(EIID_ICPipedReaderClassObject);
    }

    static CARAPI_(ICPipedReaderClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPipedReaderClassObject*)pObj->Probe(EIID_ICPipedReaderClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithIpw(
        /* [in] */ Elastos::IO::IPipedWriter * ipw,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPipeSize(
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithIpwPipeSize(
        /* [in] */ Elastos::IO::IPipedWriter * ipw,
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("8E3D7F2E-8312-2C0C-66E8-37AFC7E88FF6")
ICPipedWriterClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPipedWriterClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPipedWriterClassObject*)pObj->Probe(EIID_ICPipedWriterClassObject);
    }

    static CARAPI_(ICPipedWriterClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPipedWriterClassObject*)pObj->Probe(EIID_ICPipedWriterClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithDestination(
        /* [in] */ Elastos::IO::IPipedReader * destination,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("51866222-8312-EE0B-86E8-31FAA3BD8D1B")
ICNIOAccessClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICNIOAccessClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNIOAccessClassObject*)pObj->Probe(EIID_ICNIOAccessClassObject);
    }

    static CARAPI_(ICNIOAccessClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNIOAccessClassObject*)pObj->Probe(EIID_ICNIOAccessClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("F3F67050-0312-C236-60BC-71C1AC630D06")
ICStreamTokenizerClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICStreamTokenizerClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStreamTokenizerClassObject*)pObj->Probe(EIID_ICStreamTokenizerClassObject);
    }

    static CARAPI_(ICStreamTokenizerClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStreamTokenizerClassObject*)pObj->Probe(EIID_ICStreamTokenizerClassObject);
    }

    virtual CARAPI CreateObjectWithIs(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithR(
        /* [in] */ Elastos::IO::IReader * r,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
CAR_INTERFACE("9C7B7C2D-0312-52A3-65A3-2001438FD11F")
ICObjectOutputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICObjectOutputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICObjectOutputStreamClassObject*)pObj->Probe(EIID_ICObjectOutputStreamClassObject);
    }

    static CARAPI_(ICObjectOutputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICObjectOutputStreamClassObject*)pObj->Probe(EIID_ICObjectOutputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithR(
        /* [in] */ Elastos::IO::IOutputStream * r,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace IO {
namespace Channels {
CAR_INTERFACE("B6CF6A04-C312-64AC-1CA3-AFCDBCA46D63")
ICChannelsClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICChannelsClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICChannelsClassObject*)pObj->Probe(EIID_ICChannelsClassObject);
    }

    static CARAPI_(ICChannelsClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICChannelsClassObject*)pObj->Probe(EIID_ICChannelsClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
namespace Spi {
CAR_INTERFACE("0E577C3E-0312-F9CB-33D4-909183C589FB")
ICSelectorProviderHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSelectorProviderHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSelectorProviderHelperClassObject*)pObj->Probe(EIID_ICSelectorProviderHelperClassObject);
    }

    static CARAPI_(ICSelectorProviderHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSelectorProviderHelperClassObject*)pObj->Probe(EIID_ICSelectorProviderHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
CAR_INTERFACE("FD577234-0312-3206-4ED4-5FA6C0047C3D")
ICCodingErrorActionClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCodingErrorActionClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCodingErrorActionClassObject*)pObj->Probe(EIID_ICCodingErrorActionClassObject);
    }

    static CARAPI_(ICCodingErrorActionClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCodingErrorActionClassObject*)pObj->Probe(EIID_ICCodingErrorActionClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
CAR_INTERFACE("E30F7830-0312-3206-4ED4-5FA6C004FC08")
ICCodingErrorActionHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCodingErrorActionHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCodingErrorActionHelperClassObject*)pObj->Probe(EIID_ICCodingErrorActionHelperClassObject);
    }

    static CARAPI_(ICCodingErrorActionHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCodingErrorActionHelperClassObject*)pObj->Probe(EIID_ICCodingErrorActionHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
CAR_INTERFACE("E9FE6E11-C312-64AC-6DA3-7784BE335A33")
ICCharsetHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCharsetHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCharsetHelperClassObject*)pObj->Probe(EIID_ICCharsetHelperClassObject);
    }

    static CARAPI_(ICCharsetHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCharsetHelperClassObject*)pObj->Probe(EIID_ICCharsetHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
CAR_INTERFACE("B2256906-C312-64AC-6DA3-B7CDBCA46D63")
ICCharsetsClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCharsetsClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCharsetsClassObject*)pObj->Probe(EIID_ICCharsetsClassObject);
    }

    static CARAPI_(ICCharsetsClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCharsetsClassObject*)pObj->Probe(EIID_ICCharsetsClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
CAR_INTERFACE("3D6A6C3C-0312-3540-0EEB-31FAA3BD8D1B")
ICCoderResultClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCoderResultClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCoderResultClassObject*)pObj->Probe(EIID_ICCoderResultClassObject);
    }

    static CARAPI_(ICCoderResultClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCoderResultClassObject*)pObj->Probe(EIID_ICCoderResultClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
CAR_INTERFACE("23227234-0312-3540-0E47-40F162C67D3D")
ICCoderResultHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCoderResultHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCoderResultHelperClassObject*)pObj->Probe(EIID_ICCoderResultHelperClassObject);
    }

    static CARAPI_(ICCoderResultHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCoderResultHelperClassObject*)pObj->Probe(EIID_ICCoderResultHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
CAR_INTERFACE("12796D1A-6312-27C9-9BB2-E8E9DD29C2BC")
ICModifiedUtf8ClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICModifiedUtf8ClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICModifiedUtf8ClassObject*)pObj->Probe(EIID_ICModifiedUtf8ClassObject);
    }

    static CARAPI_(ICModifiedUtf8ClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICModifiedUtf8ClassObject*)pObj->Probe(EIID_ICModifiedUtf8ClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
CAR_INTERFACE("099A7102-C312-64DD-7C92-F5C9AC646DA3")
ICStandardCharsetsClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICStandardCharsetsClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStandardCharsetsClassObject*)pObj->Probe(EIID_ICStandardCharsetsClassObject);
    }

    static CARAPI_(ICStandardCharsetsClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStandardCharsetsClassObject*)pObj->Probe(EIID_ICStandardCharsetsClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace IO {
class CBufferedInputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBufferedInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBufferedInputStream, RGM_SAME_DOMAIN,
                EIID_ICBufferedInputStreamClassObject, (IInterface**)&pClassObject);
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
        ICBufferedInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBufferedInputStream, RGM_SAME_DOMAIN,
                EIID_ICBufferedInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIsSize(is, size, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ Elastos::IO::IBufferedInputStream** __IBufferedInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBufferedInputStream = (Elastos::IO::IBufferedInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IBufferedInputStream);
        if (*__IBufferedInputStream) __pNewObj->AddRef();
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
        /* [out] */ Elastos::IO::IBufferedInputStream** __IBufferedInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBufferedInputStream = (Elastos::IO::IBufferedInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IBufferedInputStream);
        if (*__IBufferedInputStream) __pNewObj->AddRef();
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
namespace Elastos {
namespace IO {
class CSelectorProviderImpl
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::Channels::Spi::ISelectorProvider** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSelectorProviderImpl, RGM_SAME_DOMAIN, Elastos::IO::Channels::Spi::EIID_ISelectorProvider, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSelectorProviderImpl, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSelectorProviderImpl, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSelectorProviderImpl, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace IO {
class CByteArrayOutputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICByteArrayOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CByteArrayOutputStream, RGM_SAME_DOMAIN,
                EIID_ICByteArrayOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSize(size, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IByteArrayOutputStream** __object)
    {
        return _CObject_CreateInstance(ECLSID_CByteArrayOutputStream, RGM_SAME_DOMAIN, Elastos::IO::EIID_IByteArrayOutputStream, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IOutputStream** __object)
    {
        return _CObject_CreateInstance(ECLSID_CByteArrayOutputStream, RGM_SAME_DOMAIN, Elastos::IO::EIID_IOutputStream, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ICloseable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CByteArrayOutputStream, RGM_SAME_DOMAIN, Elastos::IO::EIID_ICloseable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IFlushable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CByteArrayOutputStream, RGM_SAME_DOMAIN, Elastos::IO::EIID_IFlushable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CByteArrayOutputStream, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CByteArrayOutputStream, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CByteArrayOutputStream, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IByteArrayOutputStream** __IByteArrayOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IByteArrayOutputStream = (Elastos::IO::IByteArrayOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IByteArrayOutputStream);
        if (*__IByteArrayOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
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
namespace Elastos {
namespace IO {
class CStringWriter
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 initialSize,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStringWriterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStringWriter, RGM_SAME_DOMAIN,
                EIID_ICStringWriterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithInitialSize(initialSize, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IWriter** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStringWriter, RGM_SAME_DOMAIN, Elastos::IO::EIID_IWriter, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IStringWriter** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStringWriter, RGM_SAME_DOMAIN, Elastos::IO::EIID_IStringWriter, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ICloseable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStringWriter, RGM_SAME_DOMAIN, Elastos::IO::EIID_ICloseable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IFlushable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStringWriter, RGM_SAME_DOMAIN, Elastos::IO::EIID_IFlushable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStringWriter, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStringWriter, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStringWriter, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialSize,
        /* [out] */ Elastos::IO::IWriter** __IWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWriter = (Elastos::IO::IWriter*)__pNewObj->Probe(Elastos::IO::EIID_IWriter);
        if (*__IWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialSize,
        /* [out] */ Elastos::IO::IStringWriter** __IStringWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStringWriter = (Elastos::IO::IStringWriter*)__pNewObj->Probe(Elastos::IO::EIID_IStringWriter);
        if (*__IStringWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialSize,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialSize,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialSize,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialSize,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialSize,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialSize, &__pNewObj);
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
namespace IO {
class CFilterInputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFilterInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFilterInputStream, RGM_SAME_DOMAIN,
                EIID_ICFilterInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIs(is, &pObject);

        *__object = pObject;

        pClassObject->Release();

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
namespace Elastos {
namespace IO {
class CBufferedOutputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBufferedOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBufferedOutputStream, RGM_SAME_DOMAIN,
                EIID_ICBufferedOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOutsSize(outs, size, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBufferedOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBufferedOutputStream, RGM_SAME_DOMAIN,
                EIID_ICBufferedOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOuts(outs, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IBufferedOutputStream** __IBufferedOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBufferedOutputStream = (Elastos::IO::IBufferedOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IBufferedOutputStream);
        if (*__IBufferedOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IFilterOutputStream** __IFilterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterOutputStream = (Elastos::IO::IFilterOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterOutputStream);
        if (*__IFilterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::IO::IBufferedOutputStream** __IBufferedOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBufferedOutputStream = (Elastos::IO::IBufferedOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IBufferedOutputStream);
        if (*__IBufferedOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::IO::IFilterOutputStream** __IFilterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterOutputStream = (Elastos::IO::IFilterOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterOutputStream);
        if (*__IFilterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
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
namespace IO {
class CFilterOutputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFilterOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFilterOutputStream, RGM_SAME_DOMAIN,
                EIID_ICFilterOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOuts(outs, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::IO::IFilterOutputStream** __IFilterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterOutputStream = (Elastos::IO::IFilterOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterOutputStream);
        if (*__IFilterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
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
namespace IO {
class CBufferedReader
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IReader * rin,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBufferedReaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBufferedReader, RGM_SAME_DOMAIN,
                EIID_ICBufferedReaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithRin(rin, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IReader * rin,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBufferedReaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBufferedReader, RGM_SAME_DOMAIN,
                EIID_ICBufferedReaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithRinSize(rin, size, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * rin,
        /* [out] */ Elastos::IO::IBufferedReader** __IBufferedReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rin, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBufferedReader = (Elastos::IO::IBufferedReader*)__pNewObj->Probe(Elastos::IO::EIID_IBufferedReader);
        if (*__IBufferedReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * rin,
        /* [out] */ Elastos::IO::IReadable** __IReadable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rin, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReadable = (Elastos::IO::IReadable*)__pNewObj->Probe(Elastos::IO::EIID_IReadable);
        if (*__IReadable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * rin,
        /* [out] */ Elastos::IO::IReader** __IReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rin, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReader = (Elastos::IO::IReader*)__pNewObj->Probe(Elastos::IO::EIID_IReader);
        if (*__IReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * rin,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rin, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * rin,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rin, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * rin,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rin, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * rin,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rin, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * rin,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IBufferedReader** __IBufferedReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rin, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBufferedReader = (Elastos::IO::IBufferedReader*)__pNewObj->Probe(Elastos::IO::EIID_IBufferedReader);
        if (*__IBufferedReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * rin,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IReadable** __IReadable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rin, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReadable = (Elastos::IO::IReadable*)__pNewObj->Probe(Elastos::IO::EIID_IReadable);
        if (*__IReadable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * rin,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IReader** __IReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rin, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReader = (Elastos::IO::IReader*)__pNewObj->Probe(Elastos::IO::EIID_IReader);
        if (*__IReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * rin,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rin, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * rin,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rin, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * rin,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rin, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * rin,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rin, size, &__pNewObj);
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
namespace IO {
class CBufferedWriter
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IWriter * wout,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBufferedWriterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBufferedWriter, RGM_SAME_DOMAIN,
                EIID_ICBufferedWriterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithWout(wout, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IWriter * wout,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBufferedWriterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBufferedWriter, RGM_SAME_DOMAIN,
                EIID_ICBufferedWriterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithWoutSize(wout, size, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wout,
        /* [out] */ Elastos::IO::IBufferedWriter** __IBufferedWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wout, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBufferedWriter = (Elastos::IO::IBufferedWriter*)__pNewObj->Probe(Elastos::IO::EIID_IBufferedWriter);
        if (*__IBufferedWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wout,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wout, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wout,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wout, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wout,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wout, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wout,
        /* [out] */ Elastos::IO::IWriter** __IWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wout, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWriter = (Elastos::IO::IWriter*)__pNewObj->Probe(Elastos::IO::EIID_IWriter);
        if (*__IWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wout,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wout, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wout,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wout, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wout,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wout, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wout,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IBufferedWriter** __IBufferedWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wout, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBufferedWriter = (Elastos::IO::IBufferedWriter*)__pNewObj->Probe(Elastos::IO::EIID_IBufferedWriter);
        if (*__IBufferedWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wout,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wout, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wout,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wout, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wout,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wout, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wout,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IWriter** __IWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wout, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWriter = (Elastos::IO::IWriter*)__pNewObj->Probe(Elastos::IO::EIID_IWriter);
        if (*__IWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wout,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wout, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wout,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wout, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wout,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wout, size, &__pNewObj);
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
namespace IO {
class CByteArrayInputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICByteArrayInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CByteArrayInputStream, RGM_SAME_DOMAIN,
                EIID_ICByteArrayInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithBuffer(buffer, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICByteArrayInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CByteArrayInputStream, RGM_SAME_DOMAIN,
                EIID_ICByteArrayInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithBufferOffsetLength(buffer, offset, length, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [out] */ Elastos::IO::IByteArrayInputStream** __IByteArrayInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buffer, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IByteArrayInputStream = (Elastos::IO::IByteArrayInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IByteArrayInputStream);
        if (*__IByteArrayInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buffer, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buffer, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buffer, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buffer, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buffer, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::IO::IByteArrayInputStream** __IByteArrayInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buffer, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IByteArrayInputStream = (Elastos::IO::IByteArrayInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IByteArrayInputStream);
        if (*__IByteArrayInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buffer, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buffer, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buffer, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buffer, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * buffer,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buffer, offset, length, &__pNewObj);
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
namespace IO {
class CCharArrayReader
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buf,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCharArrayReaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCharArrayReader, RGM_SAME_DOMAIN,
                EIID_ICCharArrayReaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithBuf(buf, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCharArrayReaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCharArrayReader, RGM_SAME_DOMAIN,
                EIID_ICCharArrayReaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithBufOffsetLength(buf, offset, length, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buf,
        /* [out] */ Elastos::IO::ICharArrayReader** __ICharArrayReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICharArrayReader = (Elastos::IO::ICharArrayReader*)__pNewObj->Probe(Elastos::IO::EIID_ICharArrayReader);
        if (*__ICharArrayReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buf,
        /* [out] */ Elastos::IO::IReadable** __IReadable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReadable = (Elastos::IO::IReadable*)__pNewObj->Probe(Elastos::IO::EIID_IReadable);
        if (*__IReadable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buf,
        /* [out] */ Elastos::IO::IReader** __IReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReader = (Elastos::IO::IReader*)__pNewObj->Probe(Elastos::IO::EIID_IReader);
        if (*__IReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buf,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buf,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buf,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buf,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::IO::ICharArrayReader** __ICharArrayReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICharArrayReader = (Elastos::IO::ICharArrayReader*)__pNewObj->Probe(Elastos::IO::EIID_ICharArrayReader);
        if (*__ICharArrayReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::IO::IReadable** __IReadable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReadable = (Elastos::IO::IReadable*)__pNewObj->Probe(Elastos::IO::EIID_IReadable);
        if (*__IReadable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::IO::IReader** __IReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReader = (Elastos::IO::IReader*)__pNewObj->Probe(Elastos::IO::EIID_IReader);
        if (*__IReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, offset, length, &__pNewObj);
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
namespace IO {
class CCharArrayWriter
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 initialSize,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCharArrayWriterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCharArrayWriter, RGM_SAME_DOMAIN,
                EIID_ICCharArrayWriterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithInitialSize(initialSize, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ICharArrayWriter** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCharArrayWriter, RGM_SAME_DOMAIN, Elastos::IO::EIID_ICharArrayWriter, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::IAppendable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCharArrayWriter, RGM_SAME_DOMAIN, Elastos::Core::EIID_IAppendable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ICloseable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCharArrayWriter, RGM_SAME_DOMAIN, Elastos::IO::EIID_ICloseable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IFlushable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCharArrayWriter, RGM_SAME_DOMAIN, Elastos::IO::EIID_IFlushable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IWriter** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCharArrayWriter, RGM_SAME_DOMAIN, Elastos::IO::EIID_IWriter, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCharArrayWriter, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCharArrayWriter, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCharArrayWriter, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialSize,
        /* [out] */ Elastos::IO::ICharArrayWriter** __ICharArrayWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICharArrayWriter = (Elastos::IO::ICharArrayWriter*)__pNewObj->Probe(Elastos::IO::EIID_ICharArrayWriter);
        if (*__ICharArrayWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialSize,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialSize,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialSize,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialSize,
        /* [out] */ Elastos::IO::IWriter** __IWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWriter = (Elastos::IO::IWriter*)__pNewObj->Probe(Elastos::IO::EIID_IWriter);
        if (*__IWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialSize,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialSize,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialSize,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialSize, &__pNewObj);
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
namespace IO {
class CCharBufferHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::IO::ICharBufferHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCharBufferHelper, RGM_SAME_DOMAIN, Elastos::IO::EIID_ICharBufferHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCharBufferHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCharBufferHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCharBufferHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace IO {
class CDataInputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDataInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDataInputStream, RGM_SAME_DOMAIN,
                EIID_ICDataInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIs(is, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ Elastos::IO::IDataInputStream** __IDataInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDataInputStream = (Elastos::IO::IDataInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IDataInputStream);
        if (*__IDataInputStream) __pNewObj->AddRef();
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
        /* [out] */ Elastos::IO::IDataInput** __IDataInput)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDataInput = (Elastos::IO::IDataInput*)__pNewObj->Probe(Elastos::IO::EIID_IDataInput);
        if (*__IDataInput) __pNewObj->AddRef();
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
namespace Elastos {
namespace IO {
class CPushbackInputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPushbackInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPushbackInputStream, RGM_SAME_DOMAIN,
                EIID_ICPushbackInputStreamClassObject, (IInterface**)&pClassObject);
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
        ICPushbackInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPushbackInputStream, RGM_SAME_DOMAIN,
                EIID_ICPushbackInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIsSize(is, size, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ Elastos::IO::IPushbackInputStream** __IPushbackInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPushbackInputStream = (Elastos::IO::IPushbackInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IPushbackInputStream);
        if (*__IPushbackInputStream) __pNewObj->AddRef();
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
        /* [out] */ Elastos::IO::IPushbackInputStream** __IPushbackInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPushbackInputStream = (Elastos::IO::IPushbackInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IPushbackInputStream);
        if (*__IPushbackInputStream) __pNewObj->AddRef();
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
namespace Elastos {
namespace IO {
class CDataOutputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDataOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDataOutputStream, RGM_SAME_DOMAIN,
                EIID_ICDataOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOs(os, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ Elastos::IO::IDataOutputStream** __IDataOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDataOutputStream = (Elastos::IO::IDataOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IDataOutputStream);
        if (*__IDataOutputStream) __pNewObj->AddRef();
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
        /* [out] */ Elastos::IO::IDataOutput** __IDataOutput)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDataOutput = (Elastos::IO::IDataOutput*)__pNewObj->Probe(Elastos::IO::EIID_IDataOutput);
        if (*__IDataOutput) __pNewObj->AddRef();
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
namespace Elastos {
namespace IO {
class CByteBufferHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::IO::IByteBufferHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CByteBufferHelper, RGM_SAME_DOMAIN, Elastos::IO::EIID_IByteBufferHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CByteBufferHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CByteBufferHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CByteBufferHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace IO {
class CByteOrderHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::IO::IByteOrderHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CByteOrderHelper, RGM_SAME_DOMAIN, Elastos::IO::EIID_IByteOrderHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CByteOrderHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CByteOrderHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CByteOrderHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace IO {
class CSelectorImpl
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::Channels::Spi::ISelectorProvider * selectorProvider,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSelectorImplClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSelectorImpl, RGM_SAME_DOMAIN,
                EIID_ICSelectorImplClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSelectorProvider(selectorProvider, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::Channels::Spi::IAbstractSelector** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSelectorImpl, RGM_SAME_DOMAIN, Elastos::IO::Channels::Spi::EIID_IAbstractSelector, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::Channels::ISelector** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSelectorImpl, RGM_SAME_DOMAIN, Elastos::IO::Channels::EIID_ISelector, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ICloseable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSelectorImpl, RGM_SAME_DOMAIN, Elastos::IO::EIID_ICloseable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSelectorImpl, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSelectorImpl, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSelectorImpl, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::Channels::Spi::ISelectorProvider * selectorProvider,
        /* [out] */ Elastos::IO::Channels::Spi::IAbstractSelector** __IAbstractSelector)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(selectorProvider, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAbstractSelector = (Elastos::IO::Channels::Spi::IAbstractSelector*)__pNewObj->Probe(Elastos::IO::Channels::Spi::EIID_IAbstractSelector);
        if (*__IAbstractSelector) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::Channels::Spi::ISelectorProvider * selectorProvider,
        /* [out] */ Elastos::IO::Channels::ISelector** __ISelector)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(selectorProvider, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISelector = (Elastos::IO::Channels::ISelector*)__pNewObj->Probe(Elastos::IO::Channels::EIID_ISelector);
        if (*__ISelector) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::Channels::Spi::ISelectorProvider * selectorProvider,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(selectorProvider, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::Channels::Spi::ISelectorProvider * selectorProvider,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(selectorProvider, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::Channels::Spi::ISelectorProvider * selectorProvider,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(selectorProvider, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::Channels::Spi::ISelectorProvider * selectorProvider,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(selectorProvider, &__pNewObj);
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
namespace IO {
class CFileDescriptor
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IFileDescriptor** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFileDescriptor, RGM_SAME_DOMAIN, Elastos::IO::EIID_IFileDescriptor, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFileDescriptor, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFileDescriptor, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFileDescriptor, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace IO {
class CFile
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFile * dir,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFileClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFile, RGM_SAME_DOMAIN,
                EIID_ICFileClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithDirName(dir, name, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& path,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFileClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFile, RGM_SAME_DOMAIN,
                EIID_ICFileClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPath(path, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& dirPath,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFileClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFile, RGM_SAME_DOMAIN,
                EIID_ICFileClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithDirPathName(dirPath, name, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Net::IURI * uri,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFileClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFile, RGM_SAME_DOMAIN,
                EIID_ICFileClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithUri(uri, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * dir,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::IO::IFile** __IFile)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dir, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFile = (Elastos::IO::IFile*)__pNewObj->Probe(Elastos::IO::EIID_IFile);
        if (*__IFile) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * dir,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dir, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * dir,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dir, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * dir,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dir, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * dir,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dir, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * dir,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dir, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& path,
        /* [out] */ Elastos::IO::IFile** __IFile)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(path, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFile = (Elastos::IO::IFile*)__pNewObj->Probe(Elastos::IO::EIID_IFile);
        if (*__IFile) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& path,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(path, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
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
        /* [in] */ const _ELASTOS String& dirPath,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::IO::IFile** __IFile)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dirPath, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFile = (Elastos::IO::IFile*)__pNewObj->Probe(Elastos::IO::EIID_IFile);
        if (*__IFile) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& dirPath,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dirPath, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& dirPath,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dirPath, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& dirPath,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dirPath, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& dirPath,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dirPath, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& dirPath,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dirPath, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURI * uri,
        /* [out] */ Elastos::IO::IFile** __IFile)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(uri, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFile = (Elastos::IO::IFile*)__pNewObj->Probe(Elastos::IO::EIID_IFile);
        if (*__IFile) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURI * uri,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(uri, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURI * uri,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(uri, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURI * uri,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(uri, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURI * uri,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(uri, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURI * uri,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(uri, &__pNewObj);
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
namespace IO {
class CFileHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::IO::IFileHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFileHelper, RGM_SAME_DOMAIN, Elastos::IO::EIID_IFileHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFileHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFileHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFileHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace IO {
class CInputStreamReader
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInputStreamReaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInputStreamReader, RGM_SAME_DOMAIN,
                EIID_ICInputStreamReaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIs(is, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInputStreamReaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInputStreamReader, RGM_SAME_DOMAIN,
                EIID_ICInputStreamReaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIsCharsetName(is, charsetName, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharsetDecoder * dec,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInputStreamReaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInputStreamReader, RGM_SAME_DOMAIN,
                EIID_ICInputStreamReaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIsDec(is, dec, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharset * charset,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInputStreamReaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInputStreamReader, RGM_SAME_DOMAIN,
                EIID_ICInputStreamReaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIsCharset(is, charset, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ Elastos::IO::IInputStreamReader** __IInputStreamReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStreamReader = (Elastos::IO::IInputStreamReader*)__pNewObj->Probe(Elastos::IO::EIID_IInputStreamReader);
        if (*__IInputStreamReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ Elastos::IO::IReadable** __IReadable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReadable = (Elastos::IO::IReadable*)__pNewObj->Probe(Elastos::IO::EIID_IReadable);
        if (*__IReadable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ Elastos::IO::IReader** __IReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReader = (Elastos::IO::IReader*)__pNewObj->Probe(Elastos::IO::EIID_IReader);
        if (*__IReader) __pNewObj->AddRef();
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
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::IO::IInputStreamReader** __IInputStreamReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStreamReader = (Elastos::IO::IInputStreamReader*)__pNewObj->Probe(Elastos::IO::EIID_IInputStreamReader);
        if (*__IInputStreamReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::IO::IReadable** __IReadable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReadable = (Elastos::IO::IReadable*)__pNewObj->Probe(Elastos::IO::EIID_IReadable);
        if (*__IReadable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::IO::IReader** __IReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReader = (Elastos::IO::IReader*)__pNewObj->Probe(Elastos::IO::EIID_IReader);
        if (*__IReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharsetDecoder * dec,
        /* [out] */ Elastos::IO::IInputStreamReader** __IInputStreamReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, dec, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStreamReader = (Elastos::IO::IInputStreamReader*)__pNewObj->Probe(Elastos::IO::EIID_IInputStreamReader);
        if (*__IInputStreamReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharsetDecoder * dec,
        /* [out] */ Elastos::IO::IReadable** __IReadable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, dec, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReadable = (Elastos::IO::IReadable*)__pNewObj->Probe(Elastos::IO::EIID_IReadable);
        if (*__IReadable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharsetDecoder * dec,
        /* [out] */ Elastos::IO::IReader** __IReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, dec, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReader = (Elastos::IO::IReader*)__pNewObj->Probe(Elastos::IO::EIID_IReader);
        if (*__IReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharsetDecoder * dec,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, dec, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharsetDecoder * dec,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, dec, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharsetDecoder * dec,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, dec, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharsetDecoder * dec,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, dec, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharset * charset,
        /* [out] */ Elastos::IO::IInputStreamReader** __IInputStreamReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, charset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStreamReader = (Elastos::IO::IInputStreamReader*)__pNewObj->Probe(Elastos::IO::EIID_IInputStreamReader);
        if (*__IInputStreamReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharset * charset,
        /* [out] */ Elastos::IO::IReadable** __IReadable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, charset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReadable = (Elastos::IO::IReadable*)__pNewObj->Probe(Elastos::IO::EIID_IReadable);
        if (*__IReadable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharset * charset,
        /* [out] */ Elastos::IO::IReader** __IReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, charset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReader = (Elastos::IO::IReader*)__pNewObj->Probe(Elastos::IO::EIID_IReader);
        if (*__IReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharset * charset,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, charset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharset * charset,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, charset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharset * charset,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, charset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::IO::Charset::ICharset * charset,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, charset, &__pNewObj);
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
namespace IO {
class CDirectByteBufferHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::IO::IDirectByteBufferHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDirectByteBufferHelper, RGM_SAME_DOMAIN, Elastos::IO::EIID_IDirectByteBufferHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDirectByteBufferHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDirectByteBufferHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDirectByteBufferHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace IO {
class CPrintWriter
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPrintWriterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPrintWriter, RGM_SAME_DOMAIN,
                EIID_ICPrintWriterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOuts(outs, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPrintWriterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPrintWriter, RGM_SAME_DOMAIN,
                EIID_ICPrintWriterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOutsAutoflush(outs, autoflush, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IWriter * wr,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPrintWriterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPrintWriter, RGM_SAME_DOMAIN,
                EIID_ICPrintWriterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithWr(wr, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IWriter * wr,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPrintWriterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPrintWriter, RGM_SAME_DOMAIN,
                EIID_ICPrintWriterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithWrAutoflush(wr, autoflush, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPrintWriterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPrintWriter, RGM_SAME_DOMAIN,
                EIID_ICPrintWriterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFile(file, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& csn,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPrintWriterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPrintWriter, RGM_SAME_DOMAIN,
                EIID_ICPrintWriterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFileCsn(file, csn, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPrintWriterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPrintWriter, RGM_SAME_DOMAIN,
                EIID_ICPrintWriterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFileName(fileName, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& csn,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPrintWriterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPrintWriter, RGM_SAME_DOMAIN,
                EIID_ICPrintWriterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFileNameCsn(fileName, csn, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::IO::IPrintWriter** __IPrintWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPrintWriter = (Elastos::IO::IPrintWriter*)__pNewObj->Probe(Elastos::IO::EIID_IPrintWriter);
        if (*__IPrintWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::IO::IWriter** __IWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWriter = (Elastos::IO::IWriter*)__pNewObj->Probe(Elastos::IO::EIID_IWriter);
        if (*__IWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ Elastos::IO::IPrintWriter** __IPrintWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPrintWriter = (Elastos::IO::IPrintWriter*)__pNewObj->Probe(Elastos::IO::EIID_IPrintWriter);
        if (*__IPrintWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ Elastos::IO::IWriter** __IWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWriter = (Elastos::IO::IWriter*)__pNewObj->Probe(Elastos::IO::EIID_IWriter);
        if (*__IWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wr,
        /* [out] */ Elastos::IO::IPrintWriter** __IPrintWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPrintWriter = (Elastos::IO::IPrintWriter*)__pNewObj->Probe(Elastos::IO::EIID_IPrintWriter);
        if (*__IPrintWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wr,
        /* [out] */ Elastos::IO::IWriter** __IWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWriter = (Elastos::IO::IWriter*)__pNewObj->Probe(Elastos::IO::EIID_IWriter);
        if (*__IWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wr,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wr,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wr,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wr,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wr,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wr,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wr,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ Elastos::IO::IPrintWriter** __IPrintWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wr, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPrintWriter = (Elastos::IO::IPrintWriter*)__pNewObj->Probe(Elastos::IO::EIID_IPrintWriter);
        if (*__IPrintWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wr,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ Elastos::IO::IWriter** __IWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wr, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWriter = (Elastos::IO::IWriter*)__pNewObj->Probe(Elastos::IO::EIID_IWriter);
        if (*__IWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wr,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wr, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wr,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wr, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wr,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wr, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wr,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wr, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wr,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wr, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IWriter * wr,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wr, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::IO::IPrintWriter** __IPrintWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPrintWriter = (Elastos::IO::IPrintWriter*)__pNewObj->Probe(Elastos::IO::EIID_IPrintWriter);
        if (*__IPrintWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::IO::IWriter** __IWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWriter = (Elastos::IO::IWriter*)__pNewObj->Probe(Elastos::IO::EIID_IWriter);
        if (*__IWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
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
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
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
        /* [in] */ const _ELASTOS String& csn,
        /* [out] */ Elastos::IO::IPrintWriter** __IPrintWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, csn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPrintWriter = (Elastos::IO::IPrintWriter*)__pNewObj->Probe(Elastos::IO::EIID_IPrintWriter);
        if (*__IPrintWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& csn,
        /* [out] */ Elastos::IO::IWriter** __IWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, csn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWriter = (Elastos::IO::IWriter*)__pNewObj->Probe(Elastos::IO::EIID_IWriter);
        if (*__IWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& csn,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, csn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& csn,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, csn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& csn,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, csn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& csn,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, csn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& csn,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, csn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& csn,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, csn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ Elastos::IO::IPrintWriter** __IPrintWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPrintWriter = (Elastos::IO::IPrintWriter*)__pNewObj->Probe(Elastos::IO::EIID_IPrintWriter);
        if (*__IPrintWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ Elastos::IO::IWriter** __IWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWriter = (Elastos::IO::IWriter*)__pNewObj->Probe(Elastos::IO::EIID_IWriter);
        if (*__IWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& csn,
        /* [out] */ Elastos::IO::IPrintWriter** __IPrintWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, csn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPrintWriter = (Elastos::IO::IPrintWriter*)__pNewObj->Probe(Elastos::IO::EIID_IPrintWriter);
        if (*__IPrintWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& csn,
        /* [out] */ Elastos::IO::IWriter** __IWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, csn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWriter = (Elastos::IO::IWriter*)__pNewObj->Probe(Elastos::IO::EIID_IWriter);
        if (*__IWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& csn,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, csn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& csn,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, csn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& csn,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, csn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& csn,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, csn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& csn,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, csn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& csn,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, csn, &__pNewObj);
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
namespace IO {
class CLineNumberInputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICLineNumberInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CLineNumberInputStream, RGM_SAME_DOMAIN,
                EIID_ICLineNumberInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIs(is, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ Elastos::IO::ILineNumberInputStream** __ILineNumberInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ILineNumberInputStream = (Elastos::IO::ILineNumberInputStream*)__pNewObj->Probe(Elastos::IO::EIID_ILineNumberInputStream);
        if (*__ILineNumberInputStream) __pNewObj->AddRef();
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
namespace Elastos {
namespace IO {
class CLineNumberReader
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICLineNumberReaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CLineNumberReader, RGM_SAME_DOMAIN,
                EIID_ICLineNumberReaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIr(ir, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICLineNumberReaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CLineNumberReader, RGM_SAME_DOMAIN,
                EIID_ICLineNumberReaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIrSize(ir, size, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [out] */ Elastos::IO::ILineNumberReader** __ILineNumberReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ILineNumberReader = (Elastos::IO::ILineNumberReader*)__pNewObj->Probe(Elastos::IO::EIID_ILineNumberReader);
        if (*__ILineNumberReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [out] */ Elastos::IO::IReadable** __IReadable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReadable = (Elastos::IO::IReadable*)__pNewObj->Probe(Elastos::IO::EIID_IReadable);
        if (*__IReadable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [out] */ Elastos::IO::IReader** __IReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReader = (Elastos::IO::IReader*)__pNewObj->Probe(Elastos::IO::EIID_IReader);
        if (*__IReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [out] */ Elastos::IO::IBufferedReader** __IBufferedReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBufferedReader = (Elastos::IO::IBufferedReader*)__pNewObj->Probe(Elastos::IO::EIID_IBufferedReader);
        if (*__IBufferedReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::ILineNumberReader** __ILineNumberReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ILineNumberReader = (Elastos::IO::ILineNumberReader*)__pNewObj->Probe(Elastos::IO::EIID_ILineNumberReader);
        if (*__ILineNumberReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IReadable** __IReadable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReadable = (Elastos::IO::IReadable*)__pNewObj->Probe(Elastos::IO::EIID_IReadable);
        if (*__IReadable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IReader** __IReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReader = (Elastos::IO::IReader*)__pNewObj->Probe(Elastos::IO::EIID_IReader);
        if (*__IReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IBufferedReader** __IBufferedReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBufferedReader = (Elastos::IO::IBufferedReader*)__pNewObj->Probe(Elastos::IO::EIID_IBufferedReader);
        if (*__IBufferedReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, size, &__pNewObj);
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
namespace IO {
class COutputStreamWriter
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICOutputStreamWriterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_COutputStreamWriter, RGM_SAME_DOMAIN,
                EIID_ICOutputStreamWriterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOs(os, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ const _ELASTOS String& enc,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICOutputStreamWriterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_COutputStreamWriter, RGM_SAME_DOMAIN,
                EIID_ICOutputStreamWriterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOsEnc(os, enc, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::IO::Charset::ICharsetEncoder * charsetEncoder,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICOutputStreamWriterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_COutputStreamWriter, RGM_SAME_DOMAIN,
                EIID_ICOutputStreamWriterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOsCharsetEncoder(os, charsetEncoder, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ Elastos::IO::IOutputStreamWriter** __IOutputStreamWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStreamWriter = (Elastos::IO::IOutputStreamWriter*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStreamWriter);
        if (*__IOutputStreamWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
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
        /* [out] */ Elastos::IO::IWriter** __IWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWriter = (Elastos::IO::IWriter*)__pNewObj->Probe(Elastos::IO::EIID_IWriter);
        if (*__IWriter) __pNewObj->AddRef();
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
        /* [in] */ const _ELASTOS String& enc,
        /* [out] */ Elastos::IO::IOutputStreamWriter** __IOutputStreamWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, enc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStreamWriter = (Elastos::IO::IOutputStreamWriter*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStreamWriter);
        if (*__IOutputStreamWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ const _ELASTOS String& enc,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, enc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ const _ELASTOS String& enc,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, enc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ const _ELASTOS String& enc,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, enc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ const _ELASTOS String& enc,
        /* [out] */ Elastos::IO::IWriter** __IWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, enc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWriter = (Elastos::IO::IWriter*)__pNewObj->Probe(Elastos::IO::EIID_IWriter);
        if (*__IWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ const _ELASTOS String& enc,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, enc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ const _ELASTOS String& enc,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, enc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ const _ELASTOS String& enc,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, enc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::IO::Charset::ICharsetEncoder * charsetEncoder,
        /* [out] */ Elastos::IO::IOutputStreamWriter** __IOutputStreamWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, charsetEncoder, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStreamWriter = (Elastos::IO::IOutputStreamWriter*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStreamWriter);
        if (*__IOutputStreamWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::IO::Charset::ICharsetEncoder * charsetEncoder,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, charsetEncoder, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::IO::Charset::ICharsetEncoder * charsetEncoder,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, charsetEncoder, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::IO::Charset::ICharsetEncoder * charsetEncoder,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, charsetEncoder, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::IO::Charset::ICharsetEncoder * charsetEncoder,
        /* [out] */ Elastos::IO::IWriter** __IWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, charsetEncoder, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWriter = (Elastos::IO::IWriter*)__pNewObj->Probe(Elastos::IO::EIID_IWriter);
        if (*__IWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::IO::Charset::ICharsetEncoder * charsetEncoder,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, charsetEncoder, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::IO::Charset::ICharsetEncoder * charsetEncoder,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, charsetEncoder, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ Elastos::IO::Charset::ICharsetEncoder * charsetEncoder,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(os, charsetEncoder, &__pNewObj);
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
namespace IO {
class CPrintStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPrintStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPrintStream, RGM_SAME_DOMAIN,
                EIID_ICPrintStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOuts(outs, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPrintStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPrintStream, RGM_SAME_DOMAIN,
                EIID_ICPrintStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOutsAutoflush(outs, autoflush, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPrintStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPrintStream, RGM_SAME_DOMAIN,
                EIID_ICPrintStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOutsAutoflushCharsetName(outs, autoflush, charsetName, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPrintStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPrintStream, RGM_SAME_DOMAIN,
                EIID_ICPrintStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFile(file, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPrintStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPrintStream, RGM_SAME_DOMAIN,
                EIID_ICPrintStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFileCharsetName(file, charsetName, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPrintStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPrintStream, RGM_SAME_DOMAIN,
                EIID_ICPrintStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFileName(fileName, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPrintStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPrintStream, RGM_SAME_DOMAIN,
                EIID_ICPrintStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFileNameCharsetName(fileName, charsetName, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::IO::IPrintStream** __IPrintStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPrintStream = (Elastos::IO::IPrintStream*)__pNewObj->Probe(Elastos::IO::EIID_IPrintStream);
        if (*__IPrintStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::IO::IFilterOutputStream** __IFilterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterOutputStream = (Elastos::IO::IFilterOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterOutputStream);
        if (*__IFilterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ Elastos::IO::IPrintStream** __IPrintStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPrintStream = (Elastos::IO::IPrintStream*)__pNewObj->Probe(Elastos::IO::EIID_IPrintStream);
        if (*__IPrintStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ Elastos::IO::IFilterOutputStream** __IFilterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterOutputStream = (Elastos::IO::IFilterOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterOutputStream);
        if (*__IFilterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::IO::IPrintStream** __IPrintStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPrintStream = (Elastos::IO::IPrintStream*)__pNewObj->Probe(Elastos::IO::EIID_IPrintStream);
        if (*__IPrintStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::IO::IFilterOutputStream** __IFilterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterOutputStream = (Elastos::IO::IFilterOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterOutputStream);
        if (*__IFilterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * outs,
        /* [in] */ _ELASTOS Boolean autoflush,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(outs, autoflush, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::IO::IPrintStream** __IPrintStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPrintStream = (Elastos::IO::IPrintStream*)__pNewObj->Probe(Elastos::IO::EIID_IPrintStream);
        if (*__IPrintStream) __pNewObj->AddRef();
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
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::IO::IFilterOutputStream** __IFilterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterOutputStream = (Elastos::IO::IFilterOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterOutputStream);
        if (*__IFilterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
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
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::IO::IPrintStream** __IPrintStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPrintStream = (Elastos::IO::IPrintStream*)__pNewObj->Probe(Elastos::IO::EIID_IPrintStream);
        if (*__IPrintStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::IO::IFilterOutputStream** __IFilterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterOutputStream = (Elastos::IO::IFilterOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterOutputStream);
        if (*__IFilterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ Elastos::IO::IPrintStream** __IPrintStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPrintStream = (Elastos::IO::IPrintStream*)__pNewObj->Probe(Elastos::IO::EIID_IPrintStream);
        if (*__IPrintStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ Elastos::IO::IFilterOutputStream** __IFilterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterOutputStream = (Elastos::IO::IFilterOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterOutputStream);
        if (*__IFilterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::IO::IPrintStream** __IPrintStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPrintStream = (Elastos::IO::IPrintStream*)__pNewObj->Probe(Elastos::IO::EIID_IPrintStream);
        if (*__IPrintStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::IO::IFilterOutputStream** __IFilterOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilterOutputStream = (Elastos::IO::IFilterOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFilterOutputStream);
        if (*__IFilterOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, charsetName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, charsetName, &__pNewObj);
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
namespace IO {
class CPushbackReader
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPushbackReaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPushbackReader, RGM_SAME_DOMAIN,
                EIID_ICPushbackReaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIr(ir, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPushbackReaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPushbackReader, RGM_SAME_DOMAIN,
                EIID_ICPushbackReaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIrSize(ir, size, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [out] */ Elastos::IO::IPushbackReader** __IPushbackReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPushbackReader = (Elastos::IO::IPushbackReader*)__pNewObj->Probe(Elastos::IO::EIID_IPushbackReader);
        if (*__IPushbackReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [out] */ Elastos::IO::IReadable** __IReadable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReadable = (Elastos::IO::IReadable*)__pNewObj->Probe(Elastos::IO::EIID_IReadable);
        if (*__IReadable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [out] */ Elastos::IO::IReader** __IReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReader = (Elastos::IO::IReader*)__pNewObj->Probe(Elastos::IO::EIID_IReader);
        if (*__IReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IPushbackReader** __IPushbackReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPushbackReader = (Elastos::IO::IPushbackReader*)__pNewObj->Probe(Elastos::IO::EIID_IPushbackReader);
        if (*__IPushbackReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IReadable** __IReadable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReadable = (Elastos::IO::IReadable*)__pNewObj->Probe(Elastos::IO::EIID_IReadable);
        if (*__IReadable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::IReader** __IReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReader = (Elastos::IO::IReader*)__pNewObj->Probe(Elastos::IO::EIID_IReader);
        if (*__IReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * ir,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ir, size, &__pNewObj);
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
namespace IO {
class CRandomAccessFile
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& mode,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICRandomAccessFileClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CRandomAccessFile, RGM_SAME_DOMAIN,
                EIID_ICRandomAccessFileClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFileMode(file, mode, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& mode,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICRandomAccessFileClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CRandomAccessFile, RGM_SAME_DOMAIN,
                EIID_ICRandomAccessFileClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFileNameMode(fileName, mode, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& mode,
        /* [out] */ Elastos::IO::IRandomAccessFile** __IRandomAccessFile)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, mode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRandomAccessFile = (Elastos::IO::IRandomAccessFile*)__pNewObj->Probe(Elastos::IO::EIID_IRandomAccessFile);
        if (*__IRandomAccessFile) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& mode,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, mode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& mode,
        /* [out] */ Elastos::IO::IDataInput** __IDataInput)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, mode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDataInput = (Elastos::IO::IDataInput*)__pNewObj->Probe(Elastos::IO::EIID_IDataInput);
        if (*__IDataInput) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& mode,
        /* [out] */ Elastos::IO::IDataOutput** __IDataOutput)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, mode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDataOutput = (Elastos::IO::IDataOutput*)__pNewObj->Probe(Elastos::IO::EIID_IDataOutput);
        if (*__IDataOutput) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ const _ELASTOS String& mode,
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
        /* [in] */ const _ELASTOS String& mode,
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
        /* [in] */ const _ELASTOS String& mode,
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
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& mode,
        /* [out] */ Elastos::IO::IRandomAccessFile** __IRandomAccessFile)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, mode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRandomAccessFile = (Elastos::IO::IRandomAccessFile*)__pNewObj->Probe(Elastos::IO::EIID_IRandomAccessFile);
        if (*__IRandomAccessFile) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& mode,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, mode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& mode,
        /* [out] */ Elastos::IO::IDataInput** __IDataInput)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, mode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDataInput = (Elastos::IO::IDataInput*)__pNewObj->Probe(Elastos::IO::EIID_IDataInput);
        if (*__IDataInput) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& mode,
        /* [out] */ Elastos::IO::IDataOutput** __IDataOutput)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, mode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDataOutput = (Elastos::IO::IDataOutput*)__pNewObj->Probe(Elastos::IO::EIID_IDataOutput);
        if (*__IDataOutput) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& mode,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, mode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& mode,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, mode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ const _ELASTOS String& mode,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, mode, &__pNewObj);
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
namespace IO {
class CSequenceInputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * s1,
        /* [in] */ Elastos::IO::IInputStream * s2,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSequenceInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSequenceInputStream, RGM_SAME_DOMAIN,
                EIID_ICSequenceInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithS1S2(s1, s2, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::IEnumeration * e,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSequenceInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSequenceInputStream, RGM_SAME_DOMAIN,
                EIID_ICSequenceInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithE(e, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * s1,
        /* [in] */ Elastos::IO::IInputStream * s2,
        /* [out] */ Elastos::IO::ISequenceInputStream** __ISequenceInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s1, s2, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISequenceInputStream = (Elastos::IO::ISequenceInputStream*)__pNewObj->Probe(Elastos::IO::EIID_ISequenceInputStream);
        if (*__ISequenceInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * s1,
        /* [in] */ Elastos::IO::IInputStream * s2,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s1, s2, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * s1,
        /* [in] */ Elastos::IO::IInputStream * s2,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s1, s2, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * s1,
        /* [in] */ Elastos::IO::IInputStream * s2,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s1, s2, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * s1,
        /* [in] */ Elastos::IO::IInputStream * s2,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s1, s2, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * s1,
        /* [in] */ Elastos::IO::IInputStream * s2,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s1, s2, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IEnumeration * e,
        /* [out] */ Elastos::IO::ISequenceInputStream** __ISequenceInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(e, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISequenceInputStream = (Elastos::IO::ISequenceInputStream*)__pNewObj->Probe(Elastos::IO::EIID_ISequenceInputStream);
        if (*__ISequenceInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IEnumeration * e,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(e, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IEnumeration * e,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(e, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IEnumeration * e,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(e, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IEnumeration * e,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(e, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IEnumeration * e,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(e, &__pNewObj);
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
namespace IO {
class CStringBufferInputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStringBufferInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStringBufferInputStream, RGM_SAME_DOMAIN,
                EIID_ICStringBufferInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithStr(str, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ Elastos::IO::IStringBufferInputStream** __IStringBufferInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStringBufferInputStream = (Elastos::IO::IStringBufferInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IStringBufferInputStream);
        if (*__IStringBufferInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
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
namespace IO {
class CStringReader
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStringReaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStringReader, RGM_SAME_DOMAIN,
                EIID_ICStringReaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithStr(str, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ Elastos::IO::IStringReader** __IStringReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStringReader = (Elastos::IO::IStringReader*)__pNewObj->Probe(Elastos::IO::EIID_IStringReader);
        if (*__IStringReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ Elastos::IO::IReadable** __IReadable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReadable = (Elastos::IO::IReadable*)__pNewObj->Probe(Elastos::IO::EIID_IReadable);
        if (*__IReadable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ Elastos::IO::IReader** __IReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReader = (Elastos::IO::IReader*)__pNewObj->Probe(Elastos::IO::EIID_IReader);
        if (*__IReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
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
namespace IO {
class CFileInputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFileInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFileInputStream, RGM_SAME_DOMAIN,
                EIID_ICFileInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFile(file, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFileInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFileInputStream, RGM_SAME_DOMAIN,
                EIID_ICFileInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFd(fd, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFileInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFileInputStream, RGM_SAME_DOMAIN,
                EIID_ICFileInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFileName(fileName, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::IO::IFileInputStream** __IFileInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFileInputStream = (Elastos::IO::IFileInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFileInputStream);
        if (*__IFileInputStream) __pNewObj->AddRef();
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
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
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
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::IO::IFileInputStream** __IFileInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFileInputStream = (Elastos::IO::IFileInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFileInputStream);
        if (*__IFileInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ Elastos::IO::IFileInputStream** __IFileInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFileInputStream = (Elastos::IO::IFileInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFileInputStream);
        if (*__IFileInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
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
namespace IO {
class CFileOutputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFileOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFileOutputStream, RGM_SAME_DOMAIN,
                EIID_ICFileOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFile(file, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFileOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFileOutputStream, RGM_SAME_DOMAIN,
                EIID_ICFileOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFileAppend(file, append, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFileOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFileOutputStream, RGM_SAME_DOMAIN,
                EIID_ICFileOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFd(fd, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFileOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFileOutputStream, RGM_SAME_DOMAIN,
                EIID_ICFileOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFileName(fileName, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFileOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFileOutputStream, RGM_SAME_DOMAIN,
                EIID_ICFileOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFileNameAppend(fileName, append, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::IO::IFileOutputStream** __IFileOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFileOutputStream = (Elastos::IO::IFileOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFileOutputStream);
        if (*__IFileOutputStream) __pNewObj->AddRef();
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
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
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
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::IO::IFileOutputStream** __IFileOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFileOutputStream = (Elastos::IO::IFileOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFileOutputStream);
        if (*__IFileOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::IO::IFileOutputStream** __IFileOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFileOutputStream = (Elastos::IO::IFileOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFileOutputStream);
        if (*__IFileOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ Elastos::IO::IFileOutputStream** __IFileOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFileOutputStream = (Elastos::IO::IFileOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFileOutputStream);
        if (*__IFileOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::IO::IFileOutputStream** __IFileOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFileOutputStream = (Elastos::IO::IFileOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IFileOutputStream);
        if (*__IFileOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fileName,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fileName, append, &__pNewObj);
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
namespace IO {
class CFilePermission
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFilePermissionClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFilePermission, RGM_SAME_DOMAIN,
                EIID_ICFilePermissionClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPathActions(path, actions, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ Elastos::IO::IFilePermission** __IFilePermission)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(path, actions, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFilePermission = (Elastos::IO::IFilePermission*)__pNewObj->Probe(Elastos::IO::EIID_IFilePermission);
        if (*__IFilePermission) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ Elastos::Security::IGuard** __IGuard)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(path, actions, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IGuard = (Elastos::Security::IGuard*)__pNewObj->Probe(Elastos::Security::EIID_IGuard);
        if (*__IGuard) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ Elastos::IO::IPermission** __IPermission)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(path, actions, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPermission = (Elastos::IO::IPermission*)__pNewObj->Probe(Elastos::IO::EIID_IPermission);
        if (*__IPermission) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(path, actions, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(path, actions, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(path, actions, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& actions,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(path, actions, &__pNewObj);
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
namespace IO {
class CFileReader
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFileReaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFileReader, RGM_SAME_DOMAIN,
                EIID_ICFileReaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFile(file, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFileReaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFileReader, RGM_SAME_DOMAIN,
                EIID_ICFileReaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFd(fd, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& filename,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFileReaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFileReader, RGM_SAME_DOMAIN,
                EIID_ICFileReaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFilename(filename, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::IO::IFileReader** __IFileReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFileReader = (Elastos::IO::IFileReader*)__pNewObj->Probe(Elastos::IO::EIID_IFileReader);
        if (*__IFileReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::IO::IReadable** __IReadable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReadable = (Elastos::IO::IReadable*)__pNewObj->Probe(Elastos::IO::EIID_IReadable);
        if (*__IReadable) __pNewObj->AddRef();
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
        /* [out] */ Elastos::IO::IReader** __IReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReader = (Elastos::IO::IReader*)__pNewObj->Probe(Elastos::IO::EIID_IReader);
        if (*__IReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::IO::IInputStreamReader** __IInputStreamReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStreamReader = (Elastos::IO::IInputStreamReader*)__pNewObj->Probe(Elastos::IO::EIID_IInputStreamReader);
        if (*__IInputStreamReader) __pNewObj->AddRef();
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
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::IO::IFileReader** __IFileReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFileReader = (Elastos::IO::IFileReader*)__pNewObj->Probe(Elastos::IO::EIID_IFileReader);
        if (*__IFileReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::IO::IReadable** __IReadable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReadable = (Elastos::IO::IReadable*)__pNewObj->Probe(Elastos::IO::EIID_IReadable);
        if (*__IReadable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::IO::IReader** __IReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReader = (Elastos::IO::IReader*)__pNewObj->Probe(Elastos::IO::EIID_IReader);
        if (*__IReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::IO::IInputStreamReader** __IInputStreamReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStreamReader = (Elastos::IO::IInputStreamReader*)__pNewObj->Probe(Elastos::IO::EIID_IInputStreamReader);
        if (*__IInputStreamReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [out] */ Elastos::IO::IFileReader** __IFileReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFileReader = (Elastos::IO::IFileReader*)__pNewObj->Probe(Elastos::IO::EIID_IFileReader);
        if (*__IFileReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [out] */ Elastos::IO::IReadable** __IReadable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReadable = (Elastos::IO::IReadable*)__pNewObj->Probe(Elastos::IO::EIID_IReadable);
        if (*__IReadable) __pNewObj->AddRef();
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
        /* [out] */ Elastos::IO::IReader** __IReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReader = (Elastos::IO::IReader*)__pNewObj->Probe(Elastos::IO::EIID_IReader);
        if (*__IReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [out] */ Elastos::IO::IInputStreamReader** __IInputStreamReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStreamReader = (Elastos::IO::IInputStreamReader*)__pNewObj->Probe(Elastos::IO::EIID_IInputStreamReader);
        if (*__IInputStreamReader) __pNewObj->AddRef();
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

};
}
}
namespace Elastos {
namespace IO {
class CFileWriter
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFileWriterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFileWriter, RGM_SAME_DOMAIN,
                EIID_ICFileWriterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFile(file, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFileWriterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFileWriter, RGM_SAME_DOMAIN,
                EIID_ICFileWriterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFileAppend(file, append, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFileWriterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFileWriter, RGM_SAME_DOMAIN,
                EIID_ICFileWriterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFd(fd, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& filename,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFileWriterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFileWriter, RGM_SAME_DOMAIN,
                EIID_ICFileWriterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFilename(filename, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& filename,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFileWriterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFileWriter, RGM_SAME_DOMAIN,
                EIID_ICFileWriterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFilenameAppend(filename, append, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::IO::IFileWriter** __IFileWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFileWriter = (Elastos::IO::IFileWriter*)__pNewObj->Probe(Elastos::IO::EIID_IFileWriter);
        if (*__IFileWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
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
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::IO::IWriter** __IWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWriter = (Elastos::IO::IWriter*)__pNewObj->Probe(Elastos::IO::EIID_IWriter);
        if (*__IWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [out] */ Elastos::IO::IOutputStreamWriter** __IOutputStreamWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStreamWriter = (Elastos::IO::IOutputStreamWriter*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStreamWriter);
        if (*__IOutputStreamWriter) __pNewObj->AddRef();
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
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::IO::IFileWriter** __IFileWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFileWriter = (Elastos::IO::IFileWriter*)__pNewObj->Probe(Elastos::IO::EIID_IFileWriter);
        if (*__IFileWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::IO::IWriter** __IWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWriter = (Elastos::IO::IWriter*)__pNewObj->Probe(Elastos::IO::EIID_IWriter);
        if (*__IWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::IO::IOutputStreamWriter** __IOutputStreamWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStreamWriter = (Elastos::IO::IOutputStreamWriter*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStreamWriter);
        if (*__IOutputStreamWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFile * file,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(file, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::IO::IFileWriter** __IFileWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFileWriter = (Elastos::IO::IFileWriter*)__pNewObj->Probe(Elastos::IO::EIID_IFileWriter);
        if (*__IFileWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::IO::IWriter** __IWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWriter = (Elastos::IO::IWriter*)__pNewObj->Probe(Elastos::IO::EIID_IWriter);
        if (*__IWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::IO::IOutputStreamWriter** __IOutputStreamWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStreamWriter = (Elastos::IO::IOutputStreamWriter*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStreamWriter);
        if (*__IOutputStreamWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fd, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [out] */ Elastos::IO::IFileWriter** __IFileWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFileWriter = (Elastos::IO::IFileWriter*)__pNewObj->Probe(Elastos::IO::EIID_IFileWriter);
        if (*__IFileWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
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
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [out] */ Elastos::IO::IWriter** __IWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWriter = (Elastos::IO::IWriter*)__pNewObj->Probe(Elastos::IO::EIID_IWriter);
        if (*__IWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [out] */ Elastos::IO::IOutputStreamWriter** __IOutputStreamWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStreamWriter = (Elastos::IO::IOutputStreamWriter*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStreamWriter);
        if (*__IOutputStreamWriter) __pNewObj->AddRef();
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
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::IO::IFileWriter** __IFileWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFileWriter = (Elastos::IO::IFileWriter*)__pNewObj->Probe(Elastos::IO::EIID_IFileWriter);
        if (*__IFileWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::IO::IWriter** __IWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWriter = (Elastos::IO::IWriter*)__pNewObj->Probe(Elastos::IO::EIID_IWriter);
        if (*__IWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::IO::IOutputStreamWriter** __IOutputStreamWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStreamWriter = (Elastos::IO::IOutputStreamWriter*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStreamWriter);
        if (*__IOutputStreamWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, append, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& filename,
        /* [in] */ _ELASTOS Boolean append,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(filename, append, &__pNewObj);
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
namespace IO {
class CNioUtils
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::IO::INioUtils** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNioUtils, RGM_SAME_DOMAIN, Elastos::IO::EIID_INioUtils, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNioUtils, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNioUtils, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNioUtils, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace IO {
class CPipedInputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ IPipedOutputStream * ipos,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPipedInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPipedInputStream, RGM_SAME_DOMAIN,
                EIID_ICPipedInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIpos(ipos, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPipedInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPipedInputStream, RGM_SAME_DOMAIN,
                EIID_ICPipedInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPipeSize(pipeSize, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ IPipedOutputStream * ipos,
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPipedInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPipedInputStream, RGM_SAME_DOMAIN,
                EIID_ICPipedInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIposPipeSize(ipos, pipeSize, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IPipedInputStream** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedInputStream, RGM_SAME_DOMAIN, Elastos::IO::EIID_IPipedInputStream, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ICloseable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedInputStream, RGM_SAME_DOMAIN, Elastos::IO::EIID_ICloseable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IInputStream** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedInputStream, RGM_SAME_DOMAIN, Elastos::IO::EIID_IInputStream, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedInputStream, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedInputStream, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedInputStream, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ IPipedOutputStream * ipos,
        /* [out] */ Elastos::IO::IPipedInputStream** __IPipedInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipos, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPipedInputStream = (Elastos::IO::IPipedInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IPipedInputStream);
        if (*__IPipedInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IPipedOutputStream * ipos,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipos, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IPipedOutputStream * ipos,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipos, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IPipedOutputStream * ipos,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipos, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IPipedOutputStream * ipos,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipos, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IPipedOutputStream * ipos,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipos, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ Elastos::IO::IPipedInputStream** __IPipedInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPipedInputStream = (Elastos::IO::IPipedInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IPipedInputStream);
        if (*__IPipedInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IPipedOutputStream * ipos,
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ Elastos::IO::IPipedInputStream** __IPipedInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipos, pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPipedInputStream = (Elastos::IO::IPipedInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IPipedInputStream);
        if (*__IPipedInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IPipedOutputStream * ipos,
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipos, pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IPipedOutputStream * ipos,
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipos, pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IPipedOutputStream * ipos,
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipos, pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IPipedOutputStream * ipos,
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipos, pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IPipedOutputStream * ipos,
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipos, pipeSize, &__pNewObj);
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
namespace IO {
class CPipedOutputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IPipedInputStream * target,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPipedOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPipedOutputStream, RGM_SAME_DOMAIN,
                EIID_ICPipedOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTarget(target, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ IPipedOutputStream** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedOutputStream, RGM_SAME_DOMAIN, EIID_IPipedOutputStream, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IOutputStream** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedOutputStream, RGM_SAME_DOMAIN, Elastos::IO::EIID_IOutputStream, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ICloseable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedOutputStream, RGM_SAME_DOMAIN, Elastos::IO::EIID_ICloseable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IFlushable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedOutputStream, RGM_SAME_DOMAIN, Elastos::IO::EIID_IFlushable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedOutputStream, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedOutputStream, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedOutputStream, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedInputStream * target,
        /* [out] */ IPipedOutputStream** __IPipedOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(target, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPipedOutputStream = (IPipedOutputStream*)__pNewObj->Probe(EIID_IPipedOutputStream);
        if (*__IPipedOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedInputStream * target,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(target, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedInputStream * target,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(target, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedInputStream * target,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(target, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedInputStream * target,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(target, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedInputStream * target,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(target, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedInputStream * target,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(target, &__pNewObj);
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
namespace IO {
class CPipedReader
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IPipedWriter * ipw,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPipedReaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPipedReader, RGM_SAME_DOMAIN,
                EIID_ICPipedReaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIpw(ipw, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPipedReaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPipedReader, RGM_SAME_DOMAIN,
                EIID_ICPipedReaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPipeSize(pipeSize, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IPipedWriter * ipw,
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPipedReaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPipedReader, RGM_SAME_DOMAIN,
                EIID_ICPipedReaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIpwPipeSize(ipw, pipeSize, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IPipedReader** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedReader, RGM_SAME_DOMAIN, Elastos::IO::EIID_IPipedReader, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IReadable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedReader, RGM_SAME_DOMAIN, Elastos::IO::EIID_IReadable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IReader** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedReader, RGM_SAME_DOMAIN, Elastos::IO::EIID_IReader, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ICloseable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedReader, RGM_SAME_DOMAIN, Elastos::IO::EIID_ICloseable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedReader, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedReader, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedReader, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedWriter * ipw,
        /* [out] */ Elastos::IO::IPipedReader** __IPipedReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipw, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPipedReader = (Elastos::IO::IPipedReader*)__pNewObj->Probe(Elastos::IO::EIID_IPipedReader);
        if (*__IPipedReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedWriter * ipw,
        /* [out] */ Elastos::IO::IReadable** __IReadable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipw, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReadable = (Elastos::IO::IReadable*)__pNewObj->Probe(Elastos::IO::EIID_IReadable);
        if (*__IReadable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedWriter * ipw,
        /* [out] */ Elastos::IO::IReader** __IReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipw, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReader = (Elastos::IO::IReader*)__pNewObj->Probe(Elastos::IO::EIID_IReader);
        if (*__IReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedWriter * ipw,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipw, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedWriter * ipw,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipw, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedWriter * ipw,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipw, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedWriter * ipw,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipw, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ Elastos::IO::IPipedReader** __IPipedReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPipedReader = (Elastos::IO::IPipedReader*)__pNewObj->Probe(Elastos::IO::EIID_IPipedReader);
        if (*__IPipedReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ Elastos::IO::IReadable** __IReadable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReadable = (Elastos::IO::IReadable*)__pNewObj->Probe(Elastos::IO::EIID_IReadable);
        if (*__IReadable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ Elastos::IO::IReader** __IReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReader = (Elastos::IO::IReader*)__pNewObj->Probe(Elastos::IO::EIID_IReader);
        if (*__IReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedWriter * ipw,
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ Elastos::IO::IPipedReader** __IPipedReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipw, pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPipedReader = (Elastos::IO::IPipedReader*)__pNewObj->Probe(Elastos::IO::EIID_IPipedReader);
        if (*__IPipedReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedWriter * ipw,
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ Elastos::IO::IReadable** __IReadable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipw, pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReadable = (Elastos::IO::IReadable*)__pNewObj->Probe(Elastos::IO::EIID_IReadable);
        if (*__IReadable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedWriter * ipw,
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ Elastos::IO::IReader** __IReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipw, pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReader = (Elastos::IO::IReader*)__pNewObj->Probe(Elastos::IO::EIID_IReader);
        if (*__IReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedWriter * ipw,
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipw, pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedWriter * ipw,
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipw, pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedWriter * ipw,
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipw, pipeSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedWriter * ipw,
        /* [in] */ _ELASTOS Int32 pipeSize,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(ipw, pipeSize, &__pNewObj);
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
namespace IO {
class CPipedWriter
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IPipedReader * destination,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPipedWriterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPipedWriter, RGM_SAME_DOMAIN,
                EIID_ICPipedWriterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithDestination(destination, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IPipedWriter** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedWriter, RGM_SAME_DOMAIN, Elastos::IO::EIID_IPipedWriter, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IWriter** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedWriter, RGM_SAME_DOMAIN, Elastos::IO::EIID_IWriter, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::IAppendable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedWriter, RGM_SAME_DOMAIN, Elastos::Core::EIID_IAppendable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ICloseable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedWriter, RGM_SAME_DOMAIN, Elastos::IO::EIID_ICloseable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IFlushable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedWriter, RGM_SAME_DOMAIN, Elastos::IO::EIID_IFlushable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedWriter, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedWriter, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPipedWriter, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedReader * destination,
        /* [out] */ Elastos::IO::IPipedWriter** __IPipedWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(destination, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPipedWriter = (Elastos::IO::IPipedWriter*)__pNewObj->Probe(Elastos::IO::EIID_IPipedWriter);
        if (*__IPipedWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedReader * destination,
        /* [out] */ Elastos::IO::IWriter** __IWriter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(destination, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWriter = (Elastos::IO::IWriter*)__pNewObj->Probe(Elastos::IO::EIID_IWriter);
        if (*__IWriter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedReader * destination,
        /* [out] */ Elastos::Core::IAppendable** __IAppendable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(destination, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAppendable = (Elastos::Core::IAppendable*)__pNewObj->Probe(Elastos::Core::EIID_IAppendable);
        if (*__IAppendable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedReader * destination,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(destination, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedReader * destination,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(destination, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedReader * destination,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(destination, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedReader * destination,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(destination, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPipedReader * destination,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(destination, &__pNewObj);
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
namespace IO {
class CNIOAccess
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::IO::INIOAccess** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNIOAccess, RGM_SAME_DOMAIN, Elastos::IO::EIID_INIOAccess, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNIOAccess, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNIOAccess, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNIOAccess, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace IO {
class CStreamTokenizer
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStreamTokenizerClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStreamTokenizer, RGM_SAME_DOMAIN,
                EIID_ICStreamTokenizerClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIs(is, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IReader * r,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStreamTokenizerClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStreamTokenizer, RGM_SAME_DOMAIN,
                EIID_ICStreamTokenizerClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithR(r, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [out] */ Elastos::IO::IStreamTokenizer** __IStreamTokenizer)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStreamTokenizer = (Elastos::IO::IStreamTokenizer*)__pNewObj->Probe(Elastos::IO::EIID_IStreamTokenizer);
        if (*__IStreamTokenizer) __pNewObj->AddRef();
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
        /* [in] */ Elastos::IO::IReader * r,
        /* [out] */ Elastos::IO::IStreamTokenizer** __IStreamTokenizer)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(r, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStreamTokenizer = (Elastos::IO::IStreamTokenizer*)__pNewObj->Probe(Elastos::IO::EIID_IStreamTokenizer);
        if (*__IStreamTokenizer) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * r,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(r, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * r,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(r, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * r,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(r, &__pNewObj);
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
namespace IO {
class CObjectOutputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IOutputStream * r,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICObjectOutputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CObjectOutputStream, RGM_SAME_DOMAIN,
                EIID_ICObjectOutputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithR(r, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IObjectOutputStream** __object)
    {
        return _CObject_CreateInstance(ECLSID_CObjectOutputStream, RGM_SAME_DOMAIN, Elastos::IO::EIID_IObjectOutputStream, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IOutputStream** __object)
    {
        return _CObject_CreateInstance(ECLSID_CObjectOutputStream, RGM_SAME_DOMAIN, Elastos::IO::EIID_IOutputStream, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ICloseable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CObjectOutputStream, RGM_SAME_DOMAIN, Elastos::IO::EIID_ICloseable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IFlushable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CObjectOutputStream, RGM_SAME_DOMAIN, Elastos::IO::EIID_IFlushable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IObjectOutput** __object)
    {
        return _CObject_CreateInstance(ECLSID_CObjectOutputStream, RGM_SAME_DOMAIN, Elastos::IO::EIID_IObjectOutput, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::IDataOutput** __object)
    {
        return _CObject_CreateInstance(ECLSID_CObjectOutputStream, RGM_SAME_DOMAIN, Elastos::IO::EIID_IDataOutput, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CObjectOutputStream, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CObjectOutputStream, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CObjectOutputStream, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * r,
        /* [out] */ Elastos::IO::IObjectOutputStream** __IObjectOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(r, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObjectOutputStream = (Elastos::IO::IObjectOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IObjectOutputStream);
        if (*__IObjectOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * r,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(r, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * r,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(r, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * r,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(r, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * r,
        /* [out] */ Elastos::IO::IObjectOutput** __IObjectOutput)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(r, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObjectOutput = (Elastos::IO::IObjectOutput*)__pNewObj->Probe(Elastos::IO::EIID_IObjectOutput);
        if (*__IObjectOutput) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * r,
        /* [out] */ Elastos::IO::IDataOutput** __IDataOutput)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(r, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDataOutput = (Elastos::IO::IDataOutput*)__pNewObj->Probe(Elastos::IO::EIID_IDataOutput);
        if (*__IDataOutput) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * r,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(r, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * r,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(r, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IOutputStream * r,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(r, &__pNewObj);
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
namespace IO {
namespace Channels {
class CChannels
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::IO::Channels::IChannels** __object)
    {
        return _CObject_CreateInstance(ECLSID_CChannels, RGM_SAME_DOMAIN, Elastos::IO::Channels::EIID_IChannels, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CChannels, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CChannels, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CChannels, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace IO {
namespace Channels {
namespace Spi {
class CSelectorProviderHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::IO::Channels::Spi::ISelectorProviderHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSelectorProviderHelper, RGM_SAME_DOMAIN, Elastos::IO::Channels::Spi::EIID_ISelectorProviderHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSelectorProviderHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSelectorProviderHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSelectorProviderHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
class CCodingErrorAction
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::Charset::ICodingErrorAction** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCodingErrorAction, RGM_SAME_DOMAIN, Elastos::IO::Charset::EIID_ICodingErrorAction, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCodingErrorAction, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCodingErrorAction, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCodingErrorAction, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
class CCodingErrorActionHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::IO::Charset::ICodingErrorActionHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCodingErrorActionHelper, RGM_SAME_DOMAIN, Elastos::IO::Charset::EIID_ICodingErrorActionHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCodingErrorActionHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCodingErrorActionHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCodingErrorActionHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
class CCharsetHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::IO::Charset::ICharsetHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCharsetHelper, RGM_SAME_DOMAIN, Elastos::IO::Charset::EIID_ICharsetHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCharsetHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCharsetHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCharsetHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
class CCharsets
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::IO::Charset::ICharsets** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCharsets, RGM_SAME_DOMAIN, Elastos::IO::Charset::EIID_ICharsets, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCharsets, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCharsets, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCharsets, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
class CCoderResult
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::Charset::ICoderResult** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCoderResult, RGM_SAME_DOMAIN, Elastos::IO::Charset::EIID_ICoderResult, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCoderResult, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCoderResult, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCoderResult, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
class CCoderResultHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::IO::Charset::ICoderResultHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCoderResultHelper, RGM_SAME_DOMAIN, Elastos::IO::Charset::EIID_ICoderResultHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCoderResultHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCoderResultHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCoderResultHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
class CModifiedUtf8
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::IO::Charset::IModifiedUtf8** __object)
    {
        return _CObject_CreateInstance(ECLSID_CModifiedUtf8, RGM_SAME_DOMAIN, Elastos::IO::Charset::EIID_IModifiedUtf8, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CModifiedUtf8, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CModifiedUtf8, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CModifiedUtf8, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace IO {
namespace Charset {
class CStandardCharsets
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::IO::Charset::IStandardCharsets** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStandardCharsets, RGM_SAME_DOMAIN, Elastos::IO::Charset::EIID_IStandardCharsets, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStandardCharsets, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStandardCharsets, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStandardCharsets, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}

#endif // __Elastos_CoreLibrary_IO_h__
