if [[ $OSTYPE == *darwin* ]]; then
    export XDK_TARGET_PLATFORM=mac
    export XDK_COMPILER=llvm
else
    export XDK_TARGET_PLATFORM=linux
    export XDK_COMPILER=gnu
fi

export XDK_TARGET_CPU=x86
if [[ ! "$_ELASTOS64" == "" ]]; then
    export XDK_TARGET_CPU_ARCH=64
else
    export XDK_TARGET_CPU_ARCH=32
fi

export LD_LIBRARY_PATH=.
