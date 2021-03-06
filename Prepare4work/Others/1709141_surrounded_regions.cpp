/* Given a 2D board containing'X'and'O', capture all regions surrounded by'X'.

 A region is captured by flipping all'O's into'X's in that surrounded region .

 For example,

 X X X X
 X O O X
 X X O X
 X O X X


 After running your function, the board should be:

 X X X X
 X X X X
 X X X X
 X O X X
*/
int rowNum=0;
int colNum=0;
public void solve(char[][] board){
	if(boad==null||board.length<=0||board[0].length<=0){
		return;
	}
	rowNum=board.length;
	colNum=board[0].length;
	for(int i=0;i<colNum,i++){
		dfs(board,0,i);
		dfs(board,rowNum-1,i);
	}
	for(int i=0;i<rowNum;i++){
		dfs(board,i,0);
		dfs(board,i,colNum-1);
	}
	for(int i=0;i<rowNum;i++){
		for(int j=0;j<colNum;j++){
			if(board[i][j]=='*'){
				board[i][j]='O';
			else
				board[i][j]='X';
			}
		}
	}
}
void dfs(char[][] board.int row,int col){
	if(board[row][col]=='O'){
		board[row][col]='*';
		if(row>1){
			dfs(board,row-1,col)}
		if(col>1)
			dfs(board,row,col-1)
		if(row<rowNum-1)
			dfs(board,row+1,col);
		if(col<colNum-1)
			dfs(board,row,col+1);
	}
}
