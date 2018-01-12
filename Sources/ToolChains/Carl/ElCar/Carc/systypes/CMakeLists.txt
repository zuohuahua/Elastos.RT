
add_custom_command(
    COMMENT "Compiling systypes.car..."
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/systypes.cls"
           "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/systypes.cls"
    COMMAND carc -s -c systypes.cls ${CMAKE_CURRENT_SOURCE_DIR}/systypes.car
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/systypes.cls ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/systypes.cls
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_custom_target(systypes_car ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/systypes.cls ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/systypes.cls)

