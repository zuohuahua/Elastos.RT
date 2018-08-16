#!/bin/bash

# Exit immediately if a subsequent command exits with a non-zero status.
set -e

THIS_SCRIPT=$(basename $0)
usage()
{
    cat << EOF

The script to build openssl for various platforms.

Usage: ${THIS_SCRIPT} [options]

Options:
  -h, --help
      Print this message

  --target-platform <TARGET_PLATFORM>
      "TARGET_PLATFORM" is the target platform. e.g. ios or android

  --ndk-toolchain <NDK_TOOLCHAIN>
      "NDK_TOOLCHAIN" is the ndk-toolchain directory.

  --ndk-toolchain-basename <NDK_TOOLCHAIN_BASENAME>
      "NDK_TOOLCHAIN_BASENAME" is the base name of the ndk-toolchain compiler.

  --cross-cc <CROSS_CC>
      "CROSS_CC" is the c compiler for cross-compilation.

  --ios-cross-top <IOS_CROSS_TOP>
      "IOS_CROSS_TOP" is the top directory of the cross compile toolchain for iOS.

  --ios-cross-sdk <IOS_CROSS_SDK>
      "IOS_CROSS_SDK" is the SDK name of the cross compile toolchain for iOS.

  --ssl-config-options <SSL_CONFIG_OPTIONS>
      "SSL_CONFIG_OPTIONS" is the additional config options for OpenSSL.

  --ssl-library-suffix <SSL_LIBRARY_SUFFIX>
      "SSL_LIBRARY_SUFFIX" is the shared library suffix for OpenSSL.

  --install-dir <INSTALL_DIR>
      "INSTALL_DIR" is the installation directory.
EOF

}

# Default values
INSTALL_DIR=./install
SSL_LIBRARY_SUFFIX=so

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
    --target-platform)
        TARGET_PLATFORM="$2"
        shift;shift;; # past argument and value
    --ndk-toolchain)
        NDK_TOOLCHAIN="$2"
        shift;shift;; # past argument and value
    --ndk-toolchain-basename)
        NDK_TOOLCHAIN_BASENAME="$2"
        shift;shift;; # past argument and value
    --cross-cc)
        CROSS_CC="$2"
        shift;shift;; # past argument and value
    --ios-cross-top)
        IOS_CROSS_TOP="$2"
        shift;shift;; # past argument and value
    --ios-cross-sdk)
        IOS_CROSS_SDK="$2"
        shift;shift;; # past argument and value
    --ssl-config-options)
        SSL_CONFIG_OPTIONS="$2"
        shift;shift;; # past argument and value
    --ssl-library-suffix)
        SSL_LIBRARY_SUFFIX="$2"
        shift;shift;; # past argument and value
    --install-dir)
        INSTALL_DIR="$2"
        shift;shift;; # past argument and value
    *)    # unknown option
        echo "Unknown option: $key"
        usage
        exit 1
        ;;
esac
done


if [ "$TARGET_PLATFORM" = "android" ]; then
    export PATH=${NDK_TOOLCHAIN}/bin:$PATH
    export CC=$NDK_TOOLCHAIN_BASENAME-clang
    export CXX=$NDK_TOOLCHAIN_BASENAME-clang++
    export LINK=${CXX}
    export LD=$NDK_TOOLCHAIN_BASENAME-ld
    export AR=$NDK_TOOLCHAIN_BASENAME-ar
    export RANLIB=$NDK_TOOLCHAIN_BASENAME-ranlib
    export STRIP=$NDK_TOOLCHAIN_BASENAME-strip
    OPENSSL_PLATFORM=linux-generic32
    SSL_CONFIG_OPTIONS="shared $SSL_CONFIG_OPTIONS"
elif [ "$TARGET_PLATFORM" = "ios" ]; then
    export CC=$CROSS_CC
    export CROSS_TOP=$IOS_CROSS_TOP
    export CROSS_SDK=$IOS_CROSS_SDK
    OPENSSL_PLATFORM=iphoneos-cross
fi


./Configure $OPENSSL_PLATFORM $SSL_CONFIG_OPTIONS --prefix=$INSTALL_DIR

make CALC_VERSIONS="SHLIB_COMPAT=; SHLIB_SOVER=" all
mkdir -p $INSTALL_DIR/lib
echo "place-holder make target for avoiding symlinks" > "$INSTALL_DIR/lib/link-shared"
make CALC_VERSIONS="SHLIB_COMPAT=; SHLIB_SOVER=" SHLIB_EXT=.$SSL_LIBRARY_SUFFIX install_sw
rm $INSTALL_DIR/lib/link-shared

