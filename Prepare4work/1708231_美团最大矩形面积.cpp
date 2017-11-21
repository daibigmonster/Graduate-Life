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
    vector<vector<int> > dp(n+1,vector<int> (maxheight+1,0));
    //memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=maxheight;j++){
            if(j<=height[i-1]){
				dp[i][j]=dp[i-1][j]+j;
            	maxarea=maxarea>dp[i][j]?maxarea:dp[i][j];}
            else dp[i][j]=0;
            //cout<<dp[i][j]<<" "<<i<<" "<<j<<" "<<maxarea<<endl;
        }
    }
	/*for(int i=0;i<n+1;i++){
		for(int j=0;j<maxheight+1;j++){		
			cout<<dp[i][j]<<" ";}
		cout<<endl;
	}*/
    cout<<maxarea<<endl;
    return 0;
}
