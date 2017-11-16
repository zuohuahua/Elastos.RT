#ifndef ___Elastos_CoreLibrary_Libcore_h__
#define ___Elastos_CoreLibrary_Libcore_h__

#include <Elastos.CoreLibrary.h>

EXTERN_C ELAPI _Impl_AcquireCallbackHandler(PInterface pServerObj, _ELASTOS REIID iid, PInterface *ppHandler);
EXTERN_C ELAPI _Impl_CheckClsId(PInterface pServerObj, const _ELASTOS ClassID* pClassid, PInterface *ppServerObj);

namespace Libcore {
namespace ICU {
CAR_INTERFACE("C20E1D5A-9152-9D96-2958-93C0C0C38F0A")
ICollationKeyICU : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICollationKeyICU*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollationKeyICU*)pObj->Probe(EIID_ICollationKeyICU);
    }

    static CARAPI_(ICollationKeyICU*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollationKeyICU*)pObj->Probe(EIID_ICollationKeyICU);
    }

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("1BC9F027-4752-3F4C-2E9A-C88FE2870406")
ILocaleData : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILocaleData*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILocaleData*)pObj->Probe(EIID_ILocaleData);
    }

    static CARAPI_(ILocaleData*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILocaleData*)pObj->Probe(EIID_ILocaleData);
    }

    virtual CARAPI GetDateFormat(
        /* [in] */ Libcore::ICU::DateFormat style,
        /* [out] */ _ELASTOS String * format) = 0;

    virtual CARAPI GetTimeFormat(
        /* [in] */ Libcore::ICU::DateFormat style,
        /* [out] */ _ELASTOS String * format) = 0;

    virtual CARAPI GetFirstDayOfWeek(
        /* [out] */ Elastos::Core::IInteger32 ** day) = 0;

    virtual CARAPI GetMinimalDaysInFirstWeek(
        /* [out] */ Elastos::Core::IInteger32 ** days) = 0;

    virtual CARAPI GetAmPm(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** amPm) = 0;

    virtual CARAPI GetEras(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** eras) = 0;

    virtual CARAPI GetLongMonthNames(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** names) = 0;

    virtual CARAPI GetShortMonthNames(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** names) = 0;

    virtual CARAPI GetTinyMonthNames(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** names) = 0;

    virtual CARAPI GetLongStandAloneMonthNames(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** names) = 0;

    virtual CARAPI GetShortStandAloneMonthNames(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** names) = 0;

    virtual CARAPI GetTinyStandAloneMonthNames(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** names) = 0;

    virtual CARAPI GetLongWeekdayNames(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** names) = 0;

    virtual CARAPI GetShortWeekdayNames(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** names) = 0;

    virtual CARAPI GetTinyWeekdayNames(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** names) = 0;

    virtual CARAPI GetLongStandAloneWeekdayNames(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** names) = 0;

    virtual CARAPI GetShortStandAloneWeekdayNames(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** names) = 0;

    virtual CARAPI GetTinyStandAloneWeekdayNames(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** names) = 0;

    virtual CARAPI GetYesterday(
        /* [out] */ _ELASTOS String * yesterday) = 0;

    virtual CARAPI GetToday(
        /* [out] */ _ELASTOS String * today) = 0;

    virtual CARAPI GetTomorrow(
        /* [out] */ _ELASTOS String * tomorrow) = 0;

    virtual CARAPI GetFullTimeFormat(
        /* [out] */ _ELASTOS String * fullTimeFormat) = 0;

    virtual CARAPI GetLongTimeFormat(
        /* [out] */ _ELASTOS String * longTimeFormat) = 0;

    virtual CARAPI GetMediumTimeFormat(
        /* [out] */ _ELASTOS String * mediumTimeFormat) = 0;

    virtual CARAPI GetShortTimeFormat(
        /* [out] */ _ELASTOS String * shortTimeFormat) = 0;

    virtual CARAPI GetFullDateFormat(
        /* [out] */ _ELASTOS String * fullDateFormat) = 0;

    virtual CARAPI GetLongDateFormat(
        /* [out] */ _ELASTOS String * longDateFormat) = 0;

    virtual CARAPI GetMediumDateFormat(
        /* [out] */ _ELASTOS String * mediumDateFormat) = 0;

    virtual CARAPI GetShortDateFormat(
        /* [out] */ _ELASTOS String * shortDateFormat) = 0;

    virtual CARAPI GetNarrowAm(
        /* [out] */ _ELASTOS String * narrowAm) = 0;

    virtual CARAPI GetNarrowPm(
        /* [out] */ _ELASTOS String * narrowPm) = 0;

    virtual CARAPI GetShortDateFormat4(
        /* [out] */ _ELASTOS String * shortDateFormat4) = 0;

    virtual CARAPI GetZeroDigit(
        /* [out] */ _ELASTOS Char32 * zeroDigit) = 0;

    virtual CARAPI GetDecimalSeparator(
        /* [out] */ _ELASTOS Char32 * decimalSeparator) = 0;

    virtual CARAPI GetGroupingSeparator(
        /* [out] */ _ELASTOS Char32 * groupingSeparator) = 0;

    virtual CARAPI GetPatternSeparator(
        /* [out] */ _ELASTOS Char32 * patternSeparator) = 0;

    virtual CARAPI GetPercent(
        /* [out] */ _ELASTOS Char32 * percent) = 0;

    virtual CARAPI GetPerMill(
        /* [out] */ _ELASTOS Char32 * perMill) = 0;

    virtual CARAPI GetMonetarySeparator(
        /* [out] */ _ELASTOS Char32 * monetarySeparator) = 0;

    virtual CARAPI GetMinusSign(
        /* [out] */ _ELASTOS String * minusSign) = 0;

    virtual CARAPI GetExponentSeparator(
        /* [out] */ _ELASTOS String * exponentSeparator) = 0;

    virtual CARAPI GetInfinity(
        /* [out] */ _ELASTOS String * infinity) = 0;

    virtual CARAPI GetNaN(
        /* [out] */ _ELASTOS String * naN) = 0;

    virtual CARAPI GetCurrencySymbol(
        /* [out] */ _ELASTOS String * currencySymbol) = 0;

    virtual CARAPI GetInternationalCurrencySymbol(
        /* [out] */ _ELASTOS String * internationalCurrencySymbol) = 0;

    virtual CARAPI GetTimeFormat12(
        /* [out] */ _ELASTOS String * format) = 0;

    virtual CARAPI GetTimeFormat24(
        /* [out] */ _ELASTOS String * format) = 0;

    virtual CARAPI GetNumberPattern(
        /* [out] */ _ELASTOS String * numberPattern) = 0;

    virtual CARAPI GetIntegerPattern(
        /* [out] */ _ELASTOS String * numberPattern) = 0;

    virtual CARAPI GetCurrencyPattern(
        /* [out] */ _ELASTOS String * currencyPattern) = 0;

    virtual CARAPI GetPercentPattern(
        /* [out] */ _ELASTOS String * percentPattern) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("7D573935-4752-114C-50BC-9871FFC74513")
ILocaleDataHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILocaleDataHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILocaleDataHelper*)pObj->Probe(EIID_ILocaleDataHelper);
    }

    static CARAPI_(ILocaleDataHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILocaleDataHelper*)pObj->Probe(EIID_ILocaleDataHelper);
    }

    virtual CARAPI MapInvalidAndNullLocales(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Utility::ILocale ** rst) = 0;

    virtual CARAPI Get(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Libcore::ICU::ILocaleData ** localeData) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("663EE00F-C492-DE78-CDBE-7FC596A65CA3")
