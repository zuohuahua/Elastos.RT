
if(NOT ("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "linux"))
    xdk_add_subdirectories(carrier)
endif()

if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
    xdk_add_subdirectories(
        reflection
        elapi
        marshal
        servicemanager
        javacarmanager
        libusr
        carapi
        eladll
    )
else()
    xdk_add_subdirectories(
        reflection
        elapi
        marshal
        libusr
        carapi
        eladll
    )
endif()
