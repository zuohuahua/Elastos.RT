

set(SOURCES
    reflection.cpp
)


add_executable(HelloCarDemoReflection ${SOURCES})

target_link_libraries(HelloCarDemoReflection
    Elastos.Runtime_static
    Elastos.Runtime
    Elastos.CoreLibrary
)


