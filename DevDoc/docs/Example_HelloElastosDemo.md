# The example of building android app(HelloElastosDemo)

### 1.Generate a third-party library, export the corresponding header files and .so flies.

* find the sources file under directory of Elastos.RT/Sources/Elastos/LibCore/tests/HelloCarDemo/eco/elastos/hellocardemo/, then add the following sentence in the sources file:

```
EXPORT_ECO = 1
```

* When compiled ,it will generate directory of Export/android/Elastos.HelloCarDemo what will contain header files and .so files.

### 2.Compile android-version RT

* it can refer to Elastos.RT/DevDoc/docs/getting_started.md

### 3.Generate header files and libs files of elastos

* Execute the following order, you will find include files and lib files under directory of SDK/android/elastos.

```
dropsdk
```

### 4.Integrate elastos library information and third-party library information

* integrate elastos library

copy the contents gerenated in step 3 to SDK/android/sample/HelloElastosDemo/app/src/main/jni/elastos/

```
Elastos.RT/SDK/android/elastos$cp -rf * ../sample/HelloElastosDemo/app/src/main/jni/elastos/
```

* integrate third-party library 


copy the contents gerenated in step 1 to SDK/android/sample/HelloElastosDemo/app/src/main/jni/Elastos.HelloCarDemo/


```
Elastos.RT/Export/android/Elastos.HelloCarDemo$ 
cp *  ../../../SDK/android/sample/HelloElastosDemo/app/src/main/jni/Elastos.HelloCarDemo/
```