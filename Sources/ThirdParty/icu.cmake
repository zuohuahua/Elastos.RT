
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/icu)

set (ICU_SCRIPTS ${CMAKE_CURRENT_SOURCE_DIR}/scripts)
set (ICU_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/icu)
set (ICU_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/icu/install)

add_custom_command(
    COMMENT "Building icu..."
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/icu/cross-build/lib/libicuuc.a
    COMMAND ${ICU_SCRIPTS}/build_icu.sh ${ICU_SOURCE} ${ICU_PREFIX} ${APPLE_CLANGPP} ${APPLE_CLANG} ${CMAKE_IOS_SDK_ROOT} ${IOS_ARCH}
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${ICU_PREFIX}/include" "$ENV{XDK_USER_INC}"
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/icu
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/icu/source/configure
)

add_custom_target(build_icu ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/icu/cross-build/lib/libicuuc.a)

add_library( icuuc STATIC IMPORTED GLOBAL )
set_target_properties( icuuc PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/icu/cross-build/lib/libicuuc.a )
add_dependencies( icuuc build_icu )
