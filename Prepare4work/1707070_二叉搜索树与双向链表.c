// 题目：输入二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

//按照中序遍历的顺序，当我们遍历转换到根结点（值为10的结点）时，它的左子树已经转换成一个排序的链表了，并且处在链表中的最后一个结点是当前值最大的结点。我们把值为8的结点和跟结点链接起来，此时链表中最后一个结点就是10了。接着我们去遍历转换右子树，并把根结点和右子树中最小的结点链接起来。我们可以写出如下代码
BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
    BinaryTreeNode* pLastNodeInList=NULL;
    ConvertNode(pRootOfTree,&pLastNodeInList);
    //pLastNodeInList指向双向链表的尾结点
    //我们需要返回头结点
    BinaryTreeNode* pHeadOfList=pLastNodeList;
    while(PheadOfList!=NULL&&pHeadOfList->m_pLeft!=NULL)pHeadOfList=pHeadOfList->m_pLeft;
    return pHeadOfList; 
}
void ConvertNode(BinaryTreeNode* pNode,BinaryTreeNode** pLastNodeInList)
{
    if(pNode==NULL)return;
    BinaryTreeNode* pCurrent=pNode;
    if(pCurrent->m_pLeft!=NULL)ConvertNode(pCurrent->m_pLeft,pLastNodeInList);
    pCurrent->m_pLeft=*pLastNodeInList;
    if(*pLastNodeInList!=NULL)(*pLastNodeInList)->m_pRight=pCurrent;
    *pLastNodeInList=pCurrent;
    if(pCurrent->m_pRight!=NULL)ConvertNode(pCurrent->m_pRight,pLastNodeInList);
 }
//在上面的代码中，我们用pLastNodeInList指向已经转换好的链表的最后一个结点（也是值最大的结点）。当我们遍历到值为10的节点的时候，它的左子树都已经转换好了，因此pLastNodeInList指向值为8的结点。接着把根节点链接到链表中之后，值为10的结点成了链表中最后一个结点（新的值最大的结点），于是pLastNodeInList指向了这个值为10的结点。接下来把pLastNodeInList作为参数传入函数递归遍历右子树。我们找到右子树中最左遍的子节点（值为12的结点，在右子树中值最小），并把该节点和10的节点链接起来。
