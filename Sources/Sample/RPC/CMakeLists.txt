xdk_add_subdirectories(
    Chat
    Switch
)

if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
    xdk_add_subdirectories(
        Exe
        RPCDemo_For_Android
    )
endif()
