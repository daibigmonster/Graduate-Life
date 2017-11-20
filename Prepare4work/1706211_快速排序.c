#include<iostream>
template<typename T>
void Swap(T &a,T &b)
{
    T temp;
    temp=a;
    a=b;
    b=temp;
}
void Qsort(int a[],int left,int right)
{
    if(left>=right)return;
    int i=left;
    int j=right;
    int key=a[i];
    while(i<j)
    {
        while(i<j&&a[j]>=key){--j;}
        //将比第一个小的移动到底端
        while(i<j&&a[i]<=key){++left;}
        if(i<j)Swap(a[i],a[j]);//将比第一个大的移动到底端
    }
    Swap(a[left],a[j]);    
 //   Qsort(a,low,left-1);
 // Qsort(a,left+1,high);
   
}
#define NUM 7
using namespace std;
int main()
{
    int a[NUM]={48,36,68,72,12,48,2};
    cout<<"初始序列:";
    for(int i=0;i<NUM;i++)
    {
    cout<<a[i]<<' ';
    }
    cout<<endl;
    Qsort(a,0,6);
  //  cout<<a[0];
    for(int i=0;i<NUM;i++)
    {
    cout<<a[i]<<' ';
    }
    cout<<endl;
    return 0;
}
