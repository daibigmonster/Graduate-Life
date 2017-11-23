void SortAges(int ages[],int length)
{
    if(ages==NULL||length<=0)return;
    const int oldestAge=99;
    int timesofAge[oldestAge+a];
    for(int i=0;i<=oldestAge;++i)
        timeofAge[i]=0;
    for(int i=0;i<length;++i)
    {
        int age=ages[i];
        if(age<0||age>oldestAge)
            throw new std::exception("age out of range.");
        ++timeofAge[age];
     }
     int index=0;
     for(int i=0;i<=oldestAge;i++)
     {
         for(int j=0;j<timeOfAge[i];++j)
         {
             ages[index]=i;
             ++index;
         }
     }
 }
 //公司员工的年龄由一个范围，在上面的代码中，允许的范围是0-99岁。数组timesOfAge用来统计每个年龄出现的次数。某个你啊另出现了多少次，就在数组ages里设置几次改年龄。这样就相当给数组gaes排序了。该方法用长度100的整数数组作为辅助空间换来了O(n)的时间效率。

