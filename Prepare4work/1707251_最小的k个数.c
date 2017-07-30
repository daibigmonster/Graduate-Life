//题目：输入n个整数，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4
//如果基于数组的第k个数字来调整，使得比第k个数字小的所有数字都位于数组的左边，比第k个数字大的数字都位于数组的右边。这样调整之后，位于数组中左边的k个数字就是最小的k个数字
void GetLeastNumbers(int* input,int n,int* output,int k)
{
    if(input==NULL||output==NULL||k>n||n<=0||k<=0)return;
    int start=0;
    int end=n-1;
    int index=Partition(input,n,start,end);
    while(index!=k-1)
    {
        if(index>k-1)
        {
            end=index-1;
            index=Partition(input,n,start,end);
        }
        else
        {
            start=index+1;
            index=Partition(input,n,start,end);
        }
    }
    for(int i=0;i<k;++i)
        output[i]=input[i];
}
//解法2我们可以先创建一个大小为k的数据容器来存储最小的k个数字，接下来我们每次从输入的n个整数中读入一个数。如果容器中已有的数字少于kge，则直接把这次读入的整数放入容器之中，如果容器中已有k个数字，也就是容器已满，此时我们不能再插入新的数字而只能替换已有的数字。找出这已有的k个数字中的最大值，然后拿这次待插入的整数和最大值进行比较;如果待插入的值比之前已有的值还大，那么这个数不可能是最小的k个整数之一，于是我们可以抛弃这个整数。
//因此当容易满了之后，我们要做3件事情：一是在k个整数中找到最大数;二是有可能在这个容器中删除最大数;三是有可能要插入一个新的数字。如果用一个二叉树来实现这个数据
