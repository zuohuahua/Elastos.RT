
set(SOURCES
    elapi.cpp
)

add_definitions(-D_CAR_RUNTIME)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Library/inc/elasys)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../marshal)

if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../marshal/p2p_rpc)
set (ELACARRIER_COMPILE_VERSION debug)
if("$ENV{XDK_VERSION}" STREQUAL "rls")
    set (ELACARRIER_COMPILE_VERSION release)
endif()
include_directories(${CMAKE_BINARY_DIR}/ThirdParty/ElaCarrier/build/_dist/Android-arm/${ELACARRIER_COMPILE_VERSION}/include)
elseif("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "linux")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../marshal/others_rpc)
endif()

add_library(elapi STATIC ${SOURCES})
