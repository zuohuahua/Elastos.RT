# CAR Programming

> ## 1.范例简介

范例 __HelloCar__ 说明了如何编写带有继承结构的 __CAR__ 类以及如何编写单例类。

示例代码路径为：Elastos.RT/Sources/Sample/HelloCar

__HelloCar__ 包括两个部分：__Elastos.HelloCar.eco__ 和使用这个eco的可执行程序 __exe__ 。请阅读代码与注释了解细节，下面将讲解一下其中的要点。

``` 目录结构图
+ HelloCar
    + eco
        + elastos
            + hellocar
                - Animal.cpp
                - CAnimalHelper.cpp
                - Cat.cpp
                - CMakeLists.txt
                - Dog.cpp
                - Elastos.HelloCar.car
                - Elastos.HelloCar.cmake
                - helloCar.cpp
                - IAnimal.car
                - IDlog.car
            - CMakeLists.txt
        + inc
            + elastos
                + hellocar
                    - Animal.h
                    - CAnimalHelper.h
                    - Cat.h
                    - CCat.h
                    - CDog.h
                    - Dog.h
        - CMakeLists.txt
    - exe
        - CMakeLists.txt
        - main.cpp
    - CMakeLists.txt
```

> ## 2.操作步骤
> ### 2.1.编写 Car 文件

1. HelloCar/eco/elastos/hellocar/IAnimal.car

    在该 Car 文件中定义了2个接口，其中第一个接口 __IAnimal__ 作为该例子中的一个基类接口，第二个接口 __IAnimalHelper__ 是为了后面创建单例类准备的。

    ```cpp
    module
    {
        namespace Elastos {
        namespace HelloCar {

        interface IAnimal {                 // 接口定义
            SetName(
                [in] String name);

            GetName(
                [out] String* name);

            SetAge(
                [in] Int32 age);

            GetAge(
                [out] Int32* age);

            CanFly(
                [out] Boolean* canFly);
        }

        interface IAnimalHelper {           // 接口定义
            CanFly(
                [in] IAnimal* animal,
                [out] Boolean* canFly);
        }

        } // HelloCar
        } // Elastos
    }
    ```

2. HelloCar/eco/elastos/hellocar/IDog.car

    在该 Car 文件中，定义了一个 __IDog__ 接口，注释说明实现这个接口的类要同时实现 __IAnimal__ 接口。

    ``` cpp
    module
    {
        namespace Elastos {
        namespace HelloCar {

            // 基类注释说明 IDog extends IAnimal
            /**
            * @Involve
            * interface IAnimal;
            */
            interface IDog {
                Bark();
            }

        } // HelloCar
        } // Elastos
    }
    ```

3. HelloCar/eco/elastos/hellocar/Elastos.HelloCar.car

    在这个 Car 文件里，分别定义了两个 Car 类，还有一个单例类。

    ```cpp
    module
    {
        importlib("Elastos.CoreLibrary");       // import 依赖库

        merge("IAnimal.car");                       // 合并 CAR　文件
        merge("IDog.car");                          // 合并 CAR　文件

        using interface Elastos.Core.IComparable;   // using 声明

        namespace Elastos {                         // 命名空间
        namespace HelloCar {

        class CDog {                        // 声明 CAR 类
            constructor();                  // 显式声明无参构造函数

            constructor(                    // 显式声明有参构造函数
                [in] Int32 ctx,
                [in] String attrs);

            interface IDog;                 // 接口声明
            interface IAnimal;              // 接口声明
            interface IComparable;          // 接口声明
        }

        class CCat {                        // 声明 CAR 类
            constructor();                  // 显式声明无参构造函数

            constructor(                    // 显式声明有参构造函数
                [in] Int32 ctx,
                [in] String attrs);

            interface IAnimal;              // 接口声明
            interface IComparable;          // 接口声明
        }

        singleton class CAnimalHelper {     // 声明单例 CAR 类
            interface IAnimalHelper;        // 接口声明
        }

        } // HelloCar
        } // Elastos
    }
    ```

> ### 2.2.编译 Car 文件

进入 Elastos 编译环境，可通过执行 `emake Elastos.HelloCar.car` 自动生成代码框架。

自动生成的代码框架如下所示:

``` shell
~/Elastos.RT/Sources/Sample/HelloCar/eco/hellocar$ emake Elastos.HelloCar.car
~/Elastos.RT/Sources/Sample/HelloCar/eco/hellocar$ ls
CAnimalHelper.cpp  CCat.cpp  CDog.cpp  CMakeLists.txt        Elastos.HelloCar.cmake  IDog.car
CAnimalHelper.h    CCat.h    CDog.h    Elastos.HelloCar.car  IAnimal.car
```

