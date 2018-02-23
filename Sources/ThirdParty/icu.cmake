
set (ICU_SUBDIR icu4c)
set (ICU_SCRIPTS ${CMAKE_CURRENT_SOURCE_DIR}/scripts)
set (ICU_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/${ICU_SUBDIR})
set (ICU_BINARY ${CMAKE_CURRENT_BINARY_DIR}/${ICU_SUBDIR})
set (ICU_PREFIX ${ICU_BINARY}/install)

file(MAKE_DIRECTORY ${ICU_BINARY})

add_custom_command(
    COMMENT "Building icu..."
    OUTPUT ${ICU_BINARY}/cross-build/lib/libicuuc.a
    COMMAND ${ICU_SCRIPTS}/build_icu.sh ${ICU_SOURCE} ${ICU_PREFIX} ${APPLE_CLANGPP} ${APPLE_CLANG} ${CMAKE_IOS_SDK_ROOT} ${IOS_ARCH}
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${ICU_PREFIX}/include" "$ENV{XDK_USER_INC}"
    WORKING_DIRECTORY ${ICU_BINARY}
    DEPENDS ${ICU_SOURCE}/source/configure
)

add_custom_target(build_icu ALL DEPENDS ${ICU_BINARY}/cross-build/lib/libicuuc.a)

add_library( icuuc STATIC IMPORTED GLOBAL )
set_target_properties( icuuc PROPERTIES IMPORTED_LOCATION ${ICU_BINARY}/cross-build/lib/libicuuc.a )
add_dependencies( icuuc build_icu )
