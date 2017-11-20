/*题目：给定一颗二叉树和其中的一个结点，如何找出中序遍历序列的下一个节点？树中的节点除了由两个分别指向左右子节点的指针，还有一个指向父节点的指针
*/
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
}
BinaryTreeNode *GetNet(BinaryTreeNode* pNode)
{
	if(pNode==nullptr)return nullptr;
	BinaryTreeNode* pNext=nullptr;
	if(pNode->m_pRight!=nullptr){
		BinaryTreeNode * pRight=pNode->m_pRight;
		while(pRight->m_pLeft!=nullptr)
			pRight=pRight->m_pLeft;
		return pRight;
	}
	else if(pNode->m_Parent!=nullptr){
		BinaryTreeNode* pCurrent=pNode;
		BinaryTreeNode* pParent=pNode->m_pParent;
		while(pParent!=nullptr&&pCurrent==pParent->m_pRight){
			pCurrent=pParent;
			pParent=pPparent->m_pParent;
		}
		pNext=pParent;
	}
	return pNext;
}
