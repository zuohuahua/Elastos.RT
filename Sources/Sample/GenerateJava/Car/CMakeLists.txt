
set(CAR_FLAGS -n -u)
set(LUBE_FLAGS -n -u)

include(GenerateJava.cmake)
xdk_compile_car(CAR_GENERATED_SOURCES GenerateJava.car)

set(SOURCES
    ${CAR_GENERATED_SOURCES}
    ${CURRENT_MIRROR_SOURCES}
    CHelloJava.cpp
    CCarrierListener.cpp
)

add_library(GenerateJava SHARED ${SOURCES})

target_link_libraries(GenerateJava
    Elastos.Runtime
    Elastos.Runtime_static
    Elastos.CoreLibrary
)

