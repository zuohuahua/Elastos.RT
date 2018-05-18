# CAR Language

> ## 1.Summary

This article focuses on the syntax of __CAR__, such as classes, interfaces, methods, parameters, inheritance, constructors, and so on.

> ## 2.Data Type

The data type of __CAR__ discussed here is the data type that can be used in `.car`.

The __CAR__ data type includes the base data type, structure type (__struct__), __ArrayOf__ type, __EMuid__ type, __EGuid__ type, __String__ type, and interface type. The specific types are defined in the following table.

| type                             | directions                               |
| :------------------------------: | :--------------------------------------: |
| Char32                           | 32-bit character type                    |
| Boolean                          | Boolean type                             |
| Byte                             | Unsigned byte type                       |
| Int8                             | 8-bit signed integer                     |
| Int16                            | 16-bit signed integer                    |
| Int32                            | 32-bit signed integer                    |
| Int64                            | 64-bit signed integer                    |
| UInt16                           | 16-bit unsigned integer                  |
| UInt32                           | 32-bit unsigned integer                  |
| UInt64                           | 64-bit unsigned integer                  |
| Float                            | Single-precision floating point          |
| Double                           | Double-precision floating point          |
| ECode                            | Return type                              |
| EMuid                            | 128-bit UUID                             |
| EGuid                            | 128-bit UUID+UUNM                        |
| String                           | String type                              |
| ArrayOf                          | Array type                               |
| PVoid                            | void* type                               |
| enum xxx                         | Enumeration type                         |
| interface Ixxx                   | Interface Type                           |

> ### 2.1.Basic data types

__CAR__ uses __Char32__ as the character type, which can represent all __UNICODE__ characters. The __char__ types of C/C++ and Java can be easily and explicitly converted to __Char32__ types.

In order to be compatible with existing programs, the Elastos C++ code retains the 16-bit character __Char16__ and provides conversions between the __Char16__ array and the __Char32__ array.

Enumeration members are all capitalized and prefixed with the name of the enumeration. If the name contains multiple words, use an underscore to connect them. For example `BitmapConfig_ALPHA_8`.

> ### 2.2.String type

__CAR__ represents a string using the __String__ type. The __String__ type uses the __UTF-8__ encoding, uses heap memory to store the string content it represents, and supports reference counting to manage its own life cycle.

> ### 2.3.ArrayOf type

__ArrayOf__ implements an array-like function that stores several elements in a contiguous memory. If the __CAR__ object pointer, object pointer inherited from __Object__ or __ElLightRefBase__ class, and __String__ object are elements of __ArrayOf__, then when the __ArrayOf__ call its `Set(Int32 index, T const other)` method to set the element, these elements can be managed automatically for reference counts by __ArrayOf__, but assigning via subscript __`[]`__ does not automatically perform reference count management.

For types T that apply to `AutoPtr<T>`, pointers of this type can be used directly as the element type of __ArrayOf__. In other words using the form `ArrayOf<T*>` instead of `ArrayOf< AutoPtr<T> >` form.

When __ArrayOf__ is created, it will call `memset` to clear the allocated memory and implement the reference count itself. The reference count increase and decrease rules are described as follows:

* Create operation(__`Alloc()/Clone()`__)：

    Create or clone a new object. The reference count of the new object is 0. The returned new object needs to be automatically released by __AutoPtr__ or manually released by calling `Free()/Release()`.

* Reduce the reference count operation(__`Free()/Release()`__)：

    `Free()/Release()` these two methods are equivalent. To ensure consistency, it is recommended to use `Release()`, or to add AutoPtr to automatically reduce the reference count by calling `Release()` internally.

* Increase the reference count operation(__`AddRef()`__)：

    When an __ArrayOf__ pointer is assigned to an AutoPtr variable, the latter will call `AddRef()` to increase the reference count internally. If you need to manually increase the reference count, use the macro `INTERFACE_ADDREF()`.

__ArrayOf__ supports allocation of 0 elements, ie calling `ArrayOf<T>::Alloc(0)`, at this point, calling its `GetLength()` method will get 0 for the returned __ArrayOf__ object.

Some typical uses of __ArrayOf__ are as follows:

* General scene

    ``` cpp
    // ThreadGroup.cpp
    AutoPtr<ArrayOf<IThread *> > newThreads;
    newThreads = ArrayOf<IThread *>::Alloc(mNumThreads * 2);
    newThreads->Copy(mChildrenThreads, 0, mNumThreads);
    newThreads->Set(mNumThreads++, thread);
    mChildrenThreads = newThreads;
    ```

