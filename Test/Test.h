#ifndef _TEST_
#define _TEST_
#include <cstddef>
#include <iostream>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void ConnectListNodes(ListNode *cur,ListNode *next);
void PrintList(ListNode *head);
void DestoryList(ListNode *head);

void ConnectTreeNodes(TreeNode *cur,ListNode *left,ListNode *right);

#endif
