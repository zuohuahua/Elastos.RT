
xdk_add_subdirectories(Car)
xdk_add_subdirectories(Reflection)

if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "ios")
    xdk_add_subdirectories(iOS)
elseif("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
    # xdk_add_subdirectories(Android)
endif()
