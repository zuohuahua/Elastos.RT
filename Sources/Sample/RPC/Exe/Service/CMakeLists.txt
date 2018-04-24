
set(CAR_FLAGS -n -u)
set(LUBE_FLAGS -n -u)

include(Service.cmake)
xdk_compile_car(GENERATED_SOURCES Service.car)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../Chat)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/../../Chat)

set(SOURCES
    ${GENERATED_SOURCES}
    ${CURRENT_MIRROR_SOURCES}
    CService.cpp
    service.cpp
)

add_executable(ChatService ${SOURCES})

target_link_libraries(ChatService
    Elastos.Runtime
    Elastos.Runtime_static
    Elastos.CoreLibrary
    Chat
)