IICUUtil : public IInterface
{
    static const _ELASTOS Int32 U_ZERO_ERROR = 0;
    static const _ELASTOS Int32 U_INVALID_CHAR_FOUND = 10;
    static const _ELASTOS Int32 U_TRUNCATED_CHAR_FOUND = 11;
    static const _ELASTOS Int32 U_ILLEGAL_CHAR_FOUND = 12;
    static const _ELASTOS Int32 U_BUFFER_OVERFLOW_ERROR = 15;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IICUUtil*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IICUUtil*)pObj->Probe(EIID_IICUUtil);
    }

    static CARAPI_(IICUUtil*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IICUUtil*)pObj->Probe(EIID_IICUUtil);
    }

    virtual CARAPI GetISOLanguages(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** languages) = 0;

    virtual CARAPI GetISOCountries(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** countries) = 0;

    virtual CARAPI LocaleFromIcuLocaleId(
        /* [in] */ const _ELASTOS String& localeId,
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI LocalesFromStrings(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * localeNames,
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Utility::ILocale *> ** locales) = 0;

    virtual CARAPI GetAvailableLocales(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Utility::ILocale *> ** locales) = 0;

    virtual CARAPI GetAvailableBreakIteratorLocales(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Utility::ILocale *> ** locales) = 0;

    virtual CARAPI GetAvailableCalendarLocales(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Utility::ILocale *> ** locales) = 0;

    virtual CARAPI GetAvailableCollatorLocales(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Utility::ILocale *> ** locales) = 0;

    virtual CARAPI GetAvailableDateFormatLocales(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Utility::ILocale *> ** locales) = 0;

    virtual CARAPI GetAvailableDateFormatSymbolsLocales(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Utility::ILocale *> ** locales) = 0;

    virtual CARAPI GetAvailableDecimalFormatSymbolsLocales(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Utility::ILocale *> ** locales) = 0;

    virtual CARAPI GetAvailableNumberFormatLocales(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Utility::ILocale *> ** locales) = 0;

    virtual CARAPI GetBestDateTimePattern(
        /* [in] */ const _ELASTOS String& skeleton,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ _ELASTOS String * rst) = 0;

    virtual CARAPI GetDateFormatOrder(
        /* [in] */ const _ELASTOS String& pattern,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Char32> ** locales) = 0;

    virtual CARAPI GetCldrVersion(
        /* [out] */ _ELASTOS String * cldrVersion) = 0;

    virtual CARAPI GetIcuVersion(
        /* [out] */ _ELASTOS String * icuVersion) = 0;

    virtual CARAPI GetUnicodeVersion(
        /* [out] */ _ELASTOS String * unicodeVersion) = 0;

    virtual CARAPI ToLowerCase(
        /* [in] */ const _ELASTOS String& s,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ _ELASTOS String * ls) = 0;

    virtual CARAPI ToUpperCase(
        /* [in] */ const _ELASTOS String& s,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ _ELASTOS String * us) = 0;

    virtual CARAPI GetAvailableCurrencyCodes(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** codes) = 0;

    virtual CARAPI GetCurrencyCode(
        /* [in] */ const _ELASTOS String& locale,
        /* [out] */ _ELASTOS String * currencyCode) = 0;

    virtual CARAPI GetCurrencyDisplayName(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [in] */ const _ELASTOS String& currencyCode,
        /* [out] */ _ELASTOS String * displayName) = 0;

    virtual CARAPI GetCurrencyFractionDigits(
        /* [in] */ const _ELASTOS String& currencyCode,
        /* [out] */ _ELASTOS Int32 * currencyFractionDigits) = 0;

    virtual CARAPI GetCurrencyNumericCode(
        /* [in] */ const _ELASTOS String& currencyCode,
        /* [out] */ _ELASTOS Int32 * currencyFractionDigits) = 0;

    virtual CARAPI GetCurrencySymbol(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [in] */ const _ELASTOS String& currencyCode,
        /* [out] */ _ELASTOS String * currencySymbol) = 0;

    virtual CARAPI GetDisplayCountry(
        /* [in] */ Elastos::Utility::ILocale * targetLocale,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ _ELASTOS String * displayCountry) = 0;

    virtual CARAPI GetDisplayLanguage(
        /* [in] */ Elastos::Utility::ILocale * targetLocale,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ _ELASTOS String * displayLanguage) = 0;

    virtual CARAPI GetDisplayVariant(
        /* [in] */ Elastos::Utility::ILocale * variant,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ _ELASTOS String * displayVariant) = 0;

    virtual CARAPI GetDisplayScript(
        /* [in] */ Elastos::Utility::ILocale * targetLocale,
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ _ELASTOS String * script) = 0;

    virtual CARAPI GetISO3Country(
        /* [in] */ const _ELASTOS String& languageTag,
        /* [out] */ _ELASTOS String * ISO3country) = 0;

    virtual CARAPI GetISO3Language(
        /* [in] */ const _ELASTOS String& locale,
        /* [out] */ _ELASTOS String * ISO3Language) = 0;

    virtual CARAPI AddLikelySubtags(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Utility::ILocale ** target) = 0;

    virtual CARAPI AddLikelySubtags(
        /* [in] */ const _ELASTOS String& locale,
        /* [out] */ _ELASTOS String * result) = 0;

    virtual CARAPI GetScript(
        /* [in] */ const _ELASTOS String& locale,
        /* [out] */ _ELASTOS String * script) = 0;

    virtual CARAPI SetDefaultLocale(
        /* [in] */ const _ELASTOS String& languageTag) = 0;

    virtual CARAPI GetDefaultLocale(
        /* [out] */ _ELASTOS String * defaultLocale) = 0;

    virtual CARAPI UTF16ByteArrayToUTF8ByteArray(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS UInt16> * utf16Array,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** utf8Array) = 0;

    virtual CARAPI UTF16ByteArrayToString(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS UInt16> * utf16Array,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ _ELASTOS String * result) = 0;

    virtual CARAPI UTF8ByteArrayToUTF16ByteArray(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * utf8Array,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS UInt16> ** utf16Array) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("8F71CA48-06D2-0BDC-1615-2BD2F2B40406")
IRuleBasedCollatorICU : public IInterface
{
    static const _ELASTOS Int32 VALUE_PRIMARY = 0;
    static const _ELASTOS Int32 VALUE_SECONDARY = 1;
    static const _ELASTOS Int32 VALUE_TERTIARY = 2;
    static const _ELASTOS Int32 VALUE_DEFAULT_STRENGTH = 2;
    static const _ELASTOS Int32 VALUE_QUATERNARY = 3;
    static const _ELASTOS Int32 VALUE_IDENTICAL = 15;
    static const _ELASTOS Int32 VALUE_OFF = 16;
    static const _ELASTOS Int32 VALUE_ON = 17;
    static const _ELASTOS Int32 VALUE_SHIFTED = 20;
    static const _ELASTOS Int32 VALUE_NON_IGNORABLE = 21;
    static const _ELASTOS Int32 VALUE_LOWER_FIRST = 24;
    static const _ELASTOS Int32 VALUE_UPPER_FIRST = 25;
    static const _ELASTOS Int32 VALUE_ON_WITHOUT_HANGUL = 28;
    static const _ELASTOS Int32 VALUE_ATTRIBUTE_VALUE_COUNT = 29;
    static const _ELASTOS Int32 FRENCH_COLLATION = 0;
    static const _ELASTOS Int32 ALTERNATE_HANDLING = 1;
    static const _ELASTOS Int32 CASE_FIRST = 2;
    static const _ELASTOS Int32 CASE_LEVEL = 3;
    static const _ELASTOS Int32 DECOMPOSITION_MODE = 4;
    static const _ELASTOS Int32 STRENGTH = 5;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRuleBasedCollatorICU*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRuleBasedCollatorICU*)pObj->Probe(EIID_IRuleBasedCollatorICU);
    }

    static CARAPI_(IRuleBasedCollatorICU*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRuleBasedCollatorICU*)pObj->Probe(EIID_IRuleBasedCollatorICU);
    }

    virtual CARAPI Compare(
        /* [in] */ const _ELASTOS String& source,
        /* [in] */ const _ELASTOS String& target,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetDecomposition(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI SetDecomposition(
        /* [in] */ _ELASTOS Int32 mode) = 0;

    virtual CARAPI GetStrength(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI SetStrength(
        /* [in] */ _ELASTOS Int32 strength) = 0;

    virtual CARAPI SetAttribute(
        /* [in] */ _ELASTOS Int32 type,
        /* [in] */ _ELASTOS Int32 value) = 0;

    virtual CARAPI GetAttribute(
        /* [in] */ _ELASTOS Int32 type,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetCollationKey(
        /* [in] */ const _ELASTOS String& source,
        /* [out] */ Elastos::Text::ICollationKey ** outkey) = 0;

    virtual CARAPI GetRules(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetCollationElementIterator(
        /* [in] */ const _ELASTOS String& source,
        /* [out] */ Libcore::ICU::ICollationElementIteratorICU ** outicu) = 0;

    virtual CARAPI GetCollationElementIterator(
        /* [in] */ Elastos::Text::ICharacterIterator * it,
        /* [out] */ Libcore::ICU::ICollationElementIteratorICU ** outicu) = 0;

    virtual CARAPI Equals(
        /* [in] */ const _ELASTOS String& source,
        /* [in] */ const _ELASTOS String& target,
        /* [out] */ _ELASTOS Boolean * value) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("C956533B-7152-41F6-6DFC-B868223F8A1F")
ITimeZoneNames : public IInterface
{
    static const _ELASTOS Int32 OLSON_NAME = 0;
    static const _ELASTOS Int32 LONG_NAME = 1;
    static const _ELASTOS Int32 SHORT_NAME = 2;
    static const _ELASTOS Int32 LONG_NAME_DST = 3;
    static const _ELASTOS Int32 SHORT_NAME_DST = 4;
    static const _ELASTOS Int32 NAME_COUNT = 5;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITimeZoneNames*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITimeZoneNames*)pObj->Probe(EIID_ITimeZoneNames);
    }

    static CARAPI_(ITimeZoneNames*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITimeZoneNames*)pObj->Probe(EIID_ITimeZoneNames);
    }

    virtual CARAPI GetDisplayName(
        /* [in] */ _ELASTOS ArrayOf<Elastos::Core::IArrayOf *> * zoneStrings,
        /* [in] */ const _ELASTOS String& id,
        /* [in] */ _ELASTOS Boolean daylight,
        /* [in] */ _ELASTOS Int32 style,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetZoneStrings(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Core::IArrayOf *> ** outarray) = 0;

    virtual CARAPI ForLocale(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** outarray) = 0;

    virtual CARAPI GetExemplarLocation(
        /* [in] */ const _ELASTOS String& locale,
        /* [in] */ const _ELASTOS String& tz,
        /* [out] */ _ELASTOS String * location) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("E6E76F52-9152-9D96-1DA4-D42921F3A3AB")
ICollationElementIteratorICU : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICollationElementIteratorICU*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollationElementIteratorICU*)pObj->Probe(EIID_ICollationElementIteratorICU);
    }

    static CARAPI_(ICollationElementIteratorICU*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollationElementIteratorICU*)pObj->Probe(EIID_ICollationElementIteratorICU);
    }

    virtual CARAPI Reset() = 0;

    virtual CARAPI GetNext(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetPrevious(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetMaxExpansion(
        /* [in] */ _ELASTOS Int32 order,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI SetText(
        /* [in] */ const _ELASTOS String& source) = 0;

    virtual CARAPI SetText(
        /* [in] */ Elastos::Text::ICharacterIterator * source) = 0;

    virtual CARAPI GetOffset(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI SetOffset(
        /* [in] */ _ELASTOS Int32 offset) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("ED53615E-9152-9D96-1DA4-D42921F3A3AB")
ICollationElementIteratorICUHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICollationElementIteratorICUHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollationElementIteratorICUHelper*)pObj->Probe(EIID_ICollationElementIteratorICUHelper);
    }

    static CARAPI_(ICollationElementIteratorICUHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollationElementIteratorICUHelper*)pObj->Probe(EIID_ICollationElementIteratorICUHelper);
    }

    virtual CARAPI PrimaryOrder(
        /* [in] */ _ELASTOS Int32 order,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI SecondaryOrder(
        /* [in] */ _ELASTOS Int32 order,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI TertiaryOrder(
        /* [in] */ _ELASTOS Int32 order,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ _ELASTOS Int64 collatorAddress,
        /* [in] */ const _ELASTOS String& source,
        /* [out] */ Libcore::ICU::ICollationElementIteratorICU ** outiterICU) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("8EC5FD3E-5092-2C51-6090-78D10D06891B")
INativeDecimalFormat : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INativeDecimalFormat*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INativeDecimalFormat*)pObj->Probe(EIID_INativeDecimalFormat);
    }

    static CARAPI_(INativeDecimalFormat*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INativeDecimalFormat*)pObj->Probe(EIID_INativeDecimalFormat);
    }

    virtual CARAPI Close() = 0;

    virtual CARAPI SetDecimalFormatSymbols(
        /* [in] */ Elastos::Text::IDecimalFormatSymbols * dfs) = 0;

    virtual CARAPI SetDecimalFormatSymbols(
        /* [in] */ Libcore::ICU::ILocaleData * ld) = 0;

    virtual CARAPI FormatBigDecimal(
        /* [in] */ Elastos::Math::IBigDecimal * value,
        /* [in] */ Elastos::Text::IFieldPosition * field,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Char32> ** result) = 0;

    virtual CARAPI FormatBigInteger(
        /* [in] */ Elastos::Math::IBigInteger * value,
        /* [in] */ Elastos::Text::IFieldPosition * field,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Char32> ** result) = 0;

    virtual CARAPI FormatInt64(
        /* [in] */ _ELASTOS Int64 value,
        /* [in] */ Elastos::Text::IFieldPosition * field,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Char32> ** result) = 0;

    virtual CARAPI FormatDouble(
        /* [in] */ _ELASTOS Double value,
        /* [in] */ Elastos::Text::IFieldPosition * field,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Char32> ** result) = 0;

    virtual CARAPI ApplyLocalizedPattern(
        /* [in] */ const _ELASTOS String& pattern) = 0;

    virtual CARAPI ApplyPattern(
        /* [in] */ const _ELASTOS String& pattern) = 0;

    virtual CARAPI FormatToCharacterIterator(
        /* [in] */ IInterface * object,
        /* [out] */ Elastos::Text::IAttributedCharacterIterator ** result) = 0;

    virtual CARAPI ToLocalizedPattern(
        /* [out] */ _ELASTOS String * pattern) = 0;

    virtual CARAPI ToPattern(
        /* [out] */ _ELASTOS String * pattern) = 0;

    virtual CARAPI Parse(
        /* [in] */ const _ELASTOS String& string,
        /* [in] */ Elastos::Text::IParsePosition * position,
        /* [out] */ Elastos::Core::INumber ** result) = 0;

    virtual CARAPI GetMaximumFractionDigits(
        /* [out] */ _ELASTOS Int32 * maxFractionDigits) = 0;

    virtual CARAPI GetMaximumIntegerDigits(
        /* [out] */ _ELASTOS Int32 * maxIntegerDigits) = 0;

    virtual CARAPI GetMinimumFractionDigits(
        /* [out] */ _ELASTOS Int32 * minFractionDigits) = 0;

    virtual CARAPI GetMinimumIntegerDigits(
        /* [out] */ _ELASTOS Int32 * minIntegerDigits) = 0;

    virtual CARAPI GetGroupingSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetMultiplier(
        /* [out] */ _ELASTOS Int32 * multiplier) = 0;

    virtual CARAPI GetNegativePrefix(
        /* [out] */ _ELASTOS String * prefix) = 0;

    virtual CARAPI GetNegativeSuffix(
        /* [out] */ _ELASTOS String * suffix) = 0;

    virtual CARAPI GetPositivePrefix(
        /* [out] */ _ELASTOS String * prefix) = 0;

    virtual CARAPI GetPositiveSuffix(
        /* [out] */ _ELASTOS String * suffix) = 0;

    virtual CARAPI IsDecimalSeparatorAlwaysShown(
        /* [out] */ _ELASTOS Boolean * isAlwaysShown) = 0;

    virtual CARAPI IsParseBigDecimal(
        /* [out] */ _ELASTOS Boolean * isParseBigDecimal) = 0;

    virtual CARAPI IsParseIntegerOnly(
        /* [out] */ _ELASTOS Boolean * isParseIntegerOnly) = 0;

    virtual CARAPI IsGroupingUsed(
        /* [out] */ _ELASTOS Boolean * isGroupingUsed) = 0;

    virtual CARAPI SetDecimalSeparatorAlwaysShown(
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI SetCurrency(
        /* [in] */ const _ELASTOS String& currencySymbol,
        /* [in] */ const _ELASTOS String& currencyCode) = 0;

    virtual CARAPI SetGroupingSize(
        /* [in] */ _ELASTOS Int32 value) = 0;

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
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI SetParseIntegerOnly(
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI SetRoundingMode(
        /* [in] */ Elastos::Math::RoundingMode mode,
        /* [in] */ _ELASTOS Double roundingIncrement) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetAddr(
        /* [out] */ _ELASTOS Int32 * value) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("F3439150-1752-0BCF-F092-702121F3A3AB")
INativeBreakIterator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INativeBreakIterator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INativeBreakIterator*)pObj->Probe(EIID_INativeBreakIterator);
    }

    static CARAPI_(INativeBreakIterator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INativeBreakIterator*)pObj->Probe(EIID_INativeBreakIterator);
    }

    virtual CARAPI GetCurrent(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetFirst(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetFollowing(
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetText(
        /* [out] */ Elastos::Text::ICharacterIterator ** outiter) = 0;

    virtual CARAPI GetLast(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetNext(
        /* [in] */ _ELASTOS Int32 n,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetNext(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetPrevious(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI SetText(
        /* [in] */ Elastos::Text::ICharacterIterator * newText) = 0;

    virtual CARAPI SetText(
        /* [in] */ const _ELASTOS String& newText) = 0;

    virtual CARAPI HasText(
        /* [out] */ _ELASTOS Boolean * hasText) = 0;

    virtual CARAPI IsBoundary(
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetPreceding(
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ _ELASTOS Int32 * value) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("A28D6C47-1752-0BCF-F092-702121F3A3AB")
INativeBreakIteratorHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INativeBreakIteratorHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INativeBreakIteratorHelper*)pObj->Probe(EIID_INativeBreakIteratorHelper);
    }

    static CARAPI_(INativeBreakIteratorHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INativeBreakIteratorHelper*)pObj->Probe(EIID_INativeBreakIteratorHelper);
    }

    virtual CARAPI GetCharacterInstance(
        /* [in] */ Elastos::Utility::ILocale * where,
        /* [out] */ Libcore::ICU::INativeBreakIterator ** outiter) = 0;

    virtual CARAPI GetLineInstance(
        /* [in] */ Elastos::Utility::ILocale * where,
        /* [out] */ Libcore::ICU::INativeBreakIterator ** outiter) = 0;

    virtual CARAPI GetSentenceInstance(
        /* [in] */ Elastos::Utility::ILocale * where,
        /* [out] */ Libcore::ICU::INativeBreakIterator ** outiter) = 0;

    virtual CARAPI GetWordInstance(
        /* [in] */ Elastos::Utility::ILocale * where,
        /* [out] */ Libcore::ICU::INativeBreakIterator ** outiter) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("5FADF249-1752-45CF-5A76-8E80E245D81A")
INativeCollationHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INativeCollationHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INativeCollationHelper*)pObj->Probe(EIID_INativeCollationHelper);
    }

    static CARAPI_(INativeCollationHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INativeCollationHelper*)pObj->Probe(EIID_INativeCollationHelper);
    }

    virtual CARAPI CloseCollator(
        /* [in] */ _ELASTOS Int64 address) = 0;

    virtual CARAPI Compare(
        /* [in] */ _ELASTOS Int64 address,
        /* [in] */ const _ELASTOS String& source,
        /* [in] */ const _ELASTOS String& target,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetAttribute(
        /* [in] */ _ELASTOS Int64 address,
        /* [in] */ _ELASTOS Int32 type,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetCollationElementIterator(
        /* [in] */ _ELASTOS Int64 address,
        /* [in] */ const _ELASTOS String& source,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI GetRules(
        /* [in] */ _ELASTOS Int64 address,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetSortKey(
        /* [in] */ _ELASTOS Int64 address,
        /* [in] */ const _ELASTOS String& source,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** outarray) = 0;

    virtual CARAPI OpenCollator(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI OpenCollatorFromRules(
        /* [in] */ const _ELASTOS String& rules,
        /* [in] */ _ELASTOS Int32 normalizationMode,
        /* [in] */ _ELASTOS Int32 collationStrength,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI SafeClone(
        /* [in] */ _ELASTOS Int64 address,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI SetAttribute(
        /* [in] */ _ELASTOS Int64 address,
        /* [in] */ _ELASTOS Int32 type,
        /* [in] */ _ELASTOS Int32 value) = 0;

    virtual CARAPI CloseElements(
        /* [in] */ _ELASTOS Int64 address) = 0;

    virtual CARAPI GetMaxExpansion(
        /* [in] */ _ELASTOS Int64 address,
        /* [in] */ _ELASTOS Int32 order,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetOffset(
        /* [in] */ _ELASTOS Int64 address,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetNext(
        /* [in] */ _ELASTOS Int64 address,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetPrevious(
        /* [in] */ _ELASTOS Int64 address,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Reset(
        /* [in] */ _ELASTOS Int64 address) = 0;

    virtual CARAPI SetOffset(
        /* [in] */ _ELASTOS Int64 address,
        /* [in] */ _ELASTOS Int32 offset) = 0;

    virtual CARAPI SetText(
        /* [in] */ _ELASTOS Int64 address,
        /* [in] */ const _ELASTOS String& source) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("98892D23-5092-0D09-2E44-40F162C6FD1F")
INativeIDNHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INativeIDNHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INativeIDNHelper*)pObj->Probe(EIID_INativeIDNHelper);
    }

    static CARAPI_(INativeIDNHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INativeIDNHelper*)pObj->Probe(EIID_INativeIDNHelper);
    }

    virtual CARAPI ToASCII(
        /* [in] */ const _ELASTOS String& s,
        /* [in] */ _ELASTOS Int32 flags,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI ToUnicode(
        /* [in] */ const _ELASTOS String& s,
        /* [in] */ _ELASTOS Int32 flags,
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("14D12D4D-1752-19CF-6CDE-7DB101B78D1F")
INativePluralRules : public IInterface
{
    static const _ELASTOS Int32 ZERO = 0;
    static const _ELASTOS Int32 ONE = 1;
    static const _ELASTOS Int32 TWO = 2;
    static const _ELASTOS Int32 FEW = 3;
    static const _ELASTOS Int32 MANY = 4;
    static const _ELASTOS Int32 OTHER = 5;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INativePluralRules*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INativePluralRules*)pObj->Probe(EIID_INativePluralRules);
    }

    static CARAPI_(INativePluralRules*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INativePluralRules*)pObj->Probe(EIID_INativePluralRules);
    }

    virtual CARAPI QuantityForInt(
        /* [in] */ _ELASTOS Int32 value,
        /* [out] */ _ELASTOS Int32 * result) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("14AB2E44-1752-19CF-6CDE-7DB101B78D08")
INativePluralRulesHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INativePluralRulesHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INativePluralRulesHelper*)pObj->Probe(EIID_INativePluralRulesHelper);
    }

    static CARAPI_(INativePluralRulesHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INativePluralRulesHelper*)pObj->Probe(EIID_INativePluralRulesHelper);
    }

    virtual CARAPI ForLocale(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Libcore::ICU::INativePluralRules ** outrules) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("E81F3925-5092-2CA2-7ADC-8F80E2C58CFB")
INativeNormalizerHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INativeNormalizerHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INativeNormalizerHelper*)pObj->Probe(EIID_INativeNormalizerHelper);
    }

    static CARAPI_(INativeNormalizerHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INativeNormalizerHelper*)pObj->Probe(EIID_INativeNormalizerHelper);
    }

    virtual CARAPI IsNormalized(
        /* [in] */ Elastos::Core::ICharSequence * src,
        /* [in] */ Libcore::ICU::Form form,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Normalize(
        /* [in] */ Elastos::Core::ICharSequence * src,
        /* [in] */ Libcore::ICU::Form form,
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("69134658-1652-95A2-2D6D-99B5E3470516")
IImmutableIndex : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IImmutableIndex*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IImmutableIndex*)pObj->Probe(EIID_IImmutableIndex);
    }

    static CARAPI_(IImmutableIndex*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IImmutableIndex*)pObj->Probe(EIID_IImmutableIndex);
    }

    virtual CARAPI GetBucketCount(
        /* [out] */ _ELASTOS Int32 * count) = 0;

    virtual CARAPI GetBucketIndex(
        /* [in] */ const _ELASTOS String& s,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetBucketLabel(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS String * label) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("38878E50-8292-6417-4950-DABC65D68E1F")
IAlphabeticIndex : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAlphabeticIndex*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAlphabeticIndex*)pObj->Probe(EIID_IAlphabeticIndex);
    }

    static CARAPI_(IAlphabeticIndex*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAlphabeticIndex*)pObj->Probe(EIID_IAlphabeticIndex);
    }

    virtual CARAPI GetMaxLabelCount(
        /* [out] */ _ELASTOS Int32 * count) = 0;

    virtual CARAPI SetMaxLabelCount(
        /* [in] */ _ELASTOS Int32 count) = 0;

    virtual CARAPI AddLabels(
        /* [in] */ Elastos::Utility::ILocale * locale) = 0;

    virtual CARAPI AddLabelRange(
        /* [in] */ _ELASTOS Int32 codePointStart,
        /* [in] */ _ELASTOS Int32 codePointEnd) = 0;

    virtual CARAPI GetBucketCount(
        /* [out] */ _ELASTOS Int32 * count) = 0;

    virtual CARAPI GetBucketIndex(
        /* [in] */ const _ELASTOS String& s,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetBucketLabel(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS String * label) = 0;

    virtual CARAPI GetImmutableIndex(
        /* [out] */ Libcore::ICU::IImmutableIndex ** index) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("B1EC3E32-A652-F782-7390-78D10D06891B")
IDateIntervalFormat : public IInterface
{
    static const _ELASTOS Int32 FORMAT_SHOW_TIME = 0x00000001;
    static const _ELASTOS Int32 FORMAT_SHOW_WEEKDAY = 0x00000002;
    static const _ELASTOS Int32 FORMAT_SHOW_YEAR = 0x00000004;
    static const _ELASTOS Int32 FORMAT_NO_YEAR = 0x00000008;
    static const _ELASTOS Int32 FORMAT_SHOW_DATE = 0x00000010;
    static const _ELASTOS Int32 FORMAT_NO_MONTH_DAY = 0x00000020;
    static const _ELASTOS Int32 FORMAT_12HOUR = 0x00000040;
    static const _ELASTOS Int32 FORMAT_24HOUR = 0x00000080;
    static const _ELASTOS Int32 FORMAT_UTC = 0x00002000;
    static const _ELASTOS Int32 FORMAT_ABBREV_TIME = 0x00004000;
    static const _ELASTOS Int32 FORMAT_ABBREV_WEEKDAY = 0x00008000;
    static const _ELASTOS Int32 FORMAT_ABBREV_MONTH = 0x00010000;
    static const _ELASTOS Int32 FORMAT_NUMERIC_DATE = 0x00020000;
    static const _ELASTOS Int32 FORMAT_ABBREV_ALL = 0x00080000;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDateIntervalFormat*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDateIntervalFormat*)pObj->Probe(EIID_IDateIntervalFormat);
    }

    static CARAPI_(IDateIntervalFormat*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDateIntervalFormat*)pObj->Probe(EIID_IDateIntervalFormat);
    }

    virtual CARAPI FormatDateRange(
        /* [in] */ _ELASTOS Int64 startMs,
        /* [in] */ _ELASTOS Int64 endMs,
        /* [in] */ _ELASTOS Int32 flags,
        /* [in] */ const _ELASTOS String& olsonId,
        /* [out] */ _ELASTOS String * rst) = 0;

    virtual CARAPI FormatDateRange(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [in] */ Elastos::Utility::ITimeZone * tz,
        /* [in] */ _ELASTOS Int64 startMs,
        /* [in] */ _ELASTOS Int64 endMs,
        /* [in] */ _ELASTOS Int32 flags,
        /* [out] */ _ELASTOS String * rst) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("E7AB384D-1C52-3641-5866-7E74F5470516")
