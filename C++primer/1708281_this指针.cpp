/*this指针
对于Stock类，还有很多工作要做，到目前位置，每个类成员函数都值涉及一个对象，即调用它的对象。但右时候方法可能涉及到两个对象，在这种情况下需要使用C++的this指针。
虽然Stock类声明可以显示数据，但它缺乏分析能力，例如，从show()的输出我们可以直到持有哪一支股票价格最高，但由于程序无法直接访问total_val，因此无法作出判断。姚让程序知道存储的数据，最直接的方式是让方法返回一个值。为此，通常使用内联代码，如下所示
class Stock
{
private:
	double total_val;
public:
	double total()const{return total;}
};
就直接访问程序而言，上述定义实际上是使total_val为只读的。也就是说，可以使用方法total_val()来获得total_val()的值，但是这个类没有提供专门用于设置total_val的方法
