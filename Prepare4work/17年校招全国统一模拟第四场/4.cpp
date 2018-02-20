#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define rep(i,x,y) for(int i = x;i < y;i++)
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> s(n,0);
        set<vector<int> > arrs;
        rep(i,0,n)
        {
            cin >> s[i];
        }
        rep(i,0,n)
        {
            rep(j,i + 1,n)
            {
                vector<int> new_s(s);
                swap(new_s[i],new_s[j]);
                arrs.insert(new_s);
            }
        }
        cout << arrs.size() << endl;
    }
    return 0;
}