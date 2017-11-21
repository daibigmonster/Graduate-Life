#include<iostream>
#include<vector>
using namespace std;
int main(){
int n,temp,count=1;
vector<int>num;
cin>>n;
int flag=-1;
for(int i=n;i;i--){
    cin>>temp;
    num.push_back(temp);}
for(int i=0;i<n-1;i++){
    if(flag==-1){
        if(num[i]<num[i+1]){
            flag=0;
        }
        else if(num[i]>num[i+1])flag=1;
    }
    else if((num[i]<num[i+1])&&flag==1){
           count++;
           flag=-1;
       }
    else if((num[i]>num[i+1])&&flag==0){
           count++;
           flag=-1;
       }
}
cout<<count<<endl;
return 0;
    
    }     
