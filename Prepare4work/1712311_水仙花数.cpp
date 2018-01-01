// 题目描述
// 春天是鲜花的季节，水仙花就是其中最迷人的代表，数学上有个水仙花数，他是这样定义的： “水仙花数”是指一个三位数，它的各位数字的立方和等于其本身，比如：153=1^3+5^3+3^3。 现在要求输出所有在m和n范围内的水仙花数。
// 输入描述:

// 输入数据有多组，每组占一行，包括两个整数m和n（100 ≤ m ≤ n ≤ 999）。

// 输出描述:

// 对于每个测试实例，要求输出所有在给定范围内的水仙花数，就是说，输出的水仙花数必须大于等于m,并且小于等于n，如果有多个，则要求从小到大排列在一行内输出，之间用一个空格隔开;
// 如果给定的范围内不存在水仙花数，则输出no;
// 每个测试实例的输出占一行。
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
int main(){
    using namespace std;
    int m = 0,n = 0;
    while(cin>>m>>n){
        vector<int> res;
        for(int i = m;i <= n;i++){
            int a = i/100;
            int b = (i - a * 100)/10;
            int c = i%10;
            if(pow(a,3) + pow(b,3) + pow(c,3) == i) res.push_back(i);
        }
        if(res.empty()) cout << "no" << endl;
        else{ 
            for(int i = 0;i < res.size() - 1;i++) 
                cout << res[i] << " ";
            cout << res[res.size() - 1] << endl;
        }
    }
    return 0;
}