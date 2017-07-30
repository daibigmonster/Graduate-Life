#include "1706241_数值的整数次方.h"
#include<iostream>
using namespace std;
int main()
{
    cout<<"功能菜单："<<endl;
    cout<<"1,数值的整数次方"<<endl;
    cout<<"请根据序号选择功能：";
    int a;
    char reply;
    cin>>a;
    switch(a){
    case 1:
        double result;
        do{
        result=Power();
        cout<<"结果是："<<result<<endl;
        cout<<"是否继续?(y/n)";
        cin>>reply;}while(reply=='y');
        break;
    default:
        cout<<"没有此项功能！"<<endl;
        break;
    return 0;
        }
}
