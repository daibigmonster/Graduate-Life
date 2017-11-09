#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstdio>
using namespace std;
int evalRPN(vector<string> &tokens) {
        vector<int> temp;
        if(tokens.size()==1)return atoi(tokens.back().c_str());
        for(auto i:tokens){
            if(i=="+"){
				int a=temp.back();temp.pop_back();
				int b=temp.back();temp.pop_back();
				temp.push_back(a+b);
            }
            else if(i=="-"){
				int a=temp.back();temp.pop_back();
				int b=temp.back();temp.pop_back();
				temp.push_back(b-a);
            }
            else if(i=="*"){
				int a=temp.back();temp.pop_back();
				int b=temp.back();temp.pop_back();
				temp.push_back(b*a);
            }
            else if(i=="/"){
				int a=temp.back();temp.pop_back();
				int b=temp.back();temp.pop_back();
				temp.push_back(b/a);
            }
            else{
                    temp.push_back(atoi(i.c_str()));
            }
        }
        return temp.back();
    }
int main(){
	vector<string>tokens;
	string temp;
	while(cin>>temp){
		tokens.push_back(temp);}
	int result=evalRPN(tokens);
	cout<<result<<endl;
	return 0;
}
