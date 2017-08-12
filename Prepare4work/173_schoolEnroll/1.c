#include<iostream>
#include<string>
#include<cmath>
using namespace std;
bool magicnum(int num);
bool Isprime(int num)
{
    if(num<=0)return false;
    for(int i=2;i<sqrt(num);i++)
        if(num%i==0)return false;
    return true;
}
int main()
{
    int temp;
    cin>>temp;
    if(magicnum(temp))cout<<"1111111"<<endl;
    
    return 0;
}
bool magicnum(int num)
{
    string strnum=to_string(num);
    int begin=0;
    int length=strnum.size();
    while(begin<length-1){  
        for(int i=1;i<length-begin;i++){    
            int num1,num2;
            cout<<length<<endl;
            string str1,str2;
            (str1+=strnum[begin])+=strnum[begin+i];
            (str2+=strnum[begin+i])+=strnum[begin];
            num1=atoi(str1.c_str());
            num2=atoi(str2.c_str());
            
            if(Isprime(num1)||Isprime(num2))return true;
        }
        begin++;
    }
    return false;
}
