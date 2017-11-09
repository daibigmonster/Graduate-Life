//题目：输入一个链表，输出该链表中倒数第k个即诶大拿。为了符合大多数人的习惯，即链表的尾结点是倒数第1个结点。例如一个链表由6个结点，松头开始它们的值一次是1,2,3,4,5,6。这个链表的倒数第3个结点是值为4的结点。
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
}
ListNode *FindKthToTail(ListNode *pListHead,unsigned int k)
{
    if(pListHead==NULL||k==0)return NULL;
    ListNode *pAhead=pListHead;
    ListNode *pBehind=NULL;
    for(unsigned int i=0;i<k-1;++i)
    {
       if(pAHead->m_pNext!=NULL)
           pAHead=pAhead->m_pNext;
       else
           return NULL;
    }
    pBehind=pListHead;
    while(pAhead->m_pNext!=NULL)
    {
       pAhead=pAhead->m_pNext;
       pBehind=pBehind->m_pNext;
    }
    return pBehind;
}
