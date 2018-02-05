
xdk_gen_headers_from_cls(core_library_headers Elastos.CoreLibrary.cls)

set(SOURCES
    ${CMAKE_CURRENT_BINARY_DIR}/Elastos.CoreLibrary.cpp
)

add_library(Elastos.CoreLibrary.UUIDs STATIC ${SOURCES})
