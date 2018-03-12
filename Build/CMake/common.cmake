
include($ENV{XDK_DEFINITIONS_CMAKE})

macro(xdk_export_headers target_name)
    string(REPLACE "$ENV{XDK_SOURCE_PATH}/" "" XDK_RELATIVE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
    foreach(item ${ARGN})
        add_custom_command(
            COMMENT "Exporting ${XDK_RELATIVE_DIR}/${item}"
            OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${item}"
                    "$ENV{XDK_USER_INC}/${item}"
            COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/${item}" "${CMAKE_CURRENT_BINARY_DIR}/${item}"
            COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/${item}" "$ENV{XDK_USER_INC}/${item}"
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${item}"
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
            COMMENT "Packing ${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX}"
            OUTPUT ${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX}
            COMMAND libtool -static -o ${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX} ${ARGN}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            DEPENDS ${ARGN}
        )
    else()
        add_custom_command(
            COMMENT "Packing ${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX}"
            OUTPUT ${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX}
            COMMAND $ENV{XDK_BUILD_PATH}/CMake/create_ar_script.sh ${new_archive}.ar ${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX} ${ARGN}
            COMMAND ${CMAKE_AR} -M < ${new_archive}.ar
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            DEPENDS ${ARGN}
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

function(xdk_get_filename_without_ext name_we filename)
    string(REGEX MATCH "^(.*)\\.[^.]*$" dummy ${filename})
    set(${name_we} ${CMAKE_MATCH_1} PARENT_SCOPE)
endfunction()

macro(xdk_compile_car target_name car_file)
    xdk_get_filename_without_ext(car_filename ${car_file})
    string(REPLACE "$ENV{XDK_SOURCE_PATH}/" "" XDK_RELATIVE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${car_filename}.cmake)
        set(COMPARE_CMAKE_FILES_OR_PROMPT ${CMAKE_COMMAND} -E compare_files ${CMAKE_CURRENT_BINARY_DIR}/${car_filename}.cmake ${CMAKE_CURRENT_SOURCE_DIR}/${car_filename}.cmake)
        include(${CMAKE_CURRENT_SOURCE_DIR}/${car_filename}.cmake)
    else()
        set(COMPARE_CMAKE_FILES_OR_PROMPT ${CMAKE_COMMAND} -E echo You could copy this cmake file to the source directory in order to compile the generated files. ${CMAKE_CURRENT_BINARY_DIR}/${car_filename}.cmake)
    endif()
    add_custom_command(
        COMMENT "Compiling ${XDK_RELATIVE_DIR}/${car_file}"
        OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${car_filename}.cls"
               "${CMAKE_CURRENT_BINARY_DIR}/${car_filename}Ex.cls"
               "${CMAKE_CURRENT_BINARY_DIR}/${car_filename}.d"
               "${CMAKE_CURRENT_BINARY_DIR}/${car_filename}.mk"
               "${CMAKE_CURRENT_BINARY_DIR}/${car_filename}.cmake"
               "$ENV{XDK_TARGETS}/${car_filename}.cls"
               ${GENERATED_SOURCES}
        COMMAND carc -I${CMAKE_CURRENT_SOURCE_DIR} ${CAR_FLAGS} -a -c ${car_filename}.cls -E ${car_filename}Ex.cls ${car_file}
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${car_filename}.cls" "$ENV{XDK_TARGETS}/${car_filename}.cls"
        COMMAND ${CMAKE_COMMAND} -E echo Generating H, CPP files from ${car_filename}.cls ...
        COMMAND lube ${LUBE_FLAGS} -C${car_filename}Ex.cls -f -T header -T cls2abrg -T background ${LUBE_TS}
        COMMAND carc -I${CMAKE_CURRENT_SOURCE_DIR} ${CAR_FLAGS} -d ${car_file} >${car_filename}.d
        COMMAND ${CMAKE_COMMAND} -E echo >>${car_filename}.d
        COMMAND ${COMPARE_CMAKE_FILES_OR_PROMPT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${car_file}"
    )
    add_custom_target(${target_name} ALL DEPENDS ${car_filename}.cls)
endmacro()

macro(xdk_compile_def GENERATED_FILE def_file)
    xdk_get_filename_without_ext(def_filename ${def_file})
    string(REPLACE "$ENV{XDK_SOURCE_PATH}/" "" XDK_RELATIVE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
    set(${GENERATED_FILE}
       "${CMAKE_CURRENT_BINARY_DIR}/__${def_filename}_exp.c"
        # "${CMAKE_CURRENT_BINARY_DIR}/__dllmain.cpp"
    )
    add_custom_command(
        COMMENT "Preprocessing ${XDK_RELATIVE_DIR}/${def_file}"
        OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/__${def_file}"
               "${CMAKE_CURRENT_BINARY_DIR}/__${def_filename}.sym"
               "${CMAKE_CURRENT_BINARY_DIR}/__${def_filename}.exp"
               "${CMAKE_CURRENT_BINARY_DIR}/__${def_filename}.vs"
               "${CMAKE_CURRENT_BINARY_DIR}/__${def_filename}_exp.c"
               "${CMAKE_CURRENT_BINARY_DIR}/__dllmain.cpp"
               "${CMAKE_CURRENT_BINARY_DIR}/__section.cpp"
        COMMAND "${CMAKE_C_COMPILER}" "${CMAKE_C_FLAGS}" -E -P -x c ${XDK_DEFINITIONS} -o __${def_file} ${CMAKE_CURRENT_SOURCE_DIR}/${def_file}
        COMMAND perl "$ENV{XDK_TOOLS}/def_trans.pl" __${def_file}
        COMMAND perl "$ENV{XDK_TOOLS}/res_trans.pl" __${def_file} "def" ${def_file}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${def_file}"
    )
    add_custom_target(${def_file} ALL DEPENDS __${def_file})
    set(CMAKE_SHARED_LINKER_FLAGS "-exported_symbols_list __${def_filename}.exp")
endmacro()

macro(xdk_gen_headers_from_cls target_name cls_file)
    xdk_get_filename_without_ext(cls_filename ${cls_file})
    add_custom_command(
        COMMENT "Generating header files from ${cls_filename}"
        OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${cls_filename}.cpp"
        COMMAND lube  -C${cls_file} -f -T header2 -T headercpp
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS "$ENV{XDK_TARGETS}/${cls_file}"
    )
    add_custom_target(${target_name} ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${cls_filename}.cpp)
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

# Suppress warning: empty struct has size 0 in C, size 1 in C++ [-Wextern-c-compat]
SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-extern-c-compat" )

if($ENV{XDK_VERSION} STREQUAL "rls")
    set(CMAKE_BUILD_TYPE Release)
else()
    set(CMAKE_BUILD_TYPE Debug)
endif()
