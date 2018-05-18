# CAR Language

> ## 1.简介

本文主要讲述 __CAR__ 的语法，比如类，接口，方法，参数，继承关系，构造函数等等.

> ## 2.数据类型

这里讨论的是 __CAR__ 数据类型，即是可以在 `.car` 中使用的数据类型。

__CAR__ 数据类型包括基本数据类型、结构体类型(__struct__)、__ArrayOf__ 类型、__EMuid__ 类型、__EGuid__ 类型、__String__ 类型以及接口类型。具体类型定义如下表所示。

| 类型                            | 说明                        |
|:------------------------------:|:--------------------------:|
| Char32                         | 32位字符型                   |
| Boolean                        | 布尔型                       |
| Byte                           | 无符号字节型                  |
| Int8                           | 8位有符号整型                 |
| Int16                          | 16位有符号整型                |
| Int32                          | 32位有符号整型                |
| Int64                          | 64位有符号整型                |
| UInt16                         | 16位无符号整型                |
| UInt32                         | 32位无符号整型                |
| UInt64                         | 64位无符号整型                |
| Float                          | 单精度浮点型                  |
| Double                         | 双精度浮点型                  |
| ECode                          | 返回值类型                    |
| EMuid                          | 128位UUID                   |
| EGuid                          | 128位UUID+UUNM              |
| String                         | 字符串类型                    |
| ArrayOf                        | 数组类型                     |
| PVoid                          | void*类型                    |
| enum xxx                       | 枚举类型                     |
| interface Ixxx                 | 接口类型                     |

> ### 2.1.基本数据类型

__CAR__ 使用 __Char32__ 为字符类型，它能够表示所有的 __UNICODE__ 字符。C/C++、Java 的 __char__ 类型可以方便的显式转换为 __Char32__ 类型。

为了兼容已有的程序，Elastos 的 C++ 代码保留 16 位的字符型 __Char16__ ，并提供 __Char16__ 数组与 __Char32__ 数组之间的转换。

枚举成员的名字均为大写，并以该枚举的名字大写为前缀，若名字中包含多个单词，请用下划线连接起来。例如 `BitmapConfig_ALPHA_8`。

> ### 2.2.String 类型

__CAR__ 使用 __String__ 类型表示字符串。__String__ 类型采用 __UTF-8__ 编码方式，使用堆内存存储所表示的字符串内容，并支持引用计数来管理自身的生命周期。

> ### 2.3.ArrayOf 类型

__ArrayOf__ 实现了类似数组的功能，即在一块连续的内存中存储若干个元素。如果将 __CAR__ 对象指针、继承自 __Object__ 或者 __ElLightRefBase__ 类的对象指针以及 __String__ 对象作为 __ArrayOf__ 的元素，那么调用其 `Set(Int32 index, T const other)` 方法设置元素时，__ArrayOf__ 能对它们进行自动化引用计数管理，但是，通过下标 __`[]`__ 操作进行赋值并不会自动进行引用计数管理。

对于适用于 `AutoPtr<T>` 的类型T，该类型的指针可以直接作为 __ArrayOf__ 的元素类型，即使用 `ArrayOf<T*>` 的形式，而非 `ArrayOf< AutoPtr<T> >` 的形式。

__ArrayOf__ 创建时会调用 `memset` 将分配到的内存清零，并且自身也实现了引用计数。其引用计数增减规则说明如下：

* 创建操作(__`Alloc()/Clone()`__)：

    创建或克隆一个新对象，新对象的引用计数为 0，返回的新对象需要加入 __AutoPtr__ 自动释放或手动调用 `Free()/Release()` 释放。

* 减少引用计数操作(__`Free()/Release()`__)：

    `Free()/Release()` 这两个方法等价，为保证一致性推荐使用 `Release()` ，或加入AutoPtr由其在内部调用 `Release()` 自动减少引用计数。

* 增加引用计数操作(__`AddRef()`__)：

    将一个 __ArrayOf__ 指针赋值给一个AutoPtr变量时，后者将在内部调用 `AddRef()` 增加引用计数。如果需要手动增加引用计数，请使用宏 `INTERFACE_ADDREF()`。

__ArrayOf__ 支持分配0个元素，即调用 `ArrayOf<T>::Alloc(0)`，此时，针对返回的 __ArrayOf__ 对象，调用其 `GetLength()` 方法将获得0。

__ArrayOf__ 的几种典型用法如下：

