#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
 
int main(){
    int n;
    while (cin >> n){
        vector<int> height(n, 0);
        for (int i = 0; i < n; i++)
            cin >> height[i];
        int minH = 0;
        long long MaxArea = 0;
        for (int i = 0; i < n; i++){
            minH = height[i];
            for (int j = i; j < n; j++){
                minH = min(minH, height[j]);
                MaxArea = max(MaxArea, (long long)(minH * (j - i + 1)));
            }
        }
        cout << MaxArea << endl;
    }
    return 0;
}
