
// 在一个N*N的数组中寻找所有横，竖，左上到右下，右上到左下，四种方向的直线连续D个数字的和里面最大的值
// 输入描述:

// 每个测试输入包含1个测试用例，第一行包括两个整数 N 和 D :
// 3 <= N <= 100
// 1 <= D <= N
// 接下来有N行，每行N个数字d:
// 0 <= d <= 100



// 输出描述:

// 输出一个整数，表示找到的和的最大值


// 输入例子1:

// 4 2
// 87 98 79 61
// 10 27 95 70
// 20 64 73 29
// 71 65 15 0


// 输出例子1:

// 193

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int getDsum(vector<int> temp,int N,int D){
    sort(temp.begin(),temp.end());
    int sum = 0;
    for(int i = 1;i <= D;i++){
        sum += temp[N - i];
    }
    return sum;
}
int getrowmaxsum(vector<vector<int> > num,int N,int D){
    int maxrowsum = 0;
    for(int i = 0;i < N;i++){
        vector<int> temp(num[i].begin(),num[i].end());
        int cursum = getDsum(temp,N,D);
        if(cursum > maxrowsum) maxrowsum = cursum;
    }
    return maxrowsum;
}
int getcolmaxsum(vector<vector<int> > num,int N,int D){
    int maxcolsum = 0;
    for(int i = 0;i < N;i++){
        vector<int> temp(N,0);
        for(int j = 0;j < N;j++){
            temp[j] = num[j][i];
        }
        int cursum = getDsum(temp,N,D);
        if(cursum > maxcolsum) maxcolsum = cursum;
    }
    return maxcolsum;
}
int getxiemaxsum(vector<vector<int> > num,int N,int D){
    if(D == 1)return 0;
    int maxxiesum = 0;
    for(int i = 0;i < N - D + 1;i++){
        vector<int> temp1,temp2,temp3,temp4;
        for(int j = 0;j < N - i;j++){
            temp1.push_back(num[i + j][j]);
            temp2.push_back(num[j][i + j]);
            temp3.push_back(num[N - 1 - i - j][j]);
            temp4.push_back(num[i + j][N - 1 - j]);
        }
        // for(int j = 0;j < N - i;j++){
            
        // }
        
        int cursum1 = getDsum(temp1,temp1.size(),D);
        int cursum2 = getDsum(temp2,temp2.size(),D);
        int cursum3 = getDsum(temp3,temp3.size(),D);
        int cursum4 = getDsum(temp4,temp4.size(),D);
        int tempmax = max(max(cursum1,cursum2),max(cursum3,cursum4));
        if(tempmax > maxxiesum) maxxiesum = tempmax;
    }
    return maxxiesum;
}
int main(){
    int N,D;
    while(cin >> N >> D){
        vector<vector<int> >num(N,vector<int>(N,0));
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                cin >> num[i][j];
            }
        }
        int rowsum = getrowmaxsum(num,N,D);
        int colsum = getcolmaxsum(num,N,D);
        int xiesum = getxiemaxsum(num,N,D);
        int res = max(xiesum,max(rowsum,colsum));
        cout << res << endl;
    }
    return 0;
}