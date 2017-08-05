#include<iostream>
#include<vector>
#in
#include<algorithm>
using namespace std;
int main()
{
    int length;
    cin>>length;
    vector<int> a;
    int sum=0;
    for(int i=0;i<length;i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
        sum+=a[i];
    }
    sum=sum/2;
    sort(a.begin(),a.end());
    for(int i=0;i<length;++i)
    {
        if(sum-a[length-1]-a[0]==0)}
    return 0;
}
