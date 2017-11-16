#ifndef ___Elastos_CoreLibrary_Sql_h__
#define ___Elastos_CoreLibrary_Sql_h__

#include <Elastos.CoreLibrary.h>

EXTERN_C ELAPI _Impl_AcquireCallbackHandler(PInterface pServerObj, _ELASTOS REIID iid, PInterface *ppHandler);
EXTERN_C ELAPI _Impl_CheckClsId(PInterface pServerObj, const _ELASTOS ClassID* pClassid, PInterface *ppServerObj);

namespace Elastos {
namespace Sql {
CAR_INTERFACE("4AB91345-1C92-3F1B-1C94-9461E307071A")
ITypes : public IInterface
{
    static const _ELASTOS Int32 ARRAY = 2003;
    static const _ELASTOS Int32 BIGINT = -5;
    static const _ELASTOS Int32 BINARY = -2;
    static const _ELASTOS Int32 BIT = -7;
    static const _ELASTOS Int32 BLOB = 2004;
    static const _ELASTOS Int32 BOOLEAN = 16;
    static const _ELASTOS Int32 CHAR = 1;
    static const _ELASTOS Int32 CLOB = 2005;
    static const _ELASTOS Int32 DATALINK = 70;
    static const _ELASTOS Int32 DATE = 91;
    static const _ELASTOS Int32 DECIMAL = 3;
    static const _ELASTOS Int32 DISTINCT = 2001;
    static const _ELASTOS Int32 DOUBLE = 8;
    static const _ELASTOS Int32 FLOAT = 6;
    static const _ELASTOS Int32 INTEGER = 4;
    static const _ELASTOS Int32 JAVA_OBJECT = 2000;
    static const _ELASTOS Int32 LONGVARBINARY = -4;
    static const _ELASTOS Int32 LONGVARCHAR = -1;
    static const _ELASTOS Int32 SQL_NULL = 0;
    static const _ELASTOS Int32 NUMERIC = 2;
    static const _ELASTOS Int32 OTHER = 1111;
    static const _ELASTOS Int32 REAL = 7;
    static const _ELASTOS Int32 REF = 2006;
    static const _ELASTOS Int32 SMALLINT = 5;
    static const _ELASTOS Int32 STRUCT = 2002;
    static const _ELASTOS Int32 TIME = 92;
    static const _ELASTOS Int32 TIMESTAMP = 93;
    static const _ELASTOS Int32 TINYINT = -6;
    static const _ELASTOS Int32 VARBINARY = -3;
    static const _ELASTOS Int32 VARCHAR = 12;
    static const _ELASTOS Int32 ROWID = -8;
    static const _ELASTOS Int32 NCHAR = -15;
    static const _ELASTOS Int32 NVARCHAR = -9;
    static const _ELASTOS Int32 LONGNVARCHAR = -16;
    static const _ELASTOS Int32 NCLOB = 2011;
    static const _ELASTOS Int32 SQLXML = 2009;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITypes*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITypes*)pObj->Probe(EIID_ITypes);
    }

    static CARAPI_(ITypes*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITypes*)pObj->Probe(EIID_ITypes);
    }

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("F6DCAD04-F312-E5CA-EFBC-A47DCBF6CFD1")
IClob : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IClob*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IClob*)pObj->Probe(EIID_IClob);
    }

    static CARAPI_(IClob*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IClob*)pObj->Probe(EIID_IClob);
    }

    virtual CARAPI GetAsciiStream(
        /* [out] */ Elastos::IO::IInputStream ** is) = 0;

    virtual CARAPI GetCharacterStream(
        /* [out] */ Elastos::IO::IReader ** reader) = 0;

    virtual CARAPI GetSubString(
        /* [in] */ _ELASTOS Int64 pos,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int64 * len) = 0;

    virtual CARAPI GetPosition(
        /* [in] */ Elastos::Sql::IClob * searchstr,
        /* [in] */ _ELASTOS Int64 start,
        /* [out] */ _ELASTOS Int64 * position) = 0;

    virtual CARAPI GetPosition(
        /* [in] */ const _ELASTOS String& searchstr,
        /* [in] */ _ELASTOS Int64 start,
        /* [out] */ _ELASTOS Int64 * position) = 0;

    virtual CARAPI SetAsciiStream(
        /* [in] */ _ELASTOS Int64 pos,
        /* [out] */ Elastos::IO::IOutputStream ** os) = 0;

    virtual CARAPI SetCharacterStream(
        /* [in] */ _ELASTOS Int64 pos,
        /* [out] */ Elastos::IO::IWriter ** writer) = 0;

    virtual CARAPI SetString(
        /* [in] */ _ELASTOS Int64 pos,
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI SetString(
        /* [in] */ _ELASTOS Int64 pos,
        /* [in] */ const _ELASTOS String& str,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 len,
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI Truncate(
        /* [in] */ _ELASTOS Int64 len) = 0;

    virtual CARAPI Free() = 0;

    virtual CARAPI GetCharacterStream(
        /* [in] */ _ELASTOS Int64 pos,
        /* [in] */ _ELASTOS Int64 length,
        /* [out] */ Elastos::IO::IReader ** reader) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("7A53820B-F2D2-E5CA-EFBC-A47DCBF6CFD1")
IBlob : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBlob*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBlob*)pObj->Probe(EIID_IBlob);
    }

    static CARAPI_(IBlob*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBlob*)pObj->Probe(EIID_IBlob);
    }

    virtual CARAPI GetBinaryStream(
        /* [out] */ Elastos::IO::IInputStream ** is) = 0;

    virtual CARAPI GetBinaryStream(
        /* [in] */ _ELASTOS Int64 pos,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI GetBytes(
        /* [in] */ _ELASTOS Int64 pos,
        /* [in] */ _ELASTOS Int32 length,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** array) = 0;

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int64 * len) = 0;

    virtual CARAPI GetPosition(
        /* [in] */ Elastos::Sql::IBlob * pattern,
        /* [in] */ _ELASTOS Int64 start,
        /* [out] */ _ELASTOS Int64 * position) = 0;

    virtual CARAPI GetPosition(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * pattern,
        /* [in] */ _ELASTOS Int64 start,
        /* [out] */ _ELASTOS Int64 * position) = 0;

    virtual CARAPI SetBinaryStream(
        /* [in] */ _ELASTOS Int64 pos,
        /* [out] */ Elastos::IO::IOutputStream ** os) = 0;

    virtual CARAPI SetBytes(
        /* [in] */ _ELASTOS Int64 pos,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * theBytes,
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI SetBytes(
        /* [in] */ _ELASTOS Int64 pos,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * theBytes,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 len,
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI Truncate(
        /* [in] */ _ELASTOS Int64 len) = 0;

    virtual CARAPI Free() = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("65E51311-C5D2-72BC-F93B-2F69DFB2FD73")
INClob : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INClob*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INClob*)pObj->Probe(EIID_INClob);
    }

    static CARAPI_(INClob*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INClob*)pObj->Probe(EIID_INClob);
    }

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("7752813E-9612-ED1F-6DDC-9061E307071A")
IArray : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IArray*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IArray*)pObj->Probe(EIID_IArray);
    }

    static CARAPI_(IArray*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IArray*)pObj->Probe(EIID_IArray);
    }

    virtual CARAPI GetArray(
        /* [out] */ IInterface ** arrayiter) = 0;

    virtual CARAPI GetArray(
        /* [in] */ _ELASTOS Int64 index,
        /* [in] */ _ELASTOS Int32 count,
        /* [out] */ IInterface ** arrayiter) = 0;

    virtual CARAPI GetArray(
        /* [in] */ _ELASTOS Int64 index,
        /* [in] */ _ELASTOS Int32 count,
        /* [in] */ Elastos::Utility::IMap * sqlmap,
        /* [out] */ IInterface ** arrayiter) = 0;

    virtual CARAPI GetArray(
        /* [in] */ Elastos::Utility::IMap * sqlmap,
        /* [out] */ IInterface ** arrayiter) = 0;

    virtual CARAPI GetBaseType(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetBaseTypeName(
        /* [out] */ _ELASTOS String * value) = 0;

    virtual CARAPI GetResultSet(
        /* [out] */ Elastos::Sql::IResultSet ** resultset) = 0;

    virtual CARAPI GetResultSet(
        /* [in] */ _ELASTOS Int64 index,
        /* [in] */ _ELASTOS Int32 count,
        /* [out] */ Elastos::Sql::IResultSet ** resultset) = 0;

    virtual CARAPI GetResultSet(
        /* [in] */ _ELASTOS Int64 index,
        /* [in] */ _ELASTOS Int32 count,
        /* [in] */ Elastos::Utility::IMap * sqlmap,
        /* [out] */ Elastos::Sql::IResultSet ** resultset) = 0;

    virtual CARAPI GetResultSet(
        /* [in] */ Elastos::Utility::IMap * sqlmap,
        /* [out] */ Elastos::Sql::IResultSet ** resultset) = 0;

    virtual CARAPI Free() = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("92303C39-EC52-ED1F-6DDC-9061E307071A")
IStruct : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IStruct*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStruct*)pObj->Probe(EIID_IStruct);
    }

    static CARAPI_(IStruct*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStruct*)pObj->Probe(EIID_IStruct);
    }

    virtual CARAPI GetSQLTypeName(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetAttributes(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** interarray) = 0;

    virtual CARAPI GetAttributes(
        /* [in] */ Elastos::Utility::IMap * theMap,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** interarray) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("1C8E1505-A712-0D55-79A3-BFF392F62DDB")
ISQLDate : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISQLDate*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISQLDate*)pObj->Probe(EIID_ISQLDate);
    }

    static CARAPI_(ISQLDate*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISQLDate*)pObj->Probe(EIID_ISQLDate);
    }

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("F099120F-C752-E8C2-EFBC-A47DCBF6CFD1")
ITime : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITime*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITime*)pObj->Probe(EIID_ITime);
    }

    static CARAPI_(ITime*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITime*)pObj->Probe(EIID_ITime);
    }

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("21CD2747-1E52-6812-9FFD-705052868D1F")
IWrapper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IWrapper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IWrapper*)pObj->Probe(EIID_IWrapper);
    }

    static CARAPI_(IWrapper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IWrapper*)pObj->Probe(EIID_IWrapper);
    }

    virtual CARAPI Unwrap(
        /* [in] */ IInterface * iface,
        /* [out] */ IInterface ** oface) = 0;

    virtual CARAPI IsWrapperFor(
        /* [in] */ IInterface * iface,
        /* [out] */ _ELASTOS Boolean * value) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("1BC09F32-55D2-280B-6E90-C0F4A3BD8D1B")
IParameterMetaData : public IInterface
{
    static const _ELASTOS Int32 parameterModeIn = 1;
    static const _ELASTOS Int32 parameterModeInOut = 2;
    static const _ELASTOS Int32 parameterModeOut = 4;
    static const _ELASTOS Int32 parameterModeUnknown = 0;
    static const _ELASTOS Int32 parameterNoNulls = 0;
    static const _ELASTOS Int32 parameterNullable = 1;
    static const _ELASTOS Int32 parameterNullableUnknown = 2;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IParameterMetaData*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IParameterMetaData*)pObj->Probe(EIID_IParameterMetaData);
    }

    static CARAPI_(IParameterMetaData*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IParameterMetaData*)pObj->Probe(EIID_IParameterMetaData);
    }

    virtual CARAPI GetParameterClassName(
        /* [in] */ _ELASTOS Int32 paramIndex,
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetParameterCount(
        /* [out] */ _ELASTOS Int32 * count) = 0;

    virtual CARAPI GetParameterMode(
        /* [in] */ _ELASTOS Int32 paramIndex,
        /* [out] */ _ELASTOS Int32 * mode) = 0;

    virtual CARAPI GetParameterType(
        /* [in] */ _ELASTOS Int32 paramIndex,
        /* [out] */ _ELASTOS Int32 * type) = 0;

    virtual CARAPI GetParameterTypeName(
        /* [in] */ _ELASTOS Int32 paramIndex,
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetPrecision(
        /* [in] */ _ELASTOS Int32 paramIndex,
        /* [out] */ _ELASTOS Int32 * precision) = 0;

    virtual CARAPI GetScale(
        /* [in] */ _ELASTOS Int32 paramIndex,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI IsNullable(
        /* [in] */ _ELASTOS Int32 paramIndex,
        /* [out] */ _ELASTOS Int32 * isNullability) = 0;

    virtual CARAPI IsSigned(
        /* [in] */ _ELASTOS Int32 paramIndex,
        /* [out] */ _ELASTOS Boolean * isSigned) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("76931B19-26D2-D2EB-F93B-2F69DFB2FD73")
IRowId : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRowId*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRowId*)pObj->Probe(EIID_IRowId);
    }

    static CARAPI_(IRowId*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRowId*)pObj->Probe(EIID_IRowId);
    }

    virtual CARAPI GetBytes(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** array) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("0A323B3A-F112-241B-60CC-F8D1DEC60D19")
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

    virtual CARAPI After(
        /* [in] */ Elastos::Sql::ITimestamp * theTimestamp,
        /* [out] */ _ELASTOS Boolean * isAfter) = 0;

    virtual CARAPI Before(
        /* [in] */ Elastos::Sql::ITimestamp * theTimestamp,
        /* [out] */ _ELASTOS Boolean * isBefore) = 0;

    virtual CARAPI CompareTo(
        /* [in] */ Elastos::Sql::ITimestamp * theTimestamp,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetNanos(
        /* [out] */ _ELASTOS Int32 * nano) = 0;

    virtual CARAPI SetNanos(
        /* [in] */ _ELASTOS Int32 n) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("605D3B05-86D2-BFA6-F392-F62DDB3F47BF")
IRef : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRef*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRef*)pObj->Probe(EIID_IRef);
    }

    static CARAPI_(IRef*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRef*)pObj->Probe(EIID_IRef);
    }

    virtual CARAPI GetBaseTypeName(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetObject(
        /* [out] */ IInterface ** inter) = 0;

    virtual CARAPI GetObject(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ IInterface ** inter) = 0;

    virtual CARAPI SetObject(
        /* [in] */ IInterface * value) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("676A3F32-0712-150D-62FF-686FE3860C1B")
ISQLStruct : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISQLStruct*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISQLStruct*)pObj->Probe(EIID_ISQLStruct);
    }

    static CARAPI_(ISQLStruct*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISQLStruct*)pObj->Probe(EIID_ISQLStruct);
    }

    virtual CARAPI GetSQLTypeName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetAttributes(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** array) = 0;

    virtual CARAPI GetAttributes(
        /* [in] */ Elastos::Utility::IMap * theMap,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** intface) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("68817E18-A712-A155-55FD-CE4BDAB76CFF")
ISQLXML : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISQLXML*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISQLXML*)pObj->Probe(EIID_ISQLXML);
    }

    static CARAPI_(ISQLXML*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISQLXML*)pObj->Probe(EIID_ISQLXML);
    }

    virtual CARAPI Free() = 0;

    virtual CARAPI GetBinaryStream(
        /* [out] */ Elastos::IO::IInputStream ** is) = 0;

    virtual CARAPI SetBinaryStream(
        /* [out] */ Elastos::IO::IOutputStream ** os) = 0;

    virtual CARAPI GetCharacterStream(
        /* [out] */ Elastos::IO::IReader ** reader) = 0;

    virtual CARAPI SetCharacterStream(
        /* [out] */ Elastos::IO::IWriter ** writer) = 0;

    virtual CARAPI GetString(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI SetString(
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI GetSource(
        /* [in] */ IInterface * sourceClass,
        /* [out] */ IInterface ** oface) = 0;

    virtual CARAPI SetResult(
        /* [in] */ IInterface * resultClass,
        /* [out] */ IInterface ** oface) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("FD5FFC29-0712-150D-FEFD-686FE3860C1B")
ISQLInput : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISQLInput*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISQLInput*)pObj->Probe(EIID_ISQLInput);
    }

    static CARAPI_(ISQLInput*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISQLInput*)pObj->Probe(EIID_ISQLInput);
    }

    virtual CARAPI ReadString(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI ReadBoolean(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI ReadByte(
        /* [out] */ _ELASTOS Byte * value) = 0;

    virtual CARAPI ReadShort(
        /* [out] */ _ELASTOS Int16 * value) = 0;

    virtual CARAPI ReadInt(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI ReadLong(
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI ReadFloat(
        /* [out] */ _ELASTOS Float * value) = 0;

    virtual CARAPI ReadDouble(
        /* [out] */ _ELASTOS Double * value) = 0;

    virtual CARAPI ReadBigDecimal(
        /* [out] */ Elastos::Math::IBigDecimal ** bigDecimal) = 0;

    virtual CARAPI ReadBytes(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** array) = 0;

    virtual CARAPI ReadDate(
        /* [out] */ Elastos::Sql::ISQLDate ** date) = 0;

    virtual CARAPI ReadTime(
        /* [out] */ Elastos::Sql::ITime ** ti) = 0;

    virtual CARAPI ReadTimestamp(
        /* [out] */ Elastos::Sql::ITimestamp ** timestamp) = 0;

    virtual CARAPI ReadCharacterStream(
        /* [out] */ Elastos::IO::IReader ** reader) = 0;

    virtual CARAPI ReadAsciiStream(
        /* [out] */ Elastos::IO::IInputStream ** is) = 0;

    virtual CARAPI ReadBinaryStream(
        /* [out] */ Elastos::IO::IInputStream ** is) = 0;

    virtual CARAPI ReadObject(
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI ReadRef(
        /* [out] */ Elastos::Sql::IRef ** ref) = 0;

    virtual CARAPI ReadBlob(
        /* [out] */ Elastos::Sql::IBlob ** blob) = 0;

    virtual CARAPI ReadClob(
        /* [out] */ Elastos::Sql::IClob ** clob) = 0;

    virtual CARAPI ReadArray(
        /* [out] */ Elastos::Sql::IArray ** array) = 0;

    virtual CARAPI WasNull(
        /* [out] */ _ELASTOS Boolean * wasNull) = 0;

    virtual CARAPI ReadURL(
        /* [out] */ Elastos::Net::IURL ** url) = 0;

    virtual CARAPI ReadNClob(
        /* [out] */ Elastos::Sql::INClob ** nclob) = 0;

    virtual CARAPI ReadNString(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI ReadSQLXML(
        /* [out] */ Elastos::Sql::ISQLXML ** sqlxml) = 0;

    virtual CARAPI ReadRowId(
        /* [out] */ Elastos::Sql::IRowId ** rowid) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("D587FA30-0712-150D-A4FE-686FE3860C1B")
ISQLOutput : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISQLOutput*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISQLOutput*)pObj->Probe(EIID_ISQLOutput);
    }

    static CARAPI_(ISQLOutput*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISQLOutput*)pObj->Probe(EIID_ISQLOutput);
    }

    virtual CARAPI WriteString(
        /* [in] */ const _ELASTOS String& theString) = 0;

    virtual CARAPI WriteBoolean(
        /* [in] */ _ELASTOS Boolean theFlag) = 0;

    virtual CARAPI WriteByte(
        /* [in] */ _ELASTOS Byte theByte) = 0;

    virtual CARAPI WriteShort(
        /* [in] */ _ELASTOS Int16 theShort) = 0;

    virtual CARAPI WriteInt(
        /* [in] */ _ELASTOS Int32 theInt) = 0;

    virtual CARAPI WriteLong(
        /* [in] */ _ELASTOS Int64 theLong) = 0;

    virtual CARAPI WriteFloat(
        /* [in] */ _ELASTOS Float theFloat) = 0;

    virtual CARAPI WriteDouble(
        /* [in] */ _ELASTOS Double theDouble) = 0;

    virtual CARAPI WriteBigDecimal(
        /* [in] */ Elastos::Math::IBigDecimal * theBigDecimal) = 0;

    virtual CARAPI WriteBytes(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & theBytes) = 0;

    virtual CARAPI WriteDate(
        /* [in] */ Elastos::Sql::ISQLDate * theDate) = 0;

    virtual CARAPI WriteTime(
        /* [in] */ Elastos::Sql::ITime * theTime) = 0;

    virtual CARAPI WriteTimestamp(
        /* [in] */ Elastos::Sql::ITimestamp * theTimestamp) = 0;

    virtual CARAPI WriteCharacterStream(
        /* [in] */ Elastos::IO::IReader * theStream) = 0;

    virtual CARAPI WriteAsciiStream(
        /* [in] */ Elastos::IO::IInputStream * theStream) = 0;

    virtual CARAPI WriteBinaryStream(
        /* [in] */ Elastos::IO::IInputStream * theStream) = 0;

    virtual CARAPI WriteObject(
        /* [in] */ Elastos::Sql::ISQLData * theObject) = 0;

    virtual CARAPI WriteRef(
        /* [in] */ Elastos::Sql::IRef * theRef) = 0;

    virtual CARAPI WriteBlob(
        /* [in] */ Elastos::Sql::IBlob * theBlob) = 0;

    virtual CARAPI WriteClob(
        /* [in] */ Elastos::Sql::IClob * theClob) = 0;

    virtual CARAPI WriteStruct(
        /* [in] */ Elastos::Sql::ISQLStruct * theStruct) = 0;

    virtual CARAPI WriteArray(
        /* [in] */ Elastos::Sql::IArray * theArray) = 0;

    virtual CARAPI WriteURL(
        /* [in] */ Elastos::Net::IURL * theURL) = 0;

    virtual CARAPI WriteNString(
        /* [in] */ const _ELASTOS String& theString) = 0;

    virtual CARAPI WriteNClob(
        /* [in] */ Elastos::Sql::INClob * theNClob) = 0;

    virtual CARAPI WriteRowId(
        /* [in] */ Elastos::Sql::IRowId * theRowId) = 0;

    virtual CARAPI WwriteSQLXML(
        /* [in] */ Elastos::Sql::ISQLXML * theXml) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("E48A310B-A712-0D55-7993-BFF392F62DDB")
ISQLData : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISQLData*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISQLData*)pObj->Probe(EIID_ISQLData);
    }

    static CARAPI_(ISQLData*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISQLData*)pObj->Probe(EIID_ISQLData);
    }

    virtual CARAPI GtSQLTypeName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI ReadSQL(
        /* [in] */ Elastos::Sql::ISQLInput * stream,
        /* [in] */ const _ELASTOS String& typeName) = 0;

    virtual CARAPI WriteSQL(
        /* [in] */ Elastos::Sql::ISQLOutput * stream) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("574DFC38-EAD2-3FF7-DADB-B821C3C60F0E")
