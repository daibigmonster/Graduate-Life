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
int Partition(int data[],int length,int start,int end)
{
    if(data==NULL||length<=0||start<0||end>=length)
         return 0;
    int index=start;
    //Swap(data[index],data[end]);
    int small=start-1;
    for(index=start;index<end;++index)
    {
        if(data[index]<data[end])
        {
            ++small;
            if(small!=index){
                Swap(data[index],data[small]);
            }
         }
     }
     small=small+1;
     Swap(data[small],data[end]);
     return small;
}//对于一个长度为n的数组排序，只需要把start设为0、把end设为n-1,调用函数QuickSort即可
//函数Swap的作用是用来交换两个数字。
void QuickSort(int data[],int length,int start,int end)
{
    if(start==end)
        return;
    int index=Partition(data,length,start,end);
    if(index>start)QuickSort(data,length,start,index-1);
    if(index<end)QuickSort(data,length,index+1,end);
}
#define NUM 7
/*int main()
{
    int a[NUM]={48,36,68,72,12,48,2};
    cout<<"初始序列:";
    for(int i=0;i<NUM;i++)
    {
    cout<<a[i]<<' ';
    }
    cout<<endl;
    Partition(a,7,0,6);
    cout<<"排序后序列:";
     for(int i=0;i<NUM;i++)
    {
    cout<<a[i]<<' ';
    }
    cout<<endl;
    return 0;
}*/
int main()
{
    int a[]={48,36,68,72,12,48,02};
    cout<<"初始序列:";
    for(int i=0;i<NUM;i++)
    {
    cout<<a[i]<<' ';
    }
    cout<<endl;
    QuickSort(a,NUM,0,6);
    for(int i=0;i<NUM;i++)
    {
    cout<<a[i]<<' ';
    }
    cout<<endl;
    return 0;
}
