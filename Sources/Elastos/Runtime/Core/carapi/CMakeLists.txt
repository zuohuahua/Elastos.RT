
set(SOURCES
    carapi.cpp
    locmod.cpp
    todo.cpp
)

add_definitions(-D_CAR_RUNTIME)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Library/inc/elasys)
include_directories(../../Library/syscar)
include_directories(../../Library/syscar/eco)

add_library(carapi STATIC ${SOURCES})

