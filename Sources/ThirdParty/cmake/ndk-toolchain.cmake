
set (NDK_TOOLCHAIN ${CMAKE_CURRENT_BINARY_DIR}/ndk-toolchain)

if("$ENV{XDK_TARGET_CPU_ARCH}" STREQUAL "64")
    set (TARGET_ARCH arm64)
else("$ENV{XDK_TARGET_CPU_ARCH}" STREQUAL "64")
    set (TARGET_ARCH arm)
endif("$ENV{XDK_TARGET_CPU_ARCH}" STREQUAL "64")
add_custom_command(
    COMMENT "Making standalone NDK toolchain..."
    OUTPUT ${NDK_TOOLCHAIN}/bin/clang
    COMMAND $ENV{ANDROID_NDK}/build/tools/make_standalone_toolchain.py --arch ${TARGET_ARCH} --api 21 --stl=libc++ --install-dir=${NDK_TOOLCHAIN}
    DEPENDS $ENV{ANDROID_NDK}/build/tools/make_standalone_toolchain.py
)

add_custom_target(ndk_toolchain ALL DEPENDS ${NDK_TOOLCHAIN}/bin/clang)

