

set(CAR_FLAGS -n -u)
set(LUBE_FLAGS -n -u)

include(TC.cmake)
xdk_compile_car(GENERATED_SOURCES TC.car)

set(SOURCES
    ${GENERATED_SOURCES}
    ${CURRENT_MIRROR_SOURCES}
    CTC.cpp
)

add_library(TC SHARED ${SOURCES})

target_link_libraries(TC
    Elastos.Runtime_static
    Elastos.Runtime
    Elastos.CoreLibrary
)
