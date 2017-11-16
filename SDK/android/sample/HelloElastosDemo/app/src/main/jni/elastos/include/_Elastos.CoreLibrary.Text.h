#ifndef ___Elastos_CoreLibrary_Text_h__
#define ___Elastos_CoreLibrary_Text_h__

#include <Elastos.CoreLibrary.h>

EXTERN_C ELAPI _Impl_AcquireCallbackHandler(PInterface pServerObj, _ELASTOS REIID iid, PInterface *ppHandler);
EXTERN_C ELAPI _Impl_CheckClsId(PInterface pServerObj, const _ELASTOS ClassID* pClassid, PInterface *ppServerObj);

namespace Elastos {
namespace Text {
CAR_INTERFACE("EF392955-8292-4C18-29FF-705052868D1F")
IAnnotation : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAnnotation*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAnnotation*)pObj->Probe(EIID_IAnnotation);
    }

    static CARAPI_(IAnnotation*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAnnotation*)pObj->Probe(EIID_IAnnotation);
    }

    virtual CARAPI GetValue(
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("39E85E38-9712-0C13-5690-A841C2C48DFB")
IAttributedCharacterIteratorAttribute : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAttributedCharacterIteratorAttribute*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttributedCharacterIteratorAttribute*)pObj->Probe(EIID_IAttributedCharacterIteratorAttribute);
    }

    static CARAPI_(IAttributedCharacterIteratorAttribute*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttributedCharacterIteratorAttribute*)pObj->Probe(EIID_IAttributedCharacterIteratorAttribute);
    }

    virtual CARAPI GetName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI ReadResolve(
        /* [out] */ IInterface ** resolve) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * obj,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("B112653B-9712-0C13-5690-A841C2C48DFB")
IAttributedCharacterIteratorAttributeHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAttributedCharacterIteratorAttributeHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttributedCharacterIteratorAttributeHelper*)pObj->Probe(EIID_IAttributedCharacterIteratorAttributeHelper);
    }

    static CARAPI_(IAttributedCharacterIteratorAttributeHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttributedCharacterIteratorAttributeHelper*)pObj->Probe(EIID_IAttributedCharacterIteratorAttributeHelper);
    }

    virtual CARAPI GetINPUT_METHOD_SEGMENT(
        /* [out] */ Elastos::Text::IAttributedCharacterIteratorAttribute ** attr) = 0;

    virtual CARAPI GetLANGUAGE(
        /* [out] */ Elastos::Text::IAttributedCharacterIteratorAttribute ** attr) = 0;

    virtual CARAPI GetREADING(
        /* [out] */ Elastos::Text::IAttributedCharacterIteratorAttribute ** attr) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("B2049839-9712-0C13-5690-A841C2C48DFB")
IAttributedCharacterIterator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAttributedCharacterIterator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttributedCharacterIterator*)pObj->Probe(EIID_IAttributedCharacterIterator);
    }

    static CARAPI_(IAttributedCharacterIterator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttributedCharacterIterator*)pObj->Probe(EIID_IAttributedCharacterIterator);
    }

    virtual CARAPI GetAllAttributeKeys(
        /* [out] */ Elastos::Utility::ISet ** allAttrKeys) = 0;

    virtual CARAPI GetAttribute(
        /* [in] */ Elastos::Text::IAttributedCharacterIteratorAttribute * attribute,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI GetAttributes(
        /* [out] */ Elastos::Utility::IMap ** map) = 0;

    virtual CARAPI GetRunLimit(
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetRunLimit(
        /* [in] */ Elastos::Text::IAttributedCharacterIteratorAttribute * attribute,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetRunLimit(
        /* [in] */ Elastos::Utility::ISet * attributes,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetRunStart(
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetRunStart(
        /* [in] */ Elastos::Text::IAttributedCharacterIteratorAttribute * attribute,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetRunStart(
        /* [in] */ Elastos::Utility::ISet * attributes,
        /* [out] */ _ELASTOS Int32 * index) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("E8236538-9712-B013-7FB4-B77143868D1F")
IAttributedString : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAttributedString*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttributedString*)pObj->Probe(EIID_IAttributedString);
    }

    static CARAPI_(IAttributedString*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttributedString*)pObj->Probe(EIID_IAttributedString);
    }

    virtual CARAPI AddAttribute(
        /* [in] */ Elastos::Text::IAttributedCharacterIteratorAttribute * attribute,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI AddAttribute(
        /* [in] */ Elastos::Text::IAttributedCharacterIteratorAttribute * attribute,
        /* [in] */ IInterface * value,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end) = 0;

    virtual CARAPI AddAttributes(
        /* [in] */ Elastos::Utility::IMap * attributes,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end) = 0;

    virtual CARAPI GetIterator(
        /* [out] */ Elastos::Text::IAttributedCharacterIterator ** iterator) = 0;

    virtual CARAPI GetIterator(
        /* [in] */ _ELASTOS ArrayOf<Elastos::Text::IAttributedCharacterIteratorAttribute *> * attributes,
        /* [out] */ Elastos::Text::IAttributedCharacterIterator ** iterator) = 0;

    virtual CARAPI GetIterator(
        /* [in] */ _ELASTOS ArrayOf<Elastos::Text::IAttributedCharacterIteratorAttribute *> * attributes,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ Elastos::Text::IAttributedCharacterIterator ** iterator) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("DF389E03-C2D2-EC9E-EFBC-A47DCBF6DFA1")
IBidi : public IInterface
{
    static const _ELASTOS Int32 DIRECTION_DEFAULT_LEFT_TO_RIGHT = -2;
    static const _ELASTOS Int32 DIRECTION_DEFAULT_RIGHT_TO_LEFT = -1;
    static const _ELASTOS Int32 DIRECTION_LEFT_TO_RIGHT = 0;
    static const _ELASTOS Int32 DIRECTION_RIGHT_TO_LEFT = 1;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBidi*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBidi*)pObj->Probe(EIID_IBidi);
    }

    static CARAPI_(IBidi*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBidi*)pObj->Probe(EIID_IBidi);
    }

    virtual CARAPI BaseIsLeftToRight(
        /* [out] */ _ELASTOS Boolean * baseLevel) = 0;

    virtual CARAPI CreateLineBidi(
        /* [in] */ _ELASTOS Int32 lineStart,
        /* [in] */ _ELASTOS Int32 lineLimit,
        /* [out] */ Elastos::Text::IBidi ** object) = 0;

    virtual CARAPI GetBaseLevel(
        /* [out] */ _ELASTOS Int32 * baseLevel) = 0;

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int32 * length) = 0;

    virtual CARAPI GetLevelAt(
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ _ELASTOS Int32 * level) = 0;

    virtual CARAPI GetRunCount(
        /* [out] */ _ELASTOS Int32 * runCount) = 0;

    virtual CARAPI GetRunLevel(
        /* [in] */ _ELASTOS Int32 run,
        /* [out] */ _ELASTOS Int32 * runLevel) = 0;

    virtual CARAPI GetRunLimit(
        /* [in] */ _ELASTOS Int32 run,
        /* [out] */ _ELASTOS Int32 * limitOffset) = 0;

    virtual CARAPI GetRunStart(
        /* [in] */ _ELASTOS Int32 run,
        /* [out] */ _ELASTOS Int32 * startOffset) = 0;

    virtual CARAPI IsLeftToRight(
        /* [out] */ _ELASTOS Boolean * isLefttoRight) = 0;

    virtual CARAPI IsMixed(
        /* [out] */ _ELASTOS Boolean * isMixed) = 0;

    virtual CARAPI IsRightToLeft(
        /* [out] */ _ELASTOS Boolean * isRightToLeft) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("C802340F-C2D2-6C9E-84BE-335AFFCE4BDA")
IBidiHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBidiHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBidiHelper*)pObj->Probe(EIID_IBidiHelper);
    }

    static CARAPI_(IBidiHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBidiHelper*)pObj->Probe(EIID_IBidiHelper);
    }

    virtual CARAPI ReorderVisually(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * levels,
        /* [in] */ _ELASTOS Int32 levelStart,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * objects,
        /* [in] */ _ELASTOS Int32 objectStart,
        /* [in] */ _ELASTOS Int32 count) = 0;

    virtual CARAPI RequiresBidi(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * text,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 limit,
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("1371851B-52D2-A4A3-2BDD-684DDE72FD3B")
IBreakIterator : public IInterface
{
    static const _ELASTOS Int32 DONE = -1;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBreakIterator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBreakIterator*)pObj->Probe(EIID_IBreakIterator);
    }

    static CARAPI_(IBreakIterator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBreakIterator*)pObj->Probe(EIID_IBreakIterator);
    }

    virtual CARAPI IsBoundary(
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ _ELASTOS Boolean * isBoundary) = 0;

    virtual CARAPI GetPreceding(
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ _ELASTOS Int32 * postion) = 0;

    virtual CARAPI SetText(
        /* [in] */ const _ELASTOS String& newText) = 0;

    virtual CARAPI GetCurrent(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetFirst(
        /* [out] */ _ELASTOS Int32 * postion) = 0;

    virtual CARAPI GetFollowing(
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ _ELASTOS Int32 * postion) = 0;

    virtual CARAPI GetText(
        /* [out] */ Elastos::Text::ICharacterIterator ** text) = 0;

    virtual CARAPI GetLast(
        /* [out] */ _ELASTOS Int32 * postion) = 0;

    virtual CARAPI GetNext(
        /* [out] */ _ELASTOS Int32 * postion) = 0;

    virtual CARAPI GetNext(
        /* [in] */ _ELASTOS Int32 n,
        /* [out] */ _ELASTOS Int32 * postion) = 0;

    virtual CARAPI GetPrevious(
        /* [out] */ _ELASTOS Int32 * postion) = 0;

    virtual CARAPI SetText(
        /* [in] */ Elastos::Text::ICharacterIterator * newText) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("47B1BF09-52D2-A4A3-2BDD-684DDE721DA1")
IBreakIteratorHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBreakIteratorHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBreakIteratorHelper*)pObj->Probe(EIID_IBreakIteratorHelper);
    }

    static CARAPI_(IBreakIteratorHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBreakIteratorHelper*)pObj->Probe(EIID_IBreakIteratorHelper);
    }

    virtual CARAPI GetAvailableLocales(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Utility::ILocale *> ** locales) = 0;

    virtual CARAPI GetCharacterInstance(
        /* [out] */ Elastos::Text::IBreakIterator ** instance) = 0;

    virtual CARAPI GetCharacterInstance(
        /* [in] */ Elastos::Utility::ILocale * where,
        /* [out] */ Elastos::Text::IBreakIterator ** instance) = 0;

    virtual CARAPI GetLineInstance(
        /* [out] */ Elastos::Text::IBreakIterator ** instance) = 0;

    virtual CARAPI GetLineInstance(
        /* [in] */ Elastos::Utility::ILocale * where,
        /* [out] */ Elastos::Text::IBreakIterator ** instance) = 0;

    virtual CARAPI GetSentenceInstance(
        /* [out] */ Elastos::Text::IBreakIterator ** instance) = 0;

    virtual CARAPI GetSentenceInstance(
        /* [in] */ Elastos::Utility::ILocale * where,
        /* [out] */ Elastos::Text::IBreakIterator ** instance) = 0;

    virtual CARAPI GetWordInstance(
        /* [out] */ Elastos::Text::IBreakIterator ** instance) = 0;

    virtual CARAPI GetWordInstance(
        /* [in] */ Elastos::Utility::ILocale * where,
        /* [out] */ Elastos::Text::IBreakIterator ** instance) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("3DE67359-90D2-2444-5E3D-9390F9D1D51F")
ICharacterIterator : public IInterface
{
    static const _ELASTOS Char32 DONE = 0xffffffff;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICharacterIterator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharacterIterator*)pObj->Probe(EIID_ICharacterIterator);
    }

    static CARAPI_(ICharacterIterator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharacterIterator*)pObj->Probe(EIID_ICharacterIterator);
    }

    virtual CARAPI GetCurrent(
        /* [out] */ _ELASTOS Char32 * character) = 0;

    virtual CARAPI GetFirst(
        /* [out] */ _ELASTOS Char32 * character) = 0;

    virtual CARAPI GetBeginIndex(
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetEndIndex(
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetIndex(
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetLast(
        /* [out] */ _ELASTOS Char32 * character) = 0;

    virtual CARAPI GetNext(
        /* [out] */ _ELASTOS Char32 * character) = 0;

    virtual CARAPI GetPrevious(
        /* [out] */ _ELASTOS Char32 * character) = 0;

    virtual CARAPI SetIndex(
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ _ELASTOS Char32 * character) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("B2294D1E-B312-ACCA-893E-720D93F7EFBC")
IChoiceFormat : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IChoiceFormat*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IChoiceFormat*)pObj->Probe(EIID_IChoiceFormat);
    }

    static CARAPI_(IChoiceFormat*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IChoiceFormat*)pObj->Probe(EIID_IChoiceFormat);
    }

    virtual CARAPI ApplyPattern(
        /* [in] */ const _ELASTOS String& tem) = 0;

    virtual CARAPI GetFormats(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** formats) = 0;

    virtual CARAPI GetLimits(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Double> ** limits) = 0;

    virtual CARAPI SetChoices(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Double> * limits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * formats) = 0;

    virtual CARAPI ToPattern(
        /* [out] */ _ELASTOS String * pattern) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("349C431C-B312-ACCA-893E-720D937784BE")
IChoiceFormatHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IChoiceFormatHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IChoiceFormatHelper*)pObj->Probe(EIID_IChoiceFormatHelper);
    }

    static CARAPI_(IChoiceFormatHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IChoiceFormatHelper*)pObj->Probe(EIID_IChoiceFormatHelper);
    }

    virtual CARAPI NextDouble(
        /* [in] */ _ELASTOS Double value,
        /* [out] */ _ELASTOS Double * nextValue) = 0;

    virtual CARAPI NextDouble(
        /* [in] */ _ELASTOS Double value,
        /* [in] */ _ELASTOS Boolean increment,
        /* [out] */ _ELASTOS Double * nextValue) = 0;

    virtual CARAPI PreviousDouble(
        /* [in] */ _ELASTOS Double value,
        /* [out] */ _ELASTOS Double * previousValue) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("9C346D46-9152-9D96-1DA4-D42921F3A3AB")
ICollationElementIterator : public IInterface
{
    static const _ELASTOS Int32 NULLORDER = -1;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICollationElementIterator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollationElementIterator*)pObj->Probe(EIID_ICollationElementIterator);
    }

    static CARAPI_(ICollationElementIterator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollationElementIterator*)pObj->Probe(EIID_ICollationElementIterator);
    }

    virtual CARAPI GetMaxExpansion(
        /* [in] */ _ELASTOS Int32 order,
        /* [out] */ _ELASTOS Int32 * maxExpansion) = 0;

    virtual CARAPI GetOffset(
        /* [out] */ _ELASTOS Int32 * offset) = 0;

    virtual CARAPI GetNext(
        /* [out] */ _ELASTOS Int32 * nextValue) = 0;

    virtual CARAPI GetPrevious(
        /* [out] */ _ELASTOS Int32 * previousValue) = 0;

    virtual CARAPI Reset() = 0;

    virtual CARAPI SetOffset(
        /* [in] */ _ELASTOS Int32 newOffset) = 0;

    virtual CARAPI SetText(
        /* [in] */ Elastos::Text::ICharacterIterator * source) = 0;

    virtual CARAPI SetText(
        /* [in] */ const _ELASTOS String& source) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("A0FB5451-9152-9D96-1DA4-D42921F3A3AB")
ICollationElementIteratorHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICollationElementIteratorHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollationElementIteratorHelper*)pObj->Probe(EIID_ICollationElementIteratorHelper);
    }

    static CARAPI_(ICollationElementIteratorHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollationElementIteratorHelper*)pObj->Probe(EIID_ICollationElementIteratorHelper);
    }

    virtual CARAPI PrimaryOrder(
        /* [in] */ _ELASTOS Int32 order,
        /* [out] */ _ELASTOS Int32 * primaryOrder) = 0;

    virtual CARAPI SecondaryOrder(
        /* [in] */ _ELASTOS Int32 order,
        /* [out] */ _ELASTOS Int16 * secondaryOrder) = 0;

    virtual CARAPI TertiaryOrder(
        /* [in] */ _ELASTOS Int32 order,
        /* [out] */ _ELASTOS Int16 * tertiaryOrder) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("48223552-9152-9D96-2958-FBE1A0A40C1B")
ICollationKey : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICollationKey*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollationKey*)pObj->Probe(EIID_ICollationKey);
    }

    static CARAPI_(ICollationKey*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollationKey*)pObj->Probe(EIID_ICollationKey);
    }

    virtual CARAPI GetSourceString(
        /* [out] */ _ELASTOS String * sourceString) = 0;

    virtual CARAPI ToByteArray(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** array) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("9168764D-9152-A796-7F38-2829C3C68F0E")
ICollator : public IInterface
{
    static const _ELASTOS Int32 NO_DECOMPOSITION = 0;
    static const _ELASTOS Int32 CANONICAL_DECOMPOSITION = 1;
    static const _ELASTOS Int32 FULL_DECOMPOSITION = 2;
    static const _ELASTOS Int32 PRIMARY = 0;
    static const _ELASTOS Int32 SECONDARY = 1;
    static const _ELASTOS Int32 TERTIARY = 2;
    static const _ELASTOS Int32 IDENTICAL = 3;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICollator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollator*)pObj->Probe(EIID_ICollator);
    }

    static CARAPI_(ICollator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollator*)pObj->Probe(EIID_ICollator);
    }

    virtual CARAPI Compare(
        /* [in] */ IInterface * object1,
        /* [in] */ IInterface * object2,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI Compare(
        /* [in] */ const _ELASTOS String& string1,
        /* [in] */ const _ELASTOS String& string2,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Equals(
        /* [in] */ const _ELASTOS String& string1,
        /* [in] */ const _ELASTOS String& string2,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetCollationKey(
        /* [in] */ const _ELASTOS String& string,
        /* [out] */ Elastos::Text::ICollationKey ** collationKey) = 0;

    virtual CARAPI GetDecomposition(
        /* [out] */ _ELASTOS Int32 * decomposition) = 0;

    virtual CARAPI GetStrength(
        /* [out] */ _ELASTOS Int32 * strength) = 0;

    virtual CARAPI SetDecomposition(
        /* [in] */ _ELASTOS Int32 value) = 0;

    virtual CARAPI SetStrength(
        /* [in] */ _ELASTOS Int32 value) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("8C554656-9152-A796-23A0-7811B6C60F07")
ICollatorHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICollatorHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollatorHelper*)pObj->Probe(EIID_ICollatorHelper);
    }

    static CARAPI_(ICollatorHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollatorHelper*)pObj->Probe(EIID_ICollatorHelper);
    }

    virtual CARAPI GetAvailableLocales(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Utility::ILocale *> ** locales) = 0;

    virtual CARAPI GetInstance(
        /* [out] */ Elastos::Text::ICollator ** instance) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Text::ICollator ** instance) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("9D132E4F-8352-0F46-AEE6-BCF1C0E0C91F")
IDateFormatField : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDateFormatField*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDateFormatField*)pObj->Probe(EIID_IDateFormatField);
    }

    static CARAPI_(IDateFormatField*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDateFormatField*)pObj->Probe(EIID_IDateFormatField);
    }

    virtual CARAPI GetCalendarField(
        /* [out] */ _ELASTOS Int32 * field) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("84054B5C-8352-0F46-AEE6-BCF1C0E0C908")
IDateFormatFieldHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDateFormatFieldHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDateFormatFieldHelper*)pObj->Probe(EIID_IDateFormatFieldHelper);
    }

    static CARAPI_(IDateFormatFieldHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDateFormatFieldHelper*)pObj->Probe(EIID_IDateFormatFieldHelper);
    }

    virtual CARAPI GetDateFormatFieldByName(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Text::IDateFormatField ** field) = 0;

    virtual CARAPI OfCalendarField(
        /* [in] */ _ELASTOS Int32 calendarField,
        /* [out] */ Elastos::Text::IDateFormatField ** field) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("FF2D8C2D-A652-306E-48DC-F8D1DEC60D19")
IDateFormat : public IInterface
{
    static const _ELASTOS Int32 DEFAULT = 2;
    static const _ELASTOS Int32 FULL = 0;
    static const _ELASTOS Int32 LONG = 1;
    static const _ELASTOS Int32 MEDIUM = 2;
    static const _ELASTOS Int32 SHORT = 3;
    static const _ELASTOS Int32 ERA_FIELD = 0;
    static const _ELASTOS Int32 YEAR_FIELD = 1;
    static const _ELASTOS Int32 MONTH_FIELD = 2;
    static const _ELASTOS Int32 DATE_FIELD = 3;
    static const _ELASTOS Int32 HOUR_OF_DAY1_FIELD = 4;
    static const _ELASTOS Int32 HOUR_OF_DAY0_FIELD = 5;
    static const _ELASTOS Int32 MINUTE_FIELD = 6;
    static const _ELASTOS Int32 SECOND_FIELD = 7;
    static const _ELASTOS Int32 MILLISECOND_FIELD = 8;
    static const _ELASTOS Int32 DAY_OF_WEEK_FIELD = 9;
    static const _ELASTOS Int32 DAY_OF_YEAR_FIELD = 10;
    static const _ELASTOS Int32 DAY_OF_WEEK_IN_MONTH_FIELD = 11;
    static const _ELASTOS Int32 WEEK_OF_YEAR_FIELD = 12;
    static const _ELASTOS Int32 WEEK_OF_MONTH_FIELD = 13;
    static const _ELASTOS Int32 AM_PM_FIELD = 14;
    static const _ELASTOS Int32 HOUR1_FIELD = 15;
    static const _ELASTOS Int32 HOUR0_FIELD = 16;
    static const _ELASTOS Int32 TIMEZONE_FIELD = 17;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDateFormat*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDateFormat*)pObj->Probe(EIID_IDateFormat);
    }

    static CARAPI_(IDateFormat*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDateFormat*)pObj->Probe(EIID_IDateFormat);
    }

    virtual CARAPI Format(
        /* [in] */ Elastos::Utility::IDate * date,
        /* [out] */ _ELASTOS String * result) = 0;

    virtual CARAPI Format(
        /* [in] */ Elastos::Utility::IDate * date,
        /* [in] */ Elastos::Core::IStringBuffer * buffer,
        /* [in] */ Elastos::Text::IFieldPosition * field) = 0;

    virtual CARAPI GetCalendar(
        /* [out] */ Elastos::Utility::ICalendar ** calendar) = 0;

    virtual CARAPI GetNumberFormat(
        /* [out] */ Elastos::Text::INumberFormat ** format) = 0;

    virtual CARAPI GetTimeZone(
        /* [out] */ Elastos::Utility::ITimeZone ** timezone) = 0;

    virtual CARAPI IsLenient(
        /* [out] */ _ELASTOS Boolean * isLenient) = 0;

    virtual CARAPI Parse(
        /* [in] */ const _ELASTOS String& string,
        /* [out] */ Elastos::Utility::IDate ** date) = 0;

    virtual CARAPI Parse(
        /* [in] */ const _ELASTOS String& string,
        /* [in] */ Elastos::Text::IParsePosition * position,
        /* [out] */ Elastos::Utility::IDate ** date) = 0;

    virtual CARAPI SetCalendar(
        /* [in] */ Elastos::Utility::ICalendar * cal) = 0;

    virtual CARAPI SetLenient(
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI SetNumberFormat(
        /* [in] */ Elastos::Text::INumberFormat * format) = 0;

    virtual CARAPI SetTimeZone(
        /* [in] */ Elastos::Utility::ITimeZone * timezone) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("724AE126-A652-306E-48DC-8880E2C58CFB")
IDateFormatHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDateFormatHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDateFormatHelper*)pObj->Probe(EIID_IDateFormatHelper);
    }

    static CARAPI_(IDateFormatHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDateFormatHelper*)pObj->Probe(EIID_IDateFormatHelper);
    }

    virtual CARAPI GetAvailableLocales(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Utility::ILocale *> ** locales) = 0;

    virtual CARAPI GetDateInstance(
        /* [out] */ Elastos::Text::IDateFormat ** instance) = 0;

    virtual CARAPI GetDateInstance(
        /* [in] */ _ELASTOS Int32 style,
        /* [out] */ Elastos::Text::IDateFormat ** instance) = 0;

    virtual CARAPI GetDateInstance(
        /* [in] */ _ELASTOS Int32 style,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Text::IDateFormat ** instance) = 0;

    virtual CARAPI GetDateTimeInstance(
        /* [out] */ Elastos::Text::IDateFormat ** instance) = 0;

    virtual CARAPI GetDateTimeInstance(
        /* [in] */ _ELASTOS Int32 dateStyle,
        /* [in] */ _ELASTOS Int32 timeStyle,
        /* [out] */ Elastos::Text::IDateFormat ** instance) = 0;

    virtual CARAPI GetDateTimeInstance(
        /* [in] */ _ELASTOS Int32 dateStyle,
        /* [in] */ _ELASTOS Int32 timeStyle,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Text::IDateFormat ** instance) = 0;

    virtual CARAPI Set24HourTimePref(
        /* [in] */ _ELASTOS Boolean is24Hour) = 0;

    virtual CARAPI GetInstance(
        /* [out] */ Elastos::Text::IDateFormat ** instance) = 0;

    virtual CARAPI GetTimeInstance(
        /* [out] */ Elastos::Text::IDateFormat ** instance) = 0;

    virtual CARAPI GetTimeInstance(
        /* [in] */ _ELASTOS Int32 style,
        /* [out] */ Elastos::Text::IDateFormat ** instance) = 0;

    virtual CARAPI GetTimeInstance(
        /* [in] */ _ELASTOS Int32 style,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Text::IDateFormat ** instance) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("ECD5F224-A652-306E-48DC-B06DE3477B1B")
