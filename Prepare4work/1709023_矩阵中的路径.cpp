/*题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有的字符路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该这个格子

回溯法可以看成蛮力法的升级版，它从解决问题每一步的所有可能选项里系统地选择出一个可行的解决方案，回溯法非常适合由多个步骤组成的问题，并且每个步骤都有多个选项。当我们在某一不选择了其中一个选项时，就进入下一步，然后又面临新的选项。我们就这样重复选择，直到到达最终的状态。
用回溯法解决的问题的所有选项昂都可以形象地用树状结构表示。在某一步有n个可能的选项，那么该步骤可以看成树状结构中的一个结点，每个选项看成书中结点连接线，经过这些连接线到达该结点的n个子结点。树的叶结点对应书中结点连接线，经过这些连接线到达该结点的那个子结点。树的也结点对应着中介状态。如果在叶结点的状态满足题目的约束条件，那么我们找到了一个可行的方案

这是一个可以用回溯法解决的典型题。首先，在矩阵人选一个各自作为路径的起点。假设矩阵中某个各自的字符为ch，并且这个格子将对应于路径上的第i个字符。假如路径上第i个字符不是ch，那么这个格子不可能处在路径上的第i个位置。如果路径上的第i个字符正好是ch，那么到相邻的各自寻找路径上的第i+1个字符。出矩阵边界上的格子之外，其他各自都由4个相邻的格子.重复这个过程，直到路径上的所有字符都在矩阵中找到相应的位置。
由于回溯法的递归特性，路径可以被看成一个栈。当在矩阵中定位了路径中前n个字符的位置之后，在与第n个字符对应的各自的周围都没有找到相应的第n+1个字符，这个时候只好在路径上回到第n-1个字符，重新定位第n个字符

由于路径不能重复进入矩阵的格子，所以还需要定义和字符矩阵大小的布尔值矩阵，用来标识路径是否已经进入了每个格子。

*/
bool hasPath(char *matrix,int rows,int cols,char *str){
	if(matrix==nullptr||rows<1||cols<1||str==nullptr)return false;
	bool *visited=new bool[rows*cols];
	memset(visited,0,rows*cols);
	for(int row=0;row<rows;++row){
		for(int col;com<cols;++col){
			if(hasPathCore(matrix,rows,cols,row,col,str,pathLength,visited))return true;
		}
	}
	delete[] visited;
	return false;
}
bool hasPathCore(const char* matrix,int rows,int cols,int row,int col,const char* str,int& pathLenght,bool* visited)
{	
	if(str[pathLength]=='\0')return true;
	bool hasPath=false;
	if(row>=0&&row<rows&&col>=0&&col<cols&&matrix[row*cols+col]==str[pathLength]&&!visited[row*cols+col]){
		++pathLength;
		visited[row*cols+col]=true;
		hasPath=hasPathCore(matrix,rows,cols,row,col-1,str,pathLength,visited)||hasPathCore(matrix,rows,cols,rows-1,col,str,pathlength,visited)||hasPatheCore(matrix,rows,cols,row,col+1,str,pathLength,visited)||hasPathCore(matrix,rows,cols,row+1,col,str,pathLength,visited);
	if(!hasPath){
		--pathLength;
		visted[row*cols+col]=false;
	}
}
	return hasPath;
}
	
