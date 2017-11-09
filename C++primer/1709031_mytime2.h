/*多数C++运算符都可以用这样的方式重载。重载的运算符不必是成员函数，但必须至少有一个操作数是用户定义的类型，下面详细介绍C+++对用户定义的运算符重载的限制。
1重载后的运算符必须至少由一个操作数是用户定义的类型，这将防止用户为标准类型重载运算符。
因此，不能将减法运算符(-)重载为计算两个double值之和，而不是它们的差
2使用运算符时不能违反运算符原来的句法规则。例如，不能将求模运算符（%）重载成使用一个操作数：
int x;
Time shiva
% x;//wrong
% shiva//wrong
同样不能修改用算符的优先级，因此，如果将加号运算符重载成两个类相加，则新的运算符与原来的加号具有相同的优先级
3不能创建新的运算符。例如，不能定义operator **()函数来表示求幂
4不能重载下面的运算符
 sizeof
 . 成员运算符
 * 成员指针运算符
 :: 作用域算算符
 ？
 typeid
 const_cast
 dynamice_cast
 reinterpret_cast
 static_cast
 下面的运算符只能通过成员函数进行重载
 =：
 ():
 []:下标运算符
 ->:通过指针访问类成员的运算符`
 
 还有一些其他的操作对Time类来说是有意义的。例如，可能要将两个时间相减或将时间乘以一个因子，这需要重载减法和乘法运算符。这和重载加法运算符采用的技术相同。即将下面的原型添加到类声明中
 Time operator-(const Time &t) const;
 Time oerator*(double n)const;
 */
 #ifndef MYTIME2_H_
 #define MYTIME2_H_
 class Time
 {
 private:
 	int hours;
	int minutes;
public:
	Time();
	Time(int h,int m=0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h=0,int m=0);
	Time operator+(const Time &t)const;
	Time operator-(const Time &t)const;
	Time operator*(double n)const;
	void Show()const;
};
#endif
