/*大富翁游戏，玩家根据骰子的点数决定走的步数，即骰子点数为1时可以走一步，点数为2时可以走两步，点数为n时可以走n步。求玩家走到第n步（n<=骰子最大点数且是方法的唯一入参）时，总共有多少种投骰子的方法。
输入描述:

输入包括一个整数n,(1 ≤ n ≤ 6)



输出描述:

输出一个整数,表示投骰子的方法


输入例子1:

6


输出例子1:

32*/
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[7],dp[7];
    for(int i=0;i<=n;i++){
        a[i]=i;
        dp[i]=0;
    }
    
   
    for(int i=1;i<=n;i++){
     
        for(int j=1;j<=i;j++){
           // cout<<"111 "<<endl;
            dp[i]+=dp[i-a[j]];
        }
        dp[i]++;
    }
    cout<<dp[n]<<endl;
}
