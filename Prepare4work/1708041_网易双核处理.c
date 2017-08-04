/*一种双核CPU的两个核能够同时的处理任务，现在有n个已知数据量的任务需要交给CPU处理，假设已知CPU的每个核1秒可以处理1kb，每个核同时只能处理一项任务。n个任务可以按照任意顺序放入CPU进行处理，现在需要设计一个方案让CPU处理完这批任务所需的时间最少，求这个最小的时间。
输入描述:

输入包括两行：
第一行为整数n(1 ≤ n ≤ 50)
第二行为n个整数length[i](1024 ≤ length[i] ≤ 4194304)，表示每个任务的长度为length[i]kb，每个数均为1024的倍数。



输出描述:

输出一个整数，表示最少需要处理的时间*/
#include<iostream>
#include<set>

using namespace std;
int main()
{
    int length;
    cin>>length;
    int a[51];
    int sum=0,ans;
    for(int i=0;i<length;++i){
        int temp;
        cin>>temp;
        a[i]=temp/1024;
        sum+=a[i];
    }
    set<int>s;
    s.insert(0);
    for(int i=0;i<length;i++){
    set<int>added;
    for(set<int>::iterator it=s.begin();it!=s.end();it++)
        added.insert(*it+a[i]);
    s.insert(added.begin(),added.end());
    ans=sum;
    for(set<int>::iterator it=s.begin();it!=s.end();it++)
        ans=min(max(*it,sum-*it),ans);
    }
    cout<<ans*1024<<endl;
    return 0;
}
