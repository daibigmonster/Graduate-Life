// git是一种分布式代码管理工具，git通过树的形式记录文件的更改历史，比如： base'<--base<--A<--A' ^ | --- B<--B' 小米工程师常常需要寻找两个分支最近的分割点，即base.假设git 树是多叉树，请实现一个算法，计算git树上任意两点的最近分割点。 （假设git树节点数为n,用邻接矩阵的形式表示git树：字符串数组matrix包含n个字符串，每个字符串由字符'0'或'1'组成，长度为n。matrix[i][j]=='1'当且仅当git树种第i个和第j个节点有连接。节点0为git树的根节点。）
// 输入例子1:

// [01011,10100,01000,10000,10000],1,2


// 输出例子1:

// 1
/**
    * 返回git树上两点的最近分割点
    * 
    * @param matrix 接邻矩阵，表示git树，matrix[i][j] == '1' 当且仅当git树中第i个和第j个节点有连接，节点0为git树的跟节点
    * @param indexA 节点A的index
    * @param indexB 节点B的index
    * @return 整型
    */
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int getsameparent(vector<string> matrix,int indexA,int indexB);
map<int,int> recoder;
int getParent(vector<string> matrix,int a){
    int length = matrix[a].size();
    for(int i = 0;i < length;i++){
        if(matrix[a][i] == '1' && (recoder[i] == recoder[a] - 1)) return i;
    }
    return -1;
}

void DFSmatrix(vector<string> matrix,int i,int col,int level){
    vector<int> num;
    recoder[i] = level + 1;
    for(int j = 0;j < col;j++){
        if(matrix[i][j] == '1'){
            if(recoder.count(j) == 0)
                num.push_back(j);
        }
    }
    for(int i : num)DFSmatrix(matrix,i,col,level + 1);
}
int getSplitNode(vector<string> matrix, int indexA, int indexB) {
    if(indexA == 0 || indexB == 0) return 0;
    int row = matrix.size();
    int col = matrix[0].size();
    DFSmatrix(matrix,0,col,-1);
    // for(int i = 0;i < row;i++){
    //     for(int j = i + 1;j < col;j++){
    //         if(matrix[i][j] == '1')recoder[j] = recoder[i] + 1;
    //     }
    // }
    if(recoder[indexA] == recoder[indexB])return getsameparent(matrix,indexA,indexB);
    else if(recoder[indexA] > recoder[indexB]){
        while(recoder[indexA] != recoder[indexB])indexA = getParent(matrix,indexA);
        return getsameparent(matrix,indexA,indexB);
    }
    else{
        while(recoder[indexA] != recoder[indexB]){
            indexB = getParent(matrix,indexB);
            // cout << indexB << endl;
        }
        return getsameparent(matrix,indexA,indexB);
    }
}

int getsameparent(vector<string> matrix,int indexA,int indexB){
    if(indexA == indexB) return indexA;
    while(getParent(matrix,indexA) != getParent(matrix,indexB)){
        indexA = getParent(matrix,indexA);
        indexB = getParent(matrix,indexB);
    }
    return getParent(matrix,indexA);
}

int main(){
    // [0000001001,0010100000,0100000000,0000000011,0100000010,0000000001,1000000000,0000000001,0001100000,1001010100],6,2
    string str[10] = {"0000001001","0010100000","0100000000","0000000011","0100000010","0000000001","1000000000","0000000001","0001100000","1001010100"};
    vector<string> matrix(str,str + 10);
    cout << getSplitNode(matrix,6,2) << endl;
    for(auto it = recoder.begin();it != recoder.end();it++){
        cout << " " << (*it).first << " " << (*it).second << endl;
    }
    return 0;
    
}