* 一般场景

    ``` cpp
    // ThreadGroup.cpp
    AutoPtr<ArrayOf<IThread *> > newThreads;
    newThreads = ArrayOf<IThread *>::Alloc(mNumThreads * 2);
    newThreads->Copy(mChildrenThreads, 0, mNumThreads);
    newThreads->Set(mNumThreads++, thread);
    mChildrenThreads = newThreads;
    ```

* 作为 CAR 方法的 __out, callee__ 参数

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

    // 调用方
    AutoPtr<IPackageInfo> info;
    ...
    AutoPtr< ArrayOf<IActivityInfo*> > activities;
    info->GetActivities((ArrayOf<IActivityInfo*> **)&activities);
    ```

* 作为 C++ 方法返回值

    ``` cpp
    // CHardwareCamera.h
    AutoPtr< ArrayOf<IInteger32*> > SplitInt(
        /* [in] */ const String& str);
    ```

对于 __双重数组__，请使用 `AutoPtr< ArrayOf< AutoPtr< ArrayOf<T> > > >` 形式。为了简化代码的编写，可以参考以下两种方法(实现在 __elquintent.h__ 文件中)：

* 使用模板类。该方法通用性好，但可读性欠佳。

    ``` cpp
    // 定义：elquintent.h
    template <typename T> class ArrayOf2 {
    public:
        typedef AutoPtr<ArrayOf<T> > ElementType;
        typedef ArrayOf<ElementType> Type;
    }
    ```

* 使用在 __elquintent.h__ 文件中通过 __typedef__ 预定义的类型。该方法可读性好，但不能通用。

    ``` cpp
    // 定义：elquintent.h
    typedef AutoPtr<ArrayOf<Byte> >     ByteArray;
    typedef AutoPtr<ArrayOf<Char32> >   Char32Array;
    typedef AutoPtr<ArrayOf<String> >   StringArray;
    typedef AutoPtr<ArrayOf<Int32> >    Int32Array;
    typedef AutoPtr<ArrayOf<Int64> >    Int64Array;
    typedef AutoPtr<ArrayOf<Float> >    FloatArray;
    typedef AutoPtr<ArrayOf<Double> >   DoubleArray;

    // 使用：View.h
    static const AutoPtr<ArrayOf<Int32Array> > VIEW_STATE_SETS;
    ```

> ### 2.4.CAR 接口(interface)

接口(interface)是用来定义一种程序的协定。实现接口的类或者结构要与接口的定义严格一致。有了这个协定，就可以抛开编程语言的限制(理论上)。接口可以从多个基接口继承，而类或结构可以实现多个接口。接口可以包含方法、属性、事件和索引器。接口本身不提供它所定义的成员的实现。接口只指定实现该接口的类或接口必须提供的成员。

接口好比一种模版，这种模版定义了对象必须实现的方法，其目的就是让这些方法可以作为接口实例被引用。接口不能被实例化。类可以实现多个接口并且通过这些实现的接口被索引。接口变量只能索引实现该接口的类的实例。

参考示例可以查看:[Car文件结构](#4.1.Car文件结构)。

上面例子中的接口包含各自的接口方法。
__CAR__ 接口不支持多重继承，也就是构件类定义不可以继承自其它构件类。 类和结构可以多重实例化接口，就是一个接口定义可以被多个类定义所引用。

说明:

* __CAR__ 中的接口是独立于类来定义的。这与 C++ 模型是对立的，在 C++ 中接口实际上就是抽象基类。
* 类可以继承多个接口。
* 而类可以继承一个基类，接口根本不能继承类。这种模型避免了 C++ 的多继承问题，C++ 中不同基类中的实现可能出现冲突。因此也不再需要诸如虚拟继承和显式作用域这类复杂机制。C# 的简化接口模型有助于加快应用程序的开发。
* 一个接口定义一个只有抽象成员的引用类型。__CAR__ 中一个接口实际所做的，仅仅只存在着方法标志，但根本就没有执行代码。这就暗示了不能实例化一个接口，只能实例化一个派生自该接口的对象。

接口具有引用计数功能，应当通过引用计数或者借助 __AutoPtr__ 来管理接口的生命周期。

> ### 2.5.IInterface 接口

__`IInterface`__ 接口是所有接口的(直接或间接)父接口，如果在 `.car` 中定义接口时没有指定其父接口，那么 __CAR__ 编译器就会默认指定 __`IInterface`__ 接口为该接口的父接口。

由于 __`IInterface`__ 接口是所有接口的父接口，所以一个实现了多个接口的对象有多个地址不同的 __`IInterface`__ 接口，因此如果通过 __`IInterface`__ 接口来进行对象判等，则判等的两个对象都需要 `Probe` 出 __`IInterface`__ 接口再比较。对象的 `Equals` 方法中较多涉及此情景。

如何 `Probe`，请参考示例[Car类继承](#10.1.Car类继承)。

> ### 2.6.返回类型

 __CAR__ 文件中所有的方法其函数返回类型均默认为 `ECode`。所以在 Car 中声明定义的时候，无需再次指明。而在头文件中定义的时候，其函数返回类型写成 `CARAPI`，在cpp实现文件中可直接写成 `ECode`。

`ECode` 是一个32位二进制整数。`ECode` 高16位中，最高位表示方法调用错误(1)或成功(0)；其余15位表示具体的错误信息，例如:接口错误、驱动错误、CRT错误、文件系统错误、图形系统错误等。对于许多 CAR 兼容的实现语言(例如:Visual Basic、Java)而言，这些 `ECode` 被运行时库或者虚拟机截取，然后被映射为语言中特定的异常(exception)。`ECode` 低16位用作调试和测试用。

 __CAR__ 中提供以下两个宏，使用这两个宏可以通过判断 ECode 返回值得知方法调用是否成功：

| 宏定义               | 含义                      |
|:-------------------:|:------------------------:|
| SUCCEEDED(ec)       | 判断方法调用是否成功         |
| FAILED(ec)          | 判断方法调用是否失败         |

在 Elastos 中做开发，无论是 C++ 类，还是 Car 类，当需要声明非接口中的方法时，如果返回不是 `ECode`，也请遵循规则：返回值类型在头文件中需写成：`CARAPI_(XXX)`，其中 XXX 指的是返回值类型。比如要返回 `Int32`，则在头文件中写成 `CARAPI_(Int32)`。

> ## 3.关键字
> ### 3.1.Car 基本关键字

关键字也称保留字。它是预先定义好的表示符，这些表示符对 __CAR__ 编译程序有着特殊的含义。下面对 __CAR__ 中几个主要关键字的含义和表示方法一一进行介绍。

* 用于定义构件的关键字:

    | 关键字           | 描述                        |
    |:---------------:|:---------------------------:|
    | module          | 用于指定.dll形式的构件         |
    | library         | 用于指定.lib形式的构件         |

* 用于定义接口的关键字：

    | 关键字           | 描述                        |
    |:---------------:|:---------------------------:|
    | interface       | 用于定义或声明一个接口         |
    | callbacks       | 用于定义或声明一个异步回调接口   |
    | delegates       | 用于定义或声明一个同步回调接口   |

* 用于定义类的关键字：

    | 关键字           | 描述                        |
    |:---------------:|:---------------------------:|
    | class           | 用于定义一个普通构件类         |
    | generic         | 用于定义一个泛类              |
    | applet          | 用于定义一个applet类          |
    | aspect          | 用于定义一个方面构件类         |
    | context         | 用于定义一个语境类            |

* 用于继承的关键字：

    | 关键字           | 描述                                    |
    |:---------------:|:--------------------------------------:|
    | clasinheritss   | 用于表示普通类class继承普通类class         |
    | extends         | 表示接口interface继承接口interface        |
    | final           | 用于修饰普通构件类class，表示该类不允许被继承 |
    | substitutes     | 用于表示普通类class继承泛类generic         |

* 用于修饰接口的关键字：

    | 关键字           | 描述                                                               |
    |:---------------:|:-----------------------------------------------------------------:|
    | virtual         | 用于修饰interface,表示声明虚接口                                      |
    | asynchronous    | 用于修饰interface,表明被修饰的interface的接口的方法将被异步方式调用        |
    | privileged      | 用于修饰interface,并只能用于aspect中，指定其接口只能在聚合和解聚合的时候可见 |
    | filtering       | 用于修饰callbacks接口，表示子类过滤基类所触发的回调事件                    |

* 用于修饰类的关键字：

    | 关键字           | 描述                                                                    |
    |:---------------:|:----------------------------------------------------------------------:|
    | singleton       | 用于表示该类只能创建出唯一的对象                                             |
    | aggregates      | 表示被修饰的构件类创建对象时将自动聚合该属性中列举的方面构件对象                   |
    | pertainsto      | 用于修饰语境构件类context，表示该语境构件类拥有该属性中列举的方面构件类            |
    | affiliates      | 用于修饰方面构件类aspect，表示被修饰的方面构件类只能被该属性中列举的非方面构件类聚合  |

* 用于定义数据结构的关键字：

    | 关键字           | 描述                                          |
    |:---------------:|:--------------------------------------------:|
    | const           | 用于定义int类型的常量                           |
    | enum            | 用于定义枚举类型，使用方法与其在C语言中用法基本相同   |
    | struct          | 用于定义结构体，其使用方法与在C语言中用法基本相同     |
    | typedef         | 用于定义类型，其使用方法与在C语言中用法基本相同       |

* 用于合并构件的关键字：

    | 关键字           | 描述                                                                        |
    |:---------------:|:--------------------------------------------------------------------------:|
    | merge           | 用于在本构件中合并用到的其它构件(.car文件)                                       |
    | import          | 指定本构件中用到的其它构件（.car文件）                                           |
    | importlib       | 指定本构件中用到的其它构件（.dll或者.cls）                                       |

* 其它关键字：

    | 关键字           | 描述                                             |
    |:---------------:|:-----------------------------------------------:|
    | constructor     | 用于在类中定义构造函数                              |
    | pragma          | 禁止或允许显示CAR编译器给出的警告信息                 |
    | coalesce        | 用于在类中修饰callbacks接口方法，表示合并同类回调事件   |

> ### 3.2.Car 属性关键字

__CAR__ 属性用于修饰 __CAR__ 中构件类、接口等各个部分的内容。下面对 __CAR__ 中所支持的各属性的含义及其表示方法进行介绍。

* 用于修饰构件的属性：

    | 属性                       | 描述                       |
    |:-------------------------:|:--------------------------:|
    | version                   | 用于标识构件的版本号           |

* 用于修饰普通类的属性：

    | 属性                 | 描述                                                                  |
    |:-------------------:|:---------------------------------------------------------------------:|
    | synchronized        | 用于标识构件对象同时只允许一个线程进入到构件的实现代码中，其它访问该构件对象的线程将被阻塞等待（一旦线程调用到对象方法内，在从对象方法返回之前，其它线程对该对象的访问均会被阻塞）                     |
    | sequenced           | 用于标识构件对象同时只允许一个线程进入到构件的实现代码中，其它访问该构件对象的线程将被阻塞等待（对象方法访问其它对象时临时释放锁，允许其它线程进入对象）                                           |
    | private             | 用于标识所修饰的类只能在服务端被实例化                                       |
    | local               | 用于修饰带有constructor（内有非自描述参数）的类                              |
    | deprecated          | 用于兼容移植来的第三方软件中不符合CAR规范的数据类型使用                         |
    | applet              | 此属性用于修饰类，表示该类接口方法的调用具有类似于applet的接口方法行为            |

* 用于修饰接口的属性：

    | 属性                  | 描述                                                            |
    |:--------------------:|:---------------------------------------------------------------:|
    | local                | 表示提供该接口的类的类对象与客户程序只能在相同的域内使用，不能用于远程调用   |
    | deprecated           | 用于兼容移植来的第三方软件中不符合CAR规范的数据类型使用                  |

* 用于修饰接口方法参数的属性：

    | 属性                        | 描述                                   |
    |:--------------------------:|:--------------------------------------:|
    | in                         | 用于标识该参数为输入参数                   |
    | out                        | 用于标识该参数为输出参数                   |
    | callee                     | 用于修饰五元组，表示该参数由客户端程序分配    |

> ## 4.Car 构件组成
> ### 4.1.Car 文件结构

一个 __CAR__ 文件（扩展名为.car）对应一个 `module` 或 `library`。__CAR__ 文件的结构主要由构件类，接口和接口方法组成。每个 __CAR__ 构件都由若干类组成，每个类实现若干接口，每个接口中定义若干方法。例如：`HelloDemo.car`文件。

``` cpp
module　　　　　//构件HelloDemo
{
    //接口IHello
    [local]　　　　　　　　 //接口属性　local
    interface IHello {
        Hello(
            [in] Int32 id);  //方法
    }

    //接口IHey
    interface IHey {
        Hey(
            [in] Int32 id,
            [out] String* wtrBuf);
    }

    //类CHello1
    class CHello1 {
        constructor();

        constructor(
            [in] Int32 age);

        interface IHello;
        interface IHey;
    }

    //类CHello2
    class CHello2 {
        interface IHello;

    }
    //类CHello3
    class CHello3 {
        interface IHey;
    }
}
```

注：__CAR__ 文件中使用双斜杠“//”作为语句注释符。

> ### 4.2.Car 文件语法

在 __CAR__ 文件中，对构件、接口、类等的定义都包括两个部分：属性和定义。

__CAR__ 属性：位于方括号“[]”中，多个属性之间以逗号“,”作为分隔符；对构件、接口、类、类别等的定义位于花括号“{}”中。属性总是出现在相应主题的定义之前。

构件：在一个 __CAR__ 文件中只能有一个构件的定义。在 __CAR__ 中可以使用关键字 `module` 定义生成动态链接库 `.dll` 形式的 car 构件，也可以用关键字 `library` 定义生成静态链接库 `.lib` 形式的 car 构件。

> ### 4.3.Car 文件编译

* 编译一个 __CAR__ 文件主要分为四个步骤：

  * 编写 .car 文件，声明方法、接口、类和构件
  * 调用 `emake xxx.car` 生成前台代码框架
  * 在前台代码框架中编写实现代码
  * 调用 `emake` 生成后台代码，然后编译链接成构件(.dll或.lib)

* 自动生成前台代码框架：

    __Car__ 编译器主要包括四个工具：`carusage`（目前弃用）、 `carc`、 `lubc` 和 `lube`。简单来说，`carc` 工具是用来编译.car文件的； `lubc` 工具用来编译.lub模板的； `lube` 工具根据模板产生代码。其中 `lub` 模板是由一组特定规则组成的扩展名为 `lub` 的文件。可以使用命令 `xxx -?` 分别查看这些工具的使用说明。例如命令 `carc -?` 会列出 `carc` 工具的使用方法。

    进入 __CAR__ 编译环境，找到要编译的 car 文件所在目录，然后输入 `emake xxx.car` 后，将首先使用 `carc` 工具在当前目录下（可以指定目录）生成 `xxx.car` 文件对应的 `xxx.cls` 文件，该文件主要包括元数据的信息，编译时这些信息被打包到 `dll` 中。元数据，是一种描述数据的数据。__CAR__ 构件中的元数据主要包括模块信息（ModuleInfo），接口信息（InterfaceInfo），类信息（ClassInfo）等。这些信息是在 __CAR__ 文件编译后得到，是 __CAR__ 文件的二进制表述。

    然后使用 `lube` 工具根据刚才生成的 `xxx.cls` 文件，按照 `foreground.lub` 模板生成构件的前台代码框架，即为构件中定义的所有类生成该类对应的 `xxx.cpp` 和 `xxx.h` 文件，此外还包括 `CMakeLists.txt` 文件和 `xxx.camke` 文件。这些文件的含义如下：

        xxx.h            .car文件中定义的类对应的头文件

        xxx.cpp          .car文件中定义的类对应的C++实现代码文件

        CMakeLists.txt   用于指定如何编译源代码，生成什么类型的目标文件等信息

        xxx.camke        用于定义cmake编译相关变量。变量的值是编译car文件时，在镜像目录生成的头文件和cpp文件的列表

* 自动生成后台代码框架：

    在前台代码框架中填充实现代码后，执行 `emake` 命令，将首先使用 `carc` 工具在镜像目录下生成扩展的 `xxxEx.cls` 文件。相比较前台代码框架生成使用的 `xxx.cls` 文件，该扩展 `xxxEx.cls` 文件增加了一些额外的接口和类。然后使用 `lube` 工具，按照 `header.lub`、 `public.lub`、 `background.lub`、 `cls2abrg.lub` 等模板生成后台代码框架，最后编译链接成 `xxx.dll`（或`xxx.lib`）。

* 自动生成代码框架的优点：

    编译环境自动生成代码的主要作用是封装和抽象构件的编写和使用，让用户更方便的开发和使用 __CAR__ 构件。

    用 car 书写 __CAR__ 构件接口描述文件简单方便。Hello 构件虽然接口简单，但如果用户用 C++ 编写，仍然要考虑到许多技术细节。采用car语言编写构件，不仅简单而且让用户更加习惯构件编程的思维方法，不纠缠于内部的技术细节。

    自动生成元数据。__CLS__ 文件是 __CAR__ 文件压缩后的样式库，里面描述了整个构件的接口、类、方法、结构、枚举等的定义。有了 `cls` 文件，就可以得到该构件的接口，函数的调用方法，甚至生成源码框架。在链接生成构件的时候，将 `cls` 也放入构件中，这样就等于将一本说明书和构件捆绑在一起。无论构件被复制移动到哪里，都可以知道该构件该如何使用。

    许多构件的重要组成部分，比如类厂，DLL中的注册函数等，都由编译环境自动生成，不必用户再手工实现。

> ## 5.CAR 类

在 .car 文件中声明的类称为 __CAR__ 类，而只在 .h 文件或 .cpp 文件中声明或定义的类称为 C++ 类。

__Car__ 类和 C++ 类在定义的时候，使用的关键字不同。

C++ 类是使用关键字 `class` 定义的：

``` cpp
class B
    ：public A
{
    ...
};
```

而Car 类是使用关键字 `CarClass` 来定义的：

``` cpp
CarClass(CDemo)
    ，public A
{
    ...
    // 可使用 Elastos 定义的宏简化书写
};
```

Car 类必须要在 .car 文件中声明。

> ## 6.CAR 构造函数(constructor)
> ### 6.1.C++ 默认构造函数

1. 每个类必须有一个构造函数，否则没法创建对象;
2. 若 programer 没有提供任何构造函数，则 C++ 提供一个默认的构造函数，该默认构造函数是无参构造函数，它仅负责创建对象，不做任何初始化的工作;
3. 只要 programer 定义了一个构造函数(不管是无参还是有参构造)，C++ 就不再提供默认的构造函数。即如果为类定义了一个带参的构造函数，还想要无参构造函数，就必须自己定义;
4. 与变量定义类似，在用默认构造函数创建对象时，如果创建的是全局对象或静态对象，则对象的位模式全为 0，否则，对象值是随机的。

* 注:
  * 如 2 所述，C++ 在某些情况下会提供默认构造函数，但在某些情况下并不会自动调用。
  * 事实上，当用户没有提供自定义的构造函数的时候，声明该类的对象，以及定义包含该对象的数组，都不会调用默认构造函数；但定义包含该对象的容器时，会自动调用默认的构造函数。

> ### 6.2.CAR 类构造方法

对于一个 __CAR__ 类 `CXXX`而言，它有两种构造方法，一种是 C++ 构造方法 `CXXX()`，另一种是 __CAR__ 构造方法 __`constructor()`__ 。后者本质上是一个普通的 C++ 方法。

它们的相似点是：

* 如果没有提供自定义的实现则都会提供一个默认的无参的实现。
* 都支持构造函数重载。

它们的不同点是：

* C++ 构造方法支持初始化列表，而 __CAR__ 构造方法不支持。
* 在 C++ 构造方法执行时，该对象还未就绪，而 __CAR__ 构造方法执行时，对象已经就绪。

因此，我们可以利用 C++ 构造方法的初始化列表初始化成员变量。

对于实现了 __IParcelble__ 接口的 __CAR__ 类而言，它必须有一个无参的 __CAR__ 构造方法 __`constrctor()`__ （无论是默认提供的，还是显式声明的），这是为了支持该对象的散集(unmarshall)。散集时，先调用该构造方法创建对象，然后再转型为 __IParcelble__ 接口，调用`IParcelble::ReadFromParcel()`设置对象成员变量。因此，Elastos 里规定，凡是实现了 __IParcelable__ 接口的 __CAR__ 类都必须显式声明一个无参的 __CAR__ 构造方法。例如：

使用范例：

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

如何 new 一个 car 对象，以及如何调用接口中的方法，请参考下面的例子：

``` cpp
AutoPtr<IHello> helloobj1, helloObj2;
CHello::New((IHello**)&helloobj1);
CHello::New(18, String("andy"),(IHello**)&helloobj);
helloobj->Hello();
helloobj2->Hello();
```

另外，Elastos 规定对于非单例的 __CAR__ 类，若该类没有显式的声明 `constructor` ，则需要显式的声明无参的 `constructor`。

> ## 7.CAR 唯一实例(singleton)

保证一个 __CAR__ 类 在一个 Elastos 环境中只有一个实体(Instance、Object)，可以用 __CAR__ 关键字 `singleton` 来达到目的。

语法:

singleton class className classBody;

使用说明:

* singleton 修饰的构件类只能拥有不带参数的构造函数。
* Singleton 不能修饰aspect构件类。
* singleton 可以和关键字 final 同时修饰构件类，使用顺序是 singleton 在前，final 在后。

使用范例：

示例 singletonDemo.car 文件如下:

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

如何new一个单一例对象，以及如何调用接口中的方法，请参考下面的例子：

``` cpp
AutoPtr<IFoo> foo;
CFoo::AcquireSingleton((IFoo**)&foo);
foo->Hello();
```

上述示例定义了一个具有 singleton 属性的类 `CFoo`。

注意：可以利用 __CAR__ 的 singleton 这种机制实现实例间数据的共享。

> ### 8.Object 类

Elastos 定义了 Object 类，该类实现了以下功能：

* 支持引用计数管理生命周期。
* 支持弱引用，实现了 __IWeakReferenceSource__ 接口。
* 实现了 __IObject__ 接口，支持 `Equals()`、`GetHashCode()` 以及 `ToString()` 等方法。
* 实现了 __ISynchronize__ 接口，支持 `Lock()`、`Unlock()`、`Wait()` 以及 `Notify()` 等方法。

当编写一个 C++ 类(全部成员是静态成员的类除外)或者 __CAR__ 类时，请将 Object 类作为其基类，可以直接或者间接继承 Object。Object 的子类可以按需重载 `Equals()`、 `GetHashCode()` 以及 `ToString()` 方法，__CAR__ 类还需重载 `GetClassID()` 方法。

为方便调试，子类需重视 `ToString()` 方法的实现。一般的，`ToString()` 方法返回该对象所属类的类名。对于 __CAR__ 类，Object 基类的 `ToString()` 方法可以通过反射获取类名，因此，如无其它需求，__CAR__ 类无需重载该方法。而 C++ 类请 __重载__ 该方法，在实现中返回类名。

所有 __CAR__ 类都默认实现了 __IObject__、__ISynchronize__ 和 __IWeakReferenceSource__ 接口，在 .car 文件中声明 __CAR__ 类时，不用显式的声明这些接口，它们将由 __CAR__ 编译器自动加入到 __CAR__ 类实现的接口中去。

> ## 9.预定义宏

在编写实现 __Car__ 接口的类时，需要实现四个纯虚函数: `Probe`、`AddRef`、 `Release` 和 `GetInterfaceID`。为简化操作 Elastos 预定义了若干宏以方便开发，说明如下：

* __REFCOUNT_ADD__ 引用计数加一，__REFCOUNT_RELEASE__ 引用计数减一。
* __CAR_INTERFACE_DECL__ 声明接口的四个基本方法，__CAR_INTERFACE_IMPL__ 定义接口的四个基本方法，接口实现类(C++ 类或 __CAR__ 类)可使用它们。
* __CAR_OBJECT_DECL__ 声明非单例的 __CAR__ 类的基本方法，__CAR_OBJECT_IMPL__ 定义非单例的CAR类的基本方法，非单例的 __CAR__ 类可使用它们。
* __CAR_SINGLETON_DECL__ 声明单例 __CAR__ 类的基本方法，__CAR_SINGLETON_IMPL__ 定义单例 __CAR__ 类的基本方法，单例的 __CAR__ 类可使用它们。

使用自动生成代码框架，这些宏可以在头文件和 cpp 文件中自动生成（除了`REFCOUNT_ADD`、`REFCOUNT_RELEASE`）。

> ## 10.继承
> ### 10.1.Car 类继承

Elastos 之前版本按照 Java 中类的继承关系来定义系统中接口间的继承关系。比如， __IActivity__ 接口继承 __IContextThemeWrapper__ 接口。

接口继承的好处是便于开发，通过 __IActivity__ 接口就可以调用 __IContextThemeWrapper__ 接口中的方法。

但接口继承也有比较大的弊端，其一是若 Java 代码中，一个类实现了多个接口，那么Elastos 中应该继承哪个接口并没有相应的标准。其二是会导致代码的冗余。例如，实现 __IActivity__ 接口的类可以继承实现 __IContextThemeWrapper__ 的类，但即使前者没有重新定义 __IContextThemeWrapper__ 接口中的任何方法，仍然需要将该接口中的所有方法都封装一下，转调基类的相应方法。

目前 Elastos 取消了接口间的继承。开发时不能通过一个接口支持所有方法，而是要 __Probe__ 出相应的接口再调用。例如， __IActivity__ 接口不再继承 __IContextThemeWrapper__ 接口，因此不能通过 __IActivity__ 接口调用 __IContextThemeWrapper__ 里的方法，而是要从 __IActivity__ 接口 __Probe__ 出 __IContextThemeWrapper__ 接口再调用。

取消接口间的继承后，实现某个接口往往伴随着要实现其它接口。例如，实现 __IActivity__ 接口的类应该也实现 __IContextThemeWrapper__ 接口，而实现 __IContextThemeWrapper__ 接口也应该实现 __IContextWrapper__ 接口，而实现 __IContextWrapper__ 接口也应该实现 __IContext__ 接口。这些要同时实现的接口，在 __IActivity__ 接口的声明中都无法体现出来。因此，我们规定需要在其声明的头部加上一定的注释，注明这些要同时实现的接口。

请参考下面的示例。

car 文件内容如下：

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

在这里，我们是想让接口 __IFoo2__ 继承接口 __IFoo__ ，所以在声明接口 __IFoo2__ 前面加上注释；然后在实现接口 __IFoo2__ 的类 __CFoo2__ 中同时实现接口 __IFoo__ 。编写完 car 文件后，通过自动生成代码框架来生成其他文件，比如下面罗列的头文件和 cpp 文件。

CFoo2.h 文件内容如下：

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

CFoo2.cpp 内容如下：

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

然后补充实现代码：在头文件的private部分，增加一个成员变量。

``` cpp
Int32 mAge;
```

在cpp文件中补充实现：

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

下面举例怎么使用：

``` cpp
AutoPtr<IFoo2> fobj;
CFoo2::New(17, (IFoo2**)&fobj);
String str;
fobj->Hello(&str);
Int32 age;
IFoo::Probe(fobj)->GetAge(&age);

