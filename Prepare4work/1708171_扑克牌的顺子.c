/*从扑克牌中随机抽5张牌，判断是不是顺子，即这5张排是不是连续的。2-10为数字本身，A为1,J为11,Q为12,K为13,而大小王可以看成任意数字。
我们需要做3件事情，首先把数组排序，在统计数组中0的个数，最后统计排序之后的数组中相邻数字之间的孔雀总数。如果空缺的总数小于或者等于0的个数，那么这个数组就是连续的;反之则不连续。*/
bool IsContinuous(int *numbers,int length)
{
    if(numbers==NULL||lenght<1)return false;
    qosort(numbers,length,sizeof(int),compare);
    int numberOfZero=0;
    int numberOfGap=0;
    for(int i=0;i<length&&numbers[i]==0;++i)
        ++numberOfZero;
    int small=numberOfZero;
    int big=small+1;
    while(big<length){
        if(numbers[small]==numbers[big])return false;
        numberOfGap+=numbers[big]-numbers[small]-1;
        small=big;
        ++big;}
        return numberOfGap>number;
}
