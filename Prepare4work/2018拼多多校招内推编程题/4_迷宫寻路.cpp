#include <iostream>
#include <deque>
#include <string.h>
#include <vector>
#include <algorithm>
#define rep(i,x,y) for(int i = x;i < y;++i)
#define dep(i,x,y) for(int i = x;i > y;--i)
using namespace std;
struct Position
{
    int x,y,key,step;
    Position(int x = 0,int y = 0,int key = 0,int step = 0):x(x),y(y),key(key),step(step){};
};
int Visited[101][101][1200];

int BFS(vector<vector<char> >maze,int M,int N,Position start)
{
    int a[4] = {1,-1,0,0},b[4] = {0,0,1,-1};
    deque<Position> array;
    array.push_back(start);
    while(array.size())
    {
        Position curposition = array.front();
        array.pop_front();
        if(maze[curposition.x][curposition.y] == '3') return curposition.step;
        rep(j,0,4)
        {
            int tempx = curposition.x + a[j],tempy = curposition.y + b[j],tempkey = curposition.key,tempstep = curposition.step;
            if(tempx < 0 || tempx >= M || tempy < 0 || tempy >= N || maze[tempx][tempy] == '0') continue;
            if('a' <= maze[tempx][tempy] && maze[tempx][tempy] <= 'z') tempkey= tempkey | (1 << (maze[tempx][tempy]-'a'));
            if('A' <= maze[tempx][tempy] && maze[tempx][tempy] <= 'Z' && (tempkey & (1 << (maze[tempx][tempy]-'A'))) == 0) continue;
            if(!Visited[tempx][tempy][tempkey])
            {
                Visited[tempx][tempy][tempkey] = 1;
                array.push_back(Position(tempx,tempy,tempkey,tempstep + 1));
            }
        }
    }
    return 100001;
}
bool myfunction (Position A,Position B) { return (A.key < B.key); }
int main()
{
    int M,N;
    Position man;
    while(cin >> M >> N)
    {
        vector<vector<char> >maze(M,vector<char>(N,'0'));
        memset(Visited,0,sizeof(Visited));
        rep(i,0,M)
        {
            rep(j,0,N)
            {
                cin >> maze[i][j];
                if(maze[i][j] == '2') man.x =i,man.y = j;
            }
        }
        Visited[man.x][man.y][0] = 1;
        cout << BFS(maze,M,N,man) << endl;
    }
}


