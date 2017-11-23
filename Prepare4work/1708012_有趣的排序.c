/*度度熊有一个N个数的数组，他想将数组从小到大 排好序，但是萌萌的度度熊只会下面这个操作：
任取数组中的一个数然后将它放置在数组的最后一个位置。
问最少操作多少次可以使得数组从小到大有序？
输入描述:

首先输入一个正整数N，接下来的一行输入N个整数。(N <= 50, 每个数的绝对值小于等于1000)



输出描述:

输出一个整数表示最少的操作次数。*/
#include <iostream>
#include<string>
using namespace std;
int count(string &target);
int main()
{
    string target;
    cin>>target;
    int result=count(target);
    cout<<result<<endl;
    return 0;
}
int count(string &target)
{
    int length=target.size();
    int bnum=0,gnum=0;
    int bcount=0,gcount=0;
    
    for(int i=0;i<length;++i)
    {
        if(target[i]=='B'){
            bnum++;
            bcount+=i;
        }
        else{
            gnum++;
            gcount+=i;
        }
    }
    int comp1=bcount-(bnum*bnum-bnum)/2;
    int comp2=gcount-(gnum*gnum-gnum)/2;
    cout<<bnum<<" "<<gnum<<endl;
    cout<<comp1<<" "<<comp2<<endl;
    return min(comp1,comp2);
}
