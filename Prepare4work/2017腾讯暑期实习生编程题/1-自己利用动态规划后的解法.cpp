// 给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
// 输出需要删除的字符个数。

// 输入描述:


// 输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.
  



// 输出描述:


// 对于每组数据，输出一个整数，代表最少需要删除的字符个数。


// 输入例子1:

// abcda
// google
#include <iostream>
#include <vector>
#include <string> 
#include <algorithm>
using namespace std;
int getLength(string str1,string str2){
    if(str1 == str2) return str1.size();
    vector<vector<int> > dp(1001,vector<int>(1001,0));
    int length1 = str1.size();
    int length2 = str2.size();
    for(int i = 1;i <= length1;i++){
        for(int j = 1;j <= length2;j++){
            if(str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
        }
    }
    return dp[length1][length2];
}
int main(){
    string str1;
    while(cin >> str1){
        string str2(str1.rbegin(),str1.rend());
        cout << str1.size() - getLength(str1,str2) << endl;
    }
}