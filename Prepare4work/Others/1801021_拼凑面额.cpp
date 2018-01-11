#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    while(cin >> n){
        int coins[6] = {1,5,10,20,50,100};
        vector<int> dp(n + 1,0);
        dp[0] = 1;
        for(int i = 0;i < 6;i++){
            for(int j = 1;j <= n;j++){
                if(j >= coins[i]){
                    dp[j] = dp[j] + dp[j - coins[i]];
                }
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}