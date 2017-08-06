#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int len(int num)
{
    if(num==0) return 0;
    int length=1;
    while(num/=10)
        length++;
    return length;}
int count0(int num)
{
    if(num<=9)return 0;
    int highnum,curnum,lownum;
    int length=len(num),count=0;
    for(int i=1;highnum=num/(i*10);i*=10)
    {
        curnum=num/i;
        lownum=num%i;
        count+=(highnum-1)*pow(10,len(i/10))+lownum+1; 
       // cout<<count<<endl;
    }
    return count;
}
int count(int num,int k)
{
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
    int num;
    
    while(cin>>num){
    cout<<count0(num);
    for(int i=1;i<10;i++){
    cout<<" "<<count(num,i);}
    cout<<endl;}
    return 0;
}
