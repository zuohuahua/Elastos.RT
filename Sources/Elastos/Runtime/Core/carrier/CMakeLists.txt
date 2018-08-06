
set(SOURCES
    elcarrierapi.cpp
)

add_definitions(-D_CAR_RUNTIME)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../reflection)

if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
    if("$ENV{XDK_TARGET_CPU_ARCH}" STREQUAL "64")
        set (ELACARRIER_OS_ARCH arm64)
    else("$ENV{XDK_TARGET_CPU_ARCH}" STREQUAL "64")
        set (ELACARRIER_OS_ARCH arm)
    endif("$ENV{XDK_TARGET_CPU_ARCH}" STREQUAL "64")
    set (ELACARRIER_ENV Android-${ELACARRIER_OS_ARCH})
elseif("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "linux" AND "$ENV{XDK_TARGET_CPU_ARCH}" STREQUAL "64")
    set (ELACARRIER_ENV Linux-x86_64)
elseif("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "ios")
    exec_program(uname ARGS -m OUTPUT_VARIABLE ELACARRIER_OS_ARCH)
    set (ELACARRIER_LIBRARY_SUFFIX dylib)
    set (ELACARRIER_ENV iOS-${ELACARRIER_OS_ARCH})
elseif("$ENV{XDK_TARGET_PLATFORM}" MATCHES "darwin")
    exec_program(uname ARGS -m OUTPUT_VARIABLE ELACARRIER_OS_ARCH)
    set (ELACARRIER_LIBRARY_SUFFIX dylib)
    set (ELACARRIER_ENV Darwin-${ELACARRIER_OS_ARCH})
else()
    message(STATUS "Error: Architecture ($ENV{XDK_TARGET_PLATFORM}: $ENV{XDK_TARGET_CPU_ARCH}) not supported yet")
endif()

include_directories(${CMAKE_BINARY_DIR}/ThirdParty/ElaCarrier/build/_dist/${ELACARRIER_ENV}/${XDK_BUILD_TYPE}/include)

add_library(elcarrierapi STATIC ${SOURCES})
