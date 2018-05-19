
xdk_add_subdirectories(
    Runtime
    LibCore
)

if(NOT ("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "linux" AND "$ENV{XDK_TARGET_CPU_ARCH}" STREQUAL "32"))
    xdk_add_subdirectories(
        Blockchain
    )
endif()
