#ifndef BRASS_H_
#define BRASS_H_
#include <string>
using std::string;
class Brass
{
private:
	string fullName;
	long acctNum;
	double balance;
public:
	Brass(const string & s = "Nullbody",long an = -1,
			double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt);
	double Balance() const;
	virtual void ViewAcct() const;
	virtual ~Brass() {};
};
class BrassPlus : public Brass
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const string & s = "Nullbody",long an = -1,
			double bal = 0.0,double ml = 500,
			double r = 0.11125);
	BrassPlus(const Brass & ba,double ml = 500,
			double r = 0.11125);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) {maxLoan = m;}
	void ResetRate(double r) {rate = r;}
	void ResetOwes() {owesBank = 0;}
};
/*
 * 注意：如果在派生类中重新定义基类方法，通常应将基类方法声明
 * 为虚方法。这样，程序将根据对象类型而不是引用或指针的类型来选择
 * 方法版本。为基类声明一个虚析构函数也是一种惯例
 */
#endif
