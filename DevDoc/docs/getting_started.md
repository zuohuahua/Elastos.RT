# Quick Start Recipes

## Checking out the source code

The Elastos.RT Git repository is located
at: https://github.com/elastos/Elastos.RT

To clone the repository
in your environment:
```shell
$ cd ~
$ git clone --recurse-submodules https://github.com/elastos/Elastos.RT
```

We use `--recurse-submodules` here because we need to download the submodules as well.
If you forgot to use the argument, you could download the submodules later by typing:

```shell
$ git submodule init
$ git submodule update
```

## Preparing the build environment

Please select the appropriate compilation environment as needed:

* ### Use dockerized build environment

  If you have `docker` and `docker-compose` installed in your machine, you could use a dockerized build environment.

  You should follow the official instructions to install Docker and Docker Compose.
  
  Install Docker: https://docs.docker.com/install/
  
  Install Docker Compose: https://docs.docker.com/compose/install/

  To build the docker image and enter the dockerized build environment:
  ```
  $ cd ~/Elastos.RT/docker
  ~/Elastos.RT/docker$ docker-compose build --build-arg HOST_USER_UID=`id -u` --build-arg HOST_USER_GID=`id -g` build-env
  ~/Elastos.RT/docker$ docker-compose run --rm build-env
  ```
  NOTE: Please do NOT store any important files outside of the `Elastos.RT` folder as the docker container will be removed after you exit the building environment. And only the changes in the `Elastos.RT` folder will be retained as it has defined as a VOLUME in the Dockerfile.

  Type `exit` if you want to exit the docker build environment. And type `docker-compose run --rm build-env` if you want to re-enter it.

* ### Ubuntu_32bit

  On Ubuntu this should obtain the necessary pre-reqs:
  ```
  sudo dpkg --add-architecture i386
  sudo apt-get update
  sudo apt-get install texinfo libglib2.0-dev autoconf libtool libsdl-dev build-essential tofrodos bison g++-multilib git gperf
  sudo apt-get install libxml2-utils make bc zip zlib1g-dev zlib1g-dev:i386 libicu-dev libicu-dev:i386 libssl-dev libssl-dev:i386
  ```
  or
  copy the libs under folder Build/Prebuilt/Linux/usr/lib to /lib/i386-linux-gnu/
  ```
  sudo cp ~/Elastos.RT/Build/Prebuilt/Linux/usr/lib/lib* /lib/i386-linux-gnu/

  cd /lib/i386-linux-gnu/
  sudo ln -s libicuuc.so.52 libicuuc.so
  sudo ln -s libcrypto.so.1.0.0 libcrypto.so

  ```

* ### Ubuntu_64bit

  On Ubuntu this should obtain the necessary pre-reqs:
  ```
  sudo apt-get install texinfo libglib2.0-dev autoconf libtool libsdl-dev build-essential tofrodos zlib1g-dev:amd64 zlib1g-dev
  sudo apt-get install bison g++-multilib git gperf libxml2-utils make zlib1g-dev:i386 zip libsqlite3-dev libicu-dev libssl-dev
  ```

* ### IOS
 
  1.Install homebrew（https://brew.sh/）

  ```
  $ /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
  ```

  2.Install cmake

  ```
  $ brew install cmake
  ```

  3.Install Xcode and Check Xcode path

  Please search Xcode in AppStore and install it.
  
  ```
  $ /usr/bin/xcode-select -print-path
  ```

  if the result is not “/Applications/Xcode.app/Contents/Developer”，then 
  ```
  $ sudo xcode-select --switch /Applications/Xcode.app
  ```

  4.Install simulator in Xcode

  Xcode->Preferences->Components, install iOS 11.1 Simulator


## Build Elastos.RT

### Build Android

* Download NDK and execute script to generate NDK toolchain:

***The compiling of android-version RT needs to install NDK toolchain, you can refer to [Install NDK](https://github.com/elastos/Elastos.RT/blob/master/ToolChains/android/Readme.md),then you can  contiune it.***

1. enter the build environment:
```
$ source ~/Elastos.RT/Setup/SetEnv.sh arm_android
or
$ source ~/Elastos.RT/Setup/SetEnv.sh
then choose the index number of _arm_android_ item from the numbered list
```

2. emake
```
~/Elastos.RT/Sources$ emake
```

### Build Linux

1. enter the build environment:
```
$ source ~/Elastos.RT/Setup/SetEnv.sh linux
or
$ source ~/Elastos.RT/Setup/SetEnv.sh
then choose the index number of index number of _linux_ item from the numbered list
```

2. emake
```
~/Elastos.RT/Sources$ emake
```

### Build IOS

1. enter the build environment:
```
$ source ~/Elastos.RT/Setup/SetEnv.sh ios_simulator64 (or ios_device)

or
$ source ~/Elastos.RT/Setup/SetEnv.sh
then choose the index number of index number of _linux_ item from the numbered list
```

2. emake
```
~/Elastos.RT/Sources$ emake
```