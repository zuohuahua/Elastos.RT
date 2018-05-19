
set(CAR_FLAGS -n -u)
set(LUBE_FLAGS -n -u)

set(SOURCES
    BigIntegerConstructorsTest.cpp
    BigIntegerAddTest.cpp
    BigIntegerAndTest.cpp
    BigIntegerCompareTest.cpp
    BigIntegerHashCodeTest.cpp
    BigIntegerModPowTest.cpp
    BigIntegerMultiplyTest.cpp
    BigIntegerDivideTest.cpp
    BigIntegerConvertTest.cpp
    BigIntegerNotTest.cpp
    BigIntegerOperateBitsTest.cpp
    BigIntegerOrTest.cpp
    BigIntegerSubtractTest.cpp
    BigIntegerTest.cpp
    BigIntegerToStringTest.cpp
    BigIntegerXorTest.cpp
    MathContextTest.cpp
    OldBigIntegerTest.cpp
    RoundingModeTest.cpp
    BigDecimalArithmeticTest.cpp
    BigDecimalCompareTest.cpp
    BigDecimalConstructorsTest.cpp
    BigDecimalConvertTest.cpp
    BigDecimalScaleOperationsTest.cpp
    BigDecimalTest.cpp
    testMathMain.cpp
)

add_executable(testMath ${SOURCES})

target_link_libraries(testMath
    Elastos.Runtime
    Elastos.Runtime_static
    Elastos.CoreLibrary
)





