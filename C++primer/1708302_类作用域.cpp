/*第九章介绍了全局作用域和局部作用域。可以在全局变量所属文件的任何地方使用它，而局部变量只能在其所属的代码块中使用。函数名称的作用域也可以是全局的，但不能是局部的。C++类引入了一种新的作用域：类作用域
在类中定义的名称（如类数据成员名和类成员函数名）的作用域窦唯整个类，作用域为整个类的名称只在该类中是已知的，在类外是不可知的。因此，可以子不同类中使用相同的类成员名而不会引起冲突。例如，Stock类的shares成员不同与JobRide类的shares成员。另外，类的作用域移位着不能 从外部直接访问类的成员，公有成员函数也是如此。也就是说，要调用公有成员函数，必须通过对象：
Stock sleeper("Exclusive Ore",100,0.25);
sleeper.show();
show()//wrong
同样，在定义成员函数时，必须使用作用域解析运算符：
void Stock::update(double price){
}
总之，在类声明或成员函数定义中，可以使用维修是的成员名称，就像sell()调用set_tot()成员函数时那样。构造函数名称在被调用时，才能被识别，因为它的名称与类名相同，在其他情况下，使用类成员名时，必须根据上下文使用成员运算符(.)、->,::
例如，下面代码演示了如何访问具有类作用域的标识符：
class Ik{
private:
	int fuse;
public:
	IK(int f=9){fuss=f;}
	void View() const;
};
void Ik::VireIk() const
{
	cout<<fuss<<endl;
}
...
int main(){
	Ik *pik=new Ik;
	Ik ee=Ik(8);
	ee.ViewIk();
	pik->ViewIk();
	...
}
作用域为类的常量
有时候，使用符号常量的作用域为类很有用.例如，类声明可能使用字面值30来制定数组的长度，由于该常量对于所有对象来说都是相同的，因此创建一个由所有对象共享的常量是个不错的注意。您可能一味这样做客行
class Bakery
{
private:
	const int Months=12;
	double costs[Months];
}
但这是行不通的，因为声明类只是描述了对象的形式，并没有创建对象。因此，在创建对象前，将没有用于存储值的空间。然而，右两种方式可以实现这个目标，并且效果相同
第一种方式是在类声明中声明一个枚举，在类声明中声明枚举的作用于为整个类，因此可以用枚举为整型常量提供作用于为整个类的符号名称，也就是说，可以这样可是Bakery声明：
class Bakery
{
private:
	enum{Months=12};
	double costs[Months];
	...}
注意，用这种方式声明枚举并不会创建类数据成员。也就是说，所有对象中都不包含枚举。另外，Months知识一个符号名称，在作用域为整个类的代码中遇到它时，编译器将用30来代替它。
C++提供了另一种在类中定义常量的方式——使用关键字static:
class Bakery
{
private:
	static const int Months=12;
	double costs[Months];
	...
}
这里将创建一个名为Months的常量，该常量将于其他静态变量存储在一起，而不是存储在对象中，因此，只有一个Months常量，被所有Bakery对象共享。
作用域内枚举
传统的枚举存在一些问题，其中之一是两个枚举定义中的枚举量可能发生冲突。假设有一个处理鸡蛋和T恤的项目，其中可能包含类似下面的这样的代码
enum egg{Small.Medium,Large,Junbo};
enum t_shirt{Small,Medium,Large,Xlarge};
这将无法通过编译，因为egg small和t_shirt Small位于相同的作用域呢，它们将发生冲突。为避免这种问题，C++11提供了一种新枚举，其枚举量的作用域为类。这种枚举的声明类似与下面这样：
enum class egg {Small,Medium,Large,Jumbo};
enum class t_shirt{Small,Medium,Large,Xlarge};
也可使用关键字struct代替class。无论使用哪种方式，都需要使用枚举名限定枚举变量：
egg choice=egg::Large;
t_shirt Floyd=t_shirt::Large;
枚举两的作用域为类后，不同枚举定义中的枚举就不会发生名称冲突了，而您可继续编写处理鸡蛋和T恤的项目。
C++11还提高了作用域内枚举的类型安全。在有些情况下，创归枚举将自动转换为整型，如将其赋给int变量或用与表达式时，但作用域内枚举不能隐式地转换为整型。
enum egg_old{Small,Medium,Large,Jumbo};
enum class t_shirt{Small,Medium,barge,Xlarge};
egg_old one=Medium;
t_shirt=t_shirt::larger;
int king=Medium;//implicit type conversion for unscoped
int ring=rolf;//not allowed,no implicit type conversion
if(king<Jumbo)
std::cout<<"Jumbo converted to int before comparison.\n";
if(king<t_shirt::medium)//not allowed
std::cout<<"Not allowed:<not defined for scpoed enum.\n";
但在必要时，可进行显示类型转换：
int_Frodo=int(T_shirt::Small);
枚举用某种底层整型类型表示，在C++98中，如何选择取决于实现，因此包含枚举结构的长度可能随系统而异。对于作用域内枚举，C++11消除了这种依赖性。默认情况下，C++11作用域内枚举的底层类型为int。另外，还提供了一种语法，可用于作出不同的选择：
enum class:short pizza{Small,Medium,Large,XLarge};
:short将底层类型指定为short。底层类型必须为整型，在C++11中，也可使用这种语法来指定常规枚举的底层类型，但如果没有执行，编译器的底层类型将随实现而异。
