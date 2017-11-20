//题目：数组中右一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2.
//解法1：基于Partition函数的O(n)算法
//这段快速排序算法的意思是小于data[end]的全部排到前面。而大于data[end]的全部排到后面，最后将data[samll]与data[end]交换位置
int Partition(int data[],int length,int start,int end)
{
    if(data==NULL||length<=0||start<0||end>=length)
        return 0;
    int index=0;
    //Swap(&data[index],&data[end]);
    int small=start-1;
    for(index=start;index<end;++index)
    {
        if(data[index]<data[end])
        {
            ++small;
            if(small!=index)
                swap(&data[index],&data[small]);
        }
     }
     ++small;
     swap(&data[small],&data[end]);//如果data[small]的值大于data[end],则交换它们的值
     return small;//并返回这个small的位置
    }
//这种算法是受快速排序算法的启发，在随机快速排序算法中，我们现在数组中随机选择一个数字，然后调整数组中数字的顺序，使得比选中的数字小数字都排在它的左边，比选中的数字大的数字都排在它的右边。如果这个选中的数字的下表刚好是n/2，那么这个数字就是数组的中位数，如果它的下边大于n/2，那么中位数应该位于它的左边，我们可以接着在它的左边部分的数组中查找。如果它的下表小于n/2，那么中位数因该位于它的右边，我们可以接着在它的右边部分的数组中查找。这是典型的递归过程，可以用如下代码实现：
int MoreThanHalfNum(int* numbers,int length)
{
    if(CheckInvalidArray(numbers,length))return 0;
    int middle=length>>1;
    int start=0;
    int end=length-1;
    int index=Partition(numbers,length,start,end);
    while(index!=middle)
    {
        if(index>middle)
        {
            end=index-1;
            index=Partition(numbers,length,start,end);
        }
        else
        {
             start=index+1;
             index=Partition(numbers,length,start,end);
        }
    }
    int result=numbers[middle];
    if(!CheckMoreThanHalf(numbers,length,result))
        result=0;
    return result;
}
/*第二种思路
int MoreThanHalfNum(int* numbers,int length)
{
   if(CheckInvalidArray(numbers,length))return 0;
   int result=numbers[0];
   int times=1;
   for(int i=1;i<times;++i)
   {
       if(times==0)
       {
           result=numbers[i];
           times=1;
       }
       else if(numbers[i]==result)
           times++;
       else
           times--;
    }
    if(!CheckMoreThanHalf(numbers,length,result))
        result=0;
    return result;
}*/
//除了要完成基本功能即找到符合要求的数字之外，还要考虑一些无效的输入。如果函数的输入参数是一个指针（数组在函数传递的时候退化为指针），就要考虑这个指针可能为NULL.下面的函数CheckInvalidArray用来判断输入的数组是不是无效的。题目中说数组中有一个数字出现的次数超过数组长度的一半，如果输入的数组中出现频率最高的数字都没有达到这个标准怎么？这就是我们定义了一个CheckMOreThanHalf的原因
bool g_bInputInvalid=false;
bool CheckIncalidArray(int* numbers,int length)
{
    g_bInputInvalid=false;
    if(numbers==NULL&&length<=0)
        g_bInputInvalid=true;
    retrun g_bInputInvalid;
}
bool CheckMoreThanHalf(int * numbers;int length;int number)
{
    int times=0;
    for(int i=0;i<length;++i)
    {
        if(numbers[i]==number)
             times++;
    }
    bool isMoreThanHalf=true;
    if(times*2<=length)
    {
        g_bInputInvalid=true;
        isMoreThanHalf=false;
    }
    return isMoreThanHalf;
}
