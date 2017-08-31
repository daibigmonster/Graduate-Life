/*题目：找出数组中重复的数字
在一个长度为n的数组里的所有数字都在0～n-1的范围内。数组中某些数字是重复的，但不知由个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
解决这个问题的一个简单的方法是先把输入的数组排序。松排序的数组中找出重复的数字是一件很容易的事情，只需要从头到尾扫描排序后的数组就可以了。
还可以利用哈希表来解决这个问题，从头到尾按顺序扫描数组的每个数字，每扫描到一个数字的时候，都可以用O(1)的时间来浦安端哈希表里是否已包含了该树子。如果哈希表里还没有这个数字，就把它加入哈希表。如果哈希表里已经存在该数字，就找到一个重复的数字。这个算法的时间复杂度是O(n),但它提高时间效率是以一个大小为O(n)的哈希表为代价的。
我们之一到数组中的数字都在0-能-1的范围内。如果这个数组中没有重复的数字，那么当数组排序之后数字i将出现在下标为i的位置。由于数组中由重复的数字，有些位置可能存在多个数字，同时有些位置可能没有数字。
现在让我们重排这个数组。从头到尾依次扫描这个数组中的每个数字，当扫描到下标为i的数字时，首先比较这个数字（用m表示）是不是等于i。如果是，则接着扫描下一个数字，如果不是，则再拿它和第m个数字进行比较。如果它和第m个数字相等，就找到了一个重复的数字（该数字在下标为i和m的位置都出现了）;如果它和第m个数字不相等，就把第i个数字和第m个数字交换，把m放到术语它的位置。接下来重复这个比较、交换的过重，直到我们发现一个重复的数字。
*/
bool duplicte(int numbers[],int length, int *duplication){
	if(numbers==nullptr||length<=0)return false;
	for(itn i=0;i<length;++i){
		while(numbers[i!=i]){
			if(numbers[i]==numbers[numbers[i]]){
				*duplication=numbers[i];
				return true;
			}
			int temp=numbers[i];
			numbersp[i]=numbers[temp];
			numbers[temp]=temp;
		}
	
	}
	return false;
}
