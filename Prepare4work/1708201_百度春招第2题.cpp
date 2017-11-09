#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int n;
    vector<int> num;
    cin>>n;
    for(int i=n;i;i--){
         int temp;
         cin>>temp;
         num.push_back(temp);
    }
    if(n>2){
    int dist1[n],dist2[n];
    dist1[0]=0;
    for(int i=1;i<n;i++){
        dist1[i]=dist1[i-1]+abs(num[i]-num[i-1]);}
   // for(auto x:dist1)cout<<x<<" ";
   // cout<<endl;
    dist2[n-1]=0;
    for(int i=n-2;i>=0;--i)
        dist2[i]=dist2[i+1]+abs(num[i+1]-num[i]);
   // for(auto x:dist2)cout<<x<<" ";
   // cout<<endl;
    int pathsum=dist1[n-1];
    for(int i=1;i<n-1;i++){
        int cursum=dist1[i-1]+dist2[i+1]+abs(num[i+1]-num[i-1]);
        if(cursum<pathsum)pathsum=cursum;
    }
    if(pathsum==0)pathsum=abs(num[n-1]-num[0]);
    cout<<pathsum<<endl;
    }
    else if(n==2)cout<<abs(num[1]-num[0])<<endl;
    return 0;
}        
        