IDateFormatSymbols : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDateFormatSymbols*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDateFormatSymbols*)pObj->Probe(EIID_IDateFormatSymbols);
    }

    static CARAPI_(IDateFormatSymbols*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDateFormatSymbols*)pObj->Probe(EIID_IDateFormatSymbols);
    }

    virtual CARAPI GetAmPmStrings(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** amPmStrings) = 0;

    virtual CARAPI GetEras(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** eras) = 0;

    virtual CARAPI GetLocalPatternChars(
        /* [out] */ _ELASTOS String * localPatternChars) = 0;

    virtual CARAPI GetMonths(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** months) = 0;

    virtual CARAPI GetShortMonths(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** shortMonths) = 0;

    virtual CARAPI GetShortWeekdays(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** shortWeekdays) = 0;

    virtual CARAPI GetWeekdays(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** weekdays) = 0;

    virtual CARAPI GetZoneStrings(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Core::IArrayOf *> ** outarray) = 0;

    virtual CARAPI SetAmPmStrings(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * data) = 0;

    virtual CARAPI SetEras(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * data) = 0;

    virtual CARAPI SetLocalPatternChars(
        /* [in] */ const _ELASTOS String& data) = 0;

    virtual CARAPI SetMonths(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * data) = 0;

    virtual CARAPI SetShortMonths(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * data) = 0;

    virtual CARAPI SetShortWeekdays(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * data) = 0;

    virtual CARAPI SetWeekdays(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * data) = 0;

    virtual CARAPI SetZoneStrings(
        /* [in] */ _ELASTOS ArrayOf<Elastos::Core::IArrayOf *> * zoneStrings) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("77D64F39-A652-306E-48DC-B06D23028A17")
IDateFormatSymbolsHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDateFormatSymbolsHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDateFormatSymbolsHelper*)pObj->Probe(EIID_IDateFormatSymbolsHelper);
    }

    static CARAPI_(IDateFormatSymbolsHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDateFormatSymbolsHelper*)pObj->Probe(EIID_IDateFormatSymbolsHelper);
    }

    virtual CARAPI GetInstance(
        /* [out] */ Elastos::Text::IDateFormatSymbols ** instance) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Text::IDateFormatSymbols ** instance) = 0;

    virtual CARAPI GetAvailableLocales(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Utility::ILocale *> ** arrayOfLocales) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("46D5EC1E-8352-2C9A-4CBE-8F5CC3E4FD3B")
IDecimalFormat : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDecimalFormat*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDecimalFormat*)pObj->Probe(EIID_IDecimalFormat);
    }

    static CARAPI_(IDecimalFormat*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDecimalFormat*)pObj->Probe(EIID_IDecimalFormat);
    }

    virtual CARAPI ApplyLocalizedPattern(
        /* [in] */ const _ELASTOS String& pattern) = 0;

    virtual CARAPI ApplyPattern(
        /* [in] */ const _ELASTOS String& pattern) = 0;

    virtual CARAPI GetDecimalFormatSymbols(
        /* [out] */ Elastos::Text::IDecimalFormatSymbols ** symbols) = 0;

    virtual CARAPI GetGroupingSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetNegativePrefix(
        /* [out] */ _ELASTOS String * prefix) = 0;

    virtual CARAPI GetNegativeSuffix(
        /* [out] */ _ELASTOS String * suffix) = 0;

    virtual CARAPI GetPositivePrefix(
        /* [out] */ _ELASTOS String * prefix) = 0;

    virtual CARAPI GetPositiveSuffix(
        /* [out] */ _ELASTOS String * suffix) = 0;

    virtual CARAPI IsDecimalSeparatorAlwaysShown(
        /* [out] */ _ELASTOS Boolean * shown) = 0;

    virtual CARAPI IsParseBigDecimal(
        /* [out] */ _ELASTOS Boolean * isBigDecimal) = 0;

    virtual CARAPI SetDecimalFormatSymbols(
        /* [in] */ Elastos::Text::IDecimalFormatSymbols * value) = 0;

    virtual CARAPI SetDecimalSeparatorAlwaysShown(
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI SetGroupingSize(
        /* [in] */ _ELASTOS Int32 value) = 0;

    virtual CARAPI GetMultiplier(
        /* [out] */ _ELASTOS Int32 * multiplier) = 0;

    virtual CARAPI SetMultiplier(
        /* [in] */ _ELASTOS Int32 value) = 0;

    virtual CARAPI SetNegativePrefix(
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI SetNegativeSuffix(
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI SetPositivePrefix(
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI SetPositiveSuffix(
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI SetParseBigDecimal(
        /* [in] */ _ELASTOS Boolean newValue) = 0;

    virtual CARAPI ToLocalizedPattern(
        /* [out] */ _ELASTOS String * localizedPattern) = 0;

    virtual CARAPI ToPattern(
        /* [out] */ _ELASTOS String * pattern) = 0;

    virtual CARAPI GetRoundingMode(
        /* [out] */ Elastos::Math::RoundingMode * mode) = 0;

    virtual CARAPI SetRoundingMode(
        /* [in] */ Elastos::Math::RoundingMode mode) = 0;

    virtual CARAPI GetNdf(
        /* [out] */ Libcore::ICU::INativeDecimalFormat ** ndf) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("825AF73A-2892-3016-48BC-E80683C40DDB")
IDecimalFormatSymbols : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDecimalFormatSymbols*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDecimalFormatSymbols*)pObj->Probe(EIID_IDecimalFormatSymbols);
    }

    static CARAPI_(IDecimalFormatSymbols*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDecimalFormatSymbols*)pObj->Probe(EIID_IDecimalFormatSymbols);
    }

    virtual CARAPI GetCurrency(
        /* [out] */ Elastos::Utility::ICurrency ** currency) = 0;

    virtual CARAPI GetInternationalCurrencySymbol(
        /* [out] */ _ELASTOS String * symbol) = 0;

    virtual CARAPI GetCurrencySymbol(
        /* [out] */ _ELASTOS String * symbol) = 0;

    virtual CARAPI GetDecimalSeparator(
        /* [out] */ _ELASTOS Char32 * separator) = 0;

    virtual CARAPI GetDigit(
        /* [out] */ _ELASTOS Char32 * digit) = 0;

    virtual CARAPI GetGroupingSeparator(
        /* [out] */ _ELASTOS Char32 * separator) = 0;

    virtual CARAPI GetInfinity(
        /* [out] */ _ELASTOS String * infinity) = 0;

    virtual CARAPI GetMinusSign(
        /* [out] */ _ELASTOS Char32 * sign) = 0;

    virtual CARAPI GetMonetaryDecimalSeparator(
        /* [out] */ _ELASTOS Char32 * separator) = 0;

    virtual CARAPI GetNaN(
        /* [out] */ _ELASTOS String * NaN) = 0;

    virtual CARAPI GetPatternSeparator(
        /* [out] */ _ELASTOS Char32 * separator) = 0;

    virtual CARAPI GetPercent(
        /* [out] */ _ELASTOS Char32 * percent) = 0;

    virtual CARAPI GetPerMill(
        /* [out] */ _ELASTOS Char32 * perMill) = 0;

    virtual CARAPI GetZeroDigit(
        /* [out] */ _ELASTOS Char32 * zeroDigit) = 0;

    virtual CARAPI GetExponentSeparator(
        /* [out] */ _ELASTOS String * separator) = 0;

    virtual CARAPI SetCurrency(
        /* [in] */ Elastos::Utility::ICurrency * currency) = 0;

    virtual CARAPI SetInternationalCurrencySymbol(
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI SetCurrencySymbol(
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI SetDecimalSeparator(
        /* [in] */ _ELASTOS Char32 value) = 0;

    virtual CARAPI SetDigit(
        /* [in] */ _ELASTOS Char32 value) = 0;

    virtual CARAPI SetGroupingSeparator(
        /* [in] */ _ELASTOS Char32 value) = 0;

    virtual CARAPI SetInfinity(
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI SetMinusSign(
        /* [in] */ _ELASTOS Char32 value) = 0;

    virtual CARAPI SetMonetaryDecimalSeparator(
        /* [in] */ _ELASTOS Char32 value) = 0;

    virtual CARAPI SetNaN(
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI SetPatternSeparator(
        /* [in] */ _ELASTOS Char32 value) = 0;

    virtual CARAPI SetPercent(
        /* [in] */ _ELASTOS Char32 value) = 0;

    virtual CARAPI SetPerMill(
        /* [in] */ _ELASTOS Char32 value) = 0;

    virtual CARAPI SetZeroDigit(
        /* [in] */ _ELASTOS Char32 value) = 0;

    virtual CARAPI SetExponentSeparator(
        /* [in] */ const _ELASTOS String& value) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("F2295226-2892-3016-48BC-E80683C40DDB")
IDecimalFormatSymbolsHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDecimalFormatSymbolsHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDecimalFormatSymbolsHelper*)pObj->Probe(EIID_IDecimalFormatSymbolsHelper);
    }

    static CARAPI_(IDecimalFormatSymbolsHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDecimalFormatSymbolsHelper*)pObj->Probe(EIID_IDecimalFormatSymbolsHelper);
    }

    virtual CARAPI GetInstance(
        /* [out] */ Elastos::Text::IDecimalFormatSymbols ** instance) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Text::IDecimalFormatSymbols ** instance) = 0;

    virtual CARAPI GetAvailableLocales(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Utility::ILocale *> ** locales) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("D424724D-03D2-2783-33C8-60DCF9878392")
IFieldPosition : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFieldPosition*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFieldPosition*)pObj->Probe(EIID_IFieldPosition);
    }

    static CARAPI_(IFieldPosition*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFieldPosition*)pObj->Probe(EIID_IFieldPosition);
    }

    virtual CARAPI Clear() = 0;

    virtual CARAPI GetBeginIndex(
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetEndIndex(
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetField(
        /* [out] */ _ELASTOS Int32 * field) = 0;

    virtual CARAPI GetFieldAttribute(
        /* [out] */ Elastos::Text::IAttributedCharacterIteratorAttribute ** attribute) = 0;

    virtual CARAPI SetBeginIndex(
        /* [in] */ _ELASTOS Int32 index) = 0;

    virtual CARAPI SetEndIndex(
        /* [in] */ _ELASTOS Int32 index) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("4B091A42-83D2-39AB-6F3C-3078F2878392")
IFormatField : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFormatField*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFormatField*)pObj->Probe(EIID_IFormatField);
    }

    static CARAPI_(IFormatField*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFormatField*)pObj->Probe(EIID_IFormatField);
    }

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("AAFE500C-23D2-30D7-79FF-CE4BDAB76CFF")
IFormat : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFormat*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFormat*)pObj->Probe(EIID_IFormat);
    }

    static CARAPI_(IFormat*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFormat*)pObj->Probe(EIID_IFormat);
    }

    virtual CARAPI Format(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS String * value) = 0;

    virtual CARAPI Format(
        /* [in] */ IInterface * object,
        /* [in] */ Elastos::Core::IStringBuffer * buffer,
        /* [in] */ Elastos::Text::IFieldPosition * field) = 0;

    virtual CARAPI FormatToCharacterIterator(
        /* [in] */ IInterface * object,
        /* [out] */ Elastos::Text::IAttributedCharacterIterator ** charactorIterator) = 0;

    virtual CARAPI ParseObject(
        /* [in] */ const _ELASTOS String& string,
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI ParseObject(
        /* [in] */ const _ELASTOS String& string,
        /* [in] */ Elastos::Text::IParsePosition * position,
        /* [out] */ IInterface ** object) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("9BF0213D-CCD2-306E-48DC-78C002C58B13")
IMessageFormatField : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMessageFormatField*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMessageFormatField*)pObj->Probe(EIID_IMessageFormatField);
    }

    static CARAPI_(IMessageFormatField*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMessageFormatField*)pObj->Probe(EIID_IMessageFormatField);
    }

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("B593E22F-CCD2-306E-48DC-F8D1DEC60D19")
IMessageFormat : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMessageFormat*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMessageFormat*)pObj->Probe(EIID_IMessageFormat);
    }

    static CARAPI_(IMessageFormat*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMessageFormat*)pObj->Probe(EIID_IMessageFormat);
    }

    virtual CARAPI ApplyPattern(
        /* [in] */ const _ELASTOS String& temp) = 0;

    virtual CARAPI Format(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * objects,
        /* [in] */ Elastos::Core::IStringBuffer * buffer,
        /* [in] */ Elastos::Text::IFieldPosition * field) = 0;

    virtual CARAPI GetFormats(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Text::IFormat *> ** formats) = 0;

    virtual CARAPI GetFormatsByArgumentIndex(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Text::IFormat *> ** formatsByArgumentIndex) = 0;

    virtual CARAPI SetFormatByArgumentIndex(
        /* [in] */ _ELASTOS Int32 argIndex,
        /* [in] */ Elastos::Text::IFormat * format) = 0;

    virtual CARAPI SetFormatsByArgumentIndex(
        /* [in] */ _ELASTOS ArrayOf<Elastos::Text::IFormat *> * formats) = 0;

    virtual CARAPI GetLocale(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI Parse(
        /* [in] */ const _ELASTOS String& string,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** result) = 0;

    virtual CARAPI Parse(
        /* [in] */ const _ELASTOS String& string,
        /* [in] */ Elastos::Text::IParsePosition * position,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** result) = 0;

    virtual CARAPI SetFormat(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ Elastos::Text::IFormat * format) = 0;

    virtual CARAPI SetFormats(
        /* [in] */ _ELASTOS ArrayOf<Elastos::Text::IFormat *> * formats) = 0;

    virtual CARAPI SetLocale(
        /* [in] */ Elastos::Utility::ILocale * locale) = 0;

    virtual CARAPI ToPattern(
        /* [out] */ _ELASTOS String * pattern) = 0;

    virtual CARAPI GetMaxOffset(
        /* [out] */ _ELASTOS Int32 * maxOffset) = 0;

    virtual CARAPI GetArgumentNumbers(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Int32> ** argumentNumbers) = 0;

    virtual CARAPI GetStrings(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** strings) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("5C972E38-5112-3D16-EEFF-686FE3860C1B")
INormalizer : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INormalizer*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INormalizer*)pObj->Probe(EIID_INormalizer);
    }

    static CARAPI_(INormalizer*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INormalizer*)pObj->Probe(EIID_INormalizer);
    }

    virtual CARAPI IsNormalized(
        /* [in] */ Elastos::Core::ICharSequence * src,
        /* [in] */ Elastos::Text::NormalizerForm form,
        /* [out] */ _ELASTOS Boolean * isNormalized) = 0;

    virtual CARAPI Normalize(
        /* [in] */ Elastos::Core::ICharSequence * src,
        /* [in] */ Elastos::Text::NormalizerForm form,
        /* [out] */ _ELASTOS String * normalizeString) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("29BF200D-85D2-25C3-5A3F-720D93F7C3A2")
