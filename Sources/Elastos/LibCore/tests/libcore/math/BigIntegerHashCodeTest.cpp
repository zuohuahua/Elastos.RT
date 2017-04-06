//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#include <elautoptr.h>
#include <elastos/coredef.h>
#include <elastos/core/StringUtils.h>
#include <elastos/core/StringBuilder.h>
#include <elastos/utility/etl/List.h>
#include <elastos/utility/Arrays.h>

using namespace Elastos;
using Elastos::Core::StringUtils;
using Elastos::Core::Math;
using Elastos::Math::IBigInteger;
using Elastos::Math::CBigInteger;
using Elastos::Math::IBigDecimal;
using Elastos::Math::CBigDecimal;
using Elastos::Math::IBigDecimalHelper;
using Elastos::Math::CBigDecimalHelper;
using Elastos::Core::EIID_IComparable;


namespace Elastos {
namespace Math {

static void assertEquals(const String& expecting, const String& toVerify)
{
    printf("expecting: [%s], toVerify: [%s]\n", expecting.string(), toVerify.string());
    assert(expecting.Equals(toVerify) && "result not equals expecting!");
}

static void assertEquals(Double expecting, Double toVerify)
{
    printf("expecting: %f, toVerify: %f\n", expecting, toVerify);
    assert(expecting == toVerify);
}

static void assertEquals(Float expecting, Float toVerify)
{
    printf("expecting: %f, toVerify: %f\n", expecting, toVerify);
    assert(expecting == toVerify);
}

static void assertEquals(Int64 expecting, Int64 toVerify)
{
    printf("expecting: %lld, toVerify: %lld\n", expecting, toVerify);
    assert(expecting == toVerify);
}

static void assertEquals(const char *hintMessage, Int32 expecting, Int32 toVerify)
{
    printf("expecting: %d, toVerify: %d. %s\n", expecting, toVerify, hintMessage);
    assert(expecting == toVerify);
}

static void assertNotEquals(const char *hintMessage, Int32 expecting, Int32 toVerify)
{
    printf("expecting: %d, toVerify: %d. %s\n", expecting, toVerify, hintMessage);
    assert(expecting != toVerify);
}

static void assertEquals(const char* hintMessage, Int64 toVerify, Int64 expecting)
{
    printf("expecting: %lld, toVerify: %lld. %s\n", expecting, toVerify, hintMessage);
    assert(expecting == toVerify);
}

static void assertEquals(const char* hintMessage, Byte toVerify, Byte expecting)
{
    printf("expecting: %x, toVerify: %x. %s\n", expecting, toVerify, hintMessage);
    assert(expecting == toVerify);
}


static void printArray(ArrayOf<IBigInteger *> *v, const char* hintMessage)
{
    printf("  >------Start print %s ------<\n", hintMessage);
    Int32 len = v->GetLength();
    for (Int32 i = 0; i < len; ++i) {
        if ((*v)[i]) {
            IBigInteger* bi = (*v)[i];
            Int32 sign = 0;
            bi->GetSignum(&sign);
            printf("    > %d: %p, sign %d\n", i, bi, sign);
        }
        else {
            printf("    > %d: NULL\n", i);
        }
    }
    printf("  >------End print %s ------<\n", hintMessage);
}

#if 0
/*
 *  Licensed to the Apache Software Foundation (ASF) under one or more
 *  contributor license agreements.  See the NOTICE file distributed with
 *  this work for additional information regarding copyright ownership.
 *  The ASF licenses this file to You under the Apache License, Version 2.0
 *  (the "License"); you may not use this file except in compliance with
 *  the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */
/**
 * @author Elena Semukhina
 */

package org.apache.harmony.tests.java.math;

import java.math.BigInteger;

import junit.framework.TestCase;

/**
 * Class:   java.math.BigInteger
 * Method: hashCode()
 */
public class BigIntegerHashCodeTest extends TestCase {
#endif
    /**
     * Test hash codes for the same object
     */
#if 0
    public void testSameObject() {
        String value1 = "12378246728727834290276457386374882976782849";
        String value2 = "-5634562095872038262928728727834290276457386374882976782849";
        BigInteger aNumber1 = new BigInteger(value1);
        BigInteger aNumber2 = new BigInteger(value2);
        int code1 = aNumber1.hashCode();
        aNumber1.add(aNumber2).shiftLeft(125);
        aNumber1.subtract(aNumber2).shiftRight(125);
        aNumber1.multiply(aNumber2).toByteArray();
        aNumber1.divide(aNumber2).bitLength();
        aNumber1.gcd(aNumber2).pow(7);
        int code2 = aNumber1.hashCode();
        assertTrue("hash codes for the same object differ", code1 == code2);
    }
#endif
void testSameObject()
{
    String value1 = String("12378246728727834290276457386374882976782849");
    String value2 = String("-5634562095872038262928728727834290276457386374882976782849");

    AutoPtr<IBigInteger> aNumber;
    ECode ec = CBigInteger::New(value1, (IBigInteger**)&aNumber);
    if (FAILED(ec) || aNumber == NULL) {
        printf(" Failed to create CBigInteger. Error %08X\n", ec);
    }

    AutoPtr<IBigInteger> bNumber;
    ec = CBigInteger::New(value2, (IBigInteger**)&bNumber);
    if (FAILED(ec) || bNumber == NULL) {
        printf(" Failed to create CBigInteger. Error %08X\n", ec);
    }

    Int32 code1;
    AutoPtr<IBigInteger> cNumber;
    AutoPtr<IBigInteger> dNumber;
    AutoPtr<IBigInteger> eNumber;
    AutoPtr<IBigInteger> fNumber;
    AutoPtr<IBigInteger> gNumber;
    AutoPtr<IBigInteger> hNumber;
    AutoPtr<IBigInteger> iNumber;
    AutoPtr<IObject> iface;

    code1 = Object::GetHashCode(aNumber);

    aNumber->Add(bNumber, (IBigInteger**)&cNumber);
    cNumber->ShiftLeft(125, (IBigInteger**)&dNumber);

    dNumber->Subtract(bNumber, (IBigInteger**)&eNumber);
    eNumber->ShiftRight(125, (IBigInteger**)&fNumber);

    fNumber->Multiply(bNumber, (IBigInteger**)&gNumber);

    AutoPtr<ArrayOf<Byte> > resBytes;
    gNumber->ToByteArray((ArrayOf<Byte> **)&resBytes);

    Int32 blen;
    eNumber->Divide(bNumber, (IBigInteger**)&hNumber);
    hNumber->BitLength(&blen);

    aNumber->Gcd(bNumber, (IBigInteger**)&iNumber);
    iNumber->Pow(7, (IBigInteger**)&hNumber);

    Int32 code2;

    code2 = Object::GetHashCode(aNumber);

    assertEquals("hash codes for the same object differ", code1, code2);
}


