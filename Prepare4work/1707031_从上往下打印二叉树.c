//题目：从上往下打印出二叉树的每个结点，同一层的结点按照从左到由的顺序打印。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
vector<int> PrintFromTopToBottom(TreeNode* root)
{
    vector<int> res;
    if(root==NULL)return res;
    queue<TreeNode*> temp;
    temp.push(root);
    while(!temp.empty())
    {
        TreeNode* Node=temp.front();
        temp.pop;
        if(t->left!=NULL)
            temp.push(Node->left);
        if(t->right!=NULL)
            temp.push(Node->right);
        res.push_back(Node->val);
     }
     return res;
 }
