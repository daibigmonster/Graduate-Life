#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>
using namespace std;
int main(){
    long N;
    while(cin >> N){
        int maxnum = INT_MIN,minnum = INT_MAX;
        int maxcount = 0,mincount = 0;
        vector<int> num(N,0);
        for(int i = 0;i < N;i++){
            cin >> num[i];           
        }
        for(int i = 0;i < N;i++){
            for(int j = i + 1;j < N;j++){
                int subnum = abs(num[i] - num[j]);
                // cout << "两个数" << num[i] << " " << num[j] << endl;
                if(subnum > maxnum){
                    maxnum = subnum;
                    maxcount = 1;
                    // cout << "最大差" << maxnum << " " << maxcount << endl;
                }
                else if(subnum == maxnum){
                    maxcount++;
                    // cout << "最大差" << maxnum << " " << maxcount << endl;
                }
                if(subnum < minnum){
                    minnum = subnum;
                    mincount = 1;
                    // cout << "最小差" << minnum << " " << mincount << endl;
                }
                else if(subnum == minnum){
                    mincount++;
                    // cout << "最小差" << minnum << " " << mincount << endl;
                }
            }
        }
    cout << mincount << " " << maxcount << endl;
    }
}