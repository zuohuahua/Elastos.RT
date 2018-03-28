
***
# If you want to use the new ndk version, you can:

### 1. Download the ndk

You can download ndk at: https://developer.android.com/ndk/downloads/index.html

##### Now, we verify the ndk that can be use:
* android-ndk-r10d
* android-ndk-r10e
* android-ndk-r14b

### 2. Enter the folder: 
```
cd /xxx(ndk)/build/tools
```

### 3. You can use the script make-standalone-toolchain.sh to generate your ndk toolchains
```
./make-standalone-toolchain.sh --platform=android-21 --system=linux-x86_64 --ndk-dir=/xxx/android-ndk-r10d --toolchain=arm-linux-androideabi-4.8 --install-dir=/xxx/Elastos.RT/ToolChains/android/Ndk
```
* At some ndk version, --ndk-dir may be invalid, you don't have to use it.
