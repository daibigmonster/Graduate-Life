/*题目：输入一个棵二叉树的根结点判断该树是不是平衡二叉树，如果二叉树中任意结点的左右子树的深度相差不超过1,那么它就是一棵平衡二叉树。
在遍历树的每个结点的时候，调用函数TreeDepth得到它的右子树的深度。如果每个结点的左右子树的深度都相差不超过1,则它就是一个平衡的二叉树。
这种思路对应的代码如下：
bool IsBalanced(BinaryTreeNode* pRoot)
{
    if(pRoot==NULL)return true;
    int left=TreeDepth(pRoot->m_pLeft);
    int right=TreeDepth(pRoot->m_pRight);
    int diff=left-right;
        return false;
    retrun IsBalanced(pRoot->m_pleft)&&IsBalanced(pRoot->m_Right);
}
上面代码固然简洁，但我们也要注意到由于一个结点会被重复遍历多次。这种思路的时间效率不高。
如果我们用后序遍历的方式遍历二叉树的每一个结点，在遍历到一个结点之前我们就已经遍历了它的左右子树。只要在遍历每个结点的时候记录它的深度（某一个结点的深度等于它到叶结点的路径的长度），我们就可以一边遍历一边判断每个结点是不是平衡的*/
bool IsBalanced(BinaryTreeNode* pRoot,int* pDepth)
{
    if(pRoot==NULL)
    {
        *pDepth=0;
        return true;
    }
    int left,right;
    if(IsBalanced(pRoot->m_pLeft,&left)&&IsBalanced(pRoot->m_pRight,&right))
    {
        int diff=left-right;
        if(diff<=1&&diff>=-1)
        {
            *pDepth=1+(left>right?left:right);
            return true;
        }
     }
     return false;
 }
 /*在上面的代码中，我们用后序遍历的方式遍历整棵二叉树。在遍历某就饿点的左右子结点之后，我们可以根据它的左右子结点的深度判断它是不是平衡的，并得到当前结点的深度。当最后遍历到树的根结点的时候，也就判断了整棵二叉树是不是平衡二叉树。
