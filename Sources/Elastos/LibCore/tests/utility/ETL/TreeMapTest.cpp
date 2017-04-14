/*
 * Copyright (C) 2010 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <elautoptr.h>
#include <elastos/coredef.h>
#include <Elastos.CoreLibrary.Utility.h>
#include <Elastos.CoreLibrary.Core.h>
#include <elastos/core/Object.h>
#include "elastos/utility/AbstractMap.h"

using namespace Elastos;
using namespace Elastos::Core;
using namespace Elastos::Utility;
using Elastos::Core::IInteger32;
using Elastos::Core::CInteger32;
using Elastos::Core::CString;
using Elastos::Core::ICharSequence;
using Elastos::Core::IComparator;
using Elastos::Utility::IIterator;
using Elastos::Utility::IMap;
using Elastos::Utility::ISet;
using Elastos::Utility::IMapEntry;
using Elastos::Utility::INavigableMap;
using Elastos::Utility::ISortedMap;
using Elastos::Utility::CHashMap;
using Elastos::Utility::ITreeMap;
using Elastos::Utility::CTreeMap;
using Elastos::Utility::AbstractMap;

namespace Elastos {
namespace Utility {

static void assertEquals(
    /* [in] */ const char *expecting,
    /* [in] */ const String& toVerify)
{
    printf("expecting: %s, toVerify: %s. \n", expecting, toVerify.string());
    assert(toVerify.Equals(expecting) == TRUE);
}

static void assertEquals(
    /* [in] */ const String& expecting,
    /* [in] */ const String& toVerify)
{
    printf("expecting: %s, toVerify: %s. \n", expecting.string(), toVerify.string());
    assert(expecting.Equals(toVerify) == TRUE);
}

static void assertTrue(
    /* [in] */ Boolean condition)
{
    printf("expecting: 1, toVerify: %d. \n", condition);
    assert(condition == TRUE);
}

static void assertFalse(
    /* [in] */ Boolean condition)
{
    printf("expecting: 0, toVerify: %d. \n", condition);
    assert(condition == FALSE);
}

AutoPtr<ICharSequence> Convert(
    /* [in] */ const char* str)
{
    AutoPtr<ICharSequence> obj;
    CString::New(String(str), (ICharSequence**)&obj);
    return obj;
}

AutoPtr<IInteger32> Convert(
    /* [in] */ Int32 value)
{
    AutoPtr<IInteger32> obj;
    CInteger32::New(value, (IInteger32**)&obj);
    return obj;
}

// public class TreeMapTest extends TestCase {

#if 0
private void assertImmutable(Entry<String, String> entry) {
    String initialValue = entry.getValue();
    try {
        entry.setValue("x");
        fail();
    } catch (UnsupportedOperationException e) {
    }
    assertEquals(initialValue, entry.getValue());
}
#endif

void assertImmutable(
    /* [in] */ IMapEntry* entry) 
{
    printf("\n== assertImmutable  start ==\n");
    AutoPtr<IInterface> value;
    entry->GetValue((IInterface**)&value);
    String initialValue = Object::ToString(value);

    // try {
        value = NULL;
        ECode ec = entry->SetValue(Convert("x"), (IInterface**)&value);
        if (SUCCEEDED(ec)) {
            // fail();
            printf("Don't come here! MapEntry SetValue success, value: %s\n", Object::ToString(value).string());
        }
    // } catch (UnsupportedOperationException e) {
    // }
    value = NULL;
    entry->GetValue((IInterface**)&value);
    assertEquals(initialValue, Object::ToString(value));
    printf("\n== assertImmutable  end ==\n");
}

#if 0
/**
 * Asserts that each NavigableMap method that returns an Entry (except entrySet()) returns an
 * immutable one. Assumes that the map contains at least entries with keys "A", "B" and "C".
 */
private void assertAllEntryMethodsReturnImmutableEntries(NavigableMap<String, String> map) {
    assertImmutable(map.ceilingEntry("B"));
    assertImmutable(map.firstEntry());
    assertImmutable(map.floorEntry("D"));
    assertImmutable(map.higherEntry("A"));
    assertImmutable(map.lastEntry());
    assertImmutable(map.lowerEntry("C"));
    assertImmutable(map.pollFirstEntry());
    assertImmutable(map.pollLastEntry());
}
#endif

