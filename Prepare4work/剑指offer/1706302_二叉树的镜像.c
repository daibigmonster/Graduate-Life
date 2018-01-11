//题目：请完成一个函数，输入一个二叉树，该函数输出它的镜像
struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode m_pLeft;
    BinaryTreeNode m_pRight;
};
void MirrorRecurively(BinaryTreeNode* pNode)
{
    if((pNode==NULL)||(pNode->m_pLeft==NULL&&pNode->m_pRight==NULL))return;
    BinaryTreeNode* pTemp=pNode->m_pLeft;
    pNode->m_pLeft=pNode->m_pRight;
    pNode->m_pRight=pTemp;
    if(pNode->m_pLeft)
        MirrorRecurively(pNode->m_pleft);
    if(pNode->m_pRight)
        MirrorRecurively(pNode->m_pRight);
}
