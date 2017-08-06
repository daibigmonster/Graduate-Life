/*牛牛有一个鱼缸。鱼缸里面已经有n条鱼，每条鱼的大小为fishSize[i] (1 ≤ i ≤ n,均为正整数)，牛牛现在想把新捕捉的鱼放入鱼缸。鱼缸内存在着大鱼吃小鱼的定律。经过观察，牛牛发现一条鱼A的大小为另外一条鱼B大小的2倍到10倍(包括2倍大小和10倍大小)，鱼A会吃掉鱼B。考虑到这个，牛牛要放入的鱼就需要保证：
1、放进去的鱼是安全的，不会被其他鱼吃掉
2、这条鱼放进去也不能吃掉其他鱼
鱼缸里面已经存在的鱼已经相处了很久，不考虑他们互相捕食。现在知道新放入鱼的大小范围[minSize,maxSize](考虑鱼的大小都是整数表示),牛牛想知道有多少种大小的鱼可以放入这个鱼缸。
输入描述:

输入数据包括3行.
第一行为新放入鱼的尺寸范围minSize,maxSize(1 ≤ minSize,maxSize ≤ 1000)，以空格分隔。

第二行为鱼缸里面已经有鱼的数量n(1 ≤ n ≤ 50)

第三行为已经有的鱼的大小fishSize[i](1 ≤ fishSize[i] ≤ 1000)，以空格分隔。



输出描述:

输出有多少种大小的鱼可以放入这个鱼缸。考虑鱼的大小都是整数表示*

示例1
输入

1 12
1
1

输出

3

*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
   int minsize,maxsize,n;
   cin>>minsize>>maxsize>>n;
   int count=0;
   int size[1001]={0};
   for(int i=0;i<n;i++)
   {
       int fishsize;
       cin>>fishsize;
       for(int j=fishsize*2;j<=maxsize&&j<=fishsize*10;j++)size[j]=1;
       for(int j=fishsize/2;j>=minsize&&j>=ceil(fishsize/10.0);j--)size[j]=1;
   }
   for(int i=minsize;i<=maxsize;i++){
       if(size[i]==0)
           count++;}
   cout<<count<<endl;
   return 0;
   
}