void assertAllEntryMethodsReturnImmutableEntries(
    /* [in] */ INavigableMap* map) 
{
    printf("\n== assertAllEntryMethodsReturnImmutableEntries  start ==\n");
    AutoPtr<IMapEntry> entry;
    map->GetCeilingEntry(Convert("B"), (IMapEntry**)&entry);
    assertImmutable(entry);
    entry = NULL;
    map->GetFirstEntry((IMapEntry**)&entry);
    assertImmutable(entry);
    entry = NULL;
    map->GetFloorEntry(Convert("D"), (IMapEntry**)&entry);
    assertImmutable(entry);
    entry = NULL;
    map->GetHigherEntry(Convert("A"), (IMapEntry**)&entry);
    assertImmutable(entry);
    entry = NULL;
    map->GetLastEntry((IMapEntry**)&entry);
    assertImmutable(entry);
    entry = NULL;
    map->GetLowerEntry(Convert("C"), (IMapEntry**)&entry);
    assertImmutable(entry);
    entry = NULL;
    map->PollFirstEntry((IMapEntry**)&entry);
    assertImmutable(entry);
    entry = NULL;
    map->PollLastEntry((IMapEntry**)&entry);
    assertImmutable(entry);
    printf("\n== assertAllEntryMethodsReturnImmutableEntries  end ==\n");
}

#if 0
/**
 * Test that the entrySet() method produces correctly mutable entries.
 */
public void testEntrySetSetValue() {
    TreeMap<String, String> map = new TreeMap<String, String>();
    map.put("A", "a");
    map.put("B", "b");
    map.put("C", "c");

    Iterator<Entry<String, String>> iterator = map.entrySet().iterator();
    Entry<String, String> entryA = iterator.next();
    assertEquals("a", entryA.setValue("x"));
    assertEquals("x", entryA.getValue());
    assertEquals("x", map.get("A"));
    Entry<String, String> entryB = iterator.next();
    assertEquals("b", entryB.setValue("y"));
    Entry<String, String> entryC = iterator.next();
    assertEquals("c", entryC.setValue("z"));
    assertEquals("y", entryB.getValue());
    assertEquals("y", map.get("B"));
    assertEquals("z", entryC.getValue());
    assertEquals("z", map.get("C"));
}
#endif

void testEntrySetSetValue() 
{
    printf("\n=== testEntrySetSetValue ===\n");
    AutoPtr<ITreeMap> map;
    ECode ec = CTreeMap::New((ITreeMap**)&map);
    if (FAILED(ec) || map == NULL) {
        printf("Failed to create CTreeMap. Error %08X\n", ec);
        return;
    }

    map->Put(Convert("A"), Convert("a"));
    map->Put(Convert("B"), Convert("b"));
    map->Put(Convert("C"), Convert("c"));

    AutoPtr<ISet> entries;
    map->GetEntrySet((ISet**)&entries);
    AutoPtr<IIterator> iterator;
    entries->GetIterator((IIterator**)&iterator);

    AutoPtr<IInterface> obj;
    iterator->GetNext((IInterface**)&obj);
    IMapEntry* entryA = IMapEntry::Probe(obj);
    AutoPtr<IInterface> value;
    entryA->SetValue(Convert("x"), (IInterface**)&value);
    assertEquals("a", Object::ToString(value));
    value = NULL;
    entryA->GetValue((IInterface**)&value);
    assertEquals("x", Object::ToString(value));
    value = NULL;
    map->Get(Convert("A"), (IInterface**)&value);
    assertEquals("x", Object::ToString(value));

    obj = NULL;
    iterator->GetNext((IInterface**)&obj);
    IMapEntry* entryB = IMapEntry::Probe(obj);
    value = NULL;
    entryB->SetValue(Convert("y"), (IInterface**)&value);
    assertEquals("b", Object::ToString(value));

    obj = NULL;
    iterator->GetNext((IInterface**)&obj);
    IMapEntry* entryC = IMapEntry::Probe(obj);
    value = NULL;
    entryC->SetValue(Convert("z"), (IInterface**)&value);
    assertEquals("c", Object::ToString(value));

    value = NULL;
    entryB->GetValue((IInterface**)&value);
    assertEquals("y", Object::ToString(value));
    value = NULL;
    map->Get(Convert("B"), (IInterface**)&value);
    assertEquals("y", Object::ToString(value));

    value = NULL;
    entryC->GetValue((IInterface**)&value);
    assertEquals("z", Object::ToString(value));
    value = NULL;
    map->Get(Convert("C"), (IInterface**)&value);
    assertEquals("z", Object::ToString(value));
}

#if 0
/**
 * Test that the entrySet() method of a sub map produces correctly mutable
 * entries that propagate changes to the original map.
 */
public void testSubMapEntrySetSetValue() {
    TreeMap<String, String> map = new TreeMap<String, String>();
    map.put("A", "a");
    map.put("B", "b");
    map.put("C", "c");
    map.put("D", "d");
    NavigableMap<String, String> subMap = map.subMap("A", true, "C", true);

    Iterator<Entry<String, String>> iterator = subMap.entrySet().iterator();
    Entry<String, String> entryA = iterator.next();
    assertEquals("a", entryA.setValue("x"));
    assertEquals("x", entryA.getValue());
    assertEquals("x", subMap.get("A"));
    assertEquals("x", map.get("A"));
    Entry<String, String> entryB = iterator.next();
    assertEquals("b", entryB.setValue("y"));
    Entry<String, String> entryC = iterator.next();
    assertEquals("c", entryC.setValue("z"));
    assertEquals("y", entryB.getValue());
    assertEquals("y", subMap.get("B"));
    assertEquals("y", map.get("B"));
    assertEquals("z", entryC.getValue());
    assertEquals("z", subMap.get("C"));
    assertEquals("z", map.get("C"));
}
#endif

