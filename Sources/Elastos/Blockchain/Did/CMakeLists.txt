
set(CAR_FLAGS -n -u)
set(LUBE_FLAGS -n -u)

include(Elastos.DID.cmake)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/did/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../Wallet)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../Wallet/spv/include)
xdk_export_car_headers(export_headers ${CURRENT_MIRROR_HEADERS})
xdk_compile_car(CAR_GENERATED_SOURCES Elastos.DID.car ${export_headers})

set(SOURCES
    ${CAR_GENERATED_SOURCES}
    ${CURRENT_MIRROR_SOURCES}
    CDIDChecker.cpp
    CDIDManager.cpp
    ElaDID.cpp
)

add_library( idchain SHARED IMPORTED GLOBAL )
if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android" )
    set_target_properties( idchain PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/Elastos/Blockchain/Did/did/libs/libidchain.so )
endif()

add_library(Elastos.Did SHARED ${SOURCES})

target_link_libraries(Elastos.Did
    Elastos.Runtime
    Elastos.Runtime_static
    Elastos.CoreLibrary
    Elastos.Wallet
    idchain
)

