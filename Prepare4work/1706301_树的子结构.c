//题目：输入两颗二叉树A和B，判断B是不是A的子结构。
struct BinaryTreeNode
{
    int m_nVlaue;
    BinaryTree* m_pLeft;
    BinaryTree* m_pRight;
};
//第一步在树A中查找与根结点的值一样的结点，这实际上就是树的遍历
bool HasSubtree(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2)
{
   bool result=false;
   if(pRoot1!=NULL&&pRoot2!=NULL)
   {
        if(pRoot1->m_nValue==pRoot2->m_nValue)
            result=DoesTree1HaveTree2(pRoot1,pRoot2);
        if(!result)
            result=HasSubtree(pRoot1->m_pLeft,pRoot2);
        if(!result)
            result=HasSubtree(pRoot1->m_pRight,pRoot2);
    }
    return result;
}
//第二部是判断树A中以R为根结点的子树是不是和树B具有相同的结构。同样，我们也可以用递归的思路来考虑：如果结点R的值和树B的根结点不同，则以R为根结点的子树和树B肯定不具有相同的结点；如果它们的值相同，则递归地判断它们各地的左右结点的值是不是相同。递归的中调节是我们达到了树A和树B的叶结点。
bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2)
{
    if(pRoot2==NULL)
        return true;
    if(pRoot1==NULL)
        return false;
    if(pRoot1->m_nValue!=pROot2->m_nValue)
        return false;
    return DoesTree1HaveTree2(pRoot1->m_pLeft,pRoot2->m_pLeft)&&DoesTree1HaveTree2(pRoot1->m_pRight,pRoot2->m_pRight);
}

