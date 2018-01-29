#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int countnum(int num,int k)
{
    int count=0;
    int factor=1;
    int lownum=0;
    int curnum=0;
    int highnum=0;
    while(num/factor){
    lownum=num-(num/factor)*factor;
    curnum=(num/factor)%10;
    highnum=num/(factor*10);
    if(k==0)
    {
        if(highnum)highnum--;
        else break;
    }
    count+=highnum*factor;
    if(curnum>k)
        count+=factor;
    else if(curnum==k)
        count+=lownum+1;
    factor*=10;
    }
    return count;
    
}

int main(){
    int num;
    while(cin>>num){
    cout<<countnum(num,0);
    for(int i=1;i<10;i++)
        cout<<" "<<countnum(num,i);}
    return 0;
}