void testSubMapEntrySetSetValue() 
{
    printf("\n=== testSubMapEntrySetSetValue ===\n");
    AutoPtr<ITreeMap> map;
    ECode ec = CTreeMap::New((ITreeMap**)&map);
    if (FAILED(ec) || map == NULL) {
        printf("Failed to create CTreeMap. Error %08X\n", ec);
        return;
    }

    map->Put(Convert("A"), Convert("a"));
    map->Put(Convert("B"), Convert("b"));
    map->Put(Convert("C"), Convert("c"));
    map->Put(Convert("D"), Convert("d"));

    AutoPtr<INavigableMap> subMap;
    map->GetSubMap(Convert("A"), TRUE, Convert("C"), TRUE, (INavigableMap**)&subMap);

    AutoPtr<ISet> entries;
    subMap->GetEntrySet((ISet**)&entries);
    AutoPtr<IIterator> iterator;
    entries->GetIterator((IIterator**)&iterator);

    AutoPtr<IInterface> obj;
    iterator->GetNext((IInterface**)&obj);
    IMapEntry* entryA = IMapEntry::Probe(obj);
    AutoPtr<IInterface> value;
    entryA->SetValue(Convert("x"), (IInterface**)&value);
    assertEquals("a", Object::ToString(value));
    value = NULL;
    entryA->GetValue((IInterface**)&value);
    assertEquals("x", Object::ToString(value));
    value = NULL;
    subMap->Get(Convert("A"), (IInterface**)&value);
    assertEquals("x", Object::ToString(value));
    value = NULL;
    map->Get(Convert("A"), (IInterface**)&value);
    assertEquals("x", Object::ToString(value));
    
    obj = NULL;
    iterator->GetNext((IInterface**)&obj);
    IMapEntry* entryB = IMapEntry::Probe(obj);
    value = NULL;
    entryB->SetValue(Convert("y"), (IInterface**)&value);
    assertEquals("b", Object::ToString(value));

    obj = NULL;
    iterator->GetNext((IInterface**)&obj);
    IMapEntry* entryC = IMapEntry::Probe(obj);
    value = NULL;
    entryC->SetValue(Convert("z"), (IInterface**)&value);
    assertEquals("c", Object::ToString(value));

    value = NULL;
    entryB->GetValue((IInterface**)&value);
    assertEquals("y", Object::ToString(value));
    value = NULL;
    subMap->Get(Convert("B"), (IInterface**)&value);
    assertEquals("y", Object::ToString(value));
    value = NULL;
    map->Get(Convert("B"), (IInterface**)&value);
    assertEquals("y", Object::ToString(value));

    value = NULL;
    entryC->GetValue((IInterface**)&value);
    assertEquals("z", Object::ToString(value));
    value = NULL;
    subMap->Get(Convert("C"), (IInterface**)&value);
    assertEquals("z", Object::ToString(value));
    value = NULL;
    map->Get(Convert("C"), (IInterface**)&value);
    assertEquals("z", Object::ToString(value));
}

#if 0
/**
 * Test that an Entry given by any method except entrySet() is immutable.
 */
public void testExceptionsOnSetValue() 
{
    TreeMap<String, String> map = new TreeMap<String, String>();
    map.put("A", "a");
    map.put("B", "b");
    map.put("C", "c");

    assertAllEntryMethodsReturnImmutableEntries(map);
}
#endif

void testExceptionsOnSetValue() 
{
    printf("\n=== testExceptionsOnSetValue ===\n");
    AutoPtr<ITreeMap> map;
    ECode ec = CTreeMap::New((ITreeMap**)&map);
    if (FAILED(ec) || map == NULL) {
        printf("Failed to create CTreeMap. Error %08X\n", ec);
        return;
    }

    map->Put(Convert("A"), Convert("a"));
    map->Put(Convert("B"), Convert("b"));
    map->Put(Convert("C"), Convert("c"));

    assertAllEntryMethodsReturnImmutableEntries(INavigableMap::Probe(map));
}

#if 0
/**
 * Test that an Entry given by any method except entrySet() of a sub map is immutable.
 */
public void testExceptionsOnSubMapSetValue() {
    TreeMap<String, String> map = new TreeMap<String, String>();
    map.put("A", "a");
    map.put("B", "b");
    map.put("C", "c");
    map.put("D", "d");

    assertAllEntryMethodsReturnImmutableEntries(map.subMap("A", true, "C", true));
}
#endif

