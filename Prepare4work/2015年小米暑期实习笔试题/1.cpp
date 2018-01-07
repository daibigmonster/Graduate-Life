// 世界上有10种人，一种懂二进制，一种不懂。那么你知道两个int32整数m和n的二进制表达，有多少个位(bit)不同么？
// 输入例子1:

// 1999 2299


// 输出例子1:

// 7

#include <iostream>
#include <vector>
using namespace std;
int countBitDiff(int m, int n) {
    int bigger = max(m,n);
    int less = min(m,n);
    int count = 0;
    while(bigger){
        if(bigger%2 != less % 2)count++;
        bigger /= 2;
        less /= 2;
    }
    return count;
}
int main(){
    int m,n;
    while(cin >> m >> n){
        cout << countBitDiff(m,n) << endl;
    }
    return 0;
}