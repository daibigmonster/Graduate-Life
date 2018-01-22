
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
#define rep(i,x,y) for(int i = x;i < y;++i)
#define dep(i,x,y) for(int i = x;i > y;--i)
using namespace std;

int getcolrowsum(vector<vector<int> > num,int N,int D){
    int maxrowsum = 0,maxcolsum = 0;
    rep(i,0,N){
        rep(j,0,N){
            int cursum = 0;
            rep(k,0,D){
                if(j + k >= N)break;
                cursum += num[i][j + k];
            }
            maxrowsum = maxrowsum < cursum ? cursum : maxrowsum;
        }
    }
    rep(i,0,N){
        rep(j,0,N){
            int cursum = 0;
            rep(k,0,D){
                if(j + k >= N)break;
                cursum += num[j + k][i];
            }
            maxcolsum = maxcolsum < cursum ? cursum : maxcolsum;
        }
    }
    return max(maxrowsum,maxcolsum);


}

int getxiemaxsum(vector<vector<int> > num,int N,int D){
    int zuosum = 0,yousum = 0;
    rep(i,0,N){
        rep(j,0,N){
            int cursum = 0;
            rep(k,0,D){
                if(i + k >= N || j + k >= N)break;
                cursum += num[i + k][j + k];
            }
            zuosum = zuosum < cursum ? cursum : zuosum; 
        }
    }
    rep(i,0,N - D + 1){
        for(int j = N - 1;j >= 0;j--){
            int cursum = 0;
            rep(k,0,D){
                if(i + k >= N || j - k < 0)break;
                cursum += num[i + k][j - k];
            } 
            yousum = yousum < cursum ? cursum : yousum;
        }
    }
    return max(zuosum,yousum);
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
        cout << max(getcolrowsum(num,N,D),getxiemaxsum(num,N,D)) << endl;
    }
    return 0;
}