void testExceptionsOnSubMapSetValue() 
{
    printf("\n=== testExceptionsOnSubMapSetValue ===\n");
    AutoPtr<ITreeMap> map;
    ECode ec = CTreeMap::New((ITreeMap**)&map);
    if (FAILED(ec) || map == NULL) {
        printf("Failed to create CTreeMap. Error %08X\n", ec);
        return;
    }

    map->Put(Convert("A"), Convert("a"));
    map->Put(Convert("B"), Convert("b"));
    map->Put(Convert("C"), Convert("c"));
    map->Put(Convert("D"), Convert("d"));

    AutoPtr<INavigableMap> subMap;
    ec = map->GetSubMap(Convert("A"), TRUE, Convert("C"), TRUE, (INavigableMap**)&subMap);
    if (FAILED(ec) || subMap == NULL) {
        printf("Failed to create INavigableMap. Error %08X\n", ec);
        return;
    }

    assertAllEntryMethodsReturnImmutableEntries(subMap);
}

#if 0
public void testConcurrentModificationDetection() {
    Map<String, String> map = new TreeMap<String, String>();
    map.put("A", "a");
    map.put("B", "b");
    map.put("C", "c");
    Iterator<Entry<String,String>> iterator = map.entrySet().iterator();
    iterator.next();
    iterator.next();
    iterator.remove();
    map.put("D", "d");
    try {
        iterator.next();
        fail();
    } catch (ConcurrentModificationException e) {
    }
}
#endif

void testConcurrentModificationDetection() 
{
    printf("\n=== testConcurrentModificationDetection ===\n");
    AutoPtr<IMap> map;
    ECode ec = CTreeMap::New((IMap**)&map);
    if (FAILED(ec) || map == NULL) {
        printf("Failed to create CTreeMap. Error %08X\n", ec);
        return;
    }

    map->Put(Convert("A"), Convert("a"));
    map->Put(Convert("B"), Convert("b"));
    map->Put(Convert("C"), Convert("c"));
    AutoPtr<ISet> set;
    map->GetEntrySet((ISet**)&set);
    AutoPtr<IIterator> iterator;
    set->GetIterator((IIterator**)&iterator);
    AutoPtr<IInterface> obj;
    iterator->GetNext((IInterface**)&obj);
    obj = NULL;
    iterator->GetNext((IInterface**)&obj);
    iterator->Remove();
    map->Put(Convert("D"), Convert("d"));

    // try {
        obj = NULL;
        ec = iterator->GetNext((IInterface**)&obj);
        if (SUCCEEDED(ec)) {
            printf("Failed! Don't come here!");
        }
    //     fail();
    // } catch (ConcurrentModificationException e) {
    // }
}

#if 0
public void testIteratorRemoves() {
    Map<String, String> map = new TreeMap<String, String>();
    map.put("A", "a");
    map.put("B", "b");
    map.put("C", "c");
    Iterator<Entry<String,String>> iterator = map.entrySet().iterator();
    assertEquals("A", iterator.next().getKey());
    assertEquals("B", iterator.next().getKey());
    iterator.remove();
    assertEquals("C", iterator.next().getKey());
    iterator.remove();
    assertFalse(iterator.hasNext());
}
#endif

void testIteratorRemoves() 
{
    printf("\n=== testIteratorRemoves ===\n");
    AutoPtr<IMap> map;
    ECode ec = CTreeMap::New((IMap**)&map);
    if (FAILED(ec) || map == NULL) {
        printf("Failed to create CTreeMap. Error %08X\n", ec);
        return;
    }

    map->Put(Convert("A"), Convert("a"));
    map->Put(Convert("B"), Convert("b"));
    map->Put(Convert("C"), Convert("c"));

    AutoPtr<ISet> set;
    map->GetEntrySet((ISet**)&set);
    AutoPtr<IIterator> iterator;
    set->GetIterator((IIterator**)&iterator);
    AutoPtr<IInterface> objEntry;
    iterator->GetNext((IInterface**)&objEntry);
    AutoPtr<IInterface> key;
    IMapEntry::Probe(objEntry)->GetKey((IInterface**)&key);
    assertEquals("A", Object::ToString(key));

    objEntry = NULL;
    iterator->GetNext((IInterface**)&objEntry);
    key = NULL;
    IMapEntry::Probe(objEntry)->GetKey((IInterface**)&key);
    assertEquals("B", Object::ToString(key));

    iterator->Remove();
    objEntry = NULL;
    iterator->GetNext((IInterface**)&objEntry);
    key = NULL;
    IMapEntry::Probe(objEntry)->GetKey((IInterface**)&key);
    assertEquals("C", Object::ToString(key));
    iterator->Remove();
    Boolean hasNext;
    iterator->HasNext(&hasNext);
    assertFalse(hasNext);
}

#if 0
/**
 * Test that entry set contains and removal use the comparator rather than equals.
 */
