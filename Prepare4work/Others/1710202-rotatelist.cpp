#include "../Test/Test.h"
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using namespace std;

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *forehead = new ListNode(0),*cur;
        vector<ListNode *> List;
        cur = head;

        while(cur != nullptr){
            List.push_back(cur);
            cur = cur->next;
        }

        forehead->next = List[k + 1];
        cur = forehead;
        for(int i = 0;i < List.size();i++){
            if(i + k + 1 < List.size())
                cur->next = List[i + k + 1];
            else
                cur->next = List[i + k + 1 - List.size()];
            cur = cur->next;
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
	ConnectListNodes(node1,node2);
	ConnectListNodes(node2,node3);
	ConnectListNodes(node3,node4);
	ConnectListNodes(node4,node5);

	Solution s1;
	PrintList(node1);
	ListNode *res = s1.rotateRight(node1,3);
	PrintList(res);
	return 0;

}
