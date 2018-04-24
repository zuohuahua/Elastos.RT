
set(SOURCES
    sock.cpp
)

add_library(_sock SHARED ${SOURCES})

target_link_libraries(_sock
    pthread
)