public void testEntrySetUsesComparatorOnly() {
    Map<String,String> map = new TreeMap<String, String>(String.CASE_INSENSITIVE_ORDER);
    map.put("ABC", "a");
    assertTrue(map.entrySet().contains(new SimpleEntry<String, String>("abc", "a")));
    assertTrue(map.entrySet().remove(new SimpleEntry<String, String>("abc", "a")));
    assertEquals(0, map.size());
}
#endif

void testEntrySetUsesComparatorOnly()
{
    printf("\n=== testEntrySetUsesComparatorOnly ===\n");
    AutoPtr<IMap> map;
    ECode ec = CTreeMap::New(/*String.CASE_INSENSITIVE_ORDER*/(IMap**)&map);
    if (FAILED(ec) || map == NULL) {
        printf("Failed to create CTreeMap. Error %08X\n", ec);
        return;
    }

    map->Put(Convert("ABC"), Convert("a"));

    AutoPtr<ISet> set;
    map->GetEntrySet((ISet**)&set);

    AutoPtr<AbstractMap::SimpleEntry> entry = new AbstractMap::SimpleEntry(Convert("abc"), Convert("a"));
    Boolean res = FALSE;
    set->Contains((IMapEntry*)entry.Get(), &res);
#if 0
    //if String.CASE_INSENSITIVE_ORDER is used
    assertTrue(res);
    set->Remove((IMapEntry*)entry.Get(), &res);
    assertTrue(res);

    Int32 size;
    map->GetSize(&size);
    assertTrue(0 == size);
#endif
    // else String.CASE_INSENSITIVE_ORDER is not used
    assertFalse(res);
    set->Remove((IMapEntry*)entry.Get(), &res);
    assertFalse(res);

    Int32 size;
    map->GetSize(&size);
    assertFalse(0 == size);
}

#if 0
public void testMapConstructorPassingSortedMap() {
    Map<String,String> source = new TreeMap<String, String>(String.CASE_INSENSITIVE_ORDER);
    NavigableMap<String,String> copy = new TreeMap<String, String>(source);
    assertEquals(null, copy.comparator());
}
#endif

void testMapConstructorPassingSortedMap()
{
    printf("\n=== testMapConstructorPassingSortedMap ===\n");
    AutoPtr<IMap> source;
    ECode ec = CTreeMap::New(/*String.CASE_INSENSITIVE_ORDER*/(IMap**)&source);
    if (FAILED(ec) || source == NULL) {
        printf("Failed to create CTreeMap. Error %08X\n", ec);
        return;
    }

    AutoPtr<INavigableMap> copy;
    ec = CTreeMap::New(source, (INavigableMap**)&copy);
    if (FAILED(ec) || copy == NULL) {
        printf("Failed to create INavigableMap. Error %08X\n", ec);
        return;
    }

    AutoPtr<IComparator> comp;
    copy->GetComparator((IComparator**)&comp);
    assertTrue(NULL == comp);
}

#if 0
public void testNullsWithNaturalOrder() {
    HashMap<String, String> copyFrom = new HashMap<String, String>();
    copyFrom.put(null, "b");
    try {
        new TreeMap<String, String>(copyFrom);
        fail(); // the RI doesn't throw if null is the only key
    } catch (NullPointerException expected) {
    }

    TreeMap<String,String> map = new TreeMap<String, String>();
    try {
        map.put(null, "b");
        fail();
    } catch (NullPointerException e) {
    }

    try {
        map.descendingMap().put(null, "b");
        fail();
    } catch (NullPointerException e) {
    }

    try {
        map.subMap("a", "z").put(null, "b");
        fail();
    } catch (NullPointerException e) {
    }
}
#endif

void testNullsWithNaturalOrder()
{
    printf("\n=== testNullsWithNaturalOrder ===\n");
    AutoPtr<IHashMap> copyFrom;
    ECode ec = CHashMap::New((IHashMap**)&copyFrom);
    if (FAILED(ec) || copyFrom == NULL) {
        printf("Failed to create CHashMap. Error %08X\n", ec);
        return;
    }
    copyFrom->Put(NULL, Convert("b"));

    // try {
        AutoPtr<ITreeMap> tmp;
        ec = CTreeMap::New(IMap::Probe(copyFrom), (ITreeMap**)&tmp);
        if (SUCCEEDED(ec)) {
            printf("Failed! Don't come here.");
        }
    //     fail(); // the RI doesn't throw if null is the only key
    // } catch (NullPointerException expected) {
    // }

    AutoPtr<ITreeMap> map;
    ec = CTreeMap::New((ITreeMap**)&map);
    if (FAILED(ec) || map == NULL) {
        printf("Failed to create CTreeMap. Error %08X\n", ec);
        return;
    }
    // try {
        ec = map->Put(NULL, Convert("b"));
        if (SUCCEEDED(ec)) {
            printf("Failed! Don't come here, because should not put NULL key.");
        }
    //     fail();
    // } catch (NullPointerException e) {
    // }

    // try {
        AutoPtr<INavigableMap> dm;
        map->GetDescendingMap((INavigableMap**)&dm);
        ec = dm->Put(NULL, Convert("b"));
        if (SUCCEEDED(ec)) {
            printf("dm put success, because should not put NULL key.");
        }
    //     fail();
    // } catch (NullPointerException e) {
    // }

    // try {
        AutoPtr<ISortedMap> sortMap;
        map->GetSubMap(Convert("a"), Convert("z"), (ISortedMap**)&sortMap);
        ec = sortMap->Put(NULL, Convert("b"));
        if (SUCCEEDED(ec)) {
            printf("sortMap put success, because should not put NULL key.");
        }
    //     fail();
    // } catch (NullPointerException e) {
    // }
}

