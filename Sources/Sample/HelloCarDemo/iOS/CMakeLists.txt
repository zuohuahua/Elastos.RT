

set (APP_NAME HelloCarApp)
set (APP_SUBDIR app)
set (APP_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${APP_SUBDIR})
set (APP_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/${APP_SUBDIR})
set (APP_BUILD_DIR build_xcode)
set (APP_OUTPUT ${APP_BINARY_DIR}/${APP_BUILD_DIR}/${CMAKE_BUILD_TYPE}${CMAKE_XCODE_EFFECTIVE_PLATFORMS}/${APP_NAME}.app/${APP_NAME})

file(MAKE_DIRECTORY ${APP_BINARY_DIR})

add_custom_command(
    COMMENT "Building ios HelloCarDemo app..."
    OUTPUT ${APP_OUTPUT}
    COMMAND ${CMAKE_COMMAND} -DCMAKE_TOOLCHAIN_FILE=${APP_SOURCE_DIR}/ios.cmake -DIOS_PLATFORM=${IOS_PLATFORM} -H${APP_SOURCE_DIR} -B${APP_BUILD_DIR} -GXcode
    COMMAND ${CMAKE_COMMAND} --build ${APP_BUILD_DIR} --config ${CMAKE_BUILD_TYPE}
    COMMAND ${CMAKE_COMMAND} -E touch_nocreate ${APP_OUTPUT}
    WORKING_DIRECTORY ${APP_BINARY_DIR}
    DEPENDS Elastos.Runtime
            Elastos.CoreLibrary
            Elastos.HelloCarDemo
)

add_custom_target(build_ios_hellocardemo ALL DEPENDS ${APP_OUTPUT})
