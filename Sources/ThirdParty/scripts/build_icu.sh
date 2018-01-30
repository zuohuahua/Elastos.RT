#!/bin/bash

if [ $# -ne 6 ]; then
    echo "usage: $(basename $0) icu_path icu_prefix cxx cc sdk_root arch"
    exit 1
fi

ICU_PATH=$1
ICU_PREFIX=$2

# build for host
echo Building ICU for host...
mkdir -p host-build && cd host-build
[ -e Makefile ] && make distclean
sh $ICU_PATH/source/configure
gnumake
cd ..

export CXX=$3
export CC=$4
SDKROOT=$5
ARCH=$6

# cross build
mkdir -p cross-build && cd cross-build

ICU_FLAGS="-I$ICU_PATH/source/common/ -I$ICU_PATH/source/tools/tzcode/ "

export CFLAGS="-isysroot $SDKROOT -I$SDKROOT/usr/include/ -I./include/ -arch $ARCH -miphoneos-version-min=7.0 $ICU_FLAGS"
export CXXFLAGS="-stdlib=libc++ -std=c++11 -arch $ARCH -isysroot $SDKROOT -I$SDKROOT/usr/include/ -I./include/ -miphoneos-version-min=7.0 $ICU_FLAGS"
export LDFLAGS="-stdlib=libc++ -L$SDKROOT/usr/lib/ -isysroot $SDKROOT -Wl,-dead_strip -miphoneos-version-min=7.0 -lstdc++"

if [ "$ARCH" = "x86_64" ] || [ "$ARCH" = "i386" ]; then
    ICU_HOST=i686-apple-darwin11
else
    ICU_HOST=arm-apple-darwin
fi

echo Building ICU for $ARCH...
[ -e Makefile ] && make distclean
sh $ICU_PATH/source/configure --host=$ICU_HOST --enable-tools=no --enable-static --disable-shared --prefix=$ICU_PREFIX --with-cross-build=$(pwd)/../host-build
gnumake -j4 install

