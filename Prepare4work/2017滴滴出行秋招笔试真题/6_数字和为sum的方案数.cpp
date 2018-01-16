// 给定一个有n个正整数的数组A和一个整数sum,求选择数组A中部分数字和为sum的方案数。
// 当两种选取方案有一个数字的下标不一样,我们就认为是不同的组成方案。
// 输入描述:

// 输入为两行:
//  第一行为两个正整数n(1 ≤ n ≤ 1000)，sum(1 ≤ sum ≤ 1000)
//  第二行为n个正整数A[i](32位整数)，以空格隔开。



// 输出描述:

// 输出所求的方案数


// 输入例子1:

// 5 15 
// 5 5 10 2 3


// 输出例子1:

// 4
#include <iostream>
#include <vector>
using namespace std;
vector<vector<long> >dp(1001,vector<long>(1001,0));
int main(){
    int n,sum;
    while(cin>>n>>sum){
        vector<int> A(n,0);
        for(int i = 0;i < n;i++)cin >> A[i];
        dp[0][0] = 1;
        for(int i = 1;i <= n;i++ ){
            for(int j = 0;j <= sum;j++){
                dp[i][j] = dp[i - 1][j];
                if(A[i - 1] <= j)dp[i][j] += dp[i - 1][j - A[i - 1]];
            }
        }
        cout << dp[n][sum] << endl;
    }
    return 0;
}