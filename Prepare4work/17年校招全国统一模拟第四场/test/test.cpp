#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int a[6] = {1,5,4,2,7,5};
    vector<int> test(a,a + 6);
    swap(test[1],test[3]);
    for(int i : test) cout << i << " " ;
    cout << endl;
}