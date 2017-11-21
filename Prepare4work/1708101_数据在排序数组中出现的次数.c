/*题目：统计一个数字在排序数组中出现的次数。例如输入排序数组{1，2,3，3,3,3，4,5}和数字3,由于3在这个数组中出现了4此，因此输出4.
既然输入的数组是排序的，那么我们很自然地就能想到用二分查找算发。在题目给出的例子中，我们可以先用二分查找算法找到一个3.由于3可能出现多次，因此我们找到的3的左右两边都可能由3,于是我们在找到的3的左右两边顺序扫描，分表找到第一个3和最后一个3
接下来我们思考如何个更好地利用二分查找算法。假设我们是统计数字k在排序数组中出现的次数。在前面的算法中主要消耗在如何确定重复出现的第一个k和最后一个k的位置上。有没有可能二分查找算法直接找到第一个k和最后一个k呢。
我们先分析如何用二分查找算法在数组中找到第一个k。二分查找算法总是先拿数组中间的数字和k作比较。如果中间数字比k大，那么k只有可能出现在数组的前半端，下一轮我们只在数组的前半端查找就可以了。如果中间的数字比k小，那么k只有可能出现在数组的后半端，下一轮我们只在数组的后半端查找就可以了。如果中间的数字和k相等呢？我们先判断这个数字是不是第一个k。如果位于中间数字的前面一个数字不是k，此时中间的数字刚好就是第一个k。如果中间数字的前面一个数字也是k，也就是说第一个k肯定在数组的前半段。下一轮我们仍然需要在数组的前半段查找。
基于这个思路，我们可以很容易地写出递归的代码找到排序数组中的第一个k*/
int GetFirestK(int* data,int length ,int k,int start,int end)
{
    if(start>end)return -1;
    int middleIndex=(start+end)/2;
    int middleData=data[middleIndex];
    if(middleData==k){
        if(middleIndex>0&&data[middleIndex-1]!=k||middleIndex==0)
            return middleIndex;
        else
            end=middleIndex-1;
    }
    else if(middleData>k)
        end=middleIndex-1;
    else 
        start=middleIndex+1;
    return GetFirstK(data,length,k,start,end);
}
/*在函数GetFirstK中，如果数组中不包含数字k，那么返回-1,如果数组中包含至少一个k，那么返回第一个k在数组中的下标。
我们可以用同样的四路在排序数组中找到最后一个k。如果中间数字比k大，那么k只能出现在数组的前半段。如果中间数字比k小，k就只能出现在数组的后半端。如果中间数字等于k呢？我们需要判断这个k是不是最后一个k，也就是中间数字的加一个数字是不是也等于k。如果下一个数字不是k则中间数字就是最后一个k了；否则下一轮我们还是要在数组的后半段中去查找。*/
int GetLastK(int* data,int length,int k,int start,int end)
{
    if(start>end)return -1;
    int middleIndex=(start+end)/2;
    int middleData=data[middleIndex];
    if(middleData==k)
    {
        if((middleIndex<length-1&&data[middleIndex+1]!=k)||middleIndex==length-1)
            return middleIndex;
        else start=middleIndex+1;
    }
    else if(middleData<k)
        start=middleIndex+1;
    else
        end=middleIndex+1;
    return GetLastK(data,length,k,start,end);
}
int GetNumber(int* data,int length,int k)
{
    int number=0;
    if(data!=NULL&&length>0)
    {
        int first=GetFIrstK(data,length,k,0,length-1);
        int last=GetLastK(data,length,k,0,length-1);
        if(first>-1&&last>-1)
            number=last-first+1;
     }
     return number;
}

