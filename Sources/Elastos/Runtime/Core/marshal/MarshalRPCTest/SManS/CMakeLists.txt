

set(CAR_FLAGS -n -u)
set(LUBE_FLAGS -n -u)

include(SManS.cmake)
xdk_compile_car(GENERATED_SOURCES SManS.car)

set(SOURCES
    ${GENERATED_SOURCES}
    ${CURRENT_MIRROR_SOURCES}
    CSManS.cpp
)

add_library(SManS SHARED ${SOURCES})

target_link_libraries(SManS
    Elastos.Runtime_static
    Elastos.Runtime
    Elastos.CoreLibrary
    _sock
)

