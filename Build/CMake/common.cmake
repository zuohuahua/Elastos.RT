
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

macro(xdk_export_headers target_name)
   foreach(item ${ARGN})
       add_custom_command(
           OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${item}"
                  "$ENV{XDK_USER_INC}/${item}"
           COMMAND ${CMAKE_COMMAND} -E make_directory "$ENV{XDK_USER_INC}"
           COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/${item}" "${CMAKE_CURRENT_BINARY_DIR}/${item}"
           COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/${item}" "$ENV{XDK_USER_INC}/${item}"
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
    if($ENV{XDK_TARGET_PLATFORM} STREQUAL "mac")
        add_custom_command(
            OUTPUT ${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX}
            COMMAND libtool -static -o ${CMAKE_STATIC_LIBRARY_PREFIX}${new_archive}${CMAKE_STATIC_LIBRARY_SUFFIX} ${ARGN}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            DEPENDS ${ARGN}
        )
    else()
        add_custom_command(
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

include_directories($ENV{XDK_USER_INC})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $ENV{XDK_TARGETS} )
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY $ENV{XDK_USER_OBJ}/$ENV{XDK_BUILD_KIND}/lib )

if($ENV{XDK_VERSION} STREQUAL "rls")
    set(CMAKE_BUILD_TYPE Release)
else()
    set(CMAKE_BUILD_TYPE Debug)
endif()
