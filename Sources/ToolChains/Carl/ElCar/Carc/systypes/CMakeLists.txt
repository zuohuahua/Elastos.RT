
add_custom_command(
    COMMENT "Compiling systypes.car..."
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/systypes.cls"
           "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/systypes.cls"
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/carc -s -c systypes.cls ${CMAKE_CURRENT_SOURCE_DIR}/systypes.car
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/systypes.cls ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/systypes.cls
    DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/carc
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_custom_target(systypes_car ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/systypes.cls ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/systypes.cls)

