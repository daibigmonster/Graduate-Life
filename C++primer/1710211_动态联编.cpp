/*
 * 程序调用函数时，将使用哪个可执行代码块呢？编译器负责回答这个问题，将源代码中的函数调用解释为执行特定的函数代码块称为
 * 函数名联编(binding).在C语言中，这非常简单因为每个函数名都对应一个不同的函数。在C++中这项任务更复杂，编译器必须查看函数参数及
 * 函数名才能确定使用哪个函数。然而，C/C++编译器可以在编译的过程完成这种联编。在编译过程中进行联编被称为静态联编，又称为
 * 早期联编。然而，虚函数使这项工作变得困难。正如程序清单13.10所示的那样，使用哪一个函数式不能再编译时确定的，因为编译器不知道
 * 用户将选择哪种类型的对象，所以编译器必须生成能够在程序运行时选择正确的虚方法的代码，这成为动态联编，又称为晚期联编
 *
 * 将派生类引用或指针转换为基类引用或指针被称为向上强制转换，这使公有继承不需要进行强制的显示类型转换。
 * 该规则是is-a的一部分。BrssPlus对象都是Brass对象，因为它继承了Brass对象的所有的数据成员和成员函数。
 * 所以，可以对Brass对象执行任何操作，都适用于BrassPlus对象。因此，为处理Brass而引用而设计的函数可以对BrassPlus对象间执行同样
 * 的操作，而不必担心会导致任何问题，将指针对象的指针作为函数参数时，也是如此	，向上强制转换时可传递的，也就是说，如果从BrassPlus
 * 派生出BrassPlusPlus对象。
 * 相反的过程——将基类指针或引用转换为派生类指针或引用——称为向下强制转换。如果不适用显示类型转换，则向下强制转换是不允许的。
 * 原因是is-a关系通常是不可逆的。派生类可以新增数据成员，因此使用这些数据成员可能应用于基类。例如，假设从Employee类派生出Singer
 * 类，并添加了表示歌手音域的数据成员和报告音域的值的成员函数range(),则将range()方法应用于Employee对象时没有意义的。但如果允许
 * 隐式向下强制转换，则可能无意间将指向Singer的指针设置为一个Employee对象的地址，并使用该指针来调用range()方法。
 * 对于使用基类引用或指针作为参数的调用，将进行向上转换。
 *
 * 隐式向上强制转换时基类指针或引用可以指向基类对象或派生类对象，因此需要动态联编，C++使用虚成员函数来满足这种需求
 *
 * 虚成员函数和动态联编
 * 来回顾一下使用引用或指针调用方法的过程，请看下面的代码
 * BrassPlus ophelia;
 * Brass *bp;
 * bp = &ophelia;
 * bp->ViewAcct();
 * 正如前面介绍的，如果在基类中没有将ViewAcct（）声明为虚，则bp->ViewAcct()将根据指针类型，则bp->ViewAcct()根据对象类型
 * （BrassPlus）调用BrassPlus::ViewAcct()。在这个例子中，对象类型为BrassPlus，但通常只有在运行程序时才能确定对象的类型。
 * 所以编译器生成的代码将在程序运行时，根据对象类型将ViewAcct()关联到Brass::ViewAcct()或BrassPlus::ViewAcct().
 * 总之，编译器对虚方法进行动态联编。
 *
 * 虚函数的工作原理
 * C++规定了虚函数的行为，但将实现方法留给了编译器作者。不需要知道实现方法就可以使用虚函数，但了解虚函数的工作原理有助于更好地
 * 理解概念。
 * 通常，编译器处理虚函数的方法是：给每个对象添加一个隐藏成员。隐藏成员中保存了一个指向函数地址数组的指针。这种数组称为虚函数表（vbtl）
 * 虚函数表中存储了为类对象进行声明的虚函数的地址。如果派生类提供了虚函数的新定义，该函数表将保存了新函数的地址；
 * 如果派生类没有重新定义虚函数，该vbtl将保存函数原始版本的地址。如果派生类定义了新的虚函数，则该函数的地址也被添加到vbtl中。
 * 调用虚函数时，程序将查看存储在对象中的vbtl地址，然后转向相应的函数地址列表。如果使用类声明中定义的第一个虚函数，则程序将使用数组中
 * 的第一个函数地址，并执行具有该地址的函数。如果使用类声明中的第三个虚函数，程序将使用地址为数组中第三个元素的函数。
 *
 * 有段虚函数注意事项：
 * 我们已经讨论了虚函数的一些要点
 * 在基类方法的声明中使用关键字virtual可是该方法在基类以及所有的派生类（包括派生类派生出来的类）中都是虚的。
 * 如果使用指向对象的引用或指针来调用虚方法，程序将使用对象类型定义的方法，而不使用为引用或指针类型定义的方法。这称为动态联编
 * 这种行为非常重要，因为这样的基类指针或引用可以指向派生类对象
 * 如果定义的类将被用作基类，则应将那些要在派生类中重新定义的类类方法声明为虚的。
 *
 * 1构造函数
 * 构造函数不能使虚函数。创建派生类对象时，将调用派生类的构造函数，而不是基类的构造函数，然后，派生类的构造函数将使用基类的一个构造
 * 函数，这个顺序不同于继承机制。因此派生类不能继承基类的构造函数，所以将类构造函数声明为虚的没有什么意义
 *
 * 2析构函数
 * 析构函数应当为虚函数，除非类不用做基类。例如，假设Employee是基类，Singer是派生类，并添加一个char*成员，该成员指向由
 * new分配的内存。当Singer对象过期时，必须调用~Singer()析构函数来释放内存。
 * 例如
 * Employee *pe = new Singer;
 * ...
 * delete pe;
 * 如果使用默认的静态联编，delete语句间调用~Employee()析构函数。这将释放由Singer对象中的Employee部分指向的内存，但不会释放
 * 新的类成员指向的内存。但如果析构函数是虚的，则上述代码先调用~Singer()析构韩式释放由Singer组件组向的内存，
 * 然后调用~Employee()函数类释放由Employee组件指向的内存。
 * 这意味着，即使基类不需要显式析构函数提供服务，也不应依赖于默认构造函数，而应提供虚析构函数，即使它不执行任何操作
 * virtual ~BassClass(){}
 *
 * 3友元
 * 友元不能是虚函数，因为友元不是类成员，而只有成员才能是虚函数。如果这个原因引起了设计问题，可以通过让友元函数使用虚成员函数来解决
 *
 * 4没有重新定义
 * 如果派生类没有重新定义函数，将使用该函数的基类版本。如果派生类位于派生链中，则将使用最新函数的虚函数版本
 *
 * 5重新定义将隐藏方法
 * 假设创建了如下所示的代码
 * class Dwelling
 * {
 * public:
 * 	virtual void showperks(int a) const;
 * };
 * class Hovel : public Dwelling
 * {
 * public:
 * 	virtual void showperks() const;
 * }
 * 这将导致问题，可能会出现警告
 * Hovel trump;
 * trump.showperks();//valid
 * trump.showperks(5);//invalid
 * 新定义将showperks()定义为一个不接受任何参数的函数。重新定义不会生成函数的重载版本，而是隐藏了接受一个int参数的版本。
 * 总之，重新定义继承的方法并不是重载。如果在派生类中重新定义函数，将不是使用相同的函数特征覆盖基类声明，而是隐藏同名的基类方法，
 * 不管参数特征标如何
 * 这引出了两天经验规则：第一，如果重新定义继承的方法，应确保与原来的原型完全相同，但如果返回类型是基类引用或者指针，
 * 则可以修改为指向派生类的引用或指针。这种特性被称为返回类型协变，因为允许返回类型随类类型的变化而变化
 * class Dwelling
 * {
 * public:
 *     virtual Dewlling & build(int n);
 * };
 * class Hovel : public Dewlling
 * {
 * public:
 * 	   virtual Hovel & build(int);
 * }
 * 注意：这种例外只适用于返回值，而不适用于参数
 *
 * 第二，如果基类声明被重载了，则应在派生类中重新定义所有基类版本。
 * class Dwelling
 * {
 * public:
 * 	   virtual void showperks(int a)const;
 * 	   virtual void showperks(double x)const;
 * 	   virtual void showperks()const;
 * }；
 * class Hovel : public Dwelling
 * {
 * public:
 * 	   virtual void showperks(int a)const;
 * 	   virtual void showperks(double x)const;
 * 	   virtual void showperks()const;
 * }
 * 如果只重新定义一个版本，在另外两个版本将被隐藏，派生类对象将无法使用它们。注意，如果不需要修改，则新定义可只调用基类版本：
 * void Hovle::showperks const {Dwelling::showperks();}
 */
