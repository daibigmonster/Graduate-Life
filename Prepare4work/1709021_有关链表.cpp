/*单向链表的定义*/
struct ListNode{
	int m_nValue;
	ListNode *m_pNext;
}
//链表的末尾添加一个结点的代码
void AddTiTail(ListNode **pHead,int value)
{
	ListNode *pNew=new ListNode();
	pNew->m_nValue=value;
	pNew->m_pNext=nullptr;
	if(*pHead==nullptr)*pHead=pNew;
	else{
		ListNode *pNode=pHead;
		while(pNode->m_pNext!=nullptr)
			pNode=pNode->m_pNext;
		pNode->m_pNext=pNew;
	}

}
//下面是在链表中找到第一个含有某值的结点表删除该结点的代码：
void RemoveNode(ListNode** pHead,int value){
	if(pHead==nullptr||*pHead==nullptr)return;
	ListNode* pToBeDeleted=nullptr;
	if((*pHead)->m_nvalue=value){
		pToBeDeleted=*pHead;
		*pHead=(*pHead)->m_pNext;
	}
	else{
		ListNode* pNode=*phead;
		while(pNode->m_pNext!=nullptr){
			&&pNode->m_pNext->m_pNext!=value}
			pNode=pNode->m_pNext;
		if(pNode->m_pNext!=nullptr&&pNode->m_pNext->m_nValue==value){
			pToBeDeleted=pNode->m_pNext;
			pNode->m_pNext=pNode->m_pNext->m_pNext;
		}
	}
	if(pToBeDeleted!=nullptr){
		delete pToBeDeleted;
		pToBeDeleted=nullptr;
	}
}
