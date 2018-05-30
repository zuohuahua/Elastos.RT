# Sample

## Summary
There are several examples in this directory.

## HelloCar

HelloCar needs to compile and run in linux environment.
This demo explains that how to write a CAR class with an inheritance structure and how to write a singleton class.

## HelloCarDemo

HelloCarDemo can run in Android and iOS.
This demo shows that how to call the interface of Elastos.RT and how to call the components(or libraries) of Elastos third-party on the Android platform or iOS platform. 
Developers can use this demo to familiarize with the process of calling interface of Elastos, and also learn to develop their own components (libraries).

## PlainFile

PlainFile needs to compile and run in linux environment.
This demo explains that how to use the car class: CPlainFile to execute some operation ahout a real file or a directory.

## AutoGenerateJavaCode

PlainFile needs to compile and run in android environment.
generate cls first.
* carc -i -c Elastos.AutoGenerateJavaCodes.cls Elastos.AutoGenerateJavaCodes.car

If implement in Java, this command will generate corresponding Java and jni code.
* lube -C Elastos.AutoGenerateJavaCodes.cls -T foregroundjava

If implement in C++, and call car function by jni, using this command.
* lube -C Elastos.AutoGenerateJavaCodes.cls -T foregroundjni
