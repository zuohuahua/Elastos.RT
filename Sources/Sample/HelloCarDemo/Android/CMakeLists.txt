
set(PROJECT_SRC ${CMAKE_CURRENT_SOURCE_DIR}/HelloElastosDemo)
set(PROJECT_BIN ${CMAKE_CURRENT_BINARY_DIR}/HelloElastosDemo)

configure_file(${PROJECT_SRC}/app/CMakeLists.txt.in
               ${PROJECT_BIN}/app/CMakeLists.txt
               @ONLY)

configure_file(${PROJECT_SRC}/app/build.gradle.in
               ${PROJECT_BIN}/app/build.gradle
               @ONLY)

add_custom_command(
    COMMENT "Symbolic link the Android project files to the mirror directory..."
    OUTPUT ${PROJECT_BIN}/gradlew
    COMMAND $ENV{XDK_TOOLS}/symlink_files_in_dir.sh ${PROJECT_SRC}
    # Remove the symbolically linked source directory. Will use the original sources.
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${PROJECT_BIN}/app/src/main/cpp
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${PROJECT_BIN}/app/src/main/java
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${PROJECT_BIN}/app/src/main/res
    COMMAND ${CMAKE_COMMAND} -E echo ndk.dir=$ENV{ANDROID_NDK} > local.properties
    COMMAND ${CMAKE_COMMAND} -E echo sdk.dir=$ENV{ANDROID_HOME} >> local.properties
    WORKING_DIRECTORY ${PROJECT_BIN}
    DEPENDS ${PROJECT_SRC}/gradlew
)

add_custom_command(
    COMMENT "Copy elastos headers and libraries..."
    OUTPUT ${PROJECT_BIN}/app/elastos/include/Elastos.HelloCarDemo.h
           ${PROJECT_BIN}/app/elastos/libs/armeabi-v7a/libElastos.HelloCarDemo.so
    COMMAND dropsdk --output-dir app --lib-subdir armeabi-v7a
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_BIN}/../../Car/Elastos.HelloCarDemo.h app/elastos/include
    COMMAND ${CMAKE_COMMAND} -E copy $ENV{XDK_TARGETS}/libElastos.HelloCarDemo.so app/elastos/libs/armeabi-v7a
    WORKING_DIRECTORY ${PROJECT_BIN}
    DEPENDS ${PROJECT_BIN}/gradlew
            ${PROJECT_BIN}/../../Car/Elastos.HelloCarDemo.h
            $ENV{XDK_TARGETS}/libElastos.HelloCarDemo.so
            $ENV{XDK_TARGETS}/libElastos.Runtime.so
            $ENV{XDK_USER_LIB}/libElastos.Runtime_static.a
            $ENV{XDK_TARGETS}/libElastos.CoreLibrary.so
            $ENV{XDK_TARGETS}/libelacarrier.so
            $ENV{XDK_TARGETS}/libelacommon.so
            $ENV{XDK_TARGETS}/libelasession.so
)

set(apk_filename "${PROJECT_BIN}/app/build/outputs/apk/${XDK_BUILD_TYPE}/app-${XDK_BUILD_TYPE}.apk")

add_custom_command(
    COMMENT "Building HelloCarDemo Android project..."
    OUTPUT ${apk_filename}
    COMMAND ./gradlew assemble${CMAKE_BUILD_TYPE}
    COMMAND ${CMAKE_COMMAND} -E touch_nocreate ${apk_filename}
    WORKING_DIRECTORY ${PROJECT_BIN}
    DEPENDS ${PROJECT_BIN}/app/elastos/include/Elastos.HelloCarDemo.h
            ${PROJECT_BIN}/app/elastos/libs/armeabi-v7a/libElastos.HelloCarDemo.so
)


add_custom_target(build_hello_elastos_demo ALL DEPENDS
    ${apk_filename}
)

