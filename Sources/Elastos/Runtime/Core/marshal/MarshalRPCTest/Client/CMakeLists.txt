

set(SOURCES
    client.cpp
)

add_executable(RPCTestClient ${SOURCES})

target_include_directories(
    RPCTestClient PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/../SManC
    ${CMAKE_CURRENT_BINARY_DIR}/../TC
)

target_link_libraries(RPCTestClient
    Elastos.Runtime_static
    Elastos.Runtime
    Elastos.CoreLibrary
    pthread
)

