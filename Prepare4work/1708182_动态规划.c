/* 上文中d(i)表示凑够i元需要的最少硬币数量，我们将它定义为该问题“状态”，这个状态是怎么找出来的呢？根据子问题定义的状态。逆找到子问题，状态也就浮出水面了。最终我们要求的解的问题，可以用这个状态来表示：d(11)，即凑够11源最少需要多少个硬币。那状态转移方程是什么呢？既然我们用d(i)表示状态，那么状态转移方程自然包含d(i),上文中包含状态d(i)的方程是：d(3)=min{d(3-1)+1,d(3-3)+1}。没错，它就是状态转移方程，描述状态之间如何转移的。当然我们要对它抽象一下，
d(i)=min{d(i-vj)+1},其中i-vj>=0,vj表示第j个硬币的面值;
*/
int main(){
    int a[3]={1,3,5},sum=11,cent=0,dp[12];
    for(int i=0;i<=sum;i++)dp[i]=i;
    for(int i=1;i<=sum;++i){
        for(int j=0;j<3;j++){
            if(i>=a[j]&&dp[i-a[j]]+1<dp[i])
                dp[i]=dp[i-a[j]]+1;
        }
    }
    cout<<dp[sum]<<endl;
    return 0;
}
/*
将一个由N行数字组成的三角形，如图所以，设计一个算法，计算出三角形的由顶至底的一条路径，使该路径经过的数字总和最大。
*/
int main()
{
    int t,n,i,j;
    for(i=n-1;i;--i)
        for(j=0;j<i;j++)
            a[i-1][j]+=max(a[i][j],a[i][j+1]);
    cout<<a[0][0]<<endl;
    return 0;
}
/*一个序列有N个数，A1，A2,...,AN,求出最长非降子序列的长度
面对这样一个问题，我们首先要定义一个“状态”来代表它的自问题，并找到它的解。注意，大部分情况下，某个状态只与它前面出现的状态有关，而独立与后面的状态
让我们沿用“入门”一节里拿到简单题的思路来一步步找到“状态”和状态转移方程。加入我们考虑求A[1],A[2],...，A[i]的最长非降子序列的长度，其中，其中i<N,那么上面的问题变成了原问题的一个子问题，然后我们定义d(i),表示前i个树中以A[i]结尾的最长非降子虚列的长度。如果我们把d(1)到d(N)都计算出来，那么最终我们要找的答案就是这里面最大的那个。
如下N个数的序列是
5,3,4,8,6,7
根据上面找到的状态，我们可以得到：（非降子序列=LIS）
前1个数的LIS长度d(1)=1(序列：5)
前2个数的LIS长度d(2)=1(序列：3;3前面没有比3小的)
前面3个数的LIS长度d(3)=2(序列：3,4)
前4个数的LIS长度d(4)=3(序列：3，4，8；8前面比它小的有3个数


求最长公共子序列*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    string str1,str2;
    int dp[200][200];
    while(cin>>str1>>str2){
        memset(dp,0,sizeof(dp));
        int la=str1.length();
        int lb=str2.length();
        for(int i=1;i<=la;i++)
            for(int j=1;i<=lb;j++){
                if(str1[i-1]==str2[j-1])
                    dp[i][j]==dp[i-1][j-1]+1;
                else    
                    dp[i][j]==max(dp[i-1][j],dp[i][j-1]);
             }
             cout<<dp[la][lb]<<endl;
        }
        return 0;
 }
