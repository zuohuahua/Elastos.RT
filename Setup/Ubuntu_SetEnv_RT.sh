#!/usr/bin/env bash
export _ELASTOS64=YES
source ./SetEnv.sh gcc_devtools
export LD_LIBRARY_PATH=$XDK_TARGETS/dbg_info:$XDK_BUILD_PATH/Tools
