//题目：请实现函数ComplexListNode*Clone(ComplexListNode* pHead),复制一个复杂链表。在复杂链表中，每个结点除了有一个m——pNext指针指向下一个结点外，还有一个m_pSibling指向链表中的任意结点或者NULL.
struct ComplexListNode
{
   int m_nValue;
   ComplexListNode* m_pNext;
   ComplexListNode* m_pSibling;
};
//复制原始链表的任意结点N并创建新结点N‘，在把N’链接到N的后面
void CloneNodes(ComplexListNode* pHead)
{
    ComplexListNode* pCloned=new ComplexListNode();
    pCloned->m_nValue=pNode->m_nValue;
    pCloned->m_npNext=pNode->m_pNext;
    pCloned->m_pSibling=NULL;
    pNode->m_pNext=pCloned;
    pNode=pCloned->m_pNext;
 }
 //如果原始链表上的结点N的m_pSibling之上S，则它的对应的复制结点N’的m_pSibling指向S的下一个结点S'.
 void ConnectSiblingNodes(ComplexListNode* pHead)
 {
     ComplexListNode* pNode=pHead;
     while(pNode!=NULL)
     {
         ComplexListNode* pNode=pHead;
         if(pNode->m_psibling!=NULL)
         {
             pCloned->m_pSibling=pNode->m_pSibling->m_pNext;
         }
         pNode=pClone->m_pNext;
      }
 }
 //把第二部得到的链表拆分成两个链表，奇数位置上的结点组成原始链表，偶数位置上的结点组成复制出来的链表。
ComplexListNode* ReconnectNodes(ComplexListNode * pHead)
{
     ComplexListNode* pNode=pHead;
     ComplexListNode* pClonedHead=NULL;
     ComplexListNode* pClonedNode=NULL;
     if(pNode!=NULL)
     {
         pClonedHead=pClonedNode=pNode->m_pNext;
         pNode=pClonedNode->m_pNext;
         pNode=pNode->m_pNext;
      }
      while(pNode!=NULL)
      {
         pClonedHead->m_pNext=pNode->m_pNext;
         pClonedNode=pClonedNode->m_pNext;
         pNode->m_pNext=pClonedNode->m_pNext;}
         pNode=pNode->m_pNext;
       }
       return pCloneHead;
 }
 //把上面三步合起来，就是复制链表的完整过程
 ComplexListNode* Clone(ComplexListNode* pHead)
 {
     CloneNode(pHead);
     ConnectSiblingNodes()}
