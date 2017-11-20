#include<iostream>
#include<cmath>
using namespace std;
bool isprime(int n){
    int s=sqrt(n);
    for(int i=2;i<=s;i++)
        if(n%i==0)
            return false;
     return true;
}
int main(){
    long long n;
    while(cin>>n){
        int p,q;
        int L=log10(n)/log10(2);
        for(q=2;q<=L;q++){
            p=pow(n,1.0/q);
            if(pow(p,q)==n&&isprime(p)){
                cout<<p<<" "<<q<<endl;
                break;
            }
        }
        if(q>L)cout<<"No";
    }
    return 0;
}
