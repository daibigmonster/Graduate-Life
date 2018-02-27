#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    int dp[55][1005] = {0};
    dp[0][0] = 1;
    int n,k;
    while(cin >> n >> k)
    {
        for(int i = 0; i < n;i++)
        {
            for(int j = k;j >= 1;j--)
            {
                for(int s = 0;s < n;s++)
                {
                    dp[j][s] = (dp[j][s] + dp[j - 1][(n + s - i) % n]) % mod;
                }
            }
        }
        cout << dp[k][0] << endl;
    }
    return 0;
}