ITransliterator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITransliterator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITransliterator*)pObj->Probe(EIID_ITransliterator);
    }

    static CARAPI_(ITransliterator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITransliterator*)pObj->Probe(EIID_ITransliterator);
    }

    virtual CARAPI GetAvailableIDs(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** ids) = 0;

    virtual CARAPI Transliterate(
        /* [in] */ const _ELASTOS String& s,
        /* [out] */ _ELASTOS String * rev) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("4329F243-1752-44CF-7CFB-7D1601C58BB0")
INativeConverterHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INativeConverterHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INativeConverterHelper*)pObj->Probe(EIID_INativeConverterHelper);
    }

    static CARAPI_(INativeConverterHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INativeConverterHelper*)pObj->Probe(EIID_INativeConverterHelper);
    }

    virtual CARAPI Decode(
        /* [in] */ _ELASTOS Int64 converterHandle,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * input,
        /* [in] */ _ELASTOS Int32 inEnd,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * output,
        /* [in] */ _ELASTOS Int32 outEnd,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * data,
        /* [in] */ _ELASTOS Boolean flush,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI Encode(
        /* [in] */ _ELASTOS Int64 converterHandle,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * input,
        /* [in] */ _ELASTOS Int32 inEnd,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * output,
        /* [in] */ _ELASTOS Int32 outEnd,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * data,
        /* [in] */ _ELASTOS Boolean flush,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI OpenConverter(
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI CloseConverter(
        /* [in] */ _ELASTOS Int64 converterHandle) = 0;

    virtual CARAPI ResetByteToChar(
        /* [in] */ _ELASTOS Int64 converterHandle) = 0;

    virtual CARAPI ResetCharToByte(
        /* [in] */ _ELASTOS Int64 converterHandle) = 0;

    virtual CARAPI GetSubstitutionBytes(
        /* [in] */ _ELASTOS Int64 converterHandle,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** outarray) = 0;

    virtual CARAPI GetMaxBytesPerChar(
        /* [in] */ _ELASTOS Int64 converterHandle,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetMinBytesPerChar(
        /* [in] */ _ELASTOS Int64 converterHandle,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetAveBytesPerChar(
        /* [in] */ _ELASTOS Int64 converterHandle,
        /* [out] */ _ELASTOS Float * value) = 0;

    virtual CARAPI GetAveCharsPerByte(
        /* [in] */ _ELASTOS Int64 converterHandle,
        /* [out] */ _ELASTOS Float * value) = 0;

    virtual CARAPI Contains(
        /* [in] */ const _ELASTOS String& converterName1,
        /* [in] */ const _ELASTOS String& converterName2,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetAvailableCharsetNames(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** outarray) = 0;

    virtual CARAPI CharsetForName(
        /* [in] */ const _ELASTOS String& charsetName,
        /* [out] */ Elastos::IO::Charset::ICharset ** outset) = 0;

    virtual CARAPI SetCallbackDecode(
        /* [in] */ _ELASTOS Int64 converterHandle,
        /* [in] */ Elastos::IO::Charset::ICharsetDecoder * decoder) = 0;

    virtual CARAPI SetCallbackEncode(
        /* [in] */ _ELASTOS Int64 converterHandle,
        /* [in] */ Elastos::IO::Charset::ICharsetEncoder * encoder) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("05D87B58-8312-2D22-3B3B-48A95342E647")
ICCollationElementIteratorICUHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCollationElementIteratorICUHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCollationElementIteratorICUHelperClassObject*)pObj->Probe(EIID_ICCollationElementIteratorICUHelperClassObject);
    }

    static CARAPI_(ICCollationElementIteratorICUHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCollationElementIteratorICUHelperClassObject*)pObj->Probe(EIID_ICCollationElementIteratorICUHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("6B056F51-8312-9E2E-8BB4-EC1C01C58BB0")
ICNativeCollationHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICNativeCollationHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNativeCollationHelperClassObject*)pObj->Probe(EIID_ICNativeCollationHelperClassObject);
    }

    static CARAPI_(ICNativeCollationHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNativeCollationHelperClassObject*)pObj->Probe(EIID_ICNativeCollationHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("89F0665F-8312-2D22-3B53-B02681810706")
ICCollationKeyICUClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCollationKeyICUClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCollationKeyICUClassObject*)pObj->Probe(EIID_ICCollationKeyICUClassObject);
    }

    static CARAPI_(ICCollationKeyICUClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCollationKeyICUClassObject*)pObj->Probe(EIID_ICCollationKeyICUClassObject);
    }

    virtual CARAPI CreateObjectWithSourceAb(
        /* [in] */ const _ELASTOS String& source,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * ab,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("090E6424-8312-988E-F418-FD71D1447E14")
ICLocaleDataClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICLocaleDataClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLocaleDataClassObject*)pObj->Probe(EIID_ICLocaleDataClassObject);
    }

    static CARAPI_(ICLocaleDataClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLocaleDataClassObject*)pObj->Probe(EIID_ICLocaleDataClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("C0F36A2C-8312-988E-22A0-7831E3BE1EA3")
ICLocaleDataHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICLocaleDataHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLocaleDataHelperClassObject*)pObj->Probe(EIID_ICLocaleDataHelperClassObject);
    }

    static CARAPI_(ICLocaleDataHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLocaleDataHelperClassObject*)pObj->Probe(EIID_ICLocaleDataHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("0AB6673D-8312-ECE2-83DA-D063F4C74513")
ICTimeZoneNamesClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICTimeZoneNamesClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTimeZoneNamesClassObject*)pObj->Probe(EIID_ICTimeZoneNamesClassObject);
    }

    static CARAPI_(ICTimeZoneNamesClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTimeZoneNamesClassObject*)pObj->Probe(EIID_ICTimeZoneNamesClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("E6566939-0312-12A1-1A5C-8880E2C58CFB")
ICNativeIDNHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICNativeIDNHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNativeIDNHelperClassObject*)pObj->Probe(EIID_ICNativeIDNHelperClassObject);
    }

    static CARAPI_(ICNativeIDNHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNativeIDNHelperClassObject*)pObj->Probe(EIID_ICNativeIDNHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("539E702A-0312-44A1-59F4-B81F01C58B19")
ICNativeNormalizerHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICNativeNormalizerHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNativeNormalizerHelperClassObject*)pObj->Probe(EIID_ICNativeNormalizerHelperClassObject);
    }

    static CARAPI_(ICNativeNormalizerHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNativeNormalizerHelperClassObject*)pObj->Probe(EIID_ICNativeNormalizerHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("1B79674B-8312-9E2E-33D8-BCFB62036E1B")
ICNativePluralRulesClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICNativePluralRulesClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNativePluralRulesClassObject*)pObj->Probe(EIID_ICNativePluralRulesClassObject);
    }

    static CARAPI_(ICNativePluralRulesClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNativePluralRulesClassObject*)pObj->Probe(EIID_ICNativePluralRulesClassObject);
    }

    virtual CARAPI CreateObjectWithAddress(
        /* [in] */ _ELASTOS Int64 address,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("04957151-8312-9E2E-33D8-BCFB62036E1B")
ICNativePluralRulesHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICNativePluralRulesHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNativePluralRulesHelperClassObject*)pObj->Probe(EIID_ICNativePluralRulesHelperClassObject);
    }

    static CARAPI_(ICNativePluralRulesHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNativePluralRulesHelperClassObject*)pObj->Probe(EIID_ICNativePluralRulesHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("29D07E58-8312-B80D-172C-2A56A4E56909")
ICRuleBasedCollatorICUClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICRuleBasedCollatorICUClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRuleBasedCollatorICUClassObject*)pObj->Probe(EIID_ICRuleBasedCollatorICUClassObject);
    }

    static CARAPI_(ICRuleBasedCollatorICUClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRuleBasedCollatorICUClassObject*)pObj->Probe(EIID_ICRuleBasedCollatorICUClassObject);
    }

    virtual CARAPI CreateObjectWithRules(
        /* [in] */ const _ELASTOS String& rules,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithLocale(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("D70D734D-8312-9E2E-17E0-25E14242E647")
ICNativeBreakIteratorHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICNativeBreakIteratorHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNativeBreakIteratorHelperClassObject*)pObj->Probe(EIID_ICNativeBreakIteratorHelperClassObject);
    }

    static CARAPI_(ICNativeBreakIteratorHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNativeBreakIteratorHelperClassObject*)pObj->Probe(EIID_ICNativeBreakIteratorHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("C0486450-0312-2F05-C892-A0B479CBAC1D")
ICAlphabeticIndexClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAlphabeticIndexClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAlphabeticIndexClassObject*)pObj->Probe(EIID_ICAlphabeticIndexClassObject);
    }

    static CARAPI_(ICAlphabeticIndexClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAlphabeticIndexClassObject*)pObj->Probe(EIID_ICAlphabeticIndexClassObject);
    }

    virtual CARAPI CreateObjectWithLocale(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("337E6C27-8312-054C-EFE7-20F1A21B0C12")
ICDateIntervalFormatClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDateIntervalFormatClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDateIntervalFormatClassObject*)pObj->Probe(EIID_ICDateIntervalFormatClassObject);
    }

    static CARAPI_(ICDateIntervalFormatClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDateIntervalFormatClassObject*)pObj->Probe(EIID_ICDateIntervalFormatClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("9A1A5F53-8312-8238-6CB0-CCFCE82A0393")
ICTransliteratorClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICTransliteratorClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTransliteratorClassObject*)pObj->Probe(EIID_ICTransliteratorClassObject);
    }

    static CARAPI_(ICTransliteratorClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTransliteratorClassObject*)pObj->Probe(EIID_ICTransliteratorClassObject);
    }

    virtual CARAPI CreateObjectWithId(
        /* [in] */ const _ELASTOS String& id,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("72F0612E-0312-0C09-3C78-B8C1E2851EA3")
ICICUUtilClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICICUUtilClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICICUUtilClassObject*)pObj->Probe(EIID_ICICUUtilClassObject);
    }

    static CARAPI_(ICICUUtilClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICICUUtilClassObject*)pObj->Probe(EIID_ICICUUtilClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("6CF06F4C-8312-9E2E-89F8-F6FB2C028A17")
ICNativeConverterHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICNativeConverterHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNativeConverterHelperClassObject*)pObj->Probe(EIID_ICNativeConverterHelperClassObject);
    }

    static CARAPI_(ICNativeConverterHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNativeConverterHelperClassObject*)pObj->Probe(EIID_ICNativeConverterHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace ICU {
CAR_INTERFACE("15028734-0312-A2A1-58C0-20F1A21B0C12")
ICNativeDecimalFormatClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICNativeDecimalFormatClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNativeDecimalFormatClassObject*)pObj->Probe(EIID_ICNativeDecimalFormatClassObject);
    }

    static CARAPI_(ICNativeDecimalFormatClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNativeDecimalFormatClassObject*)pObj->Probe(EIID_ICNativeDecimalFormatClassObject);
    }

    virtual CARAPI CreateObjectWithPatternDfs(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Text::IDecimalFormatSymbols * dfs,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPatternData(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Libcore::ICU::ILocaleData * data,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("FBF9392C-9692-3515-64C4-9081C3C61F9E")
IAsynchronousCloseMonitor : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAsynchronousCloseMonitor*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAsynchronousCloseMonitor*)pObj->Probe(EIID_IAsynchronousCloseMonitor);
    }

    static CARAPI_(IAsynchronousCloseMonitor*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAsynchronousCloseMonitor*)pObj->Probe(EIID_IAsynchronousCloseMonitor);
    }

    virtual CARAPI SignalBlockedThreads(
        /* [in] */ Elastos::IO::IFileDescriptor * fd) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("6C2FFF18-6612-15FF-5B9A-728DFE12F62B")
