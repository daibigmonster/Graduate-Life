/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Solution {
    public ListNode ReverseList(ListNode head) {
        if(head == null) return null;
        ListNode pReverseHead = null;
        ListNode pNode = head;
        ListNode pPrev = null;
        while(pNode != null){
            ListNode pNext = pNode.next;
            if(pNext == null){
                pReverseHead = pNode;
            }
            pNode.next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        return pReverseHead;
    }
}