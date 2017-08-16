#include<iostream>
#include<string>
using namespace std;
int compare(string A,string B)
{
    int lenA=A.size(),lenB=B.size();
    if(B.empty()||lenA>lenB)return 0;
    if(A.empty())return lenB;
    for(int i=0;i<lenA;i++){
        for(int j=0;j<lenB;j++){
            if(A[i]==B[j])}}
    }
int main(){
    string A;
    string B;
    cin>>A>>B;
    cout<<compare(A,B);
    return 0;
}

