#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    long sum=0;
    cin>>n;
    vector<int> numbers;
    for(int i=0;i<n*3;i++){
        int temp;
        cin>>temp;
        numbers.push_back(temp);
    }
    sort(numbers.begin(),numbers.end());
    for(int i=n;i<3*n;i+=2)sum+=numbers[i];
    cout<<sum<<endl;
    return 0;
}
