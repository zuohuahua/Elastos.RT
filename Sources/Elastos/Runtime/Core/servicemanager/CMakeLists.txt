
set(SOURCES
    CServiceManager.cpp
)

add_definitions(-D_CAR_RUNTIME)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../marshal/p2p_rpc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../carrier/carrierinc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../carrier)

add_library(servicemanager STATIC ${SOURCES})
