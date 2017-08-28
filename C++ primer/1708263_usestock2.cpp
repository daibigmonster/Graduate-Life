#include<iostream>
#include"1708262_stock10.h"
int main(){
	{using std::cout;
	cout<<"Using construction to create new objects\n";
	Stock stock1("NanoSmart",12,20.0);
	stock1.show();
	Stock stock2=Stock("Boffo Objects",2,2.0);
	stock2.show();
	cout<<"Assinging stock1 to stock2:\n";
	stock2=stock1;
	cout<<"Listing stock1 and stock2\n";
	stock1.show();
	stock2.show();
	cout<<"Using a constructor to reset an object\n";
	stock1=Stock("Nifty Foods",10,50.0);
	stock1.show();
	cout<<"Done\n";}
	return 0;
}
/*程序说明
Stock stock1("NanoSmart",12,20.0);
创建一个名为stock1的Stock对象，并将其数据成员初始化为指定的值：
COnstructor using NanoSmart called
Company Nanosmart Shares: 12
下面的语句使用另一种语法创建并初始化一个名为stock2的对象
Stock stock2=Stock("Boffo Objects",2,2.0);
下面的语句标明可以将对象赋给同类型的另一个对象
stock2=stock1
与给结构赋值一样，在默认情况下，给类对象赋值时，将把一个对象的成员复制给另一个。
构造函数不仅仅可用于初始话新对象，例如
stock1=Stock("Nifty Foods",10,50.0);
stock1对象已经存在，因此这条语句不是对stock1进行初始化，而是将新值赋给它。这是通过让构造程序创建一个新的、临时的对象，然后将其内容复制给stock1来实现的，随后程序调用析构函数，以删除该临时对象
结果标明，先面两条语句有根本性的差别：
Stock stock2=Stock("Boffo Objects",2,2.0);
stock1=Stock("Niffty Foods",10,50.0);
第一条语句是初始化，它创建由指定值的对象，可能会创建临时对象（也可能不会）;第二条语句是复制。像这样在与之语句中使用构造函数总会导致在复制前创建一个临时对象。
tchi：如果即可以通过初始化，也可以通过复制来设置对象的来设置对象的值，则应采用初始化方式。通常这种方式的效率更高。
C++11列表初始化
在C++11中，可将列表初始化语法用于类吗？可以，只要提供与某个构造函数的参数列表匹配的内容，并用大括号将它们括起：
Stock hot_tip={"Derivatives Plus Plus",100,45.0};
Stock joke{"Sport Age Storage,Inc"};
Stock temp{};
在前两个声明中，用大括号括起的列表与下面的构造函数pigpen
Stock::Stock(const std::string &co,long n=0,double pr=0.0);
因此，将使用该构造函数来创建这两个对象。创建对象jock时，第二和第三个参数将为默认值0和0.0.
第三个声明与默认构造函数匹配，因此将使用该构造函数创建对象temp

const函数
const Stock land=Stock("K P");
land.show();
对于当前的C++来说，编译器拒绝执行第二行。这是什么原因呢？因为show()的代码无法确保调用对象不被修改。我们以前通过将函数参数申明为const引用或指向const的指针来解决这种问题。但这里存在语法问题：show()方法没有任何参数。相反，它所使用的对象是由方法调用隐式地提供的。需要一种新的语法——保证函数不会修改调用对象。C++的解决方法是将const关键字放在函数的括号后面。也就是说show()声明应像这样
void关键字放在函数的括号后面。也就是说show()声明应像这样：
void show() const;
同样，函数定义的开头应像这样：
void stock::show() const
以这样方式声明和定义的类函数被成为const成员函数。就像应尽可能将const引用和指针用作函数行参一样，只要类方法不修改调用对象，就应将其声明为const
构造函数和析构函数小结
构造函数是特殊的类成员函数，在创建类对象时被调用。构造函数的名称和类名相同，但通过函数重载，可以创建多个同名的构造函数，条件是每个函数的特征标（参数列表）都不同。另外，构造函数没有声明。通常，构造函数用于初始化类对象的成员，初始化应与构造函数的参数列表匹配
Bozo(const char * fname,cont char * lname);
则可以使用它来初始化对象：
Bozo bozetta=("Bozetta","Biggens");
Bozo fufu("Fufu","O'Dweeb");
Bozo *pc=new Bozo("Popo",Le Peu");
如果编译器支持C++11,则可使用列表初始化：
Bozo bozetta={"bozetta","Biggens"};
Bozo fufu{"Fufu","O'Dweb"};
Bozo *pc=new Bozo{"Popo","Le Peu"};
如果构造函数只有一个参数，则将对象初始化为一个与参数类型相同的值时，该构造函数将被调用，例如，假设右这样一个构造函数原型：
cout<<trip;
则可以使用下面的任何一种形式来初始化对象
Bozo dribble=bozo(44);
Bozo roon(66);
Bozo tuby=32;
默认构造函数没有参数，因此如果创建对象时没有进行显式第初始化，则将调用默认构造函数。如果程序中没有提供任何构造函数，则编译器会为程序定义一个默认构造函数;否则，必须自己提供哦你默认构造函数。默认构造函数可以没有任何参数;如果右，则必须给所有参数都提供默认值：
Bozo();
Bistro(const char s="Chez Zero");
对于为被初始化的对象，程序将使用默认构造函数来创建
Bozo bubi;
Bozo *pb=new Bozo;
就像对象被创建时程序将调用构造函数一样，当对象被删除时，程序将调用析构含糊。每个类都只能有一个析构函数。析构函数没有返回类型（连void都没有），也没有参数，其名成为类名称前加上~。例如，Bozo类的析构函数的原型如下：
~Bozo();
如果构造函数使用了new,则必须提供使用delete的析构函数。
