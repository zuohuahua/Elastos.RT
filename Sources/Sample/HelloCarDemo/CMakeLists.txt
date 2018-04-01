
xdk_add_subdirectories(Car)

if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "ios")
    xdk_add_subdirectories(iOS)
endif()
