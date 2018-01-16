#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<vector<int> > Test(5,vector<int>(5,0));
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            cout << Test[i][j];
        }
        cout << endl;
    }
    return 0;
}