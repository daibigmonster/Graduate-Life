// 给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
// 输入描述:

// 输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。



// 输出描述:

// 为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10用A表示，等等）


// 输入例子1:

// 7 2


// 输出例子1:

// 111

#include <iostream>
#include <string>
#include <math.h>
using namespace std;
string formatconvert(int num,int n){
    string res = "";
    int m = abs(num);
    while(m){
        string a = "";
        if(m % n < 10) a = to_string(m % n);
        else a += char('A' + m % n - 10); 
        res = a + res;
        m /= n;
    }
    if(num >= 0) return res;
    else return "-" + res;
}
int main(){
    int m,n;
    while(cin >> m >> n){
        cout << formatconvert(m,n) << endl;
    }
    return 0;
}