//题目：输入一颗二叉搜索树，将该二叉搜说树转换成一个排序的双向链表，要求不能创建任何新的结点，只能调整树中结点指针的指向。
struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
    BinaryTreeNode* pLastNodeInLIst=NULL;
    convertNode(pRootOfTree,&pLastNodeInList);
    BinaryTreeNode* pHeadOfList=pLastNodeInList;
    while(pHeadOfList!=NULL&&pHeadOfList->m_pLeft!=NULL)
        pHeadOfList=pHeadOfList->m_pLeft;
    return pHeadOfList;
}
void ConvertNode(BinaryTreeNode* pNode,BinaryTreeNode** pLastNodeInList)
{
    if(pNode==NULL)return;
    BinaryTreeNode* pCurrent=pNode;
    if(pCurrent->m_pLeft!=NULL)
        ConvertNode(pCurrent->m_pLeft,pLastNodeInList);
    pCurrent->m_pLeft=*pLastNodeInList;
    if(*pLastNodeInList!=NULL)
        (*pLastNodeInList)->m_pRight=pCurrent;
    *pLastNodeInList=pCurrent;
    if(pCurrent->m_pRight!=NULL)
        ConvertNod(pCurrent->m_pRight,pLastNodeInList);
}
//在上面的代码中，我们用pLastNodeInList指向已经转换好的链表的最后一个结点（也就是值最大的结点）。当我们遍历到值为10的结点的时候，它的左子树都已经转换好了，因此pLastNodeInList指向值为8的结点，接着把根结点连接到链表中之后，值为10的结点成了链表中的最后一个结点（新的值最大的结点），于是pLastNodeInList指向了这个值为10的结点。接下来把pLastNodeInList作为参数传入函数递归遍历右子树 。我们找到右子树中最左边的子结点（值为12的结点，在右子树值最小），并把该结点和值为10的结点链接起来
