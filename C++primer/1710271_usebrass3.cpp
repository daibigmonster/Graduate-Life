/* 在之前的程序中，方法是通过对象（而不是指针或引用）调用的，
 * 没有使用虚方法特性。下面来看一个使用了虚方法的例子。假设
 * 要同时管理Brass和BrassPlus账户，如果能使用同一个数组来
 * 保存Brass和BrassPlus对象，将很有帮助，但这是不可能的
 * 数组中所有元素的类型必须相同，而Brass和BrassPlus是不同的类型。
 * 然，可以创建指向Brass的指针数组。这样每个元素类型都相同，
 * 但由于使用的是公有继承模型，因此Brass指针既可以指向Brass
 * 对象，也可以指向BrassPlus对象。。因此，可以使用与数组来表示
 * 多种类型的对象。这就是多态性
 */
#include <iostream>
#include <string>
#include "1710241_acctabc.h"
const int CLIENTS = 4;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;

	AcctABC * p_clients[CLIENTS];
	string temp;
	long tempnum;
	double tempbal;
	char kind;

	for(int i = 0; i < CLIENTS; i++)
	{
		cout << "Enter client's name: ";
		getline(cin,temp);
		cout << "Enter client's account number: ";
		cin >> tempnum;
		cout << "Enter opening balance: $ ";
		cin >> tempbal;
		cout << "Enter 1 for Brass Account or "
			 << "2 for BrassPlus Account: ";
		while(cin >> kind && (kind != '1' && kind != '2') )cout << "Enter either 1 or 2";
		if(kind == '1')
			p_clients[i] = new Brass(temp,tempnum,tempbal);
		else if(kind == '2')
		{
			double tmax,trate;
			cout << "Enter the overdraft limit: $";
			cin >> tmax;
			cout << "Enter the interest rate "
				 << "as a decimal fraction: ";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp,tempnum,tempbal,
					tmax,trate);

		}
				
		while (cin.get() != '\n') continue;
	
	}
	cout << endl;

	for(int i = 0; i < 4 ; i++ )
	{
		p_clients[i] -> ViewAcct();
		cout << endl;
	}
    
	for(int i = 0; i < 4 ; i++ ) delete p_clients[i];
	cout << "Done.\n";
	return 0;

}
