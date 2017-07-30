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
void Qsort(T a[],int left,int right)
{
    if(left>=right)return;
    int i,j;
    if(i<j)
    {
        i=left;
        j=right+1; 
        do{
            do i++;while(a[i]<a[left]);
            do j--;while(a[j]>a[left]);
            if(i<j)Swap(a[i],a[j]);
        }while(i<j);
    Swap(a[left],a[j]);
    for(int k=0;k<right+1;k++)
    {
    cout<<a[k]<<' ';
    }
    cout<<endl;    
    Qsort(a,left,j-1);
    Qsort(a,j+1,right);
     }  
}
template<class T>
void QuickSort(T a[],int n)
{
    Qsort(a,0,n-1);     
}
#define NUM 7

int main()
{
    int a[NUM]={48,36,68,72,12,48,2};
    cout<<"初始序列:";
    for(int i=0;i<NUM;i++)
    {
    cout<<a[i]<<' ';
    }
    cout<<endl;
    QuickSort(a,7);
  //  cout<<a[0];
    for(int i=0;i<NUM;i++)
    {
    cout<<a[i]<<' ';
    }
    cout<<endl;
    return 0;
}
