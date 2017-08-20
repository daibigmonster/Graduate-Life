#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main(){
    string str1,str2;
    int dp[51][51];
    while(cin>>str1>>str2){
        int len1=str1.size();
        int len2=str2.size();
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(str1[i-1]==str2[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        cout<<dp[len1][len2]<<endl;
    }
    return 0;
}
