# Tips for build process

## How to install icu library(32bit) on ubuntu

Install the icu library with version 52, and find the location where the *.so installed.
```
$ sudo apt-get install libicu52:i386
$ dpkg -L libicu52:i386
```
Copy the needed libs to /usr/lib/i386-linux-gnu/


Issue Handling
1. /usr/bin/ld: cannot find xxx.map: No such file or directory
    export PREBUILD_LIB=xxxxx/ElastosRT/Build/Prebuilt/Linux/usr/lib

## Which config decide the ElastosRT 32 bits version or 64 bits version

It is decided with 32B_FLAGS in file $/ElastosRT/Build/Makefiles/makedefs_gnu_rdk.mk
```
ifeq "$(32B_FLAGS)" ""
  32B_FLAG = -m32
endif
```
If you want to make 64 bits version ElastosRT on Ubuntu 64bit, remove these statements.

