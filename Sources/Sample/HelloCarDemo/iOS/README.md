# CAR 构件 demo--iOS

此示例展示了如何在 iOS 平台上调用 Elastos Runtime 以及 Elastos 第三方构件（库）。开发者可以根据该例去熟悉在 iOS 平台上使用 Elastos 接口的流程，并学习开发自己的 Elastos 构件（库）。

参考示例 ios app：Elastos.RT/Source/Sample/HelloCarDemo/iOS/HelloElastosDemo。

elastos Car Demo：Elastos.RT/Sources/Sample/HelloCarDemo/Car。

## 1 编写 Car 文件

在 Sources 文件下创建一个自己的代码文件。例如: Elastos.RT/Sources/test, Elastos.RT/Sources/xxx/test，然后在该目录下编写一个 Car 文件。

下面请看范例 CAR 文件(Elastos.HelloCarDemo.car)内容:

```cpp
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

## 2 编译 Car 文件

在本示例中，执行下面语句:

``` shell
emake Elastos.HelloCarDemo.car
```

通过该命令可以自动生成代码框架。如 CHelloCar.h、 CHelloCar.cpp、 CMakeLists.txt 以及 Elastos.HelloCarDemo.cmake 文件。
一般情况下，CMakeLists.txt、Elastos.HelloCarDemo.cmake 文件是不需要修改的。

car文件中定义的每个类都会对应生成一个该类的.h和.cpp文件：

其中，.h文件中包含了该构件类中需要实现的所有接口（回调接口除外）方法的声明；.cpp文件则包含了这些方法的实现框架。在默认情况下，方法返回E_NOT_IMPLEMENTED，表示方法都未实现。

在头文件中可以添加构件类的私有方法，并在 C++ 文件中添加其的具体实现。

## 3 填入实现代码

在生成的文件框架中，方法的返回的 ECode 值为 E_NOT_IMPLEMENTED，表示此方法未实现。在填写完实现代码后，需要修改为适当的 ECode 值。

下面请看构件 hello 的实现，CHello.cpp 文件:

```cpp
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

## 4 编译

请参照下述文档中的 iOS 部分即可。

[getting_started](../../../../Docs/getting_started.md)

## 5 运行 iOS app

iOS app 具体运行请参考： [run](app/README.md)

在此，只列举涉及到 elastos 调用的代码是如何编写的。

1.Elastos.RT/Sources/Sample/HelloCarDemo/iOS/app/CppInterface.mm

在 init 方法中，new 了一个 CHelloCar 对象，然后通过调用接口中的方法 Hello ，实现了在 iOS 中调用 Car 构件。具体的调用如下：

```oc
-(instancetype)init
{
    self = [super init];
    if (self) {
        AutoPtr<IHelloCar> myHelloCar;
        String name;
        CHelloCar::New((IHelloCar**)&myHelloCar);
        ECode ec = myHelloCar->Hello(&name);
        if(FAILED(ec)) {
            printf("CHelloCar::New() error! ec = %x\n\n", ec);
            return nullptr;
        }
        printf("Hello %s\n", name.string());
        _greeting = [NSString stringWithFormat:@"Hello iOS!\nHello %s!", name.string()];
    }
    return self;
}
```

2.Elastos.RT/Sources/Sample/HelloCarDemo/iOS/app/ViewController.m

声明了一个 CppInterface 对象，调用 init 方法，实现在 RT 中定义 demo 构件的使用。

```oc

@interface ViewController ()
{
    CppInterface* i;
}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    i = [[CppInterface alloc]init];

    const int labelWidth = 300;
    const int labelHeight = 100;
    CGRect labelFrame = CGRectMake((self.view.frame.size.width - labelWidth) / 2,
                                   (self.view.frame.size.height - labelHeight) / 2,
                                   labelWidth, labelHeight);


    UILabel *myLabel = [[UILabel alloc] initWithFrame:labelFrame];

    myLabel.font = [UIFont boldSystemFontOfSize:30.0f];
    myLabel.textAlignment =  NSTextAlignmentCenter;

    myLabel.numberOfLines = 2;
    myLabel.text = i.greeting;

    [self.view addSubview:myLabel];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end

```

3.CMakeLists.txt 的内容

Elastos.RT/Sources/Sample/HelloCarDemo/iOS/app/CMakeLists.txt，需要注意的内容罗列如下：

