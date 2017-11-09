/*题目：24点运算
允许中间运算存在小数*/
#include<iostream>
#include <string>
#include <math.h>
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
typedef  char STRING[100];
const double lnum=1E-6;
const int Cardnum=4;
const int Resultvalue=24;
double num[Cardnum];
std::string result[Cardnum];
using namespace std;
bool Pg(int n)
{
    if(n==1)
    {
        if(fabs(num[0]-Resultvalue)<lnum)
            {
            cout<<result[0]<<endl;
            return true;}
         else return false;
         
     }
     for(int i=0;i<n;i++)
     {
         for(int j=i+1;j<n;j++)
         {
             double a,b;
             string expa,expb;
             a=num[i];
             b=num[j];
             num[j]=num[n-1];
             expa=result[i];
             expb=result[j];
             result[j]=result[n-1];
             
             result[i]='('+expa+'+'+expb+')';
            // cout<<result[i]<<endl;
             num[i]=a+b;
             //cout<<num[i]<<endl;
             if(Pg(n-1))
                 return true;
             
             result[i]='('+expa+'-'+expb+')';
            // cout<<result[i]<<endl;
             num[i]=a-b;
            // cout<<num[i]<<endl;
             if(Pg(n-1))
                 return true;
                 
             result[i]='('+expb+'-'+expa+')';
            // cout<<result[i]<<endl;
             num[i]=b-a;
             //cout<<num[i]<<endl;
             if(Pg(n-1))
                 return true;
                 
             result[i]='('+expa+'*'+expb+')';
            // cout<<result[i]<<endl;
             num[i]=a*b;
            // cout<<num[i]<<endl;
             if(Pg(n-1))
                 return true;
             
             
             if(b!=0){    
             result[i]='('+expa+'/'+expb+')';
            // cout<<result[i]<<endl;
             num[i]=a/b;
            // cout<<num[i]<<endl;
             if(Pg(n-1))
                 return true;}
             
             if(a!=0){
             result[i]='('+expb+'/'+expa+')';
             //cout<<result[i]<<endl;
             num[i]=b/a;
            // cout<<num[i]<<endl;
             if(Pg(n-1))
                 return true;}
            
                 
             num[i]=a;
             num[j]=b;
             result[i]=expa;
             result[j]=expb;
        }
    }
    return false;
}
int main()
{
    int x;
    for(int i=0;i<Cardnum;i++)
    {
        char buffer[20];
        cout<<"the "<<i<<"th number:";
        cin>>x;
        num[i]=x;
        //itoa(x,buffer,10);
        sprintf(buffer,"%d",x);
        result[i]=buffer;
     }
     if(Pg(Cardnum))cout<<"Success!"<<endl;
     else cout<<"Fail!"<<endl;
     return 0;
}
