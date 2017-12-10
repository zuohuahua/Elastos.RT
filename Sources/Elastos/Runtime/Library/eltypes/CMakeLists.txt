
xdk_add_subdirectories(
    elrefbase
    elstring
    elcontainer
)

set(SOURCES
    elquintet.cpp
    elstringapi.cpp
    ucase.cpp
)


if(NOT "$(XDK_TARGET_PLATFORM)" STREQUAL "android")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../unicode)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../unicode/inc)
endif()

add_library(eltypes_min STATIC ${SOURCES})

xdk_combine_static_libraries(eltypes
    $<TARGET_FILE:eltypes_min>
    $<TARGET_FILE:elrefbase>
    $<TARGET_FILE:elstring>
    $<TARGET_FILE:elcontainer>
)

