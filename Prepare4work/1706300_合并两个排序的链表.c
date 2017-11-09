//题目：输入两个递增排序的链表，合并这两个链表并使新联标中的结点仍然是按照递增排序的。
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
}
ListNode * Merge(ListNode* pHead1,ListNode* pHead2)
{
    if(pHead1==NULL)return pHead2;
    else if(pHead2=NULL)return pHead1;
    ListNode* pMergeHead=NULL:
    if(pHead1->m_nValue<phead2->m_nValue)
    {
        pMergedhead=phead1;
        pMergedhead->m_pNext=Merge(pHead1->m_pNext,pHead2);
    }
    else
    {
        pMergedHead=pHead2;
        pMergedHead->m_pNext=Merge(pHead1,pHead2->m_pNext);
    }
    return pMergedhead;
}
