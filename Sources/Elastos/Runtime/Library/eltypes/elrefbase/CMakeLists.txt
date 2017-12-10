
set(SOURCES
    elrefbase.cpp
)

add_definitions(-D_CAR_RUNTIME)

add_library(elrefbase STATIC ${SOURCES})


