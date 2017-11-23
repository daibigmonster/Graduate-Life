/*不修该数组找出重复的数字
在一个长度为n+1的数组里的所有数字都在1-n的范围内，所以数组中至少有一个数字是重复的，请找出数组中任意一个重复的数字，但不能修改输入的数组
接下来我们尝试避免使用O(n)的辅助空间。为什么数组中会有重复的数字？加入没有重复的数字，那么在1～n的范围内只有n个数字，由于数组里包含超过n个数字，所以一定包含了重复的数字。看起来在某范围里数字的个数对解决这个问题很重要。
我们把从1~n的数字从中间的数字m分为两部分，前面一般为1-m，后面一般为m+1~n.如果1~m的数字的数目超过m，那么这一半的区间里面一定包含重读的数字;否则，另一半m+1~n的区间里面里面一定包含重复的数字。这个过程和二分查找算法很累死，这是多了一步统计区间里数字的数目。*/
int getDuplication(const int *numbers,int length){
	if(numbers==nullptr||length<=0)return -1;
	int start=1;
	int end=length-1;
	while(end>=start){
		int middle((end-start)>>1)+start;
		int count=countRange(numbers,length,start,middle);
		if(end==start){
			if(count>1)return start;
			else break;}
		if(count>(middle-start+1))
			end=middle;
		else
			start=middle+1;
		}
		return -1;}
int countRange(const int *numbers,int length,int start,int end)
{
	if(numbers==nullptr)return 0;
	int count=0;
	for(int i=0;i<length;i++)
		if(numbes[i]>=start&&numbers[i]<=end)++count;
	return count;
}

