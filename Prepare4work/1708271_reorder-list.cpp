#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    void reorderList(ListNode *head) {
        vector<ListNode *> stack;
        ListNode *curnode=head,*tempnode=head;
        int n=0;
        //if((head!=nullptr)&&(head->next!=nullptr)&&(head->next->next!=nullptr)){
        while(tempnode){
        	n++;
            stack.push_back(tempnode);
            tempnode=tempnode->next;
        }
        if(n>=3){
        while((curnode!=nullptr)&&(curnode->next!=nullptr)){
			cout<<n<<endl;     
        	if((curnode->val)==(stack.back()->val))break;
        	if((curnode->next->val)==(stack.back()->val))break;
        	//cout<<curnode->val<<" "<<stack.back()->val<<endl;
            stack.back()->next=curnode->next;
            curnode->next=stack.back();
            stack.pop_back();
            stack.back()->next=nullptr;
            curnode=curnode->next->next;
        }}
       // cout<<"111"<<endl;
    }
};
int main(){
	ListNode head(1);
	ListNode *curnode=&head;
	int n=0;
    while(cin>>n){
	for(int i=2;i<=n;i++){
		ListNode *newnode=new ListNode(i);
		//cout<<newnode->val;
		//if(newnode->next==nullptr)cout<<1<<endl;
		//newnode->next=nullptr;
		curnode->next=newnode;
		curnode=newnode;
		}
	/*//curnode=nullptr;
	//cout<<head.val<<head.next->val<<endl;	
	ListNode* testnode=&head;
	while(testnode!=nullptr){
		cout<<testnode->val<<" ";
		testnode=testnode->next;
		}
	//cout<<1<<endl;*/
	Solution test;
	test.reorderList(&head);
	curnode=&head;
	while(curnode){
		cout<<curnode->val<<" ";
		curnode=curnode->next;
		}
	}
	return 0;			
}