* __out, callee__ parameter as a CAR method

    ``` cpp
    // IPackageInfo.car
    interface IPackageInfo {
        GetActivities(
            [out, callee] ArrayOf<IActivityInfo*>* activities);
    }

    // CPackageInfo.h
    CarClass(CPackageInfo)
    {
        CARAPI GetActivities(
            /* [out, callee] */ ArrayOf<IActivityInfo*>** activities);
    }

    // CPackageInfo.cpp
    ECode CPackageInfo::GetActivities(
        /* [out, callee] */ ArrayOf<IActivityInfo*>** activities)
    {
        VALIDATE_NOT_NULL(activities);
        *activities = mActivities;
        INTERFACE_ADDREF(*activities);
        return NOERROR;
    }

    // Caller
    AutoPtr<IPackageInfo> info;
    ...
    AutoPtr< ArrayOf<IActivityInfo*> > activities;
    info->GetActivities((ArrayOf<IActivityInfo*> **)&activities);
    ```

* Return value as a C++ method

    ``` cpp
    // CHardwareCamera.h
    AutoPtr< ArrayOf<IInteger32*> > SplitInt(
        /* [in] */ const String& str);
    ```

For the __Double array__, use the `AutoPtr< ArrayOf< AutoPtr< ArrayOf<T> > >` form. In order to simplify the writing of the code, you can refer to the following two methods (implemented in the __elquintent.h__ file):

* Use the template class. This method has good versatility but poor readability.

    ``` cpp
    // definition：elquintent.h
    template <typename T> class ArrayOf2 {
    public:
        typedef AutoPtr<ArrayOf<T> > ElementType;
        typedef ArrayOf<ElementType> Type;
    }
    ```

* Use the type predefined by __typedef__ in the __elquintent.h__ file. This method is readable but not universal.

    ``` cpp
    // definition：elquintent.h
    typedef AutoPtr<ArrayOf<Byte> >     ByteArray;
    typedef AutoPtr<ArrayOf<Char32> >   Char32Array;
    typedef AutoPtr<ArrayOf<String> >   StringArray;
    typedef AutoPtr<ArrayOf<Int32> >    Int32Array;
    typedef AutoPtr<ArrayOf<Int64> >    Int64Array;
    typedef AutoPtr<ArrayOf<Float> >    FloatArray;
    typedef AutoPtr<ArrayOf<Double> >   DoubleArray;

    // apply：View.h
    static const AutoPtr<ArrayOf<Int32Array> > VIEW_STATE_SETS;
    ```

> ### 2.4.CAR interface

Interface is a protocol used to define a program. The class or structure that implements the interface must be exactly the same as the interface definition. With this agreement, you can put aside the limitations of the programming language (in theory). Interfaces can inherit from multiple base interfaces, and classes or structures can implement multiple interfaces. Interfaces can contain methods, properties, events, and indexers. The interface itself does not provide the implementation of the members it defines. The interface specifies only the members that must be provided by the class or interface that implements the interface.

Interface is like a template. This template defines the methods the object must implement. Its purpose is to allow these methods to be referenced as interface instances. Interface cannot be instantiated. Classes can implement multiple interfaces and are indexed through these implemented interfaces. Interface variables can only index instances of classes that implement the interface.

