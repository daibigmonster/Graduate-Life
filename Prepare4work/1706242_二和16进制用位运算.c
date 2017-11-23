#include<iostream>
#include<stack>

using namespace std;
void convert(int n,int m,int a)
{
    stack<int> s;
    while(n)
    {
        s.push(n&(m-1));
        n>>=a;
    }
    while(s.size())
    {
        cout<<s.top();
        s.pop();
     }
} 

int main() {
    int n;    
    while(cin >> n) {
        convert(n,2,1);
        cout<<endl;
        convert(n,8,3);
        cout<<endl;
        convert(n,16,4);
        cout<<endl;
    }
    return 0;
}