IOs : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IOs*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IOs*)pObj->Probe(EIID_IOs);
    }

    static CARAPI_(IOs*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IOs*)pObj->Probe(EIID_IOs);
    }

    virtual CARAPI Accept(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ Elastos::Net::IInetSocketAddress * peerAddress,
        /* [out] */ Elastos::IO::IFileDescriptor ** retFd) = 0;

    virtual CARAPI Access(
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ _ELASTOS Int32 mode,
        /* [out] */ _ELASTOS Boolean * succeed) = 0;

    virtual CARAPI Elastos_getaddrinfo(
        /* [in] */ const _ELASTOS String& node,
        /* [in] */ Elastos::Droid::System::IStructAddrinfo * hints,
        /* [in] */ _ELASTOS Int32 netId,
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Net::IInetAddress *> ** info) = 0;

    virtual CARAPI Bind(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ Elastos::Net::IInetAddress * address,
        /* [in] */ _ELASTOS Int32 port) = 0;

    virtual CARAPI Chmod(
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ _ELASTOS Int32 mode) = 0;

    virtual CARAPI Chown(
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ _ELASTOS Int32 uid,
        /* [in] */ _ELASTOS Int32 gid) = 0;

    virtual CARAPI Close(
        /* [in] */ Elastos::IO::IFileDescriptor * fd) = 0;

    virtual CARAPI Connect(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ Elastos::Net::IInetAddress * address,
        /* [in] */ _ELASTOS Int32 port) = 0;

    virtual CARAPI Dup(
        /* [in] */ Elastos::IO::IFileDescriptor * oldFd,
        /* [out] */ Elastos::IO::IFileDescriptor ** retFd) = 0;

    virtual CARAPI Dup2(
        /* [in] */ Elastos::IO::IFileDescriptor * oldFd,
        /* [in] */ _ELASTOS Int32 newFd,
        /* [out] */ Elastos::IO::IFileDescriptor ** retFd) = 0;

    virtual CARAPI Environ(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** env) = 0;

    virtual CARAPI Execv(
        /* [in] */ const _ELASTOS String& filename,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * argv) = 0;

    virtual CARAPI Execve(
        /* [in] */ const _ELASTOS String& filename,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * argv,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * envp) = 0;

    virtual CARAPI Fchmod(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 mode) = 0;

    virtual CARAPI Fchown(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 uid,
        /* [in] */ _ELASTOS Int32 gid) = 0;

    virtual CARAPI FcntlVoid(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 cmd,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI FcntlInt64(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 cmd,
        /* [in] */ _ELASTOS Int64 arg,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI FcntlFlock(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 cmd,
        /* [in] */ Elastos::Droid::System::IStructFlock * arg,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI Fdatasync(
        /* [in] */ Elastos::IO::IFileDescriptor * fd) = 0;

    virtual CARAPI Fstat(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::Droid::System::IStructStat ** stat) = 0;

    virtual CARAPI Fstatvfs(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::Droid::System::IStructStatVfs ** statVfs) = 0;

    virtual CARAPI Fsync(
        /* [in] */ Elastos::IO::IFileDescriptor * fd) = 0;

    virtual CARAPI Ftruncate(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI Gai_strerror(
        /* [in] */ _ELASTOS Int32 error,
        /* [out] */ _ELASTOS String * strerror) = 0;

    virtual CARAPI Getegid(
        /* [out] */ _ELASTOS Int32 * egid) = 0;

    virtual CARAPI Geteuid(
        /* [out] */ _ELASTOS Int32 * euid) = 0;

    virtual CARAPI Getgid(
        /* [out] */ _ELASTOS Int32 * gid) = 0;

    virtual CARAPI Getenv(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS String * env) = 0;

    virtual CARAPI Getnameinfo(
        /* [in] */ Elastos::Net::IInetAddress * address,
        /* [in] */ _ELASTOS Int32 flags,
        /* [out] */ _ELASTOS String * nameinfo) = 0;

    virtual CARAPI Getpeername(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::Net::ISocketAddress ** peername) = 0;

    virtual CARAPI Getpid(
        /* [out] */ _ELASTOS Int32 * pid) = 0;

    virtual CARAPI Getppid(
        /* [out] */ _ELASTOS Int32 * ppid) = 0;

    virtual CARAPI Getpwnam(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Droid::System::IStructPasswd ** pwnam) = 0;

    virtual CARAPI Getpwuid(
        /* [in] */ _ELASTOS Int32 uid,
        /* [out] */ Elastos::Droid::System::IStructPasswd ** pwuid) = 0;

    virtual CARAPI Getsockname(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::Net::ISocketAddress ** sockname) = 0;

    virtual CARAPI GetsockoptByte(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 level,
        /* [in] */ _ELASTOS Int32 option,
        /* [out] */ _ELASTOS Int32 * sockopt) = 0;

    virtual CARAPI GetsockoptInAddr(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 level,
        /* [in] */ _ELASTOS Int32 option,
        /* [out] */ Elastos::Net::IInetAddress ** addr) = 0;

    virtual CARAPI GetsockoptInt32(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 level,
        /* [in] */ _ELASTOS Int32 option,
        /* [out] */ _ELASTOS Int32 * sockopt) = 0;

    virtual CARAPI GetsockoptLinger(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 level,
        /* [in] */ _ELASTOS Int32 option,
        /* [out] */ Elastos::Droid::System::IStructLinger ** linger) = 0;

    virtual CARAPI GetsockoptTimeval(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 level,
        /* [in] */ _ELASTOS Int32 option,
        /* [out] */ Elastos::Droid::System::IStructTimeval ** timeval) = 0;

    virtual CARAPI GetsockoptUcred(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 level,
        /* [in] */ _ELASTOS Int32 option,
        /* [out] */ Elastos::Droid::System::IStructUcred ** ucred) = 0;

    virtual CARAPI Gettid(
        /* [out] */ _ELASTOS Int32 * tid) = 0;

    virtual CARAPI Getuid(
        /* [out] */ _ELASTOS Int32 * uid) = 0;

    virtual CARAPI If_indextoname(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI Inet_pton(
        /* [in] */ _ELASTOS Int32 family,
        /* [in] */ const _ELASTOS String& address,
        /* [out] */ Elastos::Net::IInetAddress ** addr) = 0;

    virtual CARAPI IoctlInetAddress(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 cmd,
        /* [in] */ const _ELASTOS String& interfaceName,
        /* [out] */ Elastos::Net::IInetAddress ** addr) = 0;

    virtual CARAPI IoctlInt(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 cmd,
        /* [in] */ _ELASTOS Int32 * arg,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI Isatty(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ _ELASTOS Boolean * isatty) = 0;

    virtual CARAPI Kill(
        /* [in] */ _ELASTOS Int32 pid,
        /* [in] */ _ELASTOS Int32 signal) = 0;

    virtual CARAPI Lchown(
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ _ELASTOS Int32 uid,
        /* [in] */ _ELASTOS Int32 gid) = 0;

    virtual CARAPI Link(
        /* [in] */ const _ELASTOS String& oldPath,
        /* [in] */ const _ELASTOS String& newPath) = 0;

    virtual CARAPI Listen(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 backlog) = 0;

    virtual CARAPI Lseek(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int64 offset,
        /* [in] */ _ELASTOS Int32 whence,
        /* [out] */ _ELASTOS Int64 * result) = 0;

    virtual CARAPI Lstat(
        /* [in] */ const _ELASTOS String& path,
        /* [out] */ Elastos::Droid::System::IStructStat ** stat) = 0;

    virtual CARAPI Mincore(
        /* [in] */ _ELASTOS Int64 address,
        /* [in] */ _ELASTOS Int64 byteCount,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * vector) = 0;

    virtual CARAPI Mkdir(
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ _ELASTOS Int32 mode) = 0;

    virtual CARAPI Mlock(
        /* [in] */ _ELASTOS Int64 address,
        /* [in] */ _ELASTOS Int64 byteCount) = 0;

    virtual CARAPI Mkfifo(
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ _ELASTOS Int32 mode) = 0;

    virtual CARAPI Mmap(
        /* [in] */ _ELASTOS Int64 address,
        /* [in] */ _ELASTOS Int64 byteCount,
        /* [in] */ _ELASTOS Int32 prot,
        /* [in] */ _ELASTOS Int32 flags,
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int64 offset,
        /* [out] */ _ELASTOS Int64 * result) = 0;

    virtual CARAPI Msync(
        /* [in] */ _ELASTOS Int64 address,
        /* [in] */ _ELASTOS Int64 byteCount,
        /* [in] */ _ELASTOS Int32 flags) = 0;

    virtual CARAPI Munlock(
        /* [in] */ _ELASTOS Int64 address,
        /* [in] */ _ELASTOS Int64 byteCount) = 0;

    virtual CARAPI Munmap(
        /* [in] */ _ELASTOS Int64 address,
        /* [in] */ _ELASTOS Int64 byteCount) = 0;

    virtual CARAPI Open(
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ _ELASTOS Int32 flags,
        /* [in] */ _ELASTOS Int32 mode,
        /* [out] */ Elastos::IO::IFileDescriptor ** fd) = 0;

    virtual CARAPI Pipe(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::IO::IFileDescriptor *> ** fds) = 0;

    virtual CARAPI Poll(
        /* [in] */ _ELASTOS ArrayOf<Elastos::Droid::System::IStructPollfd *> * fds,
        /* [in] */ _ELASTOS Int32 timeoutMs,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI Posix_fallocate(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int64 offset,
        /* [in] */ _ELASTOS Int64 length) = 0;

    virtual CARAPI Prctl(
        /* [in] */ _ELASTOS Int32 option,
        /* [in] */ _ELASTOS Int64 arg2,
        /* [in] */ _ELASTOS Int64 arg3,
        /* [in] */ _ELASTOS Int64 arg4,
        /* [in] */ _ELASTOS Int64 arg5,
        /* [out] */ _ELASTOS Int32 * prctl) = 0;

    virtual CARAPI Pread(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * bytes,
        /* [in] */ _ELASTOS Int32 byteOffset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [in] */ _ELASTOS Int64 offset,
        /* [out] */ _ELASTOS Int32 * num) = 0;

    virtual CARAPI Pread(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ Elastos::IO::IByteBuffer * buffer,
        /* [in] */ _ELASTOS Int64 offset,
        /* [out] */ _ELASTOS Int32 * num) = 0;

    virtual CARAPI Pwrite(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * bytes,
        /* [in] */ _ELASTOS Int32 byteOffset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [in] */ _ELASTOS Int64 offset,
        /* [out] */ _ELASTOS Int32 * num) = 0;

    virtual CARAPI Pwrite(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ Elastos::IO::IByteBuffer * buffer,
        /* [in] */ _ELASTOS Int64 offset,
        /* [out] */ _ELASTOS Int32 * num) = 0;

    virtual CARAPI Read(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * bytes,
        /* [in] */ _ELASTOS Int32 byteOffset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [out] */ _ELASTOS Int32 * num) = 0;

    virtual CARAPI Read(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ Elastos::IO::IByteBuffer * buffer,
        /* [out] */ _ELASTOS Int32 * num) = 0;

    virtual CARAPI Readlink(
        /* [in] */ const _ELASTOS String& path,
        /* [out] */ _ELASTOS String * link) = 0;

    virtual CARAPI Readv(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * buffers,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * offsets,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * byteCounts,
        /* [out] */ _ELASTOS Int32 * num) = 0;

    virtual CARAPI Recvfrom(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * bytes,
        /* [in] */ _ELASTOS Int32 byteOffset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [in] */ _ELASTOS Int32 flags,
        /* [in] */ Elastos::Net::IInetSocketAddress * srcAddress,
        /* [out] */ _ELASTOS Int32 * num) = 0;

    virtual CARAPI Recvfrom(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ Elastos::IO::IByteBuffer * buffer,
        /* [in] */ _ELASTOS Int32 flags,
        /* [in] */ Elastos::Net::IInetSocketAddress * srcAddress,
        /* [out] */ _ELASTOS Int32 * num) = 0;

    virtual CARAPI Remove(
        /* [in] */ const _ELASTOS String& path) = 0;

    virtual CARAPI Rename(
        /* [in] */ const _ELASTOS String& oldPath,
        /* [in] */ const _ELASTOS String& newPath) = 0;

    virtual CARAPI Sendto(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * bytes,
        /* [in] */ _ELASTOS Int32 byteOffset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [in] */ _ELASTOS Int32 flags,
        /* [in] */ Elastos::Net::IInetAddress * inetAddress,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI Sendto(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ Elastos::IO::IByteBuffer * buffer,
        /* [in] */ _ELASTOS Int32 flags,
        /* [in] */ Elastos::Net::IInetAddress * inetAddress,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI Sendfile(
        /* [in] */ Elastos::IO::IFileDescriptor * outFd,
        /* [in] */ Elastos::IO::IFileDescriptor * inFd,
        /* [out] */ _ELASTOS Int64 * inOffset,
        /* [in] */ _ELASTOS Int64 byteCount,
        /* [out] */ _ELASTOS Int64 * result) = 0;

    virtual CARAPI Setegid(
        /* [in] */ _ELASTOS Int32 egid) = 0;

    virtual CARAPI Setenv(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Boolean overwrite) = 0;

    virtual CARAPI Seteuid(
        /* [in] */ _ELASTOS Int32 euid) = 0;

    virtual CARAPI Setgid(
        /* [in] */ _ELASTOS Int32 gid) = 0;

    virtual CARAPI Setsid(
        /* [out] */ _ELASTOS Int32 * sid) = 0;

    virtual CARAPI SetsockoptByte(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 level,
        /* [in] */ _ELASTOS Int32 option,
        /* [in] */ _ELASTOS Int32 value) = 0;

    virtual CARAPI SetsockoptIfreq(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 level,
        /* [in] */ _ELASTOS Int32 option,
        /* [in] */ const _ELASTOS String& interfaceName) = 0;

    virtual CARAPI SetsockoptInt32(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 level,
        /* [in] */ _ELASTOS Int32 option,
        /* [in] */ _ELASTOS Int32 value) = 0;

    virtual CARAPI SetsockoptIpMreqn(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 level,
        /* [in] */ _ELASTOS Int32 option,
        /* [in] */ _ELASTOS Int32 value) = 0;

    virtual CARAPI SetsockoptGroupReq(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 level,
        /* [in] */ _ELASTOS Int32 option,
        /* [in] */ Elastos::Droid::System::IStructGroupReq * value) = 0;

    virtual CARAPI SetsockoptGroupSourceReq(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 level,
        /* [in] */ _ELASTOS Int32 option,
        /* [in] */ Elastos::Droid::System::IStructGroupSourceReq * value) = 0;

    virtual CARAPI SetsockoptLinger(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 level,
        /* [in] */ _ELASTOS Int32 option,
        /* [in] */ Elastos::Droid::System::IStructLinger * value) = 0;

    virtual CARAPI SetsockoptTimeval(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 level,
        /* [in] */ _ELASTOS Int32 option,
        /* [in] */ Elastos::Droid::System::IStructTimeval * value) = 0;

    virtual CARAPI Setuid(
        /* [in] */ _ELASTOS Int32 uid) = 0;

    virtual CARAPI Shutdown(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 how) = 0;

    virtual CARAPI Socket(
        /* [in] */ _ELASTOS Int32 socketDomain,
        /* [in] */ _ELASTOS Int32 type,
        /* [in] */ _ELASTOS Int32 protocol,
        /* [out] */ Elastos::IO::IFileDescriptor ** fd) = 0;

    virtual CARAPI Socketpair(
        /* [in] */ _ELASTOS Int32 socketDomain,
        /* [in] */ _ELASTOS Int32 type,
        /* [in] */ _ELASTOS Int32 protocol,
        /* [in] */ Elastos::IO::IFileDescriptor * fd1,
        /* [in] */ Elastos::IO::IFileDescriptor * fd2) = 0;

    virtual CARAPI Stat(
        /* [in] */ const _ELASTOS String& path,
        /* [out] */ Elastos::Droid::System::IStructStat ** stat) = 0;

    virtual CARAPI StatVfs(
        /* [in] */ const _ELASTOS String& path,
        /* [out] */ Elastos::Droid::System::IStructStatVfs ** statfs) = 0;

    virtual CARAPI Strerror(
        /* [in] */ _ELASTOS Int32 errnum,
        /* [out] */ _ELASTOS String * strerr) = 0;

    virtual CARAPI Strsignal(
        /* [in] */ _ELASTOS Int32 signal,
        /* [out] */ _ELASTOS String * strSignal) = 0;

    virtual CARAPI Symlink(
        /* [in] */ const _ELASTOS String& oldPath,
        /* [in] */ const _ELASTOS String& newPath) = 0;

    virtual CARAPI Sysconf(
        /* [in] */ _ELASTOS Int32 name,
        /* [out] */ _ELASTOS Int64 * result) = 0;

    virtual CARAPI Tcdrain(
        /* [in] */ Elastos::IO::IFileDescriptor * fd) = 0;

    virtual CARAPI Tcsendbreak(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 duration) = 0;

    virtual CARAPI Umask(
        /* [in] */ _ELASTOS Int32 mask,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI Uname(
        /* [out] */ Elastos::Droid::System::IStructUtsname ** uname) = 0;

    virtual CARAPI Unsetenv(
        /* [in] */ const _ELASTOS String& name) = 0;

    virtual CARAPI Waitpid(
        /* [in] */ _ELASTOS Int32 pid,
        /* [out] */ _ELASTOS Int32 * status,
        /* [in] */ _ELASTOS Int32 options,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI Write(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * bytes,
        /* [in] */ _ELASTOS Int32 byteOffset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [out] */ _ELASTOS Int32 * num) = 0;

    virtual CARAPI Write(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ Elastos::IO::IByteBuffer * buffer,
        /* [out] */ _ELASTOS Int32 * num) = 0;

    virtual CARAPI Writev(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * buffers,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * offsets,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * byteCounts,
        /* [out] */ _ELASTOS Int32 * result) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("C7A8CB1D-2492-352F-7BAA-E85FB1A529D7")
IIoBridge : public IInterface
{
    static const _ELASTOS Int32 ELASTOS_MCAST_JOIN_GROUP = 19;
    static const _ELASTOS Int32 ELASTOS_MCAST_LEAVE_GROUP = 20;
    static const _ELASTOS Int32 ELASTOS_MCAST_JOIN_SOURCE_GROUP = 21;
    static const _ELASTOS Int32 ELASTOS_MCAST_LEAVE_SOURCE_GROUP = 22;
    static const _ELASTOS Int32 ELASTOS_MCAST_BLOCK_SOURCE = 23;
    static const _ELASTOS Int32 ELASTOS_MCAST_UNBLOCK_SOURCE = 24;
    static const _ELASTOS Int32 ELASTOS_IP_MULTICAST_TTL = 17;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IIoBridge*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IIoBridge*)pObj->Probe(EIID_IIoBridge);
    }

    static CARAPI_(IIoBridge*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IIoBridge*)pObj->Probe(EIID_IIoBridge);
    }

    virtual CARAPI Available(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ _ELASTOS Int32 * avail) = 0;

    virtual CARAPI Bind(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ Elastos::Net::IInetAddress * inetAddress,
        /* [in] */ _ELASTOS Int32 port) = 0;

    virtual CARAPI Connect(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ Elastos::Net::IInetAddress * inetAddress,
        /* [in] */ _ELASTOS Int32 port) = 0;

    virtual CARAPI Connect(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ Elastos::Net::IInetAddress * inetAddress,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Int32 timeoutMs) = 0;

    virtual CARAPI CloseAndSignalBlockedThreads(
        /* [in] */ Elastos::IO::IFileDescriptor * fd) = 0;

    virtual CARAPI IsConnected(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ Elastos::Net::IInetAddress * inetAddress,
        /* [in] */ _ELASTOS Int32 port,
        /* [in] */ _ELASTOS Int32 timeoutMs,
        /* [in] */ _ELASTOS Int32 remainingTimeoutMs,
        /* [out] */ _ELASTOS Boolean * isConnected) = 0;

    virtual CARAPI GetSocketOption(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 option,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI SetSocketOption(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Int32 option,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI Open(
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ _ELASTOS Int32 flags,
        /* [out] */ Elastos::IO::IFileDescriptor ** fd) = 0;

    virtual CARAPI Read(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * bytes,
        /* [in] */ _ELASTOS Int32 byteOffset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [out] */ _ELASTOS Int32 * count) = 0;

    virtual CARAPI Write(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * bytes,
        /* [in] */ _ELASTOS Int32 byteOffset,
        /* [in] */ _ELASTOS Int32 byteCount) = 0;

    virtual CARAPI Sendto(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * bytes,
        /* [in] */ _ELASTOS Int32 byteOffset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [in] */ _ELASTOS Int32 flags,
        /* [in] */ Elastos::Net::IInetAddress * inetAddress,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI Sendto(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ Elastos::IO::IByteBuffer * buffer,
        /* [in] */ _ELASTOS Int32 flags,
        /* [in] */ Elastos::Net::IInetAddress * inetAddress,
        /* [in] */ _ELASTOS Int32 port,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI Recvfrom(
        /* [in] */ _ELASTOS Boolean isRead,
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * bytes,
        /* [in] */ _ELASTOS Int32 byteOffset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [in] */ _ELASTOS Int32 flags,
        /* [in] */ Elastos::Net::IDatagramPacket * packet,
        /* [in] */ _ELASTOS Boolean isConnected,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI Recvfrom(
        /* [in] */ _ELASTOS Boolean isRead,
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ Elastos::IO::IByteBuffer * buffer,
        /* [in] */ _ELASTOS Int32 flags,
        /* [in] */ Elastos::Net::IDatagramPacket * packet,
        /* [in] */ _ELASTOS Boolean isConnected,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI Socket(
        /* [in] */ _ELASTOS Boolean stream,
        /* [out] */ Elastos::IO::IFileDescriptor ** fd) = 0;

    virtual CARAPI GetSocketLocalAddress(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ Elastos::Net::IInetAddress ** address) = 0;

    virtual CARAPI GetSocketLocalPort(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [out] */ _ELASTOS Int32 * port) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("58CF192D-45D2-F913-51FC-B868223F8A1F")
ILibcore : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILibcore*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILibcore*)pObj->Probe(EIID_ILibcore);
    }

    static CARAPI_(ILibcore*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILibcore*)pObj->Probe(EIID_ILibcore);
    }

    virtual CARAPI GetOs(
        /* [out] */ Libcore::IO::IOs ** os) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("58722924-E952-240E-54A8-B8FFE3A289FC")
ISocketTagger : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISocketTagger*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketTagger*)pObj->Probe(EIID_ISocketTagger);
    }

    static CARAPI_(ISocketTagger*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketTagger*)pObj->Probe(EIID_ISocketTagger);
    }

    virtual CARAPI Tag(
        /* [in] */ Elastos::IO::IFileDescriptor * socketDescriptor) = 0;

    virtual CARAPI Untag(
        /* [in] */ Elastos::IO::IFileDescriptor * socketDescriptor) = 0;

    virtual CARAPI Tag(
        /* [in] */ Elastos::Net::ISocket * socket) = 0;

    virtual CARAPI Untag(
        /* [in] */ Elastos::Net::ISocket * socket) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("1B3B253A-E952-240E-54A8-B81F01C58B19")
ISocketTaggerHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISocketTaggerHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketTaggerHelper*)pObj->Probe(EIID_ISocketTaggerHelper);
    }

    static CARAPI_(ISocketTaggerHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISocketTaggerHelper*)pObj->Probe(EIID_ISocketTaggerHelper);
    }

    virtual CARAPI Set(
        /* [in] */ Libcore::IO::ISocketTagger * tagger) = 0;

    virtual CARAPI Get(
        /* [out] */ Libcore::IO::ISocketTagger ** tagger) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("9D6D252B-1852-0403-7E5C-34911FC50F77")
IBase64 : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBase64*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBase64*)pObj->Probe(EIID_IBase64);
    }

    static CARAPI_(IBase64*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBase64*)pObj->Probe(EIID_IBase64);
    }

    virtual CARAPI Decode(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * inData,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** outData) = 0;

    virtual CARAPI Decode(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * inData,
        /* [in] */ _ELASTOS Int32 len,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** outData) = 0;

    virtual CARAPI Encode(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * inData,
        /* [out] */ _ELASTOS String * outData) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("4566583C-1A92-3709-EE93-B891FFC74513")
IBufferIterator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBufferIterator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBufferIterator*)pObj->Probe(EIID_IBufferIterator);
    }

    static CARAPI_(IBufferIterator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBufferIterator*)pObj->Probe(EIID_IBufferIterator);
    }

    virtual CARAPI Seek(
        /* [in] */ _ELASTOS Int32 offset) = 0;

    virtual CARAPI Skip(
        /* [in] */ _ELASTOS Int32 byteCount) = 0;

    virtual CARAPI ReadByteArray(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * dst,
        /* [in] */ _ELASTOS Int32 dstOffset,
        /* [in] */ _ELASTOS Int32 byteCount) = 0;

    virtual CARAPI ReadByte(
        /* [out] */ _ELASTOS Byte * result) = 0;

    virtual CARAPI ReadInt32(
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI ReadInt32Array(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * dst,
        /* [in] */ _ELASTOS Int32 dstOffset,
        /* [in] */ _ELASTOS Int32 intCount) = 0;

    virtual CARAPI ReadInt16(
        /* [out] */ _ELASTOS Int16 * result) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("ACF81F29-0452-2414-66A8-9170E33E891B")
IHeapBufferIterator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IHeapBufferIterator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHeapBufferIterator*)pObj->Probe(EIID_IHeapBufferIterator);
    }

    static CARAPI_(IHeapBufferIterator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHeapBufferIterator*)pObj->Probe(EIID_IHeapBufferIterator);
    }

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("717AFF37-CC52-171F-4DE4-47F1C3DD0F0F")
IMemory : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMemory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMemory*)pObj->Probe(EIID_IMemory);
    }

    static CARAPI_(IMemory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMemory*)pObj->Probe(EIID_IMemory);
    }

    virtual CARAPI UnsafeBulkGet(
        /* [out] */ _ELASTOS Byte * dst,
        /* [in] */ _ELASTOS Int32 dstOffset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * src,
        /* [in] */ _ELASTOS Int32 srcOffset,
        /* [in] */ _ELASTOS Int32 sizeofElements,
        /* [in] */ _ELASTOS Boolean swap) = 0;

    virtual CARAPI UnsafeBulkPut(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * dst,
        /* [in] */ _ELASTOS Int32 dstOffset,
        /* [in] */ _ELASTOS Int32 byteCount,
        /* [in] */ _ELASTOS Byte * src,
        /* [in] */ _ELASTOS Int32 srcOffset,
        /* [in] */ _ELASTOS Int32 sizeofElements,
        /* [in] */ _ELASTOS Boolean swap) = 0;

    virtual CARAPI PeekInt32(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * src,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ Elastos::IO::ByteOrder order,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI PeekInt64(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * src,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ Elastos::IO::ByteOrder order,
        /* [out] */ _ELASTOS Int64 * result) = 0;

    virtual CARAPI PeekInt16(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * src,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ Elastos::IO::ByteOrder order,
        /* [out] */ _ELASTOS Int16 * result) = 0;

    virtual CARAPI PokeInt32(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * dst,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 value,
        /* [in] */ Elastos::IO::ByteOrder order) = 0;

    virtual CARAPI PokeInt64(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * dst,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int64 value,
        /* [in] */ Elastos::IO::ByteOrder order) = 0;

    virtual CARAPI PokeInt16(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * dst,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int16 value,
        /* [in] */ Elastos::IO::ByteOrder order) = 0;

    virtual CARAPI Memmove(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * dstObject,
        /* [in] */ _ELASTOS Int32 dstOffset,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * srcObject,
        /* [in] */ _ELASTOS Int32 srcOffset,
        /* [in] */ _ELASTOS Int64 byteCount) = 0;

    virtual CARAPI PeekByte(
        /* [in] */ _ELASTOS Int32 address,
        /* [out] */ _ELASTOS Byte * value) = 0;

    virtual CARAPI PeekInt32(
        /* [in] */ _ELASTOS Int32 address,
        /* [in] */ _ELASTOS Boolean swap,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI PeekInt64(
        /* [in] */ _ELASTOS Int32 address,
        /* [in] */ _ELASTOS Boolean swap,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI PeekInt16(
        /* [in] */ _ELASTOS Int32 address,
        /* [in] */ _ELASTOS Boolean swap,
        /* [out] */ _ELASTOS Int16 * value) = 0;

    virtual CARAPI PeekByteArray(
        /* [in] */ _ELASTOS Int32 address,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * dst,
        /* [in] */ _ELASTOS Int32 dstOffset,
        /* [in] */ _ELASTOS Int32 byteCount) = 0;

    virtual CARAPI PeekCharArray(
        /* [in] */ _ELASTOS Int32 address,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * dst,
        /* [in] */ _ELASTOS Int32 dstOffset,
        /* [in] */ _ELASTOS Int32 charCount,
        /* [in] */ _ELASTOS Boolean swap) = 0;

    virtual CARAPI PeekDoubleArray(
        /* [in] */ _ELASTOS Int32 address,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Double> * dst,
        /* [in] */ _ELASTOS Int32 dstOffset,
        /* [in] */ _ELASTOS Int32 doubleCount,
        /* [in] */ _ELASTOS Boolean swap) = 0;

    virtual CARAPI PeekFloatArray(
        /* [in] */ _ELASTOS Int32 address,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Float> * dst,
        /* [in] */ _ELASTOS Int32 dstOffset,
        /* [in] */ _ELASTOS Int32 floatCount,
        /* [in] */ _ELASTOS Boolean swap) = 0;

    virtual CARAPI PeekInt32Array(
        /* [in] */ _ELASTOS Int32 address,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * dst,
        /* [in] */ _ELASTOS Int32 dstOffset,
        /* [in] */ _ELASTOS Int32 int32Count,
        /* [in] */ _ELASTOS Boolean swap) = 0;

    virtual CARAPI PeekInt64Array(
        /* [in] */ _ELASTOS Int32 address,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int64> * dst,
        /* [in] */ _ELASTOS Int32 dstOffset,
        /* [in] */ _ELASTOS Int32 int64Count,
        /* [in] */ _ELASTOS Boolean swap) = 0;

    virtual CARAPI PeekInt16Array(
        /* [in] */ _ELASTOS Int32 address,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int16> * dst,
        /* [in] */ _ELASTOS Int32 dstOffset,
        /* [in] */ _ELASTOS Int32 int16Count,
        /* [in] */ _ELASTOS Boolean swap) = 0;

    virtual CARAPI PokeByte(
        /* [in] */ _ELASTOS Int32 address,
        /* [in] */ _ELASTOS Byte value) = 0;

    virtual CARAPI PokeInt32(
        /* [in] */ _ELASTOS Int32 address,
        /* [in] */ _ELASTOS Int32 value,
        /* [in] */ _ELASTOS Boolean swap) = 0;

    virtual CARAPI PokeInt64(
        /* [in] */ _ELASTOS Int32 address,
        /* [in] */ _ELASTOS Int64 value,
        /* [in] */ _ELASTOS Boolean swap) = 0;

    virtual CARAPI PokeInt16(
        /* [in] */ _ELASTOS Int32 address,
        /* [in] */ _ELASTOS Int16 value,
        /* [in] */ _ELASTOS Boolean swap) = 0;

    virtual CARAPI PokeByteArray(
        /* [in] */ _ELASTOS Int32 address,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * src,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 count) = 0;

    virtual CARAPI PokeCharArray(
        /* [in] */ _ELASTOS Int32 address,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * src,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 count,
        /* [in] */ _ELASTOS Boolean swap) = 0;

    virtual CARAPI PokeDoubleArray(
        /* [in] */ _ELASTOS Int32 address,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Double> * src,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 count,
        /* [in] */ _ELASTOS Boolean swap) = 0;

    virtual CARAPI PokeFloatArray(
        /* [in] */ _ELASTOS Int32 address,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Float> * src,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 count,
        /* [in] */ _ELASTOS Boolean swap) = 0;

    virtual CARAPI PokeInt32Array(
        /* [in] */ _ELASTOS Int32 address,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * src,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 count,
        /* [in] */ _ELASTOS Boolean swap) = 0;

    virtual CARAPI PokeInt64Array(
        /* [in] */ _ELASTOS Int32 address,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int64> * src,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 count,
        /* [in] */ _ELASTOS Boolean swap) = 0;

    virtual CARAPI PokeInt16Array(
        /* [in] */ _ELASTOS Int32 address,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int16> * src,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 count,
        /* [in] */ _ELASTOS Boolean swap) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("2DED462B-CC52-3396-F453-FB71D1447E14")
IMemoryMappedFile : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMemoryMappedFile*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMemoryMappedFile*)pObj->Probe(EIID_IMemoryMappedFile);
    }

    static CARAPI_(IMemoryMappedFile*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMemoryMappedFile*)pObj->Probe(EIID_IMemoryMappedFile);
    }

    virtual CARAPI BigEndianIterator(
        /* [out] */ Libcore::IO::IBufferIterator ** it) = 0;

    virtual CARAPI LittleEndianIterator(
        /* [out] */ Libcore::IO::IBufferIterator ** it) = 0;

    virtual CARAPI Size(
        /* [out] */ _ELASTOS Int64 * size) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("A641292D-CC52-3396-F453-8B80E2C58CFB")
IMemoryMappedFileHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMemoryMappedFileHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMemoryMappedFileHelper*)pObj->Probe(EIID_IMemoryMappedFileHelper);
    }

    static CARAPI_(IMemoryMappedFileHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMemoryMappedFileHelper*)pObj->Probe(EIID_IMemoryMappedFileHelper);
    }

    virtual CARAPI MmapRO(
        /* [in] */ const _ELASTOS String& path,
        /* [out] */ Libcore::IO::IMemoryMappedFile ** file) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("C7B4132D-E852-3FA5-2E9A-C88FE287BB1F")
ISizeOf : public IInterface
{
    static const _ELASTOS Int32 CHAR = 4;
    static const _ELASTOS Int32 DOUBLE = 8;
    static const _ELASTOS Int32 FLOAT = 4;
    static const _ELASTOS Int32 INT16 = 2;
    static const _ELASTOS Int32 INT32 = 4;
    static const _ELASTOS Int32 INT64 = 8;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISizeOf*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISizeOf*)pObj->Probe(EIID_ISizeOf);
    }

    static CARAPI_(ISizeOf*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISizeOf*)pObj->Probe(EIID_ISizeOf);
    }

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("2AD31E3A-05D2-3216-D448-B8719FC48DFC")
INioBufferIterator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INioBufferIterator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INioBufferIterator*)pObj->Probe(EIID_INioBufferIterator);
    }

    static CARAPI_(INioBufferIterator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INioBufferIterator*)pObj->Probe(EIID_INioBufferIterator);
    }

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("7C18202C-2A52-CDA6-7E5C-34911FC50F77")
IDeleteOnExit : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDeleteOnExit*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDeleteOnExit*)pObj->Probe(EIID_IDeleteOnExit);
    }

    static CARAPI_(IDeleteOnExit*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDeleteOnExit*)pObj->Probe(EIID_IDeleteOnExit);
    }

    virtual CARAPI AddFile(
        /* [in] */ const _ELASTOS String& filename) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("64002A31-2A52-CDA6-22A0-7831E3FE8F8B")
IDeleteOnExitHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDeleteOnExitHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDeleteOnExitHelper*)pObj->Probe(EIID_IDeleteOnExitHelper);
    }

    static CARAPI_(IDeleteOnExitHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDeleteOnExitHelper*)pObj->Probe(EIID_IDeleteOnExitHelper);
    }

    virtual CARAPI GetInstance(
        /* [out] */ Libcore::IO::IDeleteOnExit ** instance) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("6BD62325-E052-3FFB-2E9A-C88FE287BB1F")
IReporter : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IReporter*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IReporter*)pObj->Probe(EIID_IReporter);
    }

    static CARAPI_(IReporter*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IReporter*)pObj->Probe(EIID_IReporter);
    }

    virtual CARAPI AddData(
        /* [in] */ const _ELASTOS String& tag,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 flags) = 0;

    virtual CARAPI AddText(
        /* [in] */ const _ELASTOS String& tag,
        /* [in] */ const _ELASTOS String& data) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("815B3833-AF12-3205-76FC-B868223F8A1F")
IDropBox : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDropBox*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDropBox*)pObj->Probe(EIID_IDropBox);
    }

    static CARAPI_(IDropBox*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDropBox*)pObj->Probe(EIID_IDropBox);
    }

    virtual CARAPI SetReporter(
        /* [in] */ Libcore::IO::IReporter * reporter) = 0;

    virtual CARAPI GetReporter(
        /* [out] */ Libcore::IO::IReporter ** reporter) = 0;

    virtual CARAPI AddData(
        /* [in] */ const _ELASTOS String& tag,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * data,
        /* [in] */ _ELASTOS Int32 flags) = 0;

    virtual CARAPI AddText(
        /* [in] */ const _ELASTOS String& tag,
        /* [in] */ const _ELASTOS String& data) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("B588A01C-2492-377B-FBDA-7FC596A65CA3")
IIoUtils : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IIoUtils*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IIoUtils*)pObj->Probe(EIID_IIoUtils);
    }

    static CARAPI_(IIoUtils*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IIoUtils*)pObj->Probe(EIID_IIoUtils);
    }

    virtual CARAPI Close(
        /* [in] */ Elastos::IO::IFileDescriptor * fd) = 0;

    virtual CARAPI CloseQuietly(
        /* [in] */ Elastos::IO::ICloseable * closeable) = 0;

    virtual CARAPI CloseQuietly(
        /* [in] */ Elastos::IO::IFileDescriptor * fd) = 0;

    virtual CARAPI CloseQuietly(
        /* [in] */ Elastos::Net::ISocket * socket) = 0;

    virtual CARAPI SetBlocking(
        /* [in] */ Elastos::IO::IFileDescriptor * fd,
        /* [in] */ _ELASTOS Boolean blocking) = 0;

    virtual CARAPI ReadFileAsByteArray(
        /* [in] */ const _ELASTOS String& absolutePath,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** arr) = 0;

    virtual CARAPI ReadFileAsString(
        /* [in] */ const _ELASTOS String& absolutePath,
        /* [out] */ _ELASTOS String * rst) = 0;

    virtual CARAPI DeleteContents(
        /* [in] */ Elastos::IO::IFile * dir) = 0;

    virtual CARAPI CreateTemporaryDirectory(
        /* [in] */ const _ELASTOS String& prefix,
        /* [out] */ Elastos::IO::IFile ** directory) = 0;

    virtual CARAPI CanOpenReadOnly(
        /* [in] */ const _ELASTOS String& path,
        /* [out] */ _ELASTOS Boolean * canOpen) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("7A1F9715-7712-28D7-09DB-7FC596A65CA3")
