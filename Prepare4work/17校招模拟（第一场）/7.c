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
<<<<<<< HEAD
        curnum=num/i;
        lownum=num%i;
        int curlen=len(i);
        count+=(highnum-1)*pow(10,curlen-1)+lownum+1; 
       // cout<<count<<endl;
=======
        if(highnum)highnum--;
        else break;
    }
    count+=highnum*factor;
    if(curnum>k)
        count+=factor;
    else if(curnum==k)
        count+=lownum+1;
    factor*=10;
>>>>>>> 856b8e4a784a690b8123c93237c425a2781a8f3e
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
