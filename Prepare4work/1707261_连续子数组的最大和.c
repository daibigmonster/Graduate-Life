//题目：输入一个整型数组，数组中有正数也有负数，数组中一个或连续的多个整数组成一个子数组。求所有子数组的和的最大值。
bool g_InvalidInput=false;
int FindGreatestSumOfSubArray(int *pData,int nLength)
{
    if((pData==NULL)||(nLength<=0))
    {
    	g_InvalidInput=true;
    	return 0;
    }
    g_InvalidInput=false;
    int nCurSum=0;
    int nGreatestSum=0x80000000;
    for(int i=0;i<nLength;++i)
    {
        if(CurSum<=0)
            nCurSum=pData[i];
        else
            nCurSum+=pData[i];
        if(nCurSum>nGreatesSum)
        	nGreatestSum=nCurSum;
     }
     return nGreatestSum;
}
//解法二：应用动态规划法
//如果算法的功底足够扎实，我们还可以用动态规划的思想来分析这个问题，如果函数f(i)表示以第i个数字结尾的子数组的最大和，那么我们需要求出max[f(i)]，其中0<=i<n
//这个公式的意义：当以第i-1个数字结尾的子数组中所有数字的和小于0时，如果把这个负数与第i个数累加，得到的结果比第i个数字本身还要小，所以这种情况下第i个数字结尾的结束族就是第i个数字本身。如果以第i-1个数字结尾的子数组中所有数字的和大于0,与第age数字累加就的到第age数字结尾的子数组中所有数字的和
