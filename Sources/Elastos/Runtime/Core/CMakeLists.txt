

if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
    xdk_add_subdirectories(
        reflection
        elapi
        carrier
        marshal
        servicemanager
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
