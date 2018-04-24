
set(CAR_FLAGS -n -u)
set(LUBE_FLAGS -n -u)

include(Switch.cmake)
xdk_compile_car(GENERATED_SOURCES Switch.car)

set(SOURCES
    ${GENERATED_SOURCES}
    ${CURRENT_MIRROR_SOURCES}
    CSwitch.cpp
)

add_library(Switch SHARED ${SOURCES})

target_link_libraries(Switch
    Elastos.Runtime
    Elastos.Runtime_static
    Elastos.CoreLibrary
)

