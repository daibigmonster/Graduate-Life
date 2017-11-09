/*题目：地上有一个m行n列的泛个。一个机器人从坐标(0,0)的各自开始移动，它每次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和大于k的各自。例如，当k为18时，机器人能够进入放个（35,37），因为3+5+3+7=18.但它不能进入方格(25.28),因为3+5+3+8=19.请问该机器人能够到达多少个格子 ？
*/
/*和前面的题目类似，这个放个也可以看作一个m×n的矩阵同样，在这个矩阵中，除边界上的各自之外，其他的各自都有4个相邻的各自
机器人从坐标(0,0)开始移动，当它准备进入坐标为(i,j)的格子时，通过检查坐标的数位来判断机器人是否能够进入。如果机器人嫩够进入坐标为(i,j)的格子，则在判断它能否进入4个相邻的格子。*/

int movingCount(int threshold,int rows,int cols){
	if(threshold<0||rows<=0||cols<=0)return 0;
	bool *visited=new bool[rows*cols];
	for(itn i=0;i<rows*cols;++i)
		visited[i]=false;
	int count=movingCountCore(threahold,rows,cols,0,0,visited);
	deleted[] visited;
	return count;
}
int movingCountCore(int threshold,int rows,int cols,int row,int col,bool *visited){
	int count=0;
	if(check(threshold,rows,cols,row,col,visited))
	{
		visited[row*cols+col]=true;
		count=1+movingCountCore(threshold,rows,cols,row-1,col,visited)
		+movingCountCore(threshol,rows,cols,row,col-1,visited)
		+movingCountCore(threshol,rows,cols,row+1,col,visited)
		+movingCountCore(threshol,rows,cols,row,col+1,visited)
		}
	return count;
}
bool check(int threshold,int rows,int row,int col,bool* visited){
	if(row>=0&&row<rows&&col>=0&&col<cols
		&&getDigitSum(row)+getDigitSum(col)<=threshold
		&&!visited[row*cols+col])
	return true;
	return false;
}
int getDigitSum(int number){
	int sum=0;
	while(number){
		sum+=number&1;
		number=number>>1;
	}
	return sum;
}
