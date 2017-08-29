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
*/
