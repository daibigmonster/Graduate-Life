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
void InsertSort(T a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i;
        T temp=a[i];
        while(j>0&&temp<a[j-1])
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=temp;
        cout<<"第"<<i<<"遍：";
        for(int k=0;k<n;k++)
        {
            cout<<a[k]<<' ';
        }
        cout<<endl;
    }
}/*直接插入排序算法:
最好情况下的时间复杂度为O(n)
最坏情况下的时间复杂度为O(n^2),稳定算法*/


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
    InsertSort(a,NUM);
    
    return 0;
}