#if 0
public void testClassCastExceptions() {
    Map<Object, Object> map = new TreeMap<Object, Object>();
    map.put("A", "a");
    try {
        map.get(5);
        fail();
    } catch (ClassCastException e) {
    }
    try {
        map.containsKey(5);
        fail();
    } catch (ClassCastException e) {
    }
    try {
        map.remove(5);
        fail();
    } catch (ClassCastException e) {
    }
}
#endif

void testClassCastExceptions()
{
    printf("\n=== testClassCastExceptions ===\n");
    AutoPtr<IMap> map;
    CTreeMap::New((IMap**)&map);
    map->Put(Convert("A"), Convert("a"));

    ECode ec = NOERROR;
    // try {
        AutoPtr<IInterface> obj;
        ec = map->Get(Convert(5), (IInterface**)&obj);
        if (SUCCEEDED(ec)) {
            printf("Get failed! Don't come here, because no this key.\n");
        }
    //     fail();
    // } catch (ClassCastException e) {
    // }

    // try {
        Boolean res;
        ec = map->ContainsKey(Convert(5), &res);
        if (SUCCEEDED(ec)) {
            printf("ContainsKey failed! Don't come here, because no this key.\n");
        }
        // fail();
    // } catch (ClassCastException e) {
    // }

    // try {
        ec = map->Remove(Convert(5));
        if (SUCCEEDED(ec)) {
            printf("Remove failed! Don't come here, because no this key.\n");
        }
        // fail();
    // } catch (ClassCastException e) {
    // }
}

#if 0
public void testClassCastExceptionsOnBounds() {
    Map<Object, Object> map = new TreeMap<Object, Object>().subMap("a", "z");
    try {
        map.get(5);
        fail();
    } catch (ClassCastException e) {
    }
    try {
        map.containsKey(5);
        fail();
    } catch (ClassCastException e) {
    }
    try {
        map.remove(5);
        fail();
    } catch (ClassCastException e) {
    }
}
#endif

void testClassCastExceptionsOnBounds()
{
    printf("\n=== testClassCastExceptionsOnBounds ===\n");
    AutoPtr<ITreeMap> treeMap;
    CTreeMap::New((ITreeMap**)&treeMap);

    AutoPtr<ISortedMap> sMap;
    treeMap->GetSubMap(Convert("a"), Convert("z"), (ISortedMap**)&sMap);

    IMap* map = IMap::Probe(sMap);
    ECode ec = NOERROR;

    // try {
        AutoPtr<IInterface> obj;
        ec = map->Get(Convert(5), (IInterface**)&obj);
        if (SUCCEEDED(ec)) {
            printf("Get failed! Don't come here, because no this key.\n");
        }
    //     fail();
    // } catch (ClassCastException e) {
    // }

    // try {
        Boolean res;
        ec = map->ContainsKey(Convert(5), &res);
        if (SUCCEEDED(ec)) {
            printf("ContainsKey failed! Don't come here, because no this key.\n");
        }
        // fail();
    // } catch (ClassCastException e) {
    // }

    // try {
        ec = map->Remove(Convert(5));
        if (SUCCEEDED(ec)) {
            printf("Remove failed! Don't come here, because no this key.\n");
        }
        // fail();
    // } catch (ClassCastException e) {
    // }
}

#if 0
public void testClone() {
    TreeMap<String, String> map = new TreeMap<String, String>() {
        @Override public String toString() {
            return "x:" + super.toString();
        }
    };

    map.put("A", "a");
    map.put("B", "b");

    @SuppressWarnings("unchecked")
    TreeMap<String, String> clone = (TreeMap<String, String>) map.clone();
    assertEquals(map.getClass(), clone.getClass());
    assertEquals("x:{A=a, B=b}", map.toString());
}
#endif

#if 0
public void testEmptyMapSerialization() {
    String s = "aced0005737200116a6176612e7574696c2e547265654d61700cc1f63e2d256a"
            + "e60300014c000a636f6d70617261746f727400164c6a6176612f7574696c2f436"
            + "f6d70617261746f723b78707077040000000078";
    TreeMap<String, String> map = new TreeMap<String, String>();
    new SerializationTester<TreeMap<String, String>>(map, s).test();
}
#endif

