//题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有都属位于数组的后半数分
//思路：我们在扫描这个数组的时候，如果发现有偶数出现在奇数的前面，我们可以交换它们的顺序，交换之后就符合要求了。因此我们可以维护两个指针，第一个指针初始化时指向数组的第一个数字，它只向后移动dirge指针初始化时指向数组的最后一个数字，它只能向前移动。第二个指针初始化时指向数组的最后一个数字，它只能向前移动。在两个指针相遇之前，第一个指针总是位于第二个指针的前面。如果第一个指针指向的数字是偶数，并且第二个指针指向的数字是奇数，我们就交换这两个数字。
void ReorderOddEven(int *pData,unsigned int length)
{
    if(pData==NULL||length==0)
        return;
    int *pBegin=pData;
    int *pEnd=pData+length-1;
    while(pBegin<pEndl)
    {
        while(pBegin<pEnd&&(*pBegin&1)!=0)
            pBegin++;
        while(pBegin<pEnd&&(*pEnd&1)==0)
            pEnd--;
        if(pBegin<pENd)
        {
            int temp=*pBegin;
            *pBegin=*pEnd;
            *pEnd=temp;
        }    
    }
}
//我们发现要解决这两个新的问题，起始只要修改函数ReorderOddeven中亮出判断的标准，而大的逻辑框架完全不住要改动。因此我们可以把这个逻辑框架抽象出来，而把判断的标准编程一个函数指针，也就是用一个当读的函数来判断数字是不是符合标准，这样我们就把整个函数接耦成两个部分：一是判断数字应该在数组的前半部分还是后半部分的标准，二是拆分数组的操作。
void Reorder(int *pData,unsigned int length,bool (*func)(int))
{
    if(pData==NULL||length==0)return;
    int *pBegin=pData;
    int *pEnd=pData+length-1;
    while(pBegin<pEnd)
    {
       while(pBegin<pEnd&&!Func(*pBegin))pBegin++;
       while(pBegin<pEnd&&!Func(*pENd))pEnd--;
       if(pBegin<pEnd)
       {
          int temp=*pBegin;
          *pBegin=*pEnd;
          *pEnd=temp;
       }
   }
}
bool isEven(int n)
{
    return(n&1)==0;
 }
 
 void ReorderOddEven(int *pData,unsigned int length)
 {
     Reorder(pData,length,isEven);
 }
