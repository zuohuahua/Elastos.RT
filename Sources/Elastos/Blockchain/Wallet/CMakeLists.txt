
set(CAR_FLAGS -n -u)
set(LUBE_FLAGS -n -u)

include(Elastos.Wallet.cmake)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/spv/include)
xdk_export_car_headers(export_headers ${CURRENT_MIRROR_HEADERS})
xdk_compile_car(CAR_GENERATED_SOURCES Elastos.Wallet.car ${export_headers})

set(SOURCES
    ${CAR_GENERATED_SOURCES}
    ${CURRENT_MIRROR_SOURCES}
    CMasterWalletManager.cpp
    MasterWallet.cpp
    SubWallet.cpp
    SidechainSubWallet.cpp
    IdChainSubWallet.cpp
    MainchainSubWallet.cpp
)

add_library( spvsdk SHARED IMPORTED GLOBAL )
if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android" )
    set_target_properties( spvsdk PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/Elastos/Blockchain/Wallet/spv/libs/android/libspvsdk.so )
elseif("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "linux" AND "$ENV{XDK_TARGET_CPU_ARCH}" STREQUAL "64")
    set_target_properties( spvsdk PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/Elastos/Blockchain/Wallet/spv/libs/linux64/libspvsdk.so )
endif()

add_library(Elastos.Wallet SHARED ${SOURCES})

target_link_libraries(Elastos.Wallet
    Elastos.Runtime
    Elastos.Runtime_static
    Elastos.CoreLibrary
    spvsdk
)

