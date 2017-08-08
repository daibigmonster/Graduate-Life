#include<iostream>
#include<string>
using namespace std;
int main()
{
    int num;
    
    while(cin>>num){
    cout<<count0(num);
   /*for(int i=1;i<10;i++){
    cout<<" "<<count(num,i);}
    cout<<endl;*/}
    string A,B;
    cin>>A>>B;
    int result=A.size(),count=0;
    for(int i=0;i<A.size();i++){
        if(A.size()!=B.size())break;
        if(A[i]=='A'&&B[i]=='T'||
           A[i]=='T'&&B[i]=='A'||
           A[i]=='C'&&B[i]=='G'||
           A[i]=='G'&&B[i]=='C')
             count++;}
    cout<<result-count<<endl;
    return 0;
}
