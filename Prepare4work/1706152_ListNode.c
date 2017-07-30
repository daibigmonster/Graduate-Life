#include<iostream>
using namespace std;
struct ListNode
{
    int nValue;
    ListNode* pNext;
};
void AddToTail(ListNode ** pHead,int value)
{
    ListNode * pNew=new ListNode();
    pNew->nValue=value
    pNew->pNext=NULL;
    if(*pHead=NULL)*pHead=pNew;
    else 
    {
        ListNode *pNode=*pHead;
        while(pNode->pNext!=NULL)
            pNode=pNode->pNext;
        pNode->pNext=pNew;
     }
 }
 //在上面的代码中，我们要特别注意函数的第一个参数pHead是一个指向指针的指针。当我们往一个空链表中插入一个结点时，新插入的结点就是链表的头指针，由于此时回改动头指针，因此必须把pHead参数设为指向指针的指针，否则除了这个函数pHead仍然是一个空指针。
 //下面是链表中找到第一个含有某值的结点并删除该结点的代码
 void ReNode(ListNode** pHeade,int value)
 {
     if(pHead==NULL||*phead==NULL)return;
     ListNode * pdel=NULL;
     if((*pHead)->nValue=vale)//如果头结点等于该值的话
     {
         pdel=*pHead;
         *pHead=(*pHead)->pNext;
     }
     else
     {
         ListNode * pNode=*pHead;
         while(pNode->pNext!=NULL&&pNode->pNext->nValue!=value)
         pNode=pNode->pNext;
         if(pNode->pNext!=NULL&&pNode->pNext->nValue==value)
         {
             pdel=pNode->m_pNext;
             pNode->m_pNext=pNode->pNext->pNext;
          }
      }
      if(pdel!=NULL)
      {
          delete pdel;
          pdel=NULL;
      }
   }
