#include<iostream>
#include<string>
using namespace std;
int compare(string A,string B)
{
    int lenA=A.size(),lenB=B.size();
    int N=lenB-lenA,count=0,max=0;
    if(B.empty()||lenA>lenB)return -1;
    if(A.empty())return lenB;
    for(int i=0;i<=N;i++){
        for(int j=0;j<lenA;++j){
            if(B[i+j]==A[j])
                count++;
        }
    max=max>count?max:count; 
    count=0;
    }
    return lenA-max;}
int main(){
    string A;
    string B;
    cin>>A>>B;
    cout<<compare(A,B)<<endl;
    return 0;
}

