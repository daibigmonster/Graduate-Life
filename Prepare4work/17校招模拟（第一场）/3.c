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
    int count=0;
    int factor=1;
    int lownum=0;
    int curnum=0;
    int highnum=0;
    while(num/(factor*10)!=0){
    lownum=num-(num/factor)*factor;
    curnum=(num/factor)%10;
    highnum=num/(factor*10);
    if(curnum==0||curnum!=0&&lownum!=0)
        count+=(highnum-1)*factor+lownum+1;
    else
        count+=(highnum-1)*factor+factor+lownum;
    factor*=10;
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
