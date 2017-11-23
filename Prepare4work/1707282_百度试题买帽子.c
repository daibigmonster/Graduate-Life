#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int Price3(int *data,int length)
{
    int count=1;
    if(!data||length<=0)return 0;
    sort(data,data+length-1);
    
    int i=0;
    for(i=1;i<length;++i)
    {
        if(data[i]!=data[i-1])count++;
        if(count==3)break;
    }
    cout<<count<<endl;
    if(count<=2)return -1;
    return data[i];
}
int main()
{
    int length;
    cin>>length;
    //cout<<endl;
    int data[length-1];
    for(int i=0;i<length-1;i++)
        cin>>data[i];
    int result=Price3(data,length);
    cout<<result<<endl;
    return 0;
}
