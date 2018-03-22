
# Build CAR Compiler

In general, you will not use it. It will be used that When you need to modify the tools.

1. enter the build environment:

* Ubuntu_32bit
  ```
  $ source ~/Elastos.RT/Setup/SetEnv.sh devtools_32
  or
  $ source ~/Elastos.RT/Setup/SetEnv.sh
  then choose the index number of "devtools_32" item from the numbered list
  ```

* Ubuntu_64bit
  ```
  $ source ~/Elastos.RT/Setup/SetEnv.sh devtools_64
  or
  $ source ~/Elastos.RT/Setup/SetEnv.sh
  then choose the index number of "devtools_64" item from the numbered list
  ```

* host_devtools:linux or mac
  ```
  $ source ~/Elastos.RT/Setup/SetEnv.sh host_devtools
  or
  $ source ~/Elastos.RT/Setup/SetEnv.sh
  then choose the index number of "host_devtools" item from the numbered list
  ```

2. build CAR tools

build release version of carc

```
~/Elastos.RT/Sources$ rls
~/Elastos.RT/Sources$ emake
~/Elastos.RT/Sources$ pd @
```

3. use your new CAR tools

copy your build result to ~/Elastos.RT/Build/Tools

* Ubuntu_32bit
  ```
  cp CInfoReader Cls2C carc carcode lubc lube libz.so ~/Elastos.RT/Build/Tools_32/
  ```

* Ubuntu_64bit
  ```
  cp CInfoReader Cls2C carc carcode lubc lube libz.so ~/Elastos.RT/Build/Tools_64/
  ```

* host_devtools:linux or mac

  linux
  ```
  cp CInfoReader Cls2C carc carcode lubc lube ~/Elastos.RT/Build/Tools/linux/
  cp lube.lbo systypes.cls ~/Elastos.RT/Build/Tools/
  ```

  mac
  ```
  cp Cls2C carc carcode lubc lube ~/Elastos.RT/Build/Tools/mac/
  cp lube.lbo systypes.cls ~/Elastos.RT/Build/Tools/
  ```

4. release version or debug version
```
 rls    #It is an alias of  --> chv rls
 dbg    #It is an alias of  --> chv dbg
```
