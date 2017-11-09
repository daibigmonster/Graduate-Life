#include<iostream>
using namespace std;
void QiuckSort(vector<int> &num,int start,int end)
{
    if(start==end)return;
    int index=Partition(num,start,end);
    while(index!=num.size()-1)
    {
         if(index<num.size()-1){
             start=index+1;
             index=Partition(num,start,end);
         }
    }
}
