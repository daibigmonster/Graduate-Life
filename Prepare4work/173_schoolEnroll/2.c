#include<iostream>
#include<string>
#include<cmath>
bool Isprime(int &num)
{
    if(num<=0)return false;
    for(int i=2;i<sqrt(num);i++)
        if(num%i==0)return false;
    return true;
}
int length(int &num)
{
    if(!num)return -1;
    int count=0;
    while(num){
        count++;
        num/=10;
    }
    return count;
}
bool magicnum(int &num)
{
    string strnum=to_string(num);
    int begin=0;
    int length=strnum.size();
    while(begin<length-1){
        for(int i=1;i<length;i++)
        }}
int main()
{
    int begin,end,index,count=0;
    cin>>begin>>end;
    for(index=begin;index<=end;index++){
        if(length(index)<=2&&lenght(index)>0){
            if(Isprime)count++;
        }
        else if(lenght(index)>2)}
}