INumberFormatField : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INumberFormatField*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INumberFormatField*)pObj->Probe(EIID_INumberFormatField);
    }

    static CARAPI_(INumberFormatField*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INumberFormatField*)pObj->Probe(EIID_INumberFormatField);
    }

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("60A2F803-85D2-25C3-5A3F-720D93F7EFBC")
INumberFormat : public IInterface
{
    static const _ELASTOS Int32 INTEGER_FIELD = 0;
    static const _ELASTOS Int32 FRACTION_FIELD = 1;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INumberFormat*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INumberFormat*)pObj->Probe(EIID_INumberFormat);
    }

    static CARAPI_(INumberFormat*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INumberFormat*)pObj->Probe(EIID_INumberFormat);
    }

    virtual CARAPI Format(
        /* [in] */ _ELASTOS Double value,
        /* [out] */ _ELASTOS String * format) = 0;

    virtual CARAPI Format(
        /* [in] */ _ELASTOS Double value,
        /* [in] */ Elastos::Core::IStringBuffer * inbuffer,
        /* [in] */ Elastos::Text::IFieldPosition * field) = 0;

    virtual CARAPI Format(
        /* [in] */ _ELASTOS Int64 value,
        /* [out] */ _ELASTOS String * format) = 0;

    virtual CARAPI Format(
        /* [in] */ _ELASTOS Int64 value,
        /* [in] */ Elastos::Core::IStringBuffer * inbuffer,
        /* [in] */ Elastos::Text::IFieldPosition * field) = 0;

    virtual CARAPI GetCurrency(
        /* [out] */ Elastos::Utility::ICurrency ** currency) = 0;

    virtual CARAPI GetMaximumFractionDigits(
        /* [out] */ _ELASTOS Int32 * max) = 0;

    virtual CARAPI GetMaximumIntegerDigits(
        /* [out] */ _ELASTOS Int32 * max) = 0;

    virtual CARAPI GetMinimumFractionDigits(
        /* [out] */ _ELASTOS Int32 * min) = 0;

    virtual CARAPI GetMinimumIntegerDigits(
        /* [out] */ _ELASTOS Int32 * min) = 0;

    virtual CARAPI IsGroupingUsed(
        /* [out] */ _ELASTOS Boolean * groupingUsed) = 0;

    virtual CARAPI IsParseIntegerOnly(
        /* [out] */ _ELASTOS Boolean * parseIntegerOnly) = 0;

    virtual CARAPI Parse(
        /* [in] */ const _ELASTOS String& string,
        /* [out] */ Elastos::Core::INumber ** value) = 0;

    virtual CARAPI Parse(
        /* [in] */ const _ELASTOS String& string,
        /* [in] */ Elastos::Text::IParsePosition * position,
        /* [out] */ Elastos::Core::INumber ** value) = 0;

    virtual CARAPI SetCurrency(
        /* [in] */ Elastos::Utility::ICurrency * currency) = 0;

    virtual CARAPI SetGroupingUsed(
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI SetMaximumFractionDigits(
        /* [in] */ _ELASTOS Int32 value) = 0;

    virtual CARAPI SetMaximumIntegerDigits(
        /* [in] */ _ELASTOS Int32 value) = 0;

    virtual CARAPI SetMinimumFractionDigits(
        /* [in] */ _ELASTOS Int32 value) = 0;

    virtual CARAPI SetMinimumIntegerDigits(
        /* [in] */ _ELASTOS Int32 value) = 0;

    virtual CARAPI SetParseIntegerOnly(
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI GetRoundingMode(
        /* [out] */ Elastos::Math::RoundingMode * roundingMode) = 0;

    virtual CARAPI SetRoundingMode(
        /* [in] */ Elastos::Math::RoundingMode roundingMode) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("8D39DA1C-85D2-25C3-5A3F-720D937784BE")
INumberFormatHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INumberFormatHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INumberFormatHelper*)pObj->Probe(EIID_INumberFormatHelper);
    }

    static CARAPI_(INumberFormatHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INumberFormatHelper*)pObj->Probe(EIID_INumberFormatHelper);
    }

    virtual CARAPI GetAvailableLocales(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Utility::ILocale *> ** locales) = 0;

    virtual CARAPI GetCurrencyInstance(
        /* [out] */ Elastos::Text::INumberFormat ** instance) = 0;

    virtual CARAPI GetCurrencyInstance(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Text::INumberFormat ** instance) = 0;

    virtual CARAPI GetIntegerInstance(
        /* [out] */ Elastos::Text::INumberFormat ** instance) = 0;

    virtual CARAPI GetIntegerInstance(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Text::INumberFormat ** instance) = 0;

    virtual CARAPI GetInstance(
        /* [out] */ Elastos::Text::INumberFormat ** instance) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Text::INumberFormat ** instance) = 0;

    virtual CARAPI GetNumberInstance(
        /* [out] */ Elastos::Text::INumberFormat ** instance) = 0;

    virtual CARAPI GetNumberInstance(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Text::INumberFormat ** instance) = 0;

    virtual CARAPI GetPercentInstance(
        /* [out] */ Elastos::Text::INumberFormat ** instance) = 0;

    virtual CARAPI GetPercentInstance(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Text::INumberFormat ** instance) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("4E65464E-8652-8344-33C8-60DCF9878392")
IParsePosition : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IParsePosition*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IParsePosition*)pObj->Probe(EIID_IParsePosition);
    }

    static CARAPI_(IParsePosition*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IParsePosition*)pObj->Probe(EIID_IParsePosition);
    }

    virtual CARAPI GetErrorIndex(
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetIndex(
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI SetErrorIndex(
        /* [in] */ _ELASTOS Int32 index) = 0;

    virtual CARAPI SetIndex(
        /* [in] */ _ELASTOS Int32 index) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("5E935E4C-06D2-0BDC-1615-2BD2F2F40F07")
IRuleBasedCollator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRuleBasedCollator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRuleBasedCollator*)pObj->Probe(EIID_IRuleBasedCollator);
    }

    static CARAPI_(IRuleBasedCollator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRuleBasedCollator*)pObj->Probe(EIID_IRuleBasedCollator);
    }

    virtual CARAPI GetCollationElementIterator(
        /* [in] */ const _ELASTOS String& source,
        /* [out] */ Elastos::Text::ICollationElementIterator ** iterator) = 0;

    virtual CARAPI GetCollationElementIterator(
        /* [in] */ Elastos::Text::ICharacterIterator * source,
        /* [out] */ Elastos::Text::ICollationElementIterator ** iterator) = 0;

    virtual CARAPI GetRules(
        /* [out] */ _ELASTOS String * rules) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("7DA6A756-8712-6686-1B34-7A7035E78D1F")
ISimpleDateFormat : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISimpleDateFormat*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISimpleDateFormat*)pObj->Probe(EIID_ISimpleDateFormat);
    }

    static CARAPI_(ISimpleDateFormat*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISimpleDateFormat*)pObj->Probe(EIID_ISimpleDateFormat);
    }

    virtual CARAPI ApplyLocalizedPattern(
        /* [in] */ const _ELASTOS String& tem) = 0;

    virtual CARAPI ApplyPattern(
        /* [in] */ const _ELASTOS String& tem) = 0;

    virtual CARAPI Get2DigitYearStart(
        /* [out] */ Elastos::Utility::IDate ** date) = 0;

    virtual CARAPI GetDateFormatSymbols(
        /* [out] */ Elastos::Text::IDateFormatSymbols ** dateFormatSymbols) = 0;

    virtual CARAPI Set2DigitYearStart(
        /* [in] */ Elastos::Utility::IDate * date) = 0;

    virtual CARAPI SetDateFormatSymbols(
        /* [in] */ Elastos::Text::IDateFormatSymbols * value) = 0;

    virtual CARAPI ToLocalizedPattern(
        /* [out] */ _ELASTOS String * pattern) = 0;

    virtual CARAPI ToPattern(
        /* [out] */ _ELASTOS String * pattern) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("E0992D5E-9AD2-8921-48BC-7A2621F3A3AB")
IStringCharacterIterator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IStringCharacterIterator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStringCharacterIterator*)pObj->Probe(EIID_IStringCharacterIterator);
    }

    static CARAPI_(IStringCharacterIterator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStringCharacterIterator*)pObj->Probe(EIID_IStringCharacterIterator);
    }

    virtual CARAPI SetText(
        /* [in] */ const _ELASTOS String& value) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("D1BD633F-0312-3105-62C8-B84102BE1EA3")
ICAnnotationClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAnnotationClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAnnotationClassObject*)pObj->Probe(EIID_ICAnnotationClassObject);
    }

    static CARAPI_(ICAnnotationClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAnnotationClassObject*)pObj->Probe(EIID_ICAnnotationClassObject);
    }

    virtual CARAPI CreateObjectWithAttribute(
        /* [in] */ IInterface * attribute,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("B67B7837-0312-272E-18AC-20518384891B")
ICAttributedCharacterIteratorAttributeClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAttributedCharacterIteratorAttributeClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAttributedCharacterIteratorAttributeClassObject*)pObj->Probe(EIID_ICAttributedCharacterIteratorAttributeClassObject);
    }

    static CARAPI_(ICAttributedCharacterIteratorAttributeClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAttributedCharacterIteratorAttributeClassObject*)pObj->Probe(EIID_ICAttributedCharacterIteratorAttributeClassObject);
    }

    virtual CARAPI CreateObjectWithName(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("DAD8D32A-8312-2C05-4EB0-D063F4477B1B")
ICBidiClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICBidiClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBidiClassObject*)pObj->Probe(EIID_ICBidiClassObject);
    }

    static CARAPI_(ICBidiClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBidiClassObject*)pObj->Probe(EIID_ICBidiClassObject);
    }

    virtual CARAPI CreateObjectWithParagraph(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * paragraph,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithTextTextStartEmbeddingsEmbStartParagraphLengthFlags(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * text,
        /* [in] */ _ELASTOS Int32 textStart,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * embeddings,
        /* [in] */ _ELASTOS Int32 embStart,
        /* [in] */ _ELASTOS Int32 paragraphLength,
        /* [in] */ _ELASTOS Int32 flags,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithParagraphFlags(
        /* [in] */ const _ELASTOS String& paragraph,
        /* [in] */ _ELASTOS Int32 flags,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPBidi(
        /* [in] */ _ELASTOS Int64 pBidi,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("4CDC6519-B312-27B0-1BA1-EF8CD6CC4BDA")
ICBidiHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICBidiHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBidiHelperClassObject*)pObj->Probe(EIID_ICBidiHelperClassObject);
    }

    static CARAPI_(ICBidiHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBidiHelperClassObject*)pObj->Probe(EIID_ICBidiHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("C1AC6E01-B312-28D4-E94A-375A93B75C47")
ICBreakIteratorHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICBreakIteratorHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBreakIteratorHelperClassObject*)pObj->Probe(EIID_ICBreakIteratorHelperClassObject);
    }

    static CARAPI_(ICBreakIteratorHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBreakIteratorHelperClassObject*)pObj->Probe(EIID_ICBreakIteratorHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("AFBA6E17-B312-2FE1-BA90-367A2E354ABA")
ICRuleBasedBreakIteratorClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICRuleBasedBreakIteratorClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRuleBasedBreakIteratorClassObject*)pObj->Probe(EIID_ICRuleBasedBreakIteratorClassObject);
    }

    static CARAPI_(ICRuleBasedBreakIteratorClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRuleBasedBreakIteratorClassObject*)pObj->Probe(EIID_ICRuleBasedBreakIteratorClassObject);
    }

    virtual CARAPI CreateObjectWithIterator(
        /* [in] */ Libcore::ICU::INativeBreakIterator * iterator,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("DE739951-8312-0607-4F66-90C1B8330393")
ICFieldPositionClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICFieldPositionClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFieldPositionClassObject*)pObj->Probe(EIID_ICFieldPositionClassObject);
    }

    static CARAPI_(ICFieldPositionClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFieldPositionClassObject*)pObj->Probe(EIID_ICFieldPositionClassObject);
    }

    virtual CARAPI CreateObjectWithField(
        /* [in] */ _ELASTOS Int32 field,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithAttribute(
        /* [in] */ Elastos::Text::IAttributedCharacterIteratorAttribute * attribute,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithAttributeField(
        /* [in] */ Elastos::Text::IAttributedCharacterIteratorAttribute * attribute,
        /* [in] */ _ELASTOS Int32 field,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("C5516246-8312-890C-0667-90C1B8330393")
ICParsePositionClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICParsePositionClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICParsePositionClassObject*)pObj->Probe(EIID_ICParsePositionClassObject);
    }

    static CARAPI_(ICParsePositionClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICParsePositionClassObject*)pObj->Probe(EIID_ICParsePositionClassObject);
    }

    virtual CARAPI CreateObjectWithIndex(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("97EEC73E-0312-272E-60EB-31FAA3BD8D1B")
ICAttributedStringClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAttributedStringClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAttributedStringClassObject*)pObj->Probe(EIID_ICAttributedStringClassObject);
    }

    static CARAPI_(ICAttributedStringClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAttributedStringClassObject*)pObj->Probe(EIID_ICAttributedStringClassObject);
    }

    virtual CARAPI CreateObjectWithIterator(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * iterator,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithIteratorStartEnd(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * iterator,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithIteratorStartEndAttributes(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * iterator,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Text::IAttributedCharacterIteratorAttribute *> * attributes,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithValue(
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("C1247C1C-C312-32AC-6BA2-8F5CC3E4CDBC")
ICChoiceFormatClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICChoiceFormatClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICChoiceFormatClassObject*)pObj->Probe(EIID_ICChoiceFormatClassObject);
    }

    static CARAPI_(ICChoiceFormatClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICChoiceFormatClassObject*)pObj->Probe(EIID_ICChoiceFormatClassObject);
    }

    virtual CARAPI CreateObjectWithLimitsFormats(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Double> * limits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * formats,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithTem(
        /* [in] */ const _ELASTOS String& tem,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("97526D07-C312-32AC-6BA2-8F5CC3E41DA1")
ICChoiceFormatHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICChoiceFormatHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICChoiceFormatHelperClassObject*)pObj->Probe(EIID_ICChoiceFormatHelperClassObject);
    }

    static CARAPI_(ICChoiceFormatHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICChoiceFormatHelperClassObject*)pObj->Probe(EIID_ICChoiceFormatHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("132E6A16-7312-70E1-89D6-8F5CC3E4FDB0")
ICNumberFormatFieldClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICNumberFormatFieldClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNumberFormatFieldClassObject*)pObj->Probe(EIID_ICNumberFormatFieldClassObject);
    }

    static CARAPI_(ICNumberFormatFieldClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNumberFormatFieldClassObject*)pObj->Probe(EIID_ICNumberFormatFieldClassObject);
    }

    virtual CARAPI CreateObjectWithFieldName(
        /* [in] */ const _ELASTOS String& fieldName,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("84476D05-7312-70E1-89D6-8F5CC3E41DA1")
ICNumberFormatHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICNumberFormatHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNumberFormatHelperClassObject*)pObj->Probe(EIID_ICNumberFormatHelperClassObject);
    }

    static CARAPI_(ICNumberFormatHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNumberFormatHelperClassObject*)pObj->Probe(EIID_ICNumberFormatHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("E328B818-D312-26A0-0B93-EF23D7307933")
ICDecimalFormatClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDecimalFormatClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDecimalFormatClassObject*)pObj->Probe(EIID_ICDecimalFormatClassObject);
    }

    static CARAPI_(ICDecimalFormatClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDecimalFormatClassObject*)pObj->Probe(EIID_ICDecimalFormatClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPattern(
        /* [in] */ const _ELASTOS String& pattern,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPatternValue(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Text::IDecimalFormatSymbols * value,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPatternLocale(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("FC5F851C-D312-26A0-0B93-EF23D7307973")
ICDecimalFormatSymbolsClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDecimalFormatSymbolsClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDecimalFormatSymbolsClassObject*)pObj->Probe(EIID_ICDecimalFormatSymbolsClassObject);
    }

    static CARAPI_(ICDecimalFormatSymbolsClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDecimalFormatSymbolsClassObject*)pObj->Probe(EIID_ICDecimalFormatSymbolsClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithLocale(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("31687514-D312-26A0-0B93-EF23D7307973")
ICDecimalFormatSymbolsHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDecimalFormatSymbolsHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDecimalFormatSymbolsHelperClassObject*)pObj->Probe(EIID_ICDecimalFormatSymbolsHelperClassObject);
    }

    static CARAPI_(ICDecimalFormatSymbolsHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDecimalFormatSymbolsHelperClassObject*)pObj->Probe(EIID_ICDecimalFormatSymbolsHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("A2A2792D-8312-DD99-6090-B8A1C7E88FF6")
ICMessageFormatClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICMessageFormatClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMessageFormatClassObject*)pObj->Probe(EIID_ICMessageFormatClassObject);
    }

    static CARAPI_(ICMessageFormatClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMessageFormatClassObject*)pObj->Probe(EIID_ICMessageFormatClassObject);
    }

    virtual CARAPI CreateObjectWithTemLocale(
        /* [in] */ const _ELASTOS String& tem,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithTem(
        /* [in] */ const _ELASTOS String& tem,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("3E26B55F-0312-0D0E-CD36-68F4E06ACE1B")
ICSimpleDateFormatClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSimpleDateFormatClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSimpleDateFormatClassObject*)pObj->Probe(EIID_ICSimpleDateFormatClassObject);
    }

    static CARAPI_(ICSimpleDateFormatClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSimpleDateFormatClassObject*)pObj->Probe(EIID_ICSimpleDateFormatClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPattern(
        /* [in] */ const _ELASTOS String& pattern,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithTempValue(
        /* [in] */ const _ELASTOS String& temp,
        /* [in] */ Elastos::Text::IDateFormatSymbols * value,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithTempLocale(
        /* [in] */ const _ELASTOS String& temp,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("07B06B03-D312-3790-FAC8-354CDE11FACE")
ICDateFormatHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDateFormatHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDateFormatHelperClassObject*)pObj->Probe(EIID_ICDateFormatHelperClassObject);
    }

    static CARAPI_(ICDateFormatHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDateFormatHelperClassObject*)pObj->Probe(EIID_ICDateFormatHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("E9916B33-0312-2CA2-7ADC-8F80E2C58CFB")
ICNormalizerHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICNormalizerHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNormalizerHelperClassObject*)pObj->Probe(EIID_ICNormalizerHelperClassObject);
    }

    static CARAPI_(ICNormalizerHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNormalizerHelperClassObject*)pObj->Probe(EIID_ICNormalizerHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("8B3F6626-8312-DD99-6090-B8F180058A17")
ICMessageFormatFieldClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICMessageFormatFieldClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMessageFormatFieldClassObject*)pObj->Probe(EIID_ICMessageFormatFieldClassObject);
    }

    static CARAPI_(ICMessageFormatFieldClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMessageFormatFieldClassObject*)pObj->Probe(EIID_ICMessageFormatFieldClassObject);
    }

    virtual CARAPI CreateObjectWithName(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("ACE18221-8312-DD4C-6090-B861DB861EA3")
ICDateFormatSymbolsClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDateFormatSymbolsClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDateFormatSymbolsClassObject*)pObj->Probe(EIID_ICDateFormatSymbolsClassObject);
    }

    static CARAPI_(ICDateFormatSymbolsClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDateFormatSymbolsClassObject*)pObj->Probe(EIID_ICDateFormatSymbolsClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithLocale(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("37F27546-8312-8D06-1E5C-CD79E381C193")
ICDateFormatFieldClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDateFormatFieldClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDateFormatFieldClassObject*)pObj->Probe(EIID_ICDateFormatFieldClassObject);
    }

    static CARAPI_(ICDateFormatFieldClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDateFormatFieldClassObject*)pObj->Probe(EIID_ICDateFormatFieldClassObject);
    }

    virtual CARAPI CreateObjectWithFieldNameCalendarField(
        /* [in] */ const _ELASTOS String& fieldName,
        /* [in] */ _ELASTOS Int32 calendarField,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("B5167229-8312-DD4C-6090-B861DB460414")
ICDateFormatSymbolsHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDateFormatSymbolsHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDateFormatSymbolsHelperClassObject*)pObj->Probe(EIID_ICDateFormatSymbolsHelperClassObject);
    }

    static CARAPI_(ICDateFormatSymbolsHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDateFormatSymbolsHelperClassObject*)pObj->Probe(EIID_ICDateFormatSymbolsHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("20367041-8312-2D22-3B3B-48A95342E647")
ICCollationElementIteratorClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCollationElementIteratorClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCollationElementIteratorClassObject*)pObj->Probe(EIID_ICCollationElementIteratorClassObject);
    }

    static CARAPI_(ICCollationElementIteratorClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCollationElementIteratorClassObject*)pObj->Probe(EIID_ICCollationElementIteratorClassObject);
    }

    virtual CARAPI CreateObjectWithIterator(
        /* [in] */ Libcore::ICU::ICollationElementIteratorICU * iterator,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("0DD27944-8312-2D22-3B3B-48A95342E647")
ICCollationElementIteratorHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCollationElementIteratorHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCollationElementIteratorHelperClassObject*)pObj->Probe(EIID_ICCollationElementIteratorHelperClassObject);
    }

    static CARAPI_(ICCollationElementIteratorHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCollationElementIteratorHelperClassObject*)pObj->Probe(EIID_ICCollationElementIteratorHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("A3C67D47-8312-B80D-172C-2A56A4E56906")
ICRuleBasedCollatorClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICRuleBasedCollatorClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRuleBasedCollatorClassObject*)pObj->Probe(EIID_ICRuleBasedCollatorClassObject);
    }

    static CARAPI_(ICRuleBasedCollatorClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRuleBasedCollatorClassObject*)pObj->Probe(EIID_ICRuleBasedCollatorClassObject);
    }

    virtual CARAPI CreateObjectWithWrapper(
        /* [in] */ Libcore::ICU::IRuleBasedCollatorICU * wrapper,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithRules(
        /* [in] */ const _ELASTOS String& rules,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("B620AE41-8312-4335-1291-78F54C42E647")
ICStringCharacterIteratorClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICStringCharacterIteratorClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStringCharacterIteratorClassObject*)pObj->Probe(EIID_ICStringCharacterIteratorClassObject);
    }

    static CARAPI_(ICStringCharacterIteratorClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStringCharacterIteratorClassObject*)pObj->Probe(EIID_ICStringCharacterIteratorClassObject);
    }

    virtual CARAPI CreateObjectWithValue(
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithValueLocation(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithValueStartEndLocation(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
CAR_INTERFACE("5D02695C-8312-2D22-4F47-40F1226C0D06")
ICCollatorHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCollatorHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCollatorHelperClassObject*)pObj->Probe(EIID_ICCollatorHelperClassObject);
    }

    static CARAPI_(ICCollatorHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCollatorHelperClassObject*)pObj->Probe(EIID_ICCollatorHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Elastos {
namespace Text {
class CAnnotation
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ IInterface * attribute,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAnnotationClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAnnotation, RGM_SAME_DOMAIN,
                EIID_ICAnnotationClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithAttribute(attribute, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * attribute,
        /* [out] */ Elastos::Text::IAnnotation** __IAnnotation)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(attribute, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAnnotation = (Elastos::Text::IAnnotation*)__pNewObj->Probe(Elastos::Text::EIID_IAnnotation);
        if (*__IAnnotation) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * attribute,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(attribute, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * attribute,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(attribute, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * attribute,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(attribute, &__pNewObj);
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
namespace Text {
class CAttributedCharacterIteratorAttribute
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAttributedCharacterIteratorAttributeClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAttributedCharacterIteratorAttribute, RGM_SAME_DOMAIN,
                EIID_ICAttributedCharacterIteratorAttributeClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithName(name, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Text::IAttributedCharacterIteratorAttribute** __IAttributedCharacterIteratorAttribute)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAttributedCharacterIteratorAttribute = (Elastos::Text::IAttributedCharacterIteratorAttribute*)__pNewObj->Probe(Elastos::Text::EIID_IAttributedCharacterIteratorAttribute);
        if (*__IAttributedCharacterIteratorAttribute) __pNewObj->AddRef();
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

};
}
}
namespace Elastos {
namespace Text {
class CBidi
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * paragraph,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBidiClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBidi, RGM_SAME_DOMAIN,
                EIID_ICBidiClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithParagraph(paragraph, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * text,
        /* [in] */ _ELASTOS Int32 textStart,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * embeddings,
        /* [in] */ _ELASTOS Int32 embStart,
        /* [in] */ _ELASTOS Int32 paragraphLength,
        /* [in] */ _ELASTOS Int32 flags,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBidiClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBidi, RGM_SAME_DOMAIN,
                EIID_ICBidiClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTextTextStartEmbeddingsEmbStartParagraphLengthFlags(text, textStart, embeddings, embStart, paragraphLength, flags, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& paragraph,
        /* [in] */ _ELASTOS Int32 flags,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBidiClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBidi, RGM_SAME_DOMAIN,
                EIID_ICBidiClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithParagraphFlags(paragraph, flags, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int64 pBidi,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBidiClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBidi, RGM_SAME_DOMAIN,
                EIID_ICBidiClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPBidi(pBidi, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * paragraph,
        /* [out] */ Elastos::Text::IBidi** __IBidi)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(paragraph, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBidi = (Elastos::Text::IBidi*)__pNewObj->Probe(Elastos::Text::EIID_IBidi);
        if (*__IBidi) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * paragraph,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(paragraph, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * paragraph,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(paragraph, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * paragraph,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(paragraph, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * text,
        /* [in] */ _ELASTOS Int32 textStart,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * embeddings,
        /* [in] */ _ELASTOS Int32 embStart,
        /* [in] */ _ELASTOS Int32 paragraphLength,
        /* [in] */ _ELASTOS Int32 flags,
        /* [out] */ Elastos::Text::IBidi** __IBidi)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(text, textStart, embeddings, embStart, paragraphLength, flags, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBidi = (Elastos::Text::IBidi*)__pNewObj->Probe(Elastos::Text::EIID_IBidi);
        if (*__IBidi) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * text,
        /* [in] */ _ELASTOS Int32 textStart,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * embeddings,
        /* [in] */ _ELASTOS Int32 embStart,
        /* [in] */ _ELASTOS Int32 paragraphLength,
        /* [in] */ _ELASTOS Int32 flags,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(text, textStart, embeddings, embStart, paragraphLength, flags, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * text,
        /* [in] */ _ELASTOS Int32 textStart,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * embeddings,
        /* [in] */ _ELASTOS Int32 embStart,
        /* [in] */ _ELASTOS Int32 paragraphLength,
        /* [in] */ _ELASTOS Int32 flags,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(text, textStart, embeddings, embStart, paragraphLength, flags, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * text,
        /* [in] */ _ELASTOS Int32 textStart,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * embeddings,
        /* [in] */ _ELASTOS Int32 embStart,
        /* [in] */ _ELASTOS Int32 paragraphLength,
        /* [in] */ _ELASTOS Int32 flags,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(text, textStart, embeddings, embStart, paragraphLength, flags, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& paragraph,
        /* [in] */ _ELASTOS Int32 flags,
        /* [out] */ Elastos::Text::IBidi** __IBidi)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(paragraph, flags, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBidi = (Elastos::Text::IBidi*)__pNewObj->Probe(Elastos::Text::EIID_IBidi);
        if (*__IBidi) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& paragraph,
        /* [in] */ _ELASTOS Int32 flags,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(paragraph, flags, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& paragraph,
        /* [in] */ _ELASTOS Int32 flags,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(paragraph, flags, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& paragraph,
        /* [in] */ _ELASTOS Int32 flags,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(paragraph, flags, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 pBidi,
        /* [out] */ Elastos::Text::IBidi** __IBidi)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pBidi, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBidi = (Elastos::Text::IBidi*)__pNewObj->Probe(Elastos::Text::EIID_IBidi);
        if (*__IBidi) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 pBidi,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pBidi, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 pBidi,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pBidi, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 pBidi,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pBidi, &__pNewObj);
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
namespace Text {
class CBidiHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Text::IBidiHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBidiHelper, RGM_SAME_DOMAIN, Elastos::Text::EIID_IBidiHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBidiHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBidiHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBidiHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Text {
class CBreakIteratorHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Text::IBreakIteratorHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBreakIteratorHelper, RGM_SAME_DOMAIN, Elastos::Text::EIID_IBreakIteratorHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBreakIteratorHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBreakIteratorHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBreakIteratorHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Text {
class CRuleBasedBreakIterator
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Libcore::ICU::INativeBreakIterator * iterator,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICRuleBasedBreakIteratorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CRuleBasedBreakIterator, RGM_SAME_DOMAIN,
                EIID_ICRuleBasedBreakIteratorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIterator(iterator, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Libcore::ICU::INativeBreakIterator * iterator,
        /* [out] */ Elastos::Text::IBreakIterator** __IBreakIterator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iterator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBreakIterator = (Elastos::Text::IBreakIterator*)__pNewObj->Probe(Elastos::Text::EIID_IBreakIterator);
        if (*__IBreakIterator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Libcore::ICU::INativeBreakIterator * iterator,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iterator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Libcore::ICU::INativeBreakIterator * iterator,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iterator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Libcore::ICU::INativeBreakIterator * iterator,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iterator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Libcore::ICU::INativeBreakIterator * iterator,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iterator, &__pNewObj);
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
namespace Text {
class CFieldPosition
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 field,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFieldPositionClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFieldPosition, RGM_SAME_DOMAIN,
                EIID_ICFieldPositionClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithField(field, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Text::IAttributedCharacterIteratorAttribute * attribute,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFieldPositionClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFieldPosition, RGM_SAME_DOMAIN,
                EIID_ICFieldPositionClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithAttribute(attribute, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Text::IAttributedCharacterIteratorAttribute * attribute,
        /* [in] */ _ELASTOS Int32 field,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFieldPositionClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFieldPosition, RGM_SAME_DOMAIN,
                EIID_ICFieldPositionClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithAttributeField(attribute, field, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 field,
        /* [out] */ Elastos::Text::IFieldPosition** __IFieldPosition)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(field, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFieldPosition = (Elastos::Text::IFieldPosition*)__pNewObj->Probe(Elastos::Text::EIID_IFieldPosition);
        if (*__IFieldPosition) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 field,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(field, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 field,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(field, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 field,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(field, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIteratorAttribute * attribute,
        /* [out] */ Elastos::Text::IFieldPosition** __IFieldPosition)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(attribute, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFieldPosition = (Elastos::Text::IFieldPosition*)__pNewObj->Probe(Elastos::Text::EIID_IFieldPosition);
        if (*__IFieldPosition) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIteratorAttribute * attribute,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(attribute, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIteratorAttribute * attribute,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(attribute, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIteratorAttribute * attribute,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(attribute, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIteratorAttribute * attribute,
        /* [in] */ _ELASTOS Int32 field,
        /* [out] */ Elastos::Text::IFieldPosition** __IFieldPosition)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(attribute, field, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFieldPosition = (Elastos::Text::IFieldPosition*)__pNewObj->Probe(Elastos::Text::EIID_IFieldPosition);
        if (*__IFieldPosition) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIteratorAttribute * attribute,
        /* [in] */ _ELASTOS Int32 field,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(attribute, field, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIteratorAttribute * attribute,
        /* [in] */ _ELASTOS Int32 field,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(attribute, field, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIteratorAttribute * attribute,
        /* [in] */ _ELASTOS Int32 field,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(attribute, field, &__pNewObj);
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
namespace Text {
class CParsePosition
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICParsePositionClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CParsePosition, RGM_SAME_DOMAIN,
                EIID_ICParsePositionClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIndex(index, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ Elastos::Text::IParsePosition** __IParsePosition)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(index, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IParsePosition = (Elastos::Text::IParsePosition*)__pNewObj->Probe(Elastos::Text::EIID_IParsePosition);
        if (*__IParsePosition) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(index, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(index, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(index, &__pNewObj);
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
namespace Text {
class CAttributedString
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * iterator,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAttributedStringClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAttributedString, RGM_SAME_DOMAIN,
                EIID_ICAttributedStringClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIterator(iterator, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * iterator,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAttributedStringClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAttributedString, RGM_SAME_DOMAIN,
                EIID_ICAttributedStringClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIteratorStartEnd(iterator, start, end, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * iterator,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Text::IAttributedCharacterIteratorAttribute *> * attributes,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAttributedStringClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAttributedString, RGM_SAME_DOMAIN,
                EIID_ICAttributedStringClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIteratorStartEndAttributes(iterator, start, end, attributes, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAttributedStringClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAttributedString, RGM_SAME_DOMAIN,
                EIID_ICAttributedStringClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithValue(value, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * iterator,
        /* [out] */ Elastos::Text::IAttributedString** __IAttributedString)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iterator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAttributedString = (Elastos::Text::IAttributedString*)__pNewObj->Probe(Elastos::Text::EIID_IAttributedString);
        if (*__IAttributedString) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * iterator,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iterator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * iterator,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iterator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * iterator,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iterator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * iterator,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ Elastos::Text::IAttributedString** __IAttributedString)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iterator, start, end, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAttributedString = (Elastos::Text::IAttributedString*)__pNewObj->Probe(Elastos::Text::EIID_IAttributedString);
        if (*__IAttributedString) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * iterator,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iterator, start, end, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * iterator,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iterator, start, end, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * iterator,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iterator, start, end, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * iterator,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Text::IAttributedCharacterIteratorAttribute *> * attributes,
        /* [out] */ Elastos::Text::IAttributedString** __IAttributedString)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iterator, start, end, attributes, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAttributedString = (Elastos::Text::IAttributedString*)__pNewObj->Probe(Elastos::Text::EIID_IAttributedString);
        if (*__IAttributedString) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * iterator,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Text::IAttributedCharacterIteratorAttribute *> * attributes,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iterator, start, end, attributes, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * iterator,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Text::IAttributedCharacterIteratorAttribute *> * attributes,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iterator, start, end, attributes, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Text::IAttributedCharacterIterator * iterator,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Text::IAttributedCharacterIteratorAttribute *> * attributes,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iterator, start, end, attributes, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ Elastos::Text::IAttributedString** __IAttributedString)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAttributedString = (Elastos::Text::IAttributedString*)__pNewObj->Probe(Elastos::Text::EIID_IAttributedString);
        if (*__IAttributedString) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
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
namespace Text {
class CChoiceFormat
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Double> * limits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * formats,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICChoiceFormatClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CChoiceFormat, RGM_SAME_DOMAIN,
                EIID_ICChoiceFormatClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithLimitsFormats(limits, formats, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& tem,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICChoiceFormatClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CChoiceFormat, RGM_SAME_DOMAIN,
                EIID_ICChoiceFormatClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTem(tem, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Double> * limits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * formats,
        /* [out] */ Elastos::Text::IChoiceFormat** __IChoiceFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(limits, formats, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IChoiceFormat = (Elastos::Text::IChoiceFormat*)__pNewObj->Probe(Elastos::Text::EIID_IChoiceFormat);
        if (*__IChoiceFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Double> * limits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * formats,
        /* [out] */ Elastos::Text::INumberFormat** __INumberFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(limits, formats, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumberFormat = (Elastos::Text::INumberFormat*)__pNewObj->Probe(Elastos::Text::EIID_INumberFormat);
        if (*__INumberFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Double> * limits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * formats,
        /* [out] */ Elastos::Text::IFormat** __IFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(limits, formats, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFormat = (Elastos::Text::IFormat*)__pNewObj->Probe(Elastos::Text::EIID_IFormat);
        if (*__IFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Double> * limits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * formats,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(limits, formats, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Double> * limits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * formats,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(limits, formats, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Double> * limits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * formats,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(limits, formats, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Double> * limits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * formats,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(limits, formats, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Double> * limits,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * formats,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(limits, formats, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& tem,
        /* [out] */ Elastos::Text::IChoiceFormat** __IChoiceFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tem, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IChoiceFormat = (Elastos::Text::IChoiceFormat*)__pNewObj->Probe(Elastos::Text::EIID_IChoiceFormat);
        if (*__IChoiceFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& tem,
        /* [out] */ Elastos::Text::INumberFormat** __INumberFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tem, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumberFormat = (Elastos::Text::INumberFormat*)__pNewObj->Probe(Elastos::Text::EIID_INumberFormat);
        if (*__INumberFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& tem,
        /* [out] */ Elastos::Text::IFormat** __IFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tem, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFormat = (Elastos::Text::IFormat*)__pNewObj->Probe(Elastos::Text::EIID_IFormat);
        if (*__IFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& tem,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tem, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& tem,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tem, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& tem,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tem, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& tem,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tem, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& tem,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tem, &__pNewObj);
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
namespace Text {
class CChoiceFormatHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Text::IChoiceFormatHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CChoiceFormatHelper, RGM_SAME_DOMAIN, Elastos::Text::EIID_IChoiceFormatHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CChoiceFormatHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CChoiceFormatHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CChoiceFormatHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Text {
class CNumberFormatField
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& fieldName,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICNumberFormatFieldClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CNumberFormatField, RGM_SAME_DOMAIN,
                EIID_ICNumberFormatFieldClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFieldName(fieldName, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fieldName,
        /* [out] */ Elastos::Text::INumberFormatField** __INumberFormatField)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fieldName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumberFormatField = (Elastos::Text::INumberFormatField*)__pNewObj->Probe(Elastos::Text::EIID_INumberFormatField);
        if (*__INumberFormatField) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fieldName,
        /* [out] */ Elastos::Text::IAttributedCharacterIteratorAttribute** __IAttributedCharacterIteratorAttribute)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fieldName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAttributedCharacterIteratorAttribute = (Elastos::Text::IAttributedCharacterIteratorAttribute*)__pNewObj->Probe(Elastos::Text::EIID_IAttributedCharacterIteratorAttribute);
        if (*__IAttributedCharacterIteratorAttribute) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fieldName,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fieldName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fieldName,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fieldName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fieldName,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fieldName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fieldName,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fieldName, &__pNewObj);
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
namespace Text {
class CNumberFormatHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Text::INumberFormatHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNumberFormatHelper, RGM_SAME_DOMAIN, Elastos::Text::EIID_INumberFormatHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNumberFormatHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNumberFormatHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNumberFormatHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Text {
class CDecimalFormat
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDecimalFormatClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDecimalFormat, RGM_SAME_DOMAIN,
                EIID_ICDecimalFormatClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPattern(pattern, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Text::IDecimalFormatSymbols * value,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDecimalFormatClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDecimalFormat, RGM_SAME_DOMAIN,
                EIID_ICDecimalFormatClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPatternValue(pattern, value, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDecimalFormatClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDecimalFormat, RGM_SAME_DOMAIN,
                EIID_ICDecimalFormatClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPatternLocale(pattern, locale, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Text::IDecimalFormat** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDecimalFormat, RGM_SAME_DOMAIN, Elastos::Text::EIID_IDecimalFormat, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Text::INumberFormat** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDecimalFormat, RGM_SAME_DOMAIN, Elastos::Text::EIID_INumberFormat, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Text::IFormat** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDecimalFormat, RGM_SAME_DOMAIN, Elastos::Text::EIID_IFormat, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDecimalFormat, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDecimalFormat, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDecimalFormat, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDecimalFormat, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDecimalFormat, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [out] */ Elastos::Text::IDecimalFormat** __IDecimalFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDecimalFormat = (Elastos::Text::IDecimalFormat*)__pNewObj->Probe(Elastos::Text::EIID_IDecimalFormat);
        if (*__IDecimalFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [out] */ Elastos::Text::INumberFormat** __INumberFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumberFormat = (Elastos::Text::INumberFormat*)__pNewObj->Probe(Elastos::Text::EIID_INumberFormat);
        if (*__INumberFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [out] */ Elastos::Text::IFormat** __IFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFormat = (Elastos::Text::IFormat*)__pNewObj->Probe(Elastos::Text::EIID_IFormat);
        if (*__IFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Text::IDecimalFormatSymbols * value,
        /* [out] */ Elastos::Text::IDecimalFormat** __IDecimalFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDecimalFormat = (Elastos::Text::IDecimalFormat*)__pNewObj->Probe(Elastos::Text::EIID_IDecimalFormat);
        if (*__IDecimalFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Text::IDecimalFormatSymbols * value,
        /* [out] */ Elastos::Text::INumberFormat** __INumberFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumberFormat = (Elastos::Text::INumberFormat*)__pNewObj->Probe(Elastos::Text::EIID_INumberFormat);
        if (*__INumberFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Text::IDecimalFormatSymbols * value,
        /* [out] */ Elastos::Text::IFormat** __IFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFormat = (Elastos::Text::IFormat*)__pNewObj->Probe(Elastos::Text::EIID_IFormat);
        if (*__IFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Text::IDecimalFormatSymbols * value,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Text::IDecimalFormatSymbols * value,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Text::IDecimalFormatSymbols * value,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Text::IDecimalFormatSymbols * value,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Text::IDecimalFormatSymbols * value,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Text::IDecimalFormat** __IDecimalFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDecimalFormat = (Elastos::Text::IDecimalFormat*)__pNewObj->Probe(Elastos::Text::EIID_IDecimalFormat);
        if (*__IDecimalFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Text::INumberFormat** __INumberFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumberFormat = (Elastos::Text::INumberFormat*)__pNewObj->Probe(Elastos::Text::EIID_INumberFormat);
        if (*__INumberFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Text::IFormat** __IFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFormat = (Elastos::Text::IFormat*)__pNewObj->Probe(Elastos::Text::EIID_IFormat);
        if (*__IFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, locale, &__pNewObj);
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
namespace Text {
class CDecimalFormatSymbols
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDecimalFormatSymbolsClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDecimalFormatSymbols, RGM_SAME_DOMAIN,
                EIID_ICDecimalFormatSymbolsClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithLocale(locale, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Text::IDecimalFormatSymbols** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDecimalFormatSymbols, RGM_SAME_DOMAIN, Elastos::Text::EIID_IDecimalFormatSymbols, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDecimalFormatSymbols, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDecimalFormatSymbols, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDecimalFormatSymbols, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDecimalFormatSymbols, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDecimalFormatSymbols, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Text::IDecimalFormatSymbols** __IDecimalFormatSymbols)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDecimalFormatSymbols = (Elastos::Text::IDecimalFormatSymbols*)__pNewObj->Probe(Elastos::Text::EIID_IDecimalFormatSymbols);
        if (*__IDecimalFormatSymbols) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locale, &__pNewObj);
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
namespace Text {
class CDecimalFormatSymbolsHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Text::IDecimalFormatSymbolsHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDecimalFormatSymbolsHelper, RGM_SAME_DOMAIN, Elastos::Text::EIID_IDecimalFormatSymbolsHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDecimalFormatSymbolsHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDecimalFormatSymbolsHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDecimalFormatSymbolsHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Text {
class CMessageFormat
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& tem,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICMessageFormatClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CMessageFormat, RGM_SAME_DOMAIN,
                EIID_ICMessageFormatClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTemLocale(tem, locale, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& tem,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICMessageFormatClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CMessageFormat, RGM_SAME_DOMAIN,
                EIID_ICMessageFormatClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTem(tem, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& tem,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Text::IMessageFormat** __IMessageFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tem, locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMessageFormat = (Elastos::Text::IMessageFormat*)__pNewObj->Probe(Elastos::Text::EIID_IMessageFormat);
        if (*__IMessageFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& tem,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Text::IFormat** __IFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tem, locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFormat = (Elastos::Text::IFormat*)__pNewObj->Probe(Elastos::Text::EIID_IFormat);
        if (*__IFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& tem,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tem, locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& tem,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tem, locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& tem,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tem, locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& tem,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tem, locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& tem,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tem, locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& tem,
        /* [out] */ Elastos::Text::IMessageFormat** __IMessageFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tem, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMessageFormat = (Elastos::Text::IMessageFormat*)__pNewObj->Probe(Elastos::Text::EIID_IMessageFormat);
        if (*__IMessageFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& tem,
        /* [out] */ Elastos::Text::IFormat** __IFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tem, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFormat = (Elastos::Text::IFormat*)__pNewObj->Probe(Elastos::Text::EIID_IFormat);
        if (*__IFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& tem,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tem, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& tem,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tem, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& tem,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tem, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& tem,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tem, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& tem,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(tem, &__pNewObj);
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
namespace Text {
class CSimpleDateFormat
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSimpleDateFormatClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSimpleDateFormat, RGM_SAME_DOMAIN,
                EIID_ICSimpleDateFormatClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPattern(pattern, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& temp,
        /* [in] */ Elastos::Text::IDateFormatSymbols * value,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSimpleDateFormatClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSimpleDateFormat, RGM_SAME_DOMAIN,
                EIID_ICSimpleDateFormatClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTempValue(temp, value, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& temp,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSimpleDateFormatClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSimpleDateFormat, RGM_SAME_DOMAIN,
                EIID_ICSimpleDateFormatClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithTempLocale(temp, locale, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Text::ISimpleDateFormat** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSimpleDateFormat, RGM_SAME_DOMAIN, Elastos::Text::EIID_ISimpleDateFormat, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Text::IDateFormat** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSimpleDateFormat, RGM_SAME_DOMAIN, Elastos::Text::EIID_IDateFormat, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Text::IFormat** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSimpleDateFormat, RGM_SAME_DOMAIN, Elastos::Text::EIID_IFormat, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSimpleDateFormat, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSimpleDateFormat, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSimpleDateFormat, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSimpleDateFormat, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSimpleDateFormat, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [out] */ Elastos::Text::ISimpleDateFormat** __ISimpleDateFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISimpleDateFormat = (Elastos::Text::ISimpleDateFormat*)__pNewObj->Probe(Elastos::Text::EIID_ISimpleDateFormat);
        if (*__ISimpleDateFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [out] */ Elastos::Text::IDateFormat** __IDateFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDateFormat = (Elastos::Text::IDateFormat*)__pNewObj->Probe(Elastos::Text::EIID_IDateFormat);
        if (*__IDateFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [out] */ Elastos::Text::IFormat** __IFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFormat = (Elastos::Text::IFormat*)__pNewObj->Probe(Elastos::Text::EIID_IFormat);
        if (*__IFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& temp,
        /* [in] */ Elastos::Text::IDateFormatSymbols * value,
        /* [out] */ Elastos::Text::ISimpleDateFormat** __ISimpleDateFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(temp, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISimpleDateFormat = (Elastos::Text::ISimpleDateFormat*)__pNewObj->Probe(Elastos::Text::EIID_ISimpleDateFormat);
        if (*__ISimpleDateFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& temp,
        /* [in] */ Elastos::Text::IDateFormatSymbols * value,
        /* [out] */ Elastos::Text::IDateFormat** __IDateFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(temp, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDateFormat = (Elastos::Text::IDateFormat*)__pNewObj->Probe(Elastos::Text::EIID_IDateFormat);
        if (*__IDateFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& temp,
        /* [in] */ Elastos::Text::IDateFormatSymbols * value,
        /* [out] */ Elastos::Text::IFormat** __IFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(temp, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFormat = (Elastos::Text::IFormat*)__pNewObj->Probe(Elastos::Text::EIID_IFormat);
        if (*__IFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& temp,
        /* [in] */ Elastos::Text::IDateFormatSymbols * value,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(temp, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& temp,
        /* [in] */ Elastos::Text::IDateFormatSymbols * value,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(temp, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& temp,
        /* [in] */ Elastos::Text::IDateFormatSymbols * value,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(temp, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& temp,
        /* [in] */ Elastos::Text::IDateFormatSymbols * value,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(temp, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& temp,
        /* [in] */ Elastos::Text::IDateFormatSymbols * value,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(temp, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& temp,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Text::ISimpleDateFormat** __ISimpleDateFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(temp, locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISimpleDateFormat = (Elastos::Text::ISimpleDateFormat*)__pNewObj->Probe(Elastos::Text::EIID_ISimpleDateFormat);
        if (*__ISimpleDateFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& temp,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Text::IDateFormat** __IDateFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(temp, locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDateFormat = (Elastos::Text::IDateFormat*)__pNewObj->Probe(Elastos::Text::EIID_IDateFormat);
        if (*__IDateFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& temp,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Text::IFormat** __IFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(temp, locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFormat = (Elastos::Text::IFormat*)__pNewObj->Probe(Elastos::Text::EIID_IFormat);
        if (*__IFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& temp,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(temp, locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& temp,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(temp, locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& temp,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(temp, locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& temp,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(temp, locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& temp,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(temp, locale, &__pNewObj);
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
namespace Text {
class CDateFormatHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Text::IDateFormatHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDateFormatHelper, RGM_SAME_DOMAIN, Elastos::Text::EIID_IDateFormatHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDateFormatHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDateFormatHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDateFormatHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Text {
class CNormalizerHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Text::INormalizer** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNormalizerHelper, RGM_SAME_DOMAIN, Elastos::Text::EIID_INormalizer, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNormalizerHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNormalizerHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNormalizerHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Text {
class CMessageFormatField
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICMessageFormatFieldClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CMessageFormatField, RGM_SAME_DOMAIN,
                EIID_ICMessageFormatFieldClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithName(name, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Text::IMessageFormatField** __IMessageFormatField)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMessageFormatField = (Elastos::Text::IMessageFormatField*)__pNewObj->Probe(Elastos::Text::EIID_IMessageFormatField);
        if (*__IMessageFormatField) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Text::IAttributedCharacterIteratorAttribute** __IAttributedCharacterIteratorAttribute)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAttributedCharacterIteratorAttribute = (Elastos::Text::IAttributedCharacterIteratorAttribute*)__pNewObj->Probe(Elastos::Text::EIID_IAttributedCharacterIteratorAttribute);
        if (*__IAttributedCharacterIteratorAttribute) __pNewObj->AddRef();
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

};
}
}
namespace Elastos {
namespace Text {
class CDateFormatSymbols
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDateFormatSymbolsClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDateFormatSymbols, RGM_SAME_DOMAIN,
                EIID_ICDateFormatSymbolsClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithLocale(locale, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Text::IDateFormatSymbols** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDateFormatSymbols, RGM_SAME_DOMAIN, Elastos::Text::EIID_IDateFormatSymbols, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ISerializable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDateFormatSymbols, RGM_SAME_DOMAIN, Elastos::IO::EIID_ISerializable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDateFormatSymbols, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDateFormatSymbols, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDateFormatSymbols, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDateFormatSymbols, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Text::IDateFormatSymbols** __IDateFormatSymbols)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDateFormatSymbols = (Elastos::Text::IDateFormatSymbols*)__pNewObj->Probe(Elastos::Text::EIID_IDateFormatSymbols);
        if (*__IDateFormatSymbols) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locale, &__pNewObj);
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
namespace Text {
class CDateFormatField
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& fieldName,
        /* [in] */ _ELASTOS Int32 calendarField,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDateFormatFieldClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDateFormatField, RGM_SAME_DOMAIN,
                EIID_ICDateFormatFieldClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithFieldNameCalendarField(fieldName, calendarField, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fieldName,
        /* [in] */ _ELASTOS Int32 calendarField,
        /* [out] */ Elastos::Text::IDateFormatField** __IDateFormatField)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fieldName, calendarField, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDateFormatField = (Elastos::Text::IDateFormatField*)__pNewObj->Probe(Elastos::Text::EIID_IDateFormatField);
        if (*__IDateFormatField) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fieldName,
        /* [in] */ _ELASTOS Int32 calendarField,
        /* [out] */ Elastos::Text::IAttributedCharacterIteratorAttribute** __IAttributedCharacterIteratorAttribute)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fieldName, calendarField, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAttributedCharacterIteratorAttribute = (Elastos::Text::IAttributedCharacterIteratorAttribute*)__pNewObj->Probe(Elastos::Text::EIID_IAttributedCharacterIteratorAttribute);
        if (*__IAttributedCharacterIteratorAttribute) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fieldName,
        /* [in] */ _ELASTOS Int32 calendarField,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fieldName, calendarField, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fieldName,
        /* [in] */ _ELASTOS Int32 calendarField,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fieldName, calendarField, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fieldName,
        /* [in] */ _ELASTOS Int32 calendarField,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fieldName, calendarField, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& fieldName,
        /* [in] */ _ELASTOS Int32 calendarField,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(fieldName, calendarField, &__pNewObj);
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
namespace Text {
class CDateFormatSymbolsHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Text::IDateFormatSymbolsHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDateFormatSymbolsHelper, RGM_SAME_DOMAIN, Elastos::Text::EIID_IDateFormatSymbolsHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDateFormatSymbolsHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDateFormatSymbolsHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDateFormatSymbolsHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Text {
class CCollationElementIterator
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Libcore::ICU::ICollationElementIteratorICU * iterator,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCollationElementIteratorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCollationElementIterator, RGM_SAME_DOMAIN,
                EIID_ICCollationElementIteratorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIterator(iterator, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Libcore::ICU::ICollationElementIteratorICU * iterator,
        /* [out] */ Elastos::Text::ICollationElementIterator** __ICollationElementIterator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iterator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollationElementIterator = (Elastos::Text::ICollationElementIterator*)__pNewObj->Probe(Elastos::Text::EIID_ICollationElementIterator);
        if (*__ICollationElementIterator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Libcore::ICU::ICollationElementIteratorICU * iterator,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iterator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Libcore::ICU::ICollationElementIteratorICU * iterator,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iterator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Libcore::ICU::ICollationElementIteratorICU * iterator,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(iterator, &__pNewObj);
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
namespace Text {
class CCollationElementIteratorHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Text::ICollationElementIteratorHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollationElementIteratorHelper, RGM_SAME_DOMAIN, Elastos::Text::EIID_ICollationElementIteratorHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollationElementIteratorHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollationElementIteratorHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollationElementIteratorHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Elastos {
namespace Text {
class CRuleBasedCollator
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Libcore::ICU::IRuleBasedCollatorICU * wrapper,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICRuleBasedCollatorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CRuleBasedCollator, RGM_SAME_DOMAIN,
                EIID_ICRuleBasedCollatorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithWrapper(wrapper, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& rules,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICRuleBasedCollatorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CRuleBasedCollator, RGM_SAME_DOMAIN,
                EIID_ICRuleBasedCollatorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithRules(rules, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Libcore::ICU::IRuleBasedCollatorICU * wrapper,
        /* [out] */ Elastos::Text::IRuleBasedCollator** __IRuleBasedCollator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wrapper, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRuleBasedCollator = (Elastos::Text::IRuleBasedCollator*)__pNewObj->Probe(Elastos::Text::EIID_IRuleBasedCollator);
        if (*__IRuleBasedCollator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Libcore::ICU::IRuleBasedCollatorICU * wrapper,
        /* [out] */ Elastos::Text::ICollator** __ICollator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wrapper, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollator = (Elastos::Text::ICollator*)__pNewObj->Probe(Elastos::Text::EIID_ICollator);
        if (*__ICollator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Libcore::ICU::IRuleBasedCollatorICU * wrapper,
        /* [out] */ Elastos::Core::IComparator** __IComparator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wrapper, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparator = (Elastos::Core::IComparator*)__pNewObj->Probe(Elastos::Core::EIID_IComparator);
        if (*__IComparator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Libcore::ICU::IRuleBasedCollatorICU * wrapper,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wrapper, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Libcore::ICU::IRuleBasedCollatorICU * wrapper,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wrapper, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Libcore::ICU::IRuleBasedCollatorICU * wrapper,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wrapper, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Libcore::ICU::IRuleBasedCollatorICU * wrapper,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(wrapper, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& rules,
        /* [out] */ Elastos::Text::IRuleBasedCollator** __IRuleBasedCollator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rules, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRuleBasedCollator = (Elastos::Text::IRuleBasedCollator*)__pNewObj->Probe(Elastos::Text::EIID_IRuleBasedCollator);
        if (*__IRuleBasedCollator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& rules,
        /* [out] */ Elastos::Text::ICollator** __ICollator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rules, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollator = (Elastos::Text::ICollator*)__pNewObj->Probe(Elastos::Text::EIID_ICollator);
        if (*__ICollator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& rules,
        /* [out] */ Elastos::Core::IComparator** __IComparator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rules, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparator = (Elastos::Core::IComparator*)__pNewObj->Probe(Elastos::Core::EIID_IComparator);
        if (*__IComparator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& rules,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rules, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& rules,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rules, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& rules,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rules, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& rules,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rules, &__pNewObj);
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
namespace Text {
class CStringCharacterIterator
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStringCharacterIteratorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStringCharacterIterator, RGM_SAME_DOMAIN,
                EIID_ICStringCharacterIteratorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithValue(value, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStringCharacterIteratorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStringCharacterIterator, RGM_SAME_DOMAIN,
                EIID_ICStringCharacterIteratorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithValueLocation(value, location, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStringCharacterIteratorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStringCharacterIterator, RGM_SAME_DOMAIN,
                EIID_ICStringCharacterIteratorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithValueStartEndLocation(value, start, end, location, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ Elastos::Text::IStringCharacterIterator** __IStringCharacterIterator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStringCharacterIterator = (Elastos::Text::IStringCharacterIterator*)__pNewObj->Probe(Elastos::Text::EIID_IStringCharacterIterator);
        if (*__IStringCharacterIterator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ Elastos::Text::ICharacterIterator** __ICharacterIterator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICharacterIterator = (Elastos::Text::ICharacterIterator*)__pNewObj->Probe(Elastos::Text::EIID_ICharacterIterator);
        if (*__ICharacterIterator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ Elastos::Text::IStringCharacterIterator** __IStringCharacterIterator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, location, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStringCharacterIterator = (Elastos::Text::IStringCharacterIterator*)__pNewObj->Probe(Elastos::Text::EIID_IStringCharacterIterator);
        if (*__IStringCharacterIterator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ Elastos::Text::ICharacterIterator** __ICharacterIterator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, location, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICharacterIterator = (Elastos::Text::ICharacterIterator*)__pNewObj->Probe(Elastos::Text::EIID_ICharacterIterator);
        if (*__ICharacterIterator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, location, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, location, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, location, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, location, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ Elastos::Text::IStringCharacterIterator** __IStringCharacterIterator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, start, end, location, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStringCharacterIterator = (Elastos::Text::IStringCharacterIterator*)__pNewObj->Probe(Elastos::Text::EIID_IStringCharacterIterator);
        if (*__IStringCharacterIterator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ Elastos::Text::ICharacterIterator** __ICharacterIterator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, start, end, location, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICharacterIterator = (Elastos::Text::ICharacterIterator*)__pNewObj->Probe(Elastos::Text::EIID_ICharacterIterator);
        if (*__ICharacterIterator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, start, end, location, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, start, end, location, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, start, end, location, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, start, end, location, &__pNewObj);
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
namespace Text {
class CCollatorHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Text::ICollatorHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollatorHelper, RGM_SAME_DOMAIN, Elastos::Text::EIID_ICollatorHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollatorHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollatorHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollatorHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}

#endif // __Elastos_CoreLibrary_Text_h__
