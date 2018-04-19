
set(CAR_FLAGS -n -u)
set(LUBE_FLAGS -n -u)

include(Client.cmake)
xdk_compile_car(GENERATED_SOURCES Client.car)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Chat)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/../../Chat)

set(SOURCES
    ${GENERATED_SOURCES}
    ${CURRENT_MIRROR_SOURCES}
    CClient.cpp
    client.cpp
)

add_executable(Client ${SOURCES})

target_link_libraries(Client
    Elastos.Runtime
    Elastos.Runtime_static
    Elastos.CoreLibrary
    Chat
)

