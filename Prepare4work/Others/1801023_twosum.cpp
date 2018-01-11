/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans;
        vector<int>::iterator it = numbers.begin();
        while(it != numbers.end()){
            vector<int>::iterator p = find(it + 1,numbers.end(),target - *it);
            if(p == numbers.end()) it++;
            else {
                ans.push_back(it - numbers.begin() + 1);
                ans.push_back(p - numbers.begin() + 1);
                break;
            }
        } 
        sort(ans.begin(),ans.end());
        return ans;
    } 
};
int main(){
    Solution test;
    int num[3] = {3,2,4};
    int target = 6;
    vector<int> numbers(num,num + 3);
    vector<int> ans = test.twoSum(numbers,target);
    for(auto i : ans) cout << i << " ";
}