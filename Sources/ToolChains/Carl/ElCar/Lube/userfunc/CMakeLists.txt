
set(SOURCES
    prefix.cpp
    retype.cpp
    userfunc.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../inc)
add_library(userfunc STATIC ${SOURCES})

