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

#include <stdio.h>
#include <elatypes.h>

EXTERN_C int mainBigDecimalArithmeticTest(int argc, char *argv[]);
EXTERN_C int mainBigDecimalCompareTest(int argc, char *argv[]);
EXTERN_C int mainBigDecimalConstructorsTest(int argc, char *argv[]);
EXTERN_C int mainBigDecimalConvertTest(int argc, char *argv[]);
EXTERN_C int mainBigDecimalScaleOperationsTest(int argc, char *argv[]);
EXTERN_C int mainBigDecimalTest(int argc, char *argv[]);

EXTERN_C int mainBigIntegerAddTest(int argc, char *argv[]);
EXTERN_C int mainBigIntegerAndTest(int argc, char *argv[]);
EXTERN_C int mainBigIntegerCompareTest(int argc, char *argv[]);
EXTERN_C int mainBigIntegerConstructorsTest(int argc, char *argv[]);
EXTERN_C int mainBigIntegerConvertTest(int argc, char *argv[]);
EXTERN_C int mainBigIntegerDivideTest(int argc, char *argv[]);
EXTERN_C int mainBigIntegerHashCodeTest(int argc, char *argv[]);
EXTERN_C int mainBigIntegerModPowTest(int argc, char *argv[]);
EXTERN_C int mainBigIntegerMultiplyTest(int argc, char *argv[]);
EXTERN_C int mainBigIntegerNotTest(int argc, char *argv[]);
EXTERN_C int mainBigIntegerOperateBitsTest(int argc, char *argv[]);
EXTERN_C int mainBigIntegerOrTest(int argc, char *argv[]);
EXTERN_C int mainBigIntegerSubtractTest(int argc, char *argv[]);
EXTERN_C int mainBigIntegerTest(int argc, char *argv[]);
EXTERN_C int mainBigIntegerToStringTest(int argc, char *argv[]);
EXTERN_C int mainBigIntegerXorTest(int argc, char *argv[]);
EXTERN_C int mainMathContextTest(int argc, char *argv[]);
EXTERN_C int mainOldBigIntegerTest(int argc, char *argv[]);
EXTERN_C int mainRoundingModeTest(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	printf("\nbegin libcore math toVerify\n");

    mainBigDecimalArithmeticTest(argc, argv);
    mainBigDecimalCompareTest(argc, argv);
    mainBigDecimalConstructorsTest(argc, argv);
    mainBigDecimalConvertTest(argc, argv);
    mainBigDecimalScaleOperationsTest(argc, argv);
    mainBigDecimalTest(argc, argv);

    mainBigIntegerAddTest(argc, argv);
    mainBigIntegerAndTest(argc, argv);
    mainBigIntegerCompareTest(argc, argv);
    mainBigIntegerConstructorsTest(argc, argv);
    mainBigIntegerConvertTest(argc, argv);
    mainBigIntegerDivideTest(argc, argv);
    mainBigIntegerHashCodeTest(argc, argv);
    mainBigIntegerModPowTest(argc, argv);
    mainBigIntegerMultiplyTest(argc, argv);
    mainBigIntegerNotTest(argc, argv);
    mainBigIntegerOperateBitsTest(argc, argv);
    mainBigIntegerOrTest(argc, argv);
    mainBigIntegerSubtractTest(argc, argv);
    mainBigIntegerTest(argc, argv);
    mainBigIntegerToStringTest(argc, argv);
    mainBigIntegerXorTest(argc, argv);
    mainMathContextTest(argc, argv);
    mainOldBigIntegerTest(argc, argv);
    mainRoundingModeTest(argc, argv);
}




