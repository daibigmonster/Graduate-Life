import java.util.ArrayList;
import java.util.List;

import javax.swing.tree.TreeNode;

/**
 * J4260218
 */     
public class J4260218 {
    public TreeNode reConstructBinaryTree(int [] pre,int [] in) {
        ArrayList<Integer> preList = new ArrayList<Integer>(pre.length);        
        ArrayList<Integer> inList = new ArrayList<Integer>(in.length);        
        for(int i : pre) preList.add(i);
        for(int i : in) inList.add(i);
        return getRootNode(preList,inList);
    }
    private TreeNode getRootNode(List<Integer> preList,List<Integer> inList) {
        if(preList.size() == 0) return null;
        int rootVal = preList.get(0);
        TreeNode root = new TreeNode(rootVal);
        int index = inList.indexOf(rootVal);
        List<Integer> leftInList = inList.subList(0, index);
        List<Integer> rightInList = inList.subList(index + 1, inList.size());
        List<Integer> leftPreList = preList.subList(1, leftInList.size() + 1);
        List<Integer> rightPreList = preList.subList(preList.size() - rightInList.size(), preList.size());
        root.left = getRootNode(leftPreList,leftInList);
        root.right = getRootNode(rightPreList,rightInList);

        return root;
    }
}