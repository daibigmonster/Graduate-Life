#include "../Test/Test.h"
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using namespace std;

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        vector<ListNode* > List;
        ListNode* forehead = new ListNode(0),*cur;
        forehead->next = head;
        cur = head;

        while(cur != nullptr){
            List.push_back(cur);
            cur = cur->next;
        }

        cur = forehead;
        for(auto i : List){
            if(i->val < x){
            		cur->next = i;
            		cur = cur->next;
            }
        }

        for(auto i : List){
            if(i->val >= x)
            {
        			cur->next = i;
        			cur = cur->next;
            }
        }
        cur->next = nullptr;

        return forehead->next;
    }
};
ListNode *node1 = new ListNode(1);
ListNode *node2 = new ListNode(2);
ListNode *node3 = new ListNode(3);
ListNode *node4 = new ListNode(4);
ListNode *node5 = new ListNode(5);

int main()
{
	ConnectListNodes(node3,node2);
	ConnectListNodes(node2,node1);
	ConnectListNodes(node1,node4);
	ConnectListNodes(node4,node5);

	Solution s1;
	PrintList(node3);
	ListNode *res = s1.partition(node3,3);
	PrintList(res);
	return 0;

}
