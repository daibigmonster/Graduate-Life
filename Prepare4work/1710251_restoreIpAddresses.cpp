#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2)return true;
        int length = s1.size();
        if(valid(s1,s2) == false)return false;
        for(int i = 1; i < length;i++){
             if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i)))
                return true;
            if(isScramble(s1.substr(0,i),s2.substr(length - i)) && isScramble(s1.substr(i),s2.substr(0,length - i)))
                return true;
        }
        return false;
    }
    bool valid(string s1,string s2){
        for(char x : s1){
            if(s2.find(x) == string::npos)return false;
        }
        for(char x : s2){
            if(s1.find(x) == string::npos)return false;
        }
        return true;
    }
};
int main(){
	string a = "abacd";
	string b = "baadc";
	Solution s1;
	cout << s1.isScramble(a,b) << endl;
	return 0;
}
