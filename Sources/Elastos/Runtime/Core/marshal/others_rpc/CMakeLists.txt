

set(SOURCES
    metainfos.cpp
    rot.cpp
    mshproc.cpp
    imarshal.cpp
    proxy.cpp
    stub.cpp
    CRemoteParcel.cpp
    sock.cpp
)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../Library/inc/elasys)

add_library(marshal STATIC ${SOURCES})

