//题目：输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是按照递增排序的
List Node* merge(ListNode* pHead1,ListNode* pHead2)
{
    if(pHead1==NULL)return pHead2;
    if(pHead2==NULL)return pHead1;
    ListNode* pMergedHead=NULL;
    if(pHead1->m_nValue<pHead2->m_nValue)
    {
        pMergedHead=pHead1;
        pMerged->m_pNext=Merge(pHead1->m_pNext,pHead2);
    }
    else
    {
        pMergedHead=pHead2;
        pMergedHead->m_pNext=Merge(pHead1,pHead2->m_pNext);
    }
    return pMergedHead;
}