```cpp
cmake_minimum_required (VERSION 3.7)

include($ENV{XDK_DEFINITIONS_CMAKE})
set(CMAKE_CXX_STANDARD 11)

set(DEVELOPMENT_PROJECT_NAME "hellocarapp")                 # <== Set to your project name, e.g. project.xcodeproj
set(DEVELOPMENT_TEAM_ID "AAAAA11111")                       # <== Set to your team ID from Apple
set(APP_NAME "HelloCarApp")                                 # <== Set To your app's name
set(APP_BUNDLE_IDENTIFIER "org.elastos.hellocarapp")        # <== Set to your app's bundle identifier
set(CODE_SIGN_IDENTITY "iPhone Developer")                  # <== Set to your preferred code sign identity, to see list:
                                                            # /usr/bin/env xcrun security find-identity -v -p codesigning
set(DEPLOYMENT_TARGET 8.0)                                  # <== Set your deployment target version of iOS
set(DEVICE_FAMILY "1")                                      # <== Set to "1" to target iPhone, set to "2" to target iPad, set to "1,2" to target both

......

set(APP_HEADER_FILES
  ./AppDelegate.h
  ./ViewController.h
  ./CppInterface.h
  ./Prefix.pch
)

set(APP_SOURCE_FILES
  ./AppDelegate.m
  ./ViewController.m
  ./CppInterface.mm
  ./main.m
)

......

add_library( Elastos.Runtime SHARED IMPORTED GLOBAL )
set_target_properties( Elastos.Runtime PROPERTIES IMPORTED_LOCATION $ENV{XDK_TARGETS}/Elastos.Runtime.eco )
target_link_libraries(${APP_NAME} Elastos.Runtime)

target_link_libraries(${APP_NAME}
    $ENV{XDK_USER_LIB}/libElastos.Runtime_static.a)

......

# Copy the framework into the app bundle
add_custom_command(
    TARGET
    ${APP_NAME}
    POST_BUILD COMMAND /bin/sh -c
    \"COMMAND_DONE=0 \;
    if ${CMAKE_COMMAND} -E copy
        $ENV{XDK_TARGETS}/Elastos.Runtime.eco
        $ENV{XDK_TARGETS}/Elastos.CoreLibrary.eco
        $ENV{XDK_TARGETS}/Elastos.HelloCarDemo.eco
        \${BUILT_PRODUCTS_DIR}/${APP_NAME}.app/Frameworks/
        \&\>/dev/null \; then
        COMMAND_DONE=1 \;
    fi \;
    if [ \\$$COMMAND_DONE -eq 0 ] \; then
        echo Failed to copy the framework into the app bundle \;
        exit 1 \;
    fi\"
)

# Codesign the framework in it's new spot
add_custom_command(
   TARGET
    ${APP_NAME}
    POST_BUILD COMMAND /bin/sh -c
    \"COMMAND_DONE=0 \;
    if codesign --force --verbose
        \${BUILT_PRODUCTS_DIR}/${APP_NAME}.app/Frameworks/Elastos.Runtime.eco
        --sign ${CODE_SIGN_IDENTITY}
        \&\>/dev/null \; then
        COMMAND_DONE=1 \;
    fi \;
    if codesign --force --verbose
        \${BUILT_PRODUCTS_DIR}/${APP_NAME}.app/Frameworks/Elastos.CoreLibrary.eco
        --sign ${CODE_SIGN_IDENTITY}
        \&\>/dev/null \; then
        COMMAND_DONE=1 \;
    fi \;
    if codesign --force --verbose
        \${BUILT_PRODUCTS_DIR}/${APP_NAME}.app/Frameworks/Elastos.HelloCarDemo.eco
        --sign ${CODE_SIGN_IDENTITY}
        \&\>/dev/null \; then
        COMMAND_DONE=1 \;
    fi \;
    if [ -n '$ENV{XDK_SKIP_CODE_SIGN}' ] \; then
        echo Framework codesign skiped \;
        exit 0 \;
    fi \;
    if [ \\$$COMMAND_DONE -eq 0 ] \; then
        echo Framework codesign failed \;
        exit 1 \;
    fi\"
)
......

```

Elastos.RT/Sources/Sample/HelloCarDemo/iOS/CMakeLists.txt，内容如下：

```cpp
set (APP_NAME HelloCarApp)
set (APP_SUBDIR app)
set (APP_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${APP_SUBDIR})
set (APP_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/${APP_SUBDIR})
set (APP_BUILD_DIR build_xcode)
set (APP_OUTPUT ${APP_BINARY_DIR}/${APP_BUILD_DIR}/${CMAKE_BUILD_TYPE}${CMAKE_XCODE_EFFECTIVE_PLATFORMS}/${APP_NAME}.app/${APP_NAME})

file(MAKE_DIRECTORY ${APP_BINARY_DIR})

add_custom_command(
    COMMENT "Building ios HelloCarDemo app..."
    OUTPUT ${APP_OUTPUT}
    COMMAND ${CMAKE_COMMAND} -DCMAKE_TOOLCHAIN_FILE=${APP_SOURCE_DIR}/ios.cmake -DIOS_PLATFORM=${IOS_PLATFORM} -H${APP_SOURCE_DIR} -B${APP_BUILD_DIR} -GXcode
    COMMAND ${CMAKE_COMMAND} --build ${APP_BUILD_DIR} --config ${CMAKE_BUILD_TYPE}
    COMMAND ${CMAKE_COMMAND} -E touch_nocreate ${APP_OUTPUT}
    WORKING_DIRECTORY ${APP_BINARY_DIR}
    DEPENDS Elastos.Runtime
            Elastos.CoreLibrary
            Elastos.HelloCarDemo
)

add_custom_target(build_ios_hellocardemo ALL DEPENDS ${APP_OUTPUT})
```