    /**
     * Test hash codes for equal objects.
     */
#if 0
    public void testEqualObjects() {
        String value1 = "12378246728727834290276457386374882976782849";
        String value2 = "12378246728727834290276457386374882976782849";
        BigInteger aNumber1 = new BigInteger(value1);
        BigInteger aNumber2 = new BigInteger(value2);
        int code1 = aNumber1.hashCode();
        int code2 = aNumber2.hashCode();
        if (aNumber1.equals(aNumber2)) {
            assertTrue("hash codes for equal objects are unequal", code1 == code2);
        }
    }
#endif
void testEqualObjects()
{
    String value1 = String("12378246728727834290276457386374882976782849");
    String value2 = String("-12378246728727834290276457386374882976782849");

    AutoPtr<IBigInteger> aNumber;
    ECode ec = CBigInteger::New(value1, (IBigInteger**)&aNumber);
    if (FAILED(ec) || aNumber == NULL) {
        printf(" Failed to create CBigInteger. Error %08X\n", ec);
    }

    AutoPtr<IBigInteger> bNumber;
    ec = CBigInteger::New(value2, (IBigInteger**)&bNumber);
    if (FAILED(ec) || bNumber == NULL) {
        printf(" Failed to create CBigInteger. Error %08X\n", ec);
    }

    Int32 code1, code2;
    code1 = Object::GetHashCode(aNumber);
    code2 = Object::GetHashCode(aNumber);

    Boolean result;
    aNumber->Equals(bNumber, &result);

    if (result) {
        assertEquals("hash codes for the same object differ", code1, code2);
    }
}


    /**
     * Test hash codes for unequal objects.
     * The codes are unequal.
     */
#if 0
    public void testUnequalObjectsUnequal() {
        String value1 = "12378246728727834290276457386374882976782849";
        String value2 = "-5634562095872038262928728727834290276457386374882976782849";
        BigInteger aNumber1 = new BigInteger(value1);
        BigInteger aNumber2 = new BigInteger(value2);
        int code1 = aNumber1.hashCode();
        int code2 = aNumber2.hashCode();
        if (!aNumber1.equals(aNumber2)) {
            assertTrue("hash codes for unequal objects are equal", code1 != code2);
        }
    }
#endif
void testUnequalObjectsUnequal()
{
    String value1 = String("12378246728727834290276457386374882976782849");
    String value2 = String("-5634562095872038262928728727834290276457386374882976782849");

    AutoPtr<IBigInteger> aNumber;
    ECode ec = CBigInteger::New(value1, (IBigInteger**)&aNumber);
    if (FAILED(ec) || aNumber == NULL) {
        printf(" Failed to create CBigInteger. Error %08X\n", ec);
    }

    AutoPtr<IBigInteger> bNumber;
    ec = CBigInteger::New(value2, (IBigInteger**)&bNumber);
    if (FAILED(ec) || bNumber == NULL) {
        printf(" Failed to create CBigInteger. Error %08X\n", ec);
    }

    Int32 code1, code2;
    code1 = Object::GetHashCode(aNumber);
    code2 = Object::GetHashCode(bNumber);

    Boolean result;
    aNumber->Equals(bNumber, &result);

    if (!result) {
        assertNotEquals("hash codes for unequal objects are equal", code1, code2);
    }
}

//==============================================================================

EXTERN_C int mainBigIntegerHashCodeTest(int argc, char *argv[])
{
    printf("\n==== libcore/math/BigIntegerHashCodeTest ====\n");
    testSameObject();
    testEqualObjects();
    testUnequalObjectsUnequal();
    printf("\n==== end of libcore/math/BigIntegerHashCodeTest ====\n");

    return 0;
}

}
}
