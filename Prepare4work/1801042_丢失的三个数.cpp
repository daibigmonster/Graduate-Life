#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    vector<int> num(9998,0);
    int n;
    string sum;
    for(int i = 1;i < 9998;i++){
        cin >> n;
        num[n] = n;
    }
    for(int i = 1;i < 9998;i++){
        if(num[i] == 0)sum += to_string(num[i]);
    }
    sum = atoi(sum.c_str())%7;
    cout << sum << endl;
}