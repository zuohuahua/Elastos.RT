
xdk_add_subdirectories(
    guidseed
)

set(SOURCES
    create.cpp
    select.cpp
    flat.cpp
    clsfile.cpp
    abridge.cpp
    relabrg.cpp
    util.cpp
    newop.cpp
    type.cpp
    implibs.cpp
)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../inc)
add_library(clsbase_min STATIC ${SOURCES})

xdk_combine_static_libraries(clsbase
    $<TARGET_FILE:clsbase_min>
    $<TARGET_FILE:guidseed>
    $<TARGET_FILE:clsinfo>
)
