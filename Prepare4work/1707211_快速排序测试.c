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
    int index=0;
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
         cout<<index<<":";
         for(int i=0;i<7;i++)
         {
             cout<<data[i]<<' ';
         }
         cout<<endl;
     }
     small=small+1;
     Swap(data[small],data[end]);
     return small;
}
#define NUM 7
int main()
{
    int a[NUM]={48,36,68,72,2,48,12};
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
}
