//  风口之下，猪都能飞。当今中国股市牛市，真可谓“错过等七年”。 给你一个回顾历史的机会，已知一支股票连续n天的价格走势，以长度为n的整数数组表示，数组中第i个元素（prices[i]）代表该股票第i天的股价。 假设你一开始没有股票，但有至多两次买入1股而后卖出1股的机会，并且买入前一定要先保证手上没有股票。若两次交易机会都放弃，收益为0。 设计算法，计算你能获得的最大收益。 输入数值范围：2<=n<=100,0<=prices[i]<=100
// 输入例子1:

// 3,8,5,1,7,8


// 输出例子1:
//12
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxprofit(vector<int> prices,int begin,int end){
    if(begin == end) return 0;
    int maxres = 0,minres = prices[begin];
        for(int i = begin;i <= end;i++){
            minres = min(prices[i],minres);
            maxres = max(prices[i] - minres,maxres);
        }
        return maxres;
    }

int calculateMax(vector<int> prices) {
    int days = prices.size(),res = 0;
    if(days == 2) return max(0,prices[1] - prices[0]);
    for(int i = 0;i < days;i++){
        res = max(res,maxprofit(prices,0,i) + maxprofit(prices,i,days - 1));
    }
    return res;
}

int main(){
    int a[6] = {3,8,5,1,7,8};
    vector<int> prices(a,a + 6);
    cout << calculateMax(prices) << endl;
    return 0;

}
