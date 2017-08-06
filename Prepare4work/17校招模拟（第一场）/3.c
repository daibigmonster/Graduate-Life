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
        cout<<(highnum-1)*pow(10,len(i/10))+lownum+1<<endl;
    }
    return count;
}
int main(){
    int num;
    while(cin>>num){
    int result=count0(num);
    cout<<result<<endl;}
    return 0;
}
