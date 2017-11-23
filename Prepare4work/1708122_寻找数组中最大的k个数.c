#include<iostream>
#include<vector>
using namespace std;
vector<int> Quicksort(vector<int>&num,int k);
int Partition(vector<int>&num,int start,int end);
void swap(int &a,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
int main(){
int a[8]={4,5,1,6,2,7,3,8};
vector<int> num(a,a+8);
vector<int> minknum;

for(auto x:Quicksort(num,6))cout<<x<<" ";
cout<<endl;
for(auto x:num)cout<<x<<" ";
cout<<endl;
return 0;
}
vector<int> Quicksort(vector<int>&num,int k)
{
    vector<int> output;
    if(num.empty())return output;
    int start=0;
    int end=num.size()-1;
    int index=Partition(num,start,end);
    while(index!=k-1){
        if(index>k-1){
            end=index-1;
            index=Partition(num,start,end);
        }
        else
        {
            start=index+1;
            index=Partition(num,start,end);
         }

     }
     output.insert(output.begin(),num.begin(),num.begin()+k);
     
     return output;
}
int Partition(vector<int>&num,int start,int end)
{
    int key=num[start];
    while(start<end)
    {
        if(start<end&&key>num[end])end--;
        swap(num[start],num[end]);
        if(start<end&&key<=num[start])start++;
        swap(num[start],num[end]);
    }
    return start;
}
