
set(CAR_FLAGS -n -u)
set(LUBE_FLAGS -n -u)

xdk_compile_car(elastos_core_library_car Elastos.CoreLibrary.car)

set(SOURCES
    ${GENERATED_SOURCES}
    AsynchronousCloseMonitor.cpp
#    Atomic.cpp
    Symbols.cpp
)

add_definitions(-DELASTOS_CORELIBRARY)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../inc)

add_library(Elastos.CoreLibrary SHARED ${SOURCES})
add_dependencies(Elastos.CoreLibrary elastos_core_library_car)

target_link_libraries(Elastos.CoreLibrary
    Elastos.Runtime
    elastos.core
    elastos.math
    elastos.utility
    libcore.utility
    icuuc
    crypto
    z
)
