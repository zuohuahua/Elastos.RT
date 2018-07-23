
set(SOURCES
    metainfos.cpp
)

if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../p2p_rpc)
list(APPEND SOURCES
    mshproc.cpp
    rpc.cpp
    rot.cpp
    imarshal.cpp
    proxy.cpp
    stub.cpp
    CRemoteParcel.cpp
    CParcelCarrier.cpp
)
endif()
if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "linux")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../sock_rpc)
list(APPEND SOURCES
    mshproc.cpp
    rpc.cpp
    rot.cpp
    imarshal.cpp
    proxy.cpp
    stub.cpp
    CRemoteParcel.cpp
    CParcelCarrier.cpp
)
endif()


add_definitions(-D_CAR_RUNTIME)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../Library/inc/elasys)

include_directories(${CMAKE_BINARY_DIR}/ThirdParty/ElaCarrier/build/_dist/Android-arm/${XDK_BUILD_TYPE}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../carrier)

add_library(marshalcomm STATIC ${SOURCES})

