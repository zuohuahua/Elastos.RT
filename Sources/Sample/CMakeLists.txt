xdk_add_subdirectories(
    HelloCar
    HelloCarDemo
    RPC
)

if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
    xdk_add_subdirectories(
        AutoGenerateJavaCodes
    )
endif()
