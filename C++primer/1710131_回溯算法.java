/* 给你两个整数n和k，从1 - n 中选择k 个数字的组合。比如说n = 4，那么从1，2，3，4中选取两个数字的组合，包括上述所属的四种
然后我们看题目给出的框架
public class Solution{
	public List<List<Integer>> combine(int n,int k)){}
}


这样的题目的套路
1定义一个全局List<List<Integer>> result = new ArrayList<List<Integer>>()
2定义一个辅助的方法（函数）public void back tracking(int n,int k,List<Integer> list){}
 n k 总是要有的，加上这两个参数，前面提到的List<Intefer>是数字的组合，也是需要的吧，这三个是必须
3如何实现这个算法？对于n = 4,k = 2, 1,2,3,4中选2个数字，我们可以做如下的尝试，加入先选择1，那么我们只需要再选择一个数字，，注意这时候k = 1
当然我们也可以先选择2，3或者4，通俗化点，我们可以选择（1 - n）中的所有数字。
public void backtracking(int n,int k,int start,List<Integer> list){
	if(k < 0) return;
	if(k == 0){result.add(new ArrayList(list));}
	for(int i = start;i <= n;i++){
		list.add(i);
		backtracking(n,k - 1, i + 1;list);
	}
}
观察上述代码，我们加入了一个start变量，它是i的起点。start表明我们第一次加入了1，则下面加入的则不可能是1，必须是2，3，4
我们在找到了1，2这对答案之后，下一次希望2退出然后让3进来，1，3就是我们要找的组合。如果不回退，就会产生错误答案
正确的做法就是加上：list.remove(listsize() - 1);它的作用就是每次清除一个空位，让后续元素加入。
所以完整的程序如下*/
public class Solution{
	List<List<Integer>> result = new ArrayList<List<Integer>>();
	public List<List<Integer>> combine(int n,int k){
		List<Integer> list = new ArrayList<Integer>();
		backtracking(n,k,1,list);
		return result;
	}
	public void backtracking(int n,int k,int start,List<Integer>list){
		if(k < 0)return;
		if(k == 0)result.add(new ArrayList(list));
		for(int i = start;i <= n;i++){
			list.add(i);
			backtracking(n,k - 1,i + 1;list);
			list.remove(list.size() - 1);
		}
	}
}
