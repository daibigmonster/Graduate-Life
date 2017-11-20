#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<iterator>
int main()
{
    using namespace std;
    cont int N=6;
    string s1[N]={"buffoon","thinkers","for","heavy","can","for"};
    string s2[N]={"metal","any","food","elegant","deliver","for"};
    set<string> A(s1,s1+N);
    set<string> B(s2,s2+N);
    
    ostream_iterator<string,char> out(cout," ");
    cout<<"Set A: ";
    copy(A.begin(),A.end(),out);
    cout<<endl;
    cout<<"Set B: ";
    copt(B.begin(),B.end(),out);
    cout<<endl;}
