#!/bin/bash

change_version ()
{
    if [ "$1" == "dbg" ]; then
        export XDK_VERSION=dbg
    fi
    if [ "$1" == "rls" ]; then
        export XDK_VERSION=rls
    fi
    reset_env
}

reset_env ()
{
   export PATH=$XDK_GENERAL_PATH

   unset DEBUG_INFO
   if [ ! "$XDK_VERSION" == "rls" ]; then
       export DEBUG_INFO=1
   fi

   # Set target object environment variables
   XDK_BUILD_KIND=${XDK_TARGET_CPU}_$XDK_TARGET_CPU_ARCH.$XDK_COMPILER.$XDK_TARGET_PLATFORM.
   XDK_BUILD_KIND+=${XDK_TARGET_PRODUCT:+$XDK_TARGET_PRODUCT.}
   XDK_BUILD_KIND+=${debian_chroot:+$debian_chroot.}
   XDK_BUILD_KIND+=$XDK_VERSION
   export XDK_BUILD_KIND

   export XDK_USER_OBJ=$XDK_TARGETS_PATH/obj
   export XDK_USER_INC=$XDK_USER_OBJ/$XDK_BUILD_KIND/inc
   export XDK_USER_LIB=$XDK_USER_OBJ/$XDK_BUILD_KIND/lib
   export XDK_TARGETS=$XDK_USER_OBJ/$XDK_BUILD_KIND/bin
   export TARGET_PACK_PATH=$XDK_TARGETS/package

   if [ "$XDK_BUILD_ENV" == "sdk" ]; then
       export XDK_INC_PATH=$XDK_BUILD_PATH/Prebuilt/RDK/$XDK_BUILD_KIND/inc
       export XDK_LIB_PATH=$XDK_BUILD_PATH/Prebuilt/RDK/$XDK_BUILD_KIND/lib
   fi

   if [ "$XDK_BUILD_ENV" == "sdk" ]; then
       export PATH=$PATH:$XDK_LIB_PATH:$XDK_TARGETS
   else
       export PATH=$PATH:$XDK_TARGETS
   fi
}

function pd ()
{
    case "$1" in
        "-h")
            echo "usage: pd DIR     (same as PUSHD DIR)"
            echo "       pd         (same as POPD)"
            echo "       pd m       (PUSHD to mirror directory)"
            echo "       pd @       (PUSHD to target directory)"
            echo "       pd inc     (PUSHD to compiled INC directory)"
            echo "       pd lib     (PUSHD to compiled LIB directory)"
            echo "       pd p       (PUSHD to compiled EPK directory)"
        ;;
        "")
            popd
        ;;
        "@")
            pushd $XDK_TARGETS 1>/dev/null
        ;;
        "inc" | "lib")
            pushd $XDK_USER_OBJ/$XDK_BUILD_KIND/$1 1>/dev/null
        ;;
        "p")
            pushd $TARGET_PACK_PATH 1>/dev/null
        ;;
        "m")
            local PROJECT_DIR=$PWD
            local XDK_EMAKE_DIR=${PWD/$XDK_SOURCE_PATH/}
            pushd $XDK_USER_OBJ/$XDK_BUILD_KIND/mirror$XDK_EMAKE_DIR 1>/dev/null
        ;;
        *)
            pushd $1 1>/dev/null
        ;;
    esac
}

function chv ()
{
    case "$1" in
        "-h")
            echo "Version:"
            echo "  dbg   "
            echo "  rls   "
        ;;
        "dbg" | "opt" | "pre" | "rls")
            change_version $1
        ;;
        *)
            echo "Error: No version matched."
        ;;
    esac
}

