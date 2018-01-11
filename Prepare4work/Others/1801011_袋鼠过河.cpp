#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> num(N,0),dp(N + 1,11000);
    dp[0] = 0;
    for(int i = 0;i < N;i++)cin >> num[i];
    for(int i = 1;i <= N;i++){
        for(int j = 0;j < i;j++){
            if(num[j] + j >= i)
                dp[i] = min(dp[i],dp[j] + 1);
        }
    }
    //for(int i : dp)cout << i << " " ;
    int ans = (dp[N] == 11000 ? -1 : dp[N]);
    cout << ans << endl;
    return 0;
}