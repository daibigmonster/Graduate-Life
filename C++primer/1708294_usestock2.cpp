#include<iostream>
#include"1708292_stock20.h"
const int STKS=4;
int main(){
	using std::cout;
	Stock stocks[STKS]={
		Stock("NanoSmart",12.5,20),
		Stock("Boffo Objests",200,2.0),
		Stock("Monolithic Obelisks",130,3.25),
		Stock("Fleep Enterprises",60,6.5)};
	cout<<"Stock holdings:\n";
	int st;
	for(st=0;st<STKS;st++)stocks[st].show();
	const Stock *top=&stocks[0];
	for(st=1;st<STKS;st++)top=&top->topval(stocks[st]);
	cout<<"\nMost valuable holding:\n";
	top->show();
	return 0;
}
/*声明对象数组的方法与声明标准类型数组相同
Stock mystuff[4];
上述声明要求，这个类要么没有显式地定义任何构造函数，要么定义了一个显示默认构造函数，每个元素(mystuff[0]、mystuff[1])都是Stock对象，可以使用Stock方法
mystuff[0].update();
mystuff[3].show();
const Stock * tops=mystuff[]2.topcal(mystuff[1]);
可以用构造函数来初始化数组元素。在这种情况下，必须为每个元素调用构造函数：
const int STKS=4;
Stockstocks[STKS]={
	Stock("NanoSmart",12.5,20),
	Stock("Boffo Objests",200,2.0),
	Stock("Monolithic Obelisks",130,3.25),
	Stock("Fleep Enterprises",60,6.5)};
这里的代码使用标准格式对数组进行对数组进行初始化：用括号括起的，以都好分隔的值列表。其中，每次构造函数调用表示一个值。如果类包含多个构造函数，则可以对不同元素使用不同的构造函数:
const int STKS=4;
Stockstocks[STKS]={
	Stock("NanoSmart",12.5,20);
	Stock();
	Stock("Monolithic Obelisks",130,3.25),
	};
上述代码使用Stock(const string &co,long n,double pr)初始化stock[0]和stock[2]，使用构造函数Stock()初始化stock[1].由于该声明只初始化了数组的部分元素，因此余下的7个元素将使用默认构造函数进行初始化。
大部分工作是在类设计中完成的
直到this指针就可以更深入了解C++的工作方式
初始化数组的方案是，首先使用默认构造函数创建数组元素，然后花括号中的构造函数将创建临时对象，然后将临时对象的内容复制到相应的元素中。因此，要创建对象数组，则这个类必须由默认构造函数
程序使用了这些原理，该程序对4个数组元素进行初始化，显示它们的内容，并找出这些元素中总值最高的一个。由于topval()每次之间叉两个对象，因此程序使用for循环来检查真个数组。另外，它使用stock指针来根据值最高的元素。
*/
