/*析构函数
用构造函数创建对象后，程序负责跟踪该对象，直到其过期为止。对象过期时，程序将自动调用一个特殊的成员函数：析构函数/析构函数完成清理工作。
例如，如果构造函数使用new来分配内存，则析构函数将使用delete来释放内存。Stock的构造函数没有使用new，因此析构函数实际上没有要完成的任务。在这种情况要，只需要让编译器生成一个什么都不做的隐私析构函数即可
和构造函数一样析构函数的名称也很特殊：在类名前加上~.因此，Stock类的析构函数为~Stock().另外，和构造函数一样，异构函数也可以没有返回值和声明类型。与构造函数不同的是，析构函数没有参数，因此Stock的原型必须是这样的：
~Stock()
可以将它编写为不执行任何操作的函数
Stock::~Stock(){}
什么时候应该调用析构函数呢？这由编译器决定，通常不应在代码中显式第调用析构函数。如果创建的是静态存储来对象，则其析构函数将在程序结束时自动被调用。如果创建的是自动存储类对象，则其析构函数将在程序执行完代码块是自动被调用。如果对象是通过new创建的，则它将驻留在栈内存或自由存取中，当使用delete来释放内存是，其析构函数将自动被调用。最后程序可以创建临时对象来完成特定的操作，在这种情况下,程序将在结束对象的使用时自动调用其析构函数
由于在对对象过期时析构函数将自动被调用，因此必须右一个析构函数。如果程序员没有提供析构函数，编译器将隐式第声明一个默认析构函数，并在发现导致对象被删除的代码后，提供默认析构函数的定义*/
#ifndef STOCK10_H_
#define STOCK10_H_
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
   void show();
};
#endif
