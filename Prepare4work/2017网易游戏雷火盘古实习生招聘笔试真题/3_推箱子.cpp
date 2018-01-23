// 大家一定玩过“推箱子”这个经典的游戏。具体规则就是在一个N*M的地图上，有1个玩家、1个箱子、1个目的地以及若干障碍，其余是空地。玩家可以往上下左右4个方向移动，但是不能移动出地图或者移动到障碍里去。如果往这个方向移动推到了箱子，箱子也会按这个方向移动一格，当然，箱子也不能被推出地图或推到障碍里。当箱子被推到目的地以后，游戏目标达成。现在告诉你游戏开始是初始的地图布局，请你求出玩家最少需要移动多少步才能够将游戏目标达成。
// 输入描述:

// 每个测试输入包含1个测试用例
// 第一行输入两个数字N，M表示地图的大小。其中0<N，M<=8。
// 接下来有N行，每行包含M个字符表示该行地图。其中 . 表示空地、X表示玩家、*表示箱子、#表示障碍、@表示目的地。
// 每个地图必定包含1个玩家、1个箱子、1个目的地。



// 输出描述:

// 输出一个数字表示玩家最少需要移动多少步才能将游戏目标达成。当无论如何达成不了的时候，输出-1。


// 输入例子1:

// 4 4
// ....
// ..*@
// ....
// .X..
// 6 6
// ...#..
// ......
// #*##..
// ..##.#
// ..X...
// .@#...


// 输出例子1:

// 3
// 11
#include <iostream>
#include <vector>
#define rep(i,x,y) for(int i = x;i < y;++i)
#define dep(i,x,y) for(int i = x;i > y;--i)
using namespace std;
vector<vector<int> >Visited(8,vector<int>(8,0));
struct Position{
    int x,y;
};
int DFSmap(vector<vector<char> >map,int N,int M,Position man,Position box,Position dest){
    
    
}
int main(){
    int N,M;
    while(cin >> N >> M){
        vector<vector<char> >map(N,vector<char>(M,'.'));
        Position man,box,dest;
        rep(i,0,N){
            rep(j,0,M){
                cin >> map[i][j];
                if(map[i][j] == 'X'){
                    man.x = i,man.y = j;
                else if(map[i][j] == '*')
                    box.x = i,box.y = j;
                else if(map[i][j] == '@')
                    dest.x = i,dest.y = j;
            }
        }
        Visited[man.x][man.y] = 1;
    }
}