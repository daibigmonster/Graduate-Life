#include<iostream>
#include<vector>

using std::vector;
class Solution{
    public:
    vector<int> grayCode(int n){
        vector<int> result;
        result.push_back(0);
        for(int i = 0;i < n;i++){
            int high_bit = 1 << i;
            for(int j = result.size() - 1;j >= 0;j--){
                result.push_back(high_bit | result[j]);
            }
        }
        return result;
    }
};

int main(){
    using namespace std;
    Solution s1;
    vector<int> res = s1.grayCode(3);
    for(int x:res) std::cout<<x<<" ";
    return 0;
}

