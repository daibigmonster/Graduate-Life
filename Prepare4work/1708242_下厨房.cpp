#include<iostream>
#include<string>
#include<set>
using namespace std;
int main(){
	string foodname;
	set<string> foodlist;
	while(cin>>foodname){
		if(!foodlist.count(foodname))foodlist.insert(foodname);}
	cout<<foodlist.size()<<endl;
	return 0;
}
