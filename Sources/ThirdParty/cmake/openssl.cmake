
set (OPENSSL_SCRIPTS ${CMAKE_CURRENT_SOURCE_DIR}/scripts)
set (OPENSSL_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/openssl)
set (OPENSSL_BINARY ${CMAKE_CURRENT_BINARY_DIR}/openssl)
set (OPENSSL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/openssl_install)

file(MAKE_DIRECTORY ${OPENSSL_BINARY})

if(APPLE)
    set (OPENSSL_LIBRARY_SUFFIX dylib)
else()
    set (OPENSSL_LIBRARY_SUFFIX so)
endif()

add_custom_command(
    COMMENT "Preparing openssl for out-of-source build..."
    OUTPUT ${OPENSSL_BINARY}/Configure
    COMMAND $ENV{XDK_TOOLS}/symlink_files_in_dir.sh ${OPENSSL_SOURCE}
    WORKING_DIRECTORY ${OPENSSL_BINARY}
    DEPENDS ${OPENSSL_SOURCE}/Configure
)

set (OPENSSL_CONFIG_OPTIONS "")

if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
    set (NDK_TOOLCHAIN ${CMAKE_CURRENT_BINARY_DIR}/ndk-toolchain)
    set (OPENSSL_BUILD_COMMAND ${OPENSSL_SCRIPTS}/build_openssl.sh --target-platform android --ndk-toolchain ${NDK_TOOLCHAIN} --ndk-toolchain-basename arm-linux-androideabi --install-dir ${OPENSSL_PREFIX})
else()
    set (OPENSSL_CC "${CMAKE_XCODE_DEVELOPER_DIR}/usr/bin/gcc -arch ${IOS_ARCH}")

    if (${IOS_PLATFORM} STREQUAL "SIMULATOR64")
        string (APPEND OPENSSL_CONFIG_OPTIONS " no-asm")
    endif (${IOS_PLATFORM} STREQUAL "SIMULATOR64")
    get_filename_component(OPENSSL_CROSS_SDK ${CMAKE_IOS_SDK_ROOT} NAME)

    set (OPENSSL_BUILD_COMMAND ${OPENSSL_SCRIPTS}/build_openssl.sh --target-platform ios --cross-cc ${OPENSSL_CC} --ios-cross-top ${CMAKE_IOS_DEVELOPER_ROOT} --ios-cross-sdk ${OPENSSL_CROSS_SDK} --install-dir ${OPENSSL_PREFIX} --ssl-library-suffix ${OPENSSL_LIBRARY_SUFFIX})
endif()

if (NOT ${OPENSSL_CONFIG_OPTIONS} STREQUAL "")
    list (APPEND OPENSSL_BUILD_COMMAND --ssl-config-options ${OPENSSL_CONFIG_OPTIONS})
endif()

add_custom_command(
    COMMENT "Building openssl..."
    OUTPUT "${OPENSSL_PREFIX}/lib/libssl.${OPENSSL_LIBRARY_SUFFIX}"
           "${OPENSSL_PREFIX}/lib/libcrypto.${OPENSSL_LIBRARY_SUFFIX}"
           "$ENV{XDK_TARGETS}/libssl.${OPENSSL_LIBRARY_SUFFIX}"
           "$ENV{XDK_TARGETS}/libcrypto.${OPENSSL_LIBRARY_SUFFIX}"
    COMMAND ${OPENSSL_BUILD_COMMAND}
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${OPENSSL_PREFIX}/include/openssl" "$ENV{XDK_USER_INC}/openssl"
    COMMAND ${CMAKE_COMMAND} -E copy "${OPENSSL_PREFIX}/lib/libssl.${OPENSSL_LIBRARY_SUFFIX}" "${OPENSSL_PREFIX}/lib/libcrypto.${OPENSSL_LIBRARY_SUFFIX}" $ENV{XDK_TARGETS}
    WORKING_DIRECTORY ${OPENSSL_BINARY}
    DEPENDS ${OPENSSL_BINARY}/Configure
)

add_custom_target(build_openssl ALL
    DEPENDS "${OPENSSL_PREFIX}/lib/libssl.${OPENSSL_LIBRARY_SUFFIX}"
            "${OPENSSL_PREFIX}/lib/libcrypto.${OPENSSL_LIBRARY_SUFFIX}"
            "$ENV{XDK_TARGETS}/libssl.${OPENSSL_LIBRARY_SUFFIX}"
            "$ENV{XDK_TARGETS}/libcrypto.${OPENSSL_LIBRARY_SUFFIX}"
)

add_library( ssl STATIC IMPORTED GLOBAL )
add_library( crypto STATIC IMPORTED GLOBAL )

set_target_properties( ssl PROPERTIES IMPORTED_LOCATION $ENV{XDK_TARGETS}/libssl.${OPENSSL_LIBRARY_SUFFIX} )
set_target_properties( crypto PROPERTIES IMPORTED_LOCATION $ENV{XDK_TARGETS}/libcrypto.${OPENSSL_LIBRARY_SUFFIX} )

add_dependencies( ssl build_openssl )
add_dependencies( crypto build_openssl )

if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
    add_dependencies( build_openssl ndk_toolchain )
endif()
