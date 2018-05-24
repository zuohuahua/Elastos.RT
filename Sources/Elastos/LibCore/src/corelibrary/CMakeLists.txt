
set(CAR_FLAGS -n -u)
set(LUBE_FLAGS -n -u)

include(Elastos.CoreLibrary.cmake)
xdk_export_car_headers(export_headers ${CURRENT_MIRROR_HEADERS})
xdk_compile_car(CAR_GENERATED_SOURCES Elastos.CoreLibrary.car ${export_headers})

set(SOURCES
    ${CAR_GENERATED_SOURCES}
    ${CURRENT_MIRROR_SOURCES}
    AsynchronousCloseMonitor.cpp
#    Atomic.cpp
    Symbols.cpp
)

add_definitions(-DELASTOS_CORELIBRARY)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../inc)

add_library(Elastos.CoreLibrary SHARED ${SOURCES})

if(ANDROID)
    # TODO: To be remove
    # Build from source or add 64-bits libraries
    add_library( crypto SHARED IMPORTED GLOBAL )
    set_target_properties( crypto PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../ToolChains/android/Thirdlibrary/lib/libcrypto.so )
endif()

target_link_libraries(Elastos.CoreLibrary
    elastos.utility
    libcore.utility
    elastos.core
    elastos.io
    elastos.math
    Elastos.Runtime
    icuuc
    crypto
    z
)

add_dependencies(Elastos.CoreLibrary libcore_headers)

if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "linux")
    target_link_libraries(Elastos.CoreLibrary icui18n)
endif()
