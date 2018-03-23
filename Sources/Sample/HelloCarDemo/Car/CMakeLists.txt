
set(CAR_FLAGS -n -u)
set(LUBE_FLAGS -n -u)

xdk_compile_car(elastos_hello_car_demo Elastos.HelloCarDemo.car)

set(SOURCES
    ${GENERATED_SOURCES}
    Elastos.HelloCarDemo.car
    CHelloCar.cpp
)

add_library(Elastos.HelloCarDemo SHARED ${SOURCES})
add_dependencies(Elastos.HelloCarDemo elastos_hello_car_demo)

target_link_libraries(Elastos.HelloCarDemo
    Elastos.Runtime
    Elastos.Runtime_static
    Elastos.CoreLibrary
)

xdk_add_subdirectories(
)
