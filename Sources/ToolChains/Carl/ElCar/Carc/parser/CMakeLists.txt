

set(SOURCES
    carc.cpp
    cmdarg.cpp
    carerr.cpp
    token.cpp
    parser.cpp
    StringBuilder.cpp
)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../inc)
add_executable(carc ${SOURCES})

target_link_libraries(carc
    clsutil
    clsbase
    z
)


