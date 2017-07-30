//题目1：输入一颗二叉树的根结点，求该树的深度。从根结点到叶结点一次经过的结点一次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度
struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};
//我们还可以从另外一个角度来理解树的深度。如果一棵树只有一个结点，它的深度为1.如果根结点只有左子树没有右子树，那么树的深度应该是其左子树的深度加1;同样如果根结点只有右子树而没有左子树，那么树的深度因该是其右子树的深度加1;如果既有左子树又有右子树，那该树的深度就是其左右子树的较大值再加1
int TreeDepth(BinaryTreeNode* pRoot)
{
    if(pRoot==NULL)return 0;
    int nLeft=TreeDeDepth(pRoot->m_pLeft);
    int nRight=TreeDepth(pRoot->m_pRight);
    return (nLeft>nRight)?(nLeft+1):(nRight+1);
}
//leetcode里面由一条题目，是求二叉树最小路径深度，用深度遍历的算法
int TreeDepth(BinaryTreeNode* pRoot)
{
   if(!pRoot)return 0;
   int nLeft=TreeDepth(pRoot->m_Left);
   int nRight=TreeDepth(pRoot->m_Right);
   if(nLeft==0||nRight==0)return 1+nLeft+nRight;
   return 1+min(nLeft,nRight);
}
//层次遍历的算法
int TreeDepth(BinaryTreeNode* pRoot)
{
    if(pRoot==NULL)return 0;
    queue<TreeNode> qu;
    TreeNode last,now;
    last=pRoot;
    now=pRoot;
    level=1;
    qu.push(root);
    

}
