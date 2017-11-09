/*矩阵快速幂
矩阵的快速幂是用来高效地计算矩阵的高次方的。将朴素的O(n)的时间复杂度，降到log(n).
这里对原理做下简单的介绍：
一般一个矩阵的n次方，我们会通过连成n-1此来得到它的n此幂
但做下简单的改进就能减少连乘的次数，方法如下：
把n个矩阵进行两两分组，比如A*A*A*A*A*A=(A*A)*(A*A)*(A*A)
这样变的好处是，你只需要计算一次A*A,然后将结果(A*A)连乘自己两次就能得到A^6
原理就是：利用矩阵算法的结合律，来减少重复计算的次数。
以上都是取一个具体的树来作为最小单位的长度
所以我们现在面对的问题就是找到一种与n增长速度“相适应”的“单位长度”，这个长度到底曾么去取呢？？这点是我们要思考的问题。
有了以上的知识，我们现在再来看看，到底怎么迅速第求得矩阵的N次幂
我们知道，任何一个整数N，都能用二进制来表示
例如求
A^156 而 156(10)=10011100(2)
也就是说A^156=(A^4)*(A^8)*(A^16)*(A^128)
转换成代码就是
while(N){
	if(N&1)res=res*A;
	N=N>>1;
	A=A*A;
}
里面的乘号，是矩阵的运算，res是结果矩阵
*/
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
int N;
struct matrix{
	int a[3][3];
}origin,res;

matrix multiply(matrix x,matrix y){
	matrix temp;
	memset(temp.a,0,sizeof(temp.a));
	//cout<<"开始计算"<<endl;
	for(int i=0;i<3;i++){
	//	cout<<i<<" ";
		for(int j=0;j<3;j++){
	//		cout<<j<<" ";
			for(int k=0;k<3;k++){
	//			cout<<k<<" ";
				temp.a[i][j]+=x.a[i][k]*y.a[k][j];
	//			//cout<<"计算结束"<<endl;
			}
		}
		cout<<endl;
	}
	//	cout<<"计算结束"<<endl;
	return temp;
}
void init(){
	cout<<"随机数组如下"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			origin.a[i][j]=rand()%10;
			printf("%8d",origin.a[i][j]);
		}
		cout<<endl;
	}
	cout<<endl;
	memset(res.a,0,sizeof(res.a));
	res.a[0][0]=res.a[1][1]=res.a[2][2]=1;
}//初始化为3阶矩阵
void calc(int n){
	cout<<n<<"次幂的结果如下"<<endl;
	while(n){
		if(n&1)res=multiply(res,origin);
		n>>=1;
		origin=multiply(origin,origin);
	}
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++)
				printf("%8d",res.a[i][j]);
			cout<<endl;
		}
		cout<<endl;
}
int main(){
	while(cin>>N){
		init();
		calc(N);
	}
	return 0;
}
