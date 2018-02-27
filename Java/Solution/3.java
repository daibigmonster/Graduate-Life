/**
*    public class ListNode {
*        int val;
*        ListNode next = null;
*
*        ListNode(int val) {
*            this.val = val;
*        }
*    }
*
*/
import java.util.ArrayList;
import java.util.Stack;
public class Solution {
    public ArrayList<Integer> printListFromTailToHead(ListNode listNode) {
        Stack<Integer> stack = new Stack<Integer>();
        while(listNode != null)
        {
            stack.push(listNode.val);
            listNode = listNode.next;
        }
        ArrayList<Integer> arr = new ArrayList<Integer>();
        while (!stack.empty()) {
            arr.add(stack.pop());
        }
        return arr;        
    }
}