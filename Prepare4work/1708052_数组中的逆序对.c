/* 题目：在数组中两个数字如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
一般方法，顺序扫描整个数组。
更快的算法，我们以数组{7,5,6,4}为例来分析统计逆序对的过程，我们可以考虑先比较两个相邻的数字。
我们先把数组分解成两个程度为2的子数组，再把这两个子数组分别陈分成两个长度为1的子数组。接下来一边合并相邻的子数组，以便统计逆序对的数目。在第一对长度为1的子数组7、5中7大于5,因此（7,5）组成一个逆序对。同样在对二对长度为1的子数组6、4中也有逆序对（6,4）。由于我们已经统计了这两对子数组内部的逆序对，因此需要把这两队子数组排序，一面在以后的统计过程中再重复统计。
a P1指向的数字大于P2指向的数字，标明数组中存在逆序对。P2指向的数字是第二个子数组的第二个数字，因此第二个子数组中由两个数字小于7。把逆序对的数目加2，并把7复制到辅助数组，向前移动P1和P3
b：P1指向的数字小于P2指向的数字，没有逆序对。把P2指向的数字复制到辅助数组，并向前移动P2和P3
C：P1指向的数字大于P2指向的数字，因此存在逆序对。由于P2指向的数字是第二个子数组的第一个数字，子数组中只有一个数字比5小，把逆序对数目加1,并把5复制到辅助数组，向前移动P1和P3
接下来我们统计两个长度为2的子数组之间的逆序对。
我们先用两个指针分别指向两个子数组的末尾，并每次比较两个指针指向的数字。如果第一个子数组中的数字大于第二个子数组中的数字，则构成逆序对，并且逆序对的数目等于第二个子数组中剩余数字的个数。如果第一个数组中的数字小于或等于第二个数组中的数字，则不构成逆序对，每一次比较的时候，我们都把较大的数字从后往前复制到一个辅助数组中去，确保辅助数组中的数字是递增排序的，在把较大的数字复制到辅助数组之后，把对应的指针向前移动移位，接下来进行下一轮比较。
经过前面详细的讨论，我们可以总结出统计逆序对的过程：先把数组分隔成子数组，先统计出子数组内部逆序对的数目，然后在统计出两个相邻子数之间的逆序对的数目。在统计逆序对的过程中，还需要对数组进行排序，如果对排序算法很熟悉，我们不难发现这个排序的过程实际上就是归并排序。我们可以继续归并排序写出如下代码：*/
int InversePairs(int* data,int length)
{
    if(data==NULL||length<0)return 0;
    int* copy=new int[length];
    for(int i=0;i<length;++i)cop[i]=data[i];
    int count=InversePairsCore(data,copy,0,length-1);
    delete[] copy;
    return count;
}
int INversePairsCore(int* data,int* copy,int start,int end)
{
    if(start==end)
    {
        copy[start]=data[start];
        return 0;
    }
    int length=(end-start)/2;
    int left=InversePairsCore(copy,data,start,start+length);
    int right=InversePairsCore(copy,data,start+length+1,end);
    int i=start+length;
    int j=end;
    int indexCopy=end;
    int count=0;
    while(i>=start&&j>=start+length+1)
    {
        if(data[i]>data[j])
        {
            copy[indexCopy--]=data[i--];
            count+=j-start-length;
        }
        else
            copy[indexCopy--]==data[j--];
    }
    for(;i>=start;--i)
        copy[indexCopy--]=data[i];
    for(;j>=start+length+1;--j)
        copy[indexCopy--]=data[j];
    return left+right+count;
}
