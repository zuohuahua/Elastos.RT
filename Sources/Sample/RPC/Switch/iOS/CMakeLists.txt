
set (APP_NAME SwitchServer)
set (APP_SUBDIR server)
set (APP_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${APP_SUBDIR})
set (APP_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/${APP_SUBDIR})
set (APP_BUILD_DIR build_xcode)
set (APP_OUTPUT ${APP_BINARY_DIR}/${APP_BUILD_DIR}/${CMAKE_BUILD_TYPE}${CMAKE_XCODE_EFFECTIVE_PLATFORMS}/${APP_NAME}.app/${APP_NAME})

file(MAKE_DIRECTORY ${APP_BINARY_DIR})

add_custom_command(
    COMMENT "Copy elastos headers and libraries..."
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/elastos/include/Switch.h
           ${CMAKE_CURRENT_BINARY_DIR}/elastos/libs/Switch.eco
    COMMAND dropsdk --output-dir ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/../Car/Switch.h elastos/include
    COMMAND ${CMAKE_COMMAND} -E copy $ENV{XDK_TARGETS}/Switch.eco elastos/libs/
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/../Car/Switch.h
            $ENV{XDK_TARGETS}/Switch.eco
            $ENV{XDK_TARGETS}/Elastos.Runtime.eco
            $ENV{XDK_USER_LIB}/libElastos.Runtime_static.a
            $ENV{XDK_TARGETS}/Elastos.CoreLibrary.eco
            $ENV{XDK_TARGETS}/libelacarrier.dylib
            $ENV{XDK_TARGETS}/libelacommon.dylib
            $ENV{XDK_TARGETS}/libelasession.dylib
)

file(GLOB SOURCES_FILES
    ${APP_SOURCE_DIR}/*.m
    ${APP_SOURCE_DIR}/*.mm
    ${APP_SOURCE_DIR}/*.h
    ${APP_SOURCE_DIR}/*.pch
    ${APP_SOURCE_DIR}/*.swift
)

add_custom_command(
    COMMENT "Building ios Switch Server app..."
    OUTPUT ${APP_OUTPUT}
    COMMAND ${CMAKE_COMMAND} -DCMAKE_TOOLCHAIN_FILE=${APP_SOURCE_DIR}/ios.cmake -DIOS_PLATFORM=${IOS_PLATFORM} -H${APP_SOURCE_DIR} -B${APP_BUILD_DIR} -GXcode
    COMMAND ${CMAKE_COMMAND} --build ${APP_BUILD_DIR} --config ${CMAKE_BUILD_TYPE}
    COMMAND ${CMAKE_COMMAND} -E touch_nocreate ${APP_OUTPUT}
    WORKING_DIRECTORY ${APP_BINARY_DIR}
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/elastos/include/Switch.h
            ${CMAKE_CURRENT_BINARY_DIR}/elastos/libs/Switch.eco
            ${SOURCES_FILES}
)

add_custom_target(build_ios_rpcserver ALL DEPENDS ${APP_OUTPUT})
