
set(SOURCES
    elapi.cpp
)

add_definitions(-D_CAR_RUNTIME)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Library/inc/elasys)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../marshal)

if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
add_definitions(-DP2P_RPC)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../marshal/common)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../marshal/p2p_rpc)
include_directories(${CMAKE_BINARY_DIR}/ThirdParty/ElaCarrier/build/_dist/Android-arm/${XDK_BUILD_TYPE}/include)
elseif("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "linux")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../marshal/common)
endif()

add_library(elapi STATIC ${SOURCES})
