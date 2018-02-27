// 牛牛有n张卡片排成一个序列.每张卡片一面是黑色的,另一面是白色的。初始状态的时候有些卡片是黑色朝上,有些卡片是白色朝上。牛牛现在想要把一些卡片翻过来,得到一种交替排列的形式,即每对相邻卡片的颜色都是不一样的。牛牛想知道最少需要翻转多少张卡片可以变成交替排列的形式。
// 输入描述:

// 输入包括一个字符串S,字符串长度length(3 ≤ length ≤ 50),其中只包含'W'和'B'两种字符串,分别表示白色和黑色。整个字符串表示卡片序列的初始状态。



// 输出描述:

// 输出一个整数,表示牛牛最多需要翻转的次数。


// 输入例子1:

// BBBW


// 输出例子1:

// 1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,x,y) for(int i = x;i < y;i++)
using namespace std;
int main()
{
    string words;
    while(cin >> words)
    {
        int wordlength = words.size(),countA = 0,countB = 0;
        string wordA = "W",wordB = "B";
        rep(i,0,wordlength - 1)
        {
            if(i%2)
            {
                wordA += 'W';
                wordB += 'B';
            }
            else
            {
                wordA += 'B';
                wordB += 'W';
            }
        }
        rep(i,0,wordlength)
        {
            if(words[i] != wordA[i])countA++;
            if(words[i] != wordB[i])countB++;
        }
        //cout << wordA << " " << wordB << endl;
        cout << min(countA,countB) << endl;
    }
}