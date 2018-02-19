#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,A;
    while(cin>>n>>A)
    {
        vector<int> a(n,0);
        for(int i = 0;i < n;i++)
        {
            cin >> a[i];
            if(A == a[i]) A = A * 2;
        }
        cout << A << endl;
    }
    return 0;
}
