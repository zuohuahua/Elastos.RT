
set(CAR_FLAGS -n -u)
set(LUBE_FLAGS -n -u -j)

include(Elastos.AutoGenerateJavaCodes.cmake)
xdk_compile_car(CAR_GENERATED_SOURCES Elastos.AutoGenerateJavaCodes.car)

set(SOURCES
    ${CAR_GENERATED_SOURCES}
    ${CURRENT_MIRROR_SOURCES}
    CTestCar.cpp
)

add_library(Elastos.AutoGenerateJavaCodes SHARED ${SOURCES})

target_link_libraries(Elastos.AutoGenerateJavaCodes
    Elastos.Runtime
    Elastos.Runtime_static
    Elastos.CoreLibrary
)

