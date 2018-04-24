

xdk_gen_headers_from_cls(client_smanc_headers SManC.cls)
xdk_gen_headers_from_cls(client_tc_headers TC.cls)

set(SOURCES
    client.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/TC.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/SManC.cpp
)

add_executable(RPCTestClient ${SOURCES})

target_link_libraries(RPCTestClient
    Elastos.Runtime_static
    Elastos.Runtime
    Elastos.CoreLibrary
    pthread
)

