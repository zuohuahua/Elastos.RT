
if(DEFINED ENV{XDK_TARGET_PRODUCT})
    add_definitions(-D_$ENV{XDK_TARGET_PRODUCT})
endif()
if(DEFINED ENV{XDK_TARGET_BOARD})
    add_definitions(-D_$ENV{XDK_TARGET_BOARD})
endif()
if(DEFINED ENV{_ELASTOS64})
    add_definitions(-D_ELASTOS64)
else()
    add_definitions(-D_ELASTOS32)
endif()
add_definitions(-DELASTOS -D_GNUC -D_$ENV{XDK_TARGET_CPU} -D_$ENV{XDK_TARGET_PLATFORM})

if(APPLE)
    add_definitions(-D_apple)
endif()

add_definitions(-D_cmake)

macro(xdk_export_headers target_name)
    string(REPLACE "$ENV{XDK_SOURCE_PATH}/" "" XDK_RELATIVE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
    foreach(item ${ARGN})
        add_custom_command(
            OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${item}"
                    "$ENV{XDK_USER_INC}/${item}"
            COMMAND ${CMAKE_COMMAND} -E make_directory "$ENV{XDK_USER_INC}"
            COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/${item}" "${CMAKE_CURRENT_BINARY_DIR}/${item}"
            COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/${item}" "$ENV{XDK_USER_INC}/${item}"
            DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${item}"
            COMMENT "Exporting ${XDK_RELATIVE_DIR}/${item}"
        )
    endforeach()

    add_custom_target(${target_name} ALL DEPENDS ${ARGN})
endmacro()

macro(xdk_add_subdirectories)
    foreach(item ${ARGV})
        add_subdirectory(${item})
    endforeach()
endmacro()

macro(xdk_combine_static_libraries new_archive)
    if(APPLE)
        add_custom_command(
            OUTPUT ${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX}
            COMMAND libtool -static -o ${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX} ${ARGN}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            DEPENDS ${ARGN}
            COMMENT "Packing ${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX}"
        )
    else()
        add_custom_command(
            OUTPUT ${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX}
            COMMAND $ENV{XDK_BUILD_PATH}/CMake/create_ar_script.sh ${new_archive}.ar ${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX} ${ARGN}
            COMMAND ${CMAKE_AR} -M < ${new_archive}.ar
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            DEPENDS ${ARGN}
            COMMENT "Packing ${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX}"
        )
    endif()
    add_custom_target(combined_${new_archive} ALL DEPENDS ${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX})
    add_library(${new_archive} STATIC IMPORTED GLOBAL)
    add_dependencies(${new_archive} combined_${new_archive})

    set_target_properties(${new_archive}
            PROPERTIES
            IMPORTED_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX}
            )
endmacro()

macro(xdk_compile_car target_name car_file)
    get_filename_component(car_filename ${car_file} NAME_WE)
    string(REPLACE "$ENV{XDK_SOURCE_PATH}/" "" XDK_RELATIVE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
    add_custom_command(
        OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${car_filename}.cls"
               "${CMAKE_CURRENT_BINARY_DIR}/${car_filename}Ex.cls"
               "${CMAKE_CURRENT_BINARY_DIR}/${car_filename}.d"
        COMMAND carc -I${CMAKE_CURRENT_SOURCE_DIR} ${CAR_FLAGS} -a -c ${car_filename}.cls -E ${car_filename}Ex.cls ${car_file}
        COMMAND ${CMAKE_COMMAND} -E echo Generating H, CPP files from ${car_filename}.cls ...
        COMMAND lube ${LUBE_FLAGS} -C${car_filename}Ex.cls -f -T header -T cls2abrg -T background ${LUBE_TS}
        COMMAND carc -I${CMAKE_CURRENT_SOURCE_DIR} ${CAR_FLAGS} -d ${car_file} >${car_filename}.d
        COMMAND ${CMAKE_COMMAND} -E echo >>${car_filename}.d
        DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${car_file}"
        COMMENT "Compiling ${XDK_RELATIVE_DIR}/${car_file}"
    )
    add_custom_target(${target_name} ALL DEPENDS ${car_filename}.cls)
endmacro()

# TODO: Add macro definiations from C FLAGS to perprocessor
macro(xdk_compile_def def_file)
    string(REPLACE "$ENV{XDK_SOURCE_PATH}/" "" XDK_RELATIVE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
    add_custom_command(
        OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/__${def_file}"
        COMMAND "${CMAKE_C_COMPILER}" "${CMAKE_C_FLAGS}" -E -P -x c -o __${def_file} ${CMAKE_CURRENT_SOURCE_DIR}/${def_file}
        DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${def_file}"
        COMMENT "Preprocessing ${XDK_RELATIVE_DIR}/${def_file}"
    )
    add_custom_target(${def_file} ALL DEPENDS __${def_file})
endmacro()

include_directories($ENV{XDK_USER_INC})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $ENV{XDK_TARGETS} )
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY $ENV{XDK_USER_OBJ}/$ENV{XDK_BUILD_KIND}/lib )

if(APPLE)
    set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-undefined,error")
else()
    set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined")
endif()

if($ENV{XDK_VERSION} STREQUAL "rls")
    set(CMAKE_BUILD_TYPE Release)
else()
    set(CMAKE_BUILD_TYPE Debug)
endif()
