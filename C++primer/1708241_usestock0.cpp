#include<iostream>
#include"1708171_stock.h"
int main(){
	Stock fluffy;
	fluffy.acquire("NanoSmart",20,12.50);
	fluffy.show();
	fluffy.buy(15,18.125);
	fluffy.show();
	fluffy.sell(400,20.00);
	fluffy.show();
	fluffy.buy(300000,40.125);
	fluffy.show();
	fluffy.sell(300000,0.125);
	fluffy.show();
	return 0;
}
 /*
小姐
指定类设计的第一步是提供类声明。类声明类似结构声明，可以包括数据成员和函数成员。声明由私有部分，在其声明的成员只能通过成员函数进行访问;声明还有公有部分，在其中声明的成员可被使用类对象的程序直接访问。通常，数据成员被放在私有部分中，因此典型的类声明的格式如下：
class classname{
private:
	data member declarations
public:
	menber function prototypes
};
公有部分的内容构成了设计的抽象部分——公有接口，将数据封装到私有部分中可以保护数据的完整性，这被称为数据隐藏
通常，需要使用作用域解析运算符来指出成员函数属于哪个类
char * Bozo::Retort()
换句话来说，Retort()不仅仅是char*类型的函数，而是术语Bozo类的char*函数。该函数的全名为Bozo::Retort().而名称Retort()是限定名的缩写，只能在某些特定的环境中使用，如类方法的代码中		
