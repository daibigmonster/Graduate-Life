#include <iostream>
#include <string>
#include <algorithm>
#define rep(i,x,y) for(int i = x;i < y;i++)
using namespace std;
int Uglycount(string str)
{
    int length = str.size(),uglycount = 0;
    rep(i,0,length - 1)
    {
        if(str[i] == str[i + 1]) 
        {
            uglycount++;
        }
    }
    return uglycount;
}
void strchanges(string &str)
{
    int length = str.size();
    if(str[0] == '?') 
    {
        int i = 0;
        while(str[i] == '?') 
        {
            if(i != length - 1)i++; 
            else
            {
                str[length - 1] = 'A';
            }
        }
        str[i - 1] = str[i] == 'A' ? 'B' : 'A';
        strchanges(str);
    }
    rep(i,0,length - 1)
    {
        if(str[i + 1] == '?')
        {
            str[i + 1] = str[i] == 'A' ? 'B' : 'A';
        }
    }
}
int main()
{
    string str;
    while(cin >> str)
    {
        strchanges(str);        
        //cout << str << endl;
        int uglynum = Uglycount(str);
        cout << uglynum << endl;
    } 
}
