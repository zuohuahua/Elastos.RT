
set(CAR_FLAGS -n -u)
set(LUBE_FLAGS -n -u)

include(Client.cmake)
xdk_compile_car(CAR_GENERATED_SOURCES Client.car)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Chat)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/../../Chat)

set(SOURCES
    ${CAR_GENERATED_SOURCES}
    ${CURRENT_MIRROR_SOURCES}
    CClient.cpp
    client.cpp
)

add_executable(ChatClient ${SOURCES})

target_link_libraries(ChatClient
    Elastos.Runtime
    Elastos.Runtime_static
    Elastos.CoreLibrary
    Chat
)

