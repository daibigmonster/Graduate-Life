

/**
 * 
 */
/**
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
*/
public class Solution {
    private TreeNode pLast = null;
    private TreeNode pFirst = null;
    public TreeNode Convert(TreeNode pRootOfTree) {
        if(pRootOfTree == null || (pRootOfTree.left == null && pRootOfTree.right == null))return pRootOfTree;
        ConvertNode(pRootOfTree);
        return pFirst;
    }

    /**
     * 典型的中序遍历整个二叉搜索树
     */
    private void ConvertNode(TreeNode pRootOfTree ) {
        if(pRootOfTree == null) return;
        TreeNode pCur = pRootOfTree;
        ConvertNode(pCur.left);
        // 形成双向链表，pLast是当前节点的前一个节点
        if(pLast != null)
        {
            pLast.right = pCur;
            pCur.left = pLast;
            pLast = pCur;
        }
        else{
            pLast = pCur;
            pFirst = pCur;
        }
        ConvertNode(pCur.right);
    }
}