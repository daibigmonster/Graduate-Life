#include<iostream>
#include<vector>
using namespace std;
int candy(vector<int> ratings) {
	int n=ratings.size(),sum=0;
	if(n==0||n==1)return n;
	vector<int>dp(n,1);
 	for(int i=1;i<n;i++)
		if(ratings[i]>ratings[i-1])dp[i]=dp[i-1]+1;
	for(auto x:dp)cout<<x<<" ";
	cout<<endl;
	cout<<ratings[n-2]<<" "<<ratings[n-1]<<endl;
	for(int i=n-2;i>=0;--i){
		if(ratings[i]>ratings[i+1]&&dp[i]<=dp[i+1]){
			dp[i]=dp[i+1]+1;
		cout<<"11"<<endl;
	}}
	for(auto x:dp)cout<<x<<" ";
	cout<<endl;
	for(auto x:dp)sum+=x;
	return sum;
}
int main()
{
	int n;
	vector<int>ratings;
	while(cin>>n){
		int temp;
		temp=n;
		ratings.push_back(temp);
	}
	int res=candy(ratings);
	cout<<res<<endl;
	return 0;
}
