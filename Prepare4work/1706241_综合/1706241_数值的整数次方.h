//题目：实现函数double Power(double base,int exponent),求base的exponent次方。不得使用库函数，同时不需要考虑大数问题
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
bool g_InvalidInput=false;
bool equal(double num1,double num2)
{
    if(abs(num1-num2)<0.0000001)
        return true;
    else return false;}
double PowerWithUnsignedExponent(double base,unsigned int exponent)
{
    double result=1.0;
    for(int i=1;i<=exponent;++i)
        result*=base;
    return result;
    }
double Power()
{
    double base;
    int exponent;
    cout<<"请输入基数：";
    cin>>base;
    cout<<"请输入指数：";
    cin>>exponent;
    bool g_InvalidInput=false;
    if(equal(base,0.0)&&exponent<0)
    {
        g_InvalidInput=true;
        return 0.0;
    }
    unsigned int absExponent=(unsigned int)(exponent);
    if(exponent<0)
        absExponent=(unsigned int)(-exponent);
    else absExponent=(unsigned int)(exponent);
    double result=PowerWithUnsignedExponent(base,absExponent);
    if(exponent<0)
        result=1.0/result;
    else return result;
    }

