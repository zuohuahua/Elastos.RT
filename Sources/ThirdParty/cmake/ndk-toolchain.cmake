
set (NDK_TOOLCHAIN ${CMAKE_CURRENT_BINARY_DIR}/ndk-toolchain)

add_custom_command(
    COMMENT "Making standalone NDK toolchain..."
    OUTPUT ${NDK_TOOLCHAIN}/bin/clang
    COMMAND $ENV{ANDROID_NDK}/build/tools/make_standalone_toolchain.py --arch arm --api 21 --stl=libc++ --install-dir=${NDK_TOOLCHAIN}
    DEPENDS $ENV{ANDROID_NDK}/build/tools/make_standalone_toolchain.py
)

add_custom_target(ndk_toolchain ALL DEPENDS ${NDK_TOOLCHAIN}/bin/clang)

