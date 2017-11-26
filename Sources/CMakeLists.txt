
cmake_minimum_required(VERSION 2.8)

include($ENV{XDK_COMMON_CMAKE})

xdk_add_subdirectories(
    Elastos/Runtime/Library/inc
    External/zlib
    Elastos/Runtime/Library/clsmodule
    ToolChains
)
