#include<iostream>
using namespace std;
template<typename T>
void Swap(T &a,T &b)
{
    T temp;
    temp=a;
    a=b;
    b=temp;
}
template<class T>
void SelectSort(T A[],int n)
{
    int small;
    for(int i=0;i<n-1;i++)
    {
        small=i;
        for(int j=i+1;j<n;j++)if(A[j]<A[small])small=j;
        Swap(A[i],A[small]);
        
        cout<<"第"<<i+1<<"遍：";
        for(int k=0;k<n;k++)
        {
            cout<<A[k]<<' ';
        }
        cout<<endl;
    }
}
//不论初始排列如何，该算法都需要必须执行n-1趟，每趟执行n-i-1祠关键字比较
//因此简单选择排序的最好、最坏和平均情况的时间复杂度都为O(n^2),该排序算法的经过一次排序后，就能确定一个元素的最终位置。简单排序是不稳定的排序算法

#define NUM 7
int main()
{
    int a[NUM]={48,36,68,72,12,48,02};
    int i=9;
    int j=10;
    cout<<"初始序列:";
    for(int i=0;i<NUM;i++)
    {
    cout<<a[i]<<' ';
    }
    cout<<endl;
    SelectSort(a,NUM);
    return 0;
}
