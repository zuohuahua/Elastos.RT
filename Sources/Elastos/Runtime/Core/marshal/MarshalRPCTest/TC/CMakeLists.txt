

set(CAR_FLAGS -n -u)
set(LUBE_FLAGS -n -u)

include(TC.cmake)
xdk_compile_car(CAR_GENERATED_SOURCES TC.car)

set(SOURCES
    ${CAR_GENERATED_SOURCES}
    ${CURRENT_MIRROR_SOURCES}
    CTC.cpp
)

add_library(TC SHARED ${SOURCES})

target_link_libraries(TC
    Elastos.Runtime_static
    Elastos.Runtime
    Elastos.CoreLibrary
)
