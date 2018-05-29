#!/bin/bash

# Exit immediately if a subsequent command exits with a non-zero status.
set -e

THIS_SCRIPT=$(basename $0)
usage()
{
    cat << EOF

The script to build icu4c for various platforms.

Usage: ${THIS_SCRIPT} [options]

Options:
  -h, --help
      Print this message

  --icu-path <ICU_PATH>
      "ICU_PATH" is the location of the ICU source code

  --output-dir <OUTPUT_DIR>
      "OUTPUT_DIR" is the location of the generated files.

  --install-dir <INSTALL_DIR>
      "INSTALL_DIR" is the installation directory.

  --cross-build <yes|no>
      Specify whether this is a cross-compilation.

  --cross-cc <CROSS_CC>
      "CROSS_CC" is the c compiler for cross-compilation.

  --cross-cxx <CROSS_CXX>
      "CROSS_CXX" is the cpp compiler for cross-compilation.

  --cross-toolchain <CROSS_TOOLCHAIN>
      "CROSS_TOOLCHAIN" is the toolchain prefix for cross-compilation.

  --isysroot-dir <ISYSROOT_DIR>
      "ISYSROOT_DIR" is the logical root directory for headers.

  --target-platform <TARGET_PLATFORM>
      "TARGET_PLATFORM" is the target platform. e.g. ios or android

  --target-arch <TARGET_ARCH>
      "TARGET_ARCH" is the target cpu architecture.
EOF

}

# Default values
ICU_PATH=.
OUTPUT_DIR=.
INSTALL_DIR=./install
CROSS_BUILD=no

if [[ $# -eq 0 ]]; then
    usage
    exit 0
fi

while [[ $# -gt 0 ]]
do
key="$1"

case $key in
    -h|--help)
        usage
        exit 0
        ;;
    --icu-path)
        ICU_PATH="$2"
        shift;shift;; # past argument and value
    --output-dir)
        OUTPUT_DIR="$2"
        shift;shift;; # past argument and value
    --install-dir)
        INSTALL_DIR="$2"
        shift;shift;; # past argument and value
    --cross-build)
        CROSS_BUILD="$2"
        if [[ ! "$CROSS_BUILD" == "yes" ]] && [[ ! "$CROSS_BUILD" == "no" ]]; then
            exit 1
        fi
        shift;shift;; # past argument and value
    --cross-cc)
        CROSS_CC="$2"
        shift;shift;; # past argument and value
    --cross-cxx)
        CROSS_CXX="$2"
        shift;shift;; # past argument and value
    --cross-toolchain)
        CROSS_TOOLCHAIN="$2"
        shift;shift;; # past argument and value
    --isysroot-dir)
        ISYSROOT_DIR="$2"
        shift;shift;; # past argument and value
    --target-platform)
        TARGET_PLATFORM="$2"
        shift;shift;; # past argument and value
    --target-arch)
        TARGET_ARCH="$2"
        shift;shift;; # past argument and value
    *)    # unknown option
        echo "Unknown option: $key"
        usage
        exit 1
        ;;
esac
done

mkdir -p $OUTPUT_DIR
cd $OUTPUT_DIR

# Number of CPU cores
N_CORES=$(getconf _NPROCESSORS_ONLN)

if [[ $OSTYPE == *darwin* ]]; then
    HOST_OS="MacOSX"
else
    HOST_OS="Linux"
fi

ICU_CONFIGURE_FLAGS="\
    --enable-static \
    --enable-shared=no \
    --enable-extras=no \
    --enable-strict=no \
    --enable-icuio=no \
    --enable-layout=no \
    --enable-layoutex=no \
    --enable-tests=no \
    --enable-samples=no \
    --enable-dyload=no"

# host build
echo Building ICU for host...
mkdir -p host-build && cd host-build
[ -e Makefile ] && make distclean

if [[ "$CROSS_BUILD" == "yes" ]]; then
    CFLAGS="-Os" CXXFLAGS="--std=c++11" \
    $ICU_PATH/source/runConfigureICU $HOST_OS $ICU_CONFIGURE_FLAGS
    make -j$N_CORES
    cd ..
else
    CFLAGS="-Os" CXXFLAGS="--std=c++11" \
    $ICU_PATH/source/runConfigureICU $HOST_OS --prefix=$INSTALL_DIR $ICU_CONFIGURE_FLAGS
    make -j$N_CORES install
    exit 0
fi

# cross build
mkdir -p cross-build && cd cross-build

ICU_FLAGS="-I$ICU_PATH/source/common/ -I$ICU_PATH/source/tools/tzcode/ "

if [ ! -z "$CROSS_TOOLCHAIN" ]; then
    export CXX=$CROSS_TOOLCHAIN-clang++
    export CC=$CROSS_TOOLCHAIN-clang
    export AR=$CROSS_TOOLCHAIN-ar
    export RANLIB=$CROSS_TOOLCHAIN-ranlib
fi
if [ ! -z "$CROSS_CXX" ]; then
    export CXX=$CROSS_CXX
fi
if [ ! -z "$CROSS_CC" ]; then
    export CC=$CROSS_CC
fi

if [ "$TARGET_PLATFORM" = "ios" ]; then
    export CFLAGS="-arch $TARGET_ARCH -miphoneos-version-min=7.0 $ICU_FLAGS"
    export CXXFLAGS="-stdlib=libc++ -std=c++11 $CFLAGS"
    export LDFLAGS="-stdlib=libc++ -Wl,-dead_strip -miphoneos-version-min=7.0 -lstdc++"

    if [ ! -z "$ISYSROOT_DIR" ]; then
        export CFLAGS="-isysroot $ISYSROOT_DIR -I$ISYSROOT_DIR/usr/include/ $CFLAGS"
        export CXXFLAGS="-isysroot $ISYSROOT_DIR -I$ISYSROOT_DIR/usr/include/ $CXXFLAGS"
        export LDFLAGS="-L$ISYSROOT_DIR/usr/lib/ -isysroot $ISYSROOT_DIR $LDFLAGS"
    fi
elif [ "$TARGET_PLATFORM" = "android" ]; then
    export CFLAGS='-Os -march=armv7-a -mfloat-abi=softfp -mfpu=neon'
    export CXXFLAGS='--std=c++11 -march=armv7-a -mfloat-abi=softfp -mfpu=neon'
    export LDFLAGS='-march=armv7-a -Wl,--fix-cortex-a8'
fi

if [ "$TARGET_PLATFORM" = "ios" ]; then
    if [ "$TARGET_ARCH" = "x86_64" ]; then
        ICU_HOST=x86_64-apple-darwin11
    elif [ "$TARGET_ARCH" = "i386" ]; then
        ICU_HOST=i686-apple-darwin11
    else
        ICU_HOST=arm-apple-darwin
    fi
elif [ "$TARGET_PLATFORM" = "android" ]; then
    ICU_HOST=arm-linux-androideabi
fi

echo Building ICU for $TARGET_ARCH...
[ -e Makefile ] && make distclean
sh $ICU_PATH/source/configure --host=$ICU_HOST --enable-tools=no --enable-static --disable-shared $ICU_CONFIGURE_FLAGS --prefix=$INSTALL_DIR --with-cross-build=$(pwd)/../host-build
make install -j$N_CORES

