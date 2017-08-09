/*题目1：输入一个递增排序的数组和一个数字s，在数组中查找两个树，使得它们的和正好是s。如果由很多对数字的和等于s，输出任意一对即可
简单的方法：先在数组中固定一个数字，再一次判断数组中其余的n-1个数字与它的和是不是等于s。
接着我们寻找更好的算法。我们现在数组中选择两个数字如果它们的和等于输入的s，我们就找到了要找的两个数字，如果和小于s呢？我们希望两个数字的和再大一点。由于数组已经排序，我们可以考虑选择较小数字后面的数字。因为排在后面的数字要大一些，那么两个数字的和也要大一些，就由可能等于输入的数字s了。同样，当两个数字的和大于输入的数。我们可以选择较大数字前面的数字。
题目2,输入一个正数s，打印出所有和为s的连续整数序列（至少含有两个树）。例如输入15,由于1+2+3+4+5=4+5+6=7+8=15,所以打印出3个连续序列1～5,4～6和7～8
我们考虑用两个数small和big分别表示序列的最大值和最小值，首先把small初始化为1,big初始化为2.如果从small到big序列的和大于s，我们可以从序列中去掉较小的值，也就是增大small的值。如果从small到big的值的序列小于s，我们可以增大big，让这个序列包含更多的数字。因为这个序列至少要有两个数字，我们一直增加small到（1+s）/2为止。*/
void FindContinuousSequence(int sum){
    if(sum<3)return;
    int samll=1;
    int big=2;
    int middle=(1+sum)/2;
    int curSum=samll+big;
    
    while(small<middle){
        if(curSum==sum)PrintContinuousSequence(small,big);
        while(curSum>sum&&samll<middle){
            cur-=small;
            small++;
        if(cursum==sum)PrintContinuousSequence(small,big);
        }
    big++;
    curSum+=big;
    }
}
void PringtcontinuousSequence(int small,int big)
{
    for(int i=small;i<=big;++i)printf("%d",i);
    printf("\n");
}
