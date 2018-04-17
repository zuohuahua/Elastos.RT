> ## 1.简介
此示例展示了如何在 Android 平台上调用 Elastos Runtime 以及 Elastos 第三方构件（库）。开发者可以根据该例去熟悉在 Android 平台上使用 Elastos 接口的流程，并学习开发自己的 Elastos 构件（库）。

参考示例:

android app：Elastos.RT/Source/Sample/HelloCarDemo/Android/HelloElastosDemo。

elastos Car Demo：Elastos.RT/Sources/Sample/HelloCarDemo/Car。

> ## 2.原理
欲要在 android app 中使用在elastos上开发的构件，首先需要在elastos上进行该构件的创建和开发；其次，完成编译后导出相关的.so和头文件；然后，android app中加载elastos相关的库，声明native方法同时在jni文件声明与native方法对应的C函数，native方法调用这个C函数，而在这个C函数中调用car构件中的方法。通过这个方式即可实现在android app中调用car构件.

> ## 3.操作步骤

> ### 3.1.编写 car 文件

在Sources文件下创建一个自己的代码文件。例如: Elastos.RT/Sources/Sample/test/，然后在该目录下编写一个Car文件。

下面请看范例 CAR 文件(Elastos.HelloCarDemo.car)内容:

```
module
{
    importlib("Elastos.CoreLibrary");

    interface IHelloCar {
        Hello(
            [out] String* name);
    }

    class CHelloCar {
        interface IHelloCar;
    }

}
```

示例 Elastos.HelloCarDemo.car 文件中，定义了接口 IHelloCar 和类 CHelloCar。IHelloCar 接口提供 Hello 方法；类 CHelloCar 实现接口 IHelloCar。

> ### 3.2.编译Car文件

在本示例中，执行下面语句:

```
emake Elastos.HelloCarDemo.car
```

通过该命令可以自动生成代码框架。如 CHelloCar.h、 CHelloCar.cpp、 CMakeLists.txt、Elastos.HelloCarDemo.cmake 文件以及 sources 文件。
一般情况下，CMakeLists.txt、Elastos.HelloCarDemo.cmake、 sources 文件是不需要修改的。（其中编译在升级，sources文件即将删除）

car文件中定义的每个类都会对应生成一个该类的.h和.cpp文件：

其中，.h文件中包含了该构件类中需要实现的所有接口（回调接口除外）方法的声明；.cpp文件则包含了这些方法的实现框架。在默认情况下，方法返回E_NOT_IMPLEMENTED，表示方法都未实现。

在头文件中可以添加构件类的私有方法，并在C++文件中添加其的具体实现。

> ### 3.3.填入实现代码

在生成的文件框架中，方法的返回的 ECode 值为 E_NOT_IMPLEMENTED，表示此方法未实现。在填写完实现代码后，需要修改为适当的 ECode 值。

下面请看构件 hello 的实现，CHello.cpp 文件:

```
#include "CHelloCar.h"

CAR_OBJECT_IMPL(CHelloCar)

CAR_INTERFACE_IMPL(CHelloCar, Object, IHelloCar);

ECode CHelloCar::Hello(
    /* [out] */ String * output)
{
    VALIDATE_NOT_NULL(output)
    *output = "Elastos";
    return NOERROR;
}
```

> ### 3.4.编译和集成

1.Compile android-version RT

```
$ source SetEnv.sh arm_android
$ emake
```

2.Generate header files and libs files of elastos

* Execute the following order, you will find include files and lib files under directory of SDK/android/elastos.

```
dropsdk
```

3.Integrate elastos library information and third-party library information

* integrate elastos library

copy the contents gerenated in step 2 to Sources/Sample/HelloCarDemo/Android/HelloElastosDemo/app/src/main/jni/elastos/

```
Elastos.RT/SDK/android/elastos$cp -rf * ../../../Sources/Sample/HelloCarDemo/Android/HelloElastosDemo/app/src/main/jni/elastos/
```

* integrate third-party library


copy the contents gerenated under Elastos.RT/Export/android/Elastos.HelloCarDemo to Sources/Sample/HelloCarDemo/Android/HelloElastosDemo/app/src/main/jni/Elastos.HelloCarDemo/


```
Elastos.RT/Export/android/Elastos.HelloCarDemo$
cp *  ../../../Sources/Sample/HelloCarDemo/Android/HelloElastosDemo/app/src/main/jni/Elastos.HelloCarDemo/
```

> ### 3.5.android 调用 car 构件

    接下来，只列举涉及到elastos调用的代码是如何编写的。

1. 新建一个文件TestUtils.java

    该文件包含两个内容：一，加载Elastos.RT的库、加载作为demo示例的库信息（在这里作为第三方库来看待）、加载实现调用helloCarDemo中car构件的jni文件；二，声明native方法，并定义了另外一个Java方法来调用这个native方法。

    路径：app/src/main/java/org/elastos/runtime/sample/helloelastos/TestUtils.java

```
static {
    System.loadLibrary("Elastos.Runtime");
    System.loadLibrary("Elastos.CoreLibrary");
    System.loadLibrary("Elastos.HelloCarDemo");
    System.loadLibrary("testThirdLib");
}

private static native String nativeGetHelloCarString();

public String getHelloCarString() {
    return nativeGetHelloCarString();
}
```

