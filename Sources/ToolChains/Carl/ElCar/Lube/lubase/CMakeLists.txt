
set(SOURCES
    states.cpp
    with.cpp
    withall.cpp
    if.cpp
    func.cpp
    memstr.cpp
    lubectx.cpp
    template.cpp
    savelube.cpp
    loadlube.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../inc)
add_library(lubase STATIC ${SOURCES})

