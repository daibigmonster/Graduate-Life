/*题目二叉树前序遍历
1递归法：同中序遍历，调整一下访问顺序即可
*/
class Solution1{
public:
    vector<int> preorderTraverssal(TreeNode* root){
        vector<int> ret;
        preHelper(ret,root)
        return ret;
    }
private:
    void preHelper(vector<int>& ret,TreeNode* root)
    {
        if(root==NULL)return;
        ret.push_back(root->val);
        preHelper(ret,root->left);
        preHelper(ret,root->right);
    }
}
//2迭代法：迭代法使用一个栈来保存当前不需要访问的结点。从根结点开始，访问当前结点，按照先右儿子后左儿子的顺序将当前结点的两个儿子压栈。当栈为空时说明遍历完毕。
class Solution2{
public:
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> ret;
        stack<TreeNode*> st;
        if(!root)return ret;
        st.push(root);
        while(!st.empty())
        {
            TreeNode *curr=st.top();
            st.pop();
            if(curr->right)st.push(curr->right);
            if(curr->left)st.push(curr->left);
            ret.push_back(curr->val);
        }
        return ret;
    }
};
