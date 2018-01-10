#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string str;
    while(cin >> str){
        int length = str.size(),count = 0;
        cout << length << endl;
        // for(int i = 0;i < length;i++){
        //     if(str[i] >= 'A' && str[i] <= 'Z' )count++;
        // }
        while(length > 0){
            int i = 0;
            if(str[i] >= 'A' && str[i] <= 'Z' ){
                str = str.substr(0,i) + str.substr(i + 1) + str[i];
                cout << str <<" " << i << " "<< length << endl;
                // i -= 1;
            }
            else{
                i++;
                length--;
            } 
        }
        cout << str << endl;
    }
    return 0;
}