
set(SOURCES
    RPCMessage.cpp
    session.cpp
    CSessionManager.cpp
    CP2PParcelCarrier.cpp
    CP2PParcelSession.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../common)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../Library/inc/elasys)

include_directories(${CMAKE_BINARY_DIR}/ThirdParty/ElaCarrier/build/_dist/Android-arm/${XDK_BUILD_TYPE}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../carrier)

add_library(marshal_rpc STATIC ${SOURCES})
