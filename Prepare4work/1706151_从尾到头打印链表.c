//题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值
struct ListNode
{
   int key;
   ListNode* next;
}
//我们可以用栈来实现这种函数，每经过一个结点的时候，把结点放到一个栈中。当遍历完整个链表后，再从栈顶开始逐个输出结点的值，此时输出的结点的顺序已经反转过来了。
vector<int> Prlistreversingly(List * pHead)
{
    vector<int> val;
    while(pHead!=NULL)
    {
        value.insert(value.begin(),pHead->key);
        pHead=pHead->next;
    }
    return key;
}
