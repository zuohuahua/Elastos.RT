
set(SOURCES
    elcarrierapi.cpp
)

add_definitions(-D_CAR_RUNTIME)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../reflection)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/carrierinc)

add_library(elcarrierapi STATIC ${SOURCES})

