//题目：输入一个矩阵，按照从外向里以顺时针的顺序一次打印出每一个数字
//我们得出，让循环继续的条件是columns>starX*2并且rows>statY*2.
void PrintMatrixClockwisely(int** numbers,int columns,int rows)
{
    if(numbers==NULL||columns<=0||rows<=0)
        return;
    int start=0;
    while(columns>start*2&&rows>star*2)
    {
        PrintMatrixInCircle(numbers,columns,rows,start);
        ++start;
     }
}
//分析打印每一步的前提条件。第一步总是需要的，因为打印每一圈至少有一步。如果只有一行，那么就不用第二步了。也就是需要第二步的前提条件是终止行号大于起始行号。第三部打印的前提条件是圈内至少由两行两列，也就是说除了需要终止行号大于起始行号之外，还要终止列号大于起始列号。同理，需要打印第四步的前提条件至少由三行两列，因此要求终止行号比起始行号至少大2,同时终止列号大于起始列号。
void PrintMatrixInCricle(int** numbers,int columns,int rows,int start)
{
    int endX=columns-1-start;
    int endY=rows-1-start;
    //从左往右打印一行
    for(int i=start;i<=endX;++i)
    {
        int number=numbers[start][i];
        printNumber(number);
    }
    //从上到下打印一列
    if(start<endY)
    {
        for(int i=start+1;i<=endY;++i)
        {
            int number=numbers[i][endX];
            printNumber(number);
        }
    }
    //从右到左打印一行
    if(start<endX&&start<endY-1)
    {
        for(int i=endX-1;i>=start;--i)
        {
            int number=numbers[endY][i];
            printNumber(number);
         }
     }
     //从下到上打印一行
     if(start<endX&&start<endY-1)
     {
         for(int i=endY-1;i>=start+1;--i)
         {
             int number=number[i][start];
             printNumber(number);
          }
      }
  }
  
  //class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int>res;
        res.clear();
        int row=matrix.size();//行数
        int collor=matrix[0].size();//列数
        //计算打印的圈数
        int circle=((row<collor?row:collor)-1)/2+1;//圈数
        for(int i=0;i<circle;i++){
            //从左向右打印
            for(int j=i;j<collor-i;j++)
                res.push_back(matrix[i][j]);         
            //从上往下的每一列数据
            for(int k=i+1;k<row-i;k++)
                res.push_back(matrix[k][collor-1-i]);
            //判断是否会重复打印(从右向左的每行数据)
            for(int m=collor-i-2;(m>=i)&&(row-i-1!=i);m--)
                res.push_back(matrix[row-i-1][m]);
            //判断是否会重复打印(从下往上的每一列数据)
            for(int n=row-i-2;(n>i)&&(collor-i-1!=i);n--)
                res.push_back(matrix[n][i]);}
        return res;
    }
};
