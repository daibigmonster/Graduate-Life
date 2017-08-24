#include<iostream>
#include<string>
using namespace std;
int main(){
	string a,b;
	while(cin>>a>>b){
	int lena=a.size();
	int lenb=b.size(),i=0,loc=-1;
    string result="Yes";
	for(int i=0;i<lenb;i++){
		loc=a.find(b[i],loc+1);
		if(loc==string::npos){
			result="No";
		}
	}
	cout<<result<<endl;
	}	
return 0;
}

