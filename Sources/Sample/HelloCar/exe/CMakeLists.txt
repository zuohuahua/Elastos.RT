

set(SOURCES
    main.cpp
)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/../eco/elastos/hellocar)

add_executable(HelloCar ${SOURCES})

target_link_libraries(HelloCar
    Elastos.Runtime
    Elastos.Runtime_static
    Elastos.CoreLibrary
)

