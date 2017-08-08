#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
int n,temp;
cin>>n;
vector<int>num;
vector<int>maybenum;
bool mistake=false;
for(int i=0;i<n;i++){
    int a;
    cin>>a;
    num.push_back(a);
}
sort(num.begin(),num.end());
for(int i=n-1;i;--i){
    if(num[i]==num[i-1]+1)continue;
    if(num[i]-1==num[i-1]+1)
        maybenum.push_back(num[i]-1);
    else if(num[i]-1>num[i-1]+1)
    {
        mistake=true;
        break;
    }
}
if(mistake||maybenum.size()>1)cout<<"mistake"<<endl;
else if(maybenum.empty())cout<<num.front()-1<<" "<<num.back()+1<<endl;
else if(maybenum.size()==1)cout<<maybenum.front()<<endl;
return 0;
}
