
if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
    xdk_add_subdirectories(
        p2p_rpc
    )
endif()

if(("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "linux" OR "$ENV{XDK_TARGET_PLATFORM}" STREQUAL "mac")
        AND "$ENV{XDK_TARGET_CPU_ARCH}" STREQUAL "32")
    xdk_add_subdirectories(
        others_rpc
        # MarshalRPCTest
    )
endif()

set(SOURCES
    metainfos.cpp
)

add_definitions(-D_CAR_RUNTIME)
add_definitions(-DHAVE_PTHREADS)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Library/inc/elasys)

add_library(marshalcomm STATIC ${SOURCES})

