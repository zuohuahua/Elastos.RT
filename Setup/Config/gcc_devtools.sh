export XDK_TARGET_PLATFORM=linux
export XDK_TARGET_CPU=x86
if [[ ! "$_ELASTOS64" == "" ]]; then
    export XDK_TARGET_CPU_ARCH=64
else
    export XDK_TARGET_CPU_ARCH=32
fi
export XDK_COMPILER=gnu
#export XDK_TARGET_BOARD=pc
export XDK_TARGET_PRODUCT=devtools
export XDK_TARGET_FORMAT=elf
