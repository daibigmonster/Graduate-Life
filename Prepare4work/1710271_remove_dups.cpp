#include <iostream>
#include "../Test/Test.h"

using namespace std ;

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == nullptr || head->next == nullptr)return head;
        ListNode* fore = new ListNode(-1);
        fore->next = head;
        ListNode* cur = fore;
        ListNode* next;
        
        while(cur->next != nullptr){
            next = findnextNode(cur->next,cur->next->val);
            cur -> next = next;
            cur = cur->next;
        }
        return fore->next;
    }
    ListNode *findnextNode(ListNode* head,int val){
        ListNode* cur = head;
        while(cur != nullptr){
            if(cur->val == val)cur = cur->next;
            else break;
        }
        if(cur == nullptr)return nullptr;
        return cur->next;
        
    }
    
};