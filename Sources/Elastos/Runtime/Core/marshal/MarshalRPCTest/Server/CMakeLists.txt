

set(SOURCES
    server.cpp
)

add_executable(RPCTestServer ${SOURCES})

target_include_directories(
    RPCTestServer PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/../SManC
    ${CMAKE_CURRENT_BINARY_DIR}/../TC
)

target_link_libraries(RPCTestServer
    Elastos.Runtime_static
    Elastos.Runtime
    Elastos.CoreLibrary
    pthread
)

