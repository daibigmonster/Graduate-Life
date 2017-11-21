

Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

    Only one letter can be changed at a time
    Each intermediate word must exist in the dictionary 

For example,

Given:
start ="hit"
end ="cog"
dict =["hot","dot","dog","lot","log"]

As one shortest transformation is"hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length5.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters. 

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        deque<string> temp;
        int res(1);
        temp.push_back(start);
        while(!temp.empty()){
            int tempsize=temp.size();
            ++res;
            while(tempsize--){
                string curstr=temp.front();
                temp.pop_front();
                int cursize=curstr.size();
                for(int i=0;i<cursize;i++){
                    char ch=curstr[i];
                    for(char j='a';j<='z';j++){
                        curstr[i]=j;
                        if(curstr==end)return res;
                        if(dict.find(curstr)!=dict.end()){
                            temp.push_back(curstr);
                            dict.erase(curstr);
                        }
                    }
                 curstr[i]=ch;
                }
            }
        }
        return 0;
    }
};
