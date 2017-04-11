# Quick Start Recipes

## Checking out the source code

The ElastosRT Git repository is located
at: https://github.com/elastos/ElastosRT

To clone the repository, assuming you setup the $SRC variable
in your environment:
```shell
$ cd ~
$ git clone https://github.com/elastos/ElastosRT
```

## Preparing the build environment

### Ubuntu

On Ubuntu this should obtain the necessary pre-reqs:
```
sudo apt-get install texinfo libglib2.0-dev autoconf libtool libsdl-dev build-essential tofrodos zlib1g-dev:amd64 zlib1g-dev:i386
sudo apt-get install bison g++-multilib git gperf libxml2-utils make zlib1g-dev:i386 zip
```
or
copy the libs under folder Build/Prebuilt/Linux/usr/lib to /lib/i386-linux-gnu/
```
sudo cp ~/ElastosRT/Build/Prebuilt/Linux/usr/lib/lib* /lib/i386-linux-gnu/

cd /lib/i386-linux-gnu/
sudo ln -s libicuuc.so.52 libicuuc.so
sudo ln -s libcrypto.so.1.0.0 libcrypto.so

```

## Build ElastosRT

### Build CAR Compiler(optional)

1. enter the build environment
```
cd ~/ElastosRT/Setup
~/ElastosRT/Setup$ source Ubuntu_SetEnv_tools.sh
```

2. build CAR tools
```
#build release version of carc
#the debug version doesn't work now
~/ElastosRT/Sources$rls
~/ElastosRT/Sources$ emake
~/ElastosRT/Sources$ pd @
```

3. build result
```
~/ElastosRT/Targets/rdk/x86.gnu.linux.devtools.dbg/bin$ ls
CInfoReader  Cls2C  carc  carcode  dbg_info  libz.so  lubc  lube  package
```

4. use your new CAR tools
copy your build result to ~/ElastosRT/Build/Tools
from ~/ElastosRT/Targets/rdk/x86.gnu.linux.devtools.dbg/bin
```
cp CInfoReader Cls2C carc carcode lubc lube libz.so ~/ElastosRT/Build/Tools/
```

5. release version or debug version
```
 rls    #It is an alias of  --> chv rls
 dbg    #It is an alias of  --> chv dbg
```

### Build Runtime

1. enter the build environment
```
cd ~/ElastosRT/Setup
~/ElastosRT/Setup$ source Ubuntu_SetEnv_RT.sh
```

2. build Runtime
```
cd ~/ElastosRT/Sources/Elastos/Runtime
~/ElastosRT/Sources/Elastos/Runtime$ emake
```

3. build result
```
~/ElastosRT/Targets/rdk/x86.gnu.linux.devtools.dbg/bin/Elastos.Runtime.eco
~/myfile/projects/ElastosRT/Targets/obj/rdk/x86.gnu.linux.devtools.dbg/lib/Elastos.Runtime.lib
```

### Build LibCore

1. enter the build environment(optional)
```
cd ~/ElastosRT/Setup
~/ElastosRT/Setup$ source Ubuntu_SetEnv_RT.sh
```

2. build LibCore
```
cd ~/ElastosRT/Sources/Elastos/LibCore
~/ElastosRT/Sources/Elastos/LibCore$ emake
```

3. build result
```
~/ElastosRT/Targets/rdk/x86.gnu.linux.devtools.dbg/bin/Elastos.CoreLibrary.eco
```

### Build Test cases

#### HelloCar

1. enter the build environment(optional)
```
cd ~/ElastosRT/Setup
~/ElastosRT/Setup$ source Ubuntu_SetEnv_RT.sh
```

2. build Elastos.HelloCar.eco
```
cd ~/ElastosRT/Sources/Elastos/LibCore/tests/HelloCar/eco
~/ElastosRT/Sources/Elastos/LibCore/tests/HelloCar/eco$ emake
```

3. build HelloCar
```
cd ~/ElastosRT/Sources/Elastos/LibCore/tests/HelloCar
~/ElastosRT/Sources/Elastos/LibCore/tests/HelloCar$ emake
```

4. build result
```
~/ElastosRT/Sources/Elastos/LibCore/tests/HelloCar$pd @
~/ElastosRT/Targets/rdk/x86.gnu.linux.devtools.dbg/bin$ll HelloCar
```

5. Run HelloCar
```
#export the path where the .eco files are stored, or you maybe get 80050000 error code
~/ElastosRT/Targets/rdk/x86.gnu.linux.devtools.dbg/bin$export LD_LIBRARY_PATH=dbg_info
~/ElastosRT/Targets/rdk/x86.gnu.linux.devtools.dbg/bin$./HelloCar
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
cd ~/ElastosRT/Setup
~/ElastosRT/Setup$ source Ubuntu_SetEnv_RT.sh
```

2. build Math test case
```
cd ~/ElastosRT/Sources/Elastos/LibCore/tests/libcore/math
~/ElastosRT/Sources/Elastos/LibCore/tests/libcore/math$ emake
```

3. build result
```
~/ElastosRT/Sources/Elastos/LibCore/tests/libcore/math$pd @
~/ElastosRT/Targets/rdk/x86.gnu.linux.devtools.dbg/bin$ll testMath
```

4. Run testMath
```
#export the path where the .eco files are stored,  or you maybe get 80050000 error code
~/ElastosRT/Targets/rdk/x86.gnu.linux.devtools.dbg/bin$export LD_LIBRARY_PATH=dbg_info
~/ElastosRT/Targets/rdk/x86.gnu.linux.devtools.dbg/bin$./testMath

```
