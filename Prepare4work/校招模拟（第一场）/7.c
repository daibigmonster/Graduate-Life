#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int len(int num)
{
    int length=1;
    while(num/=10)
        length++;
    return length;}
int count(int num,int k)
{
    //cout<<"1"<<endl;
    if(num==0)return 0;
    int length=len(num);
    int first=static_cast<int>(num/pow(10,length-1));
    int firstcount; 
    if(first==k)
        firstcount=num-first*pow(10,length-1)+1;
    else if(first>k)
        firstcount=pow(10,length-1);
    else
        firstcount=0;
    int notfirstcount=(length-1)*pow(10,length-2)*first;
    int lastcount=count(num-first*pow(10,length-1),k);
    return firstcount+notfirstcount+lastcount;
}
int main()
{
    int result=count(999,2);
    cout<<result<<endl;
    return 0;
}
