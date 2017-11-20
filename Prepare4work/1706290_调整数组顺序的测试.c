#include<iostream>
#include<vector>
using namespace std;   
void print(vector<int> &a,int length)
{
   for(int i=0;i<length;i++)
    {
    cout<<a[i]<<' ';
    }
    cout<<endl;
}

void reOrderArray(vector<int> &array) {
        if(&array==NULL||array.size()==0)
        {
            cout<<"出现错误！"<<endl;
            return;
         }
        int length=array.size();
        int i,j;
        for(i=0;i<length;i++)
        {
            if(array[i]&1)
            {
                int temp=array[i];
                for(j=i-1;j>=0&&!(array[j]&1);--j)
                {
                     array[j+1]=array[j];
                }
                array[j+1]=temp;
             }
        }
}

void InsertSort(vector<int> &a,int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i;
        int temp=a[i];
        while(j>0&&temp<a[j-1])
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=temp;
       /* cout<<"第"<<i<<"遍：";
        for(int k=0;k<n;k++)
        {
            cout<<a[k]<<' ';
        }
        cout<<endl;*/
    }
}

int main()
{
    int v[10]={98,76,109,34,67,190,1,3,5,7};
    vector<int> a(&v[0],&v[9]);
    int length=a.size();
    print(a,length);
    reOrderArray(a);
    print(a,length);
    InsertSort(a,length);
    print(a,length);
    return 0;
}