自动生成的代码框架中，是直接的生成的 Car 类和单例。在此，为说明 C++ 的继承和实现方式，对生成的头文件和 cpp 框架上做了改动，主要是类 __CCat__ 和类 __CDog__ 的实现改变了：增加了一个 C++ 基类 __Animal__ 来实现，然后让 Car 类再继承 C++ 类。请看下面步骤.

> ### 2.3.编写头文件和 cpp 文件
> #### 2.3.1.编写 C++ 基类 Animal

HelloCar/eco/inc/elastos/hellocar/Animal.h

``` cpp
#ifndef __HELLOCAR_ANIMAL_H__
#define __HELLOCAR_ANIMAL_H__

#include "Elastos.HelloCar.h"     // include 模块头文件，文件名格式：模块名称.h
#include "elastos/core/Object.h"  // include Object 基类

using Elastos::Core::IComparable;

namespace Elastos {
namespace HelloCar {

// C++ 类　Animal 作为 CCat，CDog 的基类，实现了 IAnimal 接口，并继承自基类 Object
class Animal
    : public Object
    , public IAnimal
    , public IComparable
{
public:
    CAR_INTERFACE_DECL()    // 实现某个 CAR 接口的类都需要使用宏 CAR_INTERFACE_DECL/CAR_INTERFACE_IMPL

    Animal();               // 若有成员需要初始化，则需显式声明构造函数，以便使用初始化列表进行初始化

    virtual ~Animal();

    CARAPI constructor();   // 用于被子类继承的 CAR 构造函数

    CARAPI constructor(     // 用于被子类继承的 CAR 构造函数
        /* [in] */ Int32 age,
        /* [in] */ const String& name);

    // IComparable 接口函数
    CARAPI CompareTo(
        /* [in] */ IInterface* another,
        /* [out] */ Int32* result);

    // IAnimal 接口函数
    CARAPI SetName(
        /* [in] */ const String& name);

    CARAPI GetName(
        /* [out] */ String* name);

    CARAPI SetAge(
        /* [in] */ Int32 age);

    CARAPI GetAge(
        /* [out] */ Int32* age);

    CARAPI CanFly(
        /* [out] */ Boolean* canFly);

protected:
    // 成员变量
    Int32 mAge;
    String mName;
};

} // HelloCar
} // Elastos

#endif //__HELLOCAR_ANIMAL_H__
```

HelloCar/eco/elastos/hellocar/Animal.cpp

``` cpp
#include "elastos/hellocar/Animal.h"
#include <stdio.h>

using Elastos::Core::EIID_IComparable;

namespace Elastos {
namespace HelloCar {

// 实现某个 CAR 接口的类都需要使用宏 CAR_INTERFACE_IMPL/CAR_INTERFACE_IMPL
CAR_INTERFACE_IMPL(Animal, Object, IAnimal, IComparable)

// 使用成员初始化列表初始化成员变量
Animal::Animal()
    : mAge(1)
    , mName("Animal")
{
}

Animal::~Animal()
{
    // printf(" ~Animal: %d, %s\n", mAge, mName.string());
}

ECode Animal::constructor()
{
    return NOERROR;
}

ECode Animal::constructor(
    /* [in] */ Int32 age,
    /* [in] */ const String& name)
{
    mAge = age;
    mName = name;
    PFL_EX("Animal::constructor(%d, %s)\n", age, name.string());
    return NOERROR;
}

ECode Animal::CompareTo(
    /* [in] */ IInterface* another,
    /* [out] */ Int32* result)
{
    VALIDATE_NOT_NULL(result);

    IAnimal* oa = IAnimal::Probe(another);
    if (oa == NULL) {
        *result = 1;
        return E_CLASS_CAST_EXCEPTION;
    }

    Animal* a = (Animal*)oa;
    *result = mName.Compare(a->mName);
    return NOERROR;
}

ECode Animal::SetName(
    /* [in] */ const String& name)
{
    mName = name;
    return NOERROR;
}

ECode Animal::GetName(
    /* [out] */ String* name)
{
    VALIDATE_NOT_NULL(name)
    *name = mName;
    return NOERROR;
}

ECode Animal::SetAge(
    /* [in] */ Int32 age)
{
    mAge = age;
    return NOERROR;
}

ECode Animal::GetAge(
    /* [out] */ Int32* age)
{
    VALIDATE_NOT_NULL(age)
    *age = mAge;
    return NOERROR;
}

ECode Animal::CanFly(
    /* [out] */ Boolean* canFly)
{
    VALIDATE_NOT_NULL(canFly);
    *canFly = FALSE;
    return NOERROR;
}

} // HelloCar
} // Elastos
```

