

add_definitions(-D_USE_MY_DLLMAIN_)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../inc)

xdk_compile_def(GENERATED_FILE elastos.def)
add_library(Elastos.Runtime SHARED ${GENERATED_FILE})

set(MY_LINK_LIBRARIES)
if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "ios")
    list(APPEND MY_LINK_LIBRARIES
        marshalcomm
    )
elseif("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
    list(APPEND MY_LINK_LIBRARIES
#        marshal
        marshalcomm
        log
    )
endif()

list(APPEND MY_LINK_LIBRARIES
    reflection
    carapi
    lib4ela
    eltypes
    elasys
    elapi
    clsinfo
    z
)

target_link_libraries(Elastos.Runtime ${MY_LINK_LIBRARIES})
