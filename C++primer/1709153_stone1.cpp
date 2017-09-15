#include<iostream>
#include"17090151_stone1.h"
int main(){
	using std::cout;
	Stonewt poppins(9,2.8);
	double p_wt=poppins;
	cout<<"Convert to double=> ";
	cout<<"Poppins: "<<p_wt<<" pounds.\n";
	cout<<"Convet to int => ";
	cout<<"Poppins: "<<int(poppins)<<" poounds.\n";
	return 0;
}
