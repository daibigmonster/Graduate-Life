#include<iostream>
#include<vector>
using namespace std;
int  fib1(int num)
{
    if(num==1||num==0)return num;
    else {
        int fib1=0,fib0=0,fibn=1;
        do{
            fib0=fib1;
            fib1=fibn;
            fibn=fib1+fib0; 
            //cout<<fib0<<" "<<fib1<<" "<<fibn<<endl;         
        }while(fibn<num);
        return fib1;
    }
}
int  fib2(int num)
{
    if(num==1||num==0)return num;
    else {
        int fib1=0,fib0=0,fibn=1;
        do{
            fib0=fib1;
            fib1=fibn;
            fibn=fib1+fib0; 
            //cout<<fib0<<" "<<fib1<<" "<<fibn<<endl;         
        }while(fibn<num);
        return fibn;
    }
}
int main(){
    int num,maxfib,minfib,count=0;
    while(cin>>num){
        maxfib=fib1(num);
        minfib=fib2(num);
        count=min(num-maxfib,minfib-num);
        cout<<count<<endl; 
    }
    return 0;
}
