/*题目描述
有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？
输入描述:

每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，表示学生的个数，接下来的一行，包含 n 个整数，按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。接下来的一行包含两个整数，k 和 d (1 <= k <= 10, 1 <= d <= 50)。

输出描述:

输出一行表示最大的乘积。*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n,k,d;
	cin>>n;
	vector<int> a(n+1,0);
	for(int i=0;i<n+1;i++){
		cin>>a[i+1];}
	cin>>k>>d;
	vector<vector<int> >dpmax(11,vector<int>(51,0));
	vector<vector<int> >dpmin(11,vector<int>(51,0));
	maxnum=0;
	for(int i=1;i<n;i++){
        dpmax[1][i]=dpmin[1][i]=stu[i];
		for(int j=2;j<=k;j++){
			for(int l=i-1;)
			maxnum=max(maxnum,a[i]);}}
	
