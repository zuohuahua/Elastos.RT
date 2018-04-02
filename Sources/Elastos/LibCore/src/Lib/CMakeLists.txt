
xdk_gen_headers_from_cls(core_library_headers Elastos.CoreLibrary.cls)

set(SOURCES
    ${CMAKE_CURRENT_BINARY_DIR}/Elastos.CoreLibrary.cpp
)

add_library(Elastos.CoreLibrary.UUIDs STATIC ${SOURCES})
set_target_properties(Elastos.CoreLibrary.UUIDs
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY $ENV{XDK_USER_LIB}
)
