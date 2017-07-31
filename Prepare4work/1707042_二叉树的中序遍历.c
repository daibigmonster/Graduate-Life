/*直观来看，二叉树的中序遍历就是将节点投影到一条水平的坐标上
1递归法
这是思路最简单的方法，容易想到并且容易实现，递归的种植条件是当前节点是否为空。首先递归调用遍历左子树，然后访问当前节点，最后递归调用右子树。代码如下*/
class Solution1{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        if(root==NULL)retrun ret;
        inoederHelper(ret,root);
        return ret;
    }
private:
    void inorderHelper(vector<int>& ret,TreeNode* root)
    {
        if(root==NULL)return;
        inorderHelper(ret,root->left);
        ret.push_back(root->val);
        inorderHelper(ret,root->right);
     }
}
/*
2迭代法
在迭代的方法中，从根结点开始找二叉树的最左结点，将走过的结点保存在一个栈中，找到的最左节点后访问，对于每个节点来说，它都是以自己为根的子树的根结点，访问完之后就可以转到右儿子上了。*/
class Solution2{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        if(root==NULL)return ret;
        TreeNode* Curr=root;
        stack<TreeNode*> st;
        while(!st.empty()||curr!=NULL)
        {
            while(curr!=NULL)
            {
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            ret.push_back(curr->val);
            curr=curr->right;
        }
        return ret;
     }
 }