2. jni文件内容

    app/src/main/jni/elastos_testthirdlib.cpp，在nativeGetHelloCarString函数中，new了一个CHelloCar对象，然后通过调用接口中的函数Hello，实现了在android中调用Car构件。

```
//For Elastos
#include "Elastos.HelloCarDemo.Export.h" （改动中）

#define JNIREG_CLASS "org/elastos/runtime/sample/helloelastos/TestUtils"

static jstring JNICALL nativeGetHelloCarString(JNIEnv *env, jobject jobj)
{
    AutoPtr<IHelloCar> helloCarObj;
    ECode ec = CHelloCar::New((IHelloCar**)&helloCarObj);
    if (ec != NOERROR || helloCarObj == NULL) {
        return 0;
    }
    String helloString;

    helloCarObj->Hello(&helloString);

    String newString("[native] Hello, ");
    newString += helloString + "!";

    return env->NewStringUTF(newString.string());
}

static const JNINativeMethod gMethods[] = {
    {"nativeGetHelloCarString", "()Ljava/lang/String;", (void*)nativeGetHelloCarString}
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved){
    JNIEnv * env;
    jclass cls;
    jint result = -1;
    if(vm->GetEnv((void **)&env,JNI_VERSION_1_6) != JNI_OK){
        return JNI_ERR;
    }

    cls = env->FindClass(JNIREG_CLASS);
    env->RegisterNatives(cls, gMethods, sizeof(gMethods)/sizeof(JNINativeMethod));
    return JNI_VERSION_1_6;
}
```

3. MainActivity内容

    app/src/main/java/org/elastos/runtime/sample/helloelastos/MainActivity.java，具体的调用如下：

```
//Show the string that comes from a Elastos car objects[CHelloCar]
TextView textLabel = (TextView)findViewById(R.id.label);
TestUtils tu = new TestUtils();
String helloString = tu.getHelloCarString();
textLabel.setText(helloString);
```

4. Android.mk的内容

    app/src/main/jni/Android.mk：

```
LOCAL_PATH := $(call my-dir)

#Elastos.Runtime
include $(CLEAR_VARS)
LOCAL_MODULE    := Elastos.Runtime
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastos/libs/libElastos.Runtime.so
include $(PREBUILT_SHARED_LIBRARY)

#Elastos.CoreLibrary
include $(CLEAR_VARS)
LOCAL_MODULE    := Elastos.CoreLibrary
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastos/libs/libElastos.CoreLibrary.so
include $(PREBUILT_SHARED_LIBRARY)

#Elastos.HelloCarDemo
include $(CLEAR_VARS)
LOCAL_MODULE    := Elastos.HelloCarDemo
LOCAL_SRC_FILES := $(LOCAL_PATH)/Elastos.HelloCarDemo/libElastos.HelloCarDemo.so
include $(PREBUILT_SHARED_LIBRARY)

#Elastos.CoreLibrary depend libcrypto.so
include $(CLEAR_VARS)
LOCAL_MODULE    := crypto
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastos/libs/libcrypto.so
include $(PREBUILT_SHARED_LIBRARY)

#Elastos.CoreLibrary depend libicuuc.so
include $(CLEAR_VARS)
LOCAL_MODULE    := icuuc
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastos/libs/libicuuc.so
include $(PREBUILT_SHARED_LIBRARY)

#Elastos.CoreLibrary depend libstlport.so
include $(CLEAR_VARS)
LOCAL_MODULE    := stlport
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastos/libs/libstlport.so
include $(PREBUILT_SHARED_LIBRARY)

#Elastos.Runtime depend libelacarrier.so
include $(CLEAR_VARS)
LOCAL_MODULE    := elacarrier
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastos/libs/libelacarrier.so
include $(PREBUILT_SHARED_LIBRARY)

#Elastos.Runtime depend libelacommon.so
include $(CLEAR_VARS)
LOCAL_MODULE    := elacommon
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastos/libs/libelacommon.so
include $(PREBUILT_SHARED_LIBRARY)

### shared library
include $(CLEAR_VARS)
LOCAL_SRC_FILES := elastos_testthirdlib.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/elastos/include \
    $(LOCAL_PATH)/elastos/include/elastos \
    $(LOCAL_PATH)/Elastos.HelloCarDemo

LOCAL_CFLAGS += -std=c++11 -D_GNUC -D_linux -D_UNDEFDLLEXP -fvisibility=hidden

LOCAL_MODULE := testThirdLib

#The elastos eco and lib.
LOCAL_LDFLAGS := $(LOCAL_PATH)/elastos/libs/libElastos.Runtime.so \
    $(LOCAL_PATH)/elastos/libs/libElastos.CoreLibrary.so \
    $(LOCAL_PATH)/Elastos.HelloCarDemo/libElastos.HelloCarDemo.so \
    $(LOCAL_PATH)/elastos/libs/Elastos.Runtime.lib

include $(BUILD_SHARED_LIBRARY)
```

> ### 3.6.运行Android app

和普通android app运行一样，此处略。
