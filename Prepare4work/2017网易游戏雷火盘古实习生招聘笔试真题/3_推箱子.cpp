#include <iostream>
#include <vector>
#include <deque>
#include <string.h>
#define rep(i,x,y) for(int i = x;i < y;++i)
#define dep(i,x,y) for(int i = x;i > y;--i)
using namespace std;
struct Position{int x,y;};
struct BoxManPosition{
    int bx,by,nx,ny;
    BoxManPosition(int a,int b,int c,int d):bx(a),by(b),nx(c),ny(d){};
};
Position man,box,destination;

int BFSmap(vector<vector<char> >map,int N,int M){
    int a[4] = {1,-1,0,0},b[4] = {0,0,1,-1},step = 0;
    int Visited[N][M][N][M];
    memset(Visited,0,sizeof(Visited));
    Visited[box.x][box.y][man.x][man.y] = 1;
    deque<BoxManPosition> array;
    array.push_back(BoxManPosition(box.x,box.y,man.x,man.y));
    while(array.size()) {
        int length = array.size();
        step++;
        rep(i,0,length){
            BoxManPosition cp = array.front();
            array.pop_front();
            Visited[cp.bx][cp.by][cp.nx][cp.ny] = 1;
            rep(i,0,4){
                BoxManPosition np = cp;
                np.nx += a[i],np.ny += b[i];
                if(np.nx >= N || np.nx < 0 || np.ny >= M || np.ny < 0 || map[np.nx][np.ny] == '#')continue;
                if(np.nx == np.bx && np.ny == np.by) np.bx += a[i],np.by += b[i];
                if(np.bx >= N || np.bx < 0 || np.by >= M || np.by < 0 || map[np.bx][np.by] == '#')continue;
                if(map[np.bx][np.by] == '@') return step;
                if(!Visited[np.bx][np.by][np.nx][np.ny])array.push_back(np);
            }
        }
    }
    return -1;
}

int main(){
    int N,M;
    while(cin >> N >> M){
        vector<vector<char> >map(N,vector<char>(M,'0'));
        rep(i,0,N){
            rep(j,0,M){
                cin >> map[i][j];
                if(map[i][j] == 'X') man.x = i,man.y = j;
                if(map[i][j] == '*') box.x = i,box.y = j;
                if(map[i][j] == '@') destination.x = i,destination.y = j;
            }
        }
        cout << BFSmap(map,N,M) << endl;
    }
}