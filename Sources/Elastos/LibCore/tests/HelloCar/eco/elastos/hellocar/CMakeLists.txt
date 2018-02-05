
set(CAR_FLAGS -n -u)
set(LUBE_FLAGS -n -u)

xdk_compile_car(elastos_hello_car Elastos.HelloCar.car)

# include("${CMAKE_CURRENT_BINARY_DIR}/Elastos.HelloCar.cmake")

set(SOURCES
    ${GENERATED_SOURCES}
    Elastos.HelloCar.car
    Animal.cpp
    Cat.cpp
    Dog.cpp
    helloCar.cpp
    CAnimalHelper.cpp
    CMyThread.cpp
#    dllmain.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../inc/elastos/hellocar)

add_library(Elastos.HelloCar SHARED ${SOURCES})
add_dependencies(Elastos.HelloCar elastos_hello_car)

target_link_libraries(Elastos.HelloCar
    Elastos.Runtime
    Elastos.Runtime_static
    Elastos.CoreLibrary.UUIDs
    Elastos.CoreLibrary
)

