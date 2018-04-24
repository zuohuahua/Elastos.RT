
add_definitions(-D_USE_MY_DLLMAIN_)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../inc)

set(SOURCES
    dllmain.cpp
    dllinit.cpp
)

xdk_compile_def(GENERATED_SOURCES elastos.def)
add_library(Elastos.Runtime SHARED ${GENERATED_SOURCES} ${SOURCES})

set(MY_LINK_LIBRARIES)

list(APPEND MY_LINK_LIBRARIES
    elapi
)

if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "ios")
    list(APPEND MY_LINK_LIBRARIES
        marshalcomm
    )
elseif("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
    list(APPEND MY_LINK_LIBRARIES
        servicemanager
        marshal
        elcarrierapi
        elacarrier
        elasession
        log
    )
elseif(("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "linux" OR "$ENV{XDK_TARGET_PLATFORM}" STREQUAL "mac") AND "$ENV{XDK_TARGET_CPU_ARCH}" STREQUAL "32")
    list(APPEND MY_LINK_LIBRARIES
        marshal
        uv
        pthread
        dl
    )
else()
    list(APPEND MY_LINK_LIBRARIES
        marshalcomm
        pthread
        dl
    )
endif()

list(APPEND MY_LINK_LIBRARIES
    reflection
    carapi
    lib4ela
    eltypes
    elasys
    clsinfo
    z
)

target_link_libraries(Elastos.Runtime ${MY_LINK_LIBRARIES})
