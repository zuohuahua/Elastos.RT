
set(SOURCES
    CJavaCarManager.cpp
)

add_definitions(-D_CAR_RUNTIME)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../reflection)

add_library(javacarmanager STATIC ${SOURCES})
