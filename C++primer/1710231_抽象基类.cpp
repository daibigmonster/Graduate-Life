/*抽象基类
 * 至此，介绍了简单继承和较复杂的多态继承。接下来就是更复杂的抽象基类
 * 假设你正在开发一个圆形程序，改程序将显示圆和椭圆等。圆是椭圆的一个特殊情况——长轴和短等长的椭圆。因此，所有的圆都是椭圆
 * 可以从Ellipse类派生出Circle类。但涉及到细节时，会发现很多问题
 * 首先考虑Ellipse类包含的内容。数据成员可以包括椭圆中心的坐标、长半轴、短半轴以及方向角。另外，还可以包括一些移动椭圆、返回椭圆
 * 面积、旋转椭圆以及缩放长半轴和短半轴的方法
 *
 * 一种解决方法，即从Ellipse和Circle类中抽象出它们的共性，将这些特性放到一个ABC中。然后从ABC派生出Circle和Ellipse类。
 * 这样，便可以使用基类指针数组同时管理Circle和Ellipse对象，即可以使用多态方法。在这个例子中，这两个类的共同点是中心坐标、
 * Move()方法（对于这两个类是相同的）和Area()方法（对于这两个类说，是不同的）。确实，甚至不能再ABC中实现Area()方法，因为它没有
 * 提供包含必要的数据成员。C++通过使用纯虚函数提供未实现的函数。纯虚函数声明的结尾处为=0，参见Area()方法
 * class BaseEllipse
 * {
 * private:
 *     double x;
 *     double y;
 * ...
 * public:
 * 	   BaseEllipse(double x0 = 0,double y0 = 0) : x(x0),y(y0) {}
 * 	   virtual BaseEllipse() {}
 * 	   void Move(int nx,ny){x = nx ; y = ny; }
 * 	   virtual double Area() const = 0;
 * }
 * 当类声明中包含纯虚函数时，则不能创建该类的对象。这里的理念是，包含纯虚函数的类只能用作基类。要成为真正的ABC，
 * 必须至少包含一个纯虚函数。原型中的=0使虚函数称为纯虚函数。这里的方法Area()没有定义,但C++甚至允许纯虚函数有定义。
 * 例如，也许所有的基类方法都与Move()一样，可以在基类中进行定义，但您扔需要将这个类声明为抽象的。在这种情况下，可以将原型声明为
 * 虚的：
 * void Move(int nx,ny) = 0;
 * 这将使基类称为抽象的，但您仍可以在实现文件中提供方法的定义：
 * Void BaseEllipse::Move(int nx,ny){x = nx ; y = ny;}
 * 总之，在原型中使用=0指出类是一个抽象基类，在类中可以不定义该函数。
 * 现在，可以从BaseEllipse类派生出Ellipse对象和Circle对象，但是不能创建BaseEllipse对象。由于Circle和Ellipse对象的基类相同
 * 因此可以使用BaseEllipse指针数组同时管理这两种对象。像Circle和Ellipse这样的类有事被称为具体类，这表示，可以创建这些类的对象。
 * 总之，ABC描述的是至少使用一个纯虚函数的接口，从ABC派生出的类将根据派生类的具体特征使用常规虚函数来实现这种接口。
 *
 */
#include <iostream>
#include "1710241_acctabc.h"
using std::cout;
using std::endl;
using std::ios_base;
using std::string;

AcctABC::AcctABC(const string & s,long an,double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}

void AcctABC::Deposit(double amt)
{
	if(amt < 0)
		cout << "Negative deposit not allowed; "
			<< "deposit is cancelled.\n";
}

void AcctABC::Withdraw(double amt){
	balance -= amt;
}


AcctABC::Formatting AcctABC::SetFormat() const{
	//set up ###.## format
	Formatting f;
	f.flag = cout.setf(ios_base::fixed,ios_base::floatfield);
	f.pr = cout.precision(2);
	return f;
}

void AcctABC::Restore(Formatting & f) const{
	cout.setf(f.flag,ios_base::floatfield);
	cout.precision(f.pr);
}

//Brass methods
void Brass::Withdraw(double amt){
	if(amt < 0)
		cout << "Withdrawal amount must be be positive;"
		     << "withdrawal canceled.\n";
	else if (amt <= balance())
		AcctABC::Withdraw(amt);
	else
		cout << "Withdrawal amount of $" << amt
			<<" exceeds your balance.\n"
			<<"Withdrawal canceled.\n";
}

void Brass::ViewAcct() const{
	Formatting f = SetFormat();
	cout << "Brass Client: " << FullName() << endl;
	cout << "Account Number: " << AcctNum() << endl;
}
