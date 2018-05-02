
set(SOURCES
    SMan.cpp
)

add_executable(SMan ${SOURCES})

target_include_directories(
    SMan PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/../SManS
)

target_link_libraries(SMan
    Elastos.Runtime_static
    Elastos.Runtime
    Elastos.CoreLibrary
    pthread
)

