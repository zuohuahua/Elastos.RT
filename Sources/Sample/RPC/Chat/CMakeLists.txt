
set(CAR_FLAGS -n -u)
set(LUBE_FLAGS -n -u)

include(Chat.cmake)
xdk_compile_car(CAR_GENERATED_SOURCES Chat.car)

set(SOURCES
    ${CAR_GENERATED_SOURCES}
    ${CURRENT_MIRROR_SOURCES}
    CChat.cpp
)

add_library(Chat SHARED ${SOURCES})

target_link_libraries(Chat
    Elastos.Runtime
    Elastos.Runtime_static
    Elastos.CoreLibrary
)
