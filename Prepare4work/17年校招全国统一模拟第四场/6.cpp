#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> h_i(n);
        for(int i = 0;i < n;i++)
        {
            cin >> h_i[i];
        }
        deque<int> leastheightdiff;
        int res = 0;
        sort(h_i.begin(),h_i.end());
        for(int i = n - 1;i >= 0;i--)
        {
            if(i%2) leastheightdiff.push_back(h_i[i]);
            else leastheightdiff.push_front(h_i[i]);
        }
        leastheightdiff.push_back(leastheightdiff.front());
        for(int i = 0;i < n;i++)
        {
            res = max(res,abs(leastheightdiff[i + 1] - leastheightdiff[i]));
        }
        cout << res << endl;
    }
    return 0;
}