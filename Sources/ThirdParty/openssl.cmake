
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/openssl)

set (OPENSSL_CONFIG_OPTIONS "-arch ${IOS_ARCH} -fembed-bitcode")
set (OPENSSL_PLATFORM "iphoneos-cross")

if (${IOS_PLATFORM} STREQUAL "SIMULATOR64")
    list (APPEND OPENSSL_CONFIG_OPTIONS no-asm)
endif (${IOS_PLATFORM} STREQUAL "SIMULATOR64")

set (OPENSSL_SCRIPTS ${CMAKE_CURRENT_SOURCE_DIR}/scripts)
set (OPENSSL_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/openssl)
set (OPENSSL_CC "${CMAKE_XCODE_DEVELOPER_DIR}/usr/bin/gcc")
set (OPENSSL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/openssl_install)
set (OPENSSL_DIR ${CMAKE_CURRENT_BINARY_DIR}/openssl_install/ssl)
get_filename_component(OPENSSL_CROSS_SDK ${CMAKE_IOS_SDK_ROOT} NAME)

add_custom_command(
    COMMENT "Preparing openssl for out-of-source build..."
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/openssl/Configure
    COMMAND $ENV{XDK_TOOLS}/symlink_files_in_dir.sh ${OPENSSL_SOURCE}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/openssl
    DEPENDS ${OPENSSL_SOURCE}/Configure
)

add_custom_command(
    COMMENT "Configuring openssl..."
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/openssl/Makefile
    COMMAND CC=${OPENSSL_CC} ./Configure ${OPENSSL_PLATFORM} ${OPENSSL_CONFIG_OPTIONS} --prefix=${OPENSSL_PREFIX} --openssldir=${OPENSSL_DIR}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/openssl
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/openssl/Configure
)

add_custom_command(
    COMMENT "Building openssl..."
    OUTPUT "${OPENSSL_PREFIX}/lib/libssl.a"
           "${OPENSSL_PREFIX}/lib/libcrypto.a"
    COMMAND CROSS_TOP=${CMAKE_IOS_DEVELOPER_ROOT} CROSS_SDK=${OPENSSL_CROSS_SDK} make all install_sw
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${OPENSSL_PREFIX}/include/openssl" "$ENV{XDK_USER_INC}/openssl"
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/openssl
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/openssl/Makefile
)

add_custom_target(build_openssl ALL DEPENDS ${OPENSSL_PREFIX}/lib/libssl.a
                                            ${OPENSSL_PREFIX}/lib/libcrypto.a)

add_library( ssl STATIC IMPORTED GLOBAL )
add_library( crypto STATIC IMPORTED GLOBAL )

set_target_properties( ssl PROPERTIES IMPORTED_LOCATION ${OPENSSL_PREFIX}/lib/libssl.a )
set_target_properties( crypto PROPERTIES IMPORTED_LOCATION ${OPENSSL_PREFIX}/lib/libcrypto.a )

add_dependencies( ssl build_openssl )
add_dependencies( crypto build_openssl )
