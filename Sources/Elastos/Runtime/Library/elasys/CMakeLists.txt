

set( SOURCES
    sysiids.cpp
    kclsinfo.cpp
    relocate.cpp
    elaatomics.cpp
)

add_definitions(-D_CAR_RUNTIME)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/../syscar/eco)
add_library(elasys STATIC ${SOURCES})
