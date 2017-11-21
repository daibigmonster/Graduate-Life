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
/*在二叉树中，每个街都有两个指向子节点的指针。在双向链表中，每个节点也有两个指针，同时二叉搜索树也是一种排序的数据结构，因此在理论上右可能实现二叉搜索树和排序的双向链表的转换。在搜索二叉树中，左子节点的值总是小于父节点的值，右子节点的值总是大于父节点的值。因此我们在转换成排序双向链表时，原先指向右子节点的指针调整为链表中指向后一个节点指针。
由于要求转换之后的链表是排好序的，我们可以中序遍历树中的每一个结点，这是因为中序遍历算法的特点是按照从小到大的顺序遍历二叉树的每一个结点，当遍历到根结点的时候，我们把树看成三部分：值为10的结点、根结点值为6的左子树，根节点值为14的右子树。按照排序链表的定义，值为10的节点将和它的左子树的最大一个结点（即值为8的结点）链接起来，同死它还将和右子树最小的结点（即值为12的结点）链接起来
按照中序遍历的排序，当我们遍历转换到根结点（值为10的结点）时，它的左子树已经转换成一个排序的链表了，并且在链表的最后一个结点是当前值最大的结点。我们把值为8 的结点和根结点链接起来，此时链表中的就是10了。接着我们去遍历转换右子树，并把根结点和右子树中最小的结点链接起来，至于怎么去转换它的左子树和右子树，由于遍历和转换的过程是一样的，我们很自然想到可以用递归。*/
BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
    BinaryTreeNode *pLastNodeInList=NULL;
    convertNode(pRootOfTree,&pLastNodeInList);
    //pLastTreeNodeInList指向双向链表的尾结点
    //我们需要返回头结点
    BinaryTreeNode *pHeadOfList=pLastNodeInList;
    while(pHeadOfList!=NULL&&pHeadOfList->m_pLeft!=NULL)
        pHeadOfList=pHeadOfList->m_pLeft;
    return pHeadOfList;
}
void ConvertNode(BinaryTreeNode* pNode,BinaryTreeNode** pLastNodeinList)
{
    if(pNode==NULL)return;
    //开始中序遍历二叉树
    BinaryTreeNode *pCurrent=pNode;
    if(pCurrent->m_pLeft!=NULL)
        ConvertNode(pCurrent->m_pLeft,pLastNodeList);
    
    pCurrent->m_pLeft=*pLastNodeInList;
    if(*pLastNodeList!=NULL)
        (*pLastNodeInList)->m_pRight=pCurent;
        
    *pLastNodeInList=pCurrent;
    if(pCurrent->m_pRight!=NULL)
        ConvertNode(pCurrent->m_Right,pLastNodeInList);
 }
 //在上面的代码中，我们用pLastNodeInList指向已经转换好的链表的最后一个节点（也是值最大的节点）。当我们遍历到值为10的节点的时候，它的左子树都已经转换好了，因此pLastNodeList指向值为8的结点。接着把根结点连接到链表中之后，值为10的结点成了链表中的最后一个结点（新的值最大的节点），于是pLastNodeList指向了这个值为10的结点。接下来把pLastNodeInList作为参数传入函数递归遍历右子树。我们找到右子树中最左边的子结点（值为12的结点，在右子树中值最小），并把该结点和值为10的结点链接起来。
