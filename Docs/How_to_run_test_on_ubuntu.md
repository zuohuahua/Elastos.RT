# Build Test cases

## HelloCar

1. enter the build environment

    ``` shell
    ~/Elastos.RT$ source Setup/SetEnv.sh linux_64
    ```

2. build Elastos.RT

    ``` shell
    ~/Elastos.RT/Sources$ emake
    ```

3. build Elastos.HelloCar.eco

    ``` shell
    cd ~/Elastos.RT/Sources/Sample/HelloCar/eco
    ~/Elastos.RT/Sources/Sample/HelloCar/eco$ emake
    ```

4. build HelloCar

    ``` shell
    cd ~/Elastos.RT/Sources/Sample/HelloCar
    ~/Elastos.RT/Sources/Sample/HelloCar$ emake
    ```

5. build result

    ``` shell
    ~/Elastos.RT/Sources/Sample/HelloCar$ pd @
    ~/Elastos.RT/Targets/obj/x86_64.gnu.linux.dbg/bin$ ll HelloCar
    ```

6. run HelloCar

    ``` shell
    # Run the executable inside the dbg_info directory if you want to debug it with debug symbols
    # We have already "export LD_LIBRARY_PATH=.". So, it will load the *.eco files inside the current directory
    ~/Elastos.RT/Targets/obj/x86_64.gnu.linux.dbg/bin/$ ./HelloCar
    ==================================
    =========== Hello Car ============
    ==================================
    Though cat has nine lives, but it can not fly!
    Kitty can not fly!

    HuaHua : wang! wang!
    HuaHua can not fly!

    Though cat has nine lives, but it can not fly!
    CAnimalHelper::CanFly : Kitty can not fly!

    =========== Exit Hello Car ============
    ```

## Math

1. enter the build environment

    ``` shell
    ~/Elastos.RT$ source Setup/SetEnv.sh linux_64
    ```

2. build Elastos.RT

    ``` shell
    ~/Elastos.RT/Sources$ emake
    ```

3. build Math test case

    ``` shell
    cd ~/Elastos.RT/Sources/Elastos/LibCore/tests/libcore/math
    ~/Elastos.RT/Sources/Elastos/LibCore/tests/libcore/math$ emake
    ```

4. build result

    ``` shell
    ~/Elastos.RT/Sources/Elastos/LibCore/tests/libcore/math$ pd @
    ~/Elastos.RT/Targets/obj/x86_64.gnu.linux.dbg/bin$ ll testMath
    ```

5. run testMath

    ``` shell
    # Run the executable inside the dbg_info directory if you want to debug it with debug symbols
    # We have already "export LD_LIBRARY_PATH=.". So, it will load the *.eco files inside the current directory
    ~/Elastos.RT/Targets/obj/x86_64.gnu.linux.dbg/bin$ ./testMath
    ```
