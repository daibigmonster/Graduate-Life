#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getSum(int n,int m){
    int sum = 0;
    while(n){
        sum += n%m;
        n /= m;
    }
    return sum;
}

int main(){
    int n;
    while(cin >> n){
        int ans = 0;
        for(int i = 1;i <= n;i++){
            int g = getSum(i,2);
            int f = getSum(i,10);
            ans += f == g ? 1 : 0;
        }
        cout << ans << endl;
    }
    return 0;
}