/*
 * 继承和动态内存分配
 * 继承是怎样与动态内存分配进行互动的呢？例如，如果基类使用动态内存分配，并重新定义复制和复制构造函数，这将怎样影响派生类的实现呢，
 * 这个问题的答案取决于派生类的属性，如果派生类也使用动态内存分配
 *
 * 第一类情况：派生类不适用new
 * 假设基类使用了动态内存分配
 *
 * class baseDMA
 * {
 * private:
 *     char * label;
 *     int rating;
 * public:
 *     baseDMA(const char * l = "null",int r = 0);
 *     baseDMA(const baseDMA & rs);
 *     virtual ~baseDMA();
 *     baseDMA & operator = (const baseDMA & rs);
 *     ...
 * }
 * 声明中包含了构造函数使用new时需要的特殊方法：析构函数、复制函数和重载复制运算符。
 * 现在，从baseDMA派生出lackDMA,而后者不使用new，也未包含其他一些不常用的、需要特殊处理的设计特性
 * class lacksDMA : public baseDMA
 * {
 * private :
 *     char color[40];
 * public:
 * ...
 * };
 * 是否需要为lackDMA类定义显示析构函数、复制构造函数和赋值运算符呢？不需要
 * 首先，来看是否需要析构函数。如果没有定义析构函数，编译器将定义一个不执行任何操作的默认构造函数。实际上，派生类的默认构造函数总是
 * 要进行一些操作：执行自身的代码后调用基类析构函数。因为我们假设lackDMA成员不需执行任何特殊操作，所以默认析构函数是合适的。
 * 接下来看复制构造函数。第12章介绍过，默认复制构造函数执行成员复制，这对于动态内存分配来说是不合适的，但对于新的lacDMA成员来说
 * 是合适的。因此，只需考虑继承的baseDMA对象。要知道，成员复制将根据数据类型采取相应的复制方式，因此，将long复制到long中是通过
 * 使用常规赋值来完成的；但赋值类成员或继承的类组件时，则是使用该类的复制构造函数完成的。所以，lacksDMA类的默认复制构造函数使用显式
 * baseDMA复制构造函数来复lacksDMA对象的baseDMA部分。因此，默认复制构造函数对于新的lacksDMA成员来说是合适的，同时对于继承的
 * baseDMA对象来说也是合适的
 * 对于赋值来说，也是如此。类的默认复制运算符将自动使用基类的赋值运算符来对基类组件进行赋值。因此，默认赋值运算符也是合适的。
 *
 * 第二种情况：派生类使用new
 * class hasDMA : public baseDMA
 * {
 * private :
 *     char * style;//use new in constructors
 * public:
 * ...
 * };
 * 在这种情况下，必须为派生类定义显式析构函数、复制构造函数和赋值运算符。下面考虑这些方法
 * 派生类析构函数自动调用基类的析构函数，故其自身的职责是对派生类构造函数是对派生类构造函数执行工作的进行清理。因此，hasDMA析构
 * 函数必须释放指针style管理的内存，并依赖于baseDMA的析构函数来释放指针label管理的内存。
 * baseDMA::~baseDMA(){
 *     delete [] label;
 * }
 *
 * hasDMA::~hasDMA()
 * {
 *     delete [] style;
 * }
 * 接下来复制构造函数。baseDMA的复制构造函数遵循用于char数组的常规模式，即使用strlen()来获悉存储C-风格字符窜所需的空间、分配足够
 * 的内存（字符数加上存储所需的1字节）并使用函数strcpy()将原始字符串复制到目的地：
 * baseDMA::baseDMA(const baseDMA & rs)
 * {
 *     label = new char[std::strlen(rs.label) + 1];
 *     std::strcpy(label,rs.label);
 *     rating = rs.rating;
 * }
 * hasDMA复制构造函数智能访问hasDMA的数据，因此他必须调用baseDMA复制构造函数来处理共享的baseDMA数据：
 * hasDMA::hasDMA(const hasDMA & hs) : baseDMA(hs)
 * {
 *     style = new char[std::strlen(hs.style) + 1];
 *     std::strcpy(style,hs.style);
 * }
 * 需要注意的一点的是，成员初始化列表将一个hasDMA
 */