> #### 2.3.2.编写只实现基类接口的 C++ 子类 Cat

HelloCar/eco/inc/elastos/hellocar/Cat.h

``` cpp
#ifndef __HELLOCAR_CAT_H__
#define __HELLOCAR_CAT_H__

#include "Animal.h"                     // include 基类

namespace Elastos {
namespace HelloCar {

class Cat
    : public Animal
{
public:
    using Animal::constructor;

    CARAPI CanFly(                      // 覆写基类方法
        /* [out] */ Boolean* canFly);
};

} // HelloCar
} // Elastos

#endif //__HELLOCAR_CAT_H__
```

HelloCar/eco/elastos/hellocar/Cat.cpp

``` cpp
#include "elastos/hellocar/Cat.h"

namespace Elastos {
namespace HelloCar {

ECode Cat::CanFly(
    /* [out] */ Boolean* canFly)
{
    printf("Though cat has nine lives, but it can not fly!\n");
    return Animal::CanFly(canFly);
}

} // HelloCar
} // Elastos
```

> #### 2.3.3.编写继承 C++ 类的 Car 类 CCat

HelloCar/eco/inc/elastos/hellocar/CCat.h

``` cpp
#ifndef __HELLOCAR_CCAT_H__
#define __HELLOCAR_CCAT_H__

#include "_Elastos_HelloCar_CCat.h"     // include 编译器生成的夹壁墙头文件，文件名格式：_命名空间_CAR类名称.h
#include "Cat.h"                        // include 基类

namespace Elastos {
namespace HelloCar {

CarClass(CCat)
    , public Cat
{
public:
    CAR_OBJECT_DECL()   // 非单例 CAR 类需要使用宏 CAR_OBJECT_DECL/CAR_OBJECT_IMPL
};

} // HelloCar
} // Elastos

#endif //__HELLOCAR_CCAT_H__
```

HelloCar/eco/elastos/hellocar/helloCar.cpp

__CCat__ 的实现和 __CDog__ 的实现一并放进了 `helloCar.cpp` 中，这种继承的实现方式，可通过宏 __CAR_OBJECT_IMPL__ 来简化实现。

``` cpp
#include "elastos/hellocar/CCat.h"
#include "elastos/hellocar/CDog.h"

namespace Elastos {
namespace HelloCar {

CAR_OBJECT_IMPL(CCat)

CAR_OBJECT_IMPL(CDog)

} // HelloCar
} // Elastos
```

> #### 2.3.4.编写继承 C++ 基类同时实现其它接口的 C++ 子类 Dog

HelloCar/eco/inc/elastos/hellocar/Dog.h

``` cpp
#ifndef __HELLOCAR_DOG_H__
#define __HELLOCAR_DOG_H__

#include "Animal.h"         // include 基类

namespace Elastos {
namespace HelloCar {

class Dog
    : public Animal
    , public IDog           // 实现　CAR 类接口　IDog
{
public:
    CAR_INTERFACE_DECL()    // 实现某个 CAR 接口的类都需要使用宏 CAR_INTERFACE_DECL/CAR_INTERFACE_IMPL

    CARAPI Bark();
};

} // HelloCar
} // Elastos

#endif //__HELLOCAR_DOG_H__
```

HelloCar/eco/elastos/hellocar/Dog.cpp

``` cpp
#include "elastos/hellocar/Dog.h"

namespace Elastos {
namespace HelloCar {

CAR_INTERFACE_IMPL(Dog, Animal, IDog)

ECode Dog::Bark()
{
    printf("%s : wang! wang!\n", mName.string());
    return NOERROR;
}

} // HelloCar
} // Elastos
```

> #### 2.3.5.编写继承 C++ 类的 Car 类 CDog

HelloCar/eco/inc/elastos/hellocar/CDog.h

``` cpp
#ifndef __HELLOCAR_CDOG_H__
#define __HELLOCAR_CDOG_H__

#include "_Elastos_HelloCar_CDog.h"     // include 编译器生成的夹壁墙头文件，文件名格式：_命名空间_CAR类名称.h
#include "Dog.h"                        // include 基类

namespace Elastos {
namespace HelloCar {

CarClass(CDog)
    , public Dog
{
public:
    CAR_OBJECT_DECL()       // 非单例 CAR 类需要使用宏 CAR_OBJECT_DECL/CAR_OBJECT_IMPL
};

} // HelloCar
} // Elastos

#endif //__HELLOCAR_CDOG_H__
```

__CDog__ 的实现和 __CCat__ 类似，都在 `helloCar.cpp` 中。

> #### 2.3.6.编写单例 CAR 类 CAnimalHelper

