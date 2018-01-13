// 链接：https://www.nowcoder.com/questionTerminal/c8c9f42c19194aa88781efefef4df44b
// 来源：牛客网

// Given two binary strings, return their sum (also a binary string).

// For example,
// a ="11"
// b ="1"
// Return"100". 
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <string.h>
using namespace std;
vector<string> fileString(string a,string b){
    vector<string> res;
    if(a.size() > b.size())
        for(int i = a.size() - b.size();i;i--) b = "0" + b;
    if(a.size() < b.size()) return fileString(b,a);
    res.push_back(a);
    res.push_back(b);
    return res;
}
string addBinary(string a, string b) {
    int alength = a.size() - 1,blength = b.size() - 1;
    string res = "";
    int abit,bbit,s = 0;
    while(alength >= 0 || blength >=0 || s){
        abit = alength >= 0 ? a[alength--] - '0':0;
        bbit = blength >= 0 ? b[blength--] - '0':0;
        s = abit + bbit + s;
        if(s % 2) res = "1" + res;
        else res = "0" + res;
        s = s >> 1;
    }
    return res;
}
int main(){
    string a,b;
    while(cin >> a >> b){
        cout << addBinary(a,b) << endl;
    }
}
        
