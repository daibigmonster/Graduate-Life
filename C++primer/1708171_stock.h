#ifndef STOCK00_H_
#define STOCK00_H_
#include<string>
class Stock
{
private:
   std::string company;
   long shares;
   double share_val;
   double total_val;
   void set_tot(){total_val=shares*share_val;}
public:
   void acquire(const std::string &co,long n,double pr);
   void buy(long num,double price);
   void sell(long num,double price);
   void update(double price);
   void show();
};
#endif
/*接下来，要存储的数据以类数据成员（如company和shares）的形式出现。例如，sally的company成员存储了公司名称，share成员存储了sally持有的股票数量，share_val存储了每股价格。同样，要执行的操作以类函数成员（方法，如sell()和update()）的形式出现。成员函数可以就地定义，也可以用原型表示
1访问控制
关键字private和public也是新的，它们描述了对类成员的访问控制。使用类对象的程序都可以直接访问共有部分，但只能通过共有成员函数来访问对象的私有成员。例如，要修改Stock类的shares成员，只能通过Stock的成员函数。因此，公有成员函数是程序和对象的私有成员之间的桥梁，提供对象和程序直接的接口
类设计尽可能将公有接口和实现细节分开。共有接口表示设计的抽象组建。将实现细节放在一起并将它们与抽象分开被称为封装。数据隐藏（将数据放在类的私有部分中）是一种封装，将实现的细节隐藏在私有部分中，就像Stock类对set_tot()所做的那样，也是一种封装。封装的另一个例子是，将函数定义和类声明放在不同文件中。
数据隐藏不仅可以防止直接访问数据，还让开发者无序了解诶数据是如何被表示的。例如,show()成员将显示某只股票的总价格（还有其他内容），这个值可以存储在对象（上述代码正式这样做的），也可以在需要时通过计算得到，从使用类的角度来看，使用哪种方法没有什么区别，所需要知道的只是成员函数的功能，也就是说需要知道成员函数接收什么样的参数以及返回什么类型的值。原则是将实现细节从接口设计中分离出来。
控制成员的访问：公有还是私有
无论类成员是数据成员还是成员函数，都可以在类的共有或私有部分中声明它，但由于隐藏数据是OOP主要目标之一，因此数据项通常放在私有部分，组成类接口的成员函数放在共有部分;否则，就无法从程序中调用这种函数，但公有方法却可以使用它们，通常，程序员使用私有成员函数来处理不属于共有接口的实现细节

C++程序员通常使用类来实现类描述，而把接口限制为只表示纯粹的数据对象

实现类成员函数*/
