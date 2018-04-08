
if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
    xdk_add_subdirectories(
        p2p_rpc
    )
endif()

set(SOURCES
    metainfos.cpp
)

add_definitions(-D_CAR_RUNTIME)
add_definitions(-DHAVE_PTHREADS)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Library/inc/elasys)

add_library(marshalcomm STATIC ${SOURCES})

