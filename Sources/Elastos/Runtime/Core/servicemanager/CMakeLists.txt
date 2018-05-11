
set(SOURCES
    CServiceManager.cpp
)

add_definitions(-D_CAR_RUNTIME)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../marshal/p2p_rpc)

set (ELACARRIER_COMPILE_VERSION debug)
if("$ENV{XDK_VERSION}" STREQUAL "rls")
    set (ELACARRIER_COMPILE_VERSION release)
endif()
include_directories(${CMAKE_BINARY_DIR}/ThirdParty/ElaCarrier/build/_dist/Android-arm/${ELACARRIER_COMPILE_VERSION}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../carrier)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../reflection)

add_library(servicemanager STATIC ${SOURCES})
