
include($ENV{XDK_DEFINITIONS_CMAKE})

link_directories($ENV{XDK_TARGETS})

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

macro(xdk_combine_static_libraries output_dir new_archive)
    if(APPLE)
        add_custom_command(
            COMMENT "Packing ${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX}"
            OUTPUT ${output_dir}/${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX}
            COMMAND libtool -static -o ${output_dir}/${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX} ${ARGN}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            DEPENDS ${ARGN}
        )
    else()
        add_custom_command(
            COMMENT "Packing ${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX}"
            OUTPUT ${output_dir}/${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX}
            COMMAND $ENV{XDK_BUILD_PATH}/CMake/create_ar_script.sh ${new_archive}.ar ${output_dir}/${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX} ${ARGN}
            COMMAND ${CMAKE_AR} -M < ${new_archive}.ar
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            DEPENDS ${ARGN}
        )
    endif()
    add_custom_target(combined_${new_archive} ALL DEPENDS ${output_dir}/${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX})
    add_library(${new_archive} STATIC IMPORTED GLOBAL)
    add_dependencies(${new_archive} combined_${new_archive})

    set_target_properties(${new_archive}
            PROPERTIES
            IMPORTED_LOCATION ${output_dir}/${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX}
            )
endmacro()

function(xdk_get_filename_without_ext name_we filename)
    string(REGEX MATCH "^(.*)\\.[^.]*$" dummy ${filename})
    set(${name_we} ${CMAKE_MATCH_1} PARENT_SCOPE)
endfunction()

macro(xdk_compile_car GENERATED_SOURCES car_file)
    xdk_get_filename_without_ext(car_filename ${car_file})
    string(REPLACE "$ENV{XDK_SOURCE_PATH}/" "" XDK_RELATIVE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${car_filename}.cmake)
        set(COMPARE_CMAKE_FILES_OR_PROMPT ${CMAKE_COMMAND} -E compare_files ${CMAKE_CURRENT_BINARY_DIR}/${car_filename}.cmake ${CMAKE_CURRENT_SOURCE_DIR}/${car_filename}.cmake)
    else()
        set(COMPARE_CMAKE_FILES_OR_PROMPT ${CMAKE_COMMAND} -E echo You could copy this cmake file to the source directory in order to compile the generated files. ${CMAKE_CURRENT_BINARY_DIR}/${car_filename}.cmake)
    endif()
    set(${GENERATED_SOURCES}
        "${CMAKE_CURRENT_BINARY_DIR}/__${car_filename}.cpp"
    )
    add_custom_command(
        COMMENT "Compiling ${XDK_RELATIVE_DIR}/${car_file}"
        OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${car_filename}.cls"
               "${CMAKE_CURRENT_BINARY_DIR}/${car_filename}Ex.cls"
               "${CMAKE_CURRENT_BINARY_DIR}/${car_filename}.d"
               "${CMAKE_CURRENT_BINARY_DIR}/${car_filename}.mk"
               "${CMAKE_CURRENT_BINARY_DIR}/${car_filename}.cmake"
               "${CMAKE_CURRENT_BINARY_DIR}/${car_filename}.h"
               "$ENV{XDK_TARGETS}/${car_filename}.cls"
               ${${GENERATED_SOURCES}}
               ${CURRENT_MIRROR_SOURCES}
        COMMAND carc -I${CMAKE_CURRENT_SOURCE_DIR} ${CAR_FLAGS} -a -c ${car_filename}.cls -E ${car_filename}Ex.cls ${car_file}
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${car_filename}.cls" "$ENV{XDK_TARGETS}/${car_filename}.cls"
        COMMAND ${CMAKE_COMMAND} -E echo Generating H, CPP files from ${car_filename}.cls ...
        COMMAND lube ${LUBE_FLAGS} -C${car_filename}Ex.cls -f -T header -T cls2abrg -T background ${LUBE_TS}
        COMMAND carc -I${CMAKE_CURRENT_SOURCE_DIR} ${CAR_FLAGS} -d ${car_file} >${car_filename}.d
        COMMAND ${CMAKE_COMMAND} -E echo >>${car_filename}.d
        COMMAND ${COMPARE_CMAKE_FILES_OR_PROMPT}
        COMMAND ${CMAKE_COMMAND} -E echo 1 ClassInfo ${car_filename}.cls > ${car_filename}.rc
        COMMAND "${CMAKE_C_COMPILER}" "${CMAKE_C_FLAGS}" -E -P -x c ${XDK_DEFINITIONS} -o __${car_filename}.rc ${car_filename}.rc
        COMMAND perl $ENV{XDK_TOOLS}/version.pl "__Elastos_CAR" "`pwd`" "$ENV{XDK_TARGETS}" "${CMAKE_CURRENT_SOURCE_DIR}/${car_file}" ""
        COMMAND perl $ENV{XDK_TOOLS}/cls_trans.pl __${car_filename}.rc 'NA'
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${car_file}"
    )
    add_custom_target(${car_file} ALL DEPENDS ${car_filename}.cls)
