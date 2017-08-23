#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
    int n,maxheight=0;
    long maxarea=0;
    cin>>n;
    vector<int> height(n,0);
    for(int i=0;i<n;i++){
        cin>>height[i];
        maxheight=maxheight>height[i]?maxheight:height[i];
    }
    //cout<<maxheight<<endl;
    int dp[n+1][maxheight+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=maxheight;j++){
            if(j<=height[i-1]){
				dp[i][j]=dp[i-1][j]+j;
            	maxarea=maxarea>dp[i][j]?maxarea:dp[i][j];}
            else dp[i][j]=0;
            //cout<<i<<" "<<j<<" "<<maxarea<<endl;
        }
    }
    cout<<maxarea<<endl;
    return 0;
}
