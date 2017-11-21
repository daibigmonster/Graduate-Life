#include<iostream>
#include<vector>
using namespace std;
vector<int> reverse(vector<int> num){
    vector<int> temp(num.rbegin(),num.rend());
    return temp;}
int main(){
    int n;
    cin>>n;
    vector<int> num(n,0);
    vector<int> result;
    for(int i=0;i<n;i++){
        cin>>num[i];
        result.push_back(num[i]);
        result=reverse(result);
    }
    cout<<result[0];
    for(int i=1;i<n;i++)cout<<" "<<result[i];
    return 0;
}
