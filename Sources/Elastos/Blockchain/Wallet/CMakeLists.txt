
set(CAR_FLAGS -n -u)
set(LUBE_FLAGS -n -u)

include(Elastos.Wallet.cmake)
xdk_compile_car(CAR_GENERATED_SOURCES Elastos.Wallet.car)

set(SOURCES
    ${CAR_GENERATED_SOURCES}
    ${CURRENT_MIRROR_SOURCES}
    CWalletFactory.cpp
    CElaWallet.cpp
    CMasterWallet.cpp
)

add_library(Elastos.Wallet SHARED ${SOURCES})

target_link_libraries(Elastos.Wallet
    Elastos.Runtime
    Elastos.Runtime_static
    Elastos.CoreLibrary
)