HelloCar/eco/inc/elastos/hellocar/CAnimalHelper.h

``` cpp
#ifndef __HELLOCAR_CANIMALHELPER_H__
#define __HELLOCAR_CANIMALHELPER_H__

#include "_Elastos_HelloCar_CAnimalHelper.h"    // include 编译器生成的夹壁墙头文件，文件名格式：_命名空间_CAR类名称.h
#include <elastos/core/Singleton.h>             // include 单例基类

namespace Elastos {
namespace HelloCar {

// CAnimalHelper 是单例 CAR 类，单例 CAR 类需要继承 Singleton 类，并使用宏 CAR_SINGLETON_DECL/CAR_SINGLETON_IMPL
CarClass(CAnimalHelper)
    , public Singleton      // 单例 CAR 类需要继承 Singleton 类
    , public IAnimalHelper  // 实现　CAR 类接口IAnimalHelper
{
public:
    CAR_INTERFACE_DECL()    // 实现某个 CAR 接口的类都需要使用宏 CAR_INTERFACE_DECL/CAR_INTERFACE_IMPL

    CAR_SINGLETON_DECL()    // 单例 CAR 类需要使用宏 CAR_SINGLETON_DECL/CAR_SINGLETON_IMPL

    CARAPI CanFly(
        /* [in] */ IAnimal* animal,
        /* [out] */ Boolean* canFly);
};
f
} // HelloCar
} // Elastos

#endif //__HELLOCAR_CANIMALHELPER_H__
```

HelloCar/eco/elastos/hellocar/CAnimalHelper.cpp

``` cpp
#include "elastos/hellocar/CAnimalHelper.h"

namespace Elastos {
namespace HelloCar {

CAR_INTERFACE_IMPL(CAnimalHelper, Singleton, IAnimalHelper)

CAR_SINGLETON_IMPL(CAnimalHelper)

ECode CAnimalHelper::CanFly(
    /* [in] */ IAnimal* animal,
    /* [out] */ Boolean* canFly)
{
    VALIDATE_NOT_NULL(canFly);
    *canFly = FALSE;
    VALIDATE_NOT_NULL(animal)

    return animal->CanFly(canFly);
}

} // HelloCar
} // Elastos
```

> ### 2.4.编写客户端代码

Sample/HelloCar/exe/main.cpp，其中，在 `testHelloCar()` 中体现了对于 __Car__ 类接口的调用。

``` cpp
#include "elautoptr.h"
#include "Elastos.HelloCar.h"

using Elastos::HelloCar::IAnimal;
using Elastos::HelloCar::IDog;
using Elastos::HelloCar::CDog;
using Elastos::HelloCar::CCat;
using Elastos::HelloCar::IAnimalHelper;
using Elastos::HelloCar::CAnimalHelper;

void testHelloCar()
{
    Boolean canFly;
    String name;

    AutoPtr<IAnimal> cat;
    ECode ec = CCat::New((IAnimal**)&cat);
    if(FAILED(ec)) {
        printf("CCat::New() error! ec = %x\n\n", ec);
        return;
    }

    cat->SetName(String("Kitty"));
    cat->GetName(&name);
    cat->CanFly(&canFly);
    printf("%s %s!\n\n", name.string(), canFly ? "can fly" : "can not fly");

    AutoPtr<IDog> dog;
    CDog::New(2, String("HuaHua"), (IDog**)&dog);
    dog->Bark();

    IAnimal* da = IAnimal::Probe(dog);
    da->GetName(&name);
    da->CanFly(&canFly);
    printf("%s %s!\n\n", name.string(), canFly ? "can fly" : "can not fly");

    AutoPtr<IAnimalHelper> helper;
    CAnimalHelper::AcquireSingleton((IAnimalHelper**)&helper);
    helper->CanFly(cat, &canFly);
    cat->GetName(&name);
    printf("CAnimalHelper::CanFly : %s %s!\n\n", name.string(), canFly ? "can fly" : "can not fly");
}

int main(int argc, char *argv[])
{
    printf("==================================\n");
    printf("=========== Hello Car ============\n");
    printf("==================================\n");

    testHelloCar();

    printf("=========== Exit Hello Car ============\n");
    return 0;
}
```

> ### 2.5.编译和运行

通过自动代码生成框架的方式生成相关文件后，本例中，我们新增了 C++ 类，同时，改变了文件的代码结构，所以请同步修改 `CMakeLists.txt` 。

修改完成后，即可编译运行：

[compile and run](How_to_run_test_on_ubuntu.md#HelloCar)

> ## 3.总结

该示例完整的展示了 __Car__ 构件的用法以及如何实现继承关系还有定义的一些宏的使用，请认真体会。
