#include "../Test/Test.h"
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using namespace std;

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == nullptr) return head;
        ListNode* forehead = new ListNode(0),*cur;
        forehead->next = head;
        cur = head;

        while(cur->next != nullptr){
            ListNode *next = findNextNode(cur->next,cur->val);
            if(next == nullptr){
//            	cout << "next is null" << endl;
                cur->next = nullptr;
                break;
            }
            else{
                cur->next = next;
                cur = cur->next;
            }
        }
        return forehead->next;

    }
    ListNode* findNextNode(ListNode* cur,int k){
        while(cur != nullptr){
            if(cur->val == k) cur = cur->next;
            else break;
        }
        return cur;
    }
};

ListNode *node11 = new ListNode(1);
ListNode *node12 = new ListNode(1);
ListNode *node2 = new ListNode(2);
ListNode *node3 = new ListNode(3);
ListNode *node4 = new ListNode(4);
ListNode *node5 = new ListNode(5);

int main()
{
	ConnectListNodes(node11,node12);
//	ConnectListNodes(node2,node1);
//	ConnectListNodes(node1,node4);
//	ConnectListNodes(node4,node5);

	Solution s1;
	PrintList(node11);
	ListNode *res = s1.deleteDuplicates(node11);
	PrintList(res);
	return 0;

}
