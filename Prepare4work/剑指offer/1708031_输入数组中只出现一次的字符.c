//在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置 
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int i;
        set<char> s;
        if(str.empty())return -1;
        for(i=0;i<str.size()-1;++i)
        {
            if(str.find(str[i],i+1)==string::npos&&s.find(str[i])==s.end())break;
            s.insert(str[i]);
        }
        return i;
    }
};
