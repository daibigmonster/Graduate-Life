/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Solution {
    public ListNode FindKthToTail(ListNode head,int k) {
        if(k <= 0 || head == null) return null;
        ListNode pre = head;
        ListNode last = head;
        for(int i = 0;i < k - 1;i++){
            if(pre.next != null){
                pre = pre.next;
            }
            else{
                return null;
            }
        }
        while(pre.next != null){
            pre = pre.next;
            last = last.next;
        }
        return last;
    }
}