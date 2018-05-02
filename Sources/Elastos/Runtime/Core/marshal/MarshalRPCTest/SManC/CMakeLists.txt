

set(CAR_FLAGS -n -u)
set(LUBE_FLAGS -n -u)

include(SManC.cmake)
xdk_compile_car(CAR_GENERATED_SOURCES SManC.car)

set(SOURCES
    ${CAR_GENERATED_SOURCES}
    ${CURRENT_MIRROR_SOURCES}
    CSManC.cpp
)

add_library(SManC SHARED ${SOURCES})

target_link_libraries(SManC
    Elastos.Runtime_static
    Elastos.Runtime
    Elastos.CoreLibrary
    _sock
)

