/*友元
有一类特殊的非成员函数可以访问类的私有成员，它们被称为友元函数

创建友元函数的第一步是将其原型放在类声明中，并在原型声明前加上关键字friend
friend Time operator*(double m,const Time &t);
该原型意味着下面两点

1虽然operator*()函数是在类声明中声明的，但它不是成员函数，因此不能使用成员运算符来调用;
2虽然operator*()函数不是成员函数，但它与成员函数的访问权限相同。
第二步是编写函数定义，因为它不是成员函数，所以不要使用Time::限定符。另外，不要在定义中使用关键字friend,定义应该如下

Time operator*(double m,const Time &t)
{
	Time result;
	long totalminutes=t.hours*mult*60_t.minutes*mult;
	result.hours=totalminutes/60;
	result.minutes=totalminutes%60;
	return result;
}
有了上述声明和定义后，下面的语句：
A=2.75*B;
将转换为如下语句，从而调用刚才定义的非成员友元函数：
A=operatot*(2.75,B);
总值，类的友元函数是非成员函数，其访问权限与成员函数相同。
应将友元函数看作类的扩展接口的组成部分。
通过使用友元函数和类方法，可以用同一个用户接口表达这两种操作。另外请记住，只有类声明可以决定哪一个函数是友元，因此雷声名仍然控制了哪些函数可以访问私有数据。总之，类方法和友元只是表达类接口的两种不同机制
实际上，按下面的方式对定义进行修改（交换乘法操作数的顺序），可以将这个友元函数编写为非友元函数
Time operator*(double m,const Time&t)
	return t*m;

如果要为类重载运算符，并将非类的项作为其第一个操作数，则可以用友元函数来反转操作数的顺序

常用的友元：重载<<运算符
一个很有用的类特性是，可以对<<运算符进行重载，使之能与cout一起来显示对象的内容
假设trip是一个Time对象。为显示Time的值，前面使用的是Show()。然而，如果可以像下面这样操作会更好
cout<<trip;
我们通过Time类声明来让重载<<,Time对象将是第一个操作数，就像使用成员函数重载*运算符那样。这意味着必须这样使用<<
trip<<cout;
我们可以这样使用友元函数，重载运算符
void operator<<(ostream & os,const Time & t){
	os<<t.hours<<" hours, << "<<t.minutes<<" minutes"; }

2<<的第二种重载版本
下面这样的语句可以正常工作：
cout<<trip;
但这种实现不允许像通常那样重新定义的<<运算符与cout一起使用
cout<<"Trip time: "<<trip<<" (Tuesday)\n";//wrong
可以对友元函数采用相同的方法。只要修改operator<<()函数，让它返回ostream对象的引用即可
ostream & operatro<<(ostream &os,const Time & t)
{
	os<<t.hours<<" hours, "<<t.minutes<<" minutes";
	return os;
}
注意返回类型是ostream &*/
#ifndef MYTIME3_H_
#define MYTIME3_H_
#include<iostream>
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
	Time operator+(const Time & t)const;
	Time operator-(const Time & t)const;
	Time operator*(double n)const;
	friend Time operator*(double m,const Time & t)
	{return t*m;}
	friend std::ostream & operator<<(std::ostream &os,const Time & t);
};
#endif


