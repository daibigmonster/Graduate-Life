/*还需要创建类描述的第二部分：为那些由类声明中的原型表示的成员函数提供代码。成员函数定义与常规函数定义非常相似，它们由函数头和函数题，也可以由返回类型和参数。但它们还有两个特殊的特征：
定义成员函数时，使用作用域解析运算符(::)来这出函数所属的类
类方法可以访问类的private组件
首先，成员的函数头使用作用域运算符解析(::)来指出函数所属的类。例如，update()成员函数的函数头如下：
void Stock::update(double price)
这种表示法意味着我们定义的update()函数是Stock类的成员。这不仅将update()标识为成员函数，还意味着我们可以将另一个类的成员函数也命名为update().例如，Buffonon()类的update()函数的函数头如下：
void Buffoon::update()
因此，作用域解析运算符确定了方法定义对应的类的身份。我们说，标识符update()具有类作用域(class scope).Stock类的其他成员函数不必使用作用域解析运算符，就可以使用update()方法，这是因为它们属于同一个类，因此update()是可见的。然而，在类声明和方法定义之外使用update()时，需要采取特殊的措施。
类方法的完整名称包括类名。我们说Stock::update()是函数的限定名;而简单的update()是全名的缩写(非限定名)，它只能在类作用域中使用
方法的第二个特点是，方法可以访问类的私有成员。例如show()方法可以使用这样的代码：
std::cout<<"Company: "<<company
		<<" Shares: "<<shares<<endl;
		<<" Shares Price: $"<<share_val
		<<" Total Worth: $"<<total_val<<endl;
其中，company、shares等都是Stock类的私有数据成员*/
#include<iostream>
#include "1708171_stock.h"
void Stock::acquire(const std::string &co,long n,double pr){
	company=co;
	if(n<0){
		std::cout<<"Number of shares can't be negative;"
			<<company<<" shares set to 0.\n";
		shares=0;
		}
		else
			shares=n;
		share_val=pr;
		set_tot();
} 
void Stock::buy(long num,double price){
	if(num<0)
	{
		std::cout<<"Number of shares purchased can't be negative."
			<<"Transaction is aborted.\n";
	}
	else{
		shares+=num;
		share_val=price;
		set_tot();
	}
}
void Stock::sell(long num,double price){
	using std::cout;
	if(num<0)
	{
		std::cout<<"Number of shares sold can't be negative."
			<<"Transaction is aborted.\n";
	}
	else if(num>shares){
		cout<<"You can't sell more than you have!"
			<<"Transaction is aborted.\n";
	}
	else{
		shares-=num;
		share_val=price;
		set_tot();
	}
}
void Stock::update(double price){
	share_val=price;
	set_tot();
}
void Stock::show(){
	std::cout<<"Company: "<<company
			<<" Shares "<<shares<<'\n'
			<<" share Price: $"<<share_val
			<<" Total Worth: $"<<total_val<<'\n';
}
/*
1成员函数说明
acquire()函数管理对某个公司股票的首次购买，而buy()和sell()管理增减或减少持有的股票。方法buy()和sell()管理增加或减少持有的股票。方法buy()和sell()确保买入或卖出的股数不为负。另外，如果用户试图卖出超过它持有的股票数量，则sell()函数将结束这次交易
4个成员函数设置或重新设置了total_val成员值，。这个类并非将计算代码编写4此，而是让每个函数都调用set_tot()函数。由于set_tot()只是实现代码的一种方式，而不是公有接口的组成部分，因此这个类将其声明为私有成员函数(即编写这个类的人可以使用它，但编写代码使用这个类的人不能使用)。
2内联方法
其定义位于类声明中的函数都将自动称为内联函数，因此Stock::set_tot()是一个内联函数。类声明常将短小的称为作为内联函数
如果愿意，也可以在类声明之外定义成员函数，并使称为内联函数，为此，只需在类实现部分中定义函数时使用inline限定符即可
class Stock{
private:
	voidset_tot();
public:...
};
inline void Stock::set_tot(){
	total_val=shares*share_val;}
所创建的每个新对象都有自己的存储空间，用于存储其内部变量和类成员：但同一个类的所有对象共享统一组方法，即每种方法只有一个副本。
例如：假设kate和joe都是Stock对象，则kate.shares将占据一个内存块，而joe.shares占用另一个内存块，但kate.show()和joe.show()都调用同一个方法，也就是说，它们将执行同一个代码块，只是将这些代码用于不同的数据。在OOP中，调用成员函数被称为发送消息，因此同样的消息发送给两个不同的对象将调用同一个方法，但该方法被用于两个不同的对象。
*/
