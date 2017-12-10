
xdk_add_subdirectories(
    ElCar
    CarCode
    Cls2C
)

if(NOT "$ENV{XDK_TARGET_PLATFORM}" STREQUAL "mac")
xdk_add_subdirectories(
    CInfoReader
)
endif()
