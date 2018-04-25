
set(CAR_FLAGS -n -u)
set(LUBE_FLAGS -n -u)

include(Elastos.AutoGenerateJavaCodes.cmake)
xdk_compile_car(GENERATED_SOURCES Elastos.AutoGenerateJavaCodes.car)

set(SOURCES
    ${GENERATED_SOURCES}
    ${CURRENT_MIRROR_SOURCES}
    CTestCar.cpp
)

add_library(Elastos.AutoGenerateJavaCodes SHARED ${SOURCES})

target_link_libraries(Elastos.AutoGenerateJavaCodes
    Elastos.Runtime
    Elastos.Runtime_static
    Elastos.CoreLibrary
)

