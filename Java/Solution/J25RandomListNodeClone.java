/*
public class RandomListNode {
    int label;
    RandomListNode next = null;
    RandomListNode random = null;

    RandomListNode(int label) {
        this.label = label;
    }
}
*/
public class Solution {
    /**
    * @brief 流程：
        1. 将clonenode插入链表
        2. 将复制node的random到clonenode random所指的对应的clonenode
        3. 将clonenode从原来的链表中分离出来
    * @param pHead 链表头
    * @return RandomListNode 
    *
    */
    public RandomListNode Clone(RandomListNode pHead)
    {
        if(pHead == null) return null;
        CloneNode(pHead);
        ConnectRandom(pHead);
        return ConnectNode(pHead);
    }

    /**
     * @brief 在每个节点后面添加新的克隆节点
     */
    public void CloneNode(RandomListNode pHead) {
        RandomListNode pNode = pHead;
        while(pNode != null){
            RandomListNode pClone = new RandomListNode(pNode.label);
            pClone.next = pNode.next;
            pNode.next = pClone;
            pNode = pClone.next;
        }
    }

    /**
     * @brief pClone的random指针指的是pNode的random指针的下个节点
     */
    public void ConnectRandom(RandomListNode pHead) {
        RandomListNode pNode = pHead;
        while(pNode != null){
            RandomListNode pClone = pNode.next;
            if(pNode.random != null) pClone.random = pNode.random.next;
            pNode = pClone.next;
        }
    }

    /**
     * @brief 将pClone节点从原来的链表中分离出来
     * @return 返回克隆链表的头结点
     */
    public RandomListNode  ConnectNode(RandomListNode pHead) {
        RandomListNode pNode = pHead;
        RandomListNode pCloneHead = null;
        RandomListNode pCloneNode = null;
        if(pNode != null){
            pCloneHead = pCloneNode = pNode.next;
            pNode.next = pCloneNode.next;
            pNode = pNode.next;
        }
        while(pNode != null){
            pCloneNode.next = pNode.next;
            pCloneNode = pCloneNode.next;
            pNode.next = pCloneNode.next;
            pNode = pNode.next;
        }
        return pCloneHead;
    }
    
    
}