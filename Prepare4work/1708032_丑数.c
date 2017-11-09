//题目：我们把质保含因此2、3和5的树称作丑数。求从小到大的顺序的第1500个丑数。例如6、8都属丑数，但14不是，因为包含因此7.
//逐个判断每个整数是不是丑数的解法：
/*bool IsUgly(int number)
{
    while(number%2==0)number/=2;
    while(number%3==0)number/=3;
    while(number%5==0)number/=5;
    return (number==1)?true:false;
}
前面的所发之所以效率低，很大程度上是因为不管一个数是不是丑数我们都要对它做进算。接下来我们试着找到一种只要计算丑数的方法，而不是在非丑数上花费时间。根据丑数的定义，丑数应该是另一个丑数乘以2,3或者5的结果（1除外）。因此我们可以创建一个数组，里面的数是排序好的丑数，每一个丑数都是前面的丑数乘以2、3和5得到
这个四路的关键在于怎样确保数组里面的丑数是排好序的。假设数组中已经由所感个丑数排好序后放在数组中，并且把已有随大的丑数记做M，我们接下来分析如何生成下一个丑数。该丑数肯定是前面某一个丑数乘以2、3和5的结果，所以我们首先把已有的每个丑数乘以2.在乘以2的时候，能够得到若干个小于或等于M的结果由于是按照顺序生成的，小于或者等于M肯定已经在数组中了，我们不需再次考虑;还会的到若干个大于M的结果，但我们值需要第一个大于M的结果，因为我们希望丑数是从小到大的顺序生成的，其他更大的结果以后再说.我们把得到的第一个乘以2后大于M的结果记为M2.同样，我们把已有的每一个丑数乘以3和5,能得到第一个大于M的结果M3和M5，那么下一个丑数应该是M2、M3和M5这三个数的最小者。
前面分析的时候，提到把已有的每个丑数分别乘以2、3和5.实施上这不是必需的*/
int GetUglyNumber_Solution2(int index)
{
    if(index<=0)return 0;
    int *pUglyNumbers=num int[index];
    pUglyNumbers[0]=1;
    int nextUglyIndex=1;
    int *pMultiply2=pUglyNumbers;
    int *pMultiply3=pUglyNumbers;
    int *pMultiply5=pUglyNumbers;
    while(nextUglyIndex<index)
    {
        int min=Min(*pMultiply2*2,*pMultuply3*3,*pMultiply5*5);
        pUglyNumbers[nextUglyIndex]=min;
        while(*pMultiply2*2<=pUglyNumbers[nextUglyIndex])
            ++pMultiply2;
        while(*pMultiply3*3<=pUglyNumbers[nextUglyIndex])
            ++pMultiply3;
        while(*pMultiply5*5<=pUglyNumbers[nextUglyIndex]) 
            ++pMultiply5;
        ++nextUglyIndex;
    }
    int ugly=pUglyNumbers[nextUglyndex-1];
    delete[] pUglynumbers;
    return ugly;
}
