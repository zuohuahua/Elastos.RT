

add_definitions(-D_USE_MY_DLLMAIN_)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../inc)

xdk_compile_def(GENERATED_FILE elastos.def)
add_library(Elastos.Runtime SHARED ${GENERATED_FILE})

target_link_libraries(Elastos.Runtime
    lib4ela
    eltypes
    elasys
    carapi
    reflection
    clsinfo
    marshalcomm
    z
)
