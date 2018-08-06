
set(SOURCES
    CServiceManager.cpp
)

add_definitions(-D_CAR_RUNTIME)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../marshal/common)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../marshal/p2p_rpc)

if("$ENV{XDK_TARGET_CPU_ARCH}" STREQUAL "64")
    set (ELACARRIER_OS_ARCH arm64)
else("$ENV{XDK_TARGET_CPU_ARCH}" STREQUAL "64")
    set (ELACARRIER_OS_ARCH arm)
endif("$ENV{XDK_TARGET_CPU_ARCH}" STREQUAL "64")
include_directories(${CMAKE_BINARY_DIR}/ThirdParty/ElaCarrier/build/_dist/Android-${ELACARRIER_OS_ARCH}/${XDK_BUILD_TYPE}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../carrier)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../reflection)

add_library(servicemanager STATIC ${SOURCES})
