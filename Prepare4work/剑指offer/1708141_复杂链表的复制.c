/*题目：请实现函数ComplexListNode* CLone(ComplexListNode * pHead),复制一个复杂链表。在复杂链表中，每个节点除了有一个m_pNext指针指向下一个节点外，还有一个m_pSibling指向链表中任意节点或者NULL给出的C++定义如下
struct ComplexListNode{
    int m_nValue;
    ComplexListNode* m_pNext;
    COmplexListNode* m_pSiling;
};
我们试着做优化
第一步仍然是复制原始链表上的每个节点N创建N’，然后把这些创建出来的节点用m_pNext链接起来。同时我们把<N,N'>的配对信息放到一个哈系表中。第二步还是设置复制链表上每个节点的m_pSibling.如果原始链表中的节点N的m_pSibling指向节点S，那么在复制链表中，对应的N‘应该指向S’。由于有了哈系表，我们可以用O(1)的时间根据S找到S'.
第二种方法相当于空间换时间。对于有n个结点的链表我们需要一个大小O(n)的哈西表，也就是说我们以O(n)的空间消耗把时间复杂由O(n^2)降低到O(n).
接下来我们再换一种思路，在不用辅助空间的情况下实现O(n)的时间效率。第三种方法的第一步仍然是根据链表的每个结点N创建对应的N'.这一次，我们把N'放在N后面
第二步设置复制出来的结点m_pSibling。假设原始链表上的N的m_pSibling指向结点S，那么对应复制出来的N'是N的m_pNext指向的节点，同样S’也是S的m_pNext指向的节点。
第三步把这个长链表拆分成两个链表：把起始位置的节点用m_pNext链接起来就是原始链表，把偶数位置的节点用m_pNext链接起来就是复制出来的链表。
第一步的代码*/
void CloneNode(ComplexListNode* pHead)
{
    ComplexListNode* pNode=pHead;
    while(pNode!=NULL)
    {
        ComplexLIstNode* pCloned=new ComplexListNode();
        pCloned->m_nValue=pNode->m_nValue;
        pCloned->m_pNext=pNode->pNext;
        pCloned->m_sibling=NULL;
        pNode->m_pNext=pCloned;
        pNode=pCloned->pNext;
    }
}
//第二部代码把对应节点N'的m_pSibling指向S的下一个节点S'
 void ConnectSiblingNodes(ComplexListNode* pHead)
 {
     ComplexListNode* pNode=pHead;
     while(pNode!=NULL)
     {
         ComplexListNode* pCLoned=pNode->m_pNext;
         if(pNode->m_pSibline!=NULL)
             pCloned->m_pSibling=pNode->m_pSibling->pNext;
         pNode=pCloned->m_pNext;
     }
 }
 //
 ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
 {
     ComplexListNode* pNode=pHead;
     ComplexListNode* pClonedHead=NULL;
     ComplexListNode* pClonedNode=NULL;
     
     if(pNode!=NULL)
     {
         pClonedHead=pClonedNode=pNode->m_pNext;
         pNode->m_pNext=pClonedNode->m_pNext;
         pNode=pNode->m_pNext;
     }
     while(pNode!=NULL)
     {
        pClonedNode->m_pNext=pNode->m_pNext;
        pCloned=pClonedNode->m_pNext;
        pNode->m_pNext=pClonedNode->m_pNext;
        pNode=pNode->m_pNext;
     }
     return pClonedHead;
 }
 //上面三步组合
 ComplexListNode* clone(ComplexLIstNode* pHead)
 {
     ClonedNodes(pHead);
     ConnectSiblingNodes(pHead);
     return ReconnectNodes(pHead);
 }
