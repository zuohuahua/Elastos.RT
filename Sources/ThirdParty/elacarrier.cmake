

set (ELACARRIER_SCRIPTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/scripts)
set (ELACARRIER_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ElaCarrier)
set (ELACARRIER_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/ElaCarrier)

file(MAKE_DIRECTORY ${ELACARRIER_BINARY_DIR})

add_custom_command(
    COMMENT "Preparing elacarrier for out-of-source build..."
    OUTPUT ${ELACARRIER_BINARY_DIR}/build/Makefile
    COMMAND ${ELACARRIER_SCRIPTS_DIR}/prepare_out_of_source_build.sh ${ELACARRIER_SOURCE_DIR}
    WORKING_DIRECTORY ${ELACARRIER_BINARY_DIR}
    DEPENDS ${ELACARRIER_SOURCE_DIR}/build/Makefile
)

add_custom_command(
    COMMENT "Downloading flatcc..."
    OUTPUT "${ELACARRIER_BINARY_DIR}/build/_build/.tarballs/flatcc-0.5.0.tar.gz"
    COMMAND mkdir -p ${ELACARRIER_BINARY_DIR}/build/_build/.tarballs
    COMMAND curl -L -o _build/.tarballs/flatcc-0.5.0.tar.gz https://github.com/dvidelabs/flatcc/archive/v0.5.0.tar.gz
    WORKING_DIRECTORY ${ELACARRIER_BINARY_DIR}/build
    DEPENDS ${ELACARRIER_BINARY_DIR}/build/Makefile
)

add_custom_command(
    COMMENT "Building flatcc..."
    OUTPUT "${ELACARRIER_BINARY_DIR}/build/flatcc-0.5.0/bin/flatcc"
    COMMAND tar xzvf _build/.tarballs/flatcc-0.5.0.tar.gz
    COMMAND mkdir -p flatcc-0.5.0/build/install && cd flatcc-0.5.0/build/install && cmake ../.. && make
    WORKING_DIRECTORY ${ELACARRIER_BINARY_DIR}/build
    DEPENDS "${ELACARRIER_BINARY_DIR}/build/_build/.tarballs/flatcc-0.5.0.tar.gz"
)

add_custom_command(
    COMMENT "Building elacarrier..."
    OUTPUT "${ELACARRIER_BINARY_DIR}/build/_dist/Android-arm/debug/lib/libelacommon.so"
           "${ELACARRIER_BINARY_DIR}/build/_dist/Android-arm/debug/lib/libelacarrier.so"
           "${ELACARRIER_BINARY_DIR}/build/_dist/Android-arm/debug/lib/libelasession.so"
    COMMAND ANDROID_NDK_HOME=$ENV{ANDROID_NDK} PATH=${ELACARRIER_BINARY_DIR}/build/flatcc-0.5.0/bin:$ENV{PATH} ./android_build.sh arm
    WORKING_DIRECTORY ${ELACARRIER_BINARY_DIR}/build
    DEPENDS "${ELACARRIER_BINARY_DIR}/build/flatcc-0.5.0/bin/flatcc"
)

add_custom_command(
    COMMENT "Copying elacarrier so to mirror..."
    OUTPUT "$ENV{XDK_TARGETS}/libelacommon.so"
           "$ENV{XDK_TARGETS}/libelacarrier.so"
           "$ENV{XDK_TARGETS}/libelasession.so"
    COMMAND ${CMAKE_COMMAND} -E copy libelacommon.so $ENV{XDK_TARGETS}
    COMMAND ${CMAKE_COMMAND} -E copy libelacarrier.so $ENV{XDK_TARGETS}
    COMMAND ${CMAKE_COMMAND} -E copy libelasession.so $ENV{XDK_TARGETS}
    WORKING_DIRECTORY ${ELACARRIER_BINARY_DIR}/build/_dist/Android-arm/debug/lib
    DEPENDS "${ELACARRIER_BINARY_DIR}/build/_dist/Android-arm/debug/lib/libelacommon.so"
    "${ELACARRIER_BINARY_DIR}/build/_dist/Android-arm/debug/lib/libelacarrier.so"
    "${ELACARRIER_BINARY_DIR}/build/_dist/Android-arm/debug/lib/libelasession.so"
)

add_custom_target(build_elacarrier ALL DEPENDS
    "$ENV{XDK_TARGETS}/libelacommon.so"
    "$ENV{XDK_TARGETS}/libelacarrier.so"
    "$ENV{XDK_TARGETS}/libelasession.so")
