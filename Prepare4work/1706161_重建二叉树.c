//题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不包含重复的数字，重建出所示的二叉树并输出它的头结点，二叉树结点的定义如下：
struct btnode
{
   int value;
   btnode * left;
   btnide * right;
}
btnode * construct(int *preorder,int * inorder,int length)
{
    if(preorder==NULL||inorder==NULL||length<=0)
        return NULL;
    renturn constructcore(preoeder,preorder+length-1,inorder,inorder+length-1);
}
btnode* constructcore(int * startpreorder,int * endpreorder,int * startinorder,int * endinorder)
{
    int rootvalue=startpreorder[0];
    btnode * root=new btnode();
    root->value=rootvalue;
    root->left=root->right=NULL;
    if(startpreorder==endpreorder)
    {
        if(startinorder=endinorder&&*startpreorder==*startinorder)
        return root;
        else throw std::expcetion("wrong!");
    }
    int * rootinorder=startinorder;
    while(rootinorder<=endinorder&&*rootinorder!=rootvalue)
        ++rootinorfer;
    if(rootinorder==endinorder&&*rootinorder!=rootvalue)
        throw std::expcetion("wrong!");
    int leftlength=rootinorder-starinorder;
    int * leftpreorderend=startpreorder+leftlength;
    if(leftlength>0)
    {
        root->left=constercore(startpreorder+1,leftpreorderend,startinorder,rootinorder-1)
    }
    if(leftlength<endpreorder-starpreorde)
    {
        root->right=constercore(leftpreorderend+1,endpreorder,rootinorder+1,endinorder)
    }
    return root;
}

 牛客网上面的答案
 /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin)
 {
     int len=pre.size();
     if(pre.empty()||pre.empty())
         return NULL;
     TreeNode *root=new TreeNode(pre[0]);
     vector<int> left_pre,left_in,right_pre,right_in;
     int mid;
     for(int i=0;i<len;i++)
     {
         if(vin[i]==pre[0])
         {
         mid=i;
         break;}
      }
      for(int i=0;i<mid;i++)
      {
          left_pre.push_back(pre[i+1]);
          left_in.push_back(vin[i]);
      }
      for(int i=mid;i<len;i++)
      {
          right_pre.push_back(pre[i+1]);
          right_in.push_back(pre[i+1]);
      }
      root->left=reConstructBinaryTree(left_pre,left_in);
      root->right=reConstructBinaryTree(right_pre,right_in);
      return root;
  }
    
