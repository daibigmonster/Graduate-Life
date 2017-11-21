#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int change(long num);
int main(){
    long temp,result;
    while(cin>>temp){
        result=change(temp);
        cout<<result<<endl;
    }
    return 0;
}
int change(long num)
{
    int count=0;
    long mul=1;
    if(num<=9)return 0;
    while(num>10){
        count++;
        while(num){
            mul*=(num%10);
            num/=10;
        }
       if(mul<10)break;
       else 
           num=mul;
    }
    return count;
}
