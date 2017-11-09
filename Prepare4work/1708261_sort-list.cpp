/*因为题目要求复杂度为O(nlogn),故可以考虑归遍排序的思想。
归并排序的一般步骤为：
1将待排序的数组（链表）取中点一分为二;
递归地对左半部分进行归并排序;
递归地对右半部分进行归并排序;
将两个部分进行合并，得到结果
所以对应此题目，可以划分为三个小问题：
找到链表重点（快慢指针思路，快指针一次走两部，慢指针一次走一步，块指针在链表末尾时，慢指针恰好在链表重点）;
写出merge函数，即如何合并链表
写出merge函数，即如何合并链表
写出mergesort函数，实现上述步骤
*/
#include<iostream>
#include<vector>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class solution{
public:
	ListNode *sortList(ListNode *head){
		if(!head||!head->next)return head;
		ListNode* p=head,*q=head->next;
		while(q&&q->next){
			p=p->next;
			q=q->next->next;
		}
	ListNode *left=sortList(p->next);
	p->next=NULL;
	ListNode *right=sortList(head);
	return merge(left,right);
}
ListNode *merge(ListNode *left,ListNode *right){
	ListNode dummy(0);
	ListNode *p=&dummy;
	while(left&&right){
		if(left->val<right->val){
			p->next=left;
			left=left->next;
		}
		else{
			p->next=right;
			right=right->next;
		}
		p=p->next;
	}
	if(left)p->next=left;
	if(right)p->next=right;
	return dummy.next;
	}
};
int main(){
}
