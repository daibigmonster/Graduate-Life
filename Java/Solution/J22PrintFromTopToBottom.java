import java.util.ArrayList;
import java.util.*;

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
    public ArrayList<Integer> PrintFromTopToBottom(TreeNode root) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        if(root == null) return list;
        Deque<TreeNode> deque = new LinkedList<TreeNode>();
        deque.add(root);
        while(!deque.isEmpty())
        {
            TreeNode t = deque.pop();
            list.add(t.val);
            if(t.left != null) deque.add(t.left);
            if(t.right != null) deque.add(t.right);
        }
        return list;
    }
}