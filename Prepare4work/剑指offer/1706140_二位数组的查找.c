/*在一个二位数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的二维数组和一个整数，判断数组中是否含有改整数*/
//分析：总结上述查找的过程，我们发现如下规律：首先选取数组中右上角的数字，如果该数字等于要查找的数字，查找过程结束：如果数字大于要查找的数字，提出这个数字所在的列;如果该数字小于要差超的数字，剔除这个数字所在的行。也就是说如果要查找的数字不再数组的右上角，则每一次都在数组的查找范围中剔除一行或者一列，这样每一步都可以缩小查找的范围，直到找到要查找的数字，或者查找范围为空*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool Find(int* matrix,int rows,int cols,int num)
{
    bool found=false;
    if(matrix!=NULL&&rows>0&&cols>0)
    {
        int row=0;
        int col=cols-1;
        while(row<rows&&cols>=0)
        {
            if(matrix[row*cols+col]==num){
                found=true;
                break;
            }
            else if(matrix[row*cols+col]>num)
                --col;
            else 
                ++row;
        }}
      return found;
    }
int main()
{
   int row,col,num;
   printf("请输入行和列:");
   scanf("%d",&row);
   scanf("%d",&col);
   int matrix[row*col];
   printf("请输入数组元素：");
   for(int i=0;i<row*col;i++){
       scanf("%d",&matrix[i]);
   }
   printf("请输入需要查找的数字：");
   scanf("%d",&num);
   bool a=Find(matrix,row,col,num);
   if(a)
       printf("查找成功！");
   else
       printf("查找失败！");
   return 0;
 }
