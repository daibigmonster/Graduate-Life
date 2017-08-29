class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL||head->next==NULL)return head;
        RandomListNode *curnode=head;
        while(curnode){
            RandomListNode *tempnode=new RandomListNode(curnode->label);
            tempnode->next=curnode->next;
            curnode->next=tempnode;
            curnode=tempnode->next;
        }
        for(curnode=head;curnode;){
            RandomListNode *randomnode=curnode->next;
            if(curnode->random)randomnode->random=curnode->random->next;
            curnode=randomnode->next;
        }
        RandomListNode *newlisthead=head->next,*newlistnode=head->next;
        for(curnode=head;curnode;){
            curnode->next=newlistnode->next;
            curnode=curnode->next;
            newlistnode->next=(curnode?curnode->next:NULL);
            newlistnode=newlistnode->next;
        }
        return newlisthead;
    }
};
