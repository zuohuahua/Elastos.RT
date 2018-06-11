# CAR Programming

> ## 1.Sample Introduction

Sample __HelloCar__ explains that how to write a CAR class with an inheritance structure and how to write a singleton class.

Sample code path：Elastos.RT/Sources/Sample/HelloCar

__HelloCar__ includes two parts：__Elastos.HelloCar.eco__ and the executable program __exe__ which uses it. Please read the code and notes for details, the following will explain the main points.

``` Directory structure
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

> ## 2.Steps
> ### 2.1.Write the Car file

1. HelloCar/eco/elastos/hellocar/IAnimal.car

    Two interfaces are defined in this Car file. The first interface __IAnimal__ is used as a base interface in the example, and the second interface __IAnimalHelper__ is prepared for creating a singleton class.

    ```cpp
    module
    {
        namespace Elastos {
        namespace HelloCar {

        interface IAnimal {                 // Interface definition
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

        interface IAnimalHelper {           // Interface definition
            CanFly(
                [in] IAnimal* animal,
                [out] Boolean* canFly);
        }

        } // HelloCar
        } // Elastos
    }
    ```

2. HelloCar/eco/elastos/hellocar/IDog.car

    In the Car file, the __IDog__ interface is defined. Note that the class that implements this interface must implement the __IAnimal__ interface.

    ``` cpp
    module
    {
        namespace Elastos {
        namespace HelloCar {

            // Base class note description IDog extends IAnimal
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

    In this Car file, there are two Car classes defined, and a singleton class.

    ```cpp
    module
    {
        importlib("Elastos.CoreLibrary");       // import dependent libraries

        merge("IAnimal.car");                       // merge CAR file
        merge("IDog.car");                          // merge CAR file

        using interface Elastos.Core.IComparable;   // using declaration

        namespace Elastos {                         // namespace
        namespace HelloCar {

        class CDog {                        // declare CAR class
            constructor();                  // explicitly declare constructor that have no parameter

            constructor(                    // explicitly declare constructor that have parameters
                [in] Int32 ctx,
                [in] String attrs);

            interface IDog;                 // interface declaration
            interface IAnimal;              // interface declaration
            interface IComparable;          // interface declaration
        }

        class CCat {                        // declare CAR class
            constructor();                  // explicitly declare constructor that have no parameter

            constructor(                    // explicitly declare constructor that have parameters
                [in] Int32 ctx,
                [in] String attrs);

            interface IAnimal;              // interface declaration
            interface IComparable;          // interface declaration
        }

        singleton class CAnimalHelper {     // declare single CAR class
            interface IAnimalHelper;        // interface declaration
        }

        } // HelloCar
        } // Elastos
    }
    ```

> ### 2.2.Compile the Car file

To enter the Elastos compilation environment, a code framework can be generated automatically by executing `emake Elastos.HelloCar.car`.

The automatically generated code framework looks like this:

``` shell
~/Elastos.RT/Sources/Sample/HelloCar/eco/hellocar$ emake Elastos.HelloCar.car
~/Elastos.RT/Sources/Sample/HelloCar/eco/hellocar$ ls
CAnimalHelper.cpp  CCat.cpp  CDog.cpp  CMakeLists.txt        Elastos.HelloCar.cmake  IDog.car
CAnimalHelper.h    CCat.h    CDog.h    Elastos.HelloCar.car  IAnimal.car
```

In the automatically generated code framework, the generated Car class and singleton class are directly generated. In here, in order to illustrate the inheritance and implementation of  C++, we change the generated header files and the cpp framework, the implementation of the classes __CCat__ and __CDog__ has changed mainly: a C++ base class __Animal__ has been added to achieve, and then let the Car class inherits this C++ class. Please see the following steps.

> ### 2.3.Writing header files and cpp files
> #### 2.3.1.Writing C++ base class Animal

HelloCar/eco/inc/elastos/hellocar/Animal.h

``` cpp
#ifndef __HELLOCAR_ANIMAL_H__
#define __HELLOCAR_ANIMAL_H__

#include "Elastos.HelloCar.h"     // include module header file, file name format: module name.h
#include "elastos/core/Object.h"  // include Object base class

using Elastos::Core::IComparable;

namespace Elastos {
namespace HelloCar {

// The C++ class Animal acts as a base class for CCat and CDog, implements the IAnimal interface,
// and inherits from the base class Object.
class Animal
    : public Object
    , public IAnimal
    , public IComparable
{
public:
    CAR_INTERFACE_DECL()    // The class which implements a CAR interface requires macros CAR_INTERFACE_DECL/CAR_INTERFACE_IMPL.

    Animal();               // If a member needs to be initialized, the constructor must be explicitly declared for initialization using an initialization list.

    virtual ~Animal();

    CARAPI constructor();   // CAR constructor for subclass inheritance.

    CARAPI constructor(     // CAR constructor for subclass inheritance.
        /* [in] */ Int32 age,
        /* [in] */ const String& name);

    // IComparable interface function
    CARAPI CompareTo(
        /* [in] */ IInterface* another,
        /* [out] */ Int32* result);

    // IAnimal interface function
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
    // Member variables
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

// The class which implements a CAR interface requires macros CAR_INTERFACE_IMPL/CAR_INTERFACE_IMPL
CAR_INTERFACE_IMPL(Animal, Object, IAnimal, IComparable)

// Initialize member variables using member initialization lists.
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

> #### 2.3.2.Write a C++ subclass Cat that implements only the base class interface

HelloCar/eco/inc/elastos/hellocar/Cat.h

``` cpp
#ifndef __HELLOCAR_CAT_H__
#define __HELLOCAR_CAT_H__

#include "Animal.h"                     // include base class

namespace Elastos {
namespace HelloCar {

class Cat
    : public Animal
{
public:
    using Animal::constructor;

    CARAPI CanFly(                      // overriding the method of base class
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

> #### 2.3.3.Write a Car class CCat that inherits C++ classes

HelloCar/eco/inc/elastos/hellocar/CCat.h

``` cpp
#ifndef __HELLOCAR_CCAT_H__
#define __HELLOCAR_CCAT_H__

#include "_Elastos_HelloCar_CCat.h"     // Include wall clip header files generated by the compiler, File name format:_namespace_CAR class name.h
#include "Cat.h"                        // include base class

namespace Elastos {
namespace HelloCar {

CarClass(CCat)
    , public Cat
{
public:
    CAR_OBJECT_DECL()   // non-single CAR class requires macros CAR_OBJECT_DECL/CAR_OBJECT_IMPL
};

} // HelloCar
} // Elastos

#endif //__HELLOCAR_CCAT_H__
```

HelloCar/eco/elastos/hellocar/helloCar.cpp

The implementation of __CCat__ and the implementation of __CDog__ are also put into `helloCar.cpp`. This kind of inheritance can be simplified by using macro __CAR_OBJECT_IMPL__.

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

> #### 2.3.4.Write C++ subclasses Dog that inherit C++ base classes and implement other interfaces

HelloCar/eco/inc/elastos/hellocar/Dog.h

``` cpp
#ifndef __HELLOCAR_DOG_H__
#define __HELLOCAR_DOG_H__

#include "Animal.h"         // include base class

namespace Elastos {
namespace HelloCar {

class Dog
    : public Animal
    , public IDog           // implement　IDog CAR class
{
public:
    CAR_INTERFACE_DECL()    // The class which implements a CAR interface requires macros CAR_INTERFACE_DECL/CAR_INTERFACE_IMPL.

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

> #### 2.3.5.Write a Car class CDog that inherits C++ class

HelloCar/eco/inc/elastos/hellocar/CDog.h

``` cpp
#ifndef __HELLOCAR_CDOG_H__
#define __HELLOCAR_CDOG_H__

#include "_Elastos_HelloCar_CDog.h"     // Include wall clip header files generated by the compiler, File name format:_namespace_CAR class name.h
#include "Dog.h"                        // include base class

namespace Elastos {
namespace HelloCar {

CarClass(CDog)
    , public Dog
{
public:
    CAR_OBJECT_DECL()       // non-single CAR class requires macros CAR_OBJECT_DECL/CAR_OBJECT_IMPL
};

} // HelloCar
} // Elastos

#endif //__HELLOCAR_CDOG_H__
```

The implementation of __CDog__ is similar to __CCat__ and is in `helloCar.cpp`.

> #### 2.3.6.Write a singleton CAR class CAnimalHelper

HelloCar/eco/inc/elastos/hellocar/CAnimalHelper.h

``` cpp
#ifndef __HELLOCAR_CANIMALHELPER_H__
#define __HELLOCAR_CANIMALHELPER_H__

#include "_Elastos_HelloCar_CAnimalHelper.h"    // Include wall clip header files generated by the compiler, File name format:_namespace_CAR class name.h
#include <elastos/core/Singleton.h>             // include singleton CAR class

namespace Elastos {
namespace HelloCar {

// CAnimalHelper is a singleton CAR class. The singleton CAR class needs to inherit Singleton class and use macros CAR_SINGLETON_DECL/CAR_SINGLETON_IMPL
CarClass(CAnimalHelper)
    , public Singleton      // The singleton CAR class needs to inherit Singleton class
    , public IAnimalHelper  // implement the interface IAnimalHelper of CAR class
{
public:
    CAR_INTERFACE_DECL()    // The class which implements a CAR interface requires macros CAR_INTERFACE_DECL/CAR_INTERFACE_IMPL

    CAR_SINGLETON_DECL()    // single CAR class requires macros CAR_SINGLETON_DECL/CAR_SINGLETON_IMPL

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

> ### 2.4.Write the code of client

Sample/HelloCar/exe/main.cpp, the call to the __Car__ class interface is reflected in `testHelloCar()` in this file.

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

> ### 2.5.Compile and run

After generating the related files through the automatic code generation framework, in this example, we added the C++ classes and changed the code structure of the files at the same time, so please modify the `CMakeLists.txt` file synchronously.

When the modification is completed, you can compile and run:

[compile and run](How_to_run_test_on_ubuntu.md#HelloCar)

> ## 3.Summary

This example shows the use of the __Car__ component and how to implement the inheritance relationship as well as the use of some of the macros defined. Please understand it.
