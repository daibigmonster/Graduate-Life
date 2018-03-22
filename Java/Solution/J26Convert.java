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
        ConvertNode(pRootOfTree);
        return pFirst;
    }


    private void ConvertNode(TreeNode pRootOfTree ) {
        if(pRootOfTree == null) return;
        TreeNode pCur = pRootOfTree;
        ConvertNode(pCur.left);
        if(pLast == null)
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