function emake ()
{
    if [ "$XDK_TOOLS" == "" ]; then
        echo "Error# Environment variables XDK_TOOLS not export."
    elif [ "$XDK_TARGET_CPU" == "" ]; then
        echo "Error# Environment variables XDK_TARGET_CPU not export."
    elif [ "$XDK_COMPILER" == "" ]; then
        echo "Error# Environment variables XDK_COMPILER not export."
    else
        # Get the current build path
        local PROJECT_DIR=$PWD

        # Initialize the checking flag
        local XDK_CHECK_ERROR=

        # Skip directory checking result while clobbering or cleaning
        if [ "$1" == "clobber" ]; then
            local XDK_CHECK_ERROR=
        fi

        #Set XDK_EMAKE_DIR
        if [ ! "$XDK_EMAKE_DIR" == "" ]; then
            unset XDK_EMAKE_DIR
        fi
        if [ ! "$XDK_SOURCE_PATH" == "$PWD" ]; then
            export XDK_EMAKE_DIR=/${PWD/$XDK_SOURCE_PATH\//}
            if [ "$XDK_EMAKE_DIR" == "/$PWD" ]; then
                XDK_CHECK_ERROR=1
            fi
        fi

        # Judge whether continue the building process or not
        if [ ! $XDK_CHECK_ERROR == "" ]; then
                unset XDK_EMAKE_DIR
                echo "Error: Can't build here. Please go to the project relative directory."
        else
            # Set verbose mode if -v is specified
            if [ "$1" == "/v" ]; then
                export BUILD_VERBOSE=1
                shift
            elif [ "$1" == "-v" ]; then
                export BUILD_VERBOSE=1
                shift
            fi
            # Set test coverage mode if -c is specified
            if [ "$1" == "/c" ]; then
                export TEST_COVERAGE=1
                shift
            elif [ "$1" == "-c" ]; then
                export TEST_COVERAGE=1
                shift
            fi

            if [ "$BUILD_VERBOSE" == "" ]; then
                export XDK_MAKE='make -s'
            else
                export XDK_MAKE='make VERBOSE=1'
            fi

            export XDK_CMAKE_DIR=$XDK_BUILD_PATH/CMake
            export XDK_DEFINITIONS_CMAKE=$XDK_CMAKE_DIR/definitions.cmake
            export XDK_COMMON_CMAKE=$XDK_CMAKE_DIR/common.cmake
            if [ -f $XDK_CMAKE_DIR/$XDK_TARGET_PLATFORM.toolchain.cmake ]; then
                CMAKE_ARGS="$CMAKE_ARGS -DCMAKE_TOOLCHAIN_FILE=$XDK_CMAKE_DIR/$XDK_TARGET_PLATFORM.toolchain.cmake"
            elif [ "$XDK_TARGET_PLATFORM" == "android" ]; then
                if [ -z "$ANDROID_NDK" ] ||
                   [ -f $ANDROID_NDK/source.properties ] && [ "$(sed -En -e 's/^Pkg.Revision\s*=\s*([0-9]+).*/\1/p' $ANDROID_NDK/source.properties)" -lt "15" ]; then
                    echo "Could not find Android NDK (r15c or newer)."
                    echo "    You should set an environment variable:"
                    echo "      export ANDROID_NDK=~/my-android-ndk"
                    return 1
                elif [ -f $ANDROID_NDK/build/cmake/android.toolchain.cmake ]; then
                    CMAKE_ARGS="$CMAKE_ARGS -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake"
                else
                    echo "Could not find $ANDROID_NDK/build/cmake/android.toolchain.cmake"
                    echo "We only support Android NDK r15c or newer version."
                    echo "    Please set the environment variable properly:"
                    echo "      export ANDROID_NDK=~/my-android-ndk"
                    return 1
                fi
            fi

            local MIRROR_ROOT_DIR=$XDK_USER_OBJ/$XDK_BUILD_KIND/mirror
            local MIRROR_DIR=$MIRROR_ROOT_DIR$XDK_EMAKE_DIR
            BUILD_EXIT_CODE=0
            if [ ! "${1%.car}" == "$1" ]; then
                carc -i -c ${1%.car}.cls $1
                if [ "$?" == "0" ]; then
                    if [ "$XDK_PACKAGE" == "sdk" ]; then
                       if [ -z "$INTERNAL_SDK" ]; then
                         lube -C ${1%.car}.cls -s -T foreground
                       else
                         lube -C ${1%.car}.cls -T foreground
                       fi
                    else
                        lube -C ${1%.car}.cls -T foreground
                    fi
                fi
                if [ -f ${1%.car}.cls ]; then
                    rm -f ${1%.car}.cls
                fi
            elif [ "$1" == "c2j" ]; then
                if [ ! "${2%.car}" == "$2" ]; then
                    carc -i -c ${2%.car}.cls $2
                    if [ ! "$?" == "0" ]; then
                        return
                    fi
                    lube -B $XDK_TOOLS/CAR2Javalube.lbo -C ${2%.car}.cls -T CAR2Java
                    if [ -f ${2%.car}.cls ]; then
                        rm -f ${2%.car}.cls
                    fi
                fi
            elif [[ "$1" == "clobber" && "$2" == "--all" ]]; then
                echo "Clobber all..."
                rm -rf $XDK_USER_OBJ/
            elif [ "$1" == "clobber" ]; then
                echo "Clobber..."
                rm -rf $XDK_USER_OBJ/$XDK_BUILD_KIND
            elif [ "$1" == "gen" ]; then
                echo "Re-generating makefiles..."
                mkdir -p $MIRROR_ROOT_DIR 1>/dev/null
                (cd $MIRROR_ROOT_DIR && cmake -G"Unix Makefiles" $CMAKE_ARGS $XDK_SOURCE_PATH)
            else
                if [ ! -f "$MIRROR_DIR/CMakeFiles/CMakeDirectoryInformation.cmake" ]; then
                    echo 'Generating makefiles...'
                    mkdir -p $MIRROR_ROOT_DIR 1>/dev/null
                    (cd $MIRROR_ROOT_DIR && cmake -G"Unix Makefiles" $CMAKE_ARGS $XDK_SOURCE_PATH)
                fi

                # prepare target directories
                mkdir -p $MIRROR_DIR 1>/dev/null
                mkdir -p $XDK_TARGETS 1>/dev/null
                mkdir -p $XDK_USER_INC 1>/dev/null
                mkdir -p $XDK_USER_LIB 1>/dev/null
                mkdir -p $XDK_USER_OBJ 1>/dev/null

                if [ "$DISABLE_EMAKE_TIMES" == "1" ]; then
                    (cd $MIRROR_DIR && $XDK_MAKE $1 $2 $3 $4 $5 $6)
                    BUILD_EXIT_CODE=$?
                else
                    local START_TIME=`date +%s`
                    (cd $MIRROR_DIR && $XDK_MAKE $1 $2 $3 $4 $5 $6)
                    BUILD_EXIT_CODE=$?
                    local ELAPSED_TIME=$(( `date +%s`-$START_TIME ))
                    local HOURS=`echo $ELAPSED_TIME/3600 | bc`
                    local MINUTES=`echo $ELAPSED_TIME/60%60 | bc`
                    local SECONDS=`echo $ELAPSED_TIME%60 | bc`
                    echo "Build finished, elapsed time: $HOURS Hours, $MINUTES Minutes, $SECONDS Seconds."
                fi
                unset XDK_MAKE XDK_MAKEFILE XDK_EMAKE_DIR BUILD_VERBOSE TEST_COVERAGE
            fi
            if [ "$1" == "clean" ]; then
                echo "Cleaning mirror direcotory..."
                rm -rf $MIRROR_DIR 1>/dev/null
            fi
            return $BUILD_EXIT_CODE
        fi
    fi
}

alias dbg='chv dbg'
alias rls='chv rls'
alias cls='clear'
alias rm='rm -i'
alias setup='pushd $XDK_SETUP_PATH/$1 1>/dev/null'
alias tools='pushd $XDK_TOOLS/$1 1>/dev/null'
alias src='pushd $XDK_SOURCE_PATH/$1 1>/dev/null'
alias inc='pd inc 1>/dev/null'
alias lib='pd lib 1>/dev/null'

if [ -f "$XDK_TOOLS/alias_usr.sh" ]; then
    source $XDK_TOOLS/alias_usr.sh
fi
