
set(SOURCES
    lib4ela.cpp
)

add_definitions(-D_CAR_RUNTIME)

add_library(lib4ela STATIC ${SOURCES})