#if 0
public void testSerializationWithComparator() {
    String s = "aced0005737200116a6176612e7574696c2e547265654d61700cc1f63e2d256a"
            + "e60300014c000a636f6d70617261746f727400164c6a6176612f7574696c2f436"
            + "f6d70617261746f723b78707372002a6a6176612e6c616e672e537472696e6724"
            + "43617365496e73656e736974697665436f6d70617261746f7277035c7d5c50e5c"
            + "e02000078707704000000027400016171007e00057400016271007e000678";
    TreeMap<String, String> map = new TreeMap<String, String>(
            String.CASE_INSENSITIVE_ORDER);
    map.put("a", "a");
    map.put("b", "b");
    new SerializationTester<NavigableMap<String, String>>(map, s) {
        @Override protected void verify(NavigableMap<String, String> deserialized) {
            assertEquals(0, deserialized.comparator().compare("X", "x"));
        }
    }.test();
}
#endif

#if 0
public void testSubMapSerialization() {
    String s = "aced0005737200216a6176612e7574696c2e547265654d617024417363656e646"
            + "96e675375624d61700cab946d1f0fab1c020000787200216a6176612e7574696c2"
            + "e547265654d6170244e6176696761626c655375624d6170e2d0a70e64210e08020"
            + "0075a000966726f6d53746172745a000b6869496e636c75736976655a000b6c6f4"
            + "96e636c75736976655a0005746f456e644c000268697400124c6a6176612f6c616"
            + "e672f4f626a6563743b4c00026c6f71007e00024c00016d7400134c6a6176612f7"
            + "574696c2f547265654d61703b7870000001007400016374000161737200116a617"
            + "6612e7574696c2e547265654d61700cc1f63e2d256ae60300014c000a636f6d706"
            + "17261746f727400164c6a6176612f7574696c2f436f6d70617261746f723b78707"
            + "372002a6a6176612e6c616e672e537472696e672443617365496e73656e7369746"
            + "97665436f6d70617261746f7277035c7d5c50e5ce0200007870770400000004710"
            + "07e000671007e00067400016271007e000c71007e000571007e000574000164710"
            + "07e000d78";
    TreeMap<String, String> map = new TreeMap<String, String>(
            String.CASE_INSENSITIVE_ORDER);
    map.put("a", "a");
    map.put("b", "b");
    map.put("c", "c");
    map.put("d", "d");
    SortedMap<String, String> subMap = map.subMap("a", "c");
    new SerializationTester<SortedMap<String, String>>(subMap, s) {
        @Override protected void verify(SortedMap<String, String> deserialized) {
            try {
                deserialized.put("e", "e");
                fail();
            } catch (IllegalArgumentException expected) {
            }
        }
    }.test();
}
#endif

#if 0
public void testNavigableSubMapSerialization() {
    String s = "aced0005737200216a6176612e7574696c2e547265654d617024417363656e646"
            + "96e675375624d61700cab946d1f0fab1c020000787200216a6176612e7574696c2"
            + "e547265654d6170244e6176696761626c655375624d6170e2d0a70e64210e08020"
            + "0075a000966726f6d53746172745a000b6869496e636c75736976655a000b6c6f4"
            + "96e636c75736976655a0005746f456e644c000268697400124c6a6176612f6c616"
            + "e672f4f626a6563743b4c00026c6f71007e00024c00016d7400134c6a6176612f7"
            + "574696c2f547265654d61703b7870000100007400016374000161737200116a617"
            + "6612e7574696c2e547265654d61700cc1f63e2d256ae60300014c000a636f6d706"
            + "17261746f727400164c6a6176612f7574696c2f436f6d70617261746f723b78707"
            + "372002a6a6176612e6c616e672e537472696e672443617365496e73656e7369746"
            + "97665436f6d70617261746f7277035c7d5c50e5ce0200007870770400000004710"
            + "07e000671007e00067400016271007e000c71007e000571007e000574000164710"
            + "07e000d78";
    TreeMap<String, String> map = new TreeMap<String, String>(
            String.CASE_INSENSITIVE_ORDER);
    map.put("a", "a");
    map.put("b", "b");
    map.put("c", "c");
    map.put("d", "d");
    SortedMap<String, String> subMap = map.subMap("a", FALSE, "c", true);
    new SerializationTester<SortedMap<String, String>>(subMap, s) {
        @Override protected void verify(SortedMap<String, String> deserialized) {
            try {
                deserialized.put("e", "e");
                fail();
            } catch (IllegalArgumentException expected) {
            }
        }
    }.test();
}
#endif

