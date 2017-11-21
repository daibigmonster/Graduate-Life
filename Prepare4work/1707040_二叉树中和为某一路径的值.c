//题目：输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
struct BinaryTreeNode
{
   int m_nValue;
   BinaryTreeNode* m_pLeft;
   BinaryTreeNode* m_pRight;
   }
void FindPath(BinaryTreeNode* pRoot,int expectedSum)
{
    if(pRoot==NULL)return;
    std::vector<int> path;
    int currentSum;
    FindPath(pRoot,expextedSum,path,currentSum);
}

void FindPath(BinaryTreeNode* pRoot,int expectedSum,std::vector<int>& path,int &currentSum)
{
    currentSum+=pRoot->m_nValue;
    path.push_back(pRoot->m_nVale);
    bool isLeaf=pRoot->m_pLetf==NULL&&pRoot->m_pRight==NULL;
    if(currentSum==expectedSum&&isLeaf)
    {
        printf("A path is found:");
        std::vector<int>::iterator iter=path.begin();
        for(;iter!=path.end();++iter)
            print("%d\t",*iter);
        printf("\n");
     }
     if(pRoot->m_pLeft!=NULL)
         FindPath(pRoot->m_pLeft,expectedSum,path,currentSum);
     if(pRoot->m_pRight!=NULL)
         FindPath(pRoot->m_right,expectedSim,path,surrentSum);
     currentSum-=pRoot->m_nValue;
     path.pop_back();
 }
//第二遍写
void FindPath(BinaryTreeNode* pRoot,int expectedSum)
{
    if(pRoot==NULL)return;
    std::vector<BinaryTreeNode* pRoot>
    int curSum=0;
    FindPath(pRoot,expectedSum,Path,curSum);
}
void FindPath(BinaryTreeNode* pRoot,int expecttedSum,std::vector<int>&path,int& curSum)
{
    curSum+=pRoot->m_nValue;
    path.push_back(pRoot->m_nValue);
    bool isLeaf=pRoot->m_pLeft==NULL&&pRot->m_pRight==NULL;
    if(curSum==expectedSum&&isLeaf)
    {
        printf("A path is found:");
        std::vector<int>::iterator iter=path.begin();
        for(;iter!=path.end();++iter)
            printf("%d\t",*iter);
        printf("\n");
     }
     if(pRoot->m_Left!=NULL)FindPath(pRoot->m_Left,expectedSum,path,curSum);
     if(pRoot->m_right!=NULL)FindPath(pRoot->m_right,expectedSum,path,curSum);
     curSum-=pRoot->m_Value;
     path.pop_back();
}

