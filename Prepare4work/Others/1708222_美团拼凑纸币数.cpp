/*给你六种面额 1、5、10、20、50、100 元的纸币，假设每种币值的数量都足够多，编写程序求组成N元（N为0~10000的非负整数）的不同组合的个数。
输入描述:

输入包括一个整数n(1 ≤ n ≤ 10000)



输出描述:

输出一个整数,表示不同的组合方案数


输入例子1:

1


输出例子1:

1*/
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int a[6]={1,5,10,20,50,100};
        int rows=6;
        vector<vector<long> > dp(rows,vector<long>(n+1,0));
        for(int i=0;i<=n;i++)dp[0][i]=1;
        for(int i=1;i<rows;i++){
            for(int j=0;j<=n;j++){
            int m=j/a[i];
                for(int k=0;k<=m;k++){
                    dp[i][j]=dp[i][j]+dp[i-1][j-k*a[i]];
                }
            }
        }
        cout<<dp[rows-1][n]<<endl;
    }
    return 0;
}
