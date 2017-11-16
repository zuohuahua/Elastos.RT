#ifndef ___Elastos_CoreLibrary_Utility_Concurrent_h__
#define ___Elastos_CoreLibrary_Utility_Concurrent_h__

#include <Elastos.CoreLibrary.h>

EXTERN_C ELAPI _Impl_AcquireCallbackHandler(PInterface pServerObj, _ELASTOS REIID iid, PInterface *ppHandler);
EXTERN_C ELAPI _Impl_CheckClsId(PInterface pServerObj, const _ELASTOS ClassID* pClassid, PInterface *ppServerObj);

namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Atomic {
CAR_INTERFACE("44EC6503-7292-30CB-6B2E-B2FCA264FC3B")
IAtomicBoolean : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAtomicBoolean*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicBoolean*)pObj->Probe(EIID_IAtomicBoolean);
    }

    static CARAPI_(IAtomicBoolean*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicBoolean*)pObj->Probe(EIID_IAtomicBoolean);
    }

    virtual CARAPI Get(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Set(
        /* [in] */ _ELASTOS Boolean newValue) = 0;

    virtual CARAPI LazySet(
        /* [in] */ _ELASTOS Boolean newValue) = 0;

    virtual CARAPI GetAndSet(
        /* [in] */ _ELASTOS Boolean newValue,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI CompareAndSet(
        /* [in] */ _ELASTOS Boolean expect,
        /* [in] */ _ELASTOS Boolean update,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI WeakCompareAndSet(
        /* [in] */ _ELASTOS Boolean expect,
        /* [in] */ _ELASTOS Boolean update,
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Atomic {
CAR_INTERFACE("A8C1DE16-7292-30CB-6B4A-F18DAA683D08")
IAtomicInteger32 : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAtomicInteger32*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicInteger32*)pObj->Probe(EIID_IAtomicInteger32);
    }

    static CARAPI_(IAtomicInteger32*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicInteger32*)pObj->Probe(EIID_IAtomicInteger32);
    }

    virtual CARAPI Get(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Set(
        /* [in] */ _ELASTOS Int32 newValue) = 0;

    virtual CARAPI LazySet(
        /* [in] */ _ELASTOS Int32 newValue) = 0;

    virtual CARAPI GetAndSet(
        /* [in] */ _ELASTOS Int32 newValue,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI CompareAndSet(
        /* [in] */ _ELASTOS Int32 expect,
        /* [in] */ _ELASTOS Int32 update,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI WeakCompareAndSet(
        /* [in] */ _ELASTOS Int32 expect,
        /* [in] */ _ELASTOS Int32 update,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetAndIncrement(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetAndDecrement(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetAndAdd(
        /* [in] */ _ELASTOS Int32 delta,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI IncrementAndGet(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI DecrementAndGet(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI AddAndGet(
        /* [in] */ _ELASTOS Int32 delta,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Int32Value(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Int64Value(
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI FloatValue(
        /* [out] */ _ELASTOS Float * value) = 0;

    virtual CARAPI DoubleValue(
        /* [out] */ _ELASTOS Double * value) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Atomic {
CAR_INTERFACE("41DECB05-7292-30CB-6B4A-F18DAA683D08")
IAtomicInteger32Array : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAtomicInteger32Array*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicInteger32Array*)pObj->Probe(EIID_IAtomicInteger32Array);
    }

    static CARAPI_(IAtomicInteger32Array*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicInteger32Array*)pObj->Probe(EIID_IAtomicInteger32Array);
    }

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Set(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Int32 newValue) = 0;

    virtual CARAPI LazySet(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Int32 newValue) = 0;

    virtual CARAPI GetAndSet(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Int32 newValue,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI CompareAndSet(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Int32 expect,
        /* [in] */ _ELASTOS Int32 update,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI WeakCompareAndSet(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Int32 expect,
        /* [in] */ _ELASTOS Int32 update,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetAndIncrement(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetAndDecrement(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetAndAdd(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Int32 delta,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI IncrementAndGet(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI DecrementAndGet(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI AddAndGet(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Int32 delta,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Atomic {
CAR_INTERFACE("899CC106-7292-30CB-6B4A-F18DAA683D08")
IAtomicInteger32FieldUpdater : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAtomicInteger32FieldUpdater*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicInteger32FieldUpdater*)pObj->Probe(EIID_IAtomicInteger32FieldUpdater);
    }

    static CARAPI_(IAtomicInteger32FieldUpdater*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicInteger32FieldUpdater*)pObj->Probe(EIID_IAtomicInteger32FieldUpdater);
    }

    virtual CARAPI CompareAndSet(
        /* [in] */ IInterface * obj,
        /* [in] */ _ELASTOS Int32 expect,
        /* [in] */ _ELASTOS Int32 update,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI WeakCompareAndSet(
        /* [in] */ IInterface * obj,
        /* [in] */ _ELASTOS Int32 expect,
        /* [in] */ _ELASTOS Int32 update,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Set(
        /* [in] */ IInterface * obj,
        /* [in] */ _ELASTOS Int32 newValue) = 0;

    virtual CARAPI LazySet(
        /* [in] */ IInterface * obj,
        /* [in] */ _ELASTOS Int32 newValue) = 0;

    virtual CARAPI Get(
        /* [in] */ IInterface * obj,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetAndSet(
        /* [in] */ IInterface * obj,
        /* [in] */ _ELASTOS Int32 newValue,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetAndIncrement(
        /* [in] */ IInterface * obj,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetAndDecrement(
        /* [in] */ IInterface * obj,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetAndAdd(
        /* [in] */ IInterface * obj,
        /* [in] */ _ELASTOS Int32 delta,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI IncrementAndGet(
        /* [in] */ IInterface * obj,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI DecrementAndGet(
        /* [in] */ IInterface * obj,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI AddAndGet(
        /* [in] */ IInterface * obj,
        /* [in] */ _ELASTOS Int32 delta,
        /* [out] */ _ELASTOS Int32 * value) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Atomic {
CAR_INTERFACE("A6BEDE03-7292-30CB-6B4A-F18DAA686D10")
IAtomicInteger64 : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAtomicInteger64*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicInteger64*)pObj->Probe(EIID_IAtomicInteger64);
    }

    static CARAPI_(IAtomicInteger64*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicInteger64*)pObj->Probe(EIID_IAtomicInteger64);
    }

    virtual CARAPI Get(
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI Set(
        /* [in] */ _ELASTOS Int64 newValue) = 0;

    virtual CARAPI LazySet(
        /* [in] */ _ELASTOS Int64 newValue) = 0;

    virtual CARAPI GetAndSet(
        /* [in] */ _ELASTOS Int64 newValue,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI CompareAndSet(
        /* [in] */ _ELASTOS Int64 expect,
        /* [in] */ _ELASTOS Int64 update,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI WeakCompareAndSet(
        /* [in] */ _ELASTOS Int64 expect,
        /* [in] */ _ELASTOS Int64 update,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetAndIncrement(
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI GetAndDecrement(
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI GetAndAdd(
        /* [in] */ _ELASTOS Int64 delta,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI IncrementAndGet(
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI DecrementAndGet(
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI AddAndGet(
        /* [in] */ _ELASTOS Int64 delta,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI Int32Value(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Int64Value(
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI FloatValue(
        /* [out] */ _ELASTOS Float * value) = 0;

    virtual CARAPI DoubleValue(
        /* [out] */ _ELASTOS Double * value) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Atomic {
CAR_INTERFACE("3FDBCB11-7292-30CB-6B4A-F18DAA686D10")
IAtomicInteger64Array : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAtomicInteger64Array*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicInteger64Array*)pObj->Probe(EIID_IAtomicInteger64Array);
    }

    static CARAPI_(IAtomicInteger64Array*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicInteger64Array*)pObj->Probe(EIID_IAtomicInteger64Array);
    }

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS Int32 i,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI Set(
        /* [in] */ _ELASTOS Int32 i,
        /* [in] */ _ELASTOS Int64 newValue) = 0;

    virtual CARAPI LazySet(
        /* [in] */ _ELASTOS Int32 i,
        /* [in] */ _ELASTOS Int64 newValue) = 0;

    virtual CARAPI GetAndSet(
        /* [in] */ _ELASTOS Int32 i,
        /* [in] */ _ELASTOS Int64 newValue,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI CompareAndSet(
        /* [in] */ _ELASTOS Int32 i,
        /* [in] */ _ELASTOS Int64 expect,
        /* [in] */ _ELASTOS Int64 update,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI WeakCompareAndSet(
        /* [in] */ _ELASTOS Int32 i,
        /* [in] */ _ELASTOS Int64 expect,
        /* [in] */ _ELASTOS Int64 update,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetAndIncrement(
        /* [in] */ _ELASTOS Int32 i,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI GetAndDecrement(
        /* [in] */ _ELASTOS Int32 i,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI GetAndAdd(
        /* [in] */ _ELASTOS Int32 i,
        /* [in] */ _ELASTOS Int64 delta,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI IncrementAndGet(
        /* [in] */ _ELASTOS Int32 i,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI DecrementAndGet(
        /* [in] */ _ELASTOS Int32 i,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI AddAndGet(
        /* [in] */ _ELASTOS Int32 i,
        /* [in] */ _ELASTOS Int64 delta,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Atomic {
CAR_INTERFACE("8799C112-7292-30CB-6B4A-F18DAA686D10")
IAtomicInteger64FieldUpdater : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAtomicInteger64FieldUpdater*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicInteger64FieldUpdater*)pObj->Probe(EIID_IAtomicInteger64FieldUpdater);
    }

    static CARAPI_(IAtomicInteger64FieldUpdater*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicInteger64FieldUpdater*)pObj->Probe(EIID_IAtomicInteger64FieldUpdater);
    }

    virtual CARAPI CompareAndSet(
        /* [in] */ IInterface * obj,
        /* [in] */ IInterface * expect,
        /* [in] */ IInterface * update,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI WeakCompareAndSet(
        /* [in] */ IInterface * obj,
        /* [in] */ _ELASTOS Int64 expect,
        /* [in] */ _ELASTOS Int64 update,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Set(
        /* [in] */ IInterface * obj,
        /* [in] */ _ELASTOS Int64 newValue) = 0;

    virtual CARAPI LazySet(
        /* [in] */ IInterface * obj,
        /* [in] */ _ELASTOS Int64 newValue) = 0;

    virtual CARAPI Get(
        /* [in] */ IInterface * obj,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI GetAndSet(
        /* [in] */ IInterface * obj,
        /* [in] */ _ELASTOS Int64 newValue,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI GetAndIncrement(
        /* [in] */ IInterface * obj,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI GetAndDecrement(
        /* [in] */ IInterface * obj,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI GetAndAdd(
        /* [in] */ IInterface * obj,
        /* [in] */ _ELASTOS Int64 delta,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI IncrementAndGet(
        /* [in] */ IInterface * obj,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI DecrementAndGet(
        /* [in] */ IInterface * obj,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI AddAndGet(
        /* [in] */ IInterface * obj,
        /* [in] */ _ELASTOS Int64 delta,
        /* [out] */ _ELASTOS Int64 * value) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Atomic {
CAR_INTERFACE("8EAC7E45-1052-3C19-4D58-48E4424F9A6C")
IAtomicMarkableReference : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAtomicMarkableReference*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicMarkableReference*)pObj->Probe(EIID_IAtomicMarkableReference);
    }

    static CARAPI_(IAtomicMarkableReference*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicMarkableReference*)pObj->Probe(EIID_IAtomicMarkableReference);
    }

    virtual CARAPI GetReference(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI IsMarked(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Boolean> * markHolder,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI WeakCompareAndSet(
        /* [in] */ IInterface * expectedReference,
        /* [in] */ IInterface * newReference,
        /* [in] */ _ELASTOS Boolean expectedMark,
        /* [in] */ _ELASTOS Boolean newMark,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI CompareAndSet(
        /* [in] */ IInterface * expectedReference,
        /* [in] */ IInterface * newReference,
        /* [in] */ _ELASTOS Boolean expectedMark,
        /* [in] */ _ELASTOS Boolean newMark,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Set(
        /* [in] */ IInterface * newReference,
        /* [in] */ _ELASTOS Boolean newMark) = 0;

    virtual CARAPI AttemptMark(
        /* [in] */ IInterface * expectedReference,
        /* [in] */ _ELASTOS Boolean newMark,
        /* [out] */ _ELASTOS Boolean * value) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Atomic {
CAR_INTERFACE("67BC6F51-1052-3C19-4DA4-C9863706A81F")
IAtomicReference : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAtomicReference*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicReference*)pObj->Probe(EIID_IAtomicReference);
    }

    static CARAPI_(IAtomicReference*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicReference*)pObj->Probe(EIID_IAtomicReference);
    }

    virtual CARAPI Get(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI Set(
        /* [in] */ IInterface * newValue) = 0;

    virtual CARAPI LazySet(
        /* [in] */ IInterface * newValue) = 0;

    virtual CARAPI CompareAndSet(
        /* [in] */ IInterface * expect,
        /* [in] */ IInterface * update,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI WeakCompareAndSet(
        /* [in] */ IInterface * expect,
        /* [in] */ IInterface * update,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetAndSet(
        /* [in] */ IInterface * newValue,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Atomic {
CAR_INTERFACE("F9A37D51-1052-3C19-4DA4-C98637062805")
IAtomicReferenceArray : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAtomicReferenceArray*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicReferenceArray*)pObj->Probe(EIID_IAtomicReferenceArray);
    }

    static CARAPI_(IAtomicReferenceArray*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicReferenceArray*)pObj->Probe(EIID_IAtomicReferenceArray);
    }

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS Int32 i,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI Set(
        /* [in] */ _ELASTOS Int32 i,
        /* [in] */ IInterface * newValue) = 0;

    virtual CARAPI LazySet(
        /* [in] */ _ELASTOS Int32 i,
        /* [in] */ IInterface * newValue) = 0;

    virtual CARAPI GetAndSet(
        /* [in] */ _ELASTOS Int32 i,
        /* [in] */ IInterface * newValue,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI CompareAndSet(
        /* [in] */ _ELASTOS Int32 i,
        /* [in] */ IInterface * expect,
        /* [in] */ IInterface * update,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI WeakCompareAndSet(
        /* [in] */ _ELASTOS Int32 i,
        /* [in] */ IInterface * expect,
        /* [in] */ IInterface * update,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Atomic {
CAR_INTERFACE("41627341-1052-3C19-4DA4-C9863706A807")
IAtomicReferenceFieldUpdater : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAtomicReferenceFieldUpdater*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicReferenceFieldUpdater*)pObj->Probe(EIID_IAtomicReferenceFieldUpdater);
    }

    static CARAPI_(IAtomicReferenceFieldUpdater*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicReferenceFieldUpdater*)pObj->Probe(EIID_IAtomicReferenceFieldUpdater);
    }

    virtual CARAPI CompareAndSet(
        /* [in] */ IInterface * obj,
        /* [in] */ IInterface * expect,
        /* [in] */ IInterface * update,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI WeakCompareAndSet(
        /* [in] */ IInterface * obj,
        /* [in] */ IInterface * expect,
        /* [in] */ IInterface * update,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Set(
        /* [in] */ IInterface * obj,
        /* [in] */ IInterface * newValue) = 0;

    virtual CARAPI LazySet(
        /* [in] */ IInterface * obj,
        /* [in] */ IInterface * newValue) = 0;

    virtual CARAPI Get(
        /* [in] */ IInterface * obj,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetAndSet(
        /* [in] */ IInterface * obj,
        /* [in] */ IInterface * newValue,
        /* [out] */ IInterface ** outface) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Atomic {
CAR_INTERFACE("E01C7E0C-7292-30CB-6B72-3709CFE8B9A1")
IAtomicStampedReference : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAtomicStampedReference*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicStampedReference*)pObj->Probe(EIID_IAtomicStampedReference);
    }

    static CARAPI_(IAtomicStampedReference*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAtomicStampedReference*)pObj->Probe(EIID_IAtomicStampedReference);
    }

    virtual CARAPI GetReference(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetStamp(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * stampHolder,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI WeakCompareAndSet(
        /* [in] */ IInterface * expectedReference,
        /* [in] */ IInterface * newReference,
        /* [in] */ _ELASTOS Int32 expectedStamp,
        /* [in] */ _ELASTOS Int32 newStamp,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI CompareAndSet(
        /* [in] */ IInterface * expectedReference,
        /* [in] */ IInterface * newReference,
        /* [in] */ _ELASTOS Int32 expectedStamp,
        /* [in] */ _ELASTOS Int32 newStamp,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Set(
        /* [in] */ IInterface * newReference,
        /* [in] */ _ELASTOS Int32 newStamp) = 0;

    virtual CARAPI AttemptStamp(
        /* [in] */ IInterface * expectedReference,
        /* [in] */ _ELASTOS Int32 newStamp,
        /* [out] */ _ELASTOS Boolean * value) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Atomic {
CAR_INTERFACE("D5F45D44-03D2-9F66-7E38-2829C3C60F0F")
IFences : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFences*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFences*)pObj->Probe(EIID_IFences);
    }

    static CARAPI_(IFences*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFences*)pObj->Probe(EIID_IFences);
    }

    virtual CARAPI OrderReads(
        /* [in] */ IInterface * ref,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI OrderWrites(
        /* [in] */ IInterface * ref,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI OrderAccesses(
        /* [in] */ IInterface * ref,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI ReachabilityFence(
        /* [in] */ IInterface * ref) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Locks {
CAR_INTERFACE("1F96415D-0552-AB19-38E8-3EEBF7878392")
ILockSupport : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILockSupport*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILockSupport*)pObj->Probe(EIID_ILockSupport);
    }

    static CARAPI_(ILockSupport*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILockSupport*)pObj->Probe(EIID_ILockSupport);
    }

    virtual CARAPI Unpark(
        /* [in] */ Elastos::Core::IThread * thread) = 0;

    virtual CARAPI Park(
        /* [in] */ IInterface * blocker) = 0;

    virtual CARAPI ParkNanos(
        /* [in] */ IInterface * blocker,
        /* [in] */ _ELASTOS Int64 nanos) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Locks {
CAR_INTERFACE("4960FF55-8292-9012-EFBE-D2409BF6892D")
IAbstractQueuedInteger64Synchronizer : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAbstractQueuedInteger64Synchronizer*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAbstractQueuedInteger64Synchronizer*)pObj->Probe(EIID_IAbstractQueuedInteger64Synchronizer);
    }

    static CARAPI_(IAbstractQueuedInteger64Synchronizer*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAbstractQueuedInteger64Synchronizer*)pObj->Probe(EIID_IAbstractQueuedInteger64Synchronizer);
    }

    virtual CARAPI AcquireQueued(
        /* [in] */ IInterface * node,
        /* [in] */ _ELASTOS Int64 arg,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Acquire(
        /* [in] */ _ELASTOS Int64 arg) = 0;

    virtual CARAPI AcquireInterruptibly(
        /* [in] */ IInterface * arg) = 0;

    virtual CARAPI TryAcquireNanos(
        /* [in] */ _ELASTOS Int64 arg,
        /* [in] */ _ELASTOS Int64 nanosTimeout,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI ToRelease(
        /* [in] */ _ELASTOS Int64 arg,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI AcquireShared(
        /* [in] */ _ELASTOS Int64 arg) = 0;

    virtual CARAPI AcquireSharedInterruptibly(
        /* [in] */ _ELASTOS Int64 arg) = 0;

    virtual CARAPI TryAcquireSharedNanos(
        /* [in] */ _ELASTOS Int64 arg,
        /* [in] */ _ELASTOS Int64 nanosTimeout,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI ReleaseShared(
        /* [in] */ _ELASTOS Int64 arg,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI HasQueuedThreads(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI HasContended(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetFirstQueuedThread(
        /* [out] */ Elastos::Core::IThread ** outhread) = 0;

    virtual CARAPI IsQueued(
        /* [in] */ Elastos::Core::IThread * thread,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI ApparentlyFirstQueuedIsExclusive(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI HasQueuedPredecessors(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetQueueLength(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetQueuedThreads(
        /* [out] */ Elastos::Utility::ICollection ** lection) = 0;

    virtual CARAPI GetExclusiveQueuedThreads(
        /* [out] */ Elastos::Utility::ICollection ** lection) = 0;

    virtual CARAPI GetSharedQueuedThreads(
        /* [out] */ Elastos::Utility::ICollection ** lection) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI IsOnSyncQueue(
        /* [in] */ IInterface * node,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI TransferForSignal(
        /* [in] */ IInterface * node,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI TransferAfterCancelledWait(
        /* [in] */ IInterface * node,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI FullyRelease(
        /* [in] */ IInterface * node,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI Owns(
        /* [in] */ IInterface * condition,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI HasWaiters(
        /* [in] */ IInterface * condition,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetWaitQueueLength(
        /* [in] */ IInterface * condition,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetWaitingThreads(
        /* [in] */ IInterface * condition,
        /* [out] */ Elastos::Utility::ICollection ** outlect) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Locks {
CAR_INTERFACE("606F3223-2252-3FA3-DADB-B821C3C60F0F")
IConditionObject : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IConditionObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IConditionObject*)pObj->Probe(EIID_IConditionObject);
    }

    static CARAPI_(IConditionObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IConditionObject*)pObj->Probe(EIID_IConditionObject);
    }

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Locks {
CAR_INTERFACE("E09BE81B-5292-77DA-4D9A-B786A3387A72")
IAbstractQueuedSynchronizer : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAbstractQueuedSynchronizer*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAbstractQueuedSynchronizer*)pObj->Probe(EIID_IAbstractQueuedSynchronizer);
    }

    static CARAPI_(IAbstractQueuedSynchronizer*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAbstractQueuedSynchronizer*)pObj->Probe(EIID_IAbstractQueuedSynchronizer);
    }

    virtual CARAPI Acquire(
        /* [in] */ _ELASTOS Int32 arg) = 0;

    virtual CARAPI AcquireInterruptibly(
        /* [in] */ _ELASTOS Int32 arg) = 0;

    virtual CARAPI TryAcquireNanos(
        /* [in] */ _ELASTOS Int32 arg,
        /* [in] */ _ELASTOS Int64 nanosTimeout,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI AcquireShared(
        /* [in] */ _ELASTOS Int32 arg) = 0;

    virtual CARAPI AcquireSharedInterruptibly(
        /* [in] */ _ELASTOS Int32 arg) = 0;

    virtual CARAPI TryAcquireSharedNanos(
        /* [in] */ _ELASTOS Int32 arg,
        /* [in] */ _ELASTOS Int64 nanosTimeout,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI ReleaseShared(
        /* [in] */ _ELASTOS Int32 arg,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI HasQueuedThreads(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI HasContended(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetFirstQueuedThread(
        /* [out] */ Elastos::Core::IThread ** outthread) = 0;

    virtual CARAPI IsQueued(
        /* [in] */ Elastos::Core::IThread * thread,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI ApparentlyFirstQueuedIsExclusive(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI HasQueuedPredecessors(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetQueueLength(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetQueuedThreads(
        /* [out] */ Elastos::Utility::ICollection ** outlect) = 0;

    virtual CARAPI GetExclusiveQueuedThreads(
        /* [out] */ Elastos::Utility::ICollection ** outlect) = 0;

    virtual CARAPI GetSharedQueuedThreads(
        /* [out] */ Elastos::Utility::ICollection ** outlect) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI Owns(
        /* [in] */ Elastos::Utility::Concurrent::Locks::ICondition * condition,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI HasWaiters(
        /* [in] */ Elastos::Utility::Concurrent::Locks::ICondition * condition,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetWaitQueueLength(
        /* [in] */ Elastos::Utility::Concurrent::Locks::ICondition * condition,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetWaitingThreads(
        /* [in] */ Elastos::Utility::Concurrent::Locks::ICondition * condition,
        /* [out] */ Elastos::Utility::ICollection ** outlect) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Locks {
CAR_INTERFACE("89D55013-5292-77DA-4D9A-B786A3387A72")
IAbstractQueuedSynchronizerHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAbstractQueuedSynchronizerHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAbstractQueuedSynchronizerHelper*)pObj->Probe(EIID_IAbstractQueuedSynchronizerHelper);
    }

    static CARAPI_(IAbstractQueuedSynchronizerHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAbstractQueuedSynchronizerHelper*)pObj->Probe(EIID_IAbstractQueuedSynchronizerHelper);
    }

    virtual CARAPI SelfInterrupt() = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Locks {
CAR_INTERFACE("32CE6D31-A252-ED1F-6DDC-9061E387871B")
ICondition : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICondition*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICondition*)pObj->Probe(EIID_ICondition);
    }

    static CARAPI_(ICondition*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICondition*)pObj->Probe(EIID_ICondition);
    }

    virtual CARAPI Await() = 0;

    virtual CARAPI AwaitUninterruptibly() = 0;

    virtual CARAPI AwaitNanos(
        /* [in] */ _ELASTOS Int64 nanosTimeout,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI Await(
        /* [in] */ _ELASTOS Int64 time,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI AwaitUntil(
        /* [in] */ Elastos::Utility::IDate * deadline,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Signal() = 0;

    virtual CARAPI SignalAll() = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Locks {
CAR_INTERFACE("1BDC5C0D-2552-EE9B-EFBC-A47DCBF6EFDD")
ILock : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILock*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILock*)pObj->Probe(EIID_ILock);
    }

    static CARAPI_(ILock*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILock*)pObj->Probe(EIID_ILock);
    }

    virtual CARAPI Lock() = 0;

    virtual CARAPI LockInterruptibly() = 0;

    virtual CARAPI TryLock(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI TryLock(
        /* [in] */ _ELASTOS Int64 time,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI UnLock() = 0;

    virtual CARAPI NewCondition(
        /* [out] */ Elastos::Utility::Concurrent::Locks::ICondition ** cond) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Locks {
CAR_INTERFACE("34EA4131-DCD2-1FF3-7FB4-B77143868D1F")
IReadWriteLock : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IReadWriteLock*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IReadWriteLock*)pObj->Probe(EIID_IReadWriteLock);
    }

    static CARAPI_(IReadWriteLock*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IReadWriteLock*)pObj->Probe(EIID_IReadWriteLock);
    }

    virtual CARAPI ReadLock(
        /* [out] */ Elastos::Utility::Concurrent::Locks::ILock ** outlock) = 0;

    virtual CARAPI WriteLock(
        /* [out] */ Elastos::Utility::Concurrent::Locks::ILock ** outlock) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Locks {
CAR_INTERFACE("86A9B00A-86D2-F1A2-5D93-F15DC9A6FB3B")
IReentrantLock : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IReentrantLock*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IReentrantLock*)pObj->Probe(EIID_IReentrantLock);
    }

    static CARAPI_(IReentrantLock*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IReentrantLock*)pObj->Probe(EIID_IReentrantLock);
    }

    virtual CARAPI GetHoldCount(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI IsHeldByCurrentThread(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI IsLocked(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI IsFair(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI HasQueuedThreads(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI HasQueuedThread(
        /* [in] */ Elastos::Core::IThread * thread,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetQueueLength(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI HasWaiters(
        /* [in] */ Elastos::Utility::Concurrent::Locks::ICondition * condition,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetWaitQueueLength(
        /* [in] */ Elastos::Utility::Concurrent::Locks::ICondition * condition,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Locks {
CAR_INTERFACE("053DEA5E-9A52-7765-63DC-3883A7828C55")
IReentrantReadWriteLock : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IReentrantReadWriteLock*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IReentrantReadWriteLock*)pObj->Probe(EIID_IReentrantReadWriteLock);
    }

    static CARAPI_(IReentrantReadWriteLock*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IReentrantReadWriteLock*)pObj->Probe(EIID_IReentrantReadWriteLock);
    }

    virtual CARAPI IsFair(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetReadLockCount(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI IsWriteLocked(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI IsWriteLockedByCurrentThread(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetWriteHoldCount(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetReadHoldCount(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI HasQueuedThreads(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI HasQueuedThread(
        /* [in] */ Elastos::Core::IThread * thread,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetQueueLength(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI HasWaiters(
        /* [in] */ Elastos::Utility::Concurrent::Locks::ICondition * condition,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetWaitQueueLength(
        /* [in] */ Elastos::Utility::Concurrent::Locks::ICondition * condition,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("5EEA594A-02D2-AB9A-206A-A04DFB878392")
IBlockingQueue : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBlockingQueue*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBlockingQueue*)pObj->Probe(EIID_IBlockingQueue);
    }

    static CARAPI_(IBlockingQueue*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBlockingQueue*)pObj->Probe(EIID_IBlockingQueue);
    }

    virtual CARAPI Put(
        /* [in] */ IInterface * e) = 0;

    virtual CARAPI Offer(
        /* [in] */ IInterface * e,
        /* [in] */ _ELASTOS Int64 timeout,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Take(
        /* [out] */ IInterface ** res) = 0;

    virtual CARAPI Poll(
        /* [in] */ _ELASTOS Int64 timeout,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ IInterface ** e) = 0;

    virtual CARAPI RemainingCapacity(
        /* [out] */ _ELASTOS Int32 * capacity) = 0;

    virtual CARAPI DrainTo(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI DrainTo(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [in] */ _ELASTOS Int32 maxElements,
        /* [out] */ _ELASTOS Int32 * number) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("17582956-0312-2640-2DFD-705052868D1F")
ICallable : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICallable*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICallable*)pObj->Probe(EIID_ICallable);
    }

    static CARAPI_(ICallable*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICallable*)pObj->Probe(EIID_ICallable);
    }

    virtual CARAPI Call(
        /* [out] */ IInterface ** result) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("D6924629-A212-2817-E067-FED1DEC60D19")
ICompletionService : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICompletionService*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICompletionService*)pObj->Probe(EIID_ICompletionService);
    }

    static CARAPI_(ICompletionService*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICompletionService*)pObj->Probe(EIID_ICompletionService);
    }

    virtual CARAPI Submit(
        /* [in] */ Elastos::Utility::Concurrent::ICallable * task,
        /* [out] */ Elastos::Utility::Concurrent::IFuture ** future) = 0;

    virtual CARAPI Submit(
        /* [in] */ Elastos::Core::IRunnable * task,
        /* [in] */ IInterface * result,
        /* [out] */ Elastos::Utility::Concurrent::IFuture ** future) = 0;

    virtual CARAPI Take(
        /* [out] */ Elastos::Utility::Concurrent::IFuture ** future) = 0;

    virtual CARAPI Poll(
        /* [out] */ Elastos::Utility::Concurrent::IFuture ** future) = 0;

    virtual CARAPI Poll(
        /* [in] */ _ELASTOS Int64 timeout,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ Elastos::Utility::Concurrent::IFuture ** future) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("4B61464E-9152-37DB-9654-7884EA878392")
ICountDownLatch : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICountDownLatch*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICountDownLatch*)pObj->Probe(EIID_ICountDownLatch);
    }

    static CARAPI_(ICountDownLatch*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICountDownLatch*)pObj->Probe(EIID_ICountDownLatch);
    }

    virtual CARAPI Await() = 0;

    virtual CARAPI Await(
        /* [in] */ _ELASTOS Int64 timeout,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI CountDown() = 0;

    virtual CARAPI GetCount(
        /* [out] */ _ELASTOS Int64 * count) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("9B3C2C5A-1452-B014-4EFF-705052868D1F")
IExecutor : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IExecutor*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IExecutor*)pObj->Probe(EIID_IExecutor);
    }

    static CARAPI_(IExecutor*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IExecutor*)pObj->Probe(EIID_IExecutor);
    }

    virtual CARAPI Execute(
        /* [in] */ Elastos::Core::IRunnable * command) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("268FEC54-1452-B014-4EDB-F8E1A0A40C1B")
IExecutors : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IExecutors*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IExecutors*)pObj->Probe(EIID_IExecutors);
    }

    static CARAPI_(IExecutors*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IExecutors*)pObj->Probe(EIID_IExecutors);
    }

    virtual CARAPI Callable(
        /* [in] */ Elastos::Core::IRunnable * task,
        /* [in] */ IInterface * result,
        /* [out] */ Elastos::Utility::Concurrent::ICallable ** object) = 0;

    virtual CARAPI NewFixedThreadPool(
        /* [in] */ _ELASTOS Int32 nThreads,
        /* [out] */ Elastos::Utility::Concurrent::IExecutorService ** result) = 0;

    virtual CARAPI NewWorkStealingPool(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [out] */ Elastos::Utility::Concurrent::IExecutorService ** result) = 0;

    virtual CARAPI NewWorkStealingPool(
        /* [out] */ Elastos::Utility::Concurrent::IExecutorService ** result) = 0;

    virtual CARAPI NewFixedThreadPool(
        /* [in] */ _ELASTOS Int32 nThreads,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [out] */ Elastos::Utility::Concurrent::IExecutorService ** result) = 0;

    virtual CARAPI NewSingleThreadExecutor(
        /* [out] */ Elastos::Utility::Concurrent::IExecutorService ** result) = 0;

    virtual CARAPI NewSingleThreadExecutor(
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [out] */ Elastos::Utility::Concurrent::IExecutorService ** result) = 0;

    virtual CARAPI NewCachedThreadPool(
        /* [out] */ Elastos::Utility::Concurrent::IExecutorService ** result) = 0;

    virtual CARAPI NewCachedThreadPool(
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [out] */ Elastos::Utility::Concurrent::IExecutorService ** result) = 0;

    virtual CARAPI NewSingleThreadScheduledExecutor(
        /* [out] */ Elastos::Utility::Concurrent::IScheduledExecutorService ** result) = 0;

    virtual CARAPI NewSingleThreadScheduledExecutor(
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [out] */ Elastos::Utility::Concurrent::IScheduledExecutorService ** result) = 0;

    virtual CARAPI NewScheduledThreadPool(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [out] */ Elastos::Utility::Concurrent::IScheduledExecutorService ** result) = 0;

    virtual CARAPI NewScheduledThreadPool(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [out] */ Elastos::Utility::Concurrent::IScheduledExecutorService ** result) = 0;

    virtual CARAPI UnconfigurableExecutorService(
        /* [in] */ Elastos::Utility::Concurrent::IExecutorService * executor,
        /* [out] */ Elastos::Utility::Concurrent::IExecutorService ** result) = 0;

    virtual CARAPI UnconfigurableScheduledExecutorService(
        /* [in] */ Elastos::Utility::Concurrent::IScheduledExecutorService * executor,
        /* [out] */ Elastos::Utility::Concurrent::IScheduledExecutorService ** result) = 0;

    virtual CARAPI PrivilegedThreadFactory(
        /* [out] */ Elastos::Utility::Concurrent::IThreadFactory ** result) = 0;

    virtual CARAPI Callable(
        /* [in] */ Elastos::Core::IRunnable * task,
        /* [out] */ Elastos::Utility::Concurrent::ICallable ** result) = 0;

    virtual CARAPI Callable(
        /* [in] */ Elastos::Security::IPrivilegedAction * action,
        /* [out] */ Elastos::Utility::Concurrent::ICallable ** result) = 0;

    virtual CARAPI Callable(
        /* [in] */ Elastos::Security::IPrivilegedExceptionAction * action,
        /* [out] */ Elastos::Utility::Concurrent::ICallable ** result) = 0;

    virtual CARAPI PrivilegedCallable(
        /* [in] */ Elastos::Utility::Concurrent::ICallable * callable,
        /* [out] */ Elastos::Utility::Concurrent::ICallable ** result) = 0;

    virtual CARAPI PrivilegedCallableUsingCurrentClassLoader(
        /* [in] */ Elastos::Utility::Concurrent::ICallable * callable,
        /* [out] */ Elastos::Utility::Concurrent::ICallable ** result) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("2DA49B25-33D2-2614-70DC-C89FF9477B1B")
IExecutorService : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IExecutorService*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IExecutorService*)pObj->Probe(EIID_IExecutorService);
    }

    static CARAPI_(IExecutorService*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IExecutorService*)pObj->Probe(EIID_IExecutorService);
    }

    virtual CARAPI Shutdown() = 0;

    virtual CARAPI ShutdownNow(
        /* [out] */ Elastos::Utility::IList ** tasks) = 0;

    virtual CARAPI IsShutdown(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI IsTerminated(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI AwaitTermination(
        /* [in] */ _ELASTOS Int64 timeout,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Submit(
        /* [in] */ Elastos::Utility::Concurrent::ICallable * task,
        /* [out] */ Elastos::Utility::Concurrent::IFuture ** future) = 0;

    virtual CARAPI Submit(
        /* [in] */ Elastos::Core::IRunnable * task,
        /* [in] */ IInterface * result,
        /* [out] */ Elastos::Utility::Concurrent::IFuture ** future) = 0;

    virtual CARAPI Submit(
        /* [in] */ Elastos::Core::IRunnable * task,
        /* [out] */ Elastos::Utility::Concurrent::IFuture ** future) = 0;

    virtual CARAPI InvokeAll(
        /* [in] */ Elastos::Utility::ICollection * tasks,
        /* [out] */ Elastos::Utility::IList ** futures) = 0;

    virtual CARAPI InvokeAll(
        /* [in] */ Elastos::Utility::ICollection * tasks,
        /* [in] */ _ELASTOS Int64 timeout,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ Elastos::Utility::IList ** futures) = 0;

    virtual CARAPI InvokeAny(
        /* [in] */ Elastos::Utility::ICollection * tasks,
        /* [out] */ IInterface ** result) = 0;

    virtual CARAPI InvokeAny(
        /* [in] */ Elastos::Utility::ICollection * tasks,
        /* [in] */ _ELASTOS Int64 timeout,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ IInterface ** result) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("E9B83451-8292-9012-EFBE-8A8202D6690E")
IAbstractExecutorService : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAbstractExecutorService*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAbstractExecutorService*)pObj->Probe(EIID_IAbstractExecutorService);
    }

    static CARAPI_(IAbstractExecutorService*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAbstractExecutorService*)pObj->Probe(EIID_IAbstractExecutorService);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("D1A64016-83D2-78DF-8DFE-CE4BDAB76CFF")
IFuture : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFuture*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFuture*)pObj->Probe(EIID_IFuture);
    }

    static CARAPI_(IFuture*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFuture*)pObj->Probe(EIID_IFuture);
    }

    virtual CARAPI Cancel(
        /* [in] */ _ELASTOS Boolean mayInterruptIfRunning,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI IsCancelled(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI IsDone(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Get(
        /* [out] */ IInterface ** result) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS Int64 timeout,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ IInterface ** result) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("89F34654-1A52-AF90-8A45-4101AB730441")
IRejectedExecutionHandler : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRejectedExecutionHandler*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRejectedExecutionHandler*)pObj->Probe(EIID_IRejectedExecutionHandler);
    }

    static CARAPI_(IRejectedExecutionHandler*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRejectedExecutionHandler*)pObj->Probe(EIID_IRejectedExecutionHandler);
    }

    virtual CARAPI RejectedExecution(
        /* [in] */ Elastos::Core::IRunnable * r,
        /* [in] */ Elastos::Utility::Concurrent::IThreadPoolExecutor * executor) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("C5822B51-86D2-45DB-2D3D-C0111BEF0F07")
IRunnableFuture : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRunnableFuture*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRunnableFuture*)pObj->Probe(EIID_IRunnableFuture);
    }

    static CARAPI_(IRunnableFuture*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRunnableFuture*)pObj->Probe(EIID_IRunnableFuture);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("EC583335-7092-3F68-DADB-B821C3C60F0F")
IThreadFactory : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IThreadFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IThreadFactory*)pObj->Probe(EIID_IThreadFactory);
    }

    static CARAPI_(IThreadFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IThreadFactory*)pObj->Probe(EIID_IThreadFactory);
    }

    virtual CARAPI NewThread(
        /* [in] */ Elastos::Core::IRunnable * r,
        /* [out] */ Elastos::Core::IThread ** t) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("5BCFEF26-F092-CFB0-5098-C07123FF8FF6")
IThreadPoolExecutor : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IThreadPoolExecutor*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IThreadPoolExecutor*)pObj->Probe(EIID_IThreadPoolExecutor);
    }

    static CARAPI_(IThreadPoolExecutor*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IThreadPoolExecutor*)pObj->Probe(EIID_IThreadPoolExecutor);
    }

    virtual CARAPI IsTerminating(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI SetThreadFactory(
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory) = 0;

    virtual CARAPI GetThreadFactory(
        /* [out] */ Elastos::Utility::Concurrent::IThreadFactory ** threadFactory) = 0;

    virtual CARAPI SetRejectedExecutionHandler(
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler) = 0;

    virtual CARAPI GetRejectedExecutionHandler(
        /* [out] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler ** handler) = 0;

    virtual CARAPI SetCorePoolSize(
        /* [in] */ _ELASTOS Int32 corePoolSize) = 0;

    virtual CARAPI GetCorePoolSize(
        /* [out] */ _ELASTOS Int32 * corePoolSize) = 0;

    virtual CARAPI PrestartCoreThread(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI PrestartAllCoreThreads(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI AllowsCoreThreadTimeOut(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI AllowCoreThreadTimeOut(
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI SetMaximumPoolSize(
        /* [in] */ _ELASTOS Int32 maximumPoolSize) = 0;

    virtual CARAPI GetMaximumPoolSize(
        /* [out] */ _ELASTOS Int32 * maximumPoolSize) = 0;

    virtual CARAPI SetKeepAliveTime(
        /* [in] */ _ELASTOS Int64 time,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit) = 0;

    virtual CARAPI GetKeepAliveTime(
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ _ELASTOS Int64 * time) = 0;

    virtual CARAPI GetQueue(
        /* [out] */ Elastos::Utility::Concurrent::IBlockingQueue ** queue) = 0;

    virtual CARAPI Remove(
        /* [in] */ Elastos::Core::IRunnable * task,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Purge() = 0;

    virtual CARAPI GetPoolSize(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI GetActiveCount(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI GetLargestPoolSize(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI GetTaskCount(
        /* [out] */ _ELASTOS Int64 * number) = 0;

    virtual CARAPI GetCompletedTaskCount(
        /* [out] */ _ELASTOS Int64 * number) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("4394845B-0752-7484-32FE-705052868D1F")
ITimeUnit : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITimeUnit*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITimeUnit*)pObj->Probe(EIID_ITimeUnit);
    }

    static CARAPI_(ITimeUnit*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITimeUnit*)pObj->Probe(EIID_ITimeUnit);
    }

    virtual CARAPI Convert(
        /* [in] */ _ELASTOS Int64 sourceDuration,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * sourceUnit,
        /* [out] */ _ELASTOS Int64 * result) = 0;

    virtual CARAPI ToNanos(
        /* [in] */ _ELASTOS Int64 duration,
        /* [out] */ _ELASTOS Int64 * result) = 0;

    virtual CARAPI ToMicros(
        /* [in] */ _ELASTOS Int64 duration,
        /* [out] */ _ELASTOS Int64 * result) = 0;

    virtual CARAPI ToMillis(
        /* [in] */ _ELASTOS Int64 duration,
        /* [out] */ _ELASTOS Int64 * result) = 0;

    virtual CARAPI ToSeconds(
        /* [in] */ _ELASTOS Int64 duration,
        /* [out] */ _ELASTOS Int64 * result) = 0;

    virtual CARAPI ToMinutes(
        /* [in] */ _ELASTOS Int64 duration,
        /* [out] */ _ELASTOS Int64 * result) = 0;

    virtual CARAPI ToHours(
        /* [in] */ _ELASTOS Int64 duration,
        /* [out] */ _ELASTOS Int64 * result) = 0;

    virtual CARAPI ToDays(
        /* [in] */ _ELASTOS Int64 duration,
        /* [out] */ _ELASTOS Int64 * result) = 0;

    virtual CARAPI ExcessNanos(
        /* [in] */ _ELASTOS Int64 d,
        /* [in] */ _ELASTOS Int64 m,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI TimedWait(
        /* [in] */ Elastos::Core::ISynchronize * obj,
        /* [in] */ _ELASTOS Int64 timeout) = 0;

    virtual CARAPI TimedJoin(
        /* [in] */ Elastos::Core::IThread * thread,
        /* [in] */ _ELASTOS Int64 timeout) = 0;

    virtual CARAPI Sleep(
        /* [in] */ _ELASTOS Int64 timeout) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("5DD47A02-C752-A8C2-17B3-7784BE335AFF")
ITimeUnitHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITimeUnitHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITimeUnitHelper*)pObj->Probe(EIID_ITimeUnitHelper);
    }

    static CARAPI_(ITimeUnitHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITimeUnitHelper*)pObj->Probe(EIID_ITimeUnitHelper);
    }

    virtual CARAPI GetNANOSECONDS(
        /* [out] */ Elastos::Utility::Concurrent::ITimeUnit ** unit) = 0;

    virtual CARAPI GetMICROSECONDS(
        /* [out] */ Elastos::Utility::Concurrent::ITimeUnit ** unit) = 0;

    virtual CARAPI GetMILLISECONDS(
        /* [out] */ Elastos::Utility::Concurrent::ITimeUnit ** unit) = 0;

    virtual CARAPI GetSECONDS(
        /* [out] */ Elastos::Utility::Concurrent::ITimeUnit ** unit) = 0;

    virtual CARAPI GetMINUTES(
        /* [out] */ Elastos::Utility::Concurrent::ITimeUnit ** unit) = 0;

    virtual CARAPI GetHOURS(
        /* [out] */ Elastos::Utility::Concurrent::ITimeUnit ** unit) = 0;

    virtual CARAPI GetDAYS(
        /* [out] */ Elastos::Utility::Concurrent::ITimeUnit ** unit) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("C9022F26-9612-F532-35E0-408103C58FF6")
IArrayBlockingQueue : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IArrayBlockingQueue*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IArrayBlockingQueue*)pObj->Probe(EIID_IArrayBlockingQueue);
    }

    static CARAPI_(IArrayBlockingQueue*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IArrayBlockingQueue*)pObj->Probe(EIID_IArrayBlockingQueue);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("67A7FF4E-02D2-AB9A-201E-99FBC3414919")
IBlockingDeque : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBlockingDeque*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBlockingDeque*)pObj->Probe(EIID_IBlockingDeque);
    }

    static CARAPI_(IBlockingDeque*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBlockingDeque*)pObj->Probe(EIID_IBlockingDeque);
    }

    virtual CARAPI AddFirst(
        /* [in] */ IInterface * e) = 0;

    virtual CARAPI AddLast(
        /* [in] */ IInterface * e) = 0;

    virtual CARAPI OfferFirst(
        /* [in] */ IInterface * e,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI OfferLast(
        /* [in] */ IInterface * e,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI PutFirst(
        /* [in] */ IInterface * e) = 0;

    virtual CARAPI PutLast(
        /* [in] */ IInterface * e) = 0;

    virtual CARAPI OfferFirst(
        /* [in] */ IInterface * e,
        /* [in] */ _ELASTOS Int64 timeout,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI OfferLast(
        /* [in] */ IInterface * e,
        /* [in] */ _ELASTOS Int64 timeout,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI RemoveFirst(
        /* [out] */ PInterface * res) = 0;

    virtual CARAPI RemoveLast(
        /* [out] */ PInterface * res) = 0;

    virtual CARAPI PollFirst(
        /* [out] */ PInterface * res) = 0;

    virtual CARAPI PollLast(
        /* [out] */ PInterface * res) = 0;

    virtual CARAPI GetFirst(
        /* [out] */ PInterface * res) = 0;

    virtual CARAPI GetLast(
        /* [out] */ PInterface * res) = 0;

    virtual CARAPI PeekFirst(
        /* [out] */ PInterface * res) = 0;

    virtual CARAPI PeekLast(
        /* [out] */ PInterface * res) = 0;

    virtual CARAPI TakeFirst(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI TakeLast(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI PollFirst(
        /* [in] */ _ELASTOS Int64 timeout,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI PollLast(
        /* [in] */ _ELASTOS Int64 timeout,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI RemoveFirstOccurrence(
        /* [in] */ IInterface * o,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI RemoveLastOccurrence(
        /* [in] */ IInterface * o,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Push(
        /* [in] */ IInterface * e) = 0;

    virtual CARAPI Pop(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetDescendingIterator(
        /* [out] */ Elastos::Utility::IIterator ** iterator) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("95943F3E-DAD2-F532-35E0-408103C58FF6")
IPriorityBlockingQueue : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPriorityBlockingQueue*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPriorityBlockingQueue*)pObj->Probe(EIID_IPriorityBlockingQueue);
    }

    static CARAPI_(IPriorityBlockingQueue*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPriorityBlockingQueue*)pObj->Probe(EIID_IPriorityBlockingQueue);
    }

    virtual CARAPI GetComparator(
        /* [out] */ Elastos::Core::IComparator ** outcom) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("5424325A-1112-7D58-9755-88584C036DDA")
IConcurrentLinkedQueue : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IConcurrentLinkedQueue*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IConcurrentLinkedQueue*)pObj->Probe(EIID_IConcurrentLinkedQueue);
    }

    static CARAPI_(IConcurrentLinkedQueue*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IConcurrentLinkedQueue*)pObj->Probe(EIID_IConcurrentLinkedQueue);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("5DE86236-2492-E7A6-B168-FCD1DEC60D19")
ICopyOnWriteArrayList : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICopyOnWriteArrayList*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICopyOnWriteArrayList*)pObj->Probe(EIID_ICopyOnWriteArrayList);
    }

    static CARAPI_(ICopyOnWriteArrayList*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICopyOnWriteArrayList*)pObj->Probe(EIID_ICopyOnWriteArrayList);
    }

    virtual CARAPI IndexOf(
        /* [in] */ IInterface * object,
        /* [in] */ _ELASTOS Int32 from,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI LastIndexOf(
        /* [in] */ IInterface * object,
        /* [in] */ _ELASTOS Int32 to,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI AddAllAbsent(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI AddIfAbsent(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetArray(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** outarr) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("24225431-2492-E7A6-B168-8C80E2C58CFB")
ICopyOnWriteArrayListHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICopyOnWriteArrayListHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICopyOnWriteArrayListHelper*)pObj->Probe(EIID_ICopyOnWriteArrayListHelper);
    }

    static CARAPI_(ICopyOnWriteArrayListHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICopyOnWriteArrayListHelper*)pObj->Probe(EIID_ICopyOnWriteArrayListHelper);
    }

    virtual CARAPI ContainsAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * snapshot,
        /* [in] */ _ELASTOS Int32 from,
        /* [in] */ _ELASTOS Int32 to,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI LastIndexOf(
        /* [in] */ IInterface * o,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * data,
        /* [in] */ _ELASTOS Int32 from,
        /* [in] */ _ELASTOS Int32 to,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI IndexOf(
        /* [in] */ IInterface * o,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * data,
        /* [in] */ _ELASTOS Int32 from,
        /* [in] */ _ELASTOS Int32 to,
        /* [out] */ _ELASTOS Int32 * value) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("BFA95B01-C312-2F9B-6B2E-645DB368FD3B")
ICyclicBarrier : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICyclicBarrier*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICyclicBarrier*)pObj->Probe(EIID_ICyclicBarrier);
    }

    static CARAPI_(ICyclicBarrier*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICyclicBarrier*)pObj->Probe(EIID_ICyclicBarrier);
    }

    virtual CARAPI GetParties(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Await(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Await(
        /* [in] */ _ELASTOS Int64 timeout,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI IsBroken(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Reset() = 0;

    virtual CARAPI GetNumberWaiting(
        /* [out] */ _ELASTOS Int32 * value) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("7AB82C34-2A92-3FFD-DADB-B821C3C60F0F")
IDelayed : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDelayed*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDelayed*)pObj->Probe(EIID_IDelayed);
    }

    static CARAPI_(IDelayed*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDelayed*)pObj->Probe(EIID_IDelayed);
    }

    virtual CARAPI GetDelay(
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ _ELASTOS Int64 * value) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("CF312F5A-11D2-3C93-34D0-A6FDC3414919")
IDelayQueue : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDelayQueue*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDelayQueue*)pObj->Probe(EIID_IDelayQueue);
    }

    static CARAPI_(IDelayQueue*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDelayQueue*)pObj->Probe(EIID_IDelayQueue);
    }

    virtual CARAPI RemoveEQ(
        /* [in] */ IInterface * o) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("4BCF3643-9452-4850-9FFD-705052868D1F")
IExchanger : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IExchanger*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IExchanger*)pObj->Probe(EIID_IExchanger);
    }

    static CARAPI_(IExchanger*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IExchanger*)pObj->Probe(EIID_IExchanger);
    }

    virtual CARAPI Exchange(
        /* [in] */ IInterface * x,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI Exchange(
        /* [in] */ IInterface * x,
        /* [in] */ _ELASTOS Int64 timeout,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ IInterface ** outface) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("30FC4822-3752-0A17-C35A-201183840AFD")
IForkJoinPoolManagedBlocker : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IForkJoinPoolManagedBlocker*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IForkJoinPoolManagedBlocker*)pObj->Probe(EIID_IForkJoinPoolManagedBlocker);
    }

    static CARAPI_(IForkJoinPoolManagedBlocker*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IForkJoinPoolManagedBlocker*)pObj->Probe(EIID_IForkJoinPoolManagedBlocker);
    }

    virtual CARAPI Block(
        /* [out] */ _ELASTOS Boolean * res) = 0;

    virtual CARAPI IsReleasable(
        /* [out] */ _ELASTOS Boolean * res) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("E355F13E-3752-0A17-C3FE-686FE3860C1B")
IForkJoinPool : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IForkJoinPool*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IForkJoinPool*)pObj->Probe(EIID_IForkJoinPool);
    }

    static CARAPI_(IForkJoinPool*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IForkJoinPool*)pObj->Probe(EIID_IForkJoinPool);
    }

    virtual CARAPI Invoke(
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinTask * task,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI Execute(
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinTask * task) = 0;

    virtual CARAPI Submit(
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinTask * task,
        /* [out] */ Elastos::Utility::Concurrent::IForkJoinTask ** outfork) = 0;

    virtual CARAPI GetFactory(
        /* [out] */ Elastos::Utility::Concurrent::IForkJoinPoolForkJoinWorkerThreadFactory ** res) = 0;

    virtual CARAPI GetUncaughtExceptionHandler(
        /* [out] */ Elastos::Core::IThreadUncaughtExceptionHandler ** res) = 0;

    virtual CARAPI GetParallelism(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetPoolSize(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetAsyncMode(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetRunningThreadCount(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetActiveThreadCount(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI IsQuiescent(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetStealCount(
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI GetQueuedTaskCount(
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI GetQueuedSubmissionCount(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI HasQueuedSubmissions(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI IsTerminating(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI AwaitQuiescence(
        /* [in] */ _ELASTOS Int64 timeout,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("23BF4D26-3752-0A17-C376-73A1B0FC7DE1")
IForkJoinPoolForkJoinWorkerThreadFactory : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IForkJoinPoolForkJoinWorkerThreadFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IForkJoinPoolForkJoinWorkerThreadFactory*)pObj->Probe(EIID_IForkJoinPoolForkJoinWorkerThreadFactory);
    }

    static CARAPI_(IForkJoinPoolForkJoinWorkerThreadFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IForkJoinPoolForkJoinWorkerThreadFactory*)pObj->Probe(EIID_IForkJoinPoolForkJoinWorkerThreadFactory);
    }

    virtual CARAPI NewThread(
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinPool * pool,
        /* [out] */ Elastos::Utility::Concurrent::IForkJoinWorkerThread ** td) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("3AA22F3C-3752-0A17-C346-40F162C6FD1F")
IForkJoinPoolHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IForkJoinPoolHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IForkJoinPoolHelper*)pObj->Probe(EIID_IForkJoinPoolHelper);
    }

    static CARAPI_(IForkJoinPoolHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IForkJoinPoolHelper*)pObj->Probe(EIID_IForkJoinPoolHelper);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("26344737-3752-0A17-CBDF-17FEA3BD8D1B")
IForkJoinWorkerThread : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IForkJoinWorkerThread*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IForkJoinWorkerThread*)pObj->Probe(EIID_IForkJoinWorkerThread);
    }

    static CARAPI_(IForkJoinWorkerThread*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IForkJoinWorkerThread*)pObj->Probe(EIID_IForkJoinWorkerThread);
    }

    virtual CARAPI GetPool(
        /* [out] */ Elastos::Utility::Concurrent::IForkJoinPool ** outpool) = 0;

    virtual CARAPI GetPoolIndex(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Run() = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("AA1AE62D-3752-0A17-3B90-B0E1E2477B1B")
IForkJoinTask : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IForkJoinTask*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IForkJoinTask*)pObj->Probe(EIID_IForkJoinTask);
    }

    static CARAPI_(IForkJoinTask*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IForkJoinTask*)pObj->Probe(EIID_IForkJoinTask);
    }

    virtual CARAPI SetRawResult(
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI Exec(
        /* [out] */ _ELASTOS Boolean * res) = 0;

    virtual CARAPI DoExec(
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI Fork(
        /* [out] */ Elastos::Utility::Concurrent::IForkJoinTask ** outtask) = 0;

    virtual CARAPI Join(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI Invoke(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI IsCompletedAbnormally(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI IsCompletedNormally(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetException(
        /* [out] */ Elastos::Core::IThrowable ** res) = 0;

    virtual CARAPI CompleteExceptionally(
        /* [in] */ Elastos::Core::IThrowable * ex) = 0;

    virtual CARAPI Complete(
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI QuietlyJoin() = 0;

    virtual CARAPI QuietlyInvoke() = 0;

    virtual CARAPI Reinitialize() = 0;

    virtual CARAPI TryUnfork(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetRawResult(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI QuietlyComplete() = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("D3C7A41A-23D2-EED7-24B3-7147DA6E84BE")
IForkJoinTaskHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IForkJoinTaskHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IForkJoinTaskHelper*)pObj->Probe(EIID_IForkJoinTaskHelper);
    }

    static CARAPI_(IForkJoinTaskHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IForkJoinTaskHelper*)pObj->Probe(EIID_IForkJoinTaskHelper);
    }

    virtual CARAPI InvokeAll(
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinTask * t1,
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinTask * t2) = 0;

    virtual CARAPI InvokeAll(
        /* [in] */ _ELASTOS ArrayOf<Elastos::Utility::Concurrent::IForkJoinTask *> * tasks) = 0;

    virtual CARAPI InvokeAll(
        /* [in] */ Elastos::Utility::ICollection * tasks,
        /* [out] */ Elastos::Utility::ICollection ** outcol) = 0;

    virtual CARAPI HelpQuiesce() = 0;

    virtual CARAPI GetPool(
        /* [out] */ Elastos::Utility::Concurrent::IForkJoinPool ** outpool) = 0;

    virtual CARAPI InForkJoinPool(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetQueuedTaskCount(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetSurplusQueuedTaskCount(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Adapt(
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [out] */ Elastos::Utility::Concurrent::IForkJoinTask ** outjoin) = 0;

    virtual CARAPI Adapt(
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [in] */ IInterface * result,
        /* [out] */ Elastos::Utility::Concurrent::IForkJoinTask ** outjoin) = 0;

    virtual CARAPI Adapt(
        /* [in] */ Elastos::Utility::Concurrent::ICallable * callable,
        /* [out] */ Elastos::Utility::Concurrent::IForkJoinTask ** outjoin) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("2C6FFC5C-9952-CF45-7E38-2829C3C60F0F")
IPhaser : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPhaser*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPhaser*)pObj->Probe(EIID_IPhaser);
    }

    static CARAPI_(IPhaser*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPhaser*)pObj->Probe(EIID_IPhaser);
    }

    virtual CARAPI Register(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI BulkRegister(
        /* [in] */ _ELASTOS Int32 parties,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Arrive(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI ArriveAndDeregister(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI ArriveAndAwaitAdvance(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI AwaitAdvance(
        /* [in] */ _ELASTOS Int32 phase,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI AwaitAdvanceInterruptibly(
        /* [in] */ _ELASTOS Int32 phase,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI AwaitAdvanceInterruptibly(
        /* [in] */ _ELASTOS Int32 phase,
        /* [in] */ _ELASTOS Int64 timeout,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI ForceTermination() = 0;

    virtual CARAPI GetPhase(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetRegisteredParties(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetArrivedParties(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetUnarrivedParties(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetParent(
        /* [out] */ Elastos::Utility::Concurrent::IPhaser ** outphase) = 0;

    virtual CARAPI GetRoot(
        /* [out] */ Elastos::Utility::Concurrent::IPhaser ** outphase) = 0;

    virtual CARAPI IsTerminated(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("1A0B4F46-86D2-45DB-2D71-10E52BE58907")
IRunnableScheduledFuture : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRunnableScheduledFuture*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRunnableScheduledFuture*)pObj->Probe(EIID_IRunnableScheduledFuture);
    }

    static CARAPI_(IRunnableScheduledFuture*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRunnableScheduledFuture*)pObj->Probe(EIID_IRunnableScheduledFuture);
    }

    virtual CARAPI IsPeriodic(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetDelay(
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI CompareTo(
        /* [in] */ IInterface * another,
        /* [out] */ _ELASTOS Int32 * result) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("71A1EA55-0712-3914-C956-FDE1A0A40C1B")
ISemaphore : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISemaphore*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISemaphore*)pObj->Probe(EIID_ISemaphore);
    }

    static CARAPI_(ISemaphore*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISemaphore*)pObj->Probe(EIID_ISemaphore);
    }

    virtual CARAPI Acquire() = 0;

    virtual CARAPI AcquireUninterruptibly() = 0;

    virtual CARAPI TryAcquire(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI TryAcquire(
        /* [in] */ _ELASTOS Int64 timeout,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI ReleasePermit() = 0;

    virtual CARAPI Acquire(
        /* [in] */ _ELASTOS Int32 permits) = 0;

    virtual CARAPI AcquireUninterruptibly(
        /* [in] */ _ELASTOS Int32 permits) = 0;

    virtual CARAPI TryAcquire(
        /* [in] */ _ELASTOS Int32 permits,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI TryAcquire(
        /* [in] */ _ELASTOS Int32 permits,
        /* [in] */ _ELASTOS Int64 timeout,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI ReleasePermit(
        /* [in] */ _ELASTOS Int32 permits) = 0;

    virtual CARAPI AvailablePermits(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI DrainPermits(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI IsFair(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI HasQueuedThreads(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetQueueLength(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("BBA62647-0812-373F-34D0-A6FDC3414919")
IWaitQueue : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IWaitQueue*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IWaitQueue*)pObj->Probe(EIID_IWaitQueue);
    }

    static CARAPI_(IWaitQueue*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IWaitQueue*)pObj->Probe(EIID_IWaitQueue);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("08CE2A1D-C552-32A6-48B2-B786A338FA3B")
ILifoWaitQueue : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILifoWaitQueue*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILifoWaitQueue*)pObj->Probe(EIID_ILifoWaitQueue);
    }

    static CARAPI_(ILifoWaitQueue*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILifoWaitQueue*)pObj->Probe(EIID_ILifoWaitQueue);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("0ECE2A19-C3D2-32A6-48B2-B786A338FA3B")
IFifoWaitQueue : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFifoWaitQueue*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFifoWaitQueue*)pObj->Probe(EIID_IFifoWaitQueue);
    }

    static CARAPI_(IFifoWaitQueue*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFifoWaitQueue*)pObj->Probe(EIID_IFifoWaitQueue);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("82863A0C-C712-E6C7-5ACB-B18CDB1A8EE2")
ISynchronousQueueTransferStack : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISynchronousQueueTransferStack*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISynchronousQueueTransferStack*)pObj->Probe(EIID_ISynchronousQueueTransferStack);
    }

    static CARAPI_(ISynchronousQueueTransferStack*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISynchronousQueueTransferStack*)pObj->Probe(EIID_ISynchronousQueueTransferStack);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("86733A05-C712-E6C7-5ACB-B18CDB1A8EE2")
ISynchronousQueueTransferQueue : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISynchronousQueueTransferQueue*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISynchronousQueueTransferQueue*)pObj->Probe(EIID_ISynchronousQueueTransferQueue);
    }

    static CARAPI_(ISynchronousQueueTransferQueue*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISynchronousQueueTransferQueue*)pObj->Probe(EIID_ISynchronousQueueTransferQueue);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("1A2F2D13-C712-E6C7-5ACB-B18CDB1A8EE2")
ISynchronousQueue : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISynchronousQueue*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISynchronousQueue*)pObj->Probe(EIID_ISynchronousQueue);
    }

    static CARAPI_(ISynchronousQueue*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISynchronousQueue*)pObj->Probe(EIID_ISynchronousQueue);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("2F895D27-7092-1B8F-48C4-382103C68FF6")
IThreadLocalRandom : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IThreadLocalRandom*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IThreadLocalRandom*)pObj->Probe(EIID_IThreadLocalRandom);
    }

    static CARAPI_(IThreadLocalRandom*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IThreadLocalRandom*)pObj->Probe(EIID_IThreadLocalRandom);
    }

    virtual CARAPI NextInt32(
        /* [in] */ _ELASTOS Int32 least,
        /* [in] */ _ELASTOS Int32 bound,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI NextInt64(
        /* [in] */ _ELASTOS Int64 n,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI NextInt64(
        /* [in] */ _ELASTOS Int64 least,
        /* [in] */ _ELASTOS Int64 bound,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI NextDouble(
        /* [in] */ _ELASTOS Double n,
        /* [out] */ _ELASTOS Double * value) = 0;

    virtual CARAPI NextDouble(
        /* [in] */ _ELASTOS Double least,
        /* [in] */ _ELASTOS Double bound,
        /* [out] */ _ELASTOS Double * value) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("E4073E26-7092-1B8F-48C4-382103460414")
IThreadLocalRandomHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IThreadLocalRandomHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IThreadLocalRandomHelper*)pObj->Probe(EIID_IThreadLocalRandomHelper);
    }

    static CARAPI_(IThreadLocalRandomHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IThreadLocalRandomHelper*)pObj->Probe(EIID_IThreadLocalRandomHelper);
    }

    virtual CARAPI GetCurrent(
        /* [out] */ Elastos::Utility::Concurrent::IThreadLocalRandom ** threadloc) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("15AE711D-5752-B193-9DA2-B586A338FA3B")
ITransferQueue : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITransferQueue*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITransferQueue*)pObj->Probe(EIID_ITransferQueue);
    }

    static CARAPI_(ITransferQueue*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITransferQueue*)pObj->Probe(EIID_ITransferQueue);
    }

    virtual CARAPI TryTransfer(
        /* [in] */ IInterface * e,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Transfer(
        /* [in] */ IInterface * e) = 0;

    virtual CARAPI TryTransfer(
        /* [in] */ IInterface * e,
        /* [in] */ _ELASTOS Int64 timeout,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI HasWaitingConsumer(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetWaitingConsumerCount(
        /* [out] */ _ELASTOS Int32 * value) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("FB9ABD45-1112-7D58-9759-2031E3878392")
IConcurrentMap : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IConcurrentMap*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IConcurrentMap*)pObj->Probe(EIID_IConcurrentMap);
    }

    static CARAPI_(IConcurrentMap*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IConcurrentMap*)pObj->Probe(EIID_IConcurrentMap);
    }

    virtual CARAPI PutIfAbsent(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Replace(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * oldValue,
        /* [in] */ IInterface * newValue,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Replace(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value,
        /* [out] */ IInterface ** result) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI ContainsKey(
        /* [in] */ IInterface * key,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsValue(
        /* [in] */ IInterface * value,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetEntrySet(
        /* [out] */ Elastos::Utility::ISet ** entries) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Get(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetKeySet(
        /* [out] */ Elastos::Utility::ISet ** keySet) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value,
        /* [out] */ IInterface ** oldValue) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI PutAll(
        /* [in] */ Elastos::Utility::IMap * map) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetValues(
        /* [out] */ Elastos::Utility::ICollection ** value) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("2E26245A-1C52-0B63-24FE-705052868D1F")
ITreeBin : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITreeBin*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITreeBin*)pObj->Probe(EIID_ITreeBin);
    }

    static CARAPI_(ITreeBin*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITreeBin*)pObj->Probe(EIID_ITreeBin);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("14D22553-1C52-5E63-66FD-705052868D1F")
ITreeNode : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITreeNode*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITreeNode*)pObj->Probe(EIID_ITreeNode);
    }

    static CARAPI_(ITreeNode*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITreeNode*)pObj->Probe(EIID_ITreeNode);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("E17F2B47-83D2-C2AB-6BD4-42EA65D60F07")
IForwardingNode : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IForwardingNode*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IForwardingNode*)pObj->Probe(EIID_IForwardingNode);
    }

    static CARAPI_(IForwardingNode*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IForwardingNode*)pObj->Probe(EIID_IForwardingNode);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("528F2C55-9A52-35C1-7A77-F632EB878392")
IReservationNode : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IReservationNode*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IReservationNode*)pObj->Probe(EIID_IReservationNode);
    }

    static CARAPI_(IReservationNode*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IReservationNode*)pObj->Probe(EIID_IReservationNode);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("EB05D558-1112-7D58-9745-58B4C2028919")
IConcurrentHashMap : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IConcurrentHashMap*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IConcurrentHashMap*)pObj->Probe(EIID_IConcurrentHashMap);
    }

    static CARAPI_(IConcurrentHashMap*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IConcurrentHashMap*)pObj->Probe(EIID_IConcurrentHashMap);
    }

    virtual CARAPI Contains(
        /* [in] */ IInterface * value,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Keys(
        /* [out] */ Elastos::Utility::IEnumeration ** outenum) = 0;

    virtual CARAPI Elements(
        /* [out] */ Elastos::Utility::IEnumeration ** outenum) = 0;

    virtual CARAPI PutIfAbsent(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Replace(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * oldValue,
        /* [in] */ IInterface * newValue,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Replace(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value,
        /* [out] */ IInterface ** result) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI ContainsKey(
        /* [in] */ IInterface * key,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsValue(
        /* [in] */ IInterface * value,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetEntrySet(
        /* [out] */ Elastos::Utility::ISet ** entries) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Get(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetKeySet(
        /* [out] */ Elastos::Utility::ISet ** keySet) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value,
        /* [out] */ IInterface ** oldValue) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI PutAll(
        /* [in] */ Elastos::Utility::IMap * map) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetValues(
        /* [out] */ Elastos::Utility::ICollection ** value) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("CEAD8D41-1112-7D58-9775-F96DCE920512")
IConcurrentNavigableMap : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IConcurrentNavigableMap*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IConcurrentNavigableMap*)pObj->Probe(EIID_IConcurrentNavigableMap);
    }

    static CARAPI_(IConcurrentNavigableMap*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IConcurrentNavigableMap*)pObj->Probe(EIID_IConcurrentNavigableMap);
    }

    virtual CARAPI SubMap(
        /* [in] */ IInterface * fromKey,
        /* [in] */ _ELASTOS Boolean fromInclusive,
        /* [in] */ IInterface * toKey,
        /* [in] */ _ELASTOS Boolean toInclusive,
        /* [out] */ Elastos::Utility::Concurrent::IConcurrentNavigableMap ** res) = 0;

    virtual CARAPI HeadMap(
        /* [in] */ IInterface * toKey,
        /* [in] */ _ELASTOS Boolean inclusive,
        /* [out] */ Elastos::Utility::Concurrent::IConcurrentNavigableMap ** res) = 0;

    virtual CARAPI TailMap(
        /* [in] */ IInterface * fromKey,
        /* [in] */ _ELASTOS Boolean inclusive,
        /* [out] */ Elastos::Utility::Concurrent::IConcurrentNavigableMap ** res) = 0;

    virtual CARAPI SubMap(
        /* [in] */ IInterface * fromKey,
        /* [in] */ IInterface * toKey,
        /* [out] */ Elastos::Utility::Concurrent::IConcurrentNavigableMap ** res) = 0;

    virtual CARAPI HeadMap(
        /* [in] */ IInterface * toKey,
        /* [out] */ Elastos::Utility::Concurrent::IConcurrentNavigableMap ** res) = 0;

    virtual CARAPI TailMap(
        /* [in] */ IInterface * fromKey,
        /* [out] */ Elastos::Utility::Concurrent::IConcurrentNavigableMap ** res) = 0;

    virtual CARAPI DescendingMap(
        /* [out] */ Elastos::Utility::Concurrent::IConcurrentNavigableMap ** res) = 0;

    virtual CARAPI NavigableKeySet(
        /* [out] */ Elastos::Utility::INavigableSet ** res) = 0;

    virtual CARAPI KeySet(
        /* [out] */ Elastos::Utility::INavigableSet ** res) = 0;

    virtual CARAPI DescendingKeySet(
        /* [out] */ Elastos::Utility::INavigableSet ** res) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("73483644-1452-B014-4E17-8161B6338767")
IExecutorCompletionService : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IExecutorCompletionService*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IExecutorCompletionService*)pObj->Probe(EIID_IExecutorCompletionService);
    }

    static CARAPI_(IExecutorCompletionService*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IExecutorCompletionService*)pObj->Probe(EIID_IExecutorCompletionService);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("7E506E48-0712-BE51-529E-888202D6690E")
IScheduledExecutorService : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IScheduledExecutorService*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IScheduledExecutorService*)pObj->Probe(EIID_IScheduledExecutorService);
    }

    static CARAPI_(IScheduledExecutorService*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IScheduledExecutorService*)pObj->Probe(EIID_IScheduledExecutorService);
    }

    virtual CARAPI Schedule(
        /* [in] */ Elastos::Core::IRunnable * command,
        /* [in] */ _ELASTOS Int64 delay,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ Elastos::Utility::Concurrent::IFuture ** result) = 0;

    virtual CARAPI Schedule(
        /* [in] */ Elastos::Utility::Concurrent::ICallable * callable,
        /* [in] */ _ELASTOS Int64 delay,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ Elastos::Utility::Concurrent::IFuture ** result) = 0;

    virtual CARAPI ScheduleAtFixedRate(
        /* [in] */ Elastos::Core::IRunnable * command,
        /* [in] */ _ELASTOS Int64 initialDelay,
        /* [in] */ _ELASTOS Int64 period,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ Elastos::Utility::Concurrent::IFuture ** result) = 0;

    virtual CARAPI ScheduleWithFixedDelay(
        /* [in] */ Elastos::Core::IRunnable * command,
        /* [in] */ _ELASTOS Int64 initialDelay,
        /* [in] */ _ELASTOS Int64 delay,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [out] */ Elastos::Utility::Concurrent::IFuture ** result) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("AD563355-1A52-3558-18FB-56F06AE20F07")
IRecursiveAction : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRecursiveAction*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRecursiveAction*)pObj->Probe(EIID_IRecursiveAction);
    }

    static CARAPI_(IRecursiveAction*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRecursiveAction*)pObj->Probe(EIID_IRecursiveAction);
    }

    virtual CARAPI Compute() = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("1BB43106-86D2-789A-6DB3-39DA91B6FB3B")
IRecursiveTask : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRecursiveTask*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRecursiveTask*)pObj->Probe(EIID_IRecursiveTask);
    }

    static CARAPI_(IRecursiveTask*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRecursiveTask*)pObj->Probe(EIID_IRecursiveTask);
    }

    virtual CARAPI Compute() = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("8ACE3041-0712-BE51-529E-78802336DE0E")
IScheduledFutureTask : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IScheduledFutureTask*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IScheduledFutureTask*)pObj->Probe(EIID_IScheduledFutureTask);
    }

    static CARAPI_(IScheduledFutureTask*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IScheduledFutureTask*)pObj->Probe(EIID_IScheduledFutureTask);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("D74B3836-0712-2B13-F4E3-78A15F78D867")
IScheduledThreadPoolExecutor : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IScheduledThreadPoolExecutor*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IScheduledThreadPoolExecutor*)pObj->Probe(EIID_IScheduledThreadPoolExecutor);
    }

    static CARAPI_(IScheduledThreadPoolExecutor*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IScheduledThreadPoolExecutor*)pObj->Probe(EIID_IScheduledThreadPoolExecutor);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("6CE5F727-2552-88FD-5EA0-B871FF477B1B")
ICountedCompleter : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICountedCompleter*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICountedCompleter*)pObj->Probe(EIID_ICountedCompleter);
    }

    static CARAPI_(ICountedCompleter*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICountedCompleter*)pObj->Probe(EIID_ICountedCompleter);
    }

    virtual CARAPI Compute() = 0;

    virtual CARAPI OnCompletion(
        /* [in] */ Elastos::Utility::Concurrent::ICountedCompleter * caller) = 0;

    virtual CARAPI OnExceptionalCompletion(
        /* [in] */ Elastos::Core::IThrowable * ex,
        /* [in] */ Elastos::Utility::Concurrent::ICountedCompleter * caller,
        /* [out] */ _ELASTOS Boolean * res) = 0;

    virtual CARAPI GetCompleter(
        /* [out] */ Elastos::Utility::Concurrent::ICountedCompleter ** res) = 0;

    virtual CARAPI GetPendingCount(
        /* [out] */ _ELASTOS Int32 * res) = 0;

    virtual CARAPI SetPendingCount(
        /* [in] */ _ELASTOS Int32 count) = 0;

    virtual CARAPI AddToPendingCount(
        /* [in] */ _ELASTOS Int32 delta) = 0;

    virtual CARAPI CompareAndSetPendingCount(
        /* [in] */ _ELASTOS Int32 expected,
        /* [in] */ _ELASTOS Int32 count,
        /* [out] */ _ELASTOS Boolean * res) = 0;

    virtual CARAPI DecrementPendingCountUnlessZero(
        /* [out] */ _ELASTOS Int32 * res) = 0;

    virtual CARAPI GetRoot(
        /* [out] */ Elastos::Utility::Concurrent::ICountedCompleter ** res) = 0;

    virtual CARAPI TryComplete() = 0;

    virtual CARAPI PropagateCompletion() = 0;

    virtual CARAPI Complete(
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI FirstComplete(
        /* [out] */ Elastos::Utility::Concurrent::ICountedCompleter ** res) = 0;

    virtual CARAPI NextComplete(
        /* [out] */ Elastos::Utility::Concurrent::ICountedCompleter ** res) = 0;

    virtual CARAPI QuietlyCompleteRoot() = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("29F9712E-8312-BA4A-2A90-B86162851EA3")
ICCountDownLatchClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCountDownLatchClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCountDownLatchClassObject*)pObj->Probe(EIID_ICCountDownLatchClassObject);
    }

    static CARAPI_(ICCountDownLatchClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCountDownLatchClassObject*)pObj->Probe(EIID_ICCountDownLatchClassObject);
    }

    virtual CARAPI CreateObjectWithCount(
        /* [in] */ _ELASTOS Int32 count,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("461FA647-8312-2828-609D-2E02C36C670E")
ICExecutorCompletionServiceClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICExecutorCompletionServiceClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICExecutorCompletionServiceClassObject*)pObj->Probe(EIID_ICExecutorCompletionServiceClassObject);
    }

    static CARAPI_(ICExecutorCompletionServiceClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICExecutorCompletionServiceClassObject*)pObj->Probe(EIID_ICExecutorCompletionServiceClassObject);
    }

    virtual CARAPI CreateObjectWithExecutor(
        /* [in] */ Elastos::Utility::Concurrent::IExecutor * executor,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithExecutorCompletionQueue(
        /* [in] */ Elastos::Utility::Concurrent::IExecutor * executor,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * completionQueue,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("90097222-8312-2867-4CE0-B891DF861EA3")
ICExecutorsClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICExecutorsClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICExecutorsClassObject*)pObj->Probe(EIID_ICExecutorsClassObject);
    }

    static CARAPI_(ICExecutorsClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICExecutorsClassObject*)pObj->Probe(EIID_ICExecutorsClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("E3DFA52E-0312-FA8C-CBD4-D78003050E14")
ICLinkedBlockingQueueClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICLinkedBlockingQueueClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLinkedBlockingQueueClassObject*)pObj->Probe(EIID_ICLinkedBlockingQueueClassObject);
    }

    static CARAPI_(ICLinkedBlockingQueueClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLinkedBlockingQueueClassObject*)pObj->Probe(EIID_ICLinkedBlockingQueueClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCapacity(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithC(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("6488D227-0312-61E1-9FA1-3081E3467E3D")
ICThreadPoolExecutorClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICThreadPoolExecutorClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICThreadPoolExecutorClassObject*)pObj->Probe(EIID_ICThreadPoolExecutorClassObject);
    }

    static CARAPI_(ICThreadPoolExecutorClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICThreadPoolExecutorClassObject*)pObj->Probe(EIID_ICThreadPoolExecutorClassObject);
    }

    virtual CARAPI CreateObjectWithCorePoolSizeMaximumPoolSizeKeepAliveTimeUnitWorkQueue(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCorePoolSizeMaximumPoolSizeKeepAliveTimeUnitWorkQueueThreadFactory(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCorePoolSizeMaximumPoolSizeKeepAliveTimeUnitWorkQueueHandler(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCorePoolSizeMaximumPoolSizeKeepAliveTimeUnitWorkQueueThreadFactoryHandler(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("A5257712-D312-30B1-EAC5-EC1DA1EF8CD6")
ICTimeUnitHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICTimeUnitHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTimeUnitHelperClassObject*)pObj->Probe(EIID_ICTimeUnitHelperClassObject);
    }

    static CARAPI_(ICTimeUnitHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTimeUnitHelperClassObject*)pObj->Probe(EIID_ICTimeUnitHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("4BC8B12C-0312-652C-EA6B-C08102070A3D")
ICArrayBlockingQueueClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICArrayBlockingQueueClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICArrayBlockingQueueClassObject*)pObj->Probe(EIID_ICArrayBlockingQueueClassObject);
    }

    static CARAPI_(ICArrayBlockingQueueClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICArrayBlockingQueueClassObject*)pObj->Probe(EIID_ICArrayBlockingQueueClassObject);
    }

    virtual CARAPI CreateObjectWithCapacity(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCapacityFair(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCapacityFairC(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Boolean fair,
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("07518F58-0312-B022-FA2E-AB10B1D891B9")
ICConcurrentLinkedDequeClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICConcurrentLinkedDequeClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICConcurrentLinkedDequeClassObject*)pObj->Probe(EIID_ICConcurrentLinkedDequeClassObject);
    }

    static CARAPI_(ICConcurrentLinkedDequeClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICConcurrentLinkedDequeClassObject*)pObj->Probe(EIID_ICConcurrentLinkedDequeClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithC(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("F74F8F5D-0312-B022-FA2E-AB10B19806DA")
ICConcurrentLinkedQueueClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICConcurrentLinkedQueueClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICConcurrentLinkedQueueClassObject*)pObj->Probe(EIID_ICConcurrentLinkedQueueClassObject);
    }

    static CARAPI_(ICConcurrentLinkedQueueClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICConcurrentLinkedQueueClassObject*)pObj->Probe(EIID_ICConcurrentLinkedQueueClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithC(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("7AB2C44A-0312-B022-FA2E-E3E082C58C0A")
ICConcurrentSkipListMapClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICConcurrentSkipListMapClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICConcurrentSkipListMapClassObject*)pObj->Probe(EIID_ICConcurrentSkipListMapClassObject);
    }

    static CARAPI_(ICConcurrentSkipListMapClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICConcurrentSkipListMapClassObject*)pObj->Probe(EIID_ICConcurrentSkipListMapClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithComparator(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithMap(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithSortedMap(
        /* [in] */ Elastos::Utility::ISortedMap * sortedMap,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("7827CB41-0312-B022-FA2E-E3E082C58C0A")
ICConcurrentSkipListSetClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICConcurrentSkipListSetClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICConcurrentSkipListSetClassObject*)pObj->Probe(EIID_ICConcurrentSkipListSetClassObject);
    }

    static CARAPI_(ICConcurrentSkipListSetClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICConcurrentSkipListSetClassObject*)pObj->Probe(EIID_ICConcurrentSkipListSetClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithComparator(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithC(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithS(
        /* [in] */ Elastos::Utility::ISortedSet * s,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithM(
        /* [in] */ Elastos::Utility::INavigableMap * m,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("4393843C-0312-1A55-70A0-C081428FD11F")
ICDelayQueueClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDelayQueueClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDelayQueueClassObject*)pObj->Probe(EIID_ICDelayQueueClassObject);
    }

    static CARAPI_(ICDelayQueueClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDelayQueueClassObject*)pObj->Probe(EIID_ICDelayQueueClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithC(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("9E28723E-8312-2667-5690-88A1E2BE1EA3")
ICExchangerClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICExchangerClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICExchangerClassObject*)pObj->Probe(EIID_ICExchangerClassObject);
    }

    static CARAPI_(ICExchangerClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICExchangerClassObject*)pObj->Probe(EIID_ICExchangerClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("1F957A29-0312-1EE1-3790-887142060C3D")
ICThreadLocalRandomClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICThreadLocalRandomClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICThreadLocalRandomClassObject*)pObj->Probe(EIID_ICThreadLocalRandomClassObject);
    }

    static CARAPI_(ICThreadLocalRandomClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICThreadLocalRandomClassObject*)pObj->Probe(EIID_ICThreadLocalRandomClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("054D8025-0312-1EE1-3790-887142068C08")
ICThreadLocalRandomHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICThreadLocalRandomHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICThreadLocalRandomHelperClassObject*)pObj->Probe(EIID_ICThreadLocalRandomHelperClassObject);
    }

    static CARAPI_(ICThreadLocalRandomHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICThreadLocalRandomHelperClassObject*)pObj->Probe(EIID_ICThreadLocalRandomHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("484BFF3B-8312-2E6E-1486-D563F4477B1B")
ICForkJoinPoolClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICForkJoinPoolClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICForkJoinPoolClassObject*)pObj->Probe(EIID_ICForkJoinPoolClassObject);
    }

    static CARAPI_(ICForkJoinPoolClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICForkJoinPoolClassObject*)pObj->Probe(EIID_ICForkJoinPoolClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithParallelism(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithParallelismFactoryHandlerAsyncMode(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinPoolForkJoinWorkerThreadFactory * factory,
        /* [in] */ Elastos::Core::IThreadUncaughtExceptionHandler * handler,
        /* [in] */ _ELASTOS Boolean asyncMode,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithParallelismFactoryHandlerModeWorkerNamePrefix(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinPoolForkJoinWorkerThreadFactory * factory,
        /* [in] */ Elastos::Core::IThreadUncaughtExceptionHandler * handler,
        /* [in] */ _ELASTOS Int32 mode,
        /* [in] */ const _ELASTOS String& workerNamePrefix,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("D1717B1A-F312-B5C8-3BC9-6CDC91B61BA1")
ICForkJoinTaskHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICForkJoinTaskHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICForkJoinTaskHelperClassObject*)pObj->Probe(EIID_ICForkJoinTaskHelperClassObject);
    }

    static CARAPI_(ICForkJoinTaskHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICForkJoinTaskHelperClassObject*)pObj->Probe(EIID_ICForkJoinTaskHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("F3E0A536-0312-FA8C-CBD4-6F8082060E14")
ICLinkedBlockingDequeClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICLinkedBlockingDequeClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLinkedBlockingDequeClassObject*)pObj->Probe(EIID_ICLinkedBlockingDequeClassObject);
    }

    static CARAPI_(ICLinkedBlockingDequeClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLinkedBlockingDequeClassObject*)pObj->Probe(EIID_ICLinkedBlockingDequeClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCapacity(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithC(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("5CC98D45-8312-110A-8BC5-1164235B0D0D")
ICLinkedTransferQueueClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICLinkedTransferQueueClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLinkedTransferQueueClassObject*)pObj->Probe(EIID_ICLinkedTransferQueueClassObject);
    }

    static CARAPI_(ICLinkedTransferQueueClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLinkedTransferQueueClassObject*)pObj->Probe(EIID_ICLinkedTransferQueueClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithC(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("BFC3B92E-8312-2B0C-48D8-B8AFC7E88FF6")
ICPhaserClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPhaserClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPhaserClassObject*)pObj->Probe(EIID_ICPhaserClassObject);
    }

    static CARAPI_(ICPhaserClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPhaserClassObject*)pObj->Probe(EIID_ICPhaserClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithParties(
        /* [in] */ _ELASTOS Int32 parties,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithParent(
        /* [in] */ Elastos::Utility::Concurrent::IPhaser * parent,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithParentParties(
        /* [in] */ Elastos::Utility::Concurrent::IPhaser * parent,
        /* [in] */ _ELASTOS Int32 parties,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("AC01AC32-0312-4C49-CF63-D1A8C7E88FF6")
ICCopyOnWriteArrayListClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCopyOnWriteArrayListClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCopyOnWriteArrayListClassObject*)pObj->Probe(EIID_ICCopyOnWriteArrayListClassObject);
    }

    static CARAPI_(ICCopyOnWriteArrayListClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCopyOnWriteArrayListClassObject*)pObj->Probe(EIID_ICCopyOnWriteArrayListClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCollection(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithArray(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * array,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("0DE98322-0312-4C49-CF63-D11801C58B19")
ICCopyOnWriteArrayListHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCopyOnWriteArrayListHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCopyOnWriteArrayListHelperClassObject*)pObj->Probe(EIID_ICCopyOnWriteArrayListHelperClassObject);
    }

    static CARAPI_(ICCopyOnWriteArrayListHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCopyOnWriteArrayListHelperClassObject*)pObj->Probe(EIID_ICCopyOnWriteArrayListHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("69CF8D2F-0312-4C49-CF63-D1ACC7E88FF6")
ICCopyOnWriteArraySetClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCopyOnWriteArraySetClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCopyOnWriteArraySetClassObject*)pObj->Probe(EIID_ICCopyOnWriteArraySetClassObject);
    }

    static CARAPI_(ICCopyOnWriteArraySetClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCopyOnWriteArraySetClassObject*)pObj->Probe(EIID_ICCopyOnWriteArraySetClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithC(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("2D43961C-C312-E6F0-CB9A-0B59D72C5A33")
ICCyclicBarrierClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCyclicBarrierClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCyclicBarrierClassObject*)pObj->Probe(EIID_ICCyclicBarrierClassObject);
    }

    static CARAPI_(ICCyclicBarrierClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCyclicBarrierClassObject*)pObj->Probe(EIID_ICCyclicBarrierClassObject);
    }

    virtual CARAPI CreateObjectWithPartiesBarrierAction(
        /* [in] */ _ELASTOS Int32 parties,
        /* [in] */ Elastos::Core::IRunnable * barrierAction,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithParties(
        /* [in] */ _ELASTOS Int32 parties,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("BBC7D72B-8312-65B5-EA6B-C08102070A3D")
ICPriorityBlockingQueueClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPriorityBlockingQueueClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPriorityBlockingQueueClassObject*)pObj->Probe(EIID_ICPriorityBlockingQueueClassObject);
    }

    static CARAPI_(ICPriorityBlockingQueueClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPriorityBlockingQueueClassObject*)pObj->Probe(EIID_ICPriorityBlockingQueueClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithInitialCapacity(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithInitialCapacityComparator(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithC(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("26C2F53F-0312-260E-56E8-C7F142BFF0B0")
ICScheduledThreadPoolExecutorClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICScheduledThreadPoolExecutorClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICScheduledThreadPoolExecutorClassObject*)pObj->Probe(EIID_ICScheduledThreadPoolExecutorClassObject);
    }

    static CARAPI_(ICScheduledThreadPoolExecutorClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICScheduledThreadPoolExecutorClassObject*)pObj->Probe(EIID_ICScheduledThreadPoolExecutorClassObject);
    }

    virtual CARAPI CreateObjectWithCorePoolSize(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCorePoolSizeThreadFactory(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCorePoolSizeHandler(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCorePoolSizeThreadFactoryHandler(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Atomic {
CAR_INTERFACE("03939918-A312-32DC-CC9A-8B2CBF281933")
ICAtomicBooleanClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAtomicBooleanClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAtomicBooleanClassObject*)pObj->Probe(EIID_ICAtomicBooleanClassObject);
    }

    static CARAPI_(ICAtomicBooleanClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAtomicBooleanClassObject*)pObj->Probe(EIID_ICAtomicBooleanClassObject);
    }

    virtual CARAPI CreateObjectWithInitialValue(
        /* [in] */ _ELASTOS Boolean initialValue,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Atomic {
CAR_INTERFACE("D44E9B12-A312-32DC-CC9A-527CA32A5A0F")
ICAtomicInteger32ClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAtomicInteger32ClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAtomicInteger32ClassObject*)pObj->Probe(EIID_ICAtomicInteger32ClassObject);
    }

    static CARAPI_(ICAtomicInteger32ClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAtomicInteger32ClassObject*)pObj->Probe(EIID_ICAtomicInteger32ClassObject);
    }

    virtual CARAPI CreateObjectWithInitialValue(
        /* [in] */ _ELASTOS Int32 initialValue,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Atomic {
CAR_INTERFACE("29BD9415-A312-32DC-CC9A-527CA32A5A0F")
ICAtomicInteger32ArrayClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAtomicInteger32ArrayClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAtomicInteger32ArrayClassObject*)pObj->Probe(EIID_ICAtomicInteger32ArrayClassObject);
    }

    static CARAPI_(ICAtomicInteger32ArrayClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAtomicInteger32ArrayClassObject*)pObj->Probe(EIID_ICAtomicInteger32ArrayClassObject);
    }

    virtual CARAPI CreateObjectWithLength(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithOther(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int32> & other,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Atomic {
CAR_INTERFACE("D14C9B03-A312-32DC-CC9A-527CA32A5A1B")
ICAtomicInteger64ClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAtomicInteger64ClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAtomicInteger64ClassObject*)pObj->Probe(EIID_ICAtomicInteger64ClassObject);
    }

    static CARAPI_(ICAtomicInteger64ClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAtomicInteger64ClassObject*)pObj->Probe(EIID_ICAtomicInteger64ClassObject);
    }

    virtual CARAPI CreateObjectWithInitialValue(
        /* [in] */ _ELASTOS Int64 initialValue,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Atomic {
CAR_INTERFACE("26BB9406-A312-32DC-CC9A-527CA32A5A1B")
ICAtomicInteger64ArrayClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAtomicInteger64ArrayClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAtomicInteger64ArrayClassObject*)pObj->Probe(EIID_ICAtomicInteger64ArrayClassObject);
    }

    static CARAPI_(ICAtomicInteger64ArrayClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAtomicInteger64ArrayClassObject*)pObj->Probe(EIID_ICAtomicInteger64ArrayClassObject);
    }

    virtual CARAPI CreateObjectWithLength(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithOther(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int64> & other,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Atomic {
CAR_INTERFACE("B624914E-8312-3220-789A-B090C8859E34")
ICAtomicMarkableReferenceClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAtomicMarkableReferenceClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAtomicMarkableReferenceClassObject*)pObj->Probe(EIID_ICAtomicMarkableReferenceClassObject);
    }

    static CARAPI_(ICAtomicMarkableReferenceClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAtomicMarkableReferenceClassObject*)pObj->Probe(EIID_ICAtomicMarkableReferenceClassObject);
    }

    virtual CARAPI CreateObjectWithInitialRefInitialMark(
        /* [in] */ IInterface * initialRef,
        /* [in] */ _ELASTOS Boolean initialMark,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Atomic {
CAR_INTERFACE("AD199B4B-8312-3220-789A-48930D6F0C50")
ICAtomicReferenceClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAtomicReferenceClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAtomicReferenceClassObject*)pObj->Probe(EIID_ICAtomicReferenceClassObject);
    }

    static CARAPI_(ICAtomicReferenceClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAtomicReferenceClassObject*)pObj->Probe(EIID_ICAtomicReferenceClassObject);
    }

    virtual CARAPI CreateObjectWithInitialValue(
        /* [in] */ IInterface * initialValue,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Atomic {
CAR_INTERFACE("08859441-8312-3220-789A-48930D6F0C50")
ICAtomicReferenceArrayClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAtomicReferenceArrayClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAtomicReferenceArrayClassObject*)pObj->Probe(EIID_ICAtomicReferenceArrayClassObject);
    }

    static CARAPI_(ICAtomicReferenceArrayClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAtomicReferenceArrayClassObject*)pObj->Probe(EIID_ICAtomicReferenceArrayClassObject);
    }

    virtual CARAPI CreateObjectWithLength(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithArray(
        /* [in] */ const _ELASTOS ArrayOf<IInterface *> & array,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Atomic {
CAR_INTERFACE("9E139117-A312-32DC-CC9A-DC4DC2337A6E")
ICAtomicStampedReferenceClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAtomicStampedReferenceClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAtomicStampedReferenceClassObject*)pObj->Probe(EIID_ICAtomicStampedReferenceClassObject);
    }

    static CARAPI_(ICAtomicStampedReferenceClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAtomicStampedReferenceClassObject*)pObj->Probe(EIID_ICAtomicStampedReferenceClassObject);
    }

    virtual CARAPI CreateObjectWithInitialRefInitialStamp(
        /* [in] */ IInterface * initialRef,
        /* [in] */ _ELASTOS Int32 initialStamp,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Atomic {
CAR_INTERFACE("3C3F7631-8312-2807-6298-C0AFC7E88FF6")
ICFencesClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICFencesClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFencesClassObject*)pObj->Probe(EIID_ICFencesClassObject);
    }

    static CARAPI_(ICFencesClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFencesClassObject*)pObj->Probe(EIID_ICFencesClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Locks {
CAR_INTERFACE("16927A39-8312-1C8F-70CC-9891FF861EA3")
ICLockSupportClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICLockSupportClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLockSupportClassObject*)pObj->Probe(EIID_ICLockSupportClassObject);
    }

    static CARAPI_(ICLockSupportClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLockSupportClassObject*)pObj->Probe(EIID_ICLockSupportClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Locks {
CAR_INTERFACE("2EF29008-B312-68A1-7CD7-647C57B2E932")
ICReentrantLockClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICReentrantLockClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICReentrantLockClassObject*)pObj->Probe(EIID_ICReentrantLockClassObject);
    }

    static CARAPI_(ICReentrantLockClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICReentrantLockClassObject*)pObj->Probe(EIID_ICReentrantLockClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFair(
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Locks {
CAR_INTERFACE("F79E9959-8312-CB34-EEC6-B871064F0519")
ICReentrantReadWriteLockClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICReentrantReadWriteLockClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICReentrantReadWriteLockClassObject*)pObj->Probe(EIID_ICReentrantReadWriteLockClassObject);
    }

    static CARAPI_(ICReentrantReadWriteLockClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICReentrantReadWriteLockClassObject*)pObj->Probe(EIID_ICReentrantReadWriteLockClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithFair(
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
CAR_INTERFACE("0773890D-C312-30A1-39AF-728D322F69DB")
ICSemaphoreClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSemaphoreClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSemaphoreClassObject*)pObj->Probe(EIID_ICSemaphoreClassObject);
    }

    static CARAPI_(ICSemaphoreClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSemaphoreClassObject*)pObj->Probe(EIID_ICSemaphoreClassObject);
    }

    virtual CARAPI CreateObjectWithPermits(
        /* [in] */ _ELASTOS Int32 permits,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPermitsFair(
        /* [in] */ _ELASTOS Int32 permits,
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
class CCountDownLatch
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 count,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCountDownLatchClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCountDownLatch, RGM_SAME_DOMAIN,
                EIID_ICCountDownLatchClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCount(count, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 count,
        /* [out] */ Elastos::Utility::Concurrent::ICountDownLatch** __ICountDownLatch)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(count, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICountDownLatch = (Elastos::Utility::Concurrent::ICountDownLatch*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_ICountDownLatch);
        if (*__ICountDownLatch) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 count,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(count, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 count,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(count, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 count,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(count, &__pNewObj);
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
namespace Concurrent {
class CExecutorCompletionService
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::Concurrent::IExecutor * executor,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICExecutorCompletionServiceClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CExecutorCompletionService, RGM_SAME_DOMAIN,
                EIID_ICExecutorCompletionServiceClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithExecutor(executor, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::Concurrent::IExecutor * executor,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * completionQueue,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICExecutorCompletionServiceClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CExecutorCompletionService, RGM_SAME_DOMAIN,
                EIID_ICExecutorCompletionServiceClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithExecutorCompletionQueue(executor, completionQueue, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Concurrent::IExecutor * executor,
        /* [out] */ Elastos::Utility::Concurrent::ICompletionService** __ICompletionService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(executor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICompletionService = (Elastos::Utility::Concurrent::ICompletionService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_ICompletionService);
        if (*__ICompletionService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Concurrent::IExecutor * executor,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(executor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Concurrent::IExecutor * executor,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(executor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Concurrent::IExecutor * executor,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(executor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Concurrent::IExecutor * executor,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * completionQueue,
        /* [out] */ Elastos::Utility::Concurrent::ICompletionService** __ICompletionService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(executor, completionQueue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICompletionService = (Elastos::Utility::Concurrent::ICompletionService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_ICompletionService);
        if (*__ICompletionService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Concurrent::IExecutor * executor,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * completionQueue,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(executor, completionQueue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Concurrent::IExecutor * executor,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * completionQueue,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(executor, completionQueue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Concurrent::IExecutor * executor,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * completionQueue,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(executor, completionQueue, &__pNewObj);
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
namespace Concurrent {
class CExecutors
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Utility::Concurrent::IExecutors** __object)
    {
        return _CObject_CreateInstance(ECLSID_CExecutors, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::EIID_IExecutors, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CExecutors, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CExecutors, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CExecutors, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
class CLinkedBlockingQueue
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICLinkedBlockingQueueClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CLinkedBlockingQueue, RGM_SAME_DOMAIN,
                EIID_ICLinkedBlockingQueueClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCapacity(capacity, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICLinkedBlockingQueueClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CLinkedBlockingQueue, RGM_SAME_DOMAIN,
                EIID_ICLinkedBlockingQueueClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithC(c, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::IBlockingQueue** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedBlockingQueue, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::EIID_IBlockingQueue, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IQueue** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedBlockingQueue, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IQueue, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ICollection** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedBlockingQueue, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ICollection, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IIterable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedBlockingQueue, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IIterable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedBlockingQueue, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedBlockingQueue, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedBlockingQueue, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedBlockingQueue, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::Concurrent::IBlockingQueue** __IBlockingQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBlockingQueue = (Elastos::Utility::Concurrent::IBlockingQueue*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IBlockingQueue);
        if (*__IBlockingQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IQueue** __IQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IQueue = (Elastos::Utility::IQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IQueue);
        if (*__IQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::Concurrent::IBlockingQueue** __IBlockingQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBlockingQueue = (Elastos::Utility::Concurrent::IBlockingQueue*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IBlockingQueue);
        if (*__IBlockingQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IQueue** __IQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IQueue = (Elastos::Utility::IQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IQueue);
        if (*__IQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
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
namespace Concurrent {
class CThreadPoolExecutor
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICThreadPoolExecutorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CThreadPoolExecutor, RGM_SAME_DOMAIN,
                EIID_ICThreadPoolExecutorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCorePoolSizeMaximumPoolSizeKeepAliveTimeUnitWorkQueue(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICThreadPoolExecutorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CThreadPoolExecutor, RGM_SAME_DOMAIN,
                EIID_ICThreadPoolExecutorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCorePoolSizeMaximumPoolSizeKeepAliveTimeUnitWorkQueueThreadFactory(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, threadFactory, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICThreadPoolExecutorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CThreadPoolExecutor, RGM_SAME_DOMAIN,
                EIID_ICThreadPoolExecutorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCorePoolSizeMaximumPoolSizeKeepAliveTimeUnitWorkQueueHandler(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, handler, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICThreadPoolExecutorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CThreadPoolExecutor, RGM_SAME_DOMAIN,
                EIID_ICThreadPoolExecutorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCorePoolSizeMaximumPoolSizeKeepAliveTimeUnitWorkQueueThreadFactoryHandler(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, threadFactory, handler, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [out] */ Elastos::Utility::Concurrent::IThreadPoolExecutor** __IThreadPoolExecutor)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IThreadPoolExecutor = (Elastos::Utility::Concurrent::IThreadPoolExecutor*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IThreadPoolExecutor);
        if (*__IThreadPoolExecutor) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [out] */ Elastos::Utility::Concurrent::IAbstractExecutorService** __IAbstractExecutorService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAbstractExecutorService = (Elastos::Utility::Concurrent::IAbstractExecutorService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IAbstractExecutorService);
        if (*__IAbstractExecutorService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [out] */ Elastos::Utility::Concurrent::IExecutorService** __IExecutorService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IExecutorService = (Elastos::Utility::Concurrent::IExecutorService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IExecutorService);
        if (*__IExecutorService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [out] */ Elastos::Utility::Concurrent::IExecutor** __IExecutor)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IExecutor = (Elastos::Utility::Concurrent::IExecutor*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IExecutor);
        if (*__IExecutor) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [out] */ Elastos::Utility::Concurrent::IThreadPoolExecutor** __IThreadPoolExecutor)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, threadFactory, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IThreadPoolExecutor = (Elastos::Utility::Concurrent::IThreadPoolExecutor*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IThreadPoolExecutor);
        if (*__IThreadPoolExecutor) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [out] */ Elastos::Utility::Concurrent::IAbstractExecutorService** __IAbstractExecutorService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, threadFactory, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAbstractExecutorService = (Elastos::Utility::Concurrent::IAbstractExecutorService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IAbstractExecutorService);
        if (*__IAbstractExecutorService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [out] */ Elastos::Utility::Concurrent::IExecutorService** __IExecutorService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, threadFactory, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IExecutorService = (Elastos::Utility::Concurrent::IExecutorService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IExecutorService);
        if (*__IExecutorService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [out] */ Elastos::Utility::Concurrent::IExecutor** __IExecutor)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, threadFactory, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IExecutor = (Elastos::Utility::Concurrent::IExecutor*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IExecutor);
        if (*__IExecutor) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, threadFactory, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, threadFactory, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, threadFactory, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ Elastos::Utility::Concurrent::IThreadPoolExecutor** __IThreadPoolExecutor)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IThreadPoolExecutor = (Elastos::Utility::Concurrent::IThreadPoolExecutor*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IThreadPoolExecutor);
        if (*__IThreadPoolExecutor) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ Elastos::Utility::Concurrent::IAbstractExecutorService** __IAbstractExecutorService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAbstractExecutorService = (Elastos::Utility::Concurrent::IAbstractExecutorService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IAbstractExecutorService);
        if (*__IAbstractExecutorService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ Elastos::Utility::Concurrent::IExecutorService** __IExecutorService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IExecutorService = (Elastos::Utility::Concurrent::IExecutorService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IExecutorService);
        if (*__IExecutorService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ Elastos::Utility::Concurrent::IExecutor** __IExecutor)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IExecutor = (Elastos::Utility::Concurrent::IExecutor*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IExecutor);
        if (*__IExecutor) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ Elastos::Utility::Concurrent::IThreadPoolExecutor** __IThreadPoolExecutor)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, threadFactory, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IThreadPoolExecutor = (Elastos::Utility::Concurrent::IThreadPoolExecutor*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IThreadPoolExecutor);
        if (*__IThreadPoolExecutor) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ Elastos::Utility::Concurrent::IAbstractExecutorService** __IAbstractExecutorService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, threadFactory, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAbstractExecutorService = (Elastos::Utility::Concurrent::IAbstractExecutorService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IAbstractExecutorService);
        if (*__IAbstractExecutorService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ Elastos::Utility::Concurrent::IExecutorService** __IExecutorService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, threadFactory, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IExecutorService = (Elastos::Utility::Concurrent::IExecutorService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IExecutorService);
        if (*__IExecutorService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ Elastos::Utility::Concurrent::IExecutor** __IExecutor)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, threadFactory, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IExecutor = (Elastos::Utility::Concurrent::IExecutor*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IExecutor);
        if (*__IExecutor) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, threadFactory, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, threadFactory, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ _ELASTOS Int32 maximumPoolSize,
        /* [in] */ _ELASTOS Int64 keepAliveTime,
        /* [in] */ Elastos::Utility::Concurrent::ITimeUnit * unit,
        /* [in] */ Elastos::Utility::Concurrent::IBlockingQueue * workQueue,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, maximumPoolSize, keepAliveTime, unit, workQueue, threadFactory, handler, &__pNewObj);
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
namespace Concurrent {
class CTimeUnitHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Utility::Concurrent::ITimeUnitHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTimeUnitHelper, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::EIID_ITimeUnitHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTimeUnitHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTimeUnitHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTimeUnitHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
class CArrayBlockingQueue
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICArrayBlockingQueueClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CArrayBlockingQueue, RGM_SAME_DOMAIN,
                EIID_ICArrayBlockingQueueClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCapacity(capacity, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICArrayBlockingQueueClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CArrayBlockingQueue, RGM_SAME_DOMAIN,
                EIID_ICArrayBlockingQueueClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCapacityFair(capacity, fair, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Boolean fair,
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICArrayBlockingQueueClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CArrayBlockingQueue, RGM_SAME_DOMAIN,
                EIID_ICArrayBlockingQueueClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCapacityFairC(capacity, fair, c, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::Concurrent::IBlockingQueue** __IBlockingQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBlockingQueue = (Elastos::Utility::Concurrent::IBlockingQueue*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IBlockingQueue);
        if (*__IBlockingQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IQueue** __IQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IQueue = (Elastos::Utility::IQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IQueue);
        if (*__IQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ Elastos::Utility::Concurrent::IBlockingQueue** __IBlockingQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, fair, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBlockingQueue = (Elastos::Utility::Concurrent::IBlockingQueue*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IBlockingQueue);
        if (*__IBlockingQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ Elastos::Utility::IQueue** __IQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, fair, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IQueue = (Elastos::Utility::IQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IQueue);
        if (*__IQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, fair, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, fair, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, fair, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, fair, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, fair, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, fair, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Boolean fair,
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::Concurrent::IBlockingQueue** __IBlockingQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, fair, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBlockingQueue = (Elastos::Utility::Concurrent::IBlockingQueue*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IBlockingQueue);
        if (*__IBlockingQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Boolean fair,
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IQueue** __IQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, fair, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IQueue = (Elastos::Utility::IQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IQueue);
        if (*__IQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Boolean fair,
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, fair, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Boolean fair,
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, fair, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Boolean fair,
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, fair, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Boolean fair,
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, fair, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Boolean fair,
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, fair, c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Boolean fair,
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, fair, c, &__pNewObj);
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
namespace Concurrent {
class CConcurrentLinkedDeque
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICConcurrentLinkedDequeClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CConcurrentLinkedDeque, RGM_SAME_DOMAIN,
                EIID_ICConcurrentLinkedDequeClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithC(c, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IDeque** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentLinkedDeque, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IDeque, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IQueue** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentLinkedDeque, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IQueue, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ICollection** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentLinkedDeque, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ICollection, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IIterable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentLinkedDeque, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IIterable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentLinkedDeque, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentLinkedDeque, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentLinkedDeque, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentLinkedDeque, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IDeque** __IDeque)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDeque = (Elastos::Utility::IDeque*)__pNewObj->Probe(Elastos::Utility::EIID_IDeque);
        if (*__IDeque) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IQueue** __IQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IQueue = (Elastos::Utility::IQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IQueue);
        if (*__IQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
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
namespace Concurrent {
class CConcurrentLinkedQueue
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICConcurrentLinkedQueueClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CConcurrentLinkedQueue, RGM_SAME_DOMAIN,
                EIID_ICConcurrentLinkedQueueClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithC(c, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::IConcurrentLinkedQueue** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentLinkedQueue, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::EIID_IConcurrentLinkedQueue, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IQueue** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentLinkedQueue, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IQueue, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ICollection** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentLinkedQueue, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ICollection, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IIterable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentLinkedQueue, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IIterable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentLinkedQueue, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentLinkedQueue, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentLinkedQueue, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentLinkedQueue, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::Concurrent::IConcurrentLinkedQueue** __IConcurrentLinkedQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IConcurrentLinkedQueue = (Elastos::Utility::Concurrent::IConcurrentLinkedQueue*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IConcurrentLinkedQueue);
        if (*__IConcurrentLinkedQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IQueue** __IQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IQueue = (Elastos::Utility::IQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IQueue);
        if (*__IQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
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
namespace Concurrent {
class CConcurrentSkipListMap
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICConcurrentSkipListMapClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CConcurrentSkipListMap, RGM_SAME_DOMAIN,
                EIID_ICConcurrentSkipListMapClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithComparator(comparator, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICConcurrentSkipListMapClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CConcurrentSkipListMap, RGM_SAME_DOMAIN,
                EIID_ICConcurrentSkipListMapClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithMap(map, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ISortedMap * sortedMap,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICConcurrentSkipListMapClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CConcurrentSkipListMap, RGM_SAME_DOMAIN,
                EIID_ICConcurrentSkipListMapClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSortedMap(sortedMap, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::INavigableMap** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentSkipListMap, RGM_SAME_DOMAIN, Elastos::Utility::EIID_INavigableMap, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ISortedMap** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentSkipListMap, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ISortedMap, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IMap** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentSkipListMap, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IMap, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::IConcurrentMap** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentSkipListMap, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::EIID_IConcurrentMap, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentSkipListMap, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentSkipListMap, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentSkipListMap, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentSkipListMap, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentSkipListMap, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::INavigableMap** __INavigableMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INavigableMap = (Elastos::Utility::INavigableMap*)__pNewObj->Probe(Elastos::Utility::EIID_INavigableMap);
        if (*__INavigableMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::ISortedMap** __ISortedMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISortedMap = (Elastos::Utility::ISortedMap*)__pNewObj->Probe(Elastos::Utility::EIID_ISortedMap);
        if (*__ISortedMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::Concurrent::IConcurrentMap** __IConcurrentMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IConcurrentMap = (Elastos::Utility::Concurrent::IConcurrentMap*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IConcurrentMap);
        if (*__IConcurrentMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ Elastos::Utility::INavigableMap** __INavigableMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INavigableMap = (Elastos::Utility::INavigableMap*)__pNewObj->Probe(Elastos::Utility::EIID_INavigableMap);
        if (*__INavigableMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ Elastos::Utility::ISortedMap** __ISortedMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISortedMap = (Elastos::Utility::ISortedMap*)__pNewObj->Probe(Elastos::Utility::EIID_ISortedMap);
        if (*__ISortedMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ Elastos::Utility::Concurrent::IConcurrentMap** __IConcurrentMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IConcurrentMap = (Elastos::Utility::Concurrent::IConcurrentMap*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IConcurrentMap);
        if (*__IConcurrentMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedMap * sortedMap,
        /* [out] */ Elastos::Utility::INavigableMap** __INavigableMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sortedMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INavigableMap = (Elastos::Utility::INavigableMap*)__pNewObj->Probe(Elastos::Utility::EIID_INavigableMap);
        if (*__INavigableMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedMap * sortedMap,
        /* [out] */ Elastos::Utility::ISortedMap** __ISortedMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sortedMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISortedMap = (Elastos::Utility::ISortedMap*)__pNewObj->Probe(Elastos::Utility::EIID_ISortedMap);
        if (*__ISortedMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedMap * sortedMap,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sortedMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedMap * sortedMap,
        /* [out] */ Elastos::Utility::Concurrent::IConcurrentMap** __IConcurrentMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sortedMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IConcurrentMap = (Elastos::Utility::Concurrent::IConcurrentMap*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IConcurrentMap);
        if (*__IConcurrentMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedMap * sortedMap,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sortedMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedMap * sortedMap,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sortedMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedMap * sortedMap,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sortedMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedMap * sortedMap,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sortedMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedMap * sortedMap,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sortedMap, &__pNewObj);
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
namespace Concurrent {
class CConcurrentSkipListSet
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICConcurrentSkipListSetClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CConcurrentSkipListSet, RGM_SAME_DOMAIN,
                EIID_ICConcurrentSkipListSetClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithComparator(comparator, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICConcurrentSkipListSetClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CConcurrentSkipListSet, RGM_SAME_DOMAIN,
                EIID_ICConcurrentSkipListSetClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithC(c, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ISortedSet * s,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICConcurrentSkipListSetClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CConcurrentSkipListSet, RGM_SAME_DOMAIN,
                EIID_ICConcurrentSkipListSetClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithS(s, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::INavigableMap * m,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICConcurrentSkipListSetClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CConcurrentSkipListSet, RGM_SAME_DOMAIN,
                EIID_ICConcurrentSkipListSetClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithM(m, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::INavigableSet** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentSkipListSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_INavigableSet, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ISortedSet** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentSkipListSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ISortedSet, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ISet** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentSkipListSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ISet, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ICollection** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentSkipListSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ICollection, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IIterable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentSkipListSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IIterable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentSkipListSet, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentSkipListSet, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentSkipListSet, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentSkipListSet, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CConcurrentSkipListSet, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::INavigableSet** __INavigableSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INavigableSet = (Elastos::Utility::INavigableSet*)__pNewObj->Probe(Elastos::Utility::EIID_INavigableSet);
        if (*__INavigableSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::ISortedSet** __ISortedSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISortedSet = (Elastos::Utility::ISortedSet*)__pNewObj->Probe(Elastos::Utility::EIID_ISortedSet);
        if (*__ISortedSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::ISet** __ISet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISet = (Elastos::Utility::ISet*)__pNewObj->Probe(Elastos::Utility::EIID_ISet);
        if (*__ISet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::INavigableSet** __INavigableSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INavigableSet = (Elastos::Utility::INavigableSet*)__pNewObj->Probe(Elastos::Utility::EIID_INavigableSet);
        if (*__INavigableSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::ISortedSet** __ISortedSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISortedSet = (Elastos::Utility::ISortedSet*)__pNewObj->Probe(Elastos::Utility::EIID_ISortedSet);
        if (*__ISortedSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::ISet** __ISet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISet = (Elastos::Utility::ISet*)__pNewObj->Probe(Elastos::Utility::EIID_ISet);
        if (*__ISet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * s,
        /* [out] */ Elastos::Utility::INavigableSet** __INavigableSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INavigableSet = (Elastos::Utility::INavigableSet*)__pNewObj->Probe(Elastos::Utility::EIID_INavigableSet);
        if (*__INavigableSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * s,
        /* [out] */ Elastos::Utility::ISortedSet** __ISortedSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISortedSet = (Elastos::Utility::ISortedSet*)__pNewObj->Probe(Elastos::Utility::EIID_ISortedSet);
        if (*__ISortedSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * s,
        /* [out] */ Elastos::Utility::ISet** __ISet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISet = (Elastos::Utility::ISet*)__pNewObj->Probe(Elastos::Utility::EIID_ISet);
        if (*__ISet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * s,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * s,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * s,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * s,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * s,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * s,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * s,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(s, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::INavigableMap * m,
        /* [out] */ Elastos::Utility::INavigableSet** __INavigableSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(m, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INavigableSet = (Elastos::Utility::INavigableSet*)__pNewObj->Probe(Elastos::Utility::EIID_INavigableSet);
        if (*__INavigableSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::INavigableMap * m,
        /* [out] */ Elastos::Utility::ISortedSet** __ISortedSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(m, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISortedSet = (Elastos::Utility::ISortedSet*)__pNewObj->Probe(Elastos::Utility::EIID_ISortedSet);
        if (*__ISortedSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::INavigableMap * m,
        /* [out] */ Elastos::Utility::ISet** __ISet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(m, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISet = (Elastos::Utility::ISet*)__pNewObj->Probe(Elastos::Utility::EIID_ISet);
        if (*__ISet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::INavigableMap * m,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(m, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::INavigableMap * m,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(m, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::INavigableMap * m,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(m, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::INavigableMap * m,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(m, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::INavigableMap * m,
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
        /* [in] */ Elastos::Utility::INavigableMap * m,
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
        /* [in] */ Elastos::Utility::INavigableMap * m,
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

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
class CDelayQueue
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDelayQueueClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDelayQueue, RGM_SAME_DOMAIN,
                EIID_ICDelayQueueClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithC(c, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::IBlockingQueue** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDelayQueue, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::EIID_IBlockingQueue, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IQueue** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDelayQueue, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IQueue, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ICollection** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDelayQueue, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ICollection, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IIterable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDelayQueue, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IIterable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDelayQueue, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDelayQueue, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDelayQueue, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::Concurrent::IBlockingQueue** __IBlockingQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBlockingQueue = (Elastos::Utility::Concurrent::IBlockingQueue*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IBlockingQueue);
        if (*__IBlockingQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IQueue** __IQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IQueue = (Elastos::Utility::IQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IQueue);
        if (*__IQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
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
namespace Concurrent {
class CExchanger
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::IExchanger** __object)
    {
        return _CObject_CreateInstance(ECLSID_CExchanger, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::EIID_IExchanger, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CExchanger, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CExchanger, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CExchanger, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
class CThreadLocalRandom
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::IThreadLocalRandom** __object)
    {
        return _CObject_CreateInstance(ECLSID_CThreadLocalRandom, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::EIID_IThreadLocalRandom, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IRandom** __object)
    {
        return _CObject_CreateInstance(ECLSID_CThreadLocalRandom, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IRandom, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CThreadLocalRandom, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CThreadLocalRandom, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CThreadLocalRandom, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
class CThreadLocalRandomHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Utility::Concurrent::IThreadLocalRandomHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CThreadLocalRandomHelper, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::EIID_IThreadLocalRandomHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CThreadLocalRandomHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CThreadLocalRandomHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CThreadLocalRandomHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
class CForkJoinPool
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICForkJoinPoolClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CForkJoinPool, RGM_SAME_DOMAIN,
                EIID_ICForkJoinPoolClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithParallelism(parallelism, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinPoolForkJoinWorkerThreadFactory * factory,
        /* [in] */ Elastos::Core::IThreadUncaughtExceptionHandler * handler,
        /* [in] */ _ELASTOS Boolean asyncMode,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICForkJoinPoolClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CForkJoinPool, RGM_SAME_DOMAIN,
                EIID_ICForkJoinPoolClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithParallelismFactoryHandlerAsyncMode(parallelism, factory, handler, asyncMode, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinPoolForkJoinWorkerThreadFactory * factory,
        /* [in] */ Elastos::Core::IThreadUncaughtExceptionHandler * handler,
        /* [in] */ _ELASTOS Int32 mode,
        /* [in] */ const _ELASTOS String& workerNamePrefix,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICForkJoinPoolClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CForkJoinPool, RGM_SAME_DOMAIN,
                EIID_ICForkJoinPoolClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithParallelismFactoryHandlerModeWorkerNamePrefix(parallelism, factory, handler, mode, workerNamePrefix, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::IForkJoinPool** __object)
    {
        return _CObject_CreateInstance(ECLSID_CForkJoinPool, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::EIID_IForkJoinPool, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::IAbstractExecutorService** __object)
    {
        return _CObject_CreateInstance(ECLSID_CForkJoinPool, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::EIID_IAbstractExecutorService, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::IExecutorService** __object)
    {
        return _CObject_CreateInstance(ECLSID_CForkJoinPool, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::EIID_IExecutorService, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::IExecutor** __object)
    {
        return _CObject_CreateInstance(ECLSID_CForkJoinPool, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::EIID_IExecutor, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CForkJoinPool, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CForkJoinPool, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CForkJoinPool, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [out] */ Elastos::Utility::Concurrent::IForkJoinPool** __IForkJoinPool)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parallelism, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IForkJoinPool = (Elastos::Utility::Concurrent::IForkJoinPool*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IForkJoinPool);
        if (*__IForkJoinPool) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [out] */ Elastos::Utility::Concurrent::IAbstractExecutorService** __IAbstractExecutorService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parallelism, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAbstractExecutorService = (Elastos::Utility::Concurrent::IAbstractExecutorService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IAbstractExecutorService);
        if (*__IAbstractExecutorService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [out] */ Elastos::Utility::Concurrent::IExecutorService** __IExecutorService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parallelism, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IExecutorService = (Elastos::Utility::Concurrent::IExecutorService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IExecutorService);
        if (*__IExecutorService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [out] */ Elastos::Utility::Concurrent::IExecutor** __IExecutor)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parallelism, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IExecutor = (Elastos::Utility::Concurrent::IExecutor*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IExecutor);
        if (*__IExecutor) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parallelism, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parallelism, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parallelism, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinPoolForkJoinWorkerThreadFactory * factory,
        /* [in] */ Elastos::Core::IThreadUncaughtExceptionHandler * handler,
        /* [in] */ _ELASTOS Boolean asyncMode,
        /* [out] */ Elastos::Utility::Concurrent::IForkJoinPool** __IForkJoinPool)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parallelism, factory, handler, asyncMode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IForkJoinPool = (Elastos::Utility::Concurrent::IForkJoinPool*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IForkJoinPool);
        if (*__IForkJoinPool) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinPoolForkJoinWorkerThreadFactory * factory,
        /* [in] */ Elastos::Core::IThreadUncaughtExceptionHandler * handler,
        /* [in] */ _ELASTOS Boolean asyncMode,
        /* [out] */ Elastos::Utility::Concurrent::IAbstractExecutorService** __IAbstractExecutorService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parallelism, factory, handler, asyncMode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAbstractExecutorService = (Elastos::Utility::Concurrent::IAbstractExecutorService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IAbstractExecutorService);
        if (*__IAbstractExecutorService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinPoolForkJoinWorkerThreadFactory * factory,
        /* [in] */ Elastos::Core::IThreadUncaughtExceptionHandler * handler,
        /* [in] */ _ELASTOS Boolean asyncMode,
        /* [out] */ Elastos::Utility::Concurrent::IExecutorService** __IExecutorService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parallelism, factory, handler, asyncMode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IExecutorService = (Elastos::Utility::Concurrent::IExecutorService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IExecutorService);
        if (*__IExecutorService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinPoolForkJoinWorkerThreadFactory * factory,
        /* [in] */ Elastos::Core::IThreadUncaughtExceptionHandler * handler,
        /* [in] */ _ELASTOS Boolean asyncMode,
        /* [out] */ Elastos::Utility::Concurrent::IExecutor** __IExecutor)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parallelism, factory, handler, asyncMode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IExecutor = (Elastos::Utility::Concurrent::IExecutor*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IExecutor);
        if (*__IExecutor) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinPoolForkJoinWorkerThreadFactory * factory,
        /* [in] */ Elastos::Core::IThreadUncaughtExceptionHandler * handler,
        /* [in] */ _ELASTOS Boolean asyncMode,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parallelism, factory, handler, asyncMode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinPoolForkJoinWorkerThreadFactory * factory,
        /* [in] */ Elastos::Core::IThreadUncaughtExceptionHandler * handler,
        /* [in] */ _ELASTOS Boolean asyncMode,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parallelism, factory, handler, asyncMode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinPoolForkJoinWorkerThreadFactory * factory,
        /* [in] */ Elastos::Core::IThreadUncaughtExceptionHandler * handler,
        /* [in] */ _ELASTOS Boolean asyncMode,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parallelism, factory, handler, asyncMode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinPoolForkJoinWorkerThreadFactory * factory,
        /* [in] */ Elastos::Core::IThreadUncaughtExceptionHandler * handler,
        /* [in] */ _ELASTOS Int32 mode,
        /* [in] */ const _ELASTOS String& workerNamePrefix,
        /* [out] */ Elastos::Utility::Concurrent::IForkJoinPool** __IForkJoinPool)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parallelism, factory, handler, mode, workerNamePrefix, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IForkJoinPool = (Elastos::Utility::Concurrent::IForkJoinPool*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IForkJoinPool);
        if (*__IForkJoinPool) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinPoolForkJoinWorkerThreadFactory * factory,
        /* [in] */ Elastos::Core::IThreadUncaughtExceptionHandler * handler,
        /* [in] */ _ELASTOS Int32 mode,
        /* [in] */ const _ELASTOS String& workerNamePrefix,
        /* [out] */ Elastos::Utility::Concurrent::IAbstractExecutorService** __IAbstractExecutorService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parallelism, factory, handler, mode, workerNamePrefix, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAbstractExecutorService = (Elastos::Utility::Concurrent::IAbstractExecutorService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IAbstractExecutorService);
        if (*__IAbstractExecutorService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinPoolForkJoinWorkerThreadFactory * factory,
        /* [in] */ Elastos::Core::IThreadUncaughtExceptionHandler * handler,
        /* [in] */ _ELASTOS Int32 mode,
        /* [in] */ const _ELASTOS String& workerNamePrefix,
        /* [out] */ Elastos::Utility::Concurrent::IExecutorService** __IExecutorService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parallelism, factory, handler, mode, workerNamePrefix, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IExecutorService = (Elastos::Utility::Concurrent::IExecutorService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IExecutorService);
        if (*__IExecutorService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinPoolForkJoinWorkerThreadFactory * factory,
        /* [in] */ Elastos::Core::IThreadUncaughtExceptionHandler * handler,
        /* [in] */ _ELASTOS Int32 mode,
        /* [in] */ const _ELASTOS String& workerNamePrefix,
        /* [out] */ Elastos::Utility::Concurrent::IExecutor** __IExecutor)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parallelism, factory, handler, mode, workerNamePrefix, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IExecutor = (Elastos::Utility::Concurrent::IExecutor*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IExecutor);
        if (*__IExecutor) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinPoolForkJoinWorkerThreadFactory * factory,
        /* [in] */ Elastos::Core::IThreadUncaughtExceptionHandler * handler,
        /* [in] */ _ELASTOS Int32 mode,
        /* [in] */ const _ELASTOS String& workerNamePrefix,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parallelism, factory, handler, mode, workerNamePrefix, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinPoolForkJoinWorkerThreadFactory * factory,
        /* [in] */ Elastos::Core::IThreadUncaughtExceptionHandler * handler,
        /* [in] */ _ELASTOS Int32 mode,
        /* [in] */ const _ELASTOS String& workerNamePrefix,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parallelism, factory, handler, mode, workerNamePrefix, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parallelism,
        /* [in] */ Elastos::Utility::Concurrent::IForkJoinPoolForkJoinWorkerThreadFactory * factory,
        /* [in] */ Elastos::Core::IThreadUncaughtExceptionHandler * handler,
        /* [in] */ _ELASTOS Int32 mode,
        /* [in] */ const _ELASTOS String& workerNamePrefix,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parallelism, factory, handler, mode, workerNamePrefix, &__pNewObj);
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
namespace Concurrent {
class CForkJoinTaskHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Utility::Concurrent::IForkJoinTaskHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CForkJoinTaskHelper, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::EIID_IForkJoinTaskHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CForkJoinTaskHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CForkJoinTaskHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CForkJoinTaskHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
class CLinkedBlockingDeque
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICLinkedBlockingDequeClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CLinkedBlockingDeque, RGM_SAME_DOMAIN,
                EIID_ICLinkedBlockingDequeClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCapacity(capacity, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICLinkedBlockingDequeClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CLinkedBlockingDeque, RGM_SAME_DOMAIN,
                EIID_ICLinkedBlockingDequeClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithC(c, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::IBlockingDeque** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedBlockingDeque, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::EIID_IBlockingDeque, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::IBlockingQueue** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedBlockingDeque, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::EIID_IBlockingQueue, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IQueue** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedBlockingDeque, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IQueue, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ICollection** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedBlockingDeque, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ICollection, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IIterable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedBlockingDeque, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IIterable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedBlockingDeque, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedBlockingDeque, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedBlockingDeque, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedBlockingDeque, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::Concurrent::IBlockingDeque** __IBlockingDeque)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBlockingDeque = (Elastos::Utility::Concurrent::IBlockingDeque*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IBlockingDeque);
        if (*__IBlockingDeque) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::Concurrent::IBlockingQueue** __IBlockingQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBlockingQueue = (Elastos::Utility::Concurrent::IBlockingQueue*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IBlockingQueue);
        if (*__IBlockingQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IQueue** __IQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IQueue = (Elastos::Utility::IQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IQueue);
        if (*__IQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::Concurrent::IBlockingDeque** __IBlockingDeque)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBlockingDeque = (Elastos::Utility::Concurrent::IBlockingDeque*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IBlockingDeque);
        if (*__IBlockingDeque) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::Concurrent::IBlockingQueue** __IBlockingQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBlockingQueue = (Elastos::Utility::Concurrent::IBlockingQueue*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IBlockingQueue);
        if (*__IBlockingQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IQueue** __IQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IQueue = (Elastos::Utility::IQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IQueue);
        if (*__IQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
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
namespace Concurrent {
class CLinkedTransferQueue
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICLinkedTransferQueueClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CLinkedTransferQueue, RGM_SAME_DOMAIN,
                EIID_ICLinkedTransferQueueClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithC(c, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::ITransferQueue** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedTransferQueue, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::EIID_ITransferQueue, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::IBlockingQueue** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedTransferQueue, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::EIID_IBlockingQueue, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IQueue** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedTransferQueue, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IQueue, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ICollection** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedTransferQueue, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ICollection, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IIterable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedTransferQueue, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IIterable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedTransferQueue, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedTransferQueue, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedTransferQueue, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedTransferQueue, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::Concurrent::ITransferQueue** __ITransferQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ITransferQueue = (Elastos::Utility::Concurrent::ITransferQueue*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_ITransferQueue);
        if (*__ITransferQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::Concurrent::IBlockingQueue** __IBlockingQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBlockingQueue = (Elastos::Utility::Concurrent::IBlockingQueue*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IBlockingQueue);
        if (*__IBlockingQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IQueue** __IQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IQueue = (Elastos::Utility::IQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IQueue);
        if (*__IQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
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
namespace Concurrent {
class CPhaser
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 parties,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPhaserClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPhaser, RGM_SAME_DOMAIN,
                EIID_ICPhaserClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithParties(parties, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::Concurrent::IPhaser * parent,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPhaserClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPhaser, RGM_SAME_DOMAIN,
                EIID_ICPhaserClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithParent(parent, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::Concurrent::IPhaser * parent,
        /* [in] */ _ELASTOS Int32 parties,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPhaserClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPhaser, RGM_SAME_DOMAIN,
                EIID_ICPhaserClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithParentParties(parent, parties, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::IPhaser** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPhaser, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::EIID_IPhaser, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPhaser, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPhaser, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPhaser, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parties,
        /* [out] */ Elastos::Utility::Concurrent::IPhaser** __IPhaser)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parties, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPhaser = (Elastos::Utility::Concurrent::IPhaser*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IPhaser);
        if (*__IPhaser) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parties,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parties, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parties,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parties, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parties,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parties, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Concurrent::IPhaser * parent,
        /* [out] */ Elastos::Utility::Concurrent::IPhaser** __IPhaser)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPhaser = (Elastos::Utility::Concurrent::IPhaser*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IPhaser);
        if (*__IPhaser) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Concurrent::IPhaser * parent,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Concurrent::IPhaser * parent,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Concurrent::IPhaser * parent,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Concurrent::IPhaser * parent,
        /* [in] */ _ELASTOS Int32 parties,
        /* [out] */ Elastos::Utility::Concurrent::IPhaser** __IPhaser)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, parties, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPhaser = (Elastos::Utility::Concurrent::IPhaser*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IPhaser);
        if (*__IPhaser) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Concurrent::IPhaser * parent,
        /* [in] */ _ELASTOS Int32 parties,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, parties, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Concurrent::IPhaser * parent,
        /* [in] */ _ELASTOS Int32 parties,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, parties, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Concurrent::IPhaser * parent,
        /* [in] */ _ELASTOS Int32 parties,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, parties, &__pNewObj);
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
namespace Concurrent {
class CCopyOnWriteArrayList
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCopyOnWriteArrayListClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCopyOnWriteArrayList, RGM_SAME_DOMAIN,
                EIID_ICCopyOnWriteArrayListClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCollection(collection, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * array,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCopyOnWriteArrayListClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCopyOnWriteArrayList, RGM_SAME_DOMAIN,
                EIID_ICCopyOnWriteArrayListClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithArray(array, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::ICopyOnWriteArrayList** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCopyOnWriteArrayList, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::EIID_ICopyOnWriteArrayList, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IList** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCopyOnWriteArrayList, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IList, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ICollection** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCopyOnWriteArrayList, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ICollection, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IIterable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCopyOnWriteArrayList, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IIterable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IRandomAccess** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCopyOnWriteArrayList, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IRandomAccess, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCopyOnWriteArrayList, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCopyOnWriteArrayList, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCopyOnWriteArrayList, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCopyOnWriteArrayList, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCopyOnWriteArrayList, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::Concurrent::ICopyOnWriteArrayList** __ICopyOnWriteArrayList)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICopyOnWriteArrayList = (Elastos::Utility::Concurrent::ICopyOnWriteArrayList*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_ICopyOnWriteArrayList);
        if (*__ICopyOnWriteArrayList) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::IList** __IList)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IList = (Elastos::Utility::IList*)__pNewObj->Probe(Elastos::Utility::EIID_IList);
        if (*__IList) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::IRandomAccess** __IRandomAccess)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRandomAccess = (Elastos::Utility::IRandomAccess*)__pNewObj->Probe(Elastos::Utility::EIID_IRandomAccess);
        if (*__IRandomAccess) __pNewObj->AddRef();
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
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
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

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * array,
        /* [out] */ Elastos::Utility::Concurrent::ICopyOnWriteArrayList** __ICopyOnWriteArrayList)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICopyOnWriteArrayList = (Elastos::Utility::Concurrent::ICopyOnWriteArrayList*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_ICopyOnWriteArrayList);
        if (*__ICopyOnWriteArrayList) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * array,
        /* [out] */ Elastos::Utility::IList** __IList)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IList = (Elastos::Utility::IList*)__pNewObj->Probe(Elastos::Utility::EIID_IList);
        if (*__IList) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * array,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * array,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * array,
        /* [out] */ Elastos::Utility::IRandomAccess** __IRandomAccess)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRandomAccess = (Elastos::Utility::IRandomAccess*)__pNewObj->Probe(Elastos::Utility::EIID_IRandomAccess);
        if (*__IRandomAccess) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * array,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * array,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * array,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * array,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * array,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
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
namespace Concurrent {
class CCopyOnWriteArrayListHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Utility::Concurrent::ICopyOnWriteArrayListHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCopyOnWriteArrayListHelper, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::EIID_ICopyOnWriteArrayListHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCopyOnWriteArrayListHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCopyOnWriteArrayListHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCopyOnWriteArrayListHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
class CCopyOnWriteArraySet
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCopyOnWriteArraySetClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCopyOnWriteArraySet, RGM_SAME_DOMAIN,
                EIID_ICCopyOnWriteArraySetClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithC(c, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ISet** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCopyOnWriteArraySet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ISet, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCopyOnWriteArraySet, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCopyOnWriteArraySet, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCopyOnWriteArraySet, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCopyOnWriteArraySet, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::ISet** __ISet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISet = (Elastos::Utility::ISet*)__pNewObj->Probe(Elastos::Utility::EIID_ISet);
        if (*__ISet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
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
namespace Concurrent {
class CCyclicBarrier
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 parties,
        /* [in] */ Elastos::Core::IRunnable * barrierAction,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCyclicBarrierClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCyclicBarrier, RGM_SAME_DOMAIN,
                EIID_ICCyclicBarrierClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPartiesBarrierAction(parties, barrierAction, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 parties,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCyclicBarrierClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCyclicBarrier, RGM_SAME_DOMAIN,
                EIID_ICCyclicBarrierClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithParties(parties, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parties,
        /* [in] */ Elastos::Core::IRunnable * barrierAction,
        /* [out] */ Elastos::Utility::Concurrent::ICyclicBarrier** __ICyclicBarrier)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parties, barrierAction, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICyclicBarrier = (Elastos::Utility::Concurrent::ICyclicBarrier*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_ICyclicBarrier);
        if (*__ICyclicBarrier) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parties,
        /* [in] */ Elastos::Core::IRunnable * barrierAction,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parties, barrierAction, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parties,
        /* [in] */ Elastos::Core::IRunnable * barrierAction,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parties, barrierAction, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parties,
        /* [in] */ Elastos::Core::IRunnable * barrierAction,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parties, barrierAction, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parties,
        /* [out] */ Elastos::Utility::Concurrent::ICyclicBarrier** __ICyclicBarrier)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parties, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICyclicBarrier = (Elastos::Utility::Concurrent::ICyclicBarrier*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_ICyclicBarrier);
        if (*__ICyclicBarrier) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parties,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parties, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parties,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parties, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 parties,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parties, &__pNewObj);
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
namespace Concurrent {
class CPriorityBlockingQueue
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPriorityBlockingQueueClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPriorityBlockingQueue, RGM_SAME_DOMAIN,
                EIID_ICPriorityBlockingQueueClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithInitialCapacity(initialCapacity, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPriorityBlockingQueueClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPriorityBlockingQueue, RGM_SAME_DOMAIN,
                EIID_ICPriorityBlockingQueueClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithInitialCapacityComparator(initialCapacity, comparator, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPriorityBlockingQueueClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPriorityBlockingQueue, RGM_SAME_DOMAIN,
                EIID_ICPriorityBlockingQueueClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithC(c, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::IPriorityBlockingQueue** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPriorityBlockingQueue, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::EIID_IPriorityBlockingQueue, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::IBlockingQueue** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPriorityBlockingQueue, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::EIID_IBlockingQueue, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IQueue** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPriorityBlockingQueue, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IQueue, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ICollection** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPriorityBlockingQueue, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ICollection, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IIterable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPriorityBlockingQueue, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IIterable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPriorityBlockingQueue, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPriorityBlockingQueue, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPriorityBlockingQueue, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPriorityBlockingQueue, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ Elastos::Utility::Concurrent::IPriorityBlockingQueue** __IPriorityBlockingQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPriorityBlockingQueue = (Elastos::Utility::Concurrent::IPriorityBlockingQueue*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IPriorityBlockingQueue);
        if (*__IPriorityBlockingQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ Elastos::Utility::Concurrent::IBlockingQueue** __IBlockingQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBlockingQueue = (Elastos::Utility::Concurrent::IBlockingQueue*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IBlockingQueue);
        if (*__IBlockingQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ Elastos::Utility::IQueue** __IQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IQueue = (Elastos::Utility::IQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IQueue);
        if (*__IQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::Concurrent::IPriorityBlockingQueue** __IPriorityBlockingQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPriorityBlockingQueue = (Elastos::Utility::Concurrent::IPriorityBlockingQueue*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IPriorityBlockingQueue);
        if (*__IPriorityBlockingQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::Concurrent::IBlockingQueue** __IBlockingQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBlockingQueue = (Elastos::Utility::Concurrent::IBlockingQueue*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IBlockingQueue);
        if (*__IBlockingQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::IQueue** __IQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IQueue = (Elastos::Utility::IQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IQueue);
        if (*__IQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::Concurrent::IPriorityBlockingQueue** __IPriorityBlockingQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPriorityBlockingQueue = (Elastos::Utility::Concurrent::IPriorityBlockingQueue*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IPriorityBlockingQueue);
        if (*__IPriorityBlockingQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::Concurrent::IBlockingQueue** __IBlockingQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBlockingQueue = (Elastos::Utility::Concurrent::IBlockingQueue*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IBlockingQueue);
        if (*__IBlockingQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IQueue** __IQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IQueue = (Elastos::Utility::IQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IQueue);
        if (*__IQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
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
namespace Concurrent {
class CScheduledThreadPoolExecutor
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICScheduledThreadPoolExecutorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CScheduledThreadPoolExecutor, RGM_SAME_DOMAIN,
                EIID_ICScheduledThreadPoolExecutorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCorePoolSize(corePoolSize, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICScheduledThreadPoolExecutorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CScheduledThreadPoolExecutor, RGM_SAME_DOMAIN,
                EIID_ICScheduledThreadPoolExecutorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCorePoolSizeThreadFactory(corePoolSize, threadFactory, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICScheduledThreadPoolExecutorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CScheduledThreadPoolExecutor, RGM_SAME_DOMAIN,
                EIID_ICScheduledThreadPoolExecutorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCorePoolSizeHandler(corePoolSize, handler, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICScheduledThreadPoolExecutorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CScheduledThreadPoolExecutor, RGM_SAME_DOMAIN,
                EIID_ICScheduledThreadPoolExecutorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCorePoolSizeThreadFactoryHandler(corePoolSize, threadFactory, handler, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [out] */ Elastos::Utility::Concurrent::IScheduledThreadPoolExecutor** __IScheduledThreadPoolExecutor)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IScheduledThreadPoolExecutor = (Elastos::Utility::Concurrent::IScheduledThreadPoolExecutor*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IScheduledThreadPoolExecutor);
        if (*__IScheduledThreadPoolExecutor) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [out] */ Elastos::Utility::Concurrent::IScheduledExecutorService** __IScheduledExecutorService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IScheduledExecutorService = (Elastos::Utility::Concurrent::IScheduledExecutorService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IScheduledExecutorService);
        if (*__IScheduledExecutorService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [out] */ Elastos::Utility::Concurrent::IExecutorService** __IExecutorService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IExecutorService = (Elastos::Utility::Concurrent::IExecutorService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IExecutorService);
        if (*__IExecutorService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [out] */ Elastos::Utility::Concurrent::IExecutor** __IExecutor)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IExecutor = (Elastos::Utility::Concurrent::IExecutor*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IExecutor);
        if (*__IExecutor) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [out] */ Elastos::Utility::Concurrent::IScheduledThreadPoolExecutor** __IScheduledThreadPoolExecutor)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, threadFactory, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IScheduledThreadPoolExecutor = (Elastos::Utility::Concurrent::IScheduledThreadPoolExecutor*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IScheduledThreadPoolExecutor);
        if (*__IScheduledThreadPoolExecutor) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [out] */ Elastos::Utility::Concurrent::IScheduledExecutorService** __IScheduledExecutorService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, threadFactory, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IScheduledExecutorService = (Elastos::Utility::Concurrent::IScheduledExecutorService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IScheduledExecutorService);
        if (*__IScheduledExecutorService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [out] */ Elastos::Utility::Concurrent::IExecutorService** __IExecutorService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, threadFactory, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IExecutorService = (Elastos::Utility::Concurrent::IExecutorService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IExecutorService);
        if (*__IExecutorService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [out] */ Elastos::Utility::Concurrent::IExecutor** __IExecutor)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, threadFactory, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IExecutor = (Elastos::Utility::Concurrent::IExecutor*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IExecutor);
        if (*__IExecutor) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, threadFactory, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, threadFactory, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, threadFactory, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ Elastos::Utility::Concurrent::IScheduledThreadPoolExecutor** __IScheduledThreadPoolExecutor)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IScheduledThreadPoolExecutor = (Elastos::Utility::Concurrent::IScheduledThreadPoolExecutor*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IScheduledThreadPoolExecutor);
        if (*__IScheduledThreadPoolExecutor) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ Elastos::Utility::Concurrent::IScheduledExecutorService** __IScheduledExecutorService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IScheduledExecutorService = (Elastos::Utility::Concurrent::IScheduledExecutorService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IScheduledExecutorService);
        if (*__IScheduledExecutorService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ Elastos::Utility::Concurrent::IExecutorService** __IExecutorService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IExecutorService = (Elastos::Utility::Concurrent::IExecutorService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IExecutorService);
        if (*__IExecutorService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ Elastos::Utility::Concurrent::IExecutor** __IExecutor)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IExecutor = (Elastos::Utility::Concurrent::IExecutor*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IExecutor);
        if (*__IExecutor) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ Elastos::Utility::Concurrent::IScheduledThreadPoolExecutor** __IScheduledThreadPoolExecutor)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, threadFactory, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IScheduledThreadPoolExecutor = (Elastos::Utility::Concurrent::IScheduledThreadPoolExecutor*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IScheduledThreadPoolExecutor);
        if (*__IScheduledThreadPoolExecutor) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ Elastos::Utility::Concurrent::IScheduledExecutorService** __IScheduledExecutorService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, threadFactory, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IScheduledExecutorService = (Elastos::Utility::Concurrent::IScheduledExecutorService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IScheduledExecutorService);
        if (*__IScheduledExecutorService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ Elastos::Utility::Concurrent::IExecutorService** __IExecutorService)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, threadFactory, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IExecutorService = (Elastos::Utility::Concurrent::IExecutorService*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IExecutorService);
        if (*__IExecutorService) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ Elastos::Utility::Concurrent::IExecutor** __IExecutor)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, threadFactory, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IExecutor = (Elastos::Utility::Concurrent::IExecutor*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_IExecutor);
        if (*__IExecutor) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, threadFactory, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, threadFactory, handler, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 corePoolSize,
        /* [in] */ Elastos::Utility::Concurrent::IThreadFactory * threadFactory,
        /* [in] */ Elastos::Utility::Concurrent::IRejectedExecutionHandler * handler,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(corePoolSize, threadFactory, handler, &__pNewObj);
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
namespace Concurrent {
namespace Atomic {
class CAtomicBoolean
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Boolean initialValue,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAtomicBooleanClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAtomicBoolean, RGM_SAME_DOMAIN,
                EIID_ICAtomicBooleanClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithInitialValue(initialValue, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::Atomic::IAtomicBoolean** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAtomicBoolean, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::Atomic::EIID_IAtomicBoolean, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAtomicBoolean, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAtomicBoolean, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAtomicBoolean, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAtomicBoolean, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean initialValue,
        /* [out] */ Elastos::Utility::Concurrent::Atomic::IAtomicBoolean** __IAtomicBoolean)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAtomicBoolean = (Elastos::Utility::Concurrent::Atomic::IAtomicBoolean*)__pNewObj->Probe(Elastos::Utility::Concurrent::Atomic::EIID_IAtomicBoolean);
        if (*__IAtomicBoolean) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean initialValue,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean initialValue,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean initialValue,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean initialValue,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialValue, &__pNewObj);
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
namespace Utility {
namespace Concurrent {
namespace Atomic {
class CAtomicInteger32
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 initialValue,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAtomicInteger32ClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAtomicInteger32, RGM_SAME_DOMAIN,
                EIID_ICAtomicInteger32ClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithInitialValue(initialValue, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::Atomic::IAtomicInteger32** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAtomicInteger32, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::Atomic::EIID_IAtomicInteger32, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAtomicInteger32, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAtomicInteger32, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAtomicInteger32, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAtomicInteger32, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialValue,
        /* [out] */ Elastos::Utility::Concurrent::Atomic::IAtomicInteger32** __IAtomicInteger32)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAtomicInteger32 = (Elastos::Utility::Concurrent::Atomic::IAtomicInteger32*)__pNewObj->Probe(Elastos::Utility::Concurrent::Atomic::EIID_IAtomicInteger32);
        if (*__IAtomicInteger32) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialValue,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialValue,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialValue,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialValue,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialValue, &__pNewObj);
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
namespace Utility {
namespace Concurrent {
namespace Atomic {
class CAtomicInteger32Array
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAtomicInteger32ArrayClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAtomicInteger32Array, RGM_SAME_DOMAIN,
                EIID_ICAtomicInteger32ArrayClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithLength(length, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int32> & other,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAtomicInteger32ArrayClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAtomicInteger32Array, RGM_SAME_DOMAIN,
                EIID_ICAtomicInteger32ArrayClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOther(other, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::Utility::Concurrent::Atomic::IAtomicInteger32Array** __IAtomicInteger32Array)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAtomicInteger32Array = (Elastos::Utility::Concurrent::Atomic::IAtomicInteger32Array*)__pNewObj->Probe(Elastos::Utility::Concurrent::Atomic::EIID_IAtomicInteger32Array);
        if (*__IAtomicInteger32Array) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int32> & other,
        /* [out] */ Elastos::Utility::Concurrent::Atomic::IAtomicInteger32Array** __IAtomicInteger32Array)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(other, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAtomicInteger32Array = (Elastos::Utility::Concurrent::Atomic::IAtomicInteger32Array*)__pNewObj->Probe(Elastos::Utility::Concurrent::Atomic::EIID_IAtomicInteger32Array);
        if (*__IAtomicInteger32Array) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int32> & other,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(other, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int32> & other,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(other, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int32> & other,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(other, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int32> & other,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(other, &__pNewObj);
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
namespace Utility {
namespace Concurrent {
namespace Atomic {
class CAtomicInteger64
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int64 initialValue,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAtomicInteger64ClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAtomicInteger64, RGM_SAME_DOMAIN,
                EIID_ICAtomicInteger64ClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithInitialValue(initialValue, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::Atomic::IAtomicInteger64** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAtomicInteger64, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::Atomic::EIID_IAtomicInteger64, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAtomicInteger64, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAtomicInteger64, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAtomicInteger64, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAtomicInteger64, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 initialValue,
        /* [out] */ Elastos::Utility::Concurrent::Atomic::IAtomicInteger64** __IAtomicInteger64)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAtomicInteger64 = (Elastos::Utility::Concurrent::Atomic::IAtomicInteger64*)__pNewObj->Probe(Elastos::Utility::Concurrent::Atomic::EIID_IAtomicInteger64);
        if (*__IAtomicInteger64) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 initialValue,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 initialValue,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 initialValue,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 initialValue,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialValue, &__pNewObj);
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
namespace Utility {
namespace Concurrent {
namespace Atomic {
class CAtomicInteger64Array
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAtomicInteger64ArrayClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAtomicInteger64Array, RGM_SAME_DOMAIN,
                EIID_ICAtomicInteger64ArrayClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithLength(length, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int64> & other,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAtomicInteger64ArrayClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAtomicInteger64Array, RGM_SAME_DOMAIN,
                EIID_ICAtomicInteger64ArrayClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithOther(other, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::Utility::Concurrent::Atomic::IAtomicInteger64Array** __IAtomicInteger64Array)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAtomicInteger64Array = (Elastos::Utility::Concurrent::Atomic::IAtomicInteger64Array*)__pNewObj->Probe(Elastos::Utility::Concurrent::Atomic::EIID_IAtomicInteger64Array);
        if (*__IAtomicInteger64Array) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int64> & other,
        /* [out] */ Elastos::Utility::Concurrent::Atomic::IAtomicInteger64Array** __IAtomicInteger64Array)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(other, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAtomicInteger64Array = (Elastos::Utility::Concurrent::Atomic::IAtomicInteger64Array*)__pNewObj->Probe(Elastos::Utility::Concurrent::Atomic::EIID_IAtomicInteger64Array);
        if (*__IAtomicInteger64Array) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int64> & other,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(other, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int64> & other,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(other, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int64> & other,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(other, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int64> & other,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(other, &__pNewObj);
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
namespace Utility {
namespace Concurrent {
namespace Atomic {
class CAtomicMarkableReference
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ IInterface * initialRef,
        /* [in] */ _ELASTOS Boolean initialMark,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAtomicMarkableReferenceClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAtomicMarkableReference, RGM_SAME_DOMAIN,
                EIID_ICAtomicMarkableReferenceClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithInitialRefInitialMark(initialRef, initialMark, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * initialRef,
        /* [in] */ _ELASTOS Boolean initialMark,
        /* [out] */ Elastos::Utility::Concurrent::Atomic::IAtomicMarkableReference** __IAtomicMarkableReference)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialRef, initialMark, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAtomicMarkableReference = (Elastos::Utility::Concurrent::Atomic::IAtomicMarkableReference*)__pNewObj->Probe(Elastos::Utility::Concurrent::Atomic::EIID_IAtomicMarkableReference);
        if (*__IAtomicMarkableReference) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * initialRef,
        /* [in] */ _ELASTOS Boolean initialMark,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialRef, initialMark, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * initialRef,
        /* [in] */ _ELASTOS Boolean initialMark,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialRef, initialMark, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * initialRef,
        /* [in] */ _ELASTOS Boolean initialMark,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialRef, initialMark, &__pNewObj);
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
namespace Utility {
namespace Concurrent {
namespace Atomic {
class CAtomicReference
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ IInterface * initialValue,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAtomicReferenceClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAtomicReference, RGM_SAME_DOMAIN,
                EIID_ICAtomicReferenceClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithInitialValue(initialValue, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::Atomic::IAtomicReference** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAtomicReference, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::Atomic::EIID_IAtomicReference, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAtomicReference, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAtomicReference, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAtomicReference, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAtomicReference, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * initialValue,
        /* [out] */ Elastos::Utility::Concurrent::Atomic::IAtomicReference** __IAtomicReference)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAtomicReference = (Elastos::Utility::Concurrent::Atomic::IAtomicReference*)__pNewObj->Probe(Elastos::Utility::Concurrent::Atomic::EIID_IAtomicReference);
        if (*__IAtomicReference) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * initialValue,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * initialValue,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * initialValue,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * initialValue,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialValue, &__pNewObj);
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
namespace Utility {
namespace Concurrent {
namespace Atomic {
class CAtomicReferenceArray
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAtomicReferenceArrayClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAtomicReferenceArray, RGM_SAME_DOMAIN,
                EIID_ICAtomicReferenceArrayClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithLength(length, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS ArrayOf<IInterface *> & array,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAtomicReferenceArrayClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAtomicReferenceArray, RGM_SAME_DOMAIN,
                EIID_ICAtomicReferenceArrayClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithArray(array, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::Utility::Concurrent::Atomic::IAtomicReferenceArray** __IAtomicReferenceArray)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAtomicReferenceArray = (Elastos::Utility::Concurrent::Atomic::IAtomicReferenceArray*)__pNewObj->Probe(Elastos::Utility::Concurrent::Atomic::EIID_IAtomicReferenceArray);
        if (*__IAtomicReferenceArray) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<IInterface *> & array,
        /* [out] */ Elastos::Utility::Concurrent::Atomic::IAtomicReferenceArray** __IAtomicReferenceArray)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAtomicReferenceArray = (Elastos::Utility::Concurrent::Atomic::IAtomicReferenceArray*)__pNewObj->Probe(Elastos::Utility::Concurrent::Atomic::EIID_IAtomicReferenceArray);
        if (*__IAtomicReferenceArray) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<IInterface *> & array,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<IInterface *> & array,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<IInterface *> & array,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<IInterface *> & array,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
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
namespace Utility {
namespace Concurrent {
namespace Atomic {
class CAtomicStampedReference
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ IInterface * initialRef,
        /* [in] */ _ELASTOS Int32 initialStamp,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAtomicStampedReferenceClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAtomicStampedReference, RGM_SAME_DOMAIN,
                EIID_ICAtomicStampedReferenceClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithInitialRefInitialStamp(initialRef, initialStamp, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * initialRef,
        /* [in] */ _ELASTOS Int32 initialStamp,
        /* [out] */ Elastos::Utility::Concurrent::Atomic::IAtomicStampedReference** __IAtomicStampedReference)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialRef, initialStamp, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAtomicStampedReference = (Elastos::Utility::Concurrent::Atomic::IAtomicStampedReference*)__pNewObj->Probe(Elastos::Utility::Concurrent::Atomic::EIID_IAtomicStampedReference);
        if (*__IAtomicStampedReference) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * initialRef,
        /* [in] */ _ELASTOS Int32 initialStamp,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialRef, initialStamp, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * initialRef,
        /* [in] */ _ELASTOS Int32 initialStamp,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialRef, initialStamp, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * initialRef,
        /* [in] */ _ELASTOS Int32 initialStamp,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialRef, initialStamp, &__pNewObj);
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
namespace Utility {
namespace Concurrent {
namespace Atomic {
class CFences
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Utility::Concurrent::Atomic::IFences** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFences, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::Atomic::EIID_IFences, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFences, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFences, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFences, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Locks {
class CLockSupport
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Utility::Concurrent::Locks::ILockSupport** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLockSupport, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::Locks::EIID_ILockSupport, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLockSupport, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLockSupport, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLockSupport, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
}
namespace Elastos {
namespace Utility {
namespace Concurrent {
namespace Locks {
class CReentrantLock
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICReentrantLockClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CReentrantLock, RGM_SAME_DOMAIN,
                EIID_ICReentrantLockClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFair(fair, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::Locks::IReentrantLock** __object)
    {
        return _CObject_CreateInstance(ECLSID_CReentrantLock, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::Locks::EIID_IReentrantLock, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::Locks::ILock** __object)
    {
        return _CObject_CreateInstance(ECLSID_CReentrantLock, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::Locks::EIID_ILock, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CReentrantLock, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CReentrantLock, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CReentrantLock, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CReentrantLock, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ Elastos::Utility::Concurrent::Locks::IReentrantLock** __IReentrantLock)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fair, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReentrantLock = (Elastos::Utility::Concurrent::Locks::IReentrantLock*)__pNewObj->Probe(Elastos::Utility::Concurrent::Locks::EIID_IReentrantLock);
        if (*__IReentrantLock) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ Elastos::Utility::Concurrent::Locks::ILock** __ILock)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fair, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ILock = (Elastos::Utility::Concurrent::Locks::ILock*)__pNewObj->Probe(Elastos::Utility::Concurrent::Locks::EIID_ILock);
        if (*__ILock) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fair, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fair, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fair, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fair, &__pNewObj);
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
namespace Utility {
namespace Concurrent {
namespace Locks {
class CReentrantReadWriteLock
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICReentrantReadWriteLockClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CReentrantReadWriteLock, RGM_SAME_DOMAIN,
                EIID_ICReentrantReadWriteLockClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFair(fair, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::Locks::IReentrantReadWriteLock** __object)
    {
        return _CObject_CreateInstance(ECLSID_CReentrantReadWriteLock, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::Locks::EIID_IReentrantReadWriteLock, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::Concurrent::Locks::IReadWriteLock** __object)
    {
        return _CObject_CreateInstance(ECLSID_CReentrantReadWriteLock, RGM_SAME_DOMAIN, Elastos::Utility::Concurrent::Locks::EIID_IReadWriteLock, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CReentrantReadWriteLock, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CReentrantReadWriteLock, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CReentrantReadWriteLock, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CReentrantReadWriteLock, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ Elastos::Utility::Concurrent::Locks::IReentrantReadWriteLock** __IReentrantReadWriteLock)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fair, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReentrantReadWriteLock = (Elastos::Utility::Concurrent::Locks::IReentrantReadWriteLock*)__pNewObj->Probe(Elastos::Utility::Concurrent::Locks::EIID_IReentrantReadWriteLock);
        if (*__IReentrantReadWriteLock) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ Elastos::Utility::Concurrent::Locks::IReadWriteLock** __IReadWriteLock)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fair, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IReadWriteLock = (Elastos::Utility::Concurrent::Locks::IReadWriteLock*)__pNewObj->Probe(Elastos::Utility::Concurrent::Locks::EIID_IReadWriteLock);
        if (*__IReadWriteLock) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fair, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fair, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fair, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fair, &__pNewObj);
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
namespace Utility {
namespace Concurrent {
class CSemaphore
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 permits,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSemaphoreClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSemaphore, RGM_SAME_DOMAIN,
                EIID_ICSemaphoreClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPermits(permits, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 permits,
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSemaphoreClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSemaphore, RGM_SAME_DOMAIN,
                EIID_ICSemaphoreClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPermitsFair(permits, fair, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 permits,
        /* [out] */ Elastos::Utility::Concurrent::ISemaphore** __ISemaphore)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(permits, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISemaphore = (Elastos::Utility::Concurrent::ISemaphore*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_ISemaphore);
        if (*__ISemaphore) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 permits,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(permits, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 permits,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(permits, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 permits,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(permits, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 permits,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(permits, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 permits,
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ Elastos::Utility::Concurrent::ISemaphore** __ISemaphore)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(permits, fair, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISemaphore = (Elastos::Utility::Concurrent::ISemaphore*)__pNewObj->Probe(Elastos::Utility::Concurrent::EIID_ISemaphore);
        if (*__ISemaphore) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 permits,
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(permits, fair, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 permits,
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(permits, fair, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 permits,
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(permits, fair, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 permits,
        /* [in] */ _ELASTOS Boolean fair,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(permits, fair, &__pNewObj);
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

#endif // __Elastos_CoreLibrary_Utility_Concurrent_h__
