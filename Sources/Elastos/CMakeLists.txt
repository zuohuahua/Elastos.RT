
xdk_add_subdirectories(
    Runtime
    LibCore
)

if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
    xdk_add_subdirectories(
        Blockchain
    )
endif()
