/*类的构造函数和析构函数
应为类提供被称为构造函数和析构函数的标准函数
C++的目标之一是让使用类对象就像用于标准类型一样，然而，到现在为止，本章提供共的代码不能让你像初始化int或结构那样初始化Stcok对象。也就是说，常规的初始化语法不适用于类型Stcok;
int year=2001;
struct thing{
	char* pn;
	int m;
};
thing amabob={"wodget",-23};
Stock hot={"Sukie's Autos,inc.",200,50.25};//这是错误的
不能想上面这样初始化Stock，数据部分的访问状态是私有的，这意味着程序不能直接访问数据成员。因此需要设计合适的成员函数，才能成功地将对象初始化
一般来说，最好是在创建对象时对它进行初始化。例如，请看下面的代码：Stock gift;
gift.buy(10,24.75);
就Stock类当前的实现而言，gift对象的company成员是没有值的。类设计假设用户在调用任何其他成员函数之前调用acquire(),但无法强加这种假设。避开这种问题的方法之一是在创建对象时，自动对它进行初始化。为此，C++提供了一个特殊的成员函数——类构造函数，专门用于构造新对象，将值赋给它们的数据成员。更准确地说，C++为这些成员函数提供了名陈和使用语法，而程序员需要提供方法定义。名称与类名同。

声明和定义构造函数
现在创建Stock的构造函数.由于需要为Stock对象提供3个值，因此应为构造函数提供3个参数
原型如下所示：
Stock::Stock(const string &co,long n=0;double pr=0.0);
{
company=co;
	if(n<0){
		std::cerr<<"Numer of shares can't be negetive;"
				<<company<<" shares set to 0.\n";
		shares=0;
	}
	else
		shares=n;
	shares_val=pr;
	set_tot();
}
使用构造函数
C++提供了两种使用构造函数，第一种是显示第调用构造函数：
Stock food=Stock{"World cabbage",250,1.25};
另一种方式是隐式第调用构造函数：
Stock garment("Furry Mason",50,2.5);
每次创建类对象（甚至使用new动态分配)时，C++都使用类构造函数。下面是将构造函数与new一起使用的方法：
Stock *pstock=new Stock("Electroshock Games",18,19.0);
无法使用对象来调用构造函数，因为早构造函数构造出对象之前，对象是不存在的。因此构造函数被用来创建对象，而不能通过调用对象来调用。
