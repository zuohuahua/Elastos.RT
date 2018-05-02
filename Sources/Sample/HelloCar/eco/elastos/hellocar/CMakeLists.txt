
set(CAR_FLAGS -n -u)
set(LUBE_FLAGS -n -u)

include(Elastos.HelloCar.cmake)
xdk_compile_car(CAR_GENERATED_SOURCES Elastos.HelloCar.car)


set(SOURCES
    ${CAR_GENERATED_SOURCES}
    ${CURRENT_MIRROR_SOURCES}
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

target_link_libraries(Elastos.HelloCar
    Elastos.Runtime
    Elastos.Runtime_static
    Elastos.CoreLibrary
)

