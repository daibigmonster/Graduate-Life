#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
int elem;
int number;
}stu,* Student;


int main()
{

Student student = (stu *)malloc(sizeof (stu)*2);

for(int i=0;i< 2;i++)
{

student[i].elem = i;
student[i].number =i;
}

stu * p=  student;

int i= 2;

while(i)
{
printf("%d " ,p->elem);

printf("%d " ,p->number);

p++; //为什么在调试的时候地址变化是加8进行递增的，并且8刚好是sizeof(stu),为什么会这样？调试第一个地址是0x3d3f00,第二次是0x03d3f08，为什么第二次

//不是0x3d3f01，同时地址数为什么不是8个字节而是6个?
i--;
}
return 0;
} 
