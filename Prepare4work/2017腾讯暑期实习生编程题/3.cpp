// 时间限制：1秒

// 空间限制：32768K
// 小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，差最小的有多少对呢？差最大呢？



// 输入描述:


//  输入包含多组测试数据。

//  对于每组测试数据：

//  N - 本组测试数据有n个数

//  a1,a2...an - 需要计算的数据

//  保证:

//  1<=N<=100000,0<=ai<=INT_MAX.

// 输出描述:


// 对于每组数据，输出两个数，第一个数表示差最小的对数，第二个数表示差最大的对数。


// 输入例子1:

// 6
// 45 12 45 32 5 6


// 输出例子1:

// 1 2
#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>
#include <algorithm>
using namespace std;
int getMin(vector<int> num){
        int length = num.size();
        int min = INT_MAX,mincount = 0;
        //寻找最小值，最小值必定发生在相邻的两个数之间
        for(int i = 0;i < length -1;i++){
            int subnum = abs(num[i] - num[i + 1]);
            if(subnum < min) min = subnum;
        }
        for(int i = 0;i < length - 1;i++){
            for(int j = i + 1;j < length;j++){
                if(num[j] - num[i] == min)mincount++;
                else break;
            }
        }
    return mincount;
}
int getMax(vector<int> num){
    int begincount = count(num.begin(),num.end(),num[0]);
    int endcount = count(num.begin(),num.end(),num[num.size() - 1]);
    return begincount * endcount;
}
int main(){
    long N;
    while(cin >> N){
        vector<int> num(N,0);
        for(int i = 0;i < N;i++){
            cin >> num[i];            
        }
        sort(num.begin(),num.end());
        if(num[0] == num[N -1]) cout << N * (N - 1)/2 << " " << N * (N - 1)/2 << endl;
        else cout << getMin(num) << " " << getMax(num) << endl;
    }
    return 0;
}

