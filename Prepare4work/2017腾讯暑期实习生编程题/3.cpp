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
int main(){
    long N;
    while(cin >> N){
        long maxnum = INT_MIN,minnum = INT_MAX;
        int maxcount = 0,mincount = 0;
        vector<int> num(N,0);
        for(int i = 0;i < N;i++){
            cin >> num[i];            
        }
        sort(num.begin(),num.end());
        for(int i = 0;i < N;i++){
            if(i)
        }

        


        for(int i = 0;i < N;i++){
            for(int j = i + 1;j < N;j++){
                long subnum = abs(long(num[i]) - long(num[j]));
                // cout << "两个数" << num[i] << " " << num[j] << endl;
                if(subnum > maxnum){
                    maxnum = subnum;
                    maxcount = 1;
                    // cout << "最大差" << maxnum << " " << maxcount << endl;
                } 
                else if(subnum == maxnum){
                    maxcount++;
                    // cout << "最大差" << maxnum << " " << maxcount << endl;
                } 
                if(subnum < minnum){
                    minnum = subnum;
                    mincount = 1;
                    // cout << "最小差" << minnum << " " << mincount << endl;
                } 
                else if(subnum == minnum){
                    mincount++; 
                    // cout << "最小差" << minnum << " " << mincount << endl;
                } 
            }
        }
    cout << mincount << " " << maxcount << endl;
    }
}

