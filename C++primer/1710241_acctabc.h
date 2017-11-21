/* 这里将ABC概念用于Brass和BrassPlus账户，首先定义一个名为AcctABC的ABC。这个类包含Brass和BrassPLus类公有的
 * 方法和数据成员，，而那些在BrassPlus和Brass类中的行为不同的方法应被声明为虚函数。至少应有一个虚函数时纯虚函数，
 * 这样才能使AcctABC称为抽象类。
 * 头文件声明了AccABC类(ABC)、Brass类和BrassPlus类（两者都是具体类）。为帮助派生类访问基类数据，AcctABC提供了一些
 * 保护方法；派生类方法可以调用这些方法，但他们并不是派生类对象的公有接口的组成部分。AcctABC还提供一个保护成员函数，
 * 用于处理格式化（以前是使用非成员函数处理的）。另外，AcctABC类还有两个纯虚函数，所以它确实是抽象类。
 *
 */
#ifndef ACCTABC_H_
#define ACCTABC_H_
#include <iostream>
#include <string>

class AcctABC
{
private:
	std::string fullName;
	long acctNum;
	double balance;
protected:
	struct Formatting
	{
		std::ios_base::fmtflags flag;
		std::streamsize pr;
	};
	const std::string & FullName() const {return fullName;}
	long AcctNum() const {return acctNum;}
	Formatting SetFormat() const;
	void Restore(Formatting & f) const;
public:
	AcctABC(const std::string & s = "Nullbody",long an = -1,double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt) = 0;//纯虚函数
	double Balance() const {return balance;};
	virtual void ViewAcct() const = 0;
	virtual ~AcctABC() {};
};



class Brass : public AcctABC
{
public:
	Brass(const std::string & s = "Nullbody",long an = -1,double bal = 0.0) : AcctABC(s,an,bal){};
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	virtual ~Brass() {};
};



class BrassPlus : public AcctABC
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const std::string & s = "Nullbody",long an = -1,double bal = 0.0,double ml = 500,double r =0.10);
	BrassPlus(const Brass & ba,double ml = 500,double r = 0.1);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) {maxLoan = m;};
	void ResetRate(double r){rate = r;};
	void ResetOwes() {owesBank = 0;};
};
#endif
