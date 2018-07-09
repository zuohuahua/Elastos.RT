
if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
    add_definitions(-DP2P_RPC)
    xdk_add_subdirectories(
        p2p_rpc
    )
endif()

if(("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "linux" OR "$ENV{XDK_TARGET_PLATFORM}" STREQUAL "mac")
        AND "$ENV{XDK_TARGET_CPU_ARCH}" STREQUAL "32")
    add_definitions(-DSOCK_RPC)
    xdk_add_subdirectories(
        sock_rpc
        MarshalRPCTest
    )
endif()

add_definitions(-D_CAR_RUNTIME)

xdk_add_subdirectories(common)

