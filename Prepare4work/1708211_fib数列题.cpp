#include<iostream>
#include<vector>
using namespace std;
int  fib(int num)
{
    if(num==1||num==0)return num;
    else {
        int fib1=0,fib0=0,fibn=1;
        while(fibn<num){
            fib0=fib1;
            fib1=fibn;
            fibn=fib1+fib0; 
            //cout<<fib0<<" "<<fib1<<" "<<fibn<<endl;         
        }
        if(fibn==num)return fibn;
        else return fib1;
    }
}
int main(){
    int num,maxfib=0,count=0;
    cin>>num;
    while(num){
        maxfib=fib(num);
        cout<<maxfib<<endl;
        num=num-maxfib;
        
        if(num>0)count++;
        else break;
    }
    cout<<count<<endl;
    return 0;
}
