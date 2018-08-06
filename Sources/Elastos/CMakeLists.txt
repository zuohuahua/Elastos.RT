
xdk_add_subdirectories(
    Runtime
    LibCore
)

if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
    if("$ENV{XDK_TARGET_CPU_ARCH}" STREQUAL "32")
        xdk_add_subdirectories(
            Blockchain
        )
    endif()
endif()
