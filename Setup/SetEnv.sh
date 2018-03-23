#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
setupArg=$1

#The arg is NULL, give user a choice.
if [ "$1" == "" ]; then
    PS3='Please enter your choice: '
    options=("linux" "arm_android" "devtools_32" "host_devtools" "devtools_64" "ios_simulator64" "ios_device" "linux_32" "quit")
    select opt in "${options[@]}"
    do
        case $opt in
            "linux")
                setupArg="linux"
                break;;
            "arm_android")
                setupArg="arm_android"
                break;;
            "devtools_32")
                setupArg="devtools_32"
                break;;
            "host_devtools")
                setupArg="host_devtools"
                break;;
            "devtools_64")
                setupArg="devtools_64"
                break;;
            "ios_simulator64")
                setupArg="ios_simulator64"
                break;;
            "ios_device")
                setupArg="ios_device"
                break;;
            "linux_32")
                setupArg="linux_32"
                break;;
            "quit")
                return;;
            *) echo "Invalid option";;
        esac
    done
fi

case $setupArg in
    "linux" | '1')
        setupArg="linux"
        export _ELASTOS64=YES;;
    "arm_android" | '2')
        setupArg="arm_android";;
    "devtools_32" | '3')
        setupArg="gcc_devtools"
        export _ELASTOS64=;;
    "host_devtools" | '4')
        setupArg="host_devtools"
        export _ELASTOS64=YES;;
    "devtools_64" | '5')
        setupArg="gcc_devtools"
        export _ELASTOS64=YES;;
    "ios_simulator64" | '6')
        setupArg="ios_simulator"
        export _ELASTOS64=YES;;
    "ios_device" | '7')
        setupArg="ios_device"
        export _ELASTOS64=YES;;
    "linux_32" | '8')
        setupArg="linux"
        export _ELASTOS64=;;
    *)
        echo "Invalid option"
        return;;
esac


if [ "$setupArg" == '-h' ]; then
    echo Usage
    echo
    echo
    echo
    echo
    echo
    echo
    echo
    echo
    exit
else
    ################################################################################
    # Set DevKit path

    if [ ! $OS_PATH ]; then
        export OS_PATH=$PATH:
    else
        export PATH=$OS_PATH:
    fi

    if [ "$setupArg" == "sdk" ]; then
        export XDK_BUILD_ENV=sdk
        shift
    else
        export XDK_BUILD_ENV=rdk
    fi

    export XDK_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )/.." && pwd )"

    if [[ ! -f $XDK_ROOT/Setup/Config/$setupArg.sh ]]; then
        echo "Error: $XDK_SETUP_PATH/Config/$setupArg.sh is not exist."
        unset XDK_BUILD_ENV XDK_ROOT
        return
    fi
    ################################################################################
    # Clean WINDOWS path
    source $XDK_ROOT/Setup/CleanEnv.sh

    export XDK_SETUP_PATH=$XDK_ROOT/Setup
    export XDK_BUILD_PATH=$XDK_ROOT/Build
    export XDK_SOURCE_PATH=$XDK_ROOT/Sources
    export XDK_TARGETS_PATH=$XDK_ROOT/Targets
    export XDK_TEMP=$XDK_TARGETS_PATH/Temp

    ################################################################################
    # Set user defined environment variables if the user config file exist
        source $XDK_SETUP_PATH/Config/$setupArg.sh

        # Set command and build-tool lookup path
        if [ "$XDK_BUILD_TOOL" == "cmake" ]; then
            export XDK_TOOLS=$XDK_BUILD_PATH/Tools
            [[ $OSTYPE == *linux* ]] && export PATH=$XDK_TOOLS/linux:$PATH
            [[ $OSTYPE == *darwin* ]] && export PATH=$XDK_TOOLS/mac:$PATH
        else
            export XDK_TOOLS=$XDK_BUILD_PATH/Tools_64
        fi

        if [[ "$_ELASTOS64" == "" ]]; then
            export XDK_TOOLS=$XDK_BUILD_PATH/Tools_32
        fi

        #export XDK_COMMANDES=$XDK_ROOT/Commandes
        export PATH=.:$XDK_TOOLS:$PATH:
        #export PATH=.:$XDK_TOOLS:$XDK_COMMANDES:

        # Set user defined environment variables if the user config file exists
        if [ -f  $XDK_ROOT/Setup/UserDefined.sh ]; then
            source $XDK_ROOT/Setup/UserDefined.sh
        fi

        if [ -z $2 ]; then
            export XDK_TARGET_HARDWARE=generic
        else
            export XDK_TARGET_HARDWARE=$2
        fi

        if [ ! -f $XDK_SETUP_PATH/Config/$XDK_TARGET_HARDWARE.sh ]; then
            echo
            echo "Error: $XDK_SETUP_PATH/Config/$XDK_TARGET_HARDWARE.sh doesn't exist."
        else
            source $XDK_SETUP_PATH/Config/$XDK_TARGET_HARDWARE.sh

            source $XDK_TOOLS/env_tools.sh

            if [ -z "$XDK_VERSION" ]; then
                export XDK_VERSION=dbg
            fi

            # Finally add Ubuntu System to the path, so we could use system tools
            PATH_LIST=${PATH//\:/ }
            for line in $PATH_LIST; do
                #if [ ! `echo $line | grep \/android\/` ]; then
                    if [ -z "$PATH_FILTEROUT_ANDROID" ]; then
                       PATH_FILTEROUT_ANDROID="$line"
                    else
                       PATH_FILTEROUT_ANDROID="$PATH_FILTEROUT_ANDROID:$line"
                    fi
                #fi
            done

            export PATH=$PATH_FILTEROUT_ANDROID
            export XDK_GENERAL_PATH=$PATH_FILTEROUT_ANDROID

            unset PATH_LIST
            unset PATH_FILTEROUT_ANDROID

            chv $XDK_VERSION

            cd $XDK_SOURCE_PATH

            #set title
            PS1_RESET='\[\e[0m\]' # Text Reset

            if [[ ! "$_ELASTOS64" == "" ]]; then
                PS1_COLOR='\[\e[0;32m\]' # Green
            else
                PS1_COLOR='\[\e[0;33m\]' # Yellow
            fi

            TITLE='$XDK_TARGET_PLATFORM-${XDK_TARGET_CPU}_$XDK_TARGET_CPU_ARCH.$XDK_COMPILER-'
            TITLE+='${XDK_TARGET_PRODUCT:+$XDK_TARGET_PRODUCT-}'
            TITLE+='${XDK_BUILD_TOOL:+$XDK_BUILD_TOOL.}'
            TITLE+='$XDK_VERSION'

            export PS1="\[\e]0;$TITLE \w\a\]\n\${debian_chroot:+(\$debian_chroot) }${PS1_COLOR}\${XDK_TARGET_CPU}_\$XDK_TARGET_CPU_ARCH.\$XDK_VERSION \w${PS1_RESET}\n$ "

            unset PS1_RESET
            unset PS1_COLOR
            unset TITLE
            #clear
        fi
fi
