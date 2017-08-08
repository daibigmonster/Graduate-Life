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
    for(int i=1;highnum=(int)(num/(i*10));i*=10)
    {
        curnum=(int)(num/i);
        lownum=num%i;
        int curlen=len(i);
        count+=(highnum-1)*pow(10,curlen-1)+lownum+1; 
       // cout<<count<<endl;
    }
    return count;
}
int main()
{
    int num;
    
    while(cin>>num){
    cout<<count0(num);
   /*for(int i=1;i<10;i++){
    cout<<" "<<count(num,i);}
    cout<<endl;*/}
    return 0;
}
