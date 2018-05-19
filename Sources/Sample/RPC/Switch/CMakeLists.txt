xdk_add_subdirectories(
    Car
)

if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
    xdk_add_subdirectories(
        RPCServer
        RPCClient
    )
endif()
