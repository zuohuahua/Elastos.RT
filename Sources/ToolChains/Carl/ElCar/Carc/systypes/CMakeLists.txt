
add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/systypes.cls"
    COMMAND ${CMAKE_COMMAND} -E echo "Compiling systypes.cls..."
    COMMAND carc -s -c systypes.cls ${CMAKE_CURRENT_SOURCE_DIR}/systypes.car
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_custom_target(systypes_car ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/systypes.cls)