IStatement : public IInterface
{
    static const _ELASTOS Int32 CLOSE_ALL_RESULTS = 3;
    static const _ELASTOS Int32 CLOSE_CURRENT_RESULT = 1;
    static const _ELASTOS Int32 EXECUTE_FAILED = -3;
    static const _ELASTOS Int32 KEEP_CURRENT_RESULT = 2;
    static const _ELASTOS Int32 NO_GENERATED_KEYS = 2;
    static const _ELASTOS Int32 RETURN_GENERATED_KEYS = 1;
    static const _ELASTOS Int32 SUCCESS_NO_INFO = -2;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IStatement*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStatement*)pObj->Probe(EIID_IStatement);
    }

    static CARAPI_(IStatement*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStatement*)pObj->Probe(EIID_IStatement);
    }

    virtual CARAPI AddBatch(
        /* [in] */ const _ELASTOS String& sql) = 0;

    virtual CARAPI Cancel() = 0;

    virtual CARAPI ClearBatch() = 0;

    virtual CARAPI ClearWarnings() = 0;

    virtual CARAPI Close() = 0;

    virtual CARAPI Execute(
        /* [in] */ const _ELASTOS String& sql,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Execute(
        /* [in] */ const _ELASTOS String& sql,
        /* [in] */ _ELASTOS Int32 autoGeneratedKeys,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Execute(
        /* [in] */ const _ELASTOS String& sql,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * columnIndexes,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Execute(
        /* [in] */ const _ELASTOS String& sql,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * columnNames,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI ExecuteBatch(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Int32> ** value) = 0;

    virtual CARAPI ExecuteQuery(
        /* [in] */ const _ELASTOS String& sql,
        /* [out] */ Elastos::Sql::IResultSet ** resultset) = 0;

    virtual CARAPI ExecuteUpdate(
        /* [in] */ const _ELASTOS String& sql,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI ExecuteUpdate(
        /* [in] */ const _ELASTOS String& sql,
        /* [in] */ _ELASTOS Int32 autoGeneratedKeys,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI ExecuteUpdate(
        /* [in] */ const _ELASTOS String& sql,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * columnIndexes,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI ExecuteUpdate(
        /* [in] */ const _ELASTOS String& sql,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * columnNames,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetConnection(
        /* [out] */ Elastos::Sql::IConnection ** conn) = 0;

    virtual CARAPI GetFetchDirection(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetFetchSize(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetGeneratedKeys(
        /* [out] */ Elastos::Sql::IResultSet ** resultset) = 0;

    virtual CARAPI GetMaxFieldSize(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetMaxRows(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetMoreResults(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetMoreResults(
        /* [in] */ _ELASTOS Int32 current,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetQueryTimeout(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetResultSet(
        /* [out] */ Elastos::Sql::IResultSet ** resultset) = 0;

    virtual CARAPI GetResultSetConcurrency(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetResultSetHoldability(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetResultSetType(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetUpdateCount(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetWarnings(
        /* [out] */ Elastos::Sql::ISQLWarning ** sqlwarn) = 0;

    virtual CARAPI SetCursorName(
        /* [in] */ const _ELASTOS String& name) = 0;

    virtual CARAPI SetEscapeProcessing(
        /* [in] */ _ELASTOS Boolean isable) = 0;

    virtual CARAPI SetFetchDirection(
        /* [in] */ _ELASTOS Int32 direction) = 0;

    virtual CARAPI SetFetchSize(
        /* [in] */ _ELASTOS Int32 rows) = 0;

    virtual CARAPI SetMaxFieldSize(
        /* [in] */ _ELASTOS Int32 max) = 0;

    virtual CARAPI SetMaxRows(
        /* [in] */ _ELASTOS Int32 max) = 0;

    virtual CARAPI SetQueryTimeout(
        /* [in] */ _ELASTOS Int32 seconds) = 0;

    virtual CARAPI IsClosed(
        /* [out] */ _ELASTOS Boolean * closed) = 0;

    virtual CARAPI SetPoolable(
        /* [in] */ _ELASTOS Boolean poolable) = 0;

    virtual CARAPI IsPoolable(
        /* [out] */ _ELASTOS Boolean * poolable) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("46C9343A-0712-150D-C8D7-FFD1DEC60D19")
ISQLWarning : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISQLWarning*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISQLWarning*)pObj->Probe(EIID_ISQLWarning);
    }

    static CARAPI_(ISQLWarning*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISQLWarning*)pObj->Probe(EIID_ISQLWarning);
    }

    virtual CARAPI GetNextWarning(
        /* [out] */ Elastos::Sql::ISQLWarning ** sqlwar) = 0;

    virtual CARAPI SetNextWarning(
        /* [in] */ Elastos::Sql::ISQLWarning * w) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("98E6EF3E-61D2-16CD-50DC-2081E9477B1B")
IResultSetMetaData : public IInterface
{
    static const _ELASTOS Int32 columnNoNulls = 0;
    static const _ELASTOS Int32 columnNullable = 1;
    static const _ELASTOS Int32 columnNullableUnknown = 2;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IResultSetMetaData*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IResultSetMetaData*)pObj->Probe(EIID_IResultSetMetaData);
    }

    static CARAPI_(IResultSetMetaData*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IResultSetMetaData*)pObj->Probe(EIID_IResultSetMetaData);
    }

    virtual CARAPI GetCatalogName(
        /* [in] */ _ELASTOS Int32 column,
        /* [out] */ _ELASTOS String * title) = 0;

    virtual CARAPI GetColumnClassName(
        /* [in] */ _ELASTOS Int32 column,
        /* [out] */ _ELASTOS String * classname) = 0;

    virtual CARAPI GetColumnCount(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetColumnDisplaySize(
        /* [in] */ _ELASTOS Int32 column,
        /* [out] */ _ELASTOS Int32 * width) = 0;

    virtual CARAPI GetColumnLabel(
        /* [in] */ _ELASTOS Int32 column,
        /* [out] */ _ELASTOS String * title) = 0;

    virtual CARAPI GetColumnName(
        /* [in] */ _ELASTOS Int32 column,
        /* [out] */ _ELASTOS String * title) = 0;

    virtual CARAPI GetColumnType(
        /* [in] */ _ELASTOS Int32 column,
        /* [out] */ _ELASTOS Int32 * type) = 0;

    virtual CARAPI GetColumnTypeName(
        /* [in] */ _ELASTOS Int32 column,
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetPrecision(
        /* [in] */ _ELASTOS Int32 column,
        /* [out] */ _ELASTOS Int32 * precision) = 0;

    virtual CARAPI GetScale(
        /* [in] */ _ELASTOS Int32 column,
        /* [out] */ _ELASTOS Int32 * scale) = 0;

    virtual CARAPI GetSchemaName(
        /* [in] */ _ELASTOS Int32 column,
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetTableName(
        /* [in] */ _ELASTOS Int32 column,
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI IsAutoIncrement(
        /* [in] */ _ELASTOS Int32 column,
        /* [out] */ _ELASTOS Boolean * isAutoIncrement) = 0;

    virtual CARAPI IsCaseSensitive(
        /* [in] */ _ELASTOS Int32 column,
        /* [out] */ _ELASTOS Boolean * isCaseSensitive) = 0;

    virtual CARAPI IsCurrency(
        /* [in] */ _ELASTOS Int32 column,
        /* [out] */ _ELASTOS Boolean * isCurrency) = 0;

    virtual CARAPI IsDefinitelyWritable(
        /* [in] */ _ELASTOS Int32 column,
        /* [out] */ _ELASTOS Boolean * idDefinitely) = 0;

    virtual CARAPI IsNullable(
        /* [in] */ _ELASTOS Int32 column,
        /* [out] */ _ELASTOS Int32 * isNull) = 0;

    virtual CARAPI IsReadOnly(
        /* [in] */ _ELASTOS Int32 column,
        /* [out] */ _ELASTOS Boolean * isReadOnly) = 0;

    virtual CARAPI IsSearchable(
        /* [in] */ _ELASTOS Int32 column,
        /* [out] */ _ELASTOS Boolean * isSearch) = 0;

    virtual CARAPI IsSigned(
        /* [in] */ _ELASTOS Int32 column,
        /* [out] */ _ELASTOS Boolean * isSigned) = 0;

    virtual CARAPI IsWritable(
        /* [in] */ _ELASTOS Int32 column,
        /* [out] */ _ELASTOS Boolean * isWritable) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("A763FC38-61D2-3FCD-DADB-B821C3C60F0E")
IResultSet : public IInterface
{
    static const _ELASTOS Int32 CLOSE_CURSORS_AT_COMMIT = 2;
    static const _ELASTOS Int32 HOLD_CURSORS_OVER_COMMIT = 1;
    static const _ELASTOS Int32 CONCUR_READ_ONLY = 1007;
    static const _ELASTOS Int32 CONCUR_UPDATABLE = 1008;
    static const _ELASTOS Int32 FETCH_FORWARD = 1000;
    static const _ELASTOS Int32 FETCH_REVERSE = 1001;
    static const _ELASTOS Int32 FETCH_UNKNOWN = 1002;
    static const _ELASTOS Int32 TYPE_FORWARD_ONLY = 1003;
    static const _ELASTOS Int32 TYPE_SCROLL_INSENSITIVE = 1004;
    static const _ELASTOS Int32 TYPE_SCROLL_SENSITIVE = 1005;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IResultSet*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IResultSet*)pObj->Probe(EIID_IResultSet);
    }

    static CARAPI_(IResultSet*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IResultSet*)pObj->Probe(EIID_IResultSet);
    }

    virtual CARAPI Absolute(
        /* [in] */ _ELASTOS Int32 row,
        /* [out] */ _ELASTOS Boolean * isAbsolute) = 0;

    virtual CARAPI AfterLast() = 0;

    virtual CARAPI BeforeFirst() = 0;

    virtual CARAPI CancelRowUpdates() = 0;

    virtual CARAPI ClearWarnings() = 0;

    virtual CARAPI Close() = 0;

    virtual CARAPI DeleteRow() = 0;

    virtual CARAPI FindColumn(
        /* [in] */ const _ELASTOS String& columnName) = 0;

    virtual CARAPI GetFirst(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetArray(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ Elastos::Sql::IArray ** iarray) = 0;

    virtual CARAPI GetArray(
        /* [in] */ const _ELASTOS String& colName,
        /* [out] */ Elastos::Sql::IArray ** iarray) = 0;

    virtual CARAPI GetAsciiStream(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ Elastos::IO::IInputStream ** is) = 0;

    virtual CARAPI GetAsciiStream(
        /* [in] */ const _ELASTOS String& columnName,
        /* [out] */ Elastos::IO::IInputStream ** is) = 0;

    virtual CARAPI GetBigDecimal(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ Elastos::Math::IBigDecimal ** bigDecimal) = 0;

    virtual CARAPI GetBigDecimal(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ Elastos::Math::IBigDecimal ** bigDecimal) = 0;

    virtual CARAPI GetBigDecimal(
        /* [in] */ const _ELASTOS String& columnName,
        /* [out] */ Elastos::Math::IBigDecimal ** bigDecimal) = 0;

    virtual CARAPI GetBigDecimal(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ Elastos::Math::IBigDecimal ** bigDecimal) = 0;

    virtual CARAPI GetBinaryStream(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ Elastos::IO::IInputStream ** is) = 0;

    virtual CARAPI GetBinaryStream(
        /* [in] */ const _ELASTOS String& columnName,
        /* [out] */ Elastos::IO::IInputStream ** is) = 0;

    virtual CARAPI GetBlob(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ Elastos::Sql::IBlob ** blob) = 0;

    virtual CARAPI GetBlob(
        /* [in] */ const _ELASTOS String& columnName,
        /* [out] */ Elastos::Sql::IBlob ** blob) = 0;

    virtual CARAPI GetBoolean(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetBoolean(
        /* [in] */ const _ELASTOS String& columnName,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetByte(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ _ELASTOS Byte * value) = 0;

    virtual CARAPI GetByte(
        /* [in] */ const _ELASTOS String& columnName,
        /* [out] */ _ELASTOS Byte * value) = 0;

    virtual CARAPI GetBytes(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** value) = 0;

    virtual CARAPI GetBytes(
        /* [in] */ const _ELASTOS String& columnName,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** value) = 0;

    virtual CARAPI GetCharacterStream(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ Elastos::IO::IReader ** reader) = 0;

    virtual CARAPI GetCharacterStream(
        /* [in] */ const _ELASTOS String& columnName,
        /* [out] */ Elastos::IO::IReader ** reader) = 0;

    virtual CARAPI GetClob(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ Elastos::Sql::IClob ** clob) = 0;

    virtual CARAPI GetClob(
        /* [in] */ const _ELASTOS String& colName,
        /* [out] */ Elastos::Sql::IClob ** clob) = 0;

    virtual CARAPI GetConcurrency(
        /* [out] */ _ELASTOS Int32 * mode) = 0;

    virtual CARAPI GetCursorName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetDate(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ Elastos::Sql::ISQLDate ** idate) = 0;

    virtual CARAPI GetDate(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::Utility::ICalendar * cal,
        /* [out] */ Elastos::Sql::ISQLDate ** idate) = 0;

    virtual CARAPI GetDate(
        /* [in] */ const _ELASTOS String& columnName,
        /* [out] */ Elastos::Sql::ISQLDate ** idate) = 0;

    virtual CARAPI GetDate(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ Elastos::Utility::ICalendar * cal,
        /* [out] */ Elastos::Sql::ISQLDate ** idate) = 0;

    virtual CARAPI GetDouble(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ _ELASTOS Double * value) = 0;

    virtual CARAPI GetDouble(
        /* [in] */ const _ELASTOS String& columnName,
        /* [out] */ _ELASTOS Double * value) = 0;

    virtual CARAPI GetFetchDirection(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetFetchSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetFloat(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ _ELASTOS Float * value) = 0;

    virtual CARAPI GetFloat(
        /* [in] */ const _ELASTOS String& columnName,
        /* [out] */ _ELASTOS Float * value) = 0;

    virtual CARAPI GetInt32(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetInt32(
        /* [in] */ const _ELASTOS String& columnName,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetInt64(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI GetInt64(
        /* [in] */ const _ELASTOS String& columnName,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI GetMetaData(
        /* [out] */ Elastos::Sql::IResultSetMetaData ** metaData) = 0;

    virtual CARAPI GetObject(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI GetObject(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI GetObject(
        /* [in] */ const _ELASTOS String& columnName,
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI GetObject(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI GetRef(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ Elastos::Sql::IRef ** ref) = 0;

    virtual CARAPI GetRef(
        /* [in] */ const _ELASTOS String& colName,
        /* [out] */ Elastos::Sql::IRef ** ref) = 0;

    virtual CARAPI GetRow(
        /* [out] */ _ELASTOS Int32 * row) = 0;

    virtual CARAPI GetInt16(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ _ELASTOS Int16 * value) = 0;

    virtual CARAPI GetInt16(
        /* [in] */ const _ELASTOS String& columnName,
        /* [out] */ _ELASTOS Int16 * value) = 0;

    virtual CARAPI GetStatement(
        /* [out] */ Elastos::Sql::IStatement ** statement) = 0;

    virtual CARAPI GetString(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ _ELASTOS String * value) = 0;

    virtual CARAPI GetString(
        /* [in] */ const _ELASTOS String& columnName,
        /* [out] */ _ELASTOS String * value) = 0;

    virtual CARAPI GetTime(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ Elastos::Sql::ITime ** ti) = 0;

    virtual CARAPI GetTime(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::Utility::ICalendar * cal,
        /* [out] */ Elastos::Sql::ITime ** ti) = 0;

    virtual CARAPI GetTime(
        /* [in] */ const _ELASTOS String& columnName,
        /* [out] */ Elastos::Sql::ITime ** ti) = 0;

    virtual CARAPI GetTime(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ Elastos::Utility::ICalendar * cal,
        /* [out] */ Elastos::Sql::ITime ** ti) = 0;

    virtual CARAPI GetTimestamp(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ Elastos::Sql::ITimestamp ** timestamp) = 0;

    virtual CARAPI GetTimestamp(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::Utility::ICalendar * cal,
        /* [out] */ Elastos::Sql::ITimestamp ** timestamp) = 0;

    virtual CARAPI GetTimestamp(
        /* [in] */ const _ELASTOS String& columnName,
        /* [out] */ Elastos::Sql::ITimestamp ** timestamp) = 0;

    virtual CARAPI GetTimestamp(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ Elastos::Utility::ICalendar * cal,
        /* [out] */ Elastos::Sql::ITimestamp ** timestamp) = 0;

    virtual CARAPI GetType(
        /* [out] */ _ELASTOS Int32 * type) = 0;

    virtual CARAPI GetUnicodeStream(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ Elastos::IO::IInputStream ** is) = 0;

    virtual CARAPI GetUnicodeStream(
        /* [in] */ const _ELASTOS String& columnName,
        /* [out] */ Elastos::IO::IInputStream ** is) = 0;

    virtual CARAPI GetURL(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ Elastos::Net::IURL ** url) = 0;

    virtual CARAPI GetURL(
        /* [in] */ const _ELASTOS String& columnName,
        /* [out] */ Elastos::Net::IURL ** url) = 0;

    virtual CARAPI GetWarnings(
        /* [out] */ Elastos::Sql::ISQLWarning ** warning) = 0;

    virtual CARAPI InsertRow() = 0;

    virtual CARAPI IsAfterLast(
        /* [out] */ _ELASTOS Boolean * isAfterLast) = 0;

    virtual CARAPI IsBeforeFirst(
        /* [out] */ _ELASTOS Boolean * isBeforeFirst) = 0;

    virtual CARAPI IsFirst(
        /* [out] */ _ELASTOS Boolean * ifFirst) = 0;

    virtual CARAPI IsLast(
        /* [out] */ _ELASTOS Boolean * isLast) = 0;

    virtual CARAPI GetLast(
        /* [out] */ _ELASTOS Boolean * last) = 0;

    virtual CARAPI MoveToCurrentRow() = 0;

    virtual CARAPI MoveToInsertRow() = 0;

    virtual CARAPI GetNext(
        /* [out] */ _ELASTOS Boolean * isValid) = 0;

    virtual CARAPI GetPrevious(
        /* [out] */ _ELASTOS Boolean * isValid) = 0;

    virtual CARAPI RefreshRow() = 0;

    virtual CARAPI Relative(
        /* [in] */ _ELASTOS Int32 rows,
        /* [out] */ _ELASTOS Boolean * isValid) = 0;

    virtual CARAPI RowDeleted(
        /* [out] */ _ELASTOS Boolean * isDeleted) = 0;

    virtual CARAPI RowInserted(
        /* [out] */ _ELASTOS Boolean * isInserted) = 0;

    virtual CARAPI RowUpdated(
        /* [out] */ _ELASTOS Boolean * isUpdate) = 0;

    virtual CARAPI SetFetchDirection(
        /* [in] */ _ELASTOS Int32 direction) = 0;

    virtual CARAPI SetFetchSize(
        /* [in] */ _ELASTOS Int32 rows) = 0;

    virtual CARAPI UpdateArray(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::Sql::IArray * x) = 0;

    virtual CARAPI UpdateArray(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ Elastos::Sql::IArray * x) = 0;

    virtual CARAPI UpdateAsciiStream(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::IO::IInputStream * x,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI UpdateAsciiStream(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ Elastos::IO::IInputStream * x,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI UpdateBigDecimal(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::Math::IBigDecimal * x) = 0;

    virtual CARAPI UpdateBigDecimal(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ Elastos::Math::IBigDecimal * x) = 0;

    virtual CARAPI UpdateBinaryStream(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::IO::IInputStream * x,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI UpdateBinaryStream(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ Elastos::IO::IInputStream * x,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI UpdateBlob(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::Sql::IBlob * x) = 0;

    virtual CARAPI UpdateBlob(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ Elastos::Sql::IBlob * x) = 0;

    virtual CARAPI UpdateBoolean(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ _ELASTOS Boolean x) = 0;

    virtual CARAPI UpdateBoolean(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ _ELASTOS Boolean x) = 0;

    virtual CARAPI UpdateByte(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ _ELASTOS Byte x) = 0;

    virtual CARAPI UpdateByte(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ _ELASTOS Byte x) = 0;

    virtual CARAPI UpdateBytes(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & x) = 0;

    virtual CARAPI UpdateBytes(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & x) = 0;

    virtual CARAPI UpdateCharacterStream(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::IO::IReader * x,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI UpdateCharacterStream(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI UpdateClob(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::Sql::IClob * x) = 0;

    virtual CARAPI UpdateClob(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ Elastos::Sql::IClob * x) = 0;

    virtual CARAPI UpdateDate(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::Sql::ISQLDate * x) = 0;

    virtual CARAPI UpdateDate(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ Elastos::Sql::ISQLDate * x) = 0;

    virtual CARAPI UpdateDouble(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ _ELASTOS Double x) = 0;

    virtual CARAPI UpdateDouble(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ _ELASTOS Double x) = 0;

    virtual CARAPI UpdateFloat(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ _ELASTOS Float x) = 0;

    virtual CARAPI UpdateFloat(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ _ELASTOS Float x) = 0;

    virtual CARAPI UpdateInt(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ _ELASTOS Int32 x) = 0;

    virtual CARAPI UpdateInt(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ _ELASTOS Int32 x) = 0;

    virtual CARAPI UpdateLong(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ _ELASTOS Int64 x) = 0;

    virtual CARAPI UpdateLong(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ _ELASTOS Int64 x) = 0;

    virtual CARAPI UpdateNull(
        /* [in] */ _ELASTOS Int32 columnIndex) = 0;

    virtual CARAPI UpdateNull(
        /* [in] */ const _ELASTOS String& columnName) = 0;

    virtual CARAPI UpdateObject(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ IInterface * x) = 0;

    virtual CARAPI UpdateObject(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ IInterface * x,
        /* [in] */ _ELASTOS Int32 scale) = 0;

    virtual CARAPI UpdateObject(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ IInterface * x) = 0;

    virtual CARAPI UpdateObject(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ IInterface * x,
        /* [in] */ _ELASTOS Int32 scale) = 0;

    virtual CARAPI UpdateRef(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::Sql::IRef * x) = 0;

    virtual CARAPI UpdateRef(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ Elastos::Sql::IRef * x) = 0;

    virtual CARAPI UpdateRow() = 0;

    virtual CARAPI UpdateShort(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ _ELASTOS Int16 x) = 0;

    virtual CARAPI UpdateShort(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ _ELASTOS Int16 x) = 0;

    virtual CARAPI UpdateString(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ const _ELASTOS String& x) = 0;

    virtual CARAPI UpdateString(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ const _ELASTOS String& x) = 0;

    virtual CARAPI UpdateTime(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::Sql::ITime * x) = 0;

    virtual CARAPI UpdateTime(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ Elastos::Sql::ITime * x) = 0;

    virtual CARAPI UpdateTimestamp(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::Sql::ITimestamp * x) = 0;

    virtual CARAPI UpdateTimestamp(
        /* [in] */ const _ELASTOS String& columnName,
        /* [in] */ Elastos::Sql::ITimestamp * x) = 0;

    virtual CARAPI WasNull(
        /* [out] */ _ELASTOS Boolean * isNull) = 0;

    virtual CARAPI GetRowId(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ Elastos::Sql::IRowId ** id) = 0;

    virtual CARAPI GetRowId(
        /* [in] */ const _ELASTOS String& columnLabel,
        /* [out] */ Elastos::Sql::IRowId ** id) = 0;

    virtual CARAPI UpdateRowId(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::Sql::IRowId * value) = 0;

    virtual CARAPI UpdateRowId(
        /* [in] */ const _ELASTOS String& columnLabel,
        /* [in] */ Elastos::Sql::IRowId * value) = 0;

    virtual CARAPI GetHoldability(
        /* [out] */ _ELASTOS Int32 * holdability) = 0;

    virtual CARAPI IsClosed(
        /* [out] */ _ELASTOS Boolean * isClosed) = 0;

    virtual CARAPI UpdateNString(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ const _ELASTOS String& nString) = 0;

    virtual CARAPI UpdateNString(
        /* [in] */ const _ELASTOS String& columnLabel,
        /* [in] */ const _ELASTOS String& nString) = 0;

    virtual CARAPI UpdateNClob(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::Sql::INClob * nClob) = 0;

    virtual CARAPI UpdateNClob(
        /* [in] */ const _ELASTOS String& columnLabel,
        /* [in] */ Elastos::Sql::INClob * nClob) = 0;

    virtual CARAPI GetNClob(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ Elastos::Sql::INClob ** nClob) = 0;

    virtual CARAPI GetNClob(
        /* [in] */ const _ELASTOS String& columnLabel,
        /* [out] */ Elastos::Sql::INClob ** nClob) = 0;

    virtual CARAPI GetSQLXML(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ Elastos::Sql::ISQLXML ** sqlxml) = 0;

    virtual CARAPI GetSQLXML(
        /* [in] */ const _ELASTOS String& columnLabel,
        /* [out] */ Elastos::Sql::ISQLXML ** sqlxml) = 0;

    virtual CARAPI UpdateSQLXML(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::Sql::ISQLXML * xmlObject) = 0;

    virtual CARAPI UpdateSQLXML(
        /* [in] */ const _ELASTOS String& columnLabel,
        /* [in] */ Elastos::Sql::ISQLXML * xmlObject) = 0;

    virtual CARAPI GetNString(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ _ELASTOS String * nstr) = 0;

    virtual CARAPI GetNString(
        /* [in] */ const _ELASTOS String& columnLabel,
        /* [out] */ _ELASTOS String * nstr) = 0;

    virtual CARAPI GetNCharacterStream(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [out] */ Elastos::IO::IReader ** reader) = 0;

    virtual CARAPI GetNCharacterStream(
        /* [in] */ const _ELASTOS String& columnLabel,
        /* [out] */ Elastos::IO::IReader ** reader) = 0;

    virtual CARAPI UpdateNCharacterStream(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::IO::IReader * x,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI UpdateNCharacterStream(
        /* [in] */ const _ELASTOS String& columnLabel,
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI UpdateAsciiStream(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::IO::IInputStream * x,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI UpdateBinaryStream(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::IO::IInputStream * x,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI UpdateCharacterStream(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::IO::IReader * x,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI UpdateAsciiStream(
        /* [in] */ const _ELASTOS String& columnLabel,
        /* [in] */ Elastos::IO::IInputStream * x,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI UpdateBinaryStream(
        /* [in] */ const _ELASTOS String& columnLabel,
        /* [in] */ Elastos::IO::IInputStream * x,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI UpdateCharacterStream(
        /* [in] */ const _ELASTOS String& columnLabel,
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI UpdateBlob(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI UpdateBlob(
        /* [in] */ const _ELASTOS String& columnLabel,
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI UpdateClob(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI UpdateClob(
        /* [in] */ const _ELASTOS String& columnLabel,
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI UpdateNClob(
        /* [in] */ _ELASTOS Int64 columnIndex,
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI UpdateNClob(
        /* [in] */ const _ELASTOS String& columnLabel,
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI UpdateNCharacterStream(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::IO::IReader * x) = 0;

    virtual CARAPI UpdateNCharacterStream(
        /* [in] */ const _ELASTOS String& columnLabel,
        /* [in] */ Elastos::IO::IReader * reader) = 0;

    virtual CARAPI UpdateAsciiStream(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::IO::IInputStream * x) = 0;

    virtual CARAPI UpdateBinaryStream(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::IO::IInputStream * x) = 0;

    virtual CARAPI UpdateCharacterStream(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::IO::IReader * x) = 0;

    virtual CARAPI UpdateAsciiStream(
        /* [in] */ const _ELASTOS String& columnLabel,
        /* [in] */ Elastos::IO::IInputStream * x) = 0;

    virtual CARAPI UpdateBinaryStream(
        /* [in] */ const _ELASTOS String& columnLabel,
        /* [in] */ Elastos::IO::IInputStream * x) = 0;

    virtual CARAPI UpdateCharacterStream(
        /* [in] */ const _ELASTOS String& columnLabel,
        /* [in] */ Elastos::IO::IReader * reader) = 0;

    virtual CARAPI UpdateBlob(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::IO::IInputStream * inputStream) = 0;

    virtual CARAPI UpdateBlob(
        /* [in] */ const _ELASTOS String& columnLabel,
        /* [in] */ Elastos::IO::IInputStream * inputStream) = 0;

    virtual CARAPI UpdateClob(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::IO::IReader * reader) = 0;

    virtual CARAPI UpdateClob(
        /* [in] */ const _ELASTOS String& columnLabel,
        /* [in] */ Elastos::IO::IReader * reader) = 0;

    virtual CARAPI UpdateNClob(
        /* [in] */ _ELASTOS Int32 columnIndex,
        /* [in] */ Elastos::IO::IReader * reader) = 0;

    virtual CARAPI UpdateNClob(
        /* [in] */ const _ELASTOS String& columnLabel,
        /* [in] */ Elastos::IO::IReader * reader) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("B7FBFF4A-0352-9246-065B-9846A201A31F")
IDatabaseMetaData : public IInterface
{
    static const _ELASTOS Int16 attributeNoNulls = 0;
    static const _ELASTOS Int16 attributeNullable = 1;
    static const _ELASTOS Int16 attributeNullableUnknown = 2;
    static const _ELASTOS Int32 bestRowNotPseudo = 1;
    static const _ELASTOS Int32 bestRowPseudo = 2;
    static const _ELASTOS Int32 bestRowSession = 2;
    static const _ELASTOS Int32 bestRowTemporary = 0;
    static const _ELASTOS Int32 bestRowTransaction = 1;
    static const _ELASTOS Int32 bestRowUnknown = 0;
    static const _ELASTOS Int32 columnNoNulls = 0;
    static const _ELASTOS Int32 columnNullable = 1;
    static const _ELASTOS Int32 columnNullableUnknown = 2;
    static const _ELASTOS Int32 importedKeyCascade = 0;
    static const _ELASTOS Int32 importedKeyInitiallyDeferred = 5;
    static const _ELASTOS Int32 importedKeyInitiallyImmediate = 6;
    static const _ELASTOS Int32 importedKeyNoAction = 3;
    static const _ELASTOS Int32 importedKeyNotDeferrable = 7;
    static const _ELASTOS Int32 importedKeyRestrict = 1;
    static const _ELASTOS Int32 importedKeySetDefault = 4;
    static const _ELASTOS Int32 importedKeySetNull = 2;
    static const _ELASTOS Int32 procedureColumnIn = 1;
    static const _ELASTOS Int32 procedureColumnInOut = 2;
    static const _ELASTOS Int32 procedureColumnOut = 4;
    static const _ELASTOS Int32 procedureColumnResult = 3;
    static const _ELASTOS Int32 procedureColumnReturn = 5;
    static const _ELASTOS Int32 procedureColumnUnknown = 0;
    static const _ELASTOS Int32 procedureNoNulls = 0;
    static const _ELASTOS Int32 procedureNoResult = 1;
    static const _ELASTOS Int32 procedureNullable = 1;
    static const _ELASTOS Int32 procedureNullableUnknown = 2;
    static const _ELASTOS Int32 procedureResultUnknown = 0;
    static const _ELASTOS Int32 procedureReturnsResult = 2;
    static const _ELASTOS Int32 sqlStateSQL99 = 2;
    static const _ELASTOS Int32 sqlStateXOpen = 1;
    static const _ELASTOS Int16 tableIndexClustered = 1;
    static const _ELASTOS Int16 tableIndexHashed = 2;
    static const _ELASTOS Int16 tableIndexOther = 3;
    static const _ELASTOS Int16 tableIndexStatistic = 0;
    static const _ELASTOS Int32 typeNoNulls = 0;
    static const _ELASTOS Int32 typeNullable = 1;
    static const _ELASTOS Int32 typeNullableUnknown = 2;
    static const _ELASTOS Int32 typePredBasic = 2;
    static const _ELASTOS Int32 typePredChar = 1;
    static const _ELASTOS Int32 typePredNone = 0;
    static const _ELASTOS Int32 typeSearchable = 3;
    static const _ELASTOS Int32 versionColumnNotPseudo = 1;
    static const _ELASTOS Int32 versionColumnPseudo = 2;
    static const _ELASTOS Int32 versionColumnUnknown = 0;
    static const _ELASTOS Int32 sqlStateSQL = 2;
    static const _ELASTOS Int32 functionColumnIn = 1;
    static const _ELASTOS Int32 functionColumnInOut = 2;
    static const _ELASTOS Int32 functionColumnOut = 3;
    static const _ELASTOS Int32 functionReturn = 4;
    static const _ELASTOS Int32 functionColumnUnknown = 0;
    static const _ELASTOS Int32 functionColumnResult = 5;
    static const _ELASTOS Int32 functionNoNulls = 0;
    static const _ELASTOS Int32 functionNullable = 1;
    static const _ELASTOS Int32 functionNullableUnknown = 2;
    static const _ELASTOS Int32 functionResultUnknown = 0;
    static const _ELASTOS Int32 functionNoTable = 1;
    static const _ELASTOS Int32 functionReturnsTable = 2;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDatabaseMetaData*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatabaseMetaData*)pObj->Probe(EIID_IDatabaseMetaData);
    }

    static CARAPI_(IDatabaseMetaData*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatabaseMetaData*)pObj->Probe(EIID_IDatabaseMetaData);
    }

    virtual CARAPI AllProceduresAreCallable(
        /* [out] */ _ELASTOS Boolean * callable) = 0;

    virtual CARAPI AllTablesAreSelectable(
        /* [out] */ _ELASTOS Boolean * selectable) = 0;

    virtual CARAPI DataDefinitionCausesTransactionCommit(
        /* [out] */ _ELASTOS Boolean * commit) = 0;

    virtual CARAPI DataDefinitionIgnoredInTransactions(
        /* [out] */ _ELASTOS Boolean * ignored) = 0;

    virtual CARAPI DeletesAreDetected(
        /* [in] */ _ELASTOS Int32 type,
        /* [out] */ _ELASTOS Boolean * detected) = 0;

    virtual CARAPI DoesMaxRowSizeIncludeBlobs(
        /* [out] */ _ELASTOS Boolean * doesmax) = 0;

    virtual CARAPI GetAttributes(
        /* [in] */ const _ELASTOS String& catalog,
        /* [in] */ const _ELASTOS String& schemaPattern,
        /* [in] */ const _ELASTOS String& typeNamePattern,
        /* [in] */ const _ELASTOS String& attributeNamePattern,
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI GetBestRowIdentifier(
        /* [in] */ const _ELASTOS String& catalog,
        /* [in] */ const _ELASTOS String& schema,
        /* [in] */ const _ELASTOS String& table,
        /* [in] */ _ELASTOS Int32 scope,
        /* [in] */ _ELASTOS Boolean nullable,
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI GetCatalogs(
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI GetCatalogSeparator(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetCatalogTerm(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetColumnPrivileges(
        /* [in] */ const _ELASTOS String& catalog,
        /* [in] */ const _ELASTOS String& schema,
        /* [in] */ const _ELASTOS String& table,
        /* [in] */ const _ELASTOS String& columnNamePattern,
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI GetColumns(
        /* [in] */ const _ELASTOS String& catalog,
        /* [in] */ const _ELASTOS String& schemaPattern,
        /* [in] */ const _ELASTOS String& tableNamePattern,
        /* [in] */ const _ELASTOS String& columnNamePattern,
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI GetConnection(
        /* [out] */ Elastos::Sql::IConnection ** connection) = 0;

    virtual CARAPI GetCrossReference(
        /* [in] */ const _ELASTOS String& primaryCatalog,
        /* [in] */ const _ELASTOS String& primarySchema,
        /* [in] */ const _ELASTOS String& primaryTable,
        /* [in] */ const _ELASTOS String& foreignCatalog,
        /* [in] */ const _ELASTOS String& foreignSchema,
        /* [in] */ const _ELASTOS String& foreignTable,
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI GetDatabaseMajorVersion(
        /* [out] */ _ELASTOS Int32 * ver) = 0;

    virtual CARAPI GetDatabaseMinorVersion(
        /* [out] */ _ELASTOS Int32 * ver) = 0;

    virtual CARAPI GetDatabaseProductName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetDatabaseProductVersion(
        /* [out] */ _ELASTOS String * ver) = 0;

    virtual CARAPI GetDefaultTransactionIsolation(
        /* [out] */ _ELASTOS Int32 * level) = 0;

    virtual CARAPI GetDriverMajorVersion(
        /* [out] */ _ELASTOS Int32 * ver) = 0;

    virtual CARAPI GetDriverMinorVersion(
        /* [out] */ _ELASTOS Int32 * ver) = 0;

    virtual CARAPI GetDriverName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetDriverVersion(
        /* [out] */ _ELASTOS String * ver) = 0;

    virtual CARAPI GetExportedKeys(
        /* [in] */ const _ELASTOS String& catalog,
        /* [in] */ const _ELASTOS String& schema,
        /* [in] */ const _ELASTOS String& table,
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI GetExtraNameCharacters(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetIdentifierQuoteString(
        /* [out] */ _ELASTOS String * quote) = 0;

    virtual CARAPI GetImportedKeys(
        /* [in] */ const _ELASTOS String& catalog,
        /* [in] */ const _ELASTOS String& schema,
        /* [in] */ const _ELASTOS String& table,
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI GetIndexInfo(
        /* [in] */ const _ELASTOS String& catalog,
        /* [in] */ const _ELASTOS String& schema,
        /* [in] */ const _ELASTOS String& table,
        /* [in] */ _ELASTOS Boolean unique,
        /* [in] */ _ELASTOS Boolean approximate,
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI GetJDBCMajorVersion(
        /* [out] */ _ELASTOS Int32 * ver) = 0;

    virtual CARAPI GetJDBCMinorVersion(
        /* [out] */ _ELASTOS Int32 * ver) = 0;

    virtual CARAPI GetMaxBinaryLiteralLength(
        /* [out] */ _ELASTOS Int32 * len) = 0;

    virtual CARAPI GetMaxCatalogNameLength(
        /* [out] */ _ELASTOS Int32 * len) = 0;

    virtual CARAPI GetMaxCharLiteralLength(
        /* [out] */ _ELASTOS Int32 * len) = 0;

    virtual CARAPI GetMaxColumnNameLength(
        /* [out] */ _ELASTOS Int32 * len) = 0;

    virtual CARAPI GetMaxColumnsInGroupBy(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI GetMaxColumnsInIndex(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI GetMaxColumnsInOrderBy(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI GetMaxColumnsInSelect(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI GetMaxColumnsInTable(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI GetMaxConnections(
        /* [out] */ _ELASTOS Int32 * connections) = 0;

    virtual CARAPI GetMaxCursorNameLength(
        /* [out] */ _ELASTOS Int32 * len) = 0;

    virtual CARAPI GetMaxIndexLength(
        /* [out] */ _ELASTOS Int32 * len) = 0;

    virtual CARAPI GetMaxProcedureNameLength(
        /* [out] */ _ELASTOS Int32 * len) = 0;

    virtual CARAPI GetMaxRowSize(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI GetMaxSchemaNameLength(
        /* [out] */ _ELASTOS Int32 * len) = 0;

    virtual CARAPI GetMaxStatementLength(
        /* [out] */ _ELASTOS Int32 * len) = 0;

    virtual CARAPI GetMaxStatements(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI GetMaxTableNameLength(
        /* [out] */ _ELASTOS Int32 * len) = 0;

    virtual CARAPI GetMaxTablesInSelect(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI GetMaxUserNameLength(
        /* [out] */ _ELASTOS Int32 * len) = 0;

    virtual CARAPI GetNumericFunctions(
        /* [out] */ _ELASTOS String * len) = 0;

    virtual CARAPI GetPrimaryKeys(
        /* [in] */ const _ELASTOS String& catalog,
        /* [in] */ const _ELASTOS String& schema,
        /* [in] */ const _ELASTOS String& table,
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI GetProcedureColumns(
        /* [in] */ const _ELASTOS String& catalog,
        /* [in] */ const _ELASTOS String& schemaPattern,
        /* [in] */ const _ELASTOS String& procedureNamePattern,
        /* [in] */ const _ELASTOS String& columnNamePattern,
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI GetProcedures(
        /* [in] */ const _ELASTOS String& catalog,
        /* [in] */ const _ELASTOS String& schemaPattern,
        /* [in] */ const _ELASTOS String& procedureNamePattern,
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI GetProcedureTerm(
        /* [out] */ _ELASTOS String * prefer) = 0;

    virtual CARAPI GetResultSetHoldability(
        /* [out] */ _ELASTOS Int32 * code) = 0;

    virtual CARAPI GetSchemas(
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI GetSchemaTerm(
        /* [out] */ _ELASTOS String * term) = 0;

    virtual CARAPI GetSearchStringEscape(
        /* [out] */ _ELASTOS String * escape) = 0;

    virtual CARAPI SetSQLKeywords(
        /* [out] */ _ELASTOS String * key) = 0;

    virtual CARAPI GetSQLStateType(
        /* [out] */ _ELASTOS Int32 * type) = 0;

    virtual CARAPI GetStringFunctions(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetSuperTables(
        /* [in] */ const _ELASTOS String& catalog,
        /* [in] */ const _ELASTOS String& schemaPattern,
        /* [in] */ const _ELASTOS String& tableNamePattern,
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI GetSuperTypes(
        /* [in] */ const _ELASTOS String& catalog,
        /* [in] */ const _ELASTOS String& schemaPattern,
        /* [in] */ const _ELASTOS String& typeNamePattern,
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI GetSystemFunctions(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetTablePrivileges(
        /* [in] */ const _ELASTOS String& catalog,
        /* [in] */ const _ELASTOS String& schemaPattern,
        /* [in] */ const _ELASTOS String& tableNamePattern,
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI GetTables(
        /* [in] */ const _ELASTOS String& catalog,
        /* [in] */ const _ELASTOS String& schemaPattern,
        /* [in] */ const _ELASTOS String& tableNamePattern,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS String> & types,
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI GetTableTypes(
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI GetTimeDateFunctions(
        /* [out] */ _ELASTOS String * time) = 0;

    virtual CARAPI GetTypeInfo(
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI GetUDTs(
        /* [in] */ const _ELASTOS String& catalog,
        /* [in] */ const _ELASTOS String& schemaPattern,
        /* [in] */ const _ELASTOS String& typeNamePattern,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int32> & types,
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI GetURL(
        /* [out] */ _ELASTOS String * url) = 0;

    virtual CARAPI GetUserName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetVersionColumns(
        /* [in] */ const _ELASTOS String& catalog,
        /* [in] */ const _ELASTOS String& schema,
        /* [in] */ const _ELASTOS String& table,
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI InsertsAreDetected(
        /* [in] */ _ELASTOS Int32 type,
        /* [out] */ _ELASTOS Boolean * detected) = 0;

    virtual CARAPI IsCatalogAtStart(
        /* [out] */ _ELASTOS Boolean * isCatalog) = 0;

    virtual CARAPI IsReadOnly(
        /* [out] */ _ELASTOS Boolean * isReadOnly) = 0;

    virtual CARAPI LocatorsUpdateCopy(
        /* [out] */ _ELASTOS Boolean * isCopy) = 0;

    virtual CARAPI NullPlusNonNullIsNull(
        /* [out] */ _ELASTOS Boolean * isNull) = 0;

    virtual CARAPI NullsAreSortedAtEnd(
        /* [out] */ _ELASTOS Boolean * isNull) = 0;

    virtual CARAPI NullsAreSortedAtStart(
        /* [out] */ _ELASTOS Boolean * isNull) = 0;

    virtual CARAPI NullsAreSortedHigh(
        /* [out] */ _ELASTOS Boolean * isNull) = 0;

    virtual CARAPI NullsAreSortedLow(
        /* [out] */ _ELASTOS Boolean * isNull) = 0;

    virtual CARAPI OthersDeletesAreVisible(
        /* [in] */ _ELASTOS Int32 type,
        /* [out] */ _ELASTOS Boolean * isVisible) = 0;

    virtual CARAPI OthersInsertsAreVisible(
        /* [in] */ _ELASTOS Int32 type,
        /* [out] */ _ELASTOS Boolean * isVisible) = 0;

    virtual CARAPI OthersUpdatesAreVisible(
        /* [in] */ _ELASTOS Int32 type,
        /* [out] */ _ELASTOS Boolean * isVisible) = 0;

    virtual CARAPI OwnDeletesAreVisible(
        /* [in] */ _ELASTOS Int32 type,
        /* [out] */ _ELASTOS Boolean * isVisible) = 0;

    virtual CARAPI OwnInsertsAreVisible(
        /* [in] */ _ELASTOS Int32 type,
        /* [out] */ _ELASTOS Boolean * isVisible) = 0;

    virtual CARAPI OwnUpdatesAreVisible(
        /* [in] */ _ELASTOS Int32 type,
        /* [out] */ _ELASTOS Boolean * isVisible) = 0;

    virtual CARAPI StoresLowerCaseIdentifiers(
        /* [out] */ _ELASTOS Boolean * isStored) = 0;

    virtual CARAPI StoresLowerCaseQuotedIdentifiers(
        /* [out] */ _ELASTOS Boolean * isStored) = 0;

    virtual CARAPI StoresMixedCaseIdentifiers(
        /* [out] */ _ELASTOS Boolean * isStored) = 0;

    virtual CARAPI StoresMixedCaseQuotedIdentifiers(
        /* [out] */ _ELASTOS Boolean * isStored) = 0;

    virtual CARAPI StoresUpperCaseIdentifiers(
        /* [out] */ _ELASTOS Boolean * isStored) = 0;

    virtual CARAPI StoresUpperCaseQuotedIdentifiers(
        /* [out] */ _ELASTOS Boolean * isStored) = 0;

    virtual CARAPI SupportsAlterTableWithAddColumn(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsAlterTableWithDropColumn(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsANSI92EntryLevelSQL(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsANSI92FullSQL(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsANSI92IntermediateSQL(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsBatchUpdates(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsCatalogsInDataManipulation(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsCatalogsInIndexDefinitions(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsCatalogsInPrivilegeDefinitions(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsCatalogsInProcedureCalls(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsCatalogsInTableDefinitions(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsColumnAliasing(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsConvert(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsConvert(
        /* [in] */ _ELASTOS Int32 fromType,
        /* [in] */ _ELASTOS Int32 toType,
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsCoreSQLGrammar(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsCorrelatedSubqueries(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsDataDefinitionAndDataManipulationTransactions(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsDataManipulationTransactionsOnly(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsDifferentTableCorrelationNames(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsExpressionsInOrderBy(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsExtendedSQLGrammar(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsFullOuterJoins(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsGetGeneratedKeys(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsGroupBy(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsGroupByBeyondSelect(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsGroupByUnrelated(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsIntegrityEnhancementFacility(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsLikeEscapeClause(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI SupportsLimitedOuterJoins(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsMinimumSQLGrammar(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsMixedCaseIdentifiers(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsMixedCaseQuotedIdentifiers(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsMultipleOpenResults(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsMultipleResultSets(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsMultipleTransactions(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsNamedParameters(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsNonNullableColumns(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsOpenCursorsAcrossCommit(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsOpenCursorsAcrossRollback(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsOpenStatementsAcrossCommit(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsOpenStatementsAcrossRollback(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsOrderByUnrelated(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsOuterJoins(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsPositionedDelete(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsPositionedUpdate(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsResultSetConcurrency(
        /* [in] */ _ELASTOS Int32 type,
        /* [in] */ _ELASTOS Int32 concurrency,
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsResultSetHoldability(
        /* [in] */ _ELASTOS Int32 holdability,
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsResultSetType(
        /* [in] */ _ELASTOS Int32 type,
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsSavepoints(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsSchemasInDataManipulation(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsSchemasInIndexDefinitions(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsSchemasInPrivilegeDefinitions(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsSchemasInProcedureCalls(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsSchemasInTableDefinitions(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsSelectForUpdate(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsStatementPooling(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsStoredProcedures(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsSubqueriesInComparisons(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsSubqueriesInExists(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsSubqueriesInIns(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsSubqueriesInQuantifieds(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsTableCorrelationNames(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsTransactionIsolationLevel(
        /* [in] */ _ELASTOS Int32 level,
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsTransactions(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsUnion(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI SupportsUnionAll(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

    virtual CARAPI UpdatesAreDetected(
        /* [in] */ _ELASTOS Int32 type,
        /* [out] */ _ELASTOS Boolean * isUpdate) = 0;

    virtual CARAPI UsesLocalFilePerTable(
        /* [out] */ _ELASTOS Boolean * isUsed) = 0;

    virtual CARAPI UsesLocalFiles(
        /* [out] */ _ELASTOS Boolean * isStored) = 0;

    virtual CARAPI AutoCommitFailureClosesAllResultSets(
        /* [out] */ _ELASTOS Boolean * isClosed) = 0;

    virtual CARAPI GetClientInfoProperties(
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI GetFunctionColumns(
        /* [in] */ const _ELASTOS String& catalog,
        /* [in] */ const _ELASTOS String& schemaPattern,
        /* [in] */ const _ELASTOS String& functionNamePattern,
        /* [in] */ const _ELASTOS String& columnNamePattern,
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI GetFunctions(
        /* [in] */ const _ELASTOS String& catalog,
        /* [in] */ const _ELASTOS String& schemaPattern,
        /* [in] */ const _ELASTOS String& functionNamePattern,
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI GetRowIdLifetime(
        /* [out] */ Elastos::Sql::RowIdLifeTime * rowIdLifeTime) = 0;

    virtual CARAPI SetSchemas(
        /* [in] */ const _ELASTOS String& catalog,
        /* [in] */ const _ELASTOS String& schemaPattern,
        /* [out] */ Elastos::Sql::IResultSet ** resultSet) = 0;

    virtual CARAPI SupportsStoredFunctionsUsingCallSyntax(
        /* [out] */ _ELASTOS Boolean * isSupported) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("2308FF28-8652-281A-6690-A8A17FF5FB1F")
IPreparedStatement : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPreparedStatement*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPreparedStatement*)pObj->Probe(EIID_IPreparedStatement);
    }

    static CARAPI_(IPreparedStatement*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPreparedStatement*)pObj->Probe(EIID_IPreparedStatement);
    }

    virtual CARAPI AddBatch() = 0;

    virtual CARAPI ClearParameters() = 0;

    virtual CARAPI Execute(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI ExecuteQuery(
        /* [out] */ Elastos::Sql::IResultSet ** resultset) = 0;

    virtual CARAPI ExecuteUpdate(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetMetaData(
        /* [out] */ Elastos::Sql::IResultSetMetaData ** resultsetmeta) = 0;

    virtual CARAPI GetParameterMetaData(
        /* [out] */ Elastos::Sql::IParameterMetaData ** parametermeta) = 0;

    virtual CARAPI SetArray(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::IArray * theArray) = 0;

    virtual CARAPI SetAsciiStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IInputStream * theInputStream,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI SetBigDecimal(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Math::IBigDecimal * theBigDecimal) = 0;

    virtual CARAPI SetBinaryStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IInputStream * theInputStream,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI SetBlob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::IBlob * theBlob) = 0;

    virtual CARAPI SetBoolean(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ _ELASTOS Boolean theBoolean) = 0;

    virtual CARAPI SetByte(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ _ELASTOS Byte theByte) = 0;

    virtual CARAPI SetBytes(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & theBytes) = 0;

    virtual CARAPI SetCharacterStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI SetClob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::IClob * theClob) = 0;

    virtual CARAPI SetDate(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::ISQLDate * theDate) = 0;

    virtual CARAPI SetDate(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::ISQLDate * theDate,
        /* [in] */ Elastos::Utility::ICalendar * cal) = 0;

    virtual CARAPI SetDouble(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ _ELASTOS Double theDouble) = 0;

    virtual CARAPI SetFloat(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ _ELASTOS Float theFloat) = 0;

    virtual CARAPI SetInt32(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ _ELASTOS Int32 theInt) = 0;

    virtual CARAPI SetInt64(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ _ELASTOS Int64 theLong) = 0;

    virtual CARAPI SetNull(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ _ELASTOS Int32 sqlType) = 0;

    virtual CARAPI SetNull(
        /* [in] */ _ELASTOS Int32 paramIndex,
        /* [in] */ _ELASTOS Int32 sqlType,
        /* [in] */ const _ELASTOS String& typeName) = 0;

    virtual CARAPI SetObject(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ IObject * theObject) = 0;

    virtual CARAPI SetObject(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ IObject * theObject,
        /* [in] */ _ELASTOS Int32 targetSqlType) = 0;

    virtual CARAPI SetObject(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ IObject * theObject,
        /* [in] */ _ELASTOS Int32 targetSqlType,
        /* [in] */ _ELASTOS Int32 scale) = 0;

    virtual CARAPI SetRef(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::IRef * theRef) = 0;

    virtual CARAPI SetInt16(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ _ELASTOS Int16 theShort) = 0;

    virtual CARAPI SetString(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ const _ELASTOS String& theString) = 0;

    virtual CARAPI SetTime(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::ITime * theTime) = 0;

    virtual CARAPI SetTime(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::ITime * theTime,
        /* [in] */ Elastos::Utility::ICalendar * cal) = 0;

    virtual CARAPI SetTimestamp(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::ITimestamp * theTimestamp) = 0;

    virtual CARAPI SetTimestamp(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::ITimestamp * theTimestamp,
        /* [in] */ Elastos::Utility::ICalendar * cal) = 0;

    virtual CARAPI SetUnicodeStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IInputStream * theInputStream,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI SetURL(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Net::IURL * theURL) = 0;

    virtual CARAPI SetRowId(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::IRowId * theRowId) = 0;

    virtual CARAPI SetNString(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ const _ELASTOS String& theString) = 0;

    virtual CARAPI SetNCharacterStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI SetNClob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::INClob * value) = 0;

    virtual CARAPI SetClob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI SetBlob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI SetNClob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI SetSQLXML(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::ISQLXML * xmlObject) = 0;

    virtual CARAPI SetAsciiStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI SetBinaryStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI SetCharacterStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI SetAsciiStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IInputStream * inputStream) = 0;

    virtual CARAPI SetBinaryStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IInputStream * inputStream) = 0;

    virtual CARAPI SetCharacterStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * reader) = 0;

    virtual CARAPI SetNCharacterStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * reader) = 0;

    virtual CARAPI SetClob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * reader) = 0;

    virtual CARAPI SetBlob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IInputStream * inputStream) = 0;

    virtual CARAPI SetNClob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * reader) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("C3B4FA22-1C92-2512-5EA0-58FDFE477B1B")
ICallableStatement : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICallableStatement*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICallableStatement*)pObj->Probe(EIID_ICallableStatement);
    }

    static CARAPI_(ICallableStatement*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICallableStatement*)pObj->Probe(EIID_ICallableStatement);
    }

    virtual CARAPI GetArray(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ Elastos::Sql::IArray ** iarray) = 0;

    virtual CARAPI GetArray(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ Elastos::Sql::IArray ** iarray) = 0;

    virtual CARAPI GetBigDecimal(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ Elastos::Math::IBigDecimal ** bigdecimal) = 0;

    virtual CARAPI GetBigDecimal(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ Elastos::Math::IBigDecimal ** bigdecimal) = 0;

    virtual CARAPI GetBigDecimal(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ Elastos::Math::IBigDecimal ** bigdecimal) = 0;

    virtual CARAPI GetBlob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ Elastos::Sql::IBlob ** blob) = 0;

    virtual CARAPI GetBlob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ Elastos::Sql::IBlob ** blob) = 0;

    virtual CARAPI GetBoolean(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetBoolean(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetByte(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ _ELASTOS Byte * obyte) = 0;

    virtual CARAPI GetByte(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ _ELASTOS Byte * obyte) = 0;

    virtual CARAPI GetBytes(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** obyte) = 0;

    virtual CARAPI GetBytes(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** obyte) = 0;

    virtual CARAPI GetClob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ Elastos::Sql::IClob ** clob) = 0;

    virtual CARAPI GetClob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ Elastos::Sql::IClob ** clob) = 0;

    virtual CARAPI GetDate(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ Elastos::Sql::ISQLDate ** idate) = 0;

    virtual CARAPI GetDate(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Utility::ICalendar * cal,
        /* [out] */ Elastos::Sql::ISQLDate ** idate) = 0;

    virtual CARAPI GetDate(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ Elastos::Sql::ISQLDate ** idate) = 0;

    virtual CARAPI GetDate(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Utility::ICalendar * cal,
        /* [out] */ Elastos::Sql::ISQLDate ** idate) = 0;

    virtual CARAPI GetDouble(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ _ELASTOS Double * value) = 0;

    virtual CARAPI GetDouble(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ _ELASTOS Double * value) = 0;

    virtual CARAPI GetFloat(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ _ELASTOS Float * value) = 0;

    virtual CARAPI GetFloat(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ _ELASTOS Float * value) = 0;

    virtual CARAPI GetInt32(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetInt32(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetInt64(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI GetInt64(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI GetObject(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ IInterface ** inter) = 0;

    virtual CARAPI GetObject(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ IInterface ** inter) = 0;

    virtual CARAPI GetObject(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ IInterface ** inter) = 0;

    virtual CARAPI GetObject(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ IInterface ** inter) = 0;

    virtual CARAPI GetRef(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ Elastos::Sql::IRef ** ref) = 0;

    virtual CARAPI GetRef(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ Elastos::Sql::IRef ** ref) = 0;

    virtual CARAPI GetInt16(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ _ELASTOS Int16 * value) = 0;

    virtual CARAPI GetInt16(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ _ELASTOS Int16 * value) = 0;

    virtual CARAPI GetString(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetString(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetTime(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ Elastos::Sql::ITime ** itime) = 0;

    virtual CARAPI GetTime(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Utility::ICalendar * cal,
        /* [out] */ Elastos::Sql::ITime ** itime) = 0;

    virtual CARAPI GetTime(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ Elastos::Sql::ITime ** itime) = 0;

    virtual CARAPI GetTime(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Utility::ICalendar * cal,
        /* [out] */ Elastos::Sql::ITime ** itime) = 0;

    virtual CARAPI GetTimestamp(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ Elastos::Sql::ITimestamp ** timestamp) = 0;

    virtual CARAPI GetTimestamp(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Utility::ICalendar * cal,
        /* [out] */ Elastos::Sql::ITimestamp ** timestamp) = 0;

    virtual CARAPI GetTimestamp(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ Elastos::Sql::ITimestamp ** timestamp) = 0;

    virtual CARAPI GetTimestamp(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Utility::ICalendar * cal,
        /* [out] */ Elastos::Sql::ITimestamp ** timestamp) = 0;

    virtual CARAPI GetURL(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ Elastos::Net::IURL ** url) = 0;

    virtual CARAPI GetURL(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ Elastos::Net::IURL ** url) = 0;

    virtual CARAPI RegisterOutParameter(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ _ELASTOS Int32 sqlType) = 0;

    virtual CARAPI RegisterOutParameter(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ _ELASTOS Int32 sqlType,
        /* [in] */ _ELASTOS Int32 scale) = 0;

    virtual CARAPI RegisterOutParameter(
        /* [in] */ _ELASTOS Int32 paramIndex,
        /* [in] */ _ELASTOS Int32 sqlType,
        /* [in] */ const _ELASTOS String& typeName) = 0;

    virtual CARAPI RegisterOutParameter(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Int32 sqlType) = 0;

    virtual CARAPI RegisterOutParameter(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Int32 sqlType,
        /* [in] */ _ELASTOS Int32 scale) = 0;

    virtual CARAPI RegisterOutParameter(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Int32 sqlType,
        /* [in] */ const _ELASTOS String& typeName) = 0;

    virtual CARAPI SetAsciiStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IInputStream * theInputStream,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI SetBigDecimal(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Math::IBigDecimal * theBigDecimal) = 0;

    virtual CARAPI SetBinaryStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IInputStream * theInputStream,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI SetBoolean(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Boolean theBoolean) = 0;

    virtual CARAPI SetByte(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Byte theByte) = 0;

    virtual CARAPI SetBytes(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & theBytes) = 0;

    virtual CARAPI SetCharacterStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI SetDate(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::ISQLDate * theDate) = 0;

    virtual CARAPI SetDate(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::ISQLDate * theDate,
        /* [in] */ Elastos::Utility::ICalendar * cal) = 0;

    virtual CARAPI SetDouble(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Double theDouble) = 0;

    virtual CARAPI SetFloat(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Float theFloat) = 0;

    virtual CARAPI SetInt32(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Int32 theInt) = 0;

    virtual CARAPI SetInt64(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Int64 theLong) = 0;

    virtual CARAPI SetNull(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Int32 sqlType) = 0;

    virtual CARAPI SetNull(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Int32 sqlType,
        /* [in] */ const _ELASTOS String& typeName) = 0;

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

    virtual CARAPI SetInt16(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Int16 theShort) = 0;

    virtual CARAPI SetString(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ const _ELASTOS String& theString) = 0;

    virtual CARAPI SetTime(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::ITime * theTime) = 0;

    virtual CARAPI SetTime(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::ITime * theTime,
        /* [in] */ Elastos::Utility::ICalendar * cal) = 0;

    virtual CARAPI SetTimestamp(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::ITimestamp * theTimestamp) = 0;

    virtual CARAPI SetTimestamp(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::ITimestamp * theTimestamp,
        /* [in] */ Elastos::Utility::ICalendar * cal) = 0;

    virtual CARAPI SetURL(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Net::IURL * theURL) = 0;

    virtual CARAPI WasNull(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetRowId(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ Elastos::Sql::IRowId ** rowid) = 0;

    virtual CARAPI GetRowId(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ Elastos::Sql::IRowId ** rowid) = 0;

    virtual CARAPI SetRowId(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::IRowId * rowId) = 0;

    virtual CARAPI SetNString(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ const _ELASTOS String& string) = 0;

    virtual CARAPI SetNCharacterStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI SetNClob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::INClob * nclob) = 0;

    virtual CARAPI SetClob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI SetBlob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI SetNClob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI GetNClob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ Elastos::Sql::INClob ** nclob) = 0;

    virtual CARAPI GetNClob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ Elastos::Sql::INClob ** nclob) = 0;

    virtual CARAPI SetSQLXML(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::ISQLXML * sqlXml) = 0;

    virtual CARAPI GetSQLXML(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ Elastos::Sql::ISQLXML ** sqlxml) = 0;

    virtual CARAPI GetSQLXML(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ Elastos::Sql::ISQLXML ** sqlxml) = 0;

    virtual CARAPI GetNString(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetNString(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetNCharacterStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ Elastos::IO::IReader ** reader) = 0;

    virtual CARAPI GetNCharacterStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ Elastos::IO::IReader ** reader) = 0;

    virtual CARAPI GetCharacterStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ Elastos::IO::IReader ** reader) = 0;

    virtual CARAPI GetCharacterStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ Elastos::IO::IReader ** reader) = 0;

    virtual CARAPI SetBlob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::IBlob * blob) = 0;

    virtual CARAPI SetClob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::IClob * clob) = 0;

    virtual CARAPI SetAsciiStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IInputStream * x,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI SetAsciiStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IInputStream * x) = 0;

    virtual CARAPI SetBinaryStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IInputStream * x,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI SetBinaryStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IInputStream * x) = 0;

    virtual CARAPI SetCharacterStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * reader,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI SetCharacterStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * reader) = 0;

    virtual CARAPI SetNCharacterStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * value) = 0;

    virtual CARAPI SetClob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * reader) = 0;

    virtual CARAPI SetBlob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IInputStream * inputStream) = 0;

    virtual CARAPI SetNClob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * reader) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("8F03353B-6492-3FAF-DADB-B821C3C60F0E")
ISavePoint : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISavePoint*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISavePoint*)pObj->Probe(EIID_ISavePoint);
    }

    static CARAPI_(ISavePoint*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISavePoint*)pObj->Probe(EIID_ISavePoint);
    }

    virtual CARAPI GetSavepointId(
        /* [out] */ _ELASTOS Int32 * id) = 0;

    virtual CARAPI GetSavepointName(
        /* [out] */ _ELASTOS String * name) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("8A7D251C-A712-1955-5AC3-AC6DB372FC3B")
ISQLPermission : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISQLPermission*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISQLPermission*)pObj->Probe(EIID_ISQLPermission);
    }

    static CARAPI_(ISQLPermission*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISQLPermission*)pObj->Probe(EIID_ISQLPermission);
    }

    virtual CARAPI GetActions(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("DEAAF538-A312-ED1F-6DDC-9061E307071A")
IConnection : public IInterface
{
    static const _ELASTOS Int32 TRANSACTION_NONE = 0;
    static const _ELASTOS Int32 TRANSACTION_READ_COMMITTED = 2;
    static const _ELASTOS Int32 TRANSACTION_READ_UNCOMMITTED = 1;
    static const _ELASTOS Int32 TRANSACTION_REPEATABLE_READ = 4;
    static const _ELASTOS Int32 TRANSACTION_SERIALIZABLE = 8;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IConnection*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IConnection*)pObj->Probe(EIID_IConnection);
    }

    static CARAPI_(IConnection*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IConnection*)pObj->Probe(EIID_IConnection);
    }

    virtual CARAPI ClearWarnings() = 0;

    virtual CARAPI Close() = 0;

    virtual CARAPI Commit() = 0;

    virtual CARAPI CreateStatement(
        /* [out] */ Elastos::Sql::IStatement ** statement) = 0;

    virtual CARAPI CreateStatement(
        /* [in] */ _ELASTOS Int32 resultSetType,
        /* [in] */ _ELASTOS Int32 resultSetConcurrency,
        /* [out] */ Elastos::Sql::IStatement ** statement) = 0;

    virtual CARAPI CreateStatement(
        /* [in] */ _ELASTOS Int32 resultSetType,
        /* [in] */ _ELASTOS Int32 resultSetConcurrency,
        /* [in] */ _ELASTOS Int32 resultSetHoldability,
        /* [out] */ Elastos::Sql::IStatement ** statement) = 0;

    virtual CARAPI GetAutoCommit(
        /* [out] */ _ELASTOS Boolean * autoValue) = 0;

    virtual CARAPI GetCatalog(
        /* [out] */ _ELASTOS String * catelog) = 0;

    virtual CARAPI GetHoldability(
        /* [out] */ _ELASTOS Int32 * holdability) = 0;

    virtual CARAPI GetMetaData(
        /* [out] */ Elastos::Sql::IDatabaseMetaData ** metadata) = 0;

    virtual CARAPI GetTransactionIsolation(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetTypeMap(
        /* [out] */ Elastos::Utility::IMap ** typemap) = 0;

    virtual CARAPI GetWarnings(
        /* [out] */ Elastos::Sql::ISQLWarning ** warning) = 0;

    virtual CARAPI IsClosed(
        /* [out] */ _ELASTOS Boolean * isClosed) = 0;

    virtual CARAPI IsReadOnly(
        /* [out] */ _ELASTOS Boolean * isReadOnly) = 0;

    virtual CARAPI NativeSQL(
        /* [in] */ const _ELASTOS String& sql,
        /* [out] */ _ELASTOS String * nsql) = 0;

    virtual CARAPI PrepareCall(
        /* [in] */ const _ELASTOS String& sql,
        /* [out] */ Elastos::Sql::ICallableStatement ** callableStatement) = 0;

    virtual CARAPI PrepareCall(
        /* [in] */ const _ELASTOS String& sql,
        /* [in] */ _ELASTOS Int32 resultSetType,
        /* [in] */ _ELASTOS Int32 resultSetConcurrency,
        /* [out] */ Elastos::Sql::ICallableStatement ** callableStatement) = 0;

    virtual CARAPI PrepareCall(
        /* [in] */ const _ELASTOS String& sql,
        /* [in] */ _ELASTOS Int32 resultSetType,
        /* [in] */ _ELASTOS Int32 resultSetConcurrency,
        /* [in] */ _ELASTOS Int32 resultSetHoldability,
        /* [out] */ Elastos::Sql::ICallableStatement ** callableStatement) = 0;

    virtual CARAPI PrepareStatement(
        /* [in] */ const _ELASTOS String& sql,
        /* [out] */ Elastos::Sql::IPreparedStatement ** preparedStatement) = 0;

    virtual CARAPI PrepareStatement(
        /* [in] */ const _ELASTOS String& sql,
        /* [in] */ _ELASTOS Int32 autoGeneratedKeys,
        /* [out] */ Elastos::Sql::IPreparedStatement ** preparedStatement) = 0;

    virtual CARAPI PrepareStatement(
        /* [in] */ const _ELASTOS String& sql,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int32> & columnIndexes,
        /* [out] */ Elastos::Sql::IPreparedStatement ** preparedStatement) = 0;

    virtual CARAPI PrepareStatement(
        /* [in] */ const _ELASTOS String& sql,
        /* [in] */ _ELASTOS Int32 resultSetType,
        /* [in] */ _ELASTOS Int32 resultSetConcurrency,
        /* [out] */ Elastos::Sql::IPreparedStatement ** statement) = 0;

    virtual CARAPI PrepareStatement(
        /* [in] */ const _ELASTOS String& sql,
        /* [in] */ _ELASTOS Int32 resultSetType,
        /* [in] */ _ELASTOS Int32 resultSetConcurrency,
        /* [in] */ _ELASTOS Int32 resultSetHoldability,
        /* [out] */ Elastos::Sql::IPreparedStatement ** preparedStatement) = 0;

    virtual CARAPI PrepareStatement(
        /* [in] */ const _ELASTOS String& sql,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS String> & columnNames,
        /* [out] */ Elastos::Sql::IPreparedStatement ** preparedStatement) = 0;

    virtual CARAPI ReleaseSavepoint(
        /* [in] */ Elastos::Sql::ISavePoint * savepoint) = 0;

    virtual CARAPI Rollback() = 0;

    virtual CARAPI Rollback(
        /* [in] */ Elastos::Sql::ISavePoint * savepoint) = 0;

    virtual CARAPI SetAutoCommit(
        /* [in] */ _ELASTOS Boolean autoCommit) = 0;

    virtual CARAPI SetCatalog(
        /* [in] */ const _ELASTOS String& catalog) = 0;

    virtual CARAPI SetHoldability(
        /* [in] */ _ELASTOS Int32 holdability) = 0;

    virtual CARAPI SetReadOnly(
        /* [in] */ _ELASTOS Boolean readOnly) = 0;

    virtual CARAPI SetSavepoint(
        /* [out] */ Elastos::Sql::ISavePoint ** savepoint) = 0;

    virtual CARAPI SetSavepoint(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Sql::ISavePoint ** savepoint) = 0;

    virtual CARAPI SetTransactionIsolation(
        /* [in] */ _ELASTOS Int32 level) = 0;

    virtual CARAPI SetTypeMap(
        /* [in] */ Elastos::Utility::IMap * typemap) = 0;

    virtual CARAPI CreateClob(
        /* [out] */ Elastos::Sql::IClob ** clob) = 0;

    virtual CARAPI CreateBlob(
        /* [out] */ Elastos::Sql::IBlob ** blob) = 0;

    virtual CARAPI CreateNClob(
        /* [out] */ Elastos::Sql::INClob ** nclob) = 0;

    virtual CARAPI CreateSQLXML(
        /* [out] */ Elastos::Sql::ISQLXML ** sqlXML) = 0;

    virtual CARAPI IsValid(
        /* [in] */ _ELASTOS Int32 timeout,
        /* [out] */ _ELASTOS Boolean * valid) = 0;

    virtual CARAPI SetClientInfo(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI SetClientInfo(
        /* [in] */ Elastos::Utility::IProperties * properties) = 0;

    virtual CARAPI GetClientInfo(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS String * info) = 0;

    virtual CARAPI GetClientInfo(
        /* [out] */ Elastos::Utility::IProperties ** properties) = 0;

    virtual CARAPI CreateArrayOf(
        /* [in] */ const _ELASTOS String& typeName,
        /* [in] */ const _ELASTOS ArrayOf<IInterface *> & elements,
        /* [out] */ Elastos::Sql::IArray ** iarray) = 0;

    virtual CARAPI CreateStruct(
        /* [in] */ const _ELASTOS String& typeName,
        /* [in] */ const _ELASTOS ArrayOf<IInterface *> & attributes,
        /* [out] */ Elastos::Sql::IStruct ** istruct) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("1ABF5F58-9352-358D-7E38-2829C3C60F0E")
IDriver : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDriver*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDriver*)pObj->Probe(EIID_IDriver);
    }

    static CARAPI_(IDriver*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDriver*)pObj->Probe(EIID_IDriver);
    }

    virtual CARAPI AcceptsURL(
        /* [in] */ const _ELASTOS String& url,
        /* [out] */ _ELASTOS Boolean * canOpen) = 0;

    virtual CARAPI Connect(
        /* [in] */ const _ELASTOS String& url,
        /* [in] */ Elastos::Utility::IProperties * info,
        /* [out] */ Elastos::Sql::IConnection ** connection) = 0;

    virtual CARAPI GetMajorVersion(
        /* [out] */ _ELASTOS Int32 * ver) = 0;

    virtual CARAPI GetMinorVersion(
        /* [out] */ _ELASTOS Int32 * ver) = 0;

    virtual CARAPI GetPropertyInfo(
        /* [in] */ const _ELASTOS String& url,
        /* [in] */ Elastos::Utility::IProperties * info,
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Sql::IDriverPropertyInfo *> ** array) = 0;

    virtual CARAPI JdbcCompliant(
        /* [out] */ _ELASTOS Boolean * isCompliant) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("4C32C826-8352-2C1A-72DC-5FF9A3BD8D1B")
IDriverManager : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDriverManager*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDriverManager*)pObj->Probe(EIID_IDriverManager);
    }

    static CARAPI_(IDriverManager*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDriverManager*)pObj->Probe(EIID_IDriverManager);
    }

    virtual CARAPI DeregisterDriver(
        /* [in] */ Elastos::Sql::IDriver * driver) = 0;

    virtual CARAPI GetConnection(
        /* [in] */ const _ELASTOS String& url,
        /* [out] */ Elastos::Sql::IConnection ** conn) = 0;

    virtual CARAPI GetConnection(
        /* [in] */ const _ELASTOS String& url,
        /* [in] */ Elastos::Utility::IProperties * info,
        /* [out] */ Elastos::Sql::IConnection ** conn) = 0;

    virtual CARAPI GetConnection(
        /* [in] */ const _ELASTOS String& url,
        /* [in] */ const _ELASTOS String& user,
        /* [in] */ const _ELASTOS String& password,
        /* [out] */ Elastos::Sql::IConnection ** conn) = 0;

    virtual CARAPI GetDriver(
        /* [in] */ const _ELASTOS String& url,
        /* [out] */ Elastos::Sql::IDriver ** driver) = 0;

    virtual CARAPI GetDrivers(
        /* [out] */ Elastos::Utility::IEnumeration ** enumeration) = 0;

    virtual CARAPI GetLoginTimeout(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetLogStream(
        /* [out] */ Elastos::IO::IPrintStream ** pntstream) = 0;

    virtual CARAPI GetLogWriter(
        /* [out] */ Elastos::IO::IPrintWriter ** pntwriter) = 0;

    virtual CARAPI Println(
        /* [in] */ const _ELASTOS String& message) = 0;

    virtual CARAPI RegisterDriver(
        /* [in] */ Elastos::Sql::IDriver * driver) = 0;

    virtual CARAPI SetLoginTimeout(
        /* [in] */ _ELASTOS Int32 seconds) = 0;

    virtual CARAPI SetLogStream(
        /* [in] */ Elastos::IO::IPrintStream * pntstream) = 0;

    virtual CARAPI SetLogWriter(
        /* [in] */ Elastos::IO::IPrintWriter * pntwriter) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("773E5146-0352-7146-6E73-FAE1A0A40C1B")
IDataTruncation : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDataTruncation*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDataTruncation*)pObj->Probe(EIID_IDataTruncation);
    }

    static CARAPI_(IDataTruncation*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDataTruncation*)pObj->Probe(EIID_IDataTruncation);
    }

    virtual CARAPI GetDataSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetIndex(
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetParameter(
        /* [out] */ _ELASTOS Boolean * isPara) = 0;

    virtual CARAPI GetRead(
        /* [out] */ _ELASTOS Boolean * isRead) = 0;

    virtual CARAPI GetTransferSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("55612055-9352-358D-32F0-0DEB9787961F")
IDriverPropertyInfo : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDriverPropertyInfo*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDriverPropertyInfo*)pObj->Probe(EIID_IDriverPropertyInfo);
    }

    static CARAPI_(IDriverPropertyInfo*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDriverPropertyInfo*)pObj->Probe(EIID_IDriverPropertyInfo);
    }

};
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("5A803B21-6C12-3560-22A0-7831E3FE8FF6")
IStringEncoderHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IStringEncoderHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStringEncoderHelper*)pObj->Probe(EIID_IStringEncoderHelper);
    }

    static CARAPI_(IStringEncoderHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStringEncoderHelper*)pObj->Probe(EIID_IStringEncoderHelper);
    }

    virtual CARAPI Encode(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * a,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI Decode(
        /* [in] */ const _ELASTOS String& s,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** outarray) = 0;

    virtual CARAPI EncodeX(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * a,
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("AB1D2849-0292-A31C-F58A-AFF1C3414919")
IAuthorizer : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAuthorizer*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAuthorizer*)pObj->Probe(EIID_IAuthorizer);
    }

    static CARAPI_(IAuthorizer*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAuthorizer*)pObj->Probe(EIID_IAuthorizer);
    }

    virtual CARAPI Authorize(
        /* [in] */ _ELASTOS Int32 what,
        /* [in] */ const _ELASTOS String& arg1,
        /* [in] */ const _ELASTOS String& arg2,
        /* [in] */ const _ELASTOS String& arg3,
        /* [in] */ const _ELASTOS String& arg4,
        /* [out] */ _ELASTOS Int32 * code) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("6A7B1A10-F2D2-E5CA-F63B-2F69DFB2FD73")
IBlobR : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBlobR*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBlobR*)pObj->Probe(EIID_IBlobR);
    }

    static CARAPI_(IBlobR*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBlobR*)pObj->Probe(EIID_IBlobR);
    }

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("1DBF1F1E-F2D2-25CA-F83B-2F69DFB2FD73")
IBlobW : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBlobW*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBlobW*)pObj->Probe(EIID_IBlobW);
    }

    static CARAPI_(IBlobW*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBlobW*)pObj->Probe(EIID_IBlobW);
    }

    virtual CARAPI Flush() = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("79023B12-F2D2-E5CA-EFBC-A47DCBF6CFD1")
IBlob : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBlob*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBlob*)pObj->Probe(EIID_IBlob);
    }

    static CARAPI_(IBlob*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBlob*)pObj->Probe(EIID_IBlob);
    }

    virtual CARAPI GetInputStream(
        /* [out] */ Elastos::IO::IInputStream ** instream) = 0;

    virtual CARAPI GetOutputStream(
        /* [out] */ Elastos::IO::IOutputStream ** outstream) = 0;

    virtual CARAPI Close() = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("02272F38-9C52-ED1F-6DDC-9061E307071A")
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

    virtual CARAPI Columns(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * coldata) = 0;

    virtual CARAPI Types(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * types) = 0;

    virtual CARAPI Newrow(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * rowdata,
        /* [out] */ _ELASTOS Boolean * value) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("347A2432-02D2-361C-789C-FBD1DEC60D19")
IBusyHandler : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBusyHandler*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBusyHandler*)pObj->Probe(EIID_IBusyHandler);
    }

    static CARAPI_(IBusyHandler*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBusyHandler*)pObj->Probe(EIID_IBusyHandler);
    }

    virtual CARAPI Busy(
        /* [in] */ const _ELASTOS String& table,
        /* [in] */ _ELASTOS Int32 count,
        /* [out] */ _ELASTOS Boolean * value) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("C3A02523-EF52-3FC3-DADB-B821C3C60F0E")
ITableResult : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITableResult*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITableResult*)pObj->Probe(EIID_ITableResult);
    }

    static CARAPI_(ITableResult*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITableResult*)pObj->Probe(EIID_ITableResult);
    }

    virtual CARAPI Clear() = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("DFB7662B-3852-3206-62DC-40B1E3C68FF6")
IFunctionContext : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFunctionContext*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFunctionContext*)pObj->Probe(EIID_IFunctionContext);
    }

    static CARAPI_(IFunctionContext*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFunctionContext*)pObj->Probe(EIID_IFunctionContext);
    }

    virtual CARAPI SetResult(
        /* [in] */ const _ELASTOS String& r) = 0;

    virtual CARAPI SetResult(
        /* [in] */ _ELASTOS Int32 r) = 0;

    virtual CARAPI SetResult(
        /* [in] */ _ELASTOS Double r) = 0;

    virtual CARAPI SetError(
        /* [in] */ const _ELASTOS String& r) = 0;

    virtual CARAPI SetResult(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & r) = 0;

    virtual CARAPI SetResultZeroblob(
        /* [in] */ _ELASTOS Int32 n) = 0;

    virtual CARAPI Count(
        /* [out] */ _ELASTOS Int32 * count) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("C0943132-B852-ED1F-6DDC-9061E307071A")
IFunction : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFunction*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFunction*)pObj->Probe(EIID_IFunction);
    }

    static CARAPI_(IFunction*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFunction*)pObj->Probe(EIID_IFunction);
    }

    virtual CARAPI Function(
        /* [in] */ Elastos::Sql::SQLite::IFunctionContext * fc,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS String> & args) = 0;

    virtual CARAPI Step(
        /* [in] */ Elastos::Sql::SQLite::IFunctionContext * fc,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS String> & args) = 0;

    virtual CARAPI LastStep(
        /* [in] */ Elastos::Sql::SQLite::IFunctionContext * fc) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("18BE1F3B-F1D2-ED1F-6DDC-9061E307071A")
ITrace : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITrace*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITrace*)pObj->Probe(EIID_ITrace);
    }

    static CARAPI_(ITrace*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITrace*)pObj->Probe(EIID_ITrace);
    }

    virtual CARAPI Trace(
        /* [in] */ const _ELASTOS String& stmt) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("35DB2351-0652-DDBE-52FE-705052868D1F")
IProfile : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IProfile*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IProfile*)pObj->Probe(EIID_IProfile);
    }

    static CARAPI_(IProfile*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IProfile*)pObj->Probe(EIID_IProfile);
    }

    virtual CARAPI Profile(
        /* [in] */ const _ELASTOS String& stmt,
        /* [in] */ _ELASTOS Int64 est) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("1FC4261C-07D2-CEFF-4BDA-B76CFF1CFDFE")
IVm : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IVm*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IVm*)pObj->Probe(EIID_IVm);
    }

    static CARAPI_(IVm*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IVm*)pObj->Probe(EIID_IVm);
    }

    virtual CARAPI Step(
        /* [in] */ Elastos::Sql::SQLite::ICallback * cb,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Compile(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Stop() = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("A092F41D-7712-F7C3-EFBC-A47DCBF6CFD1")
IStmt : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IStmt*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStmt*)pObj->Probe(EIID_IStmt);
    }

    static CARAPI_(IStmt*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStmt*)pObj->Probe(EIID_IStmt);
    }

    virtual CARAPI Prepare(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Step(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Close() = 0;

    virtual CARAPI Reset() = 0;

    virtual CARAPI ClearBindings() = 0;

    virtual CARAPI Bind(
        /* [in] */ _ELASTOS Int32 pos,
        /* [in] */ _ELASTOS Int32 value) = 0;

    virtual CARAPI Bind(
        /* [in] */ _ELASTOS Int32 pos,
        /* [in] */ _ELASTOS Int64 value) = 0;

    virtual CARAPI Bind(
        /* [in] */ _ELASTOS Int32 pos,
        /* [in] */ _ELASTOS Double value) = 0;

    virtual CARAPI Bind(
        /* [in] */ _ELASTOS Int32 pos,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & value) = 0;

    virtual CARAPI Bind(
        /* [in] */ _ELASTOS Int32 pos,
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI Bind(
        /* [in] */ _ELASTOS Int32 pos) = 0;

    virtual CARAPI BindZeroblob(
        /* [in] */ _ELASTOS Int32 pos,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI BindParameterCount(
        /* [out] */ _ELASTOS Int32 * count) = 0;

    virtual CARAPI BindParameterName(
        /* [in] */ _ELASTOS Int32 pos,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI BindParameterIndex(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI ColumnInt(
        /* [in] */ _ELASTOS Int32 col,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI ColumnLong(
        /* [in] */ _ELASTOS Int32 col,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI ColumnDouble(
        /* [in] */ _ELASTOS Int32 col,
        /* [out] */ _ELASTOS Double * value) = 0;

    virtual CARAPI ColumnBytes(
        /* [in] */ _ELASTOS Int32 col,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** array) = 0;

    virtual CARAPI ColumnString(
        /* [in] */ _ELASTOS Int32 col,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI ColumnType(
        /* [in] */ _ELASTOS Int32 col,
        /* [out] */ _ELASTOS Int32 * type) = 0;

    virtual CARAPI ColumnCount(
        /* [out] */ _ELASTOS Int32 * count) = 0;

    virtual CARAPI Column(
        /* [in] */ _ELASTOS Int32 col,
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI ColumnTableName(
        /* [in] */ _ELASTOS Int32 col,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI ColumnDatabaseName(
        /* [in] */ _ELASTOS Int32 col,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI ColumnDecltype(
        /* [in] */ _ELASTOS Int32 col,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI ColumnOriginName(
        /* [in] */ _ELASTOS Int32 col,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI Status(
        /* [in] */ _ELASTOS Int32 op,
        /* [in] */ _ELASTOS Boolean flg,
        /* [out] */ _ELASTOS Int32 * value) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("69563D0E-42D2-2E9A-3EFF-CE4BDAB76CFF")
IBackup : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBackup*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBackup*)pObj->Probe(EIID_IBackup);
    }

    static CARAPI_(IBackup*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBackup*)pObj->Probe(EIID_IBackup);
    }

    virtual CARAPI Finish() = 0;

    virtual CARAPI Step(
        /* [in] */ _ELASTOS Int32 n,
        /* [out] */ _ELASTOS Boolean * isCompleted) = 0;

    virtual CARAPI Backup() = 0;

    virtual CARAPI Remaining(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Pagecount(
        /* [out] */ _ELASTOS Int32 * number) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("80C62C3F-8652-321A-54D4-C06FE3DC8FF6")
IProgressHandler : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IProgressHandler*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IProgressHandler*)pObj->Probe(EIID_IProgressHandler);
    }

    static CARAPI_(IProgressHandler*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IProgressHandler*)pObj->Probe(EIID_IProgressHandler);
    }

    virtual CARAPI Progress(
        /* [out] */ _ELASTOS Boolean * value) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("28EFFC5A-0352-9246-06FF-705052868D1F")
IDatabase : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDatabase*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatabase*)pObj->Probe(EIID_IDatabase);
    }

    static CARAPI_(IDatabase*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatabase*)pObj->Probe(EIID_IDatabase);
    }

    virtual CARAPI Open(
        /* [in] */ const _ELASTOS String& filename,
        /* [in] */ _ELASTOS Int32 mode) = 0;

    virtual CARAPI Open(
        /* [in] */ const _ELASTOS String& filename,
        /* [in] */ _ELASTOS Int32 mode,
        /* [in] */ const _ELASTOS String& vfs) = 0;

    virtual CARAPI Open(
        /* [in] */ const _ELASTOS String& filename,
        /* [in] */ _ELASTOS Int32 mode,
        /* [in] */ const _ELASTOS String& vfs,
        /* [in] */ _ELASTOS Boolean ver2) = 0;

    virtual CARAPI OpenAuxFile(
        /* [in] */ const _ELASTOS String& filename) = 0;

    virtual CARAPI Close() = 0;

    virtual CARAPI Exec(
        /* [in] */ const _ELASTOS String& sql,
        /* [in] */ Elastos::Sql::SQLite::ICallback * cb) = 0;

    virtual CARAPI Exec(
        /* [in] */ const _ELASTOS String& sql,
        /* [in] */ Elastos::Sql::SQLite::ICallback * cb,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * args) = 0;

    virtual CARAPI LastInsertRowid(
        /* [out] */ _ELASTOS Int64 * id) = 0;

    virtual CARAPI Interrupt() = 0;

    virtual CARAPI Changes(
        /* [out] */ _ELASTOS Int64 * number) = 0;

    virtual CARAPI BusyHandler(
        /* [in] */ Elastos::Sql::SQLite::IBusyHandler * bh) = 0;

    virtual CARAPI BusyTimeout(
        /* [in] */ _ELASTOS Int32 ms) = 0;

    virtual CARAPI GetTable(
        /* [in] */ const _ELASTOS String& sql,
        /* [in] */ _ELASTOS Int32 maxrows,
        /* [out] */ Elastos::Sql::SQLite::ITableResult ** tableresult) = 0;

    virtual CARAPI GetTable(
        /* [in] */ const _ELASTOS String& sql,
        /* [out] */ Elastos::Sql::SQLite::ITableResult ** tableresult) = 0;

    virtual CARAPI GetTable(
        /* [in] */ const _ELASTOS String& sql,
        /* [in] */ _ELASTOS Int32 maxrows,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * args,
        /* [out] */ Elastos::Sql::SQLite::ITableResult ** tableresult) = 0;

    virtual CARAPI GetTable(
        /* [in] */ const _ELASTOS String& sql,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * args,
        /* [out] */ Elastos::Sql::SQLite::ITableResult ** tableresult) = 0;

    virtual CARAPI GetTable(
        /* [in] */ const _ELASTOS String& sql,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * args,
        /* [in] */ Elastos::Sql::SQLite::ITableResult * tbl) = 0;

    virtual CARAPI Dbversion(
        /* [out] */ _ELASTOS String * ver) = 0;

    virtual CARAPI CreateFunction(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Int32 nargs,
        /* [in] */ Elastos::Sql::SQLite::IFunction * f) = 0;

    virtual CARAPI CreateAggregate(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Int32 nargs,
        /* [in] */ Elastos::Sql::SQLite::IFunction * f) = 0;

    virtual CARAPI FunctionType(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Int32 type) = 0;

    virtual CARAPI LastError(
        /* [out] */ _ELASTOS Int32 * error_code) = 0;

    virtual CARAPI SetLastError(
        /* [in] */ _ELASTOS Int32 error_code) = 0;

    virtual CARAPI ErrorMessage(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI SetEncoding(
        /* [in] */ const _ELASTOS String& enc) = 0;

    virtual CARAPI SetAuthorizer(
        /* [in] */ Elastos::Sql::SQLite::IAuthorizer * auth) = 0;

    virtual CARAPI Trace(
        /* [in] */ Elastos::Sql::SQLite::ITrace * tr) = 0;

    virtual CARAPI Backup(
        /* [in] */ Elastos::Sql::SQLite::IDatabase * dest,
        /* [in] */ const _ELASTOS String& destName,
        /* [in] */ const _ELASTOS String& srcName,
        /* [out] */ Elastos::Sql::SQLite::IBackup ** backup) = 0;

    virtual CARAPI Profile(
        /* [in] */ Elastos::Sql::SQLite::IProfile * pr) = 0;

    virtual CARAPI DbStatus(
        /* [in] */ _ELASTOS Int32 op,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * info,
        /* [in] */ _ELASTOS Boolean flag,
        /* [out] */ _ELASTOS Int32 * code) = 0;

    virtual CARAPI Compile(
        /* [in] */ const _ELASTOS String& sql,
        /* [out] */ Elastos::Sql::SQLite::IVm ** vm) = 0;

    virtual CARAPI Compile(
        /* [in] */ const _ELASTOS String& sql,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * args,
        /* [out] */ Elastos::Sql::SQLite::IVm ** vm) = 0;

    virtual CARAPI Prepare(
        /* [in] */ const _ELASTOS String& sql,
        /* [out] */ Elastos::Sql::SQLite::IStmt ** st) = 0;

    virtual CARAPI OpenBlob(
        /* [in] */ const _ELASTOS String& db,
        /* [in] */ const _ELASTOS String& table,
        /* [in] */ const _ELASTOS String& column,
        /* [in] */ _ELASTOS Int64 row,
        /* [in] */ _ELASTOS Boolean rw,
        /* [out] */ Elastos::Sql::SQLite::IBlob ** bl) = 0;

    virtual CARAPI Is3(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI ProgressHandler(
        /* [in] */ _ELASTOS Int32 n,
        /* [in] */ Elastos::Sql::SQLite::IProgressHandler * p) = 0;

    virtual CARAPI Key(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * ekey) = 0;

    virtual CARAPI Key(
        /* [in] */ const _ELASTOS String& skey) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("75F16D05-4352-64DE-49DA-6884BE335AFF")
IDatabaseHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDatabaseHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatabaseHelper*)pObj->Probe(EIID_IDatabaseHelper);
    }

    static CARAPI_(IDatabaseHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDatabaseHelper*)pObj->Probe(EIID_IDatabaseHelper);
    }

    virtual CARAPI Complete(
        /* [in] */ const _ELASTOS String& sql,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Version(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI ErrorString(
        /* [in] */ _ELASTOS Int32 error_code,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI Status(
        /* [in] */ _ELASTOS Int32 op,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * info,
        /* [in] */ _ELASTOS Boolean flag,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI LongFromJulian(
        /* [in] */ _ELASTOS Double d,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI LongFromJulian(
        /* [in] */ const _ELASTOS String& s,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI JulianFromLong(
        /* [in] */ _ELASTOS Int64 ms,
        /* [out] */ _ELASTOS Double * value) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("A4B83722-0592-2619-5C84-FBD1DEC60D19")
IMockFunction : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMockFunction*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMockFunction*)pObj->Probe(EIID_IMockFunction);
    }

    static CARAPI_(IMockFunction*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMockFunction*)pObj->Probe(EIID_IMockFunction);
    }

    virtual CARAPI GetAggValue(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI PrintCalled() = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("66911E46-1112-82C8-6ED8-F8E1A0A40C1B")
IConstants : public IInterface
{
    static const _ELASTOS Int32 drv_minor = 20100131;
    static const _ELASTOS Int32 SQLITE_VERSION_NUMBER = 3006022;
    static const _ELASTOS Int32 SQLITE_OK = 0;
    static const _ELASTOS Int32 SQLITE_ERROR = 1;
    static const _ELASTOS Int32 SQLITE_INTERNAL = 2;
    static const _ELASTOS Int32 SQLITE_PERM = 3;
    static const _ELASTOS Int32 SQLITE_ABORT = 4;
    static const _ELASTOS Int32 SQLITE_BUSY = 5;
    static const _ELASTOS Int32 SQLITE_LOCKED = 6;
    static const _ELASTOS Int32 SQLITE_NOMEM = 7;
    static const _ELASTOS Int32 SQLITE_READONLY = 8;
    static const _ELASTOS Int32 SQLITE_INTERRUPT = 9;
    static const _ELASTOS Int32 SQLITE_IOERR = 10;
    static const _ELASTOS Int32 SQLITE_CORRUPT = 11;
    static const _ELASTOS Int32 SQLITE_NOTFOUND = 12;
    static const _ELASTOS Int32 SQLITE_FULL = 13;
    static const _ELASTOS Int32 SQLITE_CANTOPEN = 14;
    static const _ELASTOS Int32 SQLITE_PROTOCOL = 15;
    static const _ELASTOS Int32 SQLITE_EMPTY = 16;
    static const _ELASTOS Int32 SQLITE_SCHEMA = 17;
    static const _ELASTOS Int32 SQLITE_TOOBIG = 18;
    static const _ELASTOS Int32 SQLITE_CONSTRAINT = 19;
    static const _ELASTOS Int32 SQLITE_MISMATCH = 20;
    static const _ELASTOS Int32 SQLITE_MISUSE = 21;
    static const _ELASTOS Int32 SQLITE_NOLFS = 22;
    static const _ELASTOS Int32 SQLITE_AUTH = 23;
    static const _ELASTOS Int32 SQLITE_FORMAT = 24;
    static const _ELASTOS Int32 SQLITE_RANGE = 25;
    static const _ELASTOS Int32 SQLITE_NOTADB = 26;
    static const _ELASTOS Int32 SQLITE_ROW = 100;
    static const _ELASTOS Int32 SQLITE_DONE = 101;
    static const _ELASTOS Int32 SQLITE_OPEN_READONLY = 0x00000001;
    static const _ELASTOS Int32 SQLITE_OPEN_READWRITE = 0x00000002;
    static const _ELASTOS Int32 SQLITE_OPEN_CREATE = 0x00000004;
    static const _ELASTOS Int32 SQLITE_OPEN_DELETEONCLOSE = 0x00000008;
    static const _ELASTOS Int32 SQLITE_OPEN_EXCLUSIVE = 0x00000010;
    static const _ELASTOS Int32 SQLITE_OPEN_MAIN_DB = 0x00000100;
    static const _ELASTOS Int32 SQLITE_OPEN_TEMP_DB = 0x00000200;
    static const _ELASTOS Int32 SQLITE_OPEN_TRANSIENT_DB = 0x00000400;
    static const _ELASTOS Int32 SQLITE_OPEN_MAIN_JOURNAL = 0x00000800;
    static const _ELASTOS Int32 SQLITE_OPEN_TEMP_JOURNAL = 0x00001000;
    static const _ELASTOS Int32 SQLITE_OPEN_SUBJOURNAL = 0x00002000;
    static const _ELASTOS Int32 SQLITE_OPEN_MASTER_JOURNAL = 0x00004000;
    static const _ELASTOS Int32 SQLITE_OPEN_NOMUTEX = 0x00008000;
    static const _ELASTOS Int32 SQLITE_OPEN_FULLMUTEX = 0x00010000;
    static const _ELASTOS Int32 SQLITE_OPEN_SHAREDCACHE = 0x00020000;
    static const _ELASTOS Int32 SQLITE_OPEN_PRIVATECACHE = 0x00040000;
    static const _ELASTOS Int32 SQLITE_IOCAP_ATOMIC = 0x00000001;
    static const _ELASTOS Int32 SQLITE_IOCAP_ATOMIC512 = 0x00000002;
    static const _ELASTOS Int32 SQLITE_IOCAP_ATOMIC1K = 0x00000004;
    static const _ELASTOS Int32 SQLITE_IOCAP_ATOMIC2K = 0x00000008;
    static const _ELASTOS Int32 SQLITE_IOCAP_ATOMIC4K = 0x00000010;
    static const _ELASTOS Int32 SQLITE_IOCAP_ATOMIC8K = 0x00000020;
    static const _ELASTOS Int32 SQLITE_IOCAP_ATOMIC16K = 0x00000040;
    static const _ELASTOS Int32 SQLITE_IOCAP_ATOMIC32K = 0x00000080;
    static const _ELASTOS Int32 SQLITE_IOCAP_ATOMIC64K = 0x00000100;
    static const _ELASTOS Int32 SQLITE_IOCAP_SAFE_APPEND = 0x00000200;
    static const _ELASTOS Int32 SQLITE_IOCAP_SEQUENTIAL = 0x00000400;
    static const _ELASTOS Int32 SQLITE_LOCK_NONE = 0;
    static const _ELASTOS Int32 SQLITE_LOCK_SHARED = 1;
    static const _ELASTOS Int32 SQLITE_LOCK_RESERVED = 2;
    static const _ELASTOS Int32 SQLITE_LOCK_PENDING = 3;
    static const _ELASTOS Int32 SQLITE_LOCK_EXCLUSIVE = 4;
    static const _ELASTOS Int32 SQLITE_SYNC_NORMAL = 0x00000002;
    static const _ELASTOS Int32 SQLITE_SYNC_FULL = 0x00000003;
    static const _ELASTOS Int32 SQLITE_SYNC_DATAONLY = 0x00000010;
    static const _ELASTOS Int32 SQLITE_FCNTL_LOCKSTATE = 1;
    static const _ELASTOS Int32 SQLITE_GET_LOCKPROXYFILE = 2;
    static const _ELASTOS Int32 SQLITE_SET_LOCKPROXYFILE = 3;
    static const _ELASTOS Int32 SQLITE_LAST_ERRNO = 4;
    static const _ELASTOS Int32 SQLITE_ACCESS_EXISTS = 0;
    static const _ELASTOS Int32 SQLITE_ACCESS_READWRITE = 1;
    static const _ELASTOS Int32 SQLITE_ACCESS_READ = 2;
    static const _ELASTOS Int32 SQLITE_CONFIG_SINGLETHREAD = 1;
    static const _ELASTOS Int32 SQLITE_CONFIG_MULTITHREAD = 2;
    static const _ELASTOS Int32 SQLITE_CONFIG_SERIALIZED = 3;
    static const _ELASTOS Int32 SQLITE_CONFIG_MALLOC = 4;
    static const _ELASTOS Int32 SQLITE_CONFIG_GETMALLOC = 5;
    static const _ELASTOS Int32 SQLITE_CONFIG_SCRATCH = 6;
    static const _ELASTOS Int32 SQLITE_CONFIG_PAGECACHE = 7;
    static const _ELASTOS Int32 SQLITE_CONFIG_HEAP = 8;
    static const _ELASTOS Int32 SQLITE_CONFIG_MEMSTATUS = 9;
    static const _ELASTOS Int32 SQLITE_CONFIG_MUTEX = 10;
    static const _ELASTOS Int32 SQLITE_CONFIG_GETMUTEX = 11;
    static const _ELASTOS Int32 SQLITE_CONFIG_LOOKASIDE = 13;
    static const _ELASTOS Int32 SQLITE_CONFIG_PCACHE = 14;
    static const _ELASTOS Int32 SQLITE_CONFIG_GETPCACHE = 15;
    static const _ELASTOS Int32 SQLITE_DBCONFIG_LOOKASIDE = 1001;
    static const _ELASTOS Int32 SQLITE_DENY = 1;
    static const _ELASTOS Int32 SQLITE_IGNORE = 2;
    static const _ELASTOS Int32 SQLITE_CREATE_INDEX = 1;
    static const _ELASTOS Int32 SQLITE_CREATE_TABLE = 2;
    static const _ELASTOS Int32 SQLITE_CREATE_TEMP_INDEX = 3;
    static const _ELASTOS Int32 SQLITE_CREATE_TEMP_TABLE = 4;
    static const _ELASTOS Int32 SQLITE_CREATE_TEMP_TRIGGER = 5;
    static const _ELASTOS Int32 SQLITE_CREATE_TEMP_VIEW = 6;
    static const _ELASTOS Int32 SQLITE_CREATE_TRIGGER = 7;
    static const _ELASTOS Int32 SQLITE_CREATE_VIEW = 8;
    static const _ELASTOS Int32 SQLITE_DELETE = 9;
    static const _ELASTOS Int32 SQLITE_DROP_INDEX = 10;
    static const _ELASTOS Int32 SQLITE_DROP_TABLE = 11;
    static const _ELASTOS Int32 SQLITE_DROP_TEMP_INDEX = 12;
    static const _ELASTOS Int32 SQLITE_DROP_TEMP_TABLE = 13;
    static const _ELASTOS Int32 SQLITE_DROP_TEMP_TRIGGER = 14;
    static const _ELASTOS Int32 SQLITE_DROP_TEMP_VIEW = 15;
    static const _ELASTOS Int32 SQLITE_DROP_TRIGGER = 16;
    static const _ELASTOS Int32 SQLITE_DROP_VIEW = 17;
    static const _ELASTOS Int32 SQLITE_INSERT = 18;
    static const _ELASTOS Int32 SQLITE_PRAGMA = 19;
    static const _ELASTOS Int32 SQLITE_READ = 20;
    static const _ELASTOS Int32 SQLITE_SELECT = 21;
    static const _ELASTOS Int32 SQLITE_TRANSACTION = 22;
    static const _ELASTOS Int32 SQLITE_UPDATE = 23;
    static const _ELASTOS Int32 SQLITE_ATTACH = 24;
    static const _ELASTOS Int32 SQLITE_DETACH = 25;
    static const _ELASTOS Int32 SQLITE_ALTER_TABLE = 26;
    static const _ELASTOS Int32 SQLITE_REINDEX = 27;
    static const _ELASTOS Int32 SQLITE_ANALYZE = 28;
    static const _ELASTOS Int32 SQLITE_CREATE_VTABLE = 29;
    static const _ELASTOS Int32 SQLITE_DROP_VTABLE = 30;
    static const _ELASTOS Int32 SQLITE_FUNCTION = 31;
    static const _ELASTOS Int32 SQLITE_SAVEPOINT = 32;
    static const _ELASTOS Int32 SQLITE_COPY = 0;
    static const _ELASTOS Int32 SQLITE_LIMIT_LENGTH = 0;
    static const _ELASTOS Int32 SQLITE_LIMIT_SQL_LENGTH = 1;
    static const _ELASTOS Int32 SQLITE_LIMIT_COLUMN = 2;
    static const _ELASTOS Int32 SQLITE_LIMIT_EXPR_DEPTH = 3;
    static const _ELASTOS Int32 SQLITE_LIMIT_COMPOUND_SELECT = 4;
    static const _ELASTOS Int32 SQLITE_LIMIT_VDBE_OP = 5;
    static const _ELASTOS Int32 SQLITE_LIMIT_FUNCTION_ARG = 6;
    static const _ELASTOS Int32 SQLITE_LIMIT_ATTACHED = 7;
    static const _ELASTOS Int32 SQLITE_LIMIT_LIKE_PATTERN_LENGTH = 8;
    static const _ELASTOS Int32 SQLITE_LIMIT_VARIABLE_NUMBER = 9;
    static const _ELASTOS Int32 SQLITE_LIMIT_TRIGGER_DEPTH = 10;
    static const _ELASTOS Int32 SQLITE_INTEGER = 1;
    static const _ELASTOS Int32 SQLITE_FLOAT = 2;
    static const _ELASTOS Int32 SQLITE_BLOB = 4;
    static const _ELASTOS Int32 SQLITE_NULL = 5;
    static const _ELASTOS Int32 SQLITE3_TEXT = 3;
    static const _ELASTOS Int32 SQLITE_UTF8 = 1;
    static const _ELASTOS Int32 SQLITE_UTF16LE = 2;
    static const _ELASTOS Int32 SQLITE_UTF16BE = 3;
    static const _ELASTOS Int32 SQLITE_UTF16 = 4;
    static const _ELASTOS Int32 SQLITE_ANY = 5;
    static const _ELASTOS Int32 SQLITE_UTF16_ALIGNED = 8;
    static const _ELASTOS Int32 SQLITE_INDEX_CONSTRAINT_EQ = 2;
    static const _ELASTOS Int32 SQLITE_INDEX_CONSTRAINT_GT = 4;
    static const _ELASTOS Int32 SQLITE_INDEX_CONSTRAINT_LE = 8;
    static const _ELASTOS Int32 SQLITE_INDEX_CONSTRAINT_LT = 16;
    static const _ELASTOS Int32 SQLITE_INDEX_CONSTRAINT_GE = 32;
    static const _ELASTOS Int32 SQLITE_INDEX_CONSTRAINT_MATCH = 64;
    static const _ELASTOS Int32 SQLITE_MUTEX_FAST = 0;
    static const _ELASTOS Int32 SQLITE_MUTEX_RECURSIVE = 1;
    static const _ELASTOS Int32 SQLITE_MUTEX_STATIC_MASTER = 2;
    static const _ELASTOS Int32 SQLITE_MUTEX_STATIC_MEM = 3;
    static const _ELASTOS Int32 SQLITE_MUTEX_STATIC_MEM2 = 4;
    static const _ELASTOS Int32 SQLITE_MUTEX_STATIC_OPEN = 4;
    static const _ELASTOS Int32 SQLITE_MUTEX_STATIC_PRNG = 5;
    static const _ELASTOS Int32 SQLITE_MUTEX_STATIC_LRU = 6;
    static const _ELASTOS Int32 SQLITE_MUTEX_STATIC_LRU2 = 7;
    static const _ELASTOS Int32 SQLITE_TESTCTRL_FIRST = 5;
    static const _ELASTOS Int32 SQLITE_TESTCTRL_PRNG_SAVE = 5;
    static const _ELASTOS Int32 SQLITE_TESTCTRL_PRNG_RESTORE = 6;
    static const _ELASTOS Int32 SQLITE_TESTCTRL_PRNG_RESET = 7;
    static const _ELASTOS Int32 SQLITE_TESTCTRL_BITVEC_TEST = 8;
    static const _ELASTOS Int32 SQLITE_TESTCTRL_FAULT_INSTALL = 9;
    static const _ELASTOS Int32 SQLITE_TESTCTRL_BENIGN_MALLOC_HOOKS = 10;
    static const _ELASTOS Int32 SQLITE_TESTCTRL_PENDING_BYTE = 11;
    static const _ELASTOS Int32 SQLITE_TESTCTRL_ASSERT = 12;
    static const _ELASTOS Int32 SQLITE_TESTCTRL_ALWAYS = 13;
    static const _ELASTOS Int32 SQLITE_TESTCTRL_RESERVE = 14;
    static const _ELASTOS Int32 SQLITE_TESTCTRL_OPTIMIZATIONS = 15;
    static const _ELASTOS Int32 SQLITE_TESTCTRL_ISKEYWORD = 16;
    static const _ELASTOS Int32 SQLITE_TESTCTRL_LAST = 16;
    static const _ELASTOS Int32 SQLITE_STATUS_MEMORY_USED = 0;
    static const _ELASTOS Int32 SQLITE_STATUS_PAGECACHE_USED = 1;
    static const _ELASTOS Int32 SQLITE_STATUS_PAGECACHE_OVERFLOW = 2;
    static const _ELASTOS Int32 SQLITE_STATUS_SCRATCH_USED = 3;
    static const _ELASTOS Int32 SQLITE_STATUS_SCRATCH_OVERFLOW = 4;
    static const _ELASTOS Int32 SQLITE_STATUS_MALLOC_SIZE = 5;
    static const _ELASTOS Int32 SQLITE_STATUS_PARSER_STACK = 6;
    static const _ELASTOS Int32 SQLITE_STATUS_PAGECACHE_SIZE = 7;
    static const _ELASTOS Int32 SQLITE_STATUS_SCRATCH_SIZE = 8;
    static const _ELASTOS Int32 SQLITE_DBSTATUS_LOOKASIDE_USED = 0;
    static const _ELASTOS Int32 SQLITE_STMTSTATUS_FULLSCAN_STEP = 1;
    static const _ELASTOS Int32 SQLITE_STMTSTATUS_SORT = 2;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IConstants*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IConstants*)pObj->Probe(EIID_IConstants);
    }

    static CARAPI_(IConstants*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IConstants*)pObj->Probe(EIID_IConstants);
    }

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("49751A08-B712-EFA2-FB3B-2F69DFB2FD73")
IShell : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IShell*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IShell*)pObj->Probe(EIID_IShell);
    }

    static CARAPI_(IShell*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IShell*)pObj->Probe(EIID_IShell);
    }

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("6E2C1B03-B352-3834-3CFF-CE4BDAB76CFF")
IDBDump : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDBDump*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDBDump*)pObj->Probe(EIID_IDBDump);
    }

    static CARAPI_(IDBDump*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDBDump*)pObj->Probe(EIID_IDBDump);
    }

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
namespace JDBC {
CAR_INTERFACE("E2FD393B-84D2-0B06-1830-FAD1DEC60D19")
IJDBCConnection : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IJDBCConnection*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJDBCConnection*)pObj->Probe(EIID_IJDBCConnection);
    }

    static CARAPI_(IJDBCConnection*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJDBCConnection*)pObj->Probe(EIID_IJDBCConnection);
    }

    virtual CARAPI GetSQLiteDatabase(
        /* [out] */ Elastos::Sql::SQLite::IDatabase ** db) = 0;

};
}
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
namespace JDBC {
CAR_INTERFACE("38712731-84D2-0B06-18AC-7EFFA3BD8D1B")
IJDBCStatement : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IJDBCStatement*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJDBCStatement*)pObj->Probe(EIID_IJDBCStatement);
    }

    static CARAPI_(IJDBCStatement*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJDBCStatement*)pObj->Probe(EIID_IJDBCStatement);
    }

};
}
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
namespace JDBC {
CAR_INTERFACE("024DF302-D4D2-4C2C-56A3-3359A3277793")
IJDBCPreparedStatement : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IJDBCPreparedStatement*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJDBCPreparedStatement*)pObj->Probe(EIID_IJDBCPreparedStatement);
    }

    static CARAPI_(IJDBCPreparedStatement*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJDBCPreparedStatement*)pObj->Probe(EIID_IJDBCPreparedStatement);
    }

    virtual CARAPI RegisterOutputParameter(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Int32 sqlType) = 0;

    virtual CARAPI RegisterOutputParameter(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Int32 sqlType,
        /* [in] */ _ELASTOS Int32 scale) = 0;

    virtual CARAPI RegisterOutputParameter(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Int32 sqlType,
        /* [in] */ const _ELASTOS String& typeName) = 0;

    virtual CARAPI GetURL(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ Elastos::Net::IURL ** url) = 0;

    virtual CARAPI SetNull(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Int32 sqlType) = 0;

    virtual CARAPI SetBoolean(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Boolean val) = 0;

    virtual CARAPI SetByte(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Byte val) = 0;

    virtual CARAPI SetInt16(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Int16 val) = 0;

    virtual CARAPI SetInt32(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Int32 val) = 0;

    virtual CARAPI SetInt64(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Int64 val) = 0;

    virtual CARAPI SetFloat(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Float val) = 0;

    virtual CARAPI SetDouble(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Double val) = 0;

    virtual CARAPI SetBigDecimal(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Math::IBigDecimal * val) = 0;

    virtual CARAPI SetString(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ const _ELASTOS String& val) = 0;

    virtual CARAPI SetBytes(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & val) = 0;

    virtual CARAPI SetDate(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::ISQLDate * val) = 0;

    virtual CARAPI SetTime(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::ITime * val) = 0;

    virtual CARAPI SetTimestamp(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::ITimestamp * val) = 0;

    virtual CARAPI SetAsciiStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IInputStream * s,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI SetBinaryStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IInputStream * s,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI SetObject(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ IObject * val,
        /* [in] */ _ELASTOS Int32 targetSqlType,
        /* [in] */ _ELASTOS Int32 scale) = 0;

    virtual CARAPI SetObject(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ IObject * val,
        /* [in] */ _ELASTOS Int32 targetSqlType) = 0;

    virtual CARAPI SetObject(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ IObject * val) = 0;

    virtual CARAPI SetCharacterStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * r,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI SetDate(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::ISQLDate * val,
        /* [in] */ Elastos::Utility::ICalendar * cal) = 0;

    virtual CARAPI SetTime(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::ITime * val,
        /* [in] */ Elastos::Utility::ICalendar * cal) = 0;

    virtual CARAPI SetTimestamp(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::ITimestamp * val,
        /* [in] */ Elastos::Utility::ICalendar * cal) = 0;

    virtual CARAPI SetNull(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ _ELASTOS Int32 sqlType,
        /* [in] */ const _ELASTOS String& typeName) = 0;

    virtual CARAPI GetString(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetBoolean(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetByte(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ _ELASTOS Byte * outbyte) = 0;

    virtual CARAPI GetInt16(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ _ELASTOS Int16 * value) = 0;

    virtual CARAPI GetInt32(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetInt64(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI GetFloat(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ _ELASTOS Float * value) = 0;

    virtual CARAPI GetDouble(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ _ELASTOS Double * value) = 0;

    virtual CARAPI GetBytes(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** outarray) = 0;

    virtual CARAPI GetDate(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ Elastos::Sql::ISQLDate ** thedate) = 0;

    virtual CARAPI GetTime(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ Elastos::Sql::ITime ** thetime) = 0;

    virtual CARAPI GetTimestamp(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ Elastos::Sql::ITimestamp ** timestamp) = 0;

    virtual CARAPI GetObject(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ IObject ** theobject) = 0;

    virtual CARAPI GetObject(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ IObject ** theobject) = 0;

    virtual CARAPI GetBigDecimal(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ Elastos::Math::IBigDecimal ** bigdecimal) = 0;

    virtual CARAPI GetObject(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ IObject ** theobject) = 0;

    virtual CARAPI GetObject(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ IObject ** theobject) = 0;

    virtual CARAPI GetRef(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ Elastos::Sql::IRef ** iref) = 0;

    virtual CARAPI GetRef(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ Elastos::Sql::IRef ** iref) = 0;

    virtual CARAPI GetBlob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ Elastos::Sql::IBlob ** blob) = 0;

    virtual CARAPI GetBlob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ Elastos::Sql::IBlob ** blob) = 0;

    virtual CARAPI GetClob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ Elastos::Sql::IClob ** clob) = 0;

    virtual CARAPI GetClob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ Elastos::Sql::IClob ** clob) = 0;

    virtual CARAPI GetArray(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ Elastos::Sql::IArray ** outarray) = 0;

    virtual CARAPI GetArray(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [out] */ Elastos::Sql::IArray ** outarray) = 0;

    virtual CARAPI GetDate(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Utility::ICalendar * cal,
        /* [out] */ Elastos::Sql::ISQLDate ** thedate) = 0;

    virtual CARAPI GetDate(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Utility::ICalendar * cal,
        /* [out] */ Elastos::Sql::ISQLDate ** thedate) = 0;

    virtual CARAPI GetTime(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Utility::ICalendar * cal,
        /* [out] */ Elastos::Sql::ITime ** thetime) = 0;

    virtual CARAPI GetTime(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Utility::ICalendar * cal,
        /* [out] */ Elastos::Sql::ITime ** thetime) = 0;

    virtual CARAPI GetTimestamp(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Utility::ICalendar * cal,
        /* [out] */ Elastos::Sql::ITimestamp ** timestamp) = 0;

    virtual CARAPI GetTimestamp(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Utility::ICalendar * cal,
        /* [out] */ Elastos::Sql::ITimestamp ** timestamp) = 0;

    virtual CARAPI GetURL(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [out] */ Elastos::Net::IURL ** url) = 0;

    virtual CARAPI SetRowId(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::IRowId * x) = 0;

    virtual CARAPI SetRowId(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::IRowId * x) = 0;

    virtual CARAPI SetNString(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI SetNString(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI SetNCharacterStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * x,
        /* [in] */ _ELASTOS Int64 len) = 0;

    virtual CARAPI SetNCharacterStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * x,
        /* [in] */ _ELASTOS Int64 len) = 0;

    virtual CARAPI SetNClob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::INClob * value) = 0;

    virtual CARAPI SetNClob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::INClob * value) = 0;

    virtual CARAPI SetClob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * x,
        /* [in] */ _ELASTOS Int64 len) = 0;

    virtual CARAPI SetClob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * x,
        /* [in] */ _ELASTOS Int64 len) = 0;

    virtual CARAPI SetBlob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IInputStream * x,
        /* [in] */ _ELASTOS Int64 len) = 0;

    virtual CARAPI SetBlob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IInputStream * x,
        /* [in] */ _ELASTOS Int64 len) = 0;

    virtual CARAPI SetNClob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * x,
        /* [in] */ _ELASTOS Int64 len) = 0;

    virtual CARAPI SetNClob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * x,
        /* [in] */ _ELASTOS Int64 len) = 0;

    virtual CARAPI SetSQLXML(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::Sql::ISQLXML * xml) = 0;

    virtual CARAPI SetSQLXML(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::Sql::ISQLXML * xml) = 0;

    virtual CARAPI SetAsciiStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IInputStream * x,
        /* [in] */ _ELASTOS Int64 len) = 0;

    virtual CARAPI SetAsciiStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IInputStream * x,
        /* [in] */ _ELASTOS Int64 len) = 0;

    virtual CARAPI SetBinaryStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IInputStream * x,
        /* [in] */ _ELASTOS Int64 len) = 0;

    virtual CARAPI SetBinaryStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IInputStream * x,
        /* [in] */ _ELASTOS Int64 len) = 0;

    virtual CARAPI SetCharacterStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * x,
        /* [in] */ _ELASTOS Int64 len) = 0;

    virtual CARAPI SetCharacterStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * x,
        /* [in] */ _ELASTOS Int64 len) = 0;

    virtual CARAPI SetAsciiStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IInputStream * x) = 0;

    virtual CARAPI SetAsciiStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IInputStream * x) = 0;

    virtual CARAPI SetBinaryStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IInputStream * x) = 0;

    virtual CARAPI SetBinaryStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IInputStream * x) = 0;

    virtual CARAPI SetCharacterStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * x) = 0;

    virtual CARAPI SetCharacterStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * x) = 0;

    virtual CARAPI SetNCharacterStream(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * x) = 0;

    virtual CARAPI SetNCharacterStream(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * x) = 0;

    virtual CARAPI SetClob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * x) = 0;

    virtual CARAPI SetClob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * x) = 0;

    virtual CARAPI SetBlob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IInputStream * x) = 0;

    virtual CARAPI SetBlob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IInputStream * x) = 0;

    virtual CARAPI SetNClob(
        /* [in] */ _ELASTOS Int32 parameterIndex,
        /* [in] */ Elastos::IO::IReader * x) = 0;

    virtual CARAPI SetNClob(
        /* [in] */ const _ELASTOS String& parameterName,
        /* [in] */ Elastos::IO::IReader * x) = 0;

};
}
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
namespace JDBC {
CAR_INTERFACE("339C3C2F-84D2-0B06-181C-D66C01C50D12")
IJDBCResultSetMetaData : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IJDBCResultSetMetaData*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJDBCResultSetMetaData*)pObj->Probe(EIID_IJDBCResultSetMetaData);
    }

    static CARAPI_(IJDBCResultSetMetaData*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJDBCResultSetMetaData*)pObj->Probe(EIID_IJDBCResultSetMetaData);
    }

    virtual CARAPI FindColByName(
        /* [in] */ const _ELASTOS String& columnName,
        /* [out] */ _ELASTOS Int32 * value) = 0;

};
}
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
namespace JDBC {
CAR_INTERFACE("6C46263C-EF52-21C3-7EB4-B77143868D1F")
ITableResultX : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITableResultX*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITableResultX*)pObj->Probe(EIID_ITableResultX);
    }

    static CARAPI_(ITableResultX*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITableResultX*)pObj->Probe(EIID_ITableResultX);
    }

};
}
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
namespace JDBC {
CAR_INTERFACE("7A5E3C09-D4D2-4C2C-43DE-6449DAA885DE")
IJDBCDatabaseMetaData : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IJDBCDatabaseMetaData*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJDBCDatabaseMetaData*)pObj->Probe(EIID_IJDBCDatabaseMetaData);
    }

    static CARAPI_(IJDBCDatabaseMetaData*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJDBCDatabaseMetaData*)pObj->Probe(EIID_IJDBCDatabaseMetaData);
    }

    virtual CARAPI GetSQLKeywords(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
namespace JDBC {
CAR_INTERFACE("F37A4627-84D2-0B06-181C-D6FCA3BD8D1B")
IJDBCResultSet : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IJDBCResultSet*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJDBCResultSet*)pObj->Probe(EIID_IJDBCResultSet);
    }

    static CARAPI_(IJDBCResultSet*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJDBCResultSet*)pObj->Probe(EIID_IJDBCResultSet);
    }

    virtual CARAPI IsUpdatable(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI FillRowbuf() = 0;

    virtual CARAPI FindColumn(
        /* [in] */ const _ELASTOS String& columnName,
        /* [out] */ _ELASTOS Int32 * value) = 0;

};
}
}
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("AAA1D134-0312-1A0E-2A90-AFAFC7E88FF6")
ICSQLWarningClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSQLWarningClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSQLWarningClassObject*)pObj->Probe(EIID_ICSQLWarningClassObject);
    }

    static CARAPI_(ICSQLWarningClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSQLWarningClassObject*)pObj->Probe(EIID_ICSQLWarningClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithTheReason(
        /* [in] */ const _ELASTOS String& theReason,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithTheReasonTheSQLState(
        /* [in] */ const _ELASTOS String& theReason,
        /* [in] */ const _ELASTOS String& theSQLState,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithTheReasonTheSQLStateTheErrorCode(
        /* [in] */ const _ELASTOS String& theReason,
        /* [in] */ const _ELASTOS String& theSQLState,
        /* [in] */ _ELASTOS Int32 theErrorCode,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("CBA68335-8312-7AE2-8CFE-686FE3860C1B")
ICTimeClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICTimeClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTimeClassObject*)pObj->Probe(EIID_ICTimeClassObject);
    }

    static CARAPI_(ICTimeClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTimeClassObject*)pObj->Probe(EIID_ICTimeClassObject);
    }

    virtual CARAPI CreateObjectWithTheHourTheMinuteTheSecond(
        /* [in] */ _ELASTOS Int32 theHour,
        /* [in] */ _ELASTOS Int32 theMinute,
        /* [in] */ _ELASTOS Int32 theSecond,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithTheTime(
        /* [in] */ _ELASTOS Int64 theTime,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("BC5F822F-0312-340E-5E64-D263F4477B1B")
ICSqlDateClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSqlDateClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSqlDateClassObject*)pObj->Probe(EIID_ICSqlDateClassObject);
    }

    static CARAPI_(ICSqlDateClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSqlDateClassObject*)pObj->Probe(EIID_ICSqlDateClassObject);
    }

    virtual CARAPI CreateObjectWithTheYearTheMonthTheDay(
        /* [in] */ _ELASTOS Int32 theYear,
        /* [in] */ _ELASTOS Int32 theMonth,
        /* [in] */ _ELASTOS Int32 theDay,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithTheDate(
        /* [in] */ _ELASTOS Int64 theDate,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("F921A521-0312-37E2-48C0-98A1C7E88FF6")
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

    virtual CARAPI CreateObjectWithTheYearTheMonthTheDateTheHourTheMinuteTheSecondTheNano(
        /* [in] */ _ELASTOS Int32 theYear,
        /* [in] */ _ELASTOS Int32 theMonth,
        /* [in] */ _ELASTOS Int32 theDate,
        /* [in] */ _ELASTOS Int32 theHour,
        /* [in] */ _ELASTOS Int32 theMinute,
        /* [in] */ _ELASTOS Int32 theSecond,
        /* [in] */ _ELASTOS Int32 theNano,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithTheTime(
        /* [in] */ _ELASTOS Int64 theTime,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("04F16A43-8312-1B26-6B64-E01BD62F0F2D")
ICDriverPropertyInfoClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDriverPropertyInfoClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDriverPropertyInfoClassObject*)pObj->Probe(EIID_ICDriverPropertyInfoClassObject);
    }

    static CARAPI_(ICDriverPropertyInfoClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDriverPropertyInfoClassObject*)pObj->Probe(EIID_ICDriverPropertyInfoClassObject);
    }

    virtual CARAPI CreateObjectWithNameValue(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("14AEBE3D-0312-1D4C-6AE0-886182047C3D")
ICDataTruncationClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDataTruncationClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDataTruncationClassObject*)pObj->Probe(EIID_ICDataTruncationClassObject);
    }

    static CARAPI_(ICDataTruncationClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDataTruncationClassObject*)pObj->Probe(EIID_ICDataTruncationClassObject);
    }

    virtual CARAPI CreateObjectWithIndexParameterReadDataSizeTransferSize(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Boolean parameter,
        /* [in] */ _ELASTOS Boolean read,
        /* [in] */ _ELASTOS Int32 dataSize,
        /* [in] */ _ELASTOS Int32 transferSize,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithIndexParameterReadDataSizeTransferSizeCause(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Boolean parameter,
        /* [in] */ _ELASTOS Boolean read,
        /* [in] */ _ELASTOS Int32 dataSize,
        /* [in] */ _ELASTOS Int32 transferSize,
        /* [in] */ Elastos::Core::IThrowable * cause,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("C5886738-8312-3506-58E4-B8BF528FD11F")
ICDriverManagerClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDriverManagerClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDriverManagerClassObject*)pObj->Probe(EIID_ICDriverManagerClassObject);
    }

    static CARAPI_(ICDriverManagerClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDriverManagerClassObject*)pObj->Probe(EIID_ICDriverManagerClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Sql {
CAR_INTERFACE("4D4A7B1F-C312-5569-86D6-306BDBAC1C33")
ICSQLPermissionClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSQLPermissionClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSQLPermissionClassObject*)pObj->Probe(EIID_ICSQLPermissionClassObject);
    }

    static CARAPI_(ICSQLPermissionClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSQLPermissionClassObject*)pObj->Probe(EIID_ICSQLPermissionClassObject);
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
namespace Sql {
namespace SQLite {
CAR_INTERFACE("AAC0833B-8312-87DE-F518-FDD1DEC60D19")
ICTableResultClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICTableResultClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTableResultClassObject*)pObj->Probe(EIID_ICTableResultClassObject);
    }

    static CARAPI_(ICTableResultClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTableResultClassObject*)pObj->Probe(EIID_ICTableResultClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithMaxrows(
        /* [in] */ _ELASTOS Int32 maxrows,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("4199763C-0312-2B0E-50BC-78A1C7E88FF6")
ICShellClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICShellClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICShellClassObject*)pObj->Probe(EIID_ICShellClassObject);
    }

    static CARAPI_(ICShellClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICShellClassObject*)pObj->Probe(EIID_ICShellClassObject);
    }

    virtual CARAPI CreateObjectWithPwErr(
        /* [in] */ Elastos::IO::IPrintWriter * pw,
        /* [in] */ Elastos::IO::IPrintWriter * err,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPwErrs(
        /* [in] */ Elastos::IO::IPrintStream * pw,
        /* [in] */ Elastos::IO::IPrintStream * errs,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("406A632A-8312-0B06-1AE0-8031438FD11F")
ICDBDumpClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDBDumpClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDBDumpClassObject*)pObj->Probe(EIID_ICDBDumpClassObject);
    }

    static CARAPI_(ICDBDumpClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDBDumpClassObject*)pObj->Probe(EIID_ICDBDumpClassObject);
    }

    virtual CARAPI CreateObjectWithSTables(
        /* [in] */ Elastos::Sql::SQLite::IShell * s,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * tables,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("14406327-8312-300F-F418-FDD1DEC60D19")
ICVmClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICVmClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICVmClassObject*)pObj->Probe(EIID_ICVmClassObject);
    }

    static CARAPI_(ICVmClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICVmClassObject*)pObj->Probe(EIID_ICVmClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("B2E46526-8312-2F05-6494-D063F4477B1B")
ICBlobClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICBlobClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBlobClassObject*)pObj->Probe(EIID_ICBlobClassObject);
    }

    static CARAPI_(ICBlobClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBlobClassObject*)pObj->Probe(EIID_ICBlobClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("A2835F35-8312-2F05-6494-D8A0C7E88FF6")
ICBlobRClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICBlobRClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBlobRClassObject*)pObj->Probe(EIID_ICBlobRClassObject);
    }

    static CARAPI_(ICBlobRClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBlobRClassObject*)pObj->Probe(EIID_ICBlobRClassObject);
    }

    virtual CARAPI CreateObjectWithBlob(
        /* [in] */ Elastos::Sql::SQLite::IBlob * blob,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("A27E5F34-8312-2F05-6494-00A1C7E88FF6")
ICBlobWClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICBlobWClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBlobWClassObject*)pObj->Probe(EIID_ICBlobWClassObject);
    }

    static CARAPI_(ICBlobWClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBlobWClassObject*)pObj->Probe(EIID_ICBlobWClassObject);
    }

    virtual CARAPI CreateObjectWithBlob(
        /* [in] */ Elastos::Sql::SQLite::IBlob * blob,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("F807693C-0312-254C-48D8-40A1C7E88FF6")
ICDatabaseClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDatabaseClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDatabaseClassObject*)pObj->Probe(EIID_ICDatabaseClassObject);
    }

    static CARAPI_(ICDatabaseClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDatabaseClassObject*)pObj->Probe(EIID_ICDatabaseClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("AFED6F0A-D312-3790-5992-361AA1EF8CD6")
ICDatabaseHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDatabaseHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDatabaseHelperClassObject*)pObj->Probe(EIID_ICDatabaseHelperClassObject);
    }

    static CARAPI_(ICDatabaseHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDatabaseHelperClassObject*)pObj->Probe(EIID_ICDatabaseHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("9EF66B14-3312-0B35-D3D4-6C8ED6CC4BDA")
ICJDBCDriverClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICJDBCDriverClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJDBCDriverClassObject*)pObj->Probe(EIID_ICJDBCDriverClassObject);
    }

    static CARAPI_(ICJDBCDriverClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJDBCDriverClassObject*)pObj->Probe(EIID_ICJDBCDriverClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("447B673B-0312-3830-66E8-31FAA3BD8D1B")
ICBackupClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICBackupClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBackupClassObject*)pObj->Probe(EIID_ICBackupClassObject);
    }

    static CARAPI_(ICBackupClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBackupClassObject*)pObj->Probe(EIID_ICBackupClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("1BCB7030-8312-0C70-64C4-B88162C70D3D")
ICFunctionContextClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICFunctionContextClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFunctionContextClassObject*)pObj->Probe(EIID_ICFunctionContextClassObject);
    }

    static CARAPI_(ICFunctionContextClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFunctionContextClassObject*)pObj->Probe(EIID_ICFunctionContextClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("98D56525-0312-370E-60DC-D063F4477B1B")
ICStmtClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICStmtClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStmtClassObject*)pObj->Probe(EIID_ICStmtClassObject);
    }

    static CARAPI_(ICStmtClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStmtClassObject*)pObj->Probe(EIID_ICStmtClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
CAR_INTERFACE("85F37426-0312-C0D8-6A44-40F162C67D3D")
ICStringEncoderHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICStringEncoderHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStringEncoderHelperClassObject*)pObj->Probe(EIID_ICStringEncoderHelperClassObject);
    }

    static CARAPI_(ICStringEncoderHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStringEncoderHelperClassObject*)pObj->Probe(EIID_ICStringEncoderHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
namespace JDBC {
CAR_INTERFACE("5981793D-8312-0D09-1630-60A4C7E88FF6")
ICJDBCConnectionClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICJDBCConnectionClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJDBCConnectionClassObject*)pObj->Probe(EIID_ICJDBCConnectionClassObject);
    }

    static CARAPI_(ICJDBCConnectionClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJDBCConnectionClassObject*)pObj->Probe(EIID_ICJDBCConnectionClassObject);
    }

    virtual CARAPI CreateObjectWithUrlEncPwdDrepVfs(
        /* [in] */ const _ELASTOS String& url,
        /* [in] */ const _ELASTOS String& enc,
        /* [in] */ const _ELASTOS String& pwd,
        /* [in] */ const _ELASTOS String& drep,
        /* [in] */ const _ELASTOS String& vfs,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
namespace JDBC {
CAR_INTERFACE("82F07705-3312-0B35-93D5-E84CD6E8C9DD")
ICJDBCPreparedStatementClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICJDBCPreparedStatementClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJDBCPreparedStatementClassObject*)pObj->Probe(EIID_ICJDBCPreparedStatementClassObject);
    }

    static CARAPI_(ICJDBCPreparedStatementClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJDBCPreparedStatementClassObject*)pObj->Probe(EIID_ICJDBCPreparedStatementClassObject);
    }

    virtual CARAPI CreateObjectWithConnSql(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [in] */ const _ELASTOS String& sql,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
namespace JDBC {
CAR_INTERFACE("CB0F6C34-8312-0D09-1630-58FD5E8FD11F")
ICJDBCStatementClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICJDBCStatementClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJDBCStatementClassObject*)pObj->Probe(EIID_ICJDBCStatementClassObject);
    }

    static CARAPI_(ICJDBCStatementClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJDBCStatementClassObject*)pObj->Probe(EIID_ICJDBCStatementClassObject);
    }

    virtual CARAPI CreateObjectWithConn(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
namespace JDBC {
CAR_INTERFACE("F12C713A-8312-0D09-1630-38ACD9028A1B")
ICJDBCResultSetMetaDataClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICJDBCResultSetMetaDataClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJDBCResultSetMetaDataClassObject*)pObj->Probe(EIID_ICJDBCResultSetMetaDataClassObject);
    }

    static CARAPI_(ICJDBCResultSetMetaDataClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJDBCResultSetMetaDataClassObject*)pObj->Probe(EIID_ICJDBCResultSetMetaDataClassObject);
    }

    virtual CARAPI CreateObjectWithR(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCResultSet * r,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
namespace JDBC {
CAR_INTERFACE("59639B26-8312-87DE-43E8-31FAA3BD8D1B")
ICTableResultXClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICTableResultXClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTableResultXClassObject*)pObj->Probe(EIID_ICTableResultXClassObject);
    }

    static CARAPI_(ICTableResultXClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTableResultXClassObject*)pObj->Probe(EIID_ICTableResultXClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithMaxrows(
        /* [in] */ _ELASTOS Int32 maxrows,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithTr(
        /* [in] */ Elastos::Sql::SQLite::ITableResult * tr,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
namespace JDBC {
CAR_INTERFACE("87EF7312-3312-0B35-D390-375992366AA1")
ICJDBCDatabaseMetaDataClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICJDBCDatabaseMetaDataClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJDBCDatabaseMetaDataClassObject*)pObj->Probe(EIID_ICJDBCDatabaseMetaDataClassObject);
    }

    static CARAPI_(ICJDBCDatabaseMetaDataClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJDBCDatabaseMetaDataClassObject*)pObj->Probe(EIID_ICJDBCDatabaseMetaDataClassObject);
    }

    virtual CARAPI CreateObjectWithConn(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
namespace JDBC {
CAR_INTERFACE("16446B3F-8312-0D09-1630-38AC598FD11F")
ICJDBCResultSetClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICJDBCResultSetClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJDBCResultSetClassObject*)pObj->Probe(EIID_ICJDBCResultSetClassObject);
    }

    static CARAPI_(ICJDBCResultSetClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJDBCResultSetClassObject*)pObj->Probe(EIID_ICJDBCResultSetClassObject);
    }

    virtual CARAPI CreateObjectWithTrS(
        /* [in] */ Elastos::Sql::SQLite::ITableResult * tr,
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCStatement * s,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
namespace JDBC {
CAR_INTERFACE("F56F6F27-0312-254C-48D8-4011428FD11F")
ICDatabaseXClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDatabaseXClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDatabaseXClassObject*)pObj->Probe(EIID_ICDatabaseXClassObject);
    }

    static CARAPI_(ICDatabaseXClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDatabaseXClassObject*)pObj->Probe(EIID_ICDatabaseXClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastos {
namespace Sql {
class CSQLWarning
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& theReason,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSQLWarningClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSQLWarning, RGM_SAME_DOMAIN,
                EIID_ICSQLWarningClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTheReason(theReason, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& theReason,
        /* [in] */ const _ELASTOS String& theSQLState,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSQLWarningClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSQLWarning, RGM_SAME_DOMAIN,
                EIID_ICSQLWarningClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTheReasonTheSQLState(theReason, theSQLState, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& theReason,
        /* [in] */ const _ELASTOS String& theSQLState,
        /* [in] */ _ELASTOS Int32 theErrorCode,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSQLWarningClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSQLWarning, RGM_SAME_DOMAIN,
                EIID_ICSQLWarningClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTheReasonTheSQLStateTheErrorCode(theReason, theSQLState, theErrorCode, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Sql::ISQLWarning** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSQLWarning, RGM_SAME_DOMAIN, Elastos::Sql::EIID_ISQLWarning, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSQLWarning, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSQLWarning, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSQLWarning, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& theReason,
        /* [out] */ Elastos::Sql::ISQLWarning** __ISQLWarning)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theReason, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISQLWarning = (Elastos::Sql::ISQLWarning*)__pNewObj->Probe(Elastos::Sql::EIID_ISQLWarning);
        if (*__ISQLWarning) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& theReason,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theReason, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& theReason,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theReason, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& theReason,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theReason, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& theReason,
        /* [in] */ const _ELASTOS String& theSQLState,
        /* [out] */ Elastos::Sql::ISQLWarning** __ISQLWarning)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theReason, theSQLState, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISQLWarning = (Elastos::Sql::ISQLWarning*)__pNewObj->Probe(Elastos::Sql::EIID_ISQLWarning);
        if (*__ISQLWarning) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& theReason,
        /* [in] */ const _ELASTOS String& theSQLState,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theReason, theSQLState, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& theReason,
        /* [in] */ const _ELASTOS String& theSQLState,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theReason, theSQLState, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& theReason,
        /* [in] */ const _ELASTOS String& theSQLState,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theReason, theSQLState, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& theReason,
        /* [in] */ const _ELASTOS String& theSQLState,
        /* [in] */ _ELASTOS Int32 theErrorCode,
        /* [out] */ Elastos::Sql::ISQLWarning** __ISQLWarning)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theReason, theSQLState, theErrorCode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISQLWarning = (Elastos::Sql::ISQLWarning*)__pNewObj->Probe(Elastos::Sql::EIID_ISQLWarning);
        if (*__ISQLWarning) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& theReason,
        /* [in] */ const _ELASTOS String& theSQLState,
        /* [in] */ _ELASTOS Int32 theErrorCode,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theReason, theSQLState, theErrorCode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& theReason,
        /* [in] */ const _ELASTOS String& theSQLState,
        /* [in] */ _ELASTOS Int32 theErrorCode,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theReason, theSQLState, theErrorCode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& theReason,
        /* [in] */ const _ELASTOS String& theSQLState,
        /* [in] */ _ELASTOS Int32 theErrorCode,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theReason, theSQLState, theErrorCode, &__pNewObj);
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
namespace Sql {
class CTime
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 theHour,
        /* [in] */ _ELASTOS Int32 theMinute,
        /* [in] */ _ELASTOS Int32 theSecond,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICTimeClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CTime, RGM_SAME_DOMAIN,
                EIID_ICTimeClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTheHourTheMinuteTheSecond(theHour, theMinute, theSecond, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int64 theTime,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICTimeClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CTime, RGM_SAME_DOMAIN,
                EIID_ICTimeClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTheTime(theTime, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theHour,
        /* [in] */ _ELASTOS Int32 theMinute,
        /* [in] */ _ELASTOS Int32 theSecond,
        /* [out] */ Elastos::Sql::ITime** __ITime)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theHour, theMinute, theSecond, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ITime = (Elastos::Sql::ITime*)__pNewObj->Probe(Elastos::Sql::EIID_ITime);
        if (*__ITime) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theHour,
        /* [in] */ _ELASTOS Int32 theMinute,
        /* [in] */ _ELASTOS Int32 theSecond,
        /* [out] */ Elastos::Utility::IDate** __IDate)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theHour, theMinute, theSecond, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDate = (Elastos::Utility::IDate*)__pNewObj->Probe(Elastos::Utility::EIID_IDate);
        if (*__IDate) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theHour,
        /* [in] */ _ELASTOS Int32 theMinute,
        /* [in] */ _ELASTOS Int32 theSecond,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theHour, theMinute, theSecond, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theHour,
        /* [in] */ _ELASTOS Int32 theMinute,
        /* [in] */ _ELASTOS Int32 theSecond,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theHour, theMinute, theSecond, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theHour,
        /* [in] */ _ELASTOS Int32 theMinute,
        /* [in] */ _ELASTOS Int32 theSecond,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theHour, theMinute, theSecond, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theHour,
        /* [in] */ _ELASTOS Int32 theMinute,
        /* [in] */ _ELASTOS Int32 theSecond,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theHour, theMinute, theSecond, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theHour,
        /* [in] */ _ELASTOS Int32 theMinute,
        /* [in] */ _ELASTOS Int32 theSecond,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theHour, theMinute, theSecond, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theHour,
        /* [in] */ _ELASTOS Int32 theMinute,
        /* [in] */ _ELASTOS Int32 theSecond,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theHour, theMinute, theSecond, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theTime,
        /* [out] */ Elastos::Sql::ITime** __ITime)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theTime, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ITime = (Elastos::Sql::ITime*)__pNewObj->Probe(Elastos::Sql::EIID_ITime);
        if (*__ITime) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theTime,
        /* [out] */ Elastos::Utility::IDate** __IDate)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theTime, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDate = (Elastos::Utility::IDate*)__pNewObj->Probe(Elastos::Utility::EIID_IDate);
        if (*__IDate) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theTime,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theTime, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theTime,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theTime, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theTime,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theTime, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theTime,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theTime, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theTime,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theTime, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theTime,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theTime, &__pNewObj);
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
namespace Sql {
class CSqlDate
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 theYear,
        /* [in] */ _ELASTOS Int32 theMonth,
        /* [in] */ _ELASTOS Int32 theDay,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSqlDateClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSqlDate, RGM_SAME_DOMAIN,
                EIID_ICSqlDateClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTheYearTheMonthTheDay(theYear, theMonth, theDay, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int64 theDate,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSqlDateClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSqlDate, RGM_SAME_DOMAIN,
                EIID_ICSqlDateClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTheDate(theDate, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theYear,
        /* [in] */ _ELASTOS Int32 theMonth,
        /* [in] */ _ELASTOS Int32 theDay,
        /* [out] */ Elastos::Sql::ISQLDate** __ISQLDate)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theYear, theMonth, theDay, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISQLDate = (Elastos::Sql::ISQLDate*)__pNewObj->Probe(Elastos::Sql::EIID_ISQLDate);
        if (*__ISQLDate) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theYear,
        /* [in] */ _ELASTOS Int32 theMonth,
        /* [in] */ _ELASTOS Int32 theDay,
        /* [out] */ Elastos::Utility::IDate** __IDate)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theYear, theMonth, theDay, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDate = (Elastos::Utility::IDate*)__pNewObj->Probe(Elastos::Utility::EIID_IDate);
        if (*__IDate) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theYear,
        /* [in] */ _ELASTOS Int32 theMonth,
        /* [in] */ _ELASTOS Int32 theDay,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theYear, theMonth, theDay, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theYear,
        /* [in] */ _ELASTOS Int32 theMonth,
        /* [in] */ _ELASTOS Int32 theDay,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theYear, theMonth, theDay, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theYear,
        /* [in] */ _ELASTOS Int32 theMonth,
        /* [in] */ _ELASTOS Int32 theDay,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theYear, theMonth, theDay, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theYear,
        /* [in] */ _ELASTOS Int32 theMonth,
        /* [in] */ _ELASTOS Int32 theDay,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theYear, theMonth, theDay, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theYear,
        /* [in] */ _ELASTOS Int32 theMonth,
        /* [in] */ _ELASTOS Int32 theDay,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theYear, theMonth, theDay, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theYear,
        /* [in] */ _ELASTOS Int32 theMonth,
        /* [in] */ _ELASTOS Int32 theDay,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theYear, theMonth, theDay, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theDate,
        /* [out] */ Elastos::Sql::ISQLDate** __ISQLDate)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theDate, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISQLDate = (Elastos::Sql::ISQLDate*)__pNewObj->Probe(Elastos::Sql::EIID_ISQLDate);
        if (*__ISQLDate) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theDate,
        /* [out] */ Elastos::Utility::IDate** __IDate)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theDate, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDate = (Elastos::Utility::IDate*)__pNewObj->Probe(Elastos::Utility::EIID_IDate);
        if (*__IDate) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theDate,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theDate, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theDate,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theDate, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theDate,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theDate, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theDate,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theDate, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theDate,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theDate, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theDate,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theDate, &__pNewObj);
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
namespace Sql {
class CTimestamp
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 theYear,
        /* [in] */ _ELASTOS Int32 theMonth,
        /* [in] */ _ELASTOS Int32 theDate,
        /* [in] */ _ELASTOS Int32 theHour,
        /* [in] */ _ELASTOS Int32 theMinute,
        /* [in] */ _ELASTOS Int32 theSecond,
        /* [in] */ _ELASTOS Int32 theNano,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICTimestampClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CTimestamp, RGM_SAME_DOMAIN,
                EIID_ICTimestampClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTheYearTheMonthTheDateTheHourTheMinuteTheSecondTheNano(theYear, theMonth, theDate, theHour, theMinute, theSecond, theNano, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int64 theTime,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICTimestampClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CTimestamp, RGM_SAME_DOMAIN,
                EIID_ICTimestampClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTheTime(theTime, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theYear,
        /* [in] */ _ELASTOS Int32 theMonth,
        /* [in] */ _ELASTOS Int32 theDate,
        /* [in] */ _ELASTOS Int32 theHour,
        /* [in] */ _ELASTOS Int32 theMinute,
        /* [in] */ _ELASTOS Int32 theSecond,
        /* [in] */ _ELASTOS Int32 theNano,
        /* [out] */ Elastos::Sql::ITimestamp** __ITimestamp)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theYear, theMonth, theDate, theHour, theMinute, theSecond, theNano, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ITimestamp = (Elastos::Sql::ITimestamp*)__pNewObj->Probe(Elastos::Sql::EIID_ITimestamp);
        if (*__ITimestamp) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theYear,
        /* [in] */ _ELASTOS Int32 theMonth,
        /* [in] */ _ELASTOS Int32 theDate,
        /* [in] */ _ELASTOS Int32 theHour,
        /* [in] */ _ELASTOS Int32 theMinute,
        /* [in] */ _ELASTOS Int32 theSecond,
        /* [in] */ _ELASTOS Int32 theNano,
        /* [out] */ Elastos::Utility::IDate** __IDate)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theYear, theMonth, theDate, theHour, theMinute, theSecond, theNano, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDate = (Elastos::Utility::IDate*)__pNewObj->Probe(Elastos::Utility::EIID_IDate);
        if (*__IDate) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theYear,
        /* [in] */ _ELASTOS Int32 theMonth,
        /* [in] */ _ELASTOS Int32 theDate,
        /* [in] */ _ELASTOS Int32 theHour,
        /* [in] */ _ELASTOS Int32 theMinute,
        /* [in] */ _ELASTOS Int32 theSecond,
        /* [in] */ _ELASTOS Int32 theNano,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theYear, theMonth, theDate, theHour, theMinute, theSecond, theNano, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theYear,
        /* [in] */ _ELASTOS Int32 theMonth,
        /* [in] */ _ELASTOS Int32 theDate,
        /* [in] */ _ELASTOS Int32 theHour,
        /* [in] */ _ELASTOS Int32 theMinute,
        /* [in] */ _ELASTOS Int32 theSecond,
        /* [in] */ _ELASTOS Int32 theNano,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theYear, theMonth, theDate, theHour, theMinute, theSecond, theNano, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theYear,
        /* [in] */ _ELASTOS Int32 theMonth,
        /* [in] */ _ELASTOS Int32 theDate,
        /* [in] */ _ELASTOS Int32 theHour,
        /* [in] */ _ELASTOS Int32 theMinute,
        /* [in] */ _ELASTOS Int32 theSecond,
        /* [in] */ _ELASTOS Int32 theNano,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theYear, theMonth, theDate, theHour, theMinute, theSecond, theNano, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theYear,
        /* [in] */ _ELASTOS Int32 theMonth,
        /* [in] */ _ELASTOS Int32 theDate,
        /* [in] */ _ELASTOS Int32 theHour,
        /* [in] */ _ELASTOS Int32 theMinute,
        /* [in] */ _ELASTOS Int32 theSecond,
        /* [in] */ _ELASTOS Int32 theNano,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theYear, theMonth, theDate, theHour, theMinute, theSecond, theNano, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theYear,
        /* [in] */ _ELASTOS Int32 theMonth,
        /* [in] */ _ELASTOS Int32 theDate,
        /* [in] */ _ELASTOS Int32 theHour,
        /* [in] */ _ELASTOS Int32 theMinute,
        /* [in] */ _ELASTOS Int32 theSecond,
        /* [in] */ _ELASTOS Int32 theNano,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theYear, theMonth, theDate, theHour, theMinute, theSecond, theNano, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 theYear,
        /* [in] */ _ELASTOS Int32 theMonth,
        /* [in] */ _ELASTOS Int32 theDate,
        /* [in] */ _ELASTOS Int32 theHour,
        /* [in] */ _ELASTOS Int32 theMinute,
        /* [in] */ _ELASTOS Int32 theSecond,
        /* [in] */ _ELASTOS Int32 theNano,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theYear, theMonth, theDate, theHour, theMinute, theSecond, theNano, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theTime,
        /* [out] */ Elastos::Sql::ITimestamp** __ITimestamp)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theTime, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ITimestamp = (Elastos::Sql::ITimestamp*)__pNewObj->Probe(Elastos::Sql::EIID_ITimestamp);
        if (*__ITimestamp) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theTime,
        /* [out] */ Elastos::Utility::IDate** __IDate)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theTime, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDate = (Elastos::Utility::IDate*)__pNewObj->Probe(Elastos::Utility::EIID_IDate);
        if (*__IDate) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theTime,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theTime, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theTime,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theTime, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theTime,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theTime, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theTime,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theTime, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theTime,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theTime, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 theTime,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(theTime, &__pNewObj);
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
namespace Sql {
class CDriverPropertyInfo
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDriverPropertyInfoClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDriverPropertyInfo, RGM_SAME_DOMAIN,
                EIID_ICDriverPropertyInfoClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithNameValue(name, value, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ Elastos::Sql::IDriverPropertyInfo** __IDriverPropertyInfo)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDriverPropertyInfo = (Elastos::Sql::IDriverPropertyInfo*)__pNewObj->Probe(Elastos::Sql::EIID_IDriverPropertyInfo);
        if (*__IDriverPropertyInfo) __pNewObj->AddRef();
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
namespace Sql {
class CDataTruncation
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Boolean parameter,
        /* [in] */ _ELASTOS Boolean read,
        /* [in] */ _ELASTOS Int32 dataSize,
        /* [in] */ _ELASTOS Int32 transferSize,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDataTruncationClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDataTruncation, RGM_SAME_DOMAIN,
                EIID_ICDataTruncationClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIndexParameterReadDataSizeTransferSize(index, parameter, read, dataSize, transferSize, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Boolean parameter,
        /* [in] */ _ELASTOS Boolean read,
        /* [in] */ _ELASTOS Int32 dataSize,
        /* [in] */ _ELASTOS Int32 transferSize,
        /* [in] */ Elastos::Core::IThrowable * cause,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDataTruncationClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDataTruncation, RGM_SAME_DOMAIN,
                EIID_ICDataTruncationClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIndexParameterReadDataSizeTransferSizeCause(index, parameter, read, dataSize, transferSize, cause, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Boolean parameter,
        /* [in] */ _ELASTOS Boolean read,
        /* [in] */ _ELASTOS Int32 dataSize,
        /* [in] */ _ELASTOS Int32 transferSize,
        /* [out] */ Elastos::Sql::IDataTruncation** __IDataTruncation)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(index, parameter, read, dataSize, transferSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDataTruncation = (Elastos::Sql::IDataTruncation*)__pNewObj->Probe(Elastos::Sql::EIID_IDataTruncation);
        if (*__IDataTruncation) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Boolean parameter,
        /* [in] */ _ELASTOS Boolean read,
        /* [in] */ _ELASTOS Int32 dataSize,
        /* [in] */ _ELASTOS Int32 transferSize,
        /* [out] */ Elastos::Sql::ISQLWarning** __ISQLWarning)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(index, parameter, read, dataSize, transferSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISQLWarning = (Elastos::Sql::ISQLWarning*)__pNewObj->Probe(Elastos::Sql::EIID_ISQLWarning);
        if (*__ISQLWarning) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Boolean parameter,
        /* [in] */ _ELASTOS Boolean read,
        /* [in] */ _ELASTOS Int32 dataSize,
        /* [in] */ _ELASTOS Int32 transferSize,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(index, parameter, read, dataSize, transferSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Boolean parameter,
        /* [in] */ _ELASTOS Boolean read,
        /* [in] */ _ELASTOS Int32 dataSize,
        /* [in] */ _ELASTOS Int32 transferSize,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(index, parameter, read, dataSize, transferSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Boolean parameter,
        /* [in] */ _ELASTOS Boolean read,
        /* [in] */ _ELASTOS Int32 dataSize,
        /* [in] */ _ELASTOS Int32 transferSize,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(index, parameter, read, dataSize, transferSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Boolean parameter,
        /* [in] */ _ELASTOS Boolean read,
        /* [in] */ _ELASTOS Int32 dataSize,
        /* [in] */ _ELASTOS Int32 transferSize,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(index, parameter, read, dataSize, transferSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Boolean parameter,
        /* [in] */ _ELASTOS Boolean read,
        /* [in] */ _ELASTOS Int32 dataSize,
        /* [in] */ _ELASTOS Int32 transferSize,
        /* [in] */ Elastos::Core::IThrowable * cause,
        /* [out] */ Elastos::Sql::IDataTruncation** __IDataTruncation)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(index, parameter, read, dataSize, transferSize, cause, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDataTruncation = (Elastos::Sql::IDataTruncation*)__pNewObj->Probe(Elastos::Sql::EIID_IDataTruncation);
        if (*__IDataTruncation) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Boolean parameter,
        /* [in] */ _ELASTOS Boolean read,
        /* [in] */ _ELASTOS Int32 dataSize,
        /* [in] */ _ELASTOS Int32 transferSize,
        /* [in] */ Elastos::Core::IThrowable * cause,
        /* [out] */ Elastos::Sql::ISQLWarning** __ISQLWarning)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(index, parameter, read, dataSize, transferSize, cause, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISQLWarning = (Elastos::Sql::ISQLWarning*)__pNewObj->Probe(Elastos::Sql::EIID_ISQLWarning);
        if (*__ISQLWarning) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Boolean parameter,
        /* [in] */ _ELASTOS Boolean read,
        /* [in] */ _ELASTOS Int32 dataSize,
        /* [in] */ _ELASTOS Int32 transferSize,
        /* [in] */ Elastos::Core::IThrowable * cause,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(index, parameter, read, dataSize, transferSize, cause, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Boolean parameter,
        /* [in] */ _ELASTOS Boolean read,
        /* [in] */ _ELASTOS Int32 dataSize,
        /* [in] */ _ELASTOS Int32 transferSize,
        /* [in] */ Elastos::Core::IThrowable * cause,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(index, parameter, read, dataSize, transferSize, cause, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Boolean parameter,
        /* [in] */ _ELASTOS Boolean read,
        /* [in] */ _ELASTOS Int32 dataSize,
        /* [in] */ _ELASTOS Int32 transferSize,
        /* [in] */ Elastos::Core::IThrowable * cause,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(index, parameter, read, dataSize, transferSize, cause, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Boolean parameter,
        /* [in] */ _ELASTOS Boolean read,
        /* [in] */ _ELASTOS Int32 dataSize,
        /* [in] */ _ELASTOS Int32 transferSize,
        /* [in] */ Elastos::Core::IThrowable * cause,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(index, parameter, read, dataSize, transferSize, cause, &__pNewObj);
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
namespace Sql {
class CDriverManager
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Sql::IDriverManager** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDriverManager, RGM_SAME_DOMAIN, Elastos::Sql::EIID_IDriverManager, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDriverManager, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDriverManager, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDriverManager, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Sql {
class CSQLPermission
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSQLPermissionClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSQLPermission, RGM_SAME_DOMAIN,
                EIID_ICSQLPermissionClassObject, (IInterface**)&pClassObject);
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
        ICSQLPermissionClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSQLPermission, RGM_SAME_DOMAIN,
                EIID_ICSQLPermissionClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithNameActions(name, actions, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Sql::ISQLPermission** __ISQLPermission)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISQLPermission = (Elastos::Sql::ISQLPermission*)__pNewObj->Probe(Elastos::Sql::EIID_ISQLPermission);
        if (*__ISQLPermission) __pNewObj->AddRef();
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
        /* [out] */ Elastos::Sql::ISQLPermission** __ISQLPermission)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, actions, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISQLPermission = (Elastos::Sql::ISQLPermission*)__pNewObj->Probe(Elastos::Sql::EIID_ISQLPermission);
        if (*__ISQLPermission) __pNewObj->AddRef();
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
namespace Sql {
namespace SQLite {
class CTableResult
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 maxrows,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICTableResultClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CTableResult, RGM_SAME_DOMAIN,
                EIID_ICTableResultClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithMaxrows(maxrows, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Sql::SQLite::ITableResult** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTableResult, RGM_SAME_DOMAIN, Elastos::Sql::SQLite::EIID_ITableResult, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Sql::SQLite::ICallback** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTableResult, RGM_SAME_DOMAIN, Elastos::Sql::SQLite::EIID_ICallback, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTableResult, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTableResult, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTableResult, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 maxrows,
        /* [out] */ Elastos::Sql::SQLite::ITableResult** __ITableResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(maxrows, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ITableResult = (Elastos::Sql::SQLite::ITableResult*)__pNewObj->Probe(Elastos::Sql::SQLite::EIID_ITableResult);
        if (*__ITableResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 maxrows,
        /* [out] */ Elastos::Sql::SQLite::ICallback** __ICallback)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(maxrows, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICallback = (Elastos::Sql::SQLite::ICallback*)__pNewObj->Probe(Elastos::Sql::SQLite::EIID_ICallback);
        if (*__ICallback) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 maxrows,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(maxrows, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 maxrows,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(maxrows, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 maxrows,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(maxrows, &__pNewObj);
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
namespace Sql {
namespace SQLite {
class CShell
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IPrintWriter * pw,
        /* [in] */ Elastos::IO::IPrintWriter * err,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICShellClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CShell, RGM_SAME_DOMAIN,
                EIID_ICShellClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPwErr(pw, err, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IPrintStream * pw,
        /* [in] */ Elastos::IO::IPrintStream * errs,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICShellClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CShell, RGM_SAME_DOMAIN,
                EIID_ICShellClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPwErrs(pw, errs, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPrintWriter * pw,
        /* [in] */ Elastos::IO::IPrintWriter * err,
        /* [out] */ Elastos::Sql::SQLite::IShell** __IShell)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pw, err, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IShell = (Elastos::Sql::SQLite::IShell*)__pNewObj->Probe(Elastos::Sql::SQLite::EIID_IShell);
        if (*__IShell) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPrintWriter * pw,
        /* [in] */ Elastos::IO::IPrintWriter * err,
        /* [out] */ Elastos::Sql::SQLite::ICallback** __ICallback)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pw, err, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICallback = (Elastos::Sql::SQLite::ICallback*)__pNewObj->Probe(Elastos::Sql::SQLite::EIID_ICallback);
        if (*__ICallback) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPrintWriter * pw,
        /* [in] */ Elastos::IO::IPrintWriter * err,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pw, err, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPrintWriter * pw,
        /* [in] */ Elastos::IO::IPrintWriter * err,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pw, err, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPrintWriter * pw,
        /* [in] */ Elastos::IO::IPrintWriter * err,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pw, err, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPrintStream * pw,
        /* [in] */ Elastos::IO::IPrintStream * errs,
        /* [out] */ Elastos::Sql::SQLite::IShell** __IShell)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pw, errs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IShell = (Elastos::Sql::SQLite::IShell*)__pNewObj->Probe(Elastos::Sql::SQLite::EIID_IShell);
        if (*__IShell) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPrintStream * pw,
        /* [in] */ Elastos::IO::IPrintStream * errs,
        /* [out] */ Elastos::Sql::SQLite::ICallback** __ICallback)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pw, errs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICallback = (Elastos::Sql::SQLite::ICallback*)__pNewObj->Probe(Elastos::Sql::SQLite::EIID_ICallback);
        if (*__ICallback) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPrintStream * pw,
        /* [in] */ Elastos::IO::IPrintStream * errs,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pw, errs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPrintStream * pw,
        /* [in] */ Elastos::IO::IPrintStream * errs,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pw, errs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IPrintStream * pw,
        /* [in] */ Elastos::IO::IPrintStream * errs,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pw, errs, &__pNewObj);
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
namespace Sql {
namespace SQLite {
class CDBDump
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Sql::SQLite::IShell * s,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * tables,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDBDumpClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDBDump, RGM_SAME_DOMAIN,
                EIID_ICDBDumpClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSTables(s, tables, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::IShell * s,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * tables,
        /* [out] */ Elastos::Sql::SQLite::IDBDump** __IDBDump)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s, tables, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDBDump = (Elastos::Sql::SQLite::IDBDump*)__pNewObj->Probe(Elastos::Sql::SQLite::EIID_IDBDump);
        if (*__IDBDump) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::IShell * s,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * tables,
        /* [out] */ Elastos::Sql::SQLite::ICallback** __ICallback)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s, tables, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICallback = (Elastos::Sql::SQLite::ICallback*)__pNewObj->Probe(Elastos::Sql::SQLite::EIID_ICallback);
        if (*__ICallback) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::IShell * s,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * tables,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s, tables, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::IShell * s,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * tables,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s, tables, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::IShell * s,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * tables,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s, tables, &__pNewObj);
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
namespace Sql {
namespace SQLite {
class CVm
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::Sql::SQLite::IVm** __object)
    {
        return _CObject_CreateInstance(ECLSID_CVm, RGM_SAME_DOMAIN, Elastos::Sql::SQLite::EIID_IVm, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CVm, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CVm, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CVm, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
class CBlob
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::Sql::SQLite::IBlob** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBlob, RGM_SAME_DOMAIN, Elastos::Sql::SQLite::EIID_IBlob, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBlob, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBlob, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBlob, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
class CBlobR
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Sql::SQLite::IBlob * blob,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBlobRClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBlobR, RGM_SAME_DOMAIN,
                EIID_ICBlobRClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithBlob(blob, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::IBlob * blob,
        /* [out] */ Elastos::Sql::SQLite::IBlobR** __IBlobR)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(blob, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBlobR = (Elastos::Sql::SQLite::IBlobR*)__pNewObj->Probe(Elastos::Sql::SQLite::EIID_IBlobR);
        if (*__IBlobR) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::IBlob * blob,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(blob, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::IBlob * blob,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(blob, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::IBlob * blob,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(blob, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::IBlob * blob,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(blob, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::IBlob * blob,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(blob, &__pNewObj);
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
namespace Sql {
namespace SQLite {
class CBlobW
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Sql::SQLite::IBlob * blob,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBlobWClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBlobW, RGM_SAME_DOMAIN,
                EIID_ICBlobWClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithBlob(blob, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::IBlob * blob,
        /* [out] */ Elastos::Sql::SQLite::IBlobW** __IBlobW)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(blob, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBlobW = (Elastos::Sql::SQLite::IBlobW*)__pNewObj->Probe(Elastos::Sql::SQLite::EIID_IBlobW);
        if (*__IBlobW) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::IBlob * blob,
        /* [out] */ Elastos::IO::IOutputStream** __IOutputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(blob, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IOutputStream = (Elastos::IO::IOutputStream*)__pNewObj->Probe(Elastos::IO::EIID_IOutputStream);
        if (*__IOutputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::IBlob * blob,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(blob, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::IBlob * blob,
        /* [out] */ Elastos::IO::IFlushable** __IFlushable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(blob, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFlushable = (Elastos::IO::IFlushable*)__pNewObj->Probe(Elastos::IO::EIID_IFlushable);
        if (*__IFlushable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::IBlob * blob,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(blob, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::IBlob * blob,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(blob, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::IBlob * blob,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(blob, &__pNewObj);
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
namespace Sql {
namespace SQLite {
class CDatabase
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::Sql::SQLite::IDatabase** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatabase, RGM_SAME_DOMAIN, Elastos::Sql::SQLite::EIID_IDatabase, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatabase, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatabase, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatabase, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
class CDatabaseHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Sql::SQLite::IDatabaseHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatabaseHelper, RGM_SAME_DOMAIN, Elastos::Sql::SQLite::EIID_IDatabaseHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatabaseHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatabaseHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatabaseHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
class CJDBCDriver
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::Sql::IDriver** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJDBCDriver, RGM_SAME_DOMAIN, Elastos::Sql::EIID_IDriver, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJDBCDriver, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJDBCDriver, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJDBCDriver, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
class CBackup
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::Sql::SQLite::IBackup** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBackup, RGM_SAME_DOMAIN, Elastos::Sql::SQLite::EIID_IBackup, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBackup, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBackup, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBackup, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
class CFunctionContext
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::Sql::SQLite::IFunctionContext** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFunctionContext, RGM_SAME_DOMAIN, Elastos::Sql::SQLite::EIID_IFunctionContext, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFunctionContext, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFunctionContext, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFunctionContext, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
class CStmt
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::Sql::SQLite::IStmt** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStmt, RGM_SAME_DOMAIN, Elastos::Sql::SQLite::EIID_IStmt, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStmt, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStmt, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStmt, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
class CStringEncoderHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Sql::SQLite::IStringEncoderHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStringEncoderHelper, RGM_SAME_DOMAIN, Elastos::Sql::SQLite::EIID_IStringEncoderHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStringEncoderHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStringEncoderHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStringEncoderHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
namespace JDBC {
class CJDBCConnection
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& url,
        /* [in] */ const _ELASTOS String& enc,
        /* [in] */ const _ELASTOS String& pwd,
        /* [in] */ const _ELASTOS String& drep,
        /* [in] */ const _ELASTOS String& vfs,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJDBCConnectionClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJDBCConnection, RGM_SAME_DOMAIN,
                EIID_ICJDBCConnectionClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithUrlEncPwdDrepVfs(url, enc, pwd, drep, vfs, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& url,
        /* [in] */ const _ELASTOS String& enc,
        /* [in] */ const _ELASTOS String& pwd,
        /* [in] */ const _ELASTOS String& drep,
        /* [in] */ const _ELASTOS String& vfs,
        /* [out] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection** __IJDBCConnection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(url, enc, pwd, drep, vfs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJDBCConnection = (Elastos::Sql::SQLite::JDBC::IJDBCConnection*)__pNewObj->Probe(Elastos::Sql::SQLite::JDBC::EIID_IJDBCConnection);
        if (*__IJDBCConnection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& url,
        /* [in] */ const _ELASTOS String& enc,
        /* [in] */ const _ELASTOS String& pwd,
        /* [in] */ const _ELASTOS String& drep,
        /* [in] */ const _ELASTOS String& vfs,
        /* [out] */ Elastos::Sql::IConnection** __IConnection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(url, enc, pwd, drep, vfs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IConnection = (Elastos::Sql::IConnection*)__pNewObj->Probe(Elastos::Sql::EIID_IConnection);
        if (*__IConnection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& url,
        /* [in] */ const _ELASTOS String& enc,
        /* [in] */ const _ELASTOS String& pwd,
        /* [in] */ const _ELASTOS String& drep,
        /* [in] */ const _ELASTOS String& vfs,
        /* [out] */ Elastos::Sql::IWrapper** __IWrapper)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(url, enc, pwd, drep, vfs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWrapper = (Elastos::Sql::IWrapper*)__pNewObj->Probe(Elastos::Sql::EIID_IWrapper);
        if (*__IWrapper) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& url,
        /* [in] */ const _ELASTOS String& enc,
        /* [in] */ const _ELASTOS String& pwd,
        /* [in] */ const _ELASTOS String& drep,
        /* [in] */ const _ELASTOS String& vfs,
        /* [out] */ Elastos::Sql::SQLite::IBusyHandler** __IBusyHandler)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(url, enc, pwd, drep, vfs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBusyHandler = (Elastos::Sql::SQLite::IBusyHandler*)__pNewObj->Probe(Elastos::Sql::SQLite::EIID_IBusyHandler);
        if (*__IBusyHandler) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& url,
        /* [in] */ const _ELASTOS String& enc,
        /* [in] */ const _ELASTOS String& pwd,
        /* [in] */ const _ELASTOS String& drep,
        /* [in] */ const _ELASTOS String& vfs,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(url, enc, pwd, drep, vfs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& url,
        /* [in] */ const _ELASTOS String& enc,
        /* [in] */ const _ELASTOS String& pwd,
        /* [in] */ const _ELASTOS String& drep,
        /* [in] */ const _ELASTOS String& vfs,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(url, enc, pwd, drep, vfs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& url,
        /* [in] */ const _ELASTOS String& enc,
        /* [in] */ const _ELASTOS String& pwd,
        /* [in] */ const _ELASTOS String& drep,
        /* [in] */ const _ELASTOS String& vfs,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(url, enc, pwd, drep, vfs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& url,
        /* [in] */ const _ELASTOS String& enc,
        /* [in] */ const _ELASTOS String& pwd,
        /* [in] */ const _ELASTOS String& drep,
        /* [in] */ const _ELASTOS String& vfs,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(url, enc, pwd, drep, vfs, &__pNewObj);
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
namespace Elastos {
namespace Sql {
namespace SQLite {
namespace JDBC {
class CJDBCPreparedStatement
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [in] */ const _ELASTOS String& sql,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJDBCPreparedStatementClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJDBCPreparedStatement, RGM_SAME_DOMAIN,
                EIID_ICJDBCPreparedStatementClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithConnSql(conn, sql, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [in] */ const _ELASTOS String& sql,
        /* [out] */ Elastos::Sql::SQLite::JDBC::IJDBCPreparedStatement** __IJDBCPreparedStatement)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(conn, sql, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJDBCPreparedStatement = (Elastos::Sql::SQLite::JDBC::IJDBCPreparedStatement*)__pNewObj->Probe(Elastos::Sql::SQLite::JDBC::EIID_IJDBCPreparedStatement);
        if (*__IJDBCPreparedStatement) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [in] */ const _ELASTOS String& sql,
        /* [out] */ Elastos::Sql::SQLite::JDBC::IJDBCStatement** __IJDBCStatement)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(conn, sql, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJDBCStatement = (Elastos::Sql::SQLite::JDBC::IJDBCStatement*)__pNewObj->Probe(Elastos::Sql::SQLite::JDBC::EIID_IJDBCStatement);
        if (*__IJDBCStatement) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [in] */ const _ELASTOS String& sql,
        /* [out] */ Elastos::Sql::IStatement** __IStatement)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(conn, sql, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStatement = (Elastos::Sql::IStatement*)__pNewObj->Probe(Elastos::Sql::EIID_IStatement);
        if (*__IStatement) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [in] */ const _ELASTOS String& sql,
        /* [out] */ Elastos::Sql::IWrapper** __IWrapper)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(conn, sql, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWrapper = (Elastos::Sql::IWrapper*)__pNewObj->Probe(Elastos::Sql::EIID_IWrapper);
        if (*__IWrapper) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [in] */ const _ELASTOS String& sql,
        /* [out] */ Elastos::Sql::IPreparedStatement** __IPreparedStatement)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(conn, sql, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPreparedStatement = (Elastos::Sql::IPreparedStatement*)__pNewObj->Probe(Elastos::Sql::EIID_IPreparedStatement);
        if (*__IPreparedStatement) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [in] */ const _ELASTOS String& sql,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(conn, sql, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [in] */ const _ELASTOS String& sql,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(conn, sql, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [in] */ const _ELASTOS String& sql,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(conn, sql, &__pNewObj);
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
namespace Elastos {
namespace Sql {
namespace SQLite {
namespace JDBC {
class CJDBCStatement
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJDBCStatementClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJDBCStatement, RGM_SAME_DOMAIN,
                EIID_ICJDBCStatementClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithConn(conn, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [out] */ Elastos::Sql::SQLite::JDBC::IJDBCStatement** __IJDBCStatement)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(conn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJDBCStatement = (Elastos::Sql::SQLite::JDBC::IJDBCStatement*)__pNewObj->Probe(Elastos::Sql::SQLite::JDBC::EIID_IJDBCStatement);
        if (*__IJDBCStatement) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [out] */ Elastos::Sql::IStatement** __IStatement)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(conn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStatement = (Elastos::Sql::IStatement*)__pNewObj->Probe(Elastos::Sql::EIID_IStatement);
        if (*__IStatement) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [out] */ Elastos::Sql::IWrapper** __IWrapper)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(conn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWrapper = (Elastos::Sql::IWrapper*)__pNewObj->Probe(Elastos::Sql::EIID_IWrapper);
        if (*__IWrapper) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(conn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(conn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(conn, &__pNewObj);
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
namespace Elastos {
namespace Sql {
namespace SQLite {
namespace JDBC {
class CJDBCResultSetMetaData
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCResultSet * r,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJDBCResultSetMetaDataClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJDBCResultSetMetaData, RGM_SAME_DOMAIN,
                EIID_ICJDBCResultSetMetaDataClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithR(r, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCResultSet * r,
        /* [out] */ Elastos::Sql::SQLite::JDBC::IJDBCResultSetMetaData** __IJDBCResultSetMetaData)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(r, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJDBCResultSetMetaData = (Elastos::Sql::SQLite::JDBC::IJDBCResultSetMetaData*)__pNewObj->Probe(Elastos::Sql::SQLite::JDBC::EIID_IJDBCResultSetMetaData);
        if (*__IJDBCResultSetMetaData) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCResultSet * r,
        /* [out] */ Elastos::Sql::IResultSetMetaData** __IResultSetMetaData)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(r, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IResultSetMetaData = (Elastos::Sql::IResultSetMetaData*)__pNewObj->Probe(Elastos::Sql::EIID_IResultSetMetaData);
        if (*__IResultSetMetaData) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCResultSet * r,
        /* [out] */ Elastos::Sql::IWrapper** __IWrapper)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(r, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWrapper = (Elastos::Sql::IWrapper*)__pNewObj->Probe(Elastos::Sql::EIID_IWrapper);
        if (*__IWrapper) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCResultSet * r,
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
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCResultSet * r,
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
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCResultSet * r,
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
}
}
namespace Elastos {
namespace Sql {
namespace SQLite {
namespace JDBC {
class CTableResultX
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 maxrows,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICTableResultXClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CTableResultX, RGM_SAME_DOMAIN,
                EIID_ICTableResultXClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithMaxrows(maxrows, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Sql::SQLite::ITableResult * tr,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICTableResultXClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CTableResultX, RGM_SAME_DOMAIN,
                EIID_ICTableResultXClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTr(tr, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Sql::SQLite::JDBC::ITableResultX** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTableResultX, RGM_SAME_DOMAIN, Elastos::Sql::SQLite::JDBC::EIID_ITableResultX, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Sql::SQLite::ITableResult** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTableResultX, RGM_SAME_DOMAIN, Elastos::Sql::SQLite::EIID_ITableResult, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Sql::SQLite::ICallback** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTableResultX, RGM_SAME_DOMAIN, Elastos::Sql::SQLite::EIID_ICallback, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTableResultX, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTableResultX, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTableResultX, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 maxrows,
        /* [out] */ Elastos::Sql::SQLite::JDBC::ITableResultX** __ITableResultX)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(maxrows, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ITableResultX = (Elastos::Sql::SQLite::JDBC::ITableResultX*)__pNewObj->Probe(Elastos::Sql::SQLite::JDBC::EIID_ITableResultX);
        if (*__ITableResultX) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 maxrows,
        /* [out] */ Elastos::Sql::SQLite::ITableResult** __ITableResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(maxrows, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ITableResult = (Elastos::Sql::SQLite::ITableResult*)__pNewObj->Probe(Elastos::Sql::SQLite::EIID_ITableResult);
        if (*__ITableResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 maxrows,
        /* [out] */ Elastos::Sql::SQLite::ICallback** __ICallback)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(maxrows, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICallback = (Elastos::Sql::SQLite::ICallback*)__pNewObj->Probe(Elastos::Sql::SQLite::EIID_ICallback);
        if (*__ICallback) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 maxrows,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(maxrows, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 maxrows,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(maxrows, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 maxrows,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(maxrows, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::ITableResult * tr,
        /* [out] */ Elastos::Sql::SQLite::JDBC::ITableResultX** __ITableResultX)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ITableResultX = (Elastos::Sql::SQLite::JDBC::ITableResultX*)__pNewObj->Probe(Elastos::Sql::SQLite::JDBC::EIID_ITableResultX);
        if (*__ITableResultX) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::ITableResult * tr,
        /* [out] */ Elastos::Sql::SQLite::ITableResult** __ITableResult)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ITableResult = (Elastos::Sql::SQLite::ITableResult*)__pNewObj->Probe(Elastos::Sql::SQLite::EIID_ITableResult);
        if (*__ITableResult) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::ITableResult * tr,
        /* [out] */ Elastos::Sql::SQLite::ICallback** __ICallback)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICallback = (Elastos::Sql::SQLite::ICallback*)__pNewObj->Probe(Elastos::Sql::SQLite::EIID_ICallback);
        if (*__ICallback) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::ITableResult * tr,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::ITableResult * tr,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tr, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::ITableResult * tr,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tr, &__pNewObj);
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
namespace Elastos {
namespace Sql {
namespace SQLite {
namespace JDBC {
class CJDBCDatabaseMetaData
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJDBCDatabaseMetaDataClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJDBCDatabaseMetaData, RGM_SAME_DOMAIN,
                EIID_ICJDBCDatabaseMetaDataClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithConn(conn, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [out] */ Elastos::Sql::SQLite::JDBC::IJDBCDatabaseMetaData** __IJDBCDatabaseMetaData)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(conn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJDBCDatabaseMetaData = (Elastos::Sql::SQLite::JDBC::IJDBCDatabaseMetaData*)__pNewObj->Probe(Elastos::Sql::SQLite::JDBC::EIID_IJDBCDatabaseMetaData);
        if (*__IJDBCDatabaseMetaData) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [out] */ Elastos::Sql::IDatabaseMetaData** __IDatabaseMetaData)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(conn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDatabaseMetaData = (Elastos::Sql::IDatabaseMetaData*)__pNewObj->Probe(Elastos::Sql::EIID_IDatabaseMetaData);
        if (*__IDatabaseMetaData) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [out] */ Elastos::Sql::IWrapper** __IWrapper)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(conn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWrapper = (Elastos::Sql::IWrapper*)__pNewObj->Probe(Elastos::Sql::EIID_IWrapper);
        if (*__IWrapper) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(conn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(conn, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCConnection * conn,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(conn, &__pNewObj);
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
namespace Elastos {
namespace Sql {
namespace SQLite {
namespace JDBC {
class CJDBCResultSet
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Sql::SQLite::ITableResult * tr,
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCStatement * s,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJDBCResultSetClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJDBCResultSet, RGM_SAME_DOMAIN,
                EIID_ICJDBCResultSetClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTrS(tr, s, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::ITableResult * tr,
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCStatement * s,
        /* [out] */ Elastos::Sql::SQLite::JDBC::IJDBCResultSet** __IJDBCResultSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tr, s, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJDBCResultSet = (Elastos::Sql::SQLite::JDBC::IJDBCResultSet*)__pNewObj->Probe(Elastos::Sql::SQLite::JDBC::EIID_IJDBCResultSet);
        if (*__IJDBCResultSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::ITableResult * tr,
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCStatement * s,
        /* [out] */ Elastos::Sql::IResultSet** __IResultSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tr, s, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IResultSet = (Elastos::Sql::IResultSet*)__pNewObj->Probe(Elastos::Sql::EIID_IResultSet);
        if (*__IResultSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::ITableResult * tr,
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCStatement * s,
        /* [out] */ Elastos::Sql::IWrapper** __IWrapper)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tr, s, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWrapper = (Elastos::Sql::IWrapper*)__pNewObj->Probe(Elastos::Sql::EIID_IWrapper);
        if (*__IWrapper) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::ITableResult * tr,
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCStatement * s,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tr, s, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::ITableResult * tr,
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCStatement * s,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tr, s, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Sql::SQLite::ITableResult * tr,
        /* [in] */ Elastos::Sql::SQLite::JDBC::IJDBCStatement * s,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tr, s, &__pNewObj);
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
namespace Elastos {
namespace Sql {
namespace SQLite {
namespace JDBC {
class CDatabaseX
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::Sql::SQLite::IDatabase** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatabaseX, RGM_SAME_DOMAIN, Elastos::Sql::SQLite::EIID_IDatabase, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatabaseX, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatabaseX, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDatabaseX, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
}

#endif // __Elastos_CoreLibrary_Sql_h__
