#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,count=1;
    while(cin>>n){
    if(n==0||n==1){
        cout<<0<<endl;
        break;
    }
    vector<int> num(n,0);
    for(int i=0;i<n;i++)cin>>num[i];
    vector<int> comnum(num.begin(),num.end());
    sort(comnum.begin(),comnum.end());
    
    for(int i=1;i<n;i++){
        auto x1=find(num.begin(),num.end(),comnum[i-1]);
        auto x2=find(num.begin(),num.end(),comnum[i]);
        if(x2<x1)break;
        else count++;
    }
    cout<<num.size()-count<<endl;}
    return 0;
}
