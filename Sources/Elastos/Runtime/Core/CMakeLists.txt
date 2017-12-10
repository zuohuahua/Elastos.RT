

xdk_add_subdirectories(
    reflection
#NOTE: if marshal function used, it should be reimplemented.
#if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
    # elapi
#endif()
    marshal
    libusr
    carapi
    eladll
)
