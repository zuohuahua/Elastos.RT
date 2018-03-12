
xdk_gen_headers_from_cls(hello_car_demo_headers Elastos.HelloCarDemo.cls)


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
    COMMAND cmake -DCMAKE_TOOLCHAIN_FILE=${APP_SOURCE_DIR}/ios.cmake -DIOS_PLATFORM=${IOS_PLATFORM} -H${APP_SOURCE_DIR} -B${APP_BUILD_DIR} -GXcode
    COMMAND cmake --build ${APP_BUILD_DIR} --config ${CMAKE_BUILD_TYPE}
    WORKING_DIRECTORY ${APP_BINARY_DIR}
)

add_custom_target(build_ios_hellocardemo ALL DEPENDS ${APP_OUTPUT})

add_dependencies(build_ios_hellocardemo hello_car_demo_headers)

