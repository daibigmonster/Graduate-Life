#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    string N;
    while (cin >> N )
    {
        int cnt;
        cin>> cnt;
        int j=0;
        for (int i = 0; i<cnt; i++)
        {
            int len = N.size();
            for (; j<len - 1; j++)
            {
                if (N[j] < N[j + 1])
                {
                    N.erase(N.begin()+j);
                    break;
                }
            }
            //cout << "count = " << count << " " << "i= " << i << endl;
            if (j==len-1)
                N.erase(N.end() - 1);
            j--;
        }
        cout << N;
    }
    return 0;
}