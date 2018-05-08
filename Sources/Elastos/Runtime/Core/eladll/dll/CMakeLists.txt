
add_definitions(-D_USE_MY_DLLMAIN_)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../inc)

set(SOURCES
    dllmain.cpp
    dllinit.cpp
)

xdk_compile_def(DEF_GENERATED_SOURCES elastos.def)
add_library(Elastos.Runtime SHARED ${DEF_GENERATED_SOURCES} ${SOURCES})

set(MY_LINK_LIBRARIES)

list(APPEND MY_LINK_LIBRARIES
    elapi
)

if(NOT ("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "linux" AND "$ENV{XDK_TARGET_CPU_ARCH}" STREQUAL "32"))
    list(APPEND MY_LINK_LIBRARIES
        elcarrierapi
        elacarrier
    )
endif()

if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "ios")
    list(APPEND MY_LINK_LIBRARIES
        marshalcomm
    )
elseif("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
    list(APPEND MY_LINK_LIBRARIES
        servicemanager
        marshal
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
