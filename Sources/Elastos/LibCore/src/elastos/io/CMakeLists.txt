
set(SOURCES
    CPlainFile.cpp
)

add_definitions(-DELASTOS_CORELIBRARY)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/../../corelibrary)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../inc)

add_library(elastos.io STATIC ${SOURCES})
add_dependencies(elastos.io elastos_core_library_car)
