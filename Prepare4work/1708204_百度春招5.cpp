#include<iostream>
#include<string>
#include<vector>
#include<string.h>
using namespace std;
int main(){
    int n,row,col;
    int dp[1001][1001];
    while(cin>>n>>row){
        col=n-1-row;
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=0;i<=row;i++){
            for(int j=0;j<=col;j++){
                if(i==0||j==0)dp[i][j]=1;
                else dp[i][j]=(dp[i-1][j]*(j+1)+dp[i][j-1]*(i+1))%2017;
            }
        }
        cout<<dp[row][col];
    }
    return 0;
}