#if 0
public void testDescendingMapSerialization() {
    String s = "aced0005737200226a6176612e7574696c2e547265654d61702444657363656e6"
            + "4696e675375624d61700cab946d1f0f9d0c0200014c001172657665727365436f6"
            + "d70617261746f727400164c6a6176612f7574696c2f436f6d70617261746f723b7"
            + "87200216a6176612e7574696c2e547265654d6170244e6176696761626c6553756"
            + "24d6170e2d0a70e64210e080200075a000966726f6d53746172745a000b6869496"
            + "e636c75736976655a000b6c6f496e636c75736976655a0005746f456e644c00026"
            + "8697400124c6a6176612f6c616e672f4f626a6563743b4c00026c6f71007e00034"
            + "c00016d7400134c6a6176612f7574696c2f547265654d61703b787001010101707"
            + "0737200116a6176612e7574696c2e547265654d61700cc1f63e2d256ae60300014"
            + "c000a636f6d70617261746f7271007e000178707372002a6a6176612e6c616e672"
            + "e537472696e672443617365496e73656e736974697665436f6d70617261746f727"
            + "7035c7d5c50e5ce02000078707704000000027400016171007e000a74000162710"
            + "07e000b78737200286a6176612e7574696c2e436f6c6c656374696f6e732452657"
            + "665727365436f6d70617261746f7232000003fa6c354d510200014c0003636d707"
            + "1007e0001787071007e0009";
    TreeMap<String, String> map = new TreeMap<String, String>(
            String.CASE_INSENSITIVE_ORDER);
    map.put("a", "a");
    map.put("b", "b");
    NavigableMap<String, String> descendingMap = map.descendingMap();
    new SerializationTester<NavigableMap<String, String>>(descendingMap, s) {
        @Override protected void verify(NavigableMap<String, String> deserialized) {
            assertEquals("b", deserialized.navigableKeySet().first());
        }
    }.test();
}
#endif

#if 0
public void testJava5SerializationWithComparator() {
    String s = "aced0005737200116a6176612e7574696c2e547265654d61700cc1f63e2d256a"
            + "e60300014c000a636f6d70617261746f727400164c6a6176612f7574696c2f436"
            + "f6d70617261746f723b78707372002a6a6176612e6c616e672e537472696e6724"
            + "43617365496e73656e736974697665436f6d70617261746f7277035c7d5c50e5c"
            + "e02000078707704000000027400016171007e00057400016271007e000678";
    TreeMap<String, String> map = new TreeMap<String, String>(
            String.CASE_INSENSITIVE_ORDER);
    map.put("a", "a");
    map.put("b", "b");
    new SerializationTester<TreeMap<String, String>>(map, s) {
        @Override protected void verify(TreeMap<String, String> deserialized) {
            assertEquals(0, deserialized.comparator().compare("X", "x"));
        }
    }.test();
}
#endif

#if 0
/**
 * On JDK5, this fails with a NullPointerException after deserialization!
 */
public void testJava5SubMapSerialization() {
    String s = "aced0005737200186a6176612e7574696c2e547265654d6170245375624d6170"
            + "a5818343a213c27f0200055a000966726f6d53746172745a0005746f456e644c0"
            + "00766726f6d4b65797400124c6a6176612f6c616e672f4f626a6563743b4c0006"
            + "7468697324307400134c6a6176612f7574696c2f547265654d61703b4c0005746"
            + "f4b657971007e00017870000074000161737200116a6176612e7574696c2e5472"
            + "65654d61700cc1f63e2d256ae60300014c000a636f6d70617261746f727400164"
            + "c6a6176612f7574696c2f436f6d70617261746f723b78707372002a6a6176612e"
            + "6c616e672e537472696e672443617365496e73656e736974697665436f6d70617"
            + "261746f7277035c7d5c50e5ce020000787077040000000471007e000471007e00"
            + "047400016271007e000a7400016371007e000b7400016471007e000c7871007e0"
            + "00b";
    TreeMap<String, String> map = new TreeMap<String, String>(String.CASE_INSENSITIVE_ORDER);
    map.put("a", "a");
    map.put("b", "b");
    map.put("c", "c");
    map.put("d", "d");
    SortedMap<String, String> subMap = map.subMap("a", "c");
    new SerializationTester<SortedMap<String, String>>(subMap, s) {
        @Override protected void verify(SortedMap<String, String> deserialized) {
            try {
                deserialized.put("e", "e");
                fail();
            } catch (IllegalArgumentException expected) {
            }
        }
    }.test();
}
#endif

//==============================================================================

EXTERN_C int mainTreeMapTest(int argc, char *argv[])
{
    printf("\n==== libcore/utility/mainTreeMapTest ====\n");
    testEntrySetSetValue();
    testSubMapEntrySetSetValue();
    testExceptionsOnSetValue();
    testExceptionsOnSubMapSetValue();//
    testConcurrentModificationDetection();
    testIteratorRemoves();
    testEntrySetUsesComparatorOnly();
    testMapConstructorPassingSortedMap();
    testNullsWithNaturalOrder();
    testClassCastExceptions();
    testClassCastExceptionsOnBounds();
    printf("\n==== end of libcore/utility/mainTreeMapTest ====\n");

    return 0;
}

} //namespace Utility
} //namespace Elastos