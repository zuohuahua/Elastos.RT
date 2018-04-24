
set(SOURCES
    SMan.cpp
)

xdk_gen_headers_from_cls(smans_headers SManS.cls)

add_executable(SMan ${SOURCES})

target_link_libraries(SMan
    Elastos.Runtime_static
    Elastos.Runtime
    Elastos.CoreLibrary
    pthread
)

add_dependencies(SMan smans_headers)
