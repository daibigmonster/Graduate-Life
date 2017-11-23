#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int n;
    stack<int> a;
    while(cin>>n){
  
      while(n)
    {
        a.push(n&1);
        n>>=1;
     }
     while(a.size())
     {
         cout<<a.top();
         a.pop();
      }
      cout<<endl;
      }
      return 0;
  }
