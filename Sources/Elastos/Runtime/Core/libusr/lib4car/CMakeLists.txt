
xdk_add_subdirectories(
    lib4ela
)

set(SOURCES
    baseclsobj.cpp
    libusr.cpp
)

add_library(lib4car STATIC ${SOURCES})

