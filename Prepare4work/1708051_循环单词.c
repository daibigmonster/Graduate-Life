/*如果一个单词通过循环右移获得的单词，我们称这些单词都为一种循环单词。 例如：picture 和 turepic 就是属于同一种循环单词。 现在给出n个单词，需要统计这个n个单词中有多少种循环单词。
输入描述:

输入包括n+1行：

第一行为单词个数n(1 ≤ n ≤ 50)

接下来的n行，每行一个单词word[i]，长度length(1 ≤ length ≤ 50)。由小写字母构成



输出描述:

输出循环单词的种数*/
#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main()
{
    int length;
    cin>>length;
    vector<string> wordlist;
    set<int> recoder;
    int result=0;
    //if(length<=1)result=0;
    //else{
    for(int i=0;i<length;i++){
        string str;
        cin>>str;
        wordlist.push_back(str);
    }
    for(int i=0;i<length;i++)
    {
        if(recoder.find(i)==recoder.end())continue;
        string str=wordlist[i]+wordlist[i];
        for(int j=i+1;j<length;j++)
        {
            if(str.find(wordlist[j])!=string::npos);
            recoder.insert(j);
        }
        result++;
       // int loc=str.find(wordlist[i]);
       // cout<<loc<<endl;
    }
    //}
    cout<<result<<endl;
    //cout<<wordlist[0].size()<<endl;
    return 0;
}
