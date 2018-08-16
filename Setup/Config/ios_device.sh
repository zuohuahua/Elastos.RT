export XDK_TARGET_PLATFORM=ios
export XDK_COMPILER=llvm

export XDK_TARGET_CPU=arm
if [[ ! "$_ELASTOS64" == "" ]]; then
    export XDK_TARGET_CPU_ARCH=64
else
    export XDK_TARGET_CPU_ARCH=32
fi

export CMAKE_ARGS=-DIOS_PLATFORM=OS

