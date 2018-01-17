//  小青蛙有一天不小心落入了一个地下迷宫,小青蛙希望用自己仅剩的体力值P跳出这个地下迷宫。为了让问题简单,假设这是一个n*m的格子迷宫,迷宫每个位置为0或者1,0代表这个位置有障碍物,小青蛙达到不了这个位置;1代表小青蛙可以达到的位置。小青蛙初始在(0,0)位置,地下迷宫的出口在(0,m-1)(保证这两个位置都是1,并且保证一定有起点到终点可达的路径),小青蛙在迷宫中水平移动一个单位距离需要消耗1点体力值,向上爬一个单位距离需要消耗3个单位的体力值,向下移动不消耗体力值,当小青蛙的体力值等于0的时候还没有到达出口,小青蛙将无法逃离迷宫。现在需要你帮助小青蛙计算出能否用仅剩的体力值跳出迷宫(即达到(0,m-1)位置)。 

// 输入描述:

// 输入包括n+1行:
//  第一行为三个整数n,m(3 <= m,n <= 10),P(1 <= P <= 100)
//  接下来的n行:
//  每行m个0或者1,以空格分隔



// 输出描述:

// 如果能逃离迷宫,则输出一行体力消耗最小的路径,输出格式见样例所示;如果不能逃离迷宫,则输出"Can not escape!"。 测试数据保证答案唯一

// 示例1
// 输入

// 4 4 10 
// 1 0 0 1 
// 1 1 0 1 
// 0 1 1 1 
// 0 0 1 1

// 输出

// [0,0],[1,0],[1,1],[2,1],[2,2],[2,3],[1,3],[0,3]
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > Paths;
vector<vector<int> > Visited(11,vector<int>(11,0));
void recoderpush(int i,int j,vector<int> &Pathrecoder){
    Pathrecoder.push_back(i);
    Pathrecoder.push_back(j);
    return;
}
void recoderpop(vector<int> &Pathrecoder){
    Pathrecoder.pop_back();
    Pathrecoder.pop_back();
    return;
}

void show(int x,int y,int flag){
    if(flag == 1)
        cout << "[" << x << "," << y << "]" << "," ;
    else
        cout << "[" << x << "," << y << "]" ;
}

void getPath(int i,int j,int n,int m,int strength,vector<int> Pathrecoder,vector<vector<int> > Maze){
    // cout << "显示状态：";
    // cout << i <<  " " << j << " " << n << " " << m << " " << strength << endl;
    // // cout << Visited.size() << " " << Visited[0].size() << " " << Pathrecoder.size() << endl;
    // // cout << Visited[i][j] << endl;
    // cout << "显示访问状态" << endl;
    // for(int x = 0;x < n;x++){
    //     for(int y = 0;y < m;y++){
    //         cout << Visited[x][y] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;


    if(strength < 0)return;
    if(i == 0 && j == m - 1){
        Visited[i][j] = 1;
        // cout << "访问成功: " << strength << endl;
        Pathrecoder.push_back(strength);
        // for(int x = 0; x < Pathrecoder.size();x++)cout << Pathrecoder[x] << " ";
        // cout << endl;
        Paths.push_back(Pathrecoder);
        return;
    }
    if(strength == 0)return;
    if(i >= 1 && j >= 0 && 
        i < n && j < m &&
    Maze[i - 1][j] == 1 && Visited[i - 1][j] == 0){
        recoderpush(i - 1,j,Pathrecoder);
        Visited[i - 1][j] = 1;
        getPath(i - 1,j,n,m,strength - 3,Pathrecoder,Maze);
        Visited[i - 1][j] = 0;
        recoderpop(Pathrecoder);
    }
    if(i >= 0 && j >= 0 && 
        i < n - 1 && j < m &&
    Maze[i + 1][j] == 1 && Visited[i + 1][j] == 0){
        recoderpush(i + 1,j,Pathrecoder);
        Visited[i + 1][j] = 1;
        getPath(i + 1,j,n,m,strength,Pathrecoder,Maze);
        Visited[i + 1][j] = 0;
        recoderpop(Pathrecoder);
    }
    if(i >= 0 && j >= 1 &&
       i < n && j < m &&
    Maze[i][j - 1] == 1 && Visited[i][j - 1] == 0){
        recoderpush(i,j - 1,Pathrecoder);
        Visited[i][j - 1] = 1;
        getPath(i,j - 1,n,m,strength - 1,Pathrecoder,Maze);
        Visited[i][j - 1] = 0;
        recoderpop(Pathrecoder);
    }
    if(i >= 0 && j >= 0 && 
        i < n && j < m - 1 &&
    Maze[i][j + 1] == 1 && Visited[i][j + 1] == 0){
        recoderpush(i,j + 1,Pathrecoder);
        Visited[i][j + 1] = 1;
        getPath(i,j + 1,n,m,strength - 1,Pathrecoder,Maze);
        Visited[i][j + 1] = 0;
        recoderpop(Pathrecoder);
    }
}


int main(){
    int n,m,P;
    while(cin>>n>>m>>P){
        vector<int> Pathrecoder;
        vector<vector<int> > Maze(n,vector<int>(m,0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                cin >> Maze[i][j];
            }
        }

        recoderpush(0,0,Pathrecoder);
        Visited[0][0] = 1;
        getPath(0,0,n,m,P,Pathrecoder,Maze);
        int row = Paths.size();
        int maxstrength = 0,minline = 0; 

        if(row == 0) cout << "Can not escape!" << endl;
        else{
            for(int i = 0;i < row;i++){
                if(Paths[i][Paths[i].size() - 1] > maxstrength) {
                    maxstrength = Paths[i][Paths[i].size() - 1];
                    minline = i;
                }
            }
            for(int j = 0;j < Paths[minline].size() - 3;j += 2){
                show(Paths[minline][j],Paths[minline][j + 1],1);
            }
            show(Paths[minline][Paths[minline].size() - 3],Paths[minline][Paths[minline].size() - 2],0);
            cout << endl;
        }
    }
    return 0;
}