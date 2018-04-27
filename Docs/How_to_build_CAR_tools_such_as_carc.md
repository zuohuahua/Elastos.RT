# Build CAR Compiler

In general, you will not use it. It will be used after you modified the source code of the CAR tools.

1. Enter the build environment:

   * Ubuntu 64-bits CAR tools
     ``` shell
     source ~/Elastos.RT/Setup/SetEnv.sh linux_devtools_4
     ```
     or
     ``` shell
     source ~/Elastos.RT/Setup/SetEnv.sh
     ```
     and then choose the index number of the "linux_devtools_64" item from the numbered list

   * Ubuntu 32-bits CAR tools
     ``` shell
     source ~/Elastos.RT/Setup/SetEnv.sh linux_devtools_32
     ```
     or
     ``` shell
     source ~/Elastos.RT/Setup/SetEnv.sh
     ```
     and then choose the index number of the "linux_devtools_32" item from the numbered list

   * MacOS 64-bits CAR tools
     ``` shell
     source ~/Elastos.RT/Setup/SetEnv.sh mac_devtools_64
     ```
     or
     ``` shell
     source ~/Elastos.RT/Setup/SetEnv.sh
     ```
     and then choose the index number of the "mac_devtools_64" item from the numbered list

   * MacOS 32-bits CAR tools
     ``` shell
     source ~/Elastos.RT/Setup/SetEnv.sh mac_devtools_32
     ```
     or
     ``` shell
     source ~/Elastos.RT/Setup/SetEnv.sh
     ```
     and then choose the index number of the "mac_devtools_32" item from the numbered list

2. Build CAR tools

   Build release version of CAR compiler

   ``` shell
   ~/Elastos.RT/Sources$ rls
   ~/Elastos.RT/Sources$ emake
   ~/Elastos.RT/Sources$ pd @
   ```

3. Deploy the new CAR tools

   Copy your build results to ~/Elastos.RT/Build/Tools

   * Ubuntu 64-bits CAR tools
     ``` shell
     cp CInfoReader Cls2C carc carcode lubc lube ~/Elastos.RT/Build/Tools/64/linux/
     cp lube.lbo systypes.cls ~/Elastos.RT/Build/Tools/64/
     ```

   * Ubuntu 32-bits CAR tools
     ``` shell
     cp CInfoReader Cls2C carc carcode lubc lube ~/Elastos.RT/Build/Tools/32/linux/
     cp lube.lbo systypes.cls ~/Elastos.RT/Build/Tools/32/
     ```

   * MacOS 64-bits CAR tools
     ``` shell
     cp Cls2C carc carcode lubc lube ~/Elastos.RT/Build/Tools/64/mac/
     cp lube.lbo systypes.cls ~/Elastos.RT/Build/Tools/64/
     ```

   * MacOS 32-bits CAR tools
     ``` shell
     cp Cls2C carc carcode lubc lube ~/Elastos.RT/Build/Tools/32/mac/
     cp lube.lbo systypes.cls ~/Elastos.RT/Build/Tools/32/
     ```

4. Change between release version and debug version

   ``` shell
   rls    #It is an alias of  --> chv rls
   dbg    #It is an alias of  --> chv dbg
   ```
