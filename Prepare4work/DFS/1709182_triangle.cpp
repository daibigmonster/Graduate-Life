 Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]


The minimum path sum from top to bottom is11(i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. 

class Solution {
 
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int sum(0),row(0),col(0),cursum(0);
        for(size_t i=0;i<triangle.size();i++){
                sum+=triangle[i][0];
        }
        findmininum(triangle,sum,cursum,row,col);
        return sum;
        }
    void findmininum(vector<vector<int> > triangle,int &sum,int cursum,int row,int col){
        int colNum=triangle[row].size(),rowNum=triangle.size();
        if(triangle[row].empty()||triangle.empty()||row>=rowNum||col>=colNum)return;
        cursum+=triangle[row][col];
        if(row>=rowNum-1)sum=min(sum,cursum);
        findmininum(triangle,sum,cursum,row+1,col);
        findmininum(triangle,sum,cursum,row+1,col+1);
    }
  
 
};
