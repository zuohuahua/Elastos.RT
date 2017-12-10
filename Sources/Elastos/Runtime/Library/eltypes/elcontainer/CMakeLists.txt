
set(SOURCES
    elcontainer.cpp
)

add_definitions(-D_CAR_RUNTIME)

add_library(elcontainer STATIC ${SOURCES})


