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
```

## Build ElastosRT

1. enter the build environment
```
cd ~/ElastosRT/Setup
~/ElastosRT/Setup$ source Ubuntu_SetEnv_tools.sh
```

2. build CAR tools
```
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
cp CInfoReader Cls2C carc carcode lubc lube ~/ElastosRT/Build/Tools/
```

5. release version or debug version
```
 rls    #It is an alias of  --> chv rls
 dbg    #It is an alias of  --> chv dbg
```
