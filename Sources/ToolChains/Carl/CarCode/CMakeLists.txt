
set(SOURCES
    carcode.cpp
)

add_executable(carcode ${SOURCES})

target_link_libraries(carcode
    clsbase
    clsutil
    z
)
