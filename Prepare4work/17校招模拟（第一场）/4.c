#include<iostream>
using namespace std;
int count(int n,int x){
    int res=0,j;
    for(int i=0;j=n/10;i*=10){
        int high=j/10;
        if(x==0){
            if(high)high--;
            else break;
        }
        res+=high*i;
        int tem=j%10;
        if(tem>x)
            res+=i;
        else if(tem==x)
            res+=n-j*i+1;
     }
     return res;
}
int main(){
    int n;
    while(cin>>n){
        cout<<count(n,0);
    }
    return 0;
}