Reference example can be viewed: [Car File structure](#4.1.Car-File-structure)。

The interfaces in the above example contain their own interface methods.
The __CAR__ interface does not support multiple inheritance, that is, component class definitions cannot inherit from other component classes. Classes and structures can be multi-instance interfaces, that is, an interface definition can be referenced by multiple class definitions.

Explanation:

* The interfaces in __CAR__ are defined independently of the class. This is against the C++ model, which is actually an abstract base class in C++.

* The class can inherit multiple interfaces.

* While a class can inherit a base class, an interface cannot inherit a class at all. This model avoids C++'s multiple inheritance issues, and implementations in different base classes in C++ may conflict. Therefore, complex mechanisms such as virtual inheritance and explicit scope are no longer needed. C#'s simplified interface model helps accelerate application development.

* An interface defines a reference type that has only abstract members. Actually done by an interface in __CAR__, there is only a method flag, but no code is executed at all. This implies that you cannot instantiate an interface, you can only instantiate an object derived from that interface.

The interface has a reference count function and should manage the life cycle of the interface by reference counting or by means of __AutoPtr__.

> ### 2.5.IInterface interface

The __`IInterface`__ interface is the (direct or indirect) parent interface of all interfaces. If the parent interface is not specified when the interface is defined in `.car`, then the __CAR__ compiler will specify the __`IInterface`__ interface as the parent interface of the interface by default.

Since the __`IInterface`__ interface is the parent interface of all interfaces, an object that implements multiple interfaces has multiple __`IInterface`__ interfaces with different addresses. Therefore, if the object is judged through the __`IInterface`__ interface, both objects that are arbitrated are need `Probe` out __`IInterface`__ interface and then compare. This scenario is more involved in the object's ʻEquals` method.

How to `Probe`, Please refer to the example: [Car class inheritance](#10.1.Car-class-inheritance)。

> ### 2.6.Return type

All methods in the __CAR__ file whose function return types default to `ECode`. So when declaring a definition in Car, you don't need to specify again. When defined in the header file, the function return type is written as `CARAPI`, which can be directly written as `ECode` in the cpp implementation file.

`ECode` is a 32-bit binary integer. In the `ECode` high 16 bits, the highest bit indicates a method call error (1) or success (0); the remaining 15 bits indicate specific error information. Such as: interface error, driver error, CRT error, file system error, graphics system error and so on. For many CAR compatible implementation languages (eg: Visual Basic, Java), these `ECode` are intercepted by the runtime library or virtual machine and then mapped to language specific exceptions. The `ECode` low 16 bits are used for debugging and testing.

The following two macros are provided in __CAR__. These two macros can be used to judge whether the method call is successful by determining whether ECode returns:

| Macro definition      | implication                                           |
| :-------------------: | :---------------------------------------------------: |
| SUCCEEDED(ec)         | Determine whether the method call was successful      |
| FAILED(ec)            | Determine if the method call failed                   |

When developing in Elastos, whether it is a C++ class or a Car class, when you need to declare a method in a non-interface, if the return is not `ECode`, follow the rules: The return value type should be written in the header file as: `CARAPI_( XXX)`, where XXX is the return value type. For example, to return `Int32`, write `CARAPI_(Int32)` in the header file.

> ## 3.Keywords
> ### 3.1.Car Basic keywords

Keywords are also called reserved words. It is a pre-defined identifier that has special meaning to the __CAR__ compiler. The following describes the meaning and presentation of several major keywords in __CAR__.

* The key used to define the component:

    | keywords          | description                                          |
    | :---------------: | :--------------------------------------------------: |
    | module            | used to specify the .dll form of the component       |
    | library           | used to specify the .lib form of the component       |

* The key used to define the interface:

    | keywords          | description                                                      |
    | :---------------: | :--------------------------------------------------------------: |
    | interface         | used to define or declare an interface                           |
    | callbacks         | used to define or declare an asynchronous callback interface     |
    | delegates         | used to define or declare a synchronous callback interface       |

* The key used to define the class:

    | keywords          | description                                    |
    | :---------------: | :--------------------------------------------: |
    | class             | used to define a generic component class       |
    | generic           | used to define a generic class                 |
    | applet            | used to define a `applet` class                |
    | aspect            | used to define an aspect component class       |
    | context           | used to define a context class                 |

* Keywords used for inheritance:

    | keywords          | description                                                                                                         |
    | :---------------: | :-----------------------------------------------------------------------------------------------------------------: |
    | clasinheritss     | used to indicate ordinary class `class` inherits ordinary class `class`                                             |
    | extends           | used to indicate that the interface `interface` inherits the interface `interface`                                  |
    | final             | used to decorate the common component class `class`, indicating that the class is not allowed to be inherited       |
    | substitutes       | used to indicate that ordinary class `class` inherits generics class `generic`                                      |

* Keyword used to decorate the interface:

    | keywords          | description                                                                                                                                           |
    | :---------------: | :---------------------------------------------------------------------------------------------------------------------------------------------------: |
    | virtual           | used to decorate the `interface`, indicating that the virtual interface is declared                                                                   |
    | asynchronous      | used to decorate the `interface`, indicating that the methods of the modified `interface` interface will be invoked asynchronously                    |
    | privileged        | used to decorate the `interface`, and can only be used in `aspect`, specify its interface can only be seen when the polymerization and de-aggregation |
    | filtering         | used to decorate the `callbacks` interface to indicate that the subclass filters the callback events triggered by the base class                      |

* Keywords used to decorate the class:

    | keywords          | description                                                                                                                                                                      |
    | :---------------: | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: |
    | singleton         | used to indicate that this class can only create unique objects                                                                                                                  |
    | aggregates        | used to indicate that when the decorated widget class creates an object, it will automatically aggregate the aspect widget objects listed in the property.                       |
    | pertainsto        | used to decorate the context component class `context`, indicating that the context component class has the aspect component class listed in the attribute                       |
    | affiliates        | used to decorate the aspect class ʻaspect`, indicating that the modified aspect component class can only be aggregated by the non-aspect component class listed in the attribute |

* Keywords for defining data structures:

    | keywords          | description                                                                                         |
    | :---------------: | :-------------------------------------------------------------------------------------------------: |
    | const             | used to define constants of type int                                                                |
    | enum              | used to define the enumeration type, its usage is basically the same as its usage in C language     |
    | struct            | used to define a structure, its usage is basically the same as in C language                        |
    | typedef           | used to define a type, its use is basically the same as in C language                               |

* Keywords for merging components:

    | keywords          | description                                                                  |
    | :---------------: | :--------------------------------------------------------------------------: |
    | merge             | used to merge other components (.car files) in this component                |
    | import            | Specify other components used in this component (.car file)                  |
    | importlib         | Specify other components used in this component (.dll or .cls)               |

* Other keywords:

    | keywords          | description                                                                                                      |
    | :---------------: | :--------------------------------------------------------------------------------------------------------------: |
    | constructor       | used to define a constructor in a class                                                                          |
    | pragma            | disable or allow display of warning information given by the CAR compiler                                        |
    | coalesce          | used to decorate the `callbacks` interface method in the class, which means to merge similar callback events     |

> ### 3.2.Car attribute keyword

The __CAR__ attribute is used to decorate the contents of component parts, interfaces, etc. in __CAR__. The following describes the meaning of each of the attributes supported in __CAR__ and how they are represented.

* Used to decorate widget properties:

    | attributes                  | description                                                   |
    | :-------------------------: | :-----------------------------------------------------------: |
    | version                     | used to identify the version number the component             |

* Used to decorate the properties of ordinary classes:

    | attributes            | description                                                                                                                                                                                                                                                                                                                                    |
    | :-------------------: | :--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: |
    | synchronized          | used to identify the component object and only allow one thread to enter the implementation code of the component. Other threads that access the component object will be blocked and waited (once the thread calls into the object method, other threads access to this object that will be blocked before returning from the object method.) |
    | sequenced             | used to identify the component object and only allow one thread to enter the implementation code of the component. Other threads that access the component object will be blocked and waited (the object method will temporarily release the lock when accessing other objects, allowing other threads to enter the object)                    |
    | private               | used to identify the modified class can only be instantiated on the server                                                                                                                                                                                                                                                                     |
    | local                 | used to decorate classes with constructor (without self-describing parameters)                                                                                                                                                                                                                                                                 |
    | deprecated            | used for Compatibility with data types that are not compatible with the CAR specification in compatible third-party software                                                                                                                                                                                                                   |
    | applet                | used to decorate the class, indicating that the invocation of the interface method of this class has an interface method behavior similar to the `applet`.                                                                                                                                                                                     |

* Used to decorate the properties of the interface:

    | attributes             | description                                                                                                                                                             |
    | :--------------------: | :---------------------------------------------------------------------------------------------------------------------------------------------------------------------: |
    | local                  | indicates that the class object of the class providing the interface can only be used within the same domain as the client program, and cannot be used for remote calls |
    | deprecated             | used for Compatibility with data types that are not compatible with the CAR specification in compatible third-party software                                            |

* Used to decorate the attributes of interface method parameters:

    | attributes                   | description                                                                                           |
    | :--------------------------: | :---------------------------------------------------------------------------------------------------: |
    | in                           | used to identify this parameter as an input parameter                                                 |
    | out                          | used to identify this parameter as an output parameter                                                |
    | callee                       | used to decorate the five-tuple, indicating that the parameter is assigned by the client program      |

> ## 4.Car Component composition
> ### 4.1.Car File structure

A __CAR__ file (.car extension) corresponds to a `module` or `library`. The structure of the __CAR__ file is mainly composed of component classes, interfaces, and interface methods. Each __CAR__ component consists of several classes, each class implements several interfaces, each of which defines several methods. For example: `HelloDemo.car` file.

``` cpp
module　　　　　//component HelloDemo
{
    // interface IHello
    [local]　　　　　　　　 // Interface properties　local
    interface IHello {
        Hello(
            [in] Int32 id);  // method
    }

    // interface IHey
    interface IHey {
        Hey(
            [in] Int32 id,
            [out] String* wtrBuf);
    }

    // class CHello1
    class CHello1 {
        constructor();

        constructor(
            [in] Int32 age);

        interface IHello;
        interface IHey;
    }

    // class CHello2
    class CHello2 {
        interface IHello;

    }
    // class CHello3
    class CHello3 {
        interface IHey;
    }
}
```

Note: The double slash "//" is used as a statement comment in the __CAR__ file.

> ### 4.2.Car file syntax

In the __CAR__ file, the definition of components, interfaces, classes, etc., consists of two parts: attributes and definitions.

__CAR__ attribute: is in square brackets "[]", multiple attributes are separated by a comma ","; the definition of components, interfaces, classes, categories, etc. is in curly braces "{}". Attributes always appear before the definition of the corresponding topic.

Component: There can be only one component definition in a __CAR__ file. In __CAR__, the keyword `module` can be used to define the car component of generating the dynamic link library `.dll`, or the keyword `library` to define the car component of generating the static link library `.lib`.

> ### 4.3.Car file compilation

* Compiling a __CAR__ file is mainly divided into four steps:

  * Write a .car file, declare methods, interfaces, classes, and components
  * Call `emake xxx.car` to generate the foreground code framework
  * Write implementation code in the foreground code framework
  * Call `emake` to generate the code behind, then compile and link it into a component (.dll or .lib)

* Automatic generation of foreground code framework:

    The __Car__ compiler mainly includes four tools: `carusage` (currently deprecated), `carc`, `lubc`, and `lube`. In simple terms, the `carc` tool is used to compile .car files; the `lubc` tool is used to compile .lub templates; the `lube` tool generates code based on templates. The `lub` template is a file with the extension `lub` made up of a set of specific rules. You can use the command `xxx -?` to view the usage instructions for these tools. For example, the command `carc -?` will list the use of the `carc` tool.

    Enter the __CAR__ compilation environment, find the directory where you want to compile the car file, and then then execute the command `emake xxx.car`. First, it will use `carc` tool to generate the `xxx.cls` file which corresponds to the `xxx.car` file in the current directory (can specify the directory). This file contains mainly metadata information that was compiled into `dll` at compile time. Metadata is data that describes data. The metadata in the __CAR__ component mainly includes module information, interface information, and class information. These information are obtained after compilation of the __CAR__ file and is a binary representation of the __CAR__ file.

    Then it use the `lube` tool to generate the foreground code framework of the component according to the `foreground.lub` template based on the just generated `xxx.cls` file. This will generate the corresponding `xxx.cpp` and `xxx.h` files for the class defined for all classes in the component. In addition to the `CMakeLists.txt` file and the `xxx.camke` file. The meaning of these files is as follows:

    | file name        | description                                                                                                                                                                          |
    | :---------------: | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: |
    | xxx.h             | Header file corresponding to the class defined in the .car file                                                                                                                      |
    | xxx.cpp           | The C++ implementation code file for the class defined in the .car file                                                                                                              |
    | CMakeLists.txt    | Used to specify how to compile the source code, generate what kind of object file and other information                                                                              |
    | xxx.camke         | Used to define cmake compiler related variables?. The value of the variable is the list of header files and cpp files generated in the mirror directory when compiling the car file. |

* Automatic generation of background code framework：

    After the implementation code is filled in the foreground code framework, execute the `emake` command, which will first use the `carc` tool to generate the extended `xxxEx.cls` file in the mirror directory.
    Compared to the `xxx.cls` file generated by the front-end code framework, the extended `xxxEx.cls` file adds a few extra interfaces and classes. Then according to the `header.lub`, `public.lub`, `background.lub`, `cls2abrg.lub` and other templates, use the `lube` tool to generate the background code framework and finally compile and link it into `xxx.dll` (or `xxx.lib`).

* The advantages of automatically generated code framework:

    The main function of the automatic generation of code in the compilation environment is packaging and abstracting the writing and use of components, making it easier for users to develop and use __CAR__ components.

    Writing the __CAR__ component interface description file with car is simple and convenient. Although the interface of Hello component is simple, if users write in C++, many technical details still need to be considered. The use of car language programming components is not only simple but also allows users to become more accustomed to thinking methods of component programming, and does not entangled in the internal technical details.

    Automatically generate metadata. The __CLS__ file is a compressed style library of __CAR__ files, which describes the definition of interfaces, classes, methods, structures, and enumerations of the entire component. With the `cls` file, you can get the component's interface, function call methods, and even generate the source code framework. When linking to generate components, the `cls` is also placed into the component. This is equivalent to binding a specification and component together. No matter how the component is copied and moved, you can know how to use the component.

    Many of the important parts of the components, such as factory, registration functions in the DLL, etc., are automatically generated by the compiler environment, and don't have to be manually implemented by the user.

> ## 5.CAR class

The class declared in the .car file is called the __CAR__ class, and the class declared or defined only in the .h file or the .cpp file is called the C++ class.

The __Car__ class and the C++ class use different keywords when they are defined.

The C++ class is defined using the keyword `class`:

``` cpp
class B
    ：public A
{
    ...
};
```

The Car class is defined using the keyword `CarClass`:

``` cpp
CarClass(CDemo)
    ，public A
{
    ...
    // Elastos defined macros can be used to simplify writing
};
```

The Car class must be declared in the .car file.

> ## 6.CAR constructor
> ### 6.1.C++ default constructor

1. Each class must have a constructor, otherwise it cannot create objects;
2. If programer does not provide any constructors, C++ provides a default constructor, which is a no-argument constructor, which is only responsible for creating objects without doing any initialization work;
3. As long as programer defines a constructor (whether it has no parameters or no parameters), C++ no longer provides a default constructor. That is, if you define a constructor with a parameter for a class and you want constructor without a parameter, you must define it yourself.
4. Similar to a variable definition, when creating an object with the default constructor, if you create a global or static object, the bit pattern of the object is all 0, otherwise, the object value is random.

* Note:
  * As mentioned in 2, C++ provides a default constructor in some cases, but it is not automatically called in some cases.
  * In fact, when the user does not provide a custom constructor, declaring the object of the class, and defining the array containing the object will not call the default constructor; but when defining the container containing the object, it will automatically call the default The constructor.

> ### 6.2.CAR clsss constructor

For a __CAR__ class `CXXX`, it has two methods of construction, one is the C++ constructor `CXXX()` and the other is the __CAR__ constructor __`constructor()`__. The latter is essentially an ordinary C++ method.

The similarities between them is:

* If you do not provide a custom implementation, it will provide a default, no-argument implementation.
* Supports constructor overloading.

The difference between them is:

* C++ constructors support initialization lists, and the __CAR__ constructor does not.
* While the C++ constructor is executing, the object is not yet ready, and the object is ready when the __CAR__ constructor is executed.

Therefore, we can use the initialization list of the C++ constructor to initialize the member variables.

For the __CAR__ class that implements the __IParcelble__ interface, it must have a no-argument __CAR__ constructor __`constctor()`__ (whether provided by default or explicitly declared), which is to support the unmarshal of this object. In the case of unmarshal, first call the constructor to create the object, and then cast it to the __IParcelble__ interface. Calling `IParcelble::ReadFromParcel()` to set the object member variable. Therefore, Elastos states that any __CAR__ class that implements the __IParcelable__ interface must explicitly declare __CAR__ constructor without a parameter.

example:

``` cpp
module {
    interface IHello {
        Hello();
    }

    class CHello
    {
        constructor();

        constructor(
            [in] Int32 age,
            [in] String name);

        interface IHello;
        interface IParcelable;
    }
}
```

How to new a car object, and how to call the methods in the interface, please refer to the following example:

``` cpp
AutoPtr<IHello> helloobj1, helloObj2;
CHello::New((IHello**)&helloobj1);
CHello::New(18, String("andy"),(IHello**)&helloobj);
helloobj->Hello();
helloobj2->Hello();
```

In addition, Elastos stipulates that for a non-singleton __CAR__ class, if the class does not explicitly declare a `constructor`, then it needs to explicitly declare a `constructor` without a parameter.

> ## 7.The only instance of CAR (singleton)

Ensure that a __CAR__ class has only one entity (Instance, Object) in the Elastos environment. You can use the __CAR__ keyword `singleton` to achieve this goal.

grammar:

singleton class className classBody;

Instructions for use:

* Singleton-decorated component classes can only have constructors with no arguments.

Use example:

The sample singletonDemo.car file is as follows:

``` cpp
module {
    interface IFoo {
        Hello();
    }

    singleton class CFoo {
        constructor();

        interface IFoo;
    }
}
```

How to new a singleton object, and how to call the interface method, please refer to the following example:

``` cpp
AutoPtr<IFoo> foo;
CFoo::AcquireSingleton((IFoo**)&foo);
foo->Hello();
```

The above example defines a class `CFoo` with a singleton attribute.

Note: You can use the singleton mechanism of __CAR__  to share data between instances.

> ### 8.Object class

Elastos defines the Object class, which implements the following features:

* Supports reference count to manager life cycle.
* Supports weak references and implements the __IWeakReferenceSource__ interface.
* Implements the __IObject__ interface, supports `Equals()`, `GetHashCode()`, and `ToString()` methods.
* Implements the __ISynchronize__ interface and supports `Lock()`, `Unlock()`, `Wait()` and `Notify()` methods.

When writing a C++ class (with the exception of all static members) or a __CAR__ classes, use the Object class as its base class to inherit Object directly or indirectly. The subclass of Object can be on-demand overloading `Equals()`, `GetHashCode()` and `ToString()` method, __CAR__ class need to reload `GetClassID()` method.

To facilitate debugging, subclasses need to pay attention to the implementation of the `ToString()` method. In general, the `ToString()` method returns the class name of the class to which the object belongs. For the __CAR__ class, the `ToString()` method of the Object base class can get the class name by reflection, so the __CAR__ class does not need to override this method if there is no other requirement. The C++ class need to __override__ this method and return the class name in the implementation.

All __CAR__ classes implement the __IObject__, __ISynchronize__, and __IWeakReferenceSource__ interfaces by default. When the __CAR__ class is declared in the `.car` file, these interfaces are not explicitly declared; they will be automatically added to the interface implemented of the __CAR__ class by the __CAR__ compiler.

> ## 9.Predefined macros

When you write a class that implements the __Car__ interface, you need to implement four pure virtual functions: `Probe`, `AddRef`, `Release`, and `GetInterfaceID`. To simplify the operation, Elastos pre-defines several macros to facilitate development. The description is as follows:

* __REFCOUNT_ADD__ reference count plus one, __REFCOUNT_RELEASE__ reference count minus one.

* __CAR_INTERFACE_DECL__ declares the four basic methods of the interface, __CAR_INTERFACE_IMPL__ defines the four basic methods of the interface, and the interface implementation classes (C++ classes or __CAR__ classes) can use them.

* __CAR_OBJECT_DECL__ declares the basic method of the non-singleton __CAR__ class, and __CAR_OBJECT_IMPL__ defines the basic methods of the non-single CAR class, which can be used by the non-single __CAR__ class.

* __CAR_SINGLETON_DECL__ declares the basic method for the singleton __CAR__ class, and __CAR_SINGLETON_IMPL__ defines the basic methods for the singleton __CAR__ class, which can be used by the singleton __CAR__ class.

Using the auto-generated code framework, these macros can be automatically generated in header files and cpp files (except for `REFCOUNT_ADD` and `REFCOUNT_RELEASE`).

> ## 10.Inheritance
> ### 10.1.Car class inheritance

Previous versions of Elastos defined the inheritance relationship between interfaces in the system according to the inheritance relationship in Java. For example, the __IActivity__ interface inherits the __IContextThemeWrapper__ interface.

The advantage of interface inheritance is that it is easy to develop. The methods in the __IContextThemeWrapper__ interface can be invoked through the __IActivity__ interface.

However, interface inheritance also has some big disadvantages. One is that if a class implements multiple interfaces in Java code, there is no corresponding standard for which interface should be inherited in Elastos. The second is the redundancy of the code. For example, a class implementing the __IActivity__ interface can inherit a class that implements __IContextThemeWrapper__, but even if the former does not redefine any methods in the __IContextThemeWrapper__ interface, you still need to encapsulate all the methods in the interface and transfer the corresponding methods of the base class.

Currently Elastos cancels inter-interface inheritance. Development can not support all methods through an interface, but it can __Probe__ the corresponding interface and then call. For example, the __IActivity__ interface no longer inherits from the __IContextThemeWrapper__ interface, so it is not possible to call the method in __IContextThemeWrapper__ through the __IActivity__ interface, but it can call the method by the __IContextThemeWrapper__ interface which is from the __IActivity__ interface __Probe__ out.

After canceling inheritance between interfaces, implementing an interface is often accompanied by the implementation of other interfaces. For example, a class implementing the __IActivity__ interface should also implement the __IContextThemeWrapper__ interface, and implementing the __IContextThemeWrapper__ interface should also implement the __IContextWrapper__ interface, and implementing the __IContextWrapper__ interface should also implement the __IContext__ interface. These interfaces that are to be implemented at the same time cannot be represented in the declaration of the __IActivity__ interface. Therefore, we stipulate that we need to add a certain comment at the head of the declaration, indicating the interfaces that we want to implement at the same time.

Please refer to the following example.

The contents of the car file are as follows:

``` cpp
module
{
    importlib("Elastos.CoreLibrary");

    interface IFoo {
        SetAge(
            [in] Int32 age);

        GetAge(
            [out] Int32* age);
    }

    /**
    * @Involve
    * interface IFoo;
    */
    interface IFoo2 {
        Hello(
            [out] String* name);
    }

    class CFoo2 {
        constructor();

        constructor(
            [in] Int32 age);

        interface IFoo2;
        interface IFoo;
    }
}
```

Here, we want the interface __IFoo2__ to inherit the interface __IFoo__, so add a comment before declaring the interface __IFoo2__; then implement the interface __IFoo__ in the class __CFoo2__ which implements the interface __IFoo2__. After writing the car file, generate additional files by automatically generating code framework, such as the header files and cpp files listed below.

The contents of the CFoo2.h file are as follows:

``` cpp
#ifndef __CFOO2_H__
#define __CFOO2_H__

#include "_CFoo2.h"
#include "elastos/core/Object.h"

using Elastos::Core::IComparable;
using Elastos::Core::EIID_IComparable;

CarClass(CFoo2)
    , public Object
    , public IFoo2
    , public IFoo
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    CARAPI Hello(
        /* [out] */ String * pName);

    CARAPI SetAge(
        /* [in] */ Int32 age);

    CARAPI GetAge(
        /* [out] */ Int32 * pAge);

    CARAPI constructor();

    CARAPI constructor(
        /* [in] */ Int32 age);

private:
    // TODO: Add your private member variables here.
};

#endif // __CFOO2_H__
```

The contents of the CFoo2.cpp file are as follows:

``` cpp

#include "CFoo2.h"

CAR_OBJECT_IMPL(CFoo2)

CAR_INTERFACE_IMPL(CFoo2, Object, IFoo2, IFoo);

ECode CFoo2::SetAge(
    /* [in] */ Int32 age)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CFoo2::GetAge(
    /* [out] */ Int32 * pAge)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CFoo2::constructor()
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CFoo2::constructor(
    /* [in] */ Int32 age)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

```

Then add the implementation code: In the private part of the header file, add a member variable.

``` cpp
Int32 mAge;
```

Supplementary implementation in the cpp file:

``` cpp
ECode CFoo2::Hello(
    /* [out] */ String * pName)
{
    VALIDATE_NOT_NULL(pName)
    *pName = "Hello,Elastos!"
    return NOERROR;
}

ECode CFoo2::SetAge(
    /* [in] */ Int32 age)
{
    mAge = age;
    return NOERROR;
}

ECode CFoo2::GetAge(
    /* [out] */ Int32 * pAge)
{
    VALIDATE_NOT_NULL(pAge)
    *pAge = mAge;
    return NOERROR;
}

ECode CFoo2::constructor()
{
    mAge = 7;
    return NOERROR;
}

ECode CFoo2::constructor(
    /* [in] */ Int32 age)
{
    mAge = age;
    return NOERROR;
}
```

Here's an example of how to use:

``` cpp
AutoPtr<IFoo2> fobj;
CFoo2::New(17, (IFoo2**)&fobj);
String str;
fobj->Hello(&str);
Int32 age;
IFoo::Probe(fobj)->GetAge(&age);

// it can also be like this:

AutoPtr<IFoo> fobjOther;
CFoo2::New(10, (IFoo**)&fobjOther);
Int32 age;
fobjOther->GetAge(&age);
String str;
IFoo2::Probe(fobjOther)->Hello(&str);
```

> ### 10.2.C++ class inheritance

The class declared in the .car file is called the __CAR__ class, and the class declared or defined only in the .h file or the .cpp file is called the C++ class.

Elastos simplifies the code generated by the __CAR__ compiler and optimizes the class inheritance structure of C++ code in Elastos. Therefore, you can assign different responsibilities to the C++ class and the __CAR__ class. The C++ class is used to implement the code logic, and the __CAR__ class is used to encapsulate metadata information into the C++ class. Therefore, C++ classes can be inherited by C++ classes and __CAR__ classes, and __CAR__ classes can no longer be inherited by C++ classes or CAR classes.

At present, the inheritance relationship in Elastos, for example: the inheritance relationship of the CButton widget is __`CButton-->Button-->TextView-->View-->Object`__, and the inheritance relationship of the CTextView widget is __`CTextView-->TextView-->View-->Object`__.

For classes that contain only static member methods, implementations can be divided into C++ classes and __CAR__ classes, C++ classes are implemented as static classes (methods are static methods),
the __CAR__ class is implemented as a singleton class and calls the static methods of the C++ class in the method implementation of the __CAR__ class.

Examples can refer to this：[CAR Programming](How_To_Write_A_Car_Component.md)

> ## Appendix
> ### Namespace

__CAR__ supports namespaces to reduce naming conflicts.

The name used for reflection operations should be the full name of the containing namespace. For example, the full name of the __Elastos.Core.IThread__ interface is __LElastos/Core/IThread__.

Specific usage can refer to the example.

> ### Reference count

The types of supported reference counts in the __CAR__ data type include the __String__ type, __ArrayOf__ type, and interface type.

For user-implemented classes, the reference count of function can be increased by inheriting the __Object__ or __ElLightRefBase__ classes.

> ### Smart pointer(AutoPtr)

For the sake of simplifying the type of reference count operations and guaranteeing the correctness of the reference count operation, it is recommended to use the smart pointer __`AutoPtr`__. Also, the `AutoPtr<...>` variable does not have to explicitly assign a NULL value.

For methods that need to return an interface pointer or an object pointer, it is recommended to use __AutoPtr__ as the return value instead of returning the raw pointer directly. E.g:

``` cpp
// Foo.h
AutoPtr<IFoo> GetFoo();
```

Also, when calling the method that returns __AutoPtr__, in order to prevent the object pointed to by the returned pointer from being released early, you need to use the __AutoPtr__ type variable (instead of the raw pointer variable) to receive the return value.

``` cpp
ECode CFoo::GetFoo(
    /* [out] */ IFoo** foo)
{
    VALIDATE_NOT_NULL(foo);
    *foo = Foo::GetFoo();
    // return ptr may be released already!
    INTERFACE_ADDREF(*foo);
    return NOERROR;
}
```

The correct implementation is as follows:

``` cpp
ECode CFoo::GetFoo(
    /* [out] */ IFoo** foo)
{
    VALIDATE_NOT_NULL(foo);
    AutoPtr<IFoo> temp = Foo::GetFoo();
    *foo = temp;
    INTERFACE_ADDREF(*foo);
    return NOERROR;
}
```

When using the same __AutoPtr__ variable multiple times in a loop to receive the out parameter of a method, you need to be careful about reference counting leaks.

``` cpp
AutoPtr<IInterface> obj;
while (...) {
    GetObject((IInterface**)&obj); // memory leak!
    ...
}
```

The correct way to handle this is to explicitly call `obj = NULL;` before calling `GetObject` to clear the contents of the last store, as follows:

``` cpp
AutoPtr<IInterface> obj;
while (...) {
    obj = NULL;
    GetObject((IInterface**)&obj);
    ...
}
```

Or define the variable in the loop body as follows:

``` cpp
while (...) {
    AutoPtr<IInterface> obj;
    GetObject((IInterface**)&obj);
    ...
}
```