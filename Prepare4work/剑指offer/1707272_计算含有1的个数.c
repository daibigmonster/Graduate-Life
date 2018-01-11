#include <iostream>
#include<math.h>
using namespace std;
int com(int m,int n)//m中取n个
{
    int i,j,sum=1;
    if(m==0)return 1;
    if(n==0)return 1;
    for (i=m,j=0;j<n;j++,i--)
    {
        sum=sum*i/(j+1);
    }
    return sum;
}
int LengthofNum(int num)
{
    int length=0;
    double n=num/pow(10,length);
    while(n>0.99999999)
    {
        length++;
        n=num/pow(10,length);
    }
    return length;
}
int count(int num)
{
    if(num<=0)return 0;
    if(num<=9)return 1;
    int length=LengthofNum(num);
    int first=static_cast<int>(num/pow(10,length-1));
    int first1count=0;
    int firstothercount=0;
    int notfirst=0;
    if(first==1)
    {
        first1count=num-pow(10,length-1)+1;
        for(int i=1;i<length;i++)
            firstothercount+=com(length-1,i)*pow(9,length-i-1);
    }
    else if(first>1)
    {    
        first1count=pow(10,length-1);
    for(int i=1;i<length;i++)
        firstothercount+=com(length-1,i)*pow(9,length-i-1);
        firstothercount=firstothercount*(first-1);
        notfirst=count(num-first*pow(10,length-1))
    }
    return (first1count+firstothercount+notfirst); 
}
int main()
{
    int num,result;
    while(cin>>num)
    {
        result=count(num);
        cout<<result<<endl;
    }
    return 0;
}
