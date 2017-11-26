

set(SOURCES
    lubc.cpp
    cmdarg.cpp
    context.cpp
    token.cpp
    parerr.cpp
    parser.cpp
    memcond.cpp
    funcarg.cpp
)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../inc)
add_executable(lubc ${SOURCES})

target_link_libraries(lubc
    userfunc
    lubase
    clsutil
    clsbase
    z
)


