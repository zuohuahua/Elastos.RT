
# Build openssl ################################################################

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/openssl)

set (OPENSSL_CONFIG_OPTIONS "-arch ${IOS_ARCH} -fembed-bitcode")

if (${IOS_PLATFORM} STREQUAL "OS")
    set (OPENSSL_PLATFORM "iphoneos-cross")
elseif (${IOS_PLATFORM} STREQUAL "SIMULATOR")
    set (OPENSSL_PLATFORM "iphoneos-cross")
elseif (${IOS_PLATFORM} STREQUAL "SIMULATOR64")
    set (OPENSSL_PLATFORM "darwin64-x86_64-cc")
    list (APPEND OPENSSL_CONFIG_OPTIONS no-arm)
endif (${IOS_PLATFORM} STREQUAL "OS")


set (OPENSSL_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/openssl)
set (OPENSSL_CC "${CMAKE_XCODE_DEVELOPER_DIR}/usr/bin/gcc")
get_filename_component(OPENSSL_CROSS_SDK ${CMAKE_IOS_SDK_ROOT} NAME)

add_custom_command(
    COMMENT "Building openssl..."
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/openssl_install/lib/libssl.a"
    COMMAND bash -c \"\(cd ${OPENSSL_SOURCE}\; find . -type f\)\" | while read F\; do mkdir -p $$\(dirname $$F\)\; rm -f $$F\; ln -s ${OPENSSL_SOURCE}/$$F $$F\; echo $$F '->' ${OPENSSL_SOURCE}/$$F\; done\; make -f Makefile.org clean
    COMMAND CC=${OPENSSL_CC} ${OPENSSL_SOURCE}/Configure ${OPENSSL_PLATFORM} ${OPENSSL_CONFIG_OPTIONS} --prefix=${CMAKE_CURRENT_BINARY_DIR}/openssl_install --openssldir=${CMAKE_CURRENT_BINARY_DIR}/openssl_install
    COMMAND CROSS_TOP=${CMAKE_IOS_DEVELOPER_ROOT} CROSS_SDK=${OPENSSL_CROSS_SDK} make all install_sw V=1
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_BINARY_DIR}/openssl_install/include/openssl" "$ENV{XDK_USER_INC}/openssl"
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/openssl
    DEPENDS ${OPENSSL_SOURCE}/Configure
)

add_custom_target(build_openssl ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/openssl_install/lib/libssl.a)

# End of build openssl #########################################################
