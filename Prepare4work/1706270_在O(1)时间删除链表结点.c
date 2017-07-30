//题目：给定单向链表的头指针和一个即诶大拿指针，定义一个函数在O(1)时间删除该结点。链表结点与函数的定义如下：
strcut ListNode
{
    int m_nValue;
    LsitNode * m_pNext;
};
void DeleteNode(ListNode** pListHead,ListNode* pToBeDeleted)
{
    if(!pListHead||!pToBeDeleted)return;
    //要删除的结点不是尾结点
    if(pToBeDeleted->m_pNext!=NULL)
    {
        ListNode* pNext=pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue=pNext->m_nValue;
        pToBeDeleted->m_pNext=pNext->m_pNext;
        delete pNext;
        pNext=NULL;
    }
    else if(*pListHead==pToBeDeleted)
    {
        ListNode pToBeleted;
        pToBeDeleted=NULL;
        *pListHead=NULL;
    }//表中有多个结点，删除尾结点
    else{
        ListNode* pNode=*pListHead;
        while(pNode->m_pNext!=pToBeDeleted)
        {
            pNode=pNode->m_pNext;
        }
        pNode->m_pNext=NULL;
        delete pToBeDeleted;
        pToBeDeleted=NULL;    
    }
}
//接下来我们分析这种思路的时间复杂度。对于n-1个非尾结点而言，我们可以在O(1)时把下一个结点的内存复制覆盖要删除的结点，并删除下一个结点;
