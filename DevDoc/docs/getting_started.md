# Quick Start Recipes

## Checking out the source code

The Elastos.RT Git repository is located
at: https://github.com/elastos/Elastos.RT

To clone the repository
in your environment:
```shell
$ cd ~
$ git clone https://github.com/elastos/Elastos.RT
```

## Preparing the build environment

### Use dockerized build environment

If you have `docker` and `docker-compose` installed in your machine, you could use a dockerized build environment.

To build the docker image and enter the dockerized build environment:
```
$ cd ~/Elastos.RT/docker
~/Elastos.RT/docker$ docker-compose build --build-arg HOST_USER_UID=`id -u` --build-arg HOST_USER_GID=`id -g` build-env
~/Elastos.RT/docker$ docker-compose run --rm build-env
```
NOTE: Please do NOT store any important files outside of the `Elastos.RT` folder as the docker container will be removed after you exit the building environment. And only the changes in the `Elastos.RT` folder will be retained as it has defined as a VOLUME in the Dockerfile.

### Ubuntu

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

## Build Elastos.RT

### Build CAR Compiler(optional)

1. enter the build environment
```
$ source ~/Elastos.RT/Setup/Ubuntu_SetEnv_tools.sh
```

2. build CAR tools
```
#build release version of carc
~/Elastos.RT/Sources$ rls
~/Elastos.RT/Sources$ emake
~/Elastos.RT/Sources$ pd @
```

3. build result
```
~/Elastos.RT/Targets/rdk/x86.gnu.linux.devtools.rls/bin$ ls
CInfoReader  Cls2C  carc  carcode  dbg_info  libz.so  lubc  lube  package
```

4. use your new CAR tools
copy your build result to ~/Elastos.RT/Build/Tools
from ~/Elastos.RT/Targets/rdk/x86.gnu.linux.devtools.rls/bin
```
cp CInfoReader Cls2C carc carcode lubc lube libz.so ~/Elastos.RT/Build/Tools/
```

5. release version or debug version
```
 rls    #It is an alias of  --> chv rls
 dbg    #It is an alias of  --> chv dbg
```

### Build Runtime

1. enter the build environment
```
$ source ~/Elastos.RT/Setup/Ubuntu_SetEnv_RT.sh
```

2. build Runtime
```
cd ~/Elastos.RT/Sources/Elastos/Runtime
~/Elastos.RT/Sources/Elastos/Runtime$ emake
```

3. build result
```
~/Elastos.RT/Targets/rdk/x86.gnu.linux.devtools.dbg/bin/Elastos.Runtime.eco
~/myfile/projects/Elastos.RT/Targets/obj/rdk/x86.gnu.linux.devtools.dbg/lib/Elastos.Runtime.lib
```

### Build LibCore

1. enter the build environment(optional)
```
$ source ~/Elastos.RT/Setup/Ubuntu_SetEnv_RT.sh
```

2. build LibCore
```
cd ~/Elastos.RT/Sources/Elastos/LibCore
~/Elastos.RT/Sources/Elastos/LibCore$ emake
```

3. build result
```
~/Elastos.RT/Targets/rdk/x86.gnu.linux.devtools.dbg/bin/Elastos.CoreLibrary.eco
```

### Build Test cases

#### HelloCar

1. enter the build environment(optional)
```
$ source ~/Elastos.RT/Setup/Ubuntu_SetEnv_RT.sh
```

2. build Elastos.HelloCar.eco
```
cd ~/Elastos.RT/Sources/Elastos/LibCore/tests/HelloCar/eco
~/Elastos.RT/Sources/Elastos/LibCore/tests/HelloCar/eco$ emake
```

3. build HelloCar
```
cd ~/Elastos.RT/Sources/Elastos/LibCore/tests/HelloCar
~/Elastos.RT/Sources/Elastos/LibCore/tests/HelloCar$ emake
```

4. build result
```
~/Elastos.RT/Sources/Elastos/LibCore/tests/HelloCar$ pd @
~/Elastos.RT/Targets/rdk/x86.gnu.linux.devtools.dbg/bin$ ll HelloCar
```

5. Run HelloCar
```
# Run the executable inside the dbg_info directory if you want to debug it with debug symbols
# We have already "export LD_LIBRARY_PATH=.". So, it will load the *.eco files inside the current directory
~/Elastos.RT/Targets/rdk/x86.gnu.linux.devtools.dbg/bin$ cd dbg_info
~/Elastos.RT/Targets/rdk/x86.gnu.linux.devtools.dbg/bin/dbg_info$ ./HelloCar
==================================
=========== Hello Car ============
==================================
Though cat has nine lives, but it can not fly!
Kitty can not fly!

FILE: Animal.cpp, LINE: 51, INFO: > Animal::constructor(2, HuaHua)

HuaHua : wang! wang!
HuaHua can not fly!

Though cat has nine lives, but it can not fly!
CAnimalHelper::CanFly : Kitty can not fly!

=========== Exit Hello Car ============
```

#### Math

1. enter the build environment(optional)
```
$ source ~/Elastos.RT/Setup/Ubuntu_SetEnv_RT.sh
```

2. build Math test case
```
cd ~/Elastos.RT/Sources/Elastos/LibCore/tests/libcore/math
~/Elastos.RT/Sources/Elastos/LibCore/tests/libcore/math$ emake
```

3. build result
```
~/Elastos.RT/Sources/Elastos/LibCore/tests/libcore/math$ pd @
~/Elastos.RT/Targets/rdk/x86.gnu.linux.devtools.dbg/bin$ ll testMath
```

4. Run testMath
```
# Run the executable inside the dbg_info directory if you want to debug it with debug symbols
# We have already "export LD_LIBRARY_PATH=.". So, it will load the *.eco files inside the current directory
~/Elastos.RT/Targets/rdk/x86.gnu.linux.devtools.dbg/bin$ cd dbg_info
~/Elastos.RT/Targets/rdk/x86.gnu.linux.devtools.dbg/bin/dbg_info$ ./testMath
```
