
set(SOURCES
    strgen.cpp
    cls2car.cpp
    cls2abrg.cpp
    rabin.cpp
)

if($ENV{XDK_TARGET_PLATFORM} STREQUAL "win32")
list(APPEND SOURCES
    chgpath.cpp
)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../inc)
add_library(clsutil STATIC ${SOURCES})

