#include<iostream>
#include<string>
#include<cmath>
using namespace std;
bool Isprime(int num)
{
    if(num<=0)return false;
    for(int i=2;i<=sqrt(num);i++)
        if(num%i==0)return false;
    return true;
}
bool magicnum(int num)
{
    string strnum=to_string(num);
    int begin=0;
    int length=strnum.size();
    while(begin<length-1){  
        for(int i=1;i<length-begin;i++){    
            string str1,str2;
            (str1+=strnum[begin])+=strnum[begin+i];
            (str2+=strnum[begin+i])+=strnum[begin];
            int num1=atoi(str1.c_str());
            int num2=atoi(str2.c_str());
            
            if((Isprime(num1)&&(num1>=10))||(Isprime(num2)&&(num2>=10))){
                //cout<<num1<<" "<<num2<<endl;
                return true;}
        }
        begin++;
    }
    return false;
}
int main()
{
    int begin,end,index,count=0;
    cin>>begin>>end;
   for(index=begin;index<=end;index++){
            if(index<10)if(Isprime(index))count++;
            if(index>9&&index<100){
            int num1=index/10;
            int num2=index%10;
            int temp=num2*10+num1;
            if(Isprime(index)||(Isprime(temp)&&(temp>10))){
               // cout<<index<<" ";
                count++;}}
            if(index>99)if(magicnum(index))count++;
        }
    cout<<count<<endl;
    return 0;         
}
