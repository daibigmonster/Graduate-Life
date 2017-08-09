#include<iostream>
#include<set>
using namespace std;
int main()
{
    string str;
    multiset<char> s;
    while(cin>>str){
        if(str.empty())
        {
            cout<<"0";
            break;}
    for(int i=0;i<str.size();i++){
        if(str[i]==str[i+1]&&i!=str.size()-1)s.insert(str[i]);
        else if(str[i]!=str[i+1]&&i!=str.size()-1){
             s.insert(str[i]);
             cout<<s.count(str[i])<<str[i];
             s.clear();
        }
        else if(i==str.size()-1){
             if(str[i]!=str[i-1])
                 cout<<"1"<<str[i];
             else
             {s.insert(str[i]);
             cout<<s.count(str[i])<<str[i];
             s.clear();}
        }
  }}
    return 0;
}
