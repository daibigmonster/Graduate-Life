#include<iostream>
#include<vector>
#include<string>
using namespace std;
int division2(int num){
    if(num<=0)return num;
    while(num%2==0)num=num>>1;
    return num;
}
int main(){
    int length,temp;
    vector<int> num;
    cin>>length;
    for(int i=length;i;--i)
    {
        cin>>temp;
        num.push_back(temp);
    }
    int key=division2(num[0]);
    string result="YES";
    for(int i=1;i<length;i++){
        if(division2(num[i])!=key){
            result.clear();
            result="NO";
            break;
        }
    }
    cout<<result<<endl;
    return 0;
}
