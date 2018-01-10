
set(SOURCES
    elapi.cpp
)

add_definitions(-D_CAR_RUNTIME)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Library/inc/elasys)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../marshal)

if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../marshal/android_linux)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../marshal/linux_rpc)
elseif("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "linux")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../marshal/others_rpc)
endif()

add_library(elapi STATIC ${SOURCES})
