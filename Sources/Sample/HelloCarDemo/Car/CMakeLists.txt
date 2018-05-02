
set(CAR_FLAGS -n -u)
set(LUBE_FLAGS -n -u)

include(Elastos.HelloCarDemo.cmake)
xdk_compile_car(CAR_GENERATED_SOURCES Elastos.HelloCarDemo.car)

set(SOURCES
    ${CAR_GENERATED_SOURCES}
    ${CURRENT_MIRROR_SOURCES}
    CHelloCar.cpp
)

add_library(Elastos.HelloCarDemo SHARED ${SOURCES})

target_link_libraries(Elastos.HelloCarDemo
    Elastos.Runtime
    Elastos.Runtime_static
    Elastos.CoreLibrary
)
