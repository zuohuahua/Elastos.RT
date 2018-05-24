
set (ICU_SUBDIR icu4c)
set (ICU_SCRIPTS ${CMAKE_CURRENT_SOURCE_DIR}/scripts)
set (ICU_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/${ICU_SUBDIR})
set (ICU_BINARY ${CMAKE_CURRENT_BINARY_DIR}/${ICU_SUBDIR})
set (ICU_PREFIX ${ICU_BINARY}/install)

file(MAKE_DIRECTORY ${ICU_BINARY})

if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "ios")
    add_custom_command(
        COMMENT "Building icu..."
        OUTPUT ${ICU_BINARY}/cross-build/lib/libicuuc.a
        COMMAND ${ICU_SCRIPTS}/build_icu.sh --icu-path ${ICU_SOURCE} --output-dir ${ICU_BINARY} --install-dir ${ICU_PREFIX} --cross-build yes --cross-cxx ${APPLE_CLANGPP} --cross-cc ${APPLE_CLANG} --isysroot-dir ${CMAKE_IOS_SDK_ROOT} --target-platform ios --target-arch ${IOS_ARCH}
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${ICU_PREFIX}/include" "$ENV{XDK_USER_INC}"
        WORKING_DIRECTORY ${ICU_BINARY}
        DEPENDS ${ICU_SOURCE}/source/configure
    )
elseif("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
    set (NDK_TOOLCHAIN ${CMAKE_CURRENT_BINARY_DIR}/ndk-toolchain)
    add_custom_command(
        COMMENT "Building icu..."
        OUTPUT ${ICU_BINARY}/cross-build/lib/libicuuc.a
        COMMAND ${ICU_SCRIPTS}/build_icu.sh --icu-path ${ICU_SOURCE} --output-dir ${ICU_BINARY} --install-dir ${ICU_PREFIX} --cross-build yes --cross-toolchain ${NDK_TOOLCHAIN}/bin/arm-linux-androideabi --target-platform android --target-arch arm
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${ICU_PREFIX}/include" "$ENV{XDK_USER_INC}"
        WORKING_DIRECTORY ${ICU_BINARY}
        DEPENDS ${ICU_SOURCE}/source/configure
    )
endif()

add_custom_target(build_icu ALL DEPENDS ${ICU_BINARY}/cross-build/lib/libicuuc.a)

add_library( icuuc STATIC IMPORTED GLOBAL )
set_target_properties( icuuc PROPERTIES IMPORTED_LOCATION ${ICU_BINARY}/cross-build/lib/libicuuc.a )
add_dependencies( icuuc build_icu )

if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
    add_dependencies( build_icu ndk_toolchain )
endif()
