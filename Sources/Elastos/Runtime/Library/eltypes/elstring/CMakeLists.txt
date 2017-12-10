
set(SOURCES
    elsharedbuf.cpp
    elstring.cpp
)

add_definitions(-D_CAR_RUNTIME)

add_library(elstring STATIC ${SOURCES})


