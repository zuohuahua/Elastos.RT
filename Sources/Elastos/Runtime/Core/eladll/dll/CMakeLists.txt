

add_definitions(-D_USE_MY_DLLMAIN_)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../inc)

xdk_compile_def(elastos.def)
add_library(Elastos.Runtime SHARED)

target_link_libraries(Elastos.Runtime
    lib4ela
    eltypes
    elasys
    carapi
    reflection
    clsinfo
    marshalcomm
)
