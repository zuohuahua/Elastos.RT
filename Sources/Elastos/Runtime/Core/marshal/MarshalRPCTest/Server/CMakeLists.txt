

xdk_gen_headers_from_cls(server_smanc_headers SManC.cls)
xdk_gen_headers_from_cls(server_tc_headers TC.cls)

set(SOURCES
    server.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/TC.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/SManC.cpp
)

add_executable(RPCTestServer ${SOURCES})

target_link_libraries(RPCTestServer
    Elastos.Runtime_static
    Elastos.Runtime
    Elastos.CoreLibrary
    pthread
)

