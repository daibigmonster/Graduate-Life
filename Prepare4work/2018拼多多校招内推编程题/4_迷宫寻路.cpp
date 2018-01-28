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
    int x,y;
    char key;
    Position(char key = '#',int x = -1,int y = -1):key(key),x(x),y(y){};
};

int BFS(vector<vector<char> >maze,int M,int N,Position start,char dest)
{
    int a[4] = {1,-1,0,0},b[4] = {0,0,1,-1},step = 0;
    int Visited[M][N];
    memset(Visited,0,sizeof(Visited));
    Visited[start.x][start.y] = 1;
    deque<Position> array;
    array.push_back(start);
    while(array.size())
    {
        int length = array.size();
        step++;
        rep(i,0,length)
        {
            Position curposition = array.front();
            array.pop_front();
            Visited[curposition.x][curposition.y] = 1;
            rep(j,0,4)
            {
                Position tempposition = curposition;
                tempposition.x += a[j],tempposition.y += b[j];
                if(tempposition.x >= 0 && tempposition.x < M && tempposition.y >= 0
                && tempposition.y < N && (maze[tempposition.x][tempposition.y] == '1'
                || maze[tempposition.x][tempposition.y] == dest || maze[tempposition.x][tempposition.y] == '2' ))
                {
                    if(maze[tempposition.x][tempposition.y] == dest) return step;
                    else
                    {
                        if(!Visited[tempposition.x][tempposition.y])
                        {
                            array.push_back(tempposition);
                        }
                    }    
                }
            }
        }
    }
    return 100001;
}
bool myfunction (Position A,Position B) { return (A.key < B.key); }
int main()
{
    int M,N;
    Position man,dest;
    while(cin >> M >> N)
    {
        vector<vector<char> >maze(M,vector<char>(N,'0'));
        vector<Position> doors;
        vector<Position> keys;
        rep(i,0,M)
        {
            rep(j,0,N)
            {
                cin >> maze[i][j];
                if(maze[i][j] == '2') man.key = '2',man.x = i,man.y = j;
                if(maze[i][j] >= 'A' && maze[i][j] <= 'Z') doors.push_back(Position(maze[i][j],i,j));
                if(maze[i][j] >='a' && maze[i][j] <= 'z') keys.push_back(Position(maze[i][j],i,j));
                if(maze[i][j] == '3') dest.key = '3',dest.x = i,dest.y = j;
            }
        }
        sort(doors.begin(),doors.end(),myfunction);
        sort(keys.begin(),keys.end(),myfunction);
        int getkeysteps = 10000;
        if(doors.empty()) cout << BFS(maze,M,N,man,'3') << endl;
        else
        {
            int man2deststeps = BFS(maze,M,N,man,'3');
            rep(i,0,doors.size())
            {
                cout << "key door " << keys[i].key << doors[i].key << endl;
                int man2keysteps = BFS(maze,M,N,man,keys[i].key);
                cout << "man2keysteps " << man2keysteps << endl;
                int key2doorsteps = BFS(maze,M,N,keys[i],doors[i].key);
                cout << "key2doorsteps " << key2doorsteps << endl;
                int door2deststeps = BFS(maze,M,N,doors[i],'3');
                cout << "door2deststeps " << door2deststeps << endl;
                getkeysteps = min(man2keysteps + key2doorsteps + door2deststeps ,getkeysteps);
            }
            cout << min(getkeysteps,man2deststeps) << endl;
        }
    }
}


