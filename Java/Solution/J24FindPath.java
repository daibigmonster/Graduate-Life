import java.util.ArrayList;

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
    /**
     * brief 递归方法来求解问题
     * @return 返回所有路径和等于target的路径
     */
    public ArrayList<ArrayList<Integer>> FindPath(TreeNode root,int target) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if(root == null) return res;
        ArrayList<Integer> path = new ArrayList<Integer>();
        int curSum = 0;
        findRightPath(root,target,res,path,curSum);
        return res;
    }

    /**
     * @brief 用来递归查找路径的函数
     * @param root 当前节点
     * @param target 目标和
     * @param res 路径集合
     * @param path 当前路径
     */
    public void findRightPath(TreeNode root,int target,ArrayList<ArrayList<Integer>> res,ArrayList<Integer> path,int curSum) {
        if(root == null) return;
        
        curSum += root.val;
        path.add(root.val);

        // 用来判断是否是叶节点
        boolean isleaf = (root.left == null) && (root.right == null);

        // 如果路径值等于target而且是叶子节点 加入路径,如果不是叶子节点,左子树非空,递归处理左子树,右子树亦如此
        if(curSum == target && isleaf){
            res.add(path);
            res.add(new ArrayList<Integer>(path));
            path.remove(path.size() - 1)
            return ;
        } 
        if(root.left != null && curSum < target) findRightPath(root.left, target, res, path, curSum);
        if(root.right != null && curSum < target) findRightPath(root.right, target, res, path, curSum);
        path.remove(path.size() - 1);
    }
}