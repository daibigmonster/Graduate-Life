/*可以采用另一种方法——一种帮助您了解this指针的方法。这种方法是，定义一个成员函数，它查看两个Stock对象，并返回股价较高的那个对象的引用
首先，如何将两个要比较的对象提供给成员函数呢？例如，假设将该方法命名为topcal(),则函数调用上提出stock1.topcal()将访问stock1对象的数据，而stock2.topval()将访问stock2对象的数据。如果希望该方法对两个对象进行比较，则必须将第二个对象作为参数传递给它。处于效率方面的考虑，可以按引用来传递参数，也就是说，topval()方法使用一个类型为const Stock&的参数
其次，如何将方法的答案传回给调用程序呢？最直接的方法是让方法返回一个引用，该引用指向股价总值比较高的对象。因此，用于比较的方法的原型如下：
const Stock & topval(const Stock & s)const;
该函数隐式地访问一个对象，而显式地访问另一个对象，并返回其中一个对象的引用。括号中的const标明。该函数不会修改被显示地访问的对象：而括号后的const标明，该函数不会修改被隐式地访问的对象。由于该函数返回了连个const对象之一的引用，因此返回类型也应为const引用
假设要对Stock对象stock1和stock2进行比较，并将其中股价总值较高的哪一个赋给top对象，则可使用下面两条语句之一：
top=stock1.topval(stock2);
top=stock2.topval(stock1);
第一种各地隐式第访问stock1,而显示地访问stock2.无论使用那一种方式，都将对这两种对象进行比较，并返回股价总值较高的哪一个对象。
实际上，这种表示法有些混乱。如果可以使用关系运算符>来比较这两个对象，将更为清晰。可以使用运算重载完成这项工作。
同时，还要注意的是topval()的实现，它将引发一个小问题
const Stock & topval(const Stock & s)const
{
	if(s.total_val>total_val)return s;
	else return ????;
}
其中，s.total_val是作为参数传递的对象的总值，total_val是用来调用该方法的对象的总值。如果s.total_val大于total_val，则函数返回指向s的引用;否则将返回来调用该方法的对象。问题在于，如何称呼这个对象？
C++解决这个问题的方法是：使用被称为this的特殊指针。this指针指向用来调用成员函数的对象（this被作为隐藏参数传递给方法）。这里，函数调用stock2.topval(stock1)将this设置为stock2对象的地址。，使得这个指针可用于topval()方法.一般来说，所有的类方法都将this指针设置为调用它的对象的地址。确实，topval()中的total_val只不过是this->total_val的简写。
注意：
每个成员函数（包括构造函数和析构函数）都有一个this指针。this指针指向调用对象。如果方法需要引用整个调用对象，则可以使用表达式*this.
然饿要返回的并不是this，因为this是对象的地址，而对象本身，即*this。现在可以将*this作为调用对象的别名来完成前面的方法的定义。
const Stock & Stock::topval(const Stock &s)const{
	if(s.total_val>total_val)return s;
	else return *this;
}
返回类型为引用意味着返回的是调用对象的本身，而不是其副本 
*/
#ifndef STOCK20_H_
#define STOCK20_H_
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
	Stock();
	Stock(const std::string&co,long n=0,double pr=0.0);
	~Stock();
   void buy(long num,double price);
   void sell(long num,double price);
   void update(double price);
   void show()const;
	const Stock& topcal(const Stock &s)const;
};
#endif