IStreams : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IStreams*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStreams*)pObj->Probe(EIID_IStreams);
    }

    static CARAPI_(IStreams*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStreams*)pObj->Probe(EIID_IStreams);
    }

    virtual CARAPI ReadSingleByte(
        /* [in] */ Elastos::IO::IInputStream * instream,
        /* [out] */ _ELASTOS Int32 * singleByte) = 0;

    virtual CARAPI WriteSingleByte(
        /* [in] */ Elastos::IO::IOutputStream * outstream,
        /* [in] */ _ELASTOS Int32 b) = 0;

    virtual CARAPI ReadFully(
        /* [in] */ Elastos::IO::IInputStream * instream,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** dst) = 0;

    virtual CARAPI ReadFully(
        /* [in] */ Elastos::IO::IInputStream * instream,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * dst,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 byteCount) = 0;

    virtual CARAPI ReadFullyCloseWhenDone(
        /* [in] */ Elastos::IO::IInputStream * instream,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** bytes) = 0;

    virtual CARAPI ReadFullyNoClose(
        /* [in] */ Elastos::IO::IInputStream * instream,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** byteArray) = 0;

    virtual CARAPI ReadFully(
        /* [in] */ Elastos::IO::IReader * reader,
        /* [out] */ _ELASTOS String * result) = 0;

    virtual CARAPI SkipAll(
        /* [in] */ Elastos::IO::IInputStream * instream) = 0;

    virtual CARAPI SkipByReading(
        /* [in] */ Elastos::IO::IInputStream * instream,
        /* [in] */ _ELASTOS Int64 byteCount,
        /* [out] */ _ELASTOS Int64 * result) = 0;

    virtual CARAPI Copy(
        /* [in] */ Elastos::IO::IInputStream * instream,
        /* [in] */ Elastos::IO::IOutputStream * outstream,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI ReadAsciiLine(
        /* [in] */ Elastos::IO::IInputStream * instream,
        /* [out] */ _ELASTOS String * characters) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("16AC415D-9B12-3781-2A3C-3CF3EC470516")
IStrictLineReader : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IStrictLineReader*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStrictLineReader*)pObj->Probe(EIID_IStrictLineReader);
    }

    static CARAPI_(IStrictLineReader*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStrictLineReader*)pObj->Probe(EIID_IStrictLineReader);
    }

    virtual CARAPI ReadLine(
        /* [out] */ _ELASTOS String * line) = 0;

    virtual CARAPI ReadInt32(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI HasUnterminatedLine(
        /* [out] */ _ELASTOS Boolean * value) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("E356712E-0312-2B2D-6AC8-882103878D3F")
ICAsynchronousCloseMonitorClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAsynchronousCloseMonitorClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAsynchronousCloseMonitorClassObject*)pObj->Probe(EIID_ICAsynchronousCloseMonitorClassObject);
    }

    static CARAPI_(ICAsynchronousCloseMonitorClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAsynchronousCloseMonitorClassObject*)pObj->Probe(EIID_ICAsynchronousCloseMonitorClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("07405F2D-8312-0630-08E8-31FAE3A289FC")
ICBase64ClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICBase64ClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBase64ClassObject*)pObj->Probe(EIID_ICBase64ClassObject);
    }

    static CARAPI_(ICBase64ClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBase64ClassObject*)pObj->Probe(EIID_ICBase64ClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("7EEC602E-8312-268B-F2A3-D063F4C74513")
ICLibcoreClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICLibcoreClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLibcoreClassObject*)pObj->Probe(EIID_ICLibcoreClassObject);
    }

    static CARAPI_(ICLibcoreClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLibcoreClassObject*)pObj->Probe(EIID_ICLibcoreClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("56CF6131-8312-0B77-6AB0-38A102851EA3")
ICIoBridgeClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICIoBridgeClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICIoBridgeClassObject*)pObj->Probe(EIID_ICIoBridgeClassObject);
    }

    static CARAPI_(ICIoBridgeClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICIoBridgeClassObject*)pObj->Probe(EIID_ICIoBridgeClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("2FD46B29-8312-1DD2-48A8-50713F028A17")
ICSocketTaggerHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSocketTaggerHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSocketTaggerHelperClassObject*)pObj->Probe(EIID_ICSocketTaggerHelperClassObject);
    }

    static CARAPI_(ICSocketTaggerHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSocketTaggerHelperClassObject*)pObj->Probe(EIID_ICSocketTaggerHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("76D56028-0312-28D9-48C0-B0A1C7E88F8B")
ICStreamsClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICStreamsClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStreamsClassObject*)pObj->Probe(EIID_ICStreamsClassObject);
    }

    static CARAPI_(ICStreamsClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStreamsClassObject*)pObj->Probe(EIID_ICStreamsClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("2EEE6B32-8312-4C54-9B45-40F162C67D3D")
ICDeleteOnExitHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDeleteOnExitHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDeleteOnExitHelperClassObject*)pObj->Probe(EIID_ICDeleteOnExitHelperClassObject);
    }

    static CARAPI_(ICDeleteOnExitHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDeleteOnExitHelperClassObject*)pObj->Probe(EIID_ICDeleteOnExitHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("6C016030-0312-0B5E-64EC-D063F4C74513")
ICDropBoxClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDropBoxClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDropBoxClassObject*)pObj->Probe(EIID_ICDropBoxClassObject);
    }

    static CARAPI_(ICDropBoxClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDropBoxClassObject*)pObj->Probe(EIID_ICDropBoxClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("6DF4603F-8312-1E77-6EB0-7861438FD11F")
ICIoUtilsClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICIoUtilsClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICIoUtilsClassObject*)pObj->Probe(EIID_ICIoUtilsClassObject);
    }

    static CARAPI_(ICIoUtilsClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICIoUtilsClassObject*)pObj->Probe(EIID_ICIoUtilsClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("DCF66930-8312-2D98-67E8-A7A6C7E88F8B")
ICMemoryMappedFileClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICMemoryMappedFileClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMemoryMappedFileClassObject*)pObj->Probe(EIID_ICMemoryMappedFileClassObject);
    }

    static CARAPI_(ICMemoryMappedFileClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMemoryMappedFileClassObject*)pObj->Probe(EIID_ICMemoryMappedFileClassObject);
    }

    virtual CARAPI CreateObjectWithAddressSize(
        /* [in] */ _ELASTOS Int64 address,
        /* [in] */ _ELASTOS Int64 size,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("7B8DC057-0312-0336-6F54-7878E6190393")
ICStrictLineReaderClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICStrictLineReaderClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStrictLineReaderClassObject*)pObj->Probe(EIID_ICStrictLineReaderClassObject);
    }

    static CARAPI_(ICStrictLineReaderClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStrictLineReaderClassObject*)pObj->Probe(EIID_ICStrictLineReaderClassObject);
    }

    virtual CARAPI CreateObjectWithInput(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithInputCapacity(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithInputCharset(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [in] */ Elastos::IO::Charset::ICharset * Charset,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithInputCapacityCharset(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ Elastos::IO::Charset::ICharset * Charset,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace IO {
CAR_INTERFACE("E5335E3B-8312-320C-6CB0-D8A1C7E88F8B")
ICPosixClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPosixClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPosixClassObject*)pObj->Probe(EIID_ICPosixClassObject);
    }

    static CARAPI_(ICPosixClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPosixClassObject*)pObj->Probe(EIID_ICPosixClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace Utility {
CAR_INTERFACE("7F3D353C-9892-350A-70C0-F971D1447E14")
IBasicLruCache : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBasicLruCache*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBasicLruCache*)pObj->Probe(EIID_IBasicLruCache);
    }

    static CARAPI_(IBasicLruCache*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBasicLruCache*)pObj->Probe(EIID_IBasicLruCache);
    }

    virtual CARAPI Get(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** ouface) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI Snapshot(
        /* [out] */ Elastos::Utility::IMap ** outmap) = 0;

    virtual CARAPI EvictAll() = 0;

};
}
}
namespace Libcore {
namespace Utility {
CAR_INTERFACE("370C445D-1152-AF97-267A-F8FCC2C68F0A")
ICollectionUtils : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICollectionUtils*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollectionUtils*)pObj->Probe(EIID_ICollectionUtils);
    }

    static CARAPI_(ICollectionUtils*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollectionUtils*)pObj->Probe(EIID_ICollectionUtils);
    }

    virtual CARAPI DereferenceIterable(
        /* [in] */ Elastos::Utility::IIterable * iterable,
        /* [in] */ _ELASTOS Boolean trim,
        /* [out] */ Elastos::Utility::IIterable ** outiter) = 0;

    virtual CARAPI RemoveDuplicates(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ Elastos::Core::IComparator * comparator) = 0;

};
}
}
namespace Libcore {
namespace Utility {
CAR_INTERFACE("65DF1A3C-FB12-3F7D-2E9A-C88FE287871B")
IZoneInfo : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IZoneInfo*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IZoneInfo*)pObj->Probe(EIID_IZoneInfo);
    }

    static CARAPI_(IZoneInfo*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IZoneInfo*)pObj->Probe(EIID_IZoneInfo);
    }

};
}
}
namespace Libcore {
namespace Utility {
CAR_INTERFACE("E1532C3E-FB12-117D-50BC-9871FFC74513")
IZoneInfoHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IZoneInfoHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IZoneInfoHelper*)pObj->Probe(EIID_IZoneInfoHelper);
    }

    static CARAPI_(IZoneInfoHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IZoneInfoHelper*)pObj->Probe(EIID_IZoneInfoHelper);
    }

    virtual CARAPI MakeTimeZone(
        /* [in] */ const _ELASTOS String& id,
        /* [in] */ Libcore::IO::IBufferIterator * it,
        /* [out] */ Libcore::Utility::IZoneInfo ** zoneInfo) = 0;

};
}
}
namespace Libcore {
namespace Utility {
CAR_INTERFACE("2B707928-D252-F782-7390-78F1E3A289FC")
IOffsetInterval : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IOffsetInterval*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IOffsetInterval*)pObj->Probe(EIID_IOffsetInterval);
    }

    static CARAPI_(IOffsetInterval*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IOffsetInterval*)pObj->Probe(EIID_IOffsetInterval);
    }

    virtual CARAPI ContainsWallTime(
        /* [in] */ _ELASTOS Int64 wallTimeSeconds,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetIsDst(
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI GetTotalOffsetSeconds(
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI GetEndWallTimeSeconds(
        /* [out] */ _ELASTOS Int64 * result) = 0;

    virtual CARAPI GetStartWallTimeSeconds(
        /* [out] */ _ELASTOS Int64 * result) = 0;

};
}
}
namespace Libcore {
namespace Utility {
CAR_INTERFACE("DE272C27-D252-F782-7390-781101C58B19")
IOffsetIntervalHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IOffsetIntervalHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IOffsetIntervalHelper*)pObj->Probe(EIID_IOffsetIntervalHelper);
    }

    static CARAPI_(IOffsetIntervalHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IOffsetIntervalHelper*)pObj->Probe(EIID_IOffsetIntervalHelper);
    }

    virtual CARAPI Create(
        /* [in] */ Libcore::Utility::IZoneInfo * timeZone,
        /* [in] */ _ELASTOS Int32 transitionIndex,
        /* [out] */ Libcore::Utility::IOffsetInterval ** result) = 0;

};
}
}
namespace Libcore {
namespace Utility {
CAR_INTERFACE("0CE4E721-FB12-207D-48BC-7851FCC74513")
IZoneInfoWallTime : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IZoneInfoWallTime*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IZoneInfoWallTime*)pObj->Probe(EIID_IZoneInfoWallTime);
    }

    static CARAPI_(IZoneInfoWallTime*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IZoneInfoWallTime*)pObj->Probe(EIID_IZoneInfoWallTime);
    }

    virtual CARAPI Localtime(
        /* [in] */ _ELASTOS Int32 timeSeconds,
        /* [in] */ Libcore::Utility::IZoneInfo * zoneInfo) = 0;

    virtual CARAPI Mktime(
        /* [in] */ Libcore::Utility::IZoneInfo * zoneInfo,
        /* [out] */ _ELASTOS Int32 * rst) = 0;

    virtual CARAPI SetYear(
        /* [in] */ _ELASTOS Int32 year) = 0;

    virtual CARAPI SetMonth(
        /* [in] */ _ELASTOS Int32 month) = 0;

    virtual CARAPI SetMonthDay(
        /* [in] */ _ELASTOS Int32 monthDay) = 0;

    virtual CARAPI SetHour(
        /* [in] */ _ELASTOS Int32 hour) = 0;

    virtual CARAPI SetMinute(
        /* [in] */ _ELASTOS Int32 minute) = 0;

    virtual CARAPI SetSecond(
        /* [in] */ _ELASTOS Int32 second) = 0;

    virtual CARAPI SetWeekDay(
        /* [in] */ _ELASTOS Int32 weekDay) = 0;

    virtual CARAPI SetYearDay(
        /* [in] */ _ELASTOS Int32 yearDay) = 0;

    virtual CARAPI SetIsDst(
        /* [in] */ _ELASTOS Int32 isDst) = 0;

    virtual CARAPI SetGmtOffset(
        /* [in] */ _ELASTOS Int32 gmtoff) = 0;

    virtual CARAPI GetYear(
        /* [out] */ _ELASTOS Int32 * year) = 0;

    virtual CARAPI GetMonth(
        /* [out] */ _ELASTOS Int32 * month) = 0;

    virtual CARAPI GetMonthDay(
        /* [out] */ _ELASTOS Int32 * monthDay) = 0;

    virtual CARAPI GetHour(
        /* [out] */ _ELASTOS Int32 * hour) = 0;

    virtual CARAPI GetMinute(
        /* [out] */ _ELASTOS Int32 * minute) = 0;

    virtual CARAPI GetSecond(
        /* [out] */ _ELASTOS Int32 * second) = 0;

    virtual CARAPI GetWeekDay(
        /* [out] */ _ELASTOS Int32 * weekDay) = 0;

    virtual CARAPI GetYearDay(
        /* [out] */ _ELASTOS Int32 * yearDay) = 0;

    virtual CARAPI GetIsDst(
        /* [out] */ _ELASTOS Int32 * isDst) = 0;

    virtual CARAPI GetGmtOffset(
        /* [out] */ _ELASTOS Int32 * gmtoff) = 0;

};
}
}
namespace Libcore {
namespace Utility {
CAR_INTERFACE("D5745634-8752-981E-7E5C-34911FC50F0F")
ITzData : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITzData*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITzData*)pObj->Probe(EIID_ITzData);
    }

    static CARAPI_(ITzData*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITzData*)pObj->Probe(EIID_ITzData);
    }

    virtual CARAPI GetAvailableIDs(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** array) = 0;

    virtual CARAPI GetAvailableIDs(
        /* [in] */ _ELASTOS Int32 rawOffset,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** array) = 0;

    virtual CARAPI GetVersion(
        /* [out] */ _ELASTOS String * v) = 0;

    virtual CARAPI GetZoneTab(
        /* [out] */ _ELASTOS String * tab) = 0;

    virtual CARAPI MakeTimeZone(
        /* [in] */ const _ELASTOS String& id,
        /* [out] */ Libcore::Utility::IZoneInfo ** tz) = 0;

};
}
}
namespace Libcore {
namespace Utility {
CAR_INTERFACE("D58F2732-FB12-0D7D-16FC-B868223F8A1F")
IZoneInfoDB : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IZoneInfoDB*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IZoneInfoDB*)pObj->Probe(EIID_IZoneInfoDB);
    }

    static CARAPI_(IZoneInfoDB*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IZoneInfoDB*)pObj->Probe(EIID_IZoneInfoDB);
    }

    virtual CARAPI GetInstance(
        /* [out] */ Libcore::Utility::ITzData ** instance) = 0;

};
}
}
namespace Libcore {
namespace Utility {
CAR_INTERFACE("027D673D-0312-1531-6AE0-80A3C7E88F8B")
ICBasicLruCacheClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICBasicLruCacheClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBasicLruCacheClassObject*)pObj->Probe(EIID_ICBasicLruCacheClassObject);
    }

    static CARAPI_(ICBasicLruCacheClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBasicLruCacheClassObject*)pObj->Probe(EIID_ICBasicLruCacheClassObject);
    }

    virtual CARAPI CreateObjectWithMaxSize(
        /* [in] */ _ELASTOS Int32 maxSize,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace Utility {
CAR_INTERFACE("A0E16E33-0312-FBF6-4090-78F1A2B81EA3")
ICZoneInfoWallTimeClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICZoneInfoWallTimeClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICZoneInfoWallTimeClassObject*)pObj->Probe(EIID_ICZoneInfoWallTimeClassObject);
    }

    static CARAPI_(ICZoneInfoWallTimeClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICZoneInfoWallTimeClassObject*)pObj->Probe(EIID_ICZoneInfoWallTimeClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace Utility {
CAR_INTERFACE("7A326D4E-8312-2E22-5F4D-F4F0F9850D06")
ICCollectionUtilsClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCollectionUtilsClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCollectionUtilsClassObject*)pObj->Probe(EIID_ICCollectionUtilsClassObject);
    }

    static CARAPI_(ICCollectionUtilsClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCollectionUtilsClassObject*)pObj->Probe(EIID_ICCollectionUtilsClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace Utility {
CAR_INTERFACE("A3187222-8312-05A4-EFE7-20F122028A17")
ICOffsetIntervalHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICOffsetIntervalHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICOffsetIntervalHelperClassObject*)pObj->Probe(EIID_ICOffsetIntervalHelperClassObject);
    }

    static CARAPI_(ICOffsetIntervalHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICOffsetIntervalHelperClassObject*)pObj->Probe(EIID_ICOffsetIntervalHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace Utility {
CAR_INTERFACE("F54C6C39-0312-FBF6-22A0-7831E3BE1EA3")
ICZoneInfoHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICZoneInfoHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICZoneInfoHelperClassObject*)pObj->Probe(EIID_ICZoneInfoHelperClassObject);
    }

    static CARAPI_(ICZoneInfoHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICZoneInfoHelperClassObject*)pObj->Probe(EIID_ICZoneInfoHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace Utility {
CAR_INTERFACE("FB22682F-0312-FBF6-1A2C-D063F4C74513")
ICZoneInfoDBClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICZoneInfoDBClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICZoneInfoDBClassObject*)pObj->Probe(EIID_ICZoneInfoDBClassObject);
    }

    static CARAPI_(ICZoneInfoDBClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICZoneInfoDBClassObject*)pObj->Probe(EIID_ICZoneInfoDBClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace Net {
CAR_INTERFACE("6DF26211-C592-A8C2-77B3-AFFD576C69CA")
IMimeUtils : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMimeUtils*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMimeUtils*)pObj->Probe(EIID_IMimeUtils);
    }

    static CARAPI_(IMimeUtils*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMimeUtils*)pObj->Probe(EIID_IMimeUtils);
    }

    virtual CARAPI HasMineType(
        /* [in] */ const _ELASTOS String& mimeType,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GuessMimeTypeFromExtension(
        /* [in] */ const _ELASTOS String& extension,
        /* [out] */ _ELASTOS String * result) = 0;

    virtual CARAPI HasExtension(
        /* [in] */ const _ELASTOS String& extension,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GuessExtensionFromMimeType(
        /* [in] */ const _ELASTOS String& mimeType,
        /* [out] */ _ELASTOS String * result) = 0;

};
}
}
namespace Libcore {
namespace Net {
CAR_INTERFACE("0FCD473C-8792-2C1A-0099-F871D1447E14")
IUriCodec : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IUriCodec*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IUriCodec*)pObj->Probe(EIID_IUriCodec);
    }

    static CARAPI_(IUriCodec*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IUriCodec*)pObj->Probe(EIID_IUriCodec);
    }

    virtual CARAPI Validate(
        /* [in] */ const _ELASTOS String& uri,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS String * result) = 0;

    virtual CARAPI Encode(
        /* [in] */ const _ELASTOS String& s,
        /* [in] */ Elastos::IO::Charset::ICharset * charset,
        /* [out] */ _ELASTOS String * result) = 0;

    virtual CARAPI AppendEncoded(
        /* [in] */ Elastos::Core::IStringBuilder * builder,
        /* [in] */ const _ELASTOS String& s) = 0;

    virtual CARAPI AppendPartiallyEncoded(
        /* [in] */ Elastos::Core::IStringBuilder * builder,
        /* [in] */ const _ELASTOS String& s) = 0;

};
}
}
namespace Libcore {
namespace Net {
CAR_INTERFACE("DBC93619-5792-8CB3-7CA2-6684BE335AFF")
IUriCodecHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IUriCodecHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IUriCodecHelper*)pObj->Probe(EIID_IUriCodecHelper);
    }

    static CARAPI_(IUriCodecHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IUriCodecHelper*)pObj->Probe(EIID_IUriCodecHelper);
    }

    virtual CARAPI ValidateSimple(
        /* [in] */ const _ELASTOS String& s,
        /* [in] */ const _ELASTOS String& legal) = 0;

    virtual CARAPI Decode(
        /* [in] */ const _ELASTOS String& s,
        /* [out] */ _ELASTOS String * result) = 0;

    virtual CARAPI Decode(
        /* [in] */ const _ELASTOS String& s,
        /* [in] */ _ELASTOS Boolean convertPlus,
        /* [in] */ Elastos::IO::Charset::ICharset * charset,
        /* [in] */ _ELASTOS Boolean throwOnFailure,
        /* [out] */ _ELASTOS String * result) = 0;

};
}
}
namespace Libcore {
namespace Net {
namespace Http {
CAR_INTERFACE("FBE92621-8452-371B-6664-FA71D1447E14")
IHttpDate : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IHttpDate*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHttpDate*)pObj->Probe(EIID_IHttpDate);
    }

