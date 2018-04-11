#include <iostream>
#include <string>
#include "acctabc.h"
const int CLIENTS = 4;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;

	// AcctABC * p_clients[CLIENTS];
	string temp;
	long tempnum;
	double tempbal;
	char kind;

	cout << zheyenengxing.a << " " << zheyenengxing.b << endl;

	AcctABC * test = new Brass("daijian",100000,3.45);
	test->ViewAcct();
	delete test;

	// for(int i = 0; i < CLIENTS; i++)
	// {
	// 	cout << "Enter client's name: ";
	// 	getline(cin,temp);
	// 	cout << "Enter client's account number: ";
	// 	cin >> tempnum;
	// 	cout << "Enter opening balance: $ ";
	// 	cin >> tempbal;
	// 	cout << "Enter 1 for Brass Account or "
	// 		 << "2 for BrassPlus Account: ";
	// 	while(cin >> kind && (kind != '1' && kind != '2') )cout << "Enter either 1 or 2";
	// 	if(kind == '1')
	// 		p_clients[i] = new Brass(temp,tempnum,tempbal);
	// 	else if(kind == '2')
	// 	{
	// 		double tmax,trate;
	// 		cout << "Enter the overdraft limit: $";
	// 		cin >> tmax;
	// 		cout << "Enter the interest rate "
	// 			 << "as a decimal fraction: ";
	// 		cin >> trate;
	// 		p_clients[i] = new BrassPlus(temp,tempnum,tempbal,
	// 				tmax,trate);

	// 	}
				
	// 	while (cin.get() != '\n') continue;
	
	// }
	// cout << endl;

	// for(int i = 0; i < 4 ; i++ )
	// {
	// 	p_clients[i] -> ViewAcct();
	// 	cout << endl;
	// }
    
	// for(int i = 0; i < 4 ; i++ ) delete p_clients[i];
	// cout << "Done.\n";
	return 0;

}
