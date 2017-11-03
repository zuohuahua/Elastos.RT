#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
setupArg=$1

#The arg is NULL, give user a choice.
if [ "$1" == "" ]; then
    PS3='Please enter your choice: '
    options=("linux" "arm_android" "devtools_32" "devtools_64" "quit")
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
            "devtools_64")
                setupArg="devtools_64"
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
    "devtools_64" | '4')
        setupArg="gcc_devtools"
        export _ELASTOS64=YES;;
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
        if [[ ! "$_ELASTOS64" == "" ]]; then
            export XDK_TOOLS=$XDK_BUILD_PATH/Tools_64
        else
            export XDK_TOOLS=$XDK_BUILD_PATH/Tools
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

            unset DEBUG_INFO

            if [ ! "$XDK_VERSION" == "rls" ]; then
                export DEBUG_INFO=1
            fi

            # Set target object environment variables
            if [ -z "$XDK_TARGET_PRODUCT" ]; then
                export XDK_BUILD_KIND=${XDK_TARGET_CPU}_$XDK_TARGET_CPU_ARCH.$XDK_COMPILER.$XDK_TARGET_PLATFORM.$XDK_VERSION
            else
                export XDK_BUILD_KIND=${XDK_TARGET_CPU}_$XDK_TARGET_CPU_ARCH.$XDK_COMPILER.$XDK_TARGET_PLATFORM.$XDK_TARGET_PRODUCT.$XDK_VERSION
            fi
            export XDK_USER_OBJ=$XDK_TARGETS_PATH/obj/$XDK_BUILD_ENV
            export XDK_USER_INC=$XDK_USER_OBJ/$XDK_BUILD_KIND/inc
            export XDK_USER_LIB=$XDK_USER_OBJ/$XDK_BUILD_KIND/lib
            export XDK_TARGETS=$XDK_TARGETS_PATH/$XDK_BUILD_ENV/$XDK_BUILD_KIND/bin
            export TARGET_PACK_PATH=$XDK_TARGETS/package

            if [ "$XDK_BUILD_ENV" == "sdk" ]; then
                export XDK_INC_PATH=$XDK_BUILD_PATH/Prebuilt/RDK/$XDK_BUILD_KIND/inc
                export XDK_LIB_PATH=$XDK_BUILD_PATH/Prebuilt/RDK/$XDK_BUILD_KIND/lib
            fi

            # Finally add Ubuntu System to the path, so we could use system tools
            PATH_LIST=${PATH//\:/ }
            for line in $PATH_LIST; do
                if [ ! `echo $line | grep \/android\/` ]; then
                    if [ -z "$PATH_FILTEROUT_ANDROID" ]; then
                       PATH_FILTEROUT_ANDROID="$line"
                    else
                       PATH_FILTEROUT_ANDROID="$PATH_FILTEROUT_ANDROID:$line"
                    fi
                fi
            done

            export PATH=$PATH_FILTEROUT_ANDROID
            export XDK_GENERAL_PATH=$PATH_FILTEROUT_ANDROID

            unset PATH_LIST
            unset PATH_FILTEROUT_ANDROID

            if [ "$XDK_BUILD_ENV" == "sdk" ]; then
                export PATH=$PATH:$XDK_LIB_PATH:$XDK_TARGETS
            else
                export PATH=$PATH:$XDK_TARGETS
            fi

            cd $XDK_SOURCE_PATH

            #set title
            PS1_RESET='\[\e[0m\]' # Text Reset

            if [[ ! "$_ELASTOS64" == "" ]]; then
                PS1_COLOR='\[\e[0;32m\]' # Green
            else
                PS1_COLOR='\[\e[0;33m\]' # Yellow
            fi

            TITLE='$XDK_TARGET_PLATFORM-${XDK_TARGET_CPU}_$XDK_TARGET_CPU_ARCH.$XDK_COMPILER-${XDK_TARGET_PRODUCT:+$XDK_TARGET_PRODUCT-}$XDK_VERSION'

            export PS1="\[\e]0;$TITLE \w\a\]\n\${debian_chroot:+(\$debian_chroot) }${PS1_COLOR}\${XDK_TARGET_CPU}_\$XDK_TARGET_CPU_ARCH.\$XDK_VERSION \w${PS1_RESET}\n$ "

            unset PS1_RESET
            unset PS1_COLOR
            unset TITLE
            #clear
        fi
fi
