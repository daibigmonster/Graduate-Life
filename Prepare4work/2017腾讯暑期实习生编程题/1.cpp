#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int maxlength = 1;
void getLength(string str){
    string s(str.rbegin(),str.rend());
    if(s == str){
        if(s.size() > maxlength)maxlength = s.size();
    }
    else{
        for(int i = 0;i < str.size();i++){
            s = str.substr(0,i) + str.substr(i + 1);
            if(s.size() == 1) return;
            cout << s << " " << maxlength << endl;
            if(s.size() > maxlength)getLength(s);
        }
    }
}

int main(){
    string str;
    while(cin >> str){
        getLength(str);
        cout << str.size() - maxlength << endl;
    }
    return 0;
}
