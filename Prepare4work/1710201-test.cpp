#include "Test.h"
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using namespace std;
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *curNode;
        ListNode *forehead = new ListNode(0);
        forehead->next = head;
        vector<ListNode *> List;

        curNode = head;
        while(curNode != nullptr){
            List.push_back(curNode);
            curNode = curNode->next;
        }

        curNode = forehead;
        for(int i = 0;i < List.size();i++){
            if(i < m - 1 || i > n - 1)curNode->next = List[i];
            if(i >= m - 1 && i <= n - 1) curNode->next = List[n + m - i - 2];
            curNode = curNode->next;
        }
        curNode->next = nullptr;

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
	//ConnectListNodes(node2,node3);
	Solution s1;
	ListNode *res = s1.reverseBetween(node1,1,2);
	PrintList(res);
	return 0;

}