endmacro()

macro(xdk_compile_def GENERATED_SOURCES def_file)
    xdk_get_filename_without_ext(def_filename ${def_file})
    string(REPLACE "$ENV{XDK_SOURCE_PATH}/" "" XDK_RELATIVE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
    set(${GENERATED_SOURCES}
       "${CMAKE_CURRENT_BINARY_DIR}/__${def_filename}_exp.c"
        # "${CMAKE_CURRENT_BINARY_DIR}/__dllmain.cpp"
    )
    add_custom_command(
        COMMENT "Preprocessing ${XDK_RELATIVE_DIR}/${def_file}"
        OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/__${def_file}"
               "${CMAKE_CURRENT_BINARY_DIR}/__${def_filename}.sym"
               "${CMAKE_CURRENT_BINARY_DIR}/__${def_filename}.exp"
               "${CMAKE_CURRENT_BINARY_DIR}/__${def_filename}.vs"
               "${CMAKE_CURRENT_BINARY_DIR}/__dllmain.cpp"
               "${CMAKE_CURRENT_BINARY_DIR}/__section.cpp"
               ${${GENERATED_SOURCES}}
        COMMAND ${CMAKE_COMMAND} -E remove "${CMAKE_CURRENT_BINARY_DIR}/__section.cpp"
        COMMAND "${CMAKE_C_COMPILER}" "${CMAKE_C_FLAGS}" -E -P -x c ${XDK_DEFINITIONS} -o __${def_file} ${CMAKE_CURRENT_SOURCE_DIR}/${def_file}
        COMMAND perl "$ENV{XDK_TOOLS}/def_trans.pl" __${def_file}
        COMMAND perl "$ENV{XDK_TOOLS}/res_trans.pl" __${def_file} "def" ${def_file}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${def_file}"
    )
    add_custom_target(${def_file} ALL DEPENDS __${def_file})
    if(APPLE)
        string(APPEND CMAKE_SHARED_LINKER_FLAGS " -exported_symbols_list __${def_filename}.exp")
    else()
        string(APPEND CMAKE_SHARED_LINKER_FLAGS " -Wl,--retain-symbols-file,__${def_filename}.sym -Wl,--version-script,__${def_filename}.vs")
    endif()
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

if(ANDROID)
    # TODO: To be remove
    include_directories(${CMAKE_SOURCE_DIR}/../ToolChains/android/Thirdlibrary/include/icu/icu4c/source/i18n)
    include_directories(${CMAKE_SOURCE_DIR}/../ToolChains/android/Thirdlibrary/include/icu/include)
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $ENV{XDK_TARGETS} )
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY $ENV{XDK_TARGETS} )

if(APPLE)
    string(APPEND CMAKE_SHARED_LINKER_FLAGS " -Wl,-undefined,error")
    set(CMAKE_SHARED_LIBRARY_RUNTIME_C_FLAG "-Wl,-rpath,")
    set(CMAKE_SHARED_LIBRARY_RUNTIME_C_FLAG_SEP ":")
    set(CMAKE_SHARED_LIBRARY_PREFIX "")
    set(CMAKE_SHARED_LIBRARY_SUFFIX ".eco")

    set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
    set(CMAKE_INSTALL_RPATH "@executable_path/Frameworks;@loader_path/Frameworks")
    set(CMAKE_BUILD_WITH_INSTALL_NAME_DIR TRUE)
    set(CMAKE_INSTALL_NAME_DIR "@rpath")
else()
    string(APPEND CMAKE_SHARED_LINKER_FLAGS " -Wl,--no-undefined")
endif()

# Suppress warning: empty struct has size 0 in C, size 1 in C++ [-Wextern-c-compat]
string(APPEND CMAKE_CXX_FLAGS " -Wno-extern-c-compat")

if($ENV{XDK_VERSION} STREQUAL "rls")
    set(CMAKE_BUILD_TYPE Release)
else()
    set(CMAKE_BUILD_TYPE Debug)
endif()