//也可以像下面这样：

AutoPtr<IFoo> fobjOther;
CFoo2::New(10, (IFoo**)&fobjOther);
Int32 age;
fobjOther->GetAge(&age);
String str;
IFoo2::Probe(fobjOther)->Hello(&str);
```

> ### 10.2.C++ 类继承

在 .car 文件中声明的类称为 __CAR__ 类，而只在 .h 文件或 .cpp 文件中声明或定义的类称为 C++ 类。

Elastos 简化了 __CAR__ 编译器生成的代码，优化了 Elastos 中 C++ 代码的类继承结构。因此，可以为 C++ 类和 __CAR__ 类赋予不同的职责，C++ 类用于实现代码逻辑，而 __CAR__ 类用于封装元信息到 C++ 类中。因此，C++ 类可以被 C++ 类和 __CAR__ 类继承，而 __CAR__ 类不能再被C++类或CAR类继承。

目前Elastos中的继承关系，比如：CButton 控件的继承关系为 __`CButton-->Button-->TextView-->View-->Object`__ ，而 CTextView 控件的继承关系为 __`CTextView-->TextView-->View-->Object`__ 。

对于只包含静态成员方法的类，实现时可以分成 C++ 类和 __CAR__ 类，C++ 类实现成静态类(方法都是静态方法)，__CAR__ 类实现成单例(singleton)类，并在 __CAR__ 类的方法实现中调用 C++ 类的静态方法。

例子可参考[CAR Programming](How_To_Write_A_Car_Component.md)

> ## 附录
> ### 命名空间

__CAR__ 支持命名空间以减少命名冲突。

反射操作时使用的名称应当是包含命名空间的全名。例如， __Elastos.Core.IThread__ 接口的全名是 __LElastos/Core/IThread__。

具体用法，可参考示例。

> ### 引用计数

__CAR__ 数据类型中支持引用计数的类型包括 __String__ 类型、__ArrayOf__ 类型、接口类型。

对于用户自己实现的类，可以通过继承 __Object__ 或者 __ElLightRefBase__ 类增加引用计数功能。

> ### 智能指针(AutoPtr)

为简化类型的引用计数操作以及保证引用计数操作的正确性，推荐使用智能指针 __AutoPtr__。并且，`AutoPtr<...>` 变量不必显式的赋 NULL 值。

对于需要返回接口指针或者对象指针的方法，建议使用 __AutoPtr__ 作为返回值，而不是直接返回裸指针。例如：

``` cpp
// Foo.h
AutoPtr<IFoo> GetFoo();
```

并且，当调用返回 __AutoPtr__  的方法时，为避免返回的指针所指的对象被提前释放，需使用 __AutoPtr__  类型变量(而不是裸指针变量)接收返回值。

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

正确的实现如下：

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

在循环中使用同一个 __AutoPtr__  变量多次接收方法的 out 参数时需要小心引用计数泄漏问题。

``` cpp
AutoPtr<IInterface> obj;
while (...) {
    GetObject((IInterface**)&obj); // memory leak!
    ...
}
```

正确的处理方式是在调用 `GetObject` 前显式的调用 `obj = NULL;` 以清除上一次存储的内容，如下：

``` cpp
AutoPtr<IInterface> obj;
while (...) {
    obj = NULL;
    GetObject((IInterface**)&obj);
    ...
}
```

或者将变量定义在循环体内，如下：

``` cpp
while (...) {
    AutoPtr<IInterface> obj;
    GetObject((IInterface**)&obj);
    ...
}
```