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
    if(length<=1)result=0;
    else{
    for(int i=0;i<length;i++){
        string str;
        cin>>str;
        wordlist.push_back(str);
    }
    for(int i=0;i<length;i++)
    {
        if(recoder.count(i)!=0)continue;
        result++;
        string str=wordlist[i]+wordlist[i];
        for(int j=i+1;j<length;j++)
        {
            if(str.find(wordlist[j])!=string::npos&&(wordlist[j].size()==str.size()/2))
                recoder.insert(j);
        }
         
    }
    }
    cout<<result<<endl;
    return 0;
}
