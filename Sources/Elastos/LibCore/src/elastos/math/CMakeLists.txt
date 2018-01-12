
set(SOURCES
    NativeBN.cpp
    BigInt.cpp
    BitLevel.cpp
    Logical.cpp
    Primality.cpp
    Conversion.cpp
    Division.cpp
    Multiplication.cpp
    CBigDecimal.cpp
    CBigDecimalHelper.cpp
    CBigInteger.cpp
    CBigIntegerHelper.cpp
    CMathContext.cpp
    CMathContextHelper.cpp
)

add_definitions(-DELASTOS_CORELIBRARY)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/../../corelibrary)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../inc/elastos)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../inc/elastos/core)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../inc/elastos/math)
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../inc/org)
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../inc/org/android_prebuilt)

add_library(elastos.math STATIC ${SOURCES})