    static CARAPI_(IHttpDate*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHttpDate*)pObj->Probe(EIID_IHttpDate);
    }

    virtual CARAPI Parse(
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ Elastos::Utility::IDate ** adate) = 0;

    virtual CARAPI Format(
        /* [in] */ Elastos::Utility::IDate * value,
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
namespace Libcore {
namespace Net {
namespace Url {
CAR_INTERFACE("81191D23-B512-3F73-2E9A-C88FE2C70514")
IFileHandler : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFileHandler*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileHandler*)pObj->Probe(EIID_IFileHandler);
    }

    static CARAPI_(IFileHandler*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileHandler*)pObj->Probe(EIID_IFileHandler);
    }

};
}
}
}
namespace Libcore {
namespace Net {
namespace Url {
CAR_INTERFACE("5BF7232D-3512-8CE6-7E5C-34911FC58F0B")
IFileURLConnection : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFileURLConnection*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileURLConnection*)pObj->Probe(EIID_IFileURLConnection);
    }

    static CARAPI_(IFileURLConnection*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFileURLConnection*)pObj->Probe(EIID_IFileURLConnection);
    }

};
}
}
}
namespace Libcore {
namespace Net {
namespace Url {
CAR_INTERFACE("4BA51C33-83D2-331B-CEFD-B868223F8A1F")
IFtpHandler : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFtpHandler*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFtpHandler*)pObj->Probe(EIID_IFtpHandler);
    }

    static CARAPI_(IFtpHandler*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFtpHandler*)pObj->Probe(EIID_IFtpHandler);
    }

};
}
}
}
namespace Libcore {
namespace Net {
namespace Url {
CAR_INTERFACE("2980223A-83D2-331B-9833-FA71D1447E14")
IFtpURLConnection : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFtpURLConnection*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFtpURLConnection*)pObj->Probe(EIID_IFtpURLConnection);
    }

    static CARAPI_(IFtpURLConnection*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFtpURLConnection*)pObj->Probe(EIID_IFtpURLConnection);
    }

};
}
}
}
namespace Libcore {
namespace Net {
namespace Url {
CAR_INTERFACE("4AF2232D-83D2-331B-98FF-938D82048C1F")
IFtpURLInputStream : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFtpURLInputStream*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFtpURLInputStream*)pObj->Probe(EIID_IFtpURLInputStream);
    }

    static CARAPI_(IFtpURLInputStream*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFtpURLInputStream*)pObj->Probe(EIID_IFtpURLInputStream);
    }

};
}
}
}
namespace Libcore {
namespace Net {
namespace Url {
CAR_INTERFACE("45B81C28-04D2-3512-CEFD-B868223F8A1F")
IJarHandler : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IJarHandler*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJarHandler*)pObj->Probe(EIID_IJarHandler);
    }

    static CARAPI_(IJarHandler*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJarHandler*)pObj->Probe(EIID_IJarHandler);
    }

};
}
}
}
namespace Libcore {
namespace Net {
namespace Url {
CAR_INTERFACE("69B92628-04D2-3512-9833-AAF7E3A289FC")
IJarURLConnectionImpl : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IJarURLConnectionImpl*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJarURLConnectionImpl*)pObj->Probe(EIID_IJarURLConnectionImpl);
    }

    static CARAPI_(IJarURLConnectionImpl*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJarURLConnectionImpl*)pObj->Probe(EIID_IJarURLConnectionImpl);
    }

};
}
}
}
namespace Libcore {
namespace Net {
namespace Url {
CAR_INTERFACE("3D5C3C2C-04D2-3512-9833-AA1701C58B19")
IJarURLConnectionImplHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IJarURLConnectionImplHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJarURLConnectionImplHelper*)pObj->Probe(EIID_IJarURLConnectionImplHelper);
    }

    static CARAPI_(IJarURLConnectionImplHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJarURLConnectionImplHelper*)pObj->Probe(EIID_IJarURLConnectionImplHelper);
    }

    virtual CARAPI CloseCachedFiles() = 0;

};
}
}
}
namespace Libcore {
namespace Net {
namespace Url {
CAR_INTERFACE("69D96C1D-5792-DEBF-CDBE-7684BE335AFF")
IUrlUtilsHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IUrlUtilsHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IUrlUtilsHelper*)pObj->Probe(EIID_IUrlUtilsHelper);
    }

    static CARAPI_(IUrlUtilsHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IUrlUtilsHelper*)pObj->Probe(EIID_IUrlUtilsHelper);
    }

    virtual CARAPI CanonicalizePath(
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ _ELASTOS Boolean discardRelativePrefix,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI AuthoritySafePath(
        /* [in] */ const _ELASTOS String& authority,
        /* [in] */ const _ELASTOS String& path,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetSchemePrefix(
        /* [in] */ const _ELASTOS String& spec,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI IsValidSchemeChar(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Char32 c,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI FindFirstOf(
        /* [in] */ const _ELASTOS String& string,
        /* [in] */ const _ELASTOS String& chars,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ _ELASTOS Int32 * value) = 0;

};
}
}
}
namespace Libcore {
namespace Net {
namespace Event {
CAR_INTERFACE("86974524-05D2-3714-74E4-77C12CE3FD1F")
INetworkEventListener : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INetworkEventListener*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INetworkEventListener*)pObj->Probe(EIID_INetworkEventListener);
    }

    static CARAPI_(INetworkEventListener*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INetworkEventListener*)pObj->Probe(EIID_INetworkEventListener);
    }

    virtual CARAPI OnNetworkConfigurationChanged() = 0;

};
}
}
}
namespace Libcore {
namespace Net {
namespace Event {
CAR_INTERFACE("B599601F-85D2-BADE-5CBB-4E8EC677C3DA")
INetworkEventDispatcher : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INetworkEventDispatcher*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INetworkEventDispatcher*)pObj->Probe(EIID_INetworkEventDispatcher);
    }

    static CARAPI_(INetworkEventDispatcher*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INetworkEventDispatcher*)pObj->Probe(EIID_INetworkEventDispatcher);
    }

    virtual CARAPI AddListener(
        /* [in] */ Libcore::Net::Event::INetworkEventListener * toAdd) = 0;

    virtual CARAPI RemoveListener(
        /* [in] */ Libcore::Net::Event::INetworkEventListener * toRemove) = 0;

    virtual CARAPI OnNetworkConfigurationChanged() = 0;

};
}
}
}
namespace Libcore {
namespace Net {
namespace Event {
CAR_INTERFACE("F0643B1E-85D2-BADE-5CBB-4E8EC677C3DA")
INetworkEventDispatcherHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INetworkEventDispatcherHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INetworkEventDispatcherHelper*)pObj->Probe(EIID_INetworkEventDispatcherHelper);
    }

