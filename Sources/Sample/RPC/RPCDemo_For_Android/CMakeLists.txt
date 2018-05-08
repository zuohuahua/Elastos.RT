
set (PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/project)

configure_file(${PROJECT_DIR}/app/CMakeLists.txt.in
               app/CMakeLists.txt
               @ONLY)

configure_file(${PROJECT_DIR}/app/build.gradle.in
               app/build.gradle
               @ONLY)

add_custom_command(
    COMMENT "Symbolic link the RPCDemo Android project files to the mirror directory..."
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/gradlew
    COMMAND $ENV{XDK_TOOLS}/symlink_files_in_dir.sh ${PROJECT_DIR}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ${PROJECT_DIR}/gradlew
)

set(output_libraries
    ${CMAKE_CURRENT_BINARY_DIR}/app/elastos/libs/armeabi-v7a/libElastos.Runtime.so
    ${CMAKE_CURRENT_BINARY_DIR}/app/elastos/libs/armeabi-v7a/libElastos.Runtime_static.a
    ${CMAKE_CURRENT_BINARY_DIR}/app/elastos/libs/armeabi-v7a/libElastos.CoreLibrary.so
    ${CMAKE_CURRENT_BINARY_DIR}/app/elastos/libs/armeabi-v7a/libelacommon.so
    ${CMAKE_CURRENT_BINARY_DIR}/app/elastos/libs/armeabi-v7a/libelasession.so
    ${CMAKE_CURRENT_BINARY_DIR}/app/elastos/libs/armeabi-v7a/libelacarrier.so
    ${CMAKE_CURRENT_BINARY_DIR}/app/elastos/libs/armeabi-v7a/libcrypto.so
    ${CMAKE_CURRENT_BINARY_DIR}/app/elastos/libs/armeabi-v7a/libicuuc.so
    ${CMAKE_CURRENT_BINARY_DIR}/app/elastos/libs/armeabi-v7a/libstlport.so
    ${CMAKE_CURRENT_BINARY_DIR}/app/elastos/libs/armeabi-v7a/libChat.so
)

add_custom_command(
    COMMENT "Copy elastos libraries..."
    OUTPUT ${output_libraries}
    COMMAND dropsdk --output-dir app --lib-subdir armeabi-v7a
    COMMAND ${CMAKE_COMMAND} -E copy $ENV{XDK_TARGETS}/libChat.so app/elastos/libs/armeabi-v7a
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/gradlew
            $ENV{XDK_TARGETS}/libElastos.Runtime.so
            $ENV{XDK_USER_LIB}/libElastos.Runtime_static.a
            $ENV{XDK_TARGETS}/libElastos.CoreLibrary.so
            $ENV{XDK_TARGETS}/libelacarrier.so
            $ENV{XDK_TARGETS}/libelacommon.so
            $ENV{XDK_TARGETS}/libelasession.so
            $ENV{XDK_TARGETS}/libChat.so
)

add_custom_command(
    COMMENT "Building RPCDemo Android project..."
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/app/build/outputs/apk/debug/app-debug.apk"
    COMMAND ./gradlew assembleDebug
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ${output_libraries}
)


add_custom_target(build_rpcdemo ALL DEPENDS
    ${CMAKE_CURRENT_BINARY_DIR}/app/build/outputs/apk/debug/app-debug.apk
)

