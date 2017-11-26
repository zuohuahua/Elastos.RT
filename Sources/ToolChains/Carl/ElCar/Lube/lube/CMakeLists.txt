

set(SOURCES
    lube.cpp
    cmdarg.cpp
)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../inc)
add_executable(lube ${SOURCES})

target_link_libraries(lube
    lubase
    userfunc
    clsutil
    clsbase
    z
)