    static CARAPI_(INetworkEventDispatcherHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INetworkEventDispatcherHelper*)pObj->Probe(EIID_INetworkEventDispatcherHelper);
    }

    virtual CARAPI GetInstance(
        /* [out] */ Libcore::Net::Event::INetworkEventDispatcher ** result) = 0;

};
}
}
}
namespace Libcore {
namespace Net {
CAR_INTERFACE("A1606318-6312-30B1-EADD-EC6B332F69DB")
ICMimeUtilsClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICMimeUtilsClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMimeUtilsClassObject*)pObj->Probe(EIID_ICMimeUtilsClassObject);
    }

    static CARAPI_(ICMimeUtilsClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMimeUtilsClassObject*)pObj->Probe(EIID_ICMimeUtilsClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace Net {
CAR_INTERFACE("1A116808-E312-2CD5-239F-A819A1EF8CD6")
ICUriCodecHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICUriCodecHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICUriCodecHelperClassObject*)pObj->Probe(EIID_ICUriCodecHelperClassObject);
    }

    static CARAPI_(ICUriCodecHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICUriCodecHelperClassObject*)pObj->Probe(EIID_ICUriCodecHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Libcore {
namespace Net {
namespace Http {
CAR_INTERFACE("2D806724-8312-3708-6ECC-C8A4C7E88F8B")
ICHttpDateClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICHttpDateClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICHttpDateClassObject*)pObj->Probe(EIID_ICHttpDateClassObject);
    }

    static CARAPI_(ICHttpDateClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICHttpDateClassObject*)pObj->Probe(EIID_ICHttpDateClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Libcore {
namespace Net {
namespace Url {
CAR_INTERFACE("95646924-0312-E76A-F418-FD71D1447E14")
ICFileHandlerClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICFileHandlerClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFileHandlerClassObject*)pObj->Probe(EIID_ICFileHandlerClassObject);
    }

    static CARAPI_(ICFileHandlerClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFileHandlerClassObject*)pObj->Probe(EIID_ICFileHandlerClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Libcore {
namespace Net {
namespace Url {
CAR_INTERFACE("2CB36734-0312-CC6A-19E9-31FAE3A289FC")
ICFileURLConnectionClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICFileURLConnectionClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFileURLConnectionClassObject*)pObj->Probe(EIID_ICFileURLConnectionClassObject);
    }

    static CARAPI_(ICFileURLConnectionClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFileURLConnectionClassObject*)pObj->Probe(EIID_ICFileURLConnectionClassObject);
    }

    virtual CARAPI CreateObjectWithUrl(
        /* [in] */ Elastos::Net::IURL * url,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Libcore {
namespace Net {
namespace Url {
CAR_INTERFACE("351B6830-8312-3707-669C-D363F4C74513")
ICFtpHandlerClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICFtpHandlerClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFtpHandlerClassObject*)pObj->Probe(EIID_ICFtpHandlerClassObject);
    }

    static CARAPI_(ICFtpHandlerClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFtpHandlerClassObject*)pObj->Probe(EIID_ICFtpHandlerClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Libcore {
namespace Net {
namespace Url {
CAR_INTERFACE("C031732F-8312-3707-6630-FF271B050918")
ICFtpURLInputStreamClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICFtpURLInputStreamClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFtpURLInputStreamClassObject*)pObj->Probe(EIID_ICFtpURLInputStreamClassObject);
    }

    static CARAPI_(ICFtpURLInputStreamClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFtpURLInputStreamClassObject*)pObj->Probe(EIID_ICFtpURLInputStreamClassObject);
    }

    virtual CARAPI CreateObjectWithIsControlSocket(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Net::ISocket * controlSocket,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Libcore {
namespace Net {
namespace Url {
CAR_INTERFACE("52406C17-E312-AFD5-77B3-AF1DA1EF8CD6")
ICUrlUtilsHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICUrlUtilsHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICUrlUtilsHelperClassObject*)pObj->Probe(EIID_ICUrlUtilsHelperClassObject);
    }

    static CARAPI_(ICUrlUtilsHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICUrlUtilsHelperClassObject*)pObj->Probe(EIID_ICUrlUtilsHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Libcore {
namespace Net {
namespace Url {
CAR_INTERFACE("48156830-8312-2409-6A9C-D363F4C74513")
ICJarHandlerClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICJarHandlerClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJarHandlerClassObject*)pObj->Probe(EIID_ICJarHandlerClassObject);
    }

    static CARAPI_(ICJarHandlerClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJarHandlerClassObject*)pObj->Probe(EIID_ICJarHandlerClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Libcore {
namespace Net {
namespace Url {
CAR_INTERFACE("BCF26A36-8312-2409-6A30-67544F8FD11F")
ICJarURLConnectionImplClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICJarURLConnectionImplClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJarURLConnectionImplClassObject*)pObj->Probe(EIID_ICJarURLConnectionImplClassObject);
    }

    static CARAPI_(ICJarURLConnectionImplClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJarURLConnectionImplClassObject*)pObj->Probe(EIID_ICJarURLConnectionImplClassObject);
    }

    virtual CARAPI CreateObjectWithUrl(
        /* [in] */ Elastos::Net::IURL * url,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Libcore {
namespace Net {
namespace Event {
CAR_INTERFACE("ED207C15-7312-B7A1-2ED7-AE93A3F1DDB0")
ICNetworkEventDispatcherHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICNetworkEventDispatcherHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNetworkEventDispatcherHelperClassObject*)pObj->Probe(EIID_ICNetworkEventDispatcherHelperClassObject);
    }

    static CARAPI_(ICNetworkEventDispatcherHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNetworkEventDispatcherHelperClassObject*)pObj->Probe(EIID_ICNetworkEventDispatcherHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Libcore {
namespace ICU {
class CCollationElementIteratorICUHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::ICU::ICollationElementIteratorICUHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollationElementIteratorICUHelper, RGM_SAME_DOMAIN, Libcore::ICU::EIID_ICollationElementIteratorICUHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollationElementIteratorICUHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollationElementIteratorICUHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollationElementIteratorICUHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace ICU {
class CNativeCollationHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::ICU::INativeCollationHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativeCollationHelper, RGM_SAME_DOMAIN, Libcore::ICU::EIID_INativeCollationHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativeCollationHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativeCollationHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativeCollationHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace ICU {
class CCollationKeyICU
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& source,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * ab,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICCollationKeyICUClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CCollationKeyICU, RGM_SAME_DOMAIN,
                EIID_ICCollationKeyICUClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSourceAb(source, ab, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& source,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * ab,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(source, ab, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& source,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * ab,
        /* [out] */ Elastos::Text::ICollationKey** __ICollationKey)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(source, ab, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollationKey = (Elastos::Text::ICollationKey*)__pNewObj->Probe(Elastos::Text::EIID_ICollationKey);
        if (*__ICollationKey) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& source,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * ab,
        /* [out] */ Libcore::ICU::ICollationKeyICU** __ICollationKeyICU)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(source, ab, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollationKeyICU = (Libcore::ICU::ICollationKeyICU*)__pNewObj->Probe(Libcore::ICU::EIID_ICollationKeyICU);
        if (*__ICollationKeyICU) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& source,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * ab,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(source, ab, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& source,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * ab,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(source, ab, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& source,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * ab,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(source, ab, &__pNewObj);
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
namespace Libcore {
namespace ICU {
class CLocaleData
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Libcore::ICU::ILocaleData** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLocaleData, RGM_SAME_DOMAIN, Libcore::ICU::EIID_ILocaleData, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLocaleData, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLocaleData, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLocaleData, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace ICU {
class CLocaleDataHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::ICU::ILocaleDataHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLocaleDataHelper, RGM_SAME_DOMAIN, Libcore::ICU::EIID_ILocaleDataHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLocaleDataHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLocaleDataHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLocaleDataHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace ICU {
class CTimeZoneNames
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::ICU::ITimeZoneNames** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTimeZoneNames, RGM_SAME_DOMAIN, Libcore::ICU::EIID_ITimeZoneNames, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTimeZoneNames, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTimeZoneNames, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTimeZoneNames, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace ICU {
class CNativeIDNHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::ICU::INativeIDNHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativeIDNHelper, RGM_SAME_DOMAIN, Libcore::ICU::EIID_INativeIDNHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativeIDNHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativeIDNHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativeIDNHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace ICU {
class CNativeNormalizerHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::ICU::INativeNormalizerHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativeNormalizerHelper, RGM_SAME_DOMAIN, Libcore::ICU::EIID_INativeNormalizerHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativeNormalizerHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativeNormalizerHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativeNormalizerHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace ICU {
class CNativePluralRules
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int64 address,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICNativePluralRulesClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CNativePluralRules, RGM_SAME_DOMAIN,
                EIID_ICNativePluralRulesClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithAddress(address, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 address,
        /* [out] */ Libcore::ICU::INativePluralRules** __INativePluralRules)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INativePluralRules = (Libcore::ICU::INativePluralRules*)__pNewObj->Probe(Libcore::ICU::EIID_INativePluralRules);
        if (*__INativePluralRules) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 address,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 address,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 address,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, &__pNewObj);
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
namespace Libcore {
namespace ICU {
class CNativePluralRulesHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::ICU::INativePluralRulesHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativePluralRulesHelper, RGM_SAME_DOMAIN, Libcore::ICU::EIID_INativePluralRulesHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativePluralRulesHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativePluralRulesHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativePluralRulesHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace ICU {
class CRuleBasedCollatorICU
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& rules,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICRuleBasedCollatorICUClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CRuleBasedCollatorICU, RGM_SAME_DOMAIN,
                EIID_ICRuleBasedCollatorICUClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithRules(rules, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICRuleBasedCollatorICUClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CRuleBasedCollatorICU, RGM_SAME_DOMAIN,
                EIID_ICRuleBasedCollatorICUClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithLocale(locale, &pObject);

        *__object = pObject;

        pClassObject->Release();

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
        /* [out] */ Libcore::ICU::IRuleBasedCollatorICU** __IRuleBasedCollatorICU)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rules, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRuleBasedCollatorICU = (Libcore::ICU::IRuleBasedCollatorICU*)__pNewObj->Probe(Libcore::ICU::EIID_IRuleBasedCollatorICU);
        if (*__IRuleBasedCollatorICU) __pNewObj->AddRef();
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
        /* [out] */ Libcore::ICU::IRuleBasedCollatorICU** __IRuleBasedCollatorICU)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRuleBasedCollatorICU = (Libcore::ICU::IRuleBasedCollatorICU*)__pNewObj->Probe(Libcore::ICU::EIID_IRuleBasedCollatorICU);
        if (*__IRuleBasedCollatorICU) __pNewObj->AddRef();
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
namespace Libcore {
namespace ICU {
class CNativeBreakIteratorHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::ICU::INativeBreakIteratorHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativeBreakIteratorHelper, RGM_SAME_DOMAIN, Libcore::ICU::EIID_INativeBreakIteratorHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativeBreakIteratorHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativeBreakIteratorHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativeBreakIteratorHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace ICU {
class CAlphabeticIndex
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAlphabeticIndexClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAlphabeticIndex, RGM_SAME_DOMAIN,
                EIID_ICAlphabeticIndexClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithLocale(locale, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Libcore::ICU::IAlphabeticIndex** __IAlphabeticIndex)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAlphabeticIndex = (Libcore::ICU::IAlphabeticIndex*)__pNewObj->Probe(Libcore::ICU::EIID_IAlphabeticIndex);
        if (*__IAlphabeticIndex) __pNewObj->AddRef();
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
namespace Libcore {
namespace ICU {
class CDateIntervalFormat
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::ICU::IDateIntervalFormat** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDateIntervalFormat, RGM_SAME_DOMAIN, Libcore::ICU::EIID_IDateIntervalFormat, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDateIntervalFormat, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDateIntervalFormat, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDateIntervalFormat, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace ICU {
class CTransliterator
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& id,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICTransliteratorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CTransliterator, RGM_SAME_DOMAIN,
                EIID_ICTransliteratorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithId(id, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& id,
        /* [out] */ Libcore::ICU::ITransliterator** __ITransliterator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(id, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ITransliterator = (Libcore::ICU::ITransliterator*)__pNewObj->Probe(Libcore::ICU::EIID_ITransliterator);
        if (*__ITransliterator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& id,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(id, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& id,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(id, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& id,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(id, &__pNewObj);
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
namespace Libcore {
namespace ICU {
class CICUUtil
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::ICU::IICUUtil** __object)
    {
        return _CObject_CreateInstance(ECLSID_CICUUtil, RGM_SAME_DOMAIN, Libcore::ICU::EIID_IICUUtil, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CICUUtil, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CICUUtil, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CICUUtil, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace ICU {
class CNativeConverterHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::ICU::INativeConverterHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativeConverterHelper, RGM_SAME_DOMAIN, Libcore::ICU::EIID_INativeConverterHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativeConverterHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativeConverterHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNativeConverterHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace ICU {
class CNativeDecimalFormat
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Text::IDecimalFormatSymbols * dfs,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICNativeDecimalFormatClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CNativeDecimalFormat, RGM_SAME_DOMAIN,
                EIID_ICNativeDecimalFormatClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPatternDfs(pattern, dfs, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Libcore::ICU::ILocaleData * data,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICNativeDecimalFormatClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CNativeDecimalFormat, RGM_SAME_DOMAIN,
                EIID_ICNativeDecimalFormatClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPatternData(pattern, data, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Text::IDecimalFormatSymbols * dfs,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, dfs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Text::IDecimalFormatSymbols * dfs,
        /* [out] */ Libcore::ICU::INativeDecimalFormat** __INativeDecimalFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, dfs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INativeDecimalFormat = (Libcore::ICU::INativeDecimalFormat*)__pNewObj->Probe(Libcore::ICU::EIID_INativeDecimalFormat);
        if (*__INativeDecimalFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Text::IDecimalFormatSymbols * dfs,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, dfs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Text::IDecimalFormatSymbols * dfs,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, dfs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Elastos::Text::IDecimalFormatSymbols * dfs,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, dfs, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Libcore::ICU::ILocaleData * data,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, data, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Libcore::ICU::ILocaleData * data,
        /* [out] */ Libcore::ICU::INativeDecimalFormat** __INativeDecimalFormat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, data, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INativeDecimalFormat = (Libcore::ICU::INativeDecimalFormat*)__pNewObj->Probe(Libcore::ICU::EIID_INativeDecimalFormat);
        if (*__INativeDecimalFormat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Libcore::ICU::ILocaleData * data,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, data, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Libcore::ICU::ILocaleData * data,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, data, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& pattern,
        /* [in] */ Libcore::ICU::ILocaleData * data,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, data, &__pNewObj);
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
namespace Libcore {
namespace IO {
class CAsynchronousCloseMonitor
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::IO::IAsynchronousCloseMonitor** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAsynchronousCloseMonitor, RGM_SAME_DOMAIN, Libcore::IO::EIID_IAsynchronousCloseMonitor, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAsynchronousCloseMonitor, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAsynchronousCloseMonitor, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAsynchronousCloseMonitor, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace IO {
class CBase64
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::IO::IBase64** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBase64, RGM_SAME_DOMAIN, Libcore::IO::EIID_IBase64, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBase64, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBase64, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBase64, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace IO {
class CLibcore
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::IO::ILibcore** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLibcore, RGM_SAME_DOMAIN, Libcore::IO::EIID_ILibcore, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLibcore, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLibcore, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLibcore, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace IO {
class CIoBridge
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::IO::IIoBridge** __object)
    {
        return _CObject_CreateInstance(ECLSID_CIoBridge, RGM_SAME_DOMAIN, Libcore::IO::EIID_IIoBridge, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CIoBridge, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CIoBridge, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CIoBridge, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace IO {
class CSocketTaggerHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::IO::ISocketTaggerHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSocketTaggerHelper, RGM_SAME_DOMAIN, Libcore::IO::EIID_ISocketTaggerHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSocketTaggerHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSocketTaggerHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSocketTaggerHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace IO {
class CStreams
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::IO::IStreams** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStreams, RGM_SAME_DOMAIN, Libcore::IO::EIID_IStreams, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStreams, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStreams, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStreams, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace IO {
class CDeleteOnExitHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::IO::IDeleteOnExitHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDeleteOnExitHelper, RGM_SAME_DOMAIN, Libcore::IO::EIID_IDeleteOnExitHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDeleteOnExitHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDeleteOnExitHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDeleteOnExitHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace IO {
class CDropBox
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::IO::IDropBox** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDropBox, RGM_SAME_DOMAIN, Libcore::IO::EIID_IDropBox, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDropBox, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDropBox, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDropBox, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace IO {
class CIoUtils
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::IO::IIoUtils** __object)
    {
        return _CObject_CreateInstance(ECLSID_CIoUtils, RGM_SAME_DOMAIN, Libcore::IO::EIID_IIoUtils, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CIoUtils, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CIoUtils, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CIoUtils, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace IO {
class CMemoryMappedFile
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int64 address,
        /* [in] */ _ELASTOS Int64 size,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICMemoryMappedFileClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CMemoryMappedFile, RGM_SAME_DOMAIN,
                EIID_ICMemoryMappedFileClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithAddressSize(address, size, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 address,
        /* [in] */ _ELASTOS Int64 size,
        /* [out] */ Libcore::IO::IMemoryMappedFile** __IMemoryMappedFile)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMemoryMappedFile = (Libcore::IO::IMemoryMappedFile*)__pNewObj->Probe(Libcore::IO::EIID_IMemoryMappedFile);
        if (*__IMemoryMappedFile) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 address,
        /* [in] */ _ELASTOS Int64 size,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 address,
        /* [in] */ _ELASTOS Int64 size,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 address,
        /* [in] */ _ELASTOS Int64 size,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 address,
        /* [in] */ _ELASTOS Int64 size,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(address, size, &__pNewObj);
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
namespace Libcore {
namespace IO {
class CStrictLineReader
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStrictLineReaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStrictLineReader, RGM_SAME_DOMAIN,
                EIID_ICStrictLineReaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithInput(input, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStrictLineReaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStrictLineReader, RGM_SAME_DOMAIN,
                EIID_ICStrictLineReaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithInputCapacity(input, capacity, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [in] */ Elastos::IO::Charset::ICharset * Charset,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStrictLineReaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStrictLineReader, RGM_SAME_DOMAIN,
                EIID_ICStrictLineReaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithInputCharset(input, Charset, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ Elastos::IO::Charset::ICharset * Charset,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStrictLineReaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStrictLineReader, RGM_SAME_DOMAIN,
                EIID_ICStrictLineReaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithInputCapacityCharset(input, capacity, Charset, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [out] */ Libcore::IO::IStrictLineReader** __IStrictLineReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(input, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStrictLineReader = (Libcore::IO::IStrictLineReader*)__pNewObj->Probe(Libcore::IO::EIID_IStrictLineReader);
        if (*__IStrictLineReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(input, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(input, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(input, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(input, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Libcore::IO::IStrictLineReader** __IStrictLineReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(input, capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStrictLineReader = (Libcore::IO::IStrictLineReader*)__pNewObj->Probe(Libcore::IO::EIID_IStrictLineReader);
        if (*__IStrictLineReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(input, capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(input, capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(input, capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(input, capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [in] */ Elastos::IO::Charset::ICharset * Charset,
        /* [out] */ Libcore::IO::IStrictLineReader** __IStrictLineReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(input, Charset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStrictLineReader = (Libcore::IO::IStrictLineReader*)__pNewObj->Probe(Libcore::IO::EIID_IStrictLineReader);
        if (*__IStrictLineReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [in] */ Elastos::IO::Charset::ICharset * Charset,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(input, Charset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [in] */ Elastos::IO::Charset::ICharset * Charset,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(input, Charset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [in] */ Elastos::IO::Charset::ICharset * Charset,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(input, Charset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [in] */ Elastos::IO::Charset::ICharset * Charset,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(input, Charset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ Elastos::IO::Charset::ICharset * Charset,
        /* [out] */ Libcore::IO::IStrictLineReader** __IStrictLineReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(input, capacity, Charset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStrictLineReader = (Libcore::IO::IStrictLineReader*)__pNewObj->Probe(Libcore::IO::EIID_IStrictLineReader);
        if (*__IStrictLineReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ Elastos::IO::Charset::ICharset * Charset,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(input, capacity, Charset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ Elastos::IO::Charset::ICharset * Charset,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(input, capacity, Charset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ Elastos::IO::Charset::ICharset * Charset,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(input, capacity, Charset, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * input,
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ Elastos::IO::Charset::ICharset * Charset,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(input, capacity, Charset, &__pNewObj);
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
namespace Libcore {
namespace IO {
class CPosix
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Libcore::IO::IOs** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPosix, RGM_SAME_DOMAIN, Libcore::IO::EIID_IOs, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPosix, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPosix, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPosix, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace Utility {
class CBasicLruCache
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 maxSize,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBasicLruCacheClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBasicLruCache, RGM_SAME_DOMAIN,
                EIID_ICBasicLruCacheClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithMaxSize(maxSize, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 maxSize,
        /* [out] */ Libcore::Utility::IBasicLruCache** __IBasicLruCache)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(maxSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBasicLruCache = (Libcore::Utility::IBasicLruCache*)__pNewObj->Probe(Libcore::Utility::EIID_IBasicLruCache);
        if (*__IBasicLruCache) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 maxSize,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(maxSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 maxSize,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(maxSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 maxSize,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(maxSize, &__pNewObj);
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
namespace Libcore {
namespace Utility {
class CZoneInfoWallTime
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Libcore::Utility::IZoneInfoWallTime** __object)
    {
        return _CObject_CreateInstance(ECLSID_CZoneInfoWallTime, RGM_SAME_DOMAIN, Libcore::Utility::EIID_IZoneInfoWallTime, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CZoneInfoWallTime, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CZoneInfoWallTime, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CZoneInfoWallTime, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace Utility {
class CCollectionUtils
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::Utility::ICollectionUtils** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollectionUtils, RGM_SAME_DOMAIN, Libcore::Utility::EIID_ICollectionUtils, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollectionUtils, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollectionUtils, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollectionUtils, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace Utility {
class COffsetIntervalHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::Utility::IOffsetIntervalHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_COffsetIntervalHelper, RGM_SAME_DOMAIN, Libcore::Utility::EIID_IOffsetIntervalHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_COffsetIntervalHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_COffsetIntervalHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_COffsetIntervalHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace Utility {
class CZoneInfoHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::Utility::IZoneInfoHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CZoneInfoHelper, RGM_SAME_DOMAIN, Libcore::Utility::EIID_IZoneInfoHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CZoneInfoHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CZoneInfoHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CZoneInfoHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace Utility {
class CZoneInfoDB
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::Utility::IZoneInfoDB** __object)
    {
        return _CObject_CreateInstance(ECLSID_CZoneInfoDB, RGM_SAME_DOMAIN, Libcore::Utility::EIID_IZoneInfoDB, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CZoneInfoDB, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CZoneInfoDB, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CZoneInfoDB, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace Net {
class CMimeUtils
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::Net::IMimeUtils** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMimeUtils, RGM_SAME_DOMAIN, Libcore::Net::EIID_IMimeUtils, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMimeUtils, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMimeUtils, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMimeUtils, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace Net {
class CUriCodecHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::Net::IUriCodecHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CUriCodecHelper, RGM_SAME_DOMAIN, Libcore::Net::EIID_IUriCodecHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CUriCodecHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CUriCodecHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CUriCodecHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Libcore {
namespace Net {
namespace Http {
class CHttpDate
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::Net::Http::IHttpDate** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHttpDate, RGM_SAME_DOMAIN, Libcore::Net::Http::EIID_IHttpDate, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHttpDate, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHttpDate, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHttpDate, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Libcore {
namespace Net {
namespace Url {
class CFileHandler
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::IURLStreamHandler** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFileHandler, RGM_SAME_DOMAIN, Elastos::Net::EIID_IURLStreamHandler, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Libcore::Net::Url::IFileHandler** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFileHandler, RGM_SAME_DOMAIN, Libcore::Net::Url::EIID_IFileHandler, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFileHandler, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFileHandler, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFileHandler, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Libcore {
namespace Net {
namespace Url {
class CFileURLConnection
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Net::IURL * url,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFileURLConnectionClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFileURLConnection, RGM_SAME_DOMAIN,
                EIID_ICFileURLConnectionClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithUrl(url, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * url,
        /* [out] */ Elastos::Net::IURLConnection** __IURLConnection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(url, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IURLConnection = (Elastos::Net::IURLConnection*)__pNewObj->Probe(Elastos::Net::EIID_IURLConnection);
        if (*__IURLConnection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * url,
        /* [out] */ Libcore::Net::Url::IFileURLConnection** __IFileURLConnection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(url, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFileURLConnection = (Libcore::Net::Url::IFileURLConnection*)__pNewObj->Probe(Libcore::Net::Url::EIID_IFileURLConnection);
        if (*__IFileURLConnection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * url,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(url, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * url,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(url, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * url,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(url, &__pNewObj);
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
namespace Libcore {
namespace Net {
namespace Url {
class CFtpHandler
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::IURLStreamHandler** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFtpHandler, RGM_SAME_DOMAIN, Elastos::Net::EIID_IURLStreamHandler, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Libcore::Net::Url::IFtpHandler** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFtpHandler, RGM_SAME_DOMAIN, Libcore::Net::Url::EIID_IFtpHandler, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFtpHandler, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFtpHandler, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CFtpHandler, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Libcore {
namespace Net {
namespace Url {
class CFtpURLInputStream
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Net::ISocket * controlSocket,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFtpURLInputStreamClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFtpURLInputStream, RGM_SAME_DOMAIN,
                EIID_ICFtpURLInputStreamClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIsControlSocket(is, controlSocket, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Net::ISocket * controlSocket,
        /* [out] */ Elastos::IO::ICloseable** __ICloseable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, controlSocket, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloseable = (Elastos::IO::ICloseable*)__pNewObj->Probe(Elastos::IO::EIID_ICloseable);
        if (*__ICloseable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Net::ISocket * controlSocket,
        /* [out] */ Elastos::IO::IInputStream** __IInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, controlSocket, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputStream = (Elastos::IO::IInputStream*)__pNewObj->Probe(Elastos::IO::EIID_IInputStream);
        if (*__IInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Net::ISocket * controlSocket,
        /* [out] */ Libcore::Net::Url::IFtpURLInputStream** __IFtpURLInputStream)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, controlSocket, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFtpURLInputStream = (Libcore::Net::Url::IFtpURLInputStream*)__pNewObj->Probe(Libcore::Net::Url::EIID_IFtpURLInputStream);
        if (*__IFtpURLInputStream) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Net::ISocket * controlSocket,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, controlSocket, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Net::ISocket * controlSocket,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, controlSocket, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * is,
        /* [in] */ Elastos::Net::ISocket * controlSocket,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(is, controlSocket, &__pNewObj);
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
namespace Libcore {
namespace Net {
namespace Url {
class CUrlUtilsHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::Net::Url::IUrlUtilsHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CUrlUtilsHelper, RGM_SAME_DOMAIN, Libcore::Net::Url::EIID_IUrlUtilsHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CUrlUtilsHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CUrlUtilsHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CUrlUtilsHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Libcore {
namespace Net {
namespace Url {
class CJarHandler
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::Net::IURLStreamHandler** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJarHandler, RGM_SAME_DOMAIN, Elastos::Net::EIID_IURLStreamHandler, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Libcore::Net::Url::IJarHandler** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJarHandler, RGM_SAME_DOMAIN, Libcore::Net::Url::EIID_IJarHandler, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJarHandler, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJarHandler, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJarHandler, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Libcore {
namespace Net {
namespace Url {
class CJarURLConnectionImpl
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Net::IURL * url,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJarURLConnectionImplClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJarURLConnectionImpl, RGM_SAME_DOMAIN,
                EIID_ICJarURLConnectionImplClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithUrl(url, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * url,
        /* [out] */ Libcore::Net::Url::IJarURLConnectionImpl** __IJarURLConnectionImpl)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(url, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJarURLConnectionImpl = (Libcore::Net::Url::IJarURLConnectionImpl*)__pNewObj->Probe(Libcore::Net::Url::EIID_IJarURLConnectionImpl);
        if (*__IJarURLConnectionImpl) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * url,
        /* [out] */ Elastos::Net::IJarURLConnection** __IJarURLConnection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(url, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJarURLConnection = (Elastos::Net::IJarURLConnection*)__pNewObj->Probe(Elastos::Net::EIID_IJarURLConnection);
        if (*__IJarURLConnection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * url,
        /* [out] */ Elastos::Net::IURLConnection** __IURLConnection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(url, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IURLConnection = (Elastos::Net::IURLConnection*)__pNewObj->Probe(Elastos::Net::EIID_IURLConnection);
        if (*__IURLConnection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * url,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(url, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * url,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(url, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Net::IURL * url,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(url, &__pNewObj);
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
namespace Libcore {
namespace Net {
namespace Event {
class CNetworkEventDispatcherHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Libcore::Net::Event::INetworkEventDispatcherHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNetworkEventDispatcherHelper, RGM_SAME_DOMAIN, Libcore::Net::Event::EIID_INetworkEventDispatcherHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNetworkEventDispatcherHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNetworkEventDispatcherHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNetworkEventDispatcherHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}

#endif // __Elastos_CoreLibrary_Libcore_h__
