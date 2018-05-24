

set (ELACARRIER_SCRIPTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/scripts)
set (ELACARRIER_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ElaCarrier)
set (ELACARRIER_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/ElaCarrier)

file(MAKE_DIRECTORY ${ELACARRIER_BINARY_DIR})

add_custom_command(
    COMMENT "Preparing elacarrier for out-of-source build..."
    OUTPUT ${ELACARRIER_BINARY_DIR}/build/Makefile
    COMMAND $ENV{XDK_TOOLS}/symlink_files_in_dir.sh ${ELACARRIER_SOURCE_DIR}
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

set (ELACARRIER_COMPILE_VERSION debug)
if("$ENV{XDK_VERSION}" STREQUAL "rls")
    set (ELACARRIER_COMPILE_VERSION release)
endif()

set (ELACARRIER_LIBRARY_SUFFIX so)

if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
    set (ELACARRIER_ENV Android-arm)
    set (ELACARRIER_CMD COMMAND ANDROID_NDK_HOME=$ENV{ANDROID_NDK} PATH=${ELACARRIER_BINARY_DIR}/build/flatcc-0.5.0/bin:$ENV{PATH} ./android_build.sh ${ELACARRIER_COMPILE_VERSION})
elseif("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "linux" AND "$ENV{XDK_TARGET_CPU_ARCH}" STREQUAL "64")
    set (ELACARRIER_ENV Linux-x86_64)
    set (ELACARRIER_CMD COMMAND PATH=${ELACARRIER_BINARY_DIR}/build/flatcc-0.5.0/bin:$ENV{PATH} ./linux_build.sh ${ELACARRIER_COMPILE_VERSION})
elseif("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "ios")
    # set the architecture for iOS
    if (${IOS_PLATFORM} STREQUAL "OS")
        set (ELACARRIER_OS_ARCH arm64)
    elseif (${IOS_PLATFORM} STREQUAL "SIMULATOR")
        set (ELACARRIER_OS_ARCH i386)
    elseif (${IOS_PLATFORM} STREQUAL "SIMULATOR64")
        set (ELACARRIER_OS_ARCH x86_64)
    endif (${IOS_PLATFORM} STREQUAL "OS")

    set (ELACARRIER_LIBRARY_SUFFIX dylib)
    set (ELACARRIER_ENV iOS-${ELACARRIER_OS_ARCH})
    set (ELACARRIER_CMD COMMAND ANDROID_NDK_HOME=$ENV{ANDROID_NDK} PATH=${ELACARRIER_BINARY_DIR}/build/flatcc-0.5.0/bin:$ENV{PATH} ./ios_build.sh ${ELACARRIER_OS_ARCH} ${ELACARRIER_COMPILE_VERSION})
elseif("$ENV{XDK_TARGET_PLATFORM}" MATCHES "darwin")
    exec_program(uname ARGS -m OUTPUT_VARIABLE ELACARRIER_OS_ARCH)
    set (ELACARRIER_LIBRARY_SUFFIX dylib)
    set (ELACARRIER_ENV Darwin-${ELACARRIER_OS_ARCH})
    set (ELACARRIER_CMD COMMAND ANDROID_NDK_HOME=$ENV{ANDROID_NDK} PATH=${ELACARRIER_BINARY_DIR}/build/flatcc-0.5.0/bin:$ENV{PATH} ./darwin_build.sh ${ELACARRIER_COMPILE_VERSION})
else()
    message(STATUS "Error: Architecture ($ENV{XDK_TARGET_PLATFORM}: $ENV{XDK_TARGET_CPU_ARCH}) not supported yet")
endif()

add_custom_command(
    COMMENT "Building elacarrier..."
    OUTPUT "${ELACARRIER_BINARY_DIR}/build/_dist/${ELACARRIER_ENV}/${ELACARRIER_COMPILE_VERSION}/lib/libelacommon.${ELACARRIER_LIBRARY_SUFFIX}"
           "${ELACARRIER_BINARY_DIR}/build/_dist/${ELACARRIER_ENV}/${ELACARRIER_COMPILE_VERSION}/lib/libelacarrier.${ELACARRIER_LIBRARY_SUFFIX}"
           "${ELACARRIER_BINARY_DIR}/build/_dist/${ELACARRIER_ENV}/${ELACARRIER_COMPILE_VERSION}/lib/libelasession.${ELACARRIER_LIBRARY_SUFFIX}"
           "${ELACARRIER_BINARY_DIR}/build/_dist/${ELACARRIER_ENV}/${ELACARRIER_COMPILE_VERSION}/include/ela_carrier.h"
           "${ELACARRIER_BINARY_DIR}/build/_dist/${ELACARRIER_ENV}/${ELACARRIER_COMPILE_VERSION}/include/ela_session.h"
    ${ELACARRIER_CMD}
    WORKING_DIRECTORY ${ELACARRIER_BINARY_DIR}/build
    DEPENDS "${ELACARRIER_BINARY_DIR}/build/flatcc-0.5.0/bin/flatcc"
)

add_custom_command(
    COMMENT "Copying elacarrier ${ELACARRIER_LIBRARY_SUFFIX} to mirror..."
    OUTPUT "$ENV{XDK_TARGETS}/libelacommon.${ELACARRIER_LIBRARY_SUFFIX}"
           "$ENV{XDK_TARGETS}/libelacarrier.${ELACARRIER_LIBRARY_SUFFIX}"
           "$ENV{XDK_TARGETS}/libelasession.${ELACARRIER_LIBRARY_SUFFIX}"
           "$ENV{XDK_USER_INC}/ela_carrier.h"
           "$ENV{XDK_USER_INC}/ela_session.h"
    COMMAND ${CMAKE_COMMAND} -E copy lib/libelacommon.${ELACARRIER_LIBRARY_SUFFIX} $ENV{XDK_TARGETS}
    COMMAND ${CMAKE_COMMAND} -E copy lib/libelacarrier.${ELACARRIER_LIBRARY_SUFFIX} $ENV{XDK_TARGETS}
    COMMAND ${CMAKE_COMMAND} -E copy lib/libelasession.${ELACARRIER_LIBRARY_SUFFIX} $ENV{XDK_TARGETS}
    COMMAND ${CMAKE_COMMAND} -E copy include/ela_carrier.h $ENV{XDK_USER_INC}
    COMMAND ${CMAKE_COMMAND} -E copy include/ela_session.h $ENV{XDK_USER_INC}
    WORKING_DIRECTORY ${ELACARRIER_BINARY_DIR}/build/_dist/${ELACARRIER_ENV}/${ELACARRIER_COMPILE_VERSION}
    DEPENDS "${ELACARRIER_BINARY_DIR}/build/_dist/${ELACARRIER_ENV}/${ELACARRIER_COMPILE_VERSION}/lib/libelacommon.${ELACARRIER_LIBRARY_SUFFIX}"
    "${ELACARRIER_BINARY_DIR}/build/_dist/${ELACARRIER_ENV}/${ELACARRIER_COMPILE_VERSION}/lib/libelacarrier.${ELACARRIER_LIBRARY_SUFFIX}"
    "${ELACARRIER_BINARY_DIR}/build/_dist/${ELACARRIER_ENV}/${ELACARRIER_COMPILE_VERSION}/lib/libelasession.${ELACARRIER_LIBRARY_SUFFIX}"
    "${ELACARRIER_BINARY_DIR}/build/_dist/${ELACARRIER_ENV}/${ELACARRIER_COMPILE_VERSION}/include/ela_carrier.h"
    "${ELACARRIER_BINARY_DIR}/build/_dist/${ELACARRIER_ENV}/${ELACARRIER_COMPILE_VERSION}/include/ela_session.h"
)

add_custom_target(build_elacarrier ALL DEPENDS
    "$ENV{XDK_TARGETS}/libelacommon.${ELACARRIER_LIBRARY_SUFFIX}"
    "$ENV{XDK_TARGETS}/libelacarrier.${ELACARRIER_LIBRARY_SUFFIX}"
    "$ENV{XDK_TARGETS}/libelasession.${ELACARRIER_LIBRARY_SUFFIX}")
