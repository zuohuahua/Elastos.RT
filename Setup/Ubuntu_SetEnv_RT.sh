#!/usr/bin/env bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

export _ELASTOS64=YES
source $SCRIPT_DIR/SetEnv.sh gcc_devtools
export LD_LIBRARY_PATH=.
export XDK_TARGET_PRODUCT=
