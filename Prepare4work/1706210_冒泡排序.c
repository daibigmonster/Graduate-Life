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
void BubbleSort(T a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
             if(a[j+1]<a[j])
                 Swap(a[j],a[j+1]);
        }
        cout<<"第"<<i<<"遍：";
        for(int k=0;k<n;k++)
        {
            cout<<a[k]<<' ';
        }
        cout<<endl;
    }
}/*冒泡排序算法：
最好情况下（已经有序）只需要进行一趟排序，n-1此比较，时间复杂度为O(n)
最坏情况下的时间复杂度为O(n^2),稳定算法*/


#define NUM 7
int main()
{
    int a[NUM]={48,36,68,72,12,48,02};
    cout<<"初始序列:";
    for(int i=0;i<NUM;i++)
    {
    cout<<a[i]<<' ';
    }
    cout<<endl;
    BubbleSort(a,NUM);
    
    return 0;
}
