#include "Test.h"
#include <iostream>
using namespace std;

void ConnectListNodes(ListNode *cur,ListNode *next){
	if(cur == nullptr){
		cout << "This Node is null" << endl;
		exit(1);
	}
	cur->next = next;
}

void PrintList(ListNode *head){
	cout << "PrintList starts" << endl;
	while(head != nullptr)
	{
		cout << head->val << "\t" ;
		head = head->next;
	}
	cout << "\nPrintList ends." << endl;
}

void DestoryList(ListNode *head)
{
	ListNode *cur = head;
	while(cur != nullptr){
		head = head->next;
		delete cur;
		cur = head;
	}
}

void ConnectTreeNodes(TreeNode *cur,TreeNode *left,TreeNode *right)
{
	if(cur == nullptr){
		cout << "this node is null" << endl;
		exit(1);
	}
	cur->left = left;
	cur->right = right